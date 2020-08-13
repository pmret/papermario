.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ApplyShrinkFromOwner
/* 182A78 80254198 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 182A7C 8025419C AFB10014 */  sw    $s1, 0x14($sp)
/* 182A80 802541A0 0080882D */  daddu $s1, $a0, $zero
/* 182A84 802541A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 182A88 802541A8 AFB20018 */  sw    $s2, 0x18($sp)
/* 182A8C 802541AC AFB00010 */  sw    $s0, 0x10($sp)
/* 182A90 802541B0 8E240148 */  lw    $a0, 0x148($s1)
/* 182A94 802541B4 0C09A75B */  jal   get_actor
/* 182A98 802541B8 8E32000C */   lw    $s2, 0xc($s1)
/* 182A9C 802541BC 0220202D */  daddu $a0, $s1, $zero
/* 182AA0 802541C0 8E450000 */  lw    $a1, ($s2)
/* 182AA4 802541C4 0C0B1EAF */  jal   get_variable
/* 182AA8 802541C8 0040802D */   daddu $s0, $v0, $zero
/* 182AAC 802541CC 0040302D */  daddu $a2, $v0, $zero
/* 182AB0 802541D0 82030210 */  lb    $v1, 0x210($s0)
/* 182AB4 802541D4 2402000A */  addiu $v0, $zero, 0xa
/* 182AB8 802541D8 14620005 */  bne   $v1, $v0, .L802541F0
/* 182ABC 802541DC 00000000 */   nop   
/* 182AC0 802541E0 18C00003 */  blez  $a2, .L802541F0
/* 182AC4 802541E4 000617C2 */   srl   $v0, $a2, 0x1f
/* 182AC8 802541E8 00C21021 */  addu  $v0, $a2, $v0
/* 182ACC 802541EC 00023043 */  sra   $a2, $v0, 1
.L802541F0:
/* 182AD0 802541F0 8E450000 */  lw    $a1, ($s2)
/* 182AD4 802541F4 0C0B2026 */  jal   set_variable
/* 182AD8 802541F8 0220202D */   daddu $a0, $s1, $zero
/* 182ADC 802541FC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 182AE0 80254200 8FB20018 */  lw    $s2, 0x18($sp)
/* 182AE4 80254204 8FB10014 */  lw    $s1, 0x14($sp)
/* 182AE8 80254208 8FB00010 */  lw    $s0, 0x10($sp)
/* 182AEC 8025420C 24020002 */  addiu $v0, $zero, 2
/* 182AF0 80254210 03E00008 */  jr    $ra
/* 182AF4 80254214 27BD0020 */   addiu $sp, $sp, 0x20

