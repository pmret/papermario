.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00342C8
/* 344CD8 E00342C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 344CDC E00342CC 3C02E003 */  lui       $v0, %hi(func_E0034310)
/* 344CE0 E00342D0 24424310 */  addiu     $v0, $v0, %lo(func_E0034310)
/* 344CE4 E00342D4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 344CE8 E00342D8 24020014 */  addiu     $v0, $zero, 0x14
/* 344CEC E00342DC AFA20014 */  sw        $v0, 0x14($sp)
/* 344CF0 E00342E0 2402002D */  addiu     $v0, $zero, 0x2d
/* 344CF4 E00342E4 AFA40018 */  sw        $a0, 0x18($sp)
/* 344CF8 E00342E8 27A40010 */  addiu     $a0, $sp, 0x10
/* 344CFC E00342EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 344D00 E00342F0 0C080120 */  jal       shim_queue_render_task
/* 344D04 E00342F4 AFA20010 */   sw       $v0, 0x10($sp)
/* 344D08 E00342F8 8C430000 */  lw        $v1, ($v0)
/* 344D0C E00342FC 34630002 */  ori       $v1, $v1, 2
/* 344D10 E0034300 AC430000 */  sw        $v1, ($v0)
/* 344D14 E0034304 8FBF0020 */  lw        $ra, 0x20($sp)
/* 344D18 E0034308 03E00008 */  jr        $ra
/* 344D1C E003430C 27BD0028 */   addiu    $sp, $sp, 0x28
