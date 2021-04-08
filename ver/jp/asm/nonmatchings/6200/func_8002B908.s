.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B908
/* 6D08 8002B908 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 6D0C 8002B90C AFB5005C */  sw        $s5, 0x5c($sp)
/* 6D10 8002B910 0080A82D */  daddu     $s5, $a0, $zero
/* 6D14 8002B914 AFB20050 */  sw        $s2, 0x50($sp)
/* 6D18 8002B918 00A0902D */  daddu     $s2, $a1, $zero
/* 6D1C 8002B91C AFB1004C */  sw        $s1, 0x4c($sp)
/* 6D20 8002B920 00C0882D */  daddu     $s1, $a2, $zero
/* 6D24 8002B924 0240202D */  daddu     $a0, $s2, $zero
/* 6D28 8002B928 0220282D */  daddu     $a1, $s1, $zero
/* 6D2C 8002B92C AFBF0060 */  sw        $ra, 0x60($sp)
/* 6D30 8002B930 AFB40058 */  sw        $s4, 0x58($sp)
/* 6D34 8002B934 AFB30054 */  sw        $s3, 0x54($sp)
/* 6D38 8002B938 0C018608 */  jal       func_80061820
/* 6D3C 8002B93C AFB00048 */   sw       $s0, 0x48($sp)
/* 6D40 8002B940 27B00028 */  addiu     $s0, $sp, 0x28
/* 6D44 8002B944 0200202D */  daddu     $a0, $s0, $zero
/* 6D48 8002B948 27A50040 */  addiu     $a1, $sp, 0x40
/* 6D4C 8002B94C 0C019554 */  jal       func_80065550
/* 6D50 8002B950 24060001 */   addiu    $a2, $zero, 1
/* 6D54 8002B954 12200017 */  beqz      $s1, .L8002B9B4
/* 6D58 8002B958 0000982D */   daddu    $s3, $zero, $zero
/* 6D5C 8002B95C 0200A02D */  daddu     $s4, $s0, $zero
/* 6D60 8002B960 0015A9C0 */  sll       $s5, $s5, 7
.L8002B964:
/* 6D64 8002B964 2E220081 */  sltiu     $v0, $s1, 0x81
/* 6D68 8002B968 14400002 */  bnez      $v0, .L8002B974
/* 6D6C 8002B96C 0220802D */   daddu    $s0, $s1, $zero
/* 6D70 8002B970 24100080 */  addiu     $s0, $zero, 0x80
.L8002B974:
/* 6D74 8002B974 27A40010 */  addiu     $a0, $sp, 0x10
/* 6D78 8002B978 0000282D */  daddu     $a1, $zero, $zero
/* 6D7C 8002B97C 0240302D */  daddu     $a2, $s2, $zero
/* 6D80 8002B980 0C01BD4C */  jal       func_8006F530
/* 6D84 8002B984 0280382D */   daddu    $a3, $s4, $zero
/* 6D88 8002B988 3264FFFF */  andi      $a0, $s3, 0xffff
/* 6D8C 8002B98C 0C01BD7F */  jal       func_8006F5FC
/* 6D90 8002B990 02A42021 */   addu     $a0, $s5, $a0
/* 6D94 8002B994 0280202D */  daddu     $a0, $s4, $zero
/* 6D98 8002B998 0000282D */  daddu     $a1, $zero, $zero
/* 6D9C 8002B99C 0C0195B0 */  jal       func_800656C0
/* 6DA0 8002B9A0 24060001 */   addiu    $a2, $zero, 1
/* 6DA4 8002B9A4 26730001 */  addiu     $s3, $s3, 1
/* 6DA8 8002B9A8 02308823 */  subu      $s1, $s1, $s0
/* 6DAC 8002B9AC 1620FFED */  bnez      $s1, .L8002B964
/* 6DB0 8002B9B0 02509021 */   addu     $s2, $s2, $s0
.L8002B9B4:
/* 6DB4 8002B9B4 8FBF0060 */  lw        $ra, 0x60($sp)
/* 6DB8 8002B9B8 8FB5005C */  lw        $s5, 0x5c($sp)
/* 6DBC 8002B9BC 8FB40058 */  lw        $s4, 0x58($sp)
/* 6DC0 8002B9C0 8FB30054 */  lw        $s3, 0x54($sp)
/* 6DC4 8002B9C4 8FB20050 */  lw        $s2, 0x50($sp)
/* 6DC8 8002B9C8 8FB1004C */  lw        $s1, 0x4c($sp)
/* 6DCC 8002B9CC 8FB00048 */  lw        $s0, 0x48($sp)
/* 6DD0 8002B9D0 24020001 */  addiu     $v0, $zero, 1
/* 6DD4 8002B9D4 03E00008 */  jr        $ra
/* 6DD8 8002B9D8 27BD0068 */   addiu    $sp, $sp, 0x68
