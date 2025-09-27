class CfgMods
{
	class HP_Crafter
	{
		dir="HP_Crafter";
		picture="";
		action="";
		name="HP_Crafter";
		credits="";
		author="HIOH4IK";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"HP_Crafter/data/gui/hpicons.imageset"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"HP_Crafter/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"HP_Crafter/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"HP_Crafter/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgPatches
{
	class HP_Crafter
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Tools",
			"DZ_Gear_Consumables",
			"DZ_Weapons_Melee"
		};
		units[]=
		{
			"HP_Crafter",
			"HP_Anvil",
			"HP_Drill",
			"HP_Grinde",
			"HP_napilnik",
			"HP_Oiler",
			"HP_Vise",
			"HP_Payalnik",
			"HP_Plata",
			"HP_Battery",
			"HP_Tester"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class HP_Crafter_Kit: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_CRAFTER_KIT0";
		descriptionShort="$STR_HP_CRAFTER_KIT1";
		model="HP_Crafter\models\Box\HP_Box.p3d";
		weight=10000;
		itemSize[]={9,5};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Box\data\HP_Box.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Box\data\HP_Box.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Box\data\HP_Box.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Box\data\HP_Box.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Box\data\HP_Box.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="cloth";
	};
	class HP_Crafter: Container_Base
	{
		scope=2;
		displayName="$STR_HP_TABLE0";
		descriptionShort="$STR_HP_TABLE1";
		model="HP_Crafter\models\Table\HP_Table.p3d";
		forceFarBubble="true";
		physLayer="item_large";
		weight=10000;
		itemSize[]={10,10};
		itemBehaviour=0;
		repairableWithKits[]={10};
		repairCosts[]={30};
		class Cargo
		{
			itemsCargoSize[]={10,100};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"HP_Anvil",
			"HP_Drill",
			"HP_Grinde",
			"HP_napilnik",
			"HP_Oiler",
			"HP_Vise",
			"HP_Payalnik",
			"HP_Wrench",
			"HP_WoodAxe",
			"HP_SledgeHammer",
			"Material_MetalSheets",
			"HP_Shovel",
			"HP_Screwdriver",
			"HP_Pliers",
			"HP_Pipewrench",
			"HP_Pickaxe",
			"HP_Pipe",
			"HP_LugWrench",
			"HP_Hatchet",
			"HP_HandSaw",
			"HP_Hammer",
			"HP_Hacksaw",
			"HP_FirefighterAxe",
			"HP_FarmingHoe",
			"HP_Crowbar",
			"Material_L1_Nails"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Table\data\HP_Table.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Table\data\HP_Table.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Table\data\HP_Table.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Table\data\HP_Table.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Table\data\HP_Table.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="metal";
	};
	class HP_Anvil: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_ANVIL0";
		descriptionShort="$STR_HP_ANVIL1";
		model="HP_Crafter\models\Anvil\HP_Anvil.p3d";
		inventorySlot[]=
		{
			"HP_Anvil"
		};
		weight=70;
		itemSize[]={4,3};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Anvil\data\HP_Anvil.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Anvil\data\HP_Anvil.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Anvil\data\HP_Anvil.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Anvil\data\HP_Anvil.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Anvil\data\HP_Anvil.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class HP_Drill: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_DRILL0";
		descriptionShort="$STR_HP_DRILL1";
		model="HP_Crafter\models\Drill\HP_Drill.p3d";
		inventorySlot[]=
		{
			"HP_Drill"
		};
		weight=70;
		itemSize[]={4,6};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Drill\data\HP_Drill.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Drill\data\HP_Drill.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Drill\data\HP_Drill.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Drill\data\HP_Drill.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Drill\data\HP_Drill.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class HP_Grinde: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_GRINDE0";
		descriptionShort="$STR_HP_GRINDE1";
		model="HP_Crafter\models\Grinde\HP_Grinde.p3d";
		inventorySlot[]=
		{
			"HP_Grinde"
		};
		weight=20;
		itemSize[]={6,4};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Grinde\data\HP_Grinde.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Grinde\data\HP_Grinde.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Grinde\data\HP_Grinde.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Grinde\data\HP_Grinde.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Grinde\data\HP_Grinde.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class HP_napilnik: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_NAPILNIK0";
		descriptionShort="$STR_HP_NAPILNIK1";
		model="HP_Crafter\models\napilnik\HP_napilnik.p3d";
		inventorySlot[]=
		{
			"HP_napilnik"
		};
		weight=1;
		itemSize[]={1,2};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\napilnik\data\HP_napilnik.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\napilnik\data\HP_napilnik.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\napilnik\data\HP_napilnik.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\napilnik\data\HP_napilnik.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\napilnik\data\HP_napilnik.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class HP_Oiler: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_OILER0";
		descriptionShort="$STR_HP_OILER1";
		model="HP_Crafter\models\Oiler\HP_Oiler.p3d";
		inventorySlot[]=
		{
			"HP_Oiler"
		};
		weight=2;
		itemSize[]={3,3};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Oiler\data\HP_Oiler.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Oiler\data\HP_Oiler.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Oiler\data\HP_Oiler.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Oiler\data\HP_Oiler.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Oiler\data\HP_Oiler.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class HP_Vise: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_VISE0";
		descriptionShort="$STR_HP_VISE1";
		model="HP_Crafter\models\Vice\HP_Vise.p3d";
		inventorySlot[]=
		{
			"HP_Vise"
		};
		weight=50;
		itemSize[]={6,4};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Vice\data\HP_Vise.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Vice\data\HP_Vise.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Vice\data\HP_Vise.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Vice\data\HP_Vise.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Vice\data\HP_Vise.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class HP_Battery: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_BATTERY0";
		descriptionShort="$STR_HP_BATTERY1";
		model="HP_Crafter\models\Battery\HP_Battery.p3d";
		weight=1;
		itemSize[]={1,1};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								
							}
						},
						
						{
							0.69999999,
							
							{
								
							}
						},
						
						{
							0.5,
							
							{
								
							}
						},
						
						{
							0.30000001,
							
							{
								
							}
						},
						
						{
							0,
							
							{
								
							}
						}
					};
				};
			};
		};
	};
	class HP_Plata: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_PLATA0";
		descriptionShort="$STR_HP_PLATA1";
		model="HP_Crafter\models\Plata\HP_Plata.p3d";
		weight=1;
		itemSize[]={1,1};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								
							}
						},
						
						{
							0.69999999,
							
							{
								
							}
						},
						
						{
							0.5,
							
							{
								
							}
						},
						
						{
							0.30000001,
							
							{
								
							}
						},
						
						{
							0,
							
							{
								
							}
						}
					};
				};
			};
		};
	};
	class HP_Tester: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_TESTER0";
		descriptionShort="$STR_HP_TESTER1";
		model="HP_Crafter\models\Tester\HP_Tester.p3d";
		weight=1;
		itemSize[]={1,2};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								
							}
						},
						
						{
							0.69999999,
							
							{
								
							}
						},
						
						{
							0.5,
							
							{
								
							}
						},
						
						{
							0.30000001,
							
							{
								
							}
						},
						
						{
							0,
							
							{
								
							}
						}
					};
				};
			};
		};
	};
	class HP_Pipe: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_TESTER0";
		descriptionShort="$STR_HP_TESTER1";
		model="HP_Crafter\models\Tryba\HP_Pipe.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"HP_Crafter\models\Tryba\data\metal_pipe_co.paa",
			"HP_Crafter\models\Tryba\data\metal_pipe_co.paa"
		};
		weight=1;
		itemSize[]={1,2};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								
							}
						},
						
						{
							0.69999999,
							
							{
								
							}
						},
						
						{
							0.5,
							
							{
								
							}
						},
						
						{
							0.30000001,
							
							{
								
							}
						},
						
						{
							0,
							
							{
								
							}
						}
					};
				};
			};
		};
	};
	class HP_Payalnik: Inventory_Base
	{
		scope=2;
		displayName="$STR_HP_PAYALNIK0";
		descriptionShort="$STR_HP_PAYALNIK1";
		model="HP_Crafter\models\Payalnik\HP_Payalnik.p3d";
		inventorySlot[]=
		{
			"HP_Payalnik"
		};
		weight=5;
		itemSize[]={3,3};
		itemBehaviour=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"HP_Crafter\models\Payalnik\data\HP_Payalnik.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"HP_Crafter\models\Payalnik\data\HP_Payalnik.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"HP_Crafter\models\Payalnik\data\HP_Payalnik.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"HP_Crafter\models\Payalnik\data\HP_Payalnik.rvmat"
							}
						},
						
						{
							0,
							
							{
								"HP_Crafter\models\Payalnik\data\HP_Payalnik.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Wrench: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Wrench"
		};
	};
	class SledgeHammer: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_SledgeHammer"
		};
	};
	class Shovel: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Shovel"
		};
	};
	class Screwdriver: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Screwdriver"
		};
	};
	class Pliers: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Pliers"
		};
	};
	class Pipewrench: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Pipewrench"
		};
	};
	class Pickaxe: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Pickaxe"
		};
	};
	class Pipe: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Pipe"
		};
	};
	class LugWrench: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_LugWrench"
		};
	};
	class Crowbar: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Crowbar"
		};
	};
	class FarmingHoe: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_FarmingHoe"
		};
	};
	class FirefighterAxe: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_FirefighterAxe"
		};
	};
	class Hacksaw: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Hacksaw"
		};
	};
	class HandSaw: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_HandSaw"
		};
	};
	class Hammer: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Hammer"
		};
	};
	class Hatchet: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_Hatchet"
		};
	};
	class WoodAxe: Inventory_Base
	{
		inventorySlot[]+=
		{
			"HP_WoodAxe"
		};
	};
};
class CfgSlots
{
	class Slot_HP_Anvil
	{
		name="HP_Anvil";
		displayName="$STR_HP_ANVIL0";
		ghostIcon="set:hpicons image:HP_Anvil";
	};
	class Slot_HP_Drill
	{
		name="HP_Drill";
		displayName="$STR_HP_DRILL0";
		ghostIcon="set:hpicons image:HP_Drill";
	};
	class Slot_HP_Grinde
	{
		name="HP_Grinde";
		displayName="$STR_HP_GRINDE0";
		ghostIcon="set:hpicons image:HP_Grinder";
	};
	class Slot_HP_napilnik
	{
		name="HP_napilnik";
		displayName="$STR_HP_NAPILNIK0";
		ghostIcon="set:hpicons image:HP_File";
	};
	class Slot_HP_Oiler
	{
		name="HP_Oiler";
		displayName="$STR_HP_OILER0";
		ghostIcon="set:hpicons image:HP_Oiler";
	};
	class Slot_HP_Vise
	{
		name="HP_Vise";
		displayName="$STR_HP_VISE0";
		ghostIcon="set:hpicons image:HP_Vise";
	};
	class Slot_HP_Payalnik
	{
		name="HP_Payalnik";
		displayName="$STR_HP_PAYALNIK0";
		ghostIcon="set:hpicons image:HP_Payalnik";
	};
	class Slot_HP_Crowbar
	{
		name="HP_Crowbar";
		displayName="$STR_CfgVehicles_Crowbar0";
		ghostIcon="set:hpicons image:HP_Crowbar";
	};
	class Slot_HP_FarmingHoe
	{
		name="HP_FarmingHoe";
		displayName="$STR_CfgVehicles_FarmingHoe0";
		ghostIcon="set:hpicons image:HP_FHoe";
	};
	class Slot_HP_FirefighterAxe
	{
		name="HP_FirefighterAxe";
		displayName="$STR_CfgVehicles_FirefighterAxe0";
		ghostIcon="set:hpicons image:HP_FAxe";
	};
	class Slot_HP_Hacksaw
	{
		name="HP_Hacksaw";
		displayName="$STR_CfgVehicles_Hacksaw0";
		ghostIcon="set:hpicons image:HP_HSaw";
	};
	class Slot_HP_Hammer
	{
		name="HP_Hammer";
		displayName="$STR_CfgVehicles_Hammer0";
		ghostIcon="set:hpicons image:HP_Hammer";
	};
	class Slot_HP_HandSaw
	{
		name="HP_HandSaw";
		displayName="$STR_CfgVehicles_HandSaw0";
		ghostIcon="set:hpicons image:HP_HandSaw";
	};
	class Slot_HP_Hatchet
	{
		name="HP_Hatchet";
		displayName="$STR_CfgVehicles_Hatchet0";
		ghostIcon="set:hpicons image:HP_Hatchet";
	};
	class Slot_HP_LugWrench
	{
		name="HP_LugWrench";
		displayName="$STR_CfgVehicles_LugWrench0";
		ghostIcon="set:hpicons image:HP_Balonnik";
	};
	class Slot_HP_Pipe
	{
		name="HP_Pipe";
		displayName="$STR_CfgVehicles_Pipe0";
		ghostIcon="set:hpicons image:HP_Pipe";
	};
	class Slot_HP_Nails
	{
		name="HP_Nails";
		displayName="$STR_CfgVehicles_Nail0";
		ghostIcon="set:dayz_inventory image:nails";
	};
	class Slot_HP_Pickaxe
	{
		name="HP_Pickaxe";
		displayName="$STR_CfgVehicles_Pickaxe0";
		ghostIcon="set:hpicons image:HP_Pickaxe";
	};
	class Slot_HP_Pipewrench
	{
		name="HP_Pipewrench";
		displayName="$STR_CfgVehicles_PipeWrench0";
		ghostIcon="set:hpicons image:HP_pipewrench";
	};
	class Slot_HP_Pliers
	{
		name="HP_Pliers";
		displayName="$STR_CfgVehicles_Pliers0";
		ghostIcon="set:hpicons image:HP_Pliers";
	};
	class Slot_HP_Screwdriver
	{
		name="HP_Screwdriver";
		displayName="$STR_CfgVehicles_Screwdriver0";
		ghostIcon="set:hpicons image:HP_Screwdriver";
	};
	class Slot_HP_Shovel
	{
		name="HP_Shovel";
		displayName="$STR_CfgVehicles_Shovel0";
		ghostIcon="set:hpicons image:HP_Shovel";
	};
	class Slot_HP_MetalPlate
	{
		name="HP_MetalPlate";
		displayName="$STR_CfgVehicles_MetalPlate0";
		ghostIcon="set:dayz_inventory image:plates";
	};
	class Slot_HP_SledgeHammer
	{
		name="HP_SledgeHammer";
		displayName="$STR_CfgVehicles_SledgeHammer0";
		ghostIcon="set:hpicons image:HP_SHammer";
	};
	class Slot_HP_WoodAxe
	{
		name="HP_WoodAxe";
		displayName="$STR_CfgVehicles_WoodAxe0";
		ghostIcon="set:hpicons image:HP_Woodaxe";
	};
	class Slot_HP_Wrench
	{
		name="HP_Wrench";
		displayName="$STR_CfgVehicles_Wrench0";
		ghostIcon="set:hpicons image:HP_Wrench";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyHP_Payalnik: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Payalnik";
		model="HP_Crafter\models\Payalnik\HP_Payalnik.p3d";
	};
	class ProxyHP_Vise: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Vise";
		model="HP_Crafter\models\Vice\HP_Vise.p3d";
	};
	class ProxyHP_Oiler: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Oiler";
		model="HP_Crafter\models\Oiler\HP_Oiler.p3d";
	};
	class ProxyHP_napilnik: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_napilnik";
		model="HP_Crafter\models\napilnik\HP_napilnik.p3d";
	};
	class ProxyHP_Grinde: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Grinde";
		model="HP_Crafter\models\Grinde\HP_Grinde.p3d";
	};
	class ProxyHP_Drill: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Drill";
		model="HP_Crafter\models\Drill\HP_Drill.p3d";
	};
	class ProxyHP_Anvil: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Anvil";
		model="HP_Crafter\models\Anvil\HP_Anvil.p3d";
	};
	class ProxyHP_Craft_Crowbar: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Crowbar";
		model="HP_Crafter\models\Proxy\HP_Craft_Crowbar.p3d";
	};
	class ProxyHP_Craft_Farming_Hoe: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_FarmingHoe";
		model="HP_Crafter\models\Proxy\HP_Craft_Farming_Hoe.p3d";
	};
	class ProxyHP_Craft_FirefighterAxe: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_FirefighterAxe";
		model="HP_Crafter\models\Proxy\HP_Craft_FirefighterAxe.p3d";
	};
	class ProxyHP_Craft_hacksaw: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Hacksaw";
		model="HP_Crafter\models\Proxy\HP_Craft_hacksaw.p3d";
	};
	class ProxyHP_Craft_Hammer: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Hammer";
		model="HP_Crafter\models\Proxy\HP_Craft_Hammer.p3d";
	};
	class ProxyHP_Craft_handsaw: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_HandSaw";
		model="HP_Crafter\models\Proxy\HP_Craft_handsaw.p3d";
	};
	class ProxyHP_Craft_hatchet: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Hatchet";
		model="HP_Crafter\models\Proxy\HP_Craft_hatchet.p3d";
	};
	class ProxyHP_Craft_Lug_wrench: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_LugWrench";
		model="HP_Crafter\models\Proxy\HP_Craft_Lug_wrench.p3d";
	};
	class ProxyHP_Craft_metal_pipe: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Pipe";
		model="HP_Crafter\models\Proxy\HP_Craft_metal_pipe.p3d";
	};
	class ProxyHP_Craft_Nails_loose_10: ProxyAttachment
	{
		scope=1;
		inventorySlot="Material_L1_Nails";
		model="HP_Crafter\models\Proxy\HP_Craft_Nails_loose_10.p3d";
	};
	class ProxyHP_Craft_Pickaxe: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Pickaxe";
		model="HP_Crafter\models\Proxy\HP_Craft_Pickaxe.p3d";
	};
	class ProxyHP_Craft_pipewrench: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Pipewrench";
		model="HP_Crafter\models\Proxy\HP_Craft_pipewrench.p3d";
	};
	class ProxyHP_Craft_Pliers: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Pliers";
		model="HP_Crafter\models\Proxy\HP_Craft_Pliers.p3d";
	};
	class ProxyHP_Craft_Screwdriver: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Screwdriver";
		model="HP_Crafter\models\Proxy\HP_Craft_Screwdriver.p3d";
	};
	class ProxyHP_Craft_Shovel: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Shovel";
		model="HP_Crafter\models\Proxy\HP_Craft_Shovel.p3d";
	};
	class ProxyHPSingle_Metal_Sheet: ProxyAttachment
	{
		scope=1;
		inventorySlot="Material_MetalSheets";
		model="HP_Crafter\models\Proxy\HPSingle_Metal_Sheet.p3d";
	};
	class ProxyHPSledge_Hammer: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_SledgeHammer";
		model="HP_Crafter\models\Proxy\HPSledge_Hammer.p3d";
	};
	class ProxyHPWoodaxe: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_WoodAxe";
		model="HP_Crafter\models\Proxy\HPWoodaxe.p3d";
	};
	class ProxyHPWrench: ProxyAttachment
	{
		scope=1;
		inventorySlot="HP_Wrench";
		model="HP_Crafter\models\Proxy\HPWrench.p3d";
	};
};
