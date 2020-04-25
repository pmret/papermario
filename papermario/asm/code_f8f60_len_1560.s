
.section .text002D45B0, "ax"

/* 0F8F60 002D45B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8F64 002D45B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8F68 002D45B8 0080882D */  daddu $s1, $a0, $zero
/* 0F8F6C 002D45BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8F70 002D45C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8F74 002D45C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F8F78 002D45C8 8E050000 */  lw    $a1, ($s0)
/* 0F8F7C 002D45CC 0C0B1EAF */  jal   func_002C7ABC
/* 0F8F80 002D45D0 26100004 */   addiu $s0, $s0, 4
/* 0F8F84 002D45D4 AE2200B4 */  sw    $v0, 0xb4($s1)
/* 0F8F88 002D45D8 8E050000 */  lw    $a1, ($s0)
/* 0F8F8C 002D45DC 26100004 */  addiu $s0, $s0, 4
/* 0F8F90 002D45E0 0C0B1EAF */  jal   func_002C7ABC
/* 0F8F94 002D45E4 0220202D */   daddu $a0, $s1, $zero
/* 0F8F98 002D45E8 AE2200B8 */  sw    $v0, 0xb8($s1)
/* 0F8F9C 002D45EC 8E050000 */  lw    $a1, ($s0)
/* 0F8FA0 002D45F0 26100004 */  addiu $s0, $s0, 4
/* 0F8FA4 002D45F4 0C0B1EAF */  jal   func_002C7ABC
/* 0F8FA8 002D45F8 0220202D */   daddu $a0, $s1, $zero
/* 0F8FAC 002D45FC AE2200C0 */  sw    $v0, 0xc0($s1)
/* 0F8FB0 002D4600 8E050000 */  lw    $a1, ($s0)
/* 0F8FB4 002D4604 0C0B1EAF */  jal   func_002C7ABC
/* 0F8FB8 002D4608 0220202D */   daddu $a0, $s1, $zero
/* 0F8FBC 002D460C AE2200B0 */  sw    $v0, 0xb0($s1)
/* 0F8FC0 002D4610 AE2000BC */  sw    $zero, 0xbc($s1)
/* 0F8FC4 002D4614 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F8FC8 002D4618 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8FCC 002D461C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8FD0 002D4620 24020002 */  addiu $v0, $zero, 2
/* 0F8FD4 002D4624 03E00008 */  jr    $ra
/* 0F8FD8 002D4628 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8FDC 002D462C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8FE0 002D4630 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F8FE4 002D4634 0080802D */  daddu $s0, $a0, $zero
/* 0F8FE8 002D4638 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8FEC 002D463C C60200B4 */  lwc1  $f2, 0xb4($s0)
/* 0F8FF0 002D4640 468010A0 */  cvt.s.w $f2, $f2
/* 0F8FF4 002D4644 C60000B8 */  lwc1  $f0, 0xb8($s0)
/* 0F8FF8 002D4648 46800020 */  cvt.s.w $f0, $f0
/* 0F8FFC 002D464C 8E0200C0 */  lw    $v0, 0xc0($s0)
/* 0F9000 002D4650 44051000 */  mfc1  $a1, $f2
/* 0F9004 002D4654 44060000 */  mfc1  $a2, $f0
/* 0F9008 002D4658 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F900C 002D465C 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0F9010 002D4660 0C00A8ED */  jal   func_0002A3B4
/* 0F9014 002D4664 8E0700BC */   lw    $a3, 0xbc($s0)
/* 0F9018 002D4668 8E0200BC */  lw    $v0, 0xbc($s0)
/* 0F901C 002D466C 8E0300C0 */  lw    $v1, 0xc0($s0)
/* 0F9020 002D4670 4600010D */  trunc.w.s $f4, $f0
/* 0F9024 002D4674 E6040084 */  swc1  $f4, 0x84($s0)
/* 0F9028 002D4678 0043102A */  slt   $v0, $v0, $v1
/* 0F902C 002D467C 14400003 */  bnez  $v0, .L002D468C
/* 0F9030 002D4680 24020001 */   addiu $v0, $zero, 1
/* 0F9034 002D4684 080B51A4 */  j     func_002D4690
/* 0F9038 002D4688 AE000088 */   sw    $zero, 0x88($s0)

