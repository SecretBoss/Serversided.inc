#if defined _serversided_included
	#endinput
#endif
#define _serversided_included

/*
*
* ===============
* LIBRARY
* ===============
* Server sieded include (serversided.inc) - v1.6 [BETA]
* Makes all the client side features to server scripted parts (covers Health, Armour, Money, Weapon, Ammo and Vehicle Health).
*
* ===============
* CREDITS
* ===============
* Gammix - Include creator
* Slice - Damage processing function, weapons array and average hit/shoot functions to catch rapid fire
* SecretBoss - Testing the include
*
*/

#define WEAPON_UNARMED 			0
#define WEAPON_VEHICLE_M4 		19
#define WEAPON_VEHICLE_MINIGUN 	20
#define WEAPON_PISTOLWHIP 		48
#define WEAPON_HELIBLADES 		50
#define WEAPON_EXPLOSION 		51
#define WEAPON_CARPARK 			52
#define WEAPON_UNKNOWN 			55

enum e_SS_VENDING_MACHINE
{
	SS_vmModel,
	SS_vmInterior,
	Float:SS_vmPosX,
	Float:SS_vmPosY,
	Float:SS_vmPosZ,
	Float:SS_vmRotX,
	Float:SS_vmRotY,
	Float:SS_vmRotZ,
	Float:SS_vmFrontX,
	Float:SS_vmFrontY
}
static const Float:SS_VendingMachine[][e_SS_VENDING_MACHINE] =
{
	{955, 0, -862.82, 1536.60, 21.98, 0.00, 0.00, 180.00, -862.84, 1537.60},
	{956, 0, 2271.72, -76.46, 25.96, 0.00, 0.00, 0.00, 2271.72, -77.46},
	{955, 0, 1277.83, 372.51, 18.95, 0.00, 0.00, 64.00, 1278.73, 372.07},
	{956, 0, 662.42, -552.16, 15.71, 0.00, 0.00, 180.00, 662.41, -551.16},
	{955, 0, 201.01, -107.61, 0.89, 0.00, 0.00, 270.00, 200.01, -107.63},
	{955, 0, -253.74, 2597.95, 62.24, 0.00, 0.00, 90.00, -252.74, 2597.95},
	{956, 0, -253.74, 2599.75, 62.24, 0.00, 0.00, 90.00, -252.74, 2599.75},
	{956, 0, -76.03, 1227.99, 19.12, 0.00, 0.00, 90.00, -75.03, 1227.99},
	{955, 0, -14.70, 1175.35, 18.95, 0.00, 0.00, 180.00, -14.72, 1176.35},
	{1977, 7, 316.87, -140.35, 998.58, 0.00, 0.00, 270.00, 315.87, -140.36},
	{1775, 17, 373.82, -178.14, 1000.73, 0.00, 0.00, 0.00, 373.82, -179.14},
	{1776, 17, 379.03, -178.88, 1000.73, 0.00, 0.00, 270.00, 378.03, -178.90},
	{1775, 17, 495.96, -24.32, 1000.73, 0.00, 0.00, 180.00, 495.95, -23.32},
	{1776, 17, 500.56, -1.36, 1000.73, 0.00, 0.00, 0.00, 500.56, -2.36},
	{1775, 17, 501.82, -1.42, 1000.73, 0.00, 0.00, 0.00, 501.82, -2.42},
	{956, 0, -1455.11, 2591.66, 55.23, 0.00, 0.00, 180.00, -1455.13, 2592.66},
	{955, 0, 2352.17, -1357.15, 23.77, 0.00, 0.00, 90.00, 2353.17, -1357.15},
	{955, 0, 2325.97, -1645.13, 14.21, 0.00, 0.00, 0.00, 2325.97, -1646.13},
	{956, 0, 2139.51, -1161.48, 23.35, 0.00, 0.00, 87.00, 2140.51, -1161.53},
	{956, 0, 2153.23, -1016.14, 62.23, 0.00, 0.00, 127.00, 2154.03, -1015.54},
	{955, 0, 1928.73, -1772.44, 12.94, 0.00, 0.00, 90.00, 1929.73, -1772.44},
	{1776, 1, 2222.36, 1602.64, 1000.06, 0.00, 0.00, 90.00, 2223.36, 1602.64},
	{1775, 1, 2222.20, 1606.77, 1000.05, 0.00, 0.00, 90.00, 2223.20, 1606.77},
	{1775, 1, 2155.90, 1606.77, 1000.05, 0.00, 0.00, 90.00, 2156.90, 1606.77},
	{1775, 1, 2209.90, 1607.19, 1000.05, 0.00, 0.00, 270.00, 2208.90, 1607.17},
	{1776, 1, 2155.84, 1607.87, 1000.06, 0.00, 0.00, 90.00, 2156.84, 1607.87},
	{1776, 1, 2202.45, 1617.00, 1000.06, 0.00, 0.00, 180.00, 2202.43, 1618.00},
	{1776, 1, 2209.24, 1621.21, 1000.06, 0.00, 0.00, 0.00, 2209.24, 1620.21},
	{1776, 3, 330.67, 178.50, 1020.07, 0.00, 0.00, 0.00, 330.67, 177.50},
	{1776, 3, 331.92, 178.50, 1020.07, 0.00, 0.00, 0.00, 331.92, 177.50},
	{1776, 3, 350.90, 206.08, 1008.47, 0.00, 0.00, 90.00, 351.90, 206.08},
	{1776, 3, 361.56, 158.61, 1008.47, 0.00, 0.00, 180.00, 361.54, 159.61},
	{1776, 3, 371.59, 178.45, 1020.07, 0.00, 0.00, 0.00, 371.59, 177.45},
	{1776, 3, 374.89, 188.97, 1008.47, 0.00, 0.00, 0.00, 374.89, 187.97},
	{1775, 2, 2576.70, -1284.43, 1061.09, 0.00, 0.00, 270.00, 2575.70, -1284.44},
	{1775, 15, 2225.20, -1153.42, 1025.90, 0.00, 0.00, 270.00, 2224.20, -1153.43},
	{955, 0, 1154.72, -1460.89, 15.15, 0.00, 0.00, 270.00, 1153.72, -1460.90},
	{956, 0, 2480.85, -1959.27, 12.96, 0.00, 0.00, 180.00, 2480.84, -1958.27},
	{955, 0, 2060.11, -1897.64, 12.92, 0.00, 0.00, 0.00, 2060.11, -1898.64},
	{955, 0, 1729.78, -1943.04, 12.94, 0.00, 0.00, 0.00, 1729.78, -1944.04},
	{956, 0, 1634.10, -2237.53, 12.89, 0.00, 0.00, 0.00, 1634.10, -2238.53},
	{955, 0, 1789.21, -1369.26, 15.16, 0.00, 0.00, 270.00, 1788.21, -1369.28},
	{956, 0, -2229.18, 286.41, 34.70, 0.00, 0.00, 180.00, -2229.20, 287.41},
	{955, 256, -1980.78, 142.66, 27.07, 0.00, 0.00, 270.00, -1981.78, 142.64},
	{955, 256, -2118.96, -423.64, 34.72, 0.00, 0.00, 255.00, -2119.93, -423.40},
	{955, 256, -2118.61, -422.41, 34.72, 0.00, 0.00, 255.00, -2119.58, -422.17},
	{955, 256, -2097.27, -398.33, 34.72, 0.00, 0.00, 180.00, -2097.29, -397.33},
	{955, 256, -2092.08, -490.05, 34.72, 0.00, 0.00, 0.00, -2092.08, -491.05},
	{955, 256, -2063.27, -490.05, 34.72, 0.00, 0.00, 0.00, -2063.27, -491.05},
	{955, 256, -2005.64, -490.05, 34.72, 0.00, 0.00, 0.00, -2005.64, -491.05},
	{955, 256, -2034.46, -490.05, 34.72, 0.00, 0.00, 0.00, -2034.46, -491.05},
	{955, 256, -2068.56, -398.33, 34.72, 0.00, 0.00, 180.00, -2068.58, -397.33},
	{955, 256, -2039.85, -398.33, 34.72, 0.00, 0.00, 180.00, -2039.86, -397.33},
	{955, 256, -2011.14, -398.33, 34.72, 0.00, 0.00, 180.00, -2011.15, -397.33},
	{955, 2048, -1350.11, 492.28, 10.58, 0.00, 0.00, 90.00, -1349.11, 492.28},
	{956, 2048, -1350.11, 493.85, 10.58, 0.00, 0.00, 90.00, -1349.11, 493.85},
	{955, 0, 2319.99, 2532.85, 10.21, 0.00, 0.00, 0.00, 2319.99, 2531.85},
	{956, 0, 2845.72, 1295.04, 10.78, 0.00, 0.00, 0.00, 2845.72, 1294.04},
	{955, 0, 2503.14, 1243.69, 10.21, 0.00, 0.00, 180.00, 2503.12, 1244.69},
	{956, 0, 2647.69, 1129.66, 10.21, 0.00, 0.00, 0.00, 2647.69, 1128.66},
	{1209, 0, -2420.21, 984.57, 44.29, 0.00, 0.00, 90.00, -2419.21, 984.57},
	{1302, 0, -2420.17, 985.94, 44.29, 0.00, 0.00, 90.00, -2419.17, 985.94},
	{955, 0, 2085.77, 2071.35, 10.45, 0.00, 0.00, 90.00, 2086.77, 2071.35},
	{956, 0, 1398.84, 2222.60, 10.42, 0.00, 0.00, 180.00, 1398.82, 2223.60},
	{956, 0, 1659.46, 1722.85, 10.21, 0.00, 0.00, 0.00, 1659.46, 1721.85},
	{955, 0, 1520.14, 1055.26, 10.00, 0.00, 0.00, 270.00, 1519.14, 1055.24},
	{1775, 6, -19.03, -57.83, 1003.63, 0.00, 0.00, 180.00, -19.05, -56.83},
	{1775, 18, -16.11, -91.64, 1003.63, 0.00, 0.00, 180.00, -16.13, -90.64},
	{1775, 16, -15.10, -140.22, 1003.63, 0.00, 0.00, 180.00, -15.11, -139.22},
	{1775, 17, -32.44, -186.69, 1003.63, 0.00, 0.00, 180.00, -32.46, -185.69},
	{1775, 16, -35.72, -140.22, 1003.63, 0.00, 0.00, 180.00, -35.74, -139.22},
	{1776, 6, -36.14, -57.87, 1003.63, 0.00, 0.00, 180.00, -36.16, -56.87},
	{1776, 18, -17.54, -91.71, 1003.63, 0.00, 0.00, 180.00, -17.56, -90.71},
	{1776, 16, -16.53, -140.29, 1003.63, 0.00, 0.00, 180.00, -16.54, -139.29},
	{1776, 17, -33.87, -186.76, 1003.63, 0.00, 0.00, 180.00, -33.89, -185.76},
	{1775, 6, -19.03, -57.83, 1003.63, 0.00, 0.00, 180.00, -19.05, -56.83},
	{1776, 6, -36.14, -57.87, 1003.63, 0.00, 0.00, 180.00, -36.16, -56.87},
	{1775, 18, -16.11, -91.64, 1003.63, 0.00, 0.00, 180.00, -16.13, -90.64},
	{1776, 18, -17.54, -91.71, 1003.63, 0.00, 0.00, 180.00, -17.56, -90.71},
	{1776, 16, -16.53, -140.29, 1003.63, 0.00, 0.00, 180.00, -16.54, -139.29},
	{1775, 16, -15.10, -140.22, 1003.63, 0.00, 0.00, 180.00, -15.11, -139.22},
	{1776, 17, -33.87, -186.76, 1003.63, 0.00, 0.00, 180.00, -33.89, -185.76},
	{1775, 17, -32.44, -186.69, 1003.63, 0.00, 0.00, 180.00, -32.46, -185.69},
	{1775, 16, -35.72, -140.22, 1003.63, 0.00, 0.00, 180.00, -35.74, -139.22}
};
static SS_VendingMachineObject[sizeof(SS_VendingMachine)] = {INVALID_OBJECT_ID, ...};
static SS_VendingMachineTimer[MAX_PLAYERS];

