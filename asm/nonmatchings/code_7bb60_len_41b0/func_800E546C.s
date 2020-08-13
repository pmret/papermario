.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E546C
/* 07E91C 800E546C 3C018011 */  lui   $at, 0x8011
/* 07E920 800E5470 C424F070 */  lwc1  $f4, -0xf90($at)
/* 07E924 800E5474 3C0142B4 */  lui   $at, 0x42b4
/* 07E928 800E5478 44810000 */  mtc1  $at, $f0
/* 07E92C 800E547C 44801000 */  mtc1  $zero, $f2
/* 07E930 800E5480 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07E934 800E5484 4604003E */  c.le.s $f0, $f4
/* 07E938 800E5488 00000000 */  nop   
/* 07E93C 800E548C 4500000A */  bc1f  .L800E54B8
/* 07E940 800E5490 AFBF0010 */   sw    $ra, 0x10($sp)
/* 07E944 800E5494 3C014387 */  lui   $at, 0x4387
/* 07E948 800E5498 44810000 */  mtc1  $at, $f0
/* 07E94C 800E549C 00000000 */  nop   
/* 07E950 800E54A0 4600203C */  c.lt.s $f4, $f0
/* 07E954 800E54A4 00000000 */  nop   
/* 07E958 800E54A8 45000003 */  bc1f  .L800E54B8
/* 07E95C 800E54AC 00000000 */   nop   
/* 07E960 800E54B0 3C014334 */  lui   $at, 0x4334
/* 07E964 800E54B4 44811000 */  mtc1  $at, $f2
.L800E54B8:
/* 07E968 800E54B8 3C01800B */  lui   $at, 0x800b
/* 07E96C 800E54BC C42C1DEC */  lwc1  $f12, 0x1dec($at)
/* 07E970 800E54C0 460C1300 */  add.s $f12, $f2, $f12
/* 07E974 800E54C4 3C0142B4 */  lui   $at, 0x42b4
/* 07E978 800E54C8 44810000 */  mtc1  $at, $f0
/* 07E97C 800E54CC 0C00A6C9 */  jal   clamp_angle
/* 07E980 800E54D0 46006300 */   add.s $f12, $f12, $f0
/* 07E984 800E54D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07E988 800E54D8 03E00008 */  jr    $ra
/* 07E98C 800E54DC 27BD0018 */   addiu $sp, $sp, 0x18

