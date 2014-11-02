/*
 * Author: KoffeinFlummi
 *
 * Called when some dude gets shot. Or stabbed. Or blown up. Or pushed off a cliff. Or hit by a car. Or burnt. Or poisoned. Or gassed. Or cut. You get the idea.
 *
 * Arguments:
 * 0: Unit that got hit (Object)
 * 1: Name of the selection that was hit (String); "" for structural damage
 * 2: Amount of damage inflicted (Number)
 * 3: Shooter (Object); Null for explosion damage, falling, fire etc.
 * 4: Projectile (Object)
 *
 * Return value:
 * Damage value to be inflicted (optional)
 */

#define UNCONSCIOUSNESSTHRESHOLD 0.5

#define LEGDAMAGETHRESHOLD1 1
#define LEGDAMAGETHRESHOLD2 1.7
#define ARMDAMAGETHRESHOLD 1.7

#define PAINKILLERTHRESHOLD 0.1
#define PAINLOSS 0.0001

// ætodo: these can probably be moved.
#define BLOODTHRESHOLD1 0.35
#define BLOODTHRESHOLD2 0
#define BLOODLOSSRATE 0.02

private ["_unit", "_selectionName", "_damage", "_source", "_source", "_projectile", "_hitSelections", "_hitPoints", "_newDamage", "_found", "_preventDeath"];

_unit          = _this select 0;
_selectionName = _this select 1;
_damage        = _this select 2;
_source        = _this select 3;
_projectile    = _this select 4;

// Prevent unnecessary processing
if (damage _unit >= 1) exitWith {};

_unit setVariable ["AGM_isDiagnosed", False, True];

// @todo: custom eventhandlers
// @todo: figure out if this still applies.

// For some reason, everything is backwards in MP,
// so we need to untangle some things.
if (isMultiplayer) then {
  // If you add something to this, remember not to replace something twice.
  if (_selectionName == "hand_r") then {
    _selectionName = "leg_l";
  };
  if (_selectionName == "leg_r") then {
    _selectionName = "hand_l";
  };
  if (_selectionName == "legs") then {
    _selectionName = "hand_r";
  };
};

// This seems to only show up in MP too, but since it doesn't
// collide with anything, I'll check it in SP as well.
if (_selectionName == "r_femur_hit") then {
  _selectionName = "leg_r";
};

_hitSelections = ["head", "body", "hand_l", "hand_r", "leg_l", "leg_r"];
_hitPoints = ["HitHead", "HitBody", "HitLeftArm", "HitRightArm", "HitLeftLeg", "HitRightLeg"];

// If the damage is being weird, we just tell it to fuck off.
if !(_selectionName in (_hitSelections + [""])) exitWith {0};

// Calculate change in damage.
_newDamage = _damage - (damage _unit);
if (_selectionName in _hitSelections) then {
  _newDamage = _damage - (_unit getHitPointDamage (_hitPoints select (_hitSelections find _selectionName)));
};

// Finished with the current frame, reset variables
if (isNil "AGM_Medical_FrameNo" or {diag_framno > AGM_Medical_FrameNo}) then {
  AGM_Medical_FrameNo = diag_frameno;
  AGM_Medical_isFalling = False;
  AGM_Medical_Projectiles = [];
  AGM_Medical_HitPoints = [];
  AGM_Medical_Damages = [];
};

_damage = _damage - _newDamage;

if !(_unit getVariable ["AGM_allowDamage", True]) exitWith {_damage};

_newDamage = _newDamage * AGM_Medical_CoefDamage;

// Exclude falling damage to everything other than legs; reduce structural damage.
// @todo: figure out why this still doesn't work
if (((velocity _unit) select 2 < -5) and (vehicle _unit == _unit)) then {
  AGM_Medical_isFalling = True;
};
if (AGM_Medical_isFalling and !(_selectionName in ["", "leg_l", "leg_r"])) exitWith {
  _unit getHitPointDamage (_hitPoints select (_hitSelections find _selectionName));
};
if (AGM_Medical_isFalling) {
  _newDamage = _newDamage * 0.7;
};

// Make sure there's only one damaged selection per projectile per frame.
if (_selectionName != "") then {
  if (_projectile in AGM_Medical_Projectiles) then {
    _index = AGM_Medical_Projectiles find _projectile;
    _otherDamage = (AGM_Medical_Damages select _index);
    if (_otherDamage > _newDamage) then {
      _newDamage = 0;
    } else {
      _hitPoint = AGM_Medical_HitPoints select _index;
      _restore = ((_unit getHitPointDamage _hitPoint) - _otherDamage) max 0;
      _unit setHitPointDamage [_hitPoint, _restore];
      // Make entry unfindable
      AGM_Medical_Projectiles set [_index, objNull];
      AGM_Medical_Projectiles pushBack _projectile;
      AGM_Medical_HitPoints pushBack (_hitPoints select (_hitSelections find _selectionName));
      AGM_Medical_Damages pushBack _newDamage;
    };
  } else {
    AGM_Medical_Projectiles pushBack _projectile;
    AGM_Medical_HitPoints pushBack (_hitPoints select (_hitSelections find _selectionName));
    AGM_Medical_Damages pushBack _newDamage;
  };
};

