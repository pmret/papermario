.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD168_323AB8
/* 323AB8 802BD168 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 323ABC 802BD16C AFB00018 */  sw        $s0, 0x18($sp)
/* 323AC0 802BD170 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 323AC4 802BD174 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 323AC8 802BD178 AFBF0028 */  sw        $ra, 0x28($sp)
/* 323ACC 802BD17C AFB30024 */  sw        $s3, 0x24($sp)
/* 323AD0 802BD180 AFB20020 */  sw        $s2, 0x20($sp)
/* 323AD4 802BD184 AFB1001C */  sw        $s1, 0x1c($sp)
/* 323AD8 802BD188 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 323ADC 802BD18C 8C91014C */  lw        $s1, 0x14c($a0)
/* 323AE0 802BD190 10A00009 */  beqz      $a1, .L802BD1B8
/* 323AE4 802BD194 0220202D */   daddu    $a0, $s1, $zero
/* 323AE8 802BD198 0C03B4C4 */  jal       enable_partner_flying
/* 323AEC 802BD19C 24050001 */   addiu    $a1, $zero, 1
/* 323AF0 802BD1A0 3C04802C */  lui       $a0, %hi(D_802BDFFC)
/* 323AF4 802BD1A4 8C84DFFC */  lw        $a0, %lo(D_802BDFFC)($a0)
/* 323AF8 802BD1A8 0C00A580 */  jal       mem_clear
/* 323AFC 802BD1AC 2405001C */   addiu    $a1, $zero, 0x1c
/* 323B00 802BD1B0 3C018011 */  lui       $at, %hi(D_8010C954)
/* 323B04 802BD1B4 AC20C954 */  sw        $zero, %lo(D_8010C954)($at)
.L802BD1B8:
/* 323B08 802BD1B8 3C138011 */  lui       $s3, %hi(D_8010C954)
/* 323B0C 802BD1BC 2673C954 */  addiu     $s3, $s3, %lo(D_8010C954)
/* 323B10 802BD1C0 8E020318 */  lw        $v0, 0x318($s0)
/* 323B14 802BD1C4 8E720000 */  lw        $s2, ($s3)
/* 323B18 802BD1C8 24420001 */  addiu     $v0, $v0, 1
/* 323B1C 802BD1CC 16400007 */  bnez      $s2, .L802BD1EC
/* 323B20 802BD1D0 AE020318 */   sw       $v0, 0x318($s0)
/* 323B24 802BD1D4 0C03B52E */  jal       update_player_move_history
/* 323B28 802BD1D8 0220202D */   daddu    $a0, $s1, $zero
/* 323B2C 802BD1DC 0C03B574 */  jal       func_800ED5D0
/* 323B30 802BD1E0 0220202D */   daddu    $a0, $s1, $zero
/* 323B34 802BD1E4 080AF537 */  j         .L802BD4DC
/* 323B38 802BD1E8 0000102D */   daddu    $v0, $zero, $zero
.L802BD1EC:
/* 323B3C 802BD1EC 3C10802C */  lui       $s0, %hi(D_802BDFFC)
/* 323B40 802BD1F0 2610DFFC */  addiu     $s0, $s0, %lo(D_802BDFFC)
/* 323B44 802BD1F4 8E040000 */  lw        $a0, ($s0)
/* 323B48 802BD1F8 8C830004 */  lw        $v1, 4($a0)
/* 323B4C 802BD1FC 24050001 */  addiu     $a1, $zero, 1
/* 323B50 802BD200 10650030 */  beq       $v1, $a1, .L802BD2C4
/* 323B54 802BD204 28620002 */   slti     $v0, $v1, 2
/* 323B58 802BD208 10400005 */  beqz      $v0, .L802BD220
/* 323B5C 802BD20C 24020002 */   addiu    $v0, $zero, 2
/* 323B60 802BD210 10600009 */  beqz      $v1, .L802BD238
/* 323B64 802BD214 0000102D */   daddu    $v0, $zero, $zero
/* 323B68 802BD218 080AF537 */  j         .L802BD4DC
/* 323B6C 802BD21C 00000000 */   nop
.L802BD220:
/* 323B70 802BD220 1062009A */  beq       $v1, $v0, .L802BD48C
/* 323B74 802BD224 24020003 */   addiu    $v0, $zero, 3
/* 323B78 802BD228 106200A0 */  beq       $v1, $v0, .L802BD4AC
/* 323B7C 802BD22C 0000102D */   daddu    $v0, $zero, $zero
/* 323B80 802BD230 080AF537 */  j         .L802BD4DC
/* 323B84 802BD234 00000000 */   nop
.L802BD238:
/* 323B88 802BD238 AC850004 */  sw        $a1, 4($a0)
/* 323B8C 802BD23C 8E220000 */  lw        $v0, ($s1)
/* 323B90 802BD240 AC820008 */  sw        $v0, 8($a0)
/* 323B94 802BD244 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 323B98 802BD248 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 323B9C 802BD24C 8E460048 */  lw        $a2, 0x48($s2)
/* 323BA0 802BD250 0C00A7B5 */  jal       dist2D
/* 323BA4 802BD254 8E470050 */   lw       $a3, 0x50($s2)
/* 323BA8 802BD258 8E020000 */  lw        $v0, ($s0)
/* 323BAC 802BD25C 46000005 */  abs.s     $f0, $f0
/* 323BB0 802BD260 E440000C */  swc1      $f0, 0xc($v0)
/* 323BB4 802BD264 C64C0048 */  lwc1      $f12, 0x48($s2)
/* 323BB8 802BD268 C64E0050 */  lwc1      $f14, 0x50($s2)
/* 323BBC 802BD26C 8E260038 */  lw        $a2, 0x38($s1)
/* 323BC0 802BD270 0C00A720 */  jal       atan2
/* 323BC4 802BD274 8E270040 */   lw       $a3, 0x40($s1)
/* 323BC8 802BD278 3C040004 */  lui       $a0, 4
/* 323BCC 802BD27C 24020078 */  addiu     $v0, $zero, 0x78
/* 323BD0 802BD280 8E030000 */  lw        $v1, ($s0)
/* 323BD4 802BD284 3C0140C0 */  lui       $at, 0x40c0
/* 323BD8 802BD288 44811000 */  mtc1      $at, $f2
/* 323BDC 802BD28C 3C014248 */  lui       $at, 0x4248
/* 323BE0 802BD290 44812000 */  mtc1      $at, $f4
/* 323BE4 802BD294 34840148 */  ori       $a0, $a0, 0x148
/* 323BE8 802BD298 E4600010 */  swc1      $f0, 0x10($v1)
/* 323BEC 802BD29C E4620014 */  swc1      $f2, 0x14($v1)
/* 323BF0 802BD2A0 E4640018 */  swc1      $f4, 0x18($v1)
/* 323BF4 802BD2A4 AC620000 */  sw        $v0, ($v1)
/* 323BF8 802BD2A8 8E220000 */  lw        $v0, ($s1)
/* 323BFC 802BD2AC 2403FDFF */  addiu     $v1, $zero, -0x201
/* 323C00 802BD2B0 00441025 */  or        $v0, $v0, $a0
/* 323C04 802BD2B4 00431024 */  and       $v0, $v0, $v1
/* 323C08 802BD2B8 AE220000 */  sw        $v0, ($s1)
/* 323C0C 802BD2BC 3C10802C */  lui       $s0, %hi(D_802BDFFC)
/* 323C10 802BD2C0 2610DFFC */  addiu     $s0, $s0, %lo(D_802BDFFC)
.L802BD2C4:
/* 323C14 802BD2C4 8E020000 */  lw        $v0, ($s0)
/* 323C18 802BD2C8 3C0140C9 */  lui       $at, 0x40c9
/* 323C1C 802BD2CC 34210FD0 */  ori       $at, $at, 0xfd0
/* 323C20 802BD2D0 44810000 */  mtc1      $at, $f0
/* 323C24 802BD2D4 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 323C28 802BD2D8 46006302 */  mul.s     $f12, $f12, $f0
/* 323C2C 802BD2DC 00000000 */  nop
/* 323C30 802BD2E0 27A50010 */  addiu     $a1, $sp, 0x10
/* 323C34 802BD2E4 3C0143B4 */  lui       $at, 0x43b4
/* 323C38 802BD2E8 44810000 */  mtc1      $at, $f0
/* 323C3C 802BD2EC 27A60014 */  addiu     $a2, $sp, 0x14
/* 323C40 802BD2F0 0C00A82D */  jal       sin_cos_rad
/* 323C44 802BD2F4 46006303 */   div.s    $f12, $f12, $f0
/* 323C48 802BD2F8 8E020000 */  lw        $v0, ($s0)
/* 323C4C 802BD2FC C7A20010 */  lwc1      $f2, 0x10($sp)
/* 323C50 802BD300 C440000C */  lwc1      $f0, 0xc($v0)
/* 323C54 802BD304 46001082 */  mul.s     $f2, $f2, $f0
/* 323C58 802BD308 00000000 */  nop
/* 323C5C 802BD30C C6400048 */  lwc1      $f0, 0x48($s2)
/* 323C60 802BD310 46020000 */  add.s     $f0, $f0, $f2
/* 323C64 802BD314 E6200038 */  swc1      $f0, 0x38($s1)
/* 323C68 802BD318 C7A20014 */  lwc1      $f2, 0x14($sp)
/* 323C6C 802BD31C C440000C */  lwc1      $f0, 0xc($v0)
/* 323C70 802BD320 46001082 */  mul.s     $f2, $f2, $f0
/* 323C74 802BD324 00000000 */  nop
/* 323C78 802BD328 C6400050 */  lwc1      $f0, 0x50($s2)
/* 323C7C 802BD32C 46020001 */  sub.s     $f0, $f0, $f2
/* 323C80 802BD330 E6200040 */  swc1      $f0, 0x40($s1)
/* 323C84 802BD334 C4400010 */  lwc1      $f0, 0x10($v0)
/* 323C88 802BD338 C44C0014 */  lwc1      $f12, 0x14($v0)
/* 323C8C 802BD33C 0C00A6C9 */  jal       clamp_angle
/* 323C90 802BD340 460C0301 */   sub.s    $f12, $f0, $f12
/* 323C94 802BD344 8E100000 */  lw        $s0, ($s0)
/* 323C98 802BD348 3C0141A0 */  lui       $at, 0x41a0
/* 323C9C 802BD34C 44811000 */  mtc1      $at, $f2
/* 323CA0 802BD350 C604000C */  lwc1      $f4, 0xc($s0)
/* 323CA4 802BD354 4604103C */  c.lt.s    $f2, $f4
/* 323CA8 802BD358 00000000 */  nop
/* 323CAC 802BD35C 45000005 */  bc1f      .L802BD374
/* 323CB0 802BD360 E6000010 */   swc1     $f0, 0x10($s0)
/* 323CB4 802BD364 3C013F80 */  lui       $at, 0x3f80
/* 323CB8 802BD368 44810000 */  mtc1      $at, $f0
/* 323CBC 802BD36C 080AF4E8 */  j         .L802BD3A0
/* 323CC0 802BD370 46002001 */   sub.s    $f0, $f4, $f0
.L802BD374:
/* 323CC4 802BD374 3C014198 */  lui       $at, 0x4198
/* 323CC8 802BD378 44810000 */  mtc1      $at, $f0
/* 323CCC 802BD37C 00000000 */  nop
/* 323CD0 802BD380 4600203C */  c.lt.s    $f4, $f0
/* 323CD4 802BD384 00000000 */  nop
/* 323CD8 802BD388 45000006 */  bc1f      .L802BD3A4
/* 323CDC 802BD38C 00000000 */   nop
/* 323CE0 802BD390 3C013F80 */  lui       $at, 0x3f80
/* 323CE4 802BD394 44810000 */  mtc1      $at, $f0
/* 323CE8 802BD398 00000000 */  nop
/* 323CEC 802BD39C 46002000 */  add.s     $f0, $f4, $f0
.L802BD3A0:
/* 323CF0 802BD3A0 E600000C */  swc1      $f0, 0xc($s0)
.L802BD3A4:
/* 323CF4 802BD3A4 3C10802C */  lui       $s0, %hi(D_802BDFFC)
/* 323CF8 802BD3A8 2610DFFC */  addiu     $s0, $s0, %lo(D_802BDFFC)
/* 323CFC 802BD3AC 8E020000 */  lw        $v0, ($s0)
/* 323D00 802BD3B0 3C0140C9 */  lui       $at, 0x40c9
/* 323D04 802BD3B4 34210FD0 */  ori       $at, $at, 0xfd0
/* 323D08 802BD3B8 44810000 */  mtc1      $at, $f0
/* 323D0C 802BD3BC C44C0018 */  lwc1      $f12, 0x18($v0)
/* 323D10 802BD3C0 46006302 */  mul.s     $f12, $f12, $f0
/* 323D14 802BD3C4 00000000 */  nop
/* 323D18 802BD3C8 3C0143B4 */  lui       $at, 0x43b4
/* 323D1C 802BD3CC 4481A000 */  mtc1      $at, $f20
/* 323D20 802BD3D0 0C00A85B */  jal       sin_rad
/* 323D24 802BD3D4 46146303 */   div.s    $f12, $f12, $f20
/* 323D28 802BD3D8 8E020000 */  lw        $v0, ($s0)
/* 323D2C 802BD3DC 3C014040 */  lui       $at, 0x4040
/* 323D30 802BD3E0 44812000 */  mtc1      $at, $f4
/* 323D34 802BD3E4 C4420018 */  lwc1      $f2, 0x18($v0)
/* 323D38 802BD3E8 46041080 */  add.s     $f2, $f2, $f4
/* 323D3C 802BD3EC 3C014316 */  lui       $at, 0x4316
/* 323D40 802BD3F0 44813000 */  mtc1      $at, $f6
/* 323D44 802BD3F4 00000000 */  nop
/* 323D48 802BD3F8 4602303C */  c.lt.s    $f6, $f2
/* 323D4C 802BD3FC E4420018 */  swc1      $f2, 0x18($v0)
/* 323D50 802BD400 46040082 */  mul.s     $f2, $f0, $f4
/* 323D54 802BD404 00000000 */  nop
/* 323D58 802BD408 45030001 */  bc1tl     .L802BD410
/* 323D5C 802BD40C E4460018 */   swc1     $f6, 0x18($v0)
.L802BD410:
/* 323D60 802BD410 C620003C */  lwc1      $f0, 0x3c($s1)
/* 323D64 802BD414 46020000 */  add.s     $f0, $f0, $f2
/* 323D68 802BD418 8E020000 */  lw        $v0, ($s0)
/* 323D6C 802BD41C E620003C */  swc1      $f0, 0x3c($s1)
/* 323D70 802BD420 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 323D74 802BD424 0C00A6C9 */  jal       clamp_angle
/* 323D78 802BD428 460CA301 */   sub.s    $f12, $f20, $f12
/* 323D7C 802BD42C 8E020000 */  lw        $v0, ($s0)
/* 323D80 802BD430 E6200034 */  swc1      $f0, 0x34($s1)
/* 323D84 802BD434 C4400014 */  lwc1      $f0, 0x14($v0)
/* 323D88 802BD438 3C01802C */  lui       $at, %hi(D_802BE060)
/* 323D8C 802BD43C D422E060 */  ldc1      $f2, %lo(D_802BE060)($at)
/* 323D90 802BD440 46000021 */  cvt.d.s   $f0, $f0
/* 323D94 802BD444 46220000 */  add.d     $f0, $f0, $f2
/* 323D98 802BD448 3C014220 */  lui       $at, 0x4220
/* 323D9C 802BD44C 44811000 */  mtc1      $at, $f2
/* 323DA0 802BD450 46200020 */  cvt.s.d   $f0, $f0
/* 323DA4 802BD454 4600103C */  c.lt.s    $f2, $f0
/* 323DA8 802BD458 00000000 */  nop
/* 323DAC 802BD45C 45000002 */  bc1f      .L802BD468
/* 323DB0 802BD460 E4400014 */   swc1     $f0, 0x14($v0)
/* 323DB4 802BD464 E4420014 */  swc1      $f2, 0x14($v0)
.L802BD468:
/* 323DB8 802BD468 8E030000 */  lw        $v1, ($s0)
/* 323DBC 802BD46C 8C620000 */  lw        $v0, ($v1)
/* 323DC0 802BD470 2442FFFF */  addiu     $v0, $v0, -1
/* 323DC4 802BD474 14400018 */  bnez      $v0, .L802BD4D8
/* 323DC8 802BD478 AC620000 */   sw       $v0, ($v1)
/* 323DCC 802BD47C 8C620004 */  lw        $v0, 4($v1)
/* 323DD0 802BD480 24420001 */  addiu     $v0, $v0, 1
/* 323DD4 802BD484 080AF536 */  j         .L802BD4D8
/* 323DD8 802BD488 AC620004 */   sw       $v0, 4($v1)
.L802BD48C:
/* 323DDC 802BD48C 8C820008 */  lw        $v0, 8($a0)
/* 323DE0 802BD490 AE220000 */  sw        $v0, ($s1)
/* 323DE4 802BD494 8C820004 */  lw        $v0, 4($a0)
/* 323DE8 802BD498 2403001E */  addiu     $v1, $zero, 0x1e
/* 323DEC 802BD49C AC830000 */  sw        $v1, ($a0)
/* 323DF0 802BD4A0 24420001 */  addiu     $v0, $v0, 1
/* 323DF4 802BD4A4 080AF536 */  j         .L802BD4D8
/* 323DF8 802BD4A8 AC820004 */   sw       $v0, 4($a0)
.L802BD4AC:
/* 323DFC 802BD4AC 0C03B52E */  jal       update_player_move_history
/* 323E00 802BD4B0 0220202D */   daddu    $a0, $s1, $zero
/* 323E04 802BD4B4 0C03B574 */  jal       func_800ED5D0
/* 323E08 802BD4B8 0220202D */   daddu    $a0, $s1, $zero
/* 323E0C 802BD4BC 8E030000 */  lw        $v1, ($s0)
/* 323E10 802BD4C0 8C620000 */  lw        $v0, ($v1)
/* 323E14 802BD4C4 2442FFFF */  addiu     $v0, $v0, -1
/* 323E18 802BD4C8 14400003 */  bnez      $v0, .L802BD4D8
/* 323E1C 802BD4CC AC620000 */   sw       $v0, ($v1)
/* 323E20 802BD4D0 AC600004 */  sw        $zero, 4($v1)
/* 323E24 802BD4D4 AE600000 */  sw        $zero, ($s3)
.L802BD4D8:
/* 323E28 802BD4D8 0000102D */  daddu     $v0, $zero, $zero
.L802BD4DC:
/* 323E2C 802BD4DC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 323E30 802BD4E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 323E34 802BD4E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 323E38 802BD4E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 323E3C 802BD4EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 323E40 802BD4F0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 323E44 802BD4F4 03E00008 */  jr        $ra
/* 323E48 802BD4F8 27BD0038 */   addiu    $sp, $sp, 0x38
