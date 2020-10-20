.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024005C
/* 95401C 8024005C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 954020 80240060 0000202D */  daddu     $a0, $zero, $zero
/* 954024 80240064 AFBF0010 */  sw        $ra, 0x10($sp)
/* 954028 80240068 0C052AED */  jal       func_8014ABB4
/* 95402C 8024006C 0080282D */   daddu    $a1, $a0, $zero
/* 954030 80240070 8FBF0010 */  lw        $ra, 0x10($sp)
/* 954034 80240074 24020002 */  addiu     $v0, $zero, 2
/* 954038 80240078 03E00008 */  jr        $ra
/* 95403C 8024007C 27BD0018 */   addiu    $sp, $sp, 0x18
