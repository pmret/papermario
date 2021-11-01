maps = [f.split(" = ") for f in """
% areas
kmr = Goomba Region
mac = Toad Town
tik = Toad Town Tunnels
kgr = Inside the Whale
kkj = Peach's Castle
hos = Shooting Star Summit
nok = Koopa Region
trd = Koopa Bros Fortress
iwa = Mt Rugged
dro = Dry Dry Outpost
sbk = Dry Dry Desert
isk = Dry Dry Ruins
mim = Forever Forest
obk = Boo's Mansion
arn = Gusty Gulch
dgb = Tubba's Castle
omo = Shy Guy's Toybox
jan = Jade Jungle
kzn = Mt Lavalava
flo = Flower Fields
sam = Mt Shiver
pra = Crystal Palace
kpa = Bowser's Castle
osr = Peach's Castle Grounds
end = Ending
mgm = Minigame
gv  = Game Over
tst = Testing

% area_kmr
kmr_00 = Forest Clearing
kmr_02 = Goomba Village
kmr_03 = Bottom of the Cliff
kmr_04 = Jr. Troopa's Playground
kmr_05 = Behind the Village
kmr_06 = Goomba Road 2
kmr_07 = Goomba Road 3
kmr_09 = Goomba Road 1
kmr_10 = Toad Town Entrance
kmr_11 = Goomba King's Castle
kmr_12 = Goomba Road 4
kmr_20 = Mario's House
kmr_21 = Title Screen
kmr_22 = Chapter Start
kmr_23 = Chapter End
kmr_24 = Save and Continue
kmr_30 = Mario's House (Ending)
kmr_bt03 = Goomba Bros (Boss)
kmr_bt04 = Open Forest
kmr_bt05 = Rockey Forest
kmr_bt06 = Goomba King (Boss)

% area_mac
machi = Debug Warp Zone
mac_00 = Gate District
mac_01 = Plaza District
mac_02 = Southern District
mac_03 = Station District
mac_04 = Residental District
mac_05 = Port District
mac_06 = Riding the Whale
mac_bt01 = Port
mac_bt02 = Dojo

% area_tik
% note: B1/B2/etc refer to the number of pipes/falls required to reach the room
tik_01 = Warp Zone 1 (B1)
tik_02 = Blooper Boss 1 (B1)
tik_03 = Short Elevator Room (B1)
tik_04 = Scales Room (B2)
tik_05 = Spring Room (B2)
tik_06 = Sewer Entrance (B1)
tik_07 = Elevator Attic Room (B2)
tik_08 = Second Level Entry (B2)
tik_09 = Warp Zone 2 (B2)
tik_10 = Block Puzzle Room (B2)
tik_12 = Metal Block Room (B3)
tik_14 = Rip Cheato Antechamber (B3)
tik_15 = Rip Cheato's Home (B3)
tik_17 = Frozen Room (B3)
tik_18 = Hall to Blooper 1 (B1)
tik_19 = Under the Toad Town Pond
tik_20 = Room with Spikes (B2)
tik_21 = Hidden Blocks Room (B2)
tik_22 = Path to Shiver City (B2)
tik_23 = Windy Path (B3)
tik_24 = Hall to Ultra Boots (B3)
tik_25 = Ultra Boots Room (B3)
tik_bt01 = Simple Hall
tik_bt02 = Between Platforms
tik_bt03 = Pipe Bridge
tik_bt04 = Beside Waterway
tik_bt05 = Under the Pond

% area_kgr
kgr_01 = Whale Mouth
kgr_02 = Whale Stomach
kgr_bt01 = Whale Stomach

%area_kkj
kkj_00 = Intro Entry Hall (1F)
kkj_01 = Intro Upper Hall (2F)
kkj_02 = Intro Stairs Hallway (3F)
kkj_03 = Intro Window Hallway (4F)
kkj_10 = Entry Hall (1F)
kkj_11 = Upper Hall (2F)
kkj_12 = Stairs Hallway (3F)
kkj_13 = Window Hallway (4F)
kkj_14 = Peach's Room (2F)
kkj_15 = Passage Outlet (2F)
kkj_16 = Library (2F)
kkj_17 = Storeroom (2F)
kkj_18 = Dining Room (2F)
kkj_19 = Kitchen (1F)
kkj_20 = Guest Room (1F)
kkj_21 = Inactive Quiz-Off (1F)
kkj_22 = Double Staircase (4F)
kkj_23 = Rooftop (5F)
kkj_24 = Tower Staircase (5F)
kkj_25 = Final Boss Arena (6F)
kkj_26 = Balcony (2F)
kkj_27 = Secret Passage (2F)
kkj_28 = Darkened Quiz-Off (1F)
kkj_29 = Quiz-Off Room (1F)
kkj_bt01 = Intro Bowser
kkj_bt02 = Final Bowser

% area_hos
hos_00 = Shooting Star Path
hos_01 = Shooting Star Summit
hos_02 = Star Way
hos_03 = Star Haven
hos_04 = Outside the Sanctuary
hos_05 = Star Sanctuary
hos_06 = Merluvlee's House
hos_10 = Ending Descent Scene
hos_20 = Riding Star Ship Scene
hos_bt01 = Star Way (Space)
hos_bt02 = Near Bridge

% area_nok
nok_01 = Koopa Village 1
nok_02 = Koopa Village 2
nok_03 = Behind Koopa Village
nok_04 = Fuzzy Forest
nok_11 = Pleasant Path Entry
nok_12 = Pleasant Path Bridge
nok_13 = Pleasant Crossroads
nok_14 = Path to Fortress 1
nok_15 = Path to Fortress 2
nok_bt01 = Path with Fence
nok_bt02 = Path in Forest
nok_bt03 = Bridge
nok_bt04 = Fuzzy Forest

% area_trd
trd_00 = Fortress Exterior
trd_01 = Left Tower
trd_02 = Left Stairway
trd_03 = Central Hall
trd_04 = Right Starway
trd_05 = Right Tower
trd_06 = Jail
trd_07 = Dungeon Trap
trd_08 = Dungeon Fire Room
trd_09 = Battlement
trd_10 = Boss Battle Room
trd_bt00 = Boss
trd_bt01 = Central
trd_bt02 = Dungeon
trd_bt03 = Battlement
trd_bt04 = Spiral
trd_bt05 = Stairway

% area_iwa
iwa_00 = Mt Rugged 1
iwa_01 = Mt Rugged 2
iwa_02 = Mt Rugged 3
iwa_03 = Mt Rugged 4
iwa_04 = Suspension Bridge
iwa_10 = Train Station
iwa_11 = Train Ride Scene
iwa_bt01 = Mt Rugged
iwa_bt02 = Near Bridge

% area_dro
dro_01 = Outpost 1
dro_02 = Outpost 2

% area_sbk
% note: directions relative to center
sbk_00 = N3W3
sbk_01 = N3W2
sbk_02 = N3W1 Ruins Entrance
sbk_03 = N3
sbk_04 = N3E1
sbk_05 = N3E2 Pokey Army
sbk_06 = N3E3
sbk_10 = N2W3
sbk_11 = N2W2
sbk_12 = N2W1
sbk_13 = N2
sbk_14 = N2E1 (Tweester A)
sbk_15 = N2E2
sbk_16 = N2E3
sbk_20 = N1W3 Special Block
sbk_21 = N1W2
sbk_22 = N1W1
sbk_23 = N1 (Tweester B)
sbk_24 = N1E1 Palm Trio
sbk_25 = N1E2
sbk_26 = N1E3
sbk_30 = W3 Kolorado's Camp
sbk_31 = W2
sbk_32 = W1
sbk_33 = Center (Tweester C)
sbk_34 = E1 Nomadimouse
sbk_35 = E2
sbk_36 = E3 Outside Outpost
sbk_40 = S1W3
sbk_41 = S1W2 (Tweester D)
sbk_42 = S1W1
sbk_43 = S1
sbk_44 = S1E1
sbk_45 = S1E2 Small Bluffs
sbk_46 = S1E3 North of Oasis
sbk_50 = S2W3
sbk_51 = S2W2
sbk_52 = S2W1
sbk_53 = S2
sbk_54 = S2E1 Blue Cactus
sbk_55 = S2E2 West of Oasis
sbk_56 = S2E3 Oasis
sbk_60 = S3W3
sbk_61 = S3W2 Hidden AttackFX
sbk_62 = S3W1
sbk_63 = S3
sbk_64 = S3E1
sbk_65 = S3E2
sbk_66 = S3E3 South of Oasis
sbk_99 = Entrance
sbk_bt02 = Desert

% area_isk
isk_01 = Entrance
isk_02 = Sarcophagus Hall 1
isk_03 = Sand Drainage Room 1
isk_04 = Descending Stairs 1
isk_05 = Pyramid Stone Room
isk_06 = Sand Drainage Room 2
isk_07 = Sarcophagus Hall 2
isk_08 = Descending Stairs 2
isk_09 = Super Hammer Room
isk_10 = Vertical Shaft
isk_11 = Stone Puzzle Room
isk_12 = Sand Drainage Room 3
isk_13 = Lunar Stone Room
isk_14 = Diamond Stone Room
isk_16 = Tutankoopa Room
isk_18 = Deep Tunnel
isk_19 = Boss Antechamber
isk_bt01 = Tutankoopa Boss
isk_bt02 = Staircase and Sarcophagi
isk_bt03 = Upper Sarcophagi
isk_bt04 = Puzzle Room
isk_bt05 = Dark Passge
isk_bt06 = Right Stone Room
isk_bt07 = Left Stone Room
isk_bt08 = Lower Sarcophagi

% area_mim
mim_01 = Flower Sounds
mim_02 = Stump Eyes
mim_03 = Flowers (Oaklie)
mim_04 = Tree Face (Bub-ulb)
mim_05 = Mushrooms (HP Plus)
mim_06 = Bee Hive (Path Splits)
mim_07 = Flowers Vanish
mim_08 = Laughing Rock
mim_09 = Flowers Appear (FP Plus)
mim_10 = Exit to Toad Town
mim_11 = Outside Boo's Mansion
mim_12 = Exit to Gusty Gulch
mim_bt01 = Forest

% area_obk
obk_01 = Foyer
obk_02 = Basement Stairs
obk_03 = Basement
obk_04 = Super Boots Room
obk_05 = Pot Room
obk_06 = Library
obk_07 = Record Player Room
obk_08 = Record Room
obk_09 = Lady Bow's Room

% area_arn
arn_02 = Wasteland Ascent 1
arn_03 = Ghost Town 1
arn_04 = Wasteland Ascent 2
arn_05 = Ghost Town 2
arn_07 = Windmill Exterior
arn_08 = Windmill Interior
arn_09 = Windmill Tunnel Entry
arn_10 = Tunnel 1
arn_11 = Tubba's Heart Chamber
arn_12 = Tunnel 2
arn_13 = Tunnel 3
arn_20 = Tubba's Manor Exterior
arn_bt01 = Wasteland 2
arn_bt02 = Windmill Exterior
arn_bt03 = Wasteland 1
arn_bt04 = Tunnel Entry
arn_bt05 = Tunnel
arn_bt06 = Heart Boss

% area_dgb
dgb_00 = Escape Scene
dgb_01 = Great Hall
dgb_02 = West Hall (1F)
dgb_03 = Table/Clock Room (1/2F)
dgb_04 = Stairs to Basement
dgb_05 = Stairs Above Basement
dgb_06 = Basement
dgb_07 = Study (1F)
dgb_08 = East Hall (1/2F)
dgb_09 = West Hall (2F)
dgb_10 = Sealed Room (2F)
dgb_11 = Covered Tables Room (1F)
dgb_12 = Spike Trap Room (2F)
dgb_13 = Hidden Bedroom (2F)
dgb_14 = Stairs to Third Floor
dgb_15 = West Hall (3F)
dgb_16 = Sleeping Clubbas Room (3F)
dgb_17 = Save Room (3F)
dgb_18 = Master Bedroom (3F)
dgb_bt01 = Hall
dgb_bt02 = Table
dgb_bt03 = Window Hall
dgb_bt04 = Basement
dgb_bt05 = Master Bedroom

% area_omo
omo_01 = BLU Large Playroom
omo_02 = RED Boss Barricade
omo_03 = BLU Station
omo_04 = BLU Block City
omo_05 = PNK Gourmet Guy Crossing
omo_06 = PNK Station
omo_07 = PNK Playhouse
omo_08 = GRN Station
omo_09 = GRN Treadmills/Slot Machine
omo_10 = RED Station
omo_11 = RED Moving Platforms
omo_12 = RED Lantern Ghost
omo_13 = BLU Anti-Guy Hall
omo_14 = RED Boss Antechamber
omo_15 = RED General Guy Room
omo_16 = Riding the Train
omo_17 = PNK Tracks Hallway
omo_bt01 = Toybox
omo_bt02 = Block City
omo_bt03 = Dark Room
omo_bt04 = Slot Machine
omo_bt05 = Train Tracks
omo_bt06 = Moving Platforms
omo_bt07 = Boss Room

% area_jan
jan_00 = Whale Cove
jan_01 = Beach
jan_02 = Village Cove
jan_03 = Village Buildings
jan_04 = Sushi Tree
jan_05 = SE Jungle (Quake Hammer)
jan_06 = NE Jungle (Raven Statue)
jan_07 = Small Jungle Ledge
jan_08 = SW Jungle (Super Block)
jan_09 = NW Jungle (Large Ledge)
jan_10 = Western Dead End
jan_11 = Root Cavern
jan_12 = Deep Jungle 1
jan_13 = Deep Jungle 2 (Block Puzzle)
jan_14 = Deep Jungle 3
jan_15 = Deep Jungle 4 (Ambush)
jan_16 = Base of Great Tree
jan_17 = Lower Great Tree Interior
jan_18 = Great Tree Vine Ascent
jan_19 = Upper Great Tree Interior
jan_22 = Path to the Volcano
jan_23 = Great Treetop Roost
jan_bt00 = Beach
jan_bt01 = Jungle Islands
jan_bt02 = Jungle Cliffs
jan_bt03 = Deep Jungle
jan_bt04 = Deep Jungle Ambush

% area_kzn
kzn_01 = Volcano Entrance
kzn_02 = First Lava Lake
kzn_03 = Central Cavern
kzn_04 = Fire Bar Bridge
kzn_05 = Descent Toward Ultra Hammer
kzn_06 = Flowing Lava Puzzle
kzn_07 = Ultra Hammer Room
kzn_08 = Dizzy Stomp Room
kzn_09 = Zipline Cavern
kzn_10 = Descent Toward Boss
kzn_11 = Second Lava Lake
kzn_17 = Spike Roller Trap
kzn_18 = Boss Antechamber
kzn_19 = Boss Room
kzn_20 = Rising Lava 1
kzn_22 = Rising Lava 2
kzn_23 = Volcano Escape
kzn_bt01 = Cavern
kzn_bt02 = Lava Lake 1
kzn_bt04 = Lava Lake 2
kzn_bt05 = Lava Piranha Boss

% area_flo
flo_00 = Center
flo_03 = (East) Petunia's Field
flo_07 = (SW) Posie and Crystal Tree
flo_08 = (SE) Briar Platforming
flo_09 = (East) Triple Tree Path
flo_10 = (SE) Lily's Fountain
flo_11 = (West) Maze
flo_12 = (West) Rosie's Trellis
flo_13 = (NW) Lakilester
flo_14 = (NW) Bubble Flower
flo_15 = (NW) Sun Tower
flo_16 = (NE) Elevators
flo_17 = (NE) Fallen Logs
flo_18 = (NE) Puff Puff Machine
flo_19 = Cloudy Climb
flo_21 = Huff N Puff Room
flo_22 = (East) Old Well
flo_23 = (West) Path to Maze
flo_24 = (SE) Water Level Room
flo_25 = (SW) Path to Crystal Tree
flo_bt01 = Field
flo_bt02 = Tree
flo_bt03 = Puff Puff Machine
flo_bt04 = Huff N Puff Boss
flo_bt05 = Hedge Maze
flo_bt06 = Wasteland

% area_sam
sam_01 = Shiver City Mayor Area
sam_02 = Shiver City Center
sam_03 = Road to Shiver Snowfield
sam_04 = Shiver Snowfield
sam_05 = Path to Starborn Valley
sam_06 = Starborn Valley
sam_07 = Shiver Mountain Passage
sam_08 = Shiver Mountain Hills
sam_09 = Shiver Mountain Tunnel
sam_10 = Shiver Mountain Peaks
sam_11 = Shiver City Pond Area
sam_12 = Merlar's Sanctuary
sam_bt01 = Snowfield
sam_bt02 = Cavern
sam_bt03 = Mountain
sam_bt04 = Summit

% area_pra
pra_01 = Entrance
pra_02 = Entry Hall
pra_03 = Save Room
pra_04 = Reflected Save Room
pra_05 = Blue Key Room
pra_06 = Shooting Star Room
pra_09 = Red Key Hall
pra_10 = P-Down, D-Up Hall
pra_11 = Red Key Room
pra_12 = P-Down, D-Up Room
pra_13 = Blue Mirror Hall 1
pra_14 = Blue Mirror Hall 2
pra_15 = Star Piece Cave
pra_16 = Red Mirror Hall
pra_18 = Bridge Mirror Hall
pra_19 = Reflection Mimic Room
pra_20 = Mirrored Door Room
pra_21 = Huge Statue Room
pra_22 = Small Statue Room
pra_27 = Palace Key Room
pra_28 = P-Up, D-Down Room
pra_29 = Hidden Bridge Room
pra_31 = Dino Puzzle Room
pra_32 = Crystal Summit
pra_33 = Turnstyle Room
pra_34 = Mirror Hole Room
pra_35 = Triple Dip Room
pra_36 = Palace Key Hall
pra_37 = P-Up, D-Down Hall
pra_38 = Blue Key Hall
pra_39 = Shooting Star Hall
pra_40 = Boss Antechamber
pra_bt01 = Hallway
pra_bt02 = Mirror
pra_bt03 = Statues
pra_bt04 = Doors

% area_kpa
kpa_01 = Dark Cave 1
kpa_03 = Dark Cave 2
kpa_04 = Cave Exit
kpa_08 = Castle Key Timing Puzzle
kpa_09 = Ultra Shroom Timing Puzzle
kpa_10 = Outside Lower Jail (No Lava)
kpa_11 = Outisde Lower Jail (Lava)
kpa_12 = Lava Channel 1
kpa_13 = Lava Channel 2
kpa_14 = Lava Channel 3
kpa_15 = Lava Key Room
kpa_16 = Lava Control Room
kpa_17 = Lower Jail
kpa_32 = Lower Grand Hall
kpa_33 = Upper Grand Hall
kpa_40 = Maze Guide Room
kpa_41 = Maze Room
kpa_50 = Hall to Guard Door 1
kpa_51 = Hall to Water Puzzle
kpa_52 = Split Level Hall
kpa_53 = Fake Peach Hallway
kpa_60 = Ship Enter/Exit Scenes
kpa_61 = Battlement
kpa_62 = Front Door Exterior
kpa_63 = Hanger
kpa_70 = Entry Lava Hall
kpa_81 = Guard Door 1
kpa_82 = Guard Door 2
kpa_83 = Guard Door 3
kpa_90 = Stairs to East Upper Jail
kpa_91 = East Upper Jail
kpa_94 = Stairs to West Upper Jail
kpa_95 = West Upper Jail
kpa_96 = Item Shop
kpa_100 = Castle Key Room
kpa_101 = Ultra Shroom Room
kpa_102 = Blue Fire Bridge
kpa_111 = Room with Hidden Door 1
kpa_112 = Hidden Passage 1
kpa_113 = Room with Hidden Door 2
kpa_114 = Hidden Passage 2
kpa_115 = Room with Hidden Door 3
kpa_116 = Dead End Passage
kpa_117 = Dead End Room
kpa_118 = Hidden Passage 3
kpa_119 = Hidden Key Room
kpa_121 = Exit to Peach's Castle
kpa_130 = Bill Blaster Hall
kpa_133 = Left Water Puzzle
kpa_134 = Right Water Puzzle
kpa_80 = Guard Door Geometry % other guard door maps load this
kpa_bt01 = Timing Puzzle Rooms
kpa_bt02 = Lava Hall
kpa_bt03 = Cave
kpa_bt04 = Maze
kpa_bt05 = Drained Water Puzzle
kpa_bt07 = Battlement
kpa_bt08 = Spiral
kpa_bt09 = Bridge Hall
kpa_bt11 = Hidden Passage
kpa_bt13 = Hidden Door Room
kpa_bt14 = Jail Cell

% area_osr
osr_00 = Intro Castle Grounds
osr_01 = Ruined Castle Grounds
osr_02 = Hijacked Castle Entrance
osr_03 = Outside Hijacked Castle
osr_04 = Castle Hijacking Scene

% area_end
end_00 = Parade (Day)
end_01 = Parade (Night)

% area_mgm
mgm_00 = Playroom Lobby
mgm_01 = Jump Attack Minigame
mgm_02 = Smash Attack Minigame
mgm_03 = Large Debug Room

% area_gv
gv_01 = Game Over Screen

% area_tst
tst_01 = Jump Width Test
tst_02 = Jump Height Test
tst_03 = Entity Test
tst_04 = Moving Platforms Test
tst_10 = Entry and Camera Test
tst_11 = Reflection Test
tst_12 = Flower Fields Test
tst_13 = Partners and Shockwave
tst_20 = Pipes Gallery

% resources
mac_tex = Toad Town Textures
tik_tex = Tunnels Textures
kgr_tex = Whale Textures
kmr_tex = Goomba Region Textures
iwa_tex = Mt Rugged Textures
sbk_tex = Desert Textures
dro_tex = Outpost Textures
isk_tex = Ruins Textures
trd_tex = Fortress Textures
nok_tex = Koopa Region Textures
hos_tex = Shooting Star Textures
kpa_tex = Bowser's Castle Textures
osr_tex = Castle Grounds Textures
kkj_tex = Peach's Castle Textures
tst_tex = Testing Textures
jan_tex = Jungle Textures
mim_tex = Forever Forest Textures
obk_tex = Boo's Mansion Textures
arn_tex = Gusty Gulch Textures
dgb_tex = Tubba's Manot Textures
kzn_tex = Volcano Textures
flo_tex = Flower Fields Textures
sam_tex = Shiver Region Textures
pra_tex = Crystal Palace Textures
omo_tex = Toybox Textures
end_tex = Parade Textures
mgm_tex = Minigame Textures
gv__tex = Game Over Textures
kmr_bg = Verdant Hills
nok_bg = Dodecahedra Hills
sbk_bg = Desert
sbk3_bg = Brighter Desert
iwa_bg = Desert Mesas
hos_bg = Dark Starry Sky
arn_bg = Yellow Cloudy Sky
obk_bg = Very Dark Clouds
omo_bg = Toybox Spotlights
yos_bg = Jungle and Sky
jan_bg = Deep Jungle
fla_bg = Cloudy Flower Fields
flb_bg = Sunny Flower Fields
sra_bg = Fluffy Clouds
yki_bg = Snowy Mountains
sam_bg = Northern Lights
kpa_bg = Starry Sky Above Red Clouds
title_bg = Title Screen Background
title_data = Game Title Textures
party_kurio = Unlock Goombario Portrait
party_kameki = Unlock Kooper Portrait
party_pinki = Unlock Bombette Portrait
party_pareta = Unlock Parakarry Portrait
party_resa = Unlock Bow Portrait
party_akari = Unlock Watt Portrait
party_opuku = Unlock Sushie Portrait
party_pokopi = Unlock Lakilester Portrait
""".splitlines()]

from glob import glob

headers = glob("src/world/*/*/*.h")

for header in headers:
    map_name = header.split("/")[-1].split(".")[0]
    area_name = map_name.split("_")[0]

    desc = ""
    for a in maps:
        if len(a) != 2:
            continue
        k,v = a
        if k == map_name:
            desc = v
            break

    area_desc = ""
    for a in maps:
        if len(a) != 2:
            continue
        k,v = a
        if k == area_name:
            area_desc = v
            break

    with open(header, "r") as f:
        dog = f.read()
    with open(header, "w") as f:
        f.write(f"/// @file {map_name}.h\n")
        f.write(f"/// @brief {area_desc} - {desc}\n")
        f.write(f"\n")
        f.write(dog)
