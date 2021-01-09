.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD4B4
/* F1E64 802CD4B4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* F1E68 802CD4B8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* F1E6C 802CD4BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1E70 802CD4C0 AFBF001C */  sw        $ra, 0x1c($sp)
/* F1E74 802CD4C4 AFB20018 */  sw        $s2, 0x18($sp)
/* F1E78 802CD4C8 AFB10014 */  sw        $s1, 0x14($sp)
/* F1E7C 802CD4CC AFB00010 */  sw        $s0, 0x10($sp)
/* F1E80 802CD4D0 80420070 */  lb        $v0, 0x70($v0)
/* F1E84 802CD4D4 14400005 */  bnez      $v0, .L802CD4EC
/* F1E88 802CD4D8 00000000 */   nop      
/* F1E8C 802CD4DC 3C02802E */  lui       $v0, %hi(gWorldMeshAnimationList)
/* F1E90 802CD4E0 2442ADF0 */  addiu     $v0, $v0, %lo(gWorldMeshAnimationList)
/* F1E94 802CD4E4 080B353D */  j         .L802CD4F4
/* F1E98 802CD4E8 00000000 */   nop      
.L802CD4EC:
/* F1E9C 802CD4EC 3C02802E */  lui       $v0, %hi(gBattleMeshAnimationList)
/* F1EA0 802CD4F0 2442ADB0 */  addiu     $v0, $v0, %lo(gBattleMeshAnimationList)
.L802CD4F4:
/* F1EA4 802CD4F4 3C01802E */  lui       $at, %hi(gCurrentMeshAnimationListPtr)
/* F1EA8 802CD4F8 AC22AE30 */  sw        $v0, %lo(gCurrentMeshAnimationListPtr)($at)
/* F1EAC 802CD4FC 0000882D */  daddu     $s1, $zero, $zero
/* F1EB0 802CD500 2412FFFF */  addiu     $s2, $zero, -1
/* F1EB4 802CD504 0220802D */  daddu     $s0, $s1, $zero
.L802CD508:
/* F1EB8 802CD508 0C00AB39 */  jal       heap_malloc
/* F1EBC 802CD50C 24040070 */   addiu    $a0, $zero, 0x70
/* F1EC0 802CD510 3C03802E */  lui       $v1, %hi(gCurrentMeshAnimationListPtr)
/* F1EC4 802CD514 8C63AE30 */  lw        $v1, %lo(gCurrentMeshAnimationListPtr)($v1)
/* F1EC8 802CD518 02031821 */  addu      $v1, $s0, $v1
/* F1ECC 802CD51C 14400003 */  bnez      $v0, .L802CD52C
/* F1ED0 802CD520 AC620000 */   sw       $v0, ($v1)
.L802CD524:
/* F1ED4 802CD524 080B3549 */  j         .L802CD524
/* F1ED8 802CD528 00000000 */   nop      
.L802CD52C:
/* F1EDC 802CD52C 3C02802E */  lui       $v0, %hi(gCurrentMeshAnimationListPtr)
/* F1EE0 802CD530 8C42AE30 */  lw        $v0, %lo(gCurrentMeshAnimationListPtr)($v0)
/* F1EE4 802CD534 26310001 */  addiu     $s1, $s1, 1
/* F1EE8 802CD538 02021021 */  addu      $v0, $s0, $v0
/* F1EEC 802CD53C 8C420000 */  lw        $v0, ($v0)
/* F1EF0 802CD540 AC520000 */  sw        $s2, ($v0)
/* F1EF4 802CD544 2A220010 */  slti      $v0, $s1, 0x10
/* F1EF8 802CD548 1440FFEF */  bnez      $v0, .L802CD508
/* F1EFC 802CD54C 26100004 */   addiu    $s0, $s0, 4
/* F1F00 802CD550 3C04802D */  lui       $a0, %hi(func_802CCAC0)
/* F1F04 802CD554 2484CAC0 */  addiu     $a0, $a0, %lo(func_802CCAC0)
/* F1F08 802CD558 3C05802D */  lui       $a1, %hi(draw_anim_models)
/* F1F0C 802CD55C 0C048C56 */  jal       bind_dynamic_entity_3
/* F1F10 802CD560 24A5CB18 */   addiu    $a1, $a1, %lo(draw_anim_models)
/* F1F14 802CD564 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1F18 802CD568 8FB20018 */  lw        $s2, 0x18($sp)
/* F1F1C 802CD56C 8FB10014 */  lw        $s1, 0x14($sp)
/* F1F20 802CD570 8FB00010 */  lw        $s0, 0x10($sp)
/* F1F24 802CD574 03E00008 */  jr        $ra
/* F1F28 802CD578 27BD0020 */   addiu    $sp, $sp, 0x20
