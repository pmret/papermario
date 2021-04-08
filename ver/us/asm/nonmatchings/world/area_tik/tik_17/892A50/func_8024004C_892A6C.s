.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_17_UnkFunc17
/* 892A6C 8024004C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 892A70 80240050 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 892A74 80240054 8C430000 */  lw        $v1, ($v0)
/* 892A78 80240058 2404FFBF */  addiu     $a0, $zero, -0x41
/* 892A7C 8024005C 00641824 */  and       $v1, $v1, $a0
/* 892A80 80240060 AC430000 */  sw        $v1, ($v0)
/* 892A84 80240064 03E00008 */  jr        $ra
/* 892A88 80240068 24020002 */   addiu    $v0, $zero, 2
