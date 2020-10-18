.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD14C
/* 324A5C 802BD14C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 324A60 802BD150 AFB00018 */  sw        $s0, 0x18($sp)
/* 324A64 802BD154 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 324A68 802BD158 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 324A6C 802BD15C AFBF0028 */  sw        $ra, 0x28($sp)
/* 324A70 802BD160 AFB30024 */  sw        $s3, 0x24($sp)
/* 324A74 802BD164 AFB20020 */  sw        $s2, 0x20($sp)
/* 324A78 802BD168 AFB1001C */  sw        $s1, 0x1c($sp)
/* 324A7C 802BD16C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 324A80 802BD170 8C91014C */  lw        $s1, 0x14c($a0)
/* 324A84 802BD174 10A00009 */  beqz      $a1, .L802BD19C
/* 324A88 802BD178 0220202D */   daddu    $a0, $s1, $zero
/* 324A8C 802BD17C 0C03AE2A */  jal       enable_partner_walking
/* 324A90 802BD180 24050001 */   addiu    $a1, $zero, 1
/* 324A94 802BD184 3C04802C */  lui       $a0, 0x802c
/* 324A98 802BD188 8C84D58C */  lw        $a0, -0x2a74($a0)
/* 324A9C 802BD18C 0C00A580 */  jal       mem_clear
/* 324AA0 802BD190 2405001C */   addiu    $a1, $zero, 0x1c
/* 324AA4 802BD194 3C018011 */  lui       $at, 0x8011
/* 324AA8 802BD198 AC20C954 */  sw        $zero, -0x36ac($at)
.L802BD19C:
/* 324AAC 802BD19C 3C138011 */  lui       $s3, 0x8011
/* 324AB0 802BD1A0 2673C954 */  addiu     $s3, $s3, -0x36ac
/* 324AB4 802BD1A4 8E020308 */  lw        $v0, 0x308($s0)
/* 324AB8 802BD1A8 8E720000 */  lw        $s2, ($s3)
/* 324ABC 802BD1AC 24420001 */  addiu     $v0, $v0, 1
/* 324AC0 802BD1B0 16400007 */  bnez      $s2, .L802BD1D0
/* 324AC4 802BD1B4 AE020308 */   sw       $v0, 0x308($s0)
/* 324AC8 802BD1B8 0C03AE8F */  jal       func_800EBA3C
/* 324ACC 802BD1BC 0220202D */   daddu    $a0, $s1, $zero
/* 324AD0 802BD1C0 0C03AED0 */  jal       func_800EBB40
/* 324AD4 802BD1C4 0220202D */   daddu    $a0, $s1, $zero
/* 324AD8 802BD1C8 080AF530 */  j         .L802BD4C0
/* 324ADC 802BD1CC 0000102D */   daddu    $v0, $zero, $zero
.L802BD1D0:
/* 324AE0 802BD1D0 3C10802C */  lui       $s0, 0x802c
/* 324AE4 802BD1D4 2610D58C */  addiu     $s0, $s0, -0x2a74
/* 324AE8 802BD1D8 8E040000 */  lw        $a0, ($s0)
/* 324AEC 802BD1DC 8C830004 */  lw        $v1, 4($a0)
/* 324AF0 802BD1E0 24050001 */  addiu     $a1, $zero, 1
/* 324AF4 802BD1E4 10650030 */  beq       $v1, $a1, .L802BD2A8
/* 324AF8 802BD1E8 28620002 */   slti     $v0, $v1, 2
/* 324AFC 802BD1EC 10400005 */  beqz      $v0, .L802BD204
/* 324B00 802BD1F0 24020002 */   addiu    $v0, $zero, 2
/* 324B04 802BD1F4 10600009 */  beqz      $v1, .L802BD21C
/* 324B08 802BD1F8 0000102D */   daddu    $v0, $zero, $zero
/* 324B0C 802BD1FC 080AF530 */  j         .L802BD4C0
/* 324B10 802BD200 00000000 */   nop      
.L802BD204:
/* 324B14 802BD204 1062009A */  beq       $v1, $v0, .L802BD470
/* 324B18 802BD208 24020003 */   addiu    $v0, $zero, 3
/* 324B1C 802BD20C 106200A0 */  beq       $v1, $v0, .L802BD490
/* 324B20 802BD210 0000102D */   daddu    $v0, $zero, $zero
/* 324B24 802BD214 080AF530 */  j         .L802BD4C0
/* 324B28 802BD218 00000000 */   nop      
.L802BD21C:
/* 324B2C 802BD21C AC850004 */  sw        $a1, 4($a0)
/* 324B30 802BD220 8E220000 */  lw        $v0, ($s1)
/* 324B34 802BD224 AC820008 */  sw        $v0, 8($a0)
/* 324B38 802BD228 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 324B3C 802BD22C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 324B40 802BD230 8E460048 */  lw        $a2, 0x48($s2)
/* 324B44 802BD234 0C00A7B5 */  jal       dist2D
/* 324B48 802BD238 8E470050 */   lw       $a3, 0x50($s2)
/* 324B4C 802BD23C 8E020000 */  lw        $v0, ($s0)
/* 324B50 802BD240 46000005 */  abs.s     $f0, $f0
/* 324B54 802BD244 E440000C */  swc1      $f0, 0xc($v0)
/* 324B58 802BD248 C64C0048 */  lwc1      $f12, 0x48($s2)
/* 324B5C 802BD24C C64E0050 */  lwc1      $f14, 0x50($s2)
/* 324B60 802BD250 8E260038 */  lw        $a2, 0x38($s1)
/* 324B64 802BD254 0C00A720 */  jal       atan2
/* 324B68 802BD258 8E270040 */   lw       $a3, 0x40($s1)
/* 324B6C 802BD25C 3C040004 */  lui       $a0, 4
/* 324B70 802BD260 24020078 */  addiu     $v0, $zero, 0x78
/* 324B74 802BD264 8E030000 */  lw        $v1, ($s0)
/* 324B78 802BD268 3C0140C0 */  lui       $at, 0x40c0
/* 324B7C 802BD26C 44811000 */  mtc1      $at, $f2
/* 324B80 802BD270 3C014248 */  lui       $at, 0x4248
/* 324B84 802BD274 44812000 */  mtc1      $at, $f4
/* 324B88 802BD278 34840148 */  ori       $a0, $a0, 0x148
/* 324B8C 802BD27C E4600010 */  swc1      $f0, 0x10($v1)
/* 324B90 802BD280 E4620014 */  swc1      $f2, 0x14($v1)
/* 324B94 802BD284 E4640018 */  swc1      $f4, 0x18($v1)
/* 324B98 802BD288 AC620000 */  sw        $v0, ($v1)
/* 324B9C 802BD28C 8E220000 */  lw        $v0, ($s1)
/* 324BA0 802BD290 2403FDFF */  addiu     $v1, $zero, -0x201
/* 324BA4 802BD294 00441025 */  or        $v0, $v0, $a0
/* 324BA8 802BD298 00431024 */  and       $v0, $v0, $v1
/* 324BAC 802BD29C AE220000 */  sw        $v0, ($s1)
/* 324BB0 802BD2A0 3C10802C */  lui       $s0, 0x802c
/* 324BB4 802BD2A4 2610D58C */  addiu     $s0, $s0, -0x2a74
.L802BD2A8:
/* 324BB8 802BD2A8 8E020000 */  lw        $v0, ($s0)
/* 324BBC 802BD2AC 3C0140C9 */  lui       $at, 0x40c9
/* 324BC0 802BD2B0 34210FD0 */  ori       $at, $at, 0xfd0
/* 324BC4 802BD2B4 44810000 */  mtc1      $at, $f0
/* 324BC8 802BD2B8 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 324BCC 802BD2BC 46006302 */  mul.s     $f12, $f12, $f0
/* 324BD0 802BD2C0 00000000 */  nop       
/* 324BD4 802BD2C4 27A50010 */  addiu     $a1, $sp, 0x10
/* 324BD8 802BD2C8 3C0143B4 */  lui       $at, 0x43b4
/* 324BDC 802BD2CC 44810000 */  mtc1      $at, $f0
/* 324BE0 802BD2D0 27A60014 */  addiu     $a2, $sp, 0x14
/* 324BE4 802BD2D4 0C00A82D */  jal       sin_cos_rad
/* 324BE8 802BD2D8 46006303 */   div.s    $f12, $f12, $f0
/* 324BEC 802BD2DC 8E020000 */  lw        $v0, ($s0)
/* 324BF0 802BD2E0 C7A20010 */  lwc1      $f2, 0x10($sp)
/* 324BF4 802BD2E4 C440000C */  lwc1      $f0, 0xc($v0)
/* 324BF8 802BD2E8 46001082 */  mul.s     $f2, $f2, $f0
/* 324BFC 802BD2EC 00000000 */  nop       
/* 324C00 802BD2F0 C6400048 */  lwc1      $f0, 0x48($s2)
/* 324C04 802BD2F4 46020000 */  add.s     $f0, $f0, $f2
/* 324C08 802BD2F8 E6200038 */  swc1      $f0, 0x38($s1)
/* 324C0C 802BD2FC C7A20014 */  lwc1      $f2, 0x14($sp)
/* 324C10 802BD300 C440000C */  lwc1      $f0, 0xc($v0)
/* 324C14 802BD304 46001082 */  mul.s     $f2, $f2, $f0
/* 324C18 802BD308 00000000 */  nop       
/* 324C1C 802BD30C C6400050 */  lwc1      $f0, 0x50($s2)
/* 324C20 802BD310 46020001 */  sub.s     $f0, $f0, $f2
/* 324C24 802BD314 E6200040 */  swc1      $f0, 0x40($s1)
/* 324C28 802BD318 C4400010 */  lwc1      $f0, 0x10($v0)
/* 324C2C 802BD31C C44C0014 */  lwc1      $f12, 0x14($v0)
/* 324C30 802BD320 0C00A6C9 */  jal       clamp_angle
/* 324C34 802BD324 460C0301 */   sub.s    $f12, $f0, $f12
/* 324C38 802BD328 8E100000 */  lw        $s0, ($s0)
/* 324C3C 802BD32C 3C0141A0 */  lui       $at, 0x41a0
/* 324C40 802BD330 44811000 */  mtc1      $at, $f2
/* 324C44 802BD334 C604000C */  lwc1      $f4, 0xc($s0)
/* 324C48 802BD338 4604103C */  c.lt.s    $f2, $f4
/* 324C4C 802BD33C 00000000 */  nop       
/* 324C50 802BD340 45000005 */  bc1f      .L802BD358
/* 324C54 802BD344 E6000010 */   swc1     $f0, 0x10($s0)
/* 324C58 802BD348 3C013F80 */  lui       $at, 0x3f80
/* 324C5C 802BD34C 44810000 */  mtc1      $at, $f0
/* 324C60 802BD350 080AF4E1 */  j         .L802BD384
/* 324C64 802BD354 46002001 */   sub.s    $f0, $f4, $f0
.L802BD358:
/* 324C68 802BD358 3C014198 */  lui       $at, 0x4198
/* 324C6C 802BD35C 44810000 */  mtc1      $at, $f0
/* 324C70 802BD360 00000000 */  nop       
/* 324C74 802BD364 4600203C */  c.lt.s    $f4, $f0
/* 324C78 802BD368 00000000 */  nop       
/* 324C7C 802BD36C 45000006 */  bc1f      .L802BD388
/* 324C80 802BD370 00000000 */   nop      
/* 324C84 802BD374 3C013F80 */  lui       $at, 0x3f80
/* 324C88 802BD378 44810000 */  mtc1      $at, $f0
/* 324C8C 802BD37C 00000000 */  nop       
/* 324C90 802BD380 46002000 */  add.s     $f0, $f4, $f0
.L802BD384:
/* 324C94 802BD384 E600000C */  swc1      $f0, 0xc($s0)
.L802BD388:
/* 324C98 802BD388 3C10802C */  lui       $s0, 0x802c
/* 324C9C 802BD38C 2610D58C */  addiu     $s0, $s0, -0x2a74
/* 324CA0 802BD390 8E020000 */  lw        $v0, ($s0)
/* 324CA4 802BD394 3C0140C9 */  lui       $at, 0x40c9
/* 324CA8 802BD398 34210FD0 */  ori       $at, $at, 0xfd0
/* 324CAC 802BD39C 44810000 */  mtc1      $at, $f0
/* 324CB0 802BD3A0 C44C0018 */  lwc1      $f12, 0x18($v0)
/* 324CB4 802BD3A4 46006302 */  mul.s     $f12, $f12, $f0
/* 324CB8 802BD3A8 00000000 */  nop       
/* 324CBC 802BD3AC 3C0143B4 */  lui       $at, 0x43b4
/* 324CC0 802BD3B0 4481A000 */  mtc1      $at, $f20
/* 324CC4 802BD3B4 0C00A85B */  jal       sin_rad
/* 324CC8 802BD3B8 46146303 */   div.s    $f12, $f12, $f20
/* 324CCC 802BD3BC 8E020000 */  lw        $v0, ($s0)
/* 324CD0 802BD3C0 3C014040 */  lui       $at, 0x4040
/* 324CD4 802BD3C4 44812000 */  mtc1      $at, $f4
/* 324CD8 802BD3C8 C4420018 */  lwc1      $f2, 0x18($v0)
/* 324CDC 802BD3CC 46041080 */  add.s     $f2, $f2, $f4
/* 324CE0 802BD3D0 3C014316 */  lui       $at, 0x4316
/* 324CE4 802BD3D4 44813000 */  mtc1      $at, $f6
/* 324CE8 802BD3D8 00000000 */  nop       
/* 324CEC 802BD3DC 4602303C */  c.lt.s    $f6, $f2
/* 324CF0 802BD3E0 E4420018 */  swc1      $f2, 0x18($v0)
/* 324CF4 802BD3E4 46040082 */  mul.s     $f2, $f0, $f4
/* 324CF8 802BD3E8 00000000 */  nop       
/* 324CFC 802BD3EC 45030001 */  bc1tl     .L802BD3F4
/* 324D00 802BD3F0 E4460018 */   swc1     $f6, 0x18($v0)
.L802BD3F4:
/* 324D04 802BD3F4 C620003C */  lwc1      $f0, 0x3c($s1)
/* 324D08 802BD3F8 46020000 */  add.s     $f0, $f0, $f2
/* 324D0C 802BD3FC 8E020000 */  lw        $v0, ($s0)
/* 324D10 802BD400 E620003C */  swc1      $f0, 0x3c($s1)
/* 324D14 802BD404 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 324D18 802BD408 0C00A6C9 */  jal       clamp_angle
/* 324D1C 802BD40C 460CA301 */   sub.s    $f12, $f20, $f12
/* 324D20 802BD410 8E020000 */  lw        $v0, ($s0)
/* 324D24 802BD414 E6200034 */  swc1      $f0, 0x34($s1)
/* 324D28 802BD418 C4400014 */  lwc1      $f0, 0x14($v0)
/* 324D2C 802BD41C 3C01802C */  lui       $at, 0x802c
/* 324D30 802BD420 D422D5F0 */  ldc1      $f2, -0x2a10($at)
/* 324D34 802BD424 46000021 */  cvt.d.s   $f0, $f0
/* 324D38 802BD428 46220000 */  add.d     $f0, $f0, $f2
/* 324D3C 802BD42C 3C014220 */  lui       $at, 0x4220
/* 324D40 802BD430 44811000 */  mtc1      $at, $f2
/* 324D44 802BD434 46200020 */  cvt.s.d   $f0, $f0
/* 324D48 802BD438 4600103C */  c.lt.s    $f2, $f0
/* 324D4C 802BD43C 00000000 */  nop       
/* 324D50 802BD440 45000002 */  bc1f      .L802BD44C
/* 324D54 802BD444 E4400014 */   swc1     $f0, 0x14($v0)
/* 324D58 802BD448 E4420014 */  swc1      $f2, 0x14($v0)
.L802BD44C:
/* 324D5C 802BD44C 8E030000 */  lw        $v1, ($s0)
/* 324D60 802BD450 8C620000 */  lw        $v0, ($v1)
/* 324D64 802BD454 2442FFFF */  addiu     $v0, $v0, -1
/* 324D68 802BD458 14400018 */  bnez      $v0, .L802BD4BC
/* 324D6C 802BD45C AC620000 */   sw       $v0, ($v1)
/* 324D70 802BD460 8C620004 */  lw        $v0, 4($v1)
/* 324D74 802BD464 24420001 */  addiu     $v0, $v0, 1
/* 324D78 802BD468 080AF52F */  j         .L802BD4BC
/* 324D7C 802BD46C AC620004 */   sw       $v0, 4($v1)
.L802BD470:
/* 324D80 802BD470 8C820008 */  lw        $v0, 8($a0)
/* 324D84 802BD474 AE220000 */  sw        $v0, ($s1)
/* 324D88 802BD478 8C820004 */  lw        $v0, 4($a0)
/* 324D8C 802BD47C 2403001E */  addiu     $v1, $zero, 0x1e
/* 324D90 802BD480 AC830000 */  sw        $v1, ($a0)
/* 324D94 802BD484 24420001 */  addiu     $v0, $v0, 1
/* 324D98 802BD488 080AF52F */  j         .L802BD4BC
/* 324D9C 802BD48C AC820004 */   sw       $v0, 4($a0)
.L802BD490:
/* 324DA0 802BD490 0C03AE8F */  jal       func_800EBA3C
/* 324DA4 802BD494 0220202D */   daddu    $a0, $s1, $zero
/* 324DA8 802BD498 0C03AED0 */  jal       func_800EBB40
/* 324DAC 802BD49C 0220202D */   daddu    $a0, $s1, $zero
/* 324DB0 802BD4A0 8E030000 */  lw        $v1, ($s0)
/* 324DB4 802BD4A4 8C620000 */  lw        $v0, ($v1)
/* 324DB8 802BD4A8 2442FFFF */  addiu     $v0, $v0, -1
/* 324DBC 802BD4AC 14400003 */  bnez      $v0, .L802BD4BC
/* 324DC0 802BD4B0 AC620000 */   sw       $v0, ($v1)
/* 324DC4 802BD4B4 AC600004 */  sw        $zero, 4($v1)
/* 324DC8 802BD4B8 AE600000 */  sw        $zero, ($s3)
.L802BD4BC:
/* 324DCC 802BD4BC 0000102D */  daddu     $v0, $zero, $zero
.L802BD4C0:
/* 324DD0 802BD4C0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 324DD4 802BD4C4 8FB30024 */  lw        $s3, 0x24($sp)
/* 324DD8 802BD4C8 8FB20020 */  lw        $s2, 0x20($sp)
/* 324DDC 802BD4CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 324DE0 802BD4D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 324DE4 802BD4D4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 324DE8 802BD4D8 03E00008 */  jr        $ra
/* 324DEC 802BD4DC 27BD0038 */   addiu    $sp, $sp, 0x38