.L002D468C:
/* 0F903C 002D468C AE020088 */  sw    $v0, 0x88($s0)
func_002D4690:
/* 0F9040 002D4690 8E0200BC */  lw    $v0, 0xbc($s0)
/* 0F9044 002D4694 24420001 */  addiu $v0, $v0, 1
/* 0F9048 002D4698 AE0200BC */  sw    $v0, 0xbc($s0)
/* 0F904C 002D469C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F9050 002D46A0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F9054 002D46A4 24020002 */  addiu $v0, $zero, 2
/* 0F9058 002D46A8 03E00008 */  jr    $ra
/* 0F905C 002D46AC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F9060 002D46B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9064 002D46B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9068 002D46B8 0080882D */  daddu $s1, $a0, $zero
/* 0F906C 002D46BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F9070 002D46C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9074 002D46C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F9078 002D46C8 8E050000 */  lw    $a1, ($s0)
/* 0F907C 002D46CC 0C0B1EAF */  jal   func_002C7ABC
/* 0F9080 002D46D0 26100004 */   addiu $s0, $s0, 4
/* 0F9084 002D46D4 8E100000 */  lw    $s0, ($s0)
/* 0F9088 002D46D8 0C00A67F */  jal   func_000299FC
/* 0F908C 002D46DC 0040202D */   daddu $a0, $v0, $zero
/* 0F9090 002D46E0 0220202D */  daddu $a0, $s1, $zero
/* 0F9094 002D46E4 0040302D */  daddu $a2, $v0, $zero
/* 0F9098 002D46E8 0C0B2026 */  jal   func_002C8098
/* 0F909C 002D46EC 0200282D */   daddu $a1, $s0, $zero
/* 0F90A0 002D46F0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F90A4 002D46F4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F90A8 002D46F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F90AC 002D46FC 24020002 */  addiu $v0, $zero, 2
/* 0F90B0 002D4700 03E00008 */  jr    $ra
/* 0F90B4 002D4704 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F90B8 002D4708 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F90BC 002D470C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F90C0 002D4710 0080902D */  daddu $s2, $a0, $zero
/* 0F90C4 002D4714 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F90C8 002D4718 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F90CC 002D471C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F90D0 002D4720 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F90D4 002D4724 8E50000C */  lw    $s0, 0xc($s2)
/* 0F90D8 002D4728 8E050000 */  lw    $a1, ($s0)
/* 0F90DC 002D472C 0C0B1EAF */  jal   func_002C7ABC
/* 0F90E0 002D4730 26100004 */   addiu $s0, $s0, 4
/* 0F90E4 002D4734 8E050000 */  lw    $a1, ($s0)
/* 0F90E8 002D4738 26100004 */  addiu $s0, $s0, 4
/* 0F90EC 002D473C 0240202D */  daddu $a0, $s2, $zero
/* 0F90F0 002D4740 0C0B1EAF */  jal   func_002C7ABC
/* 0F90F4 002D4744 0040882D */   daddu $s1, $v0, $zero
/* 0F90F8 002D4748 0240202D */  daddu $a0, $s2, $zero
/* 0F90FC 002D474C 0220282D */  daddu $a1, $s1, $zero
/* 0F9100 002D4750 8E130000 */  lw    $s3, ($s0)
/* 0F9104 002D4754 0C0B36B0 */  jal   func_002CDAC0
/* 0F9108 002D4758 0040882D */   daddu $s1, $v0, $zero
/* 0F910C 002D475C 0240202D */  daddu $a0, $s2, $zero
/* 0F9110 002D4760 0220282D */  daddu $a1, $s1, $zero
/* 0F9114 002D4764 0C0B36B0 */  jal   func_002CDAC0
/* 0F9118 002D4768 0040802D */   daddu $s0, $v0, $zero
/* 0F911C 002D476C 8C460038 */  lw    $a2, 0x38($v0)
/* 0F9120 002D4770 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F9124 002D4774 C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F9128 002D4778 0C00A720 */  jal   func_00029C80
/* 0F912C 002D477C 8C470040 */   lw    $a3, 0x40($v0)
/* 0F9130 002D4780 0240202D */  daddu $a0, $s2, $zero
/* 0F9134 002D4784 4600008D */  trunc.w.s $f2, $f0
/* 0F9138 002D4788 44061000 */  mfc1  $a2, $f2
/* 0F913C 002D478C 0C0B2026 */  jal   func_002C8098
/* 0F9140 002D4790 0260282D */   daddu $a1, $s3, $zero
/* 0F9144 002D4794 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F9148 002D4798 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F914C 002D479C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9150 002D47A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9154 002D47A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9158 002D47A8 24020002 */  addiu $v0, $zero, 2
/* 0F915C 002D47AC 03E00008 */  jr    $ra
/* 0F9160 002D47B0 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F9164 002D47B4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9168 002D47B8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F916C 002D47BC 0080882D */  daddu $s1, $a0, $zero
/* 0F9170 002D47C0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F9174 002D47C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9178 002D47C8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F917C 002D47CC 8E050000 */  lw    $a1, ($s0)
/* 0F9180 002D47D0 0C0B1EAF */  jal   func_002C7ABC
/* 0F9184 002D47D4 26100004 */   addiu $s0, $s0, 4
/* 0F9188 002D47D8 0220202D */  daddu $a0, $s1, $zero
/* 0F918C 002D47DC 8E100000 */  lw    $s0, ($s0)
/* 0F9190 002D47E0 0C0B36B0 */  jal   func_002CDAC0
/* 0F9194 002D47E4 0040282D */   daddu $a1, $v0, $zero
/* 0F9198 002D47E8 3C038011 */  lui   $v1, 0x8011
/* 0F919C 002D47EC 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F91A0 002D47F0 8C460038 */  lw    $a2, 0x38($v0)
/* 0F91A4 002D47F4 C46C0028 */  lwc1  $f12, 0x28($v1)
/* 0F91A8 002D47F8 C46E0030 */  lwc1  $f14, 0x30($v1)
/* 0F91AC 002D47FC 0C00A720 */  jal   func_00029C80
/* 0F91B0 002D4800 8C470040 */   lw    $a3, 0x40($v0)
/* 0F91B4 002D4804 0220202D */  daddu $a0, $s1, $zero
/* 0F91B8 002D4808 4600008D */  trunc.w.s $f2, $f0
/* 0F91BC 002D480C 44061000 */  mfc1  $a2, $f2
/* 0F91C0 002D4810 0C0B2026 */  jal   func_002C8098
/* 0F91C4 002D4814 0200282D */   daddu $a1, $s0, $zero
/* 0F91C8 002D4818 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F91CC 002D481C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F91D0 002D4820 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F91D4 002D4824 24020002 */  addiu $v0, $zero, 2
/* 0F91D8 002D4828 03E00008 */  jr    $ra
/* 0F91DC 002D482C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F91E0 002D4830 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F91E4 002D4834 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F91E8 002D4838 0080882D */  daddu $s1, $a0, $zero
/* 0F91EC 002D483C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F91F0 002D4840 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F91F4 002D4844 8E30000C */  lw    $s0, 0xc($s1)
/* 0F91F8 002D4848 8E050000 */  lw    $a1, ($s0)
/* 0F91FC 002D484C 0C0B1EAF */  jal   func_002C7ABC
/* 0F9200 002D4850 26100004 */   addiu $s0, $s0, 4
/* 0F9204 002D4854 0220202D */  daddu $a0, $s1, $zero
/* 0F9208 002D4858 8E100000 */  lw    $s0, ($s0)
/* 0F920C 002D485C 0C0B36B0 */  jal   func_002CDAC0
/* 0F9210 002D4860 0040282D */   daddu $a1, $v0, $zero
/* 0F9214 002D4864 3C038011 */  lui   $v1, 0x8011
/* 0F9218 002D4868 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F921C 002D486C 8C660028 */  lw    $a2, 0x28($v1)
/* 0F9220 002D4870 C44C0038 */  lwc1  $f12, 0x38($v0)
/* 0F9224 002D4874 C44E0040 */  lwc1  $f14, 0x40($v0)
/* 0F9228 002D4878 0C00A720 */  jal   func_00029C80
/* 0F922C 002D487C 8C670030 */   lw    $a3, 0x30($v1)
/* 0F9230 002D4880 0220202D */  daddu $a0, $s1, $zero
/* 0F9234 002D4884 4600008D */  trunc.w.s $f2, $f0
/* 0F9238 002D4888 44061000 */  mfc1  $a2, $f2
/* 0F923C 002D488C 0C0B2026 */  jal   func_002C8098
/* 0F9240 002D4890 0200282D */   daddu $a1, $s0, $zero
/* 0F9244 002D4894 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F9248 002D4898 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F924C 002D489C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9250 002D48A0 24020002 */  addiu $v0, $zero, 2
/* 0F9254 002D48A4 03E00008 */  jr    $ra
/* 0F9258 002D48A8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F925C 002D48AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9260 002D48B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9264 002D48B4 0080882D */  daddu $s1, $a0, $zero
/* 0F9268 002D48B8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F926C 002D48BC 3C128011 */  lui   $s2, 0x8011
/* 0F9270 002D48C0 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F9274 002D48C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F9278 002D48C8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F927C 002D48CC 10A0000E */  beqz  $a1, .L002D4908
/* 0F9280 002D48D0 8E30000C */   lw    $s0, 0xc($s1)
/* 0F9284 002D48D4 8E050000 */  lw    $a1, ($s0)
/* 0F9288 002D48D8 0C0B1EAF */  jal   func_002C7ABC
/* 0F928C 002D48DC 26100004 */   addiu $s0, $s0, 4
/* 0F9290 002D48E0 AE220070 */  sw    $v0, 0x70($s1)
/* 0F9294 002D48E4 8E050000 */  lw    $a1, ($s0)
/* 0F9298 002D48E8 26100004 */  addiu $s0, $s0, 4
/* 0F929C 002D48EC 0C0B1EAF */  jal   func_002C7ABC
/* 0F92A0 002D48F0 0220202D */   daddu $a0, $s1, $zero
/* 0F92A4 002D48F4 AE220074 */  sw    $v0, 0x74($s1)
/* 0F92A8 002D48F8 8E050000 */  lw    $a1, ($s0)
/* 0F92AC 002D48FC 0C0B1EAF */  jal   func_002C7ABC
/* 0F92B0 002D4900 0220202D */   daddu $a0, $s1, $zero
/* 0F92B4 002D4904 AE220078 */  sw    $v0, 0x78($s1)
.L002D4908:
/* 0F92B8 002D4908 C6240070 */  lwc1  $f4, 0x70($s1)
/* 0F92BC 002D490C 46802120 */  cvt.s.w $f4, $f4
/* 0F92C0 002D4910 44062000 */  mfc1  $a2, $f4
/* 0F92C4 002D4914 C6240074 */  lwc1  $f4, 0x74($s1)
/* 0F92C8 002D4918 46802120 */  cvt.s.w $f4, $f4
/* 0F92CC 002D491C C64C0028 */  lwc1  $f12, 0x28($s2)
/* 0F92D0 002D4920 C64E0030 */  lwc1  $f14, 0x30($s2)
/* 0F92D4 002D4924 44072000 */  mfc1  $a3, $f4
/* 0F92D8 002D4928 0C00A7B5 */  jal   func_00029ED4
/* 0F92DC 002D492C 00000000 */   nop   
/* 0F92E0 002D4930 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F92E4 002D4934 468010A0 */  cvt.s.w $f2, $f2
/* 0F92E8 002D4938 4602003C */  c.lt.s $f0, $f2
/* 0F92EC 002D493C 00000000 */  nop   
/* 0F92F0 002D4940 45010002 */  bc1t  .L002D494C
/* 0F92F4 002D4944 24020002 */   addiu $v0, $zero, 2
/* 0F92F8 002D4948 0000102D */  daddu $v0, $zero, $zero
.L002D494C:
/* 0F92FC 002D494C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F9300 002D4950 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9304 002D4954 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9308 002D4958 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F930C 002D495C 03E00008 */  jr    $ra
/* 0F9310 002D4960 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F9314 002D4964 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F9318 002D4968 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F931C 002D496C 0080882D */  daddu $s1, $a0, $zero
/* 0F9320 002D4970 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9324 002D4974 3C12FE36 */  lui   $s2, 0xfe36
/* 0F9328 002D4978 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F932C 002D497C 3C138011 */  lui   $s3, 0x8011
/* 0F9330 002D4980 2673EFC8 */  addiu $s3, $s3, -0x1038
/* 0F9334 002D4984 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F9338 002D4988 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F933C 002D498C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0F9340 002D4990 8E30000C */  lw    $s0, 0xc($s1)
/* 0F9344 002D4994 10A00010 */  beqz  $a1, .L002D49D8
/* 0F9348 002D4998 36523C80 */   ori   $s2, $s2, 0x3c80
/* 0F934C 002D499C 8E050000 */  lw    $a1, ($s0)
/* 0F9350 002D49A0 0C0B1EAF */  jal   func_002C7ABC
/* 0F9354 002D49A4 26100004 */   addiu $s0, $s0, 4
/* 0F9358 002D49A8 AE220070 */  sw    $v0, 0x70($s1)
/* 0F935C 002D49AC 8E050000 */  lw    $a1, ($s0)
/* 0F9360 002D49B0 26100004 */  addiu $s0, $s0, 4
/* 0F9364 002D49B4 0C0B1EAF */  jal   func_002C7ABC
/* 0F9368 002D49B8 0220202D */   daddu $a0, $s1, $zero
/* 0F936C 002D49BC AE220074 */  sw    $v0, 0x74($s1)
/* 0F9370 002D49C0 8E050000 */  lw    $a1, ($s0)
/* 0F9374 002D49C4 26100004 */  addiu $s0, $s0, 4
/* 0F9378 002D49C8 0C0B1EAF */  jal   func_002C7ABC
/* 0F937C 002D49CC 0220202D */   daddu $a0, $s1, $zero
/* 0F9380 002D49D0 AE220078 */  sw    $v0, 0x78($s1)
/* 0F9384 002D49D4 8E120000 */  lw    $s2, ($s0)
.L002D49D8:
/* 0F9388 002D49D8 C6220070 */  lwc1  $f2, 0x70($s1)
/* 0F938C 002D49DC 468010A0 */  cvt.s.w $f2, $f2
/* 0F9390 002D49E0 44061000 */  mfc1  $a2, $f2
/* 0F9394 002D49E4 C6220074 */  lwc1  $f2, 0x74($s1)
/* 0F9398 002D49E8 468010A0 */  cvt.s.w $f2, $f2
/* 0F939C 002D49EC C66C0028 */  lwc1  $f12, 0x28($s3)
/* 0F93A0 002D49F0 C66E0030 */  lwc1  $f14, 0x30($s3)
/* 0F93A4 002D49F4 44071000 */  mfc1  $a3, $f2
/* 0F93A8 002D49F8 0C00A7B5 */  jal   func_00029ED4
/* 0F93AC 002D49FC 00000000 */   nop   
/* 0F93B0 002D4A00 0220202D */  daddu $a0, $s1, $zero
/* 0F93B4 002D4A04 0240282D */  daddu $a1, $s2, $zero
/* 0F93B8 002D4A08 0000302D */  daddu $a2, $zero, $zero
/* 0F93BC 002D4A0C 0C0B2026 */  jal   func_002C8098
/* 0F93C0 002D4A10 46000506 */   mov.s $f20, $f0
/* 0F93C4 002D4A14 C6200078 */  lwc1  $f0, 0x78($s1)
/* 0F93C8 002D4A18 46800020 */  cvt.s.w $f0, $f0
/* 0F93CC 002D4A1C 4600A03C */  c.lt.s $f20, $f0
/* 0F93D0 002D4A20 00000000 */  nop   
/* 0F93D4 002D4A24 45000004 */  bc1f  .L002D4A38
/* 0F93D8 002D4A28 0220202D */   daddu $a0, $s1, $zero
/* 0F93DC 002D4A2C 0240282D */  daddu $a1, $s2, $zero
/* 0F93E0 002D4A30 0C0B2026 */  jal   func_002C8098
/* 0F93E4 002D4A34 24060001 */   addiu $a2, $zero, 1
.L002D4A38:
/* 0F93E8 002D4A38 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F93EC 002D4A3C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F93F0 002D4A40 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F93F4 002D4A44 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F93F8 002D4A48 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F93FC 002D4A4C D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0F9400 002D4A50 24020002 */  addiu $v0, $zero, 2
/* 0F9404 002D4A54 03E00008 */  jr    $ra
/* 0F9408 002D4A58 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F940C 002D4A5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9410 002D4A60 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9414 002D4A64 0080882D */  daddu $s1, $a0, $zero
/* 0F9418 002D4A68 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F941C 002D4A6C 3C128011 */  lui   $s2, 0x8011
/* 0F9420 002D4A70 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F9424 002D4A74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F9428 002D4A78 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F942C 002D4A7C 10A0000E */  beqz  $a1, .L002D4AB8
/* 0F9430 002D4A80 8E30000C */   lw    $s0, 0xc($s1)
/* 0F9434 002D4A84 8E050000 */  lw    $a1, ($s0)
/* 0F9438 002D4A88 0C0B1EAF */  jal   func_002C7ABC
/* 0F943C 002D4A8C 26100004 */   addiu $s0, $s0, 4
/* 0F9440 002D4A90 AE220070 */  sw    $v0, 0x70($s1)
/* 0F9444 002D4A94 8E050000 */  lw    $a1, ($s0)
/* 0F9448 002D4A98 26100004 */  addiu $s0, $s0, 4
/* 0F944C 002D4A9C 0C0B1EAF */  jal   func_002C7ABC
/* 0F9450 002D4AA0 0220202D */   daddu $a0, $s1, $zero
/* 0F9454 002D4AA4 AE220074 */  sw    $v0, 0x74($s1)
/* 0F9458 002D4AA8 8E050000 */  lw    $a1, ($s0)
/* 0F945C 002D4AAC 0C0B1EAF */  jal   func_002C7ABC
/* 0F9460 002D4AB0 0220202D */   daddu $a0, $s1, $zero
/* 0F9464 002D4AB4 AE220078 */  sw    $v0, 0x78($s1)
.L002D4AB8:
/* 0F9468 002D4AB8 C6240070 */  lwc1  $f4, 0x70($s1)
/* 0F946C 002D4ABC 46802120 */  cvt.s.w $f4, $f4
/* 0F9470 002D4AC0 44062000 */  mfc1  $a2, $f4
/* 0F9474 002D4AC4 C6240074 */  lwc1  $f4, 0x74($s1)
/* 0F9478 002D4AC8 46802120 */  cvt.s.w $f4, $f4
/* 0F947C 002D4ACC C64C0028 */  lwc1  $f12, 0x28($s2)
/* 0F9480 002D4AD0 C64E0030 */  lwc1  $f14, 0x30($s2)
/* 0F9484 002D4AD4 44072000 */  mfc1  $a3, $f4
/* 0F9488 002D4AD8 0C00A7B5 */  jal   func_00029ED4
/* 0F948C 002D4ADC 00000000 */   nop   
/* 0F9490 002D4AE0 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F9494 002D4AE4 468010A0 */  cvt.s.w $f2, $f2
/* 0F9498 002D4AE8 4600103C */  c.lt.s $f2, $f0
/* 0F949C 002D4AEC 00000000 */  nop   
/* 0F94A0 002D4AF0 45010002 */  bc1t  .L002D4AFC
/* 0F94A4 002D4AF4 24020002 */   addiu $v0, $zero, 2
/* 0F94A8 002D4AF8 0000102D */  daddu $v0, $zero, $zero
.L002D4AFC:
/* 0F94AC 002D4AFC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F94B0 002D4B00 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F94B4 002D4B04 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F94B8 002D4B08 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F94BC 002D4B0C 03E00008 */  jr    $ra
/* 0F94C0 002D4B10 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F94C4 002D4B14 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F94C8 002D4B18 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F94CC 002D4B1C 0080882D */  daddu $s1, $a0, $zero
/* 0F94D0 002D4B20 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F94D4 002D4B24 AFB30024 */  sw    $s3, 0x24($sp)
/* 0F94D8 002D4B28 AFB20020 */  sw    $s2, 0x20($sp)
/* 0F94DC 002D4B2C AFB00018 */  sw    $s0, 0x18($sp)
/* 0F94E0 002D4B30 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0F94E4 002D4B34 8E30000C */  lw    $s0, 0xc($s1)
/* 0F94E8 002D4B38 8E130000 */  lw    $s3, ($s0)
/* 0F94EC 002D4B3C 26100004 */  addiu $s0, $s0, 4
/* 0F94F0 002D4B40 0C0B210B */  jal   func_002C842C
/* 0F94F4 002D4B44 0260282D */   daddu $a1, $s3, $zero
/* 0F94F8 002D4B48 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0F94FC 002D4B4C 8E120000 */  lw    $s2, ($s0)
/* 0F9500 002D4B50 26100004 */  addiu $s0, $s0, 4
/* 0F9504 002D4B54 0220202D */  daddu $a0, $s1, $zero
/* 0F9508 002D4B58 0C0B210B */  jal   func_002C842C
/* 0F950C 002D4B5C 0240282D */   daddu $a1, $s2, $zero
/* 0F9510 002D4B60 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0F9514 002D4B64 8E050000 */  lw    $a1, ($s0)
/* 0F9518 002D4B68 26100004 */  addiu $s0, $s0, 4
/* 0F951C 002D4B6C 0C0B210B */  jal   func_002C842C
/* 0F9520 002D4B70 0220202D */   daddu $a0, $s1, $zero
/* 0F9524 002D4B74 0220202D */  daddu $a0, $s1, $zero
/* 0F9528 002D4B78 8E050000 */  lw    $a1, ($s0)
/* 0F952C 002D4B7C 0C0B210B */  jal   func_002C842C
/* 0F9530 002D4B80 46000506 */   mov.s $f20, $f0
/* 0F9534 002D4B84 27A40010 */  addiu $a0, $sp, 0x10
/* 0F9538 002D4B88 4406A000 */  mfc1  $a2, $f20
/* 0F953C 002D4B8C 44070000 */  mfc1  $a3, $f0
/* 0F9540 002D4B90 0C00A7E7 */  jal   func_00029F9C
/* 0F9544 002D4B94 27A50014 */   addiu $a1, $sp, 0x14
/* 0F9548 002D4B98 0220202D */  daddu $a0, $s1, $zero
/* 0F954C 002D4B9C 8FA60010 */  lw    $a2, 0x10($sp)
/* 0F9550 002D4BA0 0C0B2190 */  jal   func_002C8640
/* 0F9554 002D4BA4 0260282D */   daddu $a1, $s3, $zero
/* 0F9558 002D4BA8 0220202D */  daddu $a0, $s1, $zero
/* 0F955C 002D4BAC 8FA60014 */  lw    $a2, 0x14($sp)
/* 0F9560 002D4BB0 0C0B2190 */  jal   func_002C8640
/* 0F9564 002D4BB4 0240282D */   daddu $a1, $s2, $zero
/* 0F9568 002D4BB8 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F956C 002D4BBC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0F9570 002D4BC0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F9574 002D4BC4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F9578 002D4BC8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F957C 002D4BCC D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0F9580 002D4BD0 24020002 */  addiu $v0, $zero, 2
/* 0F9584 002D4BD4 03E00008 */  jr    $ra
/* 0F9588 002D4BD8 27BD0038 */   addiu $sp, $sp, 0x38

