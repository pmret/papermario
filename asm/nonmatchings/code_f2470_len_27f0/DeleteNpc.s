.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel DeleteNpc
/* 0F25CC 802CDC1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F25D0 802CDC20 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F25D4 802CDC24 8C82000C */  lw    $v0, 0xc($a0)
/* 0F25D8 802CDC28 0C0B1EAF */  jal   get_variable
/* 0F25DC 802CDC2C 8C450000 */   lw    $a1, ($v0)
/* 0F25E0 802CDC30 0C00EABB */  jal   get_npc_unsafe
/* 0F25E4 802CDC34 0040202D */   daddu $a0, $v0, $zero
/* 0F25E8 802CDC38 50400004 */  beql  $v0, $zero, .L802CDC4C
/* 0F25EC 802CDC3C 24020002 */   addiu $v0, $zero, 2
/* 0F25F0 802CDC40 0C00E273 */  jal   free_npc
/* 0F25F4 802CDC44 0040202D */   daddu $a0, $v0, $zero
/* 0F25F8 802CDC48 24020002 */  addiu $v0, $zero, 2
.L802CDC4C:
/* 0F25FC 802CDC4C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F2600 802CDC50 03E00008 */  jr    $ra
/* 0F2604 802CDC54 27BD0018 */   addiu $sp, $sp, 0x18

