.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240810
/* 832010 80240810 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832014 80240814 AFBF0014 */  sw        $ra, 0x14($sp)
/* 832018 80240818 AFB00010 */  sw        $s0, 0x10($sp)
/* 83201C 8024081C 0C00EABB */  jal       get_npc_unsafe
/* 832020 80240820 8C84014C */   lw       $a0, 0x14c($a0)
/* 832024 80240824 24040008 */  addiu     $a0, $zero, 8
/* 832028 80240828 0040802D */  daddu     $s0, $v0, $zero
/* 83202C 8024082C 3C028024 */  lui       $v0, 0x8024
/* 832030 80240830 2442087C */  addiu     $v0, $v0, 0x87c
/* 832034 80240834 0C00AB39 */  jal       heap_malloc
/* 832038 80240838 AE020008 */   sw       $v0, 8($s0)
/* 83203C 8024083C 0040182D */  daddu     $v1, $v0, $zero
/* 832040 80240840 AE030020 */  sw        $v1, 0x20($s0)
/* 832044 80240844 AC600000 */  sw        $zero, ($v1)
/* 832048 80240848 8FBF0014 */  lw        $ra, 0x14($sp)
/* 83204C 8024084C 8FB00010 */  lw        $s0, 0x10($sp)
/* 832050 80240850 24020001 */  addiu     $v0, $zero, 1
/* 832054 80240854 03E00008 */  jr        $ra
/* 832058 80240858 27BD0018 */   addiu    $sp, $sp, 0x18
