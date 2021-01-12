.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0016454
/* 32F284 E0016454 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 32F288 E0016458 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 32F28C E001645C 0080B02D */  daddu     $s6, $a0, $zero
/* 32F290 E0016460 3C05DB06 */  lui       $a1, 0xdb06
/* 32F294 E0016464 34A50024 */  ori       $a1, $a1, 0x24
/* 32F298 E0016468 AFB300AC */  sw        $s3, 0xac($sp)
/* 32F29C E001646C 0000982D */  daddu     $s3, $zero, $zero
/* 32F2A0 E0016470 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 32F2A4 E0016474 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 32F2A8 E0016478 3C02E700 */  lui       $v0, 0xe700
/* 32F2AC E001647C AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 32F2B0 E0016480 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 32F2B4 E0016484 AFB700BC */  sw        $s7, 0xbc($sp)
/* 32F2B8 E0016488 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 32F2BC E001648C AFB400B0 */  sw        $s4, 0xb0($sp)
/* 32F2C0 E0016490 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 32F2C4 E0016494 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 32F2C8 E0016498 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 32F2CC E001649C F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 32F2D0 E00164A0 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 32F2D4 E00164A4 8CC30000 */  lw        $v1, ($a2)
/* 32F2D8 E00164A8 8ED2000C */  lw        $s2, 0xc($s6)
/* 32F2DC E00164AC 0060202D */  daddu     $a0, $v1, $zero
/* 32F2E0 E00164B0 24630008 */  addiu     $v1, $v1, 8
/* 32F2E4 E00164B4 ACC30000 */  sw        $v1, ($a2)
/* 32F2E8 E00164B8 AC820000 */  sw        $v0, ($a0)
/* 32F2EC E00164BC AC800004 */  sw        $zero, 4($a0)
/* 32F2F0 E00164C0 AC650000 */  sw        $a1, ($v1)
/* 32F2F4 E00164C4 8EC40010 */  lw        $a0, 0x10($s6)
/* 32F2F8 E00164C8 24620008 */  addiu     $v0, $v1, 8
/* 32F2FC E00164CC ACC20000 */  sw        $v0, ($a2)
/* 32F300 E00164D0 8C84001C */  lw        $a0, 0x1c($a0)
/* 32F304 E00164D4 3C02DE00 */  lui       $v0, 0xde00
/* 32F308 E00164D8 AC620008 */  sw        $v0, 8($v1)
/* 32F30C E00164DC 3C020900 */  lui       $v0, 0x900
/* 32F310 E00164E0 244200E0 */  addiu     $v0, $v0, 0xe0
/* 32F314 E00164E4 AC62000C */  sw        $v0, 0xc($v1)
/* 32F318 E00164E8 3C028000 */  lui       $v0, 0x8000
/* 32F31C E00164EC 00822021 */  addu      $a0, $a0, $v0
/* 32F320 E00164F0 AC640004 */  sw        $a0, 4($v1)
/* 32F324 E00164F4 8EC20008 */  lw        $v0, 8($s6)
/* 32F328 E00164F8 24630010 */  addiu     $v1, $v1, 0x10
/* 32F32C E00164FC 18400070 */  blez      $v0, .LE00166C0
/* 32F330 E0016500 ACC30000 */   sw       $v1, ($a2)
/* 32F334 E0016504 27B10060 */  addiu     $s1, $sp, 0x60
/* 32F338 E0016508 3C1E800A */  lui       $fp, %hi(gDisplayContext)
/* 32F33C E001650C 27DEA674 */  addiu     $fp, $fp, %lo(gDisplayContext)
/* 32F340 E0016510 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 32F344 E0016514 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 32F348 E0016518 3C150001 */  lui       $s5, 1
/* 32F34C E001651C 36B51630 */  ori       $s5, $s5, 0x1630
/* 32F350 E0016520 00C0A02D */  daddu     $s4, $a2, $zero
/* 32F354 E0016524 26500008 */  addiu     $s0, $s2, 8
/* 32F358 E0016528 4480A000 */  mtc1      $zero, $f20
/* 32F35C E001652C 3C013F80 */  lui       $at, 0x3f80
/* 32F360 E0016530 4481B000 */  mtc1      $at, $f22
.LE0016534:
/* 32F364 E0016534 8E420000 */  lw        $v0, ($s2)
/* 32F368 E0016538 5040005C */  beql      $v0, $zero, .LE00166AC
/* 32F36C E001653C 26730001 */   addiu    $s3, $s3, 1
/* 32F370 E0016540 3C09800B */  lui       $t1, %hi(gCameras)
/* 32F374 E0016544 25291D80 */  addiu     $t1, $t1, %lo(gCameras)
/* 32F378 E0016548 4405A000 */  mfc1      $a1, $f20
/* 32F37C E001654C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 32F380 E0016550 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 32F384 E0016554 4407A000 */  mfc1      $a3, $f20
/* 32F388 E0016558 00031080 */  sll       $v0, $v1, 2
/* 32F38C E001655C 00431021 */  addu      $v0, $v0, $v1
/* 32F390 E0016560 00021080 */  sll       $v0, $v0, 2
/* 32F394 E0016564 00431023 */  subu      $v0, $v0, $v1
/* 32F398 E0016568 000218C0 */  sll       $v1, $v0, 3
/* 32F39C E001656C 00431021 */  addu      $v0, $v0, $v1
/* 32F3A0 E0016570 000210C0 */  sll       $v0, $v0, 3
/* 32F3A4 E0016574 00491021 */  addu      $v0, $v0, $t1
/* 32F3A8 E0016578 C442006C */  lwc1      $f2, 0x6c($v0)
/* 32F3AC E001657C E7B60010 */  swc1      $f22, 0x10($sp)
/* 32F3B0 E0016580 C6000004 */  lwc1      $f0, 4($s0)
/* 32F3B4 E0016584 46001087 */  neg.s     $f2, $f2
/* 32F3B8 E0016588 E7A00014 */  swc1      $f0, 0x14($sp)
/* 32F3BC E001658C C6000008 */  lwc1      $f0, 8($s0)
/* 32F3C0 E0016590 44061000 */  mfc1      $a2, $f2
/* 32F3C4 E0016594 E7A00018 */  swc1      $f0, 0x18($sp)
/* 32F3C8 E0016598 C600000C */  lwc1      $f0, 0xc($s0)
/* 32F3CC E001659C 27A40020 */  addiu     $a0, $sp, 0x20
/* 32F3D0 E00165A0 0C080180 */  jal       func_E0200600
/* 32F3D4 E00165A4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 32F3D8 E00165A8 8E050014 */  lw        $a1, 0x14($s0)
/* 32F3DC E00165AC 8E060018 */  lw        $a2, 0x18($s0)
/* 32F3E0 E00165B0 8E07001C */  lw        $a3, 0x1c($s0)
/* 32F3E4 E00165B4 0C080110 */  jal       func_E0200440
/* 32F3E8 E00165B8 0220202D */   daddu    $a0, $s1, $zero
/* 32F3EC E00165BC 0220202D */  daddu     $a0, $s1, $zero
/* 32F3F0 E00165C0 27A50020 */  addiu     $a1, $sp, 0x20
/* 32F3F4 E00165C4 0C080114 */  jal       func_E0200450
/* 32F3F8 E00165C8 00A0302D */   daddu    $a2, $a1, $zero
/* 32F3FC E00165CC E7B60010 */  swc1      $f22, 0x10($sp)
/* 32F400 E00165D0 8E050010 */  lw        $a1, 0x10($s0)
/* 32F404 E00165D4 4406A000 */  mfc1      $a2, $f20
/* 32F408 E00165D8 4407A000 */  mfc1      $a3, $f20
/* 32F40C E00165DC 0C080104 */  jal       func_E0200410
/* 32F410 E00165E0 0220202D */   daddu    $a0, $s1, $zero
/* 32F414 E00165E4 0220202D */  daddu     $a0, $s1, $zero
/* 32F418 E00165E8 27A50020 */  addiu     $a1, $sp, 0x20
/* 32F41C E00165EC 0C080114 */  jal       func_E0200450
/* 32F420 E00165F0 00A0302D */   daddu    $a2, $a1, $zero
/* 32F424 E00165F4 27A40020 */  addiu     $a0, $sp, 0x20
/* 32F428 E00165F8 96E50000 */  lhu       $a1, ($s7)
/* 32F42C E00165FC 8FC20000 */  lw        $v0, ($fp)
/* 32F430 E0016600 00052980 */  sll       $a1, $a1, 6
/* 32F434 E0016604 00B52821 */  addu      $a1, $a1, $s5
/* 32F438 E0016608 0C080118 */  jal       func_E0200460
/* 32F43C E001660C 00452821 */   addu     $a1, $v0, $a1
/* 32F440 E0016610 3C077060 */  lui       $a3, 0x7060
/* 32F444 E0016614 34E71800 */  ori       $a3, $a3, 0x1800
/* 32F448 E0016618 3C08D838 */  lui       $t0, 0xd838
/* 32F44C E001661C 35080002 */  ori       $t0, $t0, 2
/* 32F450 E0016620 8E840000 */  lw        $a0, ($s4)
/* 32F454 E0016624 3C02FA00 */  lui       $v0, 0xfa00
/* 32F458 E0016628 0080302D */  daddu     $a2, $a0, $zero
/* 32F45C E001662C 24840008 */  addiu     $a0, $a0, 8
/* 32F460 E0016630 AE840000 */  sw        $a0, ($s4)
/* 32F464 E0016634 ACC20000 */  sw        $v0, ($a2)
/* 32F468 E0016638 92050000 */  lbu       $a1, ($s0)
/* 32F46C E001663C 96E30000 */  lhu       $v1, ($s7)
/* 32F470 E0016640 24820008 */  addiu     $v0, $a0, 8
/* 32F474 E0016644 AE820000 */  sw        $v0, ($s4)
/* 32F478 E0016648 24620001 */  addiu     $v0, $v1, 1
/* 32F47C E001664C A6E20000 */  sh        $v0, ($s7)
/* 32F480 E0016650 24820010 */  addiu     $v0, $a0, 0x10
/* 32F484 E0016654 AE820000 */  sw        $v0, ($s4)
/* 32F488 E0016658 24820018 */  addiu     $v0, $a0, 0x18
/* 32F48C E001665C 00A72825 */  or        $a1, $a1, $a3
/* 32F490 E0016660 AE820000 */  sw        $v0, ($s4)
/* 32F494 E0016664 3C02DA38 */  lui       $v0, 0xda38
/* 32F498 E0016668 3063FFFF */  andi      $v1, $v1, 0xffff
/* 32F49C E001666C 00031980 */  sll       $v1, $v1, 6
/* 32F4A0 E0016670 ACC50004 */  sw        $a1, 4($a2)
/* 32F4A4 E0016674 AC820000 */  sw        $v0, ($a0)
/* 32F4A8 E0016678 8FC20000 */  lw        $v0, ($fp)
/* 32F4AC E001667C 00751821 */  addu      $v1, $v1, $s5
/* 32F4B0 E0016680 AC880010 */  sw        $t0, 0x10($a0)
/* 32F4B4 E0016684 00431021 */  addu      $v0, $v0, $v1
/* 32F4B8 E0016688 AC820004 */  sw        $v0, 4($a0)
/* 32F4BC E001668C 3C02DE00 */  lui       $v0, 0xde00
/* 32F4C0 E0016690 AC820008 */  sw        $v0, 8($a0)
/* 32F4C4 E0016694 3C020900 */  lui       $v0, 0x900
/* 32F4C8 E0016698 244201B8 */  addiu     $v0, $v0, 0x1b8
/* 32F4CC E001669C AC82000C */  sw        $v0, 0xc($a0)
/* 32F4D0 E00166A0 24020040 */  addiu     $v0, $zero, 0x40
/* 32F4D4 E00166A4 AC820014 */  sw        $v0, 0x14($a0)
/* 32F4D8 E00166A8 26730001 */  addiu     $s3, $s3, 1
.LE00166AC:
/* 32F4DC E00166AC 26100050 */  addiu     $s0, $s0, 0x50
/* 32F4E0 E00166B0 8EC20008 */  lw        $v0, 8($s6)
/* 32F4E4 E00166B4 0262102A */  slt       $v0, $s3, $v0
/* 32F4E8 E00166B8 1440FF9E */  bnez      $v0, .LE0016534
/* 32F4EC E00166BC 26520050 */   addiu    $s2, $s2, 0x50
.LE00166C0:
/* 32F4F0 E00166C0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 32F4F4 E00166C4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 32F4F8 E00166C8 8C620000 */  lw        $v0, ($v1)
/* 32F4FC E00166CC 0040202D */  daddu     $a0, $v0, $zero
/* 32F500 E00166D0 24420008 */  addiu     $v0, $v0, 8
/* 32F504 E00166D4 AC620000 */  sw        $v0, ($v1)
/* 32F508 E00166D8 3C02E700 */  lui       $v0, 0xe700
/* 32F50C E00166DC AC820000 */  sw        $v0, ($a0)
/* 32F510 E00166E0 AC800004 */  sw        $zero, 4($a0)
/* 32F514 E00166E4 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 32F518 E00166E8 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 32F51C E00166EC 8FB700BC */  lw        $s7, 0xbc($sp)
/* 32F520 E00166F0 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 32F524 E00166F4 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 32F528 E00166F8 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 32F52C E00166FC 8FB300AC */  lw        $s3, 0xac($sp)
/* 32F530 E0016700 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 32F534 E0016704 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 32F538 E0016708 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 32F53C E001670C D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 32F540 E0016710 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 32F544 E0016714 03E00008 */  jr        $ra
/* 32F548 E0016718 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 32F54C E001671C 00000000 */  nop
