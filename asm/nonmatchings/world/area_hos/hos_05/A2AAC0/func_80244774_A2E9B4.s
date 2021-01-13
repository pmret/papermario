.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244774_A2E9B4
/* A2E9B4 80244774 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A2E9B8 80244778 AFB00018 */  sw        $s0, 0x18($sp)
/* A2E9BC 8024477C 0080802D */  daddu     $s0, $a0, $zero
/* A2E9C0 80244780 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2E9C4 80244784 00A0882D */  daddu     $s1, $a1, $zero
/* A2E9C8 80244788 AFBF0028 */  sw        $ra, 0x28($sp)
/* A2E9CC 8024478C AFB30024 */  sw        $s3, 0x24($sp)
/* A2E9D0 80244790 AFB20020 */  sw        $s2, 0x20($sp)
/* A2E9D4 80244794 F7B40030 */  sdc1      $f20, 0x30($sp)
/* A2E9D8 80244798 0C0B36B0 */  jal       resolve_npc
/* A2E9DC 8024479C 24050007 */   addiu    $a1, $zero, 7
/* A2E9E0 802447A0 0200202D */  daddu     $a0, $s0, $zero
/* A2E9E4 802447A4 24050008 */  addiu     $a1, $zero, 8
/* A2E9E8 802447A8 0C0B36B0 */  jal       resolve_npc
/* A2E9EC 802447AC 0040902D */   daddu    $s2, $v0, $zero
/* A2E9F0 802447B0 12200004 */  beqz      $s1, .L802447C4
/* A2E9F4 802447B4 0040982D */   daddu    $s3, $v0, $zero
/* A2E9F8 802447B8 C640003C */  lwc1      $f0, 0x3c($s2)
/* A2E9FC 802447BC 3C018025 */  lui       $at, %hi(D_8024F374)
/* A2EA00 802447C0 E420F374 */  swc1      $f0, %lo(D_8024F374)($at)
.L802447C4:
/* A2EA04 802447C4 3C018025 */  lui       $at, %hi(D_8024F374)
/* A2EA08 802447C8 C420F374 */  lwc1      $f0, %lo(D_8024F374)($at)
/* A2EA0C 802447CC 24040003 */  addiu     $a0, $zero, 3
/* A2EA10 802447D0 44050000 */  mfc1      $a1, $f0
/* A2EA14 802447D4 3C0143FA */  lui       $at, 0x43fa
/* A2EA18 802447D8 44810000 */  mtc1      $at, $f0
/* A2EA1C 802447DC 44853000 */  mtc1      $a1, $f6
/* A2EA20 802447E0 3C108025 */  lui       $s0, %hi(D_8024AEC4)
/* A2EA24 802447E4 2610AEC4 */  addiu     $s0, $s0, %lo(D_8024AEC4)
/* A2EA28 802447E8 46003180 */  add.s     $f6, $f6, $f0
/* A2EA2C 802447EC 3C014220 */  lui       $at, 0x4220
/* A2EA30 802447F0 4481A000 */  mtc1      $at, $f20
/* A2EA34 802447F4 8E070000 */  lw        $a3, ($s0)
/* A2EA38 802447F8 44063000 */  mfc1      $a2, $f6
/* A2EA3C 802447FC 2642003C */  addiu     $v0, $s2, 0x3c
/* A2EA40 80244800 AFA20014 */  sw        $v0, 0x14($sp)
/* A2EA44 80244804 0C090439 */  jal       func_802410E4_A2B324
/* A2EA48 80244808 E7B40010 */   swc1     $f20, 0x10($sp)
/* A2EA4C 8024480C C640003C */  lwc1      $f0, 0x3c($s2)
/* A2EA50 80244810 3C013F80 */  lui       $at, 0x3f80
/* A2EA54 80244814 44811000 */  mtc1      $at, $f2
/* A2EA58 80244818 E660003C */  swc1      $f0, 0x3c($s3)
/* A2EA5C 8024481C C6000000 */  lwc1      $f0, ($s0)
/* A2EA60 80244820 C644003C */  lwc1      $f4, 0x3c($s2)
/* A2EA64 80244824 46020000 */  add.s     $f0, $f0, $f2
/* A2EA68 80244828 E6440070 */  swc1      $f4, 0x70($s2)
/* A2EA6C 8024482C C662003C */  lwc1      $f2, 0x3c($s3)
/* A2EA70 80244830 24020001 */  addiu     $v0, $zero, 1
/* A2EA74 80244834 E6620070 */  swc1      $f2, 0x70($s3)
/* A2EA78 80244838 4600A03C */  c.lt.s    $f20, $f0
/* A2EA7C 8024483C 00000000 */  nop
/* A2EA80 80244840 45010002 */  bc1t      .L8024484C
/* A2EA84 80244844 E6000000 */   swc1     $f0, ($s0)
/* A2EA88 80244848 0000102D */  daddu     $v0, $zero, $zero
.L8024484C:
/* A2EA8C 8024484C 8FBF0028 */  lw        $ra, 0x28($sp)
/* A2EA90 80244850 8FB30024 */  lw        $s3, 0x24($sp)
/* A2EA94 80244854 8FB20020 */  lw        $s2, 0x20($sp)
/* A2EA98 80244858 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2EA9C 8024485C 8FB00018 */  lw        $s0, 0x18($sp)
/* A2EAA0 80244860 D7B40030 */  ldc1      $f20, 0x30($sp)
/* A2EAA4 80244864 03E00008 */  jr        $ra
/* A2EAA8 80244868 27BD0038 */   addiu    $sp, $sp, 0x38
