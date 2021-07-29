.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_9B1AA0
/* 9B1AA0 80240310 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 9B1AA4 80240314 3C06E300 */  lui       $a2, 0xe300
/* 9B1AA8 80240318 34C60A01 */  ori       $a2, $a2, 0xa01
/* 9B1AAC 8024031C 3C07D9C0 */  lui       $a3, 0xd9c0
/* 9B1AB0 80240320 34E7F9FB */  ori       $a3, $a3, 0xf9fb
/* 9B1AB4 80240324 3C09D9FF */  lui       $t1, 0xd9ff
/* 9B1AB8 80240328 3529FFFF */  ori       $t1, $t1, 0xffff
/* 9B1ABC 8024032C 3C080020 */  lui       $t0, 0x20
/* 9B1AC0 80240330 35080005 */  ori       $t0, $t0, 5
/* 9B1AC4 80240334 3C0AD700 */  lui       $t2, 0xd700
/* 9B1AC8 80240338 354A0002 */  ori       $t2, $t2, 2
/* 9B1ACC 8024033C 3C0BE300 */  lui       $t3, 0xe300
/* 9B1AD0 80240340 356B0F00 */  ori       $t3, $t3, 0xf00
/* 9B1AD4 80240344 3C0CE300 */  lui       $t4, 0xe300
/* 9B1AD8 80240348 358C0C00 */  ori       $t4, $t4, 0xc00
/* 9B1ADC 8024034C 3C0DE300 */  lui       $t5, 0xe300
/* 9B1AE0 80240350 35AD1201 */  ori       $t5, $t5, 0x1201
/* 9B1AE4 80240354 3C0EE300 */  lui       $t6, 0xe300
/* 9B1AE8 80240358 35CE1801 */  ori       $t6, $t6, 0x1801
/* 9B1AEC 8024035C 3C0FE300 */  lui       $t7, 0xe300
/* 9B1AF0 80240360 35EF0D01 */  ori       $t7, $t7, 0xd01
/* 9B1AF4 80240364 AFB000C0 */  sw        $s0, 0xc0($sp)
/* 9B1AF8 80240368 3C10E300 */  lui       $s0, 0xe300
/* 9B1AFC 8024036C 36101402 */  ori       $s0, $s0, 0x1402
/* 9B1B00 80240370 AFB300CC */  sw        $s3, 0xcc($sp)
/* 9B1B04 80240374 3C13E300 */  lui       $s3, 0xe300
/* 9B1B08 80240378 36731700 */  ori       $s3, $s3, 0x1700
/* 9B1B0C 8024037C AFB400D0 */  sw        $s4, 0xd0($sp)
/* 9B1B10 80240380 3C14E200 */  lui       $s4, 0xe200
/* 9B1B14 80240384 36941E01 */  ori       $s4, $s4, 0x1e01
/* 9B1B18 80240388 AFB200C8 */  sw        $s2, 0xc8($sp)
/* 9B1B1C 8024038C 27B20040 */  addiu     $s2, $sp, 0x40
/* 9B1B20 80240390 0240202D */  daddu     $a0, $s2, $zero
/* 9B1B24 80240394 AFB500D4 */  sw        $s5, 0xd4($sp)
/* 9B1B28 80240398 3C150001 */  lui       $s5, 1
/* 9B1B2C 8024039C AFB100C4 */  sw        $s1, 0xc4($sp)
/* 9B1B30 802403A0 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 9B1B34 802403A4 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 9B1B38 802403A8 36B51630 */  ori       $s5, $s5, 0x1630
/* 9B1B3C 802403AC AFBF00D8 */  sw        $ra, 0xd8($sp)
/* 9B1B40 802403B0 F7B600E8 */  sdc1      $f22, 0xe8($sp)
/* 9B1B44 802403B4 F7B400E0 */  sdc1      $f20, 0xe0($sp)
/* 9B1B48 802403B8 8E220000 */  lw        $v0, ($s1)
/* 9B1B4C 802403BC 3C03E700 */  lui       $v1, 0xe700
/* 9B1B50 802403C0 0040282D */  daddu     $a1, $v0, $zero
/* 9B1B54 802403C4 24420008 */  addiu     $v0, $v0, 8
/* 9B1B58 802403C8 AE220000 */  sw        $v0, ($s1)
/* 9B1B5C 802403CC ACA30000 */  sw        $v1, ($a1)
/* 9B1B60 802403D0 24430008 */  addiu     $v1, $v0, 8
/* 9B1B64 802403D4 ACA00004 */  sw        $zero, 4($a1)
/* 9B1B68 802403D8 AE230000 */  sw        $v1, ($s1)
/* 9B1B6C 802403DC 24430010 */  addiu     $v1, $v0, 0x10
/* 9B1B70 802403E0 AC460000 */  sw        $a2, ($v0)
/* 9B1B74 802403E4 AC400004 */  sw        $zero, 4($v0)
/* 9B1B78 802403E8 AE230000 */  sw        $v1, ($s1)
/* 9B1B7C 802403EC 24430018 */  addiu     $v1, $v0, 0x18
/* 9B1B80 802403F0 AC470008 */  sw        $a3, 8($v0)
/* 9B1B84 802403F4 AC40000C */  sw        $zero, 0xc($v0)
/* 9B1B88 802403F8 AE230000 */  sw        $v1, ($s1)
/* 9B1B8C 802403FC 24430020 */  addiu     $v1, $v0, 0x20
/* 9B1B90 80240400 AC490010 */  sw        $t1, 0x10($v0)
/* 9B1B94 80240404 AC480014 */  sw        $t0, 0x14($v0)
/* 9B1B98 80240408 AE230000 */  sw        $v1, ($s1)
/* 9B1B9C 8024040C 2403FFFF */  addiu     $v1, $zero, -1
/* 9B1BA0 80240410 AC43001C */  sw        $v1, 0x1c($v0)
/* 9B1BA4 80240414 24430028 */  addiu     $v1, $v0, 0x28
/* 9B1BA8 80240418 AC4A0018 */  sw        $t2, 0x18($v0)
/* 9B1BAC 8024041C AE230000 */  sw        $v1, ($s1)
/* 9B1BB0 80240420 24430030 */  addiu     $v1, $v0, 0x30
/* 9B1BB4 80240424 AC4B0020 */  sw        $t3, 0x20($v0)
/* 9B1BB8 80240428 AC400024 */  sw        $zero, 0x24($v0)
/* 9B1BBC 8024042C AE230000 */  sw        $v1, ($s1)
/* 9B1BC0 80240430 3C030008 */  lui       $v1, 8
/* 9B1BC4 80240434 AC43002C */  sw        $v1, 0x2c($v0)
/* 9B1BC8 80240438 24430038 */  addiu     $v1, $v0, 0x38
/* 9B1BCC 8024043C AC4C0028 */  sw        $t4, 0x28($v0)
/* 9B1BD0 80240440 AE230000 */  sw        $v1, ($s1)
/* 9B1BD4 80240444 24032000 */  addiu     $v1, $zero, 0x2000
/* 9B1BD8 80240448 AC4D0030 */  sw        $t5, 0x30($v0)
/* 9B1BDC 8024044C AC430034 */  sw        $v1, 0x34($v0)
/* 9B1BE0 80240450 24430040 */  addiu     $v1, $v0, 0x40
/* 9B1BE4 80240454 AE230000 */  sw        $v1, ($s1)
/* 9B1BE8 80240458 240300C0 */  addiu     $v1, $zero, 0xc0
/* 9B1BEC 8024045C AC43003C */  sw        $v1, 0x3c($v0)
/* 9B1BF0 80240460 24430048 */  addiu     $v1, $v0, 0x48
/* 9B1BF4 80240464 AC4E0038 */  sw        $t6, 0x38($v0)
/* 9B1BF8 80240468 AE230000 */  sw        $v1, ($s1)
/* 9B1BFC 8024046C 24430050 */  addiu     $v1, $v0, 0x50
/* 9B1C00 80240470 AC4F0040 */  sw        $t7, 0x40($v0)
/* 9B1C04 80240474 AC400044 */  sw        $zero, 0x44($v0)
/* 9B1C08 80240478 AE230000 */  sw        $v1, ($s1)
/* 9B1C0C 8024047C 24030C00 */  addiu     $v1, $zero, 0xc00
/* 9B1C10 80240480 AC500048 */  sw        $s0, 0x48($v0)
/* 9B1C14 80240484 AC43004C */  sw        $v1, 0x4c($v0)
/* 9B1C18 80240488 AC530050 */  sw        $s3, 0x50($v0)
/* 9B1C1C 8024048C 3C138024 */  lui       $s3, %hi(D_802451F0)
/* 9B1C20 80240490 267351F0 */  addiu     $s3, $s3, %lo(D_802451F0)
/* 9B1C24 80240494 24430058 */  addiu     $v1, $v0, 0x58
/* 9B1C28 80240498 AC400054 */  sw        $zero, 0x54($v0)
/* 9B1C2C 8024049C AC540058 */  sw        $s4, 0x58($v0)
/* 9B1C30 802404A0 AC40005C */  sw        $zero, 0x5c($v0)
/* 9B1C34 802404A4 8E650014 */  lw        $a1, 0x14($s3)
/* 9B1C38 802404A8 8E660018 */  lw        $a2, 0x18($s3)
/* 9B1C3C 802404AC 8E67001C */  lw        $a3, 0x1c($s3)
/* 9B1C40 802404B0 24420060 */  addiu     $v0, $v0, 0x60
/* 9B1C44 802404B4 AE230000 */  sw        $v1, ($s1)
/* 9B1C48 802404B8 0C019E40 */  jal       guTranslateF
/* 9B1C4C 802404BC AE220000 */   sw       $v0, ($s1)
/* 9B1C50 802404C0 27B00080 */  addiu     $s0, $sp, 0x80
/* 9B1C54 802404C4 8E650024 */  lw        $a1, 0x24($s3)
/* 9B1C58 802404C8 4480A000 */  mtc1      $zero, $f20
/* 9B1C5C 802404CC 3C013F80 */  lui       $at, 0x3f80
/* 9B1C60 802404D0 4481B000 */  mtc1      $at, $f22
/* 9B1C64 802404D4 4406A000 */  mfc1      $a2, $f20
/* 9B1C68 802404D8 4407B000 */  mfc1      $a3, $f22
/* 9B1C6C 802404DC 0200202D */  daddu     $a0, $s0, $zero
/* 9B1C70 802404E0 0C019EC8 */  jal       guRotateF
/* 9B1C74 802404E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* 9B1C78 802404E8 0200202D */  daddu     $a0, $s0, $zero
/* 9B1C7C 802404EC 0240282D */  daddu     $a1, $s2, $zero
/* 9B1C80 802404F0 0C019D80 */  jal       guMtxCatF
/* 9B1C84 802404F4 0240302D */   daddu    $a2, $s2, $zero
/* 9B1C88 802404F8 8E650028 */  lw        $a1, 0x28($s3)
/* 9B1C8C 802404FC 4406A000 */  mfc1      $a2, $f20
/* 9B1C90 80240500 4407A000 */  mfc1      $a3, $f20
/* 9B1C94 80240504 0200202D */  daddu     $a0, $s0, $zero
/* 9B1C98 80240508 0C019EC8 */  jal       guRotateF
/* 9B1C9C 8024050C E7B60010 */   swc1     $f22, 0x10($sp)
/* 9B1CA0 80240510 0200202D */  daddu     $a0, $s0, $zero
/* 9B1CA4 80240514 0240282D */  daddu     $a1, $s2, $zero
/* 9B1CA8 80240518 0C019D80 */  jal       guMtxCatF
/* 9B1CAC 8024051C 0240302D */   daddu    $a2, $s2, $zero
/* 9B1CB0 80240520 8E650020 */  lw        $a1, 0x20($s3)
/* 9B1CB4 80240524 4406B000 */  mfc1      $a2, $f22
/* 9B1CB8 80240528 4407A000 */  mfc1      $a3, $f20
/* 9B1CBC 8024052C 0200202D */  daddu     $a0, $s0, $zero
/* 9B1CC0 80240530 0C019EC8 */  jal       guRotateF
/* 9B1CC4 80240534 AFA70010 */   sw       $a3, 0x10($sp)
/* 9B1CC8 80240538 0200202D */  daddu     $a0, $s0, $zero
/* 9B1CCC 8024053C 0240282D */  daddu     $a1, $s2, $zero
/* 9B1CD0 80240540 0C019D80 */  jal       guMtxCatF
/* 9B1CD4 80240544 0240302D */   daddu    $a2, $s2, $zero
/* 9B1CD8 80240548 8E65002C */  lw        $a1, 0x2c($s3)
/* 9B1CDC 8024054C 8E660030 */  lw        $a2, 0x30($s3)
/* 9B1CE0 80240550 8E670034 */  lw        $a3, 0x34($s3)
/* 9B1CE4 80240554 0C019DF0 */  jal       guScaleF
/* 9B1CE8 80240558 0200202D */   daddu    $a0, $s0, $zero
/* 9B1CEC 8024055C 0200202D */  daddu     $a0, $s0, $zero
/* 9B1CF0 80240560 0240282D */  daddu     $a1, $s2, $zero
/* 9B1CF4 80240564 0C019D80 */  jal       guMtxCatF
/* 9B1CF8 80240568 0240302D */   daddu    $a2, $s2, $zero
/* 9B1CFC 8024056C 0240202D */  daddu     $a0, $s2, $zero
/* 9B1D00 80240570 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 9B1D04 80240574 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 9B1D08 80240578 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 9B1D0C 8024057C 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 9B1D10 80240580 96050000 */  lhu       $a1, ($s0)
/* 9B1D14 80240584 8E420000 */  lw        $v0, ($s2)
/* 9B1D18 80240588 00052980 */  sll       $a1, $a1, 6
/* 9B1D1C 8024058C 00B52821 */  addu      $a1, $a1, $s5
/* 9B1D20 80240590 0C019D40 */  jal       guMtxF2L
/* 9B1D24 80240594 00452821 */   addu     $a1, $v0, $a1
/* 9B1D28 80240598 3C03DA38 */  lui       $v1, 0xda38
/* 9B1D2C 8024059C 34630002 */  ori       $v1, $v1, 2
/* 9B1D30 802405A0 8E220000 */  lw        $v0, ($s1)
/* 9B1D34 802405A4 96040000 */  lhu       $a0, ($s0)
/* 9B1D38 802405A8 0040282D */  daddu     $a1, $v0, $zero
/* 9B1D3C 802405AC 24420008 */  addiu     $v0, $v0, 8
/* 9B1D40 802405B0 AE220000 */  sw        $v0, ($s1)
/* 9B1D44 802405B4 3082FFFF */  andi      $v0, $a0, 0xffff
/* 9B1D48 802405B8 00021180 */  sll       $v0, $v0, 6
/* 9B1D4C 802405BC ACA30000 */  sw        $v1, ($a1)
/* 9B1D50 802405C0 8E430000 */  lw        $v1, ($s2)
/* 9B1D54 802405C4 00551021 */  addu      $v0, $v0, $s5
/* 9B1D58 802405C8 00621821 */  addu      $v1, $v1, $v0
/* 9B1D5C 802405CC 3C028000 */  lui       $v0, 0x8000
/* 9B1D60 802405D0 00621821 */  addu      $v1, $v1, $v0
/* 9B1D64 802405D4 ACA30004 */  sw        $v1, 4($a1)
/* 9B1D68 802405D8 8E620000 */  lw        $v0, ($s3)
/* 9B1D6C 802405DC 24840001 */  addiu     $a0, $a0, 1
/* 9B1D70 802405E0 14400012 */  bnez      $v0, .L8024062C
/* 9B1D74 802405E4 A6040000 */   sh       $a0, ($s0)
/* 9B1D78 802405E8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9B1D7C 802405EC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9B1D80 802405F0 24030008 */  addiu     $v1, $zero, 8
/* 9B1D84 802405F4 AE63000C */  sw        $v1, 0xc($s3)
/* 9B1D88 802405F8 94420134 */  lhu       $v0, 0x134($v0)
/* 9B1D8C 802405FC 30430003 */  andi      $v1, $v0, 3
/* 9B1D90 80240600 14600003 */  bnez      $v1, .L80240610
/* 9B1D94 80240604 2C620002 */   sltiu    $v0, $v1, 2
/* 9B1D98 80240608 0809018A */  j         .L80240628
/* 9B1D9C 8024060C 24020025 */   addiu    $v0, $zero, 0x25
.L80240610:
/* 9B1DA0 80240610 14400005 */  bnez      $v0, .L80240628
/* 9B1DA4 80240614 24020026 */   addiu    $v0, $zero, 0x26
/* 9B1DA8 80240618 2C620003 */  sltiu     $v0, $v1, 3
/* 9B1DAC 8024061C 14400002 */  bnez      $v0, .L80240628
/* 9B1DB0 80240620 24020027 */   addiu    $v0, $zero, 0x27
/* 9B1DB4 80240624 24020024 */  addiu     $v0, $zero, 0x24
.L80240628:
/* 9B1DB8 80240628 AE620010 */  sw        $v0, 0x10($s3)
.L8024062C:
/* 9B1DBC 8024062C 8E65000C */  lw        $a1, 0xc($s3)
/* 9B1DC0 80240630 8E660010 */  lw        $a2, 0x10($s3)
/* 9B1DC4 80240634 0C0B7811 */  jal       spr_get_player_raster_info
/* 9B1DC8 80240638 27A40030 */   addiu    $a0, $sp, 0x30
/* 9B1DCC 8024063C 27A50018 */  addiu     $a1, $sp, 0x18
/* 9B1DD0 80240640 0000302D */  daddu     $a2, $zero, $zero
/* 9B1DD4 80240644 8E640004 */  lw        $a0, 4($s3)
/* 9B1DD8 80240648 8FA30030 */  lw        $v1, 0x30($sp)
/* 9B1DDC 8024064C 8FA90034 */  lw        $t1, 0x34($sp)
/* 9B1DE0 80240650 97A8003A */  lhu       $t0, 0x3a($sp)
/* 9B1DE4 80240654 240200FF */  addiu     $v0, $zero, 0xff
/* 9B1DE8 80240658 A3A20028 */  sb        $v0, 0x28($sp)
/* 9B1DEC 8024065C A7A80020 */  sh        $t0, 0x20($sp)
/* 9B1DF0 80240660 3108FFFF */  andi      $t0, $t0, 0xffff
/* 9B1DF4 80240664 AFA30018 */  sw        $v1, 0x18($sp)
/* 9B1DF8 80240668 97A3003E */  lhu       $v1, 0x3e($sp)
/* 9B1DFC 8024066C 44880000 */  mtc1      $t0, $f0
/* 9B1E00 80240670 00000000 */  nop
/* 9B1E04 80240674 46800020 */  cvt.s.w   $f0, $f0
/* 9B1E08 80240678 AFA9001C */  sw        $t1, 0x1c($sp)
/* 9B1E0C 8024067C E6600038 */  swc1      $f0, 0x38($s3)
/* 9B1E10 80240680 8FA20038 */  lw        $v0, 0x38($sp)
/* 9B1E14 80240684 27A70040 */  addiu     $a3, $sp, 0x40
/* 9B1E18 80240688 A7A30022 */  sh        $v1, 0x22($sp)
/* 9B1E1C 8024068C 3063FFFF */  andi      $v1, $v1, 0xffff
/* 9B1E20 80240690 44830000 */  mtc1      $v1, $f0
/* 9B1E24 80240694 00000000 */  nop
/* 9B1E28 80240698 46800020 */  cvt.s.w   $f0, $f0
/* 9B1E2C 8024069C 00021FC2 */  srl       $v1, $v0, 0x1f
/* 9B1E30 802406A0 00431021 */  addu      $v0, $v0, $v1
/* 9B1E34 802406A4 00021043 */  sra       $v0, $v0, 1
/* 9B1E38 802406A8 E660003C */  swc1      $f0, 0x3c($s3)
/* 9B1E3C 802406AC 8FA3003C */  lw        $v1, 0x3c($sp)
/* 9B1E40 802406B0 00021023 */  negu      $v0, $v0
/* 9B1E44 802406B4 A7A20024 */  sh        $v0, 0x24($sp)
/* 9B1E48 802406B8 000317C2 */  srl       $v0, $v1, 0x1f
/* 9B1E4C 802406BC 00621821 */  addu      $v1, $v1, $v0
/* 9B1E50 802406C0 00031843 */  sra       $v1, $v1, 1
/* 9B1E54 802406C4 0C04EBDC */  jal       func_8013AF70
/* 9B1E58 802406C8 A7A30026 */   sh       $v1, 0x26($sp)
/* 9B1E5C 802406CC 3C05D838 */  lui       $a1, 0xd838
/* 9B1E60 802406D0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 9B1E64 802406D4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 9B1E68 802406D8 8C620000 */  lw        $v0, ($v1)
/* 9B1E6C 802406DC 34A50002 */  ori       $a1, $a1, 2
/* 9B1E70 802406E0 0040202D */  daddu     $a0, $v0, $zero
/* 9B1E74 802406E4 24420008 */  addiu     $v0, $v0, 8
/* 9B1E78 802406E8 AC620000 */  sw        $v0, ($v1)
/* 9B1E7C 802406EC 24020040 */  addiu     $v0, $zero, 0x40
/* 9B1E80 802406F0 AC850000 */  sw        $a1, ($a0)
/* 9B1E84 802406F4 AC820004 */  sw        $v0, 4($a0)
/* 9B1E88 802406F8 8FBF00D8 */  lw        $ra, 0xd8($sp)
/* 9B1E8C 802406FC 8FB500D4 */  lw        $s5, 0xd4($sp)
/* 9B1E90 80240700 8FB400D0 */  lw        $s4, 0xd0($sp)
/* 9B1E94 80240704 8FB300CC */  lw        $s3, 0xcc($sp)
/* 9B1E98 80240708 8FB200C8 */  lw        $s2, 0xc8($sp)
/* 9B1E9C 8024070C 8FB100C4 */  lw        $s1, 0xc4($sp)
/* 9B1EA0 80240710 8FB000C0 */  lw        $s0, 0xc0($sp)
/* 9B1EA4 80240714 D7B600E8 */  ldc1      $f22, 0xe8($sp)
/* 9B1EA8 80240718 D7B400E0 */  ldc1      $f20, 0xe0($sp)
/* 9B1EAC 8024071C 03E00008 */  jr        $ra
/* 9B1EB0 80240720 27BD00F0 */   addiu    $sp, $sp, 0xf0
