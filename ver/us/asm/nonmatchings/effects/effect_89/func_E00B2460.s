.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B2460
/* 3B4BF0 E00B2460 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B4BF4 E00B2464 3C02E00B */  lui       $v0, %hi(func_E00B24B0)
/* 3B4BF8 E00B2468 244224B0 */  addiu     $v0, $v0, %lo(func_E00B24B0)
/* 3B4BFC E00B246C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B4C00 E00B2470 2402000A */  addiu     $v0, $zero, 0xa
/* 3B4C04 E00B2474 AFA20014 */  sw        $v0, 0x14($sp)
/* 3B4C08 E00B2478 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B4C0C E00B247C AFA40018 */  sw        $a0, 0x18($sp)
/* 3B4C10 E00B2480 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B4C14 E00B2484 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B4C18 E00B2488 0C080120 */  jal       func_E0200480
/* 3B4C1C E00B248C AFA20010 */   sw       $v0, 0x10($sp)
/* 3B4C20 E00B2490 8C430000 */  lw        $v1, ($v0)
/* 3B4C24 E00B2494 34630002 */  ori       $v1, $v1, 2
/* 3B4C28 E00B2498 AC430000 */  sw        $v1, ($v0)
/* 3B4C2C E00B249C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B4C30 E00B24A0 03E00008 */  jr        $ra
/* 3B4C34 E00B24A4 27BD0028 */   addiu    $sp, $sp, 0x28
