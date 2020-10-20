.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242144
/* 8EDF64 80242144 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDF68 80242148 0000202D */  daddu     $a0, $zero, $zero
/* 8EDF6C 8024214C 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8EDF70 80242150 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EDF74 80242154 0C01559B */  jal       func_8005566C
/* 8EDF78 80242158 2406003F */   addiu    $a2, $zero, 0x3f
/* 8EDF7C 8024215C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDF80 80242160 24020002 */  addiu     $v0, $zero, 2
/* 8EDF84 80242164 03E00008 */  jr        $ra
/* 8EDF88 80242168 27BD0018 */   addiu    $sp, $sp, 0x18
