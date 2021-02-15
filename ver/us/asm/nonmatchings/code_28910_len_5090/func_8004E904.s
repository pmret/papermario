.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E904
/* 29D04 8004E904 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 29D08 8004E908 AFB00010 */  sw        $s0, 0x10($sp)
/* 29D0C 8004E90C 0080802D */  daddu     $s0, $a0, $zero
/* 29D10 8004E910 AFB10014 */  sw        $s1, 0x14($sp)
/* 29D14 8004E914 24110001 */  addiu     $s1, $zero, 1
/* 29D18 8004E918 AFB40020 */  sw        $s4, 0x20($sp)
/* 29D1C 8004E91C 24140004 */  addiu     $s4, $zero, 4
/* 29D20 8004E920 AFB3001C */  sw        $s3, 0x1c($sp)
/* 29D24 8004E924 3C130004 */  lui       $s3, 4
/* 29D28 8004E928 AFB20018 */  sw        $s2, 0x18($sp)
/* 29D2C 8004E92C 3C120006 */  lui       $s2, 6
/* 29D30 8004E930 AFBF0024 */  sw        $ra, 0x24($sp)
/* 29D34 8004E934 AE0000B4 */  sw        $zero, 0xb4($s0)
/* 29D38 8004E938 AE0000BC */  sw        $zero, 0xbc($s0)
.L8004E93C:
/* 29D3C 8004E93C 8E020068 */  lw        $v0, 0x68($s0)
/* 29D40 8004E940 8C450000 */  lw        $a1, ($v0)
/* 29D44 8004E944 24420004 */  addiu     $v0, $v0, 4
/* 29D48 8004E948 14A00003 */  bnez      $a1, .L8004E958
/* 29D4C 8004E94C AE020068 */   sw       $v0, 0x68($s0)
/* 29D50 8004E950 08013A81 */  j         .L8004EA04
/* 29D54 8004E954 A2140221 */   sb       $s4, 0x221($s0)
.L8004E958:
/* 29D58 8004E958 00051B02 */  srl       $v1, $a1, 0xc
/* 29D5C 8004E95C 10730029 */  beq       $v1, $s3, .L8004EA04
/* 29D60 8004E960 0263102B */   sltu     $v0, $s3, $v1
/* 29D64 8004E964 14400007 */  bnez      $v0, .L8004E984
/* 29D68 8004E968 3C020001 */   lui      $v0, 1
/* 29D6C 8004E96C 10620012 */  beq       $v1, $v0, .L8004E9B8
/* 29D70 8004E970 3C020003 */   lui      $v0, 3
/* 29D74 8004E974 10620025 */  beq       $v1, $v0, .L8004EA0C
/* 29D78 8004E978 3222FFFF */   andi     $v0, $s1, 0xffff
/* 29D7C 8004E97C 08013A82 */  j         .L8004EA08
/* 29D80 8004E980 0000882D */   daddu    $s1, $zero, $zero
.L8004E984:
/* 29D84 8004E984 10720011 */  beq       $v1, $s2, .L8004E9CC
/* 29D88 8004E988 0243102B */   sltu     $v0, $s2, $v1
/* 29D8C 8004E98C 14400006 */  bnez      $v0, .L8004E9A8
/* 29D90 8004E990 3C020007 */   lui      $v0, 7
/* 29D94 8004E994 3C020005 */  lui       $v0, 5
/* 29D98 8004E998 10620016 */  beq       $v1, $v0, .L8004E9F4
/* 29D9C 8004E99C 00000000 */   nop
/* 29DA0 8004E9A0 08013A82 */  j         .L8004EA08
/* 29DA4 8004E9A4 0000882D */   daddu    $s1, $zero, $zero
.L8004E9A8:
/* 29DA8 8004E9A8 1062000E */  beq       $v1, $v0, .L8004E9E4
/* 29DAC 8004E9AC 00000000 */   nop
/* 29DB0 8004E9B0 08013A82 */  j         .L8004EA08
/* 29DB4 8004E9B4 0000882D */   daddu    $s1, $zero, $zero
.L8004E9B8:
/* 29DB8 8004E9B8 0C013AB5 */  jal       func_8004EAD4
/* 29DBC 8004E9BC 0200202D */   daddu    $a0, $s0, $zero
/* 29DC0 8004E9C0 24020001 */  addiu     $v0, $zero, 1
/* 29DC4 8004E9C4 08013A81 */  j         .L8004EA04
/* 29DC8 8004E9C8 A2020221 */   sb       $v0, 0x221($s0)
.L8004E9CC:
/* 29DCC 8004E9CC 92020223 */  lbu       $v0, 0x223($s0)
/* 29DD0 8004E9D0 30420001 */  andi      $v0, $v0, 1
/* 29DD4 8004E9D4 1440000D */  bnez      $v0, .L8004EA0C
/* 29DD8 8004E9D8 3222FFFF */   andi     $v0, $s1, 0xffff
/* 29DDC 8004E9DC 08013A7D */  j         .L8004E9F4
/* 29DE0 8004E9E0 00000000 */   nop
.L8004E9E4:
/* 29DE4 8004E9E4 92020223 */  lbu       $v0, 0x223($s0)
/* 29DE8 8004E9E8 30420001 */  andi      $v0, $v0, 1
/* 29DEC 8004E9EC 10400007 */  beqz      $v0, .L8004EA0C
/* 29DF0 8004E9F0 3222FFFF */   andi     $v0, $s1, 0xffff
.L8004E9F4:
/* 29DF4 8004E9F4 0C013A8D */  jal       func_8004EA34
/* 29DF8 8004E9F8 0200202D */   daddu    $a0, $s0, $zero
/* 29DFC 8004E9FC 08013A83 */  j         .L8004EA0C
/* 29E00 8004EA00 3222FFFF */   andi     $v0, $s1, 0xffff
.L8004EA04:
/* 29E04 8004EA04 0000882D */  daddu     $s1, $zero, $zero
.L8004EA08:
/* 29E08 8004EA08 3222FFFF */  andi      $v0, $s1, 0xffff
.L8004EA0C:
/* 29E0C 8004EA0C 1440FFCB */  bnez      $v0, .L8004E93C
/* 29E10 8004EA10 00000000 */   nop
/* 29E14 8004EA14 8FBF0024 */  lw        $ra, 0x24($sp)
/* 29E18 8004EA18 8FB40020 */  lw        $s4, 0x20($sp)
/* 29E1C 8004EA1C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 29E20 8004EA20 8FB20018 */  lw        $s2, 0x18($sp)
/* 29E24 8004EA24 8FB10014 */  lw        $s1, 0x14($sp)
/* 29E28 8004EA28 8FB00010 */  lw        $s0, 0x10($sp)
/* 29E2C 8004EA2C 03E00008 */  jr        $ra
/* 29E30 8004EA30 27BD0028 */   addiu    $sp, $sp, 0x28
