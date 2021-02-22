.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B10_A11390
/* A11390 80240B10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A11394 80240B14 AFBF0010 */  sw        $ra, 0x10($sp)
/* A11398 80240B18 8C82000C */  lw        $v0, 0xc($a0)
/* A1139C 80240B1C 0C0B1EAF */  jal       get_variable
/* A113A0 80240B20 8C450000 */   lw       $a1, ($v0)
/* A113A4 80240B24 8C43000C */  lw        $v1, 0xc($v0)
/* A113A8 80240B28 3C01432A */  lui       $at, 0x432a
/* A113AC 80240B2C 44810000 */  mtc1      $at, $f0
/* A113B0 80240B30 00000000 */  nop
/* A113B4 80240B34 E4600078 */  swc1      $f0, 0x78($v1)
/* A113B8 80240B38 8C43000C */  lw        $v1, 0xc($v0)
/* A113BC 80240B3C E460007C */  swc1      $f0, 0x7c($v1)
/* A113C0 80240B40 8C43000C */  lw        $v1, 0xc($v0)
/* A113C4 80240B44 3C014000 */  lui       $at, 0x4000
/* A113C8 80240B48 44810000 */  mtc1      $at, $f0
/* A113CC 80240B4C 00000000 */  nop
/* A113D0 80240B50 E4600068 */  swc1      $f0, 0x68($v1)
/* A113D4 80240B54 8FBF0010 */  lw        $ra, 0x10($sp)
/* A113D8 80240B58 24020002 */  addiu     $v0, $zero, 2
/* A113DC 80240B5C 03E00008 */  jr        $ra
/* A113E0 80240B60 27BD0018 */   addiu    $sp, $sp, 0x18
