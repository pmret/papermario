.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401C0_842D90
/* 842D90 802401C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 842D94 802401C4 2404009E */  addiu     $a0, $zero, 0x9e
/* 842D98 802401C8 2405FFFF */  addiu     $a1, $zero, -1
/* 842D9C 802401CC 24060001 */  addiu     $a2, $zero, 1
/* 842DA0 802401D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 842DA4 802401D4 0C046E54 */  jal       func_8011B950
/* 842DA8 802401D8 00C0382D */   daddu    $a3, $a2, $zero
/* 842DAC 802401DC 0000202D */  daddu     $a0, $zero, $zero
/* 842DB0 802401E0 0080282D */  daddu     $a1, $a0, $zero
/* 842DB4 802401E4 0080302D */  daddu     $a2, $a0, $zero
/* 842DB8 802401E8 0C046F97 */  jal       set_background_color_blend
/* 842DBC 802401EC 240700FF */   addiu    $a3, $zero, 0xff
/* 842DC0 802401F0 3C03800B */  lui       $v1, %hi(gCameras)
/* 842DC4 802401F4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 842DC8 802401F8 A460002C */  sh        $zero, 0x2c($v1)
/* 842DCC 802401FC A460002E */  sh        $zero, 0x2e($v1)
/* 842DD0 80240200 A4600030 */  sh        $zero, 0x30($v1)
/* 842DD4 80240204 8FBF0010 */  lw        $ra, 0x10($sp)
/* 842DD8 80240208 24020002 */  addiu     $v0, $zero, 2
/* 842DDC 8024020C 03E00008 */  jr        $ra
/* 842DE0 80240210 27BD0018 */   addiu    $sp, $sp, 0x18
/* 842DE4 80240214 00000000 */  nop
/* 842DE8 80240218 00000000 */  nop
/* 842DEC 8024021C 00000000 */  nop
