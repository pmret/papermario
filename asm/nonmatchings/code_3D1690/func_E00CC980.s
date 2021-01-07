.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CC980
/* 3D2010 E00CC980 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D2014 E00CC984 3C02E00D */  lui       $v0, %hi(D_E00CC9D0)
/* 3D2018 E00CC988 2442C9D0 */  addiu     $v0, $v0, %lo(D_E00CC9D0)
/* 3D201C E00CC98C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D2020 E00CC990 2402000A */  addiu     $v0, $zero, 0xa
/* 3D2024 E00CC994 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D2028 E00CC998 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D202C E00CC99C AFA40018 */  sw        $a0, 0x18($sp)
/* 3D2030 E00CC9A0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D2034 E00CC9A4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D2038 E00CC9A8 0C080120 */  jal       func_E0200480
/* 3D203C E00CC9AC AFA20010 */   sw       $v0, 0x10($sp)
/* 3D2040 E00CC9B0 8C430000 */  lw        $v1, ($v0)
/* 3D2044 E00CC9B4 34630002 */  ori       $v1, $v1, 2
/* 3D2048 E00CC9B8 AC430000 */  sw        $v1, ($v0)
/* 3D204C E00CC9BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D2050 E00CC9C0 03E00008 */  jr        $ra
/* 3D2054 E00CC9C4 27BD0028 */   addiu    $sp, $sp, 0x28
