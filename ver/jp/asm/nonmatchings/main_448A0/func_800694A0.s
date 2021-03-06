.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800694A0
/* 448A0 800694A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 448A4 800694A4 AFB20028 */  sw        $s2, 0x28($sp)
/* 448A8 800694A8 00809021 */  addu      $s2, $a0, $zero
/* 448AC 800694AC AFB3002C */  sw        $s3, 0x2c($sp)
/* 448B0 800694B0 00A09821 */  addu      $s3, $a1, $zero
/* 448B4 800694B4 02602021 */  addu      $a0, $s3, $zero
/* 448B8 800694B8 240200FA */  addiu     $v0, $zero, 0xfa
/* 448BC 800694BC AFBF0030 */  sw        $ra, 0x30($sp)
/* 448C0 800694C0 AFB10024 */  sw        $s1, 0x24($sp)
/* 448C4 800694C4 AFB00020 */  sw        $s0, 0x20($sp)
/* 448C8 800694C8 3C018009 */  lui       $at, %hi(D_80095864)
/* 448CC 800694CC A0225864 */  sb        $v0, %lo(D_80095864)($at)
/* 448D0 800694D0 0C01A564 */  jal       func_80069590
/* 448D4 800694D4 00002821 */   addu     $a1, $zero, $zero
/* 448D8 800694D8 24040001 */  addiu     $a0, $zero, 1
/* 448DC 800694DC 3C11800E */  lui       $s1, %hi(D_800D9FE0)
/* 448E0 800694E0 26319FE0 */  addiu     $s1, $s1, %lo(D_800D9FE0)
/* 448E4 800694E4 0C019724 */  jal       func_80065C90
/* 448E8 800694E8 02202821 */   addu     $a1, $s1, $zero
/* 448EC 800694EC 02402021 */  addu      $a0, $s2, $zero
/* 448F0 800694F0 27B00018 */  addiu     $s0, $sp, 0x18
/* 448F4 800694F4 02002821 */  addu      $a1, $s0, $zero
/* 448F8 800694F8 0C0195B0 */  jal       func_800656C0
/* 448FC 800694FC 24060001 */   addiu    $a2, $zero, 1
/* 44900 80069500 00002021 */  addu      $a0, $zero, $zero
/* 44904 80069504 0C019724 */  jal       func_80065C90
/* 44908 80069508 02202821 */   addu     $a1, $s1, $zero
/* 4490C 8006950C 02402021 */  addu      $a0, $s2, $zero
/* 44910 80069510 02002821 */  addu      $a1, $s0, $zero
/* 44914 80069514 24060001 */  addiu     $a2, $zero, 1
/* 44918 80069518 0C0195B0 */  jal       func_800656C0
/* 4491C 8006951C 00408021 */   addu     $s0, $v0, $zero
/* 44920 80069520 02602021 */  addu      $a0, $s3, $zero
/* 44924 80069524 0C01A589 */  jal       func_80069624
/* 44928 80069528 27A50010 */   addiu    $a1, $sp, 0x10
/* 4492C 8006952C 93A30012 */  lbu       $v1, 0x12($sp)
/* 44930 80069530 30620001 */  andi      $v0, $v1, 1
/* 44934 80069534 10400003 */  beqz      $v0, .L80069544
/* 44938 80069538 30620002 */   andi     $v0, $v1, 2
/* 4493C 8006953C 1440000D */  bnez      $v0, .L80069574
/* 44940 80069540 24020002 */   addiu    $v0, $zero, 2
.L80069544:
/* 44944 80069544 97A20012 */  lhu       $v0, 0x12($sp)
/* 44948 80069548 24030100 */  addiu     $v1, $zero, 0x100
/* 4494C 8006954C 304201FF */  andi      $v0, $v0, 0x1ff
/* 44950 80069550 10430003 */  beq       $v0, $v1, .L80069560
/* 44954 80069554 00000000 */   nop
/* 44958 80069558 0801A55D */  j         .L80069574
/* 4495C 8006955C 24020001 */   addiu    $v0, $zero, 1
.L80069560:
/* 44960 80069560 93A30012 */  lbu       $v1, 0x12($sp)
/* 44964 80069564 30630004 */  andi      $v1, $v1, 4
/* 44968 80069568 14600002 */  bnez      $v1, .L80069574
/* 4496C 8006956C 24020004 */   addiu    $v0, $zero, 4
/* 44970 80069570 02001021 */  addu      $v0, $s0, $zero
.L80069574:
/* 44974 80069574 8FBF0030 */  lw        $ra, 0x30($sp)
/* 44978 80069578 8FB3002C */  lw        $s3, 0x2c($sp)
/* 4497C 8006957C 8FB20028 */  lw        $s2, 0x28($sp)
/* 44980 80069580 8FB10024 */  lw        $s1, 0x24($sp)
/* 44984 80069584 8FB00020 */  lw        $s0, 0x20($sp)
/* 44988 80069588 03E00008 */  jr        $ra
/* 4498C 8006958C 27BD0038 */   addiu    $sp, $sp, 0x38
