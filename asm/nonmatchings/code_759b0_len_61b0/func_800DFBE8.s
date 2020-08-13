.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DFBE8
/* 079098 800DFBE8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07909C 800DFBEC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0790A0 800DFBF0 0C03968B */  jal   func_800E5A2C
/* 0790A4 800DFBF4 00000000 */   nop   
/* 0790A8 800DFBF8 0C038D8F */  jal   func_800E363C
/* 0790AC 800DFBFC 00000000 */   nop   
/* 0790B0 800DFC00 0C0392EE */  jal   func_800E4BB8
/* 0790B4 800DFC04 00000000 */   nop   
/* 0790B8 800DFC08 3C04800F */  lui   $a0, 0x800f
/* 0790BC 800DFC0C 8C847B30 */  lw    $a0, 0x7b30($a0)
/* 0790C0 800DFC10 8C820000 */  lw    $v0, ($a0)
/* 0790C4 800DFC14 3C030400 */  lui   $v1, 0x400
/* 0790C8 800DFC18 00431024 */  and   $v0, $v0, $v1
/* 0790CC 800DFC1C 14400009 */  bnez  $v0, .L800DFC44
/* 0790D0 800DFC20 00000000 */   nop   
/* 0790D4 800DFC24 C4800028 */  lwc1  $f0, 0x28($a0)
/* 0790D8 800DFC28 3C02800B */  lui   $v0, 0x800b
/* 0790DC 800DFC2C 24421D80 */  addiu $v0, $v0, 0x1d80
/* 0790E0 800DFC30 E4400060 */  swc1  $f0, 0x60($v0)
/* 0790E4 800DFC34 C480002C */  lwc1  $f0, 0x2c($a0)
/* 0790E8 800DFC38 E4400064 */  swc1  $f0, 0x64($v0)
/* 0790EC 800DFC3C C4800030 */  lwc1  $f0, 0x30($a0)
/* 0790F0 800DFC40 E4400068 */  swc1  $f0, 0x68($v0)
.L800DFC44:
/* 0790F4 800DFC44 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0790F8 800DFC48 03E00008 */  jr    $ra
/* 0790FC 800DFC4C 27BD0018 */   addiu $sp, $sp, 0x18