/* 0F958C 002D4BDC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9590 002D4BE0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9594 002D4BE4 10A00003 */  beqz  $a1, .L002D4BF4
/* 0F9598 002D4BE8 0080182D */   daddu $v1, $a0, $zero
/* 0F959C 002D4BEC AC600070 */  sw    $zero, 0x70($v1)
/* 0F95A0 002D4BF0 AC600074 */  sw    $zero, 0x74($v1)
.L002D4BF4:
/* 0F95A4 002D4BF4 8C620070 */  lw    $v0, 0x70($v1)
/* 0F95A8 002D4BF8 14400011 */  bnez  $v0, .L002D4C40
/* 0F95AC 002D4BFC 0000102D */   daddu $v0, $zero, $zero
/* 0F95B0 002D4C00 8C620074 */  lw    $v0, 0x74($v1)
/* 0F95B4 002D4C04 240400FF */  addiu $a0, $zero, 0xff
/* 0F95B8 002D4C08 14440003 */  bne   $v0, $a0, .L002D4C18
/* 0F95BC 002D4C0C 2442000A */   addiu $v0, $v0, 0xa
/* 0F95C0 002D4C10 080B5310 */  j     func_002D4C40
/* 0F95C4 002D4C14 24020002 */   addiu $v0, $zero, 2

.L002D4C18:
/* 0F95C8 002D4C18 AC620074 */  sw    $v0, 0x74($v1)
/* 0F95CC 002D4C1C 28420100 */  slti  $v0, $v0, 0x100
/* 0F95D0 002D4C20 50400001 */  beql  $v0, $zero, .L002D4C28
/* 0F95D4 002D4C24 AC640074 */   sw    $a0, 0x74($v1)
.L002D4C28:
/* 0F95D8 002D4C28 C4600074 */  lwc1  $f0, 0x74($v1)
/* 0F95DC 002D4C2C 46800020 */  cvt.s.w $f0, $f0
/* 0F95E0 002D4C30 44050000 */  mfc1  $a1, $f0
/* 0F95E4 002D4C34 0C04DF69 */  jal   func_00137DA4
/* 0F95E8 002D4C38 2404000A */   addiu $a0, $zero, 0xa
/* 0F95EC 002D4C3C 0000102D */  daddu $v0, $zero, $zero
func_002D4C40:
.L002D4C40:
/* 0F95F0 002D4C40 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F95F4 002D4C44 03E00008 */  jr    $ra
/* 0F95F8 002D4C48 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F95FC 002D4C4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9600 002D4C50 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9604 002D4C54 10A00004 */  beqz  $a1, .L002D4C68
/* 0F9608 002D4C58 0080182D */   daddu $v1, $a0, $zero
/* 0F960C 002D4C5C 240200FF */  addiu $v0, $zero, 0xff
/* 0F9610 002D4C60 AC600070 */  sw    $zero, 0x70($v1)
/* 0F9614 002D4C64 AC620074 */  sw    $v0, 0x74($v1)
.L002D4C68:
/* 0F9618 002D4C68 8C620070 */  lw    $v0, 0x70($v1)
/* 0F961C 002D4C6C 14400012 */  bnez  $v0, .L002D4CB8
/* 0F9620 002D4C70 0000102D */   daddu $v0, $zero, $zero
/* 0F9624 002D4C74 8C620074 */  lw    $v0, 0x74($v1)
/* 0F9628 002D4C78 14400006 */  bnez  $v0, .L002D4C94
/* 0F962C 002D4C7C 2442FFF6 */   addiu $v0, $v0, -0xa
/* 0F9630 002D4C80 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9634 002D4C84 0C04DF69 */  jal   func_00137DA4
/* 0F9638 002D4C88 240400FF */   addiu $a0, $zero, 0xff
/* 0F963C 002D4C8C 080B532E */  j     func_002D4CB8
/* 0F9640 002D4C90 24020002 */   addiu $v0, $zero, 2

.L002D4C94:
/* 0F9644 002D4C94 04410002 */  bgez  $v0, .L002D4CA0
/* 0F9648 002D4C98 AC620074 */   sw    $v0, 0x74($v1)
/* 0F964C 002D4C9C AC600074 */  sw    $zero, 0x74($v1)
.L002D4CA0:
/* 0F9650 002D4CA0 C4600074 */  lwc1  $f0, 0x74($v1)
/* 0F9654 002D4CA4 46800020 */  cvt.s.w $f0, $f0
/* 0F9658 002D4CA8 44050000 */  mfc1  $a1, $f0
/* 0F965C 002D4CAC 0C04DF69 */  jal   func_00137DA4
/* 0F9660 002D4CB0 2404000A */   addiu $a0, $zero, 0xa
/* 0F9664 002D4CB4 0000102D */  daddu $v0, $zero, $zero
func_002D4CB8:
.L002D4CB8:
/* 0F9668 002D4CB8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F966C 002D4CBC 03E00008 */  jr    $ra
/* 0F9670 002D4CC0 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F9674 002D4CC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9678 002D4CC8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F967C 002D4CCC 8C82000C */  lw    $v0, 0xc($a0)
/* 0F9680 002D4CD0 0C0B1EAF */  jal   func_002C7ABC
/* 0F9684 002D4CD4 8C450000 */   lw    $a1, ($v0)
/* 0F9688 002D4CD8 04410004 */  bgez  $v0, .L002D4CEC
/* 0F968C 002D4CDC 2404000A */   addiu $a0, $zero, 0xa
/* 0F9690 002D4CE0 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9694 002D4CE4 080B533F */  j     func_002D4CFC
/* 0F9698 002D4CE8 240400FF */   addiu $a0, $zero, 0xff

.L002D4CEC:
/* 0F969C 002D4CEC 44820000 */  mtc1  $v0, $f0
/* 0F96A0 002D4CF0 00000000 */  nop   
/* 0F96A4 002D4CF4 46800020 */  cvt.s.w $f0, $f0
/* 0F96A8 002D4CF8 44050000 */  mfc1  $a1, $f0
func_002D4CFC:
/* 0F96AC 002D4CFC 0C04DF69 */  jal   func_00137DA4
/* 0F96B0 002D4D00 00000000 */   nop   
/* 0F96B4 002D4D04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F96B8 002D4D08 24020002 */  addiu $v0, $zero, 2
/* 0F96BC 002D4D0C 03E00008 */  jr    $ra
/* 0F96C0 002D4D10 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F96C4 002D4D14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F96C8 002D4D18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F96CC 002D4D1C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F96D0 002D4D20 8C82000C */  lw    $v0, 0xc($a0)
/* 0F96D4 002D4D24 0C0B210B */  jal   func_002C842C
/* 0F96D8 002D4D28 8C450000 */   lw    $a1, ($v0)
/* 0F96DC 002D4D2C 0000202D */  daddu $a0, $zero, $zero
/* 0F96E0 002D4D30 0080282D */  daddu $a1, $a0, $zero
/* 0F96E4 002D4D34 2406000C */  addiu $a2, $zero, 0xc
/* 0F96E8 002D4D38 4600008D */  trunc.w.s $f2, $f0
/* 0F96EC 002D4D3C 44101000 */  mfc1  $s0, $f2
/* 0F96F0 002D4D40 0C04DF93 */  jal   func_00137E4C
/* 0F96F4 002D4D44 24070014 */   addiu $a3, $zero, 0x14
/* 0F96F8 002D4D48 0000202D */  daddu $a0, $zero, $zero
/* 0F96FC 002D4D4C 24050001 */  addiu $a1, $zero, 1
/* 0F9700 002D4D50 24060134 */  addiu $a2, $zero, 0x134
/* 0F9704 002D4D54 0C04DF93 */  jal   func_00137E4C
/* 0F9708 002D4D58 240700DC */   addiu $a3, $zero, 0xdc
/* 0F970C 002D4D5C 44901000 */  mtc1  $s0, $f2
/* 0F9710 002D4D60 00000000 */  nop   
/* 0F9714 002D4D64 468010A0 */  cvt.s.w $f2, $f2
/* 0F9718 002D4D68 44051000 */  mfc1  $a1, $f2
/* 0F971C 002D4D6C 0C04DF62 */  jal   func_00137D88
/* 0F9720 002D4D70 2404000C */   addiu $a0, $zero, 0xc
/* 0F9724 002D4D74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F9728 002D4D78 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F972C 002D4D7C 24020002 */  addiu $v0, $zero, 2
/* 0F9730 002D4D80 03E00008 */  jr    $ra
/* 0F9734 002D4D84 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F9738 002D4D88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F973C 002D4D8C 2404000C */  addiu $a0, $zero, 0xc
/* 0F9740 002D4D90 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9744 002D4D94 0C04DF62 */  jal   func_00137D88
/* 0F9748 002D4D98 0000282D */   daddu $a1, $zero, $zero
/* 0F974C 002D4D9C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F9750 002D4DA0 24020002 */  addiu $v0, $zero, 2
/* 0F9754 002D4DA4 03E00008 */  jr    $ra
/* 0F9758 002D4DA8 27BD0018 */   addiu $sp, $sp, 0x18

