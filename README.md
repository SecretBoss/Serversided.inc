# Serversided.inc `v1.2 [BETA]`

This include makes all the client side features to server scripted parts (covers Health, Armour, Money, Weapon, Ammo and Vehicle Health). This is some sort of anti cheat but this doesn't give notifications but handles the situation itself and reset to original values.



## Core Features
* Detection of vending machines which allows client and server intact with each other (doesn't remove buildings/objects).
* Custom scripted static pickups (AddStaticPickup) allows all the features but handled by include.
* Supports new weapon types (credits to slice)
```
* WEAPON_PISTOLWHIP - When you punch someone with a gun
* WEAPON_VEHICLE_M4 - Vehicles with M4 guns (e.g. Rustler)
* WEAPON_VEHICLE_MINIGUN - Vehicles with miniguns (e.g. Hunter)
* WEAPON_HELIBLADES - Helikill
* WEAPON_CARPARK - When you park your car on someone
```
* Damage processing, shot vector, distance, fire rate etc are examined.
* Prevent rapid fire, long range shots (shots with more range than max defined).
* Fixed lag-comp with SetPlayerTeam, server sided teams.
* Server sided vehicle health, prevent from invalid weapon shot or damage as well.
* Makes it impossible to hack:
```
* HEALTH
* ARMOUR
* MONEY
```
(all these elements or stats work on arrays per player)
* Scripted weapons and ammo, maintain a custom record of weapons which will make it 100% accurate to detect weapon hacks, exception for Flamethrower, Fire estinguisher and spray can.
* Auto detects weapon bugs and fix them automatically (e.g. RPG bug, click LMB but quickly leave AIM button to avoid ammo reduction. The RPG is shot and does damage but doesn't deduct the ammo from player).
* Modified SendDeathMessage with new weapon types detected.
* Allows default SAMP callback features. This include just layers the player stats but leave the features as is. (e.g. Returning 0 under OnPlayerWeaponShot will still make the hitid invulnerable towards the shot).



## Disclaimer
The include is in BETA and there might be bugs. So please test the features (curious about weapon damage system against other players) before using it in your host.

When the [BETA] tag is removed, that means the include is stable and ready to use in your server.
