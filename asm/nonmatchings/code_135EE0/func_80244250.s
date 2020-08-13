.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80244250
/* 137590 80244250 2A220003 */  slti  $v0, $s1, 3
/* 137594 80244254 1440FFF8 */  bnez  $v0, .L80244238
