.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003AAF8
/* 15EF8 8003AAF8 27BDFF08 */  addiu     $sp, $sp, -0xf8
/* 15EFC 8003AAFC F7BC00E8 */  sdc1      $f28, 0xe8($sp)
/* 15F00 8003AB00 4480E000 */  mtc1      $zero, $f28
/* 15F04 8003AB04 F7BA00E0 */  sdc1      $f26, 0xe0($sp)
/* 15F08 8003AB08 3C01800A */  lui       $at, %hi(D_800984A0)
/* 15F0C 8003AB0C D43A84A0 */  ldc1      $f26, %lo(D_800984A0)($at)
/* 15F10 8003AB10 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 15F14 8003AB14 0080802D */  daddu     $s0, $a0, $zero
/* 15F18 8003AB18 AFB300AC */  sw        $s3, 0xac($sp)
/* 15F1C 8003AB1C 0000982D */  daddu     $s3, $zero, $zero
/* 15F20 8003AB20 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 15F24 8003AB24 0260A82D */  daddu     $s5, $s3, $zero
/* 15F28 8003AB28 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 15F2C 8003AB2C 27B10060 */  addiu     $s1, $sp, 0x60
/* 15F30 8003AB30 AFB700BC */  sw        $s7, 0xbc($sp)
/* 15F34 8003AB34 27B70020 */  addiu     $s7, $sp, 0x20
/* 15F38 8003AB38 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 15F3C 8003AB3C 0260A02D */  daddu     $s4, $s3, $zero
/* 15F40 8003AB40 AFBF00C0 */  sw        $ra, 0xc0($sp)
/* 15F44 8003AB44 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 15F48 8003AB48 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 15F4C 8003AB4C F7BE00F0 */  sdc1      $f30, 0xf0($sp)
/* 15F50 8003AB50 F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* 15F54 8003AB54 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 15F58 8003AB58 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 15F5C 8003AB5C 8E160020 */  lw        $s6, 0x20($s0)
/* 15F60 8003AB60 3C013FF0 */  lui       $at, 0x3ff0
/* 15F64 8003AB64 4481F800 */  mtc1      $at, $f31
/* 15F68 8003AB68 4480F000 */  mtc1      $zero, $f30
/* 15F6C 8003AB6C 82D20001 */  lb        $s2, 1($s6)
/* 15F70 8003AB70 2652FFFF */  addiu     $s2, $s2, -1
.L8003AB74:
/* 15F74 8003AB74 06410002 */  bgez      $s2, .L8003AB80
/* 15F78 8003AB78 26730001 */   addiu    $s3, $s3, 1
/* 15F7C 8003AB7C 24120013 */  addiu     $s2, $zero, 0x13
.L8003AB80:
/* 15F80 8003AB80 82C20001 */  lb        $v0, 1($s6)
/* 15F84 8003AB84 1242009C */  beq       $s2, $v0, .L8003ADF8
/* 15F88 8003AB88 2A620003 */   slti     $v0, $s3, 3
/* 15F8C 8003AB8C 5440FFF9 */  bnel      $v0, $zero, .L8003AB74
/* 15F90 8003AB90 2652FFFF */   addiu    $s2, $s2, -1
/* 15F94 8003AB94 0000982D */  daddu     $s3, $zero, $zero
/* 15F98 8003AB98 26B50001 */  addiu     $s5, $s5, 1
/* 15F9C 8003AB9C 2AA20004 */  slti      $v0, $s5, 4
/* 15FA0 8003ABA0 10400095 */  beqz      $v0, .L8003ADF8
/* 15FA4 8003ABA4 26940014 */   addiu    $s4, $s4, 0x14
/* 15FA8 8003ABA8 24050007 */  addiu     $a1, $zero, 7
/* 15FAC 8003ABAC 240600FF */  addiu     $a2, $zero, 0xff
/* 15FB0 8003ABB0 00121080 */  sll       $v0, $s2, 2
/* 15FB4 8003ABB4 02C21021 */  addu      $v0, $s6, $v0
/* 15FB8 8003ABB8 C4540004 */  lwc1      $f20, 4($v0)
/* 15FBC 8003ABBC C4560054 */  lwc1      $f22, 0x54($v0)
/* 15FC0 8003ABC0 C45800A4 */  lwc1      $f24, 0xa4($v0)
/* 15FC4 8003ABC4 00C0102D */  daddu     $v0, $a2, $zero
/* 15FC8 8003ABC8 AFA20010 */  sw        $v0, 0x10($sp)
/* 15FCC 8003ABCC 24020078 */  addiu     $v0, $zero, 0x78
/* 15FD0 8003ABD0 00541023 */  subu      $v0, $v0, $s4
/* 15FD4 8003ABD4 AFA20014 */  sw        $v0, 0x14($sp)
/* 15FD8 8003ABD8 AFA00018 */  sw        $zero, 0x18($sp)
/* 15FDC 8003ABDC 8E040024 */  lw        $a0, 0x24($s0)
/* 15FE0 8003ABE0 0C0448F9 */  jal       func_801123E4
/* 15FE4 8003ABE4 00C0382D */   daddu    $a3, $a2, $zero
/* 15FE8 8003ABE8 4405A000 */  mfc1      $a1, $f20
/* 15FEC 8003ABEC 4406B000 */  mfc1      $a2, $f22
/* 15FF0 8003ABF0 4407C000 */  mfc1      $a3, $f24
/* 15FF4 8003ABF4 C6140034 */  lwc1      $f20, 0x34($s0)
/* 15FF8 8003ABF8 0C019E38 */  jal       func_800678E0
/* 15FFC 8003ABFC 27A40020 */   addiu    $a0, $sp, 0x20
/* 16000 8003AC00 C6000048 */  lwc1      $f0, 0x48($s0)
/* 16004 8003AC04 461C0032 */  c.eq.s    $f0, $f28
/* 16008 8003AC08 00000000 */  nop
/* 1600C 8003AC0C 4501000B */  bc1t      .L8003AC3C
/* 16010 8003AC10 00000000 */   nop
/* 16014 8003AC14 E7BC0010 */  swc1      $f28, 0x10($sp)
/* 16018 8003AC18 8E050048 */  lw        $a1, 0x48($s0)
/* 1601C 8003AC1C 4406E000 */  mfc1      $a2, $f28
/* 16020 8003AC20 3C073F80 */  lui       $a3, 0x3f80
/* 16024 8003AC24 0C019EC0 */  jal       func_80067B00
/* 16028 8003AC28 0220202D */   daddu    $a0, $s1, $zero
/* 1602C 8003AC2C 0220202D */  daddu     $a0, $s1, $zero
/* 16030 8003AC30 27A50020 */  addiu     $a1, $sp, 0x20
/* 16034 8003AC34 0C019D78 */  jal       func_800675E0
/* 16038 8003AC38 00A0302D */   daddu    $a2, $a1, $zero
.L8003AC3C:
/* 1603C 8003AC3C C6000044 */  lwc1      $f0, 0x44($s0)
/* 16040 8003AC40 461C0032 */  c.eq.s    $f0, $f28
/* 16044 8003AC44 00000000 */  nop
/* 16048 8003AC48 4501000B */  bc1t      .L8003AC78
/* 1604C 8003AC4C 00000000 */   nop
/* 16050 8003AC50 E7BC0010 */  swc1      $f28, 0x10($sp)
/* 16054 8003AC54 8E050048 */  lw        $a1, 0x48($s0)
/* 16058 8003AC58 4406E000 */  mfc1      $a2, $f28
/* 1605C 8003AC5C 3C073F80 */  lui       $a3, 0x3f80
/* 16060 8003AC60 0C019EC0 */  jal       func_80067B00
/* 16064 8003AC64 0220202D */   daddu    $a0, $s1, $zero
/* 16068 8003AC68 0220202D */  daddu     $a0, $s1, $zero
/* 1606C 8003AC6C 27A50020 */  addiu     $a1, $sp, 0x20
/* 16070 8003AC70 0C019D78 */  jal       func_800675E0
/* 16074 8003AC74 00A0302D */   daddu    $a2, $a1, $zero
.L8003AC78:
/* 16078 8003AC78 C600004C */  lwc1      $f0, 0x4c($s0)
/* 1607C 8003AC7C 461C0032 */  c.eq.s    $f0, $f28
/* 16080 8003AC80 00000000 */  nop
/* 16084 8003AC84 4501000B */  bc1t      .L8003ACB4
/* 16088 8003AC88 00000000 */   nop
/* 1608C 8003AC8C E7BC0010 */  swc1      $f28, 0x10($sp)
/* 16090 8003AC90 8E050048 */  lw        $a1, 0x48($s0)
/* 16094 8003AC94 4406E000 */  mfc1      $a2, $f28
/* 16098 8003AC98 3C073F80 */  lui       $a3, 0x3f80
/* 1609C 8003AC9C 0C019EC0 */  jal       func_80067B00
/* 160A0 8003ACA0 0220202D */   daddu    $a0, $s1, $zero
/* 160A4 8003ACA4 0220202D */  daddu     $a0, $s1, $zero
/* 160A8 8003ACA8 27A50020 */  addiu     $a1, $sp, 0x20
/* 160AC 8003ACAC 0C019D78 */  jal       func_800675E0
/* 160B0 8003ACB0 00A0302D */   daddu    $a2, $a1, $zero
.L8003ACB4:
/* 160B4 8003ACB4 C6000054 */  lwc1      $f0, 0x54($s0)
/* 160B8 8003ACB8 46000021 */  cvt.d.s   $f0, $f0
/* 160BC 8003ACBC 463A0002 */  mul.d     $f0, $f0, $f26
/* 160C0 8003ACC0 00000000 */  nop
/* 160C4 8003ACC4 463E0032 */  c.eq.d    $f0, $f30
/* 160C8 8003ACC8 00000000 */  nop
/* 160CC 8003ACCC 45000014 */  bc1f      .L8003AD20
/* 160D0 8003ACD0 00000000 */   nop
/* 160D4 8003ACD4 C6000058 */  lwc1      $f0, 0x58($s0)
/* 160D8 8003ACD8 C6020320 */  lwc1      $f2, 0x320($s0)
/* 160DC 8003ACDC 46020002 */  mul.s     $f0, $f0, $f2
/* 160E0 8003ACE0 00000000 */  nop
/* 160E4 8003ACE4 46000021 */  cvt.d.s   $f0, $f0
/* 160E8 8003ACE8 463A0002 */  mul.d     $f0, $f0, $f26
/* 160EC 8003ACEC 00000000 */  nop
/* 160F0 8003ACF0 463E0032 */  c.eq.d    $f0, $f30
/* 160F4 8003ACF4 00000000 */  nop
/* 160F8 8003ACF8 45000009 */  bc1f      .L8003AD20
/* 160FC 8003ACFC 00000000 */   nop
/* 16100 8003AD00 C600005C */  lwc1      $f0, 0x5c($s0)
/* 16104 8003AD04 46000021 */  cvt.d.s   $f0, $f0
/* 16108 8003AD08 463A0002 */  mul.d     $f0, $f0, $f26
/* 1610C 8003AD0C 00000000 */  nop
/* 16110 8003AD10 463E0032 */  c.eq.d    $f0, $f30
/* 16114 8003AD14 00000000 */  nop
/* 16118 8003AD18 4501001C */  bc1t      .L8003AD8C
/* 1611C 8003AD1C 00000000 */   nop
.L8003AD20:
/* 16120 8003AD20 C6060054 */  lwc1      $f6, 0x54($s0)
/* 16124 8003AD24 460031A1 */  cvt.d.s   $f6, $f6
/* 16128 8003AD28 463A3182 */  mul.d     $f6, $f6, $f26
/* 1612C 8003AD2C 00000000 */  nop
/* 16130 8003AD30 C604005C */  lwc1      $f4, 0x5c($s0)
/* 16134 8003AD34 46002121 */  cvt.d.s   $f4, $f4
/* 16138 8003AD38 463A2102 */  mul.d     $f4, $f4, $f26
/* 1613C 8003AD3C 00000000 */  nop
/* 16140 8003AD40 C6000058 */  lwc1      $f0, 0x58($s0)
/* 16144 8003AD44 C6020320 */  lwc1      $f2, 0x320($s0)
/* 16148 8003AD48 46020002 */  mul.s     $f0, $f0, $f2
/* 1614C 8003AD4C 00000000 */  nop
/* 16150 8003AD50 46000021 */  cvt.d.s   $f0, $f0
/* 16154 8003AD54 463A0002 */  mul.d     $f0, $f0, $f26
/* 16158 8003AD58 00000000 */  nop
/* 1615C 8003AD5C 462031A0 */  cvt.s.d   $f6, $f6
/* 16160 8003AD60 46202120 */  cvt.s.d   $f4, $f4
/* 16164 8003AD64 44053000 */  mfc1      $a1, $f6
/* 16168 8003AD68 44072000 */  mfc1      $a3, $f4
/* 1616C 8003AD6C 46200020 */  cvt.s.d   $f0, $f0
/* 16170 8003AD70 44060000 */  mfc1      $a2, $f0
/* 16174 8003AD74 0C019DE8 */  jal       func_800677A0
/* 16178 8003AD78 0220202D */   daddu    $a0, $s1, $zero
/* 1617C 8003AD7C 0220202D */  daddu     $a0, $s1, $zero
/* 16180 8003AD80 27A50020 */  addiu     $a1, $sp, 0x20
/* 16184 8003AD84 0C019D78 */  jal       func_800675E0
/* 16188 8003AD88 00A0302D */   daddu    $a2, $a1, $zero
.L8003AD8C:
/* 1618C 8003AD8C 8E030000 */  lw        $v1, ($s0)
/* 16190 8003AD90 3C024000 */  lui       $v0, 0x4000
/* 16194 8003AD94 00621024 */  and       $v0, $v1, $v0
/* 16198 8003AD98 5440000E */  bnel      $v0, $zero, .L8003ADD4
/* 1619C 8003AD9C AFB70010 */   sw       $s7, 0x10($sp)
/* 161A0 8003ADA0 3C020100 */  lui       $v0, 0x100
/* 161A4 8003ADA4 00621024 */  and       $v0, $v1, $v0
/* 161A8 8003ADA8 5440FF72 */  bnel      $v0, $zero, .L8003AB74
/* 161AC 8003ADAC 2652FFFF */   addiu    $s2, $s2, -1
/* 161B0 8003ADB0 4600A20D */  trunc.w.s $f8, $f20
/* 161B4 8003ADB4 44054000 */  mfc1      $a1, $f8
/* 161B8 8003ADB8 0000302D */  daddu     $a2, $zero, $zero
/* 161BC 8003ADBC AFB70010 */  sw        $s7, 0x10($sp)
/* 161C0 8003ADC0 8E040024 */  lw        $a0, 0x24($s0)
/* 161C4 8003ADC4 0C0447CA */  jal       func_80111F28
/* 161C8 8003ADC8 00C0382D */   daddu    $a3, $a2, $zero
/* 161CC 8003ADCC 0800EADD */  j         .L8003AB74
/* 161D0 8003ADD0 2652FFFF */   addiu    $s2, $s2, -1
.L8003ADD4:
/* 161D4 8003ADD4 3C044000 */  lui       $a0, 0x4000
/* 161D8 8003ADD8 34840001 */  ori       $a0, $a0, 1
/* 161DC 8003ADDC 4600A20D */  trunc.w.s $f8, $f20
/* 161E0 8003ADE0 44054000 */  mfc1      $a1, $f8
/* 161E4 8003ADE4 0000302D */  daddu     $a2, $zero, $zero
/* 161E8 8003ADE8 0C0445E4 */  jal       func_80111790
/* 161EC 8003ADEC 00C0382D */   daddu    $a3, $a2, $zero
/* 161F0 8003ADF0 0800EADD */  j         .L8003AB74
/* 161F4 8003ADF4 2652FFFF */   addiu    $s2, $s2, -1
.L8003ADF8:
/* 161F8 8003ADF8 0C00F41F */  jal       func_8003D07C
/* 161FC 8003ADFC 0200202D */   daddu    $a0, $s0, $zero
/* 16200 8003AE00 8FBF00C0 */  lw        $ra, 0xc0($sp)
/* 16204 8003AE04 8FB700BC */  lw        $s7, 0xbc($sp)
/* 16208 8003AE08 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 1620C 8003AE0C 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 16210 8003AE10 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 16214 8003AE14 8FB300AC */  lw        $s3, 0xac($sp)
/* 16218 8003AE18 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 1621C 8003AE1C 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 16220 8003AE20 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 16224 8003AE24 D7BE00F0 */  ldc1      $f30, 0xf0($sp)
/* 16228 8003AE28 D7BC00E8 */  ldc1      $f28, 0xe8($sp)
/* 1622C 8003AE2C D7BA00E0 */  ldc1      $f26, 0xe0($sp)
/* 16230 8003AE30 D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* 16234 8003AE34 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 16238 8003AE38 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 1623C 8003AE3C 03E00008 */  jr        $ra
/* 16240 8003AE40 27BD00F8 */   addiu    $sp, $sp, 0xf8
