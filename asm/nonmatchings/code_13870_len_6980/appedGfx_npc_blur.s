.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel appedGfx_npc_blur
/* 16238 8003AE38 27BDFF08 */  addiu     $sp, $sp, -0xf8
/* 1623C 8003AE3C F7BC00E8 */  sdc1      $f28, 0xe8($sp)
/* 16240 8003AE40 4480E000 */  mtc1      $zero, $f28
/* 16244 8003AE44 F7BA00E0 */  sdc1      $f26, 0xe0($sp)
/* 16248 8003AE48 3C01800A */  lui       $at, %hi(D_800984C0)
/* 1624C 8003AE4C D43A84C0 */  ldc1      $f26, %lo(D_800984C0)($at)
/* 16250 8003AE50 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 16254 8003AE54 0080802D */  daddu     $s0, $a0, $zero
/* 16258 8003AE58 AFB300AC */  sw        $s3, 0xac($sp)
/* 1625C 8003AE5C 0000982D */  daddu     $s3, $zero, $zero
/* 16260 8003AE60 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 16264 8003AE64 0260A82D */  daddu     $s5, $s3, $zero
/* 16268 8003AE68 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 1626C 8003AE6C 27B10060 */  addiu     $s1, $sp, 0x60
/* 16270 8003AE70 AFB700BC */  sw        $s7, 0xbc($sp)
/* 16274 8003AE74 27B70020 */  addiu     $s7, $sp, 0x20
/* 16278 8003AE78 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 1627C 8003AE7C 0260A02D */  daddu     $s4, $s3, $zero
/* 16280 8003AE80 AFBF00C0 */  sw        $ra, 0xc0($sp)
/* 16284 8003AE84 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 16288 8003AE88 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 1628C 8003AE8C F7BE00F0 */  sdc1      $f30, 0xf0($sp)
/* 16290 8003AE90 F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* 16294 8003AE94 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 16298 8003AE98 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 1629C 8003AE9C 8E160020 */  lw        $s6, 0x20($s0)
/* 162A0 8003AEA0 3C013FF0 */  lui       $at, 0x3ff0
/* 162A4 8003AEA4 4481F800 */  mtc1      $at, $f31
/* 162A8 8003AEA8 4480F000 */  mtc1      $zero, $f30
/* 162AC 8003AEAC 82D20001 */  lb        $s2, 1($s6)
/* 162B0 8003AEB0 2652FFFF */  addiu     $s2, $s2, -1
.L8003AEB4:
/* 162B4 8003AEB4 06410002 */  bgez      $s2, .L8003AEC0
/* 162B8 8003AEB8 26730001 */   addiu    $s3, $s3, 1
/* 162BC 8003AEBC 24120013 */  addiu     $s2, $zero, 0x13
.L8003AEC0:
/* 162C0 8003AEC0 82C20001 */  lb        $v0, 1($s6)
/* 162C4 8003AEC4 1242009C */  beq       $s2, $v0, .L8003B138
/* 162C8 8003AEC8 2A620003 */   slti     $v0, $s3, 3
/* 162CC 8003AECC 5440FFF9 */  bnel      $v0, $zero, .L8003AEB4
/* 162D0 8003AED0 2652FFFF */   addiu    $s2, $s2, -1
/* 162D4 8003AED4 0000982D */  daddu     $s3, $zero, $zero
/* 162D8 8003AED8 26B50001 */  addiu     $s5, $s5, 1
/* 162DC 8003AEDC 2AA20004 */  slti      $v0, $s5, 4
/* 162E0 8003AEE0 10400095 */  beqz      $v0, .L8003B138
/* 162E4 8003AEE4 26940014 */   addiu    $s4, $s4, 0x14
/* 162E8 8003AEE8 24050007 */  addiu     $a1, $zero, 7
/* 162EC 8003AEEC 240600FF */  addiu     $a2, $zero, 0xff
/* 162F0 8003AEF0 00121080 */  sll       $v0, $s2, 2
/* 162F4 8003AEF4 02C21021 */  addu      $v0, $s6, $v0
/* 162F8 8003AEF8 C4540004 */  lwc1      $f20, 4($v0)
/* 162FC 8003AEFC C4560054 */  lwc1      $f22, 0x54($v0)
/* 16300 8003AF00 C45800A4 */  lwc1      $f24, 0xa4($v0)
/* 16304 8003AF04 00C0102D */  daddu     $v0, $a2, $zero
/* 16308 8003AF08 AFA20010 */  sw        $v0, 0x10($sp)
/* 1630C 8003AF0C 24020078 */  addiu     $v0, $zero, 0x78
/* 16310 8003AF10 00541023 */  subu      $v0, $v0, $s4
/* 16314 8003AF14 AFA20014 */  sw        $v0, 0x14($sp)
/* 16318 8003AF18 AFA00018 */  sw        $zero, 0x18($sp)
/* 1631C 8003AF1C 8E040024 */  lw        $a0, 0x24($s0)
/* 16320 8003AF20 0C0B7A25 */  jal       func_802DE894
/* 16324 8003AF24 00C0382D */   daddu    $a3, $a2, $zero
/* 16328 8003AF28 4405A000 */  mfc1      $a1, $f20
/* 1632C 8003AF2C 4406B000 */  mfc1      $a2, $f22
/* 16330 8003AF30 4407C000 */  mfc1      $a3, $f24
/* 16334 8003AF34 C6140034 */  lwc1      $f20, 0x34($s0)
/* 16338 8003AF38 0C019E40 */  jal       guTranslateF
/* 1633C 8003AF3C 27A40020 */   addiu    $a0, $sp, 0x20
/* 16340 8003AF40 C6000048 */  lwc1      $f0, 0x48($s0)
/* 16344 8003AF44 461C0032 */  c.eq.s    $f0, $f28
/* 16348 8003AF48 00000000 */  nop       
/* 1634C 8003AF4C 4501000B */  bc1t      .L8003AF7C
/* 16350 8003AF50 00000000 */   nop      
/* 16354 8003AF54 E7BC0010 */  swc1      $f28, 0x10($sp)
/* 16358 8003AF58 8E050048 */  lw        $a1, 0x48($s0)
/* 1635C 8003AF5C 4406E000 */  mfc1      $a2, $f28
/* 16360 8003AF60 3C073F80 */  lui       $a3, 0x3f80
/* 16364 8003AF64 0C019EC8 */  jal       guRotateF
/* 16368 8003AF68 0220202D */   daddu    $a0, $s1, $zero
/* 1636C 8003AF6C 0220202D */  daddu     $a0, $s1, $zero
/* 16370 8003AF70 27A50020 */  addiu     $a1, $sp, 0x20
/* 16374 8003AF74 0C019D80 */  jal       guMtxCatF
/* 16378 8003AF78 00A0302D */   daddu    $a2, $a1, $zero
.L8003AF7C:
/* 1637C 8003AF7C C6000044 */  lwc1      $f0, 0x44($s0)
/* 16380 8003AF80 461C0032 */  c.eq.s    $f0, $f28
/* 16384 8003AF84 00000000 */  nop       
/* 16388 8003AF88 4501000B */  bc1t      .L8003AFB8
/* 1638C 8003AF8C 00000000 */   nop      
/* 16390 8003AF90 E7BC0010 */  swc1      $f28, 0x10($sp)
/* 16394 8003AF94 8E050048 */  lw        $a1, 0x48($s0)
/* 16398 8003AF98 4406E000 */  mfc1      $a2, $f28
/* 1639C 8003AF9C 3C073F80 */  lui       $a3, 0x3f80
/* 163A0 8003AFA0 0C019EC8 */  jal       guRotateF
/* 163A4 8003AFA4 0220202D */   daddu    $a0, $s1, $zero
/* 163A8 8003AFA8 0220202D */  daddu     $a0, $s1, $zero
/* 163AC 8003AFAC 27A50020 */  addiu     $a1, $sp, 0x20
/* 163B0 8003AFB0 0C019D80 */  jal       guMtxCatF
/* 163B4 8003AFB4 00A0302D */   daddu    $a2, $a1, $zero
.L8003AFB8:
/* 163B8 8003AFB8 C600004C */  lwc1      $f0, 0x4c($s0)
/* 163BC 8003AFBC 461C0032 */  c.eq.s    $f0, $f28
/* 163C0 8003AFC0 00000000 */  nop       
/* 163C4 8003AFC4 4501000B */  bc1t      .L8003AFF4
/* 163C8 8003AFC8 00000000 */   nop      
/* 163CC 8003AFCC E7BC0010 */  swc1      $f28, 0x10($sp)
/* 163D0 8003AFD0 8E050048 */  lw        $a1, 0x48($s0)
/* 163D4 8003AFD4 4406E000 */  mfc1      $a2, $f28
/* 163D8 8003AFD8 3C073F80 */  lui       $a3, 0x3f80
/* 163DC 8003AFDC 0C019EC8 */  jal       guRotateF
/* 163E0 8003AFE0 0220202D */   daddu    $a0, $s1, $zero
/* 163E4 8003AFE4 0220202D */  daddu     $a0, $s1, $zero
/* 163E8 8003AFE8 27A50020 */  addiu     $a1, $sp, 0x20
/* 163EC 8003AFEC 0C019D80 */  jal       guMtxCatF
/* 163F0 8003AFF0 00A0302D */   daddu    $a2, $a1, $zero
.L8003AFF4:
/* 163F4 8003AFF4 C6000054 */  lwc1      $f0, 0x54($s0)
/* 163F8 8003AFF8 46000021 */  cvt.d.s   $f0, $f0
/* 163FC 8003AFFC 463A0002 */  mul.d     $f0, $f0, $f26
/* 16400 8003B000 00000000 */  nop       
/* 16404 8003B004 463E0032 */  c.eq.d    $f0, $f30
/* 16408 8003B008 00000000 */  nop       
/* 1640C 8003B00C 45000014 */  bc1f      .L8003B060
/* 16410 8003B010 00000000 */   nop      
/* 16414 8003B014 C6000058 */  lwc1      $f0, 0x58($s0)
/* 16418 8003B018 C6020320 */  lwc1      $f2, 0x320($s0)
/* 1641C 8003B01C 46020002 */  mul.s     $f0, $f0, $f2
/* 16420 8003B020 00000000 */  nop       
/* 16424 8003B024 46000021 */  cvt.d.s   $f0, $f0
/* 16428 8003B028 463A0002 */  mul.d     $f0, $f0, $f26
/* 1642C 8003B02C 00000000 */  nop       
/* 16430 8003B030 463E0032 */  c.eq.d    $f0, $f30
/* 16434 8003B034 00000000 */  nop       
/* 16438 8003B038 45000009 */  bc1f      .L8003B060
/* 1643C 8003B03C 00000000 */   nop      
/* 16440 8003B040 C600005C */  lwc1      $f0, 0x5c($s0)
/* 16444 8003B044 46000021 */  cvt.d.s   $f0, $f0
/* 16448 8003B048 463A0002 */  mul.d     $f0, $f0, $f26
/* 1644C 8003B04C 00000000 */  nop       
/* 16450 8003B050 463E0032 */  c.eq.d    $f0, $f30
/* 16454 8003B054 00000000 */  nop       
/* 16458 8003B058 4501001C */  bc1t      .L8003B0CC
/* 1645C 8003B05C 00000000 */   nop      
.L8003B060:
/* 16460 8003B060 C6060054 */  lwc1      $f6, 0x54($s0)
/* 16464 8003B064 460031A1 */  cvt.d.s   $f6, $f6
/* 16468 8003B068 463A3182 */  mul.d     $f6, $f6, $f26
/* 1646C 8003B06C 00000000 */  nop       
/* 16470 8003B070 C604005C */  lwc1      $f4, 0x5c($s0)
/* 16474 8003B074 46002121 */  cvt.d.s   $f4, $f4
/* 16478 8003B078 463A2102 */  mul.d     $f4, $f4, $f26
/* 1647C 8003B07C 00000000 */  nop       
/* 16480 8003B080 C6000058 */  lwc1      $f0, 0x58($s0)
/* 16484 8003B084 C6020320 */  lwc1      $f2, 0x320($s0)
/* 16488 8003B088 46020002 */  mul.s     $f0, $f0, $f2
/* 1648C 8003B08C 00000000 */  nop       
/* 16490 8003B090 46000021 */  cvt.d.s   $f0, $f0
/* 16494 8003B094 463A0002 */  mul.d     $f0, $f0, $f26
/* 16498 8003B098 00000000 */  nop       
/* 1649C 8003B09C 462031A0 */  cvt.s.d   $f6, $f6
/* 164A0 8003B0A0 46202120 */  cvt.s.d   $f4, $f4
/* 164A4 8003B0A4 44053000 */  mfc1      $a1, $f6
/* 164A8 8003B0A8 44072000 */  mfc1      $a3, $f4
/* 164AC 8003B0AC 46200020 */  cvt.s.d   $f0, $f0
/* 164B0 8003B0B0 44060000 */  mfc1      $a2, $f0
/* 164B4 8003B0B4 0C019DF0 */  jal       guScaleF
/* 164B8 8003B0B8 0220202D */   daddu    $a0, $s1, $zero
/* 164BC 8003B0BC 0220202D */  daddu     $a0, $s1, $zero
/* 164C0 8003B0C0 27A50020 */  addiu     $a1, $sp, 0x20
/* 164C4 8003B0C4 0C019D80 */  jal       guMtxCatF
/* 164C8 8003B0C8 00A0302D */   daddu    $a2, $a1, $zero
.L8003B0CC:
/* 164CC 8003B0CC 8E030000 */  lw        $v1, ($s0)
/* 164D0 8003B0D0 3C024000 */  lui       $v0, 0x4000
/* 164D4 8003B0D4 00621024 */  and       $v0, $v1, $v0
/* 164D8 8003B0D8 5440000E */  bnel      $v0, $zero, .L8003B114
/* 164DC 8003B0DC AFB70010 */   sw       $s7, 0x10($sp)
/* 164E0 8003B0E0 3C020100 */  lui       $v0, 0x100
/* 164E4 8003B0E4 00621024 */  and       $v0, $v1, $v0
/* 164E8 8003B0E8 5440FF72 */  bnel      $v0, $zero, .L8003AEB4
/* 164EC 8003B0EC 2652FFFF */   addiu    $s2, $s2, -1
/* 164F0 8003B0F0 4600A20D */  trunc.w.s $f8, $f20
/* 164F4 8003B0F4 44054000 */  mfc1      $a1, $f8
/* 164F8 8003B0F8 0000302D */  daddu     $a2, $zero, $zero
/* 164FC 8003B0FC AFB70010 */  sw        $s7, 0x10($sp)
/* 16500 8003B100 8E040024 */  lw        $a0, 0x24($s0)
/* 16504 8003B104 0C0B78F6 */  jal       func_802DE3D8
/* 16508 8003B108 00C0382D */   daddu    $a3, $a2, $zero
/* 1650C 8003B10C 0800EBAD */  j         .L8003AEB4
/* 16510 8003B110 2652FFFF */   addiu    $s2, $s2, -1
.L8003B114:
/* 16514 8003B114 3C044000 */  lui       $a0, 0x4000
/* 16518 8003B118 34840001 */  ori       $a0, $a0, 1
/* 1651C 8003B11C 4600A20D */  trunc.w.s $f8, $f20
/* 16520 8003B120 44054000 */  mfc1      $a1, $f8
/* 16524 8003B124 0000302D */  daddu     $a2, $zero, $zero
/* 16528 8003B128 0C0B7710 */  jal       render_sprite
/* 1652C 8003B12C 00C0382D */   daddu    $a3, $a2, $zero
/* 16530 8003B130 0800EBAD */  j         .L8003AEB4
/* 16534 8003B134 2652FFFF */   addiu    $s2, $s2, -1
.L8003B138:
/* 16538 8003B138 0C00F4EF */  jal       func_8003D3BC
/* 1653C 8003B13C 0200202D */   daddu    $a0, $s0, $zero
/* 16540 8003B140 8FBF00C0 */  lw        $ra, 0xc0($sp)
/* 16544 8003B144 8FB700BC */  lw        $s7, 0xbc($sp)
/* 16548 8003B148 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 1654C 8003B14C 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 16550 8003B150 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 16554 8003B154 8FB300AC */  lw        $s3, 0xac($sp)
/* 16558 8003B158 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 1655C 8003B15C 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 16560 8003B160 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 16564 8003B164 D7BE00F0 */  ldc1      $f30, 0xf0($sp)
/* 16568 8003B168 D7BC00E8 */  ldc1      $f28, 0xe8($sp)
/* 1656C 8003B16C D7BA00E0 */  ldc1      $f26, 0xe0($sp)
/* 16570 8003B170 D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* 16574 8003B174 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 16578 8003B178 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 1657C 8003B17C 03E00008 */  jr        $ra
/* 16580 8003B180 27BD00F8 */   addiu    $sp, $sp, 0xf8
