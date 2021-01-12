.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1414_7973D4
/* 7973D4 802A1414 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7973D8 802A1418 AFB00010 */  sw        $s0, 0x10($sp)
/* 7973DC 802A141C 0080802D */  daddu     $s0, $a0, $zero
/* 7973E0 802A1420 10A00003 */  beqz      $a1, .L802A1430
/* 7973E4 802A1424 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7973E8 802A1428 24020014 */  addiu     $v0, $zero, 0x14
/* 7973EC 802A142C AE020070 */  sw        $v0, 0x70($s0)
.L802A1430:
/* 7973F0 802A1430 0000202D */  daddu     $a0, $zero, $zero
/* 7973F4 802A1434 0080282D */  daddu     $a1, $a0, $zero
/* 7973F8 802A1438 8E020070 */  lw        $v0, 0x70($s0)
/* 7973FC 802A143C 0080302D */  daddu     $a2, $a0, $zero
/* 797400 802A1440 00023880 */  sll       $a3, $v0, 2
/* 797404 802A1444 00E23821 */  addu      $a3, $a3, $v0
/* 797408 802A1448 00073840 */  sll       $a3, $a3, 1
/* 79740C 802A144C 0C046F97 */  jal       set_background_color_blend
/* 797410 802A1450 30E700FE */   andi     $a3, $a3, 0xfe
/* 797414 802A1454 8E020070 */  lw        $v0, 0x70($s0)
/* 797418 802A1458 2442FFFF */  addiu     $v0, $v0, -1
/* 79741C 802A145C 10400003 */  beqz      $v0, .L802A146C
/* 797420 802A1460 AE020070 */   sw       $v0, 0x70($s0)
/* 797424 802A1464 080A8521 */  j         .L802A1484
/* 797428 802A1468 0000102D */   daddu    $v0, $zero, $zero
.L802A146C:
/* 79742C 802A146C 0000202D */  daddu     $a0, $zero, $zero
/* 797430 802A1470 0080282D */  daddu     $a1, $a0, $zero
/* 797434 802A1474 0080302D */  daddu     $a2, $a0, $zero
/* 797438 802A1478 0C046F97 */  jal       set_background_color_blend
/* 79743C 802A147C 0080382D */   daddu    $a3, $a0, $zero
/* 797440 802A1480 24020002 */  addiu     $v0, $zero, 2
.L802A1484:
/* 797444 802A1484 8FBF0014 */  lw        $ra, 0x14($sp)
/* 797448 802A1488 8FB00010 */  lw        $s0, 0x10($sp)
/* 79744C 802A148C 03E00008 */  jr        $ra
/* 797450 802A1490 27BD0018 */   addiu    $sp, $sp, 0x18
