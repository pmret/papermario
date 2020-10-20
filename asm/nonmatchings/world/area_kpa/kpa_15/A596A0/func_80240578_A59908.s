.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240578_A59908
/* A59908 80240578 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A5990C 8024057C AFB00010 */  sw        $s0, 0x10($sp)
/* A59910 80240580 0080802D */  daddu     $s0, $a0, $zero
/* A59914 80240584 AFBF0014 */  sw        $ra, 0x14($sp)
/* A59918 80240588 8E02000C */  lw        $v0, 0xc($s0)
/* A5991C 8024058C 0C0B1EAF */  jal       get_variable
/* A59920 80240590 8C450000 */   lw       $a1, ($v0)
/* A59924 80240594 00021140 */  sll       $v0, $v0, 5
/* A59928 80240598 AE000084 */  sw        $zero, 0x84($s0)
/* A5992C 8024059C 3C018008 */  lui       $at, 0x8008
/* A59930 802405A0 00220821 */  addu      $at, $at, $v0
/* A59934 802405A4 942278F8 */  lhu       $v0, 0x78f8($at)
/* A59938 802405A8 30420040 */  andi      $v0, $v0, 0x40
/* A5993C 802405AC 10400002 */  beqz      $v0, .L802405B8
/* A59940 802405B0 24020001 */   addiu    $v0, $zero, 1
/* A59944 802405B4 AE020084 */  sw        $v0, 0x84($s0)
.L802405B8:
/* A59948 802405B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A5994C 802405BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A59950 802405C0 24020002 */  addiu     $v0, $zero, 2
/* A59954 802405C4 03E00008 */  jr        $ra
/* A59958 802405C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* A5995C 802405CC 00000000 */  nop       
