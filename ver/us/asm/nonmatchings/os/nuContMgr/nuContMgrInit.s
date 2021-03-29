.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContMgrInit
/* 3B910 80060510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B914 80060514 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B918 80060518 0C01823C */  jal       nuContDataUnLock
/* 3B91C 8006051C 00000000 */   nop
/* 3B920 80060520 3C04800B */  lui       $a0, %hi(D_800B0EB8)
/* 3B924 80060524 24840EB8 */  addiu     $a0, $a0, %lo(D_800B0EB8)
/* 3B928 80060528 3C05800B */  lui       $a1, %hi(D_800AE6D0)
/* 3B92C 8006052C 24A5E6D0 */  addiu     $a1, $a1, %lo(D_800AE6D0)
/* 3B930 80060530 0C019560 */  jal       osCreateMesgQueue
/* 3B934 80060534 24060001 */   addiu    $a2, $zero, 1
/* 3B938 80060538 3C04800E */  lui       $a0, %hi(D_800DC040)
/* 3B93C 8006053C 2484C040 */  addiu     $a0, $a0, %lo(D_800DC040)
/* 3B940 80060540 3C05800B */  lui       $a1, %hi(D_800AE6D4)
/* 3B944 80060544 24A5E6D4 */  addiu     $a1, $a1, %lo(D_800AE6D4)
/* 3B948 80060548 0C019560 */  jal       osCreateMesgQueue
/* 3B94C 8006054C 24060001 */   addiu    $a2, $zero, 1
/* 3B950 80060550 3C048009 */  lui       $a0, %hi(nuContCallBack)
/* 3B954 80060554 0C0180FC */  jal       nuSiCallBackAdd
/* 3B958 80060558 24843D38 */   addiu    $a0, $a0, %lo(nuContCallBack)
/* 3B95C 8006055C 0C018248 */  jal       nuContQueryRead
/* 3B960 80060560 00000000 */   nop
/* 3B964 80060564 24050001 */  addiu     $a1, $zero, 1
/* 3B968 80060568 0000302D */  daddu     $a2, $zero, $zero
/* 3B96C 8006056C 0000202D */  daddu     $a0, $zero, $zero
/* 3B970 80060570 24070005 */  addiu     $a3, $zero, 5
/* 3B974 80060574 3C01800A */  lui       $at, %hi(D_8009A614)
/* 3B978 80060578 AC20A614 */  sw        $zero, %lo(D_8009A614)($at)
/* 3B97C 8006057C 00041880 */  sll       $v1, $a0, 2
.L80060580:
/* 3B980 80060580 3C02800B */  lui       $v0, %hi(D_800B1B7F)
/* 3B984 80060584 00431021 */  addu      $v0, $v0, $v1
/* 3B988 80060588 90421B7F */  lbu       $v0, %lo(D_800B1B7F)($v0)
/* 3B98C 8006058C 5440000F */  bnel      $v0, $zero, .L800605CC
/* 3B990 80060590 24840001 */   addiu    $a0, $a0, 1
/* 3B994 80060594 3C02800B */  lui       $v0, %hi(D_800B1B7C)
/* 3B998 80060598 00431021 */  addu      $v0, $v0, $v1
/* 3B99C 8006059C 94421B7C */  lhu       $v0, %lo(D_800B1B7C)($v0)
/* 3B9A0 800605A0 30421F07 */  andi      $v0, $v0, 0x1f07
/* 3B9A4 800605A4 54470008 */  bnel      $v0, $a3, .L800605C8
/* 3B9A8 800605A8 00052840 */   sll      $a1, $a1, 1
/* 3B9AC 800605AC 3C02800A */  lui       $v0, %hi(D_8009A614)
/* 3B9B0 800605B0 8C42A614 */  lw        $v0, %lo(D_8009A614)($v0)
/* 3B9B4 800605B4 00C53025 */  or        $a2, $a2, $a1
/* 3B9B8 800605B8 24420001 */  addiu     $v0, $v0, 1
/* 3B9BC 800605BC 3C01800A */  lui       $at, %hi(D_8009A614)
/* 3B9C0 800605C0 AC22A614 */  sw        $v0, %lo(D_8009A614)($at)
/* 3B9C4 800605C4 00052840 */  sll       $a1, $a1, 1
.L800605C8:
/* 3B9C8 800605C8 24840001 */  addiu     $a0, $a0, 1
.L800605CC:
/* 3B9CC 800605CC 28820004 */  slti      $v0, $a0, 4
/* 3B9D0 800605D0 1440FFEB */  bnez      $v0, .L80060580
/* 3B9D4 800605D4 00041880 */   sll      $v1, $a0, 2
/* 3B9D8 800605D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B9DC 800605DC 30C200FF */  andi      $v0, $a2, 0xff
/* 3B9E0 800605E0 03E00008 */  jr        $ra
/* 3B9E4 800605E4 27BD0018 */   addiu    $sp, $sp, 0x18
