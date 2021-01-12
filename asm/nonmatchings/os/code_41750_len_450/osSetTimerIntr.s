.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSetTimerIntr
/* 41A10 80066610 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 41A14 80066614 AFB30020 */  sw        $s3, 0x20($sp)
/* 41A18 80066618 AFB2001C */  sw        $s2, 0x1c($sp)
/* 41A1C 8006661C 00809021 */  addu      $s2, $a0, $zero
/* 41A20 80066620 00A09821 */  addu      $s3, $a1, $zero
/* 41A24 80066624 AFBF0024 */  sw        $ra, 0x24($sp)
/* 41A28 80066628 16400007 */  bnez      $s2, .L80066648
/* 41A2C 8006662C AFB00018 */   sw       $s0, 0x18($sp)
/* 41A30 80066630 16400003 */  bnez      $s2, .L80066640
/* 41A34 80066634 2E6201D4 */   sltiu    $v0, $s3, 0x1d4
/* 41A38 80066638 10400003 */  beqz      $v0, .L80066648
/* 41A3C 8006663C 00000000 */   nop
.L80066640:
/* 41A40 80066640 24120000 */  addiu     $s2, $zero, 0
/* 41A44 80066644 241301D4 */  addiu     $s3, $zero, 0x1d4
.L80066648:
/* 41A48 80066648 0C01ACD8 */  jal       __osDisableInt
/* 41A4C 8006664C 00000000 */   nop
/* 41A50 80066650 0C019680 */  jal       osGetCount
/* 41A54 80066654 00408021 */   addu     $s0, $v0, $zero
/* 41A58 80066658 3C01800A */  lui       $at, %hi(D_8009A62C)
/* 41A5C 8006665C AC22A62C */  sw        $v0, %lo(D_8009A62C)($at)
/* 41A60 80066660 00402821 */  addu      $a1, $v0, $zero
/* 41A64 80066664 00002021 */  addu      $a0, $zero, $zero
/* 41A68 80066668 0C01B1A0 */  jal       osSetCompare
/* 41A6C 8006666C 02652021 */   addu     $a0, $s3, $a1
/* 41A70 80066670 0C01ACF4 */  jal       __osRestoreInt
/* 41A74 80066674 02002021 */   addu     $a0, $s0, $zero
/* 41A78 80066678 8FBF0024 */  lw        $ra, 0x24($sp)
/* 41A7C 8006667C 8FB30020 */  lw        $s3, 0x20($sp)
/* 41A80 80066680 8FB2001C */  lw        $s2, 0x1c($sp)
/* 41A84 80066684 8FB00018 */  lw        $s0, 0x18($sp)
/* 41A88 80066688 03E00008 */  jr        $ra
/* 41A8C 8006668C 27BD0028 */   addiu    $sp, $sp, 0x28
