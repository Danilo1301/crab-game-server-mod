# crab-game-server-mod

<br>

## Download

Download at [Releases](https://github.com/Danilo1301/crab-game-server-mod/releases) page
<br>
<br>
(inject on MENU only)
<br>
Can be injected using Cheat Engine or Extreme Injector through DLL Injection

<br>
<br>

## Commands:

### [player]
* by name: Testname123 or test
* by id: #3 or 3
* by steamId: 79561199219991380 (don't need to be online)
* \* - all
* *a - alive
* *d - dead

### help
* !help - show all commands that you have permission
* !help [command] - show help for a specific command
* !ahelp - show all commands that you don't have permission

### perm
* !perm add [group] [perms] - add perms to a group
    - ex: !perm add default respawn,god,tp
    - ex: !perm add default respawn
* !perm del [group] [perms] - remove perms from a group
* !perm setgroup [player] [group] - set players's group
* !perm list [group] *(page)* - show permissions for a group
* !perm groups - list all groups
* !perm creategroup [name]
* !perm removegroup [name]

<br>
You can change permissions and inheritance in (Crab Game/server/permissions/) <br>
Can also be reloaded using !config reload <br>
Default perm groups: default, mod, admin
'admin' group has the * permission, which means it has all permissions <br>

### restart
* !r - restart game

### vanish
Hide host messages in chat
* !v - toggle 

### w
* !w [weaponId] - spawns a weapon below you
* !w [weaponId] [ammo]  - spawns a weapon below you with a specific amount of ammo

### givew
* !givew [toPlayer] [weaponId] - gives weapon to a player
* !givew [toPlayer] [weaponId] (ammo) - spawns a weapon below another player with a specific amount of ammo

### god
Toggle god mode
* !god
* !god [0/1] - 0=off 1=on
* !god [player] [0/1] - (need god.others perm)

### hand
Equip a weapon in your hand (only visible for others)
* !hand [weaponId] 

### respawn
Respawn at any time of the game<br>
BUG: If you type !respawn as a host and spec (since game start, not died-spec case), the players that already spawned won't be visible for you
* !respawn
* !respawn [player]<br>

### map
Change map and mode<br>
Should only be used after the game started, otherwise it will bug
* !map [map] [mode]
* !map [player]

### jumppunch
Jump high every time you punch
* !jumppunch

### superpunch
Increase knockback when punching
* !superpunch

### forcefield
If someone tries to punch you, they will also be punched
* !forcefield

### punchdamage
Changes punch base damage<br>
Doesn't do damage in lobby<br>
* !punchdamage [weaponId]

### lobbyonly
Makes the command work only during lobby
* !lobbyonly [command]

### fly
Punch to fly<br>
* !fly - toggle
* !fly [speed] - change speed

### DeathMatch
Players spawn with a glock, and respawn after dying
* !dm - toggle

### hover
Hover someone
* !hover [player]
* !hover [player] [radius]
* !hover off

### vote
To use during any voting
* !vote [yes / no]
* !yes
* !no

### skip
To skip current map. Not recommended to use<br>
It wont check if player is tagged or not(for example), so it will have bugs in BOMB mode, TAG, HIDENSEEK, etc
* !skip

### config
Auto saves every 20 seconds (set in config.ini)<br>
config.ini is located at (Crab Game/server/) folder<br>
* !reload - reload config

### mute
Mute a player<br>
Time can be 7s (7 seconds), 7m (7 minutes), 7h (7 hours), or 7d (7 days)<br>
* !mute (player) (time)

### kick

### ban
Ban a player<br>
Reason is optional<br>
Time can be 7s (7 seconds), 7m (7 minutes), 7h (7 hours), or 7d (7 days)<br>
* !ban [player] *(reason)* - permanent ban (reason is optional)
* !ban [playar] [time] *(reason)*

### unban
* !unban [steamId] - unban player

### ready
Set ready by command<br>
* !ready
* !ready [player]


### multisnowball

### whitelist

### voteckick

### teleport

### win

### start


### broadcast

### autostart

<br>

### Weapon IDS:
* 0 - AK
* 1 - GLOCK
* 2 - REVOLVER
* 3 - DUAL
* 4 - BAT
* 5 - BOMB
* 6 - KATANA
* 7 - KNIFE
* 8 - PIPE
* 9 - SNOWBALL
* 10 - STICK
* 11 - MILK
* 12 - PIZZA
* 13 - GRENADE

### Maps:
* 0 - Bitter Beach
* 1 - Blueline
* 2 - Cocky Containers
* 3 - Color Climb
* 4 - Crusty Rocks
* 5 - Desert
* 6 - Dorm
* 7 - Funky Field
* 8 - Glass Jump
* 9 - Hasty Hill
* 10 - Icy Crack
* 11 - Icy Islands
* 12 - Icy Rocks
* 13 - Islands
* 14 - Karlson
* 15 - Lanky Lava
* 16 - Lava Lake
* 17 - Plains
* 18 - Playground
* 19 - Playground 2
* 20 - Return to Monke
* 21 - Sandstorm
* 22 - Slippery Slope
* 23 - (S) Color Climb
* 24 - (S) Glass Jump
* 25 - (S) Hill
* 26 - (S) Icy Islands
* 27 - (S) Islands
* 28 - (S) Playground
* 29 - Snowtop
* 30 - Splat
* 31 - Splot
* 32 - Sunny Saloon
* 33 - Toxic Train
* 34 - Twisted Towers
* 35 - Mini Monke
* 36 - (S) Beach
* 37 - (S) Saloon
* 38 - (S) Containers
* 39 - Tiny Town 2
* 40 - Tiny Town
* 41 - Dodgy Fields
* 42 - Dodgy Ice
* 43 - Dodgy Snow
* 44 - Dodgy Streets
* 45 - Sandy Islands
* 46 - (S) Sandy Islands
* 47 - Cheeky Chamber
* 48 - Lava Drop
* 49 - Lava Dump
* 50 - Peaceful Platform
* 51 - Salty Island
* 52 - Skybox
* 53 - Saucy Stage
* 54 - Lava Climb
* 55 - Macaroni Mountain
* 56 - Sussy Sandcastle
* 57 - Sussy Slope
* 58 - Sandy Stones
* 59 - Crabfields
* 60 - Crabheat
* 61 - Crabland

### Modes:
* 0 - waiting
* 1 - red light
* 2 - king of the kill
* 3 - stepping stones
* 4 - tag
* 5 - hide and seek
* 6 - bomb
* 7 - lightsout
* 8 - floor is lava
* 9 - tile dive
* 10 - hat
* 11 - race
* 12 - buttons
* 13 - practice
