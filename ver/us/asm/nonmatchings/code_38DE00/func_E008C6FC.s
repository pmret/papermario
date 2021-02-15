.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008C6FC
/* 38E4FC E008C6FC 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 38E500 E008C700 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 38E504 E008C704 0080F02D */  daddu     $fp, $a0, $zero
/* 38E508 E008C708 3C06DB06 */  lui       $a2, 0xdb06
/* 38E50C E008C70C 34C60024 */  ori       $a2, $a2, 0x24
/* 38E510 E008C710 27A40020 */  addiu     $a0, $sp, 0x20
/* 38E514 E008C714 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 38E518 E008C718 3C100001 */  lui       $s0, 1
/* 38E51C E008C71C 36101630 */  ori       $s0, $s0, 0x1630
/* 38E520 E008C720 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 38E524 E008C724 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 38E528 E008C728 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 38E52C E008C72C AFBF00CC */  sw        $ra, 0xcc($sp)
/* 38E530 E008C730 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 38E534 E008C734 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 38E538 E008C738 AFB500BC */  sw        $s5, 0xbc($sp)
/* 38E53C E008C73C AFB400B8 */  sw        $s4, 0xb8($sp)
/* 38E540 E008C740 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 38E544 E008C744 AFB100AC */  sw        $s1, 0xac($sp)
/* 38E548 E008C748 F7BA00E8 */  sdc1      $f26, 0xe8($sp)
/* 38E54C E008C74C F7B800E0 */  sdc1      $f24, 0xe0($sp)
/* 38E550 E008C750 F7B600D8 */  sdc1      $f22, 0xd8($sp)
/* 38E554 E008C754 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 38E558 E008C758 8E630000 */  lw        $v1, ($s3)
/* 38E55C E008C75C 8FD1000C */  lw        $s1, 0xc($fp)
/* 38E560 E008C760 0060282D */  daddu     $a1, $v1, $zero
/* 38E564 E008C764 24630008 */  addiu     $v1, $v1, 8
/* 38E568 E008C768 AE630000 */  sw        $v1, ($s3)
/* 38E56C E008C76C 8E28001C */  lw        $t0, 0x1c($s1)
/* 38E570 E008C770 AFA800A4 */  sw        $t0, 0xa4($sp)
/* 38E574 E008C774 C6380014 */  lwc1      $f24, 0x14($s1)
/* 38E578 E008C778 C6360018 */  lwc1      $f22, 0x18($s1)
/* 38E57C E008C77C 8E280000 */  lw        $t0, ($s1)
/* 38E580 E008C780 3C02E700 */  lui       $v0, 0xe700
/* 38E584 E008C784 AFA800A0 */  sw        $t0, 0xa0($sp)
/* 38E588 E008C788 ACA20000 */  sw        $v0, ($a1)
/* 38E58C E008C78C 24620008 */  addiu     $v0, $v1, 8
/* 38E590 E008C790 ACA00004 */  sw        $zero, 4($a1)
/* 38E594 E008C794 AE620000 */  sw        $v0, ($s3)
/* 38E598 E008C798 AC660000 */  sw        $a2, ($v1)
/* 38E59C E008C79C 8FC50010 */  lw        $a1, 0x10($fp)
/* 38E5A0 E008C7A0 24620010 */  addiu     $v0, $v1, 0x10
/* 38E5A4 E008C7A4 AE620000 */  sw        $v0, ($s3)
/* 38E5A8 E008C7A8 8CA5001C */  lw        $a1, 0x1c($a1)
/* 38E5AC E008C7AC 3C02DE00 */  lui       $v0, 0xde00
/* 38E5B0 E008C7B0 AC620008 */  sw        $v0, 8($v1)
/* 38E5B4 E008C7B4 3C020900 */  lui       $v0, 0x900
/* 38E5B8 E008C7B8 24420420 */  addiu     $v0, $v0, 0x420
/* 38E5BC E008C7BC AC62000C */  sw        $v0, 0xc($v1)
/* 38E5C0 E008C7C0 3C028000 */  lui       $v0, 0x8000
/* 38E5C4 E008C7C4 00A22821 */  addu      $a1, $a1, $v0
/* 38E5C8 E008C7C8 AC650004 */  sw        $a1, 4($v1)
/* 38E5CC E008C7CC 8E250008 */  lw        $a1, 8($s1)
/* 38E5D0 E008C7D0 8E26000C */  lw        $a2, 0xc($s1)
/* 38E5D4 E008C7D4 8E270010 */  lw        $a3, 0x10($s1)
/* 38E5D8 E008C7D8 4480A000 */  mtc1      $zero, $f20
/* 38E5DC E008C7DC 0C080108 */  jal       func_E0200420
/* 38E5E0 E008C7E0 24160001 */   addiu    $s6, $zero, 1
/* 38E5E4 E008C7E4 27B20060 */  addiu     $s2, $sp, 0x60
/* 38E5E8 E008C7E8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 38E5EC E008C7EC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 38E5F0 E008C7F0 4406A000 */  mfc1      $a2, $f20
/* 38E5F4 E008C7F4 00031080 */  sll       $v0, $v1, 2
/* 38E5F8 E008C7F8 00431021 */  addu      $v0, $v0, $v1
/* 38E5FC E008C7FC 00021080 */  sll       $v0, $v0, 2
/* 38E600 E008C800 00431023 */  subu      $v0, $v0, $v1
/* 38E604 E008C804 000218C0 */  sll       $v1, $v0, 3
/* 38E608 E008C808 00431021 */  addu      $v0, $v0, $v1
/* 38E60C E008C80C 000210C0 */  sll       $v0, $v0, 3
/* 38E610 E008C810 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 38E614 E008C814 00220821 */  addu      $at, $at, $v0
/* 38E618 E008C818 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 38E61C E008C81C 3C073F80 */  lui       $a3, 0x3f80
/* 38E620 E008C820 46000007 */  neg.s     $f0, $f0
/* 38E624 E008C824 44050000 */  mfc1      $a1, $f0
/* 38E628 E008C828 0240202D */  daddu     $a0, $s2, $zero
/* 38E62C E008C82C 0C080104 */  jal       func_E0200410
/* 38E630 E008C830 E7B40010 */   swc1     $f20, 0x10($sp)
/* 38E634 E008C834 0240202D */  daddu     $a0, $s2, $zero
/* 38E638 E008C838 27A50020 */  addiu     $a1, $sp, 0x20
/* 38E63C E008C83C 0C080114 */  jal       func_E0200450
/* 38E640 E008C840 00A0302D */   daddu    $a2, $a1, $zero
/* 38E644 E008C844 27A40020 */  addiu     $a0, $sp, 0x20
/* 38E648 E008C848 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* 38E64C E008C84C 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* 38E650 E008C850 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 38E654 E008C854 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 38E658 E008C858 96850000 */  lhu       $a1, ($s4)
/* 38E65C E008C85C 8EA20000 */  lw        $v0, ($s5)
/* 38E660 E008C860 00052980 */  sll       $a1, $a1, 6
/* 38E664 E008C864 00B02821 */  addu      $a1, $a1, $s0
/* 38E668 E008C868 0C080118 */  jal       func_E0200460
/* 38E66C E008C86C 00452821 */   addu     $a1, $v0, $a1
/* 38E670 E008C870 8E620000 */  lw        $v0, ($s3)
/* 38E674 E008C874 26310048 */  addiu     $s1, $s1, 0x48
/* 38E678 E008C878 0040282D */  daddu     $a1, $v0, $zero
/* 38E67C E008C87C 24420008 */  addiu     $v0, $v0, 8
/* 38E680 E008C880 AE620000 */  sw        $v0, ($s3)
/* 38E684 E008C884 96840000 */  lhu       $a0, ($s4)
/* 38E688 E008C888 3C02DA38 */  lui       $v0, 0xda38
/* 38E68C E008C88C ACA20000 */  sw        $v0, ($a1)
/* 38E690 E008C890 8EA30000 */  lw        $v1, ($s5)
/* 38E694 E008C894 3082FFFF */  andi      $v0, $a0, 0xffff
/* 38E698 E008C898 00021180 */  sll       $v0, $v0, 6
/* 38E69C E008C89C 00501021 */  addu      $v0, $v0, $s0
/* 38E6A0 E008C8A0 00621821 */  addu      $v1, $v1, $v0
/* 38E6A4 E008C8A4 ACA30004 */  sw        $v1, 4($a1)
/* 38E6A8 E008C8A8 8FC20008 */  lw        $v0, 8($fp)
/* 38E6AC E008C8AC 00962021 */  addu      $a0, $a0, $s6
/* 38E6B0 E008C8B0 02C2102A */  slt       $v0, $s6, $v0
/* 38E6B4 E008C8B4 10400073 */  beqz      $v0, .LE008CA84
/* 38E6B8 E008C8B8 A6840000 */   sh       $a0, ($s4)
/* 38E6BC E008C8BC 3C014040 */  lui       $at, 0x4040
/* 38E6C0 E008C8C0 4481D000 */  mtc1      $at, $f26
/* 38E6C4 E008C8C4 02A0B82D */  daddu     $s7, $s5, $zero
/* 38E6C8 E008C8C8 0280A82D */  daddu     $s5, $s4, $zero
/* 38E6CC E008C8CC 3C140001 */  lui       $s4, 1
/* 38E6D0 E008C8D0 36941630 */  ori       $s4, $s4, 0x1630
/* 38E6D4 E008C8D4 26300046 */  addiu     $s0, $s1, 0x46
.LE008C8D8:
/* 38E6D8 E008C8D8 C600FFCE */  lwc1      $f0, -0x32($s0)
/* 38E6DC E008C8DC 4600C002 */  mul.s     $f0, $f24, $f0
/* 38E6E0 E008C8E0 00000000 */  nop
/* 38E6E4 E008C8E4 4406A000 */  mfc1      $a2, $f20
/* 38E6E8 E008C8E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 38E6EC E008C8EC C600FFC2 */  lwc1      $f0, -0x3e($s0)
/* 38E6F0 E008C8F0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 38E6F4 E008C8F4 C600FFC6 */  lwc1      $f0, -0x3a($s0)
/* 38E6F8 E008C8F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 38E6FC E008C8FC C600FFCA */  lwc1      $f0, -0x36($s0)
/* 38E700 E008C900 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 38E704 E008C904 8E05FFE6 */  lw        $a1, -0x1a($s0)
/* 38E708 E008C908 8E07FFEE */  lw        $a3, -0x12($s0)
/* 38E70C E008C90C 0C080180 */  jal       func_E0200600
/* 38E710 E008C910 27A40020 */   addiu    $a0, $sp, 0x20
/* 38E714 E008C914 E7B40010 */  swc1      $f20, 0x10($sp)
/* 38E718 E008C918 8E05FFEA */  lw        $a1, -0x16($s0)
/* 38E71C E008C91C 4406A000 */  mfc1      $a2, $f20
/* 38E720 E008C920 3C073F80 */  lui       $a3, 0x3f80
/* 38E724 E008C924 0C080104 */  jal       func_E0200410
/* 38E728 E008C928 0240202D */   daddu    $a0, $s2, $zero
/* 38E72C E008C92C 0240202D */  daddu     $a0, $s2, $zero
/* 38E730 E008C930 27A50020 */  addiu     $a1, $sp, 0x20
/* 38E734 E008C934 0C080114 */  jal       func_E0200450
/* 38E738 E008C938 00A0302D */   daddu    $a2, $a1, $zero
/* 38E73C E008C93C 8FA800A0 */  lw        $t0, 0xa0($sp)
/* 38E740 E008C940 29020008 */  slti      $v0, $t0, 8
/* 38E744 E008C944 1040000B */  beqz      $v0, .LE008C974
/* 38E748 E008C948 00000000 */   nop
/* 38E74C E008C94C 4616C001 */  sub.s     $f0, $f24, $f22
/* 38E750 E008C950 461A0002 */  mul.s     $f0, $f0, $f26
/* 38E754 E008C954 00000000 */  nop
/* 38E758 E008C958 46160003 */  div.s     $f0, $f0, $f22
/* 38E75C E008C95C 4600D001 */  sub.s     $f0, $f26, $f0
/* 38E760 E008C960 4406A000 */  mfc1      $a2, $f20
/* 38E764 E008C964 4407A000 */  mfc1      $a3, $f20
/* 38E768 E008C968 44050000 */  mfc1      $a1, $f0
/* 38E76C E008C96C 08023260 */  j         .LE008C980
/* 38E770 E008C970 00000000 */   nop
.LE008C974:
/* 38E774 E008C974 3C054000 */  lui       $a1, 0x4000
/* 38E778 E008C978 4406A000 */  mfc1      $a2, $f20
/* 38E77C E008C97C 4407A000 */  mfc1      $a3, $f20
.LE008C980:
/* 38E780 E008C980 0C080108 */  jal       func_E0200420
/* 38E784 E008C984 0240202D */   daddu    $a0, $s2, $zero
/* 38E788 E008C988 0240202D */  daddu     $a0, $s2, $zero
/* 38E78C E008C98C 27A50020 */  addiu     $a1, $sp, 0x20
/* 38E790 E008C990 0C080114 */  jal       func_E0200450
/* 38E794 E008C994 00A0302D */   daddu    $a2, $a1, $zero
/* 38E798 E008C998 27A40020 */  addiu     $a0, $sp, 0x20
/* 38E79C E008C99C 26D60001 */  addiu     $s6, $s6, 1
/* 38E7A0 E008C9A0 8E630000 */  lw        $v1, ($s3)
/* 38E7A4 E008C9A4 96A50000 */  lhu       $a1, ($s5)
/* 38E7A8 E008C9A8 8EE20000 */  lw        $v0, ($s7)
/* 38E7AC E008C9AC 0060382D */  daddu     $a3, $v1, $zero
/* 38E7B0 E008C9B0 24630008 */  addiu     $v1, $v1, 8
/* 38E7B4 E008C9B4 00052980 */  sll       $a1, $a1, 6
/* 38E7B8 E008C9B8 00B42821 */  addu      $a1, $a1, $s4
/* 38E7BC E008C9BC 00452821 */  addu      $a1, $v0, $a1
/* 38E7C0 E008C9C0 3C02FA00 */  lui       $v0, 0xfa00
/* 38E7C4 E008C9C4 AE630000 */  sw        $v1, ($s3)
/* 38E7C8 E008C9C8 ACE20000 */  sw        $v0, ($a3)
/* 38E7CC E008C9CC 9203FFFE */  lbu       $v1, -2($s0)
/* 38E7D0 E008C9D0 9202FFFF */  lbu       $v0, -1($s0)
/* 38E7D4 E008C9D4 92060000 */  lbu       $a2, ($s0)
/* 38E7D8 E008C9D8 26100048 */  addiu     $s0, $s0, 0x48
/* 38E7DC E008C9DC 8FA800A4 */  lw        $t0, 0xa4($sp)
/* 38E7E0 E008C9E0 00031E00 */  sll       $v1, $v1, 0x18
/* 38E7E4 E008C9E4 00021400 */  sll       $v0, $v0, 0x10
/* 38E7E8 E008C9E8 00621825 */  or        $v1, $v1, $v0
/* 38E7EC E008C9EC 00063200 */  sll       $a2, $a2, 8
/* 38E7F0 E008C9F0 00661825 */  or        $v1, $v1, $a2
/* 38E7F4 E008C9F4 310200FF */  andi      $v0, $t0, 0xff
/* 38E7F8 E008C9F8 00621825 */  or        $v1, $v1, $v0
/* 38E7FC E008C9FC 0C080118 */  jal       func_E0200460
/* 38E800 E008CA00 ACE30004 */   sw       $v1, 4($a3)
/* 38E804 E008CA04 3C06D838 */  lui       $a2, 0xd838
/* 38E808 E008CA08 8E640000 */  lw        $a0, ($s3)
/* 38E80C E008CA0C 34C60002 */  ori       $a2, $a2, 2
/* 38E810 E008CA10 0080282D */  daddu     $a1, $a0, $zero
/* 38E814 E008CA14 24840008 */  addiu     $a0, $a0, 8
/* 38E818 E008CA18 AE640000 */  sw        $a0, ($s3)
/* 38E81C E008CA1C 96A20000 */  lhu       $v0, ($s5)
/* 38E820 E008CA20 3C03DA38 */  lui       $v1, 0xda38
/* 38E824 E008CA24 ACA30000 */  sw        $v1, ($a1)
/* 38E828 E008CA28 24430001 */  addiu     $v1, $v0, 1
/* 38E82C E008CA2C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38E830 E008CA30 00021180 */  sll       $v0, $v0, 6
/* 38E834 E008CA34 A6A30000 */  sh        $v1, ($s5)
/* 38E838 E008CA38 8EE30000 */  lw        $v1, ($s7)
/* 38E83C E008CA3C 00541021 */  addu      $v0, $v0, $s4
/* 38E840 E008CA40 00621821 */  addu      $v1, $v1, $v0
/* 38E844 E008CA44 24820008 */  addiu     $v0, $a0, 8
/* 38E848 E008CA48 ACA30004 */  sw        $v1, 4($a1)
/* 38E84C E008CA4C AE620000 */  sw        $v0, ($s3)
/* 38E850 E008CA50 3C02DE00 */  lui       $v0, 0xde00
/* 38E854 E008CA54 AC820000 */  sw        $v0, ($a0)
/* 38E858 E008CA58 3C020900 */  lui       $v0, 0x900
/* 38E85C E008CA5C 244203A0 */  addiu     $v0, $v0, 0x3a0
/* 38E860 E008CA60 AC820004 */  sw        $v0, 4($a0)
/* 38E864 E008CA64 24020040 */  addiu     $v0, $zero, 0x40
/* 38E868 E008CA68 AC860008 */  sw        $a2, 8($a0)
/* 38E86C E008CA6C AC82000C */  sw        $v0, 0xc($a0)
/* 38E870 E008CA70 8FC20008 */  lw        $v0, 8($fp)
/* 38E874 E008CA74 24840010 */  addiu     $a0, $a0, 0x10
/* 38E878 E008CA78 02C2102A */  slt       $v0, $s6, $v0
/* 38E87C E008CA7C 1440FF96 */  bnez      $v0, .LE008C8D8
/* 38E880 E008CA80 AE640000 */   sw       $a0, ($s3)
.LE008CA84:
/* 38E884 E008CA84 3C05D838 */  lui       $a1, 0xd838
/* 38E888 E008CA88 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 38E88C E008CA8C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 38E890 E008CA90 8C620000 */  lw        $v0, ($v1)
/* 38E894 E008CA94 34A50002 */  ori       $a1, $a1, 2
/* 38E898 E008CA98 0040202D */  daddu     $a0, $v0, $zero
/* 38E89C E008CA9C 24420008 */  addiu     $v0, $v0, 8
/* 38E8A0 E008CAA0 AC620000 */  sw        $v0, ($v1)
/* 38E8A4 E008CAA4 24020040 */  addiu     $v0, $zero, 0x40
/* 38E8A8 E008CAA8 AC850000 */  sw        $a1, ($a0)
/* 38E8AC E008CAAC AC820004 */  sw        $v0, 4($a0)
/* 38E8B0 E008CAB0 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 38E8B4 E008CAB4 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 38E8B8 E008CAB8 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 38E8BC E008CABC 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 38E8C0 E008CAC0 8FB500BC */  lw        $s5, 0xbc($sp)
/* 38E8C4 E008CAC4 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 38E8C8 E008CAC8 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 38E8CC E008CACC 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 38E8D0 E008CAD0 8FB100AC */  lw        $s1, 0xac($sp)
/* 38E8D4 E008CAD4 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 38E8D8 E008CAD8 D7BA00E8 */  ldc1      $f26, 0xe8($sp)
/* 38E8DC E008CADC D7B800E0 */  ldc1      $f24, 0xe0($sp)
/* 38E8E0 E008CAE0 D7B600D8 */  ldc1      $f22, 0xd8($sp)
/* 38E8E4 E008CAE4 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 38E8E8 E008CAE8 03E00008 */  jr        $ra
/* 38E8EC E008CAEC 27BD00F0 */   addiu    $sp, $sp, 0xf0
