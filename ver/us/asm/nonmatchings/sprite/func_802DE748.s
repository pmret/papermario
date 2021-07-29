.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DE748
/* 101838 802DE748 00041080 */  sll       $v0, $a0, 2
/* 10183C 802DE74C 00441021 */  addu      $v0, $v0, $a0
/* 101840 802DE750 00021080 */  sll       $v0, $v0, 2
/* 101844 802DE754 3C03802E */  lui       $v1, %hi(D_802DFA4C)
/* 101848 802DE758 00621821 */  addu      $v1, $v1, $v0
/* 10184C 802DE75C 8C63FA4C */  lw        $v1, %lo(D_802DFA4C)($v1)
/* 101850 802DE760 10600005 */  beqz      $v1, .L802DE778
/* 101854 802DE764 00051080 */   sll      $v0, $a1, 2
/* 101858 802DE768 00431021 */  addu      $v0, $v0, $v1
/* 10185C 802DE76C 8C420000 */  lw        $v0, ($v0)
/* 101860 802DE770 03E00008 */  jr        $ra
/* 101864 802DE774 9042004F */   lbu      $v0, 0x4f($v0)
.L802DE778:
/* 101868 802DE778 03E00008 */  jr        $ra
/* 10186C 802DE77C 2402FFFF */   addiu    $v0, $zero, -1
