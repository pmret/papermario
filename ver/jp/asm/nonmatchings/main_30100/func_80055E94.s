.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055E94
/* 31294 80055E94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31298 80055E98 0080282D */  daddu     $a1, $a0, $zero
/* 3129C 80055E9C AFBF0010 */  sw        $ra, 0x10($sp)
/* 312A0 80055EA0 0C015289 */  jal       func_80054A24
/* 312A4 80055EA4 24040010 */   addiu    $a0, $zero, 0x10
/* 312A8 80055EA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 312AC 80055EAC 03E00008 */  jr        $ra
/* 312B0 80055EB0 27BD0018 */   addiu    $sp, $sp, 0x18
