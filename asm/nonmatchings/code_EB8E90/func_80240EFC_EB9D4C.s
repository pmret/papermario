.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EFC_EB9D4C
/* EB9D4C 80240EFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB9D50 80240F00 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB9D54 80240F04 0C03C767 */  jal       func_800F1D9C
/* EB9D58 80240F08 24040006 */   addiu    $a0, $zero, 6
/* EB9D5C 80240F0C 3C028011 */  lui       $v0, %hi(D_80117840)
/* EB9D60 80240F10 24427840 */  addiu     $v0, $v0, %lo(D_80117840)
/* EB9D64 80240F14 90430003 */  lbu       $v1, 3($v0)
/* EB9D68 80240F18 90440006 */  lbu       $a0, 6($v0)
/* EB9D6C 80240F1C A0430002 */  sb        $v1, 2($v0)
/* EB9D70 80240F20 0C03C5CC */  jal       func_800F1730
/* EB9D74 80240F24 A0440005 */   sb       $a0, 5($v0)
/* EB9D78 80240F28 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB9D7C 80240F2C 24020002 */  addiu     $v0, $zero, 2
/* EB9D80 80240F30 03E00008 */  jr        $ra
/* EB9D84 80240F34 27BD0018 */   addiu    $sp, $sp, 0x18
/* EB9D88 80240F38 00000000 */  nop       
/* EB9D8C 80240F3C 00000000 */  nop       
