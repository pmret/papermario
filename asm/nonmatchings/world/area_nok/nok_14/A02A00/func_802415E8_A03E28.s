.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415E8_A03E28
/* A03E28 802415E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A03E2C 802415EC AFB00010 */  sw        $s0, 0x10($sp)
/* A03E30 802415F0 0080802D */  daddu     $s0, $a0, $zero
/* A03E34 802415F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A03E38 802415F8 8E020148 */  lw        $v0, 0x148($s0)
/* A03E3C 802415FC 0C00EABB */  jal       get_npc_unsafe
/* A03E40 80241600 84440008 */   lh       $a0, 8($v0)
/* A03E44 80241604 9443008E */  lhu       $v1, 0x8e($v0)
/* A03E48 80241608 C440003C */  lwc1      $f0, 0x3c($v0)
/* A03E4C 8024160C 24640001 */  addiu     $a0, $v1, 1
/* A03E50 80241610 00031C00 */  sll       $v1, $v1, 0x10
/* A03E54 80241614 00031B83 */  sra       $v1, $v1, 0xe
/* A03E58 80241618 A444008E */  sh        $a0, 0x8e($v0)
/* A03E5C 8024161C 3C018024 */  lui       $at, %hi(D_80243A18)
/* A03E60 80241620 00230821 */  addu      $at, $at, $v1
/* A03E64 80241624 C4223A18 */  lwc1      $f2, %lo(D_80243A18)($at)
/* A03E68 80241628 8443008E */  lh        $v1, 0x8e($v0)
/* A03E6C 8024162C 46020000 */  add.s     $f0, $f0, $f2
/* A03E70 80241630 28630005 */  slti      $v1, $v1, 5
/* A03E74 80241634 14600003 */  bnez      $v1, .L80241644
/* A03E78 80241638 E440003C */   swc1     $f0, 0x3c($v0)
/* A03E7C 8024163C 2402000C */  addiu     $v0, $zero, 0xc
/* A03E80 80241640 AE020070 */  sw        $v0, 0x70($s0)
.L80241644:
/* A03E84 80241644 8FBF0014 */  lw        $ra, 0x14($sp)
/* A03E88 80241648 8FB00010 */  lw        $s0, 0x10($sp)
/* A03E8C 8024164C 03E00008 */  jr        $ra
/* A03E90 80241650 27BD0018 */   addiu    $sp, $sp, 0x18
