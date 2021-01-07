.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004C364
/* 35A284 E004C364 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 35A288 E004C368 3C02E005 */  lui       $v0, %hi(D_E004C3A8)
/* 35A28C E004C36C 2442C3A8 */  addiu     $v0, $v0, %lo(D_E004C3A8)
/* 35A290 E004C370 AFA2001C */  sw        $v0, 0x1c($sp)
/* 35A294 E004C374 2402002D */  addiu     $v0, $zero, 0x2d
/* 35A298 E004C378 AFA40018 */  sw        $a0, 0x18($sp)
/* 35A29C E004C37C 27A40010 */  addiu     $a0, $sp, 0x10
/* 35A2A0 E004C380 AFBF0020 */  sw        $ra, 0x20($sp)
/* 35A2A4 E004C384 AFA00014 */  sw        $zero, 0x14($sp)
/* 35A2A8 E004C388 0C080120 */  jal       func_E0200480
/* 35A2AC E004C38C AFA20010 */   sw       $v0, 0x10($sp)
/* 35A2B0 E004C390 8C430000 */  lw        $v1, ($v0)
/* 35A2B4 E004C394 34630002 */  ori       $v1, $v1, 2
/* 35A2B8 E004C398 AC430000 */  sw        $v1, ($v0)
/* 35A2BC E004C39C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35A2C0 E004C3A0 03E00008 */  jr        $ra
/* 35A2C4 E004C3A4 27BD0028 */   addiu    $sp, $sp, 0x28
