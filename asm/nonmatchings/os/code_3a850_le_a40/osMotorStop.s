.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osMotorStop
/* 03AD20 8005F920 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03AD24 8005F924 AFB20018 */  sw    $s2, 0x18($sp)
/* 03AD28 8005F928 0080902D */  daddu $s2, $a0, $zero
/* 03AD2C 8005F92C 00A0302D */  daddu $a2, $a1, $zero
/* 03AD30 8005F930 AFB00010 */  sw    $s0, 0x10($sp)
/* 03AD34 8005F934 AFBF0020 */  sw    $ra, 0x20($sp)
/* 03AD38 8005F938 AFB3001C */  sw    $s3, 0x1c($sp)
/* 03AD3C 8005F93C AFB10014 */  sw    $s1, 0x14($sp)
/* 03AD40 8005F940 92430006 */  lbu   $v1, 6($s2)
/* 03AD44 8005F944 24130002 */  addiu $s3, $zero, 2
/* 03AD48 8005F948 10730069 */  beq   $v1, $s3, .L8005FAF0
/* 03AD4C 8005F94C 0000802D */   daddu $s0, $zero, $zero
/* 03AD50 8005F950 28620003 */  slti  $v0, $v1, 3
/* 03AD54 8005F954 10400005 */  beqz  $v0, .L8005F96C
/* 03AD58 8005F958 24020001 */   addiu $v0, $zero, 1
/* 03AD5C 8005F95C 1062000A */  beq   $v1, $v0, .L8005F988
/* 03AD60 8005F960 0200102D */   daddu $v0, $s0, $zero
/* 03AD64 8005F964 08017EBD */  j     .L8005FAF4
/* 03AD68 8005F968 00000000 */   nop   

.L8005F96C:
/* 03AD6C 8005F96C 24020003 */  addiu $v0, $zero, 3
/* 03AD70 8005F970 10620018 */  beq   $v1, $v0, .L8005F9D4
/* 03AD74 8005F974 24020004 */   addiu $v0, $zero, 4
/* 03AD78 8005F978 10620048 */  beq   $v1, $v0, .L8005FA9C
/* 03AD7C 8005F97C 0200102D */   daddu $v0, $s0, $zero
/* 03AD80 8005F980 08017EBD */  j     .L8005FAF4
/* 03AD84 8005F984 00000000 */   nop   

.L8005F988:
/* 03AD88 8005F988 96420004 */  lhu   $v0, 4($s2)
/* 03AD8C 8005F98C 1040000C */  beqz  $v0, .L8005F9C0
/* 03AD90 8005F990 00062040 */   sll   $a0, $a2, 1
/* 03AD94 8005F994 00862021 */  addu  $a0, $a0, $a2
/* 03AD98 8005F998 00042080 */  sll   $a0, $a0, 2
/* 03AD9C 8005F99C 00862021 */  addu  $a0, $a0, $a2
/* 03ADA0 8005F9A0 000420C0 */  sll   $a0, $a0, 3
/* 03ADA4 8005F9A4 3C02800E */  lui   $v0, 0x800e
/* 03ADA8 8005F9A8 2442AAD8 */  addiu $v0, $v0, -0x5528
/* 03ADAC 8005F9AC 00822021 */  addu  $a0, $a0, $v0
/* 03ADB0 8005F9B0 0C019F80 */  jal   osMotorAccess
/* 03ADB4 8005F9B4 0000282D */   daddu $a1, $zero, $zero
/* 03ADB8 8005F9B8 08017E71 */  j     .L8005F9C4
/* 03ADBC 8005F9BC 0040802D */   daddu $s0, $v0, $zero

.L8005F9C0:
/* 03ADC0 8005F9C0 A2530006 */  sb    $s3, 6($s2)
.L8005F9C4:
/* 03ADC4 8005F9C4 96420004 */  lhu   $v0, 4($s2)
/* 03ADC8 8005F9C8 2442FFFF */  addiu $v0, $v0, -1
/* 03ADCC 8005F9CC 08017EBC */  j     .L8005FAF0
/* 03ADD0 8005F9D0 A6420004 */   sh    $v0, 4($s2)

.L8005F9D4:
/* 03ADD4 8005F9D4 96420002 */  lhu   $v0, 2($s2)
/* 03ADD8 8005F9D8 1040001F */  beqz  $v0, .L8005FA58
/* 03ADDC 8005F9DC 00062040 */   sll   $a0, $a2, 1
/* 03ADE0 8005F9E0 96420004 */  lhu   $v0, 4($s2)
/* 03ADE4 8005F9E4 96430000 */  lhu   $v1, ($s2)
/* 03ADE8 8005F9E8 00431021 */  addu  $v0, $v0, $v1
/* 03ADEC 8005F9EC 304300FF */  andi  $v1, $v0, 0xff
/* 03ADF0 8005F9F0 3042FFFF */  andi  $v0, $v0, 0xffff
/* 03ADF4 8005F9F4 00021202 */  srl   $v0, $v0, 8
/* 03ADF8 8005F9F8 1040000B */  beqz  $v0, .L8005FA28
/* 03ADFC 8005F9FC A6430004 */   sh    $v1, 4($s2)
/* 03AE00 8005FA00 00062040 */  sll   $a0, $a2, 1
/* 03AE04 8005FA04 00862021 */  addu  $a0, $a0, $a2
/* 03AE08 8005FA08 00042080 */  sll   $a0, $a0, 2
/* 03AE0C 8005FA0C 00862021 */  addu  $a0, $a0, $a2
/* 03AE10 8005FA10 000420C0 */  sll   $a0, $a0, 3
/* 03AE14 8005FA14 3C02800E */  lui   $v0, 0x800e
/* 03AE18 8005FA18 2442AAD8 */  addiu $v0, $v0, -0x5528
/* 03AE1C 8005FA1C 00822021 */  addu  $a0, $a0, $v0
/* 03AE20 8005FA20 08017E92 */  j     .L8005FA48
/* 03AE24 8005FA24 24050001 */   addiu $a1, $zero, 1

