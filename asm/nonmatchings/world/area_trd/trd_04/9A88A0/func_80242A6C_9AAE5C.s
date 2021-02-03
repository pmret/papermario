.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A6C_9AAE5C
/* 9AAE5C 80242A6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9AAE60 80242A70 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AAE64 80242A74 0080802D */  daddu     $s0, $a0, $zero
/* 9AAE68 80242A78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9AAE6C 80242A7C 8E020148 */  lw        $v0, 0x148($s0)
/* 9AAE70 80242A80 0C00EABB */  jal       get_npc_unsafe
/* 9AAE74 80242A84 84440008 */   lh       $a0, 8($v0)
/* 9AAE78 80242A88 9443008E */  lhu       $v1, 0x8e($v0)
/* 9AAE7C 80242A8C C440003C */  lwc1      $f0, 0x3c($v0)
/* 9AAE80 80242A90 24640001 */  addiu     $a0, $v1, 1
/* 9AAE84 80242A94 00031C00 */  sll       $v1, $v1, 0x10
/* 9AAE88 80242A98 00031B83 */  sra       $v1, $v1, 0xe
/* 9AAE8C 80242A9C A444008E */  sh        $a0, 0x8e($v0)
/* 9AAE90 80242AA0 3C018024 */  lui       $at, %hi(D_802456F4_9ADAE4)
/* 9AAE94 80242AA4 00230821 */  addu      $at, $at, $v1
/* 9AAE98 80242AA8 C42256F4 */  lwc1      $f2, %lo(D_802456F4_9ADAE4)($at)
/* 9AAE9C 80242AAC 8443008E */  lh        $v1, 0x8e($v0)
/* 9AAEA0 80242AB0 46020000 */  add.s     $f0, $f0, $f2
/* 9AAEA4 80242AB4 28630005 */  slti      $v1, $v1, 5
/* 9AAEA8 80242AB8 14600003 */  bnez      $v1, .L80242AC8
/* 9AAEAC 80242ABC E440003C */   swc1     $f0, 0x3c($v0)
/* 9AAEB0 80242AC0 2402000C */  addiu     $v0, $zero, 0xc
/* 9AAEB4 80242AC4 AE020070 */  sw        $v0, 0x70($s0)
.L80242AC8:
/* 9AAEB8 80242AC8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9AAEBC 80242ACC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AAEC0 80242AD0 03E00008 */  jr        $ra
/* 9AAEC4 80242AD4 27BD0018 */   addiu    $sp, $sp, 0x18
