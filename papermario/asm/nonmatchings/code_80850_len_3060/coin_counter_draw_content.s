.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel coin_counter_draw_content
/* 082788 800E92D8 3C038011 */  lui   $v1, 0x8011
/* 08278C 800E92DC 8463F29C */  lh    $v1, -0xd64($v1)
/* 082790 800E92E0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 082794 800E92E4 AFB3002C */  sw    $s3, 0x2c($sp)
/* 082798 800E92E8 00A0982D */  daddu $s3, $a1, $zero
/* 08279C 800E92EC AFB20028 */  sw    $s2, 0x28($sp)
/* 0827A0 800E92F0 3C128011 */  lui   $s2, 0x8011
/* 0827A4 800E92F4 2652EF58 */  addiu $s2, $s2, -0x10a8
/* 0827A8 800E92F8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0827AC 800E92FC AFB40030 */  sw    $s4, 0x30($sp)
/* 0827B0 800E9300 AFB10024 */  sw    $s1, 0x24($sp)
/* 0827B4 800E9304 AFB00020 */  sw    $s0, 0x20($sp)
/* 0827B8 800E9308 86420040 */  lh    $v0, 0x40($s2)
/* 0827BC 800E930C 10620011 */  beq   $v1, $v0, .L800E9354
/* 0827C0 800E9310 00C0A02D */   daddu $s4, $a2, $zero
/* 0827C4 800E9314 3C028007 */  lui   $v0, 0x8007
/* 0827C8 800E9318 8C42419C */  lw    $v0, 0x419c($v0)
/* 0827CC 800E931C 94430134 */  lhu   $v1, 0x134($v0)
/* 0827D0 800E9320 3C02AAAA */  lui   $v0, 0xaaaa
/* 0827D4 800E9324 3442AAAB */  ori   $v0, $v0, 0xaaab
/* 0827D8 800E9328 00620019 */  multu $v1, $v0
/* 0827DC 800E932C 00004010 */  mfhi  $t0
/* 0827E0 800E9330 00082042 */  srl   $a0, $t0, 1
/* 0827E4 800E9334 00041040 */  sll   $v0, $a0, 1
/* 0827E8 800E9338 00441021 */  addu  $v0, $v0, $a0
/* 0827EC 800E933C 00621823 */  subu  $v1, $v1, $v0
/* 0827F0 800E9340 3063FFFF */  andi  $v1, $v1, 0xffff
/* 0827F4 800E9344 14600004 */  bnez  $v1, .L800E9358
/* 0827F8 800E9348 2665001B */   addiu $a1, $s3, 0x1b
/* 0827FC 800E934C 0C05272D */  jal   play_sound
/* 082800 800E9350 24040211 */   addiu $a0, $zero, 0x211
.L800E9354:
/* 082804 800E9354 2665001B */  addiu $a1, $s3, 0x1b
.L800E9358:
/* 082808 800E9358 2690000B */  addiu $s0, $s4, 0xb
/* 08280C 800E935C 8E51005C */  lw    $s1, 0x5c($s2)
/* 082810 800E9360 0200302D */  daddu $a2, $s0, $zero
/* 082814 800E9364 0C051261 */  jal   set_icon_render_pos
/* 082818 800E9368 0220202D */   daddu $a0, $s1, $zero
/* 08281C 800E936C 0C0511EA */  jal   draw_icon_0
/* 082820 800E9370 0220202D */   daddu $a0, $s1, $zero
/* 082824 800E9374 2665000F */  addiu $a1, $s3, 0xf
/* 082828 800E9378 8E510060 */  lw    $s1, 0x60($s2)
/* 08282C 800E937C 0200302D */  daddu $a2, $s0, $zero
/* 082830 800E9380 0C051261 */  jal   set_icon_render_pos
/* 082834 800E9384 0220202D */   daddu $a0, $s1, $zero
/* 082838 800E9388 0C0511EA */  jal   draw_icon_0
/* 08283C 800E938C 0220202D */   daddu $a0, $s1, $zero
/* 082840 800E9390 2665003A */  addiu $a1, $s3, 0x3a
/* 082844 800E9394 26860004 */  addiu $a2, $s4, 4
/* 082848 800E9398 2402000A */  addiu $v0, $zero, 0xa
/* 08284C 800E939C AFA20010 */  sw    $v0, 0x10($sp)
/* 082850 800E93A0 240200FF */  addiu $v0, $zero, 0xff
/* 082854 800E93A4 AFA20014 */  sw    $v0, 0x14($sp)
/* 082858 800E93A8 24020003 */  addiu $v0, $zero, 3
/* 08285C 800E93AC 86440040 */  lh    $a0, 0x40($s2)
/* 082860 800E93B0 24070001 */  addiu $a3, $zero, 1
/* 082864 800E93B4 0C049DA7 */  jal   draw_number
/* 082868 800E93B8 AFA20018 */   sw    $v0, 0x18($sp)
/* 08286C 800E93BC 8FBF0034 */  lw    $ra, 0x34($sp)
/* 082870 800E93C0 8FB40030 */  lw    $s4, 0x30($sp)
/* 082874 800E93C4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 082878 800E93C8 8FB20028 */  lw    $s2, 0x28($sp)
/* 08287C 800E93CC 8FB10024 */  lw    $s1, 0x24($sp)
/* 082880 800E93D0 8FB00020 */  lw    $s0, 0x20($sp)
/* 082884 800E93D4 03E00008 */  jr    $ra
/* 082888 800E93D8 27BD0038 */   addiu $sp, $sp, 0x38

