.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01166A0
/* 402CE0 E01166A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 402CE4 E01166A4 3C02E011 */  lui       $v0, %hi(D_E0116884)
/* 402CE8 E01166A8 24426884 */  addiu     $v0, $v0, %lo(D_E0116884)
/* 402CEC E01166AC AFA2001C */  sw        $v0, 0x1c($sp)
/* 402CF0 E01166B0 2402000A */  addiu     $v0, $zero, 0xa
/* 402CF4 E01166B4 AFA20014 */  sw        $v0, 0x14($sp)
/* 402CF8 E01166B8 24020011 */  addiu     $v0, $zero, 0x11
/* 402CFC E01166BC AFA40018 */  sw        $a0, 0x18($sp)
/* 402D00 E01166C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 402D04 E01166C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 402D08 E01166C8 0C080120 */  jal       func_E0200480
/* 402D0C E01166CC AFA20010 */   sw       $v0, 0x10($sp)
/* 402D10 E01166D0 8C430000 */  lw        $v1, ($v0)
/* 402D14 E01166D4 34630002 */  ori       $v1, $v1, 2
/* 402D18 E01166D8 AC430000 */  sw        $v1, ($v0)
/* 402D1C E01166DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 402D20 E01166E0 03E00008 */  jr        $ra
/* 402D24 E01166E4 27BD0028 */   addiu    $sp, $sp, 0x28
