.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_EB98FC
/* EB98FC 80240AAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB9900 80240AB0 AFB10014 */  sw        $s1, 0x14($sp)
/* EB9904 80240AB4 0080882D */  daddu     $s1, $a0, $zero
/* EB9908 80240AB8 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB990C 80240ABC AFB00010 */  sw        $s0, 0x10($sp)
/* EB9910 80240AC0 8E300148 */  lw        $s0, 0x148($s1)
/* EB9914 80240AC4 0C00F92F */  jal       func_8003E4BC
/* EB9918 80240AC8 86040008 */   lh       $a0, 8($s0)
/* EB991C 80240ACC 9443008E */  lhu       $v1, 0x8e($v0)
/* EB9920 80240AD0 2463FFFF */  addiu     $v1, $v1, -1
/* EB9924 80240AD4 A443008E */  sh        $v1, 0x8e($v0)
/* EB9928 80240AD8 00031C00 */  sll       $v1, $v1, 0x10
/* EB992C 80240ADC 14600008 */  bnez      $v1, .L80240B00
/* EB9930 80240AE0 00000000 */   nop
/* EB9934 80240AE4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EB9938 80240AE8 30420080 */  andi      $v0, $v0, 0x80
/* EB993C 80240AEC 10400003 */  beqz      $v0, .L80240AFC
/* EB9940 80240AF0 2402000F */   addiu    $v0, $zero, 0xf
/* EB9944 80240AF4 080902C0 */  j         .L80240B00
/* EB9948 80240AF8 AE220070 */   sw       $v0, 0x70($s1)
.L80240AFC:
/* EB994C 80240AFC AE200070 */  sw        $zero, 0x70($s1)
.L80240B00:
/* EB9950 80240B00 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB9954 80240B04 8FB10014 */  lw        $s1, 0x14($sp)
/* EB9958 80240B08 8FB00010 */  lw        $s0, 0x10($sp)
/* EB995C 80240B0C 03E00008 */  jr        $ra
/* EB9960 80240B10 27BD0020 */   addiu    $sp, $sp, 0x20
