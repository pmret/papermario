.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DDC44
/* 0770F4 800DDC44 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0770F8 800DDC48 AFB10034 */  sw    $s1, 0x34($sp)
/* 0770FC 800DDC4C 00A0882D */  daddu $s1, $a1, $zero
/* 077100 800DDC50 AFBF0038 */  sw    $ra, 0x38($sp)
/* 077104 800DDC54 AFB00030 */  sw    $s0, 0x30($sp)
/* 077108 800DDC58 C6200000 */  lwc1  $f0, ($s1)
/* 07710C 800DDC5C C7A40050 */  lwc1  $f4, 0x50($sp)
/* 077110 800DDC60 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 077114 800DDC64 C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 077118 800DDC68 3C014120 */  lui   $at, 0x4120
/* 07711C 800DDC6C 342128F6 */  ori   $at, $at, 0x28f6
/* 077120 800DDC70 44811000 */  mtc1  $at, $f2
/* 077124 800DDC74 E7A00020 */  swc1  $f0, 0x20($sp)
/* 077128 800DDC78 C4C00000 */  lwc1  $f0, ($a2)
/* 07712C 800DDC7C 00E0802D */  daddu $s0, $a3, $zero
/* 077130 800DDC80 46020000 */  add.s $f0, $f0, $f2
/* 077134 800DDC84 3C013F00 */  lui   $at, 0x3f00
/* 077138 800DDC88 44811000 */  mtc1  $at, $f2
/* 07713C 800DDC8C 27A50020 */  addiu $a1, $sp, 0x20
/* 077140 800DDC90 46023182 */  mul.s $f6, $f6, $f2
/* 077144 800DDC94 00000000 */  nop   
/* 077148 800DDC98 27A70028 */  addiu $a3, $sp, 0x28
/* 07714C 800DDC9C 27A60024 */  addiu $a2, $sp, 0x24
/* 077150 800DDCA0 E7A00024 */  swc1  $f0, 0x24($sp)
/* 077154 800DDCA4 C6000000 */  lwc1  $f0, ($s0)
/* 077158 800DDCA8 46002105 */  abs.s $f4, $f4
/* 07715C 800DDCAC E7A00028 */  swc1  $f0, 0x28($sp)
/* 077160 800DDCB0 E7A40010 */  swc1  $f4, 0x10($sp)
/* 077164 800DDCB4 E7A80014 */  swc1  $f8, 0x14($sp)
/* 077168 800DDCB8 0C037586 */  jal   func_800DD618
/* 07716C 800DDCBC E7A60018 */   swc1  $f6, 0x18($sp)
/* 077170 800DDCC0 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 077174 800DDCC4 E6200000 */  swc1  $f0, ($s1)
/* 077178 800DDCC8 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 07717C 800DDCCC 00021027 */  nor   $v0, $zero, $v0
/* 077180 800DDCD0 E6000000 */  swc1  $f0, ($s0)
/* 077184 800DDCD4 8FBF0038 */  lw    $ra, 0x38($sp)
/* 077188 800DDCD8 8FB10034 */  lw    $s1, 0x34($sp)
/* 07718C 800DDCDC 8FB00030 */  lw    $s0, 0x30($sp)
/* 077190 800DDCE0 000217C2 */  srl   $v0, $v0, 0x1f
/* 077194 800DDCE4 03E00008 */  jr    $ra
/* 077198 800DDCE8 27BD0040 */   addiu $sp, $sp, 0x40

/* 07719C 800DDCEC 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0771A0 800DDCF0 AFB10034 */  sw    $s1, 0x34($sp)
/* 0771A4 800DDCF4 00A0882D */  daddu $s1, $a1, $zero
/* 0771A8 800DDCF8 AFBF0038 */  sw    $ra, 0x38($sp)
/* 0771AC 800DDCFC AFB00030 */  sw    $s0, 0x30($sp)
/* 0771B0 800DDD00 C6200000 */  lwc1  $f0, ($s1)
/* 0771B4 800DDD04 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 0771B8 800DDD08 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 0771BC 800DDD0C C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 0771C0 800DDD10 3C014120 */  lui   $at, 0x4120
/* 0771C4 800DDD14 342128F6 */  ori   $at, $at, 0x28f6
/* 0771C8 800DDD18 44811000 */  mtc1  $at, $f2
/* 0771CC 800DDD1C E7A00020 */  swc1  $f0, 0x20($sp)
/* 0771D0 800DDD20 C4C00000 */  lwc1  $f0, ($a2)
/* 0771D4 800DDD24 00E0802D */  daddu $s0, $a3, $zero
/* 0771D8 800DDD28 46020000 */  add.s $f0, $f0, $f2
/* 0771DC 800DDD2C 3C013F00 */  lui   $at, 0x3f00
/* 0771E0 800DDD30 44811000 */  mtc1  $at, $f2
/* 0771E4 800DDD34 27A50020 */  addiu $a1, $sp, 0x20
/* 0771E8 800DDD38 46023182 */  mul.s $f6, $f6, $f2
/* 0771EC 800DDD3C 00000000 */  nop   
/* 0771F0 800DDD40 27A70028 */  addiu $a3, $sp, 0x28
/* 0771F4 800DDD44 27A60024 */  addiu $a2, $sp, 0x24
/* 0771F8 800DDD48 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0771FC 800DDD4C C6000000 */  lwc1  $f0, ($s0)
/* 077200 800DDD50 46002105 */  abs.s $f4, $f4
/* 077204 800DDD54 E7A00028 */  swc1  $f0, 0x28($sp)
/* 077208 800DDD58 E7A40010 */  swc1  $f4, 0x10($sp)
/* 07720C 800DDD5C E7A80014 */  swc1  $f8, 0x14($sp)
/* 077210 800DDD60 0C03763F */  jal   func_800DD8FC
/* 077214 800DDD64 E7A60018 */   swc1  $f6, 0x18($sp)
/* 077218 800DDD68 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07721C 800DDD6C E6200000 */  swc1  $f0, ($s1)
/* 077220 800DDD70 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 077224 800DDD74 00021027 */  nor   $v0, $zero, $v0
/* 077228 800DDD78 E6000000 */  swc1  $f0, ($s0)
/* 07722C 800DDD7C 8FBF0038 */  lw    $ra, 0x38($sp)
/* 077230 800DDD80 8FB10034 */  lw    $s1, 0x34($sp)
/* 077234 800DDD84 8FB00030 */  lw    $s0, 0x30($sp)
/* 077238 800DDD88 000217C2 */  srl   $v0, $v0, 0x1f
/* 07723C 800DDD8C 03E00008 */  jr    $ra
/* 077240 800DDD90 27BD0040 */   addiu $sp, $sp, 0x40

