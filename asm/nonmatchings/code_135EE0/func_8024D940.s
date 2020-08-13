.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024D940
/* 140C80 8024D940 90830004 */  lbu   $v1, 4($a0)
/* 140C84 8024D944 8C8E0008 */  lw    $t6, 8($a0)
/* 140C88 8024D948 90890005 */  lbu   $t1, 5($a0)
/* 140C8C 8024D94C 00031080 */  sll   $v0, $v1, 2
/* 140C90 8024D950 00431021 */  addu  $v0, $v0, $v1
/* 140C94 8024D954 00021080 */  sll   $v0, $v0, 2
/* 140C98 8024D958 00451021 */  addu  $v0, $v0, $a1
/* 140C9C 8024D95C 84450000 */  lh    $a1, ($v0)
/* 140CA0 8024D960 84460002 */  lh    $a2, 2($v0)
