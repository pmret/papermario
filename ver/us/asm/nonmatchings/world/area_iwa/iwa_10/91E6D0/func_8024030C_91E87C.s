.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_10_UnkFunc17
/* 91E87C 8024030C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 91E880 80240310 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 91E884 80240314 8C430000 */  lw        $v1, ($v0)
/* 91E888 80240318 2404FFBF */  addiu     $a0, $zero, -0x41
/* 91E88C 8024031C 00641824 */  and       $v1, $v1, $a0
/* 91E890 80240320 AC430000 */  sw        $v1, ($v0)
/* 91E894 80240324 03E00008 */  jr        $ra
/* 91E898 80240328 24020002 */   addiu    $v0, $zero, 2
