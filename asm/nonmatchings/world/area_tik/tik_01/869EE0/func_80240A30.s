.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A30
/* 869EE0 80240A30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 869EE4 80240A34 AFBF0014 */  sw        $ra, 0x14($sp)
/* 869EE8 80240A38 AFB00010 */  sw        $s0, 0x10($sp)
/* 869EEC 80240A3C 8C82000C */  lw        $v0, 0xc($a0)
/* 869EF0 80240A40 8C450000 */  lw        $a1, ($v0)
/* 869EF4 80240A44 0C0B1EAF */  jal       get_variable
/* 869EF8 80240A48 8C900148 */   lw       $s0, 0x148($a0)
/* 869EFC 80240A4C 82030004 */  lb        $v1, 4($s0)
/* 869F00 80240A50 00021080 */  sll       $v0, $v0, 2
/* 869F04 80240A54 00031880 */  sll       $v1, $v1, 2
/* 869F08 80240A58 3C04800B */  lui       $a0, 0x800b
/* 869F0C 80240A5C 00832021 */  addu      $a0, $a0, $v1
/* 869F10 80240A60 8C840F38 */  lw        $a0, 0xf38($a0)
/* 869F14 80240A64 3C038024 */  lui       $v1, 0x8024
/* 869F18 80240A68 00621821 */  addu      $v1, $v1, $v0
/* 869F1C 80240A6C 94632B7E */  lhu       $v1, 0x2b7e($v1)
/* 869F20 80240A70 A4830044 */  sh        $v1, 0x44($a0)
/* 869F24 80240A74 8FBF0014 */  lw        $ra, 0x14($sp)
/* 869F28 80240A78 8FB00010 */  lw        $s0, 0x10($sp)
/* 869F2C 80240A7C 24020002 */  addiu     $v0, $zero, 2
/* 869F30 80240A80 03E00008 */  jr        $ra
/* 869F34 80240A84 27BD0018 */   addiu    $sp, $sp, 0x18
/* 869F38 80240A88 00000000 */  nop       
/* 869F3C 80240A8C 00000000 */  nop       
