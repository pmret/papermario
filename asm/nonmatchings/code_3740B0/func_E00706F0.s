.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00706F0
/* 3747A0 E00706F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3747A4 E00706F4 3C02E007 */  lui       $v0, 0xe007
/* 3747A8 E00706F8 24420740 */  addiu     $v0, $v0, 0x740
/* 3747AC E00706FC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3747B0 E0070700 2402000A */  addiu     $v0, $zero, 0xa
/* 3747B4 E0070704 AFA20014 */  sw        $v0, 0x14($sp)
/* 3747B8 E0070708 2402002D */  addiu     $v0, $zero, 0x2d
/* 3747BC E007070C AFA40018 */  sw        $a0, 0x18($sp)
/* 3747C0 E0070710 27A40010 */  addiu     $a0, $sp, 0x10
/* 3747C4 E0070714 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3747C8 E0070718 0C080120 */  jal       func_E0200480
/* 3747CC E007071C AFA20010 */   sw       $v0, 0x10($sp)
/* 3747D0 E0070720 8C430000 */  lw        $v1, ($v0)
/* 3747D4 E0070724 34630002 */  ori       $v1, $v1, 2
/* 3747D8 E0070728 AC430000 */  sw        $v1, ($v0)
/* 3747DC E007072C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3747E0 E0070730 03E00008 */  jr        $ra
/* 3747E4 E0070734 27BD0028 */   addiu    $sp, $sp, 0x28
