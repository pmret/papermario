.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel MultiplyByActorScale
/* 1828BC 80253FDC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1828C0 80253FE0 AFB10014 */  sw    $s1, 0x14($sp)
/* 1828C4 80253FE4 0080882D */  daddu $s1, $a0, $zero
/* 1828C8 80253FE8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1828CC 80253FEC AFB20018 */  sw    $s2, 0x18($sp)
/* 1828D0 80253FF0 AFB00010 */  sw    $s0, 0x10($sp)
/* 1828D4 80253FF4 8E240148 */  lw    $a0, 0x148($s1)
/* 1828D8 80253FF8 0C09A75B */  jal   get_actor
/* 1828DC 80253FFC 8E32000C */   lw    $s2, 0xc($s1)
/* 1828E0 80254000 0220202D */  daddu $a0, $s1, $zero
/* 1828E4 80254004 8E450000 */  lw    $a1, ($s2)
/* 1828E8 80254008 0C0B210B */  jal   get_float_variable
/* 1828EC 8025400C 0040802D */   daddu $s0, $v0, $zero
/* 1828F0 80254010 C6020188 */  lwc1  $f2, 0x188($s0)
/* 1828F4 80254014 46020002 */  mul.s $f0, $f0, $f2
/* 1828F8 80254018 00000000 */  nop   
/* 1828FC 8025401C 8E450000 */  lw    $a1, ($s2)
/* 182900 80254020 44060000 */  mfc1  $a2, $f0
/* 182904 80254024 0C0B2190 */  jal   set_float_variable
/* 182908 80254028 0220202D */   daddu $a0, $s1, $zero
/* 18290C 8025402C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 182910 80254030 8FB20018 */  lw    $s2, 0x18($sp)
/* 182914 80254034 8FB10014 */  lw    $s1, 0x14($sp)
/* 182918 80254038 8FB00010 */  lw    $s0, 0x10($sp)
/* 18291C 8025403C 24020002 */  addiu $v0, $zero, 2
/* 182920 80254040 03E00008 */  jr    $ra
/* 182924 80254044 27BD0020 */   addiu $sp, $sp, 0x20

