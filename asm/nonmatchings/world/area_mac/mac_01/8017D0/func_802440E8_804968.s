.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802440E8_804968
/* 804968 802440E8 3C028011 */  lui       $v0, 0x8011
/* 80496C 802440EC 8442F29C */  lh        $v0, -0xd64($v0)
/* 804970 802440F0 AC820084 */  sw        $v0, 0x84($a0)
/* 804974 802440F4 03E00008 */  jr        $ra
/* 804978 802440F8 24020002 */   addiu    $v0, $zero, 2
