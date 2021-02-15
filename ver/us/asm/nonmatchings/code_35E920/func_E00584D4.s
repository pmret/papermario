.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00584D4
/* 35EDF4 E00584D4 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* 35EDF8 E00584D8 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 35EDFC E00584DC 0080B82D */  daddu     $s7, $a0, $zero
/* 35EE00 E00584E0 3C02DB06 */  lui       $v0, 0xdb06
/* 35EE04 E00584E4 34420024 */  ori       $v0, $v0, 0x24
/* 35EE08 E00584E8 3C061464 */  lui       $a2, 0x1464
/* 35EE0C E00584EC 34C61400 */  ori       $a2, $a2, 0x1400
/* 35EE10 E00584F0 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 35EE14 E00584F4 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 35EE18 E00584F8 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 35EE1C E00584FC AFBF00F8 */  sw        $ra, 0xf8($sp)
/* 35EE20 E0058500 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 35EE24 E0058504 AFB500EC */  sw        $s5, 0xec($sp)
/* 35EE28 E0058508 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 35EE2C E005850C AFB200E0 */  sw        $s2, 0xe0($sp)
/* 35EE30 E0058510 AFB100DC */  sw        $s1, 0xdc($sp)
/* 35EE34 E0058514 AFB000D8 */  sw        $s0, 0xd8($sp)
/* 35EE38 E0058518 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 35EE3C E005851C F7B40100 */  sdc1      $f20, 0x100($sp)
/* 35EE40 E0058520 8E650000 */  lw        $a1, ($s3)
/* 35EE44 E0058524 8EF0000C */  lw        $s0, 0xc($s7)
/* 35EE48 E0058528 00A0202D */  daddu     $a0, $a1, $zero
/* 35EE4C E005852C 24A50008 */  addiu     $a1, $a1, 8
/* 35EE50 E0058530 AE650000 */  sw        $a1, ($s3)
/* 35EE54 E0058534 AC820000 */  sw        $v0, ($a0)
/* 35EE58 E0058538 24A20008 */  addiu     $v0, $a1, 8
/* 35EE5C E005853C AE620000 */  sw        $v0, ($s3)
/* 35EE60 E0058540 8EE30010 */  lw        $v1, 0x10($s7)
/* 35EE64 E0058544 24A20010 */  addiu     $v0, $a1, 0x10
/* 35EE68 E0058548 AE620000 */  sw        $v0, ($s3)
/* 35EE6C E005854C 8C62001C */  lw        $v0, 0x1c($v1)
/* 35EE70 E0058550 3C038000 */  lui       $v1, 0x8000
/* 35EE74 E0058554 00431021 */  addu      $v0, $v0, $v1
/* 35EE78 E0058558 AC820004 */  sw        $v0, 4($a0)
/* 35EE7C E005855C 3C02DE00 */  lui       $v0, 0xde00
/* 35EE80 E0058560 ACA20000 */  sw        $v0, ($a1)
/* 35EE84 E0058564 3C020900 */  lui       $v0, 0x900
/* 35EE88 E0058568 24421100 */  addiu     $v0, $v0, 0x1100
/* 35EE8C E005856C ACA20004 */  sw        $v0, 4($a1)
/* 35EE90 E0058570 3C02FA00 */  lui       $v0, 0xfa00
/* 35EE94 E0058574 ACA20008 */  sw        $v0, 8($a1)
/* 35EE98 E0058578 92020027 */  lbu       $v0, 0x27($s0)
/* 35EE9C E005857C 24120001 */  addiu     $s2, $zero, 1
/* 35EEA0 E0058580 00461025 */  or        $v0, $v0, $a2
/* 35EEA4 E0058584 ACA2000C */  sw        $v0, 0xc($a1)
/* 35EEA8 E0058588 8E050004 */  lw        $a1, 4($s0)
/* 35EEAC E005858C 8E060008 */  lw        $a2, 8($s0)
/* 35EEB0 E0058590 8E07000C */  lw        $a3, 0xc($s0)
/* 35EEB4 E0058594 0C080108 */  jal       func_E0200420
/* 35EEB8 E0058598 27A40018 */   addiu    $a0, $sp, 0x18
/* 35EEBC E005859C 27B10058 */  addiu     $s1, $sp, 0x58
/* 35EEC0 E00585A0 4480A000 */  mtc1      $zero, $f20
/* 35EEC4 E00585A4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 35EEC8 E00585A8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 35EECC E00585AC 3C013F80 */  lui       $at, 0x3f80
/* 35EED0 E00585B0 4481B000 */  mtc1      $at, $f22
/* 35EED4 E00585B4 00031080 */  sll       $v0, $v1, 2
/* 35EED8 E00585B8 00431021 */  addu      $v0, $v0, $v1
/* 35EEDC E00585BC 00021080 */  sll       $v0, $v0, 2
/* 35EEE0 E00585C0 00431023 */  subu      $v0, $v0, $v1
/* 35EEE4 E00585C4 000218C0 */  sll       $v1, $v0, 3
/* 35EEE8 E00585C8 00431021 */  addu      $v0, $v0, $v1
/* 35EEEC E00585CC 000210C0 */  sll       $v0, $v0, 3
/* 35EEF0 E00585D0 4406A000 */  mfc1      $a2, $f20
/* 35EEF4 E00585D4 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 35EEF8 E00585D8 00220821 */  addu      $at, $at, $v0
/* 35EEFC E00585DC C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 35EF00 E00585E0 4407B000 */  mfc1      $a3, $f22
/* 35EF04 E00585E4 46000007 */  neg.s     $f0, $f0
/* 35EF08 E00585E8 44050000 */  mfc1      $a1, $f0
/* 35EF0C E00585EC 0220202D */  daddu     $a0, $s1, $zero
/* 35EF10 E00585F0 0C080104 */  jal       func_E0200410
/* 35EF14 E00585F4 E7B40010 */   swc1     $f20, 0x10($sp)
/* 35EF18 E00585F8 0220202D */  daddu     $a0, $s1, $zero
/* 35EF1C E00585FC 27A50018 */  addiu     $a1, $sp, 0x18
/* 35EF20 E0058600 0C080114 */  jal       func_E0200450
/* 35EF24 E0058604 27A60098 */   addiu    $a2, $sp, 0x98
/* 35EF28 E0058608 8EE20008 */  lw        $v0, 8($s7)
/* 35EF2C E005860C 0242102A */  slt       $v0, $s2, $v0
/* 35EF30 E0058610 1040004E */  beqz      $v0, .LE005874C
/* 35EF34 E0058614 26100034 */   addiu    $s0, $s0, 0x34
/* 35EF38 E0058618 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 35EF3C E005861C 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 35EF40 E0058620 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 35EF44 E0058624 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 35EF48 E0058628 3C140001 */  lui       $s4, 1
/* 35EF4C E005862C 36941630 */  ori       $s4, $s4, 0x1630
/* 35EF50 E0058630 26100020 */  addiu     $s0, $s0, 0x20
.LE0058634:
/* 35EF54 E0058634 0220202D */  daddu     $a0, $s1, $zero
/* 35EF58 E0058638 8E05FFE4 */  lw        $a1, -0x1c($s0)
/* 35EF5C E005863C 8E06FFE8 */  lw        $a2, -0x18($s0)
/* 35EF60 E0058640 8E07FFEC */  lw        $a3, -0x14($s0)
/* 35EF64 E0058644 0C080108 */  jal       func_E0200420
/* 35EF68 E0058648 26520001 */   addiu    $s2, $s2, 1
/* 35EF6C E005864C 0220202D */  daddu     $a0, $s1, $zero
/* 35EF70 E0058650 27A50098 */  addiu     $a1, $sp, 0x98
/* 35EF74 E0058654 0C080114 */  jal       func_E0200450
/* 35EF78 E0058658 27A60018 */   addiu    $a2, $sp, 0x18
/* 35EF7C E005865C E7B60010 */  swc1      $f22, 0x10($sp)
/* 35EF80 E0058660 8E05FFF8 */  lw        $a1, -8($s0)
/* 35EF84 E0058664 4406A000 */  mfc1      $a2, $f20
/* 35EF88 E0058668 4407A000 */  mfc1      $a3, $f20
/* 35EF8C E005866C 0C080104 */  jal       func_E0200410
/* 35EF90 E0058670 0220202D */   daddu    $a0, $s1, $zero
/* 35EF94 E0058674 0220202D */  daddu     $a0, $s1, $zero
/* 35EF98 E0058678 27A50018 */  addiu     $a1, $sp, 0x18
/* 35EF9C E005867C 0C080114 */  jal       func_E0200450
/* 35EFA0 E0058680 00A0302D */   daddu    $a2, $a1, $zero
/* 35EFA4 E0058684 0220202D */  daddu     $a0, $s1, $zero
/* 35EFA8 E0058688 E7B40010 */  swc1      $f20, 0x10($sp)
/* 35EFAC E005868C 8E050000 */  lw        $a1, ($s0)
/* 35EFB0 E0058690 4406A000 */  mfc1      $a2, $f20
/* 35EFB4 E0058694 4407B000 */  mfc1      $a3, $f22
/* 35EFB8 E0058698 0C080104 */  jal       func_E0200410
/* 35EFBC E005869C 26100034 */   addiu    $s0, $s0, 0x34
/* 35EFC0 E00586A0 0220202D */  daddu     $a0, $s1, $zero
/* 35EFC4 E00586A4 27A50018 */  addiu     $a1, $sp, 0x18
/* 35EFC8 E00586A8 0C080114 */  jal       func_E0200450
/* 35EFCC E00586AC 00A0302D */   daddu    $a2, $a1, $zero
/* 35EFD0 E00586B0 27A40018 */  addiu     $a0, $sp, 0x18
/* 35EFD4 E00586B4 96A50000 */  lhu       $a1, ($s5)
/* 35EFD8 E00586B8 8EC20000 */  lw        $v0, ($s6)
/* 35EFDC E00586BC 00052980 */  sll       $a1, $a1, 6
/* 35EFE0 E00586C0 00B42821 */  addu      $a1, $a1, $s4
/* 35EFE4 E00586C4 0C080118 */  jal       func_E0200460
/* 35EFE8 E00586C8 00452821 */   addu     $a1, $v0, $a1
/* 35EFEC E00586CC 3C06D838 */  lui       $a2, 0xd838
/* 35EFF0 E00586D0 8E640000 */  lw        $a0, ($s3)
/* 35EFF4 E00586D4 34C60002 */  ori       $a2, $a2, 2
/* 35EFF8 E00586D8 0080282D */  daddu     $a1, $a0, $zero
/* 35EFFC E00586DC 24840008 */  addiu     $a0, $a0, 8
/* 35F000 E00586E0 AE640000 */  sw        $a0, ($s3)
/* 35F004 E00586E4 96A20000 */  lhu       $v0, ($s5)
/* 35F008 E00586E8 3C03DA38 */  lui       $v1, 0xda38
/* 35F00C E00586EC ACA30000 */  sw        $v1, ($a1)
/* 35F010 E00586F0 24430001 */  addiu     $v1, $v0, 1
/* 35F014 E00586F4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 35F018 E00586F8 00021180 */  sll       $v0, $v0, 6
/* 35F01C E00586FC A6A30000 */  sh        $v1, ($s5)
/* 35F020 E0058700 8EC30000 */  lw        $v1, ($s6)
/* 35F024 E0058704 00541021 */  addu      $v0, $v0, $s4
/* 35F028 E0058708 00621821 */  addu      $v1, $v1, $v0
/* 35F02C E005870C 24820008 */  addiu     $v0, $a0, 8
/* 35F030 E0058710 ACA30004 */  sw        $v1, 4($a1)
/* 35F034 E0058714 AE620000 */  sw        $v0, ($s3)
/* 35F038 E0058718 3C02DE00 */  lui       $v0, 0xde00
/* 35F03C E005871C AC820000 */  sw        $v0, ($a0)
/* 35F040 E0058720 3C020900 */  lui       $v0, 0x900
/* 35F044 E0058724 244211B0 */  addiu     $v0, $v0, 0x11b0
/* 35F048 E0058728 AC820004 */  sw        $v0, 4($a0)
/* 35F04C E005872C 24020040 */  addiu     $v0, $zero, 0x40
/* 35F050 E0058730 AC860008 */  sw        $a2, 8($a0)
/* 35F054 E0058734 AC82000C */  sw        $v0, 0xc($a0)
/* 35F058 E0058738 8EE20008 */  lw        $v0, 8($s7)
/* 35F05C E005873C 24840010 */  addiu     $a0, $a0, 0x10
/* 35F060 E0058740 0242102A */  slt       $v0, $s2, $v0
/* 35F064 E0058744 1440FFBB */  bnez      $v0, .LE0058634
/* 35F068 E0058748 AE640000 */   sw       $a0, ($s3)
.LE005874C:
/* 35F06C E005874C 8FBF00F8 */  lw        $ra, 0xf8($sp)
/* 35F070 E0058750 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 35F074 E0058754 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 35F078 E0058758 8FB500EC */  lw        $s5, 0xec($sp)
/* 35F07C E005875C 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 35F080 E0058760 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 35F084 E0058764 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 35F088 E0058768 8FB100DC */  lw        $s1, 0xdc($sp)
/* 35F08C E005876C 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 35F090 E0058770 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 35F094 E0058774 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 35F098 E0058778 03E00008 */  jr        $ra
/* 35F09C E005877C 27BD0110 */   addiu    $sp, $sp, 0x110
