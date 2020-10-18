.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004E1D0
/* 35BBA0 E004E1D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 35BBA4 E004E1D4 3C02E005 */  lui       $v0, 0xe005
/* 35BBA8 E004E1D8 2442E214 */  addiu     $v0, $v0, -0x1dec
/* 35BBAC E004E1DC AFA2001C */  sw        $v0, 0x1c($sp)
/* 35BBB0 E004E1E0 24020028 */  addiu     $v0, $zero, 0x28
/* 35BBB4 E004E1E4 AFA40018 */  sw        $a0, 0x18($sp)
/* 35BBB8 E004E1E8 27A40010 */  addiu     $a0, $sp, 0x10
/* 35BBBC E004E1EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 35BBC0 E004E1F0 AFA00014 */  sw        $zero, 0x14($sp)
/* 35BBC4 E004E1F4 0C080120 */  jal       func_E0200480
/* 35BBC8 E004E1F8 AFA20010 */   sw       $v0, 0x10($sp)
/* 35BBCC E004E1FC 8C430000 */  lw        $v1, ($v0)
/* 35BBD0 E004E200 34630002 */  ori       $v1, $v1, 2
/* 35BBD4 E004E204 AC430000 */  sw        $v1, ($v0)
/* 35BBD8 E004E208 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35BBDC E004E20C 03E00008 */  jr        $ra
/* 35BBE0 E004E210 27BD0028 */   addiu    $sp, $sp, 0x28
