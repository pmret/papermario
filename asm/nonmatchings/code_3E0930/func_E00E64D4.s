.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E64D4
/* 3E0E04 E00E64D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3E0E08 E00E64D8 3C02E00E */  lui       $v0, %hi(D_E00E6524)
/* 3E0E0C E00E64DC 24426524 */  addiu     $v0, $v0, %lo(D_E00E6524)
/* 3E0E10 E00E64E0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E0E14 E00E64E4 2402000A */  addiu     $v0, $zero, 0xa
/* 3E0E18 E00E64E8 AFA20014 */  sw        $v0, 0x14($sp)
/* 3E0E1C E00E64EC 24020001 */  addiu     $v0, $zero, 1
/* 3E0E20 E00E64F0 AFA40018 */  sw        $a0, 0x18($sp)
/* 3E0E24 E00E64F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E0E28 E00E64F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3E0E2C E00E64FC 0C080120 */  jal       func_E0200480
/* 3E0E30 E00E6500 AFA20010 */   sw       $v0, 0x10($sp)
/* 3E0E34 E00E6504 8C430000 */  lw        $v1, ($v0)
/* 3E0E38 E00E6508 34630002 */  ori       $v1, $v1, 2
/* 3E0E3C E00E650C AC430000 */  sw        $v1, ($v0)
/* 3E0E40 E00E6510 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3E0E44 E00E6514 03E00008 */  jr        $ra
/* 3E0E48 E00E6518 27BD0028 */   addiu    $sp, $sp, 0x28
