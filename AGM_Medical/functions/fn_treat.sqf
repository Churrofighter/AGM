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

_unit = _this select 0;
_type = _this select 1;

AGM_Medical_treatmentAbort = {
  // do something
};
player setVariable ["AGM_canTreat", False, False];

if (
    (_unit == call AGM_Core_fnc_player) and
    (_type == "diagnose")
  ) exitWith {
  _this call AGM_Medical_fnc_treatmentCallback;
};

_animation = switch (_type) do {
  case "diagnose" : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "bandage"  : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "morphine" : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "epipen"   : {"AinvPknlMstpSnonWnonDr_medic4"};
  case "bloodbag" : {"AinvPknlMstpSnonWnonDr_medic4"};
  default           {"AinvPknlMstpSnonWnonDr_medic4"};
};
_time = switch (_type) do {
  case "diagnose" : {4};
  case "bandage"  : {8};
  case "morphine" : {10};
  case "epipen"   : {10};
  case "bloodbag" : {20};
  default           {10};
};

[call AGM_Core_fnc_player, _animation, 1] call AGM_Core_fnc_doAnimation;

if !([call AGM_Core_fnc_player] call AGM_Medical_fnc_isMedic) then {
  _time = _time * AGM_Medical_CoefNonMedic;
};

[
  _time,
  _this,
  "AGM_Medical_fnc_treatmentCallback",
  localize "STR_AGM_Medical_Diagnosing",
  "AGM_Medical_treatmentAbort"
] call AGM_Core_fnc_progressBar;
[_unit, true] call AGM_Core_fnc_closeDialogIfTargetMoves;
