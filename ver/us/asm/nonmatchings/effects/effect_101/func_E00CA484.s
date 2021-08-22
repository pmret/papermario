.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00CA484
/* 3D0984 E00CA484 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D0988 E00CA488 3C02E00D */  lui       $v0, %hi(func_E00CA4CC)
/* 3D098C E00CA48C 2442A4CC */  addiu     $v0, $v0, %lo(func_E00CA4CC)
/* 3D0990 E00CA490 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D0994 E00CA494 2402000A */  addiu     $v0, $zero, 0xa
/* 3D0998 E00CA498 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D099C E00CA49C 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D09A0 E00CA4A0 AFA40018 */  sw        $a0, 0x18($sp)
/* 3D09A4 E00CA4A4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D09A8 E00CA4A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D09AC E00CA4AC 0C080120 */  jal       func_E0200480
/* 3D09B0 E00CA4B0 AFA20010 */   sw       $v0, 0x10($sp)
/* 3D09B4 E00CA4B4 8C430000 */  lw        $v1, ($v0)
/* 3D09B8 E00CA4B8 34630002 */  ori       $v1, $v1, 2
/* 3D09BC E00CA4BC AC430000 */  sw        $v1, ($v0)
/* 3D09C0 E00CA4C0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D09C4 E00CA4C4 03E00008 */  jr        $ra
/* 3D09C8 E00CA4C8 27BD0028 */   addiu    $sp, $sp, 0x28
