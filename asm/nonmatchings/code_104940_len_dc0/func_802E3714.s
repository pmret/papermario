.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3714
/* 104F94 802E3714 8C820040 */  lw        $v0, 0x40($a0)
/* 104F98 802E3718 3C0142B4 */  lui       $at, 0x42b4
/* 104F9C 802E371C 44810000 */  mtc1      $at, $f0
/* 104FA0 802E3720 03E00008 */  jr        $ra
/* 104FA4 802E3724 E4400018 */   swc1     $f0, 0x18($v0)
