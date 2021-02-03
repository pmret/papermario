.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11C0_743FB0
/* 743FB0 802A11C0 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 743FB4 802A11C4 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 743FB8 802A11C8 3C04802A */  lui       $a0, %hi(D_802A4020)
/* 743FBC 802A11CC 24844020 */  addiu     $a0, $a0, %lo(D_802A4020)
/* 743FC0 802A11D0 94A202A0 */  lhu       $v0, 0x2a0($a1)
/* 743FC4 802A11D4 8C830000 */  lw        $v1, ($a0)
/* 743FC8 802A11D8 0043102A */  slt       $v0, $v0, $v1
/* 743FCC 802A11DC 10400003 */  beqz      $v0, .L802A11EC
/* 743FD0 802A11E0 00000000 */   nop
/* 743FD4 802A11E4 94820002 */  lhu       $v0, 2($a0)
/* 743FD8 802A11E8 A4A202A0 */  sh        $v0, 0x2a0($a1)
.L802A11EC:
/* 743FDC 802A11EC 03E00008 */  jr        $ra
