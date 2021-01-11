.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AA404
/* 3AAD24 E00AA404 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 3AAD28 E00AA408 3C03DB06 */  lui       $v1, 0xdb06
/* 3AAD2C E00AA40C AFB1009C */  sw        $s1, 0x9c($sp)
/* 3AAD30 E00AA410 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3AAD34 E00AA414 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3AAD38 E00AA418 34630024 */  ori       $v1, $v1, 0x24
/* 3AAD3C E00AA41C AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3AAD40 E00AA420 3C17E700 */  lui       $s7, 0xe700
/* 3AAD44 E00AA424 AFBF00B8 */  sw        $ra, 0xb8($sp)
/* 3AAD48 E00AA428 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3AAD4C E00AA42C AFB500AC */  sw        $s5, 0xac($sp)
/* 3AAD50 E00AA430 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3AAD54 E00AA434 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3AAD58 E00AA438 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3AAD5C E00AA43C AFB00098 */  sw        $s0, 0x98($sp)
/* 3AAD60 E00AA440 8E250000 */  lw        $a1, ($s1)
/* 3AAD64 E00AA444 8C93000C */  lw        $s3, 0xc($a0)
/* 3AAD68 E00AA448 00A0102D */  daddu     $v0, $a1, $zero
/* 3AAD6C E00AA44C 8E720024 */  lw        $s2, 0x24($s3)
/* 3AAD70 E00AA450 8E750000 */  lw        $s5, ($s3)
/* 3AAD74 E00AA454 24A50008 */  addiu     $a1, $a1, 8
/* 3AAD78 E00AA458 AC570000 */  sw        $s7, ($v0)
/* 3AAD7C E00AA45C AC400004 */  sw        $zero, 4($v0)
/* 3AAD80 E00AA460 ACA30000 */  sw        $v1, ($a1)
/* 3AAD84 E00AA464 8C820010 */  lw        $v0, 0x10($a0)
/* 3AAD88 E00AA468 AE250000 */  sw        $a1, ($s1)
/* 3AAD8C E00AA46C 8C42001C */  lw        $v0, 0x1c($v0)
/* 3AAD90 E00AA470 3C038000 */  lui       $v1, 0x8000
/* 3AAD94 E00AA474 00431021 */  addu      $v0, $v0, $v1
/* 3AAD98 E00AA478 ACA20004 */  sw        $v0, 4($a1)
/* 3AAD9C E00AA47C 8E62002C */  lw        $v0, 0x2c($s3)
/* 3AADA0 E00AA480 24A50008 */  addiu     $a1, $a1, 8
/* 3AADA4 E00AA484 AE250000 */  sw        $a1, ($s1)
/* 3AADA8 E00AA488 3C01E00B */  lui       $at, %hi(D_E00AA6EC)
/* 3AADAC E00AA48C 00220821 */  addu      $at, $at, $v0
/* 3AADB0 E00AA490 8022A6EC */  lb        $v0, %lo(D_E00AA6EC)($at)
/* 3AADB4 E00AA494 3C013E99 */  lui       $at, 0x3e99
/* 3AADB8 E00AA498 3421999A */  ori       $at, $at, 0x999a
/* 3AADBC E00AA49C 44811000 */  mtc1      $at, $f2
/* 3AADC0 E00AA4A0 44820000 */  mtc1      $v0, $f0
/* 3AADC4 E00AA4A4 00000000 */  nop
/* 3AADC8 E00AA4A8 46800020 */  cvt.s.w   $f0, $f0
/* 3AADCC E00AA4AC 46020002 */  mul.s     $f0, $f0, $f2
/* 3AADD0 E00AA4B0 00000000 */  nop
/* 3AADD4 E00AA4B4 C6620010 */  lwc1      $f2, 0x10($s3)
/* 3AADD8 E00AA4B8 46001080 */  add.s     $f2, $f2, $f0
/* 3AADDC E00AA4BC 8E65000C */  lw        $a1, 0xc($s3)
/* 3AADE0 E00AA4C0 8E670014 */  lw        $a3, 0x14($s3)
/* 3AADE4 E00AA4C4 44061000 */  mfc1      $a2, $f2
/* 3AADE8 E00AA4C8 0C080108 */  jal       func_E0200420
/* 3AADEC E00AA4CC 27A40018 */   addiu    $a0, $sp, 0x18
/* 3AADF0 E00AA4D0 3C160001 */  lui       $s6, 1
/* 3AADF4 E00AA4D4 3C073F80 */  lui       $a3, 0x3f80
/* 3AADF8 E00AA4D8 44800000 */  mtc1      $zero, $f0
/* 3AADFC E00AA4DC 27B00058 */  addiu     $s0, $sp, 0x58
/* 3AAE00 E00AA4E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3AAE04 E00AA4E4 8E650028 */  lw        $a1, 0x28($s3)
/* 3AAE08 E00AA4E8 44060000 */  mfc1      $a2, $f0
/* 3AAE0C E00AA4EC 0C080104 */  jal       func_E0200410
/* 3AAE10 E00AA4F0 0200202D */   daddu    $a0, $s0, $zero
/* 3AAE14 E00AA4F4 0200202D */  daddu     $a0, $s0, $zero
/* 3AAE18 E00AA4F8 27A50018 */  addiu     $a1, $sp, 0x18
/* 3AAE1C E00AA4FC 0C080114 */  jal       func_E0200450
/* 3AAE20 E00AA500 00A0302D */   daddu    $a2, $a1, $zero
/* 3AAE24 E00AA504 3C013CA3 */  lui       $at, 0x3ca3
/* 3AAE28 E00AA508 3421D70A */  ori       $at, $at, 0xd70a
/* 3AAE2C E00AA50C 44810000 */  mtc1      $at, $f0
/* 3AAE30 E00AA510 36D61630 */  ori       $s6, $s6, 0x1630
/* 3AAE34 E00AA514 44050000 */  mfc1      $a1, $f0
/* 3AAE38 E00AA518 0200202D */  daddu     $a0, $s0, $zero
/* 3AAE3C E00AA51C 00A0302D */  daddu     $a2, $a1, $zero
/* 3AAE40 E00AA520 0C080110 */  jal       func_E0200440
/* 3AAE44 E00AA524 00A0382D */   daddu    $a3, $a1, $zero
/* 3AAE48 E00AA528 0200202D */  daddu     $a0, $s0, $zero
/* 3AAE4C E00AA52C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3AAE50 E00AA530 0C080114 */  jal       func_E0200450
/* 3AAE54 E00AA534 00A0302D */   daddu    $a2, $a1, $zero
/* 3AAE58 E00AA538 27A40018 */  addiu     $a0, $sp, 0x18
/* 3AAE5C E00AA53C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3AAE60 E00AA540 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3AAE64 E00AA544 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3AAE68 E00AA548 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3AAE6C E00AA54C 96050000 */  lhu       $a1, ($s0)
/* 3AAE70 E00AA550 8E820000 */  lw        $v0, ($s4)
/* 3AAE74 E00AA554 00052980 */  sll       $a1, $a1, 6
/* 3AAE78 E00AA558 00B62821 */  addu      $a1, $a1, $s6
/* 3AAE7C E00AA55C 0C080118 */  jal       func_E0200460
/* 3AAE80 E00AA560 00452821 */   addu     $a1, $v0, $a1
/* 3AAE84 E00AA564 3C03DA38 */  lui       $v1, 0xda38
/* 3AAE88 E00AA568 34630002 */  ori       $v1, $v1, 2
/* 3AAE8C E00AA56C 3C060100 */  lui       $a2, 0x100
/* 3AAE90 E00AA570 34C6600C */  ori       $a2, $a2, 0x600c
/* 3AAE94 E00AA574 3C07D838 */  lui       $a3, 0xd838
/* 3AAE98 E00AA578 34E70002 */  ori       $a3, $a3, 2
/* 3AAE9C E00AA57C 325200FF */  andi      $s2, $s2, 0xff
/* 3AAEA0 E00AA580 0015A880 */  sll       $s5, $s5, 2
/* 3AAEA4 E00AA584 8E240000 */  lw        $a0, ($s1)
/* 3AAEA8 E00AA588 96020000 */  lhu       $v0, ($s0)
/* 3AAEAC E00AA58C 0080282D */  daddu     $a1, $a0, $zero
/* 3AAEB0 E00AA590 24840008 */  addiu     $a0, $a0, 8
/* 3AAEB4 E00AA594 AE240000 */  sw        $a0, ($s1)
/* 3AAEB8 E00AA598 ACA30000 */  sw        $v1, ($a1)
/* 3AAEBC E00AA59C 24430001 */  addiu     $v1, $v0, 1
/* 3AAEC0 E00AA5A0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3AAEC4 E00AA5A4 00021180 */  sll       $v0, $v0, 6
/* 3AAEC8 E00AA5A8 A6030000 */  sh        $v1, ($s0)
/* 3AAECC E00AA5AC 8E830000 */  lw        $v1, ($s4)
/* 3AAED0 E00AA5B0 00561021 */  addu      $v0, $v0, $s6
/* 3AAED4 E00AA5B4 00621821 */  addu      $v1, $v1, $v0
/* 3AAED8 E00AA5B8 24820008 */  addiu     $v0, $a0, 8
/* 3AAEDC E00AA5BC ACA30004 */  sw        $v1, 4($a1)
/* 3AAEE0 E00AA5C0 AE220000 */  sw        $v0, ($s1)
/* 3AAEE4 E00AA5C4 3C02FA00 */  lui       $v0, 0xfa00
/* 3AAEE8 E00AA5C8 AC820000 */  sw        $v0, ($a0)
/* 3AAEEC E00AA5CC 00121600 */  sll       $v0, $s2, 0x18
/* 3AAEF0 E00AA5D0 00121C00 */  sll       $v1, $s2, 0x10
/* 3AAEF4 E00AA5D4 00431025 */  or        $v0, $v0, $v1
/* 3AAEF8 E00AA5D8 00129200 */  sll       $s2, $s2, 8
/* 3AAEFC E00AA5DC 00521025 */  or        $v0, $v0, $s2
/* 3AAF00 E00AA5E0 344200FF */  ori       $v0, $v0, 0xff
/* 3AAF04 E00AA5E4 AC820004 */  sw        $v0, 4($a0)
/* 3AAF08 E00AA5E8 24820010 */  addiu     $v0, $a0, 0x10
/* 3AAF0C E00AA5EC 3C03DE00 */  lui       $v1, 0xde00
/* 3AAF10 E00AA5F0 AE220000 */  sw        $v0, ($s1)
/* 3AAF14 E00AA5F4 3C020900 */  lui       $v0, 0x900
/* 3AAF18 E00AA5F8 24423880 */  addiu     $v0, $v0, 0x3880
/* 3AAF1C E00AA5FC AC82000C */  sw        $v0, 0xc($a0)
/* 3AAF20 E00AA600 24820018 */  addiu     $v0, $a0, 0x18
/* 3AAF24 E00AA604 AC830008 */  sw        $v1, 8($a0)
/* 3AAF28 E00AA608 AE220000 */  sw        $v0, ($s1)
/* 3AAF2C E00AA60C AC830010 */  sw        $v1, 0x10($a0)
/* 3AAF30 E00AA610 3C05E00B */  lui       $a1, %hi(D_E00AA6C0)
/* 3AAF34 E00AA614 00B52821 */  addu      $a1, $a1, $s5
/* 3AAF38 E00AA618 8CA5A6C0 */  lw        $a1, %lo(D_E00AA6C0)($a1)
/* 3AAF3C E00AA61C 24820020 */  addiu     $v0, $a0, 0x20
/* 3AAF40 E00AA620 AE220000 */  sw        $v0, ($s1)
/* 3AAF44 E00AA624 24820028 */  addiu     $v0, $a0, 0x28
/* 3AAF48 E00AA628 AC860018 */  sw        $a2, 0x18($a0)
/* 3AAF4C E00AA62C AE220000 */  sw        $v0, ($s1)
/* 3AAF50 E00AA630 24820030 */  addiu     $v0, $a0, 0x30
/* 3AAF54 E00AA634 AE220000 */  sw        $v0, ($s1)
/* 3AAF58 E00AA638 AC850014 */  sw        $a1, 0x14($a0)
/* 3AAF5C E00AA63C 8E65002C */  lw        $a1, 0x2c($s3)
/* 3AAF60 E00AA640 24820038 */  addiu     $v0, $a0, 0x38
/* 3AAF64 E00AA644 AE220000 */  sw        $v0, ($s1)
/* 3AAF68 E00AA648 3C020900 */  lui       $v0, 0x900
/* 3AAF6C E00AA64C 24423DC8 */  addiu     $v0, $v0, 0x3dc8
/* 3AAF70 E00AA650 AC820024 */  sw        $v0, 0x24($a0)
/* 3AAF74 E00AA654 24020040 */  addiu     $v0, $zero, 0x40
/* 3AAF78 E00AA658 AC830020 */  sw        $v1, 0x20($a0)
/* 3AAF7C E00AA65C 3C030900 */  lui       $v1, 0x900
/* 3AAF80 E00AA660 24632D40 */  addiu     $v1, $v1, 0x2d40
/* 3AAF84 E00AA664 AC870028 */  sw        $a3, 0x28($a0)
/* 3AAF88 E00AA668 AC82002C */  sw        $v0, 0x2c($a0)
/* 3AAF8C E00AA66C AC970030 */  sw        $s7, 0x30($a0)
/* 3AAF90 E00AA670 AC800034 */  sw        $zero, 0x34($a0)
/* 3AAF94 E00AA674 00051040 */  sll       $v0, $a1, 1
/* 3AAF98 E00AA678 00451021 */  addu      $v0, $v0, $a1
/* 3AAF9C E00AA67C 00021140 */  sll       $v0, $v0, 5
/* 3AAFA0 E00AA680 00431021 */  addu      $v0, $v0, $v1
/* 3AAFA4 E00AA684 AC82001C */  sw        $v0, 0x1c($a0)
/* 3AAFA8 E00AA688 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* 3AAFAC E00AA68C 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3AAFB0 E00AA690 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3AAFB4 E00AA694 8FB500AC */  lw        $s5, 0xac($sp)
/* 3AAFB8 E00AA698 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3AAFBC E00AA69C 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3AAFC0 E00AA6A0 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3AAFC4 E00AA6A4 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3AAFC8 E00AA6A8 8FB00098 */  lw        $s0, 0x98($sp)
/* 3AAFCC E00AA6AC 03E00008 */  jr        $ra
/* 3AAFD0 E00AA6B0 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 3AAFD4 E00AA6B4 00000000 */  nop
/* 3AAFD8 E00AA6B8 00000000 */  nop
/* 3AAFDC E00AA6BC 00000000 */  nop