func_002D4DAC:
/* 0F975C 002D4DAC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F9760 002D4DB0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F9764 002D4DB4 0080982D */  daddu $s3, $a0, $zero
/* 0F9768 002D4DB8 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F976C 002D4DBC 00A0A82D */  daddu $s5, $a1, $zero
/* 0F9770 002D4DC0 AFBE0030 */  sw    $fp, 0x30($sp)
/* 0F9774 002D4DC4 00C0F02D */  daddu $fp, $a2, $zero
/* 0F9778 002D4DC8 AFB60028 */  sw    $s6, 0x28($sp)
/* 0F977C 002D4DCC 00E0B02D */  daddu $s6, $a3, $zero
/* 0F9780 002D4DD0 00132080 */  sll   $a0, $s3, 2
/* 0F9784 002D4DD4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0F9788 002D4DD8 AFB7002C */  sw    $s7, 0x2c($sp)
/* 0F978C 002D4DDC AFB40020 */  sw    $s4, 0x20($sp)
/* 0F9790 002D4DE0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9794 002D4DE4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9798 002D4DE8 0C00AB39 */  jal   func_0002ACE4
/* 0F979C 002D4DEC AFB00010 */   sw    $s0, 0x10($sp)
/* 0F97A0 002D4DF0 00132040 */  sll   $a0, $s3, 1
/* 0F97A4 002D4DF4 00932021 */  addu  $a0, $a0, $s3
/* 0F97A8 002D4DF8 00042080 */  sll   $a0, $a0, 2
/* 0F97AC 002D4DFC 0C00AB39 */  jal   func_0002ACE4
/* 0F97B0 002D4E00 0040B82D */   daddu $s7, $v0, $zero
/* 0F97B4 002D4E04 24110001 */  addiu $s1, $zero, 1
/* 0F97B8 002D4E08 0040A02D */  daddu $s4, $v0, $zero
/* 0F97BC 002D4E0C 0233102A */  slt   $v0, $s1, $s3
/* 0F97C0 002D4E10 10400026 */  beqz  $v0, .L002D4EAC
/* 0F97C4 002D4E14 AEA00000 */   sw    $zero, ($s5)
/* 0F97C8 002D4E18 26B20004 */  addiu $s2, $s5, 4
/* 0F97CC 002D4E1C 27D0000C */  addiu $s0, $fp, 0xc
.L002D4E20:
/* 0F97D0 002D4E20 C6040000 */  lwc1  $f4, ($s0)
/* 0F97D4 002D4E24 C600FFF4 */  lwc1  $f0, -0xc($s0)
/* 0F97D8 002D4E28 46002101 */  sub.s $f4, $f4, $f0
/* 0F97DC 002D4E2C 46042102 */  mul.s $f4, $f4, $f4
/* 0F97E0 002D4E30 00000000 */  nop   
/* 0F97E4 002D4E34 C6060004 */  lwc1  $f6, 4($s0)
/* 0F97E8 002D4E38 C600FFF8 */  lwc1  $f0, -8($s0)
/* 0F97EC 002D4E3C 46003181 */  sub.s $f6, $f6, $f0
/* 0F97F0 002D4E40 46063182 */  mul.s $f6, $f6, $f6
/* 0F97F4 002D4E44 00000000 */  nop   
/* 0F97F8 002D4E48 C602FFFC */  lwc1  $f2, -4($s0)
/* 0F97FC 002D4E4C C6000008 */  lwc1  $f0, 8($s0)
/* 0F9800 002D4E50 46020001 */  sub.s $f0, $f0, $f2
/* 0F9804 002D4E54 46000002 */  mul.s $f0, $f0, $f0
/* 0F9808 002D4E58 00000000 */  nop   
/* 0F980C 002D4E5C 46062100 */  add.s $f4, $f4, $f6
/* 0F9810 002D4E60 46002300 */  add.s $f12, $f4, $f0
/* 0F9814 002D4E64 46006084 */  sqrt.s $f2, $f12
/* 0F9818 002D4E68 46021032 */  c.eq.s $f2, $f2
/* 0F981C 002D4E6C 00000000 */  nop   
/* 0F9820 002D4E70 45010004 */  bc1t  .L002D4E84
/* 0F9824 002D4E74 00000000 */   nop   
/* 0F9828 002D4E78 0C0187BC */  jal   func_00061EF0
/* 0F982C 002D4E7C 00000000 */   nop   
/* 0F9830 002D4E80 46000086 */  mov.s $f2, $f0
.L002D4E84:
/* 0F9834 002D4E84 C640FFFC */  lwc1  $f0, -4($s2)
/* 0F9838 002D4E88 2610000C */  addiu $s0, $s0, 0xc
/* 0F983C 002D4E8C 46020000 */  add.s $f0, $f0, $f2
/* 0F9840 002D4E90 26310001 */  addiu $s1, $s1, 1
/* 0F9844 002D4E94 0233102A */  slt   $v0, $s1, $s3
/* 0F9848 002D4E98 E6400000 */  swc1  $f0, ($s2)
/* 0F984C 002D4E9C 1440FFE0 */  bnez  $v0, .L002D4E20
/* 0F9850 002D4EA0 26520004 */   addiu $s2, $s2, 4
/* 0F9854 002D4EA4 24110001 */  addiu $s1, $zero, 1
/* 0F9858 002D4EA8 0233102A */  slt   $v0, $s1, $s3
.L002D4EAC:
/* 0F985C 002D4EAC 1040000B */  beqz  $v0, .L002D4EDC
/* 0F9860 002D4EB0 00131080 */   sll   $v0, $s3, 2
/* 0F9864 002D4EB4 00552021 */  addu  $a0, $v0, $s5
/* 0F9868 002D4EB8 26A30004 */  addiu $v1, $s5, 4
.L002D4EBC:
/* 0F986C 002D4EBC 26310001 */  addiu $s1, $s1, 1
/* 0F9870 002D4EC0 C4600000 */  lwc1  $f0, ($v1)
/* 0F9874 002D4EC4 C482FFFC */  lwc1  $f2, -4($a0)
/* 0F9878 002D4EC8 0233102A */  slt   $v0, $s1, $s3
/* 0F987C 002D4ECC 46020003 */  div.s $f0, $f0, $f2
/* 0F9880 002D4ED0 E4600000 */  swc1  $f0, ($v1)
/* 0F9884 002D4ED4 1440FFF9 */  bnez  $v0, .L002D4EBC
/* 0F9888 002D4ED8 24630004 */   addiu $v1, $v1, 4
.L002D4EDC:
/* 0F988C 002D4EDC 0000882D */  daddu $s1, $zero, $zero
/* 0F9890 002D4EE0 00131040 */  sll   $v0, $s3, 1
/* 0F9894 002D4EE4 00531021 */  addu  $v0, $v0, $s3
/* 0F9898 002D4EE8 00021080 */  sll   $v0, $v0, 2
/* 0F989C 002D4EEC 00561021 */  addu  $v0, $v0, $s6
/* 0F98A0 002D4EF0 2667FFFF */  addiu $a3, $s3, -1
/* 0F98A4 002D4EF4 AEC00000 */  sw    $zero, ($s6)
/* 0F98A8 002D4EF8 AEC00004 */  sw    $zero, 4($s6)
/* 0F98AC 002D4EFC AEC00008 */  sw    $zero, 8($s6)
/* 0F98B0 002D4F00 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F98B4 002D4F04 AC40FFF8 */  sw    $zero, -8($v0)
/* 0F98B8 002D4F08 18E00021 */  blez  $a3, .L002D4F90
/* 0F98BC 002D4F0C AC40FFFC */   sw    $zero, -4($v0)
/* 0F98C0 002D4F10 02E0202D */  daddu $a0, $s7, $zero
/* 0F98C4 002D4F14 03C0302D */  daddu $a2, $fp, $zero
/* 0F98C8 002D4F18 0280182D */  daddu $v1, $s4, $zero
/* 0F98CC 002D4F1C 02A0282D */  daddu $a1, $s5, $zero
.L002D4F20:
/* 0F98D0 002D4F20 C4A40004 */  lwc1  $f4, 4($a1)
/* 0F98D4 002D4F24 C4A00000 */  lwc1  $f0, ($a1)
/* 0F98D8 002D4F28 46002101 */  sub.s $f4, $f4, $f0
/* 0F98DC 002D4F2C E4840000 */  swc1  $f4, ($a0)
/* 0F98E0 002D4F30 C4C0000C */  lwc1  $f0, 0xc($a2)
/* 0F98E4 002D4F34 C4C20000 */  lwc1  $f2, ($a2)
/* 0F98E8 002D4F38 46020001 */  sub.s $f0, $f0, $f2
/* 0F98EC 002D4F3C 24A50004 */  addiu $a1, $a1, 4
/* 0F98F0 002D4F40 46040003 */  div.s $f0, $f0, $f4
/* 0F98F4 002D4F44 E460000C */  swc1  $f0, 0xc($v1)
/* 0F98F8 002D4F48 C4C20010 */  lwc1  $f2, 0x10($a2)
/* 0F98FC 002D4F4C C4C00004 */  lwc1  $f0, 4($a2)
/* 0F9900 002D4F50 26310001 */  addiu $s1, $s1, 1
/* 0F9904 002D4F54 46001081 */  sub.s $f2, $f2, $f0
/* 0F9908 002D4F58 C4800000 */  lwc1  $f0, ($a0)
/* 0F990C 002D4F5C 0227102A */  slt   $v0, $s1, $a3
/* 0F9910 002D4F60 46001083 */  div.s $f2, $f2, $f0
/* 0F9914 002D4F64 E4620010 */  swc1  $f2, 0x10($v1)
/* 0F9918 002D4F68 C4C00014 */  lwc1  $f0, 0x14($a2)
/* 0F991C 002D4F6C C4C20008 */  lwc1  $f2, 8($a2)
/* 0F9920 002D4F70 24C6000C */  addiu $a2, $a2, 0xc
/* 0F9924 002D4F74 46020001 */  sub.s $f0, $f0, $f2
/* 0F9928 002D4F78 C4820000 */  lwc1  $f2, ($a0)
/* 0F992C 002D4F7C 24840004 */  addiu $a0, $a0, 4
/* 0F9930 002D4F80 46020003 */  div.s $f0, $f0, $f2
/* 0F9934 002D4F84 E4600014 */  swc1  $f0, 0x14($v1)
/* 0F9938 002D4F88 1440FFE5 */  bnez  $v0, .L002D4F20
/* 0F993C 002D4F8C 2463000C */   addiu $v1, $v1, 0xc
.L002D4F90:
/* 0F9940 002D4F90 C6800018 */  lwc1  $f0, 0x18($s4)
/* 0F9944 002D4F94 C682000C */  lwc1  $f2, 0xc($s4)
/* 0F9948 002D4F98 46020001 */  sub.s $f0, $f0, $f2
/* 0F994C 002D4F9C E6C0000C */  swc1  $f0, 0xc($s6)
/* 0F9950 002D4FA0 C680001C */  lwc1  $f0, 0x1c($s4)
/* 0F9954 002D4FA4 C6820010 */  lwc1  $f2, 0x10($s4)
/* 0F9958 002D4FA8 46020001 */  sub.s $f0, $f0, $f2
/* 0F995C 002D4FAC E6C00010 */  swc1  $f0, 0x10($s6)
/* 0F9960 002D4FB0 C6800020 */  lwc1  $f0, 0x20($s4)
/* 0F9964 002D4FB4 C6820014 */  lwc1  $f2, 0x14($s4)
/* 0F9968 002D4FB8 46020001 */  sub.s $f0, $f0, $f2
/* 0F996C 002D4FBC E6C00014 */  swc1  $f0, 0x14($s6)
/* 0F9970 002D4FC0 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F9974 002D4FC4 C6A20000 */  lwc1  $f2, ($s5)
/* 0F9978 002D4FC8 46020001 */  sub.s $f0, $f0, $f2
/* 0F997C 002D4FCC 46000000 */  add.s $f0, $f0, $f0
/* 0F9980 002D4FD0 E680000C */  swc1  $f0, 0xc($s4)
/* 0F9984 002D4FD4 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F9988 002D4FD8 C6A20000 */  lwc1  $f2, ($s5)
/* 0F998C 002D4FDC 46020001 */  sub.s $f0, $f0, $f2
/* 0F9990 002D4FE0 46000000 */  add.s $f0, $f0, $f0
/* 0F9994 002D4FE4 E6800010 */  swc1  $f0, 0x10($s4)
/* 0F9998 002D4FE8 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F999C 002D4FEC C6A20000 */  lwc1  $f2, ($s5)
/* 0F99A0 002D4FF0 46020001 */  sub.s $f0, $f0, $f2
/* 0F99A4 002D4FF4 24110001 */  addiu $s1, $zero, 1
/* 0F99A8 002D4FF8 46000000 */  add.s $f0, $f0, $f0
/* 0F99AC 002D4FFC 2667FFFE */  addiu $a3, $s3, -2
/* 0F99B0 002D5000 0227102A */  slt   $v0, $s1, $a3
/* 0F99B4 002D5004 10400046 */  beqz  $v0, .L002D5120
/* 0F99B8 002D5008 E6800014 */   swc1  $f0, 0x14($s4)
/* 0F99BC 002D500C 26E60004 */  addiu $a2, $s7, 4
/* 0F99C0 002D5010 26A50004 */  addiu $a1, $s5, 4
/* 0F99C4 002D5014 26C4000C */  addiu $a0, $s6, 0xc
/* 0F99C8 002D5018 2683000C */  addiu $v1, $s4, 0xc
.L002D501C:
/* 0F99CC 002D501C C4CC0000 */  lwc1  $f12, ($a2)
/* 0F99D0 002D5020 C4660000 */  lwc1  $f6, ($v1)
/* 0F99D4 002D5024 C4840000 */  lwc1  $f4, ($a0)
/* 0F99D8 002D5028 46066183 */  div.s $f6, $f12, $f6
/* 0F99DC 002D502C 46062102 */  mul.s $f4, $f4, $f6
/* 0F99E0 002D5030 00000000 */  nop   
/* 0F99E4 002D5034 C4600018 */  lwc1  $f0, 0x18($v1)
/* 0F99E8 002D5038 C462000C */  lwc1  $f2, 0xc($v1)
/* 0F99EC 002D503C 46020001 */  sub.s $f0, $f0, $f2
/* 0F99F0 002D5040 C4680004 */  lwc1  $f8, 4($v1)
/* 0F99F4 002D5044 C46A0008 */  lwc1  $f10, 8($v1)
/* 0F99F8 002D5048 46040001 */  sub.s $f0, $f0, $f4
/* 0F99FC 002D504C C4840004 */  lwc1  $f4, 4($a0)
/* 0F9A00 002D5050 46086203 */  div.s $f8, $f12, $f8
/* 0F9A04 002D5054 46082102 */  mul.s $f4, $f4, $f8
/* 0F9A08 002D5058 00000000 */  nop   
/* 0F9A0C 002D505C E480000C */  swc1  $f0, 0xc($a0)
/* 0F9A10 002D5060 C462001C */  lwc1  $f2, 0x1c($v1)
/* 0F9A14 002D5064 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0F9A18 002D5068 46001081 */  sub.s $f2, $f2, $f0
/* 0F9A1C 002D506C 46041081 */  sub.s $f2, $f2, $f4
/* 0F9A20 002D5070 C4840008 */  lwc1  $f4, 8($a0)
/* 0F9A24 002D5074 460A6303 */  div.s $f12, $f12, $f10
/* 0F9A28 002D5078 460C2102 */  mul.s $f4, $f4, $f12
/* 0F9A2C 002D507C 00000000 */  nop   
/* 0F9A30 002D5080 E4820010 */  swc1  $f2, 0x10($a0)
/* 0F9A34 002D5084 C4600020 */  lwc1  $f0, 0x20($v1)
/* 0F9A38 002D5088 C4620014 */  lwc1  $f2, 0x14($v1)
/* 0F9A3C 002D508C 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A40 002D5090 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A44 002D5094 E4800014 */  swc1  $f0, 0x14($a0)
/* 0F9A48 002D5098 C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A4C 002D509C 46062102 */  mul.s $f4, $f4, $f6
/* 0F9A50 002D50A0 00000000 */  nop   
/* 0F9A54 002D50A4 C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9A58 002D50A8 C4A20000 */  lwc1  $f2, ($a1)
/* 0F9A5C 002D50AC 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A60 002D50B0 46000000 */  add.s $f0, $f0, $f0
/* 0F9A64 002D50B4 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A68 002D50B8 E460000C */  swc1  $f0, 0xc($v1)
/* 0F9A6C 002D50BC C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A70 002D50C0 46082102 */  mul.s $f4, $f4, $f8
/* 0F9A74 002D50C4 00000000 */  nop   
/* 0F9A78 002D50C8 C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9A7C 002D50CC C4A20000 */  lwc1  $f2, ($a1)
/* 0F9A80 002D50D0 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A84 002D50D4 46000000 */  add.s $f0, $f0, $f0
/* 0F9A88 002D50D8 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A8C 002D50DC E4600010 */  swc1  $f0, 0x10($v1)
/* 0F9A90 002D50E0 C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A94 002D50E4 460C2102 */  mul.s $f4, $f4, $f12
/* 0F9A98 002D50E8 00000000 */  nop   
/* 0F9A9C 002D50EC C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9AA0 002D50F0 C4A20000 */  lwc1  $f2, ($a1)
/* 0F9AA4 002D50F4 46020001 */  sub.s $f0, $f0, $f2
/* 0F9AA8 002D50F8 26310001 */  addiu $s1, $s1, 1
/* 0F9AAC 002D50FC 46000000 */  add.s $f0, $f0, $f0
/* 0F9AB0 002D5100 0227102A */  slt   $v0, $s1, $a3
/* 0F9AB4 002D5104 2484000C */  addiu $a0, $a0, 0xc
/* 0F9AB8 002D5108 46040001 */  sub.s $f0, $f0, $f4
/* 0F9ABC 002D510C 24C60004 */  addiu $a2, $a2, 4
/* 0F9AC0 002D5110 24A50004 */  addiu $a1, $a1, 4
/* 0F9AC4 002D5114 E4600014 */  swc1  $f0, 0x14($v1)
/* 0F9AC8 002D5118 1440FFC0 */  bnez  $v0, .L002D501C
/* 0F9ACC 002D511C 2463000C */   addiu $v1, $v1, 0xc
.L002D5120:
/* 0F9AD0 002D5120 00131040 */  sll   $v0, $s3, 1
/* 0F9AD4 002D5124 00531021 */  addu  $v0, $v0, $s3
/* 0F9AD8 002D5128 00021080 */  sll   $v0, $v0, 2
/* 0F9ADC 002D512C 00561021 */  addu  $v0, $v0, $s6
/* 0F9AE0 002D5130 00131880 */  sll   $v1, $s3, 2
/* 0F9AE4 002D5134 00771821 */  addu  $v1, $v1, $s7
/* 0F9AE8 002D5138 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9AEC 002D513C C440FFF4 */  lwc1  $f0, -0xc($v0)
/* 0F9AF0 002D5140 46001082 */  mul.s $f2, $f2, $f0
/* 0F9AF4 002D5144 00000000 */  nop   
/* 0F9AF8 002D5148 C440FFE8 */  lwc1  $f0, -0x18($v0)
/* 0F9AFC 002D514C 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B00 002D5150 E440FFE8 */  swc1  $f0, -0x18($v0)
/* 0F9B04 002D5154 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9B08 002D5158 C440FFF8 */  lwc1  $f0, -8($v0)
/* 0F9B0C 002D515C 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B10 002D5160 00000000 */  nop   
/* 0F9B14 002D5164 C440FFEC */  lwc1  $f0, -0x14($v0)
/* 0F9B18 002D5168 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B1C 002D516C E440FFEC */  swc1  $f0, -0x14($v0)
/* 0F9B20 002D5170 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9B24 002D5174 C440FFFC */  lwc1  $f0, -4($v0)
/* 0F9B28 002D5178 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B2C 002D517C 00000000 */  nop   
/* 0F9B30 002D5180 C440FFF0 */  lwc1  $f0, -0x10($v0)
/* 0F9B34 002D5184 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B38 002D5188 2671FFFE */  addiu $s1, $s3, -2
/* 0F9B3C 002D518C 1A200028 */  blez  $s1, .L002D5230
/* 0F9B40 002D5190 E440FFF0 */   swc1  $f0, -0x10($v0)
/* 0F9B44 002D5194 00111080 */  sll   $v0, $s1, 2
/* 0F9B48 002D5198 00571821 */  addu  $v1, $v0, $s7
/* 0F9B4C 002D519C 00111040 */  sll   $v0, $s1, 1
/* 0F9B50 002D51A0 00511021 */  addu  $v0, $v0, $s1
/* 0F9B54 002D51A4 00021080 */  sll   $v0, $v0, 2
/* 0F9B58 002D51A8 00563821 */  addu  $a3, $v0, $s6
/* 0F9B5C 002D51AC 00541021 */  addu  $v0, $v0, $s4
.L002D51B0:
/* 0F9B60 002D51B0 C4620000 */  lwc1  $f2, ($v1)
/* 0F9B64 002D51B4 C4E0000C */  lwc1  $f0, 0xc($a3)
/* 0F9B68 002D51B8 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B6C 002D51BC 00000000 */  nop   
/* 0F9B70 002D51C0 C4E00000 */  lwc1  $f0, ($a3)
/* 0F9B74 002D51C4 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B78 002D51C8 C4420000 */  lwc1  $f2, ($v0)
/* 0F9B7C 002D51CC 46020003 */  div.s $f0, $f0, $f2
/* 0F9B80 002D51D0 E4E00000 */  swc1  $f0, ($a3)
/* 0F9B84 002D51D4 C4620000 */  lwc1  $f2, ($v1)
/* 0F9B88 002D51D8 C4E00010 */  lwc1  $f0, 0x10($a3)
/* 0F9B8C 002D51DC 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B90 002D51E0 00000000 */  nop   
/* 0F9B94 002D51E4 C4E00004 */  lwc1  $f0, 4($a3)
/* 0F9B98 002D51E8 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B9C 002D51EC C4420004 */  lwc1  $f2, 4($v0)
/* 0F9BA0 002D51F0 46020003 */  div.s $f0, $f0, $f2
/* 0F9BA4 002D51F4 E4E00004 */  swc1  $f0, 4($a3)
/* 0F9BA8 002D51F8 C4620000 */  lwc1  $f2, ($v1)
/* 0F9BAC 002D51FC C4E00014 */  lwc1  $f0, 0x14($a3)
/* 0F9BB0 002D5200 46001082 */  mul.s $f2, $f2, $f0
/* 0F9BB4 002D5204 00000000 */  nop   
/* 0F9BB8 002D5208 2631FFFF */  addiu $s1, $s1, -1
/* 0F9BBC 002D520C C4E00008 */  lwc1  $f0, 8($a3)
/* 0F9BC0 002D5210 2463FFFC */  addiu $v1, $v1, -4
/* 0F9BC4 002D5214 46020001 */  sub.s $f0, $f0, $f2
/* 0F9BC8 002D5218 C4420008 */  lwc1  $f2, 8($v0)
/* 0F9BCC 002D521C 2442FFF4 */  addiu $v0, $v0, -0xc
/* 0F9BD0 002D5220 46020003 */  div.s $f0, $f0, $f2
/* 0F9BD4 002D5224 E4E00008 */  swc1  $f0, 8($a3)
/* 0F9BD8 002D5228 1E20FFE1 */  bgtz  $s1, .L002D51B0
/* 0F9BDC 002D522C 24E7FFF4 */   addiu $a3, $a3, -0xc
.L002D5230:
/* 0F9BE0 002D5230 0C00AB4B */  jal   func_0002AD2C
/* 0F9BE4 002D5234 02E0202D */   daddu $a0, $s7, $zero
/* 0F9BE8 002D5238 0C00AB4B */  jal   func_0002AD2C
/* 0F9BEC 002D523C 0280202D */   daddu $a0, $s4, $zero
/* 0F9BF0 002D5240 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0F9BF4 002D5244 8FBE0030 */  lw    $fp, 0x30($sp)
/* 0F9BF8 002D5248 8FB7002C */  lw    $s7, 0x2c($sp)
/* 0F9BFC 002D524C 8FB60028 */  lw    $s6, 0x28($sp)
/* 0F9C00 002D5250 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F9C04 002D5254 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F9C08 002D5258 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F9C0C 002D525C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9C10 002D5260 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9C14 002D5264 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9C18 002D5268 03E00008 */  jr    $ra
/* 0F9C1C 002D526C 27BD0038 */   addiu $sp, $sp, 0x38

