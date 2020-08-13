.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004DCB8
/* 0290B8 8004DCB8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0290BC 8004DCBC AFB20018 */  sw    $s2, 0x18($sp)
/* 0290C0 8004DCC0 0080902D */  daddu $s2, $a0, $zero
/* 0290C4 8004DCC4 AFB50024 */  sw    $s5, 0x24($sp)
/* 0290C8 8004DCC8 00A0A82D */  daddu $s5, $a1, $zero
/* 0290CC 8004DCCC AFB3001C */  sw    $s3, 0x1c($sp)
/* 0290D0 8004DCD0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0290D4 8004DCD4 AFB40020 */  sw    $s4, 0x20($sp)
/* 0290D8 8004DCD8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0290DC 8004DCDC AFB00010 */  sw    $s0, 0x10($sp)
/* 0290E0 8004DCE0 8E510000 */  lw    $s1, ($s2)
/* 0290E4 8004DCE4 8E540010 */  lw    $s4, 0x10($s2)
/* 0290E8 8004DCE8 12200045 */  beqz  $s1, .L8004DE00
/* 0290EC 8004DCEC 0000982D */   daddu $s3, $zero, $zero
/* 0290F0 8004DCF0 0C0135E5 */  jal   func_8004D794
/* 0290F4 8004DCF4 0220202D */   daddu $a0, $s1, $zero
/* 0290F8 8004DCF8 0040802D */  daddu $s0, $v0, $zero
/* 0290FC 8004DCFC 52000041 */  beql  $s0, $zero, .L8004DE04
/* 029100 8004DD00 24130002 */   addiu $s3, $zero, 2
/* 029104 8004DD04 8E420014 */  lw    $v0, 0x14($s2)
/* 029108 8004DD08 14400032 */  bnez  $v0, .L8004DDD4
/* 02910C 8004DD0C 00000000 */   nop   
/* 029110 8004DD10 0C014FD9 */  jal   func_80053F64
/* 029114 8004DD14 0280202D */   daddu $a0, $s4, $zero
/* 029118 8004DD18 0040402D */  daddu $t0, $v0, $zero
/* 02911C 8004DD1C 51000039 */  beql  $t0, $zero, .L8004DE04
/* 029120 8004DD20 24130004 */   addiu $s3, $zero, 4
/* 029124 8004DD24 8E02001C */  lw    $v0, 0x1c($s0)
/* 029128 8004DD28 16220037 */  bne   $s1, $v0, .L8004DE08
/* 02912C 8004DD2C 0260102D */   daddu $v0, $s3, $zero
/* 029130 8004DD30 16A00015 */  bnez  $s5, .L8004DD88
/* 029134 8004DD34 001428C0 */   sll   $a1, $s4, 3
/* 029138 8004DD38 0260382D */  daddu $a3, $s3, $zero
/* 02913C 8004DD3C 2406025C */  addiu $a2, $zero, 0x25c
.L8004DD40:
/* 029140 8004DD40 02062821 */  addu  $a1, $s0, $a2
/* 029144 8004DD44 8CA20000 */  lw    $v0, ($a1)
/* 029148 8004DD48 5040000B */  beql  $v0, $zero, .L8004DD78
/* 02914C 8004DD4C 24E70001 */   addiu $a3, $a3, 1
/* 029150 8004DD50 90A30052 */  lbu   $v1, 0x52($a1)
/* 029154 8004DD54 90A40053 */  lbu   $a0, 0x53($a1)
/* 029158 8004DD58 0064102B */  sltu  $v0, $v1, $a0
/* 02915C 8004DD5C 50400006 */  beql  $v0, $zero, .L8004DD78
/* 029160 8004DD60 24E70001 */   addiu $a3, $a3, 1
.L8004DD64:
/* 029164 8004DD64 24630001 */  addiu $v1, $v1, 1
/* 029168 8004DD68 0064102B */  sltu  $v0, $v1, $a0
/* 02916C 8004DD6C 1440FFFD */  bnez  $v0, .L8004DD64
/* 029170 8004DD70 ACA00040 */   sw    $zero, 0x40($a1)
/* 029174 8004DD74 24E70001 */  addiu $a3, $a3, 1
.L8004DD78:
/* 029178 8004DD78 2CE20010 */  sltiu $v0, $a3, 0x10
/* 02917C 8004DD7C 1440FFF0 */  bnez  $v0, .L8004DD40
/* 029180 8004DD80 24C60060 */   addiu $a2, $a2, 0x60
/* 029184 8004DD84 001428C0 */  sll   $a1, $s4, 3
.L8004DD88:
/* 029188 8004DD88 0200202D */  daddu $a0, $s0, $zero
/* 02918C 8004DD8C 24060A9C */  addiu $a2, $zero, 0xa9c
/* 029190 8004DD90 8E020000 */  lw    $v0, ($s0)
/* 029194 8004DD94 92030234 */  lbu   $v1, 0x234($s0)
/* 029198 8004DD98 00451021 */  addu  $v0, $v0, $a1
/* 02919C 8004DD9C A0430071 */  sb    $v1, 0x71($v0)
/* 0291A0 8004DDA0 8E020000 */  lw    $v0, ($s0)
/* 0291A4 8004DDA4 24030001 */  addiu $v1, $zero, 1
/* 0291A8 8004DDA8 00451021 */  addu  $v0, $v0, $a1
/* 0291AC 8004DDAC 0100282D */  daddu $a1, $t0, $zero
/* 0291B0 8004DDB0 A0430070 */  sb    $v1, 0x70($v0)
/* 0291B4 8004DDB4 0C0153DD */  jal   al_CopyWords
/* 0291B8 8004DDB8 AE000020 */   sw    $zero, 0x20($s0)
/* 0291BC 8004DDBC 16A00012 */  bnez  $s5, .L8004DE08
/* 0291C0 8004DDC0 0260102D */   daddu $v0, $s3, $zero
/* 0291C4 8004DDC4 0C0136AA */  jal   func_8004DAA8
/* 0291C8 8004DDC8 0200202D */   daddu $a0, $s0, $zero
/* 0291CC 8004DDCC 08013782 */  j     .L8004DE08
/* 0291D0 8004DDD0 0260102D */   daddu $v0, $s3, $zero

