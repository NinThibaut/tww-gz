# tww-gz
The Wind Waker (SD) ROM hack to practice speedrunning.

To patch an ISO with a patch file, see: [PATCHING.md](./PATCHING.md)  
To build the project from source, see: [BUILDING.md](./BUILDING.md)  
For acknowledgements, see: [THANKS.md](./THANKS.md)  

If you have questions or need help, ask in the [#practice-rom-development](https://discord.com/channels/136347487710609409/830218819695673405) channel of the [Wind Waker Speedrunning Discord](https://discord.gg/Sj5aehU).

## Controls
| Button(s)          | Description   
| :---               | :---          
| L + R + D-pad down | Open menu     
| D-pad directions   | Navigate menus
| A                  | Select        
| B                  | Go back       

Some features have specific button combinations associated with them.
See the features section for more details.

## Features
- [Cheats](#Cheats)
- [Flags](#Flags)
- [Inventory](#Inventory)
- [Memory](#Memory)
- [Practice](#Practice)
- [Scene](#Scene)
- [Settings](#Settings)
- [Tools](#Tools)

---

### Cheats
Enable and disable specific cheats. Some cheats are applied constantly, and some need a button combination to use.
<details>
<summary>See the table below for a description of each cheat</summary>
<br>  

| Cheat             | Description                                        
| :---              | :---                                               
| Infinite air      | Always have max air                                
| Infinite arrows   | Always have max arrows                             
| Infinite bombs    | Always have max bombs                              
| Infinite hearts   | Always have full hearts                            
| Refill hearts     | Hold R+D-pad right to refill health                
| Infinite magic    | Always have full magic                             
| Refill magic      | Hold L+D-pad up to refill magic                    
| Infinite rupees   | Always have infinite rupees                        
| Moon jump         | Hold R+A to moon jump                              
| Storage           | Press D-pad right to get storage                   
| Normal collision  | Hold L+D-pad down to get normal collision          
| Chest storage     | Hold L+D-pad right to get chest storage            
| Door cancel       | Hold L+D-pad left to get door cancel               
| Quarter heart     | Hold R+D-pad left to reduce health to quarter heart
| Fast movement     | Hold D-pad left to get super speed                 
| Upcharge          | Hold X + Z to get negative speed for upcharge     
| Tingle Balloon    | Press L+R+D-pad up to activate a tingle balloon

</details>  

---

### Flags
Set and unset various flags in the game.

<details>
<summary> General - Flags that are most relevant or important</summary>
<br>  

| Flag Name                   | Description                                                    
| :--                         | :--                                                            
| FF2 Helmaroc Cutscene       | Switches to animation set 2, among other things                
| FF1 Gossip Stone Trigger    | Sets Pirate Ship to layer 2 (Ropes 2) and Outset to layer 4    
| Endless Night		          | Activates Endless Night, incompatible with having Nayru's Pearl
| Raise ToTG                  | Raises Tower of the Gods                                       
| Load ToTG After T2Z         | Sets FF3 Layer and F&I Arrows at Mother & Child                
| Hyrule 3 Warp               | Opens golden warp to Hyrule 3                                  
| Hyrule Barrier              | Barrier Skip skip                                              
| Dark Portal                 | Opens dark portal between FF3 and Ganon's Tower                
| Sea Chart                   | Gives the sea chart                                            
</details>

<details>
<summary> Dungeons - Flags related to dungeon collectables</summary>
<br>  

| Flag Name           | Description                                                     
| :--                 | :--                                                             
| dungeon <"name">    | Change the dungeon being modified
| keys <"amount">	  | Modify the number of small keys
| boss key		      | Gives the boss key
| map                 | Gives the dungeon map
| compass             | Gives the dungeon compass
| partner             | Spawns Medli/Makar (ET/WT Only)
| partner room        | Spawns Medli/Makar in current room on using void out tool(ET/WT Only)
</details>

<details>
<summary> Savewarp - Flags related to savewarp locations (higher tiers take priortiy)</summary>
<br>  

| Flag Name                           | Description                                                     
| :--                                 | :--           
| Leaving Outset Cutscene             | Sets savewarp location to Pirate Ship (Overworld Travelling)
| Tetra Text After Getting Spoils Bag | Sets savewarp location to Pirate Ship (At FF1)
| Barrel Launch Cutscene		      | Sets savewarp location to FF1
| Post FF1 KorL Cutscene              | Sets savewarp location to Windfall, spawns KorL, and sets FoF to layer 2
| Enter KorL First Time               | Sets savewarp location to most recent loaded area                                                  

</details>

<details>
<summary> Tuner - Flags related to tingle tuner</summary>
<br>  

| Flag Name           | Description                                                     
| :--                 | :--                                                             
| Kooloo-Limpah 10s Balloon+Shield	| Adds the 10s Balloon+Shield to the Kooloo-Limpah pool
| Tingle Balloon Discount           | Gives Tingle Balloon Discount from 30 to 20 rupees
| Tings Discount                    | Gives 50 percent off discount for all tings
| Hand-Me-Down Tingle Tuner         | Unlocks the Hand-Me-Down Tingle Tuner item in the tuner shop

</details>

---

### Inventory
Modify various parts of the inventory:
<details>
<summary>Amounts - Modify amounts for health, magic, etc.</summary>
<br>  

| Flag Name           | Description                   
| :--                 | :--        
| Health              | Modify the current health by quarter
| Bombs               | Modify the current bomb count
| Arrows              | Modify the current arrow count
| Rupees              | Modify the current rupee count
| Magic               | Modify the current magic amount
| Heart Pieces        | Modify the current heart pieces collected
| Joy Pendants        | Modify the current Joy Pendants count
| Skull Necklaces     | Modify the current Skull Necklaces count
| Boko Baba Seeds     | Modify the current Boko Baba Seeds count
| Golden Feathers     | Modify the current Golden Feathers count
| Knights Crests      | Modify the current Knights Crests count
| Red Chu Jelly       | Modify the current Red Chu Jelly count
| Green Chu Jelly     | Modify the current Green Chu Jelly count
| Blue Chu Jelly      | Modify the current Blue Chu Jelly count

</details>

<details>
<summary>Item Inventory - Modify Item Inventory Menu</summary>
<br>  

| Flag Name             | Description                   
| :--                   | :--        
| Telescope             | Add/remove telescope to/from inventory
| Sail                  | Add/remove sail to/from inventory
| Wind Waker            | Add/remove wind waker to/from inventory
| Grappling Hook        | Add/remove grappling hook to/from inventory
| Spoils Bag            | Add/remove spoils bag to/from inventory
| Boomerang             | Add/remove boomerang to/from inventory
| Deku Leaf             | Add/remove deku leaf to/from inventory
| Tingle Tuner          | Add/remove tingle tuner to/from inventory
| Progressive Picto Box | Add/remove/upgrade picto box
| Iron Boots            | Add/remove iron boots to/from inventory
| Magic Armor           | Add/remove magic armor to/from inventory
| Bait Bag              | Add/remove bait bag to/from inventory
| Progressive Bow       | Add/remove/upgrade bow
| Bombs                 | Add/remove bombs to/from inventory
| Bottle 1              | Add/remove bottle 1 to/from inventory
| Bottle 2              | Add/remove bottle 2 to/from inventory
| Bottle 3              | Add/remove bottle 3 to/from inventory
| Bottle 4              | Add/remove bottle 4 to/from inventory
| Delivery Bag          | Add/remove delivery bag to/from inventory
| Hookshot              | Add/remove hookshot to/from inventory
| Skull Hammer          | Add/remove skull hammer to/from inventory

</details>

<details>
<summary>Quest Status - Modify Quest Status Menu</summary>
<br>  

| Flag Name           | Description                   
| :--                 | :--        
| Sword               | Add/remove/upgrade sword
| Shield              | Add/remove/upgrade shield
| Magic               | Add/remove/upgrade magic
| Quiver              | Add/remove/upgrade quiver
| Hurricane Spin      | Add/remove Hurricane Spin
| Hero's Clothes      | Add/remove Hero's Clothes
| Bomb Bag            | Add/remove/upgrade bomb bag
| Power Bracelets     | Add/remove power bracelets from inventory
| Pirate's Charm      | Add/remove pirate's charm from inventory
| Hero's Charm        | Add/remove hero's charm from inventory
| Wind's Requiem      | Add/remove wind's requiem from songs list
| Ballad of Gales     | Add/remove ballad of gales from songs list
| Command Melody      | Add/remove command melody from songs list
| Earth God's Lyric   | Add/remove earth god's lyric from songs list
| Wind God's Aria     | Add/remove wind god's aria from songs list
| Song of Passing     | Add/remove song of passing from songs list
| Din's Pearl         | Add/remove din's pearl from inventory
| Farore's Pearl      | Add/remove farore's pearl from inventory
| Nayru's Pearl       | Add/remove nayru's pearl from inventory
| Triforce Piece 1    | Add/remove triforce piece 1 from inventory
| Triforce Piece 2    | Add/remove triforce piece 2 from inventory
| Triforce Piece 3    | Add/remove triforce piece 3 from inventory
| Triforce Piece 4    | Add/remove triforce piece 4 from inventory
| Triforce Piece 5    | Add/remove triforce piece 5 from inventory
| Triforce Piece 6    | Add/remove triforce piece 6 from inventory
| Triforce Piece 7    | Add/remove triforce piece 7 from inventory
| Triforce Piece 8    | Add/remove triforce piece 8 from inventory

</details>

<details>
<summary>Spoils Bag - Modify Spoils Bag Item Slots</summary>
<br>  
 
| Flag Name           | Description                   
| :--                 | :--    
| Slot 1              | Modify Item in Spoils Bag slot 1
| Slot 2              | Modify Item in Spoils Bag slot 2
| Slot 3              | Modify Item in Spoils Bag slot 3
| Slot 4              | Modify Item in Spoils Bag slot 4
| Slot 5              | Modify Item in Spoils Bag slot 5
| Slot 6              | Modify Item in Spoils Bag slot 6
| Slot 7              | Modify Item in Spoils Bag slot 7
| Slot 8              | Modify Item in Spoils Bag slot 8

</details>

<details>
<summary>Delivery Bag - Modify Delivery Bag Item Slots</summary>
<br>  
 
| Flag Name           | Description                   
| :--                 | :--        
| Slot 1              | Modify Item in Delivery Bag slot 1
| Slot 2              | Modify Item in Delivery Bag slot 2
| Slot 3              | Modify Item in Delivery Bag slot 3
| Slot 4              | Modify Item in Delivery Bag slot 4
| Slot 5              | Modify Item in Delivery Bag slot 5
| Slot 6              | Modify Item in Delivery Bag slot 6
| Slot 7              | Modify Item in Delivery Bag slot 7
| Slot 8              | Modify Item in Delivery Bag slot 8

</details>

<details>
<summary>Bait Bag - Modify Bait Bag</summary>
<br>  
  
| Flag Name           | Description                   
| :--                 | :--        
| Slot 1              | Modify Item in Bait Bag slot 1
| Slot 2              | Modify Item in Bait Bag slot 2
| Slot 3              | Modify Item in Bait Bag slot 3
| Slot 4              | Modify Item in Bait Bag slot 4
| Slot 5              | Modify Item in Bait Bag slot 5
| Slot 6              | Modify Item in Bait Bag slot 6
| Slot 7              | Modify Item in Bait Bag slot 7
| Slot 8              | Modify Item in Bait Bag slot 8

</details>

<details>
<summary>Charts - Modify All Chart Types</summary>
<br>  
 
| Flag Name           | Description                   
| :--                 | :--        
| Special Charts      | Add/Remove Special charts
| Triforce Charts     | Add/Remove/Decipher/Complete Triforce charts
| All Charts          | Add/Remove all charts

</details>

---

### Memory

Watches: View and pin on-screen values at specific memory locations  
TODO: Explain more about how this works

Memory Editor: Edit values at specific memory locations  
TODO: Explain more about how this works

Flag Logger: Output triggered events/switches to the bottom left of the screen

Memfiles : Save and load custom save files 

---

### Practice

The practice menu contains hacked save files which allow you to instantly warp to key points in a speedrun route.
The following categories are supported. Click the dropdown to view a list of each save:

<details>
<summary>Any%</summary>
<br>  
 
| Save                        | Description                                    
| :--                         | :--                                           
| Manual Superswim            | Just after the intro, at bottom of watchtower
| Post Manual Superswim       | After MSS at DRI
| FF1 Exterior                | At FF1 after leaving jail cell
| Door Cancel Leaf            | At windfall island, post FF1 cutscene
| Forest Haven Swim           | At windfall, outside bomb shop with door cancel
| Forest Haven Climb          | Outside forest haven with door cancel
| Deku Tree Cutscene Skip     | Inside Forest Haven at top, for DTCS
| Door Cancel FF2             | At windfall cove after leaf for door cancel ff2  
| FF2 Climb                   | Outside FF2 near climbing spot with door cancel
| Helmaroc Skip               | Inside FF2 Tower, at start of Helmaroc King fight
| Barrier Skip                | Outside Hyrule Castle, about to do barrier skip
| Trials Skip                 | Inside Ganon's Tower, in trials room for trials skip
| Light Arrow Skip            | In Phantom Ganon's room for light arrow skip with Tuner
| Puppet Ganon Cutscene Skip  | At bottom Grand Staircase for Puppet Ganon cutscene skip
| Puppet Ganon Skip           | Bottom of Ganondorf's Bedroom on layer 8 for Puppet Ganon skip with Tuner
| Ganondorf                   | On top of Ganondorf's Tower, at start of Ganondorf fight

</details>

<details>
<summary>Any% No MSS</summary>
<br>  

| Save                    | Description                   
| :--                     | :--    
| After Intro             | Just after the intro at bottom of watchtower
| Orca                    | Inside orca's house about to do sword tutorial
| Forest of Fairies       | Inside forest of fairies about to rescue tetra
| Ropes 1                 | Inside pirate ship about to play ropes 1 minigame
| Early Light Cycle       | On Pirate Ship before barrel launch cutscene
| FF1 [Alt]               | At start of ff1 after gossip stone cutscene
| FF1 Interior            | Inside FF1 in rope swing room
| Windfall                | At windfall island just finished talking to korl
| Bombs Swim              | At dragon roost island just got the wind waker
| Ropes 2                 | Inside pirate ship about to play ropes 2 minigame
| Forest Haven Swim       | At windfall island about to swim to forest haven
| Forest Haven Climb      | Outside forest haven with door cancel or Tuner
| Lip Crush Cutscene Skip | Inside forest haven at top for lip crush
| Chin CS Skip [Alt]      | Inside forest haven at bottom for normal dtcs
| Leaf Hover [Alt]        | Inside Forest Haven, after DTCS with leaf spawned
| Quiver Swim             | At forest haven about to swim to thorned fairy island
| FF2 Swim                | At thorned fairy island about to swim to ff2
| Helmaroc Skip           | Inside ff2 tower at start of helmaroc king fight
| Barrier Skip            | Outside hyrule castle about to do barrier skip
| Trials Skip             | Inside ganon's tower about to do trials skip
| Puppet Ganon Fight      | Inside ganondorf's bedroom at start of puppet ganon fight
| Tuner Hover [Alt]       | At top of rope in ganondorf's bedroom for Tuner hover
| Morth Hover             | Inside ganondorf's bedroom after fight at top of room
| Ganondorf               | On top of ganondorf's tower at start of ganondorf fight

</details>

<details>
<summary>All Dungeons</summary>
<br>  
 
| Save                                | Description                   
| :--                                 | :--        
| Manual Superswim                    | After intro at bottom of tower
| Post Manual Superswim               | After MSS at DRI
| Forsaken Fortress 1 Chest Storage   | FF1 in yellow rupee chest room
| Windfall                            | At Windfall, after FF1 cutscene for sail/tuner/GFCS
| Ropes 2                             | In pirate ship, ropes 2 state
| Forest Haven Swim                   | At Windfall for swim to Forest Haven
| Early Leaf Hover                    | Outside Forest Haven for hover to higher entrance
| Deku Tree Cutscene Skip             | Inside Forest Haven upper spawn for cutscene skip
| Forbidden Woods                     | Start of Forbidden Woods
| Kalle Demos                         | Kalle Demos boss fight
| Enter Dragon Roost Cavern           | Outside Forest Haven for swim to ETI/DRI
| Dragon Roost Cavern                 | Start of DRC
| DRC Miniboss                        | Outside area of DRC
| DRC Boss Key Skip                   | Inside DRC in boss door room for BK skip
| Gohma                               | Gohma boss fight
| Nayru's Pearl                       | At DRI after DRC for balloon swim to Outset
| Enter Tower of the Gods             | Outside Jabuun's Cave for swim to STI/NTI
| Tower of the Gods                   | Start of TOTG
| Darknut                             | Darknut miniboss
| TOTG Third Statue                   | TOTG after returning second statue
| Gohdan                              | Gohdan boss fight
| Puzzle Skip                         | Inside Hyrule Castle for puzzle skip
| Hyrule Escape                       | Inside Hyrule Castle after Master Sword for Hyrule escape
| Barrier Skip                        | Outside Hyrule Castle for barrier skip
| Trial Skip                          | Inside Ganon's Tower, in trials room for trials skip
| Boomerang Skip                      | In Phantom Ganon's room for boomerang skip
| Phantom Ganon                       | Phantom Ganon fight miniboss
| Enter Helmaroc                      | After Phantom Ganon fight for chest storage climb
| Hyrule 2 Skip                       | In Helm boss fight for EMS cutscene skip
| Early Wind God's Aria               | At Windfall after FF2 for swim to Gale Isle
| Power Bracelets                     | At Fire Mountain for power bracelets
| Early Earth Temple                  | At Headstone for early Earth Temple
| Earth Temple                        | Start of Earth Temple
| Song Stone Skip                     | In Earth Temple in song stone room
| Jalhalla                            | Jalhalla boss fight
| Iron Boots                          | At Headstone for swim to Ice Ring for Iron Boots
| Makar                               | At Ice Ring for swim to Forest Haven for Makar
| Enter Wind Temple                   | At Forest Haven for balloon swim to Gale Isle
| Wind Temple                         | Start of Wind Temple
| Wizzrobe                            | Wizzrobe miniboss
| After Hookshot                      | Wind Temple after Hookshot
| Molgera                             | Molgera boss fight
| Swim to Flight Control Platform     | At Gale Isle for swim to Flight Control Platform
| FCP Layer Manip                     | At Flight Control Platform for layer manip dark portal
| Puppet Ganon Cutscene Skip          | In Grand Staircase for Puppet Ganon cutscene skip
| Puppet Ganon Skip                   | In Puppet Ganon room on layer 8 for Puppet Ganon skip
| Puppet Ganon                        | Puppet Ganon fight if not doing PG skip
| Ganondorf                           | Ganondorf boss fight

</details>

<details>
<summary>PST</summary>
<br>

| Save                              | Description
| :--                               | :--
| Manual Superswim                  | After intro at bottom of tower
| Early Diamond Steppe              | After MSS at bottom of tower at Outset
| Forsaken Fortress 1 Swim          | Outside Diamond Steppe, about to swim to NFI submarine
| Forsaken Fortress 1 Chest Storage | FF1 in yellow rupee chest room
| Greatfish Swim                    | At Windfall after getting sail for swim to Greatfish
| Wallet Swim                       | At Greatfish after the cutscene for swim to NFI
| Ropes 2                           | In pirate ship, ropes 2 state
| Forest Haven Swim                 | At Windfall for swim to Forest Haven
| Early Leaf Hover                  | Outside Forest Haven for hover to higher entrance
| Deku Tree Cutscene Skip           | Inside Forest Haven upper spawn for cutscene skip
| Forbidden Woods                   | Start of Forbidden Woods
| Kalle Demos                       | Kalle Demos boss fight
| Enter Dragon Roost Cavern         | Outside Forest Haven for swim to ETI/DRI
| Dragon Roost Cavern               | Start of DRC
| Dragon Roost Cavern Miniboss      | Outside area of DRC
| Gohma                             | Gohma boss fight
| Bird's Peak Rock                  | At DRI after pearl cutscene for swim to BPR
| Ghost Ship 1                      | At Windfall for swim to Crescent Moon ghost ship
| Islet of Steel Swim               | At NTI for swim to IOS
| Nayru's Pearl                     | At Needle Rock Isle for swim to Outset for Nayru's Pearl
| Enter Tower of the Gods           | Outside Jabun's cave for swim to STI
| Tower of the Gods                 | Start of TotG
| Darknut                           | TotG Darknut miniboss
| Gohdan                            | Gohdan boss fight
| Puzzle Skip                       | Inside Hyrule Castle for puzzle skip
| Hyrule Escape                     | Inside Hyrule Castle after Master Sword for Hyrule escape
| Cyclos                            | Outside TotG for sail to NTI for Cyclos
| Forsaken Fortress 2 Swim          | At Tingle Island near Tingle for swim to FF2
| Phantom Ganon                     | Phantom Ganon fight miniboss
| Enter Helmaroc                    | After Phantom Ganon fight for chest storage climb
| Helmaroc Skip                     | In Helmaroc boss fight for Helmaroc skip
| Early Wind God's Aria             | Inside Mother and Child after Hyrule 2 for early WGA
| Power Bracelets                   | At Gale Isle for swim to Fire Mountain
| Earth God's Lyrics                | At Shark Isle for swim to Headstone
| Stonewatcher Swim                 | At Headstone for swim to Stonewatcher
| Stonewatcher Cave                 | In Stonewatcher cave for Triforce Chart
| Ghost Ship 2                      | At Stonewatcher for swim to Diamond Steppe ghost ship
| Needle Rock Chart                 | In Diamond Steppe quadrant for sailing to Needle Rock
| Medli                             | At DRI for chest storage to Medli
| Eastern Triangle Island Swim      | At DRI after getting Medli for swim to EFI/Greatfish
| Earth Temple Swim                 | At Greatfish for swim to Earth Temple
| Earth Temple                      | Start of Earth Temple
| Mirror Shield                     | In Earth Temple in the shortcut room for ZH to miniboss
| Song Stone Skip                   | In Earth Temple in song stone room
| Jalhalla                          | Jalhalla boss fight
| Makar                             | At Headstone, about to get Makar
| Iron Boots                        | At Forest Haven after getting Makar for swim to Ice Ring
| Wind Temple                       | Start of Wind Temple
| Wizzrobe Miniboss                 | Wizzrobe miniboss fight
| After Hookshot                    | In Wind Temple after miniboss
| Molgera                           | Molgera boss fight
| Overlook Swim                     | At Gale Isle for swim to Overlook
| Overlook Cave                     | In Overlook cave for Triforce Chart
| Private Oasis                     | At Private Oasis for chest storage early cabana
| Gale Isle                         | At Tingle Island for swim to Gale Isle
| Savage Labyrinth                  | Start of Savage Labyrinth
| Savage Labyrinth Floor 10         | In first Savage Labyrinth break floor
| Savage Labyrinth Floor 20         | In second Savage Labyrinth break floor
| Triforce                          | At Tingle Island for salvaging the last 3 Triforce shards
| Hyrule Darknuts                   | In Master Sword chamber for Darknut fight
| Barrier Cutscene Skip             | Outside Hyrule Castle for barrier cutscene skip
| Trials Skip                       | Inside Ganon's Tower, in trials room for trials skip
| Puppet Ganon                      | Puppet Ganon boss fight
| Ganondorf                         | Ganondorf boss fight

</details>

<details>
<summary>Any% (Bombs First, No PG Skip)</summary>
<br>  
 
| Save                        | Description                                    
| :--                         | :--                                           
| Manual Superswim            | Just after the intro, at bottom of watchtower
| Post Manual Superswim       | After MSS at DRI
| Windfall                    | At Windfall Island, post FF1 cutscene
| Ropes 2                     | Inside pirate ship, ropes 2 minigame state
| Forest Haven Swim           | At Windfall Island post bombs for swim to Forest Haven
| Deku Tree Cutscene Skip     | Inside Forest Haven for first time, for DTCS
| Leaf Hover                  | Inside Forest Haven, after DTCS with leaf spawned
| Quiver Swim                 | Outside Forest Haven, quiver swim or FF2 PG skip swim
| FF2 Swim                    | At Thorned Fairy Island, FF2 swim assuming you got quiver
| Helmaroc Skip               | Inside FF2 Tower, at start of Helmaroc King fight
| Barrier Skip                | Outside Hyrule Castle, about to do barrier skip
| Trials Skip                 | Inside Ganon's Tower, in trials room for trials skip
| Puppet Ganon Fight          | Bottom of Ganondorf's Bedroom, at start of Puppet Ganon fight
| Morth Hover                 | Inside Ganondorf's Bedroom after fight, at top of room
| Ganondorf                   | On top of Ganondorf's Tower, at start of Ganondorf fight

</details>

<details>
<summary>PMG</summary>
<br>

| Save                          | Description
| :--                           | :--
| After Intro                   | Just after the intro, at bottom of watchtower
| Orca                          | Inside Orca's house, about to do sword tutorial
| Forest of Fairies             | Inside Forest of Fairies, about to rescue Tetra
| Ropes 1                       | Inside pirate ship, about to play ropes 1 minigame
| Early Light Cycle             | Outside ship, before barrel launch cutscene
| Forsaken Fortress 1           | At start of FF1
| FF1 Interior                  | FF1 in the rope swing room
| Windfall                      | At Windfall Island, just finished talking to Korl
| Zephos Skip                   | At DRI, about to perform Zephos skip for Wind's Requiem
| Submarine Swim                | At DRI, about to swim to Bomb Island submarine
| Delivery Bag Skip             | At DRI, with chest storage, about to climb DRI to skip delivery bag
| Dragon Roost Cavern           | Start of DRC
| DRC Chest Storage             | In DRC map room, about to get chest storage
| DRC Outside Climb             | In DRC outside area, about to climb DRC with chest storage
| DRC Miniboss                  | In miniboss room, outside DRC
| DRC Boss Key Skip             | Inside DRC in boss door room for BK skip
| Gohma                         | Gohma boss fight
| Forest Haven Swim             | At DRI, after Din's Pearl cutscene, about to swim to FH
| Deku Tree Cutscene Skip       | Inside FH, about to perform DTCS
| Enter Forbidden Woods         | Inside Forest Haven, about to leaf to FW
| Forbidden Woods               | Start of Forbidden Woods
| FW Small Key Skip             | In main room of FW, about to leaf to the upper part of FW
| FW Miniboss                   | Molduga miniboss room
| FW Boss Key Skip              | In main room of FW, near warp pot, about to store Morth Pit chest
| Kalle Demos                   | Kalle Demos boss fight
| Placing Pearls                | Outside FH for swim to ETI/NTI
| Islet of Steel Swim           | At NTI, about to swim to Islet of Steel
| Windfall Swim                 | At Greatfish, about to swim to Windfall for bombs
| Ropes 2                       | Inside pirate ship, about to get bombs
| Nayru's Pearl                 | On Windfall docks, about to swim to Outset for Nayru's Pearl
| Enter Tower of the Gods       | Outside Jabun's cave, about to swim to STI
| Tower of the Gods             | Entrance of Tower of the Gods
| TotG Second Statue            | Inside TotG second statue room
| TotG Miniboss                 | Darknut miniboss fight
| TotG Third Statue             | In the room before the third TotG statue
| Gohdan                        | Gohdan boss fight
| Puzzle Skip                   | Inside Hyrule Castle for puzzle skip
| Hyrule Escape                 | Inside Hyrule Castle after Master Sword for Hyrule escape
| Forsaken Fortress 2 Swim      | On NTI, about to swim to FF2
| Phantom Ganon                 | Phantom Ganon miniboss fight
| Enter Helmaroc                | After Phantom Ganon fight for chest storage climb
| Helmaroc                      | At the top of FF2 tower, about to start the Helmaroc fight
| Barrier Skip                  | Outside Hyrule Castle, about to do barrier skip
| Trials Skip                   | Inside Ganon's Tower, about to do trials skip
| Puppet Ganon Fight            | Inside Ganondorf's bedroom, at start of Puppet Ganon fight
| Morth Hover                   | At the top of Ganondorf's bedroom for Morth hover
| Ganondorf                     | On top of Ganondorf's tower, at start of Ganondorf fight

</details>

<details>
<summary>100%</summary>
<br>

| Save                              | Description
| :--                               | :--
| Mailgame                          | About to start mail minigame for note to mom
| Dragon Roost Cavern               | At the beginning of DRC
| Pot Push Storage                  | About to get chest storage in DRC
| Boko Room                         | Inside 3 Bokos room
| DRC Miniboss                      | Outside ship, before barrel launch cutscene
| DRC Boss Key Skip                 | Skip DRC boss key with chest storage
| Zephos Skip                       | About to skip Zephos cutscene
| DRI to Windfall Swim              | After Zephos skip, about to swim to Windfall
| Forest Haven Swim 1               | At Windfall, about to swim to Forest Haven
| Deku Tree Cutscene Skip           | Inside FH, about to perform DTCS
| Leaf to Forest of Fairies         | At Outset Island, about to leaf to FoF
| FoF Fairy Clip                    | About to roll clip inside FoF great fairy
| Leaf to Invisible Pirate Ship     | At Outset, about to leaf to pirate ship
| Ropes 1                           | Inside pirate ship, for spoils bag
| FF1 Door Teleport                 | On pirate ship at FF1, about to store ship door
| Ropes 2                           | Inside pirate ship, for bombs
| FF1                               | At the bottom of FF1
| Windfall 1                        | 1st trip to Windfall, about to start hide and seek
| Forest Haven Swim 2               | At Windfall docks, about to swim to FH
| Enter Forbidden Woods             | Inside Forest Haven, about to leaf to FW
| Forbidden Woods                   | Start of Forbidden Woods
| FW Small Key Skip                 | Start of Forbidden Woods
| FW Miniboss                       | In FW miniboss room, about to fight Flying Mothula for boomerang
| FW Basement                       | In FW basement for chart chest
| FW BK Skip                        | In double Mothula room, for chest storage BK skip
| Kalle Demos                       | Forbidden Woods boss
| Placing Pearls                    | At Forest Haven, about to swim to Eastern Triangle
| Northern Triangle Swim            | At Eastern Triangle, about to swim to Northern Triangle
| Islet of Steel Swim               | At Northern Triangle, about to swim to Islet of Steel
| Outset Swim                       | At Greatfish Isle, about to swim to Outset Island
| Outset Bomb Ledge Clip            | Bomb ledge clip to enter Jabun's cave
| Southern Triangle Swim            | At Outset, about to swim to Southern Triangle
| Tower of the Gods                 | Start of Tower of the Gods
| TotG 2nd Statue                   | In 2nd statue room
| TotG Miniboss                     | Tower of the Gods Darknut miniboss fight
| TotG Scales Room                  | In TotG scales room before small key
| Gohdan                            | Tower of the Gods boss
| Cyclos                            | About to fight Cyclos for Ballad of Gales
| Crescent Moon Swim                | At NTI, about to swim to Crescent Moon sub
| Crescent Moon Submarine           | Inside Crescent Moon submarine
| FF2 Swim                          | Double storage superswim from Crescent Moon
| Helmaroc Skip                     | Skip Helmaroc to watch Hyrule 2 cutscenes
| Puzzle Skip                       | In Hyrule, before Tetra to Zelda cutscenes
| Barrier Skip                      | Outside Hyrule Castle, for barrier skip
| Trials Skip                       | In trials hub room, inside Ganon's Tower
| Helmaroc Cutscene Skip            | About to skip Helmaroc cutscene to prevent a crash
| Helmaroc                          | About to fight Helmaroc
| Windfall 2                        | 2nd trip to Windfall
| Gale Island Swim 1                | At Windfall, about to swim to Gale Island for WGA
| Fire Mountain Swim                | At Gale Island, about to swim to Fire Mountain for power bracelets
| Bird's Peak Rock Swim             | At Fire Mountain, about to swim to Bird's Peak Rock for Triforce Chart 3
| Ice Ring Swim                     | At Bird's Peak Rock, about to swim to Ice Ring for Iron Boots and Treasure Chart 36
| Two Eye Swim                      | At Ice Ring Isle, about to swim to Two Eye Reef for double magic octo
| Two Eye Big Octo                  | At Two Eye, about to fight double magic big octo
| Early Earth Temple                | Bomb push clip to enter Earth Temple
| Earth Temple                      | Start of Earth Temple
| Earth Temple Chu Room             | Earth Temple third room
| Song Stone Skip                   | In basement, about to skip 1st song stone
| Earth Temple Floormasters         | In Floormaster's room, for Treasure Chart 20
| Earth Temple Mirror Room          | In Many Mirrors room, about to clip in 3 Stalfos room
| Earth Temple Boss Key Skip        | Leaf pump to boss door
| Jalhalla                          | Earth Temple boss
| Horseshoe Swim                    | At Headstone Island, about to swim to Horseshoe for Treasure Chart 8
| Play Golf                         | Golf holes 1 and 2 skip
| Horseshoe Chest Storage           | Store heart piece chest to enter Diamond Steppe
| Inside Diamond Steppe             | Inside Diamond Steppe Island for Ghost Ship Chart
| Three Eye Swim                    | At Diamond Steppe, about to swim to Three Eye Reef for Chart 32 and heart piece
| Forest Water Shark Island Swim    | Start of the Forest Water segment
| Forest Water Needle Rock Swim     | At Shark Isle, about to swim to Needle Rock for Chart 16
| Five Eye Swim                     | At Needle Rock Isle, about to swim to Five Eye Reef for Chart 41
| Five Eye                          | Clear 5 Eye Reef for Chart 41
| Eastern Fairy Swim                | At Five Eye, about to swim to Eastern Fairy Island for bomb upgrade and Chart 40
| Gale Island Swim 2                | At Windfall, about to swim to Gale Island with double storage
| Wind Temple                       | Start of Wind Temple
| Wind Temple Miniboss              | Wind Temple miniboss room
| Wind Temple Spiky Room            | Break floors for chest
| Wind Temple Locked Room           | Big circular room
| Molgera                           | Wind Temple boss
| Star Island Swim                  | At Gale Island, about to swim to Star Island
| Star Island Cave                  | Inside Star Island cave for heart piece
| Northern Fairy Swim               | At Star Island, about to swim to Northern Fairy Island for Chart 22
| Ghost Ship                        | Farm rupees inside Ghost Ship
| Spectacle Island Minigame         | Spectacle Island minigame for heart piece and Chart 17
| Tingle Island Big Octo            | About to fight Tingle Island octo for heart piece
| Stonewatcher Swim                 | At Tingle Island, about to swim to Stonewatcher for Triforce Chart 7
| Stonewatcher Cave                 | Inside Stonewatcher cave
| Six Eye Swim                      | Swim to Six Eye Reef from Stonewatcher lookout platform
| Six Eye Submarine                 | Inside Six Eye Reef submarine
| Cyclops Reef                      | Clear Cyclops Reef for Chart 21
| Pawprint Swim                     | At Cyclops Reef, about to swim to Pawprint Island for heart piece
| Overlook Swim                     | At Pawprint, about to swim to Overlook Island for Triforce Chart 9
| Overlook Cave                     | Inside Overlook Island cave
| Savage Labyrinth                  | Start of Savage Labyrinth
| Savage 10                         | Savage Labyrinth 10th floor
| Savage 20                         | Savage Labyrinth 20th floor
| Savage Chest                      | Farm rupees before getting Triforce Chart 6
| Orca 500                          | Hit an old man 500 times
| Pig Yeet                          | Pig yeeeeet
| Headstone Sub Swim                | At Outset Island, about to swim to Headstone submarine for Chart 14
| Angular Swim                      | At Headstone, about to swim to Angular Isles for heart piece
| Bomb Island Sub Swim              | At Angular, about to swim to Bomb Island submarine for Bottle 3
| Bomb Island Cave                  | Inside Bomb Island cave
| FCP Swim                          | At Bomb Island, about to swim to Flight Control Platform for heart piece
| Mother and Child Swim 1           | At Windfall Island, about to swim to Mother and Child Isles
| Four Eye Swim                     | At Mother and Child, about to swim to Four Eye Reef for Chart 19
| Western Fairy Swim                | At Four Eye, about to swim to Western Fairy Island for quiver upgrade
| Rock Spire Swim                   | Peg storage on Western Fairy Island
| Rock Spire Cave                   | Inside Rock Spire cave
| Forest Haven HP on Isle FW2       | Start of the Forest Water 2 segment, about to get small island heart piece
| Cabana Swim FW2                   | At Forest Haven, about to swim to Private Oasis for Chart 27 and Triforce Chart 2
| Inside Cabana FW2                 | Inside cabana for Triforce Chart 2
| Tingle Island Swim FW2            | At Private Oasis, about to swim (or warp) to Tingle Island
| Gale Island Swim 3 FW2            | At Tingle Island, about to swim to Gale Island for Shard 2
| Seven Star Octo FW2               | Seven Star Isles for heart piece and Shard 7
| Two Eye Swim 2 FW2                | At Southern Triangle, about to swim to 2 Eye Reef for Shard 8 and Chart 13
| Two Eye Reef FW2                  | Clear Two Eye Reef
| Five Star Swim FW2                | At Two Eye, about to swim to Five Star submarine for heart piece
| Five Star Chest Storage FW2       | Get storage on top of Five Star submarine
| Thorned Fairy Swim FW2            | Superswim to Thorned Fairy from Cliff Plateau Isles
| Mother and Child Swim 2 FW2       | Trade postman statue with Goron at Mother and Child Isles, end of the Forest Water 2 segment
| Six Eye Reef                      | Clear 6 Eye Reef
| FF3 Swim                          | Superswim to Forsaken Fortress 3 from Six Eye Reef
| Puppet Ganon Skip                 | Skip or fight Puppet Ganon
| Ganondorf                         | Ganondorf boss fight

</details>

---

### Scene

#### Change/view various properties of the scene

| Option              | Description                   
| :--                 | :--    
| Disable BG Music    | Disable background music from playing    
| Freeze Time         | Freeze the current time of day 
| Wind Direction      | Change current wind direction
| Chart Set           | Change current chart set of file
| Current Hour        | Change current hour
| Current Minutes     | Change current minute
| Current Date        | Change current date/moon phase
| Collision Viewer    | View various types of collision
| Actor List          | Display info from actor list
| Actor Spawner       | Spawn actors at current position

#### Collision Viewer - view various types of collision

| Option              | Description                   
| :--                 | :--    
| Attack Colliders    | View hitboxes; Colliders that hurt Target Colliders
| Target Colliders    | View hurtboxes; Colliders that get hurt by Attack Colliders
| Push Colliders      | View colliders that allow actors to bump/push into each other
| Ground Polys        | View floor collision polygons
| Roof Polys          | View ceiling collision polygons
| Wall Polys          | View wall collision polygons
| Poly Edges          | View edges of each polygon
| Poly Draw Raise     | Amount to raise the drawn polygons by
| Opcaity             | Transparency amount of collision viewer
 
TODO: Explain more about how Actor List works

TODO: Explain more about how Actor Spawner works

---

### Settings

| Option                    | Description                   
| :--                       | :--    
| Cursor Color              | Change cursor color
| Font                      | Change font
| Drop Shadows              | Add shadows to all font characters
| Decimal Angles            | Display angles in decimal instead of hex
| Custom Save Positions     | Turn on/off custom positions in saves that support them
| Item Equip Priorities     | Adjust priorities on item equips in practice saves
| Save Card                 | Save settings to memory card
| Load Card                 | Load settings from memory card
| Delete Card               | Delete settings on memory card
| Menu Positions            | Change menu object pistions (A tot oggle selection, Dpad to move)
| Fast Swim Speed           | Change max speed of fast movement cheat for swimming
| Fast Land Speed           | Change max speed of fast movement cheat on land
| Spawn ID                  | Set spawn ID for disable save checks tool, invalid ID's will crash
| Pause Buffer Input Button | Set the button to train buffering after a pause

Moveable Lists: Main Menu, FIFO Queue, Link Debug Info, Time Display, Input Viewer, Frame Timer, Zombie Hover Info, Stage Info

---

### Tools

| Option                     | Description                   
| :--                        | :--    
| Link Debug Info            | Display position and angle data for Link
| Display Time Info          | Display current day, time and moon phase
| Stage Info                 | Display Link's current stage info
| Teleport                   | R+D-pad up to save position. R+D-pad down to load
| Area Reload                | Reload the current room by pressing L + R + A + Start
| Map Aelect                 | Load Map Select by holding D-pad down + Y + Z
| Zombie Hover Info          | Display A and B button presses per second
| Input Viewer               | Show current inputs
| Timers                     | Toggle timers (frames and seconds) with L + R + D-pad Right, reset with L + R + D-pad Left
| Frame Advance              | D-pad Down to pause/unpause, D-pad Up to advance frames
| ESS Checker                | Change input viewer stick color based on distance from perfect ess
| Deadzone Checker           | Change input viewer stick coor if stick is in deadzone
| Disable Save Checks        | Disable save location safety checks, set used spawn ID in settings menu
| Intro Skip                 | Skip lore segment of intro on start of new file
| Room Reload/Void Out       | Reload room by void out with L + R + B + Start
| Roll Clip Trainer          | Train roll clip timing with an OSD
| Pause Buffer Input Trainer | Train pause buffered input timing with an OSD
| Move Link                  | Move Link around freely by pressing L + R + Y
| Turbo Controller           | Simulate turbo controller inputs by holding a button
| Figurine Checker           | Check if the picture you take will be accepted by Carlov to make a figurine
