/*
 * By: KoffeinFlummi
 *
 * Starts the treatment of the unit.
 *
 * Arguments:
 * 0: Unit that is diagnosed (Object)
 * 1: Type of treatment:
 *    - "diagnose"
 *    - "bandage"
 *    - "morphine"
 *    - "epipen"
 *    - "bloodbag"
 * 2+: Additional parameters
 *
 * Return value:
 * none
 */

// @todo: morphine warning

private ["_unit", "_type", "_player", "_item", "_animation", "_time"];

_unit = _this select 0;
_type = _this select 1;
_player = call AGM_Core_fnc_player;

// check if unit is medic and if that's even necessary
if (_type in ["epipen", "bloodbag"] and
    !(([_player] call AGM_Medical_fnc_isMedic) or
    (AGM_Medical_AllowNonMedics > 0))) exitWith {
  [localize "STR_AGM_Medical_NotTrained"] call AGM_Core_fnc_displayTextStructured;
};

// remove item if necessary
_item = switch (_type) do {
  case "bandage"  : {"AGM_Bandage"};
  case "morphine" : {"AGM_Morphine"};
  case "epipen"   : {"AGM_Epipen"};
  case "bloodbag" : {"AGM_Bloodbag"};
  default           {""};
};
if (_item != "" and {!([_unit, _item] call AGM_Medical_fnc_takeItem)}) exitWith {};

// code to be executed if action is aborted
AGM_Medical_treatmentAbort = {
  _player = call AGM_Core_fnc_player;
  [_player, "AmovPknlMstpSrasWrflDnon", 1] call AGM_Core_fnc_doAnimation;
  _player setVariable ["AGM_canTreat", True, False];
};

player setVariable ["AGM_canTreat", False, False];

// self-diagnosis is instant
if (
    (_unit == call AGM_Core_fnc_player) and
    (_type == "diagnose")
  ) exitWith {
  _this call AGM_Medical_fnc_treatmentCallback;
};

// play appropriate animation
// @todo: appropriate animations.
_animation = switch (_type) do {
  case "diagnose" : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "bandage"  : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "morphine" : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "epipen"   : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "bloodbag" : {"AinvPknlMstpSnonWnonDr_medic4"};
  default           {"AinvPknlMstpSnonWnonDr_medic4"};
};
[call AGM_Core_fnc_player, _animation, 1] call AGM_Core_fnc_doAnimation;

// get time required for action to be completed
_time = switch (_type) do {
  case "diagnose" : {4};
  case "bandage"  : {8};
  case "morphine" : {10};
  case "epipen"   : {10};
  case "bloodbag" : {20};
  default           {10};
};
if !([call AGM_Core_fnc_player] call AGM_Medical_fnc_isMedic) then {
  _time = _time * AGM_Medical_CoefNonMedic;
};

// @todo: select appropriate string here.
[
  _time,
  _this,
  "AGM_Medical_fnc_treatmentCallback",
  localize "STR_AGM_Medical_Diagnosing",
  "AGM_Medical_treatmentAbort"
] call AGM_Core_fnc_progressBar;
[_unit, true] call AGM_Core_fnc_closeDialogIfTargetMoves;