func_002D5270:
/* 0F9C20 002D5270 24C6FFFF */  addiu $a2, $a2, -1
/* 0F9C24 002D5274 18C00010 */  blez  $a2, .L002D52B8
/* 0F9C28 002D5278 0000202D */   daddu $a0, $zero, $zero
/* 0F9C2C 002D527C 00861021 */  addu  $v0, $a0, $a2
.L002D5280:
/* 0F9C30 002D5280 00021FC2 */  srl   $v1, $v0, 0x1f
/* 0F9C34 002D5284 00431021 */  addu  $v0, $v0, $v1
/* 0F9C38 002D5288 00021843 */  sra   $v1, $v0, 1
/* 0F9C3C 002D528C 00031080 */  sll   $v0, $v1, 2
/* 0F9C40 002D5290 00471021 */  addu  $v0, $v0, $a3
/* 0F9C44 002D5294 C4400000 */  lwc1  $f0, ($v0)
/* 0F9C48 002D5298 460C003C */  c.lt.s $f0, $f12
/* 0F9C4C 002D529C 00000000 */  nop   
/* 0F9C50 002D52A0 45020002 */  bc1fl .L002D52AC
/* 0F9C54 002D52A4 0060302D */   daddu $a2, $v1, $zero
/* 0F9C58 002D52A8 24640001 */  addiu $a0, $v1, 1
.L002D52AC:
/* 0F9C5C 002D52AC 0086102A */  slt   $v0, $a0, $a2
/* 0F9C60 002D52B0 1440FFF3 */  bnez  $v0, .L002D5280
/* 0F9C64 002D52B4 00861021 */   addu  $v0, $a0, $a2
.L002D52B8:
/* 0F9C68 002D52B8 5C800001 */  bgtzl $a0, .L002D52C0
/* 0F9C6C 002D52BC 2484FFFF */   addiu $a0, $a0, -1
.L002D52C0:
/* 0F9C70 002D52C0 00041080 */  sll   $v0, $a0, 2
/* 0F9C74 002D52C4 00471021 */  addu  $v0, $v0, $a3
/* 0F9C78 002D52C8 00041840 */  sll   $v1, $a0, 1
/* 0F9C7C 002D52CC 00641821 */  addu  $v1, $v1, $a0
/* 0F9C80 002D52D0 00031880 */  sll   $v1, $v1, 2
/* 0F9C84 002D52D4 8FA40014 */  lw    $a0, 0x14($sp)
/* 0F9C88 002D52D8 C4480000 */  lwc1  $f8, ($v0)
/* 0F9C8C 002D52DC 00642021 */  addu  $a0, $v1, $a0
/* 0F9C90 002D52E0 C4840000 */  lwc1  $f4, ($a0)
/* 0F9C94 002D52E4 46086281 */  sub.s $f10, $f12, $f8
/* 0F9C98 002D52E8 3C014040 */  lui   $at, 0x4040
/* 0F9C9C 002D52EC 44816000 */  mtc1  $at, $f12
/* 0F9CA0 002D52F0 00000000 */  nop   
/* 0F9CA4 002D52F4 460C2002 */  mul.s $f0, $f4, $f12
/* 0F9CA8 002D52F8 00000000 */  nop   
/* 0F9CAC 002D52FC C48E000C */  lwc1  $f14, 0xc($a0)
/* 0F9CB0 002D5300 46047081 */  sub.s $f2, $f14, $f4
/* 0F9CB4 002D5304 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9CB8 002D5308 00000000 */  nop   
/* 0F9CBC 002D530C C4460004 */  lwc1  $f6, 4($v0)
/* 0F9CC0 002D5310 46083181 */  sub.s $f6, $f6, $f8
/* 0F9CC4 002D5314 46042100 */  add.s $f4, $f4, $f4
/* 0F9CC8 002D5318 460E2100 */  add.s $f4, $f4, $f14
/* 0F9CCC 002D531C 46062102 */  mul.s $f4, $f4, $f6
/* 0F9CD0 002D5320 00000000 */  nop   
/* 0F9CD4 002D5324 46061083 */  div.s $f2, $f2, $f6
/* 0F9CD8 002D5328 46001080 */  add.s $f2, $f2, $f0
/* 0F9CDC 002D532C 8FA20010 */  lw    $v0, 0x10($sp)
/* 0F9CE0 002D5330 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9CE4 002D5334 00000000 */  nop   
/* 0F9CE8 002D5338 00621821 */  addu  $v1, $v1, $v0
/* 0F9CEC 002D533C C4680000 */  lwc1  $f8, ($v1)
/* 0F9CF0 002D5340 C460000C */  lwc1  $f0, 0xc($v1)
/* 0F9CF4 002D5344 46080001 */  sub.s $f0, $f0, $f8
/* 0F9CF8 002D5348 46060003 */  div.s $f0, $f0, $f6
/* 0F9CFC 002D534C 46040001 */  sub.s $f0, $f0, $f4
/* 0F9D00 002D5350 46001080 */  add.s $f2, $f2, $f0
/* 0F9D04 002D5354 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D08 002D5358 00000000 */  nop   
/* 0F9D0C 002D535C 46081080 */  add.s $f2, $f2, $f8
/* 0F9D10 002D5360 E4A20000 */  swc1  $f2, ($a1)
/* 0F9D14 002D5364 C4840004 */  lwc1  $f4, 4($a0)
/* 0F9D18 002D5368 460C2002 */  mul.s $f0, $f4, $f12
/* 0F9D1C 002D536C 00000000 */  nop   
/* 0F9D20 002D5370 C4880010 */  lwc1  $f8, 0x10($a0)
/* 0F9D24 002D5374 46044081 */  sub.s $f2, $f8, $f4
/* 0F9D28 002D5378 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D2C 002D537C 00000000 */  nop   
/* 0F9D30 002D5380 46042100 */  add.s $f4, $f4, $f4
/* 0F9D34 002D5384 46082100 */  add.s $f4, $f4, $f8
/* 0F9D38 002D5388 46062102 */  mul.s $f4, $f4, $f6
/* 0F9D3C 002D538C 00000000 */  nop   
/* 0F9D40 002D5390 46061083 */  div.s $f2, $f2, $f6
/* 0F9D44 002D5394 46001080 */  add.s $f2, $f2, $f0
/* 0F9D48 002D5398 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D4C 002D539C 00000000 */  nop   
/* 0F9D50 002D53A0 C4680004 */  lwc1  $f8, 4($v1)
/* 0F9D54 002D53A4 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0F9D58 002D53A8 46080001 */  sub.s $f0, $f0, $f8
/* 0F9D5C 002D53AC 46060003 */  div.s $f0, $f0, $f6
/* 0F9D60 002D53B0 46040001 */  sub.s $f0, $f0, $f4
/* 0F9D64 002D53B4 46001080 */  add.s $f2, $f2, $f0
/* 0F9D68 002D53B8 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D6C 002D53BC 00000000 */  nop   
/* 0F9D70 002D53C0 46081080 */  add.s $f2, $f2, $f8
/* 0F9D74 002D53C4 E4A20004 */  swc1  $f2, 4($a1)
/* 0F9D78 002D53C8 C4840008 */  lwc1  $f4, 8($a0)
/* 0F9D7C 002D53CC 460C2302 */  mul.s $f12, $f4, $f12
/* 0F9D80 002D53D0 00000000 */  nop   
/* 0F9D84 002D53D4 C4800014 */  lwc1  $f0, 0x14($a0)
/* 0F9D88 002D53D8 46040081 */  sub.s $f2, $f0, $f4
/* 0F9D8C 002D53DC 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D90 002D53E0 00000000 */  nop   
/* 0F9D94 002D53E4 46042100 */  add.s $f4, $f4, $f4
/* 0F9D98 002D53E8 46002100 */  add.s $f4, $f4, $f0
/* 0F9D9C 002D53EC 46062102 */  mul.s $f4, $f4, $f6
/* 0F9DA0 002D53F0 00000000 */  nop   
/* 0F9DA4 002D53F4 46061083 */  div.s $f2, $f2, $f6
/* 0F9DA8 002D53F8 460C1080 */  add.s $f2, $f2, $f12
/* 0F9DAC 002D53FC 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9DB0 002D5400 00000000 */  nop   
/* 0F9DB4 002D5404 C4680008 */  lwc1  $f8, 8($v1)
/* 0F9DB8 002D5408 C4600014 */  lwc1  $f0, 0x14($v1)
/* 0F9DBC 002D540C 46080001 */  sub.s $f0, $f0, $f8
/* 0F9DC0 002D5410 46060003 */  div.s $f0, $f0, $f6
/* 0F9DC4 002D5414 46040001 */  sub.s $f0, $f0, $f4
/* 0F9DC8 002D5418 46001080 */  add.s $f2, $f2, $f0
/* 0F9DCC 002D541C 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9DD0 002D5420 00000000 */  nop   
/* 0F9DD4 002D5424 46081080 */  add.s $f2, $f2, $f8
/* 0F9DD8 002D5428 03E00008 */  jr    $ra
/* 0F9DDC 002D542C E4A20008 */   swc1  $f2, 8($a1)

