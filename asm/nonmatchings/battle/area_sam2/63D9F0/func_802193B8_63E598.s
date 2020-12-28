.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802193B8_63E598
/* 63E598 802193B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63E59C 802193BC 0000202D */  daddu     $a0, $zero, $zero
/* 63E5A0 802193C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63E5A4 802193C4 0C01C49C */  jal       func_80071270
/* 63E5A8 802193C8 24050010 */   addiu    $a1, $zero, 0x10
/* 63E5AC 802193CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63E5B0 802193D0 24020002 */  addiu     $v0, $zero, 2
/* 63E5B4 802193D4 03E00008 */  jr        $ra
/* 63E5B8 802193D8 27BD0018 */   addiu    $sp, $sp, 0x18
