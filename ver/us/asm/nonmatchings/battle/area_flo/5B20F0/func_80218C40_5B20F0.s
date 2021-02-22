.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C40_5B20F0
/* 5B20F0 80218C40 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5B20F4 80218C44 AFB10024 */  sw        $s1, 0x24($sp)
/* 5B20F8 80218C48 0080882D */  daddu     $s1, $a0, $zero
/* 5B20FC 80218C4C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5B2100 80218C50 AFB00020 */  sw        $s0, 0x20($sp)
/* 5B2104 80218C54 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5B2108 80218C58 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5B210C 80218C5C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5B2110 80218C60 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5B2114 80218C64 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5B2118 80218C68 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5B211C 80218C6C 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2120 80218C70 8E050000 */  lw        $a1, ($s0)
/* 5B2124 80218C74 0C0B210B */  jal       get_float_variable
/* 5B2128 80218C78 26100004 */   addiu    $s0, $s0, 4
/* 5B212C 80218C7C 8E050000 */  lw        $a1, ($s0)
/* 5B2130 80218C80 26100004 */  addiu     $s0, $s0, 4
/* 5B2134 80218C84 0220202D */  daddu     $a0, $s1, $zero
/* 5B2138 80218C88 0C0B210B */  jal       get_float_variable
/* 5B213C 80218C8C 46000786 */   mov.s    $f30, $f0
/* 5B2140 80218C90 8E050000 */  lw        $a1, ($s0)
/* 5B2144 80218C94 26100004 */  addiu     $s0, $s0, 4
/* 5B2148 80218C98 0220202D */  daddu     $a0, $s1, $zero
/* 5B214C 80218C9C 0C0B210B */  jal       get_float_variable
/* 5B2150 80218CA0 46000506 */   mov.s    $f20, $f0
/* 5B2154 80218CA4 8E050000 */  lw        $a1, ($s0)
/* 5B2158 80218CA8 26100004 */  addiu     $s0, $s0, 4
/* 5B215C 80218CAC 0220202D */  daddu     $a0, $s1, $zero
/* 5B2160 80218CB0 0C0B210B */  jal       get_float_variable
/* 5B2164 80218CB4 46000706 */   mov.s    $f28, $f0
/* 5B2168 80218CB8 8E050000 */  lw        $a1, ($s0)
/* 5B216C 80218CBC 26100004 */  addiu     $s0, $s0, 4
/* 5B2170 80218CC0 0220202D */  daddu     $a0, $s1, $zero
/* 5B2174 80218CC4 0C0B210B */  jal       get_float_variable
/* 5B2178 80218CC8 46000686 */   mov.s    $f26, $f0
/* 5B217C 80218CCC 8E050000 */  lw        $a1, ($s0)
/* 5B2180 80218CD0 26100004 */  addiu     $s0, $s0, 4
/* 5B2184 80218CD4 0220202D */  daddu     $a0, $s1, $zero
/* 5B2188 80218CD8 0C0B210B */  jal       get_float_variable
/* 5B218C 80218CDC 46000606 */   mov.s    $f24, $f0
/* 5B2190 80218CE0 0220202D */  daddu     $a0, $s1, $zero
/* 5B2194 80218CE4 8E050000 */  lw        $a1, ($s0)
/* 5B2198 80218CE8 0C0B1EAF */  jal       get_variable
/* 5B219C 80218CEC 46000586 */   mov.s    $f22, $f0
/* 5B21A0 80218CF0 8E240148 */  lw        $a0, 0x148($s1)
/* 5B21A4 80218CF4 0C09A75B */  jal       get_actor
/* 5B21A8 80218CF8 0040802D */   daddu    $s0, $v0, $zero
/* 5B21AC 80218CFC 4600A521 */  cvt.d.s   $f20, $f20
/* 5B21B0 80218D00 4405F000 */  mfc1      $a1, $f30
/* 5B21B4 80218D04 3C014014 */  lui       $at, 0x4014
/* 5B21B8 80218D08 44810800 */  mtc1      $at, $f1
/* 5B21BC 80218D0C 44800000 */  mtc1      $zero, $f0
/* 5B21C0 80218D10 4407E000 */  mfc1      $a3, $f28
/* 5B21C4 80218D14 4620A500 */  add.d     $f20, $f20, $f0
/* 5B21C8 80218D18 0000202D */  daddu     $a0, $zero, $zero
/* 5B21CC 80218D1C AFB0001C */  sw        $s0, 0x1c($sp)
/* 5B21D0 80218D20 4620A520 */  cvt.s.d   $f20, $f20
/* 5B21D4 80218D24 4406A000 */  mfc1      $a2, $f20
/* 5B21D8 80218D28 0040802D */  daddu     $s0, $v0, $zero
/* 5B21DC 80218D2C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 5B21E0 80218D30 E7B80014 */  swc1      $f24, 0x14($sp)
/* 5B21E4 80218D34 0C01BFD4 */  jal       func_8006FF50
/* 5B21E8 80218D38 E7B60018 */   swc1     $f22, 0x18($sp)
/* 5B21EC 80218D3C 0040202D */  daddu     $a0, $v0, $zero
/* 5B21F0 80218D40 82030210 */  lb        $v1, 0x210($s0)
/* 5B21F4 80218D44 2402000A */  addiu     $v0, $zero, 0xa
/* 5B21F8 80218D48 14620007 */  bne       $v1, $v0, .L80218D68
/* 5B21FC 80218D4C 00000000 */   nop
/* 5B2200 80218D50 8C82000C */  lw        $v0, 0xc($a0)
/* 5B2204 80218D54 3C013ECC */  lui       $at, 0x3ecc
/* 5B2208 80218D58 3421CCCD */  ori       $at, $at, 0xcccd
/* 5B220C 80218D5C 44810000 */  mtc1      $at, $f0
/* 5B2210 80218D60 00000000 */  nop
/* 5B2214 80218D64 E4400028 */  swc1      $f0, 0x28($v0)
.L80218D68:
/* 5B2218 80218D68 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B221C 80218D6C 8FB10024 */  lw        $s1, 0x24($sp)
/* 5B2220 80218D70 8FB00020 */  lw        $s0, 0x20($sp)
/* 5B2224 80218D74 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5B2228 80218D78 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5B222C 80218D7C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5B2230 80218D80 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5B2234 80218D84 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5B2238 80218D88 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5B223C 80218D8C 24020002 */  addiu     $v0, $zero, 2
/* 5B2240 80218D90 03E00008 */  jr        $ra
/* 5B2244 80218D94 27BD0060 */   addiu    $sp, $sp, 0x60
