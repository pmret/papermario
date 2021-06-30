.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_demo_battle
/* 4E214 80072E14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4E218 80072E18 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 4E21C 80072E1C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 4E220 80072E20 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4E224 80072E24 AFB10014 */  sw        $s1, 0x14($sp)
/* 4E228 80072E28 AFB00010 */  sw        $s0, 0x10($sp)
/* 4E22C 80072E2C 8C620000 */  lw        $v0, ($v1)
/* 4E230 80072E30 A04000AA */  sb        $zero, 0xaa($v0)
/* 4E234 80072E34 8C620000 */  lw        $v0, ($v1)
/* 4E238 80072E38 0080882D */  daddu     $s1, $a0, $zero
/* 4E23C 80072E3C A4400086 */  sh        $zero, 0x86($v0)
/* 4E240 80072E40 A440008C */  sh        $zero, 0x8c($v0)
/* 4E244 80072E44 0C00AB00 */  jal       general_heap_create
/* 4E248 80072E48 A0400070 */   sb       $zero, 0x70($v0)
/* 4E24C 80072E4C 0C048C2E */  jal       clear_generic_entity_list
/* 4E250 80072E50 00000000 */   nop
/* 4E254 80072E54 0C0B0C77 */  jal       clear_script_list
/* 4E258 80072E58 00000000 */   nop
/* 4E25C 80072E5C 0C00B7BD */  jal       create_cameras_a
/* 4E260 80072E60 00000000 */   nop
/* 4E264 80072E64 0C0B763E */  jal       spr_init_sprites
/* 4E268 80072E68 0000202D */   daddu    $a0, $zero, $zero
/* 4E26C 80072E6C 0C047889 */  jal       clear_animator_list
/* 4E270 80072E70 00000000 */   nop
/* 4E274 80072E74 0C0482EC */  jal       clear_entity_models
/* 4E278 80072E78 00000000 */   nop
/* 4E27C 80072E7C 0C00E12F */  jal       clear_npcs
/* 4E280 80072E80 00000000 */   nop
/* 4E284 80072E84 0C050440 */  jal       clear_hud_element_cache
/* 4E288 80072E88 00000000 */   nop
/* 4E28C 80072E8C 0C0515A0 */  jal       clear_trigger_data
/* 4E290 80072E90 00000000 */   nop
/* 4E294 80072E94 0C045751 */  jal       clear_model_data
/* 4E298 80072E98 00000000 */   nop
/* 4E29C 80072E9C 0C052010 */  jal       clear_sprite_shading_data
/* 4E2A0 80072EA0 00000000 */   nop
/* 4E2A4 80072EA4 0C05177E */  jal       reset_background_settings
/* 4E2A8 80072EA8 00000000 */   nop
/* 4E2AC 80072EAC 0C04E062 */  jal       func_80138188
/* 4E2B0 80072EB0 00000000 */   nop
/* 4E2B4 80072EB4 0C01CACC */  jal       reset_battle_status
/* 4E2B8 80072EB8 00000000 */   nop
/* 4E2BC 80072EBC 0C00F900 */  jal       clear_encounter_status
/* 4E2C0 80072EC0 00000000 */   nop
/* 4E2C4 80072EC4 0C04432E */  jal       clear_entity_data
/* 4E2C8 80072EC8 24040001 */   addiu    $a0, $zero, 1
/* 4E2CC 80072ECC 0C016727 */  jal       clear_effect_data
/* 4E2D0 80072ED0 00000000 */   nop
/* 4E2D4 80072ED4 0C037F14 */  jal       clear_player_status
/* 4E2D8 80072ED8 00000000 */   nop
/* 4E2DC 80072EDC 0C048D9D */  jal       clear_printers
/* 4E2E0 80072EE0 00000000 */   nop
/* 4E2E4 80072EE4 0C04C3FC */  jal       clear_item_entity_data
/* 4E2E8 80072EE8 00000000 */   nop
/* 4E2EC 80072EEC 0C039CE8 */  jal       clear_player_data
/* 4E2F0 80072EF0 00000000 */   nop
/* 4E2F4 80072EF4 0C039E4D */  jal       initialize_status_menu
/* 4E2F8 80072EF8 00000000 */   nop
/* 4E2FC 80072EFC 0C04C3FC */  jal       clear_item_entity_data
/* 4E300 80072F00 00000000 */   nop
/* 4E304 80072F04 3C05437F */  lui       $a1, 0x437f
/* 4E308 80072F08 0C04DF62 */  jal       set_screen_overlay_params_front
/* 4E30C 80072F0C 24040009 */   addiu    $a0, $zero, 9
/* 4E310 80072F10 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 4E314 80072F14 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 4E318 80072F18 2E220005 */  sltiu     $v0, $s1, 5
/* 4E31C 80072F1C 1040002D */  beqz      $v0, .L80072FD4
/* 4E320 80072F20 00111080 */   sll      $v0, $s1, 2
/* 4E324 80072F24 3C01800A */  lui       $at, %hi(jtbl_8009A578)
/* 4E328 80072F28 00220821 */  addu      $at, $at, $v0
/* 4E32C 80072F2C 8C22A578 */  lw        $v0, %lo(jtbl_8009A578)($at)
/* 4E330 80072F30 00400008 */  jr        $v0
/* 4E334 80072F34 00000000 */   nop
glabel L80072F38_4E338
/* 4E338 80072F38 0C01CB4B */  jal       setup_demo_player
/* 4E33C 80072F3C 24112700 */   addiu    $s1, $zero, 0x2700
/* 4E340 80072F40 0000202D */  daddu     $a0, $zero, $zero
/* 4E344 80072F44 0801CBF8 */  j         .L80072FE0
/* 4E348 80072F48 A200000A */   sb       $zero, 0xa($s0)
glabel L80072F4C_4E34C
/* 4E34C 80072F4C 0C01CB4B */  jal       setup_demo_player
/* 4E350 80072F50 24112701 */   addiu    $s1, $zero, 0x2701
/* 4E354 80072F54 0000202D */  daddu     $a0, $zero, $zero
/* 4E358 80072F58 24020009 */  addiu     $v0, $zero, 9
/* 4E35C 80072F5C 0801CBF8 */  j         .L80072FE0
/* 4E360 80072F60 A2020012 */   sb       $v0, 0x12($s0)
glabel L80072F64_4E364
/* 4E364 80072F64 0C01CB4B */  jal       setup_demo_player
/* 4E368 80072F68 24112702 */   addiu    $s1, $zero, 0x2702
/* 4E36C 80072F6C 0000202D */  daddu     $a0, $zero, $zero
/* 4E370 80072F70 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 4E374 80072F74 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 4E378 80072F78 24020004 */  addiu     $v0, $zero, 4
/* 4E37C 80072F7C A2020012 */  sb        $v0, 0x12($s0)
/* 4E380 80072F80 906200AA */  lbu       $v0, 0xaa($v1)
/* 4E384 80072F84 34420002 */  ori       $v0, $v0, 2
/* 4E388 80072F88 0801CBF8 */  j         .L80072FE0
/* 4E38C 80072F8C A06200AA */   sb       $v0, 0xaa($v1)
glabel L80072F90_4E390
/* 4E390 80072F90 0C01CB4B */  jal       setup_demo_player
/* 4E394 80072F94 24112703 */   addiu    $s1, $zero, 0x2703
/* 4E398 80072F98 0000202D */  daddu     $a0, $zero, $zero
/* 4E39C 80072F9C 24020006 */  addiu     $v0, $zero, 6
/* 4E3A0 80072FA0 0801CBF8 */  j         .L80072FE0
/* 4E3A4 80072FA4 A2020012 */   sb       $v0, 0x12($s0)
glabel L80072FA8_4E3A8
/* 4E3A8 80072FA8 0C01CB4B */  jal       setup_demo_player
/* 4E3AC 80072FAC 24112704 */   addiu    $s1, $zero, 0x2704
/* 4E3B0 80072FB0 0000202D */  daddu     $a0, $zero, $zero
/* 4E3B4 80072FB4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 4E3B8 80072FB8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 4E3BC 80072FBC 24020002 */  addiu     $v0, $zero, 2
/* 4E3C0 80072FC0 A2020012 */  sb        $v0, 0x12($s0)
/* 4E3C4 80072FC4 906200AA */  lbu       $v0, 0xaa($v1)
/* 4E3C8 80072FC8 34420004 */  ori       $v0, $v0, 4
/* 4E3CC 80072FCC 0801CBF8 */  j         .L80072FE0
/* 4E3D0 80072FD0 A06200AA */   sb       $v0, 0xaa($v1)
.L80072FD4:
/* 4E3D4 80072FD4 0C01CB4B */  jal       setup_demo_player
/* 4E3D8 80072FD8 24112700 */   addiu    $s1, $zero, 0x2700
/* 4E3DC 80072FDC 24040002 */  addiu     $a0, $zero, 2
.L80072FE0:
/* 4E3E0 80072FE0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 4E3E4 80072FE4 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 4E3E8 80072FE8 8C620000 */  lw        $v0, ($v1)
/* 4E3EC 80072FEC A0400074 */  sb        $zero, 0x74($v0)
/* 4E3F0 80072FF0 8C630000 */  lw        $v1, ($v1)
/* 4E3F4 80072FF4 24020001 */  addiu     $v0, $zero, 1
/* 4E3F8 80072FF8 A062007C */  sb        $v0, 0x7c($v1)
/* 4E3FC 80072FFC 2C820005 */  sltiu     $v0, $a0, 5
/* 4E400 80073000 10400049 */  beqz      $v0, .L80073128
/* 4E404 80073004 00041080 */   sll      $v0, $a0, 2
/* 4E408 80073008 3C01800A */  lui       $at, %hi(jtbl_8009A590)
/* 4E40C 8007300C 00220821 */  addu      $at, $at, $v0
/* 4E410 80073010 8C22A590 */  lw        $v0, %lo(jtbl_8009A590)($at)
/* 4E414 80073014 00400008 */  jr        $v0
/* 4E418 80073018 00000000 */   nop
glabel L8007301C_4E41C
/* 4E41C 8007301C 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 4E420 80073020 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 4E424 80073024 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 4E428 80073028 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 4E42C 8007302C A0600004 */  sb        $zero, 4($v1)
/* 4E430 80073030 8C850000 */  lw        $a1, ($a0)
/* 4E434 80073034 24020001 */  addiu     $v0, $zero, 1
/* 4E438 80073038 A0620005 */  sb        $v0, 5($v1)
/* 4E43C 8007303C A0600006 */  sb        $zero, 6($v1)
/* 4E440 80073040 90A200AA */  lbu       $v0, 0xaa($a1)
/* 4E444 80073044 34420010 */  ori       $v0, $v0, 0x10
/* 4E448 80073048 A0A200AA */  sb        $v0, 0xaa($a1)
/* 4E44C 8007304C 8C830000 */  lw        $v1, ($a0)
/* 4E450 80073050 906200AA */  lbu       $v0, 0xaa($v1)
/* 4E454 80073054 34420020 */  ori       $v0, $v0, 0x20
/* 4E458 80073058 A06200AA */  sb        $v0, 0xaa($v1)
/* 4E45C 8007305C 8C830000 */  lw        $v1, ($a0)
/* 4E460 80073060 906200AA */  lbu       $v0, 0xaa($v1)
/* 4E464 80073064 34420040 */  ori       $v0, $v0, 0x40
/* 4E468 80073068 0801CC4A */  j         .L80073128
/* 4E46C 8007306C A06200AA */   sb       $v0, 0xaa($v1)
glabel L80073070_4E470
/* 4E470 80073070 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 4E474 80073074 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 4E478 80073078 24020001 */  addiu     $v0, $zero, 1
/* 4E47C 8007307C A0620004 */  sb        $v0, 4($v1)
/* 4E480 80073080 92040001 */  lbu       $a0, 1($s0)
/* 4E484 80073084 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* 4E488 80073088 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* 4E48C 8007308C 0801CC2D */  j         .L800730B4
/* 4E490 80073090 24020004 */   addiu    $v0, $zero, 4
glabel L80073094_4E494
/* 4E494 80073094 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 4E498 80073098 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 4E49C 8007309C 24020001 */  addiu     $v0, $zero, 1
/* 4E4A0 800730A0 A0620004 */  sb        $v0, 4($v1)
/* 4E4A4 800730A4 92040000 */  lbu       $a0, ($s0)
/* 4E4A8 800730A8 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* 4E4AC 800730AC 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* 4E4B0 800730B0 24020002 */  addiu     $v0, $zero, 2
.L800730B4:
/* 4E4B4 800730B4 A0620005 */  sb        $v0, 5($v1)
/* 4E4B8 800730B8 A0640006 */  sb        $a0, 6($v1)
/* 4E4BC 800730BC 90A200AA */  lbu       $v0, 0xaa($a1)
/* 4E4C0 800730C0 34420010 */  ori       $v0, $v0, 0x10
/* 4E4C4 800730C4 0801CC4A */  j         .L80073128
/* 4E4C8 800730C8 A0A200AA */   sb       $v0, 0xaa($a1)
glabel L800730CC_4E4CC
/* 4E4CC 800730CC 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 4E4D0 800730D0 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 4E4D4 800730D4 24020001 */  addiu     $v0, $zero, 1
/* 4E4D8 800730D8 A0620004 */  sb        $v0, 4($v1)
/* 4E4DC 800730DC 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 4E4E0 800730E0 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 4E4E4 800730E4 24020006 */  addiu     $v0, $zero, 6
/* 4E4E8 800730E8 A0620005 */  sb        $v0, 5($v1)
/* 4E4EC 800730EC 908200AA */  lbu       $v0, 0xaa($a0)
/* 4E4F0 800730F0 0801CC49 */  j         .L80073124
/* 4E4F4 800730F4 34420020 */   ori      $v0, $v0, 0x20
glabel L800730F8_4E4F8
/* 4E4F8 800730F8 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 4E4FC 800730FC 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 4E500 80073100 24020002 */  addiu     $v0, $zero, 2
/* 4E504 80073104 A0620004 */  sb        $v0, 4($v1)
/* 4E508 80073108 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 4E50C 8007310C 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 4E510 80073110 24020001 */  addiu     $v0, $zero, 1
/* 4E514 80073114 A0620005 */  sb        $v0, 5($v1)
/* 4E518 80073118 A0600006 */  sb        $zero, 6($v1)
/* 4E51C 8007311C 908200AA */  lbu       $v0, 0xaa($a0)
/* 4E520 80073120 34420040 */  ori       $v0, $v0, 0x40
.L80073124:
/* 4E524 80073124 A08200AA */  sb        $v0, 0xaa($a0)
.L80073128:
/* 4E528 80073128 0000202D */  daddu     $a0, $zero, $zero
/* 4E52C 8007312C 3C05F840 */  lui       $a1, 0xf840
/* 4E530 80073130 34A56299 */  ori       $a1, $a1, 0x6299
/* 4E534 80073134 0C0B2026 */  jal       set_variable
/* 4E538 80073138 24060001 */   addiu    $a2, $zero, 1
/* 4E53C 8007313C 2404FFFF */  addiu     $a0, $zero, -1
/* 4E540 80073140 3C02800B */  lui       $v0, %hi(gCurrentEncounter)
/* 4E544 80073144 24420F10 */  addiu     $v0, $v0, %lo(gCurrentEncounter)
/* 4E548 80073148 A0400007 */  sb        $zero, 7($v0)
/* 4E54C 8007314C 0C01CB33 */  jal       set_battle_stage
/* 4E550 80073150 A0400010 */   sb       $zero, 0x10($v0)
/* 4E554 80073154 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 4E558 80073158 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 4E55C 8007315C 0220202D */  daddu     $a0, $s1, $zero
/* 4E560 80073160 906200AA */  lbu       $v0, 0xaa($v1)
/* 4E564 80073164 3C05800A */  lui       $a1, %hi(gOverrideFlags)
/* 4E568 80073168 24A5A650 */  addiu     $a1, $a1, %lo(gOverrideFlags)
/* 4E56C 8007316C 34420001 */  ori       $v0, $v0, 1
/* 4E570 80073170 A06200AA */  sb        $v0, 0xaa($v1)
/* 4E574 80073174 8CA20000 */  lw        $v0, ($a1)
/* 4E578 80073178 2403FFF7 */  addiu     $v1, $zero, -9
/* 4E57C 8007317C 00431024 */  and       $v0, $v0, $v1
/* 4E580 80073180 0C01CB24 */  jal       load_battle
/* 4E584 80073184 ACA20000 */   sw       $v0, ($a1)
/* 4E588 80073188 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E58C 8007318C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4E590 80073190 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E594 80073194 03E00008 */  jr        $ra
/* 4E598 80073198 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4E59C 8007319C 00000000 */  nop
