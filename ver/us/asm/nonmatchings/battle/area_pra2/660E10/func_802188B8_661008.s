.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188B8_661008
/* 661008 802188B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66100C 802188BC 0000202D */  daddu     $a0, $zero, $zero
/* 661010 802188C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 661014 802188C4 0C01C49C */  jal       func_80071270
/* 661018 802188C8 24050010 */   addiu    $a1, $zero, 0x10
/* 66101C 802188CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 661020 802188D0 24020002 */  addiu     $v0, $zero, 2
/* 661024 802188D4 03E00008 */  jr        $ra
/* 661028 802188D8 27BD0018 */   addiu    $sp, $sp, 0x18
