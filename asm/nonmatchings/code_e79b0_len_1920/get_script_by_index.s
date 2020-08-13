.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_script_by_index
/* 0E9140 802C4790 3C02802E */  lui   $v0, 0x802e
/* 0E9144 802C4794 8C42A890 */  lw    $v0, -0x5770($v0)
/* 0E9148 802C4798 00042080 */  sll   $a0, $a0, 2
/* 0E914C 802C479C 00822021 */  addu  $a0, $a0, $v0
/* 0E9150 802C47A0 03E00008 */  jr    $ra
/* 0E9154 802C47A4 8C820000 */   lw    $v0, ($a0)

