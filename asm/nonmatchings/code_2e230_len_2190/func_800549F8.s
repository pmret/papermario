.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800549F8
/* 02FDF8 800549F8 00A0582D */  daddu $t3, $a1, $zero
/* 02FDFC 800549FC 3C03800A */  lui   $v1, 0x800a
/* 02FE00 80054A00 8C63A5C0 */  lw    $v1, -0x5a40($v1)
/* 02FE04 80054A04 93AA0013 */  lbu   $t2, 0x13($sp)
/* 02FE08 80054A08 9162000E */  lbu   $v0, 0xe($t3)
/* 02FE0C 80054A0C 8C690004 */  lw    $t1, 4($v1)
/* 02FE10 80054A10 14400021 */  bnez  $v0, .L80054A98
/* 02FE14 80054A14 C4620000 */   lwc1  $f2, ($v1)
/* 02FE18 80054A18 10E0001D */  beqz  $a3, .L80054A90
/* 02FE1C 80054A1C 0000402D */   daddu $t0, $zero, $zero
.L80054A20:
/* 02FE20 80054A20 8CC30000 */  lw    $v1, ($a2)
/* 02FE24 80054A24 50600016 */  beql  $v1, $zero, .L80054A80
/* 02FE28 80054A28 ACC90000 */   sw    $t1, ($a2)
/* 02FE2C 80054A2C 8C620000 */  lw    $v0, ($v1)
/* 02FE30 80054A30 10400002 */  beqz  $v0, .L80054A3C
/* 02FE34 80054A34 00441021 */   addu  $v0, $v0, $a0
/* 02FE38 80054A38 AC620000 */  sw    $v0, ($v1)
.L80054A3C:
/* 02FE3C 80054A3C 8C620008 */  lw    $v0, 8($v1)
/* 02FE40 80054A40 10400002 */  beqz  $v0, .L80054A4C
/* 02FE44 80054A44 00451021 */   addu  $v0, $v0, $a1
/* 02FE48 80054A48 AC620008 */  sw    $v0, 8($v1)
.L80054A4C:
/* 02FE4C 80054A4C 8C620018 */  lw    $v0, 0x18($v1)
/* 02FE50 80054A50 10400002 */  beqz  $v0, .L80054A5C
/* 02FE54 80054A54 00451021 */   addu  $v0, $v0, $a1
/* 02FE58 80054A58 AC620018 */  sw    $v0, 0x18($v1)
.L80054A5C:
/* 02FE5C 80054A5C 8C62002C */  lw    $v0, 0x2c($v1)
/* 02FE60 80054A60 10400002 */  beqz  $v0, .L80054A6C
/* 02FE64 80054A64 00451021 */   addu  $v0, $v0, $a1
/* 02FE68 80054A68 AC62002C */  sw    $v0, 0x2c($v1)
.L80054A6C:
/* 02FE6C 80054A6C C4600020 */  lwc1  $f0, 0x20($v1)
/* 02FE70 80054A70 46800020 */  cvt.s.w $f0, $f0
/* 02FE74 80054A74 46020003 */  div.s $f0, $f0, $f2
/* 02FE78 80054A78 A06A0025 */  sb    $t2, 0x25($v1)
/* 02FE7C 80054A7C E4600020 */  swc1  $f0, 0x20($v1)
.L80054A80:
/* 02FE80 80054A80 25080001 */  addiu $t0, $t0, 1
/* 02FE84 80054A84 0107102B */  sltu  $v0, $t0, $a3
/* 02FE88 80054A88 1440FFE5 */  bnez  $v0, .L80054A20
/* 02FE8C 80054A8C 24C60004 */   addiu $a2, $a2, 4
.L80054A90:
/* 02FE90 80054A90 24020001 */  addiu $v0, $zero, 1
/* 02FE94 80054A94 A162000E */  sb    $v0, 0xe($t3)
.L80054A98:
/* 02FE98 80054A98 03E00008 */  jr    $ra
/* 02FE9C 80054A9C 00000000 */   nop   