.L8005FA28:
/* 03AE28 8005FA28 00862021 */  addu  $a0, $a0, $a2
/* 03AE2C 8005FA2C 00042080 */  sll   $a0, $a0, 2
/* 03AE30 8005FA30 00862021 */  addu  $a0, $a0, $a2
/* 03AE34 8005FA34 000420C0 */  sll   $a0, $a0, 3
/* 03AE38 8005FA38 3C02800E */  lui   $v0, 0x800e
/* 03AE3C 8005FA3C 2442AAD8 */  addiu $v0, $v0, -0x5528
/* 03AE40 8005FA40 00822021 */  addu  $a0, $a0, $v0
/* 03AE44 8005FA44 0000282D */  daddu $a1, $zero, $zero
.L8005FA48:
/* 03AE48 8005FA48 0C019F80 */  jal   osMotorAccess
/* 03AE4C 8005FA4C 00000000 */   nop   
/* 03AE50 8005FA50 08017EA3 */  j     .L8005FA8C
/* 03AE54 8005FA54 0040802D */   daddu $s0, $v0, $zero

.L8005FA58:
/* 03AE58 8005FA58 00862021 */  addu  $a0, $a0, $a2
/* 03AE5C 8005FA5C 00042080 */  sll   $a0, $a0, 2
/* 03AE60 8005FA60 00862021 */  addu  $a0, $a0, $a2
/* 03AE64 8005FA64 000420C0 */  sll   $a0, $a0, 3
/* 03AE68 8005FA68 3C02800E */  lui   $v0, 0x800e
/* 03AE6C 8005FA6C 2442AAD8 */  addiu $v0, $v0, -0x5528
/* 03AE70 8005FA70 00822021 */  addu  $a0, $a0, $v0
/* 03AE74 8005FA74 0C019F80 */  jal   osMotorAccess
/* 03AE78 8005FA78 0000282D */   daddu $a1, $zero, $zero
/* 03AE7C 8005FA7C 0040802D */  daddu $s0, $v0, $zero
/* 03AE80 8005FA80 24020001 */  addiu $v0, $zero, 1
/* 03AE84 8005FA84 A2420006 */  sb    $v0, 6($s2)
/* 03AE88 8005FA88 A6530004 */  sh    $s3, 4($s2)
.L8005FA8C:
/* 03AE8C 8005FA8C 96420002 */  lhu   $v0, 2($s2)
/* 03AE90 8005FA90 2442FFFF */  addiu $v0, $v0, -1
/* 03AE94 8005FA94 08017EBC */  j     .L8005FAF0
/* 03AE98 8005FA98 A6420002 */   sh    $v0, 2($s2)

.L8005FA9C:
/* 03AE9C 8005FA9C 3C04800E */  lui   $a0, 0x800e
/* 03AEA0 8005FAA0 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03AEA4 8005FAA4 00061040 */  sll   $v0, $a2, 1
/* 03AEA8 8005FAA8 00461021 */  addu  $v0, $v0, $a2
/* 03AEAC 8005FAAC 00021080 */  sll   $v0, $v0, 2
/* 03AEB0 8005FAB0 00461021 */  addu  $v0, $v0, $a2
/* 03AEB4 8005FAB4 000210C0 */  sll   $v0, $v0, 3
/* 03AEB8 8005FAB8 3C03800E */  lui   $v1, 0x800e
/* 03AEBC 8005FABC 2463AAD8 */  addiu $v1, $v1, -0x5528
/* 03AEC0 8005FAC0 00438821 */  addu  $s1, $v0, $v1
/* 03AEC4 8005FAC4 0C019FD1 */  jal   osMotorInit
/* 03AEC8 8005FAC8 0220282D */   daddu $a1, $s1, $zero
/* 03AECC 8005FACC 0040802D */  daddu $s0, $v0, $zero
/* 03AED0 8005FAD0 16000005 */  bnez  $s0, .L8005FAE8
/* 03AED4 8005FAD4 24020001 */   addiu $v0, $zero, 1
/* 03AED8 8005FAD8 0220202D */  daddu $a0, $s1, $zero
/* 03AEDC 8005FADC 0C019F80 */  jal   osMotorAccess
/* 03AEE0 8005FAE0 0000282D */   daddu $a1, $zero, $zero
/* 03AEE4 8005FAE4 24020001 */  addiu $v0, $zero, 1
.L8005FAE8:
/* 03AEE8 8005FAE8 A2420006 */  sb    $v0, 6($s2)
/* 03AEEC 8005FAEC A6530004 */  sh    $s3, 4($s2)
.L8005FAF0:
/* 03AEF0 8005FAF0 0200102D */  daddu $v0, $s0, $zero
.L8005FAF4:
/* 03AEF4 8005FAF4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 03AEF8 8005FAF8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 03AEFC 8005FAFC 8FB20018 */  lw    $s2, 0x18($sp)
/* 03AF00 8005FB00 8FB10014 */  lw    $s1, 0x14($sp)
/* 03AF04 8005FB04 8FB00010 */  lw    $s0, 0x10($sp)
/* 03AF08 8005FB08 03E00008 */  jr    $ra
/* 03AF0C 8005FB0C 27BD0028 */   addiu $sp, $sp, 0x28