static const Float:SS_WeaponRange[] =
{
	15.0, // 0 - Fist
	15.0, // 1 - Brass knuckles
	15.0, // 2 - Golf club
	15.0, // 3 - Nitestick
	15.0, // 4 - Knife
	15.0, // 5 - Bat
	15.0, // 6 - Shovel
	15.0, // 7 - Pool cue
	15.0, // 8 - Katana
	15.0, // 9 - Chainsaw
	15.0, // 10 - Dildo
	15.0, // 11 - Dildo 2
	15.0, // 12 - Vibrator
	15.0, // 13 - Vibrator 2
	15.0, // 14 - Flowers
	15.0, // 15 - Cane
	0.0, // 16 - Grenade
	0.0, // 17 - Teargas
	0.0, // 18 - Molotov
	90.0, // 19 - Vehicle M4 (custom)
	75.0, // 20 - Vehicle minigun (custom)
	0.0, // 21
	35.0, // 22 - Colt 45
	35.0, // 23 - Silenced
	35.0, // 24 - Deagle
	40.0, // 25 - Shotgun
	35.0, // 26 - Sawed-off
	40.0, // 27 - Spas
	35.0, // 28 - UZI
	45.0, // 29 - MP5
	70.0, // 30 - AK47
	90.0, // 31 - M4
	35.0, // 32 - Tec9
	100.0, // 33 - Cuntgun
	320.0, // 34 - Sniper
	0.0, // 35 - Rocket launcher
	0.0, // 36 - Heatseeker
	0.0, // 37 - Flamethrower
	75.0,  // 38 - Minigun
	0.0, // 39 - Satchel
	0.0, // 40 - Detonator
	15.0, // 41 - Spraycan
	15.0, // 42 - Fire extinguisher
	0.0, // 43 - Camera
	0.0, // 44 - Night vision
	0.0, // 45 - Infrared
	0.0, // 46 - Parachute
	0.0, // 47 - Fake pistol
	15.0, // 48 - Pistol whip (custom)
	0.0, // 49 - Vehicle
	0.0, // 50 - Helicopter blades
	0.0, // 51 - Explosion
	0.0, // 52 - Car park (custom)
	0.0, // 53 - Drowning
	0.0  // 54 - Splat
};

static const Float:SS_WeaponDamage[] =
{
	1.0, // 0 - Fist
	1.0, // 1 - Brass knuckles
	1.0, // 2 - Golf club
	1.0, // 3 - Nitestick
	1.0, // 4 - Knife
	1.0, // 5 - Bat
	1.0, // 6 - Shovel
	1.0, // 7 - Pool cue
	1.0, // 8 - Katana
	1.0, // 9 - Chainsaw
	1.0, // 10 - Dildo
	1.0, // 11 - Dildo 2
	1.0, // 12 - Vibrator
	1.0, // 13 - Vibrator 2
	1.0, // 14 - Flowers
	1.0, // 15 - Cane
	82.5, // 16 - Grenade
	0.0, // 17 - Teargas
	1.0, // 18 - Molotov
	9.9, // 19 - Vehicle M4 (custom)
	46.2, // 20 - Vehicle minigun (custom)
	0.0, // 21
	8.25, // 22 - Colt 45
	13.2, // 23 - Silenced
	46.2, // 24 - Deagle
	3.3, // 25 - Shotgun
	3.3, // 26 - Sawed-off
	4.95, // 27 - Spas
	6.6, // 28 - UZI
	8.25, // 29 - MP5
	9.9, // 30 - AK47
	9.9, // 31 - M4
	6.6, // 32 - Tec9
	24.75, // 33 - Cuntgun
	41.25, // 34 - Sniper
	82.5, // 35 - Rocket launcher
	82.5, // 36 - Heatseeker
	1.0, // 37 - Flamethrower
	46.2, // 38 - Minigun
	82.5, // 39 - Satchel
	0.0, // 40 - Detonator
	0.33, // 41 - Spraycan
	0.33, // 42 - Fire extinguisher
	0.0, // 43 - Camera
	0.0, // 44 - Night vision
	0.0, // 45 - Infrared
	0.0, // 46 - Parachute
	0.0, // 47 - Fake pistol
	2.64, // 48 - Pistol whip (custom)
	9.9, // 49 - Vehicle
	330.0, // 50 - Helicopter blades
	82.5, // 51 - Explosion
	1.0, // 52 - Car park (custom)
	1.0, // 53 - Drowning
	165.0  // 54 - Splat
};

static const SS_WeaponShootRate[] =
{
	250, // 0 - Fist
	250, // 1 - Brass knuckles
	250, // 2 - Golf club
	250, // 3 - Nitestick
	250, // 4 - Knife
	250, // 5 - Bat
	250, // 6 - Shovel
	250, // 7 - Pool cue
	250, // 8 - Katana
	30, // 9 - Chainsaw
	250, // 10 - Dildo
	250, // 11 - Dildo 2
	250, // 12 - Vibrator
	250, // 13 - Vibrator 2
	250, // 14 - Flowers
	250, // 15 - Cane
	0, // 16 - Grenade
	0, // 17 - Teargas
	0, // 18 - Molotov
	20, // 19 - Vehicle M4 (custom)
	20, // 20 - Vehicle minigun (custom)
	0, // 21
	160, // 22 - Colt 45
	120, // 23 - Silenced
	120, // 24 - Deagle
	800, // 25 - Shotgun
	120, // 26 - Sawed-off
	120, // 27 - Spas
	50, // 28 - UZI
	90, // 29 - MP5
	90, // 30 - AK47
	90, // 31 - M4
	70, // 32 - Tec9
	800, // 33 - Cuntgun
	900, // 34 - Sniper
	0, // 35 - Rocket launcher
	0, // 36 - Heatseeker
	0, // 37 - Flamethrower
	20, // 38 - Minigun
	0, // 39 - Satchel
	0, // 40 - Detonator
	10, // 41 - Spraycan
	10, // 42 - Fire extinguisher
	0, // 43 - Camera
	0, // 44 - Night vision
	0, // 45 - Infrared
	0, // 46 - Parachute
	0, // 47 - Fake pistol
	400 // 48 - Pistol whip (custom)
};

enum e_SS_CLASS_INFO
{
	SS_classTeam = NO_TEAM,
	SS_classWeapon1[2],
	SS_classWeapon2[2],
	SS_classWeapon3[2]
};
static SS_ClassData[311 + 1][e_SS_CLASS_INFO];

enum e_SS_SPAWN_INFO
{
	SS_spawnTeam = NO_TEAM,
	SS_spawnWeapon1[2],
	SS_spawnWeapon2[2],
	SS_spawnWeapon3[2]
};
static SS_SpawnData[MAX_PLAYERS][e_SS_SPAWN_INFO];

enum e_SS_LAST_SHOT
{
  	SS_shotHittype,
   	SS_shotHitid,
    SS_shotHits,
 	bool:SS_shotReturn
}
static SS_LastShot[MAX_PLAYERS][e_SS_LAST_SHOT];
static SS_LastShotTicks[MAX_PLAYERS][10];
static SS_LastShotWeapons[MAX_PLAYERS][10];
static SS_LastShotIdx[MAX_PLAYERS];

static SS_LastHitTicks[MAX_PLAYERS][10];
static SS_LastHitWeapons[MAX_PLAYERS][10];
static SS_LastHitIdx[MAX_PLAYERS];

static SS_Classid[MAX_PLAYERS];
static SS_Teamid[MAX_PLAYERS];

static Float:SS_Health[MAX_PLAYERS];
static Float:SS_Armour[MAX_PLAYERS];
static SS_Money[MAX_PLAYERS];

static SS_LastExplosive[MAX_PLAYERS];
static SS_WeaponData[MAX_PLAYERS][13][2];
static SS_LastClick[MAX_PLAYERS];
static SS_LastClickWeapon[MAX_PLAYERS];

static SS_KnifedBy[MAX_PLAYERS];

static bool:SS_Update[MAX_PLAYERS];

static SS_StaticPickup[MAX_PICKUPS];

forward __SetVendingMachine(i, set);
public	__SetVendingMachine(i, set)
{
    SS_VendingMachineObject[i] = set;
}

