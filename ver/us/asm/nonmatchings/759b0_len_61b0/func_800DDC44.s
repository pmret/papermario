.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DDC44
/* 770F4 800DDC44 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 770F8 800DDC48 AFB10034 */  sw        $s1, 0x34($sp)
/* 770FC 800DDC4C 00A0882D */  daddu     $s1, $a1, $zero
/* 77100 800DDC50 AFBF0038 */  sw        $ra, 0x38($sp)
/* 77104 800DDC54 AFB00030 */  sw        $s0, 0x30($sp)
/* 77108 800DDC58 C6200000 */  lwc1      $f0, ($s1)
/* 7710C 800DDC5C C7A40050 */  lwc1      $f4, 0x50($sp)
/* 77110 800DDC60 C7A80054 */  lwc1      $f8, 0x54($sp)
/* 77114 800DDC64 C7A6005C */  lwc1      $f6, 0x5c($sp)
/* 77118 800DDC68 3C014120 */  lui       $at, 0x4120
/* 7711C 800DDC6C 342128F6 */  ori       $at, $at, 0x28f6
/* 77120 800DDC70 44811000 */  mtc1      $at, $f2
/* 77124 800DDC74 E7A00020 */  swc1      $f0, 0x20($sp)
/* 77128 800DDC78 C4C00000 */  lwc1      $f0, ($a2)
/* 7712C 800DDC7C 00E0802D */  daddu     $s0, $a3, $zero
/* 77130 800DDC80 46020000 */  add.s     $f0, $f0, $f2
/* 77134 800DDC84 3C013F00 */  lui       $at, 0x3f00
/* 77138 800DDC88 44811000 */  mtc1      $at, $f2
/* 7713C 800DDC8C 27A50020 */  addiu     $a1, $sp, 0x20
/* 77140 800DDC90 46023182 */  mul.s     $f6, $f6, $f2
/* 77144 800DDC94 00000000 */  nop
/* 77148 800DDC98 27A70028 */  addiu     $a3, $sp, 0x28
/* 7714C 800DDC9C 27A60024 */  addiu     $a2, $sp, 0x24
/* 77150 800DDCA0 E7A00024 */  swc1      $f0, 0x24($sp)
/* 77154 800DDCA4 C6000000 */  lwc1      $f0, ($s0)
/* 77158 800DDCA8 46002105 */  abs.s     $f4, $f4
/* 7715C 800DDCAC E7A00028 */  swc1      $f0, 0x28($sp)
/* 77160 800DDCB0 E7A40010 */  swc1      $f4, 0x10($sp)
/* 77164 800DDCB4 E7A80014 */  swc1      $f8, 0x14($sp)
/* 77168 800DDCB8 0C037586 */  jal       func_800DD618
/* 7716C 800DDCBC E7A60018 */   swc1     $f6, 0x18($sp)
/* 77170 800DDCC0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 77174 800DDCC4 E6200000 */  swc1      $f0, ($s1)
/* 77178 800DDCC8 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 7717C 800DDCCC 00021027 */  nor       $v0, $zero, $v0
/* 77180 800DDCD0 E6000000 */  swc1      $f0, ($s0)
/* 77184 800DDCD4 8FBF0038 */  lw        $ra, 0x38($sp)
/* 77188 800DDCD8 8FB10034 */  lw        $s1, 0x34($sp)
/* 7718C 800DDCDC 8FB00030 */  lw        $s0, 0x30($sp)
/* 77190 800DDCE0 000217C2 */  srl       $v0, $v0, 0x1f
/* 77194 800DDCE4 03E00008 */  jr        $ra
/* 77198 800DDCE8 27BD0040 */   addiu    $sp, $sp, 0x40
