.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0074598
/* 3769F8 E0074598 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3769FC E007459C 3C02E007 */  lui       $v0, 0xe007
/* 376A00 E00745A0 244245E0 */  addiu     $v0, $v0, 0x45e0
/* 376A04 E00745A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 376A08 E00745A8 2402000A */  addiu     $v0, $zero, 0xa
/* 376A0C E00745AC AFA20014 */  sw        $v0, 0x14($sp)
/* 376A10 E00745B0 2402002D */  addiu     $v0, $zero, 0x2d
/* 376A14 E00745B4 AFA40018 */  sw        $a0, 0x18($sp)
/* 376A18 E00745B8 27A40010 */  addiu     $a0, $sp, 0x10
/* 376A1C E00745BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 376A20 E00745C0 0C080120 */  jal       func_E0200480
/* 376A24 E00745C4 AFA20010 */   sw       $v0, 0x10($sp)
/* 376A28 E00745C8 8C430000 */  lw        $v1, ($v0)
/* 376A2C E00745CC 34630002 */  ori       $v1, $v1, 2
/* 376A30 E00745D0 AC430000 */  sw        $v1, ($v0)
/* 376A34 E00745D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 376A38 E00745D8 03E00008 */  jr        $ra
/* 376A3C E00745DC 27BD0028 */   addiu    $sp, $sp, 0x28
