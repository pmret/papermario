.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80266AF8
/* 1953D8 80266AF8 3C03FFF7 */  lui   $v1, 0xfff7
/* 1953DC 80266AFC 8C820000 */  lw    $v0, ($a0)
/* 1953E0 80266B00 3463FFFF */  ori   $v1, $v1, 0xffff
/* 1953E4 80266B04 A0800206 */  sb    $zero, 0x206($a0)
/* 1953E8 80266B08 00431024 */  and   $v0, $v0, $v1
/* 1953EC 80266B0C 03E00008 */  jr    $ra
/* 1953F0 80266B10 AC820000 */   sw    $v0, ($a0)

