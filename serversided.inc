#if defined _serversided_included
	#endinput
#endif
#define _serversided_included

/*
*
* ===============
* LIBRARY
* ===============
* Server sieded include (serversided.inc) - v1.0 [BETA]
* Makes all the client side features to server scripted parts (covers Health, Armour, Money, Score, Weapon, Ammo and Vehicle Health).
*
* ===============
* CREDITS
* ===============
* Gammix - Include creator
* Slice - Weapons data array, SS_ProcessDamage and Average weapon functions
*
*/

#define WEAPON_UNARMED 0
#define WEAPON_VEHICLE_M4 19
#define WEAPON_VEHICLE_MINIGUN 20
#define WEAPON_PISTOLWHIP 48
#define WEAPON_HELIBLADES 50
#define WEAPON_EXPLOSION 51
#define WEAPON_CARPARK 52

// All default vending machines
enum e_SS_VENDING_MACHINE
{
	SS_vmInteriorid,
	Float:SS_vmZHeight,
	Float:SS_vmFrontX,
	Float:SS_vmFrontY
}
static const Float:SS_VendingMachine[][e_SS_VENDING_MACHINE] =
{
	{0, 21.98, -862.84, 1537.60},
	{0, 25.96, 2271.72, -77.46},
	{0, 18.95, 1278.73, 372.07},
	{0, 15.71, 662.41, -551.16},
	{0, 0.89,  200.01, -107.63},
	{0, 62.24, -252.74, 2597.95},
	{0, 62.24, -252.74, 2599.75},
	{0, 19.12, -75.03, 1227.99},
	{0, 18.95, -14.72, 1176.35},
	{7, 998.58,  315.87, -140.36},
	{17, 1000.73, 373.82, -179.14},
	{17, 1000.73,  378.03, -178.90},
	{17, 1000.73, 495.95, -23.32},
	{17, 1000.73, 500.56, -2.36},
	{17, 1000.73, 501.82, -2.42},
	{0, 55.23, -1455.13, 2592.66},
	{0, 23.77, 2353.17, -1357.15},
	{0, 14.21, 2325.97, -1646.13},
	{0, 23.35, 2140.51, -1161.53},
	{0, 62.23, 2154.03, -1015.54},
	{0, 12.94, 1929.73, -1772.44},
	{1, 1000.06, 2223.36, 1602.64},
	{1, 1000.05, 2223.20, 1606.77},
	{1, 1000.05, 2156.90, 1606.77},
	{1, 1000.05,  2208.90, 1607.17},
	{1, 1000.06, 2156.84, 1607.87},
	{1, 1000.06, 2202.43, 1618.00},
	{1, 1000.06, 2209.24, 1620.21},
	{3, 1020.07, 330.67, 177.50},
	{3, 1020.07, 331.92, 177.50},
	{3, 1008.47, 351.90, 206.08},
	{3, 1008.47, 361.54, 159.61},
	{3, 1020.07, 371.59, 177.45},
	{3, 1008.47, 374.89, 187.97},
	{2, 1061.09,  2575.70, -1284.44},
	{15,1025.90,  2224.20, -1153.43},
	{0, 15.15,  1153.72, -1460.90},
	{0, 12.96, 2480.84, -1958.27},
	{0, 12.92, 2060.11, -1898.64},
	{0, 12.94, 1729.78, -1944.04},
	{0, 12.89, 1634.10, -2238.53},
	{0, 15.16,  1788.21, -1369.28},
	{0, 34.70, -2229.20, 287.41},
	{256, 27.07,  -1981.78, 142.64},
	{256, 34.72, -2119.93, -423.40},
	{256, 34.72, -2119.58, -422.17},
	{256, 34.72, -2097.29, -397.33},
	{256, 34.72, -2092.08, -491.05},
	{256, 34.72, -2063.27, -491.05},
	{256, 34.72, -2005.64, -491.05},
	{256, 34.72, -2034.46, -491.05},
	{256, 34.72, -2068.58, -397.33},
	{256, 34.72, -2039.86, -397.33},
	{256, 34.72, -2011.15, -397.33},
	{256, 10.58, -1349.11, 492.28},
	{256, 10.58, -1349.11, 493.85},
	{0, 10.21, 2319.99, 2531.85},
	{0, 10.78, 2845.72, 1294.04},
	{0, 10.21, 2503.12, 1244.69},
	{0, 10.21, 2647.69, 1128.66},
	{0, 44.29, -2419.21, 984.57},
	{0, 44.29, -2419.17, 985.94},
	{0, 10.45, 2086.77, 2071.35},
	{0, 10.42, 1398.82, 2223.60},
	{0, 10.21, 1659.46, 1721.85},
	{0, 10.00, 1519.14, 1055.24},
	{6, 1003.63, -19.05, -56.83},
	{18, 1003.63, -16.13, -90.64},
	{16, 1003.63, -15.11, -139.22},
	{17, 1003.63, -32.46, -185.69},
	{16, 1003.63, -35.74, -139.22},
	{6, 1003.63, -36.16, -56.87},
	{18, 1003.63, -17.56, -90.71},
	{16, 1003.63, -16.54, -139.29},
	{17, 1003.63, -33.89, -185.76},
	{6, 1003.63, -19.05, -56.83},
	{6, 1003.63, -36.16, -56.87},
	{18, 1003.63, -16.13, -90.64},
	{18, 1003.63, -17.56, -90.71},
	{16, 1003.63, -16.54, -139.29},
	{16, 1003.63, -15.11, -139.22},
	{17, 1003.63, -33.89, -185.76},
	{17, 1003.63, -32.46, -185.69},
	{16, 1003.63, -35.74, -139.22}
};

