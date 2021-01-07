.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802196D8_63E8B8
/* 63E8B8 802196D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63E8BC 802196DC 0000202D */  daddu     $a0, $zero, $zero
/* 63E8C0 802196E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63E8C4 802196E4 0C01C49C */  jal       func_80071270
/* 63E8C8 802196E8 24050010 */   addiu    $a1, $zero, 0x10
/* 63E8CC 802196EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63E8D0 802196F0 24020002 */  addiu     $v0, $zero, 2
/* 63E8D4 802196F4 03E00008 */  jr        $ra
/* 63E8D8 802196F8 27BD0018 */   addiu    $sp, $sp, 0x18
