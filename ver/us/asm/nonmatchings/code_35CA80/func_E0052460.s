.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0052460
/* 35CEE0 E0052460 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 35CEE4 E0052464 3C05DB06 */  lui       $a1, 0xdb06
/* 35CEE8 E0052468 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 35CEEC E005246C 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 35CEF0 E0052470 34A50024 */  ori       $a1, $a1, 0x24
/* 35CEF4 E0052474 3C02E700 */  lui       $v0, 0xe700
/* 35CEF8 E0052478 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 35CEFC E005247C AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 35CF00 E0052480 AFB700BC */  sw        $s7, 0xbc($sp)
/* 35CF04 E0052484 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 35CF08 E0052488 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 35CF0C E005248C AFB400B0 */  sw        $s4, 0xb0($sp)
/* 35CF10 E0052490 AFB300AC */  sw        $s3, 0xac($sp)
/* 35CF14 E0052494 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 35CF18 E0052498 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 35CF1C E005249C AFB000A0 */  sw        $s0, 0xa0($sp)
/* 35CF20 E00524A0 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 35CF24 E00524A4 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 35CF28 E00524A8 8CE60000 */  lw        $a2, ($a3)
/* 35CF2C E00524AC 8C88000C */  lw        $t0, 0xc($a0)
/* 35CF30 E00524B0 00C0182D */  daddu     $v1, $a2, $zero
/* 35CF34 E00524B4 24C60008 */  addiu     $a2, $a2, 8
/* 35CF38 E00524B8 AC620000 */  sw        $v0, ($v1)
/* 35CF3C E00524BC AC600004 */  sw        $zero, 4($v1)
/* 35CF40 E00524C0 ACC50000 */  sw        $a1, ($a2)
/* 35CF44 E00524C4 8C820010 */  lw        $v0, 0x10($a0)
/* 35CF48 E00524C8 ACE60000 */  sw        $a2, ($a3)
/* 35CF4C E00524CC 8C42001C */  lw        $v0, 0x1c($v0)
/* 35CF50 E00524D0 3C038000 */  lui       $v1, 0x8000
/* 35CF54 E00524D4 00431021 */  addu      $v0, $v0, $v1
/* 35CF58 E00524D8 ACC20004 */  sw        $v0, 4($a2)
/* 35CF5C E00524DC 8D0A001C */  lw        $t2, 0x1c($t0)
/* 35CF60 E00524E0 24C20008 */  addiu     $v0, $a2, 8
/* 35CF64 E00524E4 AFAA0098 */  sw        $t2, 0x98($sp)
/* 35CF68 E00524E8 15400009 */  bnez      $t2, .LE0052510
/* 35CF6C E00524EC ACE20000 */   sw       $v0, ($a3)
/* 35CF70 E00524F0 24C20010 */  addiu     $v0, $a2, 0x10
/* 35CF74 E00524F4 ACE20000 */  sw        $v0, ($a3)
/* 35CF78 E00524F8 3C02DE00 */  lui       $v0, 0xde00
/* 35CF7C E00524FC ACC20008 */  sw        $v0, 8($a2)
/* 35CF80 E0052500 3C020900 */  lui       $v0, 0x900
/* 35CF84 E0052504 24420440 */  addiu     $v0, $v0, 0x440
/* 35CF88 E0052508 08014955 */  j         .LE0052554
/* 35CF8C E005250C ACC2000C */   sw       $v0, 0xc($a2)
.LE0052510:
/* 35CF90 E0052510 8FAA0098 */  lw        $t2, 0x98($sp)
/* 35CF94 E0052514 24020001 */  addiu     $v0, $zero, 1
/* 35CF98 E0052518 15420008 */  bne       $t2, $v0, .LE005253C
/* 35CF9C E005251C 24C20010 */   addiu    $v0, $a2, 0x10
/* 35CFA0 E0052520 ACE20000 */  sw        $v0, ($a3)
/* 35CFA4 E0052524 3C02DE00 */  lui       $v0, 0xde00
/* 35CFA8 E0052528 ACC20008 */  sw        $v0, 8($a2)
/* 35CFAC E005252C 3C020900 */  lui       $v0, 0x900
/* 35CFB0 E0052530 24420390 */  addiu     $v0, $v0, 0x390
/* 35CFB4 E0052534 08014955 */  j         .LE0052554
/* 35CFB8 E0052538 ACC2000C */   sw       $v0, 0xc($a2)
.LE005253C:
/* 35CFBC E005253C ACE20000 */  sw        $v0, ($a3)
/* 35CFC0 E0052540 3C02DE00 */  lui       $v0, 0xde00
/* 35CFC4 E0052544 ACC20008 */  sw        $v0, 8($a2)
/* 35CFC8 E0052548 3C020900 */  lui       $v0, 0x900
/* 35CFCC E005254C 244202E0 */  addiu     $v0, $v0, 0x2e0
/* 35CFD0 E0052550 ACC2000C */  sw        $v0, 0xc($a2)
.LE0052554:
/* 35CFD4 E0052554 27A40018 */  addiu     $a0, $sp, 0x18
/* 35CFD8 E0052558 3C120001 */  lui       $s2, 1
/* 35CFDC E005255C 36521630 */  ori       $s2, $s2, 0x1630
/* 35CFE0 E0052560 0000982D */  daddu     $s3, $zero, $zero
/* 35CFE4 E0052564 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 35CFE8 E0052568 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 35CFEC E005256C 0040B82D */  daddu     $s7, $v0, $zero
/* 35CFF0 E0052570 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 35CFF4 E0052574 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 35CFF8 E0052578 0040B02D */  daddu     $s6, $v0, $zero
/* 35CFFC E005257C 3C1E0001 */  lui       $fp, 1
/* 35D000 E0052580 37DE1630 */  ori       $fp, $fp, 0x1630
/* 35D004 E0052584 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 35D008 E0052588 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 35D00C E005258C 0040A82D */  daddu     $s5, $v0, $zero
/* 35D010 E0052590 8D050004 */  lw        $a1, 4($t0)
/* 35D014 E0052594 8D060008 */  lw        $a2, 8($t0)
/* 35D018 E0052598 8D07000C */  lw        $a3, 0xc($t0)
/* 35D01C E005259C 0C080108 */  jal       func_E0200420
/* 35D020 E00525A0 0100A02D */   daddu    $s4, $t0, $zero
/* 35D024 E00525A4 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D028 E00525A8 96C50000 */  lhu       $a1, ($s6)
/* 35D02C E00525AC 8EE20000 */  lw        $v0, ($s7)
/* 35D030 E00525B0 00052980 */  sll       $a1, $a1, 6
/* 35D034 E00525B4 00B22821 */  addu      $a1, $a1, $s2
/* 35D038 E00525B8 0C080118 */  jal       func_E0200460
/* 35D03C E00525BC 00452821 */   addu     $a1, $v0, $a1
/* 35D040 E00525C0 3C02DA38 */  lui       $v0, 0xda38
/* 35D044 E00525C4 34420002 */  ori       $v0, $v0, 2
/* 35D048 E00525C8 3C050100 */  lui       $a1, 0x100
/* 35D04C E00525CC 34A51002 */  ori       $a1, $a1, 0x1002
/* 35D050 E00525D0 3C110900 */  lui       $s1, 0x900
/* 35D054 E00525D4 26310190 */  addiu     $s1, $s1, 0x190
/* 35D058 E00525D8 4480A000 */  mtc1      $zero, $f20
/* 35D05C E00525DC 8EA80000 */  lw        $t0, ($s5)
/* 35D060 E00525E0 96C90000 */  lhu       $t1, ($s6)
/* 35D064 E00525E4 3C013F80 */  lui       $at, 0x3f80
/* 35D068 E00525E8 4481B000 */  mtc1      $at, $f22
/* 35D06C E00525EC 0100202D */  daddu     $a0, $t0, $zero
/* 35D070 E00525F0 25080008 */  addiu     $t0, $t0, 8
/* 35D074 E00525F4 AC820000 */  sw        $v0, ($a0)
/* 35D078 E00525F8 3122FFFF */  andi      $v0, $t1, 0xffff
/* 35D07C E00525FC 00021180 */  sll       $v0, $v0, 6
/* 35D080 E0052600 00521021 */  addu      $v0, $v0, $s2
/* 35D084 E0052604 25290001 */  addiu     $t1, $t1, 1
/* 35D088 E0052608 4406A000 */  mfc1      $a2, $f20
/* 35D08C E005260C 8EE30000 */  lw        $v1, ($s7)
/* 35D090 E0052610 4407A000 */  mfc1      $a3, $f20
/* 35D094 E0052614 00621821 */  addu      $v1, $v1, $v0
/* 35D098 E0052618 AC830004 */  sw        $v1, 4($a0)
/* 35D09C E005261C AD050000 */  sw        $a1, ($t0)
/* 35D0A0 E0052620 AD110004 */  sw        $s1, 4($t0)
/* 35D0A4 E0052624 E7B60010 */  swc1      $f22, 0x10($sp)
/* 35D0A8 E0052628 8E850010 */  lw        $a1, 0x10($s4)
/* 35D0AC E005262C 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D0B0 E0052630 AEA80000 */  sw        $t0, ($s5)
/* 35D0B4 E0052634 25080008 */  addiu     $t0, $t0, 8
/* 35D0B8 E0052638 A6C90000 */  sh        $t1, ($s6)
/* 35D0BC E005263C 0C080104 */  jal       func_E0200410
/* 35D0C0 E0052640 AEA80000 */   sw       $t0, ($s5)
/* 35D0C4 E0052644 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D0C8 E0052648 96C50000 */  lhu       $a1, ($s6)
/* 35D0CC E005264C 8EE20000 */  lw        $v0, ($s7)
/* 35D0D0 E0052650 00052980 */  sll       $a1, $a1, 6
/* 35D0D4 E0052654 00B22821 */  addu      $a1, $a1, $s2
/* 35D0D8 E0052658 0C080118 */  jal       func_E0200460
/* 35D0DC E005265C 00452821 */   addu     $a1, $v0, $a1
/* 35D0E0 E0052660 3C03DA38 */  lui       $v1, 0xda38
/* 35D0E4 E0052664 34630001 */  ori       $v1, $v1, 1
/* 35D0E8 E0052668 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D0EC E005266C 8EA20000 */  lw        $v0, ($s5)
/* 35D0F0 E0052670 4406A000 */  mfc1      $a2, $f20
/* 35D0F4 E0052674 96C80000 */  lhu       $t0, ($s6)
/* 35D0F8 E0052678 0040482D */  daddu     $t1, $v0, $zero
/* 35D0FC E005267C 24420008 */  addiu     $v0, $v0, 8
/* 35D100 E0052680 AEA20000 */  sw        $v0, ($s5)
/* 35D104 E0052684 AD230000 */  sw        $v1, ($t1)
/* 35D108 E0052688 3103FFFF */  andi      $v1, $t0, 0xffff
/* 35D10C E005268C 00031980 */  sll       $v1, $v1, 6
/* 35D110 E0052690 00721821 */  addu      $v1, $v1, $s2
/* 35D114 E0052694 8EE20000 */  lw        $v0, ($s7)
/* 35D118 E0052698 3C058007 */  lui       $a1, %hi(gCurrentCameraID)
/* 35D11C E005269C 8CA57410 */  lw        $a1, %lo(gCurrentCameraID)($a1)
/* 35D120 E00526A0 00431021 */  addu      $v0, $v0, $v1
/* 35D124 E00526A4 AD220004 */  sw        $v0, 4($t1)
/* 35D128 E00526A8 00051080 */  sll       $v0, $a1, 2
/* 35D12C E00526AC 00451021 */  addu      $v0, $v0, $a1
/* 35D130 E00526B0 00021080 */  sll       $v0, $v0, 2
/* 35D134 E00526B4 00451023 */  subu      $v0, $v0, $a1
/* 35D138 E00526B8 000218C0 */  sll       $v1, $v0, 3
/* 35D13C E00526BC 00431021 */  addu      $v0, $v0, $v1
/* 35D140 E00526C0 000210C0 */  sll       $v0, $v0, 3
/* 35D144 E00526C4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 35D148 E00526C8 00220821 */  addu      $at, $at, $v0
/* 35D14C E00526CC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 35D150 E00526D0 4407B000 */  mfc1      $a3, $f22
/* 35D154 E00526D4 46000007 */  neg.s     $f0, $f0
/* 35D158 E00526D8 44050000 */  mfc1      $a1, $f0
/* 35D15C E00526DC 25080001 */  addiu     $t0, $t0, 1
/* 35D160 E00526E0 A6C80000 */  sh        $t0, ($s6)
/* 35D164 E00526E4 0C080104 */  jal       func_E0200410
/* 35D168 E00526E8 E7B40010 */   swc1     $f20, 0x10($sp)
/* 35D16C E00526EC 27B00058 */  addiu     $s0, $sp, 0x58
/* 35D170 E00526F0 8E8500C4 */  lw        $a1, 0xc4($s4)
/* 35D174 E00526F4 8E8600C8 */  lw        $a2, 0xc8($s4)
/* 35D178 E00526F8 4407A000 */  mfc1      $a3, $f20
/* 35D17C E00526FC 0C080108 */  jal       func_E0200420
/* 35D180 E0052700 0200202D */   daddu    $a0, $s0, $zero
/* 35D184 E0052704 0200202D */  daddu     $a0, $s0, $zero
/* 35D188 E0052708 27A50018 */  addiu     $a1, $sp, 0x18
/* 35D18C E005270C 0C080114 */  jal       func_E0200450
/* 35D190 E0052710 00A0302D */   daddu    $a2, $a1, $zero
/* 35D194 E0052714 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D198 E0052718 96C50000 */  lhu       $a1, ($s6)
/* 35D19C E005271C 8EE20000 */  lw        $v0, ($s7)
/* 35D1A0 E0052720 00052980 */  sll       $a1, $a1, 6
/* 35D1A4 E0052724 00B22821 */  addu      $a1, $a1, $s2
/* 35D1A8 E0052728 0C080118 */  jal       func_E0200460
/* 35D1AC E005272C 00452821 */   addu     $a1, $v0, $a1
/* 35D1B0 E0052730 3C060100 */  lui       $a2, 0x100
/* 35D1B4 E0052734 34C61004 */  ori       $a2, $a2, 0x1004
/* 35D1B8 E0052738 8EA40000 */  lw        $a0, ($s5)
/* 35D1BC E005273C 3C03DA38 */  lui       $v1, 0xda38
/* 35D1C0 E0052740 0080282D */  daddu     $a1, $a0, $zero
/* 35D1C4 E0052744 24840008 */  addiu     $a0, $a0, 8
/* 35D1C8 E0052748 AEA40000 */  sw        $a0, ($s5)
/* 35D1CC E005274C 96C20000 */  lhu       $v0, ($s6)
/* 35D1D0 E0052750 2631FFF0 */  addiu     $s1, $s1, -0x10
/* 35D1D4 E0052754 ACA30000 */  sw        $v1, ($a1)
/* 35D1D8 E0052758 24430001 */  addiu     $v1, $v0, 1
/* 35D1DC E005275C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 35D1E0 E0052760 00021180 */  sll       $v0, $v0, 6
/* 35D1E4 E0052764 A6C30000 */  sh        $v1, ($s6)
/* 35D1E8 E0052768 8EE30000 */  lw        $v1, ($s7)
/* 35D1EC E005276C 00521021 */  addu      $v0, $v0, $s2
/* 35D1F0 E0052770 00621821 */  addu      $v1, $v1, $v0
/* 35D1F4 E0052774 24820008 */  addiu     $v0, $a0, 8
/* 35D1F8 E0052778 ACA30004 */  sw        $v1, 4($a1)
/* 35D1FC E005277C AEA20000 */  sw        $v0, ($s5)
/* 35D200 E0052780 AC860000 */  sw        $a2, ($a0)
/* 35D204 E0052784 AC910004 */  sw        $s1, 4($a0)
.LE0052788:
/* 35D208 E0052788 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D20C E005278C 0000382D */  daddu     $a3, $zero, $zero
/* 35D210 E0052790 8E850024 */  lw        $a1, 0x24($s4)
/* 35D214 E0052794 8E860028 */  lw        $a2, 0x28($s4)
/* 35D218 E0052798 0C080108 */  jal       func_E0200420
/* 35D21C E005279C 26940008 */   addiu    $s4, $s4, 8
/* 35D220 E00527A0 27A40018 */  addiu     $a0, $sp, 0x18
/* 35D224 E00527A4 96C50000 */  lhu       $a1, ($s6)
/* 35D228 E00527A8 8EE20000 */  lw        $v0, ($s7)
/* 35D22C E00527AC 00052980 */  sll       $a1, $a1, 6
/* 35D230 E00527B0 00BE2821 */  addu      $a1, $a1, $fp
/* 35D234 E00527B4 0C080118 */  jal       func_E0200460
/* 35D238 E00527B8 00452821 */   addu     $a1, $v0, $a1
/* 35D23C E00527BC 3C080100 */  lui       $t0, 0x100
/* 35D240 E00527C0 35081000 */  ori       $t0, $t0, 0x1000
/* 35D244 E00527C4 3C09D838 */  lui       $t1, 0xd838
/* 35D248 E00527C8 35290002 */  ori       $t1, $t1, 2
/* 35D24C E00527CC 26640003 */  addiu     $a0, $s3, 3
/* 35D250 E00527D0 00133100 */  sll       $a2, $s3, 4
/* 35D254 E00527D4 26730001 */  addiu     $s3, $s3, 1
/* 35D258 E00527D8 3C03DA38 */  lui       $v1, 0xda38
/* 35D25C E00527DC 3084007F */  andi      $a0, $a0, 0x7f
/* 35D260 E00527E0 8EA50000 */  lw        $a1, ($s5)
/* 35D264 E00527E4 00042040 */  sll       $a0, $a0, 1
/* 35D268 E00527E8 00A0382D */  daddu     $a3, $a1, $zero
/* 35D26C E00527EC 24A50008 */  addiu     $a1, $a1, 8
/* 35D270 E00527F0 AEA50000 */  sw        $a1, ($s5)
/* 35D274 E00527F4 96C20000 */  lhu       $v0, ($s6)
/* 35D278 E00527F8 00882025 */  or        $a0, $a0, $t0
/* 35D27C E00527FC ACE30000 */  sw        $v1, ($a3)
/* 35D280 E0052800 24430001 */  addiu     $v1, $v0, 1
/* 35D284 E0052804 3042FFFF */  andi      $v0, $v0, 0xffff
/* 35D288 E0052808 00021180 */  sll       $v0, $v0, 6
/* 35D28C E005280C A6C30000 */  sh        $v1, ($s6)
/* 35D290 E0052810 8EE30000 */  lw        $v1, ($s7)
/* 35D294 E0052814 005E1021 */  addu      $v0, $v0, $fp
/* 35D298 E0052818 00621821 */  addu      $v1, $v1, $v0
/* 35D29C E005281C 24A20008 */  addiu     $v0, $a1, 8
/* 35D2A0 E0052820 ACE30004 */  sw        $v1, 4($a3)
/* 35D2A4 E0052824 AEA20000 */  sw        $v0, ($s5)
/* 35D2A8 E0052828 3C020900 */  lui       $v0, 0x900
/* 35D2AC E005282C 244201A0 */  addiu     $v0, $v0, 0x1a0
/* 35D2B0 E0052830 00C23021 */  addu      $a2, $a2, $v0
/* 35D2B4 E0052834 24A20010 */  addiu     $v0, $a1, 0x10
/* 35D2B8 E0052838 24030040 */  addiu     $v1, $zero, 0x40
/* 35D2BC E005283C ACA40000 */  sw        $a0, ($a1)
/* 35D2C0 E0052840 ACA60004 */  sw        $a2, 4($a1)
/* 35D2C4 E0052844 AEA20000 */  sw        $v0, ($s5)
/* 35D2C8 E0052848 2A620014 */  slti      $v0, $s3, 0x14
/* 35D2CC E005284C ACA90008 */  sw        $t1, 8($a1)
/* 35D2D0 E0052850 1440FFCD */  bnez      $v0, .LE0052788
/* 35D2D4 E0052854 ACA3000C */   sw       $v1, 0xc($a1)
/* 35D2D8 E0052858 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 35D2DC E005285C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 35D2E0 E0052860 8CC50000 */  lw        $a1, ($a2)
/* 35D2E4 E0052864 00A0102D */  daddu     $v0, $a1, $zero
/* 35D2E8 E0052868 24A50008 */  addiu     $a1, $a1, 8
/* 35D2EC E005286C ACC50000 */  sw        $a1, ($a2)
/* 35D2F0 E0052870 AC490000 */  sw        $t1, ($v0)
/* 35D2F4 E0052874 AC430004 */  sw        $v1, 4($v0)
/* 35D2F8 E0052878 24A20008 */  addiu     $v0, $a1, 8
/* 35D2FC E005287C ACC20000 */  sw        $v0, ($a2)
/* 35D300 E0052880 ACA90000 */  sw        $t1, ($a1)
/* 35D304 E0052884 ACA30004 */  sw        $v1, 4($a1)
/* 35D308 E0052888 8FAA0098 */  lw        $t2, 0x98($sp)
/* 35D30C E005288C 29420064 */  slti      $v0, $t2, 0x64
/* 35D310 E0052890 1040001F */  beqz      $v0, .LE0052910
/* 35D314 E0052894 3C03052A */   lui      $v1, 0x52a
/* 35D318 E0052898 34630402 */  ori       $v1, $v1, 0x402
/* 35D31C E005289C 0000982D */  daddu     $s3, $zero, $zero
/* 35D320 E00528A0 00C0402D */  daddu     $t0, $a2, $zero
/* 35D324 E00528A4 3C090500 */  lui       $t1, 0x500
/* 35D328 E00528A8 35290002 */  ori       $t1, $t1, 2
/* 35D32C E00528AC 24070006 */  addiu     $a3, $zero, 6
/* 35D330 E00528B0 24060004 */  addiu     $a2, $zero, 4
/* 35D334 E00528B4 24A20010 */  addiu     $v0, $a1, 0x10
/* 35D338 E00528B8 AD020000 */  sw        $v0, ($t0)
/* 35D33C E00528BC ACA30008 */  sw        $v1, 8($a1)
/* 35D340 E00528C0 ACA0000C */  sw        $zero, 0xc($a1)
.LE00528C4:
/* 35D344 E00528C4 30E400FF */  andi      $a0, $a3, 0xff
/* 35D348 E00528C8 24E70002 */  addiu     $a3, $a3, 2
/* 35D34C E00528CC 30C300FF */  andi      $v1, $a2, 0xff
/* 35D350 E00528D0 24C60002 */  addiu     $a2, $a2, 2
/* 35D354 E00528D4 26730001 */  addiu     $s3, $s3, 1
/* 35D358 E00528D8 00031C00 */  sll       $v1, $v1, 0x10
/* 35D35C E00528DC 00042200 */  sll       $a0, $a0, 8
/* 35D360 E00528E0 00641825 */  or        $v1, $v1, $a0
/* 35D364 E00528E4 8D020000 */  lw        $v0, ($t0)
/* 35D368 E00528E8 00691825 */  or        $v1, $v1, $t1
/* 35D36C E00528EC 0040282D */  daddu     $a1, $v0, $zero
/* 35D370 E00528F0 24420008 */  addiu     $v0, $v0, 8
/* 35D374 E00528F4 AD020000 */  sw        $v0, ($t0)
/* 35D378 E00528F8 2A620013 */  slti      $v0, $s3, 0x13
/* 35D37C E00528FC ACA30000 */  sw        $v1, ($a1)
/* 35D380 E0052900 1440FFF0 */  bnez      $v0, .LE00528C4
/* 35D384 E0052904 ACA00004 */   sw       $zero, 4($a1)
/* 35D388 E0052908 08014A67 */  j         .LE005299C
/* 35D38C E005290C 00000000 */   nop
.LE0052910:
/* 35D390 E0052910 3C030500 */  lui       $v1, 0x500
/* 35D394 E0052914 34630204 */  ori       $v1, $v1, 0x204
/* 35D398 E0052918 3C040500 */  lui       $a0, 0x500
/* 35D39C E005291C 34842A02 */  ori       $a0, $a0, 0x2a02
/* 35D3A0 E0052920 0000982D */  daddu     $s3, $zero, $zero
/* 35D3A4 E0052924 00C0402D */  daddu     $t0, $a2, $zero
/* 35D3A8 E0052928 3C090500 */  lui       $t1, 0x500
/* 35D3AC E005292C 35290002 */  ori       $t1, $t1, 2
/* 35D3B0 E0052930 24070006 */  addiu     $a3, $zero, 6
/* 35D3B4 E0052934 24060004 */  addiu     $a2, $zero, 4
/* 35D3B8 E0052938 24A20010 */  addiu     $v0, $a1, 0x10
/* 35D3BC E005293C AD020000 */  sw        $v0, ($t0)
/* 35D3C0 E0052940 24A20018 */  addiu     $v0, $a1, 0x18
/* 35D3C4 E0052944 ACA30008 */  sw        $v1, 8($a1)
/* 35D3C8 E0052948 ACA0000C */  sw        $zero, 0xc($a1)
/* 35D3CC E005294C AD020000 */  sw        $v0, ($t0)
/* 35D3D0 E0052950 ACA40010 */  sw        $a0, 0x10($a1)
/* 35D3D4 E0052954 ACA00014 */  sw        $zero, 0x14($a1)
.LE0052958:
/* 35D3D8 E0052958 30E400FF */  andi      $a0, $a3, 0xff
/* 35D3DC E005295C 24E70002 */  addiu     $a3, $a3, 2
/* 35D3E0 E0052960 30C300FF */  andi      $v1, $a2, 0xff
/* 35D3E4 E0052964 24C60002 */  addiu     $a2, $a2, 2
/* 35D3E8 E0052968 26730001 */  addiu     $s3, $s3, 1
/* 35D3EC E005296C 00031C00 */  sll       $v1, $v1, 0x10
/* 35D3F0 E0052970 00042200 */  sll       $a0, $a0, 8
/* 35D3F4 E0052974 00641825 */  or        $v1, $v1, $a0
/* 35D3F8 E0052978 8D020000 */  lw        $v0, ($t0)
/* 35D3FC E005297C 00691825 */  or        $v1, $v1, $t1
/* 35D400 E0052980 0040282D */  daddu     $a1, $v0, $zero
/* 35D404 E0052984 24420008 */  addiu     $v0, $v0, 8
/* 35D408 E0052988 AD020000 */  sw        $v0, ($t0)
/* 35D40C E005298C 2A620013 */  slti      $v0, $s3, 0x13
/* 35D410 E0052990 ACA30000 */  sw        $v1, ($a1)
/* 35D414 E0052994 1440FFF0 */  bnez      $v0, .LE0052958
/* 35D418 E0052998 ACA00004 */   sw       $zero, 4($a1)
.LE005299C:
/* 35D41C E005299C 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 35D420 E00529A0 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 35D424 E00529A4 8FB700BC */  lw        $s7, 0xbc($sp)
/* 35D428 E00529A8 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 35D42C E00529AC 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 35D430 E00529B0 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 35D434 E00529B4 8FB300AC */  lw        $s3, 0xac($sp)
/* 35D438 E00529B8 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 35D43C E00529BC 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 35D440 E00529C0 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 35D444 E00529C4 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 35D448 E00529C8 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 35D44C E00529CC 03E00008 */  jr        $ra
/* 35D450 E00529D0 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 35D454 E00529D4 00000000 */  nop
/* 35D458 E00529D8 00000000 */  nop
/* 35D45C E00529DC 00000000 */  nop
