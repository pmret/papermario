.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C54_8D6A54
/* 8D6A54 80240C54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D6A58 80240C58 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D6A5C 80240C5C 0080802D */  daddu     $s0, $a0, $zero
/* 8D6A60 80240C60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D6A64 80240C64 8E020148 */  lw        $v0, 0x148($s0)
/* 8D6A68 80240C68 0C00EABB */  jal       get_npc_unsafe
/* 8D6A6C 80240C6C 84440008 */   lh       $a0, 8($v0)
/* 8D6A70 80240C70 9443008E */  lhu       $v1, 0x8e($v0)
/* 8D6A74 80240C74 C440003C */  lwc1      $f0, 0x3c($v0)
/* 8D6A78 80240C78 24640001 */  addiu     $a0, $v1, 1
/* 8D6A7C 80240C7C 00031C00 */  sll       $v1, $v1, 0x10
/* 8D6A80 80240C80 00031B83 */  sra       $v1, $v1, 0xe
/* 8D6A84 80240C84 A444008E */  sh        $a0, 0x8e($v0)
/* 8D6A88 80240C88 3C018024 */  lui       $at, %hi(D_8024186C)
/* 8D6A8C 80240C8C 00230821 */  addu      $at, $at, $v1
/* 8D6A90 80240C90 C422186C */  lwc1      $f2, %lo(D_8024186C)($at)
/* 8D6A94 80240C94 8443008E */  lh        $v1, 0x8e($v0)
/* 8D6A98 80240C98 46020000 */  add.s     $f0, $f0, $f2
/* 8D6A9C 80240C9C 28630005 */  slti      $v1, $v1, 5
/* 8D6AA0 80240CA0 14600003 */  bnez      $v1, .L80240CB0
/* 8D6AA4 80240CA4 E440003C */   swc1     $f0, 0x3c($v0)
/* 8D6AA8 80240CA8 2402000C */  addiu     $v0, $zero, 0xc
/* 8D6AAC 80240CAC AE020070 */  sw        $v0, 0x70($s0)
.L80240CB0:
/* 8D6AB0 80240CB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D6AB4 80240CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D6AB8 80240CB8 03E00008 */  jr        $ra
/* 8D6ABC 80240CBC 27BD0018 */   addiu    $sp, $sp, 0x18
