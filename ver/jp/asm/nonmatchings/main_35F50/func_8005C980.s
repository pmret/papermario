.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005C980
/* 37D80 8005C980 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 37D84 8005C984 44854000 */  mtc1      $a1, $f8
/* 37D88 8005C988 44866000 */  mtc1      $a2, $f12
/* 37D8C 8005C98C 44877000 */  mtc1      $a3, $f14
/* 37D90 8005C990 C7A40078 */  lwc1      $f4, 0x78($sp)
/* 37D94 8005C994 44800000 */  mtc1      $zero, $f0
/* 37D98 8005C998 C7A6007C */  lwc1      $f6, 0x7c($sp)
/* 37D9C 8005C99C C7AA0080 */  lwc1      $f10, 0x80($sp)
/* 37DA0 8005C9A0 AFBE0030 */  sw        $fp, 0x30($sp)
/* 37DA4 8005C9A4 8FBE0090 */  lw        $fp, 0x90($sp)
/* 37DA8 8005C9A8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 37DAC 8005C9AC AFBF0034 */  sw        $ra, 0x34($sp)
/* 37DB0 8005C9B0 AFB60028 */  sw        $s6, 0x28($sp)
/* 37DB4 8005C9B4 AFB50024 */  sw        $s5, 0x24($sp)
/* 37DB8 8005C9B8 AFB40020 */  sw        $s4, 0x20($sp)
/* 37DBC 8005C9BC AFB3001C */  sw        $s3, 0x1c($sp)
/* 37DC0 8005C9C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 37DC4 8005C9C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 37DC8 8005C9C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 37DCC 8005C9CC F7BE0060 */  sdc1      $f30, 0x60($sp)
/* 37DD0 8005C9D0 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 37DD4 8005C9D4 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 37DD8 8005C9D8 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 37DDC 8005C9DC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 37DE0 8005C9E0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 37DE4 8005C9E4 46002032 */  c.eq.s    $f4, $f0
/* 37DE8 8005C9E8 00000000 */  nop
/* 37DEC 8005C9EC 45000009 */  bc1f      .L8005CA14
/* 37DF0 8005C9F0 0080B82D */   daddu    $s7, $a0, $zero
/* 37DF4 8005C9F4 46003032 */  c.eq.s    $f6, $f0
/* 37DF8 8005C9F8 00000000 */  nop
/* 37DFC 8005C9FC 45000005 */  bc1f      .L8005CA14
/* 37E00 8005CA00 00000000 */   nop
/* 37E04 8005CA04 46005032 */  c.eq.s    $f10, $f0
/* 37E08 8005CA08 00000000 */  nop
/* 37E0C 8005CA0C 450100DF */  bc1t      .L8005CD8C
/* 37E10 8005CA10 0000102D */   daddu    $v0, $zero, $zero
.L8005CA14:
/* 37E14 8005CA14 3C15800B */  lui       $s5, %hi(D_800B42C0)
/* 37E18 8005CA18 26B542C0 */  addiu     $s5, $s5, %lo(D_800B42C0)
/* 37E1C 8005CA1C 3C01800A */  lui       $at, %hi(D_800A204C)
/* 37E20 8005CA20 E424204C */  swc1      $f4, %lo(D_800A204C)($at)
/* 37E24 8005CA24 3C01800A */  lui       $at, %hi(D_800A2050)
/* 37E28 8005CA28 E4262050 */  swc1      $f6, %lo(D_800A2050)($at)
/* 37E2C 8005CA2C 3C01800A */  lui       $at, %hi(D_800A2054)
/* 37E30 8005CA30 E42A2054 */  swc1      $f10, %lo(D_800A2054)($at)
/* 37E34 8005CA34 3C01800A */  lui       $at, %hi(D_800A2040)
/* 37E38 8005CA38 E4282040 */  swc1      $f8, %lo(D_800A2040)($at)
/* 37E3C 8005CA3C 3C01800A */  lui       $at, %hi(D_800A2044)
/* 37E40 8005CA40 E42C2044 */  swc1      $f12, %lo(D_800A2044)($at)
/* 37E44 8005CA44 3C01800A */  lui       $at, %hi(D_800A2048)
/* 37E48 8005CA48 E42E2048 */  swc1      $f14, %lo(D_800A2048)($at)
/* 37E4C 8005CA4C C7C20000 */  lwc1      $f2, ($fp)
/* 37E50 8005CA50 4600203C */  c.lt.s    $f4, $f0
/* 37E54 8005CA54 3C01800A */  lui       $at, %hi(D_800A2064)
/* 37E58 8005CA58 E4222064 */  swc1      $f2, %lo(D_800A2064)($at)
/* 37E5C 8005CA5C 45000006 */  bc1f      .L8005CA78
/* 37E60 8005CA60 2414FFFF */   addiu    $s4, $zero, -1
/* 37E64 8005CA64 46022002 */  mul.s     $f0, $f4, $f2
/* 37E68 8005CA68 00000000 */  nop
/* 37E6C 8005CA6C 46004786 */  mov.s     $f30, $f8
/* 37E70 8005CA70 080172A2 */  j         .L8005CA88
/* 37E74 8005CA74 4600F700 */   add.s    $f28, $f30, $f0
.L8005CA78:
/* 37E78 8005CA78 46022002 */  mul.s     $f0, $f4, $f2
/* 37E7C 8005CA7C 00000000 */  nop
/* 37E80 8005CA80 46004706 */  mov.s     $f28, $f8
/* 37E84 8005CA84 4600E780 */  add.s     $f30, $f28, $f0
.L8005CA88:
/* 37E88 8005CA88 44800000 */  mtc1      $zero, $f0
/* 37E8C 8005CA8C 00000000 */  nop
/* 37E90 8005CA90 4600303C */  c.lt.s    $f6, $f0
/* 37E94 8005CA94 00000000 */  nop
/* 37E98 8005CA98 45000007 */  bc1f      .L8005CAB8
/* 37E9C 8005CA9C 46006686 */   mov.s    $f26, $f12
/* 37EA0 8005CAA0 3C01800A */  lui       $at, %hi(D_800A2064)
/* 37EA4 8005CAA4 C4202064 */  lwc1      $f0, %lo(D_800A2064)($at)
/* 37EA8 8005CAA8 46003002 */  mul.s     $f0, $f6, $f0
/* 37EAC 8005CAAC 00000000 */  nop
/* 37EB0 8005CAB0 080172B4 */  j         .L8005CAD0
/* 37EB4 8005CAB4 4600D600 */   add.s    $f24, $f26, $f0
.L8005CAB8:
/* 37EB8 8005CAB8 3C01800A */  lui       $at, %hi(D_800A2064)
/* 37EBC 8005CABC C4202064 */  lwc1      $f0, %lo(D_800A2064)($at)
/* 37EC0 8005CAC0 46003002 */  mul.s     $f0, $f6, $f0
/* 37EC4 8005CAC4 00000000 */  nop
/* 37EC8 8005CAC8 46006606 */  mov.s     $f24, $f12
/* 37ECC 8005CACC 4600C680 */  add.s     $f26, $f24, $f0
.L8005CAD0:
/* 37ED0 8005CAD0 44800000 */  mtc1      $zero, $f0
/* 37ED4 8005CAD4 00000000 */  nop
/* 37ED8 8005CAD8 4600503C */  c.lt.s    $f10, $f0
/* 37EDC 8005CADC 00000000 */  nop
/* 37EE0 8005CAE0 45000007 */  bc1f      .L8005CB00
/* 37EE4 8005CAE4 46007586 */   mov.s    $f22, $f14
/* 37EE8 8005CAE8 3C01800A */  lui       $at, %hi(D_800A2064)
/* 37EEC 8005CAEC C4202064 */  lwc1      $f0, %lo(D_800A2064)($at)
/* 37EF0 8005CAF0 46005002 */  mul.s     $f0, $f10, $f0
/* 37EF4 8005CAF4 00000000 */  nop
/* 37EF8 8005CAF8 080172C6 */  j         .L8005CB18
/* 37EFC 8005CAFC 4600B500 */   add.s    $f20, $f22, $f0
.L8005CB00:
/* 37F00 8005CB00 3C01800A */  lui       $at, %hi(D_800A2064)
/* 37F04 8005CB04 C4202064 */  lwc1      $f0, %lo(D_800A2064)($at)
/* 37F08 8005CB08 46005002 */  mul.s     $f0, $f10, $f0
/* 37F0C 8005CB0C 00000000 */  nop
/* 37F10 8005CB10 46007506 */  mov.s     $f20, $f14
/* 37F14 8005CB14 4600A580 */  add.s     $f22, $f20, $f0
.L8005CB18:
/* 37F18 8005CB18 86A2000C */  lh        $v0, 0xc($s5)
/* 37F1C 8005CB1C 1840007D */  blez      $v0, .L8005CD14
/* 37F20 8005CB20 0000982D */   daddu    $s3, $zero, $zero
/* 37F24 8005CB24 0260B02D */  daddu     $s6, $s3, $zero
.L8005CB28:
/* 37F28 8005CB28 8EA20004 */  lw        $v0, 4($s5)
/* 37F2C 8005CB2C 00569021 */  addu      $s2, $v0, $s6
/* 37F30 8005CB30 8E420000 */  lw        $v0, ($s2)
/* 37F34 8005CB34 00571024 */  and       $v0, $v0, $s7
/* 37F38 8005CB38 54400071 */  bnel      $v0, $zero, .L8005CD00
/* 37F3C 8005CB3C 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37F40 8005CB40 8643000A */  lh        $v1, 0xa($s2)
/* 37F44 8005CB44 5060006E */  beql      $v1, $zero, .L8005CD00
/* 37F48 8005CB48 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37F4C 8005CB4C 8E420010 */  lw        $v0, 0x10($s2)
/* 37F50 8005CB50 C4400000 */  lwc1      $f0, ($v0)
/* 37F54 8005CB54 4600F03C */  c.lt.s    $f30, $f0
/* 37F58 8005CB58 00000000 */  nop
/* 37F5C 8005CB5C 45030068 */  bc1tl     .L8005CD00
/* 37F60 8005CB60 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37F64 8005CB64 C440000C */  lwc1      $f0, 0xc($v0)
/* 37F68 8005CB68 461C003C */  c.lt.s    $f0, $f28
/* 37F6C 8005CB6C 00000000 */  nop
/* 37F70 8005CB70 45030063 */  bc1tl     .L8005CD00
/* 37F74 8005CB74 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37F78 8005CB78 C4400008 */  lwc1      $f0, 8($v0)
/* 37F7C 8005CB7C 4600B03C */  c.lt.s    $f22, $f0
/* 37F80 8005CB80 00000000 */  nop
/* 37F84 8005CB84 4503005E */  bc1tl     .L8005CD00
/* 37F88 8005CB88 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37F8C 8005CB8C C4400014 */  lwc1      $f0, 0x14($v0)
/* 37F90 8005CB90 4614003C */  c.lt.s    $f0, $f20
/* 37F94 8005CB94 00000000 */  nop
/* 37F98 8005CB98 45030059 */  bc1tl     .L8005CD00
/* 37F9C 8005CB9C 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37FA0 8005CBA0 C4400004 */  lwc1      $f0, 4($v0)
/* 37FA4 8005CBA4 4600D03C */  c.lt.s    $f26, $f0
/* 37FA8 8005CBA8 00000000 */  nop
/* 37FAC 8005CBAC 45030054 */  bc1tl     .L8005CD00
/* 37FB0 8005CBB0 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37FB4 8005CBB4 C4400010 */  lwc1      $f0, 0x10($v0)
/* 37FB8 8005CBB8 4618003C */  c.lt.s    $f0, $f24
/* 37FBC 8005CBBC 00000000 */  nop
/* 37FC0 8005CBC0 4503004F */  bc1tl     .L8005CD00
/* 37FC4 8005CBC4 26D6001C */   addiu    $s6, $s6, 0x1c
/* 37FC8 8005CBC8 3C01800A */  lui       $at, %hi(D_800A204C)
/* 37FCC 8005CBCC C420204C */  lwc1      $f0, %lo(D_800A204C)($at)
/* 37FD0 8005CBD0 44808000 */  mtc1      $zero, $f16
/* 37FD4 8005CBD4 8E51000C */  lw        $s1, 0xc($s2)
/* 37FD8 8005CBD8 46100032 */  c.eq.s    $f0, $f16
/* 37FDC 8005CBDC 00000000 */  nop
/* 37FE0 8005CBE0 45000020 */  bc1f      .L8005CC64
/* 37FE4 8005CBE4 00000000 */   nop
/* 37FE8 8005CBE8 3C01800A */  lui       $at, %hi(D_800A2054)
/* 37FEC 8005CBEC C4202054 */  lwc1      $f0, %lo(D_800A2054)($at)
/* 37FF0 8005CBF0 46100032 */  c.eq.s    $f0, $f16
/* 37FF4 8005CBF4 00000000 */  nop
/* 37FF8 8005CBF8 4500001A */  bc1f      .L8005CC64
/* 37FFC 8005CBFC 00000000 */   nop
/* 38000 8005CC00 3C01800A */  lui       $at, %hi(D_800A2050)
/* 38004 8005CC04 C4202050 */  lwc1      $f0, %lo(D_800A2050)($at)
/* 38008 8005CC08 3C01BFF0 */  lui       $at, 0xbff0
/* 3800C 8005CC0C 44811800 */  mtc1      $at, $f3
/* 38010 8005CC10 44801000 */  mtc1      $zero, $f2
/* 38014 8005CC14 46000021 */  cvt.d.s   $f0, $f0
/* 38018 8005CC18 46220032 */  c.eq.d    $f0, $f2
/* 3801C 8005CC1C 00000000 */  nop
/* 38020 8005CC20 45000010 */  bc1f      .L8005CC64
/* 38024 8005CC24 00000000 */   nop
/* 38028 8005CC28 18600034 */  blez      $v1, .L8005CCFC
/* 3802C 8005CC2C 0000802D */   daddu    $s0, $zero, $zero
/* 38030 8005CC30 0220202D */  daddu     $a0, $s1, $zero
.L8005CC34:
/* 38034 8005CC34 8EA50000 */  lw        $a1, ($s5)
/* 38038 8005CC38 0C017053 */  jal       func_8005C14C
/* 3803C 8005CC3C 26310040 */   addiu    $s1, $s1, 0x40
/* 38040 8005CC40 54400001 */  bnel      $v0, $zero, .L8005CC48
/* 38044 8005CC44 0260A02D */   daddu    $s4, $s3, $zero
.L8005CC48:
/* 38048 8005CC48 8642000A */  lh        $v0, 0xa($s2)
/* 3804C 8005CC4C 26100001 */  addiu     $s0, $s0, 1
/* 38050 8005CC50 0202102A */  slt       $v0, $s0, $v0
/* 38054 8005CC54 1440FFF7 */  bnez      $v0, .L8005CC34
/* 38058 8005CC58 0220202D */   daddu    $a0, $s1, $zero
/* 3805C 8005CC5C 08017340 */  j         .L8005CD00
/* 38060 8005CC60 26D6001C */   addiu    $s6, $s6, 0x1c
.L8005CC64:
/* 38064 8005CC64 3C01800A */  lui       $at, %hi(D_800A2050)
/* 38068 8005CC68 C4202050 */  lwc1      $f0, %lo(D_800A2050)($at)
/* 3806C 8005CC6C 44808000 */  mtc1      $zero, $f16
/* 38070 8005CC70 00000000 */  nop
/* 38074 8005CC74 46100032 */  c.eq.s    $f0, $f16
/* 38078 8005CC78 00000000 */  nop
/* 3807C 8005CC7C 45000011 */  bc1f      .L8005CCC4
/* 38080 8005CC80 00000000 */   nop
/* 38084 8005CC84 8642000A */  lh        $v0, 0xa($s2)
/* 38088 8005CC88 1840001C */  blez      $v0, .L8005CCFC
/* 3808C 8005CC8C 0000802D */   daddu    $s0, $zero, $zero
/* 38090 8005CC90 0220202D */  daddu     $a0, $s1, $zero
.L8005CC94:
/* 38094 8005CC94 8EA50000 */  lw        $a1, ($s5)
/* 38098 8005CC98 0C017115 */  jal       func_8005C454
/* 3809C 8005CC9C 26310040 */   addiu    $s1, $s1, 0x40
/* 380A0 8005CCA0 54400001 */  bnel      $v0, $zero, .L8005CCA8
/* 380A4 8005CCA4 0260A02D */   daddu    $s4, $s3, $zero
.L8005CCA8:
/* 380A8 8005CCA8 8642000A */  lh        $v0, 0xa($s2)
/* 380AC 8005CCAC 26100001 */  addiu     $s0, $s0, 1
/* 380B0 8005CCB0 0202102A */  slt       $v0, $s0, $v0
/* 380B4 8005CCB4 1440FFF7 */  bnez      $v0, .L8005CC94
/* 380B8 8005CCB8 0220202D */   daddu    $a0, $s1, $zero
/* 380BC 8005CCBC 08017340 */  j         .L8005CD00
/* 380C0 8005CCC0 26D6001C */   addiu    $s6, $s6, 0x1c
.L8005CCC4:
/* 380C4 8005CCC4 8642000A */  lh        $v0, 0xa($s2)
/* 380C8 8005CCC8 1840000C */  blez      $v0, .L8005CCFC
/* 380CC 8005CCCC 0000802D */   daddu    $s0, $zero, $zero
/* 380D0 8005CCD0 0220202D */  daddu     $a0, $s1, $zero
.L8005CCD4:
/* 380D4 8005CCD4 8EA50000 */  lw        $a1, ($s5)
/* 380D8 8005CCD8 0C016ECD */  jal       func_8005BB34
/* 380DC 8005CCDC 26310040 */   addiu    $s1, $s1, 0x40
/* 380E0 8005CCE0 54400001 */  bnel      $v0, $zero, .L8005CCE8
/* 380E4 8005CCE4 0260A02D */   daddu    $s4, $s3, $zero
.L8005CCE8:
/* 380E8 8005CCE8 8642000A */  lh        $v0, 0xa($s2)
/* 380EC 8005CCEC 26100001 */  addiu     $s0, $s0, 1
/* 380F0 8005CCF0 0202102A */  slt       $v0, $s0, $v0
/* 380F4 8005CCF4 1440FFF7 */  bnez      $v0, .L8005CCD4
/* 380F8 8005CCF8 0220202D */   daddu    $a0, $s1, $zero
.L8005CCFC:
/* 380FC 8005CCFC 26D6001C */  addiu     $s6, $s6, 0x1c
.L8005CD00:
/* 38100 8005CD00 86A2000C */  lh        $v0, 0xc($s5)
/* 38104 8005CD04 26730001 */  addiu     $s3, $s3, 1
/* 38108 8005CD08 0262102A */  slt       $v0, $s3, $v0
/* 3810C 8005CD0C 1440FF86 */  bnez      $v0, .L8005CB28
/* 38110 8005CD10 00000000 */   nop
.L8005CD14:
/* 38114 8005CD14 0680001D */  bltz      $s4, .L8005CD8C
/* 38118 8005CD18 0280102D */   daddu    $v0, $s4, $zero
/* 3811C 8005CD1C 3C01800A */  lui       $at, %hi(D_800A2058)
/* 38120 8005CD20 C4202058 */  lwc1      $f0, %lo(D_800A2058)($at)
/* 38124 8005CD24 8FA20084 */  lw        $v0, 0x84($sp)
/* 38128 8005CD28 E4400000 */  swc1      $f0, ($v0)
/* 3812C 8005CD2C 3C01800A */  lui       $at, %hi(D_800A205C)
/* 38130 8005CD30 C420205C */  lwc1      $f0, %lo(D_800A205C)($at)
/* 38134 8005CD34 8FA20088 */  lw        $v0, 0x88($sp)
/* 38138 8005CD38 E4400000 */  swc1      $f0, ($v0)
/* 3813C 8005CD3C 3C01800A */  lui       $at, %hi(D_800A2060)
/* 38140 8005CD40 C4202060 */  lwc1      $f0, %lo(D_800A2060)($at)
/* 38144 8005CD44 8FA2008C */  lw        $v0, 0x8c($sp)
/* 38148 8005CD48 E4400000 */  swc1      $f0, ($v0)
/* 3814C 8005CD4C 3C01800A */  lui       $at, %hi(D_800A2064)
/* 38150 8005CD50 C4202064 */  lwc1      $f0, %lo(D_800A2064)($at)
/* 38154 8005CD54 E7C00000 */  swc1      $f0, ($fp)
/* 38158 8005CD58 3C01800A */  lui       $at, %hi(D_800A2068)
/* 3815C 8005CD5C C4202068 */  lwc1      $f0, %lo(D_800A2068)($at)
/* 38160 8005CD60 8FA20094 */  lw        $v0, 0x94($sp)
/* 38164 8005CD64 E4400000 */  swc1      $f0, ($v0)
/* 38168 8005CD68 3C01800A */  lui       $at, %hi(D_800A206C)
/* 3816C 8005CD6C C420206C */  lwc1      $f0, %lo(D_800A206C)($at)
/* 38170 8005CD70 8FA20098 */  lw        $v0, 0x98($sp)
/* 38174 8005CD74 E4400000 */  swc1      $f0, ($v0)
/* 38178 8005CD78 3C01800A */  lui       $at, %hi(D_800A2070)
/* 3817C 8005CD7C C4202070 */  lwc1      $f0, %lo(D_800A2070)($at)
/* 38180 8005CD80 8FA3009C */  lw        $v1, 0x9c($sp)
/* 38184 8005CD84 0280102D */  daddu     $v0, $s4, $zero
/* 38188 8005CD88 E4600000 */  swc1      $f0, ($v1)
.L8005CD8C:
/* 3818C 8005CD8C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 38190 8005CD90 8FBE0030 */  lw        $fp, 0x30($sp)
/* 38194 8005CD94 8FB7002C */  lw        $s7, 0x2c($sp)
/* 38198 8005CD98 8FB60028 */  lw        $s6, 0x28($sp)
/* 3819C 8005CD9C 8FB50024 */  lw        $s5, 0x24($sp)
/* 381A0 8005CDA0 8FB40020 */  lw        $s4, 0x20($sp)
/* 381A4 8005CDA4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 381A8 8005CDA8 8FB20018 */  lw        $s2, 0x18($sp)
/* 381AC 8005CDAC 8FB10014 */  lw        $s1, 0x14($sp)
/* 381B0 8005CDB0 8FB00010 */  lw        $s0, 0x10($sp)
/* 381B4 8005CDB4 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* 381B8 8005CDB8 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 381BC 8005CDBC D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 381C0 8005CDC0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 381C4 8005CDC4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 381C8 8005CDC8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 381CC 8005CDCC 03E00008 */  jr        $ra
/* 381D0 8005CDD0 27BD0068 */   addiu    $sp, $sp, 0x68
