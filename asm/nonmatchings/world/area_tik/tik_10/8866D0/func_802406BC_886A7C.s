.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_886A7C
/* 886A7C 802406BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 886A80 802406C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 886A84 802406C4 8C82000C */  lw        $v0, 0xc($a0)
/* 886A88 802406C8 0C0B1EAF */  jal       get_variable
/* 886A8C 802406CC 8C450000 */   lw       $a1, ($v0)
/* 886A90 802406D0 0C0B95A4 */  jal       func_802E5690
/* 886A94 802406D4 0040202D */   daddu    $a0, $v0, $zero
/* 886A98 802406D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 886A9C 802406DC 24020002 */  addiu     $v0, $zero, 2
/* 886AA0 802406E0 03E00008 */  jr        $ra
/* 886AA4 802406E4 27BD0018 */   addiu    $sp, $sp, 0x18
