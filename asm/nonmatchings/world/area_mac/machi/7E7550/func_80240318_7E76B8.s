.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240318_7E76B8
/* 7E76B8 80240318 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E76BC 8024031C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E76C0 80240320 8C820148 */  lw        $v0, 0x148($a0)
/* 7E76C4 80240324 0C00EABB */  jal       get_npc_unsafe
/* 7E76C8 80240328 84440008 */   lh       $a0, 8($v0)
/* 7E76CC 8024032C 0C01784B */  jal       func_8005E12C
/* 7E76D0 80240330 0040202D */   daddu    $a0, $v0, $zero
/* 7E76D4 80240334 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E76D8 80240338 24020002 */  addiu     $v0, $zero, 2
/* 7E76DC 8024033C 03E00008 */  jr        $ra
/* 7E76E0 80240340 27BD0018 */   addiu    $sp, $sp, 0x18
