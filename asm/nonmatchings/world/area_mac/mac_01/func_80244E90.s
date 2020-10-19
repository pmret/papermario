.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244E90
/* 805710 80244E90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 805714 80244E94 AFB60028 */  sw        $s6, 0x28($sp)
/* 805718 80244E98 0080B02D */  daddu     $s6, $a0, $zero
/* 80571C 80244E9C AFB50024 */  sw        $s5, 0x24($sp)
/* 805720 80244EA0 3C158011 */  lui       $s5, %hi(gPlayerData)
/* 805724 80244EA4 26B5F290 */  addiu     $s5, $s5, %lo(gPlayerData)
/* 805728 80244EA8 AFB20018 */  sw        $s2, 0x18($sp)
/* 80572C 80244EAC 2412FFFF */  addiu     $s2, $zero, -1
/* 805730 80244EB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 805734 80244EB4 0000802D */  daddu     $s0, $zero, $zero
/* 805738 80244EB8 AFB40020 */  sw        $s4, 0x20($sp)
/* 80573C 80244EBC 3C14F840 */  lui       $s4, 0xf840
/* 805740 80244EC0 36945C19 */  ori       $s4, $s4, 0x5c19
/* 805744 80244EC4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 805748 80244EC8 3C13F840 */  lui       $s3, 0xf840
/* 80574C 80244ECC 36735C2C */  ori       $s3, $s3, 0x5c2c
/* 805750 80244ED0 AFB10014 */  sw        $s1, 0x14($sp)
/* 805754 80244ED4 3C118025 */  lui       $s1, 0x8025
/* 805758 80244ED8 26316ADC */  addiu     $s1, $s1, 0x6adc
/* 80575C 80244EDC AFBF002C */  sw        $ra, 0x2c($sp)
.L80244EE0:
/* 805760 80244EE0 8E220000 */  lw        $v0, ($s1)
/* 805764 80244EE4 000210C0 */  sll       $v0, $v0, 3
/* 805768 80244EE8 02A21021 */  addu      $v0, $s5, $v0
/* 80576C 80244EEC 90420014 */  lbu       $v0, 0x14($v0)
/* 805770 80244EF0 1040000A */  beqz      $v0, .L80244F1C
/* 805774 80244EF4 0000202D */   daddu    $a0, $zero, $zero
/* 805778 80244EF8 0C0B1EAF */  jal       get_variable
/* 80577C 80244EFC 02142821 */   addu     $a1, $s0, $s4
/* 805780 80244F00 10400006 */  beqz      $v0, .L80244F1C
/* 805784 80244F04 0000202D */   daddu    $a0, $zero, $zero
/* 805788 80244F08 0C0B1EAF */  jal       get_variable
/* 80578C 80244F0C 02132821 */   addu     $a1, $s0, $s3
/* 805790 80244F10 10400006 */  beqz      $v0, .L80244F2C
/* 805794 80244F14 24120001 */   addiu    $s2, $zero, 1
/* 805798 80244F18 0000902D */  daddu     $s2, $zero, $zero
.L80244F1C:
/* 80579C 80244F1C 26100001 */  addiu     $s0, $s0, 1
/* 8057A0 80244F20 2E020013 */  sltiu     $v0, $s0, 0x13
/* 8057A4 80244F24 1440FFEE */  bnez      $v0, .L80244EE0
/* 8057A8 80244F28 26310014 */   addiu    $s1, $s1, 0x14
.L80244F2C:
/* 8057AC 80244F2C AED20084 */  sw        $s2, 0x84($s6)
/* 8057B0 80244F30 8FBF002C */  lw        $ra, 0x2c($sp)
/* 8057B4 80244F34 8FB60028 */  lw        $s6, 0x28($sp)
/* 8057B8 80244F38 8FB50024 */  lw        $s5, 0x24($sp)
/* 8057BC 80244F3C 8FB40020 */  lw        $s4, 0x20($sp)
/* 8057C0 80244F40 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8057C4 80244F44 8FB20018 */  lw        $s2, 0x18($sp)
/* 8057C8 80244F48 8FB10014 */  lw        $s1, 0x14($sp)
/* 8057CC 80244F4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8057D0 80244F50 24020002 */  addiu     $v0, $zero, 2
/* 8057D4 80244F54 03E00008 */  jr        $ra
/* 8057D8 80244F58 27BD0030 */   addiu    $sp, $sp, 0x30
