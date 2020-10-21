.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024035C_8A021C
/* 8A021C 8024035C 3C028016 */  lui       $v0, 0x8016
/* 8A0220 80240360 8442A552 */  lh        $v0, -0x5aae($v0)
/* 8A0224 80240364 AC820084 */  sw        $v0, 0x84($a0)
/* 8A0228 80240368 03E00008 */  jr        $ra
/* 8A022C 8024036C 24020002 */   addiu    $v0, $zero, 2
