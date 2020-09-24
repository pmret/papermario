.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055848
/* 30C48 80055848 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30C4C 8005584C AFB10014 */  sw        $s1, 0x14($sp)
/* 30C50 80055850 0080882D */  daddu     $s1, $a0, $zero
/* 30C54 80055854 3C028008 */  lui       $v0, 0x8008
/* 30C58 80055858 94428DB6 */  lhu       $v0, -0x724a($v0)
/* 30C5C 8005585C 0000182D */  daddu     $v1, $zero, $zero
/* 30C60 80055860 AFB20018 */  sw        $s2, 0x18($sp)
/* 30C64 80055864 24120004 */  addiu     $s2, $zero, 4
/* 30C68 80055868 AFBF001C */  sw        $ra, 0x1c($sp)
/* 30C6C 8005586C 12220012 */  beq       $s1, $v0, .L800558B8
/* 30C70 80055870 AFB00010 */   sw       $s0, 0x10($sp)
/* 30C74 80055874 0060802D */  daddu     $s0, $v1, $zero
.L80055878:
/* 30C78 80055878 16110005 */  bne       $s0, $s1, .L80055890
/* 30C7C 8005587C 00000000 */   nop      
/* 30C80 80055880 0C0155C6 */  jal       func_80055718
/* 30C84 80055884 0220202D */   daddu    $a0, $s1, $zero
/* 30C88 80055888 08015627 */  j         .L8005589C
/* 30C8C 8005588C 0040182D */   daddu    $v1, $v0, $zero
.L80055890:
/* 30C90 80055890 0C0155B4 */  jal       func_800556D0
/* 30C94 80055894 0200202D */   daddu    $a0, $s0, $zero
/* 30C98 80055898 0040182D */  daddu     $v1, $v0, $zero
.L8005589C:
/* 30C9C 8005589C 14600006 */  bnez      $v1, .L800558B8
/* 30CA0 800558A0 26100001 */   addiu    $s0, $s0, 1
/* 30CA4 800558A4 0212102B */  sltu      $v0, $s0, $s2
/* 30CA8 800558A8 1440FFF3 */  bnez      $v0, .L80055878
/* 30CAC 800558AC 00000000 */   nop      
/* 30CB0 800558B0 3C018008 */  lui       $at, 0x8008
/* 30CB4 800558B4 A4318DB6 */  sh        $s1, -0x724a($at)
.L800558B8:
/* 30CB8 800558B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30CBC 800558BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 30CC0 800558C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 30CC4 800558C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 30CC8 800558C8 0060102D */  daddu     $v0, $v1, $zero
/* 30CCC 800558CC 03E00008 */  jr        $ra
/* 30CD0 800558D0 27BD0020 */   addiu    $sp, $sp, 0x20
