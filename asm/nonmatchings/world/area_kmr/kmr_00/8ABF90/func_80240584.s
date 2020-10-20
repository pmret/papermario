.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240584
/* 8AC514 80240584 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8AC518 80240588 0000202D */  daddu     $a0, $zero, $zero
/* 8AC51C 8024058C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8AC520 80240590 0C01554F */  jal       func_8005553C
/* 8AC524 80240594 240507D0 */   addiu    $a1, $zero, 0x7d0
/* 8AC528 80240598 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8AC52C 8024059C 24020002 */  addiu     $v0, $zero, 2
/* 8AC530 802405A0 03E00008 */  jr        $ra
/* 8AC534 802405A4 27BD0018 */   addiu    $sp, $sp, 0x18
