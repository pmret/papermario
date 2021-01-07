.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C54_C37184
/* C37184 80240C54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C37188 80240C58 AFB00010 */  sw        $s0, 0x10($sp)
/* C3718C 80240C5C 0080802D */  daddu     $s0, $a0, $zero
/* C37190 80240C60 AFBF0014 */  sw        $ra, 0x14($sp)
/* C37194 80240C64 8E020148 */  lw        $v0, 0x148($s0)
/* C37198 80240C68 0C00EABB */  jal       get_npc_unsafe
/* C3719C 80240C6C 84440008 */   lh       $a0, 8($v0)
/* C371A0 80240C70 9443008E */  lhu       $v1, 0x8e($v0)
/* C371A4 80240C74 C440003C */  lwc1      $f0, 0x3c($v0)
/* C371A8 80240C78 24640001 */  addiu     $a0, $v1, 1
/* C371AC 80240C7C 00031C00 */  sll       $v1, $v1, 0x10
/* C371B0 80240C80 00031B83 */  sra       $v1, $v1, 0xe
/* C371B4 80240C84 A444008E */  sh        $a0, 0x8e($v0)
/* C371B8 80240C88 3C018024 */  lui       $at, %hi(D_80243560)
/* C371BC 80240C8C 00230821 */  addu      $at, $at, $v1
/* C371C0 80240C90 C4223560 */  lwc1      $f2, %lo(D_80243560)($at)
/* C371C4 80240C94 8443008E */  lh        $v1, 0x8e($v0)
/* C371C8 80240C98 46020000 */  add.s     $f0, $f0, $f2
/* C371CC 80240C9C 28630005 */  slti      $v1, $v1, 5
/* C371D0 80240CA0 14600003 */  bnez      $v1, .L80240CB0
/* C371D4 80240CA4 E440003C */   swc1     $f0, 0x3c($v0)
/* C371D8 80240CA8 2402000C */  addiu     $v0, $zero, 0xc
/* C371DC 80240CAC AE020070 */  sw        $v0, 0x70($s0)
.L80240CB0:
/* C371E0 80240CB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* C371E4 80240CB4 8FB00010 */  lw        $s0, 0x10($sp)
/* C371E8 80240CB8 03E00008 */  jr        $ra
/* C371EC 80240CBC 27BD0018 */   addiu    $sp, $sp, 0x18
