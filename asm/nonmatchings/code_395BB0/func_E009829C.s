.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E009829C
/* 395E4C E009829C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 395E50 E00982A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 395E54 E00982A4 8C83000C */  lw        $v1, 0xc($a0)
/* 395E58 E00982A8 3C02E00A */  lui       $v0, %hi(D_E00982EC)
/* 395E5C E00982AC 244282EC */  addiu     $v0, $v0, %lo(D_E00982EC)
/* 395E60 E00982B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 395E64 E00982B4 2402002D */  addiu     $v0, $zero, 0x2d
/* 395E68 E00982B8 AFA40018 */  sw        $a0, 0x18($sp)
/* 395E6C E00982BC C460000C */  lwc1      $f0, 0xc($v1)
/* 395E70 E00982C0 AFA20010 */  sw        $v0, 0x10($sp)
/* 395E74 E00982C4 4600008D */  trunc.w.s $f2, $f0
/* 395E78 E00982C8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 395E7C E00982CC 0C080120 */  jal       func_E0200480
/* 395E80 E00982D0 27A40010 */   addiu    $a0, $sp, 0x10
/* 395E84 E00982D4 8C430000 */  lw        $v1, ($v0)
/* 395E88 E00982D8 34630002 */  ori       $v1, $v1, 2
/* 395E8C E00982DC AC430000 */  sw        $v1, ($v0)
/* 395E90 E00982E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 395E94 E00982E4 03E00008 */  jr        $ra
/* 395E98 E00982E8 27BD0028 */   addiu    $sp, $sp, 0x28
