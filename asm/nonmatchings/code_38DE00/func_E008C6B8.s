.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008C6B8
/* 38E4B8 E008C6B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 38E4BC E008C6BC 3C02E009 */  lui       $v0, %hi(D_E008C6FC)
/* 38E4C0 E008C6C0 2442C6FC */  addiu     $v0, $v0, %lo(D_E008C6FC)
/* 38E4C4 E008C6C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38E4C8 E008C6C8 2402002D */  addiu     $v0, $zero, 0x2d
/* 38E4CC E008C6CC AFA40018 */  sw        $a0, 0x18($sp)
/* 38E4D0 E008C6D0 27A40010 */  addiu     $a0, $sp, 0x10
/* 38E4D4 E008C6D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 38E4D8 E008C6D8 AFA00014 */  sw        $zero, 0x14($sp)
/* 38E4DC E008C6DC 0C080120 */  jal       func_E0200480
/* 38E4E0 E008C6E0 AFA20010 */   sw       $v0, 0x10($sp)
/* 38E4E4 E008C6E4 8C430000 */  lw        $v1, ($v0)
/* 38E4E8 E008C6E8 34630002 */  ori       $v1, $v1, 2
/* 38E4EC E008C6EC AC430000 */  sw        $v1, ($v0)
/* 38E4F0 E008C6F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 38E4F4 E008C6F4 03E00008 */  jr        $ra
/* 38E4F8 E008C6F8 27BD0028 */   addiu    $sp, $sp, 0x28
