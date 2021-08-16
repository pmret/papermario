.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E6524
/* 3E0E54 E00E6524 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3E0E58 E00E6528 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 3E0E5C E00E652C 0080F02D */  daddu     $fp, $a0, $zero
/* 3E0E60 E00E6530 3C06DB06 */  lui       $a2, 0xdb06
/* 3E0E64 E00E6534 34C60024 */  ori       $a2, $a2, 0x24
/* 3E0E68 E00E6538 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E0E6C E00E653C AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3E0E70 E00E6540 3C120001 */  lui       $s2, 1
/* 3E0E74 E00E6544 36521630 */  ori       $s2, $s2, 0x1630
/* 3E0E78 E00E6548 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 3E0E7C E00E654C 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 3E0E80 E00E6550 26D6A66C */  addiu     $s6, $s6, %lo(gMasterGfxPos)
/* 3E0E84 E00E6554 AFBF00CC */  sw        $ra, 0xcc($sp)
/* 3E0E88 E00E6558 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 3E0E8C E00E655C AFB500BC */  sw        $s5, 0xbc($sp)
/* 3E0E90 E00E6560 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 3E0E94 E00E6564 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 3E0E98 E00E6568 AFB100AC */  sw        $s1, 0xac($sp)
/* 3E0E9C E00E656C AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3E0EA0 E00E6570 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 3E0EA4 E00E6574 8EC50000 */  lw        $a1, ($s6)
/* 3E0EA8 E00E6578 8FD4000C */  lw        $s4, 0xc($fp)
/* 3E0EAC E00E657C 00A0182D */  daddu     $v1, $a1, $zero
/* 3E0EB0 E00E6580 24A50008 */  addiu     $a1, $a1, 8
/* 3E0EB4 E00E6584 AEC50000 */  sw        $a1, ($s6)
/* 3E0EB8 E00E6588 8E880030 */  lw        $t0, 0x30($s4)
/* 3E0EBC E00E658C 24150001 */  addiu     $s5, $zero, 1
/* 3E0EC0 E00E6590 AFA800A0 */  sw        $t0, 0xa0($sp)
/* 3E0EC4 E00E6594 8E930000 */  lw        $s3, ($s4)
/* 3E0EC8 E00E6598 3C02E700 */  lui       $v0, 0xe700
/* 3E0ECC E00E659C AC620000 */  sw        $v0, ($v1)
/* 3E0ED0 E00E65A0 AC600004 */  sw        $zero, 4($v1)
/* 3E0ED4 E00E65A4 ACA60000 */  sw        $a2, ($a1)
/* 3E0ED8 E00E65A8 8FC30010 */  lw        $v1, 0x10($fp)
/* 3E0EDC E00E65AC 24A20008 */  addiu     $v0, $a1, 8
/* 3E0EE0 E00E65B0 AEC20000 */  sw        $v0, ($s6)
/* 3E0EE4 E00E65B4 8C62001C */  lw        $v0, 0x1c($v1)
/* 3E0EE8 E00E65B8 3C038000 */  lui       $v1, 0x8000
/* 3E0EEC E00E65BC 00431021 */  addu      $v0, $v0, $v1
/* 3E0EF0 E00E65C0 3C03800B */  lui       $v1, %hi(gCameras)
/* 3E0EF4 E00E65C4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3E0EF8 E00E65C8 ACA20004 */  sw        $v0, 4($a1)
/* 3E0EFC E00E65CC 8E850004 */  lw        $a1, 4($s4)
/* 3E0F00 E00E65D0 8E860008 */  lw        $a2, 8($s4)
/* 3E0F04 E00E65D4 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3E0F08 E00E65D8 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3E0F0C E00E65DC 8E87000C */  lw        $a3, 0xc($s4)
/* 3E0F10 E00E65E0 00028080 */  sll       $s0, $v0, 2
/* 3E0F14 E00E65E4 02028021 */  addu      $s0, $s0, $v0
/* 3E0F18 E00E65E8 00108080 */  sll       $s0, $s0, 2
/* 3E0F1C E00E65EC 02028023 */  subu      $s0, $s0, $v0
/* 3E0F20 E00E65F0 001010C0 */  sll       $v0, $s0, 3
/* 3E0F24 E00E65F4 02028021 */  addu      $s0, $s0, $v0
/* 3E0F28 E00E65F8 001080C0 */  sll       $s0, $s0, 3
/* 3E0F2C E00E65FC 0C080108 */  jal       func_E0200420
/* 3E0F30 E00E6600 02038021 */   addu     $s0, $s0, $v1
/* 3E0F34 E00E6604 27B10060 */  addiu     $s1, $sp, 0x60
/* 3E0F38 E00E6608 0220202D */  daddu     $a0, $s1, $zero
/* 3E0F3C E00E660C 8E850034 */  lw        $a1, 0x34($s4)
/* 3E0F40 E00E6610 26940038 */  addiu     $s4, $s4, 0x38
/* 3E0F44 E00E6614 00A0302D */  daddu     $a2, $a1, $zero
/* 3E0F48 E00E6618 0C080110 */  jal       func_E0200440
/* 3E0F4C E00E661C 00A0382D */   daddu    $a3, $a1, $zero
/* 3E0F50 E00E6620 0220202D */  daddu     $a0, $s1, $zero
/* 3E0F54 E00E6624 27A50020 */  addiu     $a1, $sp, 0x20
/* 3E0F58 E00E6628 0C080114 */  jal       func_E0200450
/* 3E0F5C E00E662C 00A0302D */   daddu    $a2, $a1, $zero
/* 3E0F60 E00E6630 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E0F64 E00E6634 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3E0F68 E00E6638 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3E0F6C E00E663C 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 3E0F70 E00E6640 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 3E0F74 E00E6644 96250000 */  lhu       $a1, ($s1)
/* 3E0F78 E00E6648 8EE20000 */  lw        $v0, ($s7)
/* 3E0F7C E00E664C 00052980 */  sll       $a1, $a1, 6
/* 3E0F80 E00E6650 00B22821 */  addu      $a1, $a1, $s2
/* 3E0F84 E00E6654 0C080118 */  jal       func_E0200460
/* 3E0F88 E00E6658 00452821 */   addu     $a1, $v0, $a1
/* 3E0F8C E00E665C 3C03DA38 */  lui       $v1, 0xda38
/* 3E0F90 E00E6660 34630002 */  ori       $v1, $v1, 2
/* 3E0F94 E00E6664 3C06DA38 */  lui       $a2, 0xda38
/* 3E0F98 E00E6668 00D53025 */  or        $a2, $a2, $s5
/* 3E0F9C E00E666C 00139880 */  sll       $s3, $s3, 2
/* 3E0FA0 E00E6670 8EC40000 */  lw        $a0, ($s6)
/* 3E0FA4 E00E6674 96220000 */  lhu       $v0, ($s1)
/* 3E0FA8 E00E6678 0080282D */  daddu     $a1, $a0, $zero
/* 3E0FAC E00E667C 24840008 */  addiu     $a0, $a0, 8
/* 3E0FB0 E00E6680 AEC40000 */  sw        $a0, ($s6)
/* 3E0FB4 E00E6684 ACA30000 */  sw        $v1, ($a1)
/* 3E0FB8 E00E6688 00551821 */  addu      $v1, $v0, $s5
/* 3E0FBC E00E668C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3E0FC0 E00E6690 00021180 */  sll       $v0, $v0, 6
/* 3E0FC4 E00E6694 A6230000 */  sh        $v1, ($s1)
/* 3E0FC8 E00E6698 8EE30000 */  lw        $v1, ($s7)
/* 3E0FCC E00E669C 00521021 */  addu      $v0, $v0, $s2
/* 3E0FD0 E00E66A0 00621821 */  addu      $v1, $v1, $v0
/* 3E0FD4 E00E66A4 ACA30004 */  sw        $v1, 4($a1)
/* 3E0FD8 E00E66A8 AC860000 */  sw        $a2, ($a0)
/* 3E0FDC E00E66AC 8E030204 */  lw        $v1, 0x204($s0)
/* 3E0FE0 E00E66B0 3C02DE00 */  lui       $v0, 0xde00
/* 3E0FE4 E00E66B4 AC820008 */  sw        $v0, 8($a0)
/* 3E0FE8 E00E66B8 AC830004 */  sw        $v1, 4($a0)
/* 3E0FEC E00E66BC 3C03E00E */  lui       $v1, %hi(D_E00E6888)
/* 3E0FF0 E00E66C0 00731821 */  addu      $v1, $v1, $s3
/* 3E0FF4 E00E66C4 8C636888 */  lw        $v1, %lo(D_E00E6888)($v1)
/* 3E0FF8 E00E66C8 24820008 */  addiu     $v0, $a0, 8
/* 3E0FFC E00E66CC AEC20000 */  sw        $v0, ($s6)
/* 3E1000 E00E66D0 AC83000C */  sw        $v1, 0xc($a0)
/* 3E1004 E00E66D4 8FC20008 */  lw        $v0, 8($fp)
/* 3E1008 E00E66D8 24840010 */  addiu     $a0, $a0, 0x10
/* 3E100C E00E66DC 02A2102A */  slt       $v0, $s5, $v0
/* 3E1010 E00E66E0 1040004C */  beqz      $v0, .LE00E6814
/* 3E1014 E00E66E4 AEC40000 */   sw       $a0, ($s6)
/* 3E1018 E00E66E8 4480A000 */  mtc1      $zero, $f20
/* 3E101C E00E66EC 0220902D */  daddu     $s2, $s1, $zero
/* 3E1020 E00E66F0 3C110001 */  lui       $s1, 1
/* 3E1024 E00E66F4 36311630 */  ori       $s1, $s1, 0x1630
/* 3E1028 E00E66F8 02C0802D */  daddu     $s0, $s6, $zero
/* 3E102C E00E66FC 3C02E00E */  lui       $v0, %hi(D_E00E6880)
/* 3E1030 E00E6700 24426880 */  addiu     $v0, $v0, %lo(D_E00E6880)
/* 3E1034 E00E6704 0262B021 */  addu      $s6, $s3, $v0
/* 3E1038 E00E6708 26930030 */  addiu     $s3, $s4, 0x30
.LE00E670C:
/* 3E103C E00E670C 8E62FFF0 */  lw        $v0, -0x10($s3)
/* 3E1040 E00E6710 0442003C */  bltzl     $v0, .LE00E6804
/* 3E1044 E00E6714 26B50001 */   addiu    $s5, $s5, 1
/* 3E1048 E00E6718 C6600004 */  lwc1      $f0, 4($s3)
/* 3E104C E00E671C 4405A000 */  mfc1      $a1, $f20
/* 3E1050 E00E6720 4406A000 */  mfc1      $a2, $f20
/* 3E1054 E00E6724 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3E1058 E00E6728 C660FFD4 */  lwc1      $f0, -0x2c($s3)
/* 3E105C E00E672C E7A00014 */  swc1      $f0, 0x14($sp)
/* 3E1060 E00E6730 C660FFD8 */  lwc1      $f0, -0x28($s3)
/* 3E1064 E00E6734 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3E1068 E00E6738 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3E106C E00E673C 8E67FFF4 */  lw        $a3, -0xc($s3)
/* 3E1070 E00E6740 0C080180 */  jal       func_E0200600
/* 3E1074 E00E6744 27A40020 */   addiu    $a0, $sp, 0x20
/* 3E1078 E00E6748 27A40020 */  addiu     $a0, $sp, 0x20
/* 3E107C E00E674C 96450000 */  lhu       $a1, ($s2)
/* 3E1080 E00E6750 8EE20000 */  lw        $v0, ($s7)
/* 3E1084 E00E6754 00052980 */  sll       $a1, $a1, 6
/* 3E1088 E00E6758 00B12821 */  addu      $a1, $a1, $s1
/* 3E108C E00E675C 0C080118 */  jal       func_E0200460
/* 3E1090 E00E6760 00452821 */   addu     $a1, $v0, $a1
/* 3E1094 E00E6764 8E040000 */  lw        $a0, ($s0)
/* 3E1098 E00E6768 3C06D838 */  lui       $a2, 0xd838
/* 3E109C E00E676C 0080282D */  daddu     $a1, $a0, $zero
/* 3E10A0 E00E6770 24840008 */  addiu     $a0, $a0, 8
/* 3E10A4 E00E6774 AE040000 */  sw        $a0, ($s0)
/* 3E10A8 E00E6778 96420000 */  lhu       $v0, ($s2)
/* 3E10AC E00E677C 3C03DA38 */  lui       $v1, 0xda38
/* 3E10B0 E00E6780 ACA30000 */  sw        $v1, ($a1)
/* 3E10B4 E00E6784 24430001 */  addiu     $v1, $v0, 1
/* 3E10B8 E00E6788 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3E10BC E00E678C 00021180 */  sll       $v0, $v0, 6
/* 3E10C0 E00E6790 A6430000 */  sh        $v1, ($s2)
/* 3E10C4 E00E6794 8EE30000 */  lw        $v1, ($s7)
/* 3E10C8 E00E6798 00511021 */  addu      $v0, $v0, $s1
/* 3E10CC E00E679C 00621821 */  addu      $v1, $v1, $v0
/* 3E10D0 E00E67A0 3C02FA00 */  lui       $v0, 0xfa00
/* 3E10D4 E00E67A4 ACA30004 */  sw        $v1, 4($a1)
/* 3E10D8 E00E67A8 AC820000 */  sw        $v0, ($a0)
/* 3E10DC E00E67AC 8E630000 */  lw        $v1, ($s3)
/* 3E10E0 E00E67B0 24820008 */  addiu     $v0, $a0, 8
/* 3E10E4 E00E67B4 AE020000 */  sw        $v0, ($s0)
/* 3E10E8 E00E67B8 8FA800A0 */  lw        $t0, 0xa0($sp)
/* 3E10EC E00E67BC 34C60002 */  ori       $a2, $a2, 2
/* 3E10F0 E00E67C0 01030018 */  mult      $t0, $v1
/* 3E10F4 E00E67C4 24820010 */  addiu     $v0, $a0, 0x10
/* 3E10F8 E00E67C8 AE020000 */  sw        $v0, ($s0)
/* 3E10FC E00E67CC 3C02DE00 */  lui       $v0, 0xde00
/* 3E1100 E00E67D0 AC820008 */  sw        $v0, 8($a0)
/* 3E1104 E00E67D4 00004012 */  mflo      $t0
/* 3E1108 E00E67D8 00081203 */  sra       $v0, $t0, 8
/* 3E110C E00E67DC 304200FF */  andi      $v0, $v0, 0xff
/* 3E1110 E00E67E0 AC820004 */  sw        $v0, 4($a0)
/* 3E1114 E00E67E4 8EC30000 */  lw        $v1, ($s6)
/* 3E1118 E00E67E8 24820018 */  addiu     $v0, $a0, 0x18
/* 3E111C E00E67EC AE020000 */  sw        $v0, ($s0)
/* 3E1120 E00E67F0 24020040 */  addiu     $v0, $zero, 0x40
/* 3E1124 E00E67F4 AC860010 */  sw        $a2, 0x10($a0)
/* 3E1128 E00E67F8 AC820014 */  sw        $v0, 0x14($a0)
/* 3E112C E00E67FC AC83000C */  sw        $v1, 0xc($a0)
/* 3E1130 E00E6800 26B50001 */  addiu     $s5, $s5, 1
.LE00E6804:
/* 3E1134 E00E6804 8FC20008 */  lw        $v0, 8($fp)
/* 3E1138 E00E6808 02A2102A */  slt       $v0, $s5, $v0
/* 3E113C E00E680C 1440FFBF */  bnez      $v0, .LE00E670C
/* 3E1140 E00E6810 26730038 */   addiu    $s3, $s3, 0x38
.LE00E6814:
/* 3E1144 E00E6814 3C05D838 */  lui       $a1, 0xd838
/* 3E1148 E00E6818 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3E114C E00E681C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3E1150 E00E6820 8C620000 */  lw        $v0, ($v1)
/* 3E1154 E00E6824 34A50002 */  ori       $a1, $a1, 2
/* 3E1158 E00E6828 0040202D */  daddu     $a0, $v0, $zero
/* 3E115C E00E682C 24420008 */  addiu     $v0, $v0, 8
/* 3E1160 E00E6830 AC620000 */  sw        $v0, ($v1)
/* 3E1164 E00E6834 24020040 */  addiu     $v0, $zero, 0x40
/* 3E1168 E00E6838 AC850000 */  sw        $a1, ($a0)
/* 3E116C E00E683C AC820004 */  sw        $v0, 4($a0)
/* 3E1170 E00E6840 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 3E1174 E00E6844 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 3E1178 E00E6848 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 3E117C E00E684C 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 3E1180 E00E6850 8FB500BC */  lw        $s5, 0xbc($sp)
/* 3E1184 E00E6854 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 3E1188 E00E6858 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 3E118C E00E685C 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 3E1190 E00E6860 8FB100AC */  lw        $s1, 0xac($sp)
/* 3E1194 E00E6864 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 3E1198 E00E6868 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 3E119C E00E686C 03E00008 */  jr        $ra
/* 3E11A0 E00E6870 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 3E11A4 E00E6874 00000000 */  nop
/* 3E11A8 E00E6878 00000000 */  nop
/* 3E11AC E00E687C 00000000 */  nop
