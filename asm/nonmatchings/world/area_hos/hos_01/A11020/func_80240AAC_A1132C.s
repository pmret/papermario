.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_A1132C
/* A1132C 80240AAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A11330 80240AB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A11334 80240AB4 8C82000C */  lw        $v0, 0xc($a0)
/* A11338 80240AB8 0C0B1EAF */  jal       get_variable
/* A1133C 80240ABC 8C450000 */   lw       $a1, ($v0)
/* A11340 80240AC0 8C43000C */  lw        $v1, 0xc($v0)
/* A11344 80240AC4 3C01433E */  lui       $at, 0x433e
/* A11348 80240AC8 44810000 */  mtc1      $at, $f0
/* A1134C 80240ACC 00000000 */  nop       
/* A11350 80240AD0 E4600078 */  swc1      $f0, 0x78($v1)
/* A11354 80240AD4 8C43000C */  lw        $v1, 0xc($v0)
/* A11358 80240AD8 3C01435C */  lui       $at, 0x435c
/* A1135C 80240ADC 44810000 */  mtc1      $at, $f0
/* A11360 80240AE0 00000000 */  nop       
/* A11364 80240AE4 E460007C */  swc1      $f0, 0x7c($v1)
/* A11368 80240AE8 8C43000C */  lw        $v1, 0xc($v0)
/* A1136C 80240AEC 3C013F33 */  lui       $at, 0x3f33
/* A11370 80240AF0 34213333 */  ori       $at, $at, 0x3333
/* A11374 80240AF4 44810000 */  mtc1      $at, $f0
/* A11378 80240AF8 00000000 */  nop       
/* A1137C 80240AFC E4600068 */  swc1      $f0, 0x68($v1)
/* A11380 80240B00 8FBF0010 */  lw        $ra, 0x10($sp)
/* A11384 80240B04 24020002 */  addiu     $v0, $zero, 2
/* A11388 80240B08 03E00008 */  jr        $ra
/* A1138C 80240B0C 27BD0018 */   addiu    $sp, $sp, 0x18
