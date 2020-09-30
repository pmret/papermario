.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_set_cursor_opacity
/* 135EE0 80242BA0 3C018025 */  lui       $at, 0x8025
/* 135EE4 80242BA4 03E00008 */  jr        $ra
/* 135EE8 80242BA8 AC24EFB0 */   sw       $a0, -0x1050($at)
