.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E18_EDF7D8
/* EDF7D8 80240E18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EDF7DC 80240E1C AFB00010 */  sw        $s0, 0x10($sp)
/* EDF7E0 80240E20 0080802D */  daddu     $s0, $a0, $zero
/* EDF7E4 80240E24 AFBF0014 */  sw        $ra, 0x14($sp)
/* EDF7E8 80240E28 8E020148 */  lw        $v0, 0x148($s0)
/* EDF7EC 80240E2C 0C00F92F */  jal       func_8003E4BC
/* EDF7F0 80240E30 84440008 */   lh       $a0, 8($v0)
/* EDF7F4 80240E34 9443008E */  lhu       $v1, 0x8e($v0)
/* EDF7F8 80240E38 C440003C */  lwc1      $f0, 0x3c($v0)
/* EDF7FC 80240E3C 24640001 */  addiu     $a0, $v1, 1
/* EDF800 80240E40 00031C00 */  sll       $v1, $v1, 0x10
/* EDF804 80240E44 00031B83 */  sra       $v1, $v1, 0xe
/* EDF808 80240E48 A444008E */  sh        $a0, 0x8e($v0)
/* EDF80C 80240E4C 3C018024 */  lui       $at, %hi(D_802441DC)
/* EDF810 80240E50 00230821 */  addu      $at, $at, $v1
/* EDF814 80240E54 C42241DC */  lwc1      $f2, %lo(D_802441DC)($at)
/* EDF818 80240E58 8443008E */  lh        $v1, 0x8e($v0)
/* EDF81C 80240E5C 46020000 */  add.s     $f0, $f0, $f2
/* EDF820 80240E60 28630005 */  slti      $v1, $v1, 5
/* EDF824 80240E64 14600003 */  bnez      $v1, .L80240E74
/* EDF828 80240E68 E440003C */   swc1     $f0, 0x3c($v0)
/* EDF82C 80240E6C 2402000C */  addiu     $v0, $zero, 0xc
/* EDF830 80240E70 AE020070 */  sw        $v0, 0x70($s0)
.L80240E74:
/* EDF834 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* EDF838 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* EDF83C 80240E7C 03E00008 */  jr        $ra
/* EDF840 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
