.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_79_appendGfx
/* 3A0344 E009E424 27BDFED0 */  addiu     $sp, $sp, -0x130
/* 3A0348 E009E428 AFBF0104 */  sw        $ra, 0x104($sp)
/* 3A034C E009E42C AFBE0100 */  sw        $fp, 0x100($sp)
/* 3A0350 E009E430 AFB700FC */  sw        $s7, 0xfc($sp)
/* 3A0354 E009E434 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 3A0358 E009E438 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 3A035C E009E43C AFB400F0 */  sw        $s4, 0xf0($sp)
/* 3A0360 E009E440 AFB300EC */  sw        $s3, 0xec($sp)
/* 3A0364 E009E444 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 3A0368 E009E448 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 3A036C E009E44C AFB000E0 */  sw        $s0, 0xe0($sp)
/* 3A0370 E009E450 F7BC0128 */  sdc1      $f28, 0x128($sp)
/* 3A0374 E009E454 F7BA0120 */  sdc1      $f26, 0x120($sp)
/* 3A0378 E009E458 F7B80118 */  sdc1      $f24, 0x118($sp)
/* 3A037C E009E45C F7B60110 */  sdc1      $f22, 0x110($sp)
/* 3A0380 E009E460 F7B40108 */  sdc1      $f20, 0x108($sp)
/* 3A0384 E009E464 AFA40130 */  sw        $a0, 0x130($sp)
/* 3A0388 E009E468 8C94000C */  lw        $s4, 0xc($a0)
/* 3A038C E009E46C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3A0390 E009E470 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3A0394 E009E474 3C04800B */  lui       $a0, %hi(gCameras)
/* 3A0398 E009E478 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 3A039C E009E47C 00031080 */  sll       $v0, $v1, 2
/* 3A03A0 E009E480 00431021 */  addu      $v0, $v0, $v1
/* 3A03A4 E009E484 00021080 */  sll       $v0, $v0, 2
/* 3A03A8 E009E488 00431023 */  subu      $v0, $v0, $v1
/* 3A03AC E009E48C 000218C0 */  sll       $v1, $v0, 3
/* 3A03B0 E009E490 00431021 */  addu      $v0, $v0, $v1
/* 3A03B4 E009E494 8E8D0014 */  lw        $t5, 0x14($s4)
/* 3A03B8 E009E498 000210C0 */  sll       $v0, $v0, 3
/* 3A03BC E009E49C AFAD00DC */  sw        $t5, 0xdc($sp)
/* 3A03C0 E009E4A0 8E8D001C */  lw        $t5, 0x1c($s4)
/* 3A03C4 E009E4A4 0044B021 */  addu      $s6, $v0, $a0
/* 3A03C8 E009E4A8 31B20001 */  andi      $s2, $t5, 1
/* 3A03CC E009E4AC 12400009 */  beqz      $s2, .LE009E4D4
/* 3A03D0 E009E4B0 AFAD00D8 */   sw       $t5, 0xd8($sp)
/* 3A03D4 E009E4B4 3C01E00A */  lui       $at, %hi(D_E009EE20)
/* 3A03D8 E009E4B8 D422EE20 */  ldc1      $f2, %lo(D_E009EE20)($at)
/* 3A03DC E009E4BC C7A000DC */  lwc1      $f0, 0xdc($sp)
/* 3A03E0 E009E4C0 46800021 */  cvt.d.w   $f0, $f0
/* 3A03E4 E009E4C4 46220002 */  mul.d     $f0, $f0, $f2
/* 3A03E8 E009E4C8 00000000 */  nop
/* 3A03EC E009E4CC 4620010D */  trunc.w.d $f4, $f0
/* 3A03F0 E009E4D0 E7A400DC */  swc1      $f4, 0xdc($sp)
.LE009E4D4:
/* 3A03F4 E009E4D4 3C06DB06 */  lui       $a2, 0xdb06
/* 3A03F8 E009E4D8 34C60024 */  ori       $a2, $a2, 0x24
/* 3A03FC E009E4DC 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0400 E009E4E0 3C100001 */  lui       $s0, 1
/* 3A0404 E009E4E4 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3A0408 E009E4E8 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3A040C E009E4EC 8E250000 */  lw        $a1, ($s1)
/* 3A0410 E009E4F0 3C02E700 */  lui       $v0, 0xe700
/* 3A0414 E009E4F4 00A0182D */  daddu     $v1, $a1, $zero
/* 3A0418 E009E4F8 24A50008 */  addiu     $a1, $a1, 8
/* 3A041C E009E4FC AE250000 */  sw        $a1, ($s1)
/* 3A0420 E009E500 AC620000 */  sw        $v0, ($v1)
/* 3A0424 E009E504 AC600004 */  sw        $zero, 4($v1)
/* 3A0428 E009E508 ACA60000 */  sw        $a2, ($a1)
/* 3A042C E009E50C 8FAD0130 */  lw        $t5, 0x130($sp)
/* 3A0430 E009E510 36101630 */  ori       $s0, $s0, 0x1630
/* 3A0434 E009E514 8DA30010 */  lw        $v1, 0x10($t5)
/* 3A0438 E009E518 24A20008 */  addiu     $v0, $a1, 8
/* 3A043C E009E51C AE220000 */  sw        $v0, ($s1)
/* 3A0440 E009E520 8C62001C */  lw        $v0, 0x1c($v1)
/* 3A0444 E009E524 3C038000 */  lui       $v1, 0x8000
/* 3A0448 E009E528 00431021 */  addu      $v0, $v0, $v1
/* 3A044C E009E52C ACA20004 */  sw        $v0, 4($a1)
/* 3A0450 E009E530 8E850008 */  lw        $a1, 8($s4)
/* 3A0454 E009E534 8E86000C */  lw        $a2, 0xc($s4)
/* 3A0458 E009E538 8E870010 */  lw        $a3, 0x10($s4)
/* 3A045C E009E53C 0C080108 */  jal       shim_guTranslateF
/* 3A0460 E009E540 24170001 */   addiu    $s7, $zero, 1
/* 3A0464 E009E544 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0468 E009E548 3C138007 */  lui       $s3, %hi(gMatrixListPos)
/* 3A046C E009E54C 267341F0 */  addiu     $s3, $s3, %lo(gMatrixListPos)
/* 3A0470 E009E550 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 3A0474 E009E554 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 3A0478 E009E558 96650000 */  lhu       $a1, ($s3)
/* 3A047C E009E55C 8EA20000 */  lw        $v0, ($s5)
/* 3A0480 E009E560 00052980 */  sll       $a1, $a1, 6
/* 3A0484 E009E564 00B02821 */  addu      $a1, $a1, $s0
/* 3A0488 E009E568 0C080118 */  jal       shim_guMtxF2L
/* 3A048C E009E56C 00452821 */   addu     $a1, $v0, $a1
/* 3A0490 E009E570 3C03DA38 */  lui       $v1, 0xda38
/* 3A0494 E009E574 34630002 */  ori       $v1, $v1, 2
/* 3A0498 E009E578 3C0ADA38 */  lui       $t2, 0xda38
/* 3A049C E009E57C 01575025 */  or        $t2, $t2, $s7
/* 3A04A0 E009E580 3C0BFF40 */  lui       $t3, 0xff40
/* 3A04A4 E009E584 356B4000 */  ori       $t3, $t3, 0x4000
/* 3A04A8 E009E588 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A04AC E009E58C 02F21004 */  sllv      $v0, $s2, $s7
/* 3A04B0 E009E590 8FAD00D8 */  lw        $t5, 0xd8($sp)
/* 3A04B4 E009E594 4480A000 */  mtc1      $zero, $f20
/* 3A04B8 E009E598 8E280000 */  lw        $t0, ($s1)
/* 3A04BC E009E59C 3C013F80 */  lui       $at, 0x3f80
/* 3A04C0 E009E5A0 4481C000 */  mtc1      $at, $f24
/* 3A04C4 E009E5A4 004D1021 */  addu      $v0, $v0, $t5
/* 3A04C8 E009E5A8 44822000 */  mtc1      $v0, $f4
/* 3A04CC E009E5AC 00000000 */  nop
/* 3A04D0 E009E5B0 46802120 */  cvt.s.w   $f4, $f4
/* 3A04D4 E009E5B4 0100482D */  daddu     $t1, $t0, $zero
/* 3A04D8 E009E5B8 44052000 */  mfc1      $a1, $f4
/* 3A04DC E009E5BC 4406A000 */  mfc1      $a2, $f20
/* 3A04E0 E009E5C0 96620000 */  lhu       $v0, ($s3)
/* 3A04E4 E009E5C4 25080008 */  addiu     $t0, $t0, 8
/* 3A04E8 E009E5C8 AE280000 */  sw        $t0, ($s1)
/* 3A04EC E009E5CC AD230000 */  sw        $v1, ($t1)
/* 3A04F0 E009E5D0 00571821 */  addu      $v1, $v0, $s7
/* 3A04F4 E009E5D4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A04F8 E009E5D8 00021180 */  sll       $v0, $v0, 6
/* 3A04FC E009E5DC A6630000 */  sh        $v1, ($s3)
/* 3A0500 E009E5E0 8EA30000 */  lw        $v1, ($s5)
/* 3A0504 E009E5E4 00501021 */  addu      $v0, $v0, $s0
/* 3A0508 E009E5E8 00621821 */  addu      $v1, $v1, $v0
/* 3A050C E009E5EC 25020008 */  addiu     $v0, $t0, 8
/* 3A0510 E009E5F0 AD230004 */  sw        $v1, 4($t1)
/* 3A0514 E009E5F4 AE220000 */  sw        $v0, ($s1)
/* 3A0518 E009E5F8 25020010 */  addiu     $v0, $t0, 0x10
/* 3A051C E009E5FC AD0A0000 */  sw        $t2, ($t0)
/* 3A0520 E009E600 AE220000 */  sw        $v0, ($s1)
/* 3A0524 E009E604 8EC30204 */  lw        $v1, 0x204($s6)
/* 3A0528 E009E608 3C02FA00 */  lui       $v0, 0xfa00
/* 3A052C E009E60C AD020008 */  sw        $v0, 8($t0)
/* 3A0530 E009E610 8FAD00DC */  lw        $t5, 0xdc($sp)
/* 3A0534 E009E614 4407A000 */  mfc1      $a3, $f20
/* 3A0538 E009E618 31A200FF */  andi      $v0, $t5, 0xff
/* 3A053C E009E61C 004B1025 */  or        $v0, $v0, $t3
/* 3A0540 E009E620 AD02000C */  sw        $v0, 0xc($t0)
/* 3A0544 E009E624 AD030004 */  sw        $v1, 4($t0)
/* 3A0548 E009E628 0C080104 */  jal       shim_guRotateF
/* 3A054C E009E62C E7B80010 */   swc1     $f24, 0x10($sp)
/* 3A0550 E009E630 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0554 E009E634 96650000 */  lhu       $a1, ($s3)
/* 3A0558 E009E638 8EA20000 */  lw        $v0, ($s5)
/* 3A055C E009E63C 00052980 */  sll       $a1, $a1, 6
/* 3A0560 E009E640 00B02821 */  addu      $a1, $a1, $s0
/* 3A0564 E009E644 0C080118 */  jal       shim_guMtxF2L
/* 3A0568 E009E648 00452821 */   addu     $a1, $v0, $a1
/* 3A056C E009E64C 3C06D838 */  lui       $a2, 0xd838
/* 3A0570 E009E650 8E240000 */  lw        $a0, ($s1)
/* 3A0574 E009E654 34C60002 */  ori       $a2, $a2, 2
/* 3A0578 E009E658 0080282D */  daddu     $a1, $a0, $zero
/* 3A057C E009E65C 24840008 */  addiu     $a0, $a0, 8
/* 3A0580 E009E660 AE240000 */  sw        $a0, ($s1)
/* 3A0584 E009E664 96620000 */  lhu       $v0, ($s3)
/* 3A0588 E009E668 3C03DA38 */  lui       $v1, 0xda38
/* 3A058C E009E66C ACA30000 */  sw        $v1, ($a1)
/* 3A0590 E009E670 00571821 */  addu      $v1, $v0, $s7
/* 3A0594 E009E674 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A0598 E009E678 00021180 */  sll       $v0, $v0, 6
/* 3A059C E009E67C A6630000 */  sh        $v1, ($s3)
/* 3A05A0 E009E680 8EA30000 */  lw        $v1, ($s5)
/* 3A05A4 E009E684 00501021 */  addu      $v0, $v0, $s0
/* 3A05A8 E009E688 00621821 */  addu      $v1, $v1, $v0
/* 3A05AC E009E68C 24820008 */  addiu     $v0, $a0, 8
/* 3A05B0 E009E690 ACA30004 */  sw        $v1, 4($a1)
/* 3A05B4 E009E694 3C03DE00 */  lui       $v1, 0xde00
/* 3A05B8 E009E698 AE220000 */  sw        $v0, ($s1)
/* 3A05BC E009E69C 3C020900 */  lui       $v0, 0x900
/* 3A05C0 E009E6A0 244212A8 */  addiu     $v0, $v0, 0x12a8
/* 3A05C4 E009E6A4 AC820004 */  sw        $v0, 4($a0)
/* 3A05C8 E009E6A8 24820010 */  addiu     $v0, $a0, 0x10
/* 3A05CC E009E6AC AC830000 */  sw        $v1, ($a0)
/* 3A05D0 E009E6B0 AE220000 */  sw        $v0, ($s1)
/* 3A05D4 E009E6B4 3C020900 */  lui       $v0, 0x900
/* 3A05D8 E009E6B8 24421510 */  addiu     $v0, $v0, 0x1510
/* 3A05DC E009E6BC AC82000C */  sw        $v0, 0xc($a0)
/* 3A05E0 E009E6C0 24820018 */  addiu     $v0, $a0, 0x18
/* 3A05E4 E009E6C4 AC830008 */  sw        $v1, 8($a0)
/* 3A05E8 E009E6C8 AE220000 */  sw        $v0, ($s1)
/* 3A05EC E009E6CC 24020040 */  addiu     $v0, $zero, 0x40
/* 3A05F0 E009E6D0 AC820014 */  sw        $v0, 0x14($a0)
/* 3A05F4 E009E6D4 3C020900 */  lui       $v0, 0x900
/* 3A05F8 E009E6D8 24421200 */  addiu     $v0, $v0, 0x1200
/* 3A05FC E009E6DC AC860010 */  sw        $a2, 0x10($a0)
/* 3A0600 E009E6E0 AC830018 */  sw        $v1, 0x18($a0)
/* 3A0604 E009E6E4 AC82001C */  sw        $v0, 0x1c($a0)
/* 3A0608 E009E6E8 8FAD0130 */  lw        $t5, 0x130($sp)
/* 3A060C E009E6EC 26940034 */  addiu     $s4, $s4, 0x34
/* 3A0610 E009E6F0 8DA20008 */  lw        $v0, 8($t5)
/* 3A0614 E009E6F4 24840020 */  addiu     $a0, $a0, 0x20
/* 3A0618 E009E6F8 02E2102A */  slt       $v0, $s7, $v0
/* 3A061C E009E6FC 104001A0 */  beqz      $v0, .LE009ED80
/* 3A0620 E009E700 AE240000 */   sw       $a0, ($s1)
/* 3A0624 E009E704 4600A586 */  mov.s     $f22, $f20
/* 3A0628 E009E708 0220902D */  daddu     $s2, $s1, $zero
/* 3A062C E009E70C 27B00058 */  addiu     $s0, $sp, 0x58
/* 3A0630 E009E710 02A0B02D */  daddu     $s6, $s5, $zero
/* 3A0634 E009E714 0260A82D */  daddu     $s5, $s3, $zero
/* 3A0638 E009E718 3C130001 */  lui       $s3, 1
/* 3A063C E009E71C 36731630 */  ori       $s3, $s3, 0x1630
/* 3A0640 E009E720 3C1ED838 */  lui       $fp, 0xd838
/* 3A0644 E009E724 37DE0002 */  ori       $fp, $fp, 2
/* 3A0648 E009E728 2691002C */  addiu     $s1, $s4, 0x2c
/* 3A064C E009E72C 2414000A */  addiu     $s4, $zero, 0xa
/* 3A0650 E009E730 3C014270 */  lui       $at, 0x4270
/* 3A0654 E009E734 4481E000 */  mtc1      $at, $f28
/* 3A0658 E009E738 3C014000 */  lui       $at, 0x4000
/* 3A065C E009E73C 4481D800 */  mtc1      $at, $f27
/* 3A0660 E009E740 4480D000 */  mtc1      $zero, $f26
.LE009E744:
/* 3A0664 E009E744 C634FFFC */  lwc1      $f20, -4($s1)
/* 3A0668 E009E748 4616A032 */  c.eq.s    $f20, $f22
/* 3A066C E009E74C 00000000 */  nop
/* 3A0670 E009E750 45030185 */  bc1tl     .LE009ED68
/* 3A0674 E009E754 2694000A */   addiu    $s4, $s4, 0xa
/* 3A0678 E009E758 3C0AFCFF */  lui       $t2, 0xfcff
/* 3A067C E009E75C 354A97FF */  ori       $t2, $t2, 0x97ff
/* 3A0680 E009E760 3C09FF2D */  lui       $t1, 0xff2d
/* 3A0684 E009E764 3529FEFF */  ori       $t1, $t1, 0xfeff
/* 3A0688 E009E768 8E480000 */  lw        $t0, ($s2)
/* 3A068C E009E76C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0690 E009E770 0100282D */  daddu     $a1, $t0, $zero
/* 3A0694 E009E774 3C0DFA00 */  lui       $t5, 0xfa00
/* 3A0698 E009E778 ACAD0000 */  sw        $t5, ($a1)
/* 3A069C E009E77C 8E22FFE8 */  lw        $v0, -0x18($s1)
/* 3A06A0 E009E780 8FAD00DC */  lw        $t5, 0xdc($sp)
/* 3A06A4 E009E784 2403FF00 */  addiu     $v1, $zero, -0x100
/* 3A06A8 E009E788 004D0018 */  mult      $v0, $t5
/* 3A06AC E009E78C 4406B000 */  mfc1      $a2, $f22
/* 3A06B0 E009E790 4407B000 */  mfc1      $a3, $f22
/* 3A06B4 E009E794 25080008 */  addiu     $t0, $t0, 8
/* 3A06B8 E009E798 AE480000 */  sw        $t0, ($s2)
/* 3A06BC E009E79C 00001012 */  mflo      $v0
/* 3A06C0 E009E7A0 00021203 */  sra       $v0, $v0, 8
/* 3A06C4 E009E7A4 00431025 */  or        $v0, $v0, $v1
/* 3A06C8 E009E7A8 ACA20004 */  sw        $v0, 4($a1)
/* 3A06CC E009E7AC AD0A0000 */  sw        $t2, ($t0)
/* 3A06D0 E009E7B0 AD090004 */  sw        $t1, 4($t0)
/* 3A06D4 E009E7B4 E7B80010 */  swc1      $f24, 0x10($sp)
/* 3A06D8 E009E7B8 8E25FFF4 */  lw        $a1, -0xc($s1)
/* 3A06DC E009E7BC 25080008 */  addiu     $t0, $t0, 8
/* 3A06E0 E009E7C0 0C080104 */  jal       shim_guRotateF
/* 3A06E4 E009E7C4 AE480000 */   sw       $t0, ($s2)
/* 3A06E8 E009E7C8 8E250000 */  lw        $a1, ($s1)
/* 3A06EC E009E7CC 4406B000 */  mfc1      $a2, $f22
/* 3A06F0 E009E7D0 4407B000 */  mfc1      $a3, $f22
/* 3A06F4 E009E7D4 0C080108 */  jal       shim_guTranslateF
/* 3A06F8 E009E7D8 0200202D */   daddu    $a0, $s0, $zero
/* 3A06FC E009E7DC 0200202D */  daddu     $a0, $s0, $zero
/* 3A0700 E009E7E0 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0704 E009E7E4 0C080114 */  jal       shim_guMtxCatF
/* 3A0708 E009E7E8 00A0302D */   daddu    $a2, $a1, $zero
/* 3A070C E009E7EC 4405A000 */  mfc1      $a1, $f20
/* 3A0710 E009E7F0 4406A000 */  mfc1      $a2, $f20
/* 3A0714 E009E7F4 4407A000 */  mfc1      $a3, $f20
/* 3A0718 E009E7F8 0C080110 */  jal       shim_guScaleF
/* 3A071C E009E7FC 0200202D */   daddu    $a0, $s0, $zero
/* 3A0720 E009E800 0200202D */  daddu     $a0, $s0, $zero
/* 3A0724 E009E804 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0728 E009E808 0C080114 */  jal       shim_guMtxCatF
/* 3A072C E009E80C 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0730 E009E810 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0734 E009E814 96A50000 */  lhu       $a1, ($s5)
/* 3A0738 E009E818 8EC20000 */  lw        $v0, ($s6)
/* 3A073C E009E81C 00052980 */  sll       $a1, $a1, 6
/* 3A0740 E009E820 00B32821 */  addu      $a1, $a1, $s3
/* 3A0744 E009E824 0C080118 */  jal       shim_guMtxF2L
/* 3A0748 E009E828 00452821 */   addu     $a1, $v0, $a1
/* 3A074C E009E82C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0750 E009E830 8E480000 */  lw        $t0, ($s2)
/* 3A0754 E009E834 4406B000 */  mfc1      $a2, $f22
/* 3A0758 E009E838 4407B000 */  mfc1      $a3, $f22
/* 3A075C E009E83C 96A30000 */  lhu       $v1, ($s5)
/* 3A0760 E009E840 0100282D */  daddu     $a1, $t0, $zero
/* 3A0764 E009E844 25080008 */  addiu     $t0, $t0, 8
/* 3A0768 E009E848 3C0DDA38 */  lui       $t5, 0xda38
/* 3A076C E009E84C 24620001 */  addiu     $v0, $v1, 1
/* 3A0770 E009E850 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3A0774 E009E854 00031980 */  sll       $v1, $v1, 6
/* 3A0778 E009E858 AE480000 */  sw        $t0, ($s2)
/* 3A077C E009E85C ACAD0000 */  sw        $t5, ($a1)
/* 3A0780 E009E860 A6A20000 */  sh        $v0, ($s5)
/* 3A0784 E009E864 8EC20000 */  lw        $v0, ($s6)
/* 3A0788 E009E868 00731821 */  addu      $v1, $v1, $s3
/* 3A078C E009E86C 00431021 */  addu      $v0, $v0, $v1
/* 3A0790 E009E870 ACA20004 */  sw        $v0, 4($a1)
/* 3A0794 E009E874 3C0DDE00 */  lui       $t5, 0xde00
/* 3A0798 E009E878 25020008 */  addiu     $v0, $t0, 8
/* 3A079C E009E87C AD0D0000 */  sw        $t5, ($t0)
/* 3A07A0 E009E880 3C03E00A */  lui       $v1, %hi(D_E009EDFC)
/* 3A07A4 E009E884 8C63EDFC */  lw        $v1, %lo(D_E009EDFC)($v1)
/* 3A07A8 E009E888 240D0040 */  addiu     $t5, $zero, 0x40
/* 3A07AC E009E88C AE420000 */  sw        $v0, ($s2)
/* 3A07B0 E009E890 AD1E0008 */  sw        $fp, 8($t0)
/* 3A07B4 E009E894 AD0D000C */  sw        $t5, 0xc($t0)
/* 3A07B8 E009E898 AD030004 */  sw        $v1, 4($t0)
/* 3A07BC E009E89C E7B80010 */  swc1      $f24, 0x10($sp)
/* 3A07C0 E009E8A0 8E25FFF4 */  lw        $a1, -0xc($s1)
/* 3A07C4 E009E8A4 25080010 */  addiu     $t0, $t0, 0x10
/* 3A07C8 E009E8A8 0C080104 */  jal       shim_guRotateF
/* 3A07CC E009E8AC AE480000 */   sw       $t0, ($s2)
/* 3A07D0 E009E8B0 C6220000 */  lwc1      $f2, ($s1)
/* 3A07D4 E009E8B4 3C0140A0 */  lui       $at, 0x40a0
/* 3A07D8 E009E8B8 44810000 */  mtc1      $at, $f0
/* 3A07DC E009E8BC 00000000 */  nop
/* 3A07E0 E009E8C0 46001080 */  add.s     $f2, $f2, $f0
/* 3A07E4 E009E8C4 4406B000 */  mfc1      $a2, $f22
/* 3A07E8 E009E8C8 4407B000 */  mfc1      $a3, $f22
/* 3A07EC E009E8CC 44051000 */  mfc1      $a1, $f2
/* 3A07F0 E009E8D0 0C080108 */  jal       shim_guTranslateF
/* 3A07F4 E009E8D4 0200202D */   daddu    $a0, $s0, $zero
/* 3A07F8 E009E8D8 0200202D */  daddu     $a0, $s0, $zero
/* 3A07FC E009E8DC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0800 E009E8E0 0C080114 */  jal       shim_guMtxCatF
/* 3A0804 E009E8E4 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0808 E009E8E8 3C01E00A */  lui       $at, %hi(D_E009EE28)
/* 3A080C E009E8EC D420EE28 */  ldc1      $f0, %lo(D_E009EE28)($at)
/* 3A0810 E009E8F0 4600A0A1 */  cvt.d.s   $f2, $f20
/* 3A0814 E009E8F4 46220001 */  sub.d     $f0, $f0, $f2
/* 3A0818 E009E8F8 46200020 */  cvt.s.d   $f0, $f0
/* 3A081C E009E8FC 44050000 */  mfc1      $a1, $f0
/* 3A0820 E009E900 0200202D */  daddu     $a0, $s0, $zero
/* 3A0824 E009E904 00A0302D */  daddu     $a2, $a1, $zero
/* 3A0828 E009E908 0C080110 */  jal       shim_guScaleF
/* 3A082C E009E90C 00A0382D */   daddu    $a3, $a1, $zero
/* 3A0830 E009E910 0200202D */  daddu     $a0, $s0, $zero
/* 3A0834 E009E914 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0838 E009E918 0C080114 */  jal       shim_guMtxCatF
/* 3A083C E009E91C 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0840 E009E920 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0844 E009E924 96A50000 */  lhu       $a1, ($s5)
/* 3A0848 E009E928 8EC20000 */  lw        $v0, ($s6)
/* 3A084C E009E92C 00052980 */  sll       $a1, $a1, 6
/* 3A0850 E009E930 00B32821 */  addu      $a1, $a1, $s3
/* 3A0854 E009E934 0C080118 */  jal       shim_guMtxF2L
/* 3A0858 E009E938 00452821 */   addu     $a1, $v0, $a1
/* 3A085C E009E93C 3C0CFF00 */  lui       $t4, 0xff00
/* 3A0860 E009E940 358CFF00 */  ori       $t4, $t4, 0xff00
/* 3A0864 E009E944 3C0BFF80 */  lui       $t3, 0xff80
/* 3A0868 E009E948 356BFF00 */  ori       $t3, $t3, 0xff00
/* 3A086C E009E94C 3C0AFC50 */  lui       $t2, 0xfc50
/* 3A0870 E009E950 354A96A1 */  ori       $t2, $t2, 0x96a1
/* 3A0874 E009E954 3C09332D */  lui       $t1, 0x332d
/* 3A0878 E009E958 3529FEFF */  ori       $t1, $t1, 0xfeff
/* 3A087C E009E95C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0880 E009E960 8E480000 */  lw        $t0, ($s2)
/* 3A0884 E009E964 96A30000 */  lhu       $v1, ($s5)
/* 3A0888 E009E968 3C014160 */  lui       $at, 0x4160
/* 3A088C E009E96C 44810000 */  mtc1      $at, $f0
/* 3A0890 E009E970 0100282D */  daddu     $a1, $t0, $zero
/* 3A0894 E009E974 25080008 */  addiu     $t0, $t0, 8
/* 3A0898 E009E978 3C0DDA38 */  lui       $t5, 0xda38
/* 3A089C E009E97C 24620001 */  addiu     $v0, $v1, 1
/* 3A08A0 E009E980 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3A08A4 E009E984 00031980 */  sll       $v1, $v1, 6
/* 3A08A8 E009E988 AE480000 */  sw        $t0, ($s2)
/* 3A08AC E009E98C ACAD0000 */  sw        $t5, ($a1)
/* 3A08B0 E009E990 A6A20000 */  sh        $v0, ($s5)
/* 3A08B4 E009E994 8EC20000 */  lw        $v0, ($s6)
/* 3A08B8 E009E998 00731821 */  addu      $v1, $v1, $s3
/* 3A08BC E009E99C 00431021 */  addu      $v0, $v0, $v1
/* 3A08C0 E009E9A0 ACA20004 */  sw        $v0, 4($a1)
/* 3A08C4 E009E9A4 25020008 */  addiu     $v0, $t0, 8
/* 3A08C8 E009E9A8 3C0DDE00 */  lui       $t5, 0xde00
/* 3A08CC E009E9AC AE420000 */  sw        $v0, ($s2)
/* 3A08D0 E009E9B0 25020010 */  addiu     $v0, $t0, 0x10
/* 3A08D4 E009E9B4 AD0D0000 */  sw        $t5, ($t0)
/* 3A08D8 E009E9B8 3C03E00A */  lui       $v1, %hi(D_E009EDF8)
/* 3A08DC E009E9BC 8C63EDF8 */  lw        $v1, %lo(D_E009EDF8)($v1)
/* 3A08E0 E009E9C0 240D0040 */  addiu     $t5, $zero, 0x40
/* 3A08E4 E009E9C4 AE420000 */  sw        $v0, ($s2)
/* 3A08E8 E009E9C8 25020018 */  addiu     $v0, $t0, 0x18
/* 3A08EC E009E9CC AD0D000C */  sw        $t5, 0xc($t0)
/* 3A08F0 E009E9D0 3C0DFA00 */  lui       $t5, 0xfa00
/* 3A08F4 E009E9D4 AD1E0008 */  sw        $fp, 8($t0)
/* 3A08F8 E009E9D8 AE420000 */  sw        $v0, ($s2)
/* 3A08FC E009E9DC AD0D0010 */  sw        $t5, 0x10($t0)
/* 3A0900 E009E9E0 AD030004 */  sw        $v1, 4($t0)
/* 3A0904 E009E9E4 8E22FFE8 */  lw        $v0, -0x18($s1)
/* 3A0908 E009E9E8 8FAD00DC */  lw        $t5, 0xdc($sp)
/* 3A090C E009E9EC 3C03FB00 */  lui       $v1, 0xfb00
/* 3A0910 E009E9F0 004D0018 */  mult      $v0, $t5
/* 3A0914 E009E9F4 AD030018 */  sw        $v1, 0x18($t0)
/* 3A0918 E009E9F8 AD0B001C */  sw        $t3, 0x1c($t0)
/* 3A091C E009E9FC AD0A0020 */  sw        $t2, 0x20($t0)
/* 3A0920 E009EA00 AD090024 */  sw        $t1, 0x24($t0)
/* 3A0924 E009EA04 00001012 */  mflo      $v0
/* 3A0928 E009EA08 00021243 */  sra       $v0, $v0, 9
/* 3A092C E009EA0C 304200FF */  andi      $v0, $v0, 0xff
/* 3A0930 E009EA10 004C1025 */  or        $v0, $v0, $t4
/* 3A0934 E009EA14 AD020014 */  sw        $v0, 0x14($t0)
/* 3A0938 E009EA18 C622FFF4 */  lwc1      $f2, -0xc($s1)
/* 3A093C E009EA1C 4406B000 */  mfc1      $a2, $f22
/* 3A0940 E009EA20 46001080 */  add.s     $f2, $f2, $f0
/* 3A0944 E009EA24 4407B000 */  mfc1      $a3, $f22
/* 3A0948 E009EA28 25020020 */  addiu     $v0, $t0, 0x20
/* 3A094C E009EA2C 44051000 */  mfc1      $a1, $f2
/* 3A0950 E009EA30 25080028 */  addiu     $t0, $t0, 0x28
/* 3A0954 E009EA34 AE420000 */  sw        $v0, ($s2)
/* 3A0958 E009EA38 AE480000 */  sw        $t0, ($s2)
/* 3A095C E009EA3C 0C080104 */  jal       shim_guRotateF
/* 3A0960 E009EA40 E7B80010 */   swc1     $f24, 0x10($sp)
/* 3A0964 E009EA44 3C02B60B */  lui       $v0, 0xb60b
/* 3A0968 E009EA48 344260B7 */  ori       $v0, $v0, 0x60b7
/* 3A096C E009EA4C 02820018 */  mult      $s4, $v0
/* 3A0970 E009EA50 00141FC3 */  sra       $v1, $s4, 0x1f
/* 3A0974 E009EA54 4406B000 */  mfc1      $a2, $f22
/* 3A0978 E009EA58 4407C000 */  mfc1      $a3, $f24
/* 3A097C E009EA5C 8FAD00D8 */  lw        $t5, 0xd8($sp)
/* 3A0980 E009EA60 00001010 */  mfhi      $v0
/* 3A0984 E009EA64 00541021 */  addu      $v0, $v0, $s4
/* 3A0988 E009EA68 00021143 */  sra       $v0, $v0, 5
/* 3A098C E009EA6C 00431023 */  subu      $v0, $v0, $v1
/* 3A0990 E009EA70 00021840 */  sll       $v1, $v0, 1
/* 3A0994 E009EA74 00621821 */  addu      $v1, $v1, $v0
/* 3A0998 E009EA78 00031100 */  sll       $v0, $v1, 4
/* 3A099C E009EA7C 00431023 */  subu      $v0, $v0, $v1
/* 3A09A0 E009EA80 02821023 */  subu      $v0, $s4, $v0
/* 3A09A4 E009EA84 004D1021 */  addu      $v0, $v0, $t5
/* 3A09A8 E009EA88 44822000 */  mtc1      $v0, $f4
/* 3A09AC E009EA8C 00000000 */  nop
/* 3A09B0 E009EA90 46802120 */  cvt.s.w   $f4, $f4
/* 3A09B4 E009EA94 44052000 */  mfc1      $a1, $f4
/* 3A09B8 E009EA98 0200202D */  daddu     $a0, $s0, $zero
/* 3A09BC E009EA9C 0C080104 */  jal       shim_guRotateF
/* 3A09C0 E009EAA0 E7B60010 */   swc1     $f22, 0x10($sp)
/* 3A09C4 E009EAA4 0200202D */  daddu     $a0, $s0, $zero
/* 3A09C8 E009EAA8 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A09CC E009EAAC 0C080114 */  jal       shim_guMtxCatF
/* 3A09D0 E009EAB0 00A0302D */   daddu    $a2, $a1, $zero
/* 3A09D4 E009EAB4 3C0541A0 */  lui       $a1, 0x41a0
/* 3A09D8 E009EAB8 4406B000 */  mfc1      $a2, $f22
/* 3A09DC E009EABC 4407B000 */  mfc1      $a3, $f22
/* 3A09E0 E009EAC0 0C080108 */  jal       shim_guTranslateF
/* 3A09E4 E009EAC4 0200202D */   daddu    $a0, $s0, $zero
/* 3A09E8 E009EAC8 0200202D */  daddu     $a0, $s0, $zero
/* 3A09EC E009EACC 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A09F0 E009EAD0 0C080114 */  jal       shim_guMtxCatF
/* 3A09F4 E009EAD4 00A0302D */   daddu    $a2, $a1, $zero
/* 3A09F8 E009EAD8 C6200000 */  lwc1      $f0, ($s1)
/* 3A09FC E009EADC 461C0001 */  sub.s     $f0, $f0, $f28
/* 3A0A00 E009EAE0 3C01E00A */  lui       $at, %hi(D_E009EE30)
/* 3A0A04 E009EAE4 D422EE30 */  ldc1      $f2, %lo(D_E009EE30)($at)
/* 3A0A08 E009EAE8 46000021 */  cvt.d.s   $f0, $f0
/* 3A0A0C E009EAEC 46220002 */  mul.d     $f0, $f0, $f2
/* 3A0A10 E009EAF0 00000000 */  nop
/* 3A0A14 E009EAF4 3C013FF0 */  lui       $at, 0x3ff0
/* 3A0A18 E009EAF8 44811800 */  mtc1      $at, $f3
/* 3A0A1C E009EAFC 44801000 */  mtc1      $zero, $f2
/* 3A0A20 E009EB00 00000000 */  nop
/* 3A0A24 E009EB04 46220080 */  add.d     $f2, $f0, $f2
/* 3A0A28 E009EB08 4620D001 */  sub.d     $f0, $f26, $f0
/* 3A0A2C E009EB0C 4407C000 */  mfc1      $a3, $f24
/* 3A0A30 E009EB10 462010A0 */  cvt.s.d   $f2, $f2
/* 3A0A34 E009EB14 46200020 */  cvt.s.d   $f0, $f0
/* 3A0A38 E009EB18 44051000 */  mfc1      $a1, $f2
/* 3A0A3C E009EB1C 44060000 */  mfc1      $a2, $f0
/* 3A0A40 E009EB20 0C080110 */  jal       shim_guScaleF
/* 3A0A44 E009EB24 0200202D */   daddu    $a0, $s0, $zero
/* 3A0A48 E009EB28 0200202D */  daddu     $a0, $s0, $zero
/* 3A0A4C E009EB2C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0A50 E009EB30 0C080114 */  jal       shim_guMtxCatF
/* 3A0A54 E009EB34 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0A58 E009EB38 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0A5C E009EB3C 96A50000 */  lhu       $a1, ($s5)
/* 3A0A60 E009EB40 8EC20000 */  lw        $v0, ($s6)
/* 3A0A64 E009EB44 00052980 */  sll       $a1, $a1, 6
/* 3A0A68 E009EB48 00B32821 */  addu      $a1, $a1, $s3
/* 3A0A6C E009EB4C 0C080118 */  jal       shim_guMtxF2L
/* 3A0A70 E009EB50 00452821 */   addu     $a1, $v0, $a1
/* 3A0A74 E009EB54 3C09FF40 */  lui       $t1, 0xff40
/* 3A0A78 E009EB58 8E480000 */  lw        $t0, ($s2)
/* 3A0A7C E009EB5C 4406B000 */  mfc1      $a2, $f22
/* 3A0A80 E009EB60 96A50000 */  lhu       $a1, ($s5)
/* 3A0A84 E009EB64 0100202D */  daddu     $a0, $t0, $zero
/* 3A0A88 E009EB68 25080008 */  addiu     $t0, $t0, 8
/* 3A0A8C E009EB6C 3C0DDA38 */  lui       $t5, 0xda38
/* 3A0A90 E009EB70 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3A0A94 E009EB74 00021180 */  sll       $v0, $v0, 6
/* 3A0A98 E009EB78 AC8D0000 */  sw        $t5, ($a0)
/* 3A0A9C E009EB7C 8EC30000 */  lw        $v1, ($s6)
/* 3A0AA0 E009EB80 00531021 */  addu      $v0, $v0, $s3
/* 3A0AA4 E009EB84 00621821 */  addu      $v1, $v1, $v0
/* 3A0AA8 E009EB88 AC830004 */  sw        $v1, 4($a0)
/* 3A0AAC E009EB8C 3C0DDE00 */  lui       $t5, 0xde00
/* 3A0AB0 E009EB90 AD0D0000 */  sw        $t5, ($t0)
/* 3A0AB4 E009EB94 3C02E00A */  lui       $v0, %hi(D_E009EDF4)
/* 3A0AB8 E009EB98 8C42EDF4 */  lw        $v0, %lo(D_E009EDF4)($v0)
/* 3A0ABC E009EB9C 240D0040 */  addiu     $t5, $zero, 0x40
/* 3A0AC0 E009EBA0 AD0D000C */  sw        $t5, 0xc($t0)
/* 3A0AC4 E009EBA4 3C0DFA00 */  lui       $t5, 0xfa00
/* 3A0AC8 E009EBA8 AD1E0008 */  sw        $fp, 8($t0)
/* 3A0ACC E009EBAC AD0D0010 */  sw        $t5, 0x10($t0)
/* 3A0AD0 E009EBB0 AD020004 */  sw        $v0, 4($t0)
/* 3A0AD4 E009EBB4 8E22FFE8 */  lw        $v0, -0x18($s1)
/* 3A0AD8 E009EBB8 35294000 */  ori       $t1, $t1, 0x4000
/* 3A0ADC E009EBBC AE480000 */  sw        $t0, ($s2)
/* 3A0AE0 E009EBC0 8FAD00DC */  lw        $t5, 0xdc($sp)
/* 3A0AE4 E009EBC4 3C014208 */  lui       $at, 0x4208
/* 3A0AE8 E009EBC8 44810000 */  mtc1      $at, $f0
/* 3A0AEC E009EBCC 004D0018 */  mult      $v0, $t5
/* 3A0AF0 E009EBD0 24A50001 */  addiu     $a1, $a1, 1
/* 3A0AF4 E009EBD4 A6A50000 */  sh        $a1, ($s5)
/* 3A0AF8 E009EBD8 25020008 */  addiu     $v0, $t0, 8
/* 3A0AFC E009EBDC AE420000 */  sw        $v0, ($s2)
/* 3A0B00 E009EBE0 00001812 */  mflo      $v1
/* 3A0B04 E009EBE4 00031203 */  sra       $v0, $v1, 8
/* 3A0B08 E009EBE8 304200FF */  andi      $v0, $v0, 0xff
/* 3A0B0C E009EBEC 00491025 */  or        $v0, $v0, $t1
/* 3A0B10 E009EBF0 AD020014 */  sw        $v0, 0x14($t0)
/* 3A0B14 E009EBF4 C622FFF4 */  lwc1      $f2, -0xc($s1)
/* 3A0B18 E009EBF8 25020010 */  addiu     $v0, $t0, 0x10
/* 3A0B1C E009EBFC 46001080 */  add.s     $f2, $f2, $f0
/* 3A0B20 E009EC00 AE420000 */  sw        $v0, ($s2)
/* 3A0B24 E009EC04 C7A000D8 */  lwc1      $f0, 0xd8($sp)
/* 3A0B28 E009EC08 46800020 */  cvt.s.w   $f0, $f0
/* 3A0B2C E009EC0C 46001080 */  add.s     $f2, $f2, $f0
/* 3A0B30 E009EC10 4407B000 */  mfc1      $a3, $f22
/* 3A0B34 E009EC14 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0B38 E009EC18 44051000 */  mfc1      $a1, $f2
/* 3A0B3C E009EC1C 25080018 */  addiu     $t0, $t0, 0x18
/* 3A0B40 E009EC20 AE480000 */  sw        $t0, ($s2)
/* 3A0B44 E009EC24 0C080104 */  jal       shim_guRotateF
/* 3A0B48 E009EC28 E7B80010 */   swc1     $f24, 0x10($sp)
/* 3A0B4C E009EC2C 001710C0 */  sll       $v0, $s7, 3
/* 3A0B50 E009EC30 00571021 */  addu      $v0, $v0, $s7
/* 3A0B54 E009EC34 00021080 */  sll       $v0, $v0, 2
/* 3A0B58 E009EC38 00571023 */  subu      $v0, $v0, $s7
/* 3A0B5C E009EC3C 44822000 */  mtc1      $v0, $f4
/* 3A0B60 E009EC40 00000000 */  nop
/* 3A0B64 E009EC44 46802120 */  cvt.s.w   $f4, $f4
/* 3A0B68 E009EC48 4406B000 */  mfc1      $a2, $f22
/* 3A0B6C E009EC4C 4407C000 */  mfc1      $a3, $f24
/* 3A0B70 E009EC50 44052000 */  mfc1      $a1, $f4
/* 3A0B74 E009EC54 0200202D */  daddu     $a0, $s0, $zero
/* 3A0B78 E009EC58 0C080104 */  jal       shim_guRotateF
/* 3A0B7C E009EC5C E7B60010 */   swc1     $f22, 0x10($sp)
/* 3A0B80 E009EC60 0200202D */  daddu     $a0, $s0, $zero
/* 3A0B84 E009EC64 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0B88 E009EC68 0C080114 */  jal       shim_guMtxCatF
/* 3A0B8C E009EC6C 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0B90 E009EC70 3C054170 */  lui       $a1, 0x4170
/* 3A0B94 E009EC74 4406B000 */  mfc1      $a2, $f22
/* 3A0B98 E009EC78 4407B000 */  mfc1      $a3, $f22
/* 3A0B9C E009EC7C 0C080108 */  jal       shim_guTranslateF
/* 3A0BA0 E009EC80 0200202D */   daddu    $a0, $s0, $zero
/* 3A0BA4 E009EC84 0200202D */  daddu     $a0, $s0, $zero
/* 3A0BA8 E009EC88 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0BAC E009EC8C 0C080114 */  jal       shim_guMtxCatF
/* 3A0BB0 E009EC90 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0BB4 E009EC94 C6200000 */  lwc1      $f0, ($s1)
/* 3A0BB8 E009EC98 461C0001 */  sub.s     $f0, $f0, $f28
/* 3A0BBC E009EC9C 3C01E00A */  lui       $at, %hi(D_E009EE38)
/* 3A0BC0 E009ECA0 D422EE38 */  ldc1      $f2, %lo(D_E009EE38)($at)
/* 3A0BC4 E009ECA4 46000021 */  cvt.d.s   $f0, $f0
/* 3A0BC8 E009ECA8 46220002 */  mul.d     $f0, $f0, $f2
/* 3A0BCC E009ECAC 00000000 */  nop
/* 3A0BD0 E009ECB0 463A0000 */  add.d     $f0, $f0, $f26
/* 3A0BD4 E009ECB4 4406C000 */  mfc1      $a2, $f24
/* 3A0BD8 E009ECB8 4407C000 */  mfc1      $a3, $f24
/* 3A0BDC E009ECBC 46200020 */  cvt.s.d   $f0, $f0
/* 3A0BE0 E009ECC0 44050000 */  mfc1      $a1, $f0
/* 3A0BE4 E009ECC4 0C080110 */  jal       shim_guScaleF
/* 3A0BE8 E009ECC8 0200202D */   daddu    $a0, $s0, $zero
/* 3A0BEC E009ECCC 0200202D */  daddu     $a0, $s0, $zero
/* 3A0BF0 E009ECD0 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A0BF4 E009ECD4 0C080114 */  jal       shim_guMtxCatF
/* 3A0BF8 E009ECD8 00A0302D */   daddu    $a2, $a1, $zero
/* 3A0BFC E009ECDC 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A0C00 E009ECE0 96A50000 */  lhu       $a1, ($s5)
/* 3A0C04 E009ECE4 8EC20000 */  lw        $v0, ($s6)
/* 3A0C08 E009ECE8 00052980 */  sll       $a1, $a1, 6
/* 3A0C0C E009ECEC 00B32821 */  addu      $a1, $a1, $s3
/* 3A0C10 E009ECF0 0C080118 */  jal       shim_guMtxF2L
/* 3A0C14 E009ECF4 00452821 */   addu     $a1, $v0, $a1
/* 3A0C18 E009ECF8 8E440000 */  lw        $a0, ($s2)
/* 3A0C1C E009ECFC 96A30000 */  lhu       $v1, ($s5)
/* 3A0C20 E009ED00 0080282D */  daddu     $a1, $a0, $zero
/* 3A0C24 E009ED04 24840008 */  addiu     $a0, $a0, 8
/* 3A0C28 E009ED08 3C0DDA38 */  lui       $t5, 0xda38
/* 3A0C2C E009ED0C 24620001 */  addiu     $v0, $v1, 1
/* 3A0C30 E009ED10 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3A0C34 E009ED14 00031980 */  sll       $v1, $v1, 6
/* 3A0C38 E009ED18 AE440000 */  sw        $a0, ($s2)
/* 3A0C3C E009ED1C ACAD0000 */  sw        $t5, ($a1)
/* 3A0C40 E009ED20 A6A20000 */  sh        $v0, ($s5)
/* 3A0C44 E009ED24 8EC20000 */  lw        $v0, ($s6)
/* 3A0C48 E009ED28 00731821 */  addu      $v1, $v1, $s3
/* 3A0C4C E009ED2C 00431021 */  addu      $v0, $v0, $v1
/* 3A0C50 E009ED30 ACA20004 */  sw        $v0, 4($a1)
/* 3A0C54 E009ED34 24820008 */  addiu     $v0, $a0, 8
/* 3A0C58 E009ED38 3C0DDE00 */  lui       $t5, 0xde00
/* 3A0C5C E009ED3C AE420000 */  sw        $v0, ($s2)
/* 3A0C60 E009ED40 24820010 */  addiu     $v0, $a0, 0x10
/* 3A0C64 E009ED44 AC8D0000 */  sw        $t5, ($a0)
/* 3A0C68 E009ED48 3C03E00A */  lui       $v1, %hi(D_E009EDF0)
/* 3A0C6C E009ED4C 8C63EDF0 */  lw        $v1, %lo(D_E009EDF0)($v1)
/* 3A0C70 E009ED50 240D0040 */  addiu     $t5, $zero, 0x40
/* 3A0C74 E009ED54 AE420000 */  sw        $v0, ($s2)
/* 3A0C78 E009ED58 AC9E0008 */  sw        $fp, 8($a0)
/* 3A0C7C E009ED5C AC8D000C */  sw        $t5, 0xc($a0)
/* 3A0C80 E009ED60 AC830004 */  sw        $v1, 4($a0)
/* 3A0C84 E009ED64 2694000A */  addiu     $s4, $s4, 0xa
.LE009ED68:
/* 3A0C88 E009ED68 8FAD0130 */  lw        $t5, 0x130($sp)
/* 3A0C8C E009ED6C 26F70001 */  addiu     $s7, $s7, 1
/* 3A0C90 E009ED70 8DA20008 */  lw        $v0, 8($t5)
/* 3A0C94 E009ED74 02E2102A */  slt       $v0, $s7, $v0
/* 3A0C98 E009ED78 1440FE72 */  bnez      $v0, .LE009E744
/* 3A0C9C E009ED7C 26310034 */   addiu    $s1, $s1, 0x34
.LE009ED80:
/* 3A0CA0 E009ED80 3C05D838 */  lui       $a1, 0xd838
/* 3A0CA4 E009ED84 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3A0CA8 E009ED88 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3A0CAC E009ED8C 8C620000 */  lw        $v0, ($v1)
/* 3A0CB0 E009ED90 34A50002 */  ori       $a1, $a1, 2
/* 3A0CB4 E009ED94 0040202D */  daddu     $a0, $v0, $zero
/* 3A0CB8 E009ED98 24420008 */  addiu     $v0, $v0, 8
/* 3A0CBC E009ED9C AC620000 */  sw        $v0, ($v1)
/* 3A0CC0 E009EDA0 24020040 */  addiu     $v0, $zero, 0x40
/* 3A0CC4 E009EDA4 AC850000 */  sw        $a1, ($a0)
/* 3A0CC8 E009EDA8 AC820004 */  sw        $v0, 4($a0)
/* 3A0CCC E009EDAC 8FBF0104 */  lw        $ra, 0x104($sp)
/* 3A0CD0 E009EDB0 8FBE0100 */  lw        $fp, 0x100($sp)
/* 3A0CD4 E009EDB4 8FB700FC */  lw        $s7, 0xfc($sp)
/* 3A0CD8 E009EDB8 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 3A0CDC E009EDBC 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 3A0CE0 E009EDC0 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 3A0CE4 E009EDC4 8FB300EC */  lw        $s3, 0xec($sp)
/* 3A0CE8 E009EDC8 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 3A0CEC E009EDCC 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 3A0CF0 E009EDD0 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 3A0CF4 E009EDD4 D7BC0128 */  ldc1      $f28, 0x128($sp)
/* 3A0CF8 E009EDD8 D7BA0120 */  ldc1      $f26, 0x120($sp)
/* 3A0CFC E009EDDC D7B80118 */  ldc1      $f24, 0x118($sp)
/* 3A0D00 E009EDE0 D7B60110 */  ldc1      $f22, 0x110($sp)
/* 3A0D04 E009EDE4 D7B40108 */  ldc1      $f20, 0x108($sp)
/* 3A0D08 E009EDE8 03E00008 */  jr        $ra
/* 3A0D0C E009EDEC 27BD0130 */   addiu    $sp, $sp, 0x130
