.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021AD48_6268E8
/* 6268E8 8021AD48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6268EC 8021AD4C 0000202D */  daddu     $a0, $zero, $zero
/* 6268F0 8021AD50 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6268F4 8021AD54 0C01C49C */  jal       func_80071270
/* 6268F8 8021AD58 24050010 */   addiu    $a1, $zero, 0x10
/* 6268FC 8021AD5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 626900 8021AD60 24020002 */  addiu     $v0, $zero, 2
/* 626904 8021AD64 03E00008 */  jr        $ra
/* 626908 8021AD68 27BD0018 */   addiu    $sp, $sp, 0x18