/* 02FEA0 80054AA0 3C028008 */  lui   $v0, 0x8008
/* 02FEA4 80054AA4 8C428E54 */  lw    $v0, -0x71ac($v0)
/* 02FEA8 80054AA8 27BDFF80 */  addiu $sp, $sp, -0x80
/* 02FEAC 80054AAC AFB60070 */  sw    $s6, 0x70($sp)
/* 02FEB0 80054AB0 0080B02D */  daddu $s6, $a0, $zero
/* 02FEB4 80054AB4 AFB30064 */  sw    $s3, 0x64($sp)
/* 02FEB8 80054AB8 00A0982D */  daddu $s3, $a1, $zero
/* 02FEBC 80054ABC AFB40068 */  sw    $s4, 0x68($sp)
/* 02FEC0 80054AC0 27B40018 */  addiu $s4, $sp, 0x18
/* 02FEC4 80054AC4 AFBE0078 */  sw    $fp, 0x78($sp)
/* 02FEC8 80054AC8 0000F02D */  daddu $fp, $zero, $zero
/* 02FECC 80054ACC AFB1005C */  sw    $s1, 0x5c($sp)
/* 02FED0 80054AD0 2411000B */  addiu $s1, $zero, 0xb
/* 02FED4 80054AD4 AFB20060 */  sw    $s2, 0x60($sp)
/* 02FED8 80054AD8 24120001 */  addiu $s2, $zero, 1
/* 02FEDC 80054ADC AFBF007C */  sw    $ra, 0x7c($sp)
/* 02FEE0 80054AE0 AFB70074 */  sw    $s7, 0x74($sp)
/* 02FEE4 80054AE4 AFB5006C */  sw    $s5, 0x6c($sp)
/* 02FEE8 80054AE8 AFB00058 */  sw    $s0, 0x58($sp)
/* 02FEEC 80054AEC AFA60088 */  sw    $a2, 0x88($sp)
/* 02FEF0 80054AF0 AFA7008C */  sw    $a3, 0x8c($sp)
/* 02FEF4 80054AF4 8C570018 */  lw    $s7, 0x18($v0)
/* 02FEF8 80054AF8 2402000B */  addiu $v0, $zero, 0xb
.L80054AFC:
/* 02FEFC 80054AFC 1222000A */  beq   $s1, $v0, .L80054B28
/* 02FF00 80054B00 2E22000C */   sltiu $v0, $s1, 0xc
/* 02FF04 80054B04 54400042 */  bnel  $v0, $zero, .L80054C10
/* 02FF08 80054B08 0000902D */   daddu $s2, $zero, $zero
/* 02FF0C 80054B0C 24020015 */  addiu $v0, $zero, 0x15
/* 02FF10 80054B10 12220015 */  beq   $s1, $v0, .L80054B68
/* 02FF14 80054B14 2402001F */   addiu $v0, $zero, 0x1f
/* 02FF18 80054B18 52220035 */  beql  $s1, $v0, .L80054BF0
/* 02FF1C 80054B1C AFA00010 */   sw    $zero, 0x10($sp)
/* 02FF20 80054B20 08015304 */  j     .L80054C10
/* 02FF24 80054B24 0000902D */   daddu $s2, $zero, $zero

.L80054B28:
/* 02FF28 80054B28 27A50018 */  addiu $a1, $sp, 0x18
/* 02FF2C 80054B2C 8EC40000 */  lw    $a0, ($s6)
/* 02FF30 80054B30 0C015380 */  jal   al_DmaCopy
/* 02FF34 80054B34 24060040 */   addiu $a2, $zero, 0x40
/* 02FF38 80054B38 96830000 */  lhu   $v1, ($s4)
/* 02FF3C 80054B3C 2402424B */  addiu $v0, $zero, 0x424b
/* 02FF40 80054B40 54620033 */  bnel  $v1, $v0, .L80054C10
/* 02FF44 80054B44 0000902D */   daddu $s2, $zero, $zero
/* 02FF48 80054B48 8E820004 */  lw    $v0, 4($s4)
/* 02FF4C 80054B4C 1040002F */  beqz  $v0, .L80054C0C
/* 02FF50 80054B50 24024352 */   addiu $v0, $zero, 0x4352
/* 02FF54 80054B54 9683000C */  lhu   $v1, 0xc($s4)
/* 02FF58 80054B58 5462002D */  bnel  $v1, $v0, .L80054C10
/* 02FF5C 80054B5C 0000902D */   daddu $s2, $zero, $zero
/* 02FF60 80054B60 08015304 */  j     .L80054C10
/* 02FF64 80054B64 24110015 */   addiu $s1, $zero, 0x15

