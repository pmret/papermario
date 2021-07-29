.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel check_for_conversation_prompt
/* 79A30 800E0580 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79A34 800E0584 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 79A38 800E0588 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 79A3C 800E058C AFBF0014 */  sw        $ra, 0x14($sp)
/* 79A40 800E0590 AFB00010 */  sw        $s0, 0x10($sp)
/* 79A44 800E0594 8C620004 */  lw        $v0, 4($v1)
/* 79A48 800E0598 30420100 */  andi      $v0, $v0, 0x100
/* 79A4C 800E059C 1440002A */  bnez      $v0, .L800E0648
/* 79A50 800E05A0 00000000 */   nop
/* 79A54 800E05A4 3C028011 */  lui       $v0, %hi(D_8010C958)
/* 79A58 800E05A8 8C42C958 */  lw        $v0, %lo(D_8010C958)($v0)
/* 79A5C 800E05AC 14400026 */  bnez      $v0, .L800E0648
/* 79A60 800E05B0 00000000 */   nop
/* 79A64 800E05B4 3C028011 */  lui       $v0, %hi(D_8010C920)
/* 79A68 800E05B8 8C42C920 */  lw        $v0, %lo(D_8010C920)($v0)
/* 79A6C 800E05BC 14400022 */  bnez      $v0, .L800E0648
/* 79A70 800E05C0 00000000 */   nop
/* 79A74 800E05C4 3C108011 */  lui       $s0, %hi(D_8010C940)
/* 79A78 800E05C8 2610C940 */  addiu     $s0, $s0, %lo(D_8010C940)
/* 79A7C 800E05CC 8E020000 */  lw        $v0, ($s0)
/* 79A80 800E05D0 14400019 */  bnez      $v0, .L800E0638
/* 79A84 800E05D4 00000000 */   nop
/* 79A88 800E05D8 80620015 */  lb        $v0, 0x15($v1)
/* 79A8C 800E05DC 1440001A */  bnez      $v0, .L800E0648
/* 79A90 800E05E0 00000000 */   nop
/* 79A94 800E05E4 8C620000 */  lw        $v0, ($v1)
/* 79A98 800E05E8 30420020 */  andi      $v0, $v0, 0x20
/* 79A9C 800E05EC 14400016 */  bnez      $v0, .L800E0648
/* 79AA0 800E05F0 00000000 */   nop
/* 79AA4 800E05F4 0C03814E */  jal       has_valid_conversation_npc
/* 79AA8 800E05F8 00000000 */   nop
/* 79AAC 800E05FC 14400003 */  bnez      $v0, .L800E060C
/* 79AB0 800E0600 3C06802B */   lui      $a2, 0x802b
/* 79AB4 800E0604 08038192 */  j         .L800E0648
/* 79AB8 800E0608 AE000000 */   sw       $zero, ($s0)
.L800E060C:
/* 79ABC 800E060C 34C67000 */  ori       $a2, $a2, 0x7000
/* 79AC0 800E0610 3C0400E2 */  lui       $a0, 0xe2
/* 79AC4 800E0614 24840EB0 */  addiu     $a0, $a0, 0xeb0
/* 79AC8 800E0618 3C0500E2 */  lui       $a1, 0xe2
/* 79ACC 800E061C 24A51870 */  addiu     $a1, $a1, 0x1870
/* 79AD0 800E0620 0C00A5CF */  jal       dma_copy
/* 79AD4 800E0624 AE000000 */   sw       $zero, ($s0)
/* 79AD8 800E0628 3C02802B */  lui       $v0, %hi(func_802B70B4_E201C4)
/* 79ADC 800E062C 244270B4 */  addiu     $v0, $v0, %lo(func_802B70B4_E201C4)
/* 79AE0 800E0630 10400005 */  beqz      $v0, .L800E0648
/* 79AE4 800E0634 AE020000 */   sw       $v0, ($s0)
.L800E0638:
/* 79AE8 800E0638 3C028011 */  lui       $v0, %hi(D_8010C940)
/* 79AEC 800E063C 8C42C940 */  lw        $v0, %lo(D_8010C940)($v0)
/* 79AF0 800E0640 0040F809 */  jalr      $v0
/* 79AF4 800E0644 00000000 */   nop
.L800E0648:
/* 79AF8 800E0648 8FBF0014 */  lw        $ra, 0x14($sp)
/* 79AFC 800E064C 8FB00010 */  lw        $s0, 0x10($sp)
/* 79B00 800E0650 03E00008 */  jr        $ra
/* 79B04 800E0654 27BD0018 */   addiu    $sp, $sp, 0x18
