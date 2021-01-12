.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB8_ED0BA8
/* ED0BA8 80240BB8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ED0BAC 80240BBC AFB3004C */  sw        $s3, 0x4c($sp)
/* ED0BB0 80240BC0 0080982D */  daddu     $s3, $a0, $zero
/* ED0BB4 80240BC4 AFBF0054 */  sw        $ra, 0x54($sp)
/* ED0BB8 80240BC8 AFB40050 */  sw        $s4, 0x50($sp)
/* ED0BBC 80240BCC AFB20048 */  sw        $s2, 0x48($sp)
/* ED0BC0 80240BD0 AFB10044 */  sw        $s1, 0x44($sp)
/* ED0BC4 80240BD4 AFB00040 */  sw        $s0, 0x40($sp)
/* ED0BC8 80240BD8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* ED0BCC 80240BDC F7B80068 */  sdc1      $f24, 0x68($sp)
/* ED0BD0 80240BE0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* ED0BD4 80240BE4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* ED0BD8 80240BE8 8E710148 */  lw        $s1, 0x148($s3)
/* ED0BDC 80240BEC 00A0902D */  daddu     $s2, $a1, $zero
/* ED0BE0 80240BF0 86240008 */  lh        $a0, 8($s1)
/* ED0BE4 80240BF4 0C00F92F */  jal       func_8003E4BC
/* ED0BE8 80240BF8 00C0A02D */   daddu    $s4, $a2, $zero
/* ED0BEC 80240BFC 0040802D */  daddu     $s0, $v0, $zero
/* ED0BF0 80240C00 C6200078 */  lwc1      $f0, 0x78($s1)
/* ED0BF4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* ED0BF8 80240C08 46000021 */  cvt.d.s   $f0, $f0
/* ED0BFC 80240C0C 3C014059 */  lui       $at, 0x4059
/* ED0C00 80240C10 44811800 */  mtc1      $at, $f3
/* ED0C04 80240C14 44801000 */  mtc1      $zero, $f2
/* ED0C08 80240C18 8602008E */  lh        $v0, 0x8e($s0)
/* ED0C0C 80240C1C 9603008E */  lhu       $v1, 0x8e($s0)
/* ED0C10 80240C20 46220003 */  div.d     $f0, $f0, $f2
/* ED0C14 80240C24 46200620 */  cvt.s.d   $f24, $f0
/* ED0C18 80240C28 C6200088 */  lwc1      $f0, 0x88($s1)
/* ED0C1C 80240C2C 46800020 */  cvt.s.w   $f0, $f0
/* ED0C20 80240C30 46000021 */  cvt.d.s   $f0, $f0
/* ED0C24 80240C34 46220003 */  div.d     $f0, $f0, $f2
/* ED0C28 80240C38 46200020 */  cvt.s.d   $f0, $f0
/* ED0C2C 80240C3C 18400003 */  blez      $v0, .L80240C4C
/* ED0C30 80240C40 4600C680 */   add.s    $f26, $f24, $f0
/* ED0C34 80240C44 2462FFFF */  addiu     $v0, $v1, -1
/* ED0C38 80240C48 A602008E */  sh        $v0, 0x8e($s0)
.L80240C4C:
/* ED0C3C 80240C4C 8E220070 */  lw        $v0, 0x70($s1)
/* ED0C40 80240C50 18400034 */  blez      $v0, .L80240D24
/* ED0C44 80240C54 00000000 */   nop      
/* ED0C48 80240C58 C62C0074 */  lwc1      $f12, 0x74($s1)
/* ED0C4C 80240C5C 46806320 */  cvt.s.w   $f12, $f12
/* ED0C50 80240C60 44820000 */  mtc1      $v0, $f0
/* ED0C54 80240C64 00000000 */  nop       
/* ED0C58 80240C68 46800020 */  cvt.s.w   $f0, $f0
/* ED0C5C 80240C6C 46000021 */  cvt.d.s   $f0, $f0
/* ED0C60 80240C70 46220003 */  div.d     $f0, $f0, $f2
/* ED0C64 80240C74 0C00AD77 */  jal       func_8002B5DC
/* ED0C68 80240C78 462005A0 */   cvt.s.d  $f22, $f0
/* ED0C6C 80240C7C 8E020000 */  lw        $v0, ($s0)
/* ED0C70 80240C80 30420008 */  andi      $v0, $v0, 8
/* ED0C74 80240C84 10400003 */  beqz      $v0, .L80240C94
/* ED0C78 80240C88 46000506 */   mov.s    $f20, $f0
/* ED0C7C 80240C8C 08090335 */  j         .L80240CD4
/* ED0C80 80240C90 0000102D */   daddu    $v0, $zero, $zero
.L80240C94:
/* ED0C84 80240C94 27A50028 */  addiu     $a1, $sp, 0x28
/* ED0C88 80240C98 27A6002C */  addiu     $a2, $sp, 0x2c
/* ED0C8C 80240C9C C6000038 */  lwc1      $f0, 0x38($s0)
/* ED0C90 80240CA0 C602003C */  lwc1      $f2, 0x3c($s0)
/* ED0C94 80240CA4 C6040040 */  lwc1      $f4, 0x40($s0)
/* ED0C98 80240CA8 3C01447A */  lui       $at, 0x447a
/* ED0C9C 80240CAC 44813000 */  mtc1      $at, $f6
/* ED0CA0 80240CB0 27A20034 */  addiu     $v0, $sp, 0x34
/* ED0CA4 80240CB4 E7A00028 */  swc1      $f0, 0x28($sp)
/* ED0CA8 80240CB8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* ED0CAC 80240CBC E7A40030 */  swc1      $f4, 0x30($sp)
/* ED0CB0 80240CC0 E7A60034 */  swc1      $f6, 0x34($sp)
/* ED0CB4 80240CC4 AFA20010 */  sw        $v0, 0x10($sp)
/* ED0CB8 80240CC8 8E040080 */  lw        $a0, 0x80($s0)
/* ED0CBC 80240CCC 0C03908F */  jal       func_800E423C
/* ED0CC0 80240CD0 27A70030 */   addiu    $a3, $sp, 0x30
.L80240CD4:
/* ED0CC4 80240CD4 10400007 */  beqz      $v0, .L80240CF4
/* ED0CC8 80240CD8 00000000 */   nop      
/* ED0CCC 80240CDC 4616A082 */  mul.s     $f2, $f20, $f22
/* ED0CD0 80240CE0 00000000 */  nop       
/* ED0CD4 80240CE4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* ED0CD8 80240CE8 46180000 */  add.s     $f0, $f0, $f24
/* ED0CDC 80240CEC 08090340 */  j         .L80240D00
/* ED0CE0 80240CF0 46020000 */   add.s    $f0, $f0, $f2
.L80240CF4:
/* ED0CE4 80240CF4 4616A002 */  mul.s     $f0, $f20, $f22
/* ED0CE8 80240CF8 00000000 */  nop       
/* ED0CEC 80240CFC 4600D000 */  add.s     $f0, $f26, $f0
.L80240D00:
/* ED0CF0 80240D00 E600003C */  swc1      $f0, 0x3c($s0)
/* ED0CF4 80240D04 8E220074 */  lw        $v0, 0x74($s1)
/* ED0CF8 80240D08 2442000A */  addiu     $v0, $v0, 0xa
/* ED0CFC 80240D0C 44826000 */  mtc1      $v0, $f12
/* ED0D00 80240D10 00000000 */  nop       
/* ED0D04 80240D14 0C00AB85 */  jal       func_8002AE14
/* ED0D08 80240D18 46806320 */   cvt.s.w  $f12, $f12
/* ED0D0C 80240D1C 4600020D */  trunc.w.s $f8, $f0
/* ED0D10 80240D20 E6280074 */  swc1      $f8, 0x74($s1)
.L80240D24:
/* ED0D14 80240D24 8E220090 */  lw        $v0, 0x90($s1)
/* ED0D18 80240D28 1C400040 */  bgtz      $v0, .L80240E2C
/* ED0D1C 80240D2C 2442FFFF */   addiu    $v0, $v0, -1
/* ED0D20 80240D30 860200A8 */  lh        $v0, 0xa8($s0)
/* ED0D24 80240D34 C600003C */  lwc1      $f0, 0x3c($s0)
/* ED0D28 80240D38 44821000 */  mtc1      $v0, $f2
/* ED0D2C 80240D3C 00000000 */  nop       
/* ED0D30 80240D40 468010A0 */  cvt.s.w   $f2, $f2
/* ED0D34 80240D44 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* ED0D38 80240D48 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* ED0D3C 80240D4C 46020000 */  add.s     $f0, $f0, $f2
/* ED0D40 80240D50 3C014024 */  lui       $at, 0x4024
/* ED0D44 80240D54 44812800 */  mtc1      $at, $f5
/* ED0D48 80240D58 44802000 */  mtc1      $zero, $f4
/* ED0D4C 80240D5C C442002C */  lwc1      $f2, 0x2c($v0)
/* ED0D50 80240D60 46000021 */  cvt.d.s   $f0, $f0
/* ED0D54 80240D64 46240000 */  add.d     $f0, $f0, $f4
/* ED0D58 80240D68 460010A1 */  cvt.d.s   $f2, $f2
/* ED0D5C 80240D6C 4620103C */  c.lt.d    $f2, $f0
/* ED0D60 80240D70 00000000 */  nop       
/* ED0D64 80240D74 4500002E */  bc1f      .L80240E30
/* ED0D68 80240D78 0280202D */   daddu    $a0, $s4, $zero
/* ED0D6C 80240D7C 24020001 */  addiu     $v0, $zero, 1
/* ED0D70 80240D80 AFA20010 */  sw        $v0, 0x10($sp)
/* ED0D74 80240D84 8E460024 */  lw        $a2, 0x24($s2)
/* ED0D78 80240D88 8E470028 */  lw        $a3, 0x28($s2)
/* ED0D7C 80240D8C 0C013469 */  jal       func_8004D1A4
/* ED0D80 80240D90 0220282D */   daddu    $a1, $s1, $zero
/* ED0D84 80240D94 10400026 */  beqz      $v0, .L80240E30
/* ED0D88 80240D98 0000202D */   daddu    $a0, $zero, $zero
/* ED0D8C 80240D9C 0200282D */  daddu     $a1, $s0, $zero
/* ED0D90 80240DA0 0000302D */  daddu     $a2, $zero, $zero
/* ED0D94 80240DA4 2412000C */  addiu     $s2, $zero, 0xc
/* ED0D98 80240DA8 860300A8 */  lh        $v1, 0xa8($s0)
/* ED0D9C 80240DAC 3C013F80 */  lui       $at, 0x3f80
/* ED0DA0 80240DB0 44810000 */  mtc1      $at, $f0
/* ED0DA4 80240DB4 3C014000 */  lui       $at, 0x4000
/* ED0DA8 80240DB8 44811000 */  mtc1      $at, $f2
/* ED0DAC 80240DBC 3C01C1A0 */  lui       $at, 0xc1a0
/* ED0DB0 80240DC0 44812000 */  mtc1      $at, $f4
/* ED0DB4 80240DC4 44834000 */  mtc1      $v1, $f8
/* ED0DB8 80240DC8 00000000 */  nop       
/* ED0DBC 80240DCC 46804220 */  cvt.s.w   $f8, $f8
/* ED0DC0 80240DD0 44074000 */  mfc1      $a3, $f8
/* ED0DC4 80240DD4 27A20038 */  addiu     $v0, $sp, 0x38
/* ED0DC8 80240DD8 AFB2001C */  sw        $s2, 0x1c($sp)
/* ED0DCC 80240DDC AFA20020 */  sw        $v0, 0x20($sp)
/* ED0DD0 80240DE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* ED0DD4 80240DE4 E7A20014 */  swc1      $f2, 0x14($sp)
/* ED0DD8 80240DE8 0C01D444 */  jal       func_80075110
/* ED0DDC 80240DEC E7A40018 */   swc1     $f4, 0x18($sp)
/* ED0DE0 80240DF0 0200202D */  daddu     $a0, $s0, $zero
/* ED0DE4 80240DF4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* ED0DE8 80240DF8 C480003C */  lwc1      $f0, 0x3c($a0)
/* ED0DEC 80240DFC 3C060020 */  lui       $a2, 0x20
/* ED0DF0 80240E00 0C013600 */  jal       func_8004D800
/* ED0DF4 80240E04 E4800064 */   swc1     $f0, 0x64($a0)
/* ED0DF8 80240E08 8E220018 */  lw        $v0, 0x18($s1)
/* ED0DFC 80240E0C 9442002A */  lhu       $v0, 0x2a($v0)
/* ED0E00 80240E10 30420001 */  andi      $v0, $v0, 1
/* ED0E04 80240E14 10400003 */  beqz      $v0, .L80240E24
/* ED0E08 80240E18 2402000A */   addiu    $v0, $zero, 0xa
/* ED0E0C 80240E1C 080903B3 */  j         .L80240ECC
/* ED0E10 80240E20 AE620070 */   sw       $v0, 0x70($s3)
.L80240E24:
/* ED0E14 80240E24 080903B3 */  j         .L80240ECC
/* ED0E18 80240E28 AE720070 */   sw       $s2, 0x70($s3)
.L80240E2C:
/* ED0E1C 80240E2C AE220090 */  sw        $v0, 0x90($s1)
.L80240E30:
/* ED0E20 80240E30 8602008C */  lh        $v0, 0x8c($s0)
/* ED0E24 80240E34 14400025 */  bnez      $v0, .L80240ECC
/* ED0E28 80240E38 00000000 */   nop      
/* ED0E2C 80240E3C 8602008E */  lh        $v0, 0x8e($s0)
/* ED0E30 80240E40 1C400022 */  bgtz      $v0, .L80240ECC
/* ED0E34 80240E44 00000000 */   nop      
/* ED0E38 80240E48 8E620074 */  lw        $v0, 0x74($s3)
/* ED0E3C 80240E4C 2442FFFF */  addiu     $v0, $v0, -1
/* ED0E40 80240E50 1840001D */  blez      $v0, .L80240EC8
/* ED0E44 80240E54 AE620074 */   sw       $v0, 0x74($s3)
/* ED0E48 80240E58 8E220018 */  lw        $v0, 0x18($s1)
/* ED0E4C 80240E5C 9442002A */  lhu       $v0, 0x2a($v0)
/* ED0E50 80240E60 30420010 */  andi      $v0, $v0, 0x10
/* ED0E54 80240E64 14400007 */  bnez      $v0, .L80240E84
/* ED0E58 80240E68 00000000 */   nop      
/* ED0E5C 80240E6C C600000C */  lwc1      $f0, 0xc($s0)
/* ED0E60 80240E70 3C014334 */  lui       $at, 0x4334
/* ED0E64 80240E74 44816000 */  mtc1      $at, $f12
/* ED0E68 80240E78 0C00AB85 */  jal       func_8002AE14
/* ED0E6C 80240E7C 460C0300 */   add.s    $f12, $f0, $f12
/* ED0E70 80240E80 E600000C */  swc1      $f0, 0xc($s0)
.L80240E84:
/* ED0E74 80240E84 0C00AB3B */  jal       func_8002ACEC
/* ED0E78 80240E88 240403E8 */   addiu    $a0, $zero, 0x3e8
/* ED0E7C 80240E8C 3C032E8B */  lui       $v1, 0x2e8b
/* ED0E80 80240E90 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* ED0E84 80240E94 00430018 */  mult      $v0, $v1
/* ED0E88 80240E98 00021FC3 */  sra       $v1, $v0, 0x1f
/* ED0E8C 80240E9C 00004010 */  mfhi      $t0
/* ED0E90 80240EA0 00082043 */  sra       $a0, $t0, 1
/* ED0E94 80240EA4 00832023 */  subu      $a0, $a0, $v1
/* ED0E98 80240EA8 00041840 */  sll       $v1, $a0, 1
/* ED0E9C 80240EAC 00641821 */  addu      $v1, $v1, $a0
/* ED0EA0 80240EB0 00031880 */  sll       $v1, $v1, 2
/* ED0EA4 80240EB4 00641823 */  subu      $v1, $v1, $a0
/* ED0EA8 80240EB8 00431023 */  subu      $v0, $v0, $v1
/* ED0EAC 80240EBC 24420005 */  addiu     $v0, $v0, 5
/* ED0EB0 80240EC0 080903B3 */  j         .L80240ECC
/* ED0EB4 80240EC4 A602008E */   sh       $v0, 0x8e($s0)
.L80240EC8:
/* ED0EB8 80240EC8 AE600070 */  sw        $zero, 0x70($s3)
.L80240ECC:
/* ED0EBC 80240ECC 8FBF0054 */  lw        $ra, 0x54($sp)
/* ED0EC0 80240ED0 8FB40050 */  lw        $s4, 0x50($sp)
/* ED0EC4 80240ED4 8FB3004C */  lw        $s3, 0x4c($sp)
/* ED0EC8 80240ED8 8FB20048 */  lw        $s2, 0x48($sp)
/* ED0ECC 80240EDC 8FB10044 */  lw        $s1, 0x44($sp)
/* ED0ED0 80240EE0 8FB00040 */  lw        $s0, 0x40($sp)
/* ED0ED4 80240EE4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* ED0ED8 80240EE8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* ED0EDC 80240EEC D7B60060 */  ldc1      $f22, 0x60($sp)
/* ED0EE0 80240EF0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* ED0EE4 80240EF4 03E00008 */  jr        $ra
/* ED0EE8 80240EF8 27BD0078 */   addiu    $sp, $sp, 0x78
