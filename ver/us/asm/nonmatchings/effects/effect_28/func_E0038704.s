.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0038704
/* 34E424 E0038704 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 34E428 E0038708 3C02E004 */  lui       $v0, %hi(func_E0038748)
/* 34E42C E003870C 24428748 */  addiu     $v0, $v0, %lo(func_E0038748)
/* 34E430 E0038710 AFA2001C */  sw        $v0, 0x1c($sp)
/* 34E434 E0038714 2402002D */  addiu     $v0, $zero, 0x2d
/* 34E438 E0038718 AFA40018 */  sw        $a0, 0x18($sp)
/* 34E43C E003871C 27A40010 */  addiu     $a0, $sp, 0x10
/* 34E440 E0038720 AFBF0020 */  sw        $ra, 0x20($sp)
/* 34E444 E0038724 AFA00014 */  sw        $zero, 0x14($sp)
/* 34E448 E0038728 0C080120 */  jal       func_E0200480
/* 34E44C E003872C AFA20010 */   sw       $v0, 0x10($sp)
/* 34E450 E0038730 8C430000 */  lw        $v1, ($v0)
/* 34E454 E0038734 34630002 */  ori       $v1, $v1, 2
/* 34E458 E0038738 AC430000 */  sw        $v1, ($v0)
/* 34E45C E003873C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 34E460 E0038740 03E00008 */  jr        $ra
/* 34E464 E0038744 27BD0028 */   addiu    $sp, $sp, 0x28
