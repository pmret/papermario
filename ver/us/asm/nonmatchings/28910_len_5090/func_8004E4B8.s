.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_800988C0
.word 0x8004E5A8, 0x8004E54C, 0x8004E574, 0x8004E584, 0x8004E594, 0x00000000

.section .text

glabel func_8004E4B8
/* 298B8 8004E4B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 298BC 8004E4BC AFB00010 */  sw        $s0, 0x10($sp)
/* 298C0 8004E4C0 0080802D */  daddu     $s0, $a0, $zero
/* 298C4 8004E4C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 298C8 8004E4C8 24110001 */  addiu     $s1, $zero, 1
/* 298CC 8004E4CC AFB20018 */  sw        $s2, 0x18($sp)
/* 298D0 8004E4D0 0000902D */  daddu     $s2, $zero, $zero
/* 298D4 8004E4D4 AFB40020 */  sw        $s4, 0x20($sp)
/* 298D8 8004E4D8 3C14800A */  lui       $s4, %hi(D_800988C0)
/* 298DC 8004E4DC 269488C0 */  addiu     $s4, $s4, %lo(D_800988C0)
/* 298E0 8004E4E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 298E4 8004E4E4 24130001 */  addiu     $s3, $zero, 1
/* 298E8 8004E4E8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 298EC 8004E4EC 96020052 */  lhu       $v0, 0x52($s0)
/* 298F0 8004E4F0 9603001A */  lhu       $v1, 0x1a($s0)
/* 298F4 8004E4F4 8E040018 */  lw        $a0, 0x18($s0)
/* 298F8 8004E4F8 00431021 */  addu      $v0, $v0, $v1
/* 298FC 8004E4FC 96030016 */  lhu       $v1, 0x16($s0)
/* 29900 8004E500 00042100 */  sll       $a0, $a0, 4
/* 29904 8004E504 00431021 */  addu      $v0, $v0, $v1
/* 29908 8004E508 96030056 */  lhu       $v1, 0x56($s0)
/* 2990C 8004E50C 3084FFFF */  andi      $a0, $a0, 0xffff
/* 29910 8004E510 AE020050 */  sw        $v0, 0x50($s0)
/* 29914 8004E514 8E020014 */  lw        $v0, 0x14($s0)
/* 29918 8004E518 00641821 */  addu      $v1, $v1, $a0
/* 2991C 8004E51C 00021103 */  sra       $v0, $v0, 4
/* 29920 8004E520 3042FFFF */  andi      $v0, $v0, 0xffff
/* 29924 8004E524 00621821 */  addu      $v1, $v1, $v0
/* 29928 8004E528 AE030054 */  sw        $v1, 0x54($s0)
.L8004E52C:
/* 2992C 8004E52C 92030221 */  lbu       $v1, 0x221($s0)
/* 29930 8004E530 2C620005 */  sltiu     $v0, $v1, 5
/* 29934 8004E534 1040001B */  beqz      $v0, .L8004E5A4
/* 29938 8004E538 00031080 */   sll      $v0, $v1, 2
/* 2993C 8004E53C 00541021 */  addu      $v0, $v0, $s4
/* 29940 8004E540 8C420000 */  lw        $v0, ($v0)
/* 29944 8004E544 00400008 */  jr        $v0
/* 29948 8004E548 00000000 */   nop
/* 2994C 8004E54C 92020220 */  lbu       $v0, 0x220($s0)
/* 29950 8004E550 54400016 */  bnel      $v0, $zero, .L8004E5AC
/* 29954 8004E554 0000882D */   daddu    $s1, $zero, $zero
/* 29958 8004E558 0C013B1A */  jal       func_8004EC68
/* 2995C 8004E55C 0200202D */   daddu    $a0, $s0, $zero
/* 29960 8004E560 92020221 */  lbu       $v0, 0x221($s0)
/* 29964 8004E564 14530012 */  bne       $v0, $s3, .L8004E5B0
/* 29968 8004E568 3222FFFF */   andi     $v0, $s1, 0xffff
/* 2996C 8004E56C 0801396B */  j         .L8004E5AC
/* 29970 8004E570 0000882D */   daddu    $s1, $zero, $zero
/* 29974 8004E574 0C013A41 */  jal       func_8004E904
/* 29978 8004E578 0200202D */   daddu    $a0, $s0, $zero
/* 2997C 8004E57C 0801396C */  j         .L8004E5B0
/* 29980 8004E580 3222FFFF */   andi     $v0, $s1, 0xffff
/* 29984 8004E584 0C013976 */  jal       snd_initialize_bgm_player
/* 29988 8004E588 0200202D */   daddu    $a0, $s0, $zero
/* 2998C 8004E58C 0801396B */  j         .L8004E5AC
/* 29990 8004E590 0000882D */   daddu    $s1, $zero, $zero
/* 29994 8004E594 0C013B01 */  jal       func_8004EC04
/* 29998 8004E598 0200202D */   daddu    $a0, $s0, $zero
/* 2999C 8004E59C 0801396C */  j         .L8004E5B0
/* 299A0 8004E5A0 3222FFFF */   andi     $v0, $s1, 0xffff
.L8004E5A4:
/* 299A4 8004E5A4 24120001 */  addiu     $s2, $zero, 1
/* 299A8 8004E5A8 0000882D */  daddu     $s1, $zero, $zero
.L8004E5AC:
/* 299AC 8004E5AC 3222FFFF */  andi      $v0, $s1, 0xffff
.L8004E5B0:
/* 299B0 8004E5B0 1440FFDE */  bnez      $v0, .L8004E52C
/* 299B4 8004E5B4 0240102D */   daddu    $v0, $s2, $zero
/* 299B8 8004E5B8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 299BC 8004E5BC 8FB40020 */  lw        $s4, 0x20($sp)
/* 299C0 8004E5C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 299C4 8004E5C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 299C8 8004E5C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 299CC 8004E5CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 299D0 8004E5D0 03E00008 */  jr        $ra
/* 299D4 8004E5D4 27BD0028 */   addiu    $sp, $sp, 0x28
