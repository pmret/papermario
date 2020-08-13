.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSetTimerIntr
/* 041A10 80066610 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 041A14 80066614 AFB30020 */  sw    $s3, 0x20($sp)
/* 041A18 80066618 AFB2001C */  sw    $s2, 0x1c($sp)
/* 041A1C 8006661C 00809021 */  addu  $s2, $a0, $zero
/* 041A20 80066620 00A09821 */  addu  $s3, $a1, $zero
/* 041A24 80066624 AFBF0024 */  sw    $ra, 0x24($sp)
/* 041A28 80066628 16400007 */  bnez  $s2, .L80066648
/* 041A2C 8006662C AFB00018 */   sw    $s0, 0x18($sp)
/* 041A30 80066630 16400003 */  bnez  $s2, .L80066640
/* 041A34 80066634 2E6201D4 */   sltiu $v0, $s3, 0x1d4
/* 041A38 80066638 10400003 */  beqz  $v0, .L80066648
/* 041A3C 8006663C 00000000 */   nop   
.L80066640:
/* 041A40 80066640 24120000 */  addiu $s2, $zero, 0
/* 041A44 80066644 241301D4 */  addiu $s3, $zero, 0x1d4
.L80066648:
/* 041A48 80066648 0C01ACD8 */  jal   __osDisableInt
/* 041A4C 8006664C 00000000 */   nop   
/* 041A50 80066650 0C019680 */  jal   osGetCount
/* 041A54 80066654 00408021 */   addu  $s0, $v0, $zero
/* 041A58 80066658 3C01800A */  lui   $at, 0x800a
/* 041A5C 8006665C AC22A62C */  sw    $v0, -0x59d4($at)
/* 041A60 80066660 00402821 */  addu  $a1, $v0, $zero
/* 041A64 80066664 00002021 */  addu  $a0, $zero, $zero
/* 041A68 80066668 0C01B1A0 */  jal   osSetCompare
/* 041A6C 8006666C 02652021 */   addu  $a0, $s3, $a1
/* 041A70 80066670 0C01ACF4 */  jal   __osRestoreInt
/* 041A74 80066674 02002021 */   addu  $a0, $s0, $zero
/* 041A78 80066678 8FBF0024 */  lw    $ra, 0x24($sp)
/* 041A7C 8006667C 8FB30020 */  lw    $s3, 0x20($sp)
/* 041A80 80066680 8FB2001C */  lw    $s2, 0x1c($sp)
/* 041A84 80066684 8FB00018 */  lw    $s0, 0x18($sp)
/* 041A88 80066688 03E00008 */  jr    $ra
/* 041A8C 8006668C 27BD0028 */   addiu $sp, $sp, 0x28