.L8004DDD4:
/* 0291D4 8004DDD4 8E02001C */  lw    $v0, 0x1c($s0)
/* 0291D8 8004DDD8 1622000B */  bne   $s1, $v0, .L8004DE08
/* 0291DC 8004DDDC 0260102D */   daddu $v0, $s3, $zero
/* 0291E0 8004DDE0 92020221 */  lbu   $v0, 0x221($s0)
/* 0291E4 8004DDE4 10400007 */  beqz  $v0, .L8004DE04
/* 0291E8 8004DDE8 24020001 */   addiu $v0, $zero, 1
/* 0291EC 8004DDEC A2020220 */  sb    $v0, 0x220($s0)
/* 0291F0 8004DDF0 0C014240 */  jal   func_80050900
/* 0291F4 8004DDF4 0200202D */   daddu $a0, $s0, $zero
/* 0291F8 8004DDF8 08013782 */  j     .L8004DE08
/* 0291FC 8004DDFC 0260102D */   daddu $v0, $s3, $zero

.L8004DE00:
/* 029200 8004DE00 24130003 */  addiu $s3, $zero, 3
.L8004DE04:
/* 029204 8004DE04 0260102D */  daddu $v0, $s3, $zero
.L8004DE08:
/* 029208 8004DE08 8FBF0028 */  lw    $ra, 0x28($sp)
/* 02920C 8004DE0C 8FB50024 */  lw    $s5, 0x24($sp)
/* 029210 8004DE10 8FB40020 */  lw    $s4, 0x20($sp)
/* 029214 8004DE14 8FB3001C */  lw    $s3, 0x1c($sp)
/* 029218 8004DE18 8FB20018 */  lw    $s2, 0x18($sp)
/* 02921C 8004DE1C 8FB10014 */  lw    $s1, 0x14($sp)
/* 029220 8004DE20 8FB00010 */  lw    $s0, 0x10($sp)
/* 029224 8004DE24 03E00008 */  jr    $ra
/* 029228 8004DE28 27BD0030 */   addiu $sp, $sp, 0x30

