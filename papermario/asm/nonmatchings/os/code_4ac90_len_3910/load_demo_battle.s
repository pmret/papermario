.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel load_demo_battle
/* 04E214 80072E14 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04E218 80072E18 3C038007 */  lui   $v1, 0x8007
/* 04E21C 80072E1C 2463419C */  addiu $v1, $v1, 0x419c
/* 04E220 80072E20 AFBF0018 */  sw    $ra, 0x18($sp)
/* 04E224 80072E24 AFB10014 */  sw    $s1, 0x14($sp)
/* 04E228 80072E28 AFB00010 */  sw    $s0, 0x10($sp)
/* 04E22C 80072E2C 8C620000 */  lw    $v0, ($v1)
/* 04E230 80072E30 A04000AA */  sb    $zero, 0xaa($v0)
/* 04E234 80072E34 8C620000 */  lw    $v0, ($v1)
/* 04E238 80072E38 0080882D */  daddu $s1, $a0, $zero
/* 04E23C 80072E3C A4400086 */  sh    $zero, 0x86($v0)
/* 04E240 80072E40 A440008C */  sh    $zero, 0x8c($v0)
/* 04E244 80072E44 0C00AB00 */  jal   general_heap_create
/* 04E248 80072E48 A0400070 */   sb    $zero, 0x70($v0)
/* 04E24C 80072E4C 0C048C2E */  jal   func_801230B8
/* 04E250 80072E50 00000000 */   nop   
/* 04E254 80072E54 0C0B0C77 */  jal   clear_script_list
/* 04E258 80072E58 00000000 */   nop   
/* 04E25C 80072E5C 0C00B7BD */  jal   create_cameras_a
/* 04E260 80072E60 00000000 */   nop   
/* 04E264 80072E64 0C0B763E */  jal   func_802DD8F8
/* 04E268 80072E68 0000202D */   daddu $a0, $zero, $zero
/* 04E26C 80072E6C 0C047889 */  jal   func_8011E224
/* 04E270 80072E70 00000000 */   nop   
/* 04E274 80072E74 0C0482EC */  jal   func_80120BB0
/* 04E278 80072E78 00000000 */   nop   
/* 04E27C 80072E7C 0C00E12F */  jal   func_800384BC
/* 04E280 80072E80 00000000 */   nop   
/* 04E284 80072E84 0C050440 */  jal   func_80141100
/* 04E288 80072E88 00000000 */   nop   
/* 04E28C 80072E8C 0C0515A0 */  jal   clear_trigger_data
/* 04E290 80072E90 00000000 */   nop   
/* 04E294 80072E94 0C045751 */  jal   clear_model_data
/* 04E298 80072E98 00000000 */   nop   
/* 04E29C 80072E9C 0C052010 */  jal   func_80148040
/* 04E2A0 80072EA0 00000000 */   nop   
/* 04E2A4 80072EA4 0C05177E */  jal   func_80145DF8
/* 04E2A8 80072EA8 00000000 */   nop   
/* 04E2AC 80072EAC 0C04E062 */  jal   func_80138188
/* 04E2B0 80072EB0 00000000 */   nop   
/* 04E2B4 80072EB4 0C01CACC */  jal   func_80072B30
/* 04E2B8 80072EB8 00000000 */   nop   
/* 04E2BC 80072EBC 0C00F900 */  jal   clear_encounter_status
/* 04E2C0 80072EC0 00000000 */   nop   
/* 04E2C4 80072EC4 0C04432E */  jal   func_80110CB8
/* 04E2C8 80072EC8 24040001 */   addiu $a0, $zero, 1
/* 04E2CC 80072ECC 0C016727 */  jal   func_80059C9C
/* 04E2D0 80072ED0 00000000 */   nop   
/* 04E2D4 80072ED4 0C037F14 */  jal   clear_player_status
/* 04E2D8 80072ED8 00000000 */   nop   
/* 04E2DC 80072EDC 0C048D9D */  jal   clear_printers
/* 04E2E0 80072EE0 00000000 */   nop   
/* 04E2E4 80072EE4 0C04C3FC */  jal   clear_item_entity_data
/* 04E2E8 80072EE8 00000000 */   nop   
/* 04E2EC 80072EEC 0C039CE8 */  jal   clear_player_data
/* 04E2F0 80072EF0 00000000 */   nop   
/* 04E2F4 80072EF4 0C039E4D */  jal   initialize_status_menu
/* 04E2F8 80072EF8 00000000 */   nop   
/* 04E2FC 80072EFC 0C04C3FC */  jal   clear_item_entity_data
/* 04E300 80072F00 00000000 */   nop   
/* 04E304 80072F04 3C05437F */  lui   $a1, 0x437f
/* 04E308 80072F08 0C04DF62 */  jal   func_80137D88
/* 04E30C 80072F0C 24040009 */   addiu $a0, $zero, 9
/* 04E310 80072F10 3C108011 */  lui   $s0, 0x8011
/* 04E314 80072F14 2610F290 */  addiu $s0, $s0, -0xd70
/* 04E318 80072F18 2E220005 */  sltiu $v0, $s1, 5
/* 04E31C 80072F1C 1040002D */  beqz  $v0, .L80072FD4
/* 04E320 80072F20 00111080 */   sll   $v0, $s1, 2
/* 04E324 80072F24 3C01800A */  lui   $at, 0x800a
/* 04E328 80072F28 00220821 */  addu  $at, $at, $v0
/* 04E32C 80072F2C 8C22A578 */  lw    $v0, -0x5a88($at)
/* 04E330 80072F30 00400008 */  jr    $v0
/* 04E334 80072F34 00000000 */   nop   
/* 04E338 80072F38 0C01CB4B */  jal   setup_demo_player
/* 04E33C 80072F3C 24112700 */   addiu $s1, $zero, 0x2700
/* 04E340 80072F40 0000202D */  daddu $a0, $zero, $zero
/* 04E344 80072F44 0801CBF8 */  j     .L80072FE0
/* 04E348 80072F48 A200000A */   sb    $zero, 0xa($s0)

