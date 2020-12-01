.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241764_CCCA74
/* CCCA74 80241764 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCCA78 80241768 AFB00010 */  sw        $s0, 0x10($sp)
/* CCCA7C 8024176C 0080802D */  daddu     $s0, $a0, $zero
/* CCCA80 80241770 AFBF0014 */  sw        $ra, 0x14($sp)
/* CCCA84 80241774 8E020148 */  lw        $v0, 0x148($s0)
/* CCCA88 80241778 0C00EABB */  jal       get_npc_unsafe
/* CCCA8C 8024177C 84440008 */   lh       $a0, 8($v0)
/* CCCA90 80241780 9443008E */  lhu       $v1, 0x8e($v0)
/* CCCA94 80241784 C440003C */  lwc1      $f0, 0x3c($v0)
/* CCCA98 80241788 24640001 */  addiu     $a0, $v1, 1
/* CCCA9C 8024178C 00031C00 */  sll       $v1, $v1, 0x10
/* CCCAA0 80241790 00031B83 */  sra       $v1, $v1, 0xe
/* CCCAA4 80241794 A444008E */  sh        $a0, 0x8e($v0)
/* CCCAA8 80241798 3C018024 */  lui       $at, %hi(D_802444C0)
/* CCCAAC 8024179C 00230821 */  addu      $at, $at, $v1
/* CCCAB0 802417A0 C42244C0 */  lwc1      $f2, %lo(D_802444C0)($at)
/* CCCAB4 802417A4 8443008E */  lh        $v1, 0x8e($v0)
/* CCCAB8 802417A8 46020000 */  add.s     $f0, $f0, $f2
/* CCCABC 802417AC 28630005 */  slti      $v1, $v1, 5
/* CCCAC0 802417B0 14600003 */  bnez      $v1, .L802417C0
/* CCCAC4 802417B4 E440003C */   swc1     $f0, 0x3c($v0)
/* CCCAC8 802417B8 2402000C */  addiu     $v0, $zero, 0xc
/* CCCACC 802417BC AE020070 */  sw        $v0, 0x70($s0)
.L802417C0:
/* CCCAD0 802417C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CCCAD4 802417C4 8FB00010 */  lw        $s0, 0x10($sp)
/* CCCAD8 802417C8 03E00008 */  jr        $ra
/* CCCADC 802417CC 27BD0018 */   addiu    $sp, $sp, 0x18
