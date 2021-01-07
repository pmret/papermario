.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0042374
/* 354B14 E0042374 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 354B18 E0042378 3C02E004 */  lui       $v0, %hi(D_E00423B8)
/* 354B1C E004237C 244223B8 */  addiu     $v0, $v0, %lo(D_E00423B8)
/* 354B20 E0042380 AFA2001C */  sw        $v0, 0x1c($sp)
/* 354B24 E0042384 2402002D */  addiu     $v0, $zero, 0x2d
/* 354B28 E0042388 AFA40018 */  sw        $a0, 0x18($sp)
/* 354B2C E004238C 27A40010 */  addiu     $a0, $sp, 0x10
/* 354B30 E0042390 AFBF0020 */  sw        $ra, 0x20($sp)
/* 354B34 E0042394 AFA00014 */  sw        $zero, 0x14($sp)
/* 354B38 E0042398 0C080120 */  jal       func_E0200480
/* 354B3C E004239C AFA20010 */   sw       $v0, 0x10($sp)
/* 354B40 E00423A0 8C430000 */  lw        $v1, ($v0)
/* 354B44 E00423A4 34630002 */  ori       $v1, $v1, 2
/* 354B48 E00423A8 AC430000 */  sw        $v1, ($v0)
/* 354B4C E00423AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 354B50 E00423B0 03E00008 */  jr        $ra
/* 354B54 E00423B4 27BD0028 */   addiu    $sp, $sp, 0x28
