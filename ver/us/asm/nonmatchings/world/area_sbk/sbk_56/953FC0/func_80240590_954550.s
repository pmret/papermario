.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sbk_56_UnkFunc39
/* 954550 80240590 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 954554 80240594 AFBF0010 */  sw        $ra, 0x10($sp)
/* 954558 80240598 8C82000C */  lw        $v0, 0xc($a0)
/* 95455C 8024059C 0C0B1EAF */  jal       get_variable
/* 954560 802405A0 8C450000 */   lw       $a1, ($v0)
/* 954564 802405A4 0040202D */  daddu     $a0, $v0, $zero
/* 954568 802405A8 8C830000 */  lw        $v1, ($a0)
/* 95456C 802405AC 34630010 */  ori       $v1, $v1, 0x10
/* 954570 802405B0 AC830000 */  sw        $v1, ($a0)
/* 954574 802405B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 954578 802405B8 24020002 */  addiu     $v0, $zero, 2
/* 95457C 802405BC 03E00008 */  jr        $ra
/* 954580 802405C0 27BD0018 */   addiu    $sp, $sp, 0x18
