.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024C918
/* 13FC58 8024C918 8C440000 */  lw    $a0, ($v0)
/* 13FC5C 8024C91C 08093251 */  j     func_8024C944
/* 13FC60 8024C920 8C650004 */   lw    $a1, 4($v1)

.L8024C924:
/* 13FC64 8024C924 8E030000 */  lw    $v1, ($s0)
/* 13FC68 8024C928 3C063F80 */  lui   $a2, 0x3f80
/* 13FC6C 8024C92C 00031080 */  sll   $v0, $v1, 2
/* 13FC70 8024C930 00531021 */  addu  $v0, $v0, $s3
/* 13FC74 8024C934 00031900 */  sll   $v1, $v1, 4
/* 13FC78 8024C938 00721821 */  addu  $v1, $v1, $s2
/* 13FC7C 8024C93C 8C440000 */  lw    $a0, ($v0)
/* 13FC80 8024C940 8C650000 */  lw    $a1, ($v1)
