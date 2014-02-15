/*
 * Author: KoffeinFlummi
 *
 * Key input handling.
 *
 * Arguments:
 * 0: something
 * 1: key
 * 2: more something
 *
 * Return Values:
 * None
 */

private ["_key"];

hint format ["%1", _this];

_key = _this select 1;

switch true do {
  case (_key == 20) : {[] call BWA3_Core_fnc_openInteractionMenu;};
  case (_key == 21) : {[] call BWA3_Core_fnc_openSelfMenu;};
  default             {};
};