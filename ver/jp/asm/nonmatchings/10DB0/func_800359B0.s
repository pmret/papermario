.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800359B0
/* 10DB0 800359B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10DB4 800359B4 3C058003 */  lui       $a1, %hi(func_80035A4C)
/* 10DB8 800359B8 24A55A4C */  addiu     $a1, $a1, %lo(func_80035A4C)
/* 10DBC 800359BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 10DC0 800359C0 0C045FE5 */  jal       func_80117F94
/* 10DC4 800359C4 0000202D */   daddu    $a0, $zero, $zero
/* 10DC8 800359C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10DCC 800359CC 03E00008 */  jr        $ra
/* 10DD0 800359D0 27BD0018 */   addiu    $sp, $sp, 0x18