.L80054B68:
/* 02FF68 80054B68 16600005 */  bnez  $s3, .L80054B80
/* 02FF6C 80054B6C 02E0202D */   daddu $a0, $s7, $zero
/* 02FF70 80054B70 8E860004 */  lw    $a2, 4($s4)
/* 02FF74 80054B74 0C015FE4 */  jal   alHeapAlloc
/* 02FF78 80054B78 24050001 */   addiu $a1, $zero, 1
/* 02FF7C 80054B7C 0040982D */  daddu $s3, $v0, $zero
.L80054B80:
/* 02FF80 80054B80 8EC40000 */  lw    $a0, ($s6)
/* 02FF84 80054B84 8E860004 */  lw    $a2, 4($s4)
/* 02FF88 80054B88 0C015380 */  jal   al_DmaCopy
/* 02FF8C 80054B8C 0260282D */   daddu $a1, $s3, $zero
/* 02FF90 80054B90 8FA4008C */  lw    $a0, 0x8c($sp)
/* 02FF94 80054B94 8FA50088 */  lw    $a1, 0x88($sp)
/* 02FF98 80054B98 0C0151D1 */  jal   func_80054744
/* 02FF9C 80054B9C 0000802D */   daddu $s0, $zero, $zero
/* 02FFA0 80054BA0 0040A82D */  daddu $s5, $v0, $zero
/* 02FFA4 80054BA4 02A0182D */  daddu $v1, $s5, $zero
/* 02FFA8 80054BA8 0200282D */  daddu $a1, $s0, $zero
/* 02FFAC 80054BAC 0280202D */  daddu $a0, $s4, $zero
.L80054BB0:
/* 02FFB0 80054BB0 94820012 */  lhu   $v0, 0x12($a0)
/* 02FFB4 80054BB4 10400004 */  beqz  $v0, .L80054BC8
/* 02FFB8 80054BB8 00531021 */   addu  $v0, $v0, $s3
/* 02FFBC 80054BBC 26100001 */  addiu $s0, $s0, 1
/* 02FFC0 80054BC0 080152F3 */  j     .L80054BCC
/* 02FFC4 80054BC4 AC620000 */   sw    $v0, ($v1)

.L80054BC8:
/* 02FFC8 80054BC8 AC600000 */  sw    $zero, ($v1)
.L80054BCC:
/* 02FFCC 80054BCC 24630004 */  addiu $v1, $v1, 4
/* 02FFD0 80054BD0 24A50001 */  addiu $a1, $a1, 1
/* 02FFD4 80054BD4 2CA20010 */  sltiu $v0, $a1, 0x10
/* 02FFD8 80054BD8 1440FFF5 */  bnez  $v0, .L80054BB0
/* 02FFDC 80054BDC 24840002 */   addiu $a0, $a0, 2
/* 02FFE0 80054BE0 5200000B */  beql  $s0, $zero, .L80054C10
/* 02FFE4 80054BE4 0000902D */   daddu $s2, $zero, $zero
/* 02FFE8 80054BE8 08015304 */  j     .L80054C10
/* 02FFEC 80054BEC 2411001F */   addiu $s1, $zero, 0x1f

.L80054BF0:
/* 02FFF0 80054BF0 0260202D */  daddu $a0, $s3, $zero
/* 02FFF4 80054BF4 0260282D */  daddu $a1, $s3, $zero
/* 02FFF8 80054BF8 02A0302D */  daddu $a2, $s5, $zero
/* 02FFFC 80054BFC 0C01527E */  jal   func_800549F8
/* 030000 80054C00 24070010 */   addiu $a3, $zero, 0x10
/* 030004 80054C04 08015304 */  j     .L80054C10
/* 030008 80054C08 0000882D */   daddu $s1, $zero, $zero

.L80054C0C:
/* 03000C 80054C0C 0000902D */  daddu $s2, $zero, $zero
.L80054C10:
/* 030010 80054C10 1640FFBA */  bnez  $s2, .L80054AFC
/* 030014 80054C14 2402000B */   addiu $v0, $zero, 0xb
/* 030018 80054C18 0260102D */  daddu $v0, $s3, $zero
/* 03001C 80054C1C 8FBF007C */  lw    $ra, 0x7c($sp)
/* 030020 80054C20 8FBE0078 */  lw    $fp, 0x78($sp)
/* 030024 80054C24 8FB70074 */  lw    $s7, 0x74($sp)
/* 030028 80054C28 8FB60070 */  lw    $s6, 0x70($sp)
/* 03002C 80054C2C 8FB5006C */  lw    $s5, 0x6c($sp)
/* 030030 80054C30 8FB40068 */  lw    $s4, 0x68($sp)
/* 030034 80054C34 8FB30064 */  lw    $s3, 0x64($sp)
/* 030038 80054C38 8FB20060 */  lw    $s2, 0x60($sp)
/* 03003C 80054C3C 8FB1005C */  lw    $s1, 0x5c($sp)
/* 030040 80054C40 8FB00058 */  lw    $s0, 0x58($sp)
/* 030044 80054C44 03E00008 */  jr    $ra
/* 030048 80054C48 27BD0080 */   addiu $sp, $sp, 0x80

