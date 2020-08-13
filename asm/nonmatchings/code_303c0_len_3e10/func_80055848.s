.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80055848
/* 030C48 80055848 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030C4C 8005584C AFB10014 */  sw    $s1, 0x14($sp)
/* 030C50 80055850 0080882D */  daddu $s1, $a0, $zero
/* 030C54 80055854 3C028008 */  lui   $v0, 0x8008
/* 030C58 80055858 94428DB6 */  lhu   $v0, -0x724a($v0)
/* 030C5C 8005585C 0000182D */  daddu $v1, $zero, $zero
/* 030C60 80055860 AFB20018 */  sw    $s2, 0x18($sp)
/* 030C64 80055864 24120004 */  addiu $s2, $zero, 4
/* 030C68 80055868 AFBF001C */  sw    $ra, 0x1c($sp)
/* 030C6C 8005586C 12220012 */  beq   $s1, $v0, .L800558B8
/* 030C70 80055870 AFB00010 */   sw    $s0, 0x10($sp)
/* 030C74 80055874 0060802D */  daddu $s0, $v1, $zero
.L80055878:
/* 030C78 80055878 16110005 */  bne   $s0, $s1, .L80055890
/* 030C7C 8005587C 00000000 */   nop   
/* 030C80 80055880 0C0155C6 */  jal   func_80055718
/* 030C84 80055884 0220202D */   daddu $a0, $s1, $zero
/* 030C88 80055888 08015627 */  j     .L8005589C
/* 030C8C 8005588C 0040182D */   daddu $v1, $v0, $zero

.L80055890:
/* 030C90 80055890 0C0155B4 */  jal   func_800556D0
/* 030C94 80055894 0200202D */   daddu $a0, $s0, $zero
/* 030C98 80055898 0040182D */  daddu $v1, $v0, $zero
.L8005589C:
/* 030C9C 8005589C 14600006 */  bnez  $v1, .L800558B8
/* 030CA0 800558A0 26100001 */   addiu $s0, $s0, 1
/* 030CA4 800558A4 0212102B */  sltu  $v0, $s0, $s2
/* 030CA8 800558A8 1440FFF3 */  bnez  $v0, .L80055878
/* 030CAC 800558AC 00000000 */   nop   
/* 030CB0 800558B0 3C018008 */  lui   $at, 0x8008
/* 030CB4 800558B4 A4318DB6 */  sh    $s1, -0x724a($at)
.L800558B8:
/* 030CB8 800558B8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 030CBC 800558BC 8FB20018 */  lw    $s2, 0x18($sp)
/* 030CC0 800558C0 8FB10014 */  lw    $s1, 0x14($sp)
/* 030CC4 800558C4 8FB00010 */  lw    $s0, 0x10($sp)
/* 030CC8 800558C8 0060102D */  daddu $v0, $v1, $zero
/* 030CCC 800558CC 03E00008 */  jr    $ra
/* 030CD0 800558D0 27BD0020 */   addiu $sp, $sp, 0x20

