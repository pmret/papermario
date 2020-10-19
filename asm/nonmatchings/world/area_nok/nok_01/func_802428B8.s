.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428B8
/* 9C7C98 802428B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7C9C 802428BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7CA0 802428C0 0C0155F3 */  jal       func_800557CC
/* 9C7CA4 802428C4 24040064 */   addiu    $a0, $zero, 0x64
/* 9C7CA8 802428C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7CAC 802428CC 24020002 */  addiu     $v0, $zero, 2
/* 9C7CB0 802428D0 03E00008 */  jr        $ra
/* 9C7CB4 802428D4 27BD0018 */   addiu    $sp, $sp, 0x18
