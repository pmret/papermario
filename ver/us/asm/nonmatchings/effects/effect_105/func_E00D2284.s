.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D2284
/* 3D4BF4 E00D2284 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 3D4BF8 E00D2288 0080302D */  daddu     $a2, $a0, $zero
/* 3D4BFC E00D228C 3C07DB06 */  lui       $a3, 0xdb06
/* 3D4C00 E00D2290 34E70024 */  ori       $a3, $a3, 0x24
/* 3D4C04 E00D2294 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D4C08 E00D2298 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3D4C0C E00D229C 3C160001 */  lui       $s6, 1
/* 3D4C10 E00D22A0 AFB3009C */  sw        $s3, 0x9c($sp)
/* 3D4C14 E00D22A4 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3D4C18 E00D22A8 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3D4C1C E00D22AC 36D61630 */  ori       $s6, $s6, 0x1630
/* 3D4C20 E00D22B0 AFBF00AC */  sw        $ra, 0xac($sp)
/* 3D4C24 E00D22B4 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3D4C28 E00D22B8 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3D4C2C E00D22BC AFB20098 */  sw        $s2, 0x98($sp)
/* 3D4C30 E00D22C0 AFB10094 */  sw        $s1, 0x94($sp)
/* 3D4C34 E00D22C4 AFB00090 */  sw        $s0, 0x90($sp)
/* 3D4C38 E00D22C8 F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 3D4C3C E00D22CC 8E650000 */  lw        $a1, ($s3)
/* 3D4C40 E00D22D0 8CD2000C */  lw        $s2, 0xc($a2)
/* 3D4C44 E00D22D4 00A0182D */  daddu     $v1, $a1, $zero
/* 3D4C48 E00D22D8 24A50008 */  addiu     $a1, $a1, 8
/* 3D4C4C E00D22DC AE650000 */  sw        $a1, ($s3)
/* 3D4C50 E00D22E0 8E550024 */  lw        $s5, 0x24($s2)
/* 3D4C54 E00D22E4 C6540034 */  lwc1      $f20, 0x34($s2)
/* 3D4C58 E00D22E8 C6400038 */  lwc1      $f0, 0x38($s2)
/* 3D4C5C E00D22EC 3C02E700 */  lui       $v0, 0xe700
/* 3D4C60 E00D22F0 AC620000 */  sw        $v0, ($v1)
/* 3D4C64 E00D22F4 AC600004 */  sw        $zero, 4($v1)
/* 3D4C68 E00D22F8 ACA70000 */  sw        $a3, ($a1)
/* 3D4C6C E00D22FC 8CC30010 */  lw        $v1, 0x10($a2)
/* 3D4C70 E00D2300 24A20008 */  addiu     $v0, $a1, 8
/* 3D4C74 E00D2304 AE620000 */  sw        $v0, ($s3)
/* 3D4C78 E00D2308 8C62001C */  lw        $v0, 0x1c($v1)
/* 3D4C7C E00D230C 3C038000 */  lui       $v1, 0x8000
/* 3D4C80 E00D2310 4600A502 */  mul.s     $f20, $f20, $f0
/* 3D4C84 E00D2314 00000000 */  nop
/* 3D4C88 E00D2318 00431021 */  addu      $v0, $v0, $v1
/* 3D4C8C E00D231C 3C03800B */  lui       $v1, %hi(gCameras)
/* 3D4C90 E00D2320 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3D4C94 E00D2324 ACA20004 */  sw        $v0, 4($a1)
/* 3D4C98 E00D2328 8E450004 */  lw        $a1, 4($s2)
/* 3D4C9C E00D232C 8E460008 */  lw        $a2, 8($s2)
/* 3D4CA0 E00D2330 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3D4CA4 E00D2334 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3D4CA8 E00D2338 8E47000C */  lw        $a3, 0xc($s2)
/* 3D4CAC E00D233C 00028880 */  sll       $s1, $v0, 2
/* 3D4CB0 E00D2340 02228821 */  addu      $s1, $s1, $v0
/* 3D4CB4 E00D2344 00118880 */  sll       $s1, $s1, 2
/* 3D4CB8 E00D2348 02228823 */  subu      $s1, $s1, $v0
/* 3D4CBC E00D234C 001110C0 */  sll       $v0, $s1, 3
/* 3D4CC0 E00D2350 02228821 */  addu      $s1, $s1, $v0
/* 3D4CC4 E00D2354 001188C0 */  sll       $s1, $s1, 3
/* 3D4CC8 E00D2358 0C080108 */  jal       shim_guTranslateF
/* 3D4CCC E00D235C 02238821 */   addu     $s1, $s1, $v1
/* 3D4CD0 E00D2360 27B00050 */  addiu     $s0, $sp, 0x50
/* 3D4CD4 E00D2364 4405A000 */  mfc1      $a1, $f20
/* 3D4CD8 E00D2368 0200202D */  daddu     $a0, $s0, $zero
/* 3D4CDC E00D236C 00A0302D */  daddu     $a2, $a1, $zero
/* 3D4CE0 E00D2370 0C080110 */  jal       shim_guScaleF
/* 3D4CE4 E00D2374 00A0382D */   daddu    $a3, $a1, $zero
/* 3D4CE8 E00D2378 0200202D */  daddu     $a0, $s0, $zero
/* 3D4CEC E00D237C 27A50010 */  addiu     $a1, $sp, 0x10
/* 3D4CF0 E00D2380 0C080114 */  jal       shim_guMtxCatF
/* 3D4CF4 E00D2384 00A0302D */   daddu    $a2, $a1, $zero
/* 3D4CF8 E00D2388 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D4CFC E00D238C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3D4D00 E00D2390 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3D4D04 E00D2394 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3D4D08 E00D2398 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3D4D0C E00D239C 96050000 */  lhu       $a1, ($s0)
/* 3D4D10 E00D23A0 8E820000 */  lw        $v0, ($s4)
/* 3D4D14 E00D23A4 00052980 */  sll       $a1, $a1, 6
/* 3D4D18 E00D23A8 00B62821 */  addu      $a1, $a1, $s6
/* 3D4D1C E00D23AC 0C080118 */  jal       shim_guMtxF2L
/* 3D4D20 E00D23B0 00452821 */   addu     $a1, $v0, $a1
/* 3D4D24 E00D23B4 3C03DA38 */  lui       $v1, 0xda38
/* 3D4D28 E00D23B8 34630002 */  ori       $v1, $v1, 2
/* 3D4D2C E00D23BC 3C06DA38 */  lui       $a2, 0xda38
/* 3D4D30 E00D23C0 34C60001 */  ori       $a2, $a2, 1
/* 3D4D34 E00D23C4 3C08D838 */  lui       $t0, 0xd838
/* 3D4D38 E00D23C8 35080002 */  ori       $t0, $t0, 2
/* 3D4D3C E00D23CC 32B500FF */  andi      $s5, $s5, 0xff
/* 3D4D40 E00D23D0 8E640000 */  lw        $a0, ($s3)
/* 3D4D44 E00D23D4 96020000 */  lhu       $v0, ($s0)
/* 3D4D48 E00D23D8 0080282D */  daddu     $a1, $a0, $zero
/* 3D4D4C E00D23DC 24840008 */  addiu     $a0, $a0, 8
/* 3D4D50 E00D23E0 AE640000 */  sw        $a0, ($s3)
/* 3D4D54 E00D23E4 ACA30000 */  sw        $v1, ($a1)
/* 3D4D58 E00D23E8 24430001 */  addiu     $v1, $v0, 1
/* 3D4D5C E00D23EC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D4D60 E00D23F0 00021180 */  sll       $v0, $v0, 6
/* 3D4D64 E00D23F4 A6030000 */  sh        $v1, ($s0)
/* 3D4D68 E00D23F8 8E830000 */  lw        $v1, ($s4)
/* 3D4D6C E00D23FC 00561021 */  addu      $v0, $v0, $s6
/* 3D4D70 E00D2400 00621821 */  addu      $v1, $v1, $v0
/* 3D4D74 E00D2404 24820008 */  addiu     $v0, $a0, 8
/* 3D4D78 E00D2408 ACA30004 */  sw        $v1, 4($a1)
/* 3D4D7C E00D240C AE620000 */  sw        $v0, ($s3)
/* 3D4D80 E00D2410 24820010 */  addiu     $v0, $a0, 0x10
/* 3D4D84 E00D2414 AC860000 */  sw        $a2, ($a0)
/* 3D4D88 E00D2418 AE620000 */  sw        $v0, ($s3)
/* 3D4D8C E00D241C 8E230204 */  lw        $v1, 0x204($s1)
/* 3D4D90 E00D2420 3C02FA00 */  lui       $v0, 0xfa00
/* 3D4D94 E00D2424 AC820008 */  sw        $v0, 8($a0)
/* 3D4D98 E00D2428 AC830004 */  sw        $v1, 4($a0)
/* 3D4D9C E00D242C 9242001B */  lbu       $v0, 0x1b($s2)
/* 3D4DA0 E00D2430 9245001F */  lbu       $a1, 0x1f($s2)
/* 3D4DA4 E00D2434 92460023 */  lbu       $a2, 0x23($s2)
/* 3D4DA8 E00D2438 24830018 */  addiu     $v1, $a0, 0x18
/* 3D4DAC E00D243C AE630000 */  sw        $v1, ($s3)
/* 3D4DB0 E00D2440 3C03FB00 */  lui       $v1, 0xfb00
/* 3D4DB4 E00D2444 AC830010 */  sw        $v1, 0x10($a0)
/* 3D4DB8 E00D2448 00021600 */  sll       $v0, $v0, 0x18
/* 3D4DBC E00D244C 00052C00 */  sll       $a1, $a1, 0x10
/* 3D4DC0 E00D2450 00451025 */  or        $v0, $v0, $a1
/* 3D4DC4 E00D2454 00063200 */  sll       $a2, $a2, 8
/* 3D4DC8 E00D2458 00461025 */  or        $v0, $v0, $a2
/* 3D4DCC E00D245C 00551025 */  or        $v0, $v0, $s5
/* 3D4DD0 E00D2460 AC82000C */  sw        $v0, 0xc($a0)
/* 3D4DD4 E00D2464 24820020 */  addiu     $v0, $a0, 0x20
/* 3D4DD8 E00D2468 9243002B */  lbu       $v1, 0x2b($s2)
/* 3D4DDC E00D246C 9246002F */  lbu       $a2, 0x2f($s2)
/* 3D4DE0 E00D2470 92470033 */  lbu       $a3, 0x33($s2)
/* 3D4DE4 E00D2474 3C05DE00 */  lui       $a1, 0xde00
/* 3D4DE8 E00D2478 AE620000 */  sw        $v0, ($s3)
/* 3D4DEC E00D247C 3C020900 */  lui       $v0, 0x900
/* 3D4DF0 E00D2480 24420080 */  addiu     $v0, $v0, 0x80
/* 3D4DF4 E00D2484 AC82001C */  sw        $v0, 0x1c($a0)
/* 3D4DF8 E00D2488 24820028 */  addiu     $v0, $a0, 0x28
/* 3D4DFC E00D248C AC850018 */  sw        $a1, 0x18($a0)
/* 3D4E00 E00D2490 AE620000 */  sw        $v0, ($s3)
/* 3D4E04 E00D2494 3C020900 */  lui       $v0, 0x900
/* 3D4E08 E00D2498 24420168 */  addiu     $v0, $v0, 0x168
/* 3D4E0C E00D249C AC820024 */  sw        $v0, 0x24($a0)
/* 3D4E10 E00D24A0 24820030 */  addiu     $v0, $a0, 0x30
/* 3D4E14 E00D24A4 AC850020 */  sw        $a1, 0x20($a0)
/* 3D4E18 E00D24A8 AE620000 */  sw        $v0, ($s3)
/* 3D4E1C E00D24AC 24020040 */  addiu     $v0, $zero, 0x40
/* 3D4E20 E00D24B0 AC880028 */  sw        $t0, 0x28($a0)
/* 3D4E24 E00D24B4 AC82002C */  sw        $v0, 0x2c($a0)
/* 3D4E28 E00D24B8 00031E00 */  sll       $v1, $v1, 0x18
/* 3D4E2C E00D24BC 00063400 */  sll       $a2, $a2, 0x10
/* 3D4E30 E00D24C0 00661825 */  or        $v1, $v1, $a2
/* 3D4E34 E00D24C4 00073A00 */  sll       $a3, $a3, 8
/* 3D4E38 E00D24C8 00671825 */  or        $v1, $v1, $a3
/* 3D4E3C E00D24CC AC830014 */  sw        $v1, 0x14($a0)
/* 3D4E40 E00D24D0 8FBF00AC */  lw        $ra, 0xac($sp)
/* 3D4E44 E00D24D4 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3D4E48 E00D24D8 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 3D4E4C E00D24DC 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 3D4E50 E00D24E0 8FB3009C */  lw        $s3, 0x9c($sp)
/* 3D4E54 E00D24E4 8FB20098 */  lw        $s2, 0x98($sp)
/* 3D4E58 E00D24E8 8FB10094 */  lw        $s1, 0x94($sp)
/* 3D4E5C E00D24EC 8FB00090 */  lw        $s0, 0x90($sp)
/* 3D4E60 E00D24F0 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 3D4E64 E00D24F4 03E00008 */  jr        $ra
/* 3D4E68 E00D24F8 27BD00B8 */   addiu    $sp, $sp, 0xb8
/* 3D4E6C E00D24FC 00000000 */  nop