static const Float:SS_WeaponRange[] =
{
	0.0, // 0 - Fist
	0.0, // 1 - Brass knuckles
	0.0, // 2 - Golf club
	0.0, // 3 - Nitestick
	0.0, // 4 - Knife
	0.0, // 5 - Bat
	0.0, // 6 - Shovel
	0.0, // 7 - Pool cue
	0.0, // 8 - Katana
	0.0, // 9 - Chainsaw
	0.0, // 10 - Dildo
	0.0, // 11 - Dildo 2
	0.0, // 12 - Vibrator
	0.0, // 13 - Vibrator 2
	0.0, // 14 - Flowers
	0.0, // 15 - Cane
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
	75.0  // 38 - Minigun
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

static const SS_WeaponDamageType[] =
{
	0, // 0 - Fist
	0, // 1 - Brass knuckles
	0, // 2 - Golf club
	0, // 3 - Nitestick
	0, // 4 - Knife
	0, // 5 - Bat
	0, // 6 - Shovel
	0, // 7 - Pool cue
	0, // 8 - Katana
	0, // 9 - Chainsaw
	0, // 10 - Dildo
	0, // 11 - Dildo 2
	0, // 12 - Vibrator
	0, // 13 - Vibrator 2
	0, // 14 - Flowers
	0, // 15 - Cane
	0, // 16 - Grenade
	1, // 17 - Teargas
	0, // 18 - Molotov
	1, // 19 - Vehicle M4 (custom)
	1, // 20 - Vehicle minigun (custom)
	0, // 21
	1, // 22 - Colt 45
	1, // 23 - Silenced
	1, // 24 - Deagle
	1, // 25 - Shotgun
	1, // 26 - Sawed-off
	1, // 27 - Spas
	1, // 28 - UZI
	1, // 29 - MP5
	1, // 30 - AK47
	1, // 31 - M4
	1, // 32 - Tec9
	1, // 33 - Cuntgun
	1, // 34 - Sniper
	0, // 35 - Rocket launcher
	0, // 36 - Heatseeker
	0, // 37 - Flamethrower
	1, // 38 - Minigun
	0, // 39 - Satchel
	0, // 40 - Detonator
	1, // 41 - Spraycan
	1, // 42 - Fire extinguisher
	0, // 43 - Camera
	0, // 44 - Night vision
	0, // 45 - Infrared
	0, // 46 - Parachute
	0, // 47 - Fake pistol
	1, // 48 - Pistol whip (custom)
	1, // 49 - Vehicle
	1, // 50 - Helicopter blades
	0, // 51 - Explosion
	0, // 52 - Car park
	0, // 53 - Drowning
	0  // 54 - Splat
};

enum e_SS_CLASS_INFO
{
	SS_classSkin,
	SS_classTeam,
	Float:SS_classPos[4],
	SS_classWeapon1[2],
	SS_classWeapon2[2],
	SS_classWeapon3[2]
};
static SS_ClassData[311 + 1][e_SS_CLASS_INFO];

enum e_SS_SPAWN_INFO
{
	SS_spawnSkin,
	SS_spawnTeam,
	Float:SS_spawnPos[4],
	SS_spawnWeapon1[2],
	SS_spawnWeapon2[2],
	SS_spawnWeapon3[2]
};
static SS_SpawnData[MAX_PLAYERS][e_SS_SPAWN_INFO];

enum e_SS_LAST_SHOT
{
	SS_shotTick,
 	SS_shotWeapon,
  	SS_shotHittype,
   	SS_shotHitid,
    SS_shotHits,
	Float:SS_shotPos[3],
	Float:SS_shotOrigin[3],
	Float:SS_shotHit[3],
	Float:SS_shotLength,
 	bool:SS_shotValid,
 	bool:SS_shotReturn
}
static SS_LastShot[MAX_PLAYERS][e_SS_LAST_SHOT];
static SS_LastShotTicks[MAX_PLAYERS][10];
static SS_LastShotWeapons[MAX_PLAYERS][10];
static SS_LastShotIdx[MAX_PLAYERS];

static SS_LastHitTicks[MAX_PLAYERS][10];
static SS_LastHitWeapons[MAX_PLAYERS][10];
static SS_LastHitIdx[MAX_PLAYERS];

static SS_StaticPickup[MAX_PICKUPS];

static Float:SS_Health[MAX_PLAYERS];
static Float:SS_Armour[MAX_PLAYERS];

static SS_Money[MAX_PLAYERS];
static SS_Score[MAX_PLAYERS];

static SS_WeaponData[MAX_PLAYERS][13][2];

static SS_Classid[MAX_PLAYERS];
static SS_Teamid[MAX_PLAYERS];

static SS_LastExplosive[MAX_PLAYERS];

static SS_Knifed[MAX_PLAYERS];

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
	    return SetPlayerHealth(playerid, 150.0);
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
	    return SetPlayerArmour(playerid, 150.0);
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

forward __SetPlayerScore(playerid, score);
public 	__SetPlayerScore(playerid, score)
{
    SS_Score[playerid] = score;
}

stock SS_SetPlayerScore(playerid, score)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return false;
	}

	CallRemoteFunction("__SetPlayerScore", "ii", playerid, score);

	return SetPlayerScore(playerid, score);
}
#if defined _ALS_SetPlayerScore
    #undef SetPlayerScore
