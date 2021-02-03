.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F74_CB5F74
/* CB5F74 80240F74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB5F78 80240F78 AFB00010 */  sw        $s0, 0x10($sp)
/* CB5F7C 80240F7C 0080802D */  daddu     $s0, $a0, $zero
/* CB5F80 80240F80 AFBF0014 */  sw        $ra, 0x14($sp)
/* CB5F84 80240F84 8E020148 */  lw        $v0, 0x148($s0)
/* CB5F88 80240F88 0C00EABB */  jal       get_npc_unsafe
/* CB5F8C 80240F8C 84440008 */   lh       $a0, 8($v0)
/* CB5F90 80240F90 9443008E */  lhu       $v1, 0x8e($v0)
/* CB5F94 80240F94 C440003C */  lwc1      $f0, 0x3c($v0)
/* CB5F98 80240F98 24640001 */  addiu     $a0, $v1, 1
/* CB5F9C 80240F9C 00031C00 */  sll       $v1, $v1, 0x10
/* CB5FA0 80240FA0 00031B83 */  sra       $v1, $v1, 0xe
/* CB5FA4 80240FA4 A444008E */  sh        $a0, 0x8e($v0)
/* CB5FA8 80240FA8 3C018024 */  lui       $at, %hi(D_8024362C_CB862C)
/* CB5FAC 80240FAC 00230821 */  addu      $at, $at, $v1
/* CB5FB0 80240FB0 C422362C */  lwc1      $f2, %lo(D_8024362C_CB862C)($at)
/* CB5FB4 80240FB4 8443008E */  lh        $v1, 0x8e($v0)
/* CB5FB8 80240FB8 46020000 */  add.s     $f0, $f0, $f2
/* CB5FBC 80240FBC 28630005 */  slti      $v1, $v1, 5
/* CB5FC0 80240FC0 14600003 */  bnez      $v1, .L80240FD0
/* CB5FC4 80240FC4 E440003C */   swc1     $f0, 0x3c($v0)
/* CB5FC8 80240FC8 2402000C */  addiu     $v0, $zero, 0xc
/* CB5FCC 80240FCC AE020070 */  sw        $v0, 0x70($s0)
.L80240FD0:
/* CB5FD0 80240FD0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CB5FD4 80240FD4 8FB00010 */  lw        $s0, 0x10($sp)
/* CB5FD8 80240FD8 03E00008 */  jr        $ra
/* CB5FDC 80240FDC 27BD0018 */   addiu    $sp, $sp, 0x18