/* 0F9DE0 002D5430 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F9DE4 002D5434 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9DE8 002D5438 0080902D */  daddu $s2, $a0, $zero
/* 0F9DEC 002D543C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F9DF0 002D5440 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F9DF4 002D5444 AFB40020 */  sw    $s4, 0x20($sp)
/* 0F9DF8 002D5448 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F9DFC 002D544C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9E00 002D5450 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9E04 002D5454 8E50000C */  lw    $s0, 0xc($s2)
/* 0F9E08 002D5458 8E050000 */  lw    $a1, ($s0)
/* 0F9E0C 002D545C 0C0B1EAF */  jal   func_002C7ABC
/* 0F9E10 002D5460 26100004 */   addiu $s0, $s0, 4
/* 0F9E14 002D5464 8E050000 */  lw    $a1, ($s0)
/* 0F9E18 002D5468 26100004 */  addiu $s0, $s0, 4
/* 0F9E1C 002D546C 0240202D */  daddu $a0, $s2, $zero
/* 0F9E20 002D5470 0C0B1EAF */  jal   func_002C7ABC
/* 0F9E24 002D5474 0040982D */   daddu $s3, $v0, $zero
/* 0F9E28 002D5478 8E050000 */  lw    $a1, ($s0)
/* 0F9E2C 002D547C 26100004 */  addiu $s0, $s0, 4
/* 0F9E30 002D5480 0240202D */  daddu $a0, $s2, $zero
/* 0F9E34 002D5484 0C0B1EAF */  jal   func_002C7ABC
/* 0F9E38 002D5488 0040A02D */   daddu $s4, $v0, $zero
/* 0F9E3C 002D548C 0240202D */  daddu $a0, $s2, $zero
/* 0F9E40 002D5490 8E050000 */  lw    $a1, ($s0)
/* 0F9E44 002D5494 0C0B1EAF */  jal   func_002C7ABC
/* 0F9E48 002D5498 0040882D */   daddu $s1, $v0, $zero
/* 0F9E4C 002D549C 2404001C */  addiu $a0, $zero, 0x1c
/* 0F9E50 002D54A0 0C00AB39 */  jal   func_0002ACE4
/* 0F9E54 002D54A4 0040A82D */   daddu $s5, $v0, $zero
/* 0F9E58 002D54A8 00112080 */  sll   $a0, $s1, 2
/* 0F9E5C 002D54AC 0040802D */  daddu $s0, $v0, $zero
/* 0F9E60 002D54B0 AE5000C0 */  sw    $s0, 0xc0($s2)
/* 0F9E64 002D54B4 0C00AB39 */  jal   func_0002ACE4
/* 0F9E68 002D54B8 AE110000 */   sw    $s1, ($s0)
/* 0F9E6C 002D54BC 00112040 */  sll   $a0, $s1, 1
/* 0F9E70 002D54C0 00912021 */  addu  $a0, $a0, $s1
/* 0F9E74 002D54C4 00042080 */  sll   $a0, $a0, 2
/* 0F9E78 002D54C8 AE020004 */  sw    $v0, 4($s0)
/* 0F9E7C 002D54CC 0C00AB39 */  jal   func_0002ACE4
/* 0F9E80 002D54D0 AE140008 */   sw    $s4, 8($s0)
/* 0F9E84 002D54D4 8E040000 */  lw    $a0, ($s0)
/* 0F9E88 002D54D8 8E050004 */  lw    $a1, 4($s0)
/* 0F9E8C 002D54DC 8E060008 */  lw    $a2, 8($s0)
/* 0F9E90 002D54E0 0040382D */  daddu $a3, $v0, $zero
/* 0F9E94 002D54E4 0C0B536B */  jal   func_002D4DAC
/* 0F9E98 002D54E8 AE02000C */   sw    $v0, 0xc($s0)
/* 0F9E9C 002D54EC 2673FFFF */  addiu $s3, $s3, -1
/* 0F9EA0 002D54F0 AE000010 */  sw    $zero, 0x10($s0)
/* 0F9EA4 002D54F4 AE130014 */  sw    $s3, 0x14($s0)
/* 0F9EA8 002D54F8 AE150018 */  sw    $s5, 0x18($s0)
/* 0F9EAC 002D54FC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F9EB0 002D5500 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F9EB4 002D5504 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F9EB8 002D5508 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F9EBC 002D550C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9EC0 002D5510 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9EC4 002D5514 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9EC8 002D5518 24020002 */  addiu $v0, $zero, 2
/* 0F9ECC 002D551C 03E00008 */  jr    $ra
/* 0F9ED0 002D5520 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F9ED4 002D5524 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F9ED8 002D5528 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0F9EDC 002D552C 0080882D */  daddu $s1, $a0, $zero
/* 0F9EE0 002D5530 AFBF0030 */  sw    $ra, 0x30($sp)
/* 0F9EE4 002D5534 AFB00028 */  sw    $s0, 0x28($sp)
/* 0F9EE8 002D5538 8E3000C0 */  lw    $s0, 0xc0($s1)
/* 0F9EEC 002D553C 8E030018 */  lw    $v1, 0x18($s0)
/* 0F9EF0 002D5540 24020001 */  addiu $v0, $zero, 1
/* 0F9EF4 002D5544 10620017 */  beq   $v1, $v0, .L002D55A4
/* 0F9EF8 002D5548 28620002 */   slti  $v0, $v1, 2
/* 0F9EFC 002D554C 10400005 */  beqz  $v0, .L002D5564
/* 0F9F00 002D5550 24020004 */   addiu $v0, $zero, 4
/* 0F9F04 002D5554 10600009 */  beqz  $v1, .L002D557C
/* 0F9F08 002D5558 00000000 */   nop   
/* 0F9F0C 002D555C 080B55A3 */  j     func_002D568C
/* 0F9F10 002D5560 00000000 */   nop   

