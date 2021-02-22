.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240358_8EC178
/* 8EC178 80240358 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EC17C 8024035C 0000202D */  daddu     $a0, $zero, $zero
/* 8EC180 80240360 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8EC184 80240364 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EC188 80240368 0C01559B */  jal       func_8005566C
/* 8EC18C 8024036C 2406007F */   addiu    $a2, $zero, 0x7f
/* 8EC190 80240370 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EC194 80240374 24020002 */  addiu     $v0, $zero, 2
/* 8EC198 80240378 03E00008 */  jr        $ra
/* 8EC19C 8024037C 27BD0018 */   addiu    $sp, $sp, 0x18