/* 04E34C 80072F4C 0C01CB4B */  jal   setup_demo_player
/* 04E350 80072F50 24112701 */   addiu $s1, $zero, 0x2701
/* 04E354 80072F54 0000202D */  daddu $a0, $zero, $zero
/* 04E358 80072F58 24020009 */  addiu $v0, $zero, 9
/* 04E35C 80072F5C 0801CBF8 */  j     .L80072FE0
/* 04E360 80072F60 A2020012 */   sb    $v0, 0x12($s0)

/* 04E364 80072F64 0C01CB4B */  jal   setup_demo_player
/* 04E368 80072F68 24112702 */   addiu $s1, $zero, 0x2702
/* 04E36C 80072F6C 0000202D */  daddu $a0, $zero, $zero
/* 04E370 80072F70 3C038007 */  lui   $v1, 0x8007
/* 04E374 80072F74 8C63419C */  lw    $v1, 0x419c($v1)
/* 04E378 80072F78 24020004 */  addiu $v0, $zero, 4
/* 04E37C 80072F7C A2020012 */  sb    $v0, 0x12($s0)
/* 04E380 80072F80 906200AA */  lbu   $v0, 0xaa($v1)
/* 04E384 80072F84 34420002 */  ori   $v0, $v0, 2
/* 04E388 80072F88 0801CBF8 */  j     .L80072FE0
/* 04E38C 80072F8C A06200AA */   sb    $v0, 0xaa($v1)

/* 04E390 80072F90 0C01CB4B */  jal   setup_demo_player
/* 04E394 80072F94 24112703 */   addiu $s1, $zero, 0x2703
/* 04E398 80072F98 0000202D */  daddu $a0, $zero, $zero
/* 04E39C 80072F9C 24020006 */  addiu $v0, $zero, 6
/* 04E3A0 80072FA0 0801CBF8 */  j     .L80072FE0
/* 04E3A4 80072FA4 A2020012 */   sb    $v0, 0x12($s0)

/* 04E3A8 80072FA8 0C01CB4B */  jal   setup_demo_player
/* 04E3AC 80072FAC 24112704 */   addiu $s1, $zero, 0x2704
/* 04E3B0 80072FB0 0000202D */  daddu $a0, $zero, $zero
/* 04E3B4 80072FB4 3C038007 */  lui   $v1, 0x8007
/* 04E3B8 80072FB8 8C63419C */  lw    $v1, 0x419c($v1)
/* 04E3BC 80072FBC 24020002 */  addiu $v0, $zero, 2
/* 04E3C0 80072FC0 A2020012 */  sb    $v0, 0x12($s0)
/* 04E3C4 80072FC4 906200AA */  lbu   $v0, 0xaa($v1)
/* 04E3C8 80072FC8 34420004 */  ori   $v0, $v0, 4
/* 04E3CC 80072FCC 0801CBF8 */  j     .L80072FE0
/* 04E3D0 80072FD0 A06200AA */   sb    $v0, 0xaa($v1)

