.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCamType
/* 0F0914 802CBF64 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0918 802CBF68 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F091C 802CBF6C 0080902D */  daddu $s2, $a0, $zero
/* 0F0920 802CBF70 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0924 802CBF74 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0928 802CBF78 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F092C 802CBF7C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0930 802CBF80 8E250000 */  lw    $a1, ($s1)
/* 0F0934 802CBF84 0C0B1EAF */  jal   get_variable
/* 0F0938 802CBF88 26310004 */   addiu $s1, $s1, 4
/* 0F093C 802CBF8C 3C03800B */  lui   $v1, 0x800b
/* 0F0940 802CBF90 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0944 802CBF94 00028080 */  sll   $s0, $v0, 2
/* 0F0948 802CBF98 02028021 */  addu  $s0, $s0, $v0
/* 0F094C 802CBF9C 00108080 */  sll   $s0, $s0, 2
/* 0F0950 802CBFA0 02028023 */  subu  $s0, $s0, $v0
/* 0F0954 802CBFA4 001010C0 */  sll   $v0, $s0, 3
/* 0F0958 802CBFA8 02028021 */  addu  $s0, $s0, $v0
/* 0F095C 802CBFAC 001080C0 */  sll   $s0, $s0, 3
/* 0F0960 802CBFB0 02038021 */  addu  $s0, $s0, $v1
/* 0F0964 802CBFB4 8E250000 */  lw    $a1, ($s1)
/* 0F0968 802CBFB8 8E0604D8 */  lw    $a2, 0x4d8($s0)
/* 0F096C 802CBFBC 8E310004 */  lw    $s1, 4($s1)
/* 0F0970 802CBFC0 0C0B2026 */  jal   set_variable
/* 0F0974 802CBFC4 0240202D */   daddu $a0, $s2, $zero
/* 0F0978 802CBFC8 0240202D */  daddu $a0, $s2, $zero
/* 0F097C 802CBFCC 8E060500 */  lw    $a2, 0x500($s0)
/* 0F0980 802CBFD0 0C0B2026 */  jal   set_variable
/* 0F0984 802CBFD4 0220282D */   daddu $a1, $s1, $zero
/* 0F0988 802CBFD8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F098C 802CBFDC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0990 802CBFE0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0994 802CBFE4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0998 802CBFE8 24020002 */  addiu $v0, $zero, 2
/* 0F099C 802CBFEC 03E00008 */  jr    $ra
/* 0F09A0 802CBFF0 27BD0020 */   addiu $sp, $sp, 0x20

