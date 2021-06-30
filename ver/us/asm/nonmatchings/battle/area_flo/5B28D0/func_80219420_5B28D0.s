.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219420_5B28D0
/* 5B28D0 80219420 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B28D4 80219424 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B28D8 80219428 0000902D */  daddu     $s2, $zero, $zero
/* 5B28DC 8021942C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B28E0 80219430 0240882D */  daddu     $s1, $s2, $zero
/* 5B28E4 80219434 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B28E8 80219438 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B28EC 8021943C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B28F0 80219440 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B28F4 80219444 3C108023 */  lui       $s0, %hi(D_802311D8_5CA688)
/* 5B28F8 80219448 261011D8 */  addiu     $s0, $s0, %lo(D_802311D8_5CA688)
/* 5B28FC 8021944C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219450:
/* 5B2900 80219450 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B2904 80219454 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B2908 80219458 8E050000 */  lw        $a1, ($s0)
/* 5B290C 8021945C 84430086 */  lh        $v1, 0x86($v0)
/* 5B2910 80219460 8442008C */  lh        $v0, 0x8c($v0)
/* 5B2914 80219464 00031900 */  sll       $v1, $v1, 4
/* 5B2918 80219468 00731821 */  addu      $v1, $v1, $s3
/* 5B291C 8021946C 8C630004 */  lw        $v1, 4($v1)
/* 5B2920 80219470 00021140 */  sll       $v0, $v0, 5
/* 5B2924 80219474 00431021 */  addu      $v0, $v0, $v1
/* 5B2928 80219478 0C01BB5C */  jal       strcmp
/* 5B292C 8021947C 8C440000 */   lw       $a0, ($v0)
/* 5B2930 80219480 14400003 */  bnez      $v0, .L80219490
/* 5B2934 80219484 26310001 */   addiu    $s1, $s1, 1
/* 5B2938 80219488 08086527 */  j         .L8021949C
/* 5B293C 8021948C 24120001 */   addiu    $s2, $zero, 1
.L80219490:
/* 5B2940 80219490 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2944 80219494 1440FFEE */  bnez      $v0, .L80219450
/* 5B2948 80219498 26100004 */   addiu    $s0, $s0, 4
.L8021949C:
/* 5B294C 8021949C 44800000 */  mtc1      $zero, $f0
/* 5B2950 802194A0 00000000 */  nop
/* 5B2954 802194A4 44050000 */  mfc1      $a1, $f0
/* 5B2958 802194A8 0240202D */  daddu     $a0, $s2, $zero
/* 5B295C 802194AC AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2960 802194B0 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2964 802194B4 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2968 802194B8 0C01CA54 */  jal       playFX_82
/* 5B296C 802194BC AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2970 802194C0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2974 802194C4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2978 802194C8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B297C 802194CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2980 802194D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2984 802194D4 24020002 */  addiu     $v0, $zero, 2
/* 5B2988 802194D8 03E00008 */  jr        $ra
/* 5B298C 802194DC 27BD0030 */   addiu    $sp, $sp, 0x30