.L80072FD4:
/* 04E3D4 80072FD4 0C01CB4B */  jal   setup_demo_player
/* 04E3D8 80072FD8 24112700 */   addiu $s1, $zero, 0x2700
/* 04E3DC 80072FDC 24040002 */  addiu $a0, $zero, 2
.L80072FE0:
/* 04E3E0 80072FE0 3C038007 */  lui   $v1, 0x8007
/* 04E3E4 80072FE4 2463419C */  addiu $v1, $v1, 0x419c
/* 04E3E8 80072FE8 8C620000 */  lw    $v0, ($v1)
/* 04E3EC 80072FEC A0400074 */  sb    $zero, 0x74($v0)
/* 04E3F0 80072FF0 8C630000 */  lw    $v1, ($v1)
/* 04E3F4 80072FF4 24020001 */  addiu $v0, $zero, 1
/* 04E3F8 80072FF8 A062007C */  sb    $v0, 0x7c($v1)
/* 04E3FC 80072FFC 2C820005 */  sltiu $v0, $a0, 5
/* 04E400 80073000 10400049 */  beqz  $v0, .L80073128
/* 04E404 80073004 00041080 */   sll   $v0, $a0, 2
/* 04E408 80073008 3C01800A */  lui   $at, 0x800a
/* 04E40C 8007300C 00220821 */  addu  $at, $at, $v0
/* 04E410 80073010 8C22A590 */  lw    $v0, -0x5a70($at)
/* 04E414 80073014 00400008 */  jr    $v0
/* 04E418 80073018 00000000 */   nop   
/* 04E41C 8007301C 3C03800B */  lui   $v1, 0x800b
/* 04E420 80073020 24630F10 */  addiu $v1, $v1, 0xf10
/* 04E424 80073024 3C048007 */  lui   $a0, 0x8007
/* 04E428 80073028 2484419C */  addiu $a0, $a0, 0x419c
/* 04E42C 8007302C A0600004 */  sb    $zero, 4($v1)
/* 04E430 80073030 8C850000 */  lw    $a1, ($a0)
/* 04E434 80073034 24020001 */  addiu $v0, $zero, 1
/* 04E438 80073038 A0620005 */  sb    $v0, 5($v1)
/* 04E43C 8007303C A0600006 */  sb    $zero, 6($v1)
/* 04E440 80073040 90A200AA */  lbu   $v0, 0xaa($a1)
/* 04E444 80073044 34420010 */  ori   $v0, $v0, 0x10
/* 04E448 80073048 A0A200AA */  sb    $v0, 0xaa($a1)
/* 04E44C 8007304C 8C830000 */  lw    $v1, ($a0)
/* 04E450 80073050 906200AA */  lbu   $v0, 0xaa($v1)
/* 04E454 80073054 34420020 */  ori   $v0, $v0, 0x20
/* 04E458 80073058 A06200AA */  sb    $v0, 0xaa($v1)
/* 04E45C 8007305C 8C830000 */  lw    $v1, ($a0)
/* 04E460 80073060 906200AA */  lbu   $v0, 0xaa($v1)
/* 04E464 80073064 34420040 */  ori   $v0, $v0, 0x40
/* 04E468 80073068 0801CC4A */  j     .L80073128
/* 04E46C 8007306C A06200AA */   sb    $v0, 0xaa($v1)

/* 04E470 80073070 3C03800B */  lui   $v1, 0x800b
/* 04E474 80073074 24630F10 */  addiu $v1, $v1, 0xf10
/* 04E478 80073078 24020001 */  addiu $v0, $zero, 1
/* 04E47C 8007307C A0620004 */  sb    $v0, 4($v1)
/* 04E480 80073080 92040001 */  lbu   $a0, 1($s0)
/* 04E484 80073084 3C058007 */  lui   $a1, 0x8007
/* 04E488 80073088 8CA5419C */  lw    $a1, 0x419c($a1)
/* 04E48C 8007308C 0801CC2D */  j     .L800730B4
/* 04E490 80073090 24020004 */   addiu $v0, $zero, 4

/* 04E494 80073094 3C03800B */  lui   $v1, 0x800b
/* 04E498 80073098 24630F10 */  addiu $v1, $v1, 0xf10
/* 04E49C 8007309C 24020001 */  addiu $v0, $zero, 1
/* 04E4A0 800730A0 A0620004 */  sb    $v0, 4($v1)
/* 04E4A4 800730A4 92040000 */  lbu   $a0, ($s0)
/* 04E4A8 800730A8 3C058007 */  lui   $a1, 0x8007
/* 04E4AC 800730AC 8CA5419C */  lw    $a1, 0x419c($a1)
/* 04E4B0 800730B0 24020002 */  addiu $v0, $zero, 2
.L800730B4:
/* 04E4B4 800730B4 A0620005 */  sb    $v0, 5($v1)
/* 04E4B8 800730B8 A0640006 */  sb    $a0, 6($v1)
/* 04E4BC 800730BC 90A200AA */  lbu   $v0, 0xaa($a1)
/* 04E4C0 800730C0 34420010 */  ori   $v0, $v0, 0x10
/* 04E4C4 800730C4 0801CC4A */  j     .L80073128
/* 04E4C8 800730C8 A0A200AA */   sb    $v0, 0xaa($a1)

