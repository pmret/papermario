.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsGetStatus
/* 448C0 800694C0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 448C4 800694C4 AFB20028 */  sw        $s2, 0x28($sp)
/* 448C8 800694C8 00809021 */  addu      $s2, $a0, $zero
/* 448CC 800694CC AFB3002C */  sw        $s3, 0x2c($sp)
/* 448D0 800694D0 00A09821 */  addu      $s3, $a1, $zero
/* 448D4 800694D4 02602021 */  addu      $a0, $s3, $zero
/* 448D8 800694D8 240200FA */  addiu     $v0, $zero, 0xfa
/* 448DC 800694DC AFBF0030 */  sw        $ra, 0x30($sp)
/* 448E0 800694E0 AFB10024 */  sw        $s1, 0x24($sp)
/* 448E4 800694E4 AFB00020 */  sw        $s0, 0x20($sp)
/* 448E8 800694E8 3C018009 */  lui       $at, %hi(D_800958D4)
/* 448EC 800694EC A02258D4 */  sb        $v0, %lo(D_800958D4)($at)
/* 448F0 800694F0 0C01A56C */  jal       osPfsRequestOneChannel
/* 448F4 800694F4 00002821 */   addu     $a1, $zero, $zero
/* 448F8 800694F8 24040001 */  addiu     $a0, $zero, 1
/* 448FC 800694FC 3C11800E */  lui       $s1, %hi(D_800DA000)
/* 44900 80069500 2631A000 */  addiu     $s1, $s1, %lo(D_800DA000)
/* 44904 80069504 0C019730 */  jal       osSiRawStartDma
/* 44908 80069508 02202821 */   addu     $a1, $s1, $zero
/* 4490C 8006950C 02402021 */  addu      $a0, $s2, $zero
/* 44910 80069510 27B00018 */  addiu     $s0, $sp, 0x18
/* 44914 80069514 02002821 */  addu      $a1, $s0, $zero
/* 44918 80069518 0C0195BC */  jal       osRecvMesg
/* 4491C 8006951C 24060001 */   addiu    $a2, $zero, 1
/* 44920 80069520 00002021 */  addu      $a0, $zero, $zero
/* 44924 80069524 0C019730 */  jal       osSiRawStartDma
/* 44928 80069528 02202821 */   addu     $a1, $s1, $zero
/* 4492C 8006952C 02402021 */  addu      $a0, $s2, $zero
/* 44930 80069530 02002821 */  addu      $a1, $s0, $zero
/* 44934 80069534 24060001 */  addiu     $a2, $zero, 1
/* 44938 80069538 0C0195BC */  jal       osRecvMesg
/* 4493C 8006953C 00408021 */   addu     $s0, $v0, $zero
/* 44940 80069540 02602021 */  addu      $a0, $s3, $zero
/* 44944 80069544 0C01A591 */  jal       osPfsGetOneChannelData
/* 44948 80069548 27A50010 */   addiu    $a1, $sp, 0x10
/* 4494C 8006954C 93A30012 */  lbu       $v1, 0x12($sp)
/* 44950 80069550 30620001 */  andi      $v0, $v1, 1
/* 44954 80069554 10400003 */  beqz      $v0, .L80069564
/* 44958 80069558 30620002 */   andi     $v0, $v1, 2
/* 4495C 8006955C 1440000D */  bnez      $v0, .L80069594
/* 44960 80069560 24020002 */   addiu    $v0, $zero, 2
.L80069564:
/* 44964 80069564 97A20012 */  lhu       $v0, 0x12($sp)
/* 44968 80069568 24030100 */  addiu     $v1, $zero, 0x100
/* 4496C 8006956C 304201FF */  andi      $v0, $v0, 0x1ff
/* 44970 80069570 10430003 */  beq       $v0, $v1, .L80069580
/* 44974 80069574 00000000 */   nop
/* 44978 80069578 0801A565 */  j         .L80069594
/* 4497C 8006957C 24020001 */   addiu    $v0, $zero, 1
.L80069580:
/* 44980 80069580 93A30012 */  lbu       $v1, 0x12($sp)
/* 44984 80069584 30630004 */  andi      $v1, $v1, 4
/* 44988 80069588 14600002 */  bnez      $v1, .L80069594
/* 4498C 8006958C 24020004 */   addiu    $v0, $zero, 4
/* 44990 80069590 02001021 */  addu      $v0, $s0, $zero
.L80069594:
/* 44994 80069594 8FBF0030 */  lw        $ra, 0x30($sp)
/* 44998 80069598 8FB3002C */  lw        $s3, 0x2c($sp)
/* 4499C 8006959C 8FB20028 */  lw        $s2, 0x28($sp)
/* 449A0 800695A0 8FB10024 */  lw        $s1, 0x24($sp)
/* 449A4 800695A4 8FB00020 */  lw        $s0, 0x20($sp)
/* 449A8 800695A8 03E00008 */  jr        $ra
/* 449AC 800695AC 27BD0038 */   addiu    $sp, $sp, 0x38
