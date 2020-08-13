.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel unfreeze_cam
/* 17CEE0 8024E600 3C018028 */  lui   $at, 0x8028
/* 17CEE4 8024E604 03E00008 */  jr    $ra
/* 17CEE8 8024E608 A0200CE0 */   sb    $zero, 0xce0($at)

