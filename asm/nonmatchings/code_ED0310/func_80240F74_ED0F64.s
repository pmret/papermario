.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F74_ED0F64
/* ED0F64 80240F74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ED0F68 80240F78 AFB00010 */  sw        $s0, 0x10($sp)
/* ED0F6C 80240F7C 0080802D */  daddu     $s0, $a0, $zero
/* ED0F70 80240F80 AFBF0014 */  sw        $ra, 0x14($sp)
/* ED0F74 80240F84 8E020148 */  lw        $v0, 0x148($s0)
/* ED0F78 80240F88 0C00F92F */  jal       func_8003E4BC
/* ED0F7C 80240F8C 84440008 */   lh       $a0, 8($v0)
/* ED0F80 80240F90 9443008E */  lhu       $v1, 0x8e($v0)
/* ED0F84 80240F94 C440003C */  lwc1      $f0, 0x3c($v0)
/* ED0F88 80240F98 24640001 */  addiu     $a0, $v1, 1
/* ED0F8C 80240F9C 00031C00 */  sll       $v1, $v1, 0x10
/* ED0F90 80240FA0 00031B83 */  sra       $v1, $v1, 0xe
/* ED0F94 80240FA4 A444008E */  sh        $a0, 0x8e($v0)
/* ED0F98 80240FA8 3C018024 */  lui       $at, %hi(D_8024365C)
/* ED0F9C 80240FAC 00230821 */  addu      $at, $at, $v1
/* ED0FA0 80240FB0 C422365C */  lwc1      $f2, %lo(D_8024365C)($at)
/* ED0FA4 80240FB4 8443008E */  lh        $v1, 0x8e($v0)
/* ED0FA8 80240FB8 46020000 */  add.s     $f0, $f0, $f2
/* ED0FAC 80240FBC 28630005 */  slti      $v1, $v1, 5
/* ED0FB0 80240FC0 14600003 */  bnez      $v1, .L80240FD0
/* ED0FB4 80240FC4 E440003C */   swc1     $f0, 0x3c($v0)
/* ED0FB8 80240FC8 2402000C */  addiu     $v0, $zero, 0xc
/* ED0FBC 80240FCC AE020070 */  sw        $v0, 0x70($s0)
.L80240FD0:
/* ED0FC0 80240FD0 8FBF0014 */  lw        $ra, 0x14($sp)
/* ED0FC4 80240FD4 8FB00010 */  lw        $s0, 0x10($sp)
/* ED0FC8 80240FD8 03E00008 */  jr        $ra
/* ED0FCC 80240FDC 27BD0018 */   addiu    $sp, $sp, 0x18
