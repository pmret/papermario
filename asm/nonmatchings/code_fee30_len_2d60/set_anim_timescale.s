.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_anim_timescale
/* 10097C 802DD88C 460C6300 */  add.s     $f12, $f12, $f12
/* 100980 802DD890 3C01802E */  lui       $at, %hi(D_802DF4C0)
/* 100984 802DD894 03E00008 */  jr        $ra
/* 100988 802DD898 E42CF4C0 */   swc1     $f12, %lo(D_802DF4C0)($at)
