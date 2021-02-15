.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1414_78BA14
/* 78BA14 802A1414 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78BA18 802A1418 AFB00010 */  sw        $s0, 0x10($sp)
/* 78BA1C 802A141C 0080802D */  daddu     $s0, $a0, $zero
/* 78BA20 802A1420 10A00003 */  beqz      $a1, .L802A1430
/* 78BA24 802A1424 AFBF0014 */   sw       $ra, 0x14($sp)
/* 78BA28 802A1428 24020014 */  addiu     $v0, $zero, 0x14
/* 78BA2C 802A142C AE020070 */  sw        $v0, 0x70($s0)
.L802A1430:
/* 78BA30 802A1430 0000202D */  daddu     $a0, $zero, $zero
/* 78BA34 802A1434 0080282D */  daddu     $a1, $a0, $zero
/* 78BA38 802A1438 8E020070 */  lw        $v0, 0x70($s0)
/* 78BA3C 802A143C 0080302D */  daddu     $a2, $a0, $zero
/* 78BA40 802A1440 00023880 */  sll       $a3, $v0, 2
/* 78BA44 802A1444 00E23821 */  addu      $a3, $a3, $v0
/* 78BA48 802A1448 00073840 */  sll       $a3, $a3, 1
/* 78BA4C 802A144C 0C046F97 */  jal       set_background_color_blend
/* 78BA50 802A1450 30E700FE */   andi     $a3, $a3, 0xfe
/* 78BA54 802A1454 8E020070 */  lw        $v0, 0x70($s0)
/* 78BA58 802A1458 2442FFFF */  addiu     $v0, $v0, -1
/* 78BA5C 802A145C 10400003 */  beqz      $v0, .L802A146C
/* 78BA60 802A1460 AE020070 */   sw       $v0, 0x70($s0)
/* 78BA64 802A1464 080A8521 */  j         .L802A1484
/* 78BA68 802A1468 0000102D */   daddu    $v0, $zero, $zero
.L802A146C:
/* 78BA6C 802A146C 0000202D */  daddu     $a0, $zero, $zero
/* 78BA70 802A1470 0080282D */  daddu     $a1, $a0, $zero
/* 78BA74 802A1474 0080302D */  daddu     $a2, $a0, $zero
/* 78BA78 802A1478 0C046F97 */  jal       set_background_color_blend
/* 78BA7C 802A147C 0080382D */   daddu    $a3, $a0, $zero
/* 78BA80 802A1480 24020002 */  addiu     $v0, $zero, 2
.L802A1484:
/* 78BA84 802A1484 8FBF0014 */  lw        $ra, 0x14($sp)
/* 78BA88 802A1488 8FB00010 */  lw        $s0, 0x10($sp)
/* 78BA8C 802A148C 03E00008 */  jr        $ra
/* 78BA90 802A1490 27BD0018 */   addiu    $sp, $sp, 0x18
