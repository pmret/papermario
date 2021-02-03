.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1438_733508
/* 733508 802A1438 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 73350C 802A143C AFB1001C */  sw        $s1, 0x1c($sp)
/* 733510 802A1440 0080882D */  daddu     $s1, $a0, $zero
/* 733514 802A1444 AFBF0028 */  sw        $ra, 0x28($sp)
/* 733518 802A1448 AFB30024 */  sw        $s3, 0x24($sp)
/* 73351C 802A144C AFB20020 */  sw        $s2, 0x20($sp)
/* 733520 802A1450 AFB00018 */  sw        $s0, 0x18($sp)
/* 733524 802A1454 8E30000C */  lw        $s0, 0xc($s1)
/* 733528 802A1458 8E050000 */  lw        $a1, ($s0)
/* 73352C 802A145C 0C0B1EAF */  jal       get_variable
/* 733530 802A1460 26100004 */   addiu    $s0, $s0, 4
/* 733534 802A1464 8E050000 */  lw        $a1, ($s0)
/* 733538 802A1468 26100004 */  addiu     $s0, $s0, 4
/* 73353C 802A146C 0220202D */  daddu     $a0, $s1, $zero
/* 733540 802A1470 0C0B1EAF */  jal       get_variable
/* 733544 802A1474 0040982D */   daddu    $s3, $v0, $zero
/* 733548 802A1478 8E050000 */  lw        $a1, ($s0)
/* 73354C 802A147C 26100004 */  addiu     $s0, $s0, 4
/* 733550 802A1480 0220202D */  daddu     $a0, $s1, $zero
/* 733554 802A1484 0C0B1EAF */  jal       get_variable
/* 733558 802A1488 0040902D */   daddu    $s2, $v0, $zero
/* 73355C 802A148C 0220202D */  daddu     $a0, $s1, $zero
/* 733560 802A1490 8E050000 */  lw        $a1, ($s0)
/* 733564 802A1494 0C0B1EAF */  jal       get_variable
/* 733568 802A1498 0040802D */   daddu    $s0, $v0, $zero
/* 73356C 802A149C 44930000 */  mtc1      $s3, $f0
/* 733570 802A14A0 00000000 */  nop
/* 733574 802A14A4 46800020 */  cvt.s.w   $f0, $f0
/* 733578 802A14A8 44050000 */  mfc1      $a1, $f0
/* 73357C 802A14AC 44920000 */  mtc1      $s2, $f0
/* 733580 802A14B0 00000000 */  nop
/* 733584 802A14B4 46800020 */  cvt.s.w   $f0, $f0
/* 733588 802A14B8 44060000 */  mfc1      $a2, $f0
/* 73358C 802A14BC 44900000 */  mtc1      $s0, $f0
/* 733590 802A14C0 00000000 */  nop
/* 733594 802A14C4 46800020 */  cvt.s.w   $f0, $f0
/* 733598 802A14C8 44070000 */  mfc1      $a3, $f0
/* 73359C 802A14CC 24040001 */  addiu     $a0, $zero, 1
/* 7335A0 802A14D0 0C01C424 */  jal       func_80071090
/* 7335A4 802A14D4 AFA20010 */   sw       $v0, 0x10($sp)
/* 7335A8 802A14D8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 7335AC 802A14DC 8FB30024 */  lw        $s3, 0x24($sp)
/* 7335B0 802A14E0 8FB20020 */  lw        $s2, 0x20($sp)
/* 7335B4 802A14E4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7335B8 802A14E8 8FB00018 */  lw        $s0, 0x18($sp)
/* 7335BC 802A14EC 24020002 */  addiu     $v0, $zero, 2
/* 7335C0 802A14F0 03E00008 */  jr        $ra
/* 7335C4 802A14F4 27BD0030 */   addiu    $sp, $sp, 0x30
