.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024081C_9B1FAC
/* 9B1FAC 8024081C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B1FB0 80240820 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B1FB4 80240824 3C108024 */  lui       $s0, %hi(D_802451F0)
/* 9B1FB8 80240828 261051F0 */  addiu     $s0, $s0, %lo(D_802451F0)
/* 9B1FBC 8024082C AFBF0014 */  sw        $ra, 0x14($sp)
/* 9B1FC0 80240830 0C04EA15 */  jal       func_8013A854
/* 9B1FC4 80240834 8E040004 */   lw       $a0, 4($s0)
/* 9B1FC8 80240838 0C048D70 */  jal       free_dynamic_entity
/* 9B1FCC 8024083C 8E040008 */   lw       $a0, 8($s0)
/* 9B1FD0 80240840 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9B1FD4 80240844 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B1FD8 80240848 24020002 */  addiu     $v0, $zero, 2
/* 9B1FDC 8024084C 03E00008 */  jr        $ra
/* 9B1FE0 80240850 27BD0018 */   addiu    $sp, $sp, 0x18
