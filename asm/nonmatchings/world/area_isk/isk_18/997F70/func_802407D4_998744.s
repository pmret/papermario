.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D4_998744
/* 998744 802407D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 998748 802407D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 99874C 802407DC 0C00EAD2 */  jal       get_npc_safe
/* 998750 802407E0 8C84014C */   lw       $a0, 0x14c($a0)
/* 998754 802407E4 0040182D */  daddu     $v1, $v0, $zero
/* 998758 802407E8 846200A8 */  lh        $v0, 0xa8($v1)
/* 99875C 802407EC C462003C */  lwc1      $f2, 0x3c($v1)
/* 998760 802407F0 906400A9 */  lbu       $a0, 0xa9($v1)
/* 998764 802407F4 44820000 */  mtc1      $v0, $f0
/* 998768 802407F8 00000000 */  nop       
/* 99876C 802407FC 46800020 */  cvt.s.w   $f0, $f0
/* 998770 80240800 46001081 */  sub.s     $f2, $f2, $f0
/* 998774 80240804 A06400AB */  sb        $a0, 0xab($v1)
/* 998778 80240808 E462003C */  swc1      $f2, 0x3c($v1)
/* 99877C 8024080C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 998780 80240810 24020002 */  addiu     $v0, $zero, 2
/* 998784 80240814 03E00008 */  jr        $ra
/* 998788 80240818 27BD0018 */   addiu    $sp, $sp, 0x18
