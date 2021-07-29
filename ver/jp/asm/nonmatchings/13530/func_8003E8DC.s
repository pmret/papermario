.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E8DC
/* 19CDC 8003E8DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19CE0 8003E8E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19CE4 8003E8E4 0080982D */  daddu     $s3, $a0, $zero
/* 19CE8 8003E8E8 AFB40020 */  sw        $s4, 0x20($sp)
/* 19CEC 8003E8EC 00A0A02D */  daddu     $s4, $a1, $zero
/* 19CF0 8003E8F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 19CF4 8003E8F4 3C12800B */  lui       $s2, %hi(D_800B0EF0)
/* 19CF8 8003E8F8 26520EF0 */  addiu     $s2, $s2, %lo(D_800B0EF0)
/* 19CFC 8003E8FC AFBF0024 */  sw        $ra, 0x24($sp)
/* 19D00 8003E900 AFB10014 */  sw        $s1, 0x14($sp)
/* 19D04 8003E904 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D08 8003E908 8242001C */  lb        $v0, 0x1c($s2)
/* 19D0C 8003E90C 1840001E */  blez      $v0, .L8003E988
/* 19D10 8003E910 0000802D */   daddu    $s0, $zero, $zero
/* 19D14 8003E914 0240882D */  daddu     $s1, $s2, $zero
.L8003E918:
/* 19D18 8003E918 8E260028 */  lw        $a2, 0x28($s1)
/* 19D1C 8003E91C 50C00015 */  beql      $a2, $zero, .L8003E974
/* 19D20 8003E920 26310004 */   addiu    $s1, $s1, 4
/* 19D24 8003E924 8CC20000 */  lw        $v0, ($a2)
/* 19D28 8003E928 18400011 */  blez      $v0, .L8003E970
/* 19D2C 8003E92C 0000282D */   daddu    $a1, $zero, $zero
/* 19D30 8003E930 00C0182D */  daddu     $v1, $a2, $zero
.L8003E934:
/* 19D34 8003E934 8C640004 */  lw        $a0, 4($v1)
/* 19D38 8003E938 10800008 */  beqz      $a0, .L8003E95C
/* 19D3C 8003E93C 00000000 */   nop
/* 19D40 8003E940 84820008 */  lh        $v0, 8($a0)
/* 19D44 8003E944 14530005 */  bne       $v0, $s3, .L8003E95C
/* 19D48 8003E948 00000000 */   nop
/* 19D4C 8003E94C 0C00F9B7 */  jal       func_8003E6DC
/* 19D50 8003E950 0280282D */   daddu    $a1, $s4, $zero
/* 19D54 8003E954 0800FA5D */  j         .L8003E974
/* 19D58 8003E958 26310004 */   addiu    $s1, $s1, 4
.L8003E95C:
/* 19D5C 8003E95C 8CC20000 */  lw        $v0, ($a2)
/* 19D60 8003E960 24A50001 */  addiu     $a1, $a1, 1
/* 19D64 8003E964 00A2102A */  slt       $v0, $a1, $v0
/* 19D68 8003E968 1440FFF2 */  bnez      $v0, .L8003E934
/* 19D6C 8003E96C 24630004 */   addiu    $v1, $v1, 4
.L8003E970:
/* 19D70 8003E970 26310004 */  addiu     $s1, $s1, 4
.L8003E974:
/* 19D74 8003E974 8242001C */  lb        $v0, 0x1c($s2)
/* 19D78 8003E978 26100001 */  addiu     $s0, $s0, 1
/* 19D7C 8003E97C 0202102A */  slt       $v0, $s0, $v0
/* 19D80 8003E980 1440FFE5 */  bnez      $v0, .L8003E918
/* 19D84 8003E984 00000000 */   nop
.L8003E988:
/* 19D88 8003E988 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19D8C 8003E98C 8FB40020 */  lw        $s4, 0x20($sp)
/* 19D90 8003E990 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D94 8003E994 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D98 8003E998 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D9C 8003E99C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DA0 8003E9A0 03E00008 */  jr        $ra
/* 19DA4 8003E9A4 27BD0028 */   addiu    $sp, $sp, 0x28
