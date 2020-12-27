.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005A3F4
/* 3606B4 E005A3F4 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3606B8 E005A3F8 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 3606BC E005A3FC 0080F02D */  daddu     $fp, $a0, $zero
/* 3606C0 E005A400 3C06DB06 */  lui       $a2, 0xdb06
/* 3606C4 E005A404 34C60024 */  ori       $a2, $a2, 0x24
/* 3606C8 E005A408 27A40018 */  addiu     $a0, $sp, 0x18
/* 3606CC E005A40C AFB00098 */  sw        $s0, 0x98($sp)
/* 3606D0 E005A410 3C100001 */  lui       $s0, 1
/* 3606D4 E005A414 36101630 */  ori       $s0, $s0, 0x1630
/* 3606D8 E005A418 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3606DC E005A41C 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* 3606E0 E005A420 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* 3606E4 E005A424 3C02E700 */  lui       $v0, 0xe700
/* 3606E8 E005A428 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 3606EC E005A42C AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3606F0 E005A430 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3606F4 E005A434 AFB500AC */  sw        $s5, 0xac($sp)
/* 3606F8 E005A438 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3606FC E005A43C AFB300A4 */  sw        $s3, 0xa4($sp)
/* 360700 E005A440 AFB1009C */  sw        $s1, 0x9c($sp)
/* 360704 E005A444 F7B800D0 */  sdc1      $f24, 0xd0($sp)
/* 360708 E005A448 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* 36070C E005A44C F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 360710 E005A450 8E430000 */  lw        $v1, ($s2)
/* 360714 E005A454 8FD3000C */  lw        $s3, 0xc($fp)
/* 360718 E005A458 0060282D */  daddu     $a1, $v1, $zero
/* 36071C E005A45C 24630008 */  addiu     $v1, $v1, 8
/* 360720 E005A460 AE430000 */  sw        $v1, ($s2)
/* 360724 E005A464 ACA20000 */  sw        $v0, ($a1)
/* 360728 E005A468 24620008 */  addiu     $v0, $v1, 8
/* 36072C E005A46C ACA00004 */  sw        $zero, 4($a1)
/* 360730 E005A470 AE420000 */  sw        $v0, ($s2)
/* 360734 E005A474 AC660000 */  sw        $a2, ($v1)
/* 360738 E005A478 8FC50010 */  lw        $a1, 0x10($fp)
/* 36073C E005A47C 24620010 */  addiu     $v0, $v1, 0x10
/* 360740 E005A480 AE420000 */  sw        $v0, ($s2)
/* 360744 E005A484 8CA5001C */  lw        $a1, 0x1c($a1)
/* 360748 E005A488 3C02DE00 */  lui       $v0, 0xde00
/* 36074C E005A48C AC620008 */  sw        $v0, 8($v1)
/* 360750 E005A490 3C020900 */  lui       $v0, 0x900
/* 360754 E005A494 24420440 */  addiu     $v0, $v0, 0x440
/* 360758 E005A498 AC62000C */  sw        $v0, 0xc($v1)
/* 36075C E005A49C 3C028000 */  lui       $v0, 0x8000
/* 360760 E005A4A0 00A22821 */  addu      $a1, $a1, $v0
/* 360764 E005A4A4 AC650004 */  sw        $a1, 4($v1)
/* 360768 E005A4A8 8E650004 */  lw        $a1, 4($s3)
/* 36076C E005A4AC 8E660008 */  lw        $a2, 8($s3)
/* 360770 E005A4B0 8E67000C */  lw        $a3, 0xc($s3)
/* 360774 E005A4B4 0C080108 */  jal       func_E0200420
/* 360778 E005A4B8 24140001 */   addiu    $s4, $zero, 1
/* 36077C E005A4BC 27B10058 */  addiu     $s1, $sp, 0x58
/* 360780 E005A4C0 4480A000 */  mtc1      $zero, $f20
/* 360784 E005A4C4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 360788 E005A4C8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 36078C E005A4CC 3C013F80 */  lui       $at, 0x3f80
/* 360790 E005A4D0 4481C000 */  mtc1      $at, $f24
/* 360794 E005A4D4 00031080 */  sll       $v0, $v1, 2
/* 360798 E005A4D8 00431021 */  addu      $v0, $v0, $v1
/* 36079C E005A4DC 00021080 */  sll       $v0, $v0, 2
/* 3607A0 E005A4E0 00431023 */  subu      $v0, $v0, $v1
/* 3607A4 E005A4E4 000218C0 */  sll       $v1, $v0, 3
/* 3607A8 E005A4E8 00431021 */  addu      $v0, $v0, $v1
/* 3607AC E005A4EC 000210C0 */  sll       $v0, $v0, 3
/* 3607B0 E005A4F0 4406A000 */  mfc1      $a2, $f20
/* 3607B4 E005A4F4 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3607B8 E005A4F8 00220821 */  addu      $at, $at, $v0
/* 3607BC E005A4FC C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 3607C0 E005A500 4407C000 */  mfc1      $a3, $f24
/* 3607C4 E005A504 46000007 */  neg.s     $f0, $f0
/* 3607C8 E005A508 44050000 */  mfc1      $a1, $f0
/* 3607CC E005A50C 0220202D */  daddu     $a0, $s1, $zero
/* 3607D0 E005A510 0C080104 */  jal       func_E0200410
/* 3607D4 E005A514 E7B40010 */   swc1     $f20, 0x10($sp)
/* 3607D8 E005A518 0220202D */  daddu     $a0, $s1, $zero
/* 3607DC E005A51C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3607E0 E005A520 0C080114 */  jal       func_E0200450
/* 3607E4 E005A524 00A0302D */   daddu    $a2, $a1, $zero
/* 3607E8 E005A528 27A40018 */  addiu     $a0, $sp, 0x18
/* 3607EC E005A52C 3C158007 */  lui       $s5, %hi(D_800741F0)
/* 3607F0 E005A530 26B541F0 */  addiu     $s5, $s5, %lo(D_800741F0)
/* 3607F4 E005A534 3C16800A */  lui       $s6, %hi(D_8009A674)
/* 3607F8 E005A538 26D6A674 */  addiu     $s6, $s6, %lo(D_8009A674)
/* 3607FC E005A53C 96A50000 */  lhu       $a1, ($s5)
/* 360800 E005A540 8EC20000 */  lw        $v0, ($s6)
/* 360804 E005A544 00052980 */  sll       $a1, $a1, 6
/* 360808 E005A548 00B02821 */  addu      $a1, $a1, $s0
/* 36080C E005A54C 0C080118 */  jal       func_E0200460
/* 360810 E005A550 00452821 */   addu     $a1, $v0, $a1
/* 360814 E005A554 3C06DCDC */  lui       $a2, 0xdcdc
/* 360818 E005A558 8E440000 */  lw        $a0, ($s2)
/* 36081C E005A55C 34C628E6 */  ori       $a2, $a2, 0x28e6
/* 360820 E005A560 0080282D */  daddu     $a1, $a0, $zero
/* 360824 E005A564 24840008 */  addiu     $a0, $a0, 8
/* 360828 E005A568 AE440000 */  sw        $a0, ($s2)
/* 36082C E005A56C 96A20000 */  lhu       $v0, ($s5)
/* 360830 E005A570 3C03DA38 */  lui       $v1, 0xda38
/* 360834 E005A574 ACA30000 */  sw        $v1, ($a1)
/* 360838 E005A578 00541821 */  addu      $v1, $v0, $s4
/* 36083C E005A57C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 360840 E005A580 00021180 */  sll       $v0, $v0, 6
/* 360844 E005A584 A6A30000 */  sh        $v1, ($s5)
/* 360848 E005A588 8EC30000 */  lw        $v1, ($s6)
/* 36084C E005A58C 00501021 */  addu      $v0, $v0, $s0
/* 360850 E005A590 00621821 */  addu      $v1, $v1, $v0
/* 360854 E005A594 24820008 */  addiu     $v0, $a0, 8
/* 360858 E005A598 ACA30004 */  sw        $v1, 4($a1)
/* 36085C E005A59C AE420000 */  sw        $v0, ($s2)
/* 360860 E005A5A0 3C02FA00 */  lui       $v0, 0xfa00
/* 360864 E005A5A4 AC820000 */  sw        $v0, ($a0)
/* 360868 E005A5A8 AC860004 */  sw        $a2, 4($a0)
/* 36086C E005A5AC 8FC20008 */  lw        $v0, 8($fp)
/* 360870 E005A5B0 0282102A */  slt       $v0, $s4, $v0
/* 360874 E005A5B4 10400049 */  beqz      $v0, .LE005A6DC
/* 360878 E005A5B8 26730034 */   addiu    $s3, $s3, 0x34
/* 36087C E005A5BC 4600A586 */  mov.s     $f22, $f20
/* 360880 E005A5C0 4600C506 */  mov.s     $f20, $f24
/* 360884 E005A5C4 02C0B82D */  daddu     $s7, $s6, $zero
/* 360888 E005A5C8 02A0B02D */  daddu     $s6, $s5, $zero
/* 36088C E005A5CC 3C150001 */  lui       $s5, 1
/* 360890 E005A5D0 36B51630 */  ori       $s5, $s5, 0x1630
/* 360894 E005A5D4 26700030 */  addiu     $s0, $s3, 0x30
.LE005A5D8:
/* 360898 E005A5D8 27A40018 */  addiu     $a0, $sp, 0x18
/* 36089C E005A5DC 8E05FFD4 */  lw        $a1, -0x2c($s0)
/* 3608A0 E005A5E0 8E06FFD8 */  lw        $a2, -0x28($s0)
/* 3608A4 E005A5E4 8E07FFDC */  lw        $a3, -0x24($s0)
/* 3608A8 E005A5E8 0C080108 */  jal       func_E0200420
/* 3608AC E005A5EC 26940001 */   addiu    $s4, $s4, 1
/* 3608B0 E005A5F0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 3608B4 E005A5F4 8E05FFEC */  lw        $a1, -0x14($s0)
/* 3608B8 E005A5F8 4406B000 */  mfc1      $a2, $f22
/* 3608BC E005A5FC 4407B000 */  mfc1      $a3, $f22
/* 3608C0 E005A600 0C080104 */  jal       func_E0200410
/* 3608C4 E005A604 0220202D */   daddu    $a0, $s1, $zero
/* 3608C8 E005A608 0220202D */  daddu     $a0, $s1, $zero
/* 3608CC E005A60C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3608D0 E005A610 0C080114 */  jal       func_E0200450
/* 3608D4 E005A614 00A0302D */   daddu    $a2, $a1, $zero
/* 3608D8 E005A618 0220202D */  daddu     $a0, $s1, $zero
/* 3608DC E005A61C 8E050000 */  lw        $a1, ($s0)
/* 3608E0 E005A620 26100034 */  addiu     $s0, $s0, 0x34
/* 3608E4 E005A624 4407A000 */  mfc1      $a3, $f20
/* 3608E8 E005A628 0C080110 */  jal       func_E0200440
/* 3608EC E005A62C 00A0302D */   daddu    $a2, $a1, $zero
/* 3608F0 E005A630 0220202D */  daddu     $a0, $s1, $zero
/* 3608F4 E005A634 27A50018 */  addiu     $a1, $sp, 0x18
/* 3608F8 E005A638 0C080114 */  jal       func_E0200450
/* 3608FC E005A63C 00A0302D */   daddu    $a2, $a1, $zero
/* 360900 E005A640 27A40018 */  addiu     $a0, $sp, 0x18
/* 360904 E005A644 96C50000 */  lhu       $a1, ($s6)
/* 360908 E005A648 8EE20000 */  lw        $v0, ($s7)
/* 36090C E005A64C 00052980 */  sll       $a1, $a1, 6
/* 360910 E005A650 00B52821 */  addu      $a1, $a1, $s5
/* 360914 E005A654 0C080118 */  jal       func_E0200460
/* 360918 E005A658 00452821 */   addu     $a1, $v0, $a1
/* 36091C E005A65C 3C06D838 */  lui       $a2, 0xd838
/* 360920 E005A660 8E440000 */  lw        $a0, ($s2)
/* 360924 E005A664 34C60002 */  ori       $a2, $a2, 2
/* 360928 E005A668 0080282D */  daddu     $a1, $a0, $zero
/* 36092C E005A66C 24840008 */  addiu     $a0, $a0, 8
/* 360930 E005A670 AE440000 */  sw        $a0, ($s2)
/* 360934 E005A674 96C20000 */  lhu       $v0, ($s6)
/* 360938 E005A678 3C03DA38 */  lui       $v1, 0xda38
/* 36093C E005A67C ACA30000 */  sw        $v1, ($a1)
/* 360940 E005A680 24430001 */  addiu     $v1, $v0, 1
/* 360944 E005A684 3042FFFF */  andi      $v0, $v0, 0xffff
/* 360948 E005A688 00021180 */  sll       $v0, $v0, 6
/* 36094C E005A68C A6C30000 */  sh        $v1, ($s6)
/* 360950 E005A690 8EE30000 */  lw        $v1, ($s7)
/* 360954 E005A694 00551021 */  addu      $v0, $v0, $s5
/* 360958 E005A698 00621821 */  addu      $v1, $v1, $v0
/* 36095C E005A69C 24820008 */  addiu     $v0, $a0, 8
/* 360960 E005A6A0 ACA30004 */  sw        $v1, 4($a1)
/* 360964 E005A6A4 AE420000 */  sw        $v0, ($s2)
/* 360968 E005A6A8 3C02DE00 */  lui       $v0, 0xde00
/* 36096C E005A6AC 3C080900 */  lui       $t0, 0x900
/* 360970 E005A6B0 250804F0 */  addiu     $t0, $t0, 0x4f0
/* 360974 E005A6B4 AC820000 */  sw        $v0, ($a0)
/* 360978 E005A6B8 24020040 */  addiu     $v0, $zero, 0x40
/* 36097C E005A6BC AC880004 */  sw        $t0, 4($a0)
/* 360980 E005A6C0 AC860008 */  sw        $a2, 8($a0)
/* 360984 E005A6C4 AC82000C */  sw        $v0, 0xc($a0)
/* 360988 E005A6C8 8FC20008 */  lw        $v0, 8($fp)
/* 36098C E005A6CC 24840010 */  addiu     $a0, $a0, 0x10
/* 360990 E005A6D0 0282102A */  slt       $v0, $s4, $v0
/* 360994 E005A6D4 1440FFC0 */  bnez      $v0, .LE005A5D8
/* 360998 E005A6D8 AE440000 */   sw       $a0, ($s2)
.LE005A6DC:
/* 36099C E005A6DC 3C05D838 */  lui       $a1, 0xd838
/* 3609A0 E005A6E0 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 3609A4 E005A6E4 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 3609A8 E005A6E8 8C620000 */  lw        $v0, ($v1)
/* 3609AC E005A6EC 34A50002 */  ori       $a1, $a1, 2
/* 3609B0 E005A6F0 0040202D */  daddu     $a0, $v0, $zero
/* 3609B4 E005A6F4 24420008 */  addiu     $v0, $v0, 8
/* 3609B8 E005A6F8 AC620000 */  sw        $v0, ($v1)
/* 3609BC E005A6FC 24020040 */  addiu     $v0, $zero, 0x40
/* 3609C0 E005A700 AC850000 */  sw        $a1, ($a0)
/* 3609C4 E005A704 AC820004 */  sw        $v0, 4($a0)
/* 3609C8 E005A708 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 3609CC E005A70C 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 3609D0 E005A710 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3609D4 E005A714 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3609D8 E005A718 8FB500AC */  lw        $s5, 0xac($sp)
/* 3609DC E005A71C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3609E0 E005A720 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3609E4 E005A724 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3609E8 E005A728 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3609EC E005A72C 8FB00098 */  lw        $s0, 0x98($sp)
/* 3609F0 E005A730 D7B800D0 */  ldc1      $f24, 0xd0($sp)
/* 3609F4 E005A734 D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* 3609F8 E005A738 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 3609FC E005A73C 03E00008 */  jr        $ra
/* 360A00 E005A740 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 360A04 E005A744 00000000 */  nop       
/* 360A08 E005A748 00000000 */  nop       
/* 360A0C E005A74C 00000000 */  nop       