// we want to move damage to another selection; have to do it ourselves.
// this is only the case for limbs, so this will not impact the killed EH.
if (_selectionName != (_this select 1)) then {
  _unit setHitPointDamage [_hitPoints select (_hitSelections find _selectionName), _damage + _newDamage];
  _newDamage = 0;
};

_damage = _damage + _newDamage;

// Assign orphan structural damage to torso;
// using spawn with custom damage handling here, but since I just
// move damage, this shouldn't be any issue for the Killed EH
_unit spawn {
  sleep 0.001;

  _damagesum = (_this getHitPointDamage "HitHead")
    + (_this getHitPointDamage "HitBody")
    + (_this getHitPointDamage "HitLeftArm")
    + (_this getHitPointDamage "HitRightArm")
    + (_this getHitPointDamage "HitLeftLeg")
    + (_this getHitPointDamage "HitRightLeg");
  if (_damagesum <= 0.06 and (damage _this) > 0.01) then {
    _damage = damage _this;
    _this setDamage 0;
    _this setHitPointDamage ["HitBody", (_damage min 0.89)]; // just to be sure.
  };
};

// Leg Damage
_legDamage = (_unit getHitPointDamage "HitLeftLeg") + (_unit getHitPointDamage "HitRightLeg");
if (_selectionName == "leg_l") then {
  _legDamage = _damage + (_unit getHitPointDamage "HitRightLeg");
};
if (_selectionName == "leg_r") then {
  _legDamage = (_unit getHitPointDamage "HitLeftLeg") + _damage;
};
// lightly wounded, only limit walking speed (forceWalk is for suckers)
if (_legDamage >= LEGDAMAGETRESHOLD1) {
  _unit setHitPointDamage ["HitLegs", 1];
else {
  _unit setHitPointDamage ["HitLegs", 0];
};
// @ŧodo: force prone for completely fucked up legs.

// Arm Damage
_armdamage = "haha just kidding there's no arm damage.";
_armdamage = _armdamage + " (yet)";
_unit setHitPointDamage ["HitHands", 0];

// Unconsciousness
if (_selectionName == "" and
    _damage >= UNCONSCIOUSNESSTRESHOLD and
    _damage < 1 and
    !(_unit getVariable ["AGM_isUnconscious", False]
  )) then {
  // random chance to kill AI instead of knocking them out, otherwise
  // there'd be shittons of unconscious people after every firefight,
  // causing executions. And nobody likes executions.
  if (!(_unit getVariable ["AGM_allowUnconscious", [_unit] call AGM_Core_fnc_isPlayer]) and
      {random 1 > 0.5}
    ) then {
    _damage = 1;
  } else {
    [_unit] call AGM_Medical_fnc_knockOut;
  };
};

// Set Pain
// @todo: reimplement pain effect in clientinit
_potentialPain = _damage * (_unit getVariable "AGM_Painkiller");
if ((_selectionName == "") and (_potentialPain > _unit getVariable "AGM_Pain")) then {
  _unit setVariable ["AGM_Pain", _damage * (_unit getVariable "AGM_Painkiller"), true];
};

// @todo: handle bleeding in clientinit

// Only prevent death if we are going to handle unconciousness
_preventDeath = False;
if (([_unit] call AGM_Core_fnc_isPlayer) or _unit getVariable ["AGM_allowUnconscious", false]) then {
  if (!(_unit getVariable "AGM_isUnconscious") and {AGM_Medical_PreventInstaDeath > 0}) then {
    _preventDeath = True;
  };
  if ((_unit getVariable "AGM_isUnconscious") and {AGM_Medical_PreventDeathWhileUnconscious > 0}) then {
    _preventDeath = True;
  };
};

// @todo: some serious testing
// again, using spawn, but there shouldn't be any death, so the killed EH should be fine.
if (_preventDeath and {vehicle _unit != _unit} and {damage (vehicle _unit) >= 1} exitWith {
  _unit setPosATL [
    (getPos _unit select 0) + (random 3) - 1.5,
    (getPos _unit select 1) + (random 3) - 1.5,
    0
  ];
  if !(_unit getVariable ["AGM_isUnconscious", False]) then {
    [_unit] call AGM_Medical_fnc_knockOut;
  };
  _unit setVariable ["AGM_allowDamage", False];
  _unit spawn {
    sleep 1;
    _unit setVariable ["AGM_allowDamage", True];
  };
};

if (_preventDeath) then {
  _damage min 0.98
} else {
  _damage
};

