.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024081C
/* 98564C 8024081C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 985650 80240820 AFBF0010 */  sw        $ra, 0x10($sp)
/* 985654 80240824 0C00EAD2 */  jal       get_npc_safe
/* 985658 80240828 8C84014C */   lw       $a0, 0x14c($a0)
/* 98565C 8024082C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 985660 80240830 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 985664 80240834 C44C0038 */  lwc1      $f12, 0x38($v0)
/* 985668 80240838 C44E0040 */  lwc1      $f14, 0x40($v0)
/* 98566C 8024083C 8C660028 */  lw        $a2, 0x28($v1)
/* 985670 80240840 0C00A7B5 */  jal       dist2D
/* 985674 80240844 8C670030 */   lw       $a3, 0x30($v1)
/* 985678 80240848 3C014248 */  lui       $at, 0x4248
/* 98567C 8024084C 44811000 */  mtc1      $at, $f2
/* 985680 80240850 00000000 */  nop       
/* 985684 80240854 4602003C */  c.lt.s    $f0, $f2
/* 985688 80240858 00000000 */  nop       
/* 98568C 8024085C 45010002 */  bc1t      .L80240868
/* 985690 80240860 24020002 */   addiu    $v0, $zero, 2
/* 985694 80240864 0000102D */  daddu     $v0, $zero, $zero
.L80240868:
/* 985698 80240868 8FBF0010 */  lw        $ra, 0x10($sp)
/* 98569C 8024086C 03E00008 */  jr        $ra
/* 9856A0 80240870 27BD0018 */   addiu    $sp, $sp, 0x18
