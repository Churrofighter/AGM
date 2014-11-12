class CfgPatches {
  class AGM_GetIn {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgVehicles {
  class LandVehicle;
  class Car: LandVehicle {
    class AGM_Actions {
      class AGM_GetInDriver {
        displayName = "$STR_AGM_GetInVehicleAsDriver";
        distance = 4;
        condition = "[_player, _target, 'Driver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Driver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, _target, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCommander {
        displayName = "$STR_AGM_GetInVehicleAsCommander";
        distance = 4;
        condition = "[_player, _target, 'Commander'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Commander'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, _target, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
      class AGM_GetInCoDriver {
        displayName = "$STR_AGM_GetInVehicleAsCoDriver";
        distance = 4;
        condition = "[_player, _target, 'Codriver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Codriver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToDriver {
        displayName = "$STR_AGM_MoveToDriver";
        condition = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCommander {
        displayName = "$STR_AGM_MoveToCommander";
        condition = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoDriver {
        displayName = "$STR_AGM_MoveToCoDriver";
        condition = "[_player, _vehicle, 'Codriver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Codriver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };
  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_GetInDriver {
        displayName = "$STR_AGM_GetInVehicleAsDriver";
        distance = 4;
        condition = "[_player, _target, 'Driver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Driver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, _target, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCommander {
        displayName = "$STR_AGM_GetInVehicleAsCommander";
        distance = 4;
        condition = "[_player, _target, 'Commander'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Commander'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, _target, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
      class AGM_GetInCoDriver {
        displayName = "$STR_AGM_GetInVehicleAsCoDriver";
        distance = 4;
        condition = "[_player, _target, 'Codriver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Codriver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToDriver {
        displayName = "$STR_AGM_MoveToDriver";
        condition = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCommander {
        displayName = "$STR_AGM_MoveToCommander";
        condition = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoDriver {
        displayName = "$STR_AGM_MoveToCoDriver";
        condition = "[_player, _vehicle, 'Codriver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Codriver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };

  class Air;
  class Helicopter : Air {
    class AGM_Actions {
      class AGM_GetInPilot {
        displayName = "$STR_AGM_GetInVehicleAsPilot";
        distance = 4;
        condition = "[_player, _target, 'Pilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Pilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCoPilot {
        displayName = "$STR_AGM_GetInVehicleAsCoPilot";
        distance = 4;
        condition = "[_player, _target, 'Copilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Copilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, _target, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, _target, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToPilot {
        displayName = "$STR_AGM_MoveToPilot";
        condition = "[_player, _vehicle, 'Pilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Pilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoPilot {
        displayName = "$STR_AGM_MoveToCoPilot";
        condition = "[_player, _vehicle, 'Copilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Copilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };
  class Plane: Air {
    class AGM_Actions {
      class AGM_GetInPilot {
        displayName = "$STR_AGM_GetInVehicleAsPilot";
        distance = 4;
        condition = "[_player, _target, 'Pilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Pilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCoPilot {
        displayName = "$STR_AGM_GetInVehicleAsCoPilot";
        distance = 4;
        condition = "[_player, _target, 'Copilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Copilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, _target, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToPilot {
        displayName = "$STR_AGM_MoveToPilot";
        condition = "[_player, _vehicle, 'Pilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Pilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoPilot {
        displayName = "$STR_AGM_MoveToCoPilot";
        condition = "[_player, _vehicle, 'Copilot'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Copilot'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };

  class Ship;
  class Ship_F: Ship {
    class AGM_Actions {
      class AGM_GetInDriver {
        displayName = "$STR_AGM_GetInVehicleAsDriver";
        distance = 4;
        condition = "[_player, _target, 'Driver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Driver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, _target, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCommander {
        displayName = "$STR_AGM_GetInVehicleAsCommander";
        distance = 4;
        condition = "[_player, _target, 'Commander'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Commander'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, _target, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToDriver {
        displayName = "$STR_AGM_MoveToDriver";
        condition = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCommander {
        displayName = "$STR_AGM_MoveToCommander";
        condition = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_canGetInPosition";
        statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };

  /*class StaticWeapon: LandVehicle {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
      };
    };
  };

  class StaticMortar;
  class Mortar_01_base_F: StaticMortar {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
      };
    };
  };*/
};
