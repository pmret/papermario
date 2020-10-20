.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EA8_97E978
/* 97E978 80240EA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97E97C 80240EAC AFB00010 */  sw        $s0, 0x10($sp)
/* 97E980 80240EB0 0080802D */  daddu     $s0, $a0, $zero
/* 97E984 80240EB4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 97E988 80240EB8 AFB20018 */  sw        $s2, 0x18($sp)
/* 97E98C 80240EBC AFB10014 */  sw        $s1, 0x14($sp)
/* 97E990 80240EC0 8E020148 */  lw        $v0, 0x148($s0)
/* 97E994 80240EC4 00A0882D */  daddu     $s1, $a1, $zero
/* 97E998 80240EC8 84440008 */  lh        $a0, 8($v0)
/* 97E99C 80240ECC 0C00EABB */  jal       get_npc_unsafe
/* 97E9A0 80240ED0 00C0902D */   daddu    $s2, $a2, $zero
/* 97E9A4 80240ED4 0200202D */  daddu     $a0, $s0, $zero
/* 97E9A8 80240ED8 0040802D */  daddu     $s0, $v0, $zero
/* 97E9AC 80240EDC 0220282D */  daddu     $a1, $s1, $zero
/* 97E9B0 80240EE0 0C0127DF */  jal       func_80049F7C
/* 97E9B4 80240EE4 0240302D */   daddu    $a2, $s2, $zero
/* 97E9B8 80240EE8 0C00A67F */  jal       rand_int
/* 97E9BC 80240EEC 24040005 */   addiu    $a0, $zero, 5
/* 97E9C0 80240EF0 3C014014 */  lui       $at, 0x4014
/* 97E9C4 80240EF4 44811800 */  mtc1      $at, $f3
/* 97E9C8 80240EF8 44801000 */  mtc1      $zero, $f2
/* 97E9CC 80240EFC 44820000 */  mtc1      $v0, $f0
/* 97E9D0 80240F00 00000000 */  nop       
/* 97E9D4 80240F04 46800021 */  cvt.d.w   $f0, $f0
/* 97E9D8 80240F08 46220000 */  add.d     $f0, $f0, $f2
/* 97E9DC 80240F0C 3C013FC0 */  lui       $at, 0x3fc0
/* 97E9E0 80240F10 44811000 */  mtc1      $at, $f2
/* 97E9E4 80240F14 00000000 */  nop       
/* 97E9E8 80240F18 E6020014 */  swc1      $f2, 0x14($s0)
/* 97E9EC 80240F1C 46200020 */  cvt.s.d   $f0, $f0
/* 97E9F0 80240F20 E600001C */  swc1      $f0, 0x1c($s0)
/* 97E9F4 80240F24 8FBF001C */  lw        $ra, 0x1c($sp)
/* 97E9F8 80240F28 8FB20018 */  lw        $s2, 0x18($sp)
/* 97E9FC 80240F2C 8FB10014 */  lw        $s1, 0x14($sp)
/* 97EA00 80240F30 8FB00010 */  lw        $s0, 0x10($sp)
/* 97EA04 80240F34 03E00008 */  jr        $ra
/* 97EA08 80240F38 27BD0020 */   addiu    $sp, $sp, 0x20
