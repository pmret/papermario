.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_BE7D38
/* BE7D38 80240158 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BE7D3C 8024015C AFB20038 */  sw        $s2, 0x38($sp)
/* BE7D40 80240160 0080902D */  daddu     $s2, $a0, $zero
/* BE7D44 80240164 AFBF0044 */  sw        $ra, 0x44($sp)
/* BE7D48 80240168 AFB40040 */  sw        $s4, 0x40($sp)
/* BE7D4C 8024016C AFB3003C */  sw        $s3, 0x3c($sp)
/* BE7D50 80240170 AFB10034 */  sw        $s1, 0x34($sp)
/* BE7D54 80240174 AFB00030 */  sw        $s0, 0x30($sp)
/* BE7D58 80240178 F7B60050 */  sdc1      $f22, 0x50($sp)
/* BE7D5C 8024017C F7B40048 */  sdc1      $f20, 0x48($sp)
/* BE7D60 80240180 8E510148 */  lw        $s1, 0x148($s2)
/* BE7D64 80240184 00A0982D */  daddu     $s3, $a1, $zero
/* BE7D68 80240188 86240008 */  lh        $a0, 8($s1)
/* BE7D6C 8024018C 0C00EABB */  jal       get_npc_unsafe
/* BE7D70 80240190 00C0A02D */   daddu    $s4, $a2, $zero
/* BE7D74 80240194 8E630014 */  lw        $v1, 0x14($s3)
/* BE7D78 80240198 04600030 */  bltz      $v1, .L8024025C
/* BE7D7C 8024019C 0040802D */   daddu    $s0, $v0, $zero
/* BE7D80 802401A0 8E420074 */  lw        $v0, 0x74($s2)
/* BE7D84 802401A4 1C40002C */  bgtz      $v0, .L80240258
/* BE7D88 802401A8 2442FFFF */   addiu    $v0, $v0, -1
/* BE7D8C 802401AC 0280202D */  daddu     $a0, $s4, $zero
/* BE7D90 802401B0 AE430074 */  sw        $v1, 0x74($s2)
/* BE7D94 802401B4 AFA00010 */  sw        $zero, 0x10($sp)
/* BE7D98 802401B8 8E66000C */  lw        $a2, 0xc($s3)
/* BE7D9C 802401BC 8E670010 */  lw        $a3, 0x10($s3)
/* BE7DA0 802401C0 0C01242D */  jal       func_800490B4
/* BE7DA4 802401C4 0220282D */   daddu    $a1, $s1, $zero
/* BE7DA8 802401C8 10400021 */  beqz      $v0, .L80240250
/* BE7DAC 802401CC 0000202D */   daddu    $a0, $zero, $zero
/* BE7DB0 802401D0 0200282D */  daddu     $a1, $s0, $zero
/* BE7DB4 802401D4 0000302D */  daddu     $a2, $zero, $zero
/* BE7DB8 802401D8 860300A8 */  lh        $v1, 0xa8($s0)
/* BE7DBC 802401DC 3C013F80 */  lui       $at, 0x3f80
/* BE7DC0 802401E0 44810000 */  mtc1      $at, $f0
/* BE7DC4 802401E4 3C014000 */  lui       $at, 0x4000
/* BE7DC8 802401E8 44811000 */  mtc1      $at, $f2
/* BE7DCC 802401EC 3C01C1A0 */  lui       $at, 0xc1a0
/* BE7DD0 802401F0 44812000 */  mtc1      $at, $f4
/* BE7DD4 802401F4 2402000F */  addiu     $v0, $zero, 0xf
/* BE7DD8 802401F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE7DDC 802401FC 44833000 */  mtc1      $v1, $f6
/* BE7DE0 80240200 00000000 */  nop
/* BE7DE4 80240204 468031A0 */  cvt.s.w   $f6, $f6
/* BE7DE8 80240208 44073000 */  mfc1      $a3, $f6
/* BE7DEC 8024020C 27A20028 */  addiu     $v0, $sp, 0x28
/* BE7DF0 80240210 AFA20020 */  sw        $v0, 0x20($sp)
/* BE7DF4 80240214 E7A00010 */  swc1      $f0, 0x10($sp)
/* BE7DF8 80240218 E7A20014 */  swc1      $f2, 0x14($sp)
/* BE7DFC 8024021C 0C01BFA4 */  jal       fx_emote
/* BE7E00 80240220 E7A40018 */   swc1     $f4, 0x18($sp)
/* BE7E04 80240224 0200202D */  daddu     $a0, $s0, $zero
/* BE7E08 80240228 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BE7E0C 8024022C 0C012530 */  jal       func_800494C0
/* BE7E10 80240230 3C060020 */   lui      $a2, 0x20
/* BE7E14 80240234 8E220018 */  lw        $v0, 0x18($s1)
/* BE7E18 80240238 9442002A */  lhu       $v0, 0x2a($v0)
/* BE7E1C 8024023C 30420001 */  andi      $v0, $v0, 1
/* BE7E20 80240240 14400064 */  bnez      $v0, .L802403D4
/* BE7E24 80240244 2402000A */   addiu    $v0, $zero, 0xa
/* BE7E28 80240248 080900F5 */  j         .L802403D4
/* BE7E2C 8024024C 2402000C */   addiu    $v0, $zero, 0xc
.L80240250:
/* BE7E30 80240250 8E420074 */  lw        $v0, 0x74($s2)
/* BE7E34 80240254 2442FFFF */  addiu     $v0, $v0, -1
.L80240258:
/* BE7E38 80240258 AE420074 */  sw        $v0, 0x74($s2)
.L8024025C:
/* BE7E3C 8024025C 8602008C */  lh        $v0, 0x8c($s0)
/* BE7E40 80240260 1440005D */  bnez      $v0, .L802403D8
/* BE7E44 80240264 00000000 */   nop
/* BE7E48 80240268 C6000018 */  lwc1      $f0, 0x18($s0)
/* BE7E4C 8024026C 3C014010 */  lui       $at, 0x4010
/* BE7E50 80240270 44811800 */  mtc1      $at, $f3
/* BE7E54 80240274 44801000 */  mtc1      $zero, $f2
/* BE7E58 80240278 46000021 */  cvt.d.s   $f0, $f0
/* BE7E5C 8024027C 4622003C */  c.lt.d    $f0, $f2
/* BE7E60 80240280 00000000 */  nop
/* BE7E64 80240284 45000003 */  bc1f      .L80240294
/* BE7E68 80240288 0200202D */   daddu    $a0, $s0, $zero
/* BE7E6C 8024028C 080900A6 */  j         .L80240298
/* BE7E70 80240290 0000282D */   daddu    $a1, $zero, $zero
.L80240294:
/* BE7E74 80240294 24050001 */  addiu     $a1, $zero, 1
.L80240298:
/* BE7E78 80240298 0C00F598 */  jal       func_8003D660
/* BE7E7C 8024029C 00000000 */   nop
/* BE7E80 802402A0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE7E84 802402A4 8E430078 */  lw        $v1, 0x78($s2)
/* BE7E88 802402A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE7E8C 802402AC 00031040 */  sll       $v0, $v1, 1
/* BE7E90 802402B0 00431021 */  addu      $v0, $v0, $v1
/* BE7E94 802402B4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE7E98 802402B8 00021080 */  sll       $v0, $v0, 2
/* BE7E9C 802402BC 00431021 */  addu      $v0, $v0, $v1
/* BE7EA0 802402C0 C4560004 */  lwc1      $f22, 4($v0)
/* BE7EA4 802402C4 4680B5A0 */  cvt.s.w   $f22, $f22
/* BE7EA8 802402C8 C454000C */  lwc1      $f20, 0xc($v0)
/* BE7EAC 802402CC 4680A520 */  cvt.s.w   $f20, $f20
/* BE7EB0 802402D0 4406B000 */  mfc1      $a2, $f22
/* BE7EB4 802402D4 4407A000 */  mfc1      $a3, $f20
/* BE7EB8 802402D8 0C00A720 */  jal       atan2
/* BE7EBC 802402DC 00000000 */   nop
/* BE7EC0 802402E0 8E050018 */  lw        $a1, 0x18($s0)
/* BE7EC4 802402E4 44060000 */  mfc1      $a2, $f0
/* BE7EC8 802402E8 0200202D */  daddu     $a0, $s0, $zero
/* BE7ECC 802402EC 0C00EA95 */  jal       npc_move_heading
/* BE7ED0 802402F0 AE06000C */   sw       $a2, 0xc($s0)
/* BE7ED4 802402F4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE7ED8 802402F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE7EDC 802402FC 4406B000 */  mfc1      $a2, $f22
/* BE7EE0 80240300 4407A000 */  mfc1      $a3, $f20
/* BE7EE4 80240304 0C00A7B5 */  jal       dist2D
/* BE7EE8 80240308 00000000 */   nop
/* BE7EEC 8024030C C6020018 */  lwc1      $f2, 0x18($s0)
/* BE7EF0 80240310 4602003E */  c.le.s    $f0, $f2
/* BE7EF4 80240314 00000000 */  nop
/* BE7EF8 80240318 4500002F */  bc1f      .L802403D8
/* BE7EFC 8024031C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BE7F00 80240320 24020002 */  addiu     $v0, $zero, 2
/* BE7F04 80240324 0C00A67F */  jal       rand_int
/* BE7F08 80240328 AE420070 */   sw       $v0, 0x70($s2)
/* BE7F0C 8024032C 3C035555 */  lui       $v1, 0x5555
/* BE7F10 80240330 34635556 */  ori       $v1, $v1, 0x5556
/* BE7F14 80240334 00430018 */  mult      $v0, $v1
/* BE7F18 80240338 000227C3 */  sra       $a0, $v0, 0x1f
/* BE7F1C 8024033C 00004010 */  mfhi      $t0
/* BE7F20 80240340 01042023 */  subu      $a0, $t0, $a0
/* BE7F24 80240344 00041840 */  sll       $v1, $a0, 1
/* BE7F28 80240348 00641821 */  addu      $v1, $v1, $a0
/* BE7F2C 8024034C 00431023 */  subu      $v0, $v0, $v1
/* BE7F30 80240350 24430002 */  addiu     $v1, $v0, 2
/* BE7F34 80240354 AE430074 */  sw        $v1, 0x74($s2)
/* BE7F38 80240358 8E62002C */  lw        $v0, 0x2c($s3)
/* BE7F3C 8024035C 18400009 */  blez      $v0, .L80240384
/* BE7F40 80240360 24020004 */   addiu    $v0, $zero, 4
/* BE7F44 80240364 8E620004 */  lw        $v0, 4($s3)
/* BE7F48 80240368 18400006 */  blez      $v0, .L80240384
/* BE7F4C 8024036C 24020004 */   addiu    $v0, $zero, 4
/* BE7F50 80240370 8E620008 */  lw        $v0, 8($s3)
/* BE7F54 80240374 18400003 */  blez      $v0, .L80240384
/* BE7F58 80240378 24020004 */   addiu    $v0, $zero, 4
/* BE7F5C 8024037C 14600002 */  bnez      $v1, .L80240388
/* BE7F60 80240380 00000000 */   nop
.L80240384:
/* BE7F64 80240384 AE420070 */  sw        $v0, 0x70($s2)
.L80240388:
/* BE7F68 80240388 0C00A67F */  jal       rand_int
/* BE7F6C 8024038C 24042710 */   addiu    $a0, $zero, 0x2710
/* BE7F70 80240390 3C0351EB */  lui       $v1, 0x51eb
/* BE7F74 80240394 3463851F */  ori       $v1, $v1, 0x851f
/* BE7F78 80240398 00430018 */  mult      $v0, $v1
/* BE7F7C 8024039C 00021FC3 */  sra       $v1, $v0, 0x1f
/* BE7F80 802403A0 00004010 */  mfhi      $t0
/* BE7F84 802403A4 00082143 */  sra       $a0, $t0, 5
/* BE7F88 802403A8 00832023 */  subu      $a0, $a0, $v1
/* BE7F8C 802403AC 00041840 */  sll       $v1, $a0, 1
/* BE7F90 802403B0 00641821 */  addu      $v1, $v1, $a0
/* BE7F94 802403B4 000318C0 */  sll       $v1, $v1, 3
/* BE7F98 802403B8 00641821 */  addu      $v1, $v1, $a0
/* BE7F9C 802403BC 00031880 */  sll       $v1, $v1, 2
/* BE7FA0 802403C0 8E640004 */  lw        $a0, 4($s3)
/* BE7FA4 802403C4 00431023 */  subu      $v0, $v0, $v1
/* BE7FA8 802403C8 0044102A */  slt       $v0, $v0, $a0
/* BE7FAC 802403CC 10400002 */  beqz      $v0, .L802403D8
/* BE7FB0 802403D0 24020004 */   addiu    $v0, $zero, 4
.L802403D4:
/* BE7FB4 802403D4 AE420070 */  sw        $v0, 0x70($s2)
.L802403D8:
/* BE7FB8 802403D8 8FBF0044 */  lw        $ra, 0x44($sp)
/* BE7FBC 802403DC 8FB40040 */  lw        $s4, 0x40($sp)
/* BE7FC0 802403E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE7FC4 802403E4 8FB20038 */  lw        $s2, 0x38($sp)
/* BE7FC8 802403E8 8FB10034 */  lw        $s1, 0x34($sp)
/* BE7FCC 802403EC 8FB00030 */  lw        $s0, 0x30($sp)
/* BE7FD0 802403F0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* BE7FD4 802403F4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* BE7FD8 802403F8 03E00008 */  jr        $ra
/* BE7FDC 802403FC 27BD0058 */   addiu    $sp, $sp, 0x58
