.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0038748
/* 34E468 E0038748 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 34E46C E003874C AFB700B4 */  sw        $s7, 0xb4($sp)
/* 34E470 E0038750 0080B82D */  daddu     $s7, $a0, $zero
/* 34E474 E0038754 3C02DB06 */  lui       $v0, 0xdb06
/* 34E478 E0038758 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 34E47C E003875C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 34E480 E0038760 34420024 */  ori       $v0, $v0, 0x24
/* 34E484 E0038764 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 34E488 E0038768 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 34E48C E003876C AFB600B0 */  sw        $s6, 0xb0($sp)
/* 34E490 E0038770 AFB500AC */  sw        $s5, 0xac($sp)
/* 34E494 E0038774 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 34E498 E0038778 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 34E49C E003877C AFB200A0 */  sw        $s2, 0xa0($sp)
/* 34E4A0 E0038780 AFB1009C */  sw        $s1, 0x9c($sp)
/* 34E4A4 E0038784 AFB00098 */  sw        $s0, 0x98($sp)
/* 34E4A8 E0038788 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* 34E4AC E003878C F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 34E4B0 E0038790 8CC40000 */  lw        $a0, ($a2)
/* 34E4B4 E0038794 8EE7000C */  lw        $a3, 0xc($s7)
/* 34E4B8 E0038798 0080282D */  daddu     $a1, $a0, $zero
/* 34E4BC E003879C 24840008 */  addiu     $a0, $a0, 8
/* 34E4C0 E00387A0 ACC40000 */  sw        $a0, ($a2)
/* 34E4C4 E00387A4 ACA20000 */  sw        $v0, ($a1)
/* 34E4C8 E00387A8 24820008 */  addiu     $v0, $a0, 8
/* 34E4CC E00387AC ACC20000 */  sw        $v0, ($a2)
/* 34E4D0 E00387B0 8EE30010 */  lw        $v1, 0x10($s7)
/* 34E4D4 E00387B4 24820010 */  addiu     $v0, $a0, 0x10
/* 34E4D8 E00387B8 ACC20000 */  sw        $v0, ($a2)
/* 34E4DC E00387BC 8C62001C */  lw        $v0, 0x1c($v1)
/* 34E4E0 E00387C0 3C038000 */  lui       $v1, 0x8000
/* 34E4E4 E00387C4 00431021 */  addu      $v0, $v0, $v1
/* 34E4E8 E00387C8 ACA20004 */  sw        $v0, 4($a1)
/* 34E4EC E00387CC 3C02DE00 */  lui       $v0, 0xde00
/* 34E4F0 E00387D0 AC820000 */  sw        $v0, ($a0)
/* 34E4F4 E00387D4 3C020900 */  lui       $v0, 0x900
/* 34E4F8 E00387D8 24420440 */  addiu     $v0, $v0, 0x440
/* 34E4FC E00387DC AC820004 */  sw        $v0, 4($a0)
/* 34E500 E00387E0 3C02FA00 */  lui       $v0, 0xfa00
/* 34E504 E00387E4 AC820008 */  sw        $v0, 8($a0)
/* 34E508 E00387E8 90E20027 */  lbu       $v0, 0x27($a3)
/* 34E50C E00387EC 2403FF00 */  addiu     $v1, $zero, -0x100
/* 34E510 E00387F0 00431025 */  or        $v0, $v0, $v1
/* 34E514 E00387F4 AC82000C */  sw        $v0, 0xc($a0)
/* 34E518 E00387F8 8EE20008 */  lw        $v0, 8($s7)
/* 34E51C E00387FC 1840006B */  blez      $v0, .LE00389AC
/* 34E520 E0038800 0000902D */   daddu    $s2, $zero, $zero
/* 34E524 E0038804 27B10058 */  addiu     $s1, $sp, 0x58
/* 34E528 E0038808 3C1E800B */  lui       $fp, %hi(gCameras)
/* 34E52C E003880C 27DE1D80 */  addiu     $fp, $fp, %lo(gCameras)
/* 34E530 E0038810 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 34E534 E0038814 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 34E538 E0038818 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 34E53C E003881C 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 34E540 E0038820 3C140001 */  lui       $s4, 1
/* 34E544 E0038824 36941630 */  ori       $s4, $s4, 0x1630
/* 34E548 E0038828 00C0982D */  daddu     $s3, $a2, $zero
/* 34E54C E003882C 24F00020 */  addiu     $s0, $a3, 0x20
/* 34E550 E0038830 4480A000 */  mtc1      $zero, $f20
/* 34E554 E0038834 3C013F80 */  lui       $at, 0x3f80
/* 34E558 E0038838 4481B000 */  mtc1      $at, $f22
.LE003883C:
/* 34E55C E003883C 27A40018 */  addiu     $a0, $sp, 0x18
/* 34E560 E0038840 8E05FFE4 */  lw        $a1, -0x1c($s0)
/* 34E564 E0038844 8E06FFE8 */  lw        $a2, -0x18($s0)
/* 34E568 E0038848 8E07FFEC */  lw        $a3, -0x14($s0)
/* 34E56C E003884C 0C080108 */  jal       func_E0200420
/* 34E570 E0038850 26520001 */   addiu    $s2, $s2, 1
/* 34E574 E0038854 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 34E578 E0038858 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 34E57C E003885C 4406A000 */  mfc1      $a2, $f20
/* 34E580 E0038860 00031080 */  sll       $v0, $v1, 2
/* 34E584 E0038864 00431021 */  addu      $v0, $v0, $v1
/* 34E588 E0038868 00021080 */  sll       $v0, $v0, 2
/* 34E58C E003886C 00431023 */  subu      $v0, $v0, $v1
/* 34E590 E0038870 000218C0 */  sll       $v1, $v0, 3
/* 34E594 E0038874 00431021 */  addu      $v0, $v0, $v1
/* 34E598 E0038878 000210C0 */  sll       $v0, $v0, 3
/* 34E59C E003887C 005E1021 */  addu      $v0, $v0, $fp
/* 34E5A0 E0038880 C440006C */  lwc1      $f0, 0x6c($v0)
/* 34E5A4 E0038884 4407B000 */  mfc1      $a3, $f22
/* 34E5A8 E0038888 46000007 */  neg.s     $f0, $f0
/* 34E5AC E003888C 44050000 */  mfc1      $a1, $f0
/* 34E5B0 E0038890 0220202D */  daddu     $a0, $s1, $zero
/* 34E5B4 E0038894 0C080104 */  jal       func_E0200410
/* 34E5B8 E0038898 E7B40010 */   swc1     $f20, 0x10($sp)
/* 34E5BC E003889C 0220202D */  daddu     $a0, $s1, $zero
/* 34E5C0 E00388A0 27A50018 */  addiu     $a1, $sp, 0x18
/* 34E5C4 E00388A4 0C080114 */  jal       func_E0200450
/* 34E5C8 E00388A8 00A0302D */   daddu    $a2, $a1, $zero
/* 34E5CC E00388AC E7B60010 */  swc1      $f22, 0x10($sp)
/* 34E5D0 E00388B0 8E05FFFC */  lw        $a1, -4($s0)
/* 34E5D4 E00388B4 4406A000 */  mfc1      $a2, $f20
/* 34E5D8 E00388B8 4407A000 */  mfc1      $a3, $f20
/* 34E5DC E00388BC 0C080104 */  jal       func_E0200410
/* 34E5E0 E00388C0 0220202D */   daddu    $a0, $s1, $zero
/* 34E5E4 E00388C4 0220202D */  daddu     $a0, $s1, $zero
/* 34E5E8 E00388C8 27A50018 */  addiu     $a1, $sp, 0x18
/* 34E5EC E00388CC 0C080114 */  jal       func_E0200450
/* 34E5F0 E00388D0 00A0302D */   daddu    $a2, $a1, $zero
/* 34E5F4 E00388D4 0220202D */  daddu     $a0, $s1, $zero
/* 34E5F8 E00388D8 8E050000 */  lw        $a1, ($s0)
/* 34E5FC E00388DC 26100030 */  addiu     $s0, $s0, 0x30
/* 34E600 E00388E0 4407B000 */  mfc1      $a3, $f22
/* 34E604 E00388E4 0C080110 */  jal       func_E0200440
/* 34E608 E00388E8 00A0302D */   daddu    $a2, $a1, $zero
/* 34E60C E00388EC 0220202D */  daddu     $a0, $s1, $zero
/* 34E610 E00388F0 27A50018 */  addiu     $a1, $sp, 0x18
/* 34E614 E00388F4 0C080114 */  jal       func_E0200450
/* 34E618 E00388F8 00A0302D */   daddu    $a2, $a1, $zero
/* 34E61C E00388FC 27A40018 */  addiu     $a0, $sp, 0x18
/* 34E620 E0038900 96A50000 */  lhu       $a1, ($s5)
/* 34E624 E0038904 8EC20000 */  lw        $v0, ($s6)
/* 34E628 E0038908 00052980 */  sll       $a1, $a1, 6
/* 34E62C E003890C 00B42821 */  addu      $a1, $a1, $s4
/* 34E630 E0038910 0C080118 */  jal       func_E0200460
/* 34E634 E0038914 00452821 */   addu     $a1, $v0, $a1
/* 34E638 E0038918 3C05D838 */  lui       $a1, 0xd838
/* 34E63C E003891C 34A50002 */  ori       $a1, $a1, 2
/* 34E640 E0038920 8E640000 */  lw        $a0, ($s3)
/* 34E644 E0038924 3C02E700 */  lui       $v0, 0xe700
/* 34E648 E0038928 0080182D */  daddu     $v1, $a0, $zero
/* 34E64C E003892C 24840008 */  addiu     $a0, $a0, 8
/* 34E650 E0038930 AE640000 */  sw        $a0, ($s3)
/* 34E654 E0038934 AC620000 */  sw        $v0, ($v1)
/* 34E658 E0038938 24820008 */  addiu     $v0, $a0, 8
/* 34E65C E003893C AC600004 */  sw        $zero, 4($v1)
/* 34E660 E0038940 AE620000 */  sw        $v0, ($s3)
/* 34E664 E0038944 96A20000 */  lhu       $v0, ($s5)
/* 34E668 E0038948 3C03DA38 */  lui       $v1, 0xda38
/* 34E66C E003894C AC830000 */  sw        $v1, ($a0)
/* 34E670 E0038950 24430001 */  addiu     $v1, $v0, 1
/* 34E674 E0038954 3042FFFF */  andi      $v0, $v0, 0xffff
/* 34E678 E0038958 00021180 */  sll       $v0, $v0, 6
/* 34E67C E003895C A6A30000 */  sh        $v1, ($s5)
/* 34E680 E0038960 8EC30000 */  lw        $v1, ($s6)
/* 34E684 E0038964 00541021 */  addu      $v0, $v0, $s4
/* 34E688 E0038968 00621821 */  addu      $v1, $v1, $v0
/* 34E68C E003896C 24820010 */  addiu     $v0, $a0, 0x10
/* 34E690 E0038970 AC830004 */  sw        $v1, 4($a0)
/* 34E694 E0038974 AE620000 */  sw        $v0, ($s3)
/* 34E698 E0038978 3C02DE00 */  lui       $v0, 0xde00
/* 34E69C E003897C AC820008 */  sw        $v0, 8($a0)
/* 34E6A0 E0038980 3C020900 */  lui       $v0, 0x900
/* 34E6A4 E0038984 244204E8 */  addiu     $v0, $v0, 0x4e8
/* 34E6A8 E0038988 AC82000C */  sw        $v0, 0xc($a0)
/* 34E6AC E003898C 24020040 */  addiu     $v0, $zero, 0x40
/* 34E6B0 E0038990 AC850010 */  sw        $a1, 0x10($a0)
/* 34E6B4 E0038994 AC820014 */  sw        $v0, 0x14($a0)
/* 34E6B8 E0038998 8EE20008 */  lw        $v0, 8($s7)
/* 34E6BC E003899C 24840018 */  addiu     $a0, $a0, 0x18
/* 34E6C0 E00389A0 0242102A */  slt       $v0, $s2, $v0
/* 34E6C4 E00389A4 1440FFA5 */  bnez      $v0, .LE003883C
/* 34E6C8 E00389A8 AE640000 */   sw       $a0, ($s3)
.LE00389AC:
/* 34E6CC E00389AC 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 34E6D0 E00389B0 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 34E6D4 E00389B4 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 34E6D8 E00389B8 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 34E6DC E00389BC 8FB500AC */  lw        $s5, 0xac($sp)
/* 34E6E0 E00389C0 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 34E6E4 E00389C4 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 34E6E8 E00389C8 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 34E6EC E00389CC 8FB1009C */  lw        $s1, 0x9c($sp)
/* 34E6F0 E00389D0 8FB00098 */  lw        $s0, 0x98($sp)
/* 34E6F4 E00389D4 D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* 34E6F8 E00389D8 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 34E6FC E00389DC 03E00008 */  jr        $ra
/* 34E700 E00389E0 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 34E704 E00389E4 00000000 */  nop       
/* 34E708 E00389E8 00000000 */  nop       
/* 34E70C E00389EC 00000000 */  nop       