/* 04E4CC 800730CC 3C03800B */  lui   $v1, 0x800b
/* 04E4D0 800730D0 24630F10 */  addiu $v1, $v1, 0xf10
/* 04E4D4 800730D4 24020001 */  addiu $v0, $zero, 1
/* 04E4D8 800730D8 A0620004 */  sb    $v0, 4($v1)
/* 04E4DC 800730DC 3C048007 */  lui   $a0, 0x8007
/* 04E4E0 800730E0 8C84419C */  lw    $a0, 0x419c($a0)
/* 04E4E4 800730E4 24020006 */  addiu $v0, $zero, 6
/* 04E4E8 800730E8 A0620005 */  sb    $v0, 5($v1)
/* 04E4EC 800730EC 908200AA */  lbu   $v0, 0xaa($a0)
/* 04E4F0 800730F0 0801CC49 */  j     .L80073124
/* 04E4F4 800730F4 34420020 */   ori   $v0, $v0, 0x20

/* 04E4F8 800730F8 3C03800B */  lui   $v1, 0x800b
/* 04E4FC 800730FC 24630F10 */  addiu $v1, $v1, 0xf10
/* 04E500 80073100 24020002 */  addiu $v0, $zero, 2
/* 04E504 80073104 A0620004 */  sb    $v0, 4($v1)
/* 04E508 80073108 3C048007 */  lui   $a0, 0x8007
/* 04E50C 8007310C 8C84419C */  lw    $a0, 0x419c($a0)
/* 04E510 80073110 24020001 */  addiu $v0, $zero, 1
/* 04E514 80073114 A0620005 */  sb    $v0, 5($v1)
/* 04E518 80073118 A0600006 */  sb    $zero, 6($v1)
/* 04E51C 8007311C 908200AA */  lbu   $v0, 0xaa($a0)
/* 04E520 80073120 34420040 */  ori   $v0, $v0, 0x40
.L80073124:
/* 04E524 80073124 A08200AA */  sb    $v0, 0xaa($a0)
.L80073128:
/* 04E528 80073128 0000202D */  daddu $a0, $zero, $zero
/* 04E52C 8007312C 3C05F840 */  lui   $a1, 0xf840
/* 04E530 80073130 34A56299 */  ori   $a1, $a1, 0x6299
/* 04E534 80073134 0C0B2026 */  jal   set_variable
/* 04E538 80073138 24060001 */   addiu $a2, $zero, 1
/* 04E53C 8007313C 2404FFFF */  addiu $a0, $zero, -1
/* 04E540 80073140 3C02800B */  lui   $v0, 0x800b
/* 04E544 80073144 24420F10 */  addiu $v0, $v0, 0xf10
/* 04E548 80073148 A0400007 */  sb    $zero, 7($v0)
/* 04E54C 8007314C 0C01CB33 */  jal   func_80072CCC
/* 04E550 80073150 A0400010 */   sb    $zero, 0x10($v0)
/* 04E554 80073154 3C038007 */  lui   $v1, 0x8007
/* 04E558 80073158 8C63419C */  lw    $v1, 0x419c($v1)
/* 04E55C 8007315C 0220202D */  daddu $a0, $s1, $zero
/* 04E560 80073160 906200AA */  lbu   $v0, 0xaa($v1)
/* 04E564 80073164 3C05800A */  lui   $a1, 0x800a
/* 04E568 80073168 24A5A650 */  addiu $a1, $a1, -0x59b0
/* 04E56C 8007316C 34420001 */  ori   $v0, $v0, 1
/* 04E570 80073170 A06200AA */  sb    $v0, 0xaa($v1)
/* 04E574 80073174 8CA20000 */  lw    $v0, ($a1)
/* 04E578 80073178 2403FFF7 */  addiu $v1, $zero, -9
/* 04E57C 8007317C 00431024 */  and   $v0, $v0, $v1
/* 04E580 80073180 0C01CB24 */  jal   load_battle
/* 04E584 80073184 ACA20000 */   sw    $v0, ($a1)
/* 04E588 80073188 8FBF0018 */  lw    $ra, 0x18($sp)
/* 04E58C 8007318C 8FB10014 */  lw    $s1, 0x14($sp)
/* 04E590 80073190 8FB00010 */  lw    $s0, 0x10($sp)
/* 04E594 80073194 03E00008 */  jr    $ra
/* 04E598 80073198 27BD0020 */   addiu $sp, $sp, 0x20

/* 04E59C 8007319C 00000000 */  nop   


