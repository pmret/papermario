.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A97AC
/* 41E53C 802A97AC AC22CC6C */  sw    $v0, -0x3394($at)
/* 41E540 802A97B0 080AA6A9 */  j     .L802A9AA4
/* 41E544 802A97B4 24020002 */   addiu $v0, $zero, 2

/* 41E548 802A97B8 0C0A923F */  jal   func_802A48FC
