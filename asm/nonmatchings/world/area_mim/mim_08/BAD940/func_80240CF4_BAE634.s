.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CF4_BAE634
/* BAE634 80240CF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAE638 80240CF8 AFB00010 */  sw        $s0, 0x10($sp)
/* BAE63C 80240CFC 0080802D */  daddu     $s0, $a0, $zero
/* BAE640 80240D00 AFBF0014 */  sw        $ra, 0x14($sp)
/* BAE644 80240D04 8E020148 */  lw        $v0, 0x148($s0)
/* BAE648 80240D08 0C00EABB */  jal       get_npc_unsafe
/* BAE64C 80240D0C 84440008 */   lh       $a0, 8($v0)
/* BAE650 80240D10 9443008E */  lhu       $v1, 0x8e($v0)
/* BAE654 80240D14 C440003C */  lwc1      $f0, 0x3c($v0)
/* BAE658 80240D18 24640001 */  addiu     $a0, $v1, 1
/* BAE65C 80240D1C 00031C00 */  sll       $v1, $v1, 0x10
/* BAE660 80240D20 00031B83 */  sra       $v1, $v1, 0xe
/* BAE664 80240D24 A444008E */  sh        $a0, 0x8e($v0)
/* BAE668 80240D28 3C018024 */  lui       $at, %hi(D_802443C0_BB1D00)
/* BAE66C 80240D2C 00230821 */  addu      $at, $at, $v1
/* BAE670 80240D30 C42243C0 */  lwc1      $f2, %lo(D_802443C0_BB1D00)($at)
/* BAE674 80240D34 8443008E */  lh        $v1, 0x8e($v0)
/* BAE678 80240D38 46020000 */  add.s     $f0, $f0, $f2
/* BAE67C 80240D3C 28630005 */  slti      $v1, $v1, 5
/* BAE680 80240D40 14600003 */  bnez      $v1, .L80240D50
/* BAE684 80240D44 E440003C */   swc1     $f0, 0x3c($v0)
/* BAE688 80240D48 2402000C */  addiu     $v0, $zero, 0xc
/* BAE68C 80240D4C AE020070 */  sw        $v0, 0x70($s0)
.L80240D50:
/* BAE690 80240D50 8FBF0014 */  lw        $ra, 0x14($sp)
/* BAE694 80240D54 8FB00010 */  lw        $s0, 0x10($sp)
/* BAE698 80240D58 03E00008 */  jr        $ra
/* BAE69C 80240D5C 27BD0018 */   addiu    $sp, $sp, 0x18
