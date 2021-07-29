.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPiRawStartDma
/* 46880 8006B480 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 46884 8006B484 AFB00010 */  sw        $s0, 0x10($sp)
/* 46888 8006B488 00808021 */  addu      $s0, $a0, $zero
/* 4688C 8006B48C AFB10014 */  sw        $s1, 0x14($sp)
/* 46890 8006B490 00A08821 */  addu      $s1, $a1, $zero
/* 46894 8006B494 3C02A460 */  lui       $v0, 0xa460
/* 46898 8006B498 34420010 */  ori       $v0, $v0, 0x10
/* 4689C 8006B49C AFBF001C */  sw        $ra, 0x1c($sp)
/* 468A0 8006B4A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 468A4 8006B4A4 8C420000 */  lw        $v0, ($v0)
/* 468A8 8006B4A8 00C02021 */  addu      $a0, $a2, $zero
/* 468AC 8006B4AC 30420003 */  andi      $v0, $v0, 3
/* 468B0 8006B4B0 10400007 */  beqz      $v0, .L8006B4D0
/* 468B4 8006B4B4 00E09021 */   addu     $s2, $a3, $zero
/* 468B8 8006B4B8 3C03A460 */  lui       $v1, 0xa460
/* 468BC 8006B4BC 34630010 */  ori       $v1, $v1, 0x10
.L8006B4C0:
/* 468C0 8006B4C0 8C620000 */  lw        $v0, ($v1)
/* 468C4 8006B4C4 30420003 */  andi      $v0, $v0, 3
/* 468C8 8006B4C8 1440FFFD */  bnez      $v0, .L8006B4C0
/* 468CC 8006B4CC 00000000 */   nop
.L8006B4D0:
/* 468D0 8006B4D0 0C0187A4 */  jal       osVirtualToPhysical
/* 468D4 8006B4D4 00000000 */   nop
/* 468D8 8006B4D8 3C06A460 */  lui       $a2, 0xa460
/* 468DC 8006B4DC 34C60004 */  ori       $a2, $a2, 4
/* 468E0 8006B4E0 3C051FFF */  lui       $a1, 0x1fff
/* 468E4 8006B4E4 3C038000 */  lui       $v1, %hi(D_80000308)
/* 468E8 8006B4E8 8C630308 */  lw        $v1, %lo(D_80000308)($v1)
/* 468EC 8006B4EC 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 468F0 8006B4F0 3C04A460 */  lui       $a0, 0xa460
/* 468F4 8006B4F4 AC820000 */  sw        $v0, ($a0)
/* 468F8 8006B4F8 00711825 */  or        $v1, $v1, $s1
/* 468FC 8006B4FC 00651824 */  and       $v1, $v1, $a1
/* 46900 8006B500 ACC30000 */  sw        $v1, ($a2)
/* 46904 8006B504 12000005 */  beqz      $s0, .L8006B51C
/* 46908 8006B508 24020001 */   addiu    $v0, $zero, 1
/* 4690C 8006B50C 12020006 */  beq       $s0, $v0, .L8006B528
/* 46910 8006B510 3C03A460 */   lui      $v1, 0xa460
/* 46914 8006B514 0801AD4E */  j         .L8006B538
/* 46918 8006B518 2402FFFF */   addiu    $v0, $zero, -1
.L8006B51C:
/* 4691C 8006B51C 3C03A460 */  lui       $v1, 0xa460
/* 46920 8006B520 0801AD4B */  j         .L8006B52C
/* 46924 8006B524 3463000C */   ori      $v1, $v1, 0xc
.L8006B528:
/* 46928 8006B528 34630008 */  ori       $v1, $v1, 8
.L8006B52C:
/* 4692C 8006B52C 2642FFFF */  addiu     $v0, $s2, -1
/* 46930 8006B530 AC620000 */  sw        $v0, ($v1)
/* 46934 8006B534 00001021 */  addu      $v0, $zero, $zero
.L8006B538:
/* 46938 8006B538 8FBF001C */  lw        $ra, 0x1c($sp)
/* 4693C 8006B53C 8FB20018 */  lw        $s2, 0x18($sp)
/* 46940 8006B540 8FB10014 */  lw        $s1, 0x14($sp)
/* 46944 8006B544 8FB00010 */  lw        $s0, 0x10($sp)
/* 46948 8006B548 03E00008 */  jr        $ra
/* 4694C 8006B54C 27BD0020 */   addiu    $sp, $sp, 0x20
