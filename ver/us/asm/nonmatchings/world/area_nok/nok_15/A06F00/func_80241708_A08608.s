.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_15_SixFloatsFunc
/* A08608 80241708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A0860C 8024170C AFB00010 */  sw        $s0, 0x10($sp)
/* A08610 80241710 0080802D */  daddu     $s0, $a0, $zero
/* A08614 80241714 AFBF0014 */  sw        $ra, 0x14($sp)
/* A08618 80241718 8E020148 */  lw        $v0, 0x148($s0)
/* A0861C 8024171C 0C00EABB */  jal       get_npc_unsafe
/* A08620 80241720 84440008 */   lh       $a0, 8($v0)
/* A08624 80241724 9443008E */  lhu       $v1, 0x8e($v0)
/* A08628 80241728 C440003C */  lwc1      $f0, 0x3c($v0)
/* A0862C 8024172C 24640001 */  addiu     $a0, $v1, 1
/* A08630 80241730 00031C00 */  sll       $v1, $v1, 0x10
/* A08634 80241734 00031B83 */  sra       $v1, $v1, 0xe
/* A08638 80241738 A444008E */  sh        $a0, 0x8e($v0)
/* A0863C 8024173C 3C018024 */  lui       $at, %hi(nok_15_sixFloats)
/* A08640 80241740 00230821 */  addu      $at, $at, $v1
/* A08644 80241744 C4223D5C */  lwc1      $f2, %lo(nok_15_sixFloats)($at)
/* A08648 80241748 8443008E */  lh        $v1, 0x8e($v0)
/* A0864C 8024174C 46020000 */  add.s     $f0, $f0, $f2
/* A08650 80241750 28630005 */  slti      $v1, $v1, 5
/* A08654 80241754 14600003 */  bnez      $v1, .L80241764
/* A08658 80241758 E440003C */   swc1     $f0, 0x3c($v0)
/* A0865C 8024175C 2402000C */  addiu     $v0, $zero, 0xc
/* A08660 80241760 AE020070 */  sw        $v0, 0x70($s0)
.L80241764:
/* A08664 80241764 8FBF0014 */  lw        $ra, 0x14($sp)
/* A08668 80241768 8FB00010 */  lw        $s0, 0x10($sp)
/* A0866C 8024176C 03E00008 */  jr        $ra
/* A08670 80241770 27BD0018 */   addiu    $sp, $sp, 0x18
