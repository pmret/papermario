.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00448E4
/* 355844 E00448E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 355848 E00448E8 3C02E004 */  lui       $v0, 0xe004
/* 35584C E00448EC 2442491C */  addiu     $v0, $v0, 0x491c
/* 355850 E00448F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 355854 E00448F4 2402002D */  addiu     $v0, $zero, 0x2d
/* 355858 E00448F8 AFA40018 */  sw        $a0, 0x18($sp)
/* 35585C E00448FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 355860 E0044900 AFBF0020 */  sw        $ra, 0x20($sp)
/* 355864 E0044904 AFA00014 */  sw        $zero, 0x14($sp)
/* 355868 E0044908 0C080120 */  jal       func_E0200480
/* 35586C E004490C AFA20010 */   sw       $v0, 0x10($sp)
/* 355870 E0044910 8FBF0020 */  lw        $ra, 0x20($sp)
/* 355874 E0044914 03E00008 */  jr        $ra
/* 355878 E0044918 27BD0028 */   addiu    $sp, $sp, 0x28
