.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419D0_8445A0
/* 8445A0 802419D0 3C028011 */  lui       $v0, 0x8011
/* 8445A4 802419D4 8442F29C */  lh        $v0, -0xd64($v0)
/* 8445A8 802419D8 AC820084 */  sw        $v0, 0x84($a0)
/* 8445AC 802419DC 03E00008 */  jr        $ra
/* 8445B0 802419E0 24020002 */   addiu    $v0, $zero, 2
