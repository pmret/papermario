.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800665E0
/* 419E0 800665E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 419E4 800665E4 AFB30020 */  sw        $s3, 0x20($sp)
/* 419E8 800665E8 AFB2001C */  sw        $s2, 0x1c($sp)
/* 419EC 800665EC 00809021 */  addu      $s2, $a0, $zero
/* 419F0 800665F0 00A09821 */  addu      $s3, $a1, $zero
/* 419F4 800665F4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 419F8 800665F8 16400007 */  bnez      $s2, .L80066618
/* 419FC 800665FC AFB00018 */   sw       $s0, 0x18($sp)
/* 41A00 80066600 16400003 */  bnez      $s2, .L80066610
/* 41A04 80066604 2E6201D4 */   sltiu    $v0, $s3, 0x1d4
/* 41A08 80066608 10400003 */  beqz      $v0, .L80066618
/* 41A0C 8006660C 00000000 */   nop
.L80066610:
/* 41A10 80066610 24120000 */  addiu     $s2, $zero, 0
/* 41A14 80066614 241301D4 */  addiu     $s3, $zero, 0x1d4
.L80066618:
/* 41A18 80066618 0C01ACD0 */  jal       func_8006B340
/* 41A1C 8006661C 00000000 */   nop
/* 41A20 80066620 0C019674 */  jal       func_800659D0
/* 41A24 80066624 00408021 */   addu     $s0, $v0, $zero
/* 41A28 80066628 3C01800A */  lui       $at, %hi(D_8009A60C)
/* 41A2C 8006662C AC22A60C */  sw        $v0, %lo(D_8009A60C)($at)
/* 41A30 80066630 00402821 */  addu      $a1, $v0, $zero
/* 41A34 80066634 00002021 */  addu      $a0, $zero, $zero
/* 41A38 80066638 0C01B198 */  jal       func_8006C660
/* 41A3C 8006663C 02652021 */   addu     $a0, $s3, $a1
/* 41A40 80066640 0C01ACEC */  jal       func_8006B3B0
/* 41A44 80066644 02002021 */   addu     $a0, $s0, $zero
/* 41A48 80066648 8FBF0024 */  lw        $ra, 0x24($sp)
/* 41A4C 8006664C 8FB30020 */  lw        $s3, 0x20($sp)
/* 41A50 80066650 8FB2001C */  lw        $s2, 0x1c($sp)
/* 41A54 80066654 8FB00018 */  lw        $s0, 0x18($sp)
/* 41A58 80066658 03E00008 */  jr        $ra
/* 41A5C 8006665C 27BD0028 */   addiu    $sp, $sp, 0x28
