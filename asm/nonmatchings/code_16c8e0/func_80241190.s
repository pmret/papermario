.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80241190
/* 16FA70 80241190 3C03800E */  lui   $v1, 0x800e
/* 16FA74 80241194 8C63C074 */  lw    $v1, -0x3f8c($v1)
/* 16FA78 80241198 24020001 */  addiu $v0, $zero, 1
/* 16FA7C 8024119C 3C01800E */  lui   $at, 0x800e
/* 16FA80 802411A0 AC24C068 */  sw    $a0, -0x3f98($at)
/* 16FA84 802411A4 3C01800E */  lui   $at, 0x800e
/* 16FA88 802411A8 AC22C4E0 */  sw    $v0, -0x3b20($at)
/* 16FA8C 802411AC 3C01800E */  lui   $at, 0x800e
/* 16FA90 802411B0 AC20C4DC */  sw    $zero, -0x3b24($at)
/* 16FA94 802411B4 30630040 */  andi  $v1, $v1, 0x40
/* 16FA98 802411B8 10600015 */  beqz  $v1, .L80241210
/* 16FA9C 802411BC 24020008 */   addiu $v0, $zero, 8
/* 16FAA0 802411C0 10820010 */  beq   $a0, $v0, .L80241204
/* 16FAA4 802411C4 28820009 */   slti  $v0, $a0, 9
/* 16FAA8 802411C8 10400005 */  beqz  $v0, .L802411E0
/* 16FAAC 802411CC 24020007 */   addiu $v0, $zero, 7
/* 16FAB0 802411D0 5082000D */  beql  $a0, $v0, .L80241208
/* 16FAB4 802411D4 24040008 */   addiu $a0, $zero, 8
/* 16FAB8 802411D8 08090482 */  j     .L80241208
/* 16FABC 802411DC 00000000 */   nop   

.L802411E0:
/* 16FAC0 802411E0 2402000D */  addiu $v0, $zero, 0xd
/* 16FAC4 802411E4 10820005 */  beq   $a0, $v0, .L802411FC
/* 16FAC8 802411E8 2402000E */   addiu $v0, $zero, 0xe
/* 16FACC 802411EC 50820006 */  beql  $a0, $v0, .L80241208
/* 16FAD0 802411F0 24040010 */   addiu $a0, $zero, 0x10
/* 16FAD4 802411F4 08090482 */  j     .L80241208
/* 16FAD8 802411F8 00000000 */   nop   

.L802411FC:
/* 16FADC 802411FC 08090482 */  j     .L80241208
/* 16FAE0 80241200 2404000F */   addiu $a0, $zero, 0xf

.L80241204:
/* 16FAE4 80241204 24040007 */  addiu $a0, $zero, 7
.L80241208:
.L80241208:
/* 16FAE8 80241208 3C01800E */  lui   $at, 0x800e
/* 16FAEC 8024120C AC24C068 */  sw    $a0, -0x3f98($at)
.L80241210:
/* 16FAF0 80241210 03E00008 */  jr    $ra
/* 16FAF4 80241214 00000000 */   nop   

