.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242634_8547A4
/* 8547A4 80242634 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8547A8 80242638 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8547AC 8024263C 8C82000C */  lw        $v0, 0xc($a0)
/* 8547B0 80242640 0C0B1EAF */  jal       get_variable
/* 8547B4 80242644 8C450000 */   lw       $a1, ($v0)
/* 8547B8 80242648 3C018024 */  lui       $at, 0x8024
/* 8547BC 8024264C AC2276DC */  sw        $v0, 0x76dc($at)
/* 8547C0 80242650 24020002 */  addiu     $v0, $zero, 2
/* 8547C4 80242654 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8547C8 80242658 24030001 */  addiu     $v1, $zero, 1
/* 8547CC 8024265C 3C018024 */  lui       $at, 0x8024
/* 8547D0 80242660 AC2376D8 */  sw        $v1, 0x76d8($at)
/* 8547D4 80242664 03E00008 */  jr        $ra
/* 8547D8 80242668 27BD0018 */   addiu    $sp, $sp, 0x18
