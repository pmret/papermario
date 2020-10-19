.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C58
/* 889828 80240C58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 88982C 80240C5C AFBF0010 */  sw        $ra, 0x10($sp)
/* 889830 80240C60 8C82000C */  lw        $v0, 0xc($a0)
/* 889834 80240C64 0C0B1EAF */  jal       get_variable
/* 889838 80240C68 8C450000 */   lw       $a1, ($v0)
/* 88983C 80240C6C 0C0B95A4 */  jal       func_802E5690
/* 889840 80240C70 0040202D */   daddu    $a0, $v0, $zero
/* 889844 80240C74 8FBF0010 */  lw        $ra, 0x10($sp)
/* 889848 80240C78 24020002 */  addiu     $v0, $zero, 2
/* 88984C 80240C7C 03E00008 */  jr        $ra
/* 889850 80240C80 27BD0018 */   addiu    $sp, $sp, 0x18
