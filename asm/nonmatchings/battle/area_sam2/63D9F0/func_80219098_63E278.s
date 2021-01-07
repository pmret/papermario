.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219098_63E278
/* 63E278 80219098 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63E27C 8021909C 0000202D */  daddu     $a0, $zero, $zero
/* 63E280 802190A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63E284 802190A4 0C01C49C */  jal       func_80071270
/* 63E288 802190A8 24050010 */   addiu    $a1, $zero, 0x10
/* 63E28C 802190AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63E290 802190B0 24020002 */  addiu     $v0, $zero, 2
/* 63E294 802190B4 03E00008 */  jr        $ra
/* 63E298 802190B8 27BD0018 */   addiu    $sp, $sp, 0x18