stock EnableVendingMachines()
{
    for (new i, j = sizeof(SS_VendingMachine); i < j; i++)
	{
		#if defined STREAMER_TYPE_OBJECT
		    if (IsValidDynamicObject(SS_VendingMachineObject[i]))
		    {
		        DestroyDynamicObject(SS_VendingMachineObject[i]);
		    }
			SS_VendingMachineObject[i] = CreateDynamicObject(SS_VendingMachine[i][SS_vmModel], SS_VendingMachine[i][SS_vmPosX], SS_VendingMachine[i][SS_vmPosY], SS_VendingMachine[i][SS_vmPosZ], SS_VendingMachine[i][SS_vmRotX], SS_VendingMachine[i][SS_vmRotY], SS_VendingMachine[i][SS_vmRotZ], .interiorid = SS_VendingMachine[i][SS_vmInterior]);
		#else
		    if (IsValidObject(SS_VendingMachineObject[i]))
		    {
		        DestroyObject(SS_VendingMachineObject[i]);
		    }
			SS_VendingMachineObject[i] = CreateObject(SS_VendingMachine[i][SS_vmModel], SS_VendingMachine[i][SS_vmPosX], SS_VendingMachine[i][SS_vmPosY], SS_VendingMachine[i][SS_vmPosZ], SS_VendingMachine[i][SS_vmRotX], SS_VendingMachine[i][SS_vmRotY], SS_VendingMachine[i][SS_vmRotZ]);
		#endif
		
		CallRemoteFunction("__SetVendingMachine", "ii", i, SS_VendingMachineObject[i]);
	}
}

stock Float:SS_GetDistanceBetweenPoints(Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2)
{
	return floatadd(floatadd(floatsqroot(floatpower(floatsub(x1, x2), 2)), floatsqroot(floatpower(floatsub(y1, y2), 2))), floatsqroot(floatpower(floatsub(z1, z2), 2)));
}

stock SS_RemoveBuildingForPlayer(playerid, modelid, Float:fX, Float:fY, Float:fZ, Float:fRadius)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}
	
	for (new i, j = sizeof(SS_VendingMachine); i < j; i++)
	{
	    if (modelid == SS_VendingMachine[i][SS_vmModel])
	    {
		    if (SS_GetDistanceBetweenPoints(fX, fY, 0.0, SS_VendingMachine[i][SS_vmPosX], SS_VendingMachine[i][SS_vmPosY], 0.0) <= fRadius)
		    {
		        #if defined STREAMER_TYPE_OBJECT
				    if (IsValidDynamicObject(SS_VendingMachineObject[i]))
				    {
				        DestroyDynamicObject(SS_VendingMachineObject[i]);
				        return true;
				    }
				#else
				    if (IsValidObject(SS_VendingMachineObject[i]))
				    {
				        DestroyObject(SS_VendingMachineObject[i]);
				        return true;
				    }
				#endif
				
				break;
		    }
 		}
	}

	return RemoveBuildingForPlayer(playerid, modelid, fX, fY, fZ, fRadius);
}
#if defined _ALS_RemoveBuildingForPlayer
    #undef RemoveBuildingForPlayer
#else
	native OLD_RemoveBuildingForPlayer(playerid, modelid, Float:fX, Float:fY, Float:fZ, Float:fRadius) = RemoveBuildingForPlayer;
    #define _ALS_RemoveBuildingForPlayer
#endif
#define RemoveBuildingForPlayer SS_RemoveBuildingForPlayer

forward __SetPlayerTeam(playerid, teamid);
public 	__SetPlayerTeam(playerid, teamid)
{
    SS_Teamid[playerid] = teamid;
}

stock SS_SetPlayerTeam(playerid, teamid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerTeam", "ii", playerid, teamid);

	return true;
}
#if defined _ALS_SetPlayerTeam
    #undef SetPlayerTeam
#else
	native OLD_SetPlayerTeam(playerid, teamid) = SetPlayerTeam;
    #define _ALS_SetPlayerTeam
#endif
#define SetPlayerTeam SS_SetPlayerTeam

stock SS_GetPlayerTeam(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	return SS_Teamid[playerid];
}
#if defined _ALS_GetPlayerTeam
    #undef GetPlayerTeam
#else
	native OLD_GetPlayerTeam(playerid) = GetPlayerTeam;
    #define _ALS_GetPlayerTeam
#endif
#define GetPlayerTeam SS_GetPlayerTeam

forward __SetPlayerHealth(playerid, Float:health);
public 	__SetPlayerHealth(playerid, Float:health)
{
	if (health < 0.0)
	{
		health = 0.0;
	}
    SS_Health[playerid] = health;
}

stock SS_SetPlayerHealth(playerid, Float:health)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerHealth", "if", playerid, health);

	if (health > 100.0)
	{
	    return SetPlayerHealth(playerid, 100.0);
	}
	else
	{
	    return SetPlayerHealth(playerid, health);
	}
}
#if defined _ALS_SetPlayerHealth
    #undef SetPlayerHealth
#else
	native OLD_SetPlayerHealth(playerid, Float:health) = SetPlayerHealth;
    #define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth SS_SetPlayerHealth

stock SS_GetPlayerHealth(playerid, &Float:health)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	health = SS_Health[playerid];

	return true;
}
#if defined _ALS_GetPlayerHealth
    #undef GetPlayerHealth
#else
	native OLD_GetPlayerHealth(playerid, &Float:health) = GetPlayerHealth;
    #define _ALS_GetPlayerHealth
#endif
#define GetPlayerHealth SS_GetPlayerHealth

forward __SetPlayerArmour(playerid, Float:armour);
public 	__SetPlayerArmour(playerid, Float:armour)
{
	if (armour < 0.0)
	{
		armour = 0.0;
	}
    SS_Armour[playerid] = armour;
}

stock SS_SetPlayerArmour(playerid, Float:armour)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerArmour", "if", playerid, armour);

	if (armour > 100.0)
	{
	    return SetPlayerArmour(playerid, 100.0);
	}
	else
	{
	    return SetPlayerArmour(playerid, armour);
	}
}
#if defined _ALS_SetPlayerArmour
    #undef SetPlayerArmour
#else
	native OLD_SetPlayerArmour(playerid, Float:armour) = SetPlayerArmour;
    #define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour SS_SetPlayerArmour

stock SS_GetPlayerArmour(playerid, &Float:armour)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	armour = SS_Armour[playerid];

	return true;
}
#if defined _ALS_GetPlayerArmour
    #undef GetPlayerArmour
#else
	native OLD_GetPlayerArmour(playerid, &Float:armour) = GetPlayerArmour;
    #define _ALS_GetPlayerArmour
#endif
#define GetPlayerArmour SS_GetPlayerArmour

forward __SetPlayerMoney(playerid, money);
public 	__SetPlayerMoney(playerid, money)
{
    SS_Money[playerid] = money;
}

stock SS_GivePlayerMoney(playerid, money)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerMoney", "ii", playerid, money + SS_Money[playerid]);

	return GivePlayerMoney(playerid, SS_Money[playerid]);
}
#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
	native OLD_GivePlayerMoney(playerid, money) = GivePlayerMoney;
    #define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney SS_GivePlayerMoney

stock SS_ResetPlayerMoney(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerMoney", "ii", playerid, 0);

    return ResetPlayerMoney(playerid);
}
#if defined _ALS_ResetPlayerMoney
    #undef ResetPlayerMoney
#else
	native OLD_ResetPlayerMoney(playerid) = ResetPlayerMoney;
    #define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney SS_ResetPlayerMoney

stock SS_GetPlayerMoney(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return 0;
	}

	return SS_Money[playerid];
}
#if defined _ALS_GetPlayerMoney
    #undef GetPlayerMoney
#else
	native OLD_GetPlayerMoney(playerid) = GetPlayerMoney;
    #define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney SS_GetPlayerMoney

forward __SetPlayerWeapon(playerid, slot, weaponid, ammo);
public 	__SetPlayerWeapon(playerid, slot, weaponid, ammo)
{
    SS_WeaponData[playerid][slot][0] = weaponid;
    SS_WeaponData[playerid][slot][1] = ammo;
}

stock static SS_GetWeaponSlot(weaponid)
{
	switch (weaponid)
	{
		case 0, 1: return 0;
		case 2..9: return 1;
		case 10..15: return 10;
		case 16..18, 39: return 8;
		case 22..24: return 2;
		case 25..27: return 3;
		case 28, 29, 32: return 4;
		case 30, 31: return 5;
		case 33, 34: return 6;
		case 35..38: return 7;
		case 40: return 12;
		case 41..43: return 9;
		case 44..46: return 11;
	}
	return -1;
}

stock SS_GivePlayerWeapon(playerid, weaponid, ammo)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	new slot = SS_GetWeaponSlot(weaponid);
	if (slot == -1)
	{
	    return false;
	}

	CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, slot, weaponid, ammo + SS_WeaponData[playerid][slot][1]);

	return GivePlayerWeapon(playerid, weaponid, ammo);
}
#if defined _ALS_GivePlayerWeapon
    #undef GivePlayerWeapon
#else
	native OLD_GivePlayerWeapon(playerid, weaponid, ammo) = GivePlayerWeapon;
    #define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon SS_GivePlayerWeapon

stock SS_ResetPlayerWeapons(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	for (new i; i < 13; i++)
	{
		CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, 0, 0);
	}

	return ResetPlayerWeapons(playerid);
}
#if defined _ALS_ResetPlayerWeapons
    #undef ResetPlayerWeapons
#else
	native OLD_ResetPlayerWeapons(playerid) = ResetPlayerWeapons;
    #define _ALS_ResetPlayerWeapons
#endif
#define ResetPlayerWeapons SS_ResetPlayerWeapons

stock SS_GetPlayerWeaponData(playerid, slot, &weapons, &ammo)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	if (slot > 12 || slot < 0)
	{
	    return false;
	}

	weapons = SS_WeaponData[playerid][slot][0];
	ammo = SS_WeaponData[playerid][slot][1];

	return true;
}
#if defined _ALS_GetPlayerWeaponData
    #undef GetPlayerWeaponData
#else
	native OLD_GetPlayerWeaponData(playerid, slot, &weapons, &ammo) = GetPlayerWeaponData;
    #define _ALS_GetPlayerWeaponData
#endif
#define GetPlayerWeaponData SS_GetPlayerWeaponData

