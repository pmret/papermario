.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242898_9C7C78
/* 9C7C78 80242898 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7C7C 8024289C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7C80 802428A0 0C015612 */  jal       func_80055848
/* 9C7C84 802428A4 24040004 */   addiu    $a0, $zero, 4
/* 9C7C88 802428A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7C8C 802428AC 24020002 */  addiu     $v0, $zero, 2
/* 9C7C90 802428B0 03E00008 */  jr        $ra
/* 9C7C94 802428B4 27BD0018 */   addiu    $sp, $sp, 0x18
