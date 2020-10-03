.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026919C
/* 197A7C 8026919C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197A80 802691A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197A84 802691A4 8C82000C */  lw        $v0, 0xc($a0)
/* 197A88 802691A8 0C0B1EAF */  jal       get_variable
/* 197A8C 802691AC 8C450000 */   lw       $a1, ($v0)
/* 197A90 802691B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197A94 802691B4 3C01800E */  lui       $at, 0x800e
/* 197A98 802691B8 AC22C4A4 */  sw        $v0, -0x3b5c($at)
/* 197A9C 802691BC 24020002 */  addiu     $v0, $zero, 2
/* 197AA0 802691C0 03E00008 */  jr        $ra
/* 197AA4 802691C4 27BD0018 */   addiu    $sp, $sp, 0x18
