.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_10_UnkFunc17
/* 886A5C 8024069C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 886A60 802406A0 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 886A64 802406A4 8C430000 */  lw        $v1, ($v0)
/* 886A68 802406A8 2404FFBF */  addiu     $a0, $zero, -0x41
/* 886A6C 802406AC 00641824 */  and       $v1, $v1, $a0
/* 886A70 802406B0 AC430000 */  sw        $v1, ($v0)
/* 886A74 802406B4 03E00008 */  jr        $ra
/* 886A78 802406B8 24020002 */   addiu    $v0, $zero, 2
