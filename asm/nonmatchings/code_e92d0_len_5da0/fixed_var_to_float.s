.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel fixed_var_to_float
/* 0E92D0 802C4920 3C02F2E3 */  lui   $v0, 0xf2e3
/* 0E92D4 802C4924 34421100 */  ori   $v0, $v0, 0x1100
/* 0E92D8 802C4928 0044102A */  slt   $v0, $v0, $a0
/* 0E92DC 802C492C 10400005 */  beqz  $v0, .L802C4944
/* 0E92E0 802C4930 3C020DB5 */   lui   $v0, 0xdb5
/* 0E92E4 802C4934 44840000 */  mtc1  $a0, $f0
/* 0E92E8 802C4938 00000000 */  nop   
/* 0E92EC 802C493C 03E00008 */  jr    $ra
/* 0E92F0 802C4940 46800020 */   cvt.s.w $f0, $f0

.L802C4944:
/* 0E92F4 802C4944 34428580 */  ori   $v0, $v0, 0x8580
/* 0E92F8 802C4948 00821021 */  addu  $v0, $a0, $v0
/* 0E92FC 802C494C 3C013A80 */  lui   $at, 0x3a80
/* 0E9300 802C4950 44811000 */  mtc1  $at, $f2
/* 0E9304 802C4954 44820000 */  mtc1  $v0, $f0
/* 0E9308 802C4958 00000000 */  nop   
/* 0E930C 802C495C 46800020 */  cvt.s.w $f0, $f0
/* 0E9310 802C4960 46020002 */  mul.s $f0, $f0, $f2
/* 0E9314 802C4964 03E00008 */  jr    $ra
/* 0E9318 802C4968 00000000 */   nop   

