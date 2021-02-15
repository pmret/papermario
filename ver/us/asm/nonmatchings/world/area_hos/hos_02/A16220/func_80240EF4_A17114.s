.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF4_A17114
/* A17114 80240EF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A17118 80240EF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1711C 80240EFC 8C82000C */  lw        $v0, 0xc($a0)
/* A17120 80240F00 0C0B1EAF */  jal       get_variable
/* A17124 80240F04 8C450000 */   lw       $a1, ($v0)
/* A17128 80240F08 0040182D */  daddu     $v1, $v0, $zero
/* A1712C 80240F0C 8C62000C */  lw        $v0, 0xc($v1)
/* A17130 80240F10 3C01433E */  lui       $at, 0x433e
/* A17134 80240F14 44810000 */  mtc1      $at, $f0
/* A17138 80240F18 00000000 */  nop
/* A1713C 80240F1C E4400078 */  swc1      $f0, 0x78($v0)
/* A17140 80240F20 8C62000C */  lw        $v0, 0xc($v1)
/* A17144 80240F24 3C01435C */  lui       $at, 0x435c
/* A17148 80240F28 44810000 */  mtc1      $at, $f0
/* A1714C 80240F2C 00000000 */  nop
/* A17150 80240F30 E440007C */  swc1      $f0, 0x7c($v0)
/* A17154 80240F34 8C64000C */  lw        $a0, 0xc($v1)
/* A17158 80240F38 3C013F33 */  lui       $at, 0x3f33
/* A1715C 80240F3C 34213333 */  ori       $at, $at, 0x3333
/* A17160 80240F40 44810000 */  mtc1      $at, $f0
/* A17164 80240F44 00000000 */  nop
/* A17168 80240F48 E4800068 */  swc1      $f0, 0x68($a0)
/* A1716C 80240F4C 8C64000C */  lw        $a0, 0xc($v1)
/* A17170 80240F50 240300FF */  addiu     $v1, $zero, 0xff
/* A17174 80240F54 AC830038 */  sw        $v1, 0x38($a0)
/* A17178 80240F58 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1717C 80240F5C 24020002 */  addiu     $v0, $zero, 2
/* A17180 80240F60 03E00008 */  jr        $ra
/* A17184 80240F64 27BD0018 */   addiu    $sp, $sp, 0x18
