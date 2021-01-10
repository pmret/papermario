.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1420_722F60
/* 722F60 802A1420 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 722F64 802A1424 AFB00010 */  sw        $s0, 0x10($sp)
/* 722F68 802A1428 0080802D */  daddu     $s0, $a0, $zero
/* 722F6C 802A142C 10A00003 */  beqz      $a1, .L802A143C
/* 722F70 802A1430 AFBF0014 */   sw       $ra, 0x14($sp)
/* 722F74 802A1434 24020014 */  addiu     $v0, $zero, 0x14
/* 722F78 802A1438 AE020070 */  sw        $v0, 0x70($s0)
.L802A143C:
/* 722F7C 802A143C 0000202D */  daddu     $a0, $zero, $zero
/* 722F80 802A1440 0080282D */  daddu     $a1, $a0, $zero
/* 722F84 802A1444 8E020070 */  lw        $v0, 0x70($s0)
/* 722F88 802A1448 0080302D */  daddu     $a2, $a0, $zero
/* 722F8C 802A144C 00023880 */  sll       $a3, $v0, 2
/* 722F90 802A1450 00E23821 */  addu      $a3, $a3, $v0
/* 722F94 802A1454 00073840 */  sll       $a3, $a3, 1
/* 722F98 802A1458 0C046F97 */  jal       set_background_color_blend
/* 722F9C 802A145C 30E700FE */   andi     $a3, $a3, 0xfe
/* 722FA0 802A1460 8E020070 */  lw        $v0, 0x70($s0)
/* 722FA4 802A1464 2442FFFF */  addiu     $v0, $v0, -1
/* 722FA8 802A1468 10400003 */  beqz      $v0, .L802A1478
/* 722FAC 802A146C AE020070 */   sw       $v0, 0x70($s0)
/* 722FB0 802A1470 080A8524 */  j         .L802A1490
/* 722FB4 802A1474 0000102D */   daddu    $v0, $zero, $zero
.L802A1478:
/* 722FB8 802A1478 0000202D */  daddu     $a0, $zero, $zero
/* 722FBC 802A147C 0080282D */  daddu     $a1, $a0, $zero
/* 722FC0 802A1480 0080302D */  daddu     $a2, $a0, $zero
/* 722FC4 802A1484 0C046F97 */  jal       set_background_color_blend
/* 722FC8 802A1488 0080382D */   daddu    $a3, $a0, $zero
/* 722FCC 802A148C 24020002 */  addiu     $v0, $zero, 2
.L802A1490:
/* 722FD0 802A1490 8FBF0014 */  lw        $ra, 0x14($sp)
/* 722FD4 802A1494 8FB00010 */  lw        $s0, 0x10($sp)
/* 722FD8 802A1498 03E00008 */  jr        $ra
/* 722FDC 802A149C 27BD0018 */   addiu    $sp, $sp, 0x18