#else
	native OLD_SetPlayerScore(playerid, score) = SetPlayerScore;
    #define _ALS_SetPlayerScore
#endif
#define SetPlayerScore SS_SetPlayerScore

stock SS_GetPlayerScore(playerid)
{
    if (playerid < 0 || playerid >= MAX_PLAYERS)
	{
		return 0;
	}

	return SS_Score[playerid];
}
#if defined _ALS_GetPlayerScore
    #undef GetPlayerScore
#else
	native OLD_GetPlayerScore(playerid) = GetPlayerScore;
    #define _ALS_GetPlayerScore
#endif
#define GetPlayerScore SS_GetPlayerScore

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

stock SS_AddPlayerClass(modelid, Float:SS_spawn_x, Float:SS_spawn_y, Float:SS_spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new ret = AddPlayerClass(modelid, SS_spawn_x, SS_spawn_y, SS_spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

	SS_ClassData[ret][SS_classSkin] = modelid;
	SS_ClassData[ret][SS_classTeam] = NO_TEAM;
	SS_ClassData[ret][SS_classPos][0] = x;
	SS_ClassData[ret][SS_classPos][1] = y;
	SS_ClassData[ret][SS_classPos][2] = z;
	SS_ClassData[ret][SS_classPos][3] = rotation;
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
	native OLD_AddPlayerClass(modelid, Float:SS_spawn_x, Float:SS_spawn_y, Float:SS_spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = AddPlayerClass;
    #define _ALS_AddPlayerClass
#endif
#define AddPlayerClass SS_AddPlayerClass

stock SS_AddPlayerClassEx(teamid, modelid, Float:SS_spawn_x, Float:SS_spawn_y, Float:SS_spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new ret = AddPlayerClassEx(teamid, modelid, SS_spawn_x, SS_spawn_y, SS_spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

	SS_ClassData[ret][SS_classSkin] = modelid;
	SS_ClassData[ret][SS_classTeam] = teamid;
	SS_ClassData[ret][SS_classPos][0] = x;
	SS_ClassData[ret][SS_classPos][1] = y;
	SS_ClassData[ret][SS_classPos][2] = z;
	SS_ClassData[ret][SS_classPos][3] = rotation;
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
	native OLD_AddPlayerClassEx(teamid, modelid, Float:SS_spawn_x, Float:SS_spawn_y, Float:SS_spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo) = AddPlayerClassEx;
    #define _ALS_AddPlayerClassEx
#endif
#define AddPlayerClassEx SS_AddPlayerClassEx

forward __SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
public  __SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	SS_SpawnData[playerid][SS_spawnSkin] = skin;
	SS_SpawnData[playerid][SS_spawnTeam] = team;
	SS_SpawnData[playerid][SS_spawnPos][0] = x;
	SS_SpawnData[playerid][SS_spawnPos][1] = y;
	SS_SpawnData[playerid][SS_spawnPos][2] = z;
	SS_SpawnData[playerid][SS_spawnPos][3] = rotation;
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
	CallRemoteFunction("__SetPlayerHealth", "if", playerid, 100.0);
	CallRemoteFunction("__SetPlayerArmour", "if", playerid, 0.0);

	CallRemoteFunction("__SetPlayerMoney", "ii", playerid, 0);
	CallRemoteFunction("__SetPlayerScore", "ii", playerid, 0);

	for (new i; i < 13; i++)
	{
		CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, 0, 0);
	}
	SS_LastExplosive[playerid] = 0;

	SS_Classid[playerid] = 0;
	SS_Teamid[playerid] = NO_TEAM;

	SS_LastShotIdx[playerid] = 0;
	SS_LastShot[playerid][SS_shotTick] = 0;

	SS_LastHitIdx[playerid] = 0;

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

public OnPlayerSpawn(playerid)
{
    SS_Knifed[playerid] = INVALID_PLAYER_ID;
    SS_LastShot[playerid][SS_shotHitid] = -1;

	// Adjusting weapons according to SS_class and SS_spawninfo
    new weapon, ammo;
	for (new i; i < 13; i++)
	{
		OLD_GetPlayerWeaponData(playerid, i, weapon, ammo);
		if (weapon && ammo)
		{
			if (SS_SpawnData[playerid][SS_spawnWeapon1][0] == weapon || SS_SpawnData[playerid][SS_spawnWeapon1][1] != ammo)
			{
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, weapon, SS_SpawnData[playerid][SS_spawnWeapon1][1]);
			    continue;
			}
			else if (SS_SpawnData[playerid][SS_spawnWeapon2][1] == weapon || SS_SpawnData[playerid][SS_spawnWeapon2][1] != ammo)
			{
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, weapon, SS_SpawnData[playerid][SS_spawnWeapon2][1]);
			    continue;
			}
			else if (SS_SpawnData[playerid][SS_spawnWeapon3][1] == weapon || SS_SpawnData[playerid][SS_spawnWeapon3][1] != ammo)
			{
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, weapon, SS_SpawnData[playerid][SS_spawnWeapon3][1]);
			    continue;
			}
			else if (SS_ClassData[SS_Classid[playerid]][SS_classWeapon1][0] == weapon || SS_ClassData[playerid][SS_classWeapon1][1] != ammo)
			{
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, weapon, SS_ClassData[SS_Classid[playerid]][SS_classWeapon1][1]);
			    continue;
			}
			else if (SS_ClassData[SS_Classid[playerid]][SS_classWeapon2][1] == weapon || SS_ClassData[playerid][SS_classWeapon2][1] != ammo)
			{
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, weapon, SS_ClassData[SS_Classid[playerid]][SS_classWeapon2][1]);
			    continue;
			}
			else if (SS_ClassData[SS_Classid[playerid]][SS_classWeapon3][1] == weapon || SS_ClassData[playerid][SS_classWeapon3][1] != ammo)
			{
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, weapon, SS_ClassData[SS_Classid[playerid]][SS_classWeapon3][1]);
			    continue;
			}
			else
			{
			    OLD_SetPlayerAmmo(playerid, weapon, 0);
			    CallRemoteFunction("__SetPlayerWeapon", "iiii", playerid, i, 0, 0);
			    continue;
			}
		}
	}

	SetPlayerTeam(playerid, SS_ClassData[SS_Classid[playerid]][SS_classTeam]);
	SetPlayerTeam(playerid, SS_SpawnData[playerid][SS_spawnTeam]);

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