stock SS_SetPlayerAmmo(playerid, weaponid, ammo)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, SS_GetWeaponSlot(weaponid), weaponid, ammo);

    return SetPlayerAmmo(playerid, weaponid, ammo);
}
#if defined _ALS_SetPlayerAmmo
    #undef SetPlayerAmmo
#else
	native OLD_SetPlayerAmmo(playerid, weaponid, ammo) = SetPlayerAmmo;
    #define _ALS_SetPlayerAmmo
#endif
#define SetPlayerAmmo SS_SetPlayerAmmo

stock SS_GetPlayerAmmo(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return 0;
	}

	new slot = SS_GetWeaponSlot(GetPlayerWeapon(playerid));
	if (slot > 12 || slot < 0)
	{
	    return 0;
	}

	return SS_WeaponData[playerid][slot][1];
}
#if defined _ALS_GetPlayerAmmo
    #undef GetPlayerAmmo
#else
	native OLD_GetPlayerAmmo(playerid) = GetPlayerAmmo;
    #define _ALS_GetPlayerAmmo
#endif
#define GetPlayerAmmo SS_GetPlayerAmmo

stock SS_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new ret = AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

	SS_ClassData[ret][SS_classTeam] = NO_TEAM;
	SS_ClassData[ret][SS_classWeapon1][0] = weapon1;
	SS_ClassData[ret][SS_classWeapon1][1] = weapon1_ammo;
	SS_ClassData[ret][SS_classWeapon2][0] = weapon2;
	SS_ClassData[ret][SS_classWeapon2][1] = weapon2_ammo;
	SS_ClassData[ret][SS_classWeapon3][0] = weapon3;
	SS_ClassData[ret][SS_classWeapon3][1] = weapon3_ammo;

	return ret;
}
#if defined _ALS_AddPlayerClass
    #undef AddPlayerClass
#else
	native OLD_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = AddPlayerClass;
    #define _ALS_AddPlayerClass
#endif
#define AddPlayerClass SS_AddPlayerClass

stock SS_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new ret = AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

	SS_ClassData[ret][SS_classTeam] = teamid;
	SS_ClassData[ret][SS_classWeapon1][0] = weapon1;
	SS_ClassData[ret][SS_classWeapon1][1] = weapon1_ammo;
	SS_ClassData[ret][SS_classWeapon2][0] = weapon2;
	SS_ClassData[ret][SS_classWeapon2][1] = weapon2_ammo;
	SS_ClassData[ret][SS_classWeapon3][0] = weapon3;
	SS_ClassData[ret][SS_classWeapon3][1] = weapon3_ammo;

	return ret;
}
#if defined _ALS_AddPlayerClassEx
    #undef AddPlayerClass
#else
	native OLD_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = AddPlayerClassEx;
    #define _ALS_AddPlayerClassEx
#endif
#define AddPlayerClassEx SS_AddPlayerClassEx

forward __SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
public  __SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	SS_SpawnData[playerid][SS_spawnTeam] = team;
	SS_SpawnData[playerid][SS_spawnWeapon1][0] = weapon1;
	SS_SpawnData[playerid][SS_spawnWeapon1][1] = weapon1_ammo;
	SS_SpawnData[playerid][SS_spawnWeapon2][0] = weapon2;
	SS_SpawnData[playerid][SS_spawnWeapon2][1] = weapon2_ammo;
	SS_SpawnData[playerid][SS_spawnWeapon3][0] = weapon3;
	SS_SpawnData[playerid][SS_spawnWeapon3][1] = weapon3_ammo;
}

stock SS_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetSpawnInfo", "iiiffffiiiiii", playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

	return SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}
#if defined _ALS_SetSpawnInfo
    #undef SetSpawnInfo
#else
	native OLD_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = SetSpawnInfo;
    #define _ALS_SetSpawnInfo
#endif
#define SetSpawnInfo SS_SetSpawnInfo

public OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 955, 0.0, 0.0, 0.0, 20000.0); // CJ_EXT_SPRUNK
	RemoveBuildingForPlayer(playerid, 956, 0.0, 0.0, 0.0, 20000.0); // CJ_EXT_CANDY
	RemoveBuildingForPlayer(playerid, 1209, 0.0, 0.0, 0.0, 20000.0); // vendmach
	RemoveBuildingForPlayer(playerid, 1302, 0.0, 0.0, 0.0, 20000.0); // vendmachfd
	RemoveBuildingForPlayer(playerid, 1775, 0.0, 0.0, 0.0, 20000.0); // CJ_SPRUNK1
	RemoveBuildingForPlayer(playerid, 1776, 0.0, 0.0, 0.0, 20000.0); // CJ_CANDYVENDOR
	RemoveBuildingForPlayer(playerid, 1977, 0.0, 0.0, 0.0, 20000.0); // vendin3
	for (new i, j = sizeof(SS_VendingMachine); i < j; i++)
	{
		RemoveBuildingForPlayer(playerid, SS_VendingMachine[i][SS_vmModel], SS_VendingMachine[i][SS_vmPosX], SS_VendingMachine[i][SS_vmPosY], SS_VendingMachine[i][SS_vmPosZ], 1.0);
	}
	SS_VendingMachineTimer[playerid] = 0;

	SS_Health[playerid] = 100.0;
	SS_Armour[playerid] = 0.0;
	SS_Money[playerid] = 0;

	for (new i; i < 13; i++)
	{
		SS_WeaponData[playerid][i][0] = 0;
		SS_WeaponData[playerid][i][1] = 0;
	}
	SS_LastClick[playerid] = 0;
	SS_LastClickWeapon[playerid] = 0;

	SS_Classid[playerid] = 0;
	SS_Teamid[playerid] = NO_TEAM;

	SS_LastExplosive[playerid] = 0;

	SS_LastShotIdx[playerid] = 0;

	SS_LastHitIdx[playerid] = 0;

	if (GetPVarType(playerid, "SS_OnPlayerUpdate") == PLAYER_VARTYPE_NONE)
	{
		SS_Update[playerid] = true;
		SetPVarInt(playerid, "SS_OnPlayerUpdate", 1);
	}

	#if defined SS_OnPlayerConnect
		return SS_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect SS_OnPlayerConnect
#if defined SS_OnPlayerConnect
	forward SS_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	SS_Update[playerid] = false;
	DeletePVar(playerid, "SS_OnPlayerUpdate");

	#if defined SS_OnPlayerDisconnect
		return SS_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect SS_OnPlayerDisconnect
