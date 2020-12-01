.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A4650
/* 3A3E30 E00A4650 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3A3E34 E00A4654 0080302D */  daddu     $a2, $a0, $zero
/* 3A3E38 E00A4658 3C07DB06 */  lui       $a3, 0xdb06
/* 3A3E3C E00A465C 34E70024 */  ori       $a3, $a3, 0x24
/* 3A3E40 E00A4660 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A3E44 E00A4664 AFB700BC */  sw        $s7, 0xbc($sp)
/* 3A3E48 E00A4668 3C170001 */  lui       $s7, 1
/* 3A3E4C E00A466C 3C0AE300 */  lui       $t2, 0xe300
/* 3A3E50 E00A4670 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3A3E54 E00A4674 3C15800A */  lui       $s5, %hi(D_8009A66C)
/* 3A3E58 E00A4678 26B5A66C */  addiu     $s5, $s5, %lo(D_8009A66C)
/* 3A3E5C E00A467C AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3A3E60 E00A4680 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3A3E64 E00A4684 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3A3E68 E00A4688 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3A3E6C E00A468C AFB300AC */  sw        $s3, 0xac($sp)
/* 3A3E70 E00A4690 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3A3E74 E00A4694 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3A3E78 E00A4698 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3A3E7C E00A469C F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 3A3E80 E00A46A0 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 3A3E84 E00A46A4 8EA50000 */  lw        $a1, ($s5)
/* 3A3E88 E00A46A8 354A1801 */  ori       $t2, $t2, 0x1801
/* 3A3E8C E00A46AC AFAA009C */  sw        $t2, 0x9c($sp)
/* 3A3E90 E00A46B0 8CD2000C */  lw        $s2, 0xc($a2)
/* 3A3E94 E00A46B4 00A0182D */  daddu     $v1, $a1, $zero
/* 3A3E98 E00A46B8 24A50008 */  addiu     $a1, $a1, 8
/* 3A3E9C E00A46BC AEA50000 */  sw        $a1, ($s5)
/* 3A3EA0 E00A46C0 8E4A0014 */  lw        $t2, 0x14($s2)
/* 3A3EA4 E00A46C4 36F71630 */  ori       $s7, $s7, 0x1630
/* 3A3EA8 E00A46C8 AFAA0098 */  sw        $t2, 0x98($sp)
/* 3A3EAC E00A46CC 8E53002C */  lw        $s3, 0x2c($s2)
/* 3A3EB0 E00A46D0 8E540000 */  lw        $s4, ($s2)
/* 3A3EB4 E00A46D4 3C02E700 */  lui       $v0, 0xe700
/* 3A3EB8 E00A46D8 AC620000 */  sw        $v0, ($v1)
/* 3A3EBC E00A46DC AC600004 */  sw        $zero, 4($v1)
/* 3A3EC0 E00A46E0 ACA70000 */  sw        $a3, ($a1)
/* 3A3EC4 E00A46E4 8CC30010 */  lw        $v1, 0x10($a2)
/* 3A3EC8 E00A46E8 24A20008 */  addiu     $v0, $a1, 8
/* 3A3ECC E00A46EC AEA20000 */  sw        $v0, ($s5)
/* 3A3ED0 E00A46F0 8C62001C */  lw        $v0, 0x1c($v1)
/* 3A3ED4 E00A46F4 3C038000 */  lui       $v1, %hi(D_80001D80)
/* 3A3ED8 E00A46F8 00431021 */  addu      $v0, $v0, $v1
/* 3A3EDC E00A46FC 3C03800B */  lui       $v1, %hi(gCameras)
/* 3A3EE0 E00A4700 24631D80 */  addiu     $v1, $v1, %lo(D_80001D80)
/* 3A3EE4 E00A4704 ACA20004 */  sw        $v0, 4($a1)
/* 3A3EE8 E00A4708 8E450004 */  lw        $a1, 4($s2)
/* 3A3EEC E00A470C 8E460008 */  lw        $a2, 8($s2)
/* 3A3EF0 E00A4710 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3A3EF4 E00A4714 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3A3EF8 E00A4718 8E47000C */  lw        $a3, 0xc($s2)
/* 3A3EFC E00A471C 00028080 */  sll       $s0, $v0, 2
/* 3A3F00 E00A4720 02028021 */  addu      $s0, $s0, $v0
/* 3A3F04 E00A4724 00108080 */  sll       $s0, $s0, 2
/* 3A3F08 E00A4728 02028023 */  subu      $s0, $s0, $v0
/* 3A3F0C E00A472C 001010C0 */  sll       $v0, $s0, 3
/* 3A3F10 E00A4730 02028021 */  addu      $s0, $s0, $v0
/* 3A3F14 E00A4734 001080C0 */  sll       $s0, $s0, 3
/* 3A3F18 E00A4738 0C080108 */  jal       func_E0200420
/* 3A3F1C E00A473C 02038021 */   addu     $s0, $s0, $v1
/* 3A3F20 E00A4740 27B10058 */  addiu     $s1, $sp, 0x58
/* 3A3F24 E00A4744 8E450030 */  lw        $a1, 0x30($s2)
/* 3A3F28 E00A4748 0220202D */  daddu     $a0, $s1, $zero
/* 3A3F2C E00A474C 00A0302D */  daddu     $a2, $a1, $zero
/* 3A3F30 E00A4750 0C080110 */  jal       func_E0200440
/* 3A3F34 E00A4754 00A0382D */   daddu    $a3, $a1, $zero
/* 3A3F38 E00A4758 0220202D */  daddu     $a0, $s1, $zero
/* 3A3F3C E00A475C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3A3F40 E00A4760 0C080114 */  jal       func_E0200450
/* 3A3F44 E00A4764 00A0302D */   daddu    $a2, $a1, $zero
/* 3A3F48 E00A4768 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A3F4C E00A476C 3C168007 */  lui       $s6, %hi(D_800741F0)
/* 3A3F50 E00A4770 26D641F0 */  addiu     $s6, $s6, %lo(D_800741F0)
/* 3A3F54 E00A4774 3C1E800A */  lui       $fp, %hi(D_8009A674)
/* 3A3F58 E00A4778 27DEA674 */  addiu     $fp, $fp, %lo(D_8009A674)
/* 3A3F5C E00A477C 96C50000 */  lhu       $a1, ($s6)
/* 3A3F60 E00A4780 8FC20000 */  lw        $v0, ($fp)
/* 3A3F64 E00A4784 00052980 */  sll       $a1, $a1, 6
/* 3A3F68 E00A4788 00B72821 */  addu      $a1, $a1, $s7
/* 3A3F6C E00A478C 0C080118 */  jal       func_E0200460
/* 3A3F70 E00A4790 00452821 */   addu     $a1, $v0, $a1
/* 3A3F74 E00A4794 3C03DA38 */  lui       $v1, 0xda38
/* 3A3F78 E00A4798 34630002 */  ori       $v1, $v1, 2
/* 3A3F7C E00A479C 3C05DA38 */  lui       $a1, 0xda38
/* 3A3F80 E00A47A0 34A50001 */  ori       $a1, $a1, 1
/* 3A3F84 E00A47A4 3C06E300 */  lui       $a2, 0xe300
/* 3A3F88 E00A47A8 34C61A01 */  ori       $a2, $a2, 0x1a01
/* 3A3F8C E00A47AC 327300FF */  andi      $s3, $s3, 0xff
/* 3A3F90 E00A47B0 2A940003 */  slti      $s4, $s4, 3
/* 3A3F94 E00A47B4 8EA80000 */  lw        $t0, ($s5)
/* 3A3F98 E00A47B8 96C20000 */  lhu       $v0, ($s6)
/* 3A3F9C E00A47BC 0100202D */  daddu     $a0, $t0, $zero
/* 3A3FA0 E00A47C0 25080008 */  addiu     $t0, $t0, 8
/* 3A3FA4 E00A47C4 AEA80000 */  sw        $t0, ($s5)
/* 3A3FA8 E00A47C8 AC830000 */  sw        $v1, ($a0)
/* 3A3FAC E00A47CC 24430001 */  addiu     $v1, $v0, 1
/* 3A3FB0 E00A47D0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A3FB4 E00A47D4 00021180 */  sll       $v0, $v0, 6
/* 3A3FB8 E00A47D8 A6C30000 */  sh        $v1, ($s6)
/* 3A3FBC E00A47DC 8FC30000 */  lw        $v1, ($fp)
/* 3A3FC0 E00A47E0 00571021 */  addu      $v0, $v0, $s7
/* 3A3FC4 E00A47E4 00621821 */  addu      $v1, $v1, $v0
/* 3A3FC8 E00A47E8 25020008 */  addiu     $v0, $t0, 8
/* 3A3FCC E00A47EC AC830004 */  sw        $v1, 4($a0)
/* 3A3FD0 E00A47F0 AEA20000 */  sw        $v0, ($s5)
/* 3A3FD4 E00A47F4 25020010 */  addiu     $v0, $t0, 0x10
/* 3A3FD8 E00A47F8 AD050000 */  sw        $a1, ($t0)
/* 3A3FDC E00A47FC AEA20000 */  sw        $v0, ($s5)
/* 3A3FE0 E00A4800 8E030204 */  lw        $v1, 0x204($s0)
/* 3A3FE4 E00A4804 3C02FA00 */  lui       $v0, 0xfa00
/* 3A3FE8 E00A4808 AD020008 */  sw        $v0, 8($t0)
/* 3A3FEC E00A480C AD030004 */  sw        $v1, 4($t0)
/* 3A3FF0 E00A4810 92430023 */  lbu       $v1, 0x23($s2)
/* 3A3FF4 E00A4814 92440027 */  lbu       $a0, 0x27($s2)
/* 3A3FF8 E00A4818 9245002B */  lbu       $a1, 0x2b($s2)
/* 3A3FFC E00A481C 25020018 */  addiu     $v0, $t0, 0x18
/* 3A4000 E00A4820 AEA20000 */  sw        $v0, ($s5)
/* 3A4004 E00A4824 8FAA009C */  lw        $t2, 0x9c($sp)
/* 3A4008 E00A4828 25020020 */  addiu     $v0, $t0, 0x20
/* 3A400C E00A482C AD0A0010 */  sw        $t2, 0x10($t0)
/* 3A4010 E00A4830 240A0040 */  addiu     $t2, $zero, 0x40
/* 3A4014 E00A4834 00031E00 */  sll       $v1, $v1, 0x18
/* 3A4018 E00A4838 00042400 */  sll       $a0, $a0, 0x10
/* 3A401C E00A483C 00641825 */  or        $v1, $v1, $a0
/* 3A4020 E00A4840 00052A00 */  sll       $a1, $a1, 8
/* 3A4024 E00A4844 00651825 */  or        $v1, $v1, $a1
/* 3A4028 E00A4848 00731825 */  or        $v1, $v1, $s3
/* 3A402C E00A484C AD0A0014 */  sw        $t2, 0x14($t0)
/* 3A4030 E00A4850 AEA20000 */  sw        $v0, ($s5)
/* 3A4034 E00A4854 AD060018 */  sw        $a2, 0x18($t0)
/* 3A4038 E00A4858 AD00001C */  sw        $zero, 0x1c($t0)
/* 3A403C E00A485C 12800068 */  beqz      $s4, .LE00A4A00
/* 3A4040 E00A4860 AD03000C */   sw       $v1, 0xc($t0)
/* 3A4044 E00A4864 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A4048 E00A4868 C7A00098 */  lwc1      $f0, 0x98($sp)
/* 3A404C E00A486C 46800020 */  cvt.s.w   $f0, $f0
/* 3A4050 E00A4870 3C12D838 */  lui       $s2, 0xd838
/* 3A4054 E00A4874 36520002 */  ori       $s2, $s2, 2
/* 3A4058 E00A4878 25020028 */  addiu     $v0, $t0, 0x28
/* 3A405C E00A487C 44050000 */  mfc1      $a1, $f0
/* 3A4060 E00A4880 4480A000 */  mtc1      $zero, $f20
/* 3A4064 E00A4884 3C013F80 */  lui       $at, 0x3f80
/* 3A4068 E00A4888 4481B000 */  mtc1      $at, $f22
/* 3A406C E00A488C 3C10DE00 */  lui       $s0, 0xde00
/* 3A4070 E00A4890 AEA20000 */  sw        $v0, ($s5)
/* 3A4074 E00A4894 4406A000 */  mfc1      $a2, $f20
/* 3A4078 E00A4898 4407A000 */  mfc1      $a3, $f20
/* 3A407C E00A489C 3C020900 */  lui       $v0, 0x900
/* 3A4080 E00A48A0 24421000 */  addiu     $v0, $v0, 0x1000
/* 3A4084 E00A48A4 AD100020 */  sw        $s0, 0x20($t0)
/* 3A4088 E00A48A8 AD020024 */  sw        $v0, 0x24($t0)
/* 3A408C E00A48AC 0C080104 */  jal       func_E0200410
/* 3A4090 E00A48B0 E7B60010 */   swc1     $f22, 0x10($sp)
/* 3A4094 E00A48B4 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A4098 E00A48B8 96C50000 */  lhu       $a1, ($s6)
/* 3A409C E00A48BC 8FC20000 */  lw        $v0, ($fp)
/* 3A40A0 E00A48C0 00052980 */  sll       $a1, $a1, 6
/* 3A40A4 E00A48C4 00B72821 */  addu      $a1, $a1, $s7
/* 3A40A8 E00A48C8 0C080118 */  jal       func_E0200460
/* 3A40AC E00A48CC 00452821 */   addu     $a1, $v0, $a1
/* 3A40B0 E00A48D0 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A40B4 E00A48D4 8FAA0098 */  lw        $t2, 0x98($sp)
/* 3A40B8 E00A48D8 8EA80000 */  lw        $t0, ($s5)
/* 3A40BC E00A48DC 4406A000 */  mfc1      $a2, $f20
/* 3A40C0 E00A48E0 000A1023 */  negu      $v0, $t2
/* 3A40C4 E00A48E4 000210C0 */  sll       $v0, $v0, 3
/* 3A40C8 E00A48E8 44820000 */  mtc1      $v0, $f0
/* 3A40CC E00A48EC 00000000 */  nop       
/* 3A40D0 E00A48F0 46800020 */  cvt.s.w   $f0, $f0
/* 3A40D4 E00A48F4 0100482D */  daddu     $t1, $t0, $zero
/* 3A40D8 E00A48F8 44050000 */  mfc1      $a1, $f0
/* 3A40DC E00A48FC 25080008 */  addiu     $t0, $t0, 8
/* 3A40E0 E00A4900 AEA80000 */  sw        $t0, ($s5)
/* 3A40E4 E00A4904 96C20000 */  lhu       $v0, ($s6)
/* 3A40E8 E00A4908 3C11DA38 */  lui       $s1, 0xda38
/* 3A40EC E00A490C AD310000 */  sw        $s1, ($t1)
/* 3A40F0 E00A4910 24430001 */  addiu     $v1, $v0, 1
/* 3A40F4 E00A4914 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A40F8 E00A4918 00021180 */  sll       $v0, $v0, 6
/* 3A40FC E00A491C A6C30000 */  sh        $v1, ($s6)
/* 3A4100 E00A4920 8FC30000 */  lw        $v1, ($fp)
/* 3A4104 E00A4924 00571021 */  addu      $v0, $v0, $s7
/* 3A4108 E00A4928 00621821 */  addu      $v1, $v1, $v0
/* 3A410C E00A492C 25020008 */  addiu     $v0, $t0, 8
/* 3A4110 E00A4930 AD230004 */  sw        $v1, 4($t1)
/* 3A4114 E00A4934 AEA20000 */  sw        $v0, ($s5)
/* 3A4118 E00A4938 3C020900 */  lui       $v0, 0x900
/* 3A411C E00A493C 244211D0 */  addiu     $v0, $v0, 0x11d0
/* 3A4120 E00A4940 AD020004 */  sw        $v0, 4($t0)
/* 3A4124 E00A4944 25020010 */  addiu     $v0, $t0, 0x10
/* 3A4128 E00A4948 240A0040 */  addiu     $t2, $zero, 0x40
/* 3A412C E00A494C AD100000 */  sw        $s0, ($t0)
/* 3A4130 E00A4950 AEA20000 */  sw        $v0, ($s5)
/* 3A4134 E00A4954 25020018 */  addiu     $v0, $t0, 0x18
/* 3A4138 E00A4958 AD120008 */  sw        $s2, 8($t0)
/* 3A413C E00A495C AD0A000C */  sw        $t2, 0xc($t0)
/* 3A4140 E00A4960 AEA20000 */  sw        $v0, ($s5)
/* 3A4144 E00A4964 8FAA009C */  lw        $t2, 0x9c($sp)
/* 3A4148 E00A4968 00C0382D */  daddu     $a3, $a2, $zero
/* 3A414C E00A496C AD0A0010 */  sw        $t2, 0x10($t0)
/* 3A4150 E00A4970 AD000014 */  sw        $zero, 0x14($t0)
/* 3A4154 E00A4974 0C080104 */  jal       func_E0200410
/* 3A4158 E00A4978 E7B60010 */   swc1     $f22, 0x10($sp)
/* 3A415C E00A497C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3A4160 E00A4980 96C50000 */  lhu       $a1, ($s6)
/* 3A4164 E00A4984 8FC20000 */  lw        $v0, ($fp)
/* 3A4168 E00A4988 00052980 */  sll       $a1, $a1, 6
/* 3A416C E00A498C 00B72821 */  addu      $a1, $a1, $s7
/* 3A4170 E00A4990 0C080118 */  jal       func_E0200460
/* 3A4174 E00A4994 00452821 */   addu     $a1, $v0, $a1
/* 3A4178 E00A4998 8EA40000 */  lw        $a0, ($s5)
/* 3A417C E00A499C 96C20000 */  lhu       $v0, ($s6)
/* 3A4180 E00A49A0 0080282D */  daddu     $a1, $a0, $zero
/* 3A4184 E00A49A4 24840008 */  addiu     $a0, $a0, 8
/* 3A4188 E00A49A8 24430001 */  addiu     $v1, $v0, 1
/* 3A418C E00A49AC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3A4190 E00A49B0 00021180 */  sll       $v0, $v0, 6
/* 3A4194 E00A49B4 AEA40000 */  sw        $a0, ($s5)
/* 3A4198 E00A49B8 ACB10000 */  sw        $s1, ($a1)
/* 3A419C E00A49BC A6C30000 */  sh        $v1, ($s6)
/* 3A41A0 E00A49C0 8FC30000 */  lw        $v1, ($fp)
/* 3A41A4 E00A49C4 00571021 */  addu      $v0, $v0, $s7
/* 3A41A8 E00A49C8 00621821 */  addu      $v1, $v1, $v0
/* 3A41AC E00A49CC 24820008 */  addiu     $v0, $a0, 8
/* 3A41B0 E00A49D0 ACA30004 */  sw        $v1, 4($a1)
/* 3A41B4 E00A49D4 AEA20000 */  sw        $v0, ($s5)
/* 3A41B8 E00A49D8 3C020900 */  lui       $v0, 0x900
/* 3A41BC E00A49DC 244211F0 */  addiu     $v0, $v0, 0x11f0
/* 3A41C0 E00A49E0 AC820004 */  sw        $v0, 4($a0)
/* 3A41C4 E00A49E4 24820010 */  addiu     $v0, $a0, 0x10
/* 3A41C8 E00A49E8 240A0040 */  addiu     $t2, $zero, 0x40
/* 3A41CC E00A49EC AC900000 */  sw        $s0, ($a0)
/* 3A41D0 E00A49F0 AEA20000 */  sw        $v0, ($s5)
/* 3A41D4 E00A49F4 AC920008 */  sw        $s2, 8($a0)
/* 3A41D8 E00A49F8 0802928D */  j         .LE00A4A34
/* 3A41DC E00A49FC AC8A000C */   sw       $t2, 0xc($a0)
.LE00A4A00:
/* 3A41E0 E00A4A00 25020028 */  addiu     $v0, $t0, 0x28
/* 3A41E4 E00A4A04 3C03DE00 */  lui       $v1, 0xde00
/* 3A41E8 E00A4A08 AEA20000 */  sw        $v0, ($s5)
/* 3A41EC E00A4A0C 3C020900 */  lui       $v0, 0x900
/* 3A41F0 E00A4A10 244210A8 */  addiu     $v0, $v0, 0x10a8
/* 3A41F4 E00A4A14 AD020024 */  sw        $v0, 0x24($t0)
/* 3A41F8 E00A4A18 25020030 */  addiu     $v0, $t0, 0x30
/* 3A41FC E00A4A1C AD030020 */  sw        $v1, 0x20($t0)
/* 3A4200 E00A4A20 AEA20000 */  sw        $v0, ($s5)
/* 3A4204 E00A4A24 3C020900 */  lui       $v0, 0x900
/* 3A4208 E00A4A28 24421210 */  addiu     $v0, $v0, 0x1210
/* 3A420C E00A4A2C AD030028 */  sw        $v1, 0x28($t0)
/* 3A4210 E00A4A30 AD02002C */  sw        $v0, 0x2c($t0)
.LE00A4A34:
/* 3A4214 E00A4A34 3C02E300 */  lui       $v0, 0xe300
/* 3A4218 E00A4A38 34421801 */  ori       $v0, $v0, 0x1801
/* 3A421C E00A4A3C 3C06E300 */  lui       $a2, 0xe300
/* 3A4220 E00A4A40 34C61A01 */  ori       $a2, $a2, 0x1a01
/* 3A4224 E00A4A44 3C07D838 */  lui       $a3, 0xd838
/* 3A4228 E00A4A48 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 3A422C E00A4A4C 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 3A4230 E00A4A50 8C830000 */  lw        $v1, ($a0)
/* 3A4234 E00A4A54 34E70002 */  ori       $a3, $a3, 2
/* 3A4238 E00A4A58 0060282D */  daddu     $a1, $v1, $zero
/* 3A423C E00A4A5C 24630008 */  addiu     $v1, $v1, 8
/* 3A4240 E00A4A60 AC830000 */  sw        $v1, ($a0)
/* 3A4244 E00A4A64 ACA20000 */  sw        $v0, ($a1)
/* 3A4248 E00A4A68 240200C0 */  addiu     $v0, $zero, 0xc0
/* 3A424C E00A4A6C ACA20004 */  sw        $v0, 4($a1)
/* 3A4250 E00A4A70 24620008 */  addiu     $v0, $v1, 8
/* 3A4254 E00A4A74 AC820000 */  sw        $v0, ($a0)
/* 3A4258 E00A4A78 24020030 */  addiu     $v0, $zero, 0x30
/* 3A425C E00A4A7C AC620004 */  sw        $v0, 4($v1)
/* 3A4260 E00A4A80 24620010 */  addiu     $v0, $v1, 0x10
/* 3A4264 E00A4A84 AC660000 */  sw        $a2, ($v1)
/* 3A4268 E00A4A88 AC820000 */  sw        $v0, ($a0)
/* 3A426C E00A4A8C 24020040 */  addiu     $v0, $zero, 0x40
/* 3A4270 E00A4A90 AC670008 */  sw        $a3, 8($v1)
/* 3A4274 E00A4A94 AC62000C */  sw        $v0, 0xc($v1)
/* 3A4278 E00A4A98 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3A427C E00A4A9C 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3A4280 E00A4AA0 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3A4284 E00A4AA4 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3A4288 E00A4AA8 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3A428C E00A4AAC 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3A4290 E00A4AB0 8FB300AC */  lw        $s3, 0xac($sp)
/* 3A4294 E00A4AB4 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3A4298 E00A4AB8 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3A429C E00A4ABC 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3A42A0 E00A4AC0 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 3A42A4 E00A4AC4 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 3A42A8 E00A4AC8 03E00008 */  jr        $ra
/* 3A42AC E00A4ACC 27BD00D8 */   addiu    $sp, $sp, 0xd8
