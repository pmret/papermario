.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C38_DAE038
/* DAE038 80240C38 27BDFF88 */  addiu     $sp, $sp, -0x78
/* DAE03C 80240C3C AFB3004C */  sw        $s3, 0x4c($sp)
/* DAE040 80240C40 0080982D */  daddu     $s3, $a0, $zero
/* DAE044 80240C44 AFBF0054 */  sw        $ra, 0x54($sp)
/* DAE048 80240C48 AFB40050 */  sw        $s4, 0x50($sp)
/* DAE04C 80240C4C AFB20048 */  sw        $s2, 0x48($sp)
/* DAE050 80240C50 AFB10044 */  sw        $s1, 0x44($sp)
/* DAE054 80240C54 AFB00040 */  sw        $s0, 0x40($sp)
/* DAE058 80240C58 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* DAE05C 80240C5C F7B80068 */  sdc1      $f24, 0x68($sp)
/* DAE060 80240C60 F7B60060 */  sdc1      $f22, 0x60($sp)
/* DAE064 80240C64 F7B40058 */  sdc1      $f20, 0x58($sp)
/* DAE068 80240C68 8E710148 */  lw        $s1, 0x148($s3)
/* DAE06C 80240C6C 00A0902D */  daddu     $s2, $a1, $zero
/* DAE070 80240C70 86240008 */  lh        $a0, 8($s1)
/* DAE074 80240C74 0C00EABB */  jal       get_npc_unsafe
/* DAE078 80240C78 00C0A02D */   daddu    $s4, $a2, $zero
/* DAE07C 80240C7C 0040802D */  daddu     $s0, $v0, $zero
/* DAE080 80240C80 C6200078 */  lwc1      $f0, 0x78($s1)
/* DAE084 80240C84 46800020 */  cvt.s.w   $f0, $f0
/* DAE088 80240C88 46000021 */  cvt.d.s   $f0, $f0
/* DAE08C 80240C8C 3C014059 */  lui       $at, 0x4059
/* DAE090 80240C90 44811800 */  mtc1      $at, $f3
/* DAE094 80240C94 44801000 */  mtc1      $zero, $f2
/* DAE098 80240C98 8602008E */  lh        $v0, 0x8e($s0)
/* DAE09C 80240C9C 9603008E */  lhu       $v1, 0x8e($s0)
/* DAE0A0 80240CA0 46220003 */  div.d     $f0, $f0, $f2
/* DAE0A4 80240CA4 46200620 */  cvt.s.d   $f24, $f0
/* DAE0A8 80240CA8 C6200088 */  lwc1      $f0, 0x88($s1)
/* DAE0AC 80240CAC 46800020 */  cvt.s.w   $f0, $f0
/* DAE0B0 80240CB0 46000021 */  cvt.d.s   $f0, $f0
/* DAE0B4 80240CB4 46220003 */  div.d     $f0, $f0, $f2
/* DAE0B8 80240CB8 46200020 */  cvt.s.d   $f0, $f0
/* DAE0BC 80240CBC 18400003 */  blez      $v0, .L80240CCC
/* DAE0C0 80240CC0 4600C680 */   add.s    $f26, $f24, $f0
/* DAE0C4 80240CC4 2462FFFF */  addiu     $v0, $v1, -1
/* DAE0C8 80240CC8 A602008E */  sh        $v0, 0x8e($s0)
.L80240CCC:
/* DAE0CC 80240CCC 8E220070 */  lw        $v0, 0x70($s1)
/* DAE0D0 80240CD0 18400034 */  blez      $v0, .L80240DA4
/* DAE0D4 80240CD4 00000000 */   nop
/* DAE0D8 80240CD8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* DAE0DC 80240CDC 46806320 */  cvt.s.w   $f12, $f12
/* DAE0E0 80240CE0 44820000 */  mtc1      $v0, $f0
/* DAE0E4 80240CE4 00000000 */  nop
/* DAE0E8 80240CE8 46800020 */  cvt.s.w   $f0, $f0
/* DAE0EC 80240CEC 46000021 */  cvt.d.s   $f0, $f0
/* DAE0F0 80240CF0 46220003 */  div.d     $f0, $f0, $f2
/* DAE0F4 80240CF4 0C00A8BB */  jal       sin_deg
/* DAE0F8 80240CF8 462005A0 */   cvt.s.d  $f22, $f0
/* DAE0FC 80240CFC 8E020000 */  lw        $v0, ($s0)
/* DAE100 80240D00 30420008 */  andi      $v0, $v0, 8
/* DAE104 80240D04 10400003 */  beqz      $v0, .L80240D14
/* DAE108 80240D08 46000506 */   mov.s    $f20, $f0
/* DAE10C 80240D0C 08090355 */  j         .L80240D54
/* DAE110 80240D10 0000102D */   daddu    $v0, $zero, $zero
.L80240D14:
/* DAE114 80240D14 27A50028 */  addiu     $a1, $sp, 0x28
/* DAE118 80240D18 27A6002C */  addiu     $a2, $sp, 0x2c
/* DAE11C 80240D1C C6000038 */  lwc1      $f0, 0x38($s0)
/* DAE120 80240D20 C602003C */  lwc1      $f2, 0x3c($s0)
/* DAE124 80240D24 C6040040 */  lwc1      $f4, 0x40($s0)
/* DAE128 80240D28 3C01447A */  lui       $at, 0x447a
/* DAE12C 80240D2C 44813000 */  mtc1      $at, $f6
/* DAE130 80240D30 27A20034 */  addiu     $v0, $sp, 0x34
/* DAE134 80240D34 E7A00028 */  swc1      $f0, 0x28($sp)
/* DAE138 80240D38 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DAE13C 80240D3C E7A40030 */  swc1      $f4, 0x30($sp)
/* DAE140 80240D40 E7A60034 */  swc1      $f6, 0x34($sp)
/* DAE144 80240D44 AFA20010 */  sw        $v0, 0x10($sp)
/* DAE148 80240D48 8E040080 */  lw        $a0, 0x80($s0)
/* DAE14C 80240D4C 0C0372DF */  jal       func_800DCB7C
/* DAE150 80240D50 27A70030 */   addiu    $a3, $sp, 0x30
.L80240D54:
/* DAE154 80240D54 10400007 */  beqz      $v0, .L80240D74
/* DAE158 80240D58 00000000 */   nop
/* DAE15C 80240D5C 4616A082 */  mul.s     $f2, $f20, $f22
/* DAE160 80240D60 00000000 */  nop
/* DAE164 80240D64 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DAE168 80240D68 46180000 */  add.s     $f0, $f0, $f24
/* DAE16C 80240D6C 08090360 */  j         .L80240D80
/* DAE170 80240D70 46020000 */   add.s    $f0, $f0, $f2
.L80240D74:
/* DAE174 80240D74 4616A002 */  mul.s     $f0, $f20, $f22
/* DAE178 80240D78 00000000 */  nop
/* DAE17C 80240D7C 4600D000 */  add.s     $f0, $f26, $f0
.L80240D80:
/* DAE180 80240D80 E600003C */  swc1      $f0, 0x3c($s0)
/* DAE184 80240D84 8E220074 */  lw        $v0, 0x74($s1)
/* DAE188 80240D88 2442000A */  addiu     $v0, $v0, 0xa
/* DAE18C 80240D8C 44826000 */  mtc1      $v0, $f12
/* DAE190 80240D90 00000000 */  nop
/* DAE194 80240D94 0C00A6C9 */  jal       clamp_angle
/* DAE198 80240D98 46806320 */   cvt.s.w  $f12, $f12
/* DAE19C 80240D9C 4600020D */  trunc.w.s $f8, $f0
/* DAE1A0 80240DA0 E6280074 */  swc1      $f8, 0x74($s1)
.L80240DA4:
/* DAE1A4 80240DA4 8E220090 */  lw        $v0, 0x90($s1)
/* DAE1A8 80240DA8 1C400040 */  bgtz      $v0, .L80240EAC
/* DAE1AC 80240DAC 2442FFFF */   addiu    $v0, $v0, -1
/* DAE1B0 80240DB0 860200A8 */  lh        $v0, 0xa8($s0)
/* DAE1B4 80240DB4 C600003C */  lwc1      $f0, 0x3c($s0)
/* DAE1B8 80240DB8 44821000 */  mtc1      $v0, $f2
/* DAE1BC 80240DBC 00000000 */  nop
/* DAE1C0 80240DC0 468010A0 */  cvt.s.w   $f2, $f2
/* DAE1C4 80240DC4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DAE1C8 80240DC8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DAE1CC 80240DCC 46020000 */  add.s     $f0, $f0, $f2
/* DAE1D0 80240DD0 3C014024 */  lui       $at, 0x4024
/* DAE1D4 80240DD4 44812800 */  mtc1      $at, $f5
/* DAE1D8 80240DD8 44802000 */  mtc1      $zero, $f4
/* DAE1DC 80240DDC C442002C */  lwc1      $f2, 0x2c($v0)
/* DAE1E0 80240DE0 46000021 */  cvt.d.s   $f0, $f0
/* DAE1E4 80240DE4 46240000 */  add.d     $f0, $f0, $f4
/* DAE1E8 80240DE8 460010A1 */  cvt.d.s   $f2, $f2
/* DAE1EC 80240DEC 4620103C */  c.lt.d    $f2, $f0
/* DAE1F0 80240DF0 00000000 */  nop
/* DAE1F4 80240DF4 4500002E */  bc1f      .L80240EB0
/* DAE1F8 80240DF8 0280202D */   daddu    $a0, $s4, $zero
/* DAE1FC 80240DFC 24020001 */  addiu     $v0, $zero, 1
/* DAE200 80240E00 AFA20010 */  sw        $v0, 0x10($sp)
/* DAE204 80240E04 8E460024 */  lw        $a2, 0x24($s2)
/* DAE208 80240E08 8E470028 */  lw        $a3, 0x28($s2)
/* DAE20C 80240E0C 0C01242D */  jal       func_800490B4
/* DAE210 80240E10 0220282D */   daddu    $a1, $s1, $zero
/* DAE214 80240E14 10400026 */  beqz      $v0, .L80240EB0
/* DAE218 80240E18 0000202D */   daddu    $a0, $zero, $zero
/* DAE21C 80240E1C 0200282D */  daddu     $a1, $s0, $zero
/* DAE220 80240E20 0000302D */  daddu     $a2, $zero, $zero
/* DAE224 80240E24 2412000C */  addiu     $s2, $zero, 0xc
/* DAE228 80240E28 860300A8 */  lh        $v1, 0xa8($s0)
/* DAE22C 80240E2C 3C013F80 */  lui       $at, 0x3f80
/* DAE230 80240E30 44810000 */  mtc1      $at, $f0
/* DAE234 80240E34 3C014000 */  lui       $at, 0x4000
/* DAE238 80240E38 44811000 */  mtc1      $at, $f2
/* DAE23C 80240E3C 3C01C1A0 */  lui       $at, 0xc1a0
/* DAE240 80240E40 44812000 */  mtc1      $at, $f4
/* DAE244 80240E44 44834000 */  mtc1      $v1, $f8
/* DAE248 80240E48 00000000 */  nop
/* DAE24C 80240E4C 46804220 */  cvt.s.w   $f8, $f8
/* DAE250 80240E50 44074000 */  mfc1      $a3, $f8
/* DAE254 80240E54 27A20038 */  addiu     $v0, $sp, 0x38
/* DAE258 80240E58 AFB2001C */  sw        $s2, 0x1c($sp)
/* DAE25C 80240E5C AFA20020 */  sw        $v0, 0x20($sp)
/* DAE260 80240E60 E7A00010 */  swc1      $f0, 0x10($sp)
/* DAE264 80240E64 E7A20014 */  swc1      $f2, 0x14($sp)
/* DAE268 80240E68 0C01BFA4 */  jal       fx_emote
/* DAE26C 80240E6C E7A40018 */   swc1     $f4, 0x18($sp)
/* DAE270 80240E70 0200202D */  daddu     $a0, $s0, $zero
/* DAE274 80240E74 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DAE278 80240E78 C480003C */  lwc1      $f0, 0x3c($a0)
/* DAE27C 80240E7C 3C060020 */  lui       $a2, 0x20
/* DAE280 80240E80 0C012530 */  jal       func_800494C0
/* DAE284 80240E84 E4800064 */   swc1     $f0, 0x64($a0)
/* DAE288 80240E88 8E220018 */  lw        $v0, 0x18($s1)
/* DAE28C 80240E8C 9442002A */  lhu       $v0, 0x2a($v0)
/* DAE290 80240E90 30420001 */  andi      $v0, $v0, 1
/* DAE294 80240E94 10400003 */  beqz      $v0, .L80240EA4
/* DAE298 80240E98 2402000A */   addiu    $v0, $zero, 0xa
/* DAE29C 80240E9C 080903D3 */  j         .L80240F4C
/* DAE2A0 80240EA0 AE620070 */   sw       $v0, 0x70($s3)
.L80240EA4:
/* DAE2A4 80240EA4 080903D3 */  j         .L80240F4C
/* DAE2A8 80240EA8 AE720070 */   sw       $s2, 0x70($s3)
.L80240EAC:
/* DAE2AC 80240EAC AE220090 */  sw        $v0, 0x90($s1)
.L80240EB0:
/* DAE2B0 80240EB0 8602008C */  lh        $v0, 0x8c($s0)
/* DAE2B4 80240EB4 14400025 */  bnez      $v0, .L80240F4C
/* DAE2B8 80240EB8 00000000 */   nop
/* DAE2BC 80240EBC 8602008E */  lh        $v0, 0x8e($s0)
/* DAE2C0 80240EC0 1C400022 */  bgtz      $v0, .L80240F4C
/* DAE2C4 80240EC4 00000000 */   nop
/* DAE2C8 80240EC8 8E620074 */  lw        $v0, 0x74($s3)
/* DAE2CC 80240ECC 2442FFFF */  addiu     $v0, $v0, -1
/* DAE2D0 80240ED0 1840001D */  blez      $v0, .L80240F48
/* DAE2D4 80240ED4 AE620074 */   sw       $v0, 0x74($s3)
/* DAE2D8 80240ED8 8E220018 */  lw        $v0, 0x18($s1)
/* DAE2DC 80240EDC 9442002A */  lhu       $v0, 0x2a($v0)
/* DAE2E0 80240EE0 30420010 */  andi      $v0, $v0, 0x10
/* DAE2E4 80240EE4 14400007 */  bnez      $v0, .L80240F04
/* DAE2E8 80240EE8 00000000 */   nop
/* DAE2EC 80240EEC C600000C */  lwc1      $f0, 0xc($s0)
/* DAE2F0 80240EF0 3C014334 */  lui       $at, 0x4334
/* DAE2F4 80240EF4 44816000 */  mtc1      $at, $f12
/* DAE2F8 80240EF8 0C00A6C9 */  jal       clamp_angle
/* DAE2FC 80240EFC 460C0300 */   add.s    $f12, $f0, $f12
/* DAE300 80240F00 E600000C */  swc1      $f0, 0xc($s0)
.L80240F04:
/* DAE304 80240F04 0C00A67F */  jal       rand_int
/* DAE308 80240F08 240403E8 */   addiu    $a0, $zero, 0x3e8
/* DAE30C 80240F0C 3C032E8B */  lui       $v1, 0x2e8b
/* DAE310 80240F10 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* DAE314 80240F14 00430018 */  mult      $v0, $v1
/* DAE318 80240F18 00021FC3 */  sra       $v1, $v0, 0x1f
/* DAE31C 80240F1C 00004010 */  mfhi      $t0
/* DAE320 80240F20 00082043 */  sra       $a0, $t0, 1
/* DAE324 80240F24 00832023 */  subu      $a0, $a0, $v1
/* DAE328 80240F28 00041840 */  sll       $v1, $a0, 1
/* DAE32C 80240F2C 00641821 */  addu      $v1, $v1, $a0
/* DAE330 80240F30 00031880 */  sll       $v1, $v1, 2
/* DAE334 80240F34 00641823 */  subu      $v1, $v1, $a0
/* DAE338 80240F38 00431023 */  subu      $v0, $v0, $v1
/* DAE33C 80240F3C 24420005 */  addiu     $v0, $v0, 5
/* DAE340 80240F40 080903D3 */  j         .L80240F4C
/* DAE344 80240F44 A602008E */   sh       $v0, 0x8e($s0)
.L80240F48:
/* DAE348 80240F48 AE600070 */  sw        $zero, 0x70($s3)
.L80240F4C:
/* DAE34C 80240F4C 8FBF0054 */  lw        $ra, 0x54($sp)
/* DAE350 80240F50 8FB40050 */  lw        $s4, 0x50($sp)
/* DAE354 80240F54 8FB3004C */  lw        $s3, 0x4c($sp)
/* DAE358 80240F58 8FB20048 */  lw        $s2, 0x48($sp)
/* DAE35C 80240F5C 8FB10044 */  lw        $s1, 0x44($sp)
/* DAE360 80240F60 8FB00040 */  lw        $s0, 0x40($sp)
/* DAE364 80240F64 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* DAE368 80240F68 D7B80068 */  ldc1      $f24, 0x68($sp)
/* DAE36C 80240F6C D7B60060 */  ldc1      $f22, 0x60($sp)
/* DAE370 80240F70 D7B40058 */  ldc1      $f20, 0x58($sp)
/* DAE374 80240F74 03E00008 */  jr        $ra
/* DAE378 80240F78 27BD0078 */   addiu    $sp, $sp, 0x78