#if defined SS_OnPlayerDisconnect
	forward SS_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerRequestClass(playerid, classid)
{
	SS_Classid[playerid] = classid;

	#if defined SS_OnPlayerRequestClass
		return SS_OnPlayerRequestClass(playerid, classid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerRequestClass
    #undef OnPlayerRequestClass
#else
    #define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass SS_OnPlayerRequestClass
#if defined SS_OnPlayerRequestClass
	forward SS_OnPlayerRequestClass(playerid, classid);
#endif

public OnPlayerRequestSpawn(playerid)
{
	new ret = 1;
    #if defined SS_OnPlayerRequestSpawn
		ret = SS_OnPlayerRequestSpawn(playerid);
	#endif

    if (ret)
	{
		// Adjusting weapons according to classinfo
	    new weapon, ammo;
		for (new i; i < 13; i++)
		{
			OLD_GetPlayerWeaponData(playerid, i, weapon, ammo);
			if (weapon && ammo)
			{
				if (SS_ClassData[SS_Classid[playerid]][SS_classWeapon1][0] == weapon || SS_ClassData[playerid][SS_classWeapon1][1] != ammo)
				{
				    SS_WeaponData[playerid][i][0] = weapon;
    				SS_WeaponData[playerid][i][1] = SS_ClassData[SS_Classid[playerid]][SS_classWeapon1][1];
				}
				else if (SS_ClassData[SS_Classid[playerid]][SS_classWeapon2][1] == weapon || SS_ClassData[playerid][SS_classWeapon2][1] != ammo)
				{
				    SS_WeaponData[playerid][i][0] = weapon;
    				SS_WeaponData[playerid][i][1] = SS_ClassData[SS_Classid[playerid]][SS_classWeapon2][1];
				}
				else if (SS_ClassData[SS_Classid[playerid]][SS_classWeapon3][1] == weapon || SS_ClassData[playerid][SS_classWeapon3][1] != ammo)
				{
				    SS_WeaponData[playerid][i][0] = weapon;
    				SS_WeaponData[playerid][i][1] = SS_ClassData[SS_Classid[playerid]][SS_classWeapon3][1];
				}
				else
				{
				    OLD_SetPlayerAmmo(playerid, weapon, 0);
				    SS_WeaponData[playerid][i][0] = 0;
    				SS_WeaponData[playerid][i][1] = 0;
				}
			}
		}

		// Set class info team
		SS_Teamid[playerid] = SS_ClassData[playerid][SS_classTeam];
		OLD_SetPlayerTeam(playerid, 0);
	}

	return ret;
}
#if defined _ALS_OnPlayerRequestSpawn
    #undef OnPlayerRequestSpawn
#else
    #define _ALS_OnPlayerRequestSpawn
#endif
#define OnPlayerRequestSpawn SS_OnPlayerRequestSpawn
#if defined SS_OnPlayerRequestSpawn
	forward SS_OnPlayerRequestSpawn(playerid);
#endif

public OnPlayerSpawn(playerid)
{
    SS_Health[playerid] = 100.0;
    OLD_SetPlayerHealth(playerid, 100.0);

    SS_KnifedBy[playerid] = INVALID_PLAYER_ID;
    SS_LastShot[playerid][SS_shotHitid] = -1;

	// Adjusting weapons according to spawninfo
 	new weapon, ammo;
	for (new i; i < 13; i++)
	{
		OLD_GetPlayerWeaponData(playerid, i, weapon, ammo);
		if (weapon && ammo)
		{
			if (SS_SpawnData[playerid][SS_spawnWeapon1][0] == weapon || SS_SpawnData[playerid][SS_spawnWeapon1][1] != ammo)
			{
			    SS_WeaponData[playerid][i][0] = weapon;
    			SS_WeaponData[playerid][i][1] = SS_SpawnData[playerid][SS_spawnWeapon1][1];
			}
			else if (SS_SpawnData[playerid][SS_spawnWeapon2][1] == weapon || SS_SpawnData[playerid][SS_spawnWeapon2][1] != ammo)
			{
			    SS_WeaponData[playerid][i][0] = weapon;
    			SS_WeaponData[playerid][i][1] = SS_SpawnData[playerid][SS_spawnWeapon2][1];
			}
			else if (SS_SpawnData[playerid][SS_spawnWeapon3][1] == weapon || SS_SpawnData[playerid][SS_spawnWeapon3][1] != ammo)
			{
			    SS_WeaponData[playerid][i][0] = weapon;
    			SS_WeaponData[playerid][i][1] = SS_SpawnData[playerid][SS_spawnWeapon3][1];
			}
			else
			{
			    OLD_SetPlayerAmmo(playerid, weapon, 0);
			    SS_WeaponData[playerid][i][0] = 0;
    			SS_WeaponData[playerid][i][1] = 0;
			}
		}
	}

	// Set spawn info team
	SS_Teamid[playerid] = SS_SpawnData[playerid][SS_spawnTeam];
	OLD_SetPlayerTeam(playerid, 0);

	#if defined SS_OnPlayerSpawn
		return SS_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn SS_OnPlayerSpawn
#if defined SS_OnPlayerSpawn
	forward SS_OnPlayerSpawn(playerid);
#endif

stock static SS_AverageShootRate(playerid, SS_shots, &multiple_weapons = 0)// Credits to Slice
{
	new total = 0;
	new idx = SS_LastShotIdx[playerid];

	multiple_weapons = false;

	for (new i = SS_shots - 2; i >= 0; i--)
	{
		new prev_idx = (idx - i - 1) % sizeof(SS_LastShotTicks[]);

		// JIT plugin fix
		if (prev_idx < 0)
		{
			prev_idx += sizeof(SS_LastShotTicks[]);
		}

		new prev = SS_LastShotTicks[playerid][prev_idx];
		new prev_weap = SS_LastShotWeapons[playerid][prev_idx];
		new this_idx = (idx - i) % sizeof(SS_LastShotTicks[]);

		// JIT plugin fix
		if (this_idx < 0)
		{
			this_idx += sizeof(SS_LastShotTicks[]);
		}

		if (prev_weap != SS_LastShotWeapons[playerid][this_idx])
		{
			multiple_weapons = true;
		}

		total += SS_LastShotTicks[playerid][this_idx] - prev;
	}

	return total / (SS_shots - 1);
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	SS_LastShot[playerid][SS_shotHits] = 0;

	// Decrease the ammo through the script to maintain player weapon data record
	if ((WEAPON_COLT45 <= weaponid <= WEAPON_SNIPER) || weaponid == WEAPON_MINIGUN)
	{
		new slot = SS_GetWeaponSlot(weaponid);

		SS_WeaponData[playerid][slot][1]--;
		if (! SS_WeaponData[playerid][slot][1])
		{
		 	SS_WeaponData[playerid][slot][0] = 0;
		    SS_WeaponData[playerid][slot][1] = 0;
	    }
	}

	// Check for distance of origin and hit
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);

	new Float:origin[3], Float:hit[3];
	GetPlayerLastShotVectors(playerid, origin[0], origin[1], origin[2], hit[0], hit[1], hit[2]);

	new Float:length = VectorSize(origin[0] - hit[0], origin[1] - hit[1], origin[2] - hit[2]);
	new Float:origin_dist = VectorSize(origin[0] - x, origin[1] - y, origin[2] - z);

	if (origin_dist > 15.0)
	{
		new bool:in_vehicle = bool:(IsPlayerInAnyVehicle(hitid) || GetPlayerSurfingVehicleID(playerid));

		if ((! in_vehicle && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID) || origin_dist > 50.0)
		{
			ClearAnimations(playerid);
			return 0;
		}
	}

	// Shot exceeding the max range?
	if (hittype != BULLET_HIT_TYPE_NONE)
	{
		if (length > SS_WeaponRange[weaponid])
		{
			if (hittype == BULLET_HIT_TYPE_PLAYER)
			{
				ClearAnimations(playerid);
				return 0;
			}
		}
		if (hittype == BULLET_HIT_TYPE_PLAYER)
		{
			if (IsPlayerInAnyVehicle(playerid) && GetPlayerVehicleID(playerid) == GetPlayerVehicleID(hitid))
			{
				ClearAnimations(playerid);
				return 0;
			}

			new Float:dist = GetPlayerDistanceFromPoint(hitid, hit[0], hit[1], hit[2]);
			new bool:in_vehicle = bool:IsPlayerInAnyVehicle(hitid);

			if ((! in_vehicle && dist > 20.0) || dist > 50.0)
			{
				ClearAnimations(playerid);
				return 0;
			}
		}
	}

	new tick = GetTickCount();
	if (tick == 0) tick = 1;

	new idx = (SS_LastShotIdx[playerid] + 1) % sizeof(SS_LastShotTicks[]);

	// JIT plugin fix
	if (idx < 0)
	{
		idx += sizeof(SS_LastShotTicks[]);
	}

	SS_LastShotIdx[playerid] = idx;
	SS_LastShotTicks[playerid][idx] = tick;
	SS_LastShotWeapons[playerid][idx] = weaponid;

	SS_LastShot[playerid][SS_shotHittype] = hittype;
	SS_LastShot[playerid][SS_shotHitid] = hitid;
	SS_LastShot[playerid][SS_shotHits] = 0;
	#if defined SS_OnPlayerWeaponShot
		SS_LastShot[playerid][SS_shotReturn] = bool:SS_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
	#else
		SS_LastShot[playerid][SS_shotReturn] = true;
	#endif

	// Check for rapid fire / Bullet flood
	new multiple_weapons;
	new avg_rate = SS_AverageShootRate(playerid, 5, multiple_weapons);

	// Bullet flood?
	// Could be either a cheat or just lag
	if (avg_rate != -1)
	{
		if (multiple_weapons)
		{
			if (avg_rate < 100)
			{
				ClearAnimations(playerid);
				return 0;
			}
		}
		else if (SS_WeaponShootRate[weaponid] - avg_rate > 20)
		{
			ClearAnimations(playerid);
			return 0;
		}
	}

	// Serversided vehicle damage (only health)
	if (hittype == BULLET_HIT_TYPE_VEHICLE)
	{
		new vehicleid = GetPlayerVehicleID(playerid);

		// Shouldn't be possible to damage the vehicle you're in
		if (hitid == vehicleid)
		{
			ClearAnimations(playerid);
			return 0;
		}

		if (SS_LastShot[playerid][SS_shotReturn])
		{
			for (new i, j = GetPlayerPoolSize(); i <= j; i++)
			{
				if (i == playerid || ! IsPlayerConnected(i))
				{
					continue;
				}

				if (GetPlayerVehicleID(i) != hitid)
				{
					continue;
				}

				new seat = GetPlayerVehicleSeat(i);
				if (seat == 0)
				{
					new Float:health;
					GetVehicleHealth(hitid, health);

                    // Set final amount
					switch (weaponid)
					{
						case WEAPON_MOLTOV,
							 WEAPON_COLT45..WEAPON_DEAGLE,
							 WEAPON_UZI..WEAPON_SNIPER,
							 WEAPON_MINIGUN,
							 WEAPON_PISTOLWHIP,
							 WEAPON_VEHICLE,
							 WEAPON_HELIBLADES:
						{
						    health -= SS_WeaponDamage[weaponid] * 3.0;
						}

						case WEAPON_SHOTGSPA:
					 	{
							GetVehiclePos(hitid, x, y, z);

							new Float:distance;
							distance = SS_GetDistanceBetweenPoints(fX, fZ, fY, x, y, z);

							new Float:bullets;
							bullets = 15 / distance;

					 	    health -= (SS_WeaponDamage[weaponid] * bullets) * 3.0;
						}

						case WEAPON_SHOTGUN,
							 WEAPON_SAWEDOFF:
					 	{
							GetVehiclePos(hitid, x, y, z);

							new Float:distance;
							distance = SS_GetDistanceBetweenPoints(fX, fZ, fY, x, y, z);

							new Float:bullets;
							bullets = 8 / distance;

					 	    health -= (SS_WeaponDamage[weaponid] * bullets) * 3.0;
						}
					}

					if (health <= 0.0)
					{
						health = 0.0;
					}
					SetVehicleHealth(hitid, health);
					
					return 0;
				}
			}
		}
	}

	return SS_LastShot[playerid][SS_shotReturn];
}
#if defined _ALS_OnPlayerWeaponShot
    #undef OnPlayerWeaponShot
#else
    #define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot SS_OnPlayerWeaponShot
#if defined SS_OnPlayerWeaponShot
	forward SS_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif

stock static SS_AverageHitRate(playerid, hits, &multiple_weapons = 0)// Credits to Slice
{
	new total = 0;
	new idx = SS_LastHitIdx[playerid];

	multiple_weapons = false;

	for (new i = hits - 2; i >= 0; i--)
	{
		new prev_idx = (idx - i - 1) % sizeof(SS_LastHitTicks[]);

		// JIT plugin fix
		if (prev_idx < 0)
		{
			prev_idx += sizeof(SS_LastHitTicks[]);
		}

		new prev = SS_LastHitTicks[playerid][prev_idx];
		new prev_weap = SS_LastHitWeapons[playerid][prev_idx];
		new this_idx = (idx - i) % sizeof(SS_LastHitTicks[]);

		// JIT plugin fix
		if (this_idx < 0)
		{
			this_idx += sizeof(SS_LastHitTicks[]);
		}

		if (prev_weap != SS_LastHitWeapons[playerid][this_idx])
		{
			multiple_weapons = true;
		}

		total += SS_LastHitTicks[playerid][this_idx] - prev;
	}

	return total / (hits - 1);
}

stock static bool:SS_ProcessDamage(&playerid, &issuerid, &Float:amount, &weaponid, &bodypart) //Credits to Slice, Modified by me
{
	// Amount can't be negative
	if (amount < 0.0)
	{
	    return false;
	}

    // Prevent climb bug
	if (weaponid == WEAPON_COLLISION)
	{
		if (1061 <= GetPlayerAnimationIndex(playerid) <= 1067)
		{
			return false;
		}
	}

    // Prevent stealth knives, can be any weapon
	if (_:amount == _:1833.33154296875)
	{
		return false;
	}

	// Detect original weapons type
    if (issuerid != INVALID_PLAYER_ID)
    {
        switch (weaponid)
        {
            case WEAPON_COLT45..WEAPON_SNIPER, WEAPON_SPRAYCAN, WEAPON_FIREEXTINGUISHER:
            {
				if (_:amount == _:2.6400001049041748046875)
				{
					bodypart = 3;
					weaponid = WEAPON_PISTOLWHIP;
				}
			}
			case WEAPON_HELIBLADES:
			{
			    if (_:amount != _:330.0)
			    {
			        weaponid = WEAPON_CARPARK;
			    }
			}
		}
	}

	if (weaponid != WEAPON_PISTOLWHIP)
	{
		switch (amount)
		{
			case 1.32000005245208740234375,
			     1.650000095367431640625,
			     1.980000019073486328125,
			     2.3100001811981201171875,
			     2.6400001049041748046875,
			     2.9700000286102294921875,
			     3.96000003814697265625,
			     4.28999996185302734375,
			     4.62000036239624023437,
			     5.280000209808349609375:
		 	{
				if (! ((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP))
				{
					weaponid = WEAPON_UNARMED;
				}
			}

			case 6.6000003814697265625:
			{
				if (! ((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP))
				{
					switch (weaponid)
					{
						case WEAPON_UZI, WEAPON_TEC9, WEAPON_CHAINSAW, WEAPON_SHOTGUN, WEAPON_SAWEDOFF:
					 	{
					 	}
						default:
						{
							weaponid = WEAPON_UNARMED;
						}
					}
				}
			}

			case 54.12000274658203125:
			{
				if (! ((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP))
				{
					weaponid = WEAPON_UNARMED;
					amount = 1.32000005245208740234375;
				}
			}

			default:
			{
			    if ((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP)
				{
				    amount = 1.32000005245208740234375;
				}
			}
		}
	}

	// Detecting what caused the damage
	if (weaponid == WEAPON_EXPLOSION)
	{
		if (issuerid != INVALID_PLAYER_ID && GetPlayerState(issuerid) != PLAYER_STATE_DRIVER && SS_LastExplosive[issuerid])
		{
			weaponid = SS_LastExplosive[playerid];
		}
	}

	new Float:distance;
	// Check for valid range shots
	if (issuerid != INVALID_PLAYER_ID)
	{
		if (SS_WeaponRange[weaponid] != 0.0)
		{
			new Float:x, Float:y, Float:z;
			GetPlayerPos(issuerid, x, y, z);

			distance = GetPlayerDistanceFromPoint(playerid, x, y, z);
			if (distance > SS_WeaponRange[weaponid] + 2.0)
		  	{
				return false;
			}
		}
	}

	// Adjust damage from animation bugs
	switch (amount)
	{
		case 3.63000011444091796875,
		     5.940000057220458984375,
		     5.610000133514404296875:
	 	{
			amount = 2.6400001049041748046875;
		}

		case 3.30000019073486328125:
		{
			if (weaponid != WEAPON_SHOTGUN && weaponid != WEAPON_SAWEDOFF)
			{
				amount = 2.6400001049041748046875;
			}
		}

		case 4.950000286102294921875:
		{
			if ((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP)
			{
				amount = 2.6400001049041748046875;
			}
		}

		case 6.270000457763671875,
		     6.93000030517578125,
		     7.2600002288818359375,
		     7.9200000762939453125,
		     8.5799999237060546875,
		     9.24000072479248046875,
		     11.88000011444091796875,
		     11.22000026702880859375:
	 	{
			amount = 2.6400001049041748046875;
		}

		case 9.90000057220458984375:
		{
			switch (weaponid)
			{
				case WEAPON_VEHICLE, WEAPON_VEHICLE_M4, WEAPON_AK47, WEAPON_M4, WEAPON_SHOTGUN, WEAPON_SAWEDOFF, WEAPON_SHOTGSPA:
				{
				}
				default:
				{
					amount = 6.6000003814697265625;
				}
			}
		}
	}

	// Check chainsaw damage
	if (weaponid == WEAPON_CHAINSAW)
	{
		switch (amount)
		{
			case 6.6000003814697265625,
			     13.5300006866455078125,
			     16.1700000762939453125,
			     26.40000152587890625,
			     27.060001373291015625:
		 	{
			}

			default:
			{
				amount = SS_WeaponDamage[WEAPON_CHAINSAW];
			}
		}
	}

	// Set final amount
	switch (weaponid)
	{
	    case WEAPON_DROWN,
			 WEAPON_COLLISION,
			 WEAPON_EXPLOSION,
			 WEAPON_FLAMETHROWER,
			 WEAPON_CARPARK,
			 WEAPON_SPRAYCAN,
			 WEAPON_FIREEXTINGUISHER:
	    {
	    	if (amount > SS_WeaponDamage[weaponid])
			{
				amount = SS_WeaponDamage[weaponid];
			}
	    }

		case WEAPON_GRENADE,
			 WEAPON_ROCKETLAUNCHER,
			 WEAPON_HEATSEEKER,
			 WEAPON_SATCHEL:
		{
			if (amount > SS_WeaponDamage[weaponid])
			{
		    	amount = SS_WeaponDamage[weaponid] / distance;
		    }
		}

		case WEAPON_MOLTOV,
			 WEAPON_COLT45..WEAPON_DEAGLE,
			 WEAPON_UZI..WEAPON_SNIPER,
			 WEAPON_MINIGUN,
			 WEAPON_PISTOLWHIP,
			 WEAPON_VEHICLE,
			 WEAPON_HELIBLADES:
		{
		    amount = SS_WeaponDamage[weaponid];
		}

		case WEAPON_SHOTGSPA:
	 	{
	 	    new Float:bullets = amount / 4.950000286102294921875;
			if (8.0 - bullets < -0.05)
			{
				return false;
			}

			new Float:f = floatfract(bullets);
			if (f > 0.01 && f < 0.99)
			{
				return false;
			}

	 	    amount = SS_WeaponDamage[weaponid] * bullets;
		}

		case WEAPON_SHOTGUN,
			 WEAPON_SAWEDOFF:
	 	{
	 	    new Float:bullets = amount / 3.30000019073486328125;
			if (15.0 - bullets < -0.05)
			{
				return false;
			}

			new Float:f = floatfract(bullets);
			if (f > 0.01 && f < 0.99)
			{
				return false;
			}

	 	    amount = SS_WeaponDamage[weaponid] * bullets;
		}
	}

	// Valid damage was given
	return true;
}

stock static bool:HasSameTeam(playerid, otherid)
{
	if (SS_Teamid[playerid] == NO_TEAM || SS_Teamid[otherid] == NO_TEAM)
	{
		return false;
	}

	return bool:(SS_Teamid[playerid] == SS_Teamid[otherid]);
}


public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	new tick = GetTickCount();
	if (tick == 0) tick = 1;

	new idx = (SS_LastHitIdx[playerid] + 1) % sizeof(SS_LastHitTicks[]);

	// JIT plugin fix
	if (idx < 0)
	{
		idx += sizeof(SS_LastHitTicks[]);
	}

	SS_LastHitIdx[playerid] = idx;
	SS_LastHitTicks[playerid][idx] = tick;
	SS_LastHitWeapons[playerid][idx] = weaponid;

	// Check for rapid fire / Bullet flood
	new multiple_weapons;
	new avg_rate = SS_AverageHitRate(playerid, 5, multiple_weapons);

	// Hit issue flood?
	// Could be either a cheat or just lag
	if (avg_rate != -1)
	{
		if (multiple_weapons)
		{
			if (avg_rate < 100)
			{
				ClearAnimations(playerid);
				return 0;
			}
		}
		else if (SS_WeaponShootRate[weaponid] - avg_rate > 20)
		{
			ClearAnimations(playerid);
			return 0;
		}
	}

	// Additional checks
	if (damagedid != INVALID_PLAYER_ID)
	{
		// Check for OnPlayerWeaponShot, if it returned 0, that means no damage is given
	    if (SS_LastShot[playerid][SS_shotHittype] == BULLET_HIT_TYPE_PLAYER && SS_LastShot[playerid][SS_shotHitid] == damagedid)
	    {
	        if (! SS_LastShot[playerid][SS_shotReturn])
	        {
	            SS_LastShot[playerid][SS_shotReturn] = true;
	            SS_LastShot[playerid][SS_shotHitid] = -1;

				#if defined SS_OnPlayerGiveDamage
					return SS_OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
				#else
					return 1;
				#endif
	        }
	    }
		// Check for same teams
		if (HasSameTeam(playerid, damagedid))
		{
		    #if defined SS_OnPlayerGiveDamage
				return SS_OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
			#else
				return 1;
			#endif
		}
	}

	// Detect invalid shots fired, multiple hits and so on
    if (((WEAPON_COLT45 <= weaponid <= WEAPON_SNIPER) || weaponid == WEAPON_MINIGUN) && _:amount != _:2.6400001049041748046875 && ! (IsPlayerInAnyVehicle(playerid) && GetPlayerVehicleSeat(playerid) == 0))
	{
		if (WEAPON_SHOTGUN <= weaponid <= WEAPON_SHOTGSPA)
		{
			// Let's assume someone won't hit 3 players with 1 shotgun shot, and that one OnPlayerWeaponShot can be out of sync
			if (SS_LastShot[playerid][SS_shotHits] >= 3)
			{
				SS_LastShot[playerid][SS_shotHits] += 1;
				ClearAnimations(playerid);
			    return 0;
			}
		}
		else if (SS_LastShot[playerid][SS_shotHits] > 0)
		{
			// Sniper doesn't always send OnPlayerWeaponShot
			if (SS_LastShot[playerid][SS_shotHits] > 4 && weaponid != WEAPON_SNIPER)
			{
				SS_LastShot[playerid][SS_shotHits] += 1;
				ClearAnimations(playerid);
			    return 0;
			}
		}

		SS_LastShot[playerid][SS_shotHits] += 1;
	}

	#if defined SS_OnPlayerGiveDamage
		return SS_OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerGiveDamage
    #undef OnPlayerGiveDamage
#else
    #define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage SS_OnPlayerGiveDamage
#if defined SS_OnPlayerGiveDamage
	forward SS_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);
#endif

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	// Process damage
	if (weaponid != WEAPON_KNIFE && amount > SS_WeaponDamage[WEAPON_KNIFE])
	{
		if (! SS_ProcessDamage(playerid, issuerid, amount, weaponid, bodypart))
		{
			ClearAnimations(issuerid);
		    return 0;
		}
	}

	if (issuerid != INVALID_PLAYER_ID)
	{
		// Check for OnPlayerWeaponShot, if it returned 0, that means no damage is given
	    if (SS_LastShot[issuerid][SS_shotHittype] == BULLET_HIT_TYPE_PLAYER && SS_LastShot[issuerid][SS_shotHitid] == playerid)
	    {
	        if (! SS_LastShot[issuerid][SS_shotReturn])
	        {
	            SS_LastShot[issuerid][SS_shotReturn] = true;
	            SS_LastShot[issuerid][SS_shotHitid] = -1;

				#if defined SS_OnPlayerTakeDamage
					return SS_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
				#else
					return 1;
				#endif
	        }
	    }
		// Check for same teams
		if (HasSameTeam(playerid, issuerid))
		{
			#if defined SS_OnPlayerTakeDamage
				return SS_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
			#else
				return 1;
			#endif
		}
	}

	// Process knife stab
	if (weaponid == WEAPON_KNIFE && _:amount == _:0.0)
	{
	    if (GetPVarType(playerid, "SS_OnPlayerKnifed") == PLAYER_VARTYPE_NONE)
		{
			SetPVarInt(playerid, "SS_OnPlayerKnifed", SetTimerEx("SS_OnPlayerKnifed", 3000 + GetPlayerPing(playerid), false, "ii", playerid, issuerid));
		}
		else
		{
		    #if defined SS_OnPlayerTakeDamage
				return SS_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
			#else
				return 1;
			#endif
		}
	}

	// If the damage is valid, reduce armour or health
	if (weaponid == WEAPON_COLLISION)
	{
	    SetPlayerHealth(playerid, SS_Health[playerid] - amount);
	}
	else
	{
	    if (amount >= SS_Armour[playerid] + SS_Health[playerid])
	    {
		    SetPlayerArmour(playerid, 0.0);
	    	SetPlayerHealth(playerid, 0.0);
	    }
	    else
	    {
	        if (SS_Armour[playerid])
			{
			    new Float:loss = SS_Armour[playerid] - amount;
   				SetPlayerArmour(playerid, SS_Armour[playerid] - amount);

				if (loss < 0.0)
				{
				    SetPlayerHealth(playerid, SS_Health[playerid] + loss);
				}
			}
			else
			{
			    SetPlayerHealth(playerid, SS_Health[playerid] - amount);
			}
	    }
    }

	#if defined SS_OnPlayerTakeDamage
		return SS_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerTakeDamage
    #undef OnPlayerTakeDamage
#else
    #define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage SS_OnPlayerTakeDamage
#if defined SS_OnPlayerTakeDamage
	forward SS_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);
#endif

forward SS_OnPlayerKnifed(playerid, killerid);
public  SS_OnPlayerKnifed(playerid, killerid)
{
	CallRemoteFunction("SS_OnPlayerKnifeComplete", "ii", playerid, killerid);

	DeletePVar(playerid, "SS_OnPlayerKnifed");
}

forward SS_OnPlayerKnifeComplete(playerid, killerid);
public  SS_OnPlayerKnifeComplete(playerid, killerid)
{
	SS_Armour[playerid] = 0.0;
	OLD_SetPlayerArmour(playerid, 0.0);

	SS_Health[playerid] = 0.0;
    OLD_SetPlayerHealth(playerid, 0.0);

	SS_KnifedBy[playerid] = killerid;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	SS_Health[playerid] = 0.0;
	SS_Armour[playerid] = 0.0;

	// Playerid was knifed
	if (SS_KnifedBy[playerid] != INVALID_PLAYER_ID)
	{
	    killerid = SS_KnifedBy[playerid];
	    reason = 4;
	}

	#if defined SS_OnPlayerDeath
		return SS_OnPlayerDeath(playerid, killerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath SS_OnPlayerDeath
#if defined SS_OnPlayerDeath
	forward SS_OnPlayerDeath(playerid, killerid, reason);
#endif

public OnPlayerUpdate(playerid)
{
	if (SS_Update[playerid])
	{
		// Check for health hack
		new Float:health;
		OLD_GetPlayerHealth(playerid, health);
		if (SS_Health[playerid] > 100.0 && health < 100.0)
		{
			OLD_SetPlayerHealth(playerid, 100.0);
		}
		else if (health != SS_Health[playerid])
		{
		    OLD_SetPlayerHealth(playerid, SS_Health[playerid]);
		}

		// Check for armour hack
		new Float:armour;
		OLD_GetPlayerArmour(playerid, armour);
		if (SS_Armour[playerid] > 100.0 && armour < 100.0)
		{
			OLD_SetPlayerArmour(playerid, 100.0);
		}
		else if (armour != SS_Armour[playerid])
		{
		    OLD_SetPlayerArmour(playerid, SS_Armour[playerid]);
		}

		// Check for money hack
		if (OLD_GetPlayerMoney(playerid) != SS_Money[playerid])
		{
		    OLD_ResetPlayerMoney(playerid);
			OLD_GivePlayerMoney(playerid, SS_Money[playerid]);
		}

		//Weapons check
		new weapon = GetPlayerWeapon(playerid);
		new slot;
		if (SS_LastClickWeapon[playerid])
		{
			switch (SS_LastClickWeapon[playerid])
			{
				case WEAPON_TEARGAS, WEAPON_MOLTOV, WEAPON_GRENADE, WEAPON_SATCHEL:
				{
				    if (GetTickCount() - SS_LastClick[playerid] < 430)
					{
					    if (weapon != SS_LastClickWeapon[playerid])
					    {
					        SS_LastClickWeapon[playerid] = 0;
					    }
					    else
					    {
					        if (! (644 <= GetPlayerAnimationIndex(playerid) <= 646))
					        {
					        	SS_LastClickWeapon[playerid] = 0;
					        }
					    }
					}
					else
					{
					    if (SS_LastClickWeapon[playerid] == WEAPON_GRENADE || SS_LastClickWeapon[playerid] == WEAPON_SATCHEL)
						{
							SS_LastExplosive[playerid] = SS_LastClickWeapon[playerid];
						}

						slot = SS_GetWeaponSlot(SS_LastClickWeapon[playerid]);
						SS_WeaponData[playerid][slot][1]--;
						if (! SS_WeaponData[playerid][slot][1])
						{
							SS_WeaponData[playerid][slot][0] = 0;
							SS_WeaponData[playerid][slot][1] = 0;
						}

						SS_LastClickWeapon[playerid] = 0;
					}
				}
			}
		}
		if (! SS_LastClickWeapon[playerid])
		{
			slot = SS_GetWeaponSlot(weapon);

			if (SS_WeaponData[playerid][slot][0] != weapon)
			{
				OLD_SetPlayerAmmo(playerid, weapon, 0);
				OLD_GivePlayerWeapon(playerid, SS_WeaponData[playerid][slot][0], SS_WeaponData[playerid][slot][1]);
			}
			else
			{
			    switch (weapon)
			    {
					case WEAPON_GRENADE..WEAPON_MOLTOV, WEAPON_COLT45..WEAPON_SNIPER, WEAPON_MINIGUN, WEAPON_SATCHEL:
			    	{
						if (SS_WeaponData[playerid][slot][1] != OLD_GetPlayerAmmo(playerid))
						{
							OLD_SetPlayerAmmo(playerid, weapon, SS_WeaponData[playerid][slot][1]);
						}
					}
					default:
					{
						if (OLD_GetPlayerAmmo(playerid) > SS_WeaponData[playerid][slot][1])
						{
							OLD_SetPlayerAmmo(playerid, weapon, SS_WeaponData[playerid][slot][1]);
						}
					}
				}
			}
		}
	}

	#if defined SS_OnPlayerUpdate
		return SS_OnPlayerUpdate(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate SS_OnPlayerUpdate
#if defined SS_OnPlayerUpdate
	forward SS_OnPlayerUpdate(playerid);
#endif

#if ! defined KEY_AIM
	#define KEY_AIM (128)
#endif
#if ! defined PRESSED
	#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif
/*
#if ! defined HOLDING
	#define HOLDING(%0) ((newkeys & (%0)) == (%0))
#endif
#if ! defined RELEASED
	#define RELEASED(%0) (((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#endif
*/
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
	    if (SS_Update[playerid])
	    {
		    if (PRESSED(KEY_SECONDARY_ATTACK))
		    {
			    if (GetPlayerAnimationIndex(playerid) != 1660 && ! SS_VendingMachineTimer[playerid])
				{
		  			new interiorid = GetPlayerInterior(playerid);
		  			
					new Float:z;
                   	GetPlayerPos(playerid, z, z, z);
                   	
					for (new i, j = sizeof(SS_VendingMachine); i < j; i++)
					{
					    #if defined STREAMER_TYPE_OBJECT
						    if (IsValidDynamicObject(SS_VendingMachineObject[i]))
						    {
						        continue;
						    }
						#else
						    if (IsValidObject(SS_VendingMachineObject[i]))
						    {
						        continue;
						    }
						#endif
					    
						if (interiorid != SS_VendingMachine[i][SS_vmInterior])
		    			{
						    continue;
						}

						if (! IsPlayerInRangeOfPoint(playerid, 0.5, SS_VendingMachine[i][SS_vmFrontX], SS_VendingMachine[i][SS_vmFrontY], z))
						{
							continue;
						}
						
						if (floatabs(z - SS_VendingMachine[i][SS_vmPosZ]) > 1.5)
						{
							continue;
						}

					    if (SS_Money[playerid] <= 0)
					    {
					        PlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
					        break;
					    }

						SetPlayerPos(playerid, SS_VendingMachine[i][SS_vmFrontX], SS_VendingMachine[i][SS_vmFrontY], z);
                    	SetPlayerFacingAngle(playerid, SS_VendingMachine[i][SS_vmRotZ]);
                    	
                        ApplyAnimation(playerid, "VENDING", "VEND_USE", 4.1, 0, 0, 1, 0, 0, 1);
                        
                        PlayerPlaySound(playerid, 42600, 0.0, 0.0, 0.0);

						SS_VendingMachineTimer[playerid] = SetTimerEx("OnPlayerUseVendingMachine", 2500, false, "i", playerid);
						GivePlayerMoney(playerid, -1);

						break;
					}
				}
			}
			else if (newkeys & KEY_FIRE)
			{
			    new weaponid = GetPlayerWeapon(playerid);
				switch (weaponid)
				{
					case WEAPON_TEARGAS, WEAPON_MOLTOV, WEAPON_GRENADE, WEAPON_SATCHEL:
					{
					    if (! SS_LastClickWeapon[playerid])
					    {
					        SS_LastClickWeapon[playerid] = weaponid;
					    	SS_LastClick[playerid] = GetTickCount();
					    }
					}
					case WEAPON_ROCKETLAUNCHER, WEAPON_HEATSEEKER:
					{
					    SS_LastExplosive[playerid] = weaponid;
					}
				}
			}
		}	
	}

	#if defined SS_OnPlayerKeyStateChange
		return SS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange SS_OnPlayerKeyStateChange
#if defined SS_OnPlayerKeyStateChange
	forward SS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

forward OnPlayerUseVendingMachine(playerid);
public  OnPlayerUseVendingMachine(playerid)
{
	if (SS_Health[playerid] < 100.0)
	{
	    SetPlayerHealth(playerid, (100.0 - SS_Health[playerid] >= 35.0) ? (SS_Health[playerid] + 35.0) : (SS_Health[playerid] + (100.0 - SS_Health[playerid])));
 	}
	SS_VendingMachineTimer[playerid] = 0;
}

stock static SS_GetModelWeaponID(weaponid)
{
	switch (weaponid)
	{
	    case 331: return 1;
	    case 333: return 2;
	    case 334: return 3;
	    case 335: return 4;
	    case 336: return 5;
	    case 337: return 6;
	    case 338: return 7;
	    case 339: return 8;
	    case 341: return 9;
	    case 321: return 10;
	    case 322: return 11;
	    case 323: return 12;
	    case 324: return 13;
	    case 325: return 14;
	    case 326: return 15;
	    case 342: return 16;
	    case 343: return 17;
	    case 344: return 18;
	    case 346: return 22;
	    case 347: return 23;
	    case 348: return 24;
	    case 349: return 25;
	    case 350: return 26;
	    case 351: return 27;
	    case 352: return 28;
	    case 353: return 29;
	    case 355: return 30;
	    case 356: return 31;
	    case 372: return 32;
	    case 357: return 33;
	    case 358: return 34;
	    case 359: return 35;
	    case 360: return 36;
	    case 361: return 37;
	    case 362: return 38;
	    case 363: return 39;
	    case 364: return 40;
	    case 365: return 41;
	    case 366: return 42;
	    case 367: return 43;
	    case 368: return 44;
	    case 369: return 45;
	    case 371: return 46;
	}
	return 0;
}

forward __SetStaticPickup(pickupid, model);
public  __SetStaticPickup(pickupid, model)
{
    SS_StaticPickup[pickupid] = model;
}

stock SS_AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, Virtualworld)
{
	switch (model)
	{
	    case 1240, 1242, 321..369, 371, 372:
	    {
   		}

     	default:
     	{
     	    return AddStaticPickup(model, type, X, Y, Z, Virtualworld);
     	}
	}

	new ret = CreatePickup(model, type, X, Y, Z, Virtualworld);
	if (ret == -1)
	{
	    return false;
	}

	CallRemoteFunction("__SetStaticPickup", "ii", ret, model);

	return true;
}
#if defined _ALS_AddStaticPickup
    #undef AddStaticPickup
#else
	native OLD_AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, Virtualworld) = AddStaticPickup;
    #define _ALS_AddStaticPickup
#endif
#define AddStaticPickup SS_AddStaticPickup

stock SS_CreatePickup(model, type, Float:X, Float:Y, Float:Z, Virtualworld)
{
    if (type == 1)
	{
 		return CreatePickup(model, type, X, Y, Z, Virtualworld);
	}

	switch (model)
	{
	    case 1240, 1242, 321..369, 371, 372:
	    {
   		}

     	default:
     	{
     	    return CreatePickup(model, type, X, Y, Z, Virtualworld);
     	}
	}

	new ret = CreatePickup(model, type, X, Y, Z, Virtualworld);
	if (ret == -1)
	{
	    return false;
	}

	CallRemoteFunction("__SetStaticPickup", "ii", ret, model);

	return true;
}
#if defined _ALS_CreatePickup
    #undef CreatePickup
#else
	native OLD_CreatePickup(model, type, Float:X, Float:Y, Float:Z, Virtualworld) = CreatePickup;
    #define _ALS_CreatePickup
#endif
#define CreatePickup SS_CreatePickup

stock SS_DestroyPickup(pickupid)
{
	if (SS_StaticPickup[pickupid])
	{
		CallRemoteFunction("__SetStaticPickup", "ii", pickupid, 0);
	}

	return DestroyPickup(pickupid);
}
#if defined _ALS_DestroyPickup
    #undef DestroyPickup
#else
	native OLD_DestroyPickup(pickupid) = DestroyPickup;
    #define _ALS_DestroyPickup
#endif
#define DestroyPickup SS_DestroyPickup

public OnPlayerPickUpPickup(playerid, pickupid)
{
	// Custom static pickups
	switch (SS_StaticPickup[pickupid])
 	{
  		case 1240 :
	    {
     		if (SS_Health[playerid] < 100.0)
	        {
	            SS_Health[playerid] = 100.0;
	            OLD_SetPlayerHealth(playerid, 100.0);
	        }

	        return 1;
		}
	    case 1242 :
	    {
     		if (SS_Armour[playerid] < 100.0)
       		{
	            SS_Armour[playerid] = 100.0;
	            OLD_SetPlayerArmour(playerid, 100.0);
           	}

			return 1;
   		}
     	case 321..369, 371, 372:
      	{
       		new weapon = SS_GetModelWeaponID(SS_StaticPickup[pickupid]);
       		new slot = SS_GetWeaponSlot(weapon);

       		switch (weapon)
		    {
		        case WEAPON_BRASSKNUCKLE..WEAPON_CANE, WEAPON_PARACHUTE:
		        {
    				SS_WeaponData[playerid][slot][1] += 1;
		        }
		        case WEAPON_GRENADE..WEAPON_MOLTOV:
		        {
    				SS_WeaponData[playerid][slot][1] += 8;
		        }
		        case WEAPON_COLT45:
		        {
    				SS_WeaponData[playerid][slot][1] += 30;
		        }
				case WEAPON_SILENCED, WEAPON_DEAGLE:
		        {
    				SS_WeaponData[playerid][slot][1] += 10;
		        }
		        case WEAPON_SHOTGUN:
		        {
    				SS_WeaponData[playerid][slot][1] += 15;
		        }
		        case WEAPON_SAWEDOFF, WEAPON_SHOTGSPA:
		        {
    				SS_WeaponData[playerid][slot][1] += 10;
		        }
		        case WEAPON_UZI, WEAPON_MP5, WEAPON_TEC9:
		        {
    				SS_WeaponData[playerid][slot][1] += 60;
		        }
		        case WEAPON_AK47, WEAPON_M4:
		        {
    				SS_WeaponData[playerid][slot][1] += 80;
		        }
		        case WEAPON_RIFLE:
		        {
    				SS_WeaponData[playerid][slot][1] += 20;
		        }
		        case WEAPON_SNIPER:
		        {
    				SS_WeaponData[playerid][slot][1] += 10;
		        }
		        case WEAPON_ROCKETLAUNCHER:
		        {
    				SS_WeaponData[playerid][slot][1] += 4;
		        }
		        case WEAPON_HEATSEEKER:
		        {
    				SS_WeaponData[playerid][slot][1] += 3;
		        }
		        case WEAPON_FLAMETHROWER:
		        {
    				SS_WeaponData[playerid][slot][1] += 100;
		        }
		        case WEAPON_MINIGUN:
		        {
    				SS_WeaponData[playerid][slot][1] += 500;
		        }
		        case WEAPON_SATCHEL:
		        {
    				SS_WeaponData[playerid][slot][1] += 5;
		        }
		        case WEAPON_SPRAYCAN:
		        {
    				SS_WeaponData[playerid][slot][1] += 500;
		        }
		        case WEAPON_FIREEXTINGUISHER:
		        {
    				SS_WeaponData[playerid][slot][1] += 100;
		        }
		        case WEAPON_CAMERA:
		        {
    				SS_WeaponData[playerid][slot][1] += 36;
		        }
		    }

         	if (weapon != -1)
          	{
			  	SS_WeaponData[playerid][slot][0] = weapon;
           		OLD_GivePlayerWeapon(playerid, weapon, SS_WeaponData[playerid][slot][1]);
           	}

			return 1;
	    }
	}

	#if defined SS_OnPlayerPickUpPickup
		return SS_OnPlayerPickUpPickup(playerid, pickupid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerPickUpPickup
    #undef OnPlayerPickUpPickup
#else
    #define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup SS_OnPlayerPickUpPickup
#if defined SS_OnPlayerPickUpPickup
	forward SS_OnPlayerPickUpPickup(playerid, pickupid);
#endif

stock SS_SendDeathMessage(playerid, killerid, reason)
{
	switch (reason)
	{
	    case WEAPON_UNKNOWN:
	    {
			reason = WEAPON_DROWN;
	    }
	    case WEAPON_CARPARK:
	    {
			reason = WEAPON_VEHICLE;
	    }
	    case WEAPON_PISTOLWHIP:
	    {
			reason = WEAPON_UNARMED;
	    }
	    case WEAPON_VEHICLE_M4:
	    {
			reason = WEAPON_M4;
	    }
	    case WEAPON_VEHICLE_MINIGUN:
	    {
			reason = WEAPON_MINIGUN;
	    }
	}

	return SendDeathMessage(playerid, killerid, reason);
}
#if defined _ALS_SendDeathMessage
    #undef SendDeathMessage
#else
	native OLD_SendDeathMessage(playerid, killerid, reason) = SendDeathMessage;
    #define _ALS_SendDeathMessage
#endif
#define SendDeathMessage SS_SendDeathMessage
