.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00502C4
/* 35C294 E00502C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 35C298 E00502C8 3C02E005 */  lui       $v0, %hi(func_E0050308)
/* 35C29C E00502CC 24420308 */  addiu     $v0, $v0, %lo(func_E0050308)
/* 35C2A0 E00502D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 35C2A4 E00502D4 2402002D */  addiu     $v0, $zero, 0x2d
/* 35C2A8 E00502D8 AFA40018 */  sw        $a0, 0x18($sp)
/* 35C2AC E00502DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 35C2B0 E00502E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 35C2B4 E00502E4 AFA00014 */  sw        $zero, 0x14($sp)
/* 35C2B8 E00502E8 0C080120 */  jal       func_E0200480
/* 35C2BC E00502EC AFA20010 */   sw       $v0, 0x10($sp)
/* 35C2C0 E00502F0 8C430000 */  lw        $v1, ($v0)
/* 35C2C4 E00502F4 34630002 */  ori       $v1, $v1, 2
/* 35C2C8 E00502F8 AC430000 */  sw        $v1, ($v0)
/* 35C2CC E00502FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35C2D0 E0050300 03E00008 */  jr        $ra
/* 35C2D4 E0050304 27BD0028 */   addiu    $sp, $sp, 0x28
