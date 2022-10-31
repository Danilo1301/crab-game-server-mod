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
* 0 - menu
* 1 - win screen
* 2 - dorm
* 3 - desert
* 4 - slippery slope
* 5 - glass jump
* 6 - ???
* 7 - blueline
* 8 - ???
* 9 - sunny saloon
* 10 - ???
* 11 - sussy slope
* 12 - funky field
* 13 - ???
* 14 - bitter beach
* 15 - ???
* 16 - ???
* 17 - ???
* 18 - cocky containers
* 19 - cheecky chamber
* 20 - macaroni mountain
* 21 - icy crack
* 22 - small saloon
* 23 - ???
* 24 - playground
* 25 - ???
* 26 - tiny town 2
* 27 - ???
* 28 - ???
* 29 - ???
* 30 - ???
* 31 - ???
* 32 - peaceful platform
* 33 - ???
* 34 - snowtop
* 35 - ???
* 36 - karlson
* 37 - milk mountain
* 38 - ???
* 39 - ???
* 40 - skybox
* 41 - splot
* 42 - mini monke
* 43 - saucy stage
* 44 - return to monke
* 45 - small glass jump
* 46 - ???
* 47 - lava climb
* 48 - sussy sandcastle
* 49 - ???
* 50 - ???
* 51 - ???
* 52 - ???
* 53 - ???
* 54 - ???
* 55 - ???
* 56 - small beach
* 57 - playground2
* 58 - sandstorm
* 59 - nasty hill
* 60 - small color climb
* 61 - small hill
* 62 - lanky lava
* 63 - twisted towers
* 64 - ???
* 65 - ???
* 66 - ???
* 67 - ???
* 68 - tiny town
* 69 - small playground

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
