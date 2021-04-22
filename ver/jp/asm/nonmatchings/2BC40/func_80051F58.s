.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80051F58
/* 2D358 80051F58 24A901D4 */  addiu     $t1, $a1, 0x1d4
/* 2D35C 80051F5C 8CA70030 */  lw        $a3, 0x30($a1)
/* 2D360 80051F60 8CA20034 */  lw        $v0, 0x34($a1)
/* 2D364 80051F64 00E2102B */  sltu      $v0, $a3, $v0
/* 2D368 80051F68 1040001A */  beqz      $v0, .L80051FD4
/* 2D36C 80051F6C 0000402D */   daddu    $t0, $zero, $zero
/* 2D370 80051F70 24A601D6 */  addiu     $a2, $a1, 0x1d6
.L80051F74:
/* 2D374 80051F74 8CA20030 */  lw        $v0, 0x30($a1)
/* 2D378 80051F78 00E21023 */  subu      $v0, $a3, $v0
/* 2D37C 80051F7C 000210C0 */  sll       $v0, $v0, 3
/* 2D380 80051F80 244207B4 */  addiu     $v0, $v0, 0x7b4
/* 2D384 80051F84 00821821 */  addu      $v1, $a0, $v0
/* 2D388 80051F88 90620007 */  lbu       $v0, 7($v1)
/* 2D38C 80051F8C 1040000C */  beqz      $v0, .L80051FC0
/* 2D390 80051F90 00000000 */   nop
/* 2D394 80051F94 90620001 */  lbu       $v0, 1($v1)
/* 2D398 80051F98 A1220000 */  sb        $v0, ($t1)
/* 2D39C 80051F9C 90620002 */  lbu       $v0, 2($v1)
/* 2D3A0 80051FA0 25080001 */  addiu     $t0, $t0, 1
/* 2D3A4 80051FA4 A0C2FFFF */  sb        $v0, -1($a2)
/* 2D3A8 80051FA8 90620006 */  lbu       $v0, 6($v1)
/* 2D3AC 80051FAC 25290004 */  addiu     $t1, $t1, 4
/* 2D3B0 80051FB0 A0C20000 */  sb        $v0, ($a2)
/* 2D3B4 80051FB4 2D020004 */  sltiu     $v0, $t0, 4
/* 2D3B8 80051FB8 10400006 */  beqz      $v0, .L80051FD4
/* 2D3BC 80051FBC 24C60004 */   addiu    $a2, $a2, 4
.L80051FC0:
/* 2D3C0 80051FC0 8CA20034 */  lw        $v0, 0x34($a1)
/* 2D3C4 80051FC4 24E70001 */  addiu     $a3, $a3, 1
/* 2D3C8 80051FC8 00E2102B */  sltu      $v0, $a3, $v0
/* 2D3CC 80051FCC 1440FFE9 */  bnez      $v0, .L80051F74
/* 2D3D0 80051FD0 00000000 */   nop
.L80051FD4:
/* 2D3D4 80051FD4 03E00008 */  jr        $ra
/* 2D3D8 80051FD8 00000000 */   nop
