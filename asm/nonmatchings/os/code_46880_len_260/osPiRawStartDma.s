.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osPiRawStartDma
/* 046880 8006B480 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 046884 8006B484 AFB00010 */  sw    $s0, 0x10($sp)
/* 046888 8006B488 00808021 */  addu  $s0, $a0, $zero
/* 04688C 8006B48C AFB10014 */  sw    $s1, 0x14($sp)
/* 046890 8006B490 00A08821 */  addu  $s1, $a1, $zero
/* 046894 8006B494 3C02A460 */  lui   $v0, 0xa460
/* 046898 8006B498 34420010 */  ori   $v0, $v0, 0x10
/* 04689C 8006B49C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0468A0 8006B4A0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0468A4 8006B4A4 8C420000 */  lw    $v0, ($v0)
/* 0468A8 8006B4A8 00C02021 */  addu  $a0, $a2, $zero
/* 0468AC 8006B4AC 30420003 */  andi  $v0, $v0, 3
/* 0468B0 8006B4B0 10400007 */  beqz  $v0, .L8006B4D0
/* 0468B4 8006B4B4 00E09021 */   addu  $s2, $a3, $zero
/* 0468B8 8006B4B8 3C03A460 */  lui   $v1, 0xa460
/* 0468BC 8006B4BC 34630010 */  ori   $v1, $v1, 0x10
.L8006B4C0:
/* 0468C0 8006B4C0 8C620000 */  lw    $v0, ($v1)
/* 0468C4 8006B4C4 30420003 */  andi  $v0, $v0, 3
/* 0468C8 8006B4C8 1440FFFD */  bnez  $v0, .L8006B4C0
/* 0468CC 8006B4CC 00000000 */   nop   
.L8006B4D0:
/* 0468D0 8006B4D0 0C0187A4 */  jal   osVirtualToPhysical
/* 0468D4 8006B4D4 00000000 */   nop   
/* 0468D8 8006B4D8 3C06A460 */  lui   $a2, 0xa460
/* 0468DC 8006B4DC 34C60004 */  ori   $a2, $a2, 4
/* 0468E0 8006B4E0 3C051FFF */  lui   $a1, 0x1fff
/* 0468E4 8006B4E4 3C038000 */  lui   $v1, 0x8000
/* 0468E8 8006B4E8 8C630308 */  lw    $v1, 0x308($v1)
/* 0468EC 8006B4EC 34A5FFFF */  ori   $a1, $a1, 0xffff
/* 0468F0 8006B4F0 3C04A460 */  lui   $a0, 0xa460
/* 0468F4 8006B4F4 AC820000 */  sw    $v0, ($a0)
/* 0468F8 8006B4F8 00711825 */  or    $v1, $v1, $s1
/* 0468FC 8006B4FC 00651824 */  and   $v1, $v1, $a1
/* 046900 8006B500 ACC30000 */  sw    $v1, ($a2)
/* 046904 8006B504 12000005 */  beqz  $s0, .L8006B51C
/* 046908 8006B508 24020001 */   addiu $v0, $zero, 1
/* 04690C 8006B50C 12020006 */  beq   $s0, $v0, .L8006B528
/* 046910 8006B510 3C03A460 */   lui   $v1, 0xa460
/* 046914 8006B514 0801AD4E */  j     .L8006B538
/* 046918 8006B518 2402FFFF */   addiu $v0, $zero, -1

.L8006B51C:
/* 04691C 8006B51C 3C03A460 */  lui   $v1, 0xa460
/* 046920 8006B520 0801AD4B */  j     .L8006B52C
/* 046924 8006B524 3463000C */   ori   $v1, $v1, 0xc

.L8006B528:
/* 046928 8006B528 34630008 */  ori   $v1, $v1, 8
.L8006B52C:
/* 04692C 8006B52C 2642FFFF */  addiu $v0, $s2, -1
/* 046930 8006B530 AC620000 */  sw    $v0, ($v1)
/* 046934 8006B534 00001021 */  addu  $v0, $zero, $zero
.L8006B538:
/* 046938 8006B538 8FBF001C */  lw    $ra, 0x1c($sp)
/* 04693C 8006B53C 8FB20018 */  lw    $s2, 0x18($sp)
/* 046940 8006B540 8FB10014 */  lw    $s1, 0x14($sp)
/* 046944 8006B544 8FB00010 */  lw    $s0, 0x10($sp)
/* 046948 8006B548 03E00008 */  jr    $ra
/* 04694C 8006B54C 27BD0020 */   addiu $sp, $sp, 0x20

