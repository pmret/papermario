.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261D98
/* 190678 80261D98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19067C 80261D9C AFBF0010 */  sw        $ra, 0x10($sp)
/* 190680 80261DA0 0C09A75B */  jal       get_actor
/* 190684 80261DA4 8C840148 */   lw       $a0, 0x148($a0)
/* 190688 80261DA8 0040202D */  daddu     $a0, $v0, $zero
/* 19068C 80261DAC 24050004 */  addiu     $a1, $zero, 4
/* 190690 80261DB0 0000302D */  daddu     $a2, $zero, $zero
/* 190694 80261DB4 0C099B3C */  jal       inflict_status_set_duration
/* 190698 80261DB8 24070001 */   addiu    $a3, $zero, 1
/* 19069C 80261DBC 0C099DDF */  jal       func_8026777C
/* 1906A0 80261DC0 00000000 */   nop      
/* 1906A4 80261DC4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1906A8 80261DC8 24020002 */  addiu     $v0, $zero, 2
/* 1906AC 80261DCC 03E00008 */  jr        $ra
/* 1906B0 80261DD0 27BD0018 */   addiu    $sp, $sp, 0x18
