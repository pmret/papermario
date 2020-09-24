.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DDCEC
/* 7719C 800DDCEC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 771A0 800DDCF0 AFB10034 */  sw        $s1, 0x34($sp)
/* 771A4 800DDCF4 00A0882D */  daddu     $s1, $a1, $zero
/* 771A8 800DDCF8 AFBF0038 */  sw        $ra, 0x38($sp)
/* 771AC 800DDCFC AFB00030 */  sw        $s0, 0x30($sp)
/* 771B0 800DDD00 C6200000 */  lwc1      $f0, ($s1)
/* 771B4 800DDD04 C7A40050 */  lwc1      $f4, 0x50($sp)
/* 771B8 800DDD08 C7A80054 */  lwc1      $f8, 0x54($sp)
/* 771BC 800DDD0C C7A6005C */  lwc1      $f6, 0x5c($sp)
/* 771C0 800DDD10 3C014120 */  lui       $at, 0x4120
/* 771C4 800DDD14 342128F6 */  ori       $at, $at, 0x28f6
/* 771C8 800DDD18 44811000 */  mtc1      $at, $f2
/* 771CC 800DDD1C E7A00020 */  swc1      $f0, 0x20($sp)
/* 771D0 800DDD20 C4C00000 */  lwc1      $f0, ($a2)
/* 771D4 800DDD24 00E0802D */  daddu     $s0, $a3, $zero
/* 771D8 800DDD28 46020000 */  add.s     $f0, $f0, $f2
/* 771DC 800DDD2C 3C013F00 */  lui       $at, 0x3f00
/* 771E0 800DDD30 44811000 */  mtc1      $at, $f2
/* 771E4 800DDD34 27A50020 */  addiu     $a1, $sp, 0x20
/* 771E8 800DDD38 46023182 */  mul.s     $f6, $f6, $f2
/* 771EC 800DDD3C 00000000 */  nop       
/* 771F0 800DDD40 27A70028 */  addiu     $a3, $sp, 0x28
/* 771F4 800DDD44 27A60024 */  addiu     $a2, $sp, 0x24
/* 771F8 800DDD48 E7A00024 */  swc1      $f0, 0x24($sp)
/* 771FC 800DDD4C C6000000 */  lwc1      $f0, ($s0)
/* 77200 800DDD50 46002105 */  abs.s     $f4, $f4
/* 77204 800DDD54 E7A00028 */  swc1      $f0, 0x28($sp)
/* 77208 800DDD58 E7A40010 */  swc1      $f4, 0x10($sp)
/* 7720C 800DDD5C E7A80014 */  swc1      $f8, 0x14($sp)
/* 77210 800DDD60 0C03763F */  jal       func_800DD8FC
/* 77214 800DDD64 E7A60018 */   swc1     $f6, 0x18($sp)
/* 77218 800DDD68 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7721C 800DDD6C E6200000 */  swc1      $f0, ($s1)
/* 77220 800DDD70 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 77224 800DDD74 00021027 */  nor       $v0, $zero, $v0
/* 77228 800DDD78 E6000000 */  swc1      $f0, ($s0)
/* 7722C 800DDD7C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 77230 800DDD80 8FB10034 */  lw        $s1, 0x34($sp)
/* 77234 800DDD84 8FB00030 */  lw        $s0, 0x30($sp)
/* 77238 800DDD88 000217C2 */  srl       $v0, $v0, 0x1f
/* 7723C 800DDD8C 03E00008 */  jr        $ra
/* 77240 800DDD90 27BD0040 */   addiu    $sp, $sp, 0x40