.L002D5564:
/* 0F9F14 002D5564 10620022 */  beq   $v1, $v0, .L002D55F0
/* 0F9F18 002D5568 2402000A */   addiu $v0, $zero, 0xa
/* 0F9F1C 002D556C 10620032 */  beq   $v1, $v0, .L002D5638
/* 0F9F20 002D5570 00000000 */   nop   
/* 0F9F24 002D5574 080B55A3 */  j     func_002D568C
/* 0F9F28 002D5578 00000000 */   nop   

.L002D557C:
/* 0F9F2C 002D557C 3C013F80 */  lui   $at, 0x3f80
/* 0F9F30 002D5580 44810000 */  mtc1  $at, $f0
/* 0F9F34 002D5584 C6020014 */  lwc1  $f2, 0x14($s0)
/* 0F9F38 002D5588 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F3C 002D558C 46020003 */  div.s $f0, $f0, $f2
/* 0F9F40 002D5590 C6020010 */  lwc1  $f2, 0x10($s0)
/* 0F9F44 002D5594 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F48 002D5598 46020302 */  mul.s $f12, $f0, $f2
/* 0F9F4C 002D559C 080B55A4 */  j     func_002D5690
/* 0F9F50 002D55A0 00000000 */   nop   

.L002D55A4:
/* 0F9F54 002D55A4 8E020014 */  lw    $v0, 0x14($s0)
/* 0F9F58 002D55A8 00420018 */  mult  $v0, $v0
/* 0F9F5C 002D55AC 00001812 */  mflo  $v1
/* 0F9F60 002D55B0 8E020010 */  lw    $v0, 0x10($s0)
/* 0F9F64 002D55B4 00000000 */  nop   
/* 0F9F68 002D55B8 00420018 */  mult  $v0, $v0
/* 0F9F6C 002D55BC 3C013F80 */  lui   $at, 0x3f80
/* 0F9F70 002D55C0 44810000 */  mtc1  $at, $f0
/* 0F9F74 002D55C4 44831000 */  mtc1  $v1, $f2
/* 0F9F78 002D55C8 00000000 */  nop   
/* 0F9F7C 002D55CC 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F80 002D55D0 00001012 */  mflo  $v0
/* 0F9F84 002D55D4 46020003 */  div.s $f0, $f0, $f2
/* 0F9F88 002D55D8 44821000 */  mtc1  $v0, $f2
/* 0F9F8C 002D55DC 00000000 */  nop   
/* 0F9F90 002D55E0 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F94 002D55E4 46020302 */  mul.s $f12, $f0, $f2
/* 0F9F98 002D55E8 080B55A4 */  j     func_002D5690
/* 0F9F9C 002D55EC 00000000 */   nop   

.L002D55F0:
/* 0F9FA0 002D55F0 8E020014 */  lw    $v0, 0x14($s0)
/* 0F9FA4 002D55F4 00420018 */  mult  $v0, $v0
/* 0F9FA8 002D55F8 8E030010 */  lw    $v1, 0x10($s0)
/* 0F9FAC 002D55FC 00431023 */  subu  $v0, $v0, $v1
/* 0F9FB0 002D5600 44820000 */  mtc1  $v0, $f0
/* 0F9FB4 002D5604 00000000 */  nop   
/* 0F9FB8 002D5608 46800020 */  cvt.s.w $f0, $f0
/* 0F9FBC 002D560C 46000002 */  mul.s $f0, $f0, $f0
/* 0F9FC0 002D5610 00000000 */  nop   
/* 0F9FC4 002D5614 3C013F80 */  lui   $at, 0x3f80
/* 0F9FC8 002D5618 44812000 */  mtc1  $at, $f4
/* 0F9FCC 002D561C 00004012 */  mflo  $t0
/* 0F9FD0 002D5620 44881000 */  mtc1  $t0, $f2
/* 0F9FD4 002D5624 00000000 */  nop   
/* 0F9FD8 002D5628 468010A0 */  cvt.s.w $f2, $f2
/* 0F9FDC 002D562C 46020003 */  div.s $f0, $f0, $f2
/* 0F9FE0 002D5630 080B55A4 */  j     func_002D5690
/* 0F9FE4 002D5634 46002301 */   sub.s $f12, $f4, $f0

.L002D5638:
/* 0F9FE8 002D5638 3C014049 */  lui   $at, 0x4049
/* 0F9FEC 002D563C 34210FD8 */  ori   $at, $at, 0xfd8
/* 0F9FF0 002D5640 44816000 */  mtc1  $at, $f12
/* 0F9FF4 002D5644 C6000014 */  lwc1  $f0, 0x14($s0)
/* 0F9FF8 002D5648 46800020 */  cvt.s.w $f0, $f0
/* 0F9FFC 002D564C 46006303 */  div.s $f12, $f12, $f0
/* 0FA000 002D5650 C6000010 */  lwc1  $f0, 0x10($s0)
/* 0FA004 002D5654 46800020 */  cvt.s.w $f0, $f0
/* 0FA008 002D5658 46006302 */  mul.s $f12, $f12, $f0
/* 0FA00C 002D565C 0C00A874 */  jal   func_0002A1D0
/* 0FA010 002D5660 00000000 */   nop   
/* 0FA014 002D5664 3C013F80 */  lui   $at, 0x3f80
/* 0FA018 002D5668 44811000 */  mtc1  $at, $f2
/* 0FA01C 002D566C 00000000 */  nop   
/* 0FA020 002D5670 46001081 */  sub.s $f2, $f2, $f0
/* 0FA024 002D5674 3C013F00 */  lui   $at, 0x3f00
/* 0FA028 002D5678 44810000 */  mtc1  $at, $f0
/* 0FA02C 002D567C 00000000 */  nop   
/* 0FA030 002D5680 46001302 */  mul.s $f12, $f2, $f0
/* 0FA034 002D5684 080B55A4 */  j     func_002D5690
/* 0FA038 002D5688 00000000 */   nop   

func_002D568C:
/* 0FA03C 002D568C 44806000 */  mtc1  $zero, $f12
func_002D5690:
/* 0FA040 002D5690 8E020008 */  lw    $v0, 8($s0)
/* 0FA044 002D5694 AFA20010 */  sw    $v0, 0x10($sp)
/* 0FA048 002D5698 8E02000C */  lw    $v0, 0xc($s0)
/* 0FA04C 002D569C AFA20014 */  sw    $v0, 0x14($sp)
/* 0FA050 002D56A0 8E060000 */  lw    $a2, ($s0)
/* 0FA054 002D56A4 8E070004 */  lw    $a3, 4($s0)
/* 0FA058 002D56A8 0C0B549C */  jal   func_002D5270
/* 0FA05C 002D56AC 27A50018 */   addiu $a1, $sp, 0x18
/* 0FA060 002D56B0 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 0FA064 002D56B4 3C014480 */  lui   $at, 0x4480
/* 0FA068 002D56B8 44812000 */  mtc1  $at, $f4
/* 0FA06C 002D56BC 00000000 */  nop   
/* 0FA070 002D56C0 46040002 */  mul.s $f0, $f0, $f4
/* 0FA074 002D56C4 00000000 */  nop   
/* 0FA078 002D56C8 3C01CD5B */  lui   $at, 0xcd5b
/* 0FA07C 002D56CC 34215858 */  ori   $at, $at, 0x5858
/* 0FA080 002D56D0 44811000 */  mtc1  $at, $f2
/* 0FA084 002D56D4 00000000 */  nop   
/* 0FA088 002D56D8 46020000 */  add.s $f0, $f0, $f2
/* 0FA08C 002D56DC 4600018D */  trunc.w.s $f6, $f0
/* 0FA090 002D56E0 E6260088 */  swc1  $f6, 0x88($s1)
/* 0FA094 002D56E4 C7A0001C */  lwc1  $f0, 0x1c($sp)
/* 0FA098 002D56E8 46040002 */  mul.s $f0, $f0, $f4
/* 0FA09C 002D56EC 00000000 */  nop   
/* 0FA0A0 002D56F0 46020000 */  add.s $f0, $f0, $f2
/* 0FA0A4 002D56F4 4600018D */  trunc.w.s $f6, $f0
/* 0FA0A8 002D56F8 E626008C */  swc1  $f6, 0x8c($s1)
/* 0FA0AC 002D56FC C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0FA0B0 002D5700 46040002 */  mul.s $f0, $f0, $f4
/* 0FA0B4 002D5704 00000000 */  nop   
/* 0FA0B8 002D5708 46020000 */  add.s $f0, $f0, $f2
/* 0FA0BC 002D570C 4600018D */  trunc.w.s $f6, $f0
/* 0FA0C0 002D5710 E6260090 */  swc1  $f6, 0x90($s1)
/* 0FA0C4 002D5714 8E030010 */  lw    $v1, 0x10($s0)
/* 0FA0C8 002D5718 8E020014 */  lw    $v0, 0x14($s0)
/* 0FA0CC 002D571C 0062102A */  slt   $v0, $v1, $v0
/* 0FA0D0 002D5720 10400005 */  beqz  $v0, .L002D5738
/* 0FA0D4 002D5724 24620001 */   addiu $v0, $v1, 1
/* 0FA0D8 002D5728 AE020010 */  sw    $v0, 0x10($s0)
/* 0FA0DC 002D572C 24020001 */  addiu $v0, $zero, 1
/* 0FA0E0 002D5730 080B55D6 */  j     func_002D5758
/* 0FA0E4 002D5734 AE220084 */   sw    $v0, 0x84($s1)

.L002D5738:
/* 0FA0E8 002D5738 8E040004 */  lw    $a0, 4($s0)
/* 0FA0EC 002D573C 0C00AB4B */  jal   func_0002AD2C
/* 0FA0F0 002D5740 00000000 */   nop   
/* 0FA0F4 002D5744 0C00AB4B */  jal   func_0002AD2C
/* 0FA0F8 002D5748 8E04000C */   lw    $a0, 0xc($s0)
/* 0FA0FC 002D574C 0C00AB4B */  jal   func_0002AD2C
/* 0FA100 002D5750 8E2400C0 */   lw    $a0, 0xc0($s1)
/* 0FA104 002D5754 AE200084 */  sw    $zero, 0x84($s1)
func_002D5758:
/* 0FA108 002D5758 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0FA10C 002D575C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0FA110 002D5760 8FB00028 */  lw    $s0, 0x28($sp)
/* 0FA114 002D5764 24020002 */  addiu $v0, $zero, 2
/* 0FA118 002D5768 03E00008 */  jr    $ra
/* 0FA11C 002D576C 27BD0038 */   addiu $sp, $sp, 0x38

/* 0FA120 002D5770 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FA124 002D5774 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA128 002D5778 0080882D */  daddu $s1, $a0, $zero
/* 0FA12C 002D577C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FA130 002D5780 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FA134 002D5784 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA138 002D5788 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0FA13C 002D578C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0FA140 002D5790 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0FA144 002D5794 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA148 002D5798 8E120000 */  lw    $s2, ($s0)
/* 0FA14C 002D579C 26100004 */  addiu $s0, $s0, 4
/* 0FA150 002D57A0 8E050000 */  lw    $a1, ($s0)
/* 0FA154 002D57A4 0C0B210B */  jal   func_002C842C
/* 0FA158 002D57A8 26100004 */   addiu $s0, $s0, 4
/* 0FA15C 002D57AC 8E050000 */  lw    $a1, ($s0)
/* 0FA160 002D57B0 26100004 */  addiu $s0, $s0, 4
/* 0FA164 002D57B4 0220202D */  daddu $a0, $s1, $zero
/* 0FA168 002D57B8 0C0B210B */  jal   func_002C842C
/* 0FA16C 002D57BC 46000606 */   mov.s $f24, $f0
/* 0FA170 002D57C0 8E050000 */  lw    $a1, ($s0)
/* 0FA174 002D57C4 26100004 */  addiu $s0, $s0, 4
/* 0FA178 002D57C8 0220202D */  daddu $a0, $s1, $zero
/* 0FA17C 002D57CC 0C0B210B */  jal   func_002C842C
/* 0FA180 002D57D0 46000586 */   mov.s $f22, $f0
/* 0FA184 002D57D4 0220202D */  daddu $a0, $s1, $zero
/* 0FA188 002D57D8 8E050000 */  lw    $a1, ($s0)
/* 0FA18C 002D57DC 0C0B210B */  jal   func_002C842C
/* 0FA190 002D57E0 46000506 */   mov.s $f20, $f0
/* 0FA194 002D57E4 4600C306 */  mov.s $f12, $f24
/* 0FA198 002D57E8 4406A000 */  mfc1  $a2, $f20
/* 0FA19C 002D57EC 44070000 */  mfc1  $a3, $f0
/* 0FA1A0 002D57F0 0C00A7B5 */  jal   func_00029ED4
/* 0FA1A4 002D57F4 4600B386 */   mov.s $f14, $f22
/* 0FA1A8 002D57F8 0220202D */  daddu $a0, $s1, $zero
/* 0FA1AC 002D57FC 44060000 */  mfc1  $a2, $f0
/* 0FA1B0 002D5800 0C0B2190 */  jal   func_002C8640
/* 0FA1B4 002D5804 0240282D */   daddu $a1, $s2, $zero
/* 0FA1B8 002D5808 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FA1BC 002D580C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FA1C0 002D5810 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA1C4 002D5814 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA1C8 002D5818 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0FA1CC 002D581C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0FA1D0 002D5820 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0FA1D4 002D5824 24020002 */  addiu $v0, $zero, 2
/* 0FA1D8 002D5828 03E00008 */  jr    $ra
/* 0FA1DC 002D582C 27BD0038 */   addiu $sp, $sp, 0x38

