.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DE5C8
/* 1016B8 802DE5C8 00041080 */  sll       $v0, $a0, 2
/* 1016BC 802DE5CC 00441021 */  addu      $v0, $v0, $a0
/* 1016C0 802DE5D0 00021080 */  sll       $v0, $v0, 2
/* 1016C4 802DE5D4 3C01802E */  lui       $at, %hi(D_802DFA58)
/* 1016C8 802DE5D8 00220821 */  addu      $at, $at, $v0
/* 1016CC 802DE5DC 8C22FA58 */  lw        $v0, %lo(D_802DFA58)($at)
/* 1016D0 802DE5E0 03E00008 */  jr        $ra
/* 1016D4 802DE5E4 00000000 */   nop
