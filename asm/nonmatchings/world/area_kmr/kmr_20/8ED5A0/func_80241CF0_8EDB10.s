.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CF0_8EDB10
/* 8EDB10 80241CF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDB14 80241CF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EDB18 80241CF8 8C82000C */  lw        $v0, 0xc($a0)
/* 8EDB1C 80241CFC 0C0B210B */  jal       get_float_variable
/* 8EDB20 80241D00 8C450000 */   lw       $a1, ($v0)
/* 8EDB24 80241D04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDB28 80241D08 24020002 */  addiu     $v0, $zero, 2
/* 8EDB2C 80241D0C 3C01800B */  lui       $at, %hi(D_800B2210)
/* 8EDB30 80241D10 E4202210 */  swc1      $f0, %lo(D_800B2210)($at)
/* 8EDB34 80241D14 03E00008 */  jr        $ra
/* 8EDB38 80241D18 27BD0018 */   addiu    $sp, $sp, 0x18