/* 0FA1E0 002D5830 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA1E4 002D5834 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA1E8 002D5838 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA1EC 002D583C 0C0B1EAF */  jal   func_002C7ABC
/* 0FA1F0 002D5840 8C450000 */   lw    $a1, ($v0)
/* 0FA1F4 002D5844 0C009C22 */  jal   func_00027088
/* 0FA1F8 002D5848 0040202D */   daddu $a0, $v0, $zero
/* 0FA1FC 002D584C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA200 002D5850 24020002 */  addiu $v0, $zero, 2
/* 0FA204 002D5854 03E00008 */  jr    $ra
/* 0FA208 002D5858 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA20C 002D585C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA210 002D5860 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA214 002D5864 0080882D */  daddu $s1, $a0, $zero
/* 0FA218 002D5868 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA21C 002D586C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA220 002D5870 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA224 002D5874 8E050000 */  lw    $a1, ($s0)
/* 0FA228 002D5878 0C0B1EAF */  jal   func_002C7ABC
/* 0FA22C 002D587C 26100004 */   addiu $s0, $s0, 4
/* 0FA230 002D5880 0220202D */  daddu $a0, $s1, $zero
/* 0FA234 002D5884 8E050000 */  lw    $a1, ($s0)
/* 0FA238 002D5888 0C0B1EAF */  jal   func_002C7ABC
/* 0FA23C 002D588C 0040802D */   daddu $s0, $v0, $zero
/* 0FA240 002D5890 12000007 */  beqz  $s0, .L002D58B0
/* 0FA244 002D5894 0040202D */   daddu $a0, $v0, $zero
/* 0FA248 002D5898 3C03800A */  lui   $v1, 0x800a
/* 0FA24C 002D589C 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0FA250 002D58A0 8C620000 */  lw    $v0, ($v1)
/* 0FA254 002D58A4 00441025 */  or    $v0, $v0, $a0
/* 0FA258 002D58A8 080B5632 */  j     func_002D58C8
/* 0FA25C 002D58AC AC620000 */   sw    $v0, ($v1)

.L002D58B0:
/* 0FA260 002D58B0 3C02800A */  lui   $v0, 0x800a
/* 0FA264 002D58B4 2442A650 */  addiu $v0, $v0, -0x59b0
/* 0FA268 002D58B8 8C430000 */  lw    $v1, ($v0)
/* 0FA26C 002D58BC 00042027 */  nor   $a0, $zero, $a0
/* 0FA270 002D58C0 00641824 */  and   $v1, $v1, $a0
/* 0FA274 002D58C4 AC430000 */  sw    $v1, ($v0)
func_002D58C8:
/* 0FA278 002D58C8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA27C 002D58CC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA280 002D58D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA284 002D58D4 24020002 */  addiu $v0, $zero, 2
/* 0FA288 002D58D8 03E00008 */  jr    $ra
/* 0FA28C 002D58DC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA290 002D58E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA294 002D58E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA298 002D58E8 0080882D */  daddu $s1, $a0, $zero
/* 0FA29C 002D58EC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA2A0 002D58F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA2A4 002D58F4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA2A8 002D58F8 8E050000 */  lw    $a1, ($s0)
/* 0FA2AC 002D58FC 0C0B1EAF */  jal   func_002C7ABC
/* 0FA2B0 002D5900 26100004 */   addiu $s0, $s0, 4
/* 0FA2B4 002D5904 0220202D */  daddu $a0, $s1, $zero
/* 0FA2B8 002D5908 8E050000 */  lw    $a1, ($s0)
/* 0FA2BC 002D590C 0C0B1EAF */  jal   func_002C7ABC
/* 0FA2C0 002D5910 0040802D */   daddu $s0, $v0, $zero
/* 0FA2C4 002D5914 0220202D */  daddu $a0, $s1, $zero
/* 0FA2C8 002D5918 0200282D */  daddu $a1, $s0, $zero
/* 0FA2CC 002D591C 0C0B2026 */  jal   func_002C8098
/* 0FA2D0 002D5920 0040302D */   daddu $a2, $v0, $zero
/* 0FA2D4 002D5924 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA2D8 002D5928 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA2DC 002D592C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA2E0 002D5930 24020002 */  addiu $v0, $zero, 2
/* 0FA2E4 002D5934 03E00008 */  jr    $ra
/* 0FA2E8 002D5938 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA2EC 002D593C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA2F0 002D5940 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA2F4 002D5944 0080882D */  daddu $s1, $a0, $zero
/* 0FA2F8 002D5948 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA2FC 002D594C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA300 002D5950 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA304 002D5954 8E050000 */  lw    $a1, ($s0)
/* 0FA308 002D5958 0C0B1EAF */  jal   func_002C7ABC
/* 0FA30C 002D595C 26100004 */   addiu $s0, $s0, 4
/* 0FA310 002D5960 0220202D */  daddu $a0, $s1, $zero
/* 0FA314 002D5964 8E100000 */  lw    $s0, ($s0)
/* 0FA318 002D5968 0C0B1EAF */  jal   func_002C7ABC
/* 0FA31C 002D596C 0040282D */   daddu $a1, $v0, $zero
/* 0FA320 002D5970 0220202D */  daddu $a0, $s1, $zero
/* 0FA324 002D5974 0040302D */  daddu $a2, $v0, $zero
/* 0FA328 002D5978 0C0B2026 */  jal   func_002C8098
/* 0FA32C 002D597C 0200282D */   daddu $a1, $s0, $zero
/* 0FA330 002D5980 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA334 002D5984 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA338 002D5988 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA33C 002D598C 24020002 */  addiu $v0, $zero, 2
/* 0FA340 002D5990 03E00008 */  jr    $ra
/* 0FA344 002D5994 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA348 002D5998 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA34C 002D599C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA350 002D59A0 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA354 002D59A4 0C0B1EAF */  jal   func_002C7ABC
/* 0FA358 002D59A8 8C450000 */   lw    $a1, ($v0)
/* 0FA35C 002D59AC 10400005 */  beqz  $v0, .L002D59C4
/* 0FA360 002D59B0 00000000 */   nop   
/* 0FA364 002D59B4 0C03A6CC */  jal   func_000E9B30
/* 0FA368 002D59B8 00000000 */   nop   
/* 0FA36C 002D59BC 080B5673 */  j     func_002D59CC
/* 0FA370 002D59C0 00000000 */   nop   

.L002D59C4:
/* 0FA374 002D59C4 0C03A6D5 */  jal   func_000E9B54
/* 0FA378 002D59C8 00000000 */   nop   
func_002D59CC:
/* 0FA37C 002D59CC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA380 002D59D0 24020002 */  addiu $v0, $zero, 2
/* 0FA384 002D59D4 03E00008 */  jr    $ra
/* 0FA388 002D59D8 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA38C 002D59DC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA390 002D59E0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA394 002D59E4 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA398 002D59E8 0C0B1EAF */  jal   func_002C7ABC
/* 0FA39C 002D59EC 8C450000 */   lw    $a1, ($v0)
/* 0FA3A0 002D59F0 10400007 */  beqz  $v0, .L002D5A10
/* 0FA3A4 002D59F4 00000000 */   nop   
/* 0FA3A8 002D59F8 0C03A625 */  jal   func_000E9894
/* 0FA3AC 002D59FC 00000000 */   nop   
/* 0FA3B0 002D5A00 0C03A5EE */  jal   func_000E97B8
/* 0FA3B4 002D5A04 00000000 */   nop   
/* 0FA3B8 002D5A08 080B5686 */  j     func_002D5A18
/* 0FA3BC 002D5A0C 00000000 */   nop   

.L002D5A10:
/* 0FA3C0 002D5A10 0C03A631 */  jal   func_000E98C4
/* 0FA3C4 002D5A14 00000000 */   nop   
func_002D5A18:
/* 0FA3C8 002D5A18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA3CC 002D5A1C 24020002 */  addiu $v0, $zero, 2
/* 0FA3D0 002D5A20 03E00008 */  jr    $ra
/* 0FA3D4 002D5A24 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA3D8 002D5A28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA3DC 002D5A2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA3E0 002D5A30 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA3E4 002D5A34 0C0B1EAF */  jal   func_002C7ABC
/* 0FA3E8 002D5A38 8C450000 */   lw    $a1, ($v0)
/* 0FA3EC 002D5A3C 00021400 */  sll   $v0, $v0, 0x10
/* 0FA3F0 002D5A40 0C00CD3C */  jal   func_000334F0
/* 0FA3F4 002D5A44 00022403 */   sra   $a0, $v0, 0x10
/* 0FA3F8 002D5A48 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA3FC 002D5A4C 24020002 */  addiu $v0, $zero, 2
/* 0FA400 002D5A50 03E00008 */  jr    $ra
/* 0FA404 002D5A54 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA408 002D5A58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA40C 002D5A5C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA410 002D5A60 0080802D */  daddu $s0, $a0, $zero
/* 0FA414 002D5A64 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA418 002D5A68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA41C 002D5A6C 8E11000C */  lw    $s1, 0xc($s0)
/* 0FA420 002D5A70 0C0B1EAF */  jal   func_002C7ABC
/* 0FA424 002D5A74 8E250000 */   lw    $a1, ($s1)
/* 0FA428 002D5A78 44826000 */  mtc1  $v0, $f12
/* 0FA42C 002D5A7C 00000000 */  nop   
/* 0FA430 002D5A80 0C00A6C9 */  jal   func_00029B24
/* 0FA434 002D5A84 46806320 */   cvt.s.w $f12, $f12
/* 0FA438 002D5A88 8E250000 */  lw    $a1, ($s1)
/* 0FA43C 002D5A8C 4600008D */  trunc.w.s $f2, $f0
/* 0FA440 002D5A90 44061000 */  mfc1  $a2, $f2
/* 0FA444 002D5A94 0C0B2026 */  jal   func_002C8098
/* 0FA448 002D5A98 0200202D */   daddu $a0, $s0, $zero
/* 0FA44C 002D5A9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA450 002D5AA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA454 002D5AA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA458 002D5AA8 24020002 */  addiu $v0, $zero, 2
/* 0FA45C 002D5AAC 03E00008 */  jr    $ra
/* 0FA460 002D5AB0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA464 002D5AB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA468 002D5AB8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA46C 002D5ABC 0080802D */  daddu $s0, $a0, $zero
/* 0FA470 002D5AC0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA474 002D5AC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA478 002D5AC8 8E11000C */  lw    $s1, 0xc($s0)
/* 0FA47C 002D5ACC 0C0B210B */  jal   func_002C842C
/* 0FA480 002D5AD0 8E250000 */   lw    $a1, ($s1)
/* 0FA484 002D5AD4 0C00A6C9 */  jal   func_00029B24
/* 0FA488 002D5AD8 46000306 */   mov.s $f12, $f0
/* 0FA48C 002D5ADC 8E250000 */  lw    $a1, ($s1)
/* 0FA490 002D5AE0 44060000 */  mfc1  $a2, $f0
/* 0FA494 002D5AE4 0C0B2190 */  jal   func_002C8640
/* 0FA498 002D5AE8 0200202D */   daddu $a0, $s0, $zero
/* 0FA49C 002D5AEC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA4A0 002D5AF0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA4A4 002D5AF4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA4A8 002D5AF8 24020002 */  addiu $v0, $zero, 2
/* 0FA4AC 002D5AFC 03E00008 */  jr    $ra
/* 0FA4B0 002D5B00 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA4B4 002D5B04 00000000 */  nop   
/* 0FA4B8 002D5B08 00000000 */  nop   
/* 0FA4BC 002D5B0C 00000000 */  nop   
