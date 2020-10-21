.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F0_87A3D0
/* 87A3D0 802407F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87A3D4 802407F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 87A3D8 802407F8 8C82000C */  lw        $v0, 0xc($a0)
/* 87A3DC 802407FC 0C0B1EAF */  jal       get_variable
/* 87A3E0 80240800 8C450000 */   lw       $a1, ($v0)
/* 87A3E4 80240804 0040202D */  daddu     $a0, $v0, $zero
/* 87A3E8 80240808 8C830000 */  lw        $v1, ($a0)
/* 87A3EC 8024080C 34630010 */  ori       $v1, $v1, 0x10
/* 87A3F0 80240810 AC830000 */  sw        $v1, ($a0)
/* 87A3F4 80240814 8FBF0010 */  lw        $ra, 0x10($sp)
/* 87A3F8 80240818 24020002 */  addiu     $v0, $zero, 2
/* 87A3FC 8024081C 03E00008 */  jr        $ra
/* 87A400 80240820 27BD0018 */   addiu    $sp, $sp, 0x18
