.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CE428
/* 3D2EE8 E00CE428 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D2EEC E00CE42C 3C02E00D */  lui       $v0, %hi(func_E00CE478)
/* 3D2EF0 E00CE430 2442E478 */  addiu     $v0, $v0, %lo(func_E00CE478)
/* 3D2EF4 E00CE434 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D2EF8 E00CE438 2402000A */  addiu     $v0, $zero, 0xa
/* 3D2EFC E00CE43C AFA20014 */  sw        $v0, 0x14($sp)
/* 3D2F00 E00CE440 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D2F04 E00CE444 AFA40018 */  sw        $a0, 0x18($sp)
/* 3D2F08 E00CE448 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D2F0C E00CE44C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D2F10 E00CE450 0C080120 */  jal       func_E0200480
/* 3D2F14 E00CE454 AFA20010 */   sw       $v0, 0x10($sp)
/* 3D2F18 E00CE458 8C430000 */  lw        $v1, ($v0)
/* 3D2F1C E00CE45C 34630002 */  ori       $v1, $v1, 2
/* 3D2F20 E00CE460 AC430000 */  sw        $v1, ($v0)
/* 3D2F24 E00CE464 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D2F28 E00CE468 03E00008 */  jr        $ra
/* 3D2F2C E00CE46C 27BD0028 */   addiu    $sp, $sp, 0x28
