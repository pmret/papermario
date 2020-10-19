.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB8_CB5BB8
/* CB5BB8 80240BB8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CB5BBC 80240BBC AFB3004C */  sw        $s3, 0x4c($sp)
/* CB5BC0 80240BC0 0080982D */  daddu     $s3, $a0, $zero
/* CB5BC4 80240BC4 AFBF0054 */  sw        $ra, 0x54($sp)
/* CB5BC8 80240BC8 AFB40050 */  sw        $s4, 0x50($sp)
/* CB5BCC 80240BCC AFB20048 */  sw        $s2, 0x48($sp)
/* CB5BD0 80240BD0 AFB10044 */  sw        $s1, 0x44($sp)
/* CB5BD4 80240BD4 AFB00040 */  sw        $s0, 0x40($sp)
/* CB5BD8 80240BD8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* CB5BDC 80240BDC F7B80068 */  sdc1      $f24, 0x68($sp)
/* CB5BE0 80240BE0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CB5BE4 80240BE4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CB5BE8 80240BE8 8E710148 */  lw        $s1, 0x148($s3)
/* CB5BEC 80240BEC 00A0902D */  daddu     $s2, $a1, $zero
/* CB5BF0 80240BF0 86240008 */  lh        $a0, 8($s1)
/* CB5BF4 80240BF4 0C00EABB */  jal       get_npc_unsafe
/* CB5BF8 80240BF8 00C0A02D */   daddu    $s4, $a2, $zero
/* CB5BFC 80240BFC 0040802D */  daddu     $s0, $v0, $zero
/* CB5C00 80240C00 C6200078 */  lwc1      $f0, 0x78($s1)
/* CB5C04 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* CB5C08 80240C08 46000021 */  cvt.d.s   $f0, $f0
/* CB5C0C 80240C0C 3C014059 */  lui       $at, 0x4059
/* CB5C10 80240C10 44811800 */  mtc1      $at, $f3
/* CB5C14 80240C14 44801000 */  mtc1      $zero, $f2
/* CB5C18 80240C18 8602008E */  lh        $v0, 0x8e($s0)
/* CB5C1C 80240C1C 9603008E */  lhu       $v1, 0x8e($s0)
/* CB5C20 80240C20 46220003 */  div.d     $f0, $f0, $f2
/* CB5C24 80240C24 46200620 */  cvt.s.d   $f24, $f0
/* CB5C28 80240C28 C6200088 */  lwc1      $f0, 0x88($s1)
/* CB5C2C 80240C2C 46800020 */  cvt.s.w   $f0, $f0
/* CB5C30 80240C30 46000021 */  cvt.d.s   $f0, $f0
/* CB5C34 80240C34 46220003 */  div.d     $f0, $f0, $f2
/* CB5C38 80240C38 46200020 */  cvt.s.d   $f0, $f0
/* CB5C3C 80240C3C 18400003 */  blez      $v0, .L80240C4C
/* CB5C40 80240C40 4600C680 */   add.s    $f26, $f24, $f0
/* CB5C44 80240C44 2462FFFF */  addiu     $v0, $v1, -1
/* CB5C48 80240C48 A602008E */  sh        $v0, 0x8e($s0)
.L80240C4C:
/* CB5C4C 80240C4C 8E220070 */  lw        $v0, 0x70($s1)
/* CB5C50 80240C50 18400034 */  blez      $v0, .L80240D24
/* CB5C54 80240C54 00000000 */   nop      
/* CB5C58 80240C58 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CB5C5C 80240C5C 46806320 */  cvt.s.w   $f12, $f12
/* CB5C60 80240C60 44820000 */  mtc1      $v0, $f0
/* CB5C64 80240C64 00000000 */  nop       
/* CB5C68 80240C68 46800020 */  cvt.s.w   $f0, $f0
/* CB5C6C 80240C6C 46000021 */  cvt.d.s   $f0, $f0
/* CB5C70 80240C70 46220003 */  div.d     $f0, $f0, $f2
/* CB5C74 80240C74 0C00A8BB */  jal       sin_deg
/* CB5C78 80240C78 462005A0 */   cvt.s.d  $f22, $f0
/* CB5C7C 80240C7C 8E020000 */  lw        $v0, ($s0)
/* CB5C80 80240C80 30420008 */  andi      $v0, $v0, 8
/* CB5C84 80240C84 10400003 */  beqz      $v0, .L80240C94
/* CB5C88 80240C88 46000506 */   mov.s    $f20, $f0
/* CB5C8C 80240C8C 08090335 */  j         .L80240CD4
/* CB5C90 80240C90 0000102D */   daddu    $v0, $zero, $zero
.L80240C94:
/* CB5C94 80240C94 27A50028 */  addiu     $a1, $sp, 0x28
/* CB5C98 80240C98 27A6002C */  addiu     $a2, $sp, 0x2c
/* CB5C9C 80240C9C C6000038 */  lwc1      $f0, 0x38($s0)
/* CB5CA0 80240CA0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CB5CA4 80240CA4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CB5CA8 80240CA8 3C01447A */  lui       $at, 0x447a
/* CB5CAC 80240CAC 44813000 */  mtc1      $at, $f6
/* CB5CB0 80240CB0 27A20034 */  addiu     $v0, $sp, 0x34
/* CB5CB4 80240CB4 E7A00028 */  swc1      $f0, 0x28($sp)
/* CB5CB8 80240CB8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CB5CBC 80240CBC E7A40030 */  swc1      $f4, 0x30($sp)
/* CB5CC0 80240CC0 E7A60034 */  swc1      $f6, 0x34($sp)
/* CB5CC4 80240CC4 AFA20010 */  sw        $v0, 0x10($sp)
/* CB5CC8 80240CC8 8E040080 */  lw        $a0, 0x80($s0)
/* CB5CCC 80240CCC 0C0372DF */  jal       func_800DCB7C
/* CB5CD0 80240CD0 27A70030 */   addiu    $a3, $sp, 0x30
.L80240CD4:
/* CB5CD4 80240CD4 10400007 */  beqz      $v0, .L80240CF4
/* CB5CD8 80240CD8 00000000 */   nop      
/* CB5CDC 80240CDC 4616A082 */  mul.s     $f2, $f20, $f22
/* CB5CE0 80240CE0 00000000 */  nop       
/* CB5CE4 80240CE4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CB5CE8 80240CE8 46180000 */  add.s     $f0, $f0, $f24
/* CB5CEC 80240CEC 08090340 */  j         .L80240D00
/* CB5CF0 80240CF0 46020000 */   add.s    $f0, $f0, $f2
.L80240CF4:
/* CB5CF4 80240CF4 4616A002 */  mul.s     $f0, $f20, $f22
/* CB5CF8 80240CF8 00000000 */  nop       
/* CB5CFC 80240CFC 4600D000 */  add.s     $f0, $f26, $f0
.L80240D00:
/* CB5D00 80240D00 E600003C */  swc1      $f0, 0x3c($s0)
/* CB5D04 80240D04 8E220074 */  lw        $v0, 0x74($s1)
/* CB5D08 80240D08 2442000A */  addiu     $v0, $v0, 0xa
/* CB5D0C 80240D0C 44826000 */  mtc1      $v0, $f12
/* CB5D10 80240D10 00000000 */  nop       
/* CB5D14 80240D14 0C00A6C9 */  jal       clamp_angle
/* CB5D18 80240D18 46806320 */   cvt.s.w  $f12, $f12
/* CB5D1C 80240D1C 4600020D */  trunc.w.s $f8, $f0
/* CB5D20 80240D20 E6280074 */  swc1      $f8, 0x74($s1)
.L80240D24:
/* CB5D24 80240D24 8E220090 */  lw        $v0, 0x90($s1)
/* CB5D28 80240D28 1C400040 */  bgtz      $v0, .L80240E2C
/* CB5D2C 80240D2C 2442FFFF */   addiu    $v0, $v0, -1
/* CB5D30 80240D30 860200A8 */  lh        $v0, 0xa8($s0)
/* CB5D34 80240D34 C600003C */  lwc1      $f0, 0x3c($s0)
/* CB5D38 80240D38 44821000 */  mtc1      $v0, $f2
/* CB5D3C 80240D3C 00000000 */  nop       
/* CB5D40 80240D40 468010A0 */  cvt.s.w   $f2, $f2
/* CB5D44 80240D44 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CB5D48 80240D48 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CB5D4C 80240D4C 46020000 */  add.s     $f0, $f0, $f2
/* CB5D50 80240D50 3C014024 */  lui       $at, 0x4024
/* CB5D54 80240D54 44812800 */  mtc1      $at, $f5
/* CB5D58 80240D58 44802000 */  mtc1      $zero, $f4
/* CB5D5C 80240D5C C442002C */  lwc1      $f2, 0x2c($v0)
/* CB5D60 80240D60 46000021 */  cvt.d.s   $f0, $f0
/* CB5D64 80240D64 46240000 */  add.d     $f0, $f0, $f4
/* CB5D68 80240D68 460010A1 */  cvt.d.s   $f2, $f2
/* CB5D6C 80240D6C 4620103C */  c.lt.d    $f2, $f0
/* CB5D70 80240D70 00000000 */  nop       
/* CB5D74 80240D74 4500002E */  bc1f      .L80240E30
/* CB5D78 80240D78 0280202D */   daddu    $a0, $s4, $zero
/* CB5D7C 80240D7C 24020001 */  addiu     $v0, $zero, 1
/* CB5D80 80240D80 AFA20010 */  sw        $v0, 0x10($sp)
/* CB5D84 80240D84 8E460024 */  lw        $a2, 0x24($s2)
/* CB5D88 80240D88 8E470028 */  lw        $a3, 0x28($s2)
/* CB5D8C 80240D8C 0C01242D */  jal       func_800490B4
/* CB5D90 80240D90 0220282D */   daddu    $a1, $s1, $zero
/* CB5D94 80240D94 10400026 */  beqz      $v0, .L80240E30
/* CB5D98 80240D98 0000202D */   daddu    $a0, $zero, $zero
/* CB5D9C 80240D9C 0200282D */  daddu     $a1, $s0, $zero
/* CB5DA0 80240DA0 0000302D */  daddu     $a2, $zero, $zero
/* CB5DA4 80240DA4 2412000C */  addiu     $s2, $zero, 0xc
/* CB5DA8 80240DA8 860300A8 */  lh        $v1, 0xa8($s0)
/* CB5DAC 80240DAC 3C013F80 */  lui       $at, 0x3f80
/* CB5DB0 80240DB0 44810000 */  mtc1      $at, $f0
/* CB5DB4 80240DB4 3C014000 */  lui       $at, 0x4000
/* CB5DB8 80240DB8 44811000 */  mtc1      $at, $f2
/* CB5DBC 80240DBC 3C01C1A0 */  lui       $at, 0xc1a0
/* CB5DC0 80240DC0 44812000 */  mtc1      $at, $f4
/* CB5DC4 80240DC4 44834000 */  mtc1      $v1, $f8
/* CB5DC8 80240DC8 00000000 */  nop       
/* CB5DCC 80240DCC 46804220 */  cvt.s.w   $f8, $f8
/* CB5DD0 80240DD0 44074000 */  mfc1      $a3, $f8
/* CB5DD4 80240DD4 27A20038 */  addiu     $v0, $sp, 0x38
/* CB5DD8 80240DD8 AFB2001C */  sw        $s2, 0x1c($sp)
/* CB5DDC 80240DDC AFA20020 */  sw        $v0, 0x20($sp)
/* CB5DE0 80240DE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CB5DE4 80240DE4 E7A20014 */  swc1      $f2, 0x14($sp)
/* CB5DE8 80240DE8 0C01BFA4 */  jal       fx_emote
/* CB5DEC 80240DEC E7A40018 */   swc1     $f4, 0x18($sp)
/* CB5DF0 80240DF0 0200202D */  daddu     $a0, $s0, $zero
/* CB5DF4 80240DF4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CB5DF8 80240DF8 C480003C */  lwc1      $f0, 0x3c($a0)
/* CB5DFC 80240DFC 3C060020 */  lui       $a2, 0x20
/* CB5E00 80240E00 0C012530 */  jal       func_800494C0
/* CB5E04 80240E04 E4800064 */   swc1     $f0, 0x64($a0)
/* CB5E08 80240E08 8E220018 */  lw        $v0, 0x18($s1)
/* CB5E0C 80240E0C 9442002A */  lhu       $v0, 0x2a($v0)
/* CB5E10 80240E10 30420001 */  andi      $v0, $v0, 1
/* CB5E14 80240E14 10400003 */  beqz      $v0, .L80240E24
/* CB5E18 80240E18 2402000A */   addiu    $v0, $zero, 0xa
/* CB5E1C 80240E1C 080903B3 */  j         .L80240ECC
/* CB5E20 80240E20 AE620070 */   sw       $v0, 0x70($s3)
.L80240E24:
/* CB5E24 80240E24 080903B3 */  j         .L80240ECC
/* CB5E28 80240E28 AE720070 */   sw       $s2, 0x70($s3)
.L80240E2C:
/* CB5E2C 80240E2C AE220090 */  sw        $v0, 0x90($s1)
.L80240E30:
/* CB5E30 80240E30 8602008C */  lh        $v0, 0x8c($s0)
/* CB5E34 80240E34 14400025 */  bnez      $v0, .L80240ECC
/* CB5E38 80240E38 00000000 */   nop      
/* CB5E3C 80240E3C 8602008E */  lh        $v0, 0x8e($s0)
/* CB5E40 80240E40 1C400022 */  bgtz      $v0, .L80240ECC
/* CB5E44 80240E44 00000000 */   nop      
/* CB5E48 80240E48 8E620074 */  lw        $v0, 0x74($s3)
/* CB5E4C 80240E4C 2442FFFF */  addiu     $v0, $v0, -1
/* CB5E50 80240E50 1840001D */  blez      $v0, .L80240EC8
/* CB5E54 80240E54 AE620074 */   sw       $v0, 0x74($s3)
/* CB5E58 80240E58 8E220018 */  lw        $v0, 0x18($s1)
/* CB5E5C 80240E5C 9442002A */  lhu       $v0, 0x2a($v0)
/* CB5E60 80240E60 30420010 */  andi      $v0, $v0, 0x10
/* CB5E64 80240E64 14400007 */  bnez      $v0, .L80240E84
/* CB5E68 80240E68 00000000 */   nop      
/* CB5E6C 80240E6C C600000C */  lwc1      $f0, 0xc($s0)
/* CB5E70 80240E70 3C014334 */  lui       $at, 0x4334
/* CB5E74 80240E74 44816000 */  mtc1      $at, $f12
/* CB5E78 80240E78 0C00A6C9 */  jal       clamp_angle
/* CB5E7C 80240E7C 460C0300 */   add.s    $f12, $f0, $f12
/* CB5E80 80240E80 E600000C */  swc1      $f0, 0xc($s0)
.L80240E84:
/* CB5E84 80240E84 0C00A67F */  jal       rand_int
/* CB5E88 80240E88 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CB5E8C 80240E8C 3C032E8B */  lui       $v1, 0x2e8b
/* CB5E90 80240E90 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CB5E94 80240E94 00430018 */  mult      $v0, $v1
/* CB5E98 80240E98 00021FC3 */  sra       $v1, $v0, 0x1f
/* CB5E9C 80240E9C 00004010 */  mfhi      $t0
/* CB5EA0 80240EA0 00082043 */  sra       $a0, $t0, 1
/* CB5EA4 80240EA4 00832023 */  subu      $a0, $a0, $v1
/* CB5EA8 80240EA8 00041840 */  sll       $v1, $a0, 1
/* CB5EAC 80240EAC 00641821 */  addu      $v1, $v1, $a0
/* CB5EB0 80240EB0 00031880 */  sll       $v1, $v1, 2
/* CB5EB4 80240EB4 00641823 */  subu      $v1, $v1, $a0
/* CB5EB8 80240EB8 00431023 */  subu      $v0, $v0, $v1
/* CB5EBC 80240EBC 24420005 */  addiu     $v0, $v0, 5
/* CB5EC0 80240EC0 080903B3 */  j         .L80240ECC
/* CB5EC4 80240EC4 A602008E */   sh       $v0, 0x8e($s0)
.L80240EC8:
/* CB5EC8 80240EC8 AE600070 */  sw        $zero, 0x70($s3)
.L80240ECC:
/* CB5ECC 80240ECC 8FBF0054 */  lw        $ra, 0x54($sp)
/* CB5ED0 80240ED0 8FB40050 */  lw        $s4, 0x50($sp)
/* CB5ED4 80240ED4 8FB3004C */  lw        $s3, 0x4c($sp)
/* CB5ED8 80240ED8 8FB20048 */  lw        $s2, 0x48($sp)
/* CB5EDC 80240EDC 8FB10044 */  lw        $s1, 0x44($sp)
/* CB5EE0 80240EE0 8FB00040 */  lw        $s0, 0x40($sp)
/* CB5EE4 80240EE4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* CB5EE8 80240EE8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* CB5EEC 80240EEC D7B60060 */  ldc1      $f22, 0x60($sp)
/* CB5EF0 80240EF0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* CB5EF4 80240EF4 03E00008 */  jr        $ra
/* CB5EF8 80240EF8 27BD0078 */   addiu    $sp, $sp, 0x78
