.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_engine_data
/* 21DC 80026DDC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 21E0 80026DE0 3C040010 */  lui       $a0, 0x10
/* 21E4 80026DE4 2484EE30 */  addiu     $a0, $a0, -0x11d0
/* 21E8 80026DE8 3C050010 */  lui       $a1, 0x10
/* 21EC 80026DEC 24A52610 */  addiu     $a1, $a1, 0x2610
/* 21F0 80026DF0 3C06802E */  lui       $a2, %hi(D_802DBD40)
/* 21F4 80026DF4 24C6BD40 */  addiu     $a2, $a2, %lo(D_802DBD40)
/* 21F8 80026DF8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 21FC 80026DFC 0C00A5CF */  jal       dma_copy
/* 2200 80026E00 AFB00010 */   sw       $s0, 0x10($sp)
/* 2204 80026E04 3C040007 */  lui       $a0, 7
/* 2208 80026E08 248459B0 */  addiu     $a0, $a0, 0x59b0
/* 220C 80026E0C 3C05000A */  lui       $a1, 0xa
/* 2210 80026E10 24A55DD0 */  addiu     $a1, $a1, 0x5dd0
/* 2214 80026E14 3C06800E */  lui       $a2, %hi(D_800DC500)
/* 2218 80026E18 24C6C500 */  addiu     $a2, $a2, %lo(D_800DC500)
/* 221C 80026E1C 0C00A5CF */  jal       dma_copy
/* 2220 80026E20 00000000 */   nop
/* 2224 80026E24 3C04000E */  lui       $a0, 0xe
/* 2228 80026E28 248479B0 */  addiu     $a0, $a0, 0x79b0
/* 222C 80026E2C 3C050010 */  lui       $a1, 0x10
/* 2230 80026E30 24A5EE30 */  addiu     $a1, $a1, -0x11d0
/* 2234 80026E34 3C06802C */  lui       $a2, %hi(sort_scripts)
/* 2238 80026E38 24C63000 */  addiu     $a2, $a2, %lo(sort_scripts)
/* 223C 80026E3C 0C00A5CF */  jal       dma_copy
/* 2240 80026E40 00000000 */   nop
/* 2244 80026E44 3C040010 */  lui       $a0, 0x10
/* 2248 80026E48 24842610 */  addiu     $a0, $a0, 0x2610
/* 224C 80026E4C 3C050011 */  lui       $a1, 0x11
/* 2250 80026E50 24A5CC10 */  addiu     $a1, $a1, -0x33f0
/* 2254 80026E54 3C06802E */  lui       $a2, %hi(create_shadow_callback)
/* 2258 80026E58 24C60D90 */  addiu     $a2, $a2, %lo(create_shadow_callback)
/* 225C 80026E5C 0C00A5CF */  jal       dma_copy
/* 2260 80026E60 00000000 */   nop
/* 2264 80026E64 3C04000A */  lui       $a0, 0xa
/* 2268 80026E68 24845DD0 */  addiu     $a0, $a0, 0x5dd0
/* 226C 80026E6C 3C05000E */  lui       $a1, 0xe
/* 2270 80026E70 24A579B0 */  addiu     $a1, $a1, 0x79b0
/* 2274 80026E74 3C068011 */  lui       $a2, %hi(update_entities)
/* 2278 80026E78 24C6F6D0 */  addiu     $a2, $a2, %lo(update_entities)
/* 227C 80026E7C 0C00A5CF */  jal       dma_copy
/* 2280 80026E80 00000000 */   nop
/* 2284 80026E84 3C040011 */  lui       $a0, 0x11
/* 2288 80026E88 2484CC10 */  addiu     $a0, $a0, -0x33f0
/* 228C 80026E8C 3C050011 */  lui       $a1, 0x11
/* 2290 80026E90 24A5F1B0 */  addiu     $a1, $a1, -0xe50
/* 2294 80026E94 3C06802F */  lui       $a2, %hi(D_802EB3D0)
/* 2298 80026E98 24C6B3D0 */  addiu     $a2, $a2, %lo(D_802EB3D0)
/* 229C 80026E9C 0C00A5CF */  jal       dma_copy
/* 22A0 80026EA0 00000000 */   nop
/* 22A4 80026EA4 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 22A8 80026EA8 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 22AC 80026EAC 8E020000 */  lw        $v0, ($s0)
/* 22B0 80026EB0 3C01800A */  lui       $at, %hi(D_8009A650)
/* 22B4 80026EB4 AC20A650 */  sw        $zero, %lo(D_8009A650)($at)
/* 22B8 80026EB8 A0400079 */  sb        $zero, 0x79($v0)
/* 22BC 80026EBC 8E030000 */  lw        $v1, ($s0)
/* 22C0 80026EC0 24040001 */  addiu     $a0, $zero, 1
/* 22C4 80026EC4 A064007A */  sb        $a0, 0x7a($v1)
/* 22C8 80026EC8 8E020000 */  lw        $v0, ($s0)
/* 22CC 80026ECC A4600148 */  sh        $zero, 0x148($v1)
/* 22D0 80026ED0 A044007C */  sb        $a0, 0x7c($v0)
/* 22D4 80026ED4 8E030000 */  lw        $v1, ($s0)
/* 22D8 80026ED8 2402FFFF */  addiu     $v0, $zero, -1
/* 22DC 80026EDC A06200A8 */  sb        $v0, 0xa8($v1)
/* 22E0 80026EE0 8E020000 */  lw        $v0, ($s0)
/* 22E4 80026EE4 A04000AA */  sb        $zero, 0xaa($v0)
/* 22E8 80026EE8 8E020000 */  lw        $v0, ($s0)
/* 22EC 80026EEC A0400081 */  sb        $zero, 0x81($v0)
/* 22F0 80026EF0 8E030000 */  lw        $v1, ($s0)
/* 22F4 80026EF4 2402FFF8 */  addiu     $v0, $zero, -8
/* 22F8 80026EF8 A0620082 */  sb        $v0, 0x82($v1)
/* 22FC 80026EFC 8E030000 */  lw        $v1, ($s0)
/* 2300 80026F00 24020004 */  addiu     $v0, $zero, 4
/* 2304 80026F04 A0620083 */  sb        $v0, 0x83($v1)
/* 2308 80026F08 8E020000 */  lw        $v0, ($s0)
/* 230C 80026F0C 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 2310 80026F10 AC20A5D8 */  sw        $zero, %lo(D_8009A5D8)($at)
/* 2314 80026F14 A440013C */  sh        $zero, 0x13c($v0)
/* 2318 80026F18 A0400075 */  sb        $zero, 0x75($v0)
/* 231C 80026F1C 8E030000 */  lw        $v1, ($s0)
/* 2320 80026F20 24020005 */  addiu     $v0, $zero, 5
/* 2324 80026F24 3C018007 */  lui       $at, %hi(D_80074021)
/* 2328 80026F28 A0224021 */  sb        $v0, %lo(D_80074021)($at)
/* 232C 80026F2C 0C00AE13 */  jal       fio_init_flash
/* 2330 80026F30 AC600168 */   sw       $zero, 0x168($v1)
/* 2334 80026F34 0C00A20E */  jal       func_80028838
/* 2338 80026F38 00000000 */   nop
/* 233C 80026F3C 0C00AB00 */  jal       general_heap_create
/* 2340 80026F40 00000000 */   nop
/* 2344 80026F44 0C047624 */  jal       func_8011D890
/* 2348 80026F48 00000000 */   nop
/* 234C 80026F4C 0C048C2E */  jal       clear_dynamic_entity_list
/* 2350 80026F50 00000000 */   nop
/* 2354 80026F54 0C0B0C77 */  jal       clear_script_list
/* 2358 80026F58 00000000 */   nop
/* 235C 80026F5C 0C00B7BD */  jal       create_cameras_a
/* 2360 80026F60 00000000 */   nop
/* 2364 80026F64 0C037F14 */  jal       clear_player_status
/* 2368 80026F68 00000000 */   nop
/* 236C 80026F6C 0C0B763E */  jal       func_802DD8F8
/* 2370 80026F70 0000202D */   daddu    $a0, $zero, $zero
/* 2374 80026F74 0C0482EC */  jal       clear_entity_models
/* 2378 80026F78 00000000 */   nop
/* 237C 80026F7C 0C047889 */  jal       func_8011E224
/* 2380 80026F80 00000000 */   nop
/* 2384 80026F84 0C045751 */  jal       clear_model_data
/* 2388 80026F88 00000000 */   nop
/* 238C 80026F8C 0C052010 */  jal       func_80148040
/* 2390 80026F90 00000000 */   nop
/* 2394 80026F94 0C05177E */  jal       use_default_background_settings
/* 2398 80026F98 00000000 */   nop
/* 239C 80026F9C 0C048D98 */  jal       clear_character_set
/* 23A0 80026FA0 00000000 */   nop
/* 23A4 80026FA4 0C048D9D */  jal       clear_printers
/* 23A8 80026FA8 00000000 */   nop
/* 23AC 80026FAC 0C044AE6 */  jal       func_80112B98
/* 23B0 80026FB0 00000000 */   nop
/* 23B4 80026FB4 0C00E12F */  jal       clear_npcs
/* 23B8 80026FB8 00000000 */   nop
/* 23BC 80026FBC 0C050440 */  jal       func_80141100
/* 23C0 80026FC0 00000000 */   nop
/* 23C4 80026FC4 0C0515A0 */  jal       clear_trigger_data
/* 23C8 80026FC8 00000000 */   nop
/* 23CC 80026FCC 0C04432E */  jal       clear_entity_data
/* 23D0 80026FD0 0000202D */   daddu    $a0, $zero, $zero
/* 23D4 80026FD4 0C039CE8 */  jal       clear_player_data
/* 23D8 80026FD8 00000000 */   nop
/* 23DC 80026FDC 0C00F8CE */  jal       func_8003E338
/* 23E0 80026FE0 00000000 */   nop
/* 23E4 80026FE4 0C04E042 */  jal       clear_transition_stencil
/* 23E8 80026FE8 00000000 */   nop
/* 23EC 80026FEC 0C016727 */  jal       clear_effect_data
/* 23F0 80026FF0 00000000 */   nop
/* 23F4 80026FF4 0C0514C8 */  jal       clear_saved_variables
/* 23F8 80026FF8 00000000 */   nop
/* 23FC 80026FFC 0C04C3FC */  jal       clear_item_entity_data
/* 2400 80027000 00000000 */   nop
/* 2404 80027004 0C052926 */  jal       func_8014A498
/* 2408 80027008 00000000 */   nop
/* 240C 8002700C 0C051C8C */  jal       reset_ambient_sounds
/* 2410 80027010 00000000 */   nop
/* 2414 80027014 0C052586 */  jal       func_80149618
/* 2418 80027018 00000000 */   nop
/* 241C 8002701C 0C051CFC */  jal       clear_windows
/* 2420 80027020 00000000 */   nop
/* 2424 80027024 0C00AE90 */  jal       initialize_curtains
/* 2428 80027028 00000000 */   nop
/* 242C 8002702C 0C00A3B8 */  jal       poll_rumble
/* 2430 80027030 00000000 */   nop
/* 2434 80027034 0000182D */  daddu     $v1, $zero, $zero
/* 2438 80027038 24050003 */  addiu     $a1, $zero, 3
/* 243C 8002703C 2404000C */  addiu     $a0, $zero, 0xc
/* 2440 80027040 8E100000 */  lw        $s0, ($s0)
.L80027044:
/* 2444 80027044 A6050050 */  sh        $a1, 0x50($s0)
/* 2448 80027048 A6040048 */  sh        $a0, 0x48($s0)
/* 244C 8002704C 24630001 */  addiu     $v1, $v1, 1
/* 2450 80027050 28620004 */  slti      $v0, $v1, 4
/* 2454 80027054 1440FFFB */  bnez      $v0, .L80027044
/* 2458 80027058 26100002 */   addiu    $s0, $s0, 2
/* 245C 8002705C 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 2460 80027060 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 2464 80027064 8C620000 */  lw        $v0, ($v1)
/* 2468 80027068 0000202D */  daddu     $a0, $zero, $zero
/* 246C 8002706C 34420008 */  ori       $v0, $v0, 8
/* 2470 80027070 0C00CD3C */  jal       set_game_mode
/* 2474 80027074 AC620000 */   sw       $v0, ($v1)
/* 2478 80027078 8FBF0014 */  lw        $ra, 0x14($sp)
/* 247C 8002707C 8FB00010 */  lw        $s0, 0x10($sp)
/* 2480 80027080 03E00008 */  jr        $ra
/* 2484 80027084 27BD0018 */   addiu    $sp, $sp, 0x18
