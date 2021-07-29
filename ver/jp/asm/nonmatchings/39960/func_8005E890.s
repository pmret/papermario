.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005E890
/* 39C90 8005E890 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 39C94 8005E894 AFB40028 */  sw        $s4, 0x28($sp)
/* 39C98 8005E898 3C14800E */  lui       $s4, %hi(D_800DA424)
/* 39C9C 8005E89C 2694A424 */  addiu     $s4, $s4, %lo(D_800DA424)
/* 39CA0 8005E8A0 AFB30024 */  sw        $s3, 0x24($sp)
/* 39CA4 8005E8A4 2693066C */  addiu     $s3, $s4, 0x66c
/* 39CA8 8005E8A8 AFB5002C */  sw        $s5, 0x2c($sp)
/* 39CAC 8005E8AC 269500A8 */  addiu     $s5, $s4, 0xa8
/* 39CB0 8005E8B0 AFB20020 */  sw        $s2, 0x20($sp)
/* 39CB4 8005E8B4 27B20014 */  addiu     $s2, $sp, 0x14
/* 39CB8 8005E8B8 AFBF0030 */  sw        $ra, 0x30($sp)
/* 39CBC 8005E8BC AFB1001C */  sw        $s1, 0x1c($sp)
/* 39CC0 8005E8C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 39CC4 8005E8C4 0280202D */  daddu     $a0, $s4, $zero
.L8005E8C8:
/* 39CC8 8005E8C8 27A50010 */  addiu     $a1, $sp, 0x10
/* 39CCC 8005E8CC 0C0195B0 */  jal       func_800656C0
/* 39CD0 8005E8D0 24060001 */   addiu    $a2, $zero, 1
/* 39CD4 8005E8D4 3C02800A */  lui       $v0, %hi(D_8009A590)
/* 39CD8 8005E8D8 9042A590 */  lbu       $v0, %lo(D_8009A590)($v0)
/* 39CDC 8005E8DC 30420002 */  andi      $v0, $v0, 2
/* 39CE0 8005E8E0 14400031 */  bnez      $v0, .L8005E9A8
/* 39CE4 8005E8E4 00000000 */   nop
/* 39CE8 8005E8E8 0C018628 */  jal       func_800618A0
/* 39CEC 8005E8EC 0000802D */   daddu    $s0, $zero, $zero
/* 39CF0 8005E8F0 8E910668 */  lw        $s1, 0x668($s4)
/* 39CF4 8005E8F4 1220000B */  beqz      $s1, .L8005E924
/* 39CF8 8005E8F8 00000000 */   nop
/* 39CFC 8005E8FC 0C019708 */  jal       func_80065C20
/* 39D00 8005E900 24100002 */   addiu    $s0, $zero, 2
/* 39D04 8005E904 268400A8 */  addiu     $a0, $s4, 0xa8
/* 39D08 8005E908 27A50014 */  addiu     $a1, $sp, 0x14
/* 39D0C 8005E90C 0C0195B0 */  jal       func_800656C0
/* 39D10 8005E910 24060001 */   addiu    $a2, $zero, 1
/* 39D14 8005E914 0C019710 */  jal       func_80065C40
/* 39D18 8005E918 26240010 */   addiu    $a0, $s1, 0x10
/* 39D1C 8005E91C 54400001 */  bnel      $v0, $zero, .L8005E924
/* 39D20 8005E920 24100001 */   addiu    $s0, $zero, 1
.L8005E924:
/* 39D24 8005E924 8FA20010 */  lw        $v0, 0x10($sp)
/* 39D28 8005E928 24440010 */  addiu     $a0, $v0, 0x10
/* 39D2C 8005E92C 0C019678 */  jal       func_800659E0
/* 39D30 8005E930 AE620000 */   sw       $v0, ($s3)
/* 39D34 8005E934 8FA40010 */  lw        $a0, 0x10($sp)
/* 39D38 8005E938 0C0196FB */  jal       func_80065BEC
/* 39D3C 8005E93C 24840010 */   addiu    $a0, $a0, 0x10
/* 39D40 8005E940 02A0202D */  daddu     $a0, $s5, $zero
/* 39D44 8005E944 0240282D */  daddu     $a1, $s2, $zero
/* 39D48 8005E948 0C0195B0 */  jal       func_800656C0
/* 39D4C 8005E94C 24060001 */   addiu    $a2, $zero, 1
/* 39D50 8005E950 8E620004 */  lw        $v0, 4($s3)
/* 39D54 8005E954 10400005 */  beqz      $v0, .L8005E96C
/* 39D58 8005E958 AE600000 */   sw       $zero, ($s3)
/* 39D5C 8005E95C 2664FAAC */  addiu     $a0, $s3, -0x554
/* 39D60 8005E960 0240282D */  daddu     $a1, $s2, $zero
/* 39D64 8005E964 0C0195FC */  jal       func_800657F0
/* 39D68 8005E968 24060001 */   addiu    $a2, $zero, 1
.L8005E96C:
/* 39D6C 8005E96C 24020001 */  addiu     $v0, $zero, 1
/* 39D70 8005E970 16020008 */  bne       $s0, $v0, .L8005E994
/* 39D74 8005E974 24020002 */   addiu    $v0, $zero, 2
/* 39D78 8005E978 26300010 */  addiu     $s0, $s1, 0x10
/* 39D7C 8005E97C 0C019678 */  jal       func_800659E0
/* 39D80 8005E980 0200202D */   daddu    $a0, $s0, $zero
/* 39D84 8005E984 0C0196FB */  jal       func_80065BEC
/* 39D88 8005E988 0200202D */   daddu    $a0, $s0, $zero
/* 39D8C 8005E98C 08017A6A */  j         .L8005E9A8
/* 39D90 8005E990 00000000 */   nop
.L8005E994:
/* 39D94 8005E994 16020004 */  bne       $s0, $v0, .L8005E9A8
/* 39D98 8005E998 02A0202D */   daddu    $a0, $s5, $zero
/* 39D9C 8005E99C 0240282D */  daddu     $a1, $s2, $zero
/* 39DA0 8005E9A0 0C0195FC */  jal       func_800657F0
/* 39DA4 8005E9A4 24060001 */   addiu    $a2, $zero, 1
.L8005E9A8:
/* 39DA8 8005E9A8 8FA20010 */  lw        $v0, 0x10($sp)
/* 39DAC 8005E9AC 8C440050 */  lw        $a0, 0x50($v0)
/* 39DB0 8005E9B0 8C450054 */  lw        $a1, 0x54($v0)
/* 39DB4 8005E9B4 0C0195FC */  jal       func_800657F0
/* 39DB8 8005E9B8 24060001 */   addiu    $a2, $zero, 1
/* 39DBC 8005E9BC 08017A32 */  j         .L8005E8C8
/* 39DC0 8005E9C0 0280202D */   daddu    $a0, $s4, $zero
/* 39DC4 8005E9C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 39DC8 8005E9C8 AFB00018 */  sw        $s0, 0x18($sp)
/* 39DCC 8005E9CC 3C10800E */  lui       $s0, %hi(D_800DA45C)
/* 39DD0 8005E9D0 2610A45C */  addiu     $s0, $s0, %lo(D_800DA45C)
/* 39DD4 8005E9D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 39DD8 8005E9D8 27B10014 */  addiu     $s1, $sp, 0x14
/* 39DDC 8005E9DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 39DE0 8005E9E0 0200202D */  daddu     $a0, $s0, $zero
.L8005E9E4:
/* 39DE4 8005E9E4 27A50010 */  addiu     $a1, $sp, 0x10
/* 39DE8 8005E9E8 0C0195B0 */  jal       func_800656C0
/* 39DEC 8005E9EC 24060001 */   addiu    $a2, $zero, 1
/* 39DF0 8005E9F0 3C02800A */  lui       $v0, %hi(D_8009A590)
/* 39DF4 8005E9F4 9042A590 */  lbu       $v0, %lo(D_8009A590)($v0)
/* 39DF8 8005E9F8 30420002 */  andi      $v0, $v0, 2
/* 39DFC 8005E9FC 14400032 */  bnez      $v0, .L8005EAC8
/* 39E00 8005EA00 00000000 */   nop
/* 39E04 8005EA04 0C017B74 */  jal       func_8005EDD0
/* 39E08 8005EA08 8FA40010 */   lw       $a0, 0x10($sp)
/* 39E0C 8005EA0C 0C018244 */  jal       func_80060910
/* 39E10 8005EA10 24040001 */   addiu    $a0, $zero, 1
/* 39E14 8005EA14 8E030634 */  lw        $v1, 0x634($s0)
/* 39E18 8005EA18 1060000C */  beqz      $v1, .L8005EA4C
/* 39E1C 8005EA1C 0040202D */   daddu    $a0, $v0, $zero
/* 39E20 8005EA20 8FA20010 */  lw        $v0, 0x10($sp)
/* 39E24 8005EA24 0C018244 */  jal       func_80060910
/* 39E28 8005EA28 AE020638 */   sw       $v0, 0x638($s0)
/* 39E2C 8005EA2C 260400E0 */  addiu     $a0, $s0, 0xe0
/* 39E30 8005EA30 27A50014 */  addiu     $a1, $sp, 0x14
/* 39E34 8005EA34 0C0195B0 */  jal       func_800656C0
/* 39E38 8005EA38 24060001 */   addiu    $a2, $zero, 1
/* 39E3C 8005EA3C 0C018244 */  jal       func_80060910
/* 39E40 8005EA40 24040001 */   addiu    $a0, $zero, 1
/* 39E44 8005EA44 0040202D */  daddu     $a0, $v0, $zero
/* 39E48 8005EA48 AE000638 */  sw        $zero, 0x638($s0)
.L8005EA4C:
/* 39E4C 8005EA4C 0C018244 */  jal       func_80060910
/* 39E50 8005EA50 00000000 */   nop
/* 39E54 8005EA54 0C018244 */  jal       func_80060910
/* 39E58 8005EA58 24040001 */   addiu    $a0, $zero, 1
/* 39E5C 8005EA5C 8FA30010 */  lw        $v1, 0x10($sp)
/* 39E60 8005EA60 0040202D */  daddu     $a0, $v0, $zero
/* 39E64 8005EA64 0C018244 */  jal       func_80060910
/* 39E68 8005EA68 AE030630 */   sw       $v1, 0x630($s0)
/* 39E6C 8005EA6C 8FA40010 */  lw        $a0, 0x10($sp)
/* 39E70 8005EA70 0C019678 */  jal       func_800659E0
/* 39E74 8005EA74 24840010 */   addiu    $a0, $a0, 0x10
/* 39E78 8005EA78 8FA40010 */  lw        $a0, 0x10($sp)
/* 39E7C 8005EA7C 0C0196FB */  jal       func_80065BEC
/* 39E80 8005EA80 24840010 */   addiu    $a0, $a0, 0x10
/* 39E84 8005EA84 26040070 */  addiu     $a0, $s0, 0x70
/* 39E88 8005EA88 0220282D */  daddu     $a1, $s1, $zero
/* 39E8C 8005EA8C 0C0195B0 */  jal       func_800656C0
/* 39E90 8005EA90 24060001 */   addiu    $a2, $zero, 1
/* 39E94 8005EA94 0C018244 */  jal       func_80060910
/* 39E98 8005EA98 24040001 */   addiu    $a0, $zero, 1
/* 39E9C 8005EA9C 0040202D */  daddu     $a0, $v0, $zero
/* 39EA0 8005EAA0 0C018244 */  jal       func_80060910
/* 39EA4 8005EAA4 AE000630 */   sw       $zero, 0x630($s0)
/* 39EA8 8005EAA8 8FA20010 */  lw        $v0, 0x10($sp)
/* 39EAC 8005EAAC 8C420008 */  lw        $v0, 8($v0)
/* 39EB0 8005EAB0 30420002 */  andi      $v0, $v0, 2
/* 39EB4 8005EAB4 14400004 */  bnez      $v0, .L8005EAC8
/* 39EB8 8005EAB8 260400A8 */   addiu    $a0, $s0, 0xa8
/* 39EBC 8005EABC 0220282D */  daddu     $a1, $s1, $zero
/* 39EC0 8005EAC0 0C0195B0 */  jal       func_800656C0
/* 39EC4 8005EAC4 24060001 */   addiu    $a2, $zero, 1
.L8005EAC8:
/* 39EC8 8005EAC8 8FA50010 */  lw        $a1, 0x10($sp)
/* 39ECC 8005EACC 8CA40050 */  lw        $a0, 0x50($a1)
/* 39ED0 8005EAD0 0C0195FC */  jal       func_800657F0
/* 39ED4 8005EAD4 24060001 */   addiu    $a2, $zero, 1
/* 39ED8 8005EAD8 08017A79 */  j         .L8005E9E4
/* 39EDC 8005EADC 0200202D */   daddu    $a0, $s0, $zero
