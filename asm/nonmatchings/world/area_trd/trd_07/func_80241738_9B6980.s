.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241738_9B80B8
/* 9B80B8 80241738 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B80BC 8024173C AFB00010 */  sw        $s0, 0x10($sp)
/* 9B80C0 80241740 0080802D */  daddu     $s0, $a0, $zero
/* 9B80C4 80241744 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9B80C8 80241748 8E020148 */  lw        $v0, 0x148($s0)
/* 9B80CC 8024174C 0C00EABB */  jal       get_npc_unsafe
/* 9B80D0 80241750 84440008 */   lh       $a0, 8($v0)
/* 9B80D4 80241754 9443008E */  lhu       $v1, 0x8e($v0)
/* 9B80D8 80241758 C440003C */  lwc1      $f0, 0x3c($v0)
/* 9B80DC 8024175C 24640001 */  addiu     $a0, $v1, 1
/* 9B80E0 80241760 00031C00 */  sll       $v1, $v1, 0x10
/* 9B80E4 80241764 00031B83 */  sra       $v1, $v1, 0xe
/* 9B80E8 80241768 A444008E */  sh        $a0, 0x8e($v0)
/* 9B80EC 8024176C 3C018024 */  lui       $at, 0x8024
/* 9B80F0 80241770 00230821 */  addu      $at, $at, $v1
/* 9B80F4 80241774 C4222EAC */  lwc1      $f2, 0x2eac($at)
/* 9B80F8 80241778 8443008E */  lh        $v1, 0x8e($v0)
/* 9B80FC 8024177C 46020000 */  add.s     $f0, $f0, $f2
/* 9B8100 80241780 28630005 */  slti      $v1, $v1, 5
/* 9B8104 80241784 14600003 */  bnez      $v1, .L80241794
/* 9B8108 80241788 E440003C */   swc1     $f0, 0x3c($v0)
/* 9B810C 8024178C 2402000C */  addiu     $v0, $zero, 0xc
/* 9B8110 80241790 AE020070 */  sw        $v0, 0x70($s0)
.L80241794:
/* 9B8114 80241794 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9B8118 80241798 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B811C 8024179C 03E00008 */  jr        $ra
/* 9B8120 802417A0 27BD0018 */   addiu    $sp, $sp, 0x18
