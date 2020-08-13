.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuScGetGfxMQ
/* 03A378 8005EF78 3C02800E */  lui   $v0, 0x800e
/* 03A37C 8005EF7C 03E00008 */  jr    $ra
/* 03A380 8005EF80 2442A47C */   addiu $v0, $v0, -0x5b84