stock static bool:SS_ProcessDamage(&playerid, &issuerid, &Float:amount, &weaponid, &bodypart) //Credits to Slice
{
	// Check if the damage is not negative
	if (amount < 0.0)
	{
		return false;
	}

    // From stealth knife, can be any weapon
	if (_:amount == _:1833.33154296875)
	{
		return false;
	}

	// Prevent carjack damage
	if (weaponid == 54 && _:amount == _:0.0)
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

	// Detect vehicle weapons
	switch (weaponid)
	{
	    case 37, 49, 50, 51, 53, 54:
	    {
	    }
		default:
		{
			if (issuerid != INVALID_PLAYER_ID && IsPlayerInAnyVehicle(issuerid) && GetPlayerVehicleSeat(issuerid) == 0 && (weaponid == WEAPON_M4 || weaponid == WEAPON_MINIGUN))
			{
				weaponid = (weaponid == WEAPON_M4) ? (WEAPON_VEHICLE_M4) : (WEAPON_VEHICLE_MINIGUN);
			}
		}
	}

	// Prevent invalid range SS_shots
	if ((WEAPON_COLT45 <= weaponid <= WEAPON_SNIPER) || weaponid == WEAPON_MINIGUN)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);

		if (GetPlayerDistanceFromPoint(playerid, x, y, z) > SS_WeaponRange[weaponid] + 2.0)
  		{
			return false;
		}
	}

	// Adjust damage for animation bugs
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

	// Car parking
	if (weaponid == WEAPON_HELIBLADES && _:amount != _:330.0)
	{
		weaponid = WEAPON_CARPARK;
	}

	// Finish processing drown/fire/carpark quickly, since they are sent at very high rates
	if ((WEAPON_COLT45 <= weaponid <= WEAPON_SNIPER) || weaponid == WEAPON_MINIGUN)
	{
		// Apply reasonable bounds
		if (weaponid == WEAPON_DROWN)
		{
			if (amount > 10.0)
			{
				amount = 10.0;
			}
		}
		else if (amount > 1.0)
		{
			amount = 1.0;
		}

		// Adjust the damage if the multiplier is not 1.0
		if (_:SS_WeaponDamage[weaponid] != _:1.0)
		{
			amount *= SS_WeaponDamage[weaponid];
		}

		// Make sure the distance and issuer is valid; carpark can be self-inflicted so it doesn't require an issuer
		if (weaponid == WEAPON_SPRAYCAN || weaponid == WEAPON_FIREEXTINGUISHER || (weaponid == WEAPON_CARPARK && issuerid != INVALID_PLAYER_ID))
		{
			if (issuerid == INVALID_PLAYER_ID)
			{
				return false;
			}

			new Float:x, Float:y, Float:z;
			GetPlayerPos(issuerid, x, y, z);
			if (GetPlayerDistanceFromPoint(playerid, x, y, z) > 15.0)
			{
				return false;
			}
		}

		return true;
	}

	// Bullet or melee damage must have an issuerid, otherwise something has gone wrong (e.g. sniper bug)
	if (issuerid == INVALID_PLAYER_ID && (((WEAPON_COLT45 <= weaponid <= WEAPON_SNIPER) || weaponid == WEAPON_MINIGUN) || ((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP)))
	{
		return false;
	}

	// Punching with a parachute
	if (weaponid == WEAPON_PARACHUTE)
	{
		weaponid = WEAPON_UNARMED;
	}

	// Collision damage should never be above 165
	if (weaponid == WEAPON_COLLISION)
	{
		if (amount > 165.0)
		{
			amount = 1.0;
		}
		else
		{
			amount /= 165.0;
		}
	}

	if (weaponid == WEAPON_EXPLOSION)
	{
		// Explosions do at most 82.5 damage. This will later be multipled by the damage value
		amount /= 82.5;

		// Figure out what caused the explosion
		if (issuerid != INVALID_PLAYER_ID && SS_LastExplosive[issuerid])
		{
			weaponid = SS_LastExplosive[issuerid];
		}
	}

	// Check for pistol whip
	switch (weaponid)
	{
		case WEAPON_COLT45..WEAPON_SNIPER, WEAPON_MINIGUN, WEAPON_SPRAYCAN, WEAPON_FIREEXTINGUISHER:
		{
			// A pistol whip inflicts 2.64 damage
			if (_:amount == _:2.6400001049041748046875)
			{
				// Save the weapon in the bodypart argument (it's always BODY_PART_TORSO)
				bodypart = weaponid;
				weaponid = WEAPON_PISTOLWHIP;
			}
		}
	}

	new bool:melee = bool:((WEAPON_UNARMED <= weaponid <= WEAPON_KATANA) || (WEAPON_DILDO <= weaponid <= WEAPON_CANE) || weaponid == WEAPON_PISTOLWHIP);

	// Can't punch from a vehicle
	if (melee && IsPlayerInAnyVehicle(issuerid))
	{
		return false;
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
				// Damage is most likely from punching and switching weapon quickly
				if (! melee)
				{
					weaponid = WEAPON_UNARMED;
					melee = true;
				}
			}
			case 6.6000003814697265625:
			{
				if (! melee)
				{
					switch (weaponid)
					{
						case WEAPON_UZI, WEAPON_TEC9, WEAPON_CHAINSAW, WEAPON_SHOTGUN, WEAPON_SAWEDOFF:
						{
						}
						default:
						{
							weaponid = WEAPON_UNARMED;
							melee = true;
						}
					}
				}
			}
			case 54.12000274658203125:
			{
				if (!melee)
				{
					melee = true;
					weaponid = WEAPON_UNARMED;
					amount = 1.32000005245208740234375;
				}

				// Be extra sure about this one
				if (GetPlayerFightingStyle(issuerid) != FIGHT_STYLE_KNEEHEAD)
				{
					return false;
				}
			}
			// Melee damage has been tampered with
			default:
			{
				if (melee)
				{
					return false;
				}
			}
		}
	}

	new Float:bullets;
	switch (weaponid)
	{
		// The spas SS_shotguns shoot 8 bullets, each inflicting 4.95 damage
		case WEAPON_SHOTGSPA:
		{
			bullets = amount / 4.950000286102294921875;

			if (8.0 - bullets < -0.05)
			{
				return false;
			}
		}
		// Shotguns and sawed-off SS_shotguns shoot 15 bullets, each inflicting 3.3 damage
		case WEAPON_SHOTGUN, WEAPON_SAWEDOFF:
		{
			bullets = amount / 3.30000019073486328125;

			if (15.0 - bullets < -0.05)
			{
				return false;
			}
		}
	}
	if (_:bullets)
	{
		new Float:f = floatfract(bullets);

		// The damage for each bullet has been tampered with
		if (f > 0.01 && f < 0.99)
		{
			return false;
		}

		// Divide the damage amount by the number of bullets
		amount /= bullets;
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
				return false;
			}
		}
	}

 	// Check gun damage
	if (weaponid != WEAPON_COLLISION)
	{
		if (_:amount && _:amount > _:SS_WeaponDamage[weaponid])
		{
		    return false;
		}
	}

	// Adjust the damage
	switch (SS_WeaponDamageType[weaponid])
	{
	    // multiplyable damage
		case 0:
		{
			if (_:SS_WeaponDamage[weaponid] != _:1.0)
			{
				amount *= SS_WeaponDamage[weaponid];
			}
		}
		// a constant rate of damage
		case 1:
		{
			if (_:bullets)
			{
				amount = SS_WeaponDamage[weaponid] * bullets;
			}
			else
			{
				amount = SS_WeaponDamage[weaponid];
			}
		}
	}

	// Valid damage was given!
	return true;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	if (damagedid != INVALID_PLAYER_ID)
	{
		// Check for OnPlayerWeaponShot, if it returned 0, that means no damage is given
	    if (SS_LastShot[playerid][SS_shotHittype] == BULLET_HIT_TYPE_PLAYER && SS_LastShot[playerid][SS_shotHitid] == damagedid)
	    {
	        if (! SS_LastShot[playerid][SS_shotReturn])
	        {
	            SS_LastShot[playerid][SS_shotReturn] = true;

				#if defined SS_OnPlayerGiveDamage
					return SS_OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
				#else
					return 1;
				#endif
	        }
	    }
		// Check for same teams
		if ((SS_Teamid[playerid] != NO_TEAM || SS_Teamid[damagedid] != NO_TEAM) && SS_Teamid[playerid] == SS_Teamid[damagedid])
		{
		    #if defined SS_OnPlayerGiveDamage
				return SS_OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
			#else
				return 1;
			#endif
		}
	}

	// Process damage
	if (! SS_ProcessDamage(damagedid, playerid, amount, weaponid, bodypart))
	{
		ClearAnimations(playerid);
	    return 0;
	}

	// Knifing system
    if (weaponid == WEAPON_KNIFE && GetPVarType(playerid, "SS_Knifed") == PLAYER_VARTYPE_NONE)
	{
		if (_:amount == _:0.0)
		{
		    SetPVarInt(playerid, "SS_Knifed", SetTimerEx("SS_OnPlayerKnifed", 4000 - GetPlayerPing(playerid), false, "ii", damagedid, playerid));
		}
	}

	//
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

	// Detect invalid SS_shots fired, multiple hits and so on
    if (((WEAPON_COLT45 <= weaponid <= WEAPON_SNIPER) || weaponid == WEAPON_MINIGUN) && _:amount != _:2.6400001049041748046875 && ! (IsPlayerInAnyVehicle(playerid) && GetPlayerVehicleSeat(playerid) == 0))
	{
		if (! SS_LastShot[playerid][SS_shotValid])
		{
			SS_LastShot[playerid][SS_shotHits] += 1;
		    return false;
		}
		else if (WEAPON_SHOTGUN <= weaponid <= WEAPON_SHOTGSPA)
		{
			// Let's assume someone won't hit 3 players with 1 SS_shotgun SS_shot, and that one OnPlayerWeaponShot can be out of sync
			if (SS_LastShot[playerid][SS_shotHits] >= 3)
			{
				SS_LastShot[playerid][SS_shotHits] += 1;
			    return false;
			}
		}
		else if (SS_LastShot[playerid][SS_shotHits] > 0)
		{
			// Sniper doesn't always send OnPlayerWeaponShot
			if (SS_LastShot[playerid][SS_shotHits] > 4 && weaponid != WEAPON_SNIPER)
			{
				SS_LastShot[playerid][SS_shotHits] += 1;
			    return false;
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

forward SS_OnPlayerKnifed(playerid, killerid);
public  SS_OnPlayerKnifed(playerid, killerid)
{
	SetPlayerHealth(playerid, 0.0);
	SS_Knifed[playerid] = killerid;
	
	DeletePVar(playerid, "SS_Knifed");
}

public OnPlayerDeath(playerid, killerid, reason)
{
	SS_Health[playerid] = 0.0;
	SS_Armour[playerid] = 0.0;

	// Playerid was knifed
	if (SS_Knifed[playerid] != INVALID_PLAYER_ID)
	{
	    killerid = SS_Knifed[playerid];
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

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if (issuerid != INVALID_PLAYER_ID)
	{
		// Check for OnPlayerWeaponShot, if it returned 0, that means no damage is given
	    if (SS_LastShot[issuerid][SS_shotHittype] == BULLET_HIT_TYPE_PLAYER && SS_LastShot[issuerid][SS_shotHitid] == playerid)
	    {
	        if (! SS_LastShot[issuerid][SS_shotReturn])
	        {
	            SS_LastShot[issuerid][SS_shotReturn] = true;

				#if defined SS_OnPlayerTakeDamage
					return SS_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
				#else
					return 1;
				#endif
	        }
	    }
		// Check for same teams
		if ((SS_Teamid[playerid] != NO_TEAM || SS_Teamid[issuerid] != NO_TEAM) && SS_Teamid[playerid] == SS_Teamid[issuerid])
		{
			#if defined SS_OnPlayerTakeDamage
				return SS_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
			#else
				return 1;
			#endif
		}
	}

	// Process damage
	if (! SS_ProcessDamage(playerid, issuerid, amount, weaponid, bodypart))
	{
		ClearAnimations(issuerid);
	    return 0;
	}

	// If the damage is valid, reduce armour or health
	if (SS_Armour[playerid])
	{
	    SS_Armour[playerid] -= amount;
		SetPlayerArmour(playerid, SS_Armour[playerid]);
	}
	else
	{
    	SS_Health[playerid] -= amount;
		SetPlayerHealth(playerid, SS_Health[playerid]);
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

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	SS_LastShot[playerid][SS_shotValid] = false;
	SS_LastShot[playerid][SS_shotHits] = false;

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

	SS_LastShot[playerid][SS_shotTick] = tick;
	SS_LastShot[playerid][SS_shotWeapon] = weaponid;
	SS_LastShot[playerid][SS_shotHittype] = hittype;
	SS_LastShot[playerid][SS_shotHitid] = hitid;
	SS_LastShot[playerid][SS_shotPos][0] = fX;
	SS_LastShot[playerid][SS_shotPos][1] = fY;
	SS_LastShot[playerid][SS_shotPos][2] = fZ;
	SS_LastShot[playerid][SS_shotOrigin][0] = origin[0];
	SS_LastShot[playerid][SS_shotOrigin][1] = origin[1];
	SS_LastShot[playerid][SS_shotOrigin][2] = origin[2];
	SS_LastShot[playerid][SS_shotHit][0] = hit[0];
	SS_LastShot[playerid][SS_shotHit][1] = hit[1];
	SS_LastShot[playerid][SS_shotHit][2] = hit[2];
	SS_LastShot[playerid][SS_shotLength] = length;
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

		new bool:ret = true;
	    #if defined SS_OnPlayerWeaponShot
			ret = bool:SS_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
		#endif
		if (ret)
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

					if (WEAPON_SHOTGUN <= weaponid <= WEAPON_SHOTGSPA)
					{
						health -= 120.0;
					}
					else
					{
						health -= SS_WeaponDamage[weaponid] * 3.0;
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


	#if defined SS_OnPlayerWeaponShot
		return SS_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
	#else
		return 1;
	#endif
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

public OnPlayerUpdate(playerid)
{
	// Check for health hack
	new Float:health;
	OLD_GetPlayerHealth(playerid, health);
	if (_:health >= 100 && _:SS_Health[playerid] < 100 || _:health < 100 && _:SS_Health[playerid] >= 100)
	{
	    return OLD_SetPlayerHealth(playerid, SS_Health[playerid]);
	}

	// Check for armour hack
	new Float:armour;
	OLD_GetPlayerArmour(playerid, armour);
	if (_:armour >= 100 && _:SS_Armour[playerid] < 100 || _:armour < 100 && _:SS_Armour[playerid] >= 100)
	{
	    return OLD_SetPlayerArmour(playerid, SS_Armour[playerid]);
	}

	// Check for money hack
	if (OLD_GetPlayerMoney(playerid) != SS_Money[playerid])
	{
	    OLD_ResetPlayerMoney(playerid);
		return OLD_GivePlayerMoney(playerid, SS_Money[playerid]);
	}

	// Check for score hack
	if (OLD_GetPlayerScore(playerid) != SS_Score[playerid])
	{
		return OLD_SetPlayerScore(playerid, SS_Score[playerid]);
	}

	// Check for weapon hack
	new weapon = GetPlayerWeapon(playerid);
	new slot = SS_GetWeaponSlot(weapon);
	if (SS_WeaponData[playerid][slot][0] != weapon)
	{
		OLD_SetPlayerAmmo(playerid, weapon, 0);
		OLD_GivePlayerWeapon(playerid, SS_WeaponData[playerid][slot][0], SS_WeaponData[playerid][slot][1]);
	}
	else
	{
	    switch (weapon)
	    {
			case WEAPON_GRENADE..WEAPON_MOLTOV, WEAPON_COLT45..WEAPON_SNIPER, WEAPON_ROCKETLAUNCHER, WEAPON_HEATSEEKER, WEAPON_MINIGUN, WEAPON_CAMERA, WEAPON_SATCHEL:
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

	// Detecting vending machine
    if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if (GetPlayerAnimationIndex(playerid) == 1660 && GetPVarType(playerid, "SS_Vending") == PLAYER_VARTYPE_NONE)
		{
		    new interiorid = GetPlayerInterior(playerid);
			for (new i, j = sizeof(SS_VendingMachine); i < j; i++)
			{
			    if (interiorid != SS_VendingMachine[i][SS_vmInteriorid])
			    {
			        continue;
			    }

				if (! IsPlayerInRangeOfPoint(playerid, 1.0, SS_VendingMachine[i][SS_vmFrontX], SS_VendingMachine[i][SS_vmFrontY], SS_VendingMachine[i][SS_vmZHeight]))
				{
					continue;
				}
				
				printf("DEBUG: OnPlayerUpdate");

				SetPVarInt(playerid, "SS_Vending", SetTimerEx("OnPlayerUseVendingMachine", 1750, false, "i", playerid));
				GivePlayerMoney(playerid, -1);
				
				break;
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

forward OnPlayerUseVendingMachine(playerid);
public  OnPlayerUseVendingMachine(playerid)
{
	if (SS_Health[playerid] + 35.0 <= 100.0)
 	{
		SetPlayerHealth(playerid, SS_Health[playerid] + 35.0);
	}
	else if (SS_Health[playerid] < 100.0)
	{
		new Float:amount = 100.0 - SS_Health[playerid];
		SetPlayerHealth(playerid, SS_Health[playerid] + amount);
  	}
  	
	DeletePVar(playerid, "SS_Vending");
}

#if ! defined PRESSED
	#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	// Store player last explosive used
    if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
	    if (PRESSED(KEY_FIRE))
		{
 			new weaponid = GetPlayerWeapon(playerid);
		    switch (weaponid)
			{
				case WEAPON_BOMB, WEAPON_SATCHEL:
				{
					SS_LastExplosive[playerid] = WEAPON_SATCHEL;

	  				new slot = SS_GetWeaponSlot(weaponid);

					SS_WeaponData[playerid][slot][1]--;
					if (! SS_WeaponData[playerid][slot][1])
					{
					 	SS_WeaponData[playerid][slot][0] = 0;
					    SS_WeaponData[playerid][slot][1] = 0;
				    }
				}
				case WEAPON_ROCKETLAUNCHER, WEAPON_HEATSEEKER, WEAPON_GRENADE:
				{
					SS_LastExplosive[playerid] = weaponid;

					new slot = SS_GetWeaponSlot(weaponid);

					SS_WeaponData[playerid][slot][1]--;
					if (! SS_WeaponData[playerid][slot][1])
					{
					 	SS_WeaponData[playerid][slot][0] = 0;
					    SS_WeaponData[playerid][slot][1] = 0;
				    }
				}
				case WEAPON_CAMERA:
				{
					new slot = SS_GetWeaponSlot(weaponid);

					SS_WeaponData[playerid][slot][1]--;
					if (! SS_WeaponData[playerid][slot][1])
					{
					 	SS_WeaponData[playerid][slot][0] = 0;
					    SS_WeaponData[playerid][slot][1] = 0;
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
    #define _ALS_AddStaticPickup
#endif
#define AddStaticPickup SS_AddStaticPickup

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
	         	SetPlayerHealth(playerid, 100.0);
	        }

	        return 1;
		}
	    case 1242 :
	    {
     		if (SS_Armour[playerid] < 100.0)
       		{
         		SetPlayerArmour(playerid, 100.0);
           	}

			return 1;
   		}
     	case 321..369, 371, 372:
      	{
       		new weapon = SS_GetModelWeaponID(SS_StaticPickup[pickupid]);
         	if (weapon != -1)
          	{
           		GivePlayerWeapon(playerid, weapon, 100);
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
	    case WEAPON_CARPARK:
	    {
			reason = WEAPON_VEHICLE;
	    }
	    case WEAPON_PISTOLWHIP:
	    {
			reason = WEAPON_UNARMED;
	    }
	    case WEAPON_UNKNOWN:
	    {
			reason = WEAPON_DROWN;
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
