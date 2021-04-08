.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F7C0
/* 3ABC0 8005F7C0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3ABC4 8005F7C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3ABC8 8005F7C8 0000882D */  daddu     $s1, $zero, $zero
/* 3ABCC 8005F7CC AFB40020 */  sw        $s4, 0x20($sp)
/* 3ABD0 8005F7D0 24140002 */  addiu     $s4, $zero, 2
/* 3ABD4 8005F7D4 AFB50024 */  sw        $s5, 0x24($sp)
/* 3ABD8 8005F7D8 24150001 */  addiu     $s5, $zero, 1
/* 3ABDC 8005F7DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 3ABE0 8005F7E0 0220982D */  daddu     $s3, $s1, $zero
/* 3ABE4 8005F7E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 3ABE8 8005F7E8 0220902D */  daddu     $s2, $s1, $zero
/* 3ABEC 8005F7EC AFBF0028 */  sw        $ra, 0x28($sp)
/* 3ABF0 8005F7F0 AFB00010 */  sw        $s0, 0x10($sp)
.L8005F7F4:
/* 3ABF4 8005F7F4 3C02800B */  lui       $v0, %hi(D_800B1D20)
/* 3ABF8 8005F7F8 24421D20 */  addiu     $v0, $v0, %lo(D_800B1D20)
/* 3ABFC 8005F7FC 02428021 */  addu      $s0, $s2, $v0
/* 3AC00 8005F800 92030007 */  lbu       $v1, 7($s0)
/* 3AC04 8005F804 10740015 */  beq       $v1, $s4, .L8005F85C
/* 3AC08 8005F808 28620003 */   slti     $v0, $v1, 3
/* 3AC0C 8005F80C 50400007 */  beql      $v0, $zero, .L8005F82C
/* 3AC10 8005F810 28620083 */   slti     $v0, $v1, 0x83
/* 3AC14 8005F814 5060003B */  beql      $v1, $zero, .L8005F904
/* 3AC18 8005F818 26730068 */   addiu    $s3, $s3, 0x68
/* 3AC1C 8005F81C 10750009 */  beq       $v1, $s5, .L8005F844
/* 3AC20 8005F820 0200202D */   daddu    $a0, $s0, $zero
/* 3AC24 8005F824 08017E41 */  j         .L8005F904
/* 3AC28 8005F828 26730068 */   addiu    $s3, $s3, 0x68
.L8005F82C:
/* 3AC2C 8005F82C 10400034 */  beqz      $v0, .L8005F900
/* 3AC30 8005F830 28620081 */   slti     $v0, $v1, 0x81
/* 3AC34 8005F834 54400033 */  bnel      $v0, $zero, .L8005F904
/* 3AC38 8005F838 26730068 */   addiu    $s3, $s3, 0x68
/* 3AC3C 8005F83C 08017E3A */  j         .L8005F8E8
/* 3AC40 8005F840 00000000 */   nop
.L8005F844:
/* 3AC44 8005F844 0C017D74 */  jal       func_8005F5D0
/* 3AC48 8005F848 0220282D */   daddu    $a1, $s1, $zero
/* 3AC4C 8005F84C 5440002C */  bnel      $v0, $zero, .L8005F900
/* 3AC50 8005F850 A2000007 */   sb       $zero, 7($s0)
/* 3AC54 8005F854 08017E41 */  j         .L8005F904
/* 3AC58 8005F858 26730068 */   addiu    $s3, $s3, 0x68
.L8005F85C:
/* 3AC5C 8005F85C 92020008 */  lbu       $v0, 8($s0)
/* 3AC60 8005F860 14400019 */  bnez      $v0, .L8005F8C8
/* 3AC64 8005F864 0200202D */   daddu    $a0, $s0, $zero
/* 3AC68 8005F868 96030004 */  lhu       $v1, 4($s0)
/* 3AC6C 8005F86C 3C028009 */  lui       $v0, %hi(D_80093CB0)
/* 3AC70 8005F870 8C423CB0 */  lw        $v0, %lo(D_80093CB0)($v0)
/* 3AC74 8005F874 14400002 */  bnez      $v0, .L8005F880
/* 3AC78 8005F878 0062001B */   divu     $zero, $v1, $v0
/* 3AC7C 8005F87C 0007000D */  break     7
.L8005F880:
/* 3AC80 8005F880 00001010 */   mfhi     $v0
/* 3AC84 8005F884 1440000C */  bnez      $v0, .L8005F8B8
/* 3AC88 8005F888 00000000 */   nop
/* 3AC8C 8005F88C 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3AC90 8005F890 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3AC94 8005F894 3C05800E */  lui       $a1, %hi(D_800DAAB8)
/* 3AC98 8005F898 24A5AAB8 */  addiu     $a1, $a1, %lo(D_800DAAB8)
/* 3AC9C 8005F89C 02652821 */  addu      $a1, $s3, $a1
/* 3ACA0 8005F8A0 0C019FC9 */  jal       func_80067F24
/* 3ACA4 8005F8A4 0220302D */   daddu    $a2, $s1, $zero
/* 3ACA8 8005F8A8 14400003 */  bnez      $v0, .L8005F8B8
/* 3ACAC 8005F8AC 00000000 */   nop
/* 3ACB0 8005F8B0 A2150008 */  sb        $s5, 8($s0)
/* 3ACB4 8005F8B4 A2140009 */  sb        $s4, 9($s0)
.L8005F8B8:
/* 3ACB8 8005F8B8 96020004 */  lhu       $v0, 4($s0)
/* 3ACBC 8005F8BC 24420001 */  addiu     $v0, $v0, 1
/* 3ACC0 8005F8C0 08017E40 */  j         .L8005F900
/* 3ACC4 8005F8C4 A6020004 */   sh       $v0, 4($s0)
.L8005F8C8:
/* 3ACC8 8005F8C8 0C017D74 */  jal       func_8005F5D0
/* 3ACCC 8005F8CC 0220282D */   daddu    $a1, $s1, $zero
/* 3ACD0 8005F8D0 5040000C */  beql      $v0, $zero, .L8005F904
/* 3ACD4 8005F8D4 26730068 */   addiu    $s3, $s3, 0x68
/* 3ACD8 8005F8D8 A6110004 */  sh        $s1, 4($s0)
/* 3ACDC 8005F8DC A2000008 */  sb        $zero, 8($s0)
/* 3ACE0 8005F8E0 08017E40 */  j         .L8005F900
/* 3ACE4 8005F8E4 A2000009 */   sb       $zero, 9($s0)
.L8005F8E8:
/* 3ACE8 8005F8E8 92020009 */  lbu       $v0, 9($s0)
/* 3ACEC 8005F8EC 54540005 */  bnel      $v0, $s4, .L8005F904
/* 3ACF0 8005F8F0 26730068 */   addiu    $s3, $s3, 0x68
/* 3ACF4 8005F8F4 0200202D */  daddu     $a0, $s0, $zero
/* 3ACF8 8005F8F8 0C017D74 */  jal       func_8005F5D0
/* 3ACFC 8005F8FC 0220282D */   daddu    $a1, $s1, $zero
.L8005F900:
/* 3AD00 8005F900 26730068 */  addiu     $s3, $s3, 0x68
.L8005F904:
/* 3AD04 8005F904 26310001 */  addiu     $s1, $s1, 1
/* 3AD08 8005F908 2E220004 */  sltiu     $v0, $s1, 4
/* 3AD0C 8005F90C 1440FFB9 */  bnez      $v0, .L8005F7F4
/* 3AD10 8005F910 2652000A */   addiu    $s2, $s2, 0xa
/* 3AD14 8005F914 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3AD18 8005F918 8FB50024 */  lw        $s5, 0x24($sp)
/* 3AD1C 8005F91C 8FB40020 */  lw        $s4, 0x20($sp)
/* 3AD20 8005F920 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3AD24 8005F924 8FB20018 */  lw        $s2, 0x18($sp)
/* 3AD28 8005F928 8FB10014 */  lw        $s1, 0x14($sp)
/* 3AD2C 8005F92C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3AD30 8005F930 0000102D */  daddu     $v0, $zero, $zero
/* 3AD34 8005F934 03E00008 */  jr        $ra
/* 3AD38 8005F938 27BD0030 */   addiu    $sp, $sp, 0x30
