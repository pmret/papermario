.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF628
/* 88AD8 800EF628 3C038011 */  lui       $v1, 0x8011
/* 88ADC 800EF62C 2463EBB0 */  addiu     $v1, $v1, -0x1450
/* 88AE0 800EF630 90620014 */  lbu       $v0, 0x14($v1)
/* 88AE4 800EF634 24420001 */  addiu     $v0, $v0, 1
/* 88AE8 800EF638 03E00008 */  jr        $ra
/* 88AEC 800EF63C A0620014 */   sb       $v0, 0x14($v1)
