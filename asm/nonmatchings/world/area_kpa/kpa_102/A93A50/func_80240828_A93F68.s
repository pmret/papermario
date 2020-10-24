.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240828_A93F68
/* A93F68 80240828 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A93F6C 8024082C AFB00010 */  sw        $s0, 0x10($sp)
/* A93F70 80240830 0080802D */  daddu     $s0, $a0, $zero
/* A93F74 80240834 AFBF0014 */  sw        $ra, 0x14($sp)
/* A93F78 80240838 8E020148 */  lw        $v0, 0x148($s0)
/* A93F7C 8024083C 0C00EABB */  jal       get_npc_unsafe
/* A93F80 80240840 84440008 */   lh       $a0, 8($v0)
/* A93F84 80240844 9443008E */  lhu       $v1, 0x8e($v0)
/* A93F88 80240848 2463FFFF */  addiu     $v1, $v1, -1
/* A93F8C 8024084C A443008E */  sh        $v1, 0x8e($v0)
/* A93F90 80240850 00031C00 */  sll       $v1, $v1, 0x10
/* A93F94 80240854 58600001 */  blezl     $v1, .L8024085C
/* A93F98 80240858 AE000070 */   sw       $zero, 0x70($s0)
.L8024085C:
/* A93F9C 8024085C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A93FA0 80240860 8FB00010 */  lw        $s0, 0x10($sp)
/* A93FA4 80240864 03E00008 */  jr        $ra
/* A93FA8 80240868 27BD0018 */   addiu    $sp, $sp, 0x18
