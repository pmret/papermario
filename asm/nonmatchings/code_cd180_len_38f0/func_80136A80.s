.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80136A80
/* CD180 80136A80 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CD184 80136A84 F7B80060 */  sdc1      $f24, 0x60($sp)
/* CD188 80136A88 4485C000 */  mtc1      $a1, $f24
/* CD18C 80136A8C 3C050001 */  lui       $a1, 1
/* CD190 80136A90 44800000 */  mtc1      $zero, $f0
/* CD194 80136A94 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CD198 80136A98 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CD19C 80136A9C 34A51630 */  ori       $a1, $a1, 0x1630
/* CD1A0 80136AA0 A3A40020 */  sb        $a0, 0x20($sp)
/* CD1A4 80136AA4 3C04800B */  lui       $a0, %hi(gCameras)
/* CD1A8 80136AA8 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* CD1AC 80136AAC AFBF004C */  sw        $ra, 0x4c($sp)
/* CD1B0 80136AB0 AFBE0048 */  sw        $fp, 0x48($sp)
/* CD1B4 80136AB4 AFB70044 */  sw        $s7, 0x44($sp)
/* CD1B8 80136AB8 AFB60040 */  sw        $s6, 0x40($sp)
/* CD1BC 80136ABC AFB5003C */  sw        $s5, 0x3c($sp)
/* CD1C0 80136AC0 AFB40038 */  sw        $s4, 0x38($sp)
/* CD1C4 80136AC4 AFB30034 */  sw        $s3, 0x34($sp)
/* CD1C8 80136AC8 AFB20030 */  sw        $s2, 0x30($sp)
/* CD1CC 80136ACC AFB1002C */  sw        $s1, 0x2c($sp)
/* CD1D0 80136AD0 AFB00028 */  sw        $s0, 0x28($sp)
/* CD1D4 80136AD4 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* CD1D8 80136AD8 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* CD1DC 80136ADC F7B60058 */  sdc1      $f22, 0x58($sp)
/* CD1E0 80136AE0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* CD1E4 80136AE4 00031080 */  sll       $v0, $v1, 2
/* CD1E8 80136AE8 00431021 */  addu      $v0, $v0, $v1
/* CD1EC 80136AEC 00021080 */  sll       $v0, $v0, 2
/* CD1F0 80136AF0 00431023 */  subu      $v0, $v0, $v1
/* CD1F4 80136AF4 000218C0 */  sll       $v1, $v0, 3
/* CD1F8 80136AF8 00431021 */  addu      $v0, $v0, $v1
/* CD1FC 80136AFC 000210C0 */  sll       $v0, $v0, 3
/* CD200 80136B00 00444821 */  addu      $t1, $v0, $a0
/* CD204 80136B04 3C03800A */  lui       $v1, %hi(D_8009A674)
/* CD208 80136B08 8C63A674 */  lw        $v1, %lo(D_8009A674)($v1)
/* CD20C 80136B0C 4600C032 */  c.eq.s    $f24, $f0
/* CD210 80136B10 00000000 */  nop       
/* CD214 80136B14 4501048B */  bc1t      .L80137D44
/* CD218 80136B18 0065F021 */   addu     $fp, $v1, $a1
/* CD21C 80136B1C 10C0000A */  beqz      $a2, .L80136B48
/* CD220 80136B20 0000A82D */   daddu    $s5, $zero, $zero
/* CD224 80136B24 90D30000 */  lbu       $s3, ($a2)
/* CD228 80136B28 90D40001 */  lbu       $s4, 1($a2)
/* CD22C 80136B2C 90D50002 */  lbu       $s5, 2($a2)
/* CD230 80136B30 8CD10004 */  lw        $s1, 4($a2)
/* CD234 80136B34 8CD20008 */  lw        $s2, 8($a2)
/* CD238 80136B38 8CD6000C */  lw        $s6, 0xc($a2)
/* CD23C 80136B3C 8CD70010 */  lw        $s7, 0x10($a2)
/* CD240 80136B40 0804DAD9 */  j         .L80136B64
/* CD244 80136B44 C4DC0014 */   lwc1     $f28, 0x14($a2)
.L80136B48:
/* CD248 80136B48 02A0A02D */  daddu     $s4, $s5, $zero
/* CD24C 80136B4C 02A0982D */  daddu     $s3, $s5, $zero
/* CD250 80136B50 0000B82D */  daddu     $s7, $zero, $zero
/* CD254 80136B54 02E0B02D */  daddu     $s6, $s7, $zero
/* CD258 80136B58 02E0902D */  daddu     $s2, $s7, $zero
/* CD25C 80136B5C 02E0882D */  daddu     $s1, $s7, $zero
/* CD260 80136B60 46000706 */  mov.s     $f28, $f0
.L80136B64:
/* CD264 80136B64 93A30020 */  lbu       $v1, 0x20($sp)
/* CD268 80136B68 10600005 */  beqz      $v1, .L80136B80
/* CD26C 80136B6C 24020001 */   addiu    $v0, $zero, 1
/* CD270 80136B70 10620070 */  beq       $v1, $v0, .L80136D34
/* CD274 80136B74 3C04E300 */   lui      $a0, 0xe300
/* CD278 80136B78 0804DBCA */  j         .L80136F28
/* CD27C 80136B7C 00000000 */   nop      
.L80136B80:
/* CD280 80136B80 3C04E300 */  lui       $a0, 0xe300
/* CD284 80136B84 34841801 */  ori       $a0, $a0, 0x1801
/* CD288 80136B88 3C05E300 */  lui       $a1, 0xe300
/* CD28C 80136B8C 34A51A01 */  ori       $a1, $a1, 0x1a01
/* CD290 80136B90 3C06E300 */  lui       $a2, 0xe300
/* CD294 80136B94 3C08800A */  lui       $t0, %hi(D_8009A66C)
/* CD298 80136B98 2508A66C */  addiu     $t0, $t0, %lo(D_8009A66C)
/* CD29C 80136B9C 34C60A01 */  ori       $a2, $a2, 0xa01
/* CD2A0 80136BA0 3C02E700 */  lui       $v0, 0xe700
/* CD2A4 80136BA4 8D070000 */  lw        $a3, ($t0)
/* CD2A8 80136BA8 3C01437F */  lui       $at, 0x437f
/* CD2AC 80136BAC 44810000 */  mtc1      $at, $f0
/* CD2B0 80136BB0 00E0182D */  daddu     $v1, $a3, $zero
/* CD2B4 80136BB4 24E70008 */  addiu     $a3, $a3, 8
/* CD2B8 80136BB8 AD070000 */  sw        $a3, ($t0)
/* CD2BC 80136BBC AC620000 */  sw        $v0, ($v1)
/* CD2C0 80136BC0 24E20008 */  addiu     $v0, $a3, 8
/* CD2C4 80136BC4 AC600004 */  sw        $zero, 4($v1)
/* CD2C8 80136BC8 AD020000 */  sw        $v0, ($t0)
/* CD2CC 80136BCC 24E20010 */  addiu     $v0, $a3, 0x10
/* CD2D0 80136BD0 ACE40000 */  sw        $a0, ($a3)
/* CD2D4 80136BD4 ACE00004 */  sw        $zero, 4($a3)
/* CD2D8 80136BD8 AD020000 */  sw        $v0, ($t0)
/* CD2DC 80136BDC 24E20018 */  addiu     $v0, $a3, 0x18
/* CD2E0 80136BE0 4600C032 */  c.eq.s    $f24, $f0
/* CD2E4 80136BE4 ACE50008 */  sw        $a1, 8($a3)
/* CD2E8 80136BE8 ACE0000C */  sw        $zero, 0xc($a3)
/* CD2EC 80136BEC AD020000 */  sw        $v0, ($t0)
/* CD2F0 80136BF0 ACE60010 */  sw        $a2, 0x10($a3)
/* CD2F4 80136BF4 45000006 */  bc1f      .L80136C10
/* CD2F8 80136BF8 ACE00014 */   sw       $zero, 0x14($a3)
/* CD2FC 80136BFC 3C04E200 */  lui       $a0, 0xe200
/* CD300 80136C00 3484001C */  ori       $a0, $a0, 0x1c
/* CD304 80136C04 3C030F0A */  lui       $v1, 0xf0a
/* CD308 80136C08 0804DB08 */  j         .L80136C20
/* CD30C 80136C0C 34634300 */   ori      $v1, $v1, 0x4300
.L80136C10:
/* CD310 80136C10 3C04E200 */  lui       $a0, 0xe200
/* CD314 80136C14 3484001C */  ori       $a0, $a0, 0x1c
/* CD318 80136C18 3C030050 */  lui       $v1, 0x50
/* CD31C 80136C1C 34634340 */  ori       $v1, $v1, 0x4340
.L80136C20:
/* CD320 80136C20 24E20020 */  addiu     $v0, $a3, 0x20
/* CD324 80136C24 AD020000 */  sw        $v0, ($t0)
/* CD328 80136C28 ACE40018 */  sw        $a0, 0x18($a3)
/* CD32C 80136C2C ACE3001C */  sw        $v1, 0x1c($a3)
/* CD330 80136C30 3C06FCFF */  lui       $a2, 0xfcff
/* CD334 80136C34 34C6FFFF */  ori       $a2, $a2, 0xffff
/* CD338 80136C38 3C05FFFD */  lui       $a1, 0xfffd
/* CD33C 80136C3C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CD340 80136C40 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CD344 80136C44 34A5F6FB */  ori       $a1, $a1, 0xf6fb
/* CD348 80136C48 8C830000 */  lw        $v1, ($a0)
/* CD34C 80136C4C 3C014F00 */  lui       $at, 0x4f00
/* CD350 80136C50 44810000 */  mtc1      $at, $f0
/* CD354 80136C54 0060102D */  daddu     $v0, $v1, $zero
/* CD358 80136C58 24630008 */  addiu     $v1, $v1, 8
/* CD35C 80136C5C AC830000 */  sw        $v1, ($a0)
/* CD360 80136C60 AC460000 */  sw        $a2, ($v0)
/* CD364 80136C64 AC450004 */  sw        $a1, 4($v0)
/* CD368 80136C68 24620008 */  addiu     $v0, $v1, 8
/* CD36C 80136C6C AC820000 */  sw        $v0, ($a0)
/* CD370 80136C70 3C02FA00 */  lui       $v0, 0xfa00
/* CD374 80136C74 246A0004 */  addiu     $t2, $v1, 4
/* CD378 80136C78 AC620000 */  sw        $v0, ($v1)
/* CD37C 80136C7C 00131600 */  sll       $v0, $s3, 0x18
/* CD380 80136C80 00141C00 */  sll       $v1, $s4, 0x10
/* CD384 80136C84 00431025 */  or        $v0, $v0, $v1
/* CD388 80136C88 00151A00 */  sll       $v1, $s5, 8
/* CD38C 80136C8C 4618003E */  c.le.s    $f0, $f24
/* CD390 80136C90 00000000 */  nop       
/* CD394 80136C94 45010005 */  bc1t      .L80136CAC
/* CD398 80136C98 00434825 */   or       $t1, $v0, $v1
/* CD39C 80136C9C 4600C20D */  trunc.w.s $f8, $f24
/* CD3A0 80136CA0 44054000 */  mfc1      $a1, $f8
/* CD3A4 80136CA4 0804DB32 */  j         .L80136CC8
/* CD3A8 80136CA8 3C060050 */   lui      $a2, 0x50
.L80136CAC:
/* CD3AC 80136CAC 4600C001 */  sub.s     $f0, $f24, $f0
/* CD3B0 80136CB0 3C028000 */  lui       $v0, 0x8000
/* CD3B4 80136CB4 4600020D */  trunc.w.s $f8, $f0
/* CD3B8 80136CB8 44054000 */  mfc1      $a1, $f8
/* CD3BC 80136CBC 00000000 */  nop       
/* CD3C0 80136CC0 00A22825 */  or        $a1, $a1, $v0
/* CD3C4 80136CC4 3C060050 */  lui       $a2, 0x50
.L80136CC8:
/* CD3C8 80136CC8 34C603C0 */  ori       $a2, $a2, 0x3c0
/* CD3CC 80136CCC 3C07F64F */  lui       $a3, 0xf64f
/* CD3D0 80136CD0 34E7C3BC */  ori       $a3, $a3, 0xc3bc
/* CD3D4 80136CD4 3C08E300 */  lui       $t0, 0xe300
/* CD3D8 80136CD8 35081801 */  ori       $t0, $t0, 0x1801
/* CD3DC 80136CDC 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CD3E0 80136CE0 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CD3E4 80136CE4 30A200FF */  andi      $v0, $a1, 0xff
/* CD3E8 80136CE8 8C830000 */  lw        $v1, ($a0)
/* CD3EC 80136CEC 01221025 */  or        $v0, $t1, $v0
/* CD3F0 80136CF0 AD420000 */  sw        $v0, ($t2)
/* CD3F4 80136CF4 3C02ED00 */  lui       $v0, 0xed00
/* CD3F8 80136CF8 0060282D */  daddu     $a1, $v1, $zero
/* CD3FC 80136CFC 24630008 */  addiu     $v1, $v1, 8
/* CD400 80136D00 AC830000 */  sw        $v1, ($a0)
/* CD404 80136D04 ACA20000 */  sw        $v0, ($a1)
/* CD408 80136D08 24620008 */  addiu     $v0, $v1, 8
/* CD40C 80136D0C ACA60004 */  sw        $a2, 4($a1)
/* CD410 80136D10 AC820000 */  sw        $v0, ($a0)
/* CD414 80136D14 24620010 */  addiu     $v0, $v1, 0x10
/* CD418 80136D18 AC670000 */  sw        $a3, ($v1)
/* CD41C 80136D1C AC600004 */  sw        $zero, 4($v1)
/* CD420 80136D20 AC820000 */  sw        $v0, ($a0)
/* CD424 80136D24 240200C0 */  addiu     $v0, $zero, 0xc0
/* CD428 80136D28 AC680008 */  sw        $t0, 8($v1)
/* CD42C 80136D2C 0804DF51 */  j         .L80137D44
/* CD430 80136D30 AC62000C */   sw       $v0, 0xc($v1)
.L80136D34:
/* CD434 80136D34 34841801 */  ori       $a0, $a0, 0x1801
/* CD438 80136D38 3C05E300 */  lui       $a1, 0xe300
/* CD43C 80136D3C 34A51A01 */  ori       $a1, $a1, 0x1a01
/* CD440 80136D40 3C06E300 */  lui       $a2, 0xe300
/* CD444 80136D44 3C08800A */  lui       $t0, %hi(D_8009A66C)
/* CD448 80136D48 2508A66C */  addiu     $t0, $t0, %lo(D_8009A66C)
/* CD44C 80136D4C 34C60A01 */  ori       $a2, $a2, 0xa01
/* CD450 80136D50 3C02E700 */  lui       $v0, 0xe700
/* CD454 80136D54 8D070000 */  lw        $a3, ($t0)
/* CD458 80136D58 3C01437F */  lui       $at, 0x437f
/* CD45C 80136D5C 44810000 */  mtc1      $at, $f0
/* CD460 80136D60 00E0182D */  daddu     $v1, $a3, $zero
/* CD464 80136D64 24E70008 */  addiu     $a3, $a3, 8
/* CD468 80136D68 AD070000 */  sw        $a3, ($t0)
/* CD46C 80136D6C AC620000 */  sw        $v0, ($v1)
/* CD470 80136D70 24E20008 */  addiu     $v0, $a3, 8
/* CD474 80136D74 AC600004 */  sw        $zero, 4($v1)
/* CD478 80136D78 AD020000 */  sw        $v0, ($t0)
/* CD47C 80136D7C 24E20010 */  addiu     $v0, $a3, 0x10
/* CD480 80136D80 ACE40000 */  sw        $a0, ($a3)
/* CD484 80136D84 ACE00004 */  sw        $zero, 4($a3)
/* CD488 80136D88 AD020000 */  sw        $v0, ($t0)
/* CD48C 80136D8C 24E20018 */  addiu     $v0, $a3, 0x18
/* CD490 80136D90 4600C032 */  c.eq.s    $f24, $f0
/* CD494 80136D94 ACE50008 */  sw        $a1, 8($a3)
/* CD498 80136D98 ACE0000C */  sw        $zero, 0xc($a3)
/* CD49C 80136D9C AD020000 */  sw        $v0, ($t0)
/* CD4A0 80136DA0 ACE60010 */  sw        $a2, 0x10($a3)
/* CD4A4 80136DA4 45000006 */  bc1f      .L80136DC0
/* CD4A8 80136DA8 ACE00014 */   sw       $zero, 0x14($a3)
/* CD4AC 80136DAC 3C04E200 */  lui       $a0, 0xe200
/* CD4B0 80136DB0 3484001C */  ori       $a0, $a0, 0x1c
/* CD4B4 80136DB4 3C030F0A */  lui       $v1, 0xf0a
/* CD4B8 80136DB8 0804DB74 */  j         .L80136DD0
/* CD4BC 80136DBC 34634300 */   ori      $v1, $v1, 0x4300
.L80136DC0:
/* CD4C0 80136DC0 3C04E200 */  lui       $a0, 0xe200
/* CD4C4 80136DC4 3484001C */  ori       $a0, $a0, 0x1c
/* CD4C8 80136DC8 3C030050 */  lui       $v1, 0x50
/* CD4CC 80136DCC 34634340 */  ori       $v1, $v1, 0x4340
.L80136DD0:
/* CD4D0 80136DD0 24E20020 */  addiu     $v0, $a3, 0x20
/* CD4D4 80136DD4 AD020000 */  sw        $v0, ($t0)
/* CD4D8 80136DD8 ACE40018 */  sw        $a0, 0x18($a3)
/* CD4DC 80136DDC ACE3001C */  sw        $v1, 0x1c($a3)
/* CD4E0 80136DE0 3C06FCFF */  lui       $a2, 0xfcff
/* CD4E4 80136DE4 34C6FFFF */  ori       $a2, $a2, 0xffff
/* CD4E8 80136DE8 3C05FFFD */  lui       $a1, 0xfffd
/* CD4EC 80136DEC 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CD4F0 80136DF0 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CD4F4 80136DF4 34A5F6FB */  ori       $a1, $a1, 0xf6fb
/* CD4F8 80136DF8 8C830000 */  lw        $v1, ($a0)
/* CD4FC 80136DFC 3C014F00 */  lui       $at, 0x4f00
/* CD500 80136E00 44810000 */  mtc1      $at, $f0
/* CD504 80136E04 0060102D */  daddu     $v0, $v1, $zero
/* CD508 80136E08 24630008 */  addiu     $v1, $v1, 8
/* CD50C 80136E0C AC830000 */  sw        $v1, ($a0)
/* CD510 80136E10 AC460000 */  sw        $a2, ($v0)
/* CD514 80136E14 AC450004 */  sw        $a1, 4($v0)
/* CD518 80136E18 24620008 */  addiu     $v0, $v1, 8
/* CD51C 80136E1C AC820000 */  sw        $v0, ($a0)
/* CD520 80136E20 3C02FA00 */  lui       $v0, 0xfa00
/* CD524 80136E24 24680004 */  addiu     $t0, $v1, 4
/* CD528 80136E28 AC620000 */  sw        $v0, ($v1)
/* CD52C 80136E2C 00131600 */  sll       $v0, $s3, 0x18
/* CD530 80136E30 00141C00 */  sll       $v1, $s4, 0x10
/* CD534 80136E34 00431025 */  or        $v0, $v0, $v1
/* CD538 80136E38 00151A00 */  sll       $v1, $s5, 8
/* CD53C 80136E3C 4618003E */  c.le.s    $f0, $f24
/* CD540 80136E40 00000000 */  nop       
/* CD544 80136E44 45010005 */  bc1t      .L80136E5C
/* CD548 80136E48 00431825 */   or       $v1, $v0, $v1
/* CD54C 80136E4C 4600C20D */  trunc.w.s $f8, $f24
/* CD550 80136E50 44104000 */  mfc1      $s0, $f8
/* CD554 80136E54 0804DB9E */  j         .L80136E78
/* CD558 80136E58 3C040050 */   lui      $a0, 0x50
.L80136E5C:
/* CD55C 80136E5C 4600C001 */  sub.s     $f0, $f24, $f0
/* CD560 80136E60 3C028000 */  lui       $v0, 0x8000
/* CD564 80136E64 4600020D */  trunc.w.s $f8, $f0
/* CD568 80136E68 44104000 */  mfc1      $s0, $f8
/* CD56C 80136E6C 00000000 */  nop       
/* CD570 80136E70 02028025 */  or        $s0, $s0, $v0
/* CD574 80136E74 3C040050 */  lui       $a0, 0x50
.L80136E78:
/* CD578 80136E78 348403C0 */  ori       $a0, $a0, 0x3c0
/* CD57C 80136E7C 3C07E300 */  lui       $a3, 0xe300
/* CD580 80136E80 34E71801 */  ori       $a3, $a3, 0x1801
/* CD584 80136E84 3C06800A */  lui       $a2, %hi(D_8009A66C)
/* CD588 80136E88 24C6A66C */  addiu     $a2, $a2, %lo(D_8009A66C)
/* CD58C 80136E8C 320200FF */  andi      $v0, $s0, 0xff
/* CD590 80136E90 8CC50000 */  lw        $a1, ($a2)
/* CD594 80136E94 00621025 */  or        $v0, $v1, $v0
/* CD598 80136E98 AD020000 */  sw        $v0, ($t0)
/* CD59C 80136E9C 3C02ED00 */  lui       $v0, 0xed00
/* CD5A0 80136EA0 00A0182D */  daddu     $v1, $a1, $zero
/* CD5A4 80136EA4 24A50008 */  addiu     $a1, $a1, 8
/* CD5A8 80136EA8 ACC50000 */  sw        $a1, ($a2)
/* CD5AC 80136EAC AC620000 */  sw        $v0, ($v1)
/* CD5B0 80136EB0 AC640004 */  sw        $a0, 4($v1)
/* CD5B4 80136EB4 8523000E */  lh        $v1, 0xe($t1)
/* CD5B8 80136EB8 8524000A */  lh        $a0, 0xa($t1)
/* CD5BC 80136EBC 24A20008 */  addiu     $v0, $a1, 8
/* CD5C0 80136EC0 ACC20000 */  sw        $v0, ($a2)
/* CD5C4 80136EC4 85220010 */  lh        $v0, 0x10($t1)
/* CD5C8 80136EC8 00641821 */  addu      $v1, $v1, $a0
/* CD5CC 80136ECC 306303FF */  andi      $v1, $v1, 0x3ff
/* CD5D0 80136ED0 8524000C */  lh        $a0, 0xc($t1)
/* CD5D4 80136ED4 00031B80 */  sll       $v1, $v1, 0xe
/* CD5D8 80136ED8 00441021 */  addu      $v0, $v0, $a0
/* CD5DC 80136EDC 304203FF */  andi      $v0, $v0, 0x3ff
/* CD5E0 80136EE0 00021080 */  sll       $v0, $v0, 2
/* CD5E4 80136EE4 3C04F600 */  lui       $a0, 0xf600
/* CD5E8 80136EE8 00441025 */  or        $v0, $v0, $a0
/* CD5EC 80136EEC 00621825 */  or        $v1, $v1, $v0
/* CD5F0 80136EF0 ACA30000 */  sw        $v1, ($a1)
/* CD5F4 80136EF4 9522000E */  lhu       $v0, 0xe($t1)
/* CD5F8 80136EF8 95240010 */  lhu       $a0, 0x10($t1)
/* CD5FC 80136EFC 24A30010 */  addiu     $v1, $a1, 0x10
/* CD600 80136F00 ACC30000 */  sw        $v1, ($a2)
/* CD604 80136F04 240300C0 */  addiu     $v1, $zero, 0xc0
/* CD608 80136F08 ACA70008 */  sw        $a3, 8($a1)
/* CD60C 80136F0C ACA3000C */  sw        $v1, 0xc($a1)
/* CD610 80136F10 304203FF */  andi      $v0, $v0, 0x3ff
/* CD614 80136F14 00021380 */  sll       $v0, $v0, 0xe
/* CD618 80136F18 308403FF */  andi      $a0, $a0, 0x3ff
/* CD61C 80136F1C 00042080 */  sll       $a0, $a0, 2
/* CD620 80136F20 0804DF50 */  j         .L80137D40
/* CD624 80136F24 00441025 */   or       $v0, $v0, $a0
.L80136F28:
/* CD628 80136F28 3C108007 */  lui       $s0, %hi(D_800741F0)
/* CD62C 80136F2C 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* CD630 80136F30 44800000 */  mtc1      $zero, $f0
/* CD634 80136F34 3C0643A0 */  lui       $a2, 0x43a0
/* CD638 80136F38 96040000 */  lhu       $a0, ($s0)
/* CD63C 80136F3C 3C01C47A */  lui       $at, 0xc47a
/* CD640 80136F40 44811000 */  mtc1      $at, $f2
/* CD644 80136F44 3C01447A */  lui       $at, 0x447a
/* CD648 80136F48 44812000 */  mtc1      $at, $f4
/* CD64C 80136F4C 3C013F80 */  lui       $at, 0x3f80
/* CD650 80136F50 44813000 */  mtc1      $at, $f6
/* CD654 80136F54 00042180 */  sll       $a0, $a0, 6
/* CD658 80136F58 44050000 */  mfc1      $a1, $f0
/* CD65C 80136F5C 3C014370 */  lui       $at, 0x4370
/* CD660 80136F60 44810000 */  mtc1      $at, $f0
/* CD664 80136F64 03C42021 */  addu      $a0, $fp, $a0
/* CD668 80136F68 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD66C 80136F6C E7A40018 */  swc1      $f4, 0x18($sp)
/* CD670 80136F70 E7A6001C */  swc1      $f6, 0x1c($sp)
/* CD674 80136F74 00A0382D */  daddu     $a3, $a1, $zero
/* CD678 80136F78 0C018E90 */  jal       guOrtho
/* CD67C 80136F7C E7A00010 */   swc1     $f0, 0x10($sp)
/* CD680 80136F80 3C06DA38 */  lui       $a2, 0xda38
/* CD684 80136F84 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CD688 80136F88 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CD68C 80136F8C 34C60007 */  ori       $a2, $a2, 7
/* CD690 80136F90 8C830000 */  lw        $v1, ($a0)
/* CD694 80136F94 96020000 */  lhu       $v0, ($s0)
/* CD698 80136F98 0060282D */  daddu     $a1, $v1, $zero
/* CD69C 80136F9C 24630008 */  addiu     $v1, $v1, 8
/* CD6A0 80136FA0 AC830000 */  sw        $v1, ($a0)
/* CD6A4 80136FA4 24430001 */  addiu     $v1, $v0, 1
/* CD6A8 80136FA8 3042FFFF */  andi      $v0, $v0, 0xffff
/* CD6AC 80136FAC 00021180 */  sll       $v0, $v0, 6
/* CD6B0 80136FB0 03C21021 */  addu      $v0, $fp, $v0
/* CD6B4 80136FB4 ACA60000 */  sw        $a2, ($a1)
/* CD6B8 80136FB8 A6030000 */  sh        $v1, ($s0)
/* CD6BC 80136FBC ACA20004 */  sw        $v0, 4($a1)
/* CD6C0 80136FC0 93A20020 */  lbu       $v0, 0x20($sp)
/* CD6C4 80136FC4 2443FFFE */  addiu     $v1, $v0, -2
/* CD6C8 80136FC8 2C62000E */  sltiu     $v0, $v1, 0xe
/* CD6CC 80136FCC 1040034C */  beqz      $v0, .L80137D00
/* CD6D0 80136FD0 00031080 */   sll      $v0, $v1, 2
/* CD6D4 80136FD4 3C018015 */  lui       $at, %hi(D_80150EA0)
/* CD6D8 80136FD8 00220821 */  addu      $at, $at, $v0
/* CD6DC 80136FDC 8C220EA0 */  lw        $v0, %lo(D_80150EA0)($at)
/* CD6E0 80136FE0 00400008 */  jr        $v0
/* CD6E4 80136FE4 00000000 */   nop      
/* CD6E8 80136FE8 240400A0 */  addiu     $a0, $zero, 0xa0
/* CD6EC 80136FEC 24050078 */  addiu     $a1, $zero, 0x78
/* CD6F0 80136FF0 0260382D */  daddu     $a3, $s3, $zero
/* CD6F4 80136FF4 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CD6F8 80136FF8 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CD6FC 80136FFC 461CC002 */  mul.s     $f0, $f24, $f28
/* CD700 80137000 00000000 */  nop       
/* CD704 80137004 8C620000 */  lw        $v0, ($v1)
/* CD708 80137008 4406C000 */  mfc1      $a2, $f24
/* CD70C 8013700C 3C01437F */  lui       $at, 0x437f
/* CD710 80137010 44811000 */  mtc1      $at, $f2
/* CD714 80137014 0040402D */  daddu     $t0, $v0, $zero
/* CD718 80137018 24420008 */  addiu     $v0, $v0, 8
/* CD71C 8013701C AC620000 */  sw        $v0, ($v1)
/* CD720 80137020 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CD724 80137024 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CD728 80137028 3C02DE00 */  lui       $v0, %hi(D_DDFFE670)
/* CD72C 8013702C AD020000 */  sw        $v0, ($t0)
/* CD730 80137030 3C028015 */  lui       $v0, %hi(D_8014E670)
/* CD734 80137034 2442E670 */  addiu     $v0, $v0, %lo(D_DDFFE670)
/* CD738 80137038 AD020004 */  sw        $v0, 4($t0)
/* CD73C 8013703C AFB40010 */  sw        $s4, 0x10($sp)
/* CD740 80137040 AFB50014 */  sw        $s5, 0x14($sp)
/* CD744 80137044 0804DC56 */  j         .L80137158
/* CD748 80137048 AFA3001C */   sw       $v1, 0x1c($sp)
/* CD74C 8013704C 240400A0 */  addiu     $a0, $zero, 0xa0
/* CD750 80137050 24050078 */  addiu     $a1, $zero, 0x78
/* CD754 80137054 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CD758 80137058 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CD75C 8013705C 461CC002 */  mul.s     $f0, $f24, $f28
/* CD760 80137060 00000000 */  nop       
/* CD764 80137064 8C620000 */  lw        $v0, ($v1)
/* CD768 80137068 4406C000 */  mfc1      $a2, $f24
/* CD76C 8013706C 3C01437F */  lui       $at, 0x437f
/* CD770 80137070 44811000 */  mtc1      $at, $f2
/* CD774 80137074 0040402D */  daddu     $t0, $v0, $zero
/* CD778 80137078 24420008 */  addiu     $v0, $v0, 8
/* CD77C 8013707C AC620000 */  sw        $v0, ($v1)
/* CD780 80137080 3C02DE00 */  lui       $v0, %hi(D_DDFFE670)
/* CD784 80137084 AD020000 */  sw        $v0, ($t0)
/* CD788 80137088 3C028015 */  lui       $v0, %hi(D_8014E670)
/* CD78C 8013708C 2442E670 */  addiu     $v0, $v0, %lo(D_DDFFE670)
/* CD790 80137090 0804DC51 */  j         .L80137144
/* CD794 80137094 0260382D */   daddu    $a3, $s3, $zero
/* CD798 80137098 240400A0 */  addiu     $a0, $zero, 0xa0
/* CD79C 8013709C 24050078 */  addiu     $a1, $zero, 0x78
/* CD7A0 801370A0 0260382D */  daddu     $a3, $s3, $zero
/* CD7A4 801370A4 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CD7A8 801370A8 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CD7AC 801370AC 461CC002 */  mul.s     $f0, $f24, $f28
/* CD7B0 801370B0 00000000 */  nop       
/* CD7B4 801370B4 8C620000 */  lw        $v0, ($v1)
/* CD7B8 801370B8 4406C000 */  mfc1      $a2, $f24
/* CD7BC 801370BC 3C01437F */  lui       $at, 0x437f
/* CD7C0 801370C0 44811000 */  mtc1      $at, $f2
/* CD7C4 801370C4 0040402D */  daddu     $t0, $v0, $zero
/* CD7C8 801370C8 24420008 */  addiu     $v0, $v0, 8
/* CD7CC 801370CC AC620000 */  sw        $v0, ($v1)
/* CD7D0 801370D0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CD7D4 801370D4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CD7D8 801370D8 3C02DE00 */  lui       $v0, %hi(D_DDFFE6C0)
/* CD7DC 801370DC AD020000 */  sw        $v0, ($t0)
/* CD7E0 801370E0 3C028015 */  lui       $v0, %hi(D_8014E6C0)
/* CD7E4 801370E4 2442E6C0 */  addiu     $v0, $v0, %lo(D_DDFFE6C0)
/* CD7E8 801370E8 AD020004 */  sw        $v0, 4($t0)
/* CD7EC 801370EC AFB40010 */  sw        $s4, 0x10($sp)
/* CD7F0 801370F0 AFB50014 */  sw        $s5, 0x14($sp)
/* CD7F4 801370F4 0804DC56 */  j         .L80137158
/* CD7F8 801370F8 AFA3001C */   sw       $v1, 0x1c($sp)
/* CD7FC 801370FC 240400A0 */  addiu     $a0, $zero, 0xa0
/* CD800 80137100 24050078 */  addiu     $a1, $zero, 0x78
/* CD804 80137104 0260382D */  daddu     $a3, $s3, $zero
/* CD808 80137108 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CD80C 8013710C 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CD810 80137110 461CC002 */  mul.s     $f0, $f24, $f28
/* CD814 80137114 00000000 */  nop       
/* CD818 80137118 8C620000 */  lw        $v0, ($v1)
/* CD81C 8013711C 4406C000 */  mfc1      $a2, $f24
/* CD820 80137120 3C01437F */  lui       $at, 0x437f
/* CD824 80137124 44811000 */  mtc1      $at, $f2
/* CD828 80137128 0040402D */  daddu     $t0, $v0, $zero
/* CD82C 8013712C 24420008 */  addiu     $v0, $v0, 8
/* CD830 80137130 AC620000 */  sw        $v0, ($v1)
/* CD834 80137134 3C02DE00 */  lui       $v0, %hi(D_DDFFE6C0)
/* CD838 80137138 AD020000 */  sw        $v0, ($t0)
/* CD83C 8013713C 3C028015 */  lui       $v0, %hi(D_8014E6C0)
/* CD840 80137140 2442E6C0 */  addiu     $v0, $v0, %lo(D_DDFFE6C0)
.L80137144:
/* CD844 80137144 AD020004 */  sw        $v0, 4($t0)
/* CD848 80137148 2402FFFF */  addiu     $v0, $zero, -1
/* CD84C 8013714C AFB40010 */  sw        $s4, 0x10($sp)
/* CD850 80137150 AFB50014 */  sw        $s5, 0x14($sp)
/* CD854 80137154 AFA2001C */  sw        $v0, 0x1c($sp)
.L80137158:
/* CD858 80137158 46020003 */  div.s     $f0, $f0, $f2
/* CD85C 8013715C 4600020D */  trunc.w.s $f8, $f0
/* CD860 80137160 0C04E7C4 */  jal       func_80139F10
/* CD864 80137164 E7A80018 */   swc1     $f8, 0x18($sp)
/* CD868 80137168 0804DF41 */  j         .L80137D04
/* CD86C 8013716C 3C06DA38 */   lui      $a2, 0xda38
/* CD870 80137170 0220202D */  daddu     $a0, $s1, $zero
/* CD874 80137174 0240282D */  daddu     $a1, $s2, $zero
/* CD878 80137178 0000382D */  daddu     $a3, $zero, $zero
/* CD87C 8013717C 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CD880 80137180 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CD884 80137184 8C620000 */  lw        $v0, ($v1)
/* CD888 80137188 4406C000 */  mfc1      $a2, $f24
/* CD88C 8013718C 0040402D */  daddu     $t0, $v0, $zero
/* CD890 80137190 24420008 */  addiu     $v0, $v0, 8
/* CD894 80137194 AC620000 */  sw        $v0, ($v1)
/* CD898 80137198 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CD89C 8013719C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CD8A0 801371A0 3C02DE00 */  lui       $v0, %hi(D_DDFFE618)
/* CD8A4 801371A4 AD020000 */  sw        $v0, ($t0)
/* CD8A8 801371A8 3C028015 */  lui       $v0, %hi(D_8014E618)
/* CD8AC 801371AC 2442E618 */  addiu     $v0, $v0, %lo(D_DDFFE618)
/* CD8B0 801371B0 AD020004 */  sw        $v0, 4($t0)
/* CD8B4 801371B4 AFA00010 */  sw        $zero, 0x10($sp)
/* CD8B8 801371B8 AFA00014 */  sw        $zero, 0x14($sp)
/* CD8BC 801371BC AFA00018 */  sw        $zero, 0x18($sp)
/* CD8C0 801371C0 0C04E7C4 */  jal       func_80139F10
/* CD8C4 801371C4 AFA3001C */   sw       $v1, 0x1c($sp)
/* CD8C8 801371C8 0804DF41 */  j         .L80137D04
/* CD8CC 801371CC 3C06DA38 */   lui      $a2, 0xda38
/* CD8D0 801371D0 0220202D */  daddu     $a0, $s1, $zero
/* CD8D4 801371D4 0240282D */  daddu     $a1, $s2, $zero
/* CD8D8 801371D8 0000382D */  daddu     $a3, $zero, $zero
/* CD8DC 801371DC 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CD8E0 801371E0 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CD8E4 801371E4 8C620000 */  lw        $v0, ($v1)
/* CD8E8 801371E8 4406C000 */  mfc1      $a2, $f24
/* CD8EC 801371EC 0040402D */  daddu     $t0, $v0, $zero
/* CD8F0 801371F0 24420008 */  addiu     $v0, $v0, 8
/* CD8F4 801371F4 AC620000 */  sw        $v0, ($v1)
/* CD8F8 801371F8 3C02DE00 */  lui       $v0, %hi(D_DDFFE618)
/* CD8FC 801371FC AD020000 */  sw        $v0, ($t0)
/* CD900 80137200 3C028015 */  lui       $v0, %hi(D_8014E618)
/* CD904 80137204 2442E618 */  addiu     $v0, $v0, %lo(D_DDFFE618)
/* CD908 80137208 AD020004 */  sw        $v0, 4($t0)
/* CD90C 8013720C 2402FFFF */  addiu     $v0, $zero, -1
/* CD910 80137210 AFA00010 */  sw        $zero, 0x10($sp)
/* CD914 80137214 AFA00014 */  sw        $zero, 0x14($sp)
/* CD918 80137218 AFA00018 */  sw        $zero, 0x18($sp)
/* CD91C 8013721C 0C04E7C4 */  jal       func_80139F10
/* CD920 80137220 AFA2001C */   sw       $v0, 0x1c($sp)
/* CD924 80137224 0804DF41 */  j         .L80137D04
/* CD928 80137228 3C06DA38 */   lui      $a2, 0xda38
/* CD92C 8013722C 3C15DA38 */  lui       $s5, 0xda38
/* CD930 80137230 36B50002 */  ori       $s5, $s5, 2
/* CD934 80137234 3C14DA38 */  lui       $s4, 0xda38
/* CD938 80137238 36940001 */  ori       $s4, $s4, 1
/* CD93C 8013723C 3C16D838 */  lui       $s6, 0xd838
/* CD940 80137240 36D60002 */  ori       $s6, $s6, 2
/* CD944 80137244 3C118007 */  lui       $s1, %hi(D_800741F0)
/* CD948 80137248 263141F0 */  addiu     $s1, $s1, %lo(D_800741F0)
/* CD94C 8013724C 4600C20D */  trunc.w.s $f8, $f24
/* CD950 80137250 44104000 */  mfc1      $s0, $f8
/* CD954 80137254 96240000 */  lhu       $a0, ($s1)
/* CD958 80137258 3C0542A0 */  lui       $a1, 0x42a0
/* CD95C 8013725C 3C0142F0 */  lui       $at, 0x42f0
/* CD960 80137260 4481E000 */  mtc1      $at, $f28
/* CD964 80137264 4480B000 */  mtc1      $zero, $f22
/* CD968 80137268 00042180 */  sll       $a0, $a0, 6
/* CD96C 8013726C 4406E000 */  mfc1      $a2, $f28
/* CD970 80137270 4407B000 */  mfc1      $a3, $f22
/* CD974 80137274 0C019E08 */  jal       guTranslate
/* CD978 80137278 03C42021 */   addu     $a0, $fp, $a0
/* CD97C 8013727C 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* CD980 80137280 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* CD984 80137284 00108400 */  sll       $s0, $s0, 0x10
/* CD988 80137288 00108403 */  sra       $s0, $s0, 0x10
/* CD98C 8013728C 4490C000 */  mtc1      $s0, $f24
/* CD990 80137290 00000000 */  nop       
/* CD994 80137294 4680C620 */  cvt.s.w   $f24, $f24
/* CD998 80137298 3C013F80 */  lui       $at, 0x3f80
/* CD99C 8013729C 4481D000 */  mtc1      $at, $f26
/* CD9A0 801372A0 8E420000 */  lw        $v0, ($s2)
/* CD9A4 801372A4 3C01437F */  lui       $at, 0x437f
/* CD9A8 801372A8 4481A000 */  mtc1      $at, $f20
/* CD9AC 801372AC 3C018015 */  lui       $at, %hi(D_80150ED8)
/* CD9B0 801372B0 D4200ED8 */  ldc1      $f0, %lo(D_80150ED8)($at)
/* CD9B4 801372B4 0040202D */  daddu     $a0, $v0, $zero
/* CD9B8 801372B8 4614C503 */  div.s     $f20, $f24, $f20
/* CD9BC 801372BC 24420008 */  addiu     $v0, $v0, 8
/* CD9C0 801372C0 AE420000 */  sw        $v0, ($s2)
/* CD9C4 801372C4 96220000 */  lhu       $v0, ($s1)
/* CD9C8 801372C8 4614D501 */  sub.s     $f20, $f26, $f20
/* CD9CC 801372CC AC950000 */  sw        $s5, ($a0)
/* CD9D0 801372D0 24430001 */  addiu     $v1, $v0, 1
/* CD9D4 801372D4 3042FFFF */  andi      $v0, $v0, 0xffff
/* CD9D8 801372D8 4600A521 */  cvt.d.s   $f20, $f20
/* CD9DC 801372DC 4620A502 */  mul.d     $f20, $f20, $f0
/* CD9E0 801372E0 00000000 */  nop       
/* CD9E4 801372E4 00021180 */  sll       $v0, $v0, 6
/* CD9E8 801372E8 03C21021 */  addu      $v0, $fp, $v0
/* CD9EC 801372EC A6230000 */  sh        $v1, ($s1)
/* CD9F0 801372F0 AC820004 */  sw        $v0, 4($a0)
/* CD9F4 801372F4 96240000 */  lhu       $a0, ($s1)
/* CD9F8 801372F8 4407D000 */  mfc1      $a3, $f26
/* CD9FC 801372FC 00042180 */  sll       $a0, $a0, 6
/* CDA00 80137300 4620A520 */  cvt.s.d   $f20, $f20
/* CDA04 80137304 4405A000 */  mfc1      $a1, $f20
/* CDA08 80137308 4406A000 */  mfc1      $a2, $f20
/* CDA0C 8013730C 0C019DC0 */  jal       guScale
/* CDA10 80137310 03C42021 */   addu     $a0, $fp, $a0
/* CDA14 80137314 8E430000 */  lw        $v1, ($s2)
/* CDA18 80137318 4406B000 */  mfc1      $a2, $f22
/* CDA1C 8013731C 96220000 */  lhu       $v0, ($s1)
/* CDA20 80137320 3C013F00 */  lui       $at, 0x3f00
/* CDA24 80137324 44810000 */  mtc1      $at, $f0
/* CDA28 80137328 0060202D */  daddu     $a0, $v1, $zero
/* CDA2C 8013732C 24630008 */  addiu     $v1, $v1, 8
/* CDA30 80137330 AE430000 */  sw        $v1, ($s2)
/* CDA34 80137334 24430001 */  addiu     $v1, $v0, 1
/* CDA38 80137338 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDA3C 8013733C 00021180 */  sll       $v0, $v0, 6
/* CDA40 80137340 03C21021 */  addu      $v0, $fp, $v0
/* CDA44 80137344 4600C602 */  mul.s     $f24, $f24, $f0
/* CDA48 80137348 00000000 */  nop       
/* CDA4C 8013734C AC940000 */  sw        $s4, ($a0)
/* CDA50 80137350 A6230000 */  sh        $v1, ($s1)
/* CDA54 80137354 AC820004 */  sw        $v0, 4($a0)
/* CDA58 80137358 E7BA0010 */  swc1      $f26, 0x10($sp)
/* CDA5C 8013735C 96240000 */  lhu       $a0, ($s1)
/* CDA60 80137360 4407B000 */  mfc1      $a3, $f22
/* CDA64 80137364 00042180 */  sll       $a0, $a0, 6
/* CDA68 80137368 4405C000 */  mfc1      $a1, $f24
/* CDA6C 8013736C 0C019F20 */  jal       guRotate
/* CDA70 80137370 03C42021 */   addu     $a0, $fp, $a0
/* CDA74 80137374 3C13DE00 */  lui       $s3, 0xde00
/* CDA78 80137378 8E480000 */  lw        $t0, ($s2)
/* CDA7C 8013737C 3C054370 */  lui       $a1, 0x4370
/* CDA80 80137380 4406E000 */  mfc1      $a2, $f28
/* CDA84 80137384 4407B000 */  mfc1      $a3, $f22
/* CDA88 80137388 96220000 */  lhu       $v0, ($s1)
/* CDA8C 8013738C 0100202D */  daddu     $a0, $t0, $zero
/* CDA90 80137390 25080008 */  addiu     $t0, $t0, 8
/* CDA94 80137394 24430001 */  addiu     $v1, $v0, 1
/* CDA98 80137398 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDA9C 8013739C 00021180 */  sll       $v0, $v0, 6
/* CDAA0 801373A0 03C21021 */  addu      $v0, $fp, $v0
/* CDAA4 801373A4 AE480000 */  sw        $t0, ($s2)
/* CDAA8 801373A8 AC940000 */  sw        $s4, ($a0)
/* CDAAC 801373AC A6230000 */  sh        $v1, ($s1)
/* CDAB0 801373B0 AC820004 */  sw        $v0, 4($a0)
/* CDAB4 801373B4 25020008 */  addiu     $v0, $t0, 8
/* CDAB8 801373B8 3C0B8015 */  lui       $t3, %hi(D_8014E8F0)
/* CDABC 801373BC 256BE8F0 */  addiu     $t3, $t3, %lo(D_8014E8F0)
/* CDAC0 801373C0 AE420000 */  sw        $v0, ($s2)
/* CDAC4 801373C4 25020010 */  addiu     $v0, $t0, 0x10
/* CDAC8 801373C8 AD130000 */  sw        $s3, ($t0)
/* CDACC 801373CC AD0B0004 */  sw        $t3, 4($t0)
/* CDAD0 801373D0 AE420000 */  sw        $v0, ($s2)
/* CDAD4 801373D4 AD160008 */  sw        $s6, 8($t0)
/* CDAD8 801373D8 96240000 */  lhu       $a0, ($s1)
/* CDADC 801373DC 24100040 */  addiu     $s0, $zero, 0x40
/* CDAE0 801373E0 AD10000C */  sw        $s0, 0xc($t0)
/* CDAE4 801373E4 00042180 */  sll       $a0, $a0, 6
/* CDAE8 801373E8 0C019E08 */  jal       guTranslate
/* CDAEC 801373EC 03C42021 */   addu     $a0, $fp, $a0
/* CDAF0 801373F0 8E430000 */  lw        $v1, ($s2)
/* CDAF4 801373F4 4405A000 */  mfc1      $a1, $f20
/* CDAF8 801373F8 4407D000 */  mfc1      $a3, $f26
/* CDAFC 801373FC 96220000 */  lhu       $v0, ($s1)
/* CDB00 80137400 00A0302D */  daddu     $a2, $a1, $zero
/* CDB04 80137404 0060402D */  daddu     $t0, $v1, $zero
/* CDB08 80137408 24630008 */  addiu     $v1, $v1, 8
/* CDB0C 8013740C AE430000 */  sw        $v1, ($s2)
/* CDB10 80137410 24430001 */  addiu     $v1, $v0, 1
/* CDB14 80137414 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDB18 80137418 00021180 */  sll       $v0, $v0, 6
/* CDB1C 8013741C AD150000 */  sw        $s5, ($t0)
/* CDB20 80137420 A6230000 */  sh        $v1, ($s1)
/* CDB24 80137424 3064FFFF */  andi      $a0, $v1, 0xffff
/* CDB28 80137428 03C21021 */  addu      $v0, $fp, $v0
/* CDB2C 8013742C 00042180 */  sll       $a0, $a0, 6
/* CDB30 80137430 03C42021 */  addu      $a0, $fp, $a0
/* CDB34 80137434 0C019DC0 */  jal       guScale
/* CDB38 80137438 AD020004 */   sw       $v0, 4($t0)
/* CDB3C 8013743C 8E430000 */  lw        $v1, ($s2)
/* CDB40 80137440 4405C000 */  mfc1      $a1, $f24
/* CDB44 80137444 4406B000 */  mfc1      $a2, $f22
/* CDB48 80137448 4407B000 */  mfc1      $a3, $f22
/* CDB4C 8013744C 96220000 */  lhu       $v0, ($s1)
/* CDB50 80137450 0060402D */  daddu     $t0, $v1, $zero
/* CDB54 80137454 24630008 */  addiu     $v1, $v1, 8
/* CDB58 80137458 AE430000 */  sw        $v1, ($s2)
/* CDB5C 8013745C 24430001 */  addiu     $v1, $v0, 1
/* CDB60 80137460 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDB64 80137464 00021180 */  sll       $v0, $v0, 6
/* CDB68 80137468 AD140000 */  sw        $s4, ($t0)
/* CDB6C 8013746C A6230000 */  sh        $v1, ($s1)
/* CDB70 80137470 3064FFFF */  andi      $a0, $v1, 0xffff
/* CDB74 80137474 03C21021 */  addu      $v0, $fp, $v0
/* CDB78 80137478 00042180 */  sll       $a0, $a0, 6
/* CDB7C 8013747C 03C42021 */  addu      $a0, $fp, $a0
/* CDB80 80137480 AD020004 */  sw        $v0, 4($t0)
/* CDB84 80137484 0C019F20 */  jal       guRotate
/* CDB88 80137488 E7BA0010 */   swc1     $f26, 0x10($sp)
/* CDB8C 8013748C 8E480000 */  lw        $t0, ($s2)
/* CDB90 80137490 4405B000 */  mfc1      $a1, $f22
/* CDB94 80137494 96220000 */  lhu       $v0, ($s1)
/* CDB98 80137498 00A0302D */  daddu     $a2, $a1, $zero
/* CDB9C 8013749C 00A0382D */  daddu     $a3, $a1, $zero
/* CDBA0 801374A0 0100202D */  daddu     $a0, $t0, $zero
/* CDBA4 801374A4 25080008 */  addiu     $t0, $t0, 8
/* CDBA8 801374A8 24430001 */  addiu     $v1, $v0, 1
/* CDBAC 801374AC 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDBB0 801374B0 00021180 */  sll       $v0, $v0, 6
/* CDBB4 801374B4 03C21021 */  addu      $v0, $fp, $v0
/* CDBB8 801374B8 AE480000 */  sw        $t0, ($s2)
/* CDBBC 801374BC AC940000 */  sw        $s4, ($a0)
/* CDBC0 801374C0 A6230000 */  sh        $v1, ($s1)
/* CDBC4 801374C4 AC820004 */  sw        $v0, 4($a0)
/* CDBC8 801374C8 25020008 */  addiu     $v0, $t0, 8
/* CDBCC 801374CC 3C0B8015 */  lui       $t3, %hi(D_8014E8F0)
/* CDBD0 801374D0 256BE8F0 */  addiu     $t3, $t3, %lo(D_8014E8F0)
/* CDBD4 801374D4 AE420000 */  sw        $v0, ($s2)
/* CDBD8 801374D8 AD130000 */  sw        $s3, ($t0)
/* CDBDC 801374DC AD0B0004 */  sw        $t3, 4($t0)
/* CDBE0 801374E0 96240000 */  lhu       $a0, ($s1)
/* CDBE4 801374E4 25020010 */  addiu     $v0, $t0, 0x10
/* CDBE8 801374E8 AE420000 */  sw        $v0, ($s2)
/* CDBEC 801374EC AD160008 */  sw        $s6, 8($t0)
/* CDBF0 801374F0 AD10000C */  sw        $s0, 0xc($t0)
/* CDBF4 801374F4 00042180 */  sll       $a0, $a0, 6
/* CDBF8 801374F8 0C019E08 */  jal       guTranslate
/* CDBFC 801374FC 03C42021 */   addu     $a0, $fp, $a0
/* CDC00 80137500 8E440000 */  lw        $a0, ($s2)
/* CDC04 80137504 96220000 */  lhu       $v0, ($s1)
/* CDC08 80137508 0080282D */  daddu     $a1, $a0, $zero
/* CDC0C 8013750C 24840008 */  addiu     $a0, $a0, 8
/* CDC10 80137510 24430001 */  addiu     $v1, $v0, 1
/* CDC14 80137514 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDC18 80137518 00021180 */  sll       $v0, $v0, 6
/* CDC1C 8013751C 03C21021 */  addu      $v0, $fp, $v0
/* CDC20 80137520 AE440000 */  sw        $a0, ($s2)
/* CDC24 80137524 ACB50000 */  sw        $s5, ($a1)
/* CDC28 80137528 A6230000 */  sh        $v1, ($s1)
/* CDC2C 8013752C ACA20004 */  sw        $v0, 4($a1)
/* CDC30 80137530 24820008 */  addiu     $v0, $a0, 8
/* CDC34 80137534 AE420000 */  sw        $v0, ($s2)
/* CDC38 80137538 3C028015 */  lui       $v0, %hi(D_8014EA48)
/* CDC3C 8013753C 2442EA48 */  addiu     $v0, $v0, %lo(D_8014EA48)
/* CDC40 80137540 AC820004 */  sw        $v0, 4($a0)
/* CDC44 80137544 24820010 */  addiu     $v0, $a0, 0x10
/* CDC48 80137548 AC930000 */  sw        $s3, ($a0)
/* CDC4C 8013754C AE420000 */  sw        $v0, ($s2)
/* CDC50 80137550 AC960008 */  sw        $s6, 8($a0)
/* CDC54 80137554 0804DF40 */  j         .L80137D00
/* CDC58 80137558 AC90000C */   sw       $s0, 0xc($a0)
/* CDC5C 8013755C 44914000 */  mtc1      $s1, $f8
/* CDC60 80137560 00000000 */  nop       
/* CDC64 80137564 46804220 */  cvt.s.w   $f8, $f8
/* CDC68 80137568 241300F0 */  addiu     $s3, $zero, 0xf0
/* CDC6C 8013756C 02721023 */  subu      $v0, $s3, $s2
/* CDC70 80137570 44054000 */  mfc1      $a1, $f8
/* CDC74 80137574 44824000 */  mtc1      $v0, $f8
/* CDC78 80137578 00000000 */  nop       
/* CDC7C 8013757C 46804220 */  cvt.s.w   $f8, $f8
/* CDC80 80137580 3C15DA38 */  lui       $s5, 0xda38
/* CDC84 80137584 36B50002 */  ori       $s5, $s5, 2
/* CDC88 80137588 3C14DA38 */  lui       $s4, 0xda38
/* CDC8C 8013758C 36940001 */  ori       $s4, $s4, 1
/* CDC90 80137590 3C0BD838 */  lui       $t3, 0xd838
/* CDC94 80137594 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* CDC98 80137598 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* CDC9C 8013759C 356B0002 */  ori       $t3, $t3, 2
/* CDCA0 801375A0 44064000 */  mfc1      $a2, $f8
/* CDCA4 801375A4 8E420000 */  lw        $v0, ($s2)
/* CDCA8 801375A8 4480B000 */  mtc1      $zero, $f22
/* CDCAC 801375AC 3C118007 */  lui       $s1, %hi(D_800741F0)
/* CDCB0 801375B0 263141F0 */  addiu     $s1, $s1, %lo(D_800741F0)
/* CDCB4 801375B4 AFAB0024 */  sw        $t3, 0x24($sp)
/* CDCB8 801375B8 96240000 */  lhu       $a0, ($s1)
/* CDCBC 801375BC 0040182D */  daddu     $v1, $v0, $zero
/* CDCC0 801375C0 24420008 */  addiu     $v0, $v0, 8
/* CDCC4 801375C4 00042180 */  sll       $a0, $a0, 6
/* CDCC8 801375C8 03C42021 */  addu      $a0, $fp, $a0
/* CDCCC 801375CC 4407B000 */  mfc1      $a3, $f22
/* CDCD0 801375D0 3C0BFA00 */  lui       $t3, 0xfa00
/* CDCD4 801375D4 AE420000 */  sw        $v0, ($s2)
/* CDCD8 801375D8 AC6B0000 */  sw        $t3, ($v1)
/* CDCDC 801375DC 4600C20D */  trunc.w.s $f8, $f24
/* CDCE0 801375E0 44104000 */  mfc1      $s0, $f8
/* CDCE4 801375E4 0C019E08 */  jal       guTranslate
/* CDCE8 801375E8 AC600004 */   sw       $zero, 4($v1)
/* CDCEC 801375EC 00108400 */  sll       $s0, $s0, 0x10
/* CDCF0 801375F0 00108403 */  sra       $s0, $s0, 0x10
/* CDCF4 801375F4 4490A000 */  mtc1      $s0, $f20
/* CDCF8 801375F8 00000000 */  nop       
/* CDCFC 801375FC 4680A520 */  cvt.s.w   $f20, $f20
/* CDD00 80137600 3C013F80 */  lui       $at, 0x3f80
/* CDD04 80137604 4481C000 */  mtc1      $at, $f24
/* CDD08 80137608 8E420000 */  lw        $v0, ($s2)
/* CDD0C 8013760C 3C01437F */  lui       $at, 0x437f
/* CDD10 80137610 44810000 */  mtc1      $at, $f0
/* CDD14 80137614 0040202D */  daddu     $a0, $v0, $zero
/* CDD18 80137618 4600A503 */  div.s     $f20, $f20, $f0
/* CDD1C 8013761C 3C018015 */  lui       $at, %hi(D_80150EE0)
/* CDD20 80137620 D4200EE0 */  ldc1      $f0, %lo(D_80150EE0)($at)
/* CDD24 80137624 24420008 */  addiu     $v0, $v0, 8
/* CDD28 80137628 AE420000 */  sw        $v0, ($s2)
/* CDD2C 8013762C 96220000 */  lhu       $v0, ($s1)
/* CDD30 80137630 4614C501 */  sub.s     $f20, $f24, $f20
/* CDD34 80137634 AC950000 */  sw        $s5, ($a0)
/* CDD38 80137638 24430001 */  addiu     $v1, $v0, 1
/* CDD3C 8013763C 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDD40 80137640 4600A521 */  cvt.d.s   $f20, $f20
/* CDD44 80137644 4620A502 */  mul.d     $f20, $f20, $f0
/* CDD48 80137648 00000000 */  nop       
/* CDD4C 8013764C 00021180 */  sll       $v0, $v0, 6
/* CDD50 80137650 03C21021 */  addu      $v0, $fp, $v0
/* CDD54 80137654 A6230000 */  sh        $v1, ($s1)
/* CDD58 80137658 AC820004 */  sw        $v0, 4($a0)
/* CDD5C 8013765C 96240000 */  lhu       $a0, ($s1)
/* CDD60 80137660 4407C000 */  mfc1      $a3, $f24
/* CDD64 80137664 00042180 */  sll       $a0, $a0, 6
/* CDD68 80137668 4620A520 */  cvt.s.d   $f20, $f20
/* CDD6C 8013766C 4405A000 */  mfc1      $a1, $f20
/* CDD70 80137670 4406A000 */  mfc1      $a2, $f20
/* CDD74 80137674 0C019DC0 */  jal       guScale
/* CDD78 80137678 03C42021 */   addu     $a0, $fp, $a0
/* CDD7C 8013767C 00108023 */  negu      $s0, $s0
/* CDD80 80137680 4490D000 */  mtc1      $s0, $f26
/* CDD84 80137684 00000000 */  nop       
/* CDD88 80137688 4680D6A0 */  cvt.s.w   $f26, $f26
/* CDD8C 8013768C 8E430000 */  lw        $v1, ($s2)
/* CDD90 80137690 4405D000 */  mfc1      $a1, $f26
/* CDD94 80137694 4406B000 */  mfc1      $a2, $f22
/* CDD98 80137698 4407B000 */  mfc1      $a3, $f22
/* CDD9C 8013769C 96220000 */  lhu       $v0, ($s1)
/* CDDA0 801376A0 0060402D */  daddu     $t0, $v1, $zero
/* CDDA4 801376A4 24630008 */  addiu     $v1, $v1, 8
/* CDDA8 801376A8 AE430000 */  sw        $v1, ($s2)
/* CDDAC 801376AC 24430001 */  addiu     $v1, $v0, 1
/* CDDB0 801376B0 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDDB4 801376B4 00021180 */  sll       $v0, $v0, 6
/* CDDB8 801376B8 AD140000 */  sw        $s4, ($t0)
/* CDDBC 801376BC A6230000 */  sh        $v1, ($s1)
/* CDDC0 801376C0 3064FFFF */  andi      $a0, $v1, 0xffff
/* CDDC4 801376C4 03C21021 */  addu      $v0, $fp, $v0
/* CDDC8 801376C8 00042180 */  sll       $a0, $a0, 6
/* CDDCC 801376CC 03C42021 */  addu      $a0, $fp, $a0
/* CDDD0 801376D0 AD020004 */  sw        $v0, 4($t0)
/* CDDD4 801376D4 0C019F20 */  jal       guRotate
/* CDDD8 801376D8 E7B80010 */   swc1     $f24, 0x10($sp)
/* CDDDC 801376DC 44964000 */  mtc1      $s6, $f8
/* CDDE0 801376E0 00000000 */  nop       
/* CDDE4 801376E4 46804220 */  cvt.s.w   $f8, $f8
/* CDDE8 801376E8 02779823 */  subu      $s3, $s3, $s7
/* CDDEC 801376EC 44054000 */  mfc1      $a1, $f8
/* CDDF0 801376F0 44934000 */  mtc1      $s3, $f8
/* CDDF4 801376F4 00000000 */  nop       
/* CDDF8 801376F8 46804220 */  cvt.s.w   $f8, $f8
/* CDDFC 801376FC 3C16DE00 */  lui       $s6, 0xde00
/* CDE00 80137700 3C138015 */  lui       $s3, %hi(D_8014E8F0)
/* CDE04 80137704 2673E8F0 */  addiu     $s3, $s3, %lo(D_8014E8F0)
/* CDE08 80137708 44064000 */  mfc1      $a2, $f8
/* CDE0C 8013770C 8E480000 */  lw        $t0, ($s2)
/* CDE10 80137710 4407B000 */  mfc1      $a3, $f22
/* CDE14 80137714 96220000 */  lhu       $v0, ($s1)
/* CDE18 80137718 0100202D */  daddu     $a0, $t0, $zero
/* CDE1C 8013771C 25080008 */  addiu     $t0, $t0, 8
/* CDE20 80137720 24430001 */  addiu     $v1, $v0, 1
/* CDE24 80137724 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDE28 80137728 00021180 */  sll       $v0, $v0, 6
/* CDE2C 8013772C 03C21021 */  addu      $v0, $fp, $v0
/* CDE30 80137730 AE480000 */  sw        $t0, ($s2)
/* CDE34 80137734 AC940000 */  sw        $s4, ($a0)
/* CDE38 80137738 A6230000 */  sh        $v1, ($s1)
/* CDE3C 8013773C AC820004 */  sw        $v0, 4($a0)
/* CDE40 80137740 25020008 */  addiu     $v0, $t0, 8
/* CDE44 80137744 AE420000 */  sw        $v0, ($s2)
/* CDE48 80137748 25020010 */  addiu     $v0, $t0, 0x10
/* CDE4C 8013774C AD160000 */  sw        $s6, ($t0)
/* CDE50 80137750 AD130004 */  sw        $s3, 4($t0)
/* CDE54 80137754 AE420000 */  sw        $v0, ($s2)
/* CDE58 80137758 8FAB0024 */  lw        $t3, 0x24($sp)
/* CDE5C 8013775C AD0B0008 */  sw        $t3, 8($t0)
/* CDE60 80137760 96240000 */  lhu       $a0, ($s1)
/* CDE64 80137764 24100040 */  addiu     $s0, $zero, 0x40
/* CDE68 80137768 AD10000C */  sw        $s0, 0xc($t0)
/* CDE6C 8013776C 00042180 */  sll       $a0, $a0, 6
/* CDE70 80137770 0C019E08 */  jal       guTranslate
/* CDE74 80137774 03C42021 */   addu     $a0, $fp, $a0
/* CDE78 80137778 8E430000 */  lw        $v1, ($s2)
/* CDE7C 8013777C 4405A000 */  mfc1      $a1, $f20
/* CDE80 80137780 4407C000 */  mfc1      $a3, $f24
/* CDE84 80137784 96220000 */  lhu       $v0, ($s1)
/* CDE88 80137788 00A0302D */  daddu     $a2, $a1, $zero
/* CDE8C 8013778C 0060402D */  daddu     $t0, $v1, $zero
/* CDE90 80137790 24630008 */  addiu     $v1, $v1, 8
/* CDE94 80137794 AE430000 */  sw        $v1, ($s2)
/* CDE98 80137798 24430001 */  addiu     $v1, $v0, 1
/* CDE9C 8013779C 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDEA0 801377A0 00021180 */  sll       $v0, $v0, 6
/* CDEA4 801377A4 AD150000 */  sw        $s5, ($t0)
/* CDEA8 801377A8 A6230000 */  sh        $v1, ($s1)
/* CDEAC 801377AC 3064FFFF */  andi      $a0, $v1, 0xffff
/* CDEB0 801377B0 03C21021 */  addu      $v0, $fp, $v0
/* CDEB4 801377B4 00042180 */  sll       $a0, $a0, 6
/* CDEB8 801377B8 03C42021 */  addu      $a0, $fp, $a0
/* CDEBC 801377BC 0C019DC0 */  jal       guScale
/* CDEC0 801377C0 AD020004 */   sw       $v0, 4($t0)
/* CDEC4 801377C4 8E430000 */  lw        $v1, ($s2)
/* CDEC8 801377C8 4405D000 */  mfc1      $a1, $f26
/* CDECC 801377CC 4406B000 */  mfc1      $a2, $f22
/* CDED0 801377D0 4407B000 */  mfc1      $a3, $f22
/* CDED4 801377D4 96220000 */  lhu       $v0, ($s1)
/* CDED8 801377D8 0060402D */  daddu     $t0, $v1, $zero
/* CDEDC 801377DC 24630008 */  addiu     $v1, $v1, 8
/* CDEE0 801377E0 AE430000 */  sw        $v1, ($s2)
/* CDEE4 801377E4 24430001 */  addiu     $v1, $v0, 1
/* CDEE8 801377E8 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDEEC 801377EC 00021180 */  sll       $v0, $v0, 6
/* CDEF0 801377F0 AD140000 */  sw        $s4, ($t0)
/* CDEF4 801377F4 A6230000 */  sh        $v1, ($s1)
/* CDEF8 801377F8 3064FFFF */  andi      $a0, $v1, 0xffff
/* CDEFC 801377FC 03C21021 */  addu      $v0, $fp, $v0
/* CDF00 80137800 00042180 */  sll       $a0, $a0, 6
/* CDF04 80137804 03C42021 */  addu      $a0, $fp, $a0
/* CDF08 80137808 AD020004 */  sw        $v0, 4($t0)
/* CDF0C 8013780C 0C019F20 */  jal       guRotate
/* CDF10 80137810 E7B80010 */   swc1     $f24, 0x10($sp)
/* CDF14 80137814 8E480000 */  lw        $t0, ($s2)
/* CDF18 80137818 4405B000 */  mfc1      $a1, $f22
/* CDF1C 8013781C 96220000 */  lhu       $v0, ($s1)
/* CDF20 80137820 00A0302D */  daddu     $a2, $a1, $zero
/* CDF24 80137824 00A0382D */  daddu     $a3, $a1, $zero
/* CDF28 80137828 0100202D */  daddu     $a0, $t0, $zero
/* CDF2C 8013782C 25080008 */  addiu     $t0, $t0, 8
/* CDF30 80137830 24430001 */  addiu     $v1, $v0, 1
/* CDF34 80137834 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDF38 80137838 00021180 */  sll       $v0, $v0, 6
/* CDF3C 8013783C 03C21021 */  addu      $v0, $fp, $v0
/* CDF40 80137840 AE480000 */  sw        $t0, ($s2)
/* CDF44 80137844 AC940000 */  sw        $s4, ($a0)
/* CDF48 80137848 A6230000 */  sh        $v1, ($s1)
/* CDF4C 8013784C AC820004 */  sw        $v0, 4($a0)
/* CDF50 80137850 25020008 */  addiu     $v0, $t0, 8
/* CDF54 80137854 AE420000 */  sw        $v0, ($s2)
/* CDF58 80137858 AD160000 */  sw        $s6, ($t0)
/* CDF5C 8013785C AD130004 */  sw        $s3, 4($t0)
/* CDF60 80137860 96240000 */  lhu       $a0, ($s1)
/* CDF64 80137864 25020010 */  addiu     $v0, $t0, 0x10
/* CDF68 80137868 AE420000 */  sw        $v0, ($s2)
/* CDF6C 8013786C 8FAB0024 */  lw        $t3, 0x24($sp)
/* CDF70 80137870 00042180 */  sll       $a0, $a0, 6
/* CDF74 80137874 03C42021 */  addu      $a0, $fp, $a0
/* CDF78 80137878 AD0B0008 */  sw        $t3, 8($t0)
/* CDF7C 8013787C 0C019E08 */  jal       guTranslate
/* CDF80 80137880 AD10000C */   sw       $s0, 0xc($t0)
/* CDF84 80137884 8E440000 */  lw        $a0, ($s2)
/* CDF88 80137888 3C014F00 */  lui       $at, 0x4f00
/* CDF8C 8013788C 44810000 */  mtc1      $at, $f0
/* CDF90 80137890 96220000 */  lhu       $v0, ($s1)
/* CDF94 80137894 0080282D */  daddu     $a1, $a0, $zero
/* CDF98 80137898 24840008 */  addiu     $a0, $a0, 8
/* CDF9C 8013789C 24430001 */  addiu     $v1, $v0, 1
/* CDFA0 801378A0 3042FFFF */  andi      $v0, $v0, 0xffff
/* CDFA4 801378A4 00021180 */  sll       $v0, $v0, 6
/* CDFA8 801378A8 03C21021 */  addu      $v0, $fp, $v0
/* CDFAC 801378AC AE440000 */  sw        $a0, ($s2)
/* CDFB0 801378B0 ACB50000 */  sw        $s5, ($a1)
/* CDFB4 801378B4 A6230000 */  sh        $v1, ($s1)
/* CDFB8 801378B8 ACA20004 */  sw        $v0, 4($a1)
/* CDFBC 801378BC 24820008 */  addiu     $v0, $a0, 8
/* CDFC0 801378C0 3C0BFA00 */  lui       $t3, 0xfa00
/* CDFC4 801378C4 24850004 */  addiu     $a1, $a0, 4
/* CDFC8 801378C8 461C003E */  c.le.s    $f0, $f28
/* CDFCC 801378CC AE420000 */  sw        $v0, ($s2)
/* CDFD0 801378D0 45010005 */  bc1t      .L801378E8
/* CDFD4 801378D4 AC8B0000 */   sw       $t3, ($a0)
/* CDFD8 801378D8 4600E20D */  trunc.w.s $f8, $f28
/* CDFDC 801378DC 44074000 */  mfc1      $a3, $f8
/* CDFE0 801378E0 0804DE41 */  j         .L80137904
/* CDFE4 801378E4 3C06D838 */   lui      $a2, 0xd838
.L801378E8:
/* CDFE8 801378E8 4600E001 */  sub.s     $f0, $f28, $f0
/* CDFEC 801378EC 3C028000 */  lui       $v0, 0x8000
/* CDFF0 801378F0 4600020D */  trunc.w.s $f8, $f0
/* CDFF4 801378F4 44074000 */  mfc1      $a3, $f8
/* CDFF8 801378F8 00000000 */  nop       
/* CDFFC 801378FC 00E23825 */  or        $a3, $a3, $v0
/* CE000 80137900 3C06D838 */  lui       $a2, 0xd838
.L80137904:
/* CE004 80137904 34C60002 */  ori       $a2, $a2, 2
/* CE008 80137908 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CE00C 8013790C 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CE010 80137910 8C830000 */  lw        $v1, ($a0)
/* CE014 80137914 30E200FF */  andi      $v0, $a3, 0xff
/* CE018 80137918 ACA20000 */  sw        $v0, ($a1)
/* CE01C 8013791C 3C02DE00 */  lui       $v0, 0xde00
/* CE020 80137920 0060282D */  daddu     $a1, $v1, $zero
/* CE024 80137924 24630008 */  addiu     $v1, $v1, 8
/* CE028 80137928 AC830000 */  sw        $v1, ($a0)
/* CE02C 8013792C ACA20000 */  sw        $v0, ($a1)
/* CE030 80137930 3C028015 */  lui       $v0, %hi(D_8014E9A8)
/* CE034 80137934 2442E9A8 */  addiu     $v0, $v0, %lo(D_8014E9A8)
/* CE038 80137938 ACA20004 */  sw        $v0, 4($a1)
/* CE03C 8013793C 24620008 */  addiu     $v0, $v1, 8
/* CE040 80137940 AC820000 */  sw        $v0, ($a0)
/* CE044 80137944 24020040 */  addiu     $v0, $zero, 0x40
/* CE048 80137948 AC660000 */  sw        $a2, ($v1)
/* CE04C 8013794C 0804DF40 */  j         .L80137D00
/* CE050 80137950 AC620004 */   sw       $v0, 4($v1)
/* CE054 80137954 44914000 */  mtc1      $s1, $f8
/* CE058 80137958 00000000 */  nop       
/* CE05C 8013795C 46804220 */  cvt.s.w   $f8, $f8
/* CE060 80137960 240200F0 */  addiu     $v0, $zero, 0xf0
/* CE064 80137964 00521023 */  subu      $v0, $v0, $s2
/* CE068 80137968 44054000 */  mfc1      $a1, $f8
/* CE06C 8013796C 44824000 */  mtc1      $v0, $f8
/* CE070 80137970 00000000 */  nop       
/* CE074 80137974 46804220 */  cvt.s.w   $f8, $f8
/* CE078 80137978 3C15DA38 */  lui       $s5, 0xda38
/* CE07C 8013797C 36B50002 */  ori       $s5, $s5, 2
/* CE080 80137980 3C13DA38 */  lui       $s3, 0xda38
/* CE084 80137984 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* CE088 80137988 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* CE08C 8013798C 36730001 */  ori       $s3, $s3, 1
/* CE090 80137990 3C118007 */  lui       $s1, %hi(D_800741F0)
/* CE094 80137994 263141F0 */  addiu     $s1, $s1, %lo(D_800741F0)
/* CE098 80137998 3C14FA00 */  lui       $s4, 0xfa00
/* CE09C 8013799C 44064000 */  mfc1      $a2, $f8
/* CE0A0 801379A0 4600C20D */  trunc.w.s $f8, $f24
/* CE0A4 801379A4 44104000 */  mfc1      $s0, $f8
/* CE0A8 801379A8 8E420000 */  lw        $v0, ($s2)
/* CE0AC 801379AC 4480B000 */  mtc1      $zero, $f22
/* CE0B0 801379B0 96240000 */  lhu       $a0, ($s1)
/* CE0B4 801379B4 0040182D */  daddu     $v1, $v0, $zero
/* CE0B8 801379B8 24420008 */  addiu     $v0, $v0, 8
/* CE0BC 801379BC 00042180 */  sll       $a0, $a0, 6
/* CE0C0 801379C0 4407B000 */  mfc1      $a3, $f22
/* CE0C4 801379C4 03C42021 */  addu      $a0, $fp, $a0
/* CE0C8 801379C8 AE420000 */  sw        $v0, ($s2)
/* CE0CC 801379CC AC740000 */  sw        $s4, ($v1)
/* CE0D0 801379D0 0C019E08 */  jal       guTranslate
/* CE0D4 801379D4 AC600004 */   sw       $zero, 4($v1)
/* CE0D8 801379D8 00108400 */  sll       $s0, $s0, 0x10
/* CE0DC 801379DC 00108403 */  sra       $s0, $s0, 0x10
/* CE0E0 801379E0 44900000 */  mtc1      $s0, $f0
/* CE0E4 801379E4 00000000 */  nop       
/* CE0E8 801379E8 46800020 */  cvt.s.w   $f0, $f0
/* CE0EC 801379EC 3C013F80 */  lui       $at, 0x3f80
/* CE0F0 801379F0 4481A000 */  mtc1      $at, $f20
/* CE0F4 801379F4 8E420000 */  lw        $v0, ($s2)
/* CE0F8 801379F8 3C01437F */  lui       $at, 0x437f
/* CE0FC 801379FC 44811000 */  mtc1      $at, $f2
/* CE100 80137A00 0040202D */  daddu     $a0, $v0, $zero
/* CE104 80137A04 46020003 */  div.s     $f0, $f0, $f2
/* CE108 80137A08 3C018015 */  lui       $at, %hi(D_80150EE8)
/* CE10C 80137A0C D4220EE8 */  ldc1      $f2, %lo(D_80150EE8)($at)
/* CE110 80137A10 24420008 */  addiu     $v0, $v0, 8
/* CE114 80137A14 AE420000 */  sw        $v0, ($s2)
/* CE118 80137A18 96220000 */  lhu       $v0, ($s1)
/* CE11C 80137A1C 4600A001 */  sub.s     $f0, $f20, $f0
/* CE120 80137A20 AC950000 */  sw        $s5, ($a0)
/* CE124 80137A24 24430001 */  addiu     $v1, $v0, 1
/* CE128 80137A28 3042FFFF */  andi      $v0, $v0, 0xffff
/* CE12C 80137A2C 46000021 */  cvt.d.s   $f0, $f0
/* CE130 80137A30 46220002 */  mul.d     $f0, $f0, $f2
/* CE134 80137A34 00000000 */  nop       
/* CE138 80137A38 00021180 */  sll       $v0, $v0, 6
/* CE13C 80137A3C 03C21021 */  addu      $v0, $fp, $v0
/* CE140 80137A40 A6230000 */  sh        $v1, ($s1)
/* CE144 80137A44 AC820004 */  sw        $v0, 4($a0)
/* CE148 80137A48 96240000 */  lhu       $a0, ($s1)
/* CE14C 80137A4C 4407A000 */  mfc1      $a3, $f20
/* CE150 80137A50 00042180 */  sll       $a0, $a0, 6
/* CE154 80137A54 46200020 */  cvt.s.d   $f0, $f0
/* CE158 80137A58 44050000 */  mfc1      $a1, $f0
/* CE15C 80137A5C 03C42021 */  addu      $a0, $fp, $a0
/* CE160 80137A60 0C019DC0 */  jal       guScale
/* CE164 80137A64 00A0302D */   daddu    $a2, $a1, $zero
/* CE168 80137A68 00108023 */  negu      $s0, $s0
/* CE16C 80137A6C 44900000 */  mtc1      $s0, $f0
/* CE170 80137A70 00000000 */  nop       
/* CE174 80137A74 46800020 */  cvt.s.w   $f0, $f0
/* CE178 80137A78 46000021 */  cvt.d.s   $f0, $f0
/* CE17C 80137A7C 8E420000 */  lw        $v0, ($s2)
/* CE180 80137A80 4406B000 */  mfc1      $a2, $f22
/* CE184 80137A84 4407B000 */  mfc1      $a3, $f22
/* CE188 80137A88 96230000 */  lhu       $v1, ($s1)
/* CE18C 80137A8C 3C013FE0 */  lui       $at, 0x3fe0
/* CE190 80137A90 44811800 */  mtc1      $at, $f3
/* CE194 80137A94 44801000 */  mtc1      $zero, $f2
/* CE198 80137A98 0040282D */  daddu     $a1, $v0, $zero
/* CE19C 80137A9C 24420008 */  addiu     $v0, $v0, 8
/* CE1A0 80137AA0 AE420000 */  sw        $v0, ($s2)
/* CE1A4 80137AA4 24620001 */  addiu     $v0, $v1, 1
/* CE1A8 80137AA8 3063FFFF */  andi      $v1, $v1, 0xffff
/* CE1AC 80137AAC 46220002 */  mul.d     $f0, $f0, $f2
/* CE1B0 80137AB0 00000000 */  nop       
/* CE1B4 80137AB4 00031980 */  sll       $v1, $v1, 6
/* CE1B8 80137AB8 ACB30000 */  sw        $s3, ($a1)
/* CE1BC 80137ABC A6220000 */  sh        $v0, ($s1)
/* CE1C0 80137AC0 3044FFFF */  andi      $a0, $v0, 0xffff
/* CE1C4 80137AC4 03C31821 */  addu      $v1, $fp, $v1
/* CE1C8 80137AC8 00042180 */  sll       $a0, $a0, 6
/* CE1CC 80137ACC ACA30004 */  sw        $v1, 4($a1)
/* CE1D0 80137AD0 46200020 */  cvt.s.d   $f0, $f0
/* CE1D4 80137AD4 44050000 */  mfc1      $a1, $f0
/* CE1D8 80137AD8 03C42021 */  addu      $a0, $fp, $a0
/* CE1DC 80137ADC 0C019F20 */  jal       guRotate
/* CE1E0 80137AE0 E7B40010 */   swc1     $f20, 0x10($sp)
/* CE1E4 80137AE4 3C09D838 */  lui       $t1, 0xd838
/* CE1E8 80137AE8 35290002 */  ori       $t1, $t1, 2
/* CE1EC 80137AEC 8E480000 */  lw        $t0, ($s2)
/* CE1F0 80137AF0 4405B000 */  mfc1      $a1, $f22
/* CE1F4 80137AF4 96220000 */  lhu       $v0, ($s1)
/* CE1F8 80137AF8 00A0302D */  daddu     $a2, $a1, $zero
/* CE1FC 80137AFC 00A0382D */  daddu     $a3, $a1, $zero
/* CE200 80137B00 0100202D */  daddu     $a0, $t0, $zero
/* CE204 80137B04 25080008 */  addiu     $t0, $t0, 8
/* CE208 80137B08 24430001 */  addiu     $v1, $v0, 1
/* CE20C 80137B0C 3042FFFF */  andi      $v0, $v0, 0xffff
/* CE210 80137B10 00021180 */  sll       $v0, $v0, 6
/* CE214 80137B14 03C21021 */  addu      $v0, $fp, $v0
/* CE218 80137B18 AE480000 */  sw        $t0, ($s2)
/* CE21C 80137B1C AC930000 */  sw        $s3, ($a0)
/* CE220 80137B20 A6230000 */  sh        $v1, ($s1)
/* CE224 80137B24 AC820004 */  sw        $v0, 4($a0)
/* CE228 80137B28 25020008 */  addiu     $v0, $t0, 8
/* CE22C 80137B2C AE420000 */  sw        $v0, ($s2)
/* CE230 80137B30 3C02DE00 */  lui       $v0, %hi(D_DDFFE8F0)
/* CE234 80137B34 AD020000 */  sw        $v0, ($t0)
/* CE238 80137B38 3C028015 */  lui       $v0, %hi(D_8014E8F0)
/* CE23C 80137B3C 2442E8F0 */  addiu     $v0, $v0, %lo(D_DDFFE8F0)
/* CE240 80137B40 AD020004 */  sw        $v0, 4($t0)
/* CE244 80137B44 25020010 */  addiu     $v0, $t0, 0x10
/* CE248 80137B48 AE420000 */  sw        $v0, ($s2)
/* CE24C 80137B4C AD090008 */  sw        $t1, 8($t0)
/* CE250 80137B50 96240000 */  lhu       $a0, ($s1)
/* CE254 80137B54 24020040 */  addiu     $v0, $zero, 0x40
/* CE258 80137B58 AD02000C */  sw        $v0, 0xc($t0)
/* CE25C 80137B5C 00042180 */  sll       $a0, $a0, 6
/* CE260 80137B60 0C019E08 */  jal       guTranslate
/* CE264 80137B64 03C42021 */   addu     $a0, $fp, $a0
/* CE268 80137B68 8E440000 */  lw        $a0, ($s2)
/* CE26C 80137B6C 3C014F00 */  lui       $at, 0x4f00
/* CE270 80137B70 44810000 */  mtc1      $at, $f0
/* CE274 80137B74 96220000 */  lhu       $v0, ($s1)
/* CE278 80137B78 0080282D */  daddu     $a1, $a0, $zero
/* CE27C 80137B7C 24840008 */  addiu     $a0, $a0, 8
/* CE280 80137B80 24430001 */  addiu     $v1, $v0, 1
/* CE284 80137B84 3042FFFF */  andi      $v0, $v0, 0xffff
/* CE288 80137B88 00021180 */  sll       $v0, $v0, 6
/* CE28C 80137B8C 03C21021 */  addu      $v0, $fp, $v0
/* CE290 80137B90 AE440000 */  sw        $a0, ($s2)
/* CE294 80137B94 ACB50000 */  sw        $s5, ($a1)
/* CE298 80137B98 A6230000 */  sh        $v1, ($s1)
/* CE29C 80137B9C ACA20004 */  sw        $v0, 4($a1)
/* CE2A0 80137BA0 24820008 */  addiu     $v0, $a0, 8
/* CE2A4 80137BA4 24850004 */  addiu     $a1, $a0, 4
/* CE2A8 80137BA8 461C003E */  c.le.s    $f0, $f28
/* CE2AC 80137BAC AE420000 */  sw        $v0, ($s2)
/* CE2B0 80137BB0 45010005 */  bc1t      .L80137BC8
/* CE2B4 80137BB4 AC940000 */   sw       $s4, ($a0)
/* CE2B8 80137BB8 4600E20D */  trunc.w.s $f8, $f28
/* CE2BC 80137BBC 44074000 */  mfc1      $a3, $f8
/* CE2C0 80137BC0 0804DEF9 */  j         .L80137BE4
/* CE2C4 80137BC4 3C06D838 */   lui      $a2, 0xd838
.L80137BC8:
/* CE2C8 80137BC8 4600E001 */  sub.s     $f0, $f28, $f0
/* CE2CC 80137BCC 3C028000 */  lui       $v0, 0x8000
/* CE2D0 80137BD0 4600020D */  trunc.w.s $f8, $f0
/* CE2D4 80137BD4 44074000 */  mfc1      $a3, $f8
/* CE2D8 80137BD8 00000000 */  nop       
/* CE2DC 80137BDC 00E23825 */  or        $a3, $a3, $v0
/* CE2E0 80137BE0 3C06D838 */  lui       $a2, 0xd838
.L80137BE4:
/* CE2E4 80137BE4 34C60002 */  ori       $a2, $a2, 2
/* CE2E8 80137BE8 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CE2EC 80137BEC 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CE2F0 80137BF0 8C830000 */  lw        $v1, ($a0)
/* CE2F4 80137BF4 30E200FF */  andi      $v0, $a3, 0xff
/* CE2F8 80137BF8 ACA20000 */  sw        $v0, ($a1)
/* CE2FC 80137BFC 3C02DE00 */  lui       $v0, 0xde00
/* CE300 80137C00 3C01432A */  lui       $at, 0x432a
/* CE304 80137C04 44810000 */  mtc1      $at, $f0
/* CE308 80137C08 0060282D */  daddu     $a1, $v1, $zero
/* CE30C 80137C0C 4618003C */  c.lt.s    $f0, $f24
/* CE310 80137C10 3C014220 */  lui       $at, 0x4220
/* CE314 80137C14 44810000 */  mtc1      $at, $f0
/* CE318 80137C18 24630008 */  addiu     $v1, $v1, 8
/* CE31C 80137C1C AC830000 */  sw        $v1, ($a0)
/* CE320 80137C20 ACA20000 */  sw        $v0, ($a1)
/* CE324 80137C24 3C028015 */  lui       $v0, %hi(D_8014E9A8)
/* CE328 80137C28 2442E9A8 */  addiu     $v0, $v0, %lo(D_8014E9A8)
/* CE32C 80137C2C ACA20004 */  sw        $v0, 4($a1)
/* CE330 80137C30 24620008 */  addiu     $v0, $v1, 8
/* CE334 80137C34 AC820000 */  sw        $v0, ($a0)
/* CE338 80137C38 24020040 */  addiu     $v0, $zero, 0x40
/* CE33C 80137C3C 4600C000 */  add.s     $f0, $f24, $f0
/* CE340 80137C40 AC660000 */  sw        $a2, ($v1)
/* CE344 80137C44 AC620004 */  sw        $v0, 4($v1)
/* CE348 80137C48 4600020D */  trunc.w.s $f8, $f0
/* CE34C 80137C4C 44024000 */  mfc1      $v0, $f8
/* CE350 80137C50 45030001 */  bc1tl     .L80137C58
/* CE354 80137C54 240200AA */   addiu    $v0, $zero, 0xaa
.L80137C58:
/* CE358 80137C58 00021400 */  sll       $v0, $v0, 0x10
/* CE35C 80137C5C 00021403 */  sra       $v0, $v0, 0x10
/* CE360 80137C60 44820000 */  mtc1      $v0, $f0
/* CE364 80137C64 00000000 */  nop       
/* CE368 80137C68 46800020 */  cvt.s.w   $f0, $f0
/* CE36C 80137C6C E7A00010 */  swc1      $f0, 0x10($sp)
/* CE370 80137C70 0000202D */  daddu     $a0, $zero, $zero
/* CE374 80137C74 0080282D */  daddu     $a1, $a0, $zero
/* CE378 80137C78 2406013F */  addiu     $a2, $zero, 0x13f
/* CE37C 80137C7C 0C04E362 */  jal       func_80138D88
/* CE380 80137C80 240700EF */   addiu    $a3, $zero, 0xef
/* CE384 80137C84 0804DF41 */  j         .L80137D04
/* CE388 80137C88 3C06DA38 */   lui      $a2, 0xda38
/* CE38C 80137C8C 24040001 */  addiu     $a0, $zero, 1
/* CE390 80137C90 02C0282D */  daddu     $a1, $s6, $zero
/* CE394 80137C94 0804DF32 */  j         .L80137CC8
/* CE398 80137C98 02E0302D */   daddu    $a2, $s7, $zero
/* CE39C 80137C9C E7B80010 */  swc1      $f24, 0x10($sp)
/* CE3A0 80137CA0 0220202D */  daddu     $a0, $s1, $zero
/* CE3A4 80137CA4 0240282D */  daddu     $a1, $s2, $zero
/* CE3A8 80137CA8 02C0302D */  daddu     $a2, $s6, $zero
/* CE3AC 80137CAC 0C04E362 */  jal       func_80138D88
/* CE3B0 80137CB0 02E0382D */   daddu    $a3, $s7, $zero
/* CE3B4 80137CB4 0804DF41 */  j         .L80137D04
/* CE3B8 80137CB8 3C06DA38 */   lui      $a2, 0xda38
/* CE3BC 80137CBC 0000202D */  daddu     $a0, $zero, $zero
/* CE3C0 80137CC0 0220282D */  daddu     $a1, $s1, $zero
/* CE3C4 80137CC4 0240302D */  daddu     $a2, $s2, $zero
.L80137CC8:
/* CE3C8 80137CC8 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* CE3CC 80137CCC 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* CE3D0 80137CD0 8C620000 */  lw        $v0, ($v1)
/* CE3D4 80137CD4 4407E000 */  mfc1      $a3, $f28
/* CE3D8 80137CD8 0040402D */  daddu     $t0, $v0, $zero
/* CE3DC 80137CDC 24420008 */  addiu     $v0, $v0, 8
/* CE3E0 80137CE0 AC620000 */  sw        $v0, ($v1)
/* CE3E4 80137CE4 3C02DE00 */  lui       $v0, %hi(D_DDFFE718)
/* CE3E8 80137CE8 AD020000 */  sw        $v0, ($t0)
/* CE3EC 80137CEC 3C028015 */  lui       $v0, %hi(D_8014E718)
/* CE3F0 80137CF0 2442E718 */  addiu     $v0, $v0, %lo(D_DDFFE718)
/* CE3F4 80137CF4 AD020004 */  sw        $v0, 4($t0)
/* CE3F8 80137CF8 0C04E395 */  jal       func_80138E54
/* CE3FC 80137CFC E7B80010 */   swc1     $f24, 0x10($sp)
.L80137D00:
/* CE400 80137D00 3C06DA38 */  lui       $a2, 0xda38
.L80137D04:
/* CE404 80137D04 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* CE408 80137D08 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* CE40C 80137D0C 34C60007 */  ori       $a2, $a2, 7
/* CE410 80137D10 8C820000 */  lw        $v0, ($a0)
/* CE414 80137D14 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CE418 80137D18 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CE41C 80137D1C 0040282D */  daddu     $a1, $v0, $zero
/* CE420 80137D20 24420008 */  addiu     $v0, $v0, 8
/* CE424 80137D24 00031980 */  sll       $v1, $v1, 6
/* CE428 80137D28 AC820000 */  sw        $v0, ($a0)
/* CE42C 80137D2C 3C02800A */  lui       $v0, %hi(D_8009A674)
/* CE430 80137D30 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* CE434 80137D34 24630030 */  addiu     $v1, $v1, 0x30
/* CE438 80137D38 ACA60000 */  sw        $a2, ($a1)
/* CE43C 80137D3C 00431021 */  addu      $v0, $v0, $v1
.L80137D40:
/* CE440 80137D40 ACA20004 */  sw        $v0, 4($a1)
.L80137D44:
/* CE444 80137D44 8FBF004C */  lw        $ra, 0x4c($sp)
/* CE448 80137D48 8FBE0048 */  lw        $fp, 0x48($sp)
/* CE44C 80137D4C 8FB70044 */  lw        $s7, 0x44($sp)
/* CE450 80137D50 8FB60040 */  lw        $s6, 0x40($sp)
/* CE454 80137D54 8FB5003C */  lw        $s5, 0x3c($sp)
/* CE458 80137D58 8FB40038 */  lw        $s4, 0x38($sp)
/* CE45C 80137D5C 8FB30034 */  lw        $s3, 0x34($sp)
/* CE460 80137D60 8FB20030 */  lw        $s2, 0x30($sp)
/* CE464 80137D64 8FB1002C */  lw        $s1, 0x2c($sp)
/* CE468 80137D68 8FB00028 */  lw        $s0, 0x28($sp)
/* CE46C 80137D6C D7BC0070 */  ldc1      $f28, 0x70($sp)
/* CE470 80137D70 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* CE474 80137D74 D7B80060 */  ldc1      $f24, 0x60($sp)
/* CE478 80137D78 D7B60058 */  ldc1      $f22, 0x58($sp)
/* CE47C 80137D7C D7B40050 */  ldc1      $f20, 0x50($sp)
/* CE480 80137D80 03E00008 */  jr        $ra
/* CE484 80137D84 27BD0078 */   addiu    $sp, $sp, 0x78
