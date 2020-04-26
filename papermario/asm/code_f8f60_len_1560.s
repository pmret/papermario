
.section .text802D45B0, "ax"

/* 0F8F60 802D45B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8F64 802D45B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8F68 802D45B8 0080882D */  daddu $s1, $a0, $zero
/* 0F8F6C 802D45BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8F70 802D45C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8F74 802D45C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F8F78 802D45C8 8E050000 */  lw    $a1, ($s0)
/* 0F8F7C 802D45CC 0C0B1EAF */  jal   func_802C7ABC
/* 0F8F80 802D45D0 26100004 */   addiu $s0, $s0, 4
/* 0F8F84 802D45D4 AE2200B4 */  sw    $v0, 0xb4($s1)
/* 0F8F88 802D45D8 8E050000 */  lw    $a1, ($s0)
/* 0F8F8C 802D45DC 26100004 */  addiu $s0, $s0, 4
/* 0F8F90 802D45E0 0C0B1EAF */  jal   func_802C7ABC
/* 0F8F94 802D45E4 0220202D */   daddu $a0, $s1, $zero
/* 0F8F98 802D45E8 AE2200B8 */  sw    $v0, 0xb8($s1)
/* 0F8F9C 802D45EC 8E050000 */  lw    $a1, ($s0)
/* 0F8FA0 802D45F0 26100004 */  addiu $s0, $s0, 4
/* 0F8FA4 802D45F4 0C0B1EAF */  jal   func_802C7ABC
/* 0F8FA8 802D45F8 0220202D */   daddu $a0, $s1, $zero
/* 0F8FAC 802D45FC AE2200C0 */  sw    $v0, 0xc0($s1)
/* 0F8FB0 802D4600 8E050000 */  lw    $a1, ($s0)
/* 0F8FB4 802D4604 0C0B1EAF */  jal   func_802C7ABC
/* 0F8FB8 802D4608 0220202D */   daddu $a0, $s1, $zero
/* 0F8FBC 802D460C AE2200B0 */  sw    $v0, 0xb0($s1)
/* 0F8FC0 802D4610 AE2000BC */  sw    $zero, 0xbc($s1)
/* 0F8FC4 802D4614 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F8FC8 802D4618 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8FCC 802D461C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8FD0 802D4620 24020002 */  addiu $v0, $zero, 2
/* 0F8FD4 802D4624 03E00008 */  jr    $ra
/* 0F8FD8 802D4628 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8FDC 802D462C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8FE0 802D4630 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F8FE4 802D4634 0080802D */  daddu $s0, $a0, $zero
/* 0F8FE8 802D4638 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8FEC 802D463C C60200B4 */  lwc1  $f2, 0xb4($s0)
/* 0F8FF0 802D4640 468010A0 */  cvt.s.w $f2, $f2
/* 0F8FF4 802D4644 C60000B8 */  lwc1  $f0, 0xb8($s0)
/* 0F8FF8 802D4648 46800020 */  cvt.s.w $f0, $f0
/* 0F8FFC 802D464C 8E0200C0 */  lw    $v0, 0xc0($s0)
/* 0F9000 802D4650 44051000 */  mfc1  $a1, $f2
/* 0F9004 802D4654 44060000 */  mfc1  $a2, $f0
/* 0F9008 802D4658 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F900C 802D465C 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0F9010 802D4660 0C00A8ED */  jal   func_8002A3B4
/* 0F9014 802D4664 8E0700BC */   lw    $a3, 0xbc($s0)
/* 0F9018 802D4668 8E0200BC */  lw    $v0, 0xbc($s0)
/* 0F901C 802D466C 8E0300C0 */  lw    $v1, 0xc0($s0)
/* 0F9020 802D4670 4600010D */  trunc.w.s $f4, $f0
/* 0F9024 802D4674 E6040084 */  swc1  $f4, 0x84($s0)
/* 0F9028 802D4678 0043102A */  slt   $v0, $v0, $v1
/* 0F902C 802D467C 14400003 */  bnez  $v0, .L802D468C
/* 0F9030 802D4680 24020001 */   addiu $v0, $zero, 1
/* 0F9034 802D4684 080B51A4 */  j     func_802D4690
/* 0F9038 802D4688 AE000088 */   sw    $zero, 0x88($s0)

.L802D468C:
/* 0F903C 802D468C AE020088 */  sw    $v0, 0x88($s0)
func_802D4690:
/* 0F9040 802D4690 8E0200BC */  lw    $v0, 0xbc($s0)
/* 0F9044 802D4694 24420001 */  addiu $v0, $v0, 1
/* 0F9048 802D4698 AE0200BC */  sw    $v0, 0xbc($s0)
/* 0F904C 802D469C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F9050 802D46A0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F9054 802D46A4 24020002 */  addiu $v0, $zero, 2
/* 0F9058 802D46A8 03E00008 */  jr    $ra
/* 0F905C 802D46AC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F9060 802D46B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9064 802D46B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9068 802D46B8 0080882D */  daddu $s1, $a0, $zero
/* 0F906C 802D46BC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F9070 802D46C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9074 802D46C4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F9078 802D46C8 8E050000 */  lw    $a1, ($s0)
/* 0F907C 802D46CC 0C0B1EAF */  jal   func_802C7ABC
/* 0F9080 802D46D0 26100004 */   addiu $s0, $s0, 4
/* 0F9084 802D46D4 8E100000 */  lw    $s0, ($s0)
/* 0F9088 802D46D8 0C00A67F */  jal   func_800299FC
/* 0F908C 802D46DC 0040202D */   daddu $a0, $v0, $zero
/* 0F9090 802D46E0 0220202D */  daddu $a0, $s1, $zero
/* 0F9094 802D46E4 0040302D */  daddu $a2, $v0, $zero
/* 0F9098 802D46E8 0C0B2026 */  jal   func_802C8098
/* 0F909C 802D46EC 0200282D */   daddu $a1, $s0, $zero
/* 0F90A0 802D46F0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F90A4 802D46F4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F90A8 802D46F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F90AC 802D46FC 24020002 */  addiu $v0, $zero, 2
/* 0F90B0 802D4700 03E00008 */  jr    $ra
/* 0F90B4 802D4704 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F90B8 802D4708 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F90BC 802D470C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F90C0 802D4710 0080902D */  daddu $s2, $a0, $zero
/* 0F90C4 802D4714 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F90C8 802D4718 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F90CC 802D471C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F90D0 802D4720 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F90D4 802D4724 8E50000C */  lw    $s0, 0xc($s2)
/* 0F90D8 802D4728 8E050000 */  lw    $a1, ($s0)
/* 0F90DC 802D472C 0C0B1EAF */  jal   func_802C7ABC
/* 0F90E0 802D4730 26100004 */   addiu $s0, $s0, 4
/* 0F90E4 802D4734 8E050000 */  lw    $a1, ($s0)
/* 0F90E8 802D4738 26100004 */  addiu $s0, $s0, 4
/* 0F90EC 802D473C 0240202D */  daddu $a0, $s2, $zero
/* 0F90F0 802D4740 0C0B1EAF */  jal   func_802C7ABC
/* 0F90F4 802D4744 0040882D */   daddu $s1, $v0, $zero
/* 0F90F8 802D4748 0240202D */  daddu $a0, $s2, $zero
/* 0F90FC 802D474C 0220282D */  daddu $a1, $s1, $zero
/* 0F9100 802D4750 8E130000 */  lw    $s3, ($s0)
/* 0F9104 802D4754 0C0B36B0 */  jal   func_802CDAC0
/* 0F9108 802D4758 0040882D */   daddu $s1, $v0, $zero
/* 0F910C 802D475C 0240202D */  daddu $a0, $s2, $zero
/* 0F9110 802D4760 0220282D */  daddu $a1, $s1, $zero
/* 0F9114 802D4764 0C0B36B0 */  jal   func_802CDAC0
/* 0F9118 802D4768 0040802D */   daddu $s0, $v0, $zero
/* 0F911C 802D476C 8C460038 */  lw    $a2, 0x38($v0)
/* 0F9120 802D4770 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F9124 802D4774 C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F9128 802D4778 0C00A720 */  jal   func_80029C80
/* 0F912C 802D477C 8C470040 */   lw    $a3, 0x40($v0)
/* 0F9130 802D4780 0240202D */  daddu $a0, $s2, $zero
/* 0F9134 802D4784 4600008D */  trunc.w.s $f2, $f0
/* 0F9138 802D4788 44061000 */  mfc1  $a2, $f2
/* 0F913C 802D478C 0C0B2026 */  jal   func_802C8098
/* 0F9140 802D4790 0260282D */   daddu $a1, $s3, $zero
/* 0F9144 802D4794 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F9148 802D4798 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F914C 802D479C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9150 802D47A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9154 802D47A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9158 802D47A8 24020002 */  addiu $v0, $zero, 2
/* 0F915C 802D47AC 03E00008 */  jr    $ra
/* 0F9160 802D47B0 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F9164 802D47B4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9168 802D47B8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F916C 802D47BC 0080882D */  daddu $s1, $a0, $zero
/* 0F9170 802D47C0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F9174 802D47C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9178 802D47C8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F917C 802D47CC 8E050000 */  lw    $a1, ($s0)
/* 0F9180 802D47D0 0C0B1EAF */  jal   func_802C7ABC
/* 0F9184 802D47D4 26100004 */   addiu $s0, $s0, 4
/* 0F9188 802D47D8 0220202D */  daddu $a0, $s1, $zero
/* 0F918C 802D47DC 8E100000 */  lw    $s0, ($s0)
/* 0F9190 802D47E0 0C0B36B0 */  jal   func_802CDAC0
/* 0F9194 802D47E4 0040282D */   daddu $a1, $v0, $zero
/* 0F9198 802D47E8 3C038011 */  lui   $v1, 0x8011
/* 0F919C 802D47EC 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F91A0 802D47F0 8C460038 */  lw    $a2, 0x38($v0)
/* 0F91A4 802D47F4 C46C0028 */  lwc1  $f12, 0x28($v1)
/* 0F91A8 802D47F8 C46E0030 */  lwc1  $f14, 0x30($v1)
/* 0F91AC 802D47FC 0C00A720 */  jal   func_80029C80
/* 0F91B0 802D4800 8C470040 */   lw    $a3, 0x40($v0)
/* 0F91B4 802D4804 0220202D */  daddu $a0, $s1, $zero
/* 0F91B8 802D4808 4600008D */  trunc.w.s $f2, $f0
/* 0F91BC 802D480C 44061000 */  mfc1  $a2, $f2
/* 0F91C0 802D4810 0C0B2026 */  jal   func_802C8098
/* 0F91C4 802D4814 0200282D */   daddu $a1, $s0, $zero
/* 0F91C8 802D4818 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F91CC 802D481C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F91D0 802D4820 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F91D4 802D4824 24020002 */  addiu $v0, $zero, 2
/* 0F91D8 802D4828 03E00008 */  jr    $ra
/* 0F91DC 802D482C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F91E0 802D4830 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F91E4 802D4834 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F91E8 802D4838 0080882D */  daddu $s1, $a0, $zero
/* 0F91EC 802D483C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F91F0 802D4840 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F91F4 802D4844 8E30000C */  lw    $s0, 0xc($s1)
/* 0F91F8 802D4848 8E050000 */  lw    $a1, ($s0)
/* 0F91FC 802D484C 0C0B1EAF */  jal   func_802C7ABC
/* 0F9200 802D4850 26100004 */   addiu $s0, $s0, 4
/* 0F9204 802D4854 0220202D */  daddu $a0, $s1, $zero
/* 0F9208 802D4858 8E100000 */  lw    $s0, ($s0)
/* 0F920C 802D485C 0C0B36B0 */  jal   func_802CDAC0
/* 0F9210 802D4860 0040282D */   daddu $a1, $v0, $zero
/* 0F9214 802D4864 3C038011 */  lui   $v1, 0x8011
/* 0F9218 802D4868 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F921C 802D486C 8C660028 */  lw    $a2, 0x28($v1)
/* 0F9220 802D4870 C44C0038 */  lwc1  $f12, 0x38($v0)
/* 0F9224 802D4874 C44E0040 */  lwc1  $f14, 0x40($v0)
/* 0F9228 802D4878 0C00A720 */  jal   func_80029C80
/* 0F922C 802D487C 8C670030 */   lw    $a3, 0x30($v1)
/* 0F9230 802D4880 0220202D */  daddu $a0, $s1, $zero
/* 0F9234 802D4884 4600008D */  trunc.w.s $f2, $f0
/* 0F9238 802D4888 44061000 */  mfc1  $a2, $f2
/* 0F923C 802D488C 0C0B2026 */  jal   func_802C8098
/* 0F9240 802D4890 0200282D */   daddu $a1, $s0, $zero
/* 0F9244 802D4894 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F9248 802D4898 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F924C 802D489C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9250 802D48A0 24020002 */  addiu $v0, $zero, 2
/* 0F9254 802D48A4 03E00008 */  jr    $ra
/* 0F9258 802D48A8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F925C 802D48AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9260 802D48B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9264 802D48B4 0080882D */  daddu $s1, $a0, $zero
/* 0F9268 802D48B8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F926C 802D48BC 3C128011 */  lui   $s2, 0x8011
/* 0F9270 802D48C0 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F9274 802D48C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F9278 802D48C8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F927C 802D48CC 10A0000E */  beqz  $a1, .L802D4908
/* 0F9280 802D48D0 8E30000C */   lw    $s0, 0xc($s1)
/* 0F9284 802D48D4 8E050000 */  lw    $a1, ($s0)
/* 0F9288 802D48D8 0C0B1EAF */  jal   func_802C7ABC
/* 0F928C 802D48DC 26100004 */   addiu $s0, $s0, 4
/* 0F9290 802D48E0 AE220070 */  sw    $v0, 0x70($s1)
/* 0F9294 802D48E4 8E050000 */  lw    $a1, ($s0)
/* 0F9298 802D48E8 26100004 */  addiu $s0, $s0, 4
/* 0F929C 802D48EC 0C0B1EAF */  jal   func_802C7ABC
/* 0F92A0 802D48F0 0220202D */   daddu $a0, $s1, $zero
/* 0F92A4 802D48F4 AE220074 */  sw    $v0, 0x74($s1)
/* 0F92A8 802D48F8 8E050000 */  lw    $a1, ($s0)
/* 0F92AC 802D48FC 0C0B1EAF */  jal   func_802C7ABC
/* 0F92B0 802D4900 0220202D */   daddu $a0, $s1, $zero
/* 0F92B4 802D4904 AE220078 */  sw    $v0, 0x78($s1)
.L802D4908:
/* 0F92B8 802D4908 C6240070 */  lwc1  $f4, 0x70($s1)
/* 0F92BC 802D490C 46802120 */  cvt.s.w $f4, $f4
/* 0F92C0 802D4910 44062000 */  mfc1  $a2, $f4
/* 0F92C4 802D4914 C6240074 */  lwc1  $f4, 0x74($s1)
/* 0F92C8 802D4918 46802120 */  cvt.s.w $f4, $f4
/* 0F92CC 802D491C C64C0028 */  lwc1  $f12, 0x28($s2)
/* 0F92D0 802D4920 C64E0030 */  lwc1  $f14, 0x30($s2)
/* 0F92D4 802D4924 44072000 */  mfc1  $a3, $f4
/* 0F92D8 802D4928 0C00A7B5 */  jal   func_80029ED4
/* 0F92DC 802D492C 00000000 */   nop   
/* 0F92E0 802D4930 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F92E4 802D4934 468010A0 */  cvt.s.w $f2, $f2
/* 0F92E8 802D4938 4602003C */  c.lt.s $f0, $f2
/* 0F92EC 802D493C 00000000 */  nop   
/* 0F92F0 802D4940 45010002 */  bc1t  .L802D494C
/* 0F92F4 802D4944 24020002 */   addiu $v0, $zero, 2
/* 0F92F8 802D4948 0000102D */  daddu $v0, $zero, $zero
.L802D494C:
/* 0F92FC 802D494C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F9300 802D4950 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9304 802D4954 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9308 802D4958 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F930C 802D495C 03E00008 */  jr    $ra
/* 0F9310 802D4960 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F9314 802D4964 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F9318 802D4968 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F931C 802D496C 0080882D */  daddu $s1, $a0, $zero
/* 0F9320 802D4970 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9324 802D4974 3C12FE36 */  lui   $s2, 0xfe36
/* 0F9328 802D4978 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F932C 802D497C 3C138011 */  lui   $s3, 0x8011
/* 0F9330 802D4980 2673EFC8 */  addiu $s3, $s3, -0x1038
/* 0F9334 802D4984 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F9338 802D4988 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F933C 802D498C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0F9340 802D4990 8E30000C */  lw    $s0, 0xc($s1)
/* 0F9344 802D4994 10A00010 */  beqz  $a1, .L802D49D8
/* 0F9348 802D4998 36523C80 */   ori   $s2, $s2, 0x3c80
/* 0F934C 802D499C 8E050000 */  lw    $a1, ($s0)
/* 0F9350 802D49A0 0C0B1EAF */  jal   func_802C7ABC
/* 0F9354 802D49A4 26100004 */   addiu $s0, $s0, 4
/* 0F9358 802D49A8 AE220070 */  sw    $v0, 0x70($s1)
/* 0F935C 802D49AC 8E050000 */  lw    $a1, ($s0)
/* 0F9360 802D49B0 26100004 */  addiu $s0, $s0, 4
/* 0F9364 802D49B4 0C0B1EAF */  jal   func_802C7ABC
/* 0F9368 802D49B8 0220202D */   daddu $a0, $s1, $zero
/* 0F936C 802D49BC AE220074 */  sw    $v0, 0x74($s1)
/* 0F9370 802D49C0 8E050000 */  lw    $a1, ($s0)
/* 0F9374 802D49C4 26100004 */  addiu $s0, $s0, 4
/* 0F9378 802D49C8 0C0B1EAF */  jal   func_802C7ABC
/* 0F937C 802D49CC 0220202D */   daddu $a0, $s1, $zero
/* 0F9380 802D49D0 AE220078 */  sw    $v0, 0x78($s1)
/* 0F9384 802D49D4 8E120000 */  lw    $s2, ($s0)
.L802D49D8:
/* 0F9388 802D49D8 C6220070 */  lwc1  $f2, 0x70($s1)
/* 0F938C 802D49DC 468010A0 */  cvt.s.w $f2, $f2
/* 0F9390 802D49E0 44061000 */  mfc1  $a2, $f2
/* 0F9394 802D49E4 C6220074 */  lwc1  $f2, 0x74($s1)
/* 0F9398 802D49E8 468010A0 */  cvt.s.w $f2, $f2
/* 0F939C 802D49EC C66C0028 */  lwc1  $f12, 0x28($s3)
/* 0F93A0 802D49F0 C66E0030 */  lwc1  $f14, 0x30($s3)
/* 0F93A4 802D49F4 44071000 */  mfc1  $a3, $f2
/* 0F93A8 802D49F8 0C00A7B5 */  jal   func_80029ED4
/* 0F93AC 802D49FC 00000000 */   nop   
/* 0F93B0 802D4A00 0220202D */  daddu $a0, $s1, $zero
/* 0F93B4 802D4A04 0240282D */  daddu $a1, $s2, $zero
/* 0F93B8 802D4A08 0000302D */  daddu $a2, $zero, $zero
/* 0F93BC 802D4A0C 0C0B2026 */  jal   func_802C8098
/* 0F93C0 802D4A10 46000506 */   mov.s $f20, $f0
/* 0F93C4 802D4A14 C6200078 */  lwc1  $f0, 0x78($s1)
/* 0F93C8 802D4A18 46800020 */  cvt.s.w $f0, $f0
/* 0F93CC 802D4A1C 4600A03C */  c.lt.s $f20, $f0
/* 0F93D0 802D4A20 00000000 */  nop   
/* 0F93D4 802D4A24 45000004 */  bc1f  .L802D4A38
/* 0F93D8 802D4A28 0220202D */   daddu $a0, $s1, $zero
/* 0F93DC 802D4A2C 0240282D */  daddu $a1, $s2, $zero
/* 0F93E0 802D4A30 0C0B2026 */  jal   func_802C8098
/* 0F93E4 802D4A34 24060001 */   addiu $a2, $zero, 1
.L802D4A38:
/* 0F93E8 802D4A38 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F93EC 802D4A3C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F93F0 802D4A40 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F93F4 802D4A44 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F93F8 802D4A48 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F93FC 802D4A4C D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0F9400 802D4A50 24020002 */  addiu $v0, $zero, 2
/* 0F9404 802D4A54 03E00008 */  jr    $ra
/* 0F9408 802D4A58 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F940C 802D4A5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9410 802D4A60 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9414 802D4A64 0080882D */  daddu $s1, $a0, $zero
/* 0F9418 802D4A68 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F941C 802D4A6C 3C128011 */  lui   $s2, 0x8011
/* 0F9420 802D4A70 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F9424 802D4A74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F9428 802D4A78 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F942C 802D4A7C 10A0000E */  beqz  $a1, .L802D4AB8
/* 0F9430 802D4A80 8E30000C */   lw    $s0, 0xc($s1)
/* 0F9434 802D4A84 8E050000 */  lw    $a1, ($s0)
/* 0F9438 802D4A88 0C0B1EAF */  jal   func_802C7ABC
/* 0F943C 802D4A8C 26100004 */   addiu $s0, $s0, 4
/* 0F9440 802D4A90 AE220070 */  sw    $v0, 0x70($s1)
/* 0F9444 802D4A94 8E050000 */  lw    $a1, ($s0)
/* 0F9448 802D4A98 26100004 */  addiu $s0, $s0, 4
/* 0F944C 802D4A9C 0C0B1EAF */  jal   func_802C7ABC
/* 0F9450 802D4AA0 0220202D */   daddu $a0, $s1, $zero
/* 0F9454 802D4AA4 AE220074 */  sw    $v0, 0x74($s1)
/* 0F9458 802D4AA8 8E050000 */  lw    $a1, ($s0)
/* 0F945C 802D4AAC 0C0B1EAF */  jal   func_802C7ABC
/* 0F9460 802D4AB0 0220202D */   daddu $a0, $s1, $zero
/* 0F9464 802D4AB4 AE220078 */  sw    $v0, 0x78($s1)
.L802D4AB8:
/* 0F9468 802D4AB8 C6240070 */  lwc1  $f4, 0x70($s1)
/* 0F946C 802D4ABC 46802120 */  cvt.s.w $f4, $f4
/* 0F9470 802D4AC0 44062000 */  mfc1  $a2, $f4
/* 0F9474 802D4AC4 C6240074 */  lwc1  $f4, 0x74($s1)
/* 0F9478 802D4AC8 46802120 */  cvt.s.w $f4, $f4
/* 0F947C 802D4ACC C64C0028 */  lwc1  $f12, 0x28($s2)
/* 0F9480 802D4AD0 C64E0030 */  lwc1  $f14, 0x30($s2)
/* 0F9484 802D4AD4 44072000 */  mfc1  $a3, $f4
/* 0F9488 802D4AD8 0C00A7B5 */  jal   func_80029ED4
/* 0F948C 802D4ADC 00000000 */   nop   
/* 0F9490 802D4AE0 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F9494 802D4AE4 468010A0 */  cvt.s.w $f2, $f2
/* 0F9498 802D4AE8 4600103C */  c.lt.s $f2, $f0
/* 0F949C 802D4AEC 00000000 */  nop   
/* 0F94A0 802D4AF0 45010002 */  bc1t  .L802D4AFC
/* 0F94A4 802D4AF4 24020002 */   addiu $v0, $zero, 2
/* 0F94A8 802D4AF8 0000102D */  daddu $v0, $zero, $zero
.L802D4AFC:
/* 0F94AC 802D4AFC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F94B0 802D4B00 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F94B4 802D4B04 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F94B8 802D4B08 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F94BC 802D4B0C 03E00008 */  jr    $ra
/* 0F94C0 802D4B10 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F94C4 802D4B14 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F94C8 802D4B18 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F94CC 802D4B1C 0080882D */  daddu $s1, $a0, $zero
/* 0F94D0 802D4B20 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F94D4 802D4B24 AFB30024 */  sw    $s3, 0x24($sp)
/* 0F94D8 802D4B28 AFB20020 */  sw    $s2, 0x20($sp)
/* 0F94DC 802D4B2C AFB00018 */  sw    $s0, 0x18($sp)
/* 0F94E0 802D4B30 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0F94E4 802D4B34 8E30000C */  lw    $s0, 0xc($s1)
/* 0F94E8 802D4B38 8E130000 */  lw    $s3, ($s0)
/* 0F94EC 802D4B3C 26100004 */  addiu $s0, $s0, 4
/* 0F94F0 802D4B40 0C0B210B */  jal   func_802C842C
/* 0F94F4 802D4B44 0260282D */   daddu $a1, $s3, $zero
/* 0F94F8 802D4B48 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0F94FC 802D4B4C 8E120000 */  lw    $s2, ($s0)
/* 0F9500 802D4B50 26100004 */  addiu $s0, $s0, 4
/* 0F9504 802D4B54 0220202D */  daddu $a0, $s1, $zero
/* 0F9508 802D4B58 0C0B210B */  jal   func_802C842C
/* 0F950C 802D4B5C 0240282D */   daddu $a1, $s2, $zero
/* 0F9510 802D4B60 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0F9514 802D4B64 8E050000 */  lw    $a1, ($s0)
/* 0F9518 802D4B68 26100004 */  addiu $s0, $s0, 4
/* 0F951C 802D4B6C 0C0B210B */  jal   func_802C842C
/* 0F9520 802D4B70 0220202D */   daddu $a0, $s1, $zero
/* 0F9524 802D4B74 0220202D */  daddu $a0, $s1, $zero
/* 0F9528 802D4B78 8E050000 */  lw    $a1, ($s0)
/* 0F952C 802D4B7C 0C0B210B */  jal   func_802C842C
/* 0F9530 802D4B80 46000506 */   mov.s $f20, $f0
/* 0F9534 802D4B84 27A40010 */  addiu $a0, $sp, 0x10
/* 0F9538 802D4B88 4406A000 */  mfc1  $a2, $f20
/* 0F953C 802D4B8C 44070000 */  mfc1  $a3, $f0
/* 0F9540 802D4B90 0C00A7E7 */  jal   func_80029F9C
/* 0F9544 802D4B94 27A50014 */   addiu $a1, $sp, 0x14
/* 0F9548 802D4B98 0220202D */  daddu $a0, $s1, $zero
/* 0F954C 802D4B9C 8FA60010 */  lw    $a2, 0x10($sp)
/* 0F9550 802D4BA0 0C0B2190 */  jal   func_802C8640
/* 0F9554 802D4BA4 0260282D */   daddu $a1, $s3, $zero
/* 0F9558 802D4BA8 0220202D */  daddu $a0, $s1, $zero
/* 0F955C 802D4BAC 8FA60014 */  lw    $a2, 0x14($sp)
/* 0F9560 802D4BB0 0C0B2190 */  jal   func_802C8640
/* 0F9564 802D4BB4 0240282D */   daddu $a1, $s2, $zero
/* 0F9568 802D4BB8 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F956C 802D4BBC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0F9570 802D4BC0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F9574 802D4BC4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F9578 802D4BC8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F957C 802D4BCC D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0F9580 802D4BD0 24020002 */  addiu $v0, $zero, 2
/* 0F9584 802D4BD4 03E00008 */  jr    $ra
/* 0F9588 802D4BD8 27BD0038 */   addiu $sp, $sp, 0x38

/* 0F958C 802D4BDC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9590 802D4BE0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9594 802D4BE4 10A00003 */  beqz  $a1, .L802D4BF4
/* 0F9598 802D4BE8 0080182D */   daddu $v1, $a0, $zero
/* 0F959C 802D4BEC AC600070 */  sw    $zero, 0x70($v1)
/* 0F95A0 802D4BF0 AC600074 */  sw    $zero, 0x74($v1)
.L802D4BF4:
/* 0F95A4 802D4BF4 8C620070 */  lw    $v0, 0x70($v1)
/* 0F95A8 802D4BF8 14400011 */  bnez  $v0, .L802D4C40
/* 0F95AC 802D4BFC 0000102D */   daddu $v0, $zero, $zero
/* 0F95B0 802D4C00 8C620074 */  lw    $v0, 0x74($v1)
/* 0F95B4 802D4C04 240400FF */  addiu $a0, $zero, 0xff
/* 0F95B8 802D4C08 14440003 */  bne   $v0, $a0, .L802D4C18
/* 0F95BC 802D4C0C 2442000A */   addiu $v0, $v0, 0xa
/* 0F95C0 802D4C10 080B5310 */  j     func_802D4C40
/* 0F95C4 802D4C14 24020002 */   addiu $v0, $zero, 2

.L802D4C18:
/* 0F95C8 802D4C18 AC620074 */  sw    $v0, 0x74($v1)
/* 0F95CC 802D4C1C 28420100 */  slti  $v0, $v0, 0x100
/* 0F95D0 802D4C20 50400001 */  beql  $v0, $zero, .L802D4C28
/* 0F95D4 802D4C24 AC640074 */   sw    $a0, 0x74($v1)
.L802D4C28:
/* 0F95D8 802D4C28 C4600074 */  lwc1  $f0, 0x74($v1)
/* 0F95DC 802D4C2C 46800020 */  cvt.s.w $f0, $f0
/* 0F95E0 802D4C30 44050000 */  mfc1  $a1, $f0
/* 0F95E4 802D4C34 0C04DF69 */  jal   func_80137DA4
/* 0F95E8 802D4C38 2404000A */   addiu $a0, $zero, 0xa
/* 0F95EC 802D4C3C 0000102D */  daddu $v0, $zero, $zero
func_802D4C40:
.L802D4C40:
/* 0F95F0 802D4C40 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F95F4 802D4C44 03E00008 */  jr    $ra
/* 0F95F8 802D4C48 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F95FC 802D4C4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9600 802D4C50 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9604 802D4C54 10A00004 */  beqz  $a1, .L802D4C68
/* 0F9608 802D4C58 0080182D */   daddu $v1, $a0, $zero
/* 0F960C 802D4C5C 240200FF */  addiu $v0, $zero, 0xff
/* 0F9610 802D4C60 AC600070 */  sw    $zero, 0x70($v1)
/* 0F9614 802D4C64 AC620074 */  sw    $v0, 0x74($v1)
.L802D4C68:
/* 0F9618 802D4C68 8C620070 */  lw    $v0, 0x70($v1)
/* 0F961C 802D4C6C 14400012 */  bnez  $v0, .L802D4CB8
/* 0F9620 802D4C70 0000102D */   daddu $v0, $zero, $zero
/* 0F9624 802D4C74 8C620074 */  lw    $v0, 0x74($v1)
/* 0F9628 802D4C78 14400006 */  bnez  $v0, .L802D4C94
/* 0F962C 802D4C7C 2442FFF6 */   addiu $v0, $v0, -0xa
/* 0F9630 802D4C80 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9634 802D4C84 0C04DF69 */  jal   func_80137DA4
/* 0F9638 802D4C88 240400FF */   addiu $a0, $zero, 0xff
/* 0F963C 802D4C8C 080B532E */  j     func_802D4CB8
/* 0F9640 802D4C90 24020002 */   addiu $v0, $zero, 2

.L802D4C94:
/* 0F9644 802D4C94 04410002 */  bgez  $v0, .L802D4CA0
/* 0F9648 802D4C98 AC620074 */   sw    $v0, 0x74($v1)
/* 0F964C 802D4C9C AC600074 */  sw    $zero, 0x74($v1)
.L802D4CA0:
/* 0F9650 802D4CA0 C4600074 */  lwc1  $f0, 0x74($v1)
/* 0F9654 802D4CA4 46800020 */  cvt.s.w $f0, $f0
/* 0F9658 802D4CA8 44050000 */  mfc1  $a1, $f0
/* 0F965C 802D4CAC 0C04DF69 */  jal   func_80137DA4
/* 0F9660 802D4CB0 2404000A */   addiu $a0, $zero, 0xa
/* 0F9664 802D4CB4 0000102D */  daddu $v0, $zero, $zero
func_802D4CB8:
.L802D4CB8:
/* 0F9668 802D4CB8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F966C 802D4CBC 03E00008 */  jr    $ra
/* 0F9670 802D4CC0 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F9674 802D4CC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F9678 802D4CC8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F967C 802D4CCC 8C82000C */  lw    $v0, 0xc($a0)
/* 0F9680 802D4CD0 0C0B1EAF */  jal   func_802C7ABC
/* 0F9684 802D4CD4 8C450000 */   lw    $a1, ($v0)
/* 0F9688 802D4CD8 04410004 */  bgez  $v0, .L802D4CEC
/* 0F968C 802D4CDC 2404000A */   addiu $a0, $zero, 0xa
/* 0F9690 802D4CE0 3C05BF80 */  lui   $a1, 0xbf80
/* 0F9694 802D4CE4 080B533F */  j     func_802D4CFC
/* 0F9698 802D4CE8 240400FF */   addiu $a0, $zero, 0xff

.L802D4CEC:
/* 0F969C 802D4CEC 44820000 */  mtc1  $v0, $f0
/* 0F96A0 802D4CF0 00000000 */  nop   
/* 0F96A4 802D4CF4 46800020 */  cvt.s.w $f0, $f0
/* 0F96A8 802D4CF8 44050000 */  mfc1  $a1, $f0
func_802D4CFC:
/* 0F96AC 802D4CFC 0C04DF69 */  jal   func_80137DA4
/* 0F96B0 802D4D00 00000000 */   nop   
/* 0F96B4 802D4D04 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F96B8 802D4D08 24020002 */  addiu $v0, $zero, 2
/* 0F96BC 802D4D0C 03E00008 */  jr    $ra
/* 0F96C0 802D4D10 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F96C4 802D4D14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F96C8 802D4D18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F96CC 802D4D1C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F96D0 802D4D20 8C82000C */  lw    $v0, 0xc($a0)
/* 0F96D4 802D4D24 0C0B210B */  jal   func_802C842C
/* 0F96D8 802D4D28 8C450000 */   lw    $a1, ($v0)
/* 0F96DC 802D4D2C 0000202D */  daddu $a0, $zero, $zero
/* 0F96E0 802D4D30 0080282D */  daddu $a1, $a0, $zero
/* 0F96E4 802D4D34 2406000C */  addiu $a2, $zero, 0xc
/* 0F96E8 802D4D38 4600008D */  trunc.w.s $f2, $f0
/* 0F96EC 802D4D3C 44101000 */  mfc1  $s0, $f2
/* 0F96F0 802D4D40 0C04DF93 */  jal   func_80137E4C
/* 0F96F4 802D4D44 24070014 */   addiu $a3, $zero, 0x14
/* 0F96F8 802D4D48 0000202D */  daddu $a0, $zero, $zero
/* 0F96FC 802D4D4C 24050001 */  addiu $a1, $zero, 1
/* 0F9700 802D4D50 24060134 */  addiu $a2, $zero, 0x134
/* 0F9704 802D4D54 0C04DF93 */  jal   func_80137E4C
/* 0F9708 802D4D58 240700DC */   addiu $a3, $zero, 0xdc
/* 0F970C 802D4D5C 44901000 */  mtc1  $s0, $f2
/* 0F9710 802D4D60 00000000 */  nop   
/* 0F9714 802D4D64 468010A0 */  cvt.s.w $f2, $f2
/* 0F9718 802D4D68 44051000 */  mfc1  $a1, $f2
/* 0F971C 802D4D6C 0C04DF62 */  jal   func_80137D88
/* 0F9720 802D4D70 2404000C */   addiu $a0, $zero, 0xc
/* 0F9724 802D4D74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F9728 802D4D78 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F972C 802D4D7C 24020002 */  addiu $v0, $zero, 2
/* 0F9730 802D4D80 03E00008 */  jr    $ra
/* 0F9734 802D4D84 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F9738 802D4D88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F973C 802D4D8C 2404000C */  addiu $a0, $zero, 0xc
/* 0F9740 802D4D90 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F9744 802D4D94 0C04DF62 */  jal   func_80137D88
/* 0F9748 802D4D98 0000282D */   daddu $a1, $zero, $zero
/* 0F974C 802D4D9C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F9750 802D4DA0 24020002 */  addiu $v0, $zero, 2
/* 0F9754 802D4DA4 03E00008 */  jr    $ra
/* 0F9758 802D4DA8 27BD0018 */   addiu $sp, $sp, 0x18

func_802D4DAC:
/* 0F975C 802D4DAC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F9760 802D4DB0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F9764 802D4DB4 0080982D */  daddu $s3, $a0, $zero
/* 0F9768 802D4DB8 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F976C 802D4DBC 00A0A82D */  daddu $s5, $a1, $zero
/* 0F9770 802D4DC0 AFBE0030 */  sw    $fp, 0x30($sp)
/* 0F9774 802D4DC4 00C0F02D */  daddu $fp, $a2, $zero
/* 0F9778 802D4DC8 AFB60028 */  sw    $s6, 0x28($sp)
/* 0F977C 802D4DCC 00E0B02D */  daddu $s6, $a3, $zero
/* 0F9780 802D4DD0 00132080 */  sll   $a0, $s3, 2
/* 0F9784 802D4DD4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0F9788 802D4DD8 AFB7002C */  sw    $s7, 0x2c($sp)
/* 0F978C 802D4DDC AFB40020 */  sw    $s4, 0x20($sp)
/* 0F9790 802D4DE0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9794 802D4DE4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9798 802D4DE8 0C00AB39 */  jal   func_8002ACE4
/* 0F979C 802D4DEC AFB00010 */   sw    $s0, 0x10($sp)
/* 0F97A0 802D4DF0 00132040 */  sll   $a0, $s3, 1
/* 0F97A4 802D4DF4 00932021 */  addu  $a0, $a0, $s3
/* 0F97A8 802D4DF8 00042080 */  sll   $a0, $a0, 2
/* 0F97AC 802D4DFC 0C00AB39 */  jal   func_8002ACE4
/* 0F97B0 802D4E00 0040B82D */   daddu $s7, $v0, $zero
/* 0F97B4 802D4E04 24110001 */  addiu $s1, $zero, 1
/* 0F97B8 802D4E08 0040A02D */  daddu $s4, $v0, $zero
/* 0F97BC 802D4E0C 0233102A */  slt   $v0, $s1, $s3
/* 0F97C0 802D4E10 10400026 */  beqz  $v0, .L802D4EAC
/* 0F97C4 802D4E14 AEA00000 */   sw    $zero, ($s5)
/* 0F97C8 802D4E18 26B20004 */  addiu $s2, $s5, 4
/* 0F97CC 802D4E1C 27D0000C */  addiu $s0, $fp, 0xc
.L802D4E20:
/* 0F97D0 802D4E20 C6040000 */  lwc1  $f4, ($s0)
/* 0F97D4 802D4E24 C600FFF4 */  lwc1  $f0, -0xc($s0)
/* 0F97D8 802D4E28 46002101 */  sub.s $f4, $f4, $f0
/* 0F97DC 802D4E2C 46042102 */  mul.s $f4, $f4, $f4
/* 0F97E0 802D4E30 00000000 */  nop   
/* 0F97E4 802D4E34 C6060004 */  lwc1  $f6, 4($s0)
/* 0F97E8 802D4E38 C600FFF8 */  lwc1  $f0, -8($s0)
/* 0F97EC 802D4E3C 46003181 */  sub.s $f6, $f6, $f0
/* 0F97F0 802D4E40 46063182 */  mul.s $f6, $f6, $f6
/* 0F97F4 802D4E44 00000000 */  nop   
/* 0F97F8 802D4E48 C602FFFC */  lwc1  $f2, -4($s0)
/* 0F97FC 802D4E4C C6000008 */  lwc1  $f0, 8($s0)
/* 0F9800 802D4E50 46020001 */  sub.s $f0, $f0, $f2
/* 0F9804 802D4E54 46000002 */  mul.s $f0, $f0, $f0
/* 0F9808 802D4E58 00000000 */  nop   
/* 0F980C 802D4E5C 46062100 */  add.s $f4, $f4, $f6
/* 0F9810 802D4E60 46002300 */  add.s $f12, $f4, $f0
/* 0F9814 802D4E64 46006084 */  sqrt.s $f2, $f12
/* 0F9818 802D4E68 46021032 */  c.eq.s $f2, $f2
/* 0F981C 802D4E6C 00000000 */  nop   
/* 0F9820 802D4E70 45010004 */  bc1t  .L802D4E84
/* 0F9824 802D4E74 00000000 */   nop   
/* 0F9828 802D4E78 0C0187BC */  jal   sqrtf
/* 0F982C 802D4E7C 00000000 */   nop   
/* 0F9830 802D4E80 46000086 */  mov.s $f2, $f0
.L802D4E84:
/* 0F9834 802D4E84 C640FFFC */  lwc1  $f0, -4($s2)
/* 0F9838 802D4E88 2610000C */  addiu $s0, $s0, 0xc
/* 0F983C 802D4E8C 46020000 */  add.s $f0, $f0, $f2
/* 0F9840 802D4E90 26310001 */  addiu $s1, $s1, 1
/* 0F9844 802D4E94 0233102A */  slt   $v0, $s1, $s3
/* 0F9848 802D4E98 E6400000 */  swc1  $f0, ($s2)
/* 0F984C 802D4E9C 1440FFE0 */  bnez  $v0, .L802D4E20
/* 0F9850 802D4EA0 26520004 */   addiu $s2, $s2, 4
/* 0F9854 802D4EA4 24110001 */  addiu $s1, $zero, 1
/* 0F9858 802D4EA8 0233102A */  slt   $v0, $s1, $s3
.L802D4EAC:
/* 0F985C 802D4EAC 1040000B */  beqz  $v0, .L802D4EDC
/* 0F9860 802D4EB0 00131080 */   sll   $v0, $s3, 2
/* 0F9864 802D4EB4 00552021 */  addu  $a0, $v0, $s5
/* 0F9868 802D4EB8 26A30004 */  addiu $v1, $s5, 4
.L802D4EBC:
/* 0F986C 802D4EBC 26310001 */  addiu $s1, $s1, 1
/* 0F9870 802D4EC0 C4600000 */  lwc1  $f0, ($v1)
/* 0F9874 802D4EC4 C482FFFC */  lwc1  $f2, -4($a0)
/* 0F9878 802D4EC8 0233102A */  slt   $v0, $s1, $s3
/* 0F987C 802D4ECC 46020003 */  div.s $f0, $f0, $f2
/* 0F9880 802D4ED0 E4600000 */  swc1  $f0, ($v1)
/* 0F9884 802D4ED4 1440FFF9 */  bnez  $v0, .L802D4EBC
/* 0F9888 802D4ED8 24630004 */   addiu $v1, $v1, 4
.L802D4EDC:
/* 0F988C 802D4EDC 0000882D */  daddu $s1, $zero, $zero
/* 0F9890 802D4EE0 00131040 */  sll   $v0, $s3, 1
/* 0F9894 802D4EE4 00531021 */  addu  $v0, $v0, $s3
/* 0F9898 802D4EE8 00021080 */  sll   $v0, $v0, 2
/* 0F989C 802D4EEC 00561021 */  addu  $v0, $v0, $s6
/* 0F98A0 802D4EF0 2667FFFF */  addiu $a3, $s3, -1
/* 0F98A4 802D4EF4 AEC00000 */  sw    $zero, ($s6)
/* 0F98A8 802D4EF8 AEC00004 */  sw    $zero, 4($s6)
/* 0F98AC 802D4EFC AEC00008 */  sw    $zero, 8($s6)
/* 0F98B0 802D4F00 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F98B4 802D4F04 AC40FFF8 */  sw    $zero, -8($v0)
/* 0F98B8 802D4F08 18E00021 */  blez  $a3, .L802D4F90
/* 0F98BC 802D4F0C AC40FFFC */   sw    $zero, -4($v0)
/* 0F98C0 802D4F10 02E0202D */  daddu $a0, $s7, $zero
/* 0F98C4 802D4F14 03C0302D */  daddu $a2, $fp, $zero
/* 0F98C8 802D4F18 0280182D */  daddu $v1, $s4, $zero
/* 0F98CC 802D4F1C 02A0282D */  daddu $a1, $s5, $zero
.L802D4F20:
/* 0F98D0 802D4F20 C4A40004 */  lwc1  $f4, 4($a1)
/* 0F98D4 802D4F24 C4A00000 */  lwc1  $f0, ($a1)
/* 0F98D8 802D4F28 46002101 */  sub.s $f4, $f4, $f0
/* 0F98DC 802D4F2C E4840000 */  swc1  $f4, ($a0)
/* 0F98E0 802D4F30 C4C0000C */  lwc1  $f0, 0xc($a2)
/* 0F98E4 802D4F34 C4C20000 */  lwc1  $f2, ($a2)
/* 0F98E8 802D4F38 46020001 */  sub.s $f0, $f0, $f2
/* 0F98EC 802D4F3C 24A50004 */  addiu $a1, $a1, 4
/* 0F98F0 802D4F40 46040003 */  div.s $f0, $f0, $f4
/* 0F98F4 802D4F44 E460000C */  swc1  $f0, 0xc($v1)
/* 0F98F8 802D4F48 C4C20010 */  lwc1  $f2, 0x10($a2)
/* 0F98FC 802D4F4C C4C00004 */  lwc1  $f0, 4($a2)
/* 0F9900 802D4F50 26310001 */  addiu $s1, $s1, 1
/* 0F9904 802D4F54 46001081 */  sub.s $f2, $f2, $f0
/* 0F9908 802D4F58 C4800000 */  lwc1  $f0, ($a0)
/* 0F990C 802D4F5C 0227102A */  slt   $v0, $s1, $a3
/* 0F9910 802D4F60 46001083 */  div.s $f2, $f2, $f0
/* 0F9914 802D4F64 E4620010 */  swc1  $f2, 0x10($v1)
/* 0F9918 802D4F68 C4C00014 */  lwc1  $f0, 0x14($a2)
/* 0F991C 802D4F6C C4C20008 */  lwc1  $f2, 8($a2)
/* 0F9920 802D4F70 24C6000C */  addiu $a2, $a2, 0xc
/* 0F9924 802D4F74 46020001 */  sub.s $f0, $f0, $f2
/* 0F9928 802D4F78 C4820000 */  lwc1  $f2, ($a0)
/* 0F992C 802D4F7C 24840004 */  addiu $a0, $a0, 4
/* 0F9930 802D4F80 46020003 */  div.s $f0, $f0, $f2
/* 0F9934 802D4F84 E4600014 */  swc1  $f0, 0x14($v1)
/* 0F9938 802D4F88 1440FFE5 */  bnez  $v0, .L802D4F20
/* 0F993C 802D4F8C 2463000C */   addiu $v1, $v1, 0xc
.L802D4F90:
/* 0F9940 802D4F90 C6800018 */  lwc1  $f0, 0x18($s4)
/* 0F9944 802D4F94 C682000C */  lwc1  $f2, 0xc($s4)
/* 0F9948 802D4F98 46020001 */  sub.s $f0, $f0, $f2
/* 0F994C 802D4F9C E6C0000C */  swc1  $f0, 0xc($s6)
/* 0F9950 802D4FA0 C680001C */  lwc1  $f0, 0x1c($s4)
/* 0F9954 802D4FA4 C6820010 */  lwc1  $f2, 0x10($s4)
/* 0F9958 802D4FA8 46020001 */  sub.s $f0, $f0, $f2
/* 0F995C 802D4FAC E6C00010 */  swc1  $f0, 0x10($s6)
/* 0F9960 802D4FB0 C6800020 */  lwc1  $f0, 0x20($s4)
/* 0F9964 802D4FB4 C6820014 */  lwc1  $f2, 0x14($s4)
/* 0F9968 802D4FB8 46020001 */  sub.s $f0, $f0, $f2
/* 0F996C 802D4FBC E6C00014 */  swc1  $f0, 0x14($s6)
/* 0F9970 802D4FC0 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F9974 802D4FC4 C6A20000 */  lwc1  $f2, ($s5)
/* 0F9978 802D4FC8 46020001 */  sub.s $f0, $f0, $f2
/* 0F997C 802D4FCC 46000000 */  add.s $f0, $f0, $f0
/* 0F9980 802D4FD0 E680000C */  swc1  $f0, 0xc($s4)
/* 0F9984 802D4FD4 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F9988 802D4FD8 C6A20000 */  lwc1  $f2, ($s5)
/* 0F998C 802D4FDC 46020001 */  sub.s $f0, $f0, $f2
/* 0F9990 802D4FE0 46000000 */  add.s $f0, $f0, $f0
/* 0F9994 802D4FE4 E6800010 */  swc1  $f0, 0x10($s4)
/* 0F9998 802D4FE8 C6A00008 */  lwc1  $f0, 8($s5)
/* 0F999C 802D4FEC C6A20000 */  lwc1  $f2, ($s5)
/* 0F99A0 802D4FF0 46020001 */  sub.s $f0, $f0, $f2
/* 0F99A4 802D4FF4 24110001 */  addiu $s1, $zero, 1
/* 0F99A8 802D4FF8 46000000 */  add.s $f0, $f0, $f0
/* 0F99AC 802D4FFC 2667FFFE */  addiu $a3, $s3, -2
/* 0F99B0 802D5000 0227102A */  slt   $v0, $s1, $a3
/* 0F99B4 802D5004 10400046 */  beqz  $v0, .L802D5120
/* 0F99B8 802D5008 E6800014 */   swc1  $f0, 0x14($s4)
/* 0F99BC 802D500C 26E60004 */  addiu $a2, $s7, 4
/* 0F99C0 802D5010 26A50004 */  addiu $a1, $s5, 4
/* 0F99C4 802D5014 26C4000C */  addiu $a0, $s6, 0xc
/* 0F99C8 802D5018 2683000C */  addiu $v1, $s4, 0xc
.L802D501C:
/* 0F99CC 802D501C C4CC0000 */  lwc1  $f12, ($a2)
/* 0F99D0 802D5020 C4660000 */  lwc1  $f6, ($v1)
/* 0F99D4 802D5024 C4840000 */  lwc1  $f4, ($a0)
/* 0F99D8 802D5028 46066183 */  div.s $f6, $f12, $f6
/* 0F99DC 802D502C 46062102 */  mul.s $f4, $f4, $f6
/* 0F99E0 802D5030 00000000 */  nop   
/* 0F99E4 802D5034 C4600018 */  lwc1  $f0, 0x18($v1)
/* 0F99E8 802D5038 C462000C */  lwc1  $f2, 0xc($v1)
/* 0F99EC 802D503C 46020001 */  sub.s $f0, $f0, $f2
/* 0F99F0 802D5040 C4680004 */  lwc1  $f8, 4($v1)
/* 0F99F4 802D5044 C46A0008 */  lwc1  $f10, 8($v1)
/* 0F99F8 802D5048 46040001 */  sub.s $f0, $f0, $f4
/* 0F99FC 802D504C C4840004 */  lwc1  $f4, 4($a0)
/* 0F9A00 802D5050 46086203 */  div.s $f8, $f12, $f8
/* 0F9A04 802D5054 46082102 */  mul.s $f4, $f4, $f8
/* 0F9A08 802D5058 00000000 */  nop   
/* 0F9A0C 802D505C E480000C */  swc1  $f0, 0xc($a0)
/* 0F9A10 802D5060 C462001C */  lwc1  $f2, 0x1c($v1)
/* 0F9A14 802D5064 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0F9A18 802D5068 46001081 */  sub.s $f2, $f2, $f0
/* 0F9A1C 802D506C 46041081 */  sub.s $f2, $f2, $f4
/* 0F9A20 802D5070 C4840008 */  lwc1  $f4, 8($a0)
/* 0F9A24 802D5074 460A6303 */  div.s $f12, $f12, $f10
/* 0F9A28 802D5078 460C2102 */  mul.s $f4, $f4, $f12
/* 0F9A2C 802D507C 00000000 */  nop   
/* 0F9A30 802D5080 E4820010 */  swc1  $f2, 0x10($a0)
/* 0F9A34 802D5084 C4600020 */  lwc1  $f0, 0x20($v1)
/* 0F9A38 802D5088 C4620014 */  lwc1  $f2, 0x14($v1)
/* 0F9A3C 802D508C 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A40 802D5090 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A44 802D5094 E4800014 */  swc1  $f0, 0x14($a0)
/* 0F9A48 802D5098 C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A4C 802D509C 46062102 */  mul.s $f4, $f4, $f6
/* 0F9A50 802D50A0 00000000 */  nop   
/* 0F9A54 802D50A4 C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9A58 802D50A8 C4A20000 */  lwc1  $f2, ($a1)
/* 0F9A5C 802D50AC 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A60 802D50B0 46000000 */  add.s $f0, $f0, $f0
/* 0F9A64 802D50B4 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A68 802D50B8 E460000C */  swc1  $f0, 0xc($v1)
/* 0F9A6C 802D50BC C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A70 802D50C0 46082102 */  mul.s $f4, $f4, $f8
/* 0F9A74 802D50C4 00000000 */  nop   
/* 0F9A78 802D50C8 C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9A7C 802D50CC C4A20000 */  lwc1  $f2, ($a1)
/* 0F9A80 802D50D0 46020001 */  sub.s $f0, $f0, $f2
/* 0F9A84 802D50D4 46000000 */  add.s $f0, $f0, $f0
/* 0F9A88 802D50D8 46040001 */  sub.s $f0, $f0, $f4
/* 0F9A8C 802D50DC E4600010 */  swc1  $f0, 0x10($v1)
/* 0F9A90 802D50E0 C4C40000 */  lwc1  $f4, ($a2)
/* 0F9A94 802D50E4 460C2102 */  mul.s $f4, $f4, $f12
/* 0F9A98 802D50E8 00000000 */  nop   
/* 0F9A9C 802D50EC C4A00008 */  lwc1  $f0, 8($a1)
/* 0F9AA0 802D50F0 C4A20000 */  lwc1  $f2, ($a1)
/* 0F9AA4 802D50F4 46020001 */  sub.s $f0, $f0, $f2
/* 0F9AA8 802D50F8 26310001 */  addiu $s1, $s1, 1
/* 0F9AAC 802D50FC 46000000 */  add.s $f0, $f0, $f0
/* 0F9AB0 802D5100 0227102A */  slt   $v0, $s1, $a3
/* 0F9AB4 802D5104 2484000C */  addiu $a0, $a0, 0xc
/* 0F9AB8 802D5108 46040001 */  sub.s $f0, $f0, $f4
/* 0F9ABC 802D510C 24C60004 */  addiu $a2, $a2, 4
/* 0F9AC0 802D5110 24A50004 */  addiu $a1, $a1, 4
/* 0F9AC4 802D5114 E4600014 */  swc1  $f0, 0x14($v1)
/* 0F9AC8 802D5118 1440FFC0 */  bnez  $v0, .L802D501C
/* 0F9ACC 802D511C 2463000C */   addiu $v1, $v1, 0xc
.L802D5120:
/* 0F9AD0 802D5120 00131040 */  sll   $v0, $s3, 1
/* 0F9AD4 802D5124 00531021 */  addu  $v0, $v0, $s3
/* 0F9AD8 802D5128 00021080 */  sll   $v0, $v0, 2
/* 0F9ADC 802D512C 00561021 */  addu  $v0, $v0, $s6
/* 0F9AE0 802D5130 00131880 */  sll   $v1, $s3, 2
/* 0F9AE4 802D5134 00771821 */  addu  $v1, $v1, $s7
/* 0F9AE8 802D5138 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9AEC 802D513C C440FFF4 */  lwc1  $f0, -0xc($v0)
/* 0F9AF0 802D5140 46001082 */  mul.s $f2, $f2, $f0
/* 0F9AF4 802D5144 00000000 */  nop   
/* 0F9AF8 802D5148 C440FFE8 */  lwc1  $f0, -0x18($v0)
/* 0F9AFC 802D514C 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B00 802D5150 E440FFE8 */  swc1  $f0, -0x18($v0)
/* 0F9B04 802D5154 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9B08 802D5158 C440FFF8 */  lwc1  $f0, -8($v0)
/* 0F9B0C 802D515C 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B10 802D5160 00000000 */  nop   
/* 0F9B14 802D5164 C440FFEC */  lwc1  $f0, -0x14($v0)
/* 0F9B18 802D5168 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B1C 802D516C E440FFEC */  swc1  $f0, -0x14($v0)
/* 0F9B20 802D5170 C462FFF8 */  lwc1  $f2, -8($v1)
/* 0F9B24 802D5174 C440FFFC */  lwc1  $f0, -4($v0)
/* 0F9B28 802D5178 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B2C 802D517C 00000000 */  nop   
/* 0F9B30 802D5180 C440FFF0 */  lwc1  $f0, -0x10($v0)
/* 0F9B34 802D5184 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B38 802D5188 2671FFFE */  addiu $s1, $s3, -2
/* 0F9B3C 802D518C 1A200028 */  blez  $s1, .L802D5230
/* 0F9B40 802D5190 E440FFF0 */   swc1  $f0, -0x10($v0)
/* 0F9B44 802D5194 00111080 */  sll   $v0, $s1, 2
/* 0F9B48 802D5198 00571821 */  addu  $v1, $v0, $s7
/* 0F9B4C 802D519C 00111040 */  sll   $v0, $s1, 1
/* 0F9B50 802D51A0 00511021 */  addu  $v0, $v0, $s1
/* 0F9B54 802D51A4 00021080 */  sll   $v0, $v0, 2
/* 0F9B58 802D51A8 00563821 */  addu  $a3, $v0, $s6
/* 0F9B5C 802D51AC 00541021 */  addu  $v0, $v0, $s4
.L802D51B0:
/* 0F9B60 802D51B0 C4620000 */  lwc1  $f2, ($v1)
/* 0F9B64 802D51B4 C4E0000C */  lwc1  $f0, 0xc($a3)
/* 0F9B68 802D51B8 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B6C 802D51BC 00000000 */  nop   
/* 0F9B70 802D51C0 C4E00000 */  lwc1  $f0, ($a3)
/* 0F9B74 802D51C4 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B78 802D51C8 C4420000 */  lwc1  $f2, ($v0)
/* 0F9B7C 802D51CC 46020003 */  div.s $f0, $f0, $f2
/* 0F9B80 802D51D0 E4E00000 */  swc1  $f0, ($a3)
/* 0F9B84 802D51D4 C4620000 */  lwc1  $f2, ($v1)
/* 0F9B88 802D51D8 C4E00010 */  lwc1  $f0, 0x10($a3)
/* 0F9B8C 802D51DC 46001082 */  mul.s $f2, $f2, $f0
/* 0F9B90 802D51E0 00000000 */  nop   
/* 0F9B94 802D51E4 C4E00004 */  lwc1  $f0, 4($a3)
/* 0F9B98 802D51E8 46020001 */  sub.s $f0, $f0, $f2
/* 0F9B9C 802D51EC C4420004 */  lwc1  $f2, 4($v0)
/* 0F9BA0 802D51F0 46020003 */  div.s $f0, $f0, $f2
/* 0F9BA4 802D51F4 E4E00004 */  swc1  $f0, 4($a3)
/* 0F9BA8 802D51F8 C4620000 */  lwc1  $f2, ($v1)
/* 0F9BAC 802D51FC C4E00014 */  lwc1  $f0, 0x14($a3)
/* 0F9BB0 802D5200 46001082 */  mul.s $f2, $f2, $f0
/* 0F9BB4 802D5204 00000000 */  nop   
/* 0F9BB8 802D5208 2631FFFF */  addiu $s1, $s1, -1
/* 0F9BBC 802D520C C4E00008 */  lwc1  $f0, 8($a3)
/* 0F9BC0 802D5210 2463FFFC */  addiu $v1, $v1, -4
/* 0F9BC4 802D5214 46020001 */  sub.s $f0, $f0, $f2
/* 0F9BC8 802D5218 C4420008 */  lwc1  $f2, 8($v0)
/* 0F9BCC 802D521C 2442FFF4 */  addiu $v0, $v0, -0xc
/* 0F9BD0 802D5220 46020003 */  div.s $f0, $f0, $f2
/* 0F9BD4 802D5224 E4E00008 */  swc1  $f0, 8($a3)
/* 0F9BD8 802D5228 1E20FFE1 */  bgtz  $s1, .L802D51B0
/* 0F9BDC 802D522C 24E7FFF4 */   addiu $a3, $a3, -0xc
.L802D5230:
/* 0F9BE0 802D5230 0C00AB4B */  jal   func_8002AD2C
/* 0F9BE4 802D5234 02E0202D */   daddu $a0, $s7, $zero
/* 0F9BE8 802D5238 0C00AB4B */  jal   func_8002AD2C
/* 0F9BEC 802D523C 0280202D */   daddu $a0, $s4, $zero
/* 0F9BF0 802D5240 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0F9BF4 802D5244 8FBE0030 */  lw    $fp, 0x30($sp)
/* 0F9BF8 802D5248 8FB7002C */  lw    $s7, 0x2c($sp)
/* 0F9BFC 802D524C 8FB60028 */  lw    $s6, 0x28($sp)
/* 0F9C00 802D5250 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F9C04 802D5254 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F9C08 802D5258 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F9C0C 802D525C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9C10 802D5260 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9C14 802D5264 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9C18 802D5268 03E00008 */  jr    $ra
/* 0F9C1C 802D526C 27BD0038 */   addiu $sp, $sp, 0x38

func_802D5270:
/* 0F9C20 802D5270 24C6FFFF */  addiu $a2, $a2, -1
/* 0F9C24 802D5274 18C00010 */  blez  $a2, .L802D52B8
/* 0F9C28 802D5278 0000202D */   daddu $a0, $zero, $zero
/* 0F9C2C 802D527C 00861021 */  addu  $v0, $a0, $a2
.L802D5280:
/* 0F9C30 802D5280 00021FC2 */  srl   $v1, $v0, 0x1f
/* 0F9C34 802D5284 00431021 */  addu  $v0, $v0, $v1
/* 0F9C38 802D5288 00021843 */  sra   $v1, $v0, 1
/* 0F9C3C 802D528C 00031080 */  sll   $v0, $v1, 2
/* 0F9C40 802D5290 00471021 */  addu  $v0, $v0, $a3
/* 0F9C44 802D5294 C4400000 */  lwc1  $f0, ($v0)
/* 0F9C48 802D5298 460C003C */  c.lt.s $f0, $f12
/* 0F9C4C 802D529C 00000000 */  nop   
/* 0F9C50 802D52A0 45020002 */  bc1fl .L802D52AC
/* 0F9C54 802D52A4 0060302D */   daddu $a2, $v1, $zero
/* 0F9C58 802D52A8 24640001 */  addiu $a0, $v1, 1
.L802D52AC:
/* 0F9C5C 802D52AC 0086102A */  slt   $v0, $a0, $a2
/* 0F9C60 802D52B0 1440FFF3 */  bnez  $v0, .L802D5280
/* 0F9C64 802D52B4 00861021 */   addu  $v0, $a0, $a2
.L802D52B8:
/* 0F9C68 802D52B8 5C800001 */  bgtzl $a0, .L802D52C0
/* 0F9C6C 802D52BC 2484FFFF */   addiu $a0, $a0, -1
.L802D52C0:
/* 0F9C70 802D52C0 00041080 */  sll   $v0, $a0, 2
/* 0F9C74 802D52C4 00471021 */  addu  $v0, $v0, $a3
/* 0F9C78 802D52C8 00041840 */  sll   $v1, $a0, 1
/* 0F9C7C 802D52CC 00641821 */  addu  $v1, $v1, $a0
/* 0F9C80 802D52D0 00031880 */  sll   $v1, $v1, 2
/* 0F9C84 802D52D4 8FA40014 */  lw    $a0, 0x14($sp)
/* 0F9C88 802D52D8 C4480000 */  lwc1  $f8, ($v0)
/* 0F9C8C 802D52DC 00642021 */  addu  $a0, $v1, $a0
/* 0F9C90 802D52E0 C4840000 */  lwc1  $f4, ($a0)
/* 0F9C94 802D52E4 46086281 */  sub.s $f10, $f12, $f8
/* 0F9C98 802D52E8 3C014040 */  lui   $at, 0x4040
/* 0F9C9C 802D52EC 44816000 */  mtc1  $at, $f12
/* 0F9CA0 802D52F0 00000000 */  nop   
/* 0F9CA4 802D52F4 460C2002 */  mul.s $f0, $f4, $f12
/* 0F9CA8 802D52F8 00000000 */  nop   
/* 0F9CAC 802D52FC C48E000C */  lwc1  $f14, 0xc($a0)
/* 0F9CB0 802D5300 46047081 */  sub.s $f2, $f14, $f4
/* 0F9CB4 802D5304 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9CB8 802D5308 00000000 */  nop   
/* 0F9CBC 802D530C C4460004 */  lwc1  $f6, 4($v0)
/* 0F9CC0 802D5310 46083181 */  sub.s $f6, $f6, $f8
/* 0F9CC4 802D5314 46042100 */  add.s $f4, $f4, $f4
/* 0F9CC8 802D5318 460E2100 */  add.s $f4, $f4, $f14
/* 0F9CCC 802D531C 46062102 */  mul.s $f4, $f4, $f6
/* 0F9CD0 802D5320 00000000 */  nop   
/* 0F9CD4 802D5324 46061083 */  div.s $f2, $f2, $f6
/* 0F9CD8 802D5328 46001080 */  add.s $f2, $f2, $f0
/* 0F9CDC 802D532C 8FA20010 */  lw    $v0, 0x10($sp)
/* 0F9CE0 802D5330 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9CE4 802D5334 00000000 */  nop   
/* 0F9CE8 802D5338 00621821 */  addu  $v1, $v1, $v0
/* 0F9CEC 802D533C C4680000 */  lwc1  $f8, ($v1)
/* 0F9CF0 802D5340 C460000C */  lwc1  $f0, 0xc($v1)
/* 0F9CF4 802D5344 46080001 */  sub.s $f0, $f0, $f8
/* 0F9CF8 802D5348 46060003 */  div.s $f0, $f0, $f6
/* 0F9CFC 802D534C 46040001 */  sub.s $f0, $f0, $f4
/* 0F9D00 802D5350 46001080 */  add.s $f2, $f2, $f0
/* 0F9D04 802D5354 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D08 802D5358 00000000 */  nop   
/* 0F9D0C 802D535C 46081080 */  add.s $f2, $f2, $f8
/* 0F9D10 802D5360 E4A20000 */  swc1  $f2, ($a1)
/* 0F9D14 802D5364 C4840004 */  lwc1  $f4, 4($a0)
/* 0F9D18 802D5368 460C2002 */  mul.s $f0, $f4, $f12
/* 0F9D1C 802D536C 00000000 */  nop   
/* 0F9D20 802D5370 C4880010 */  lwc1  $f8, 0x10($a0)
/* 0F9D24 802D5374 46044081 */  sub.s $f2, $f8, $f4
/* 0F9D28 802D5378 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D2C 802D537C 00000000 */  nop   
/* 0F9D30 802D5380 46042100 */  add.s $f4, $f4, $f4
/* 0F9D34 802D5384 46082100 */  add.s $f4, $f4, $f8
/* 0F9D38 802D5388 46062102 */  mul.s $f4, $f4, $f6
/* 0F9D3C 802D538C 00000000 */  nop   
/* 0F9D40 802D5390 46061083 */  div.s $f2, $f2, $f6
/* 0F9D44 802D5394 46001080 */  add.s $f2, $f2, $f0
/* 0F9D48 802D5398 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D4C 802D539C 00000000 */  nop   
/* 0F9D50 802D53A0 C4680004 */  lwc1  $f8, 4($v1)
/* 0F9D54 802D53A4 C4600010 */  lwc1  $f0, 0x10($v1)
/* 0F9D58 802D53A8 46080001 */  sub.s $f0, $f0, $f8
/* 0F9D5C 802D53AC 46060003 */  div.s $f0, $f0, $f6
/* 0F9D60 802D53B0 46040001 */  sub.s $f0, $f0, $f4
/* 0F9D64 802D53B4 46001080 */  add.s $f2, $f2, $f0
/* 0F9D68 802D53B8 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D6C 802D53BC 00000000 */  nop   
/* 0F9D70 802D53C0 46081080 */  add.s $f2, $f2, $f8
/* 0F9D74 802D53C4 E4A20004 */  swc1  $f2, 4($a1)
/* 0F9D78 802D53C8 C4840008 */  lwc1  $f4, 8($a0)
/* 0F9D7C 802D53CC 460C2302 */  mul.s $f12, $f4, $f12
/* 0F9D80 802D53D0 00000000 */  nop   
/* 0F9D84 802D53D4 C4800014 */  lwc1  $f0, 0x14($a0)
/* 0F9D88 802D53D8 46040081 */  sub.s $f2, $f0, $f4
/* 0F9D8C 802D53DC 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9D90 802D53E0 00000000 */  nop   
/* 0F9D94 802D53E4 46042100 */  add.s $f4, $f4, $f4
/* 0F9D98 802D53E8 46002100 */  add.s $f4, $f4, $f0
/* 0F9D9C 802D53EC 46062102 */  mul.s $f4, $f4, $f6
/* 0F9DA0 802D53F0 00000000 */  nop   
/* 0F9DA4 802D53F4 46061083 */  div.s $f2, $f2, $f6
/* 0F9DA8 802D53F8 460C1080 */  add.s $f2, $f2, $f12
/* 0F9DAC 802D53FC 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9DB0 802D5400 00000000 */  nop   
/* 0F9DB4 802D5404 C4680008 */  lwc1  $f8, 8($v1)
/* 0F9DB8 802D5408 C4600014 */  lwc1  $f0, 0x14($v1)
/* 0F9DBC 802D540C 46080001 */  sub.s $f0, $f0, $f8
/* 0F9DC0 802D5410 46060003 */  div.s $f0, $f0, $f6
/* 0F9DC4 802D5414 46040001 */  sub.s $f0, $f0, $f4
/* 0F9DC8 802D5418 46001080 */  add.s $f2, $f2, $f0
/* 0F9DCC 802D541C 460A1082 */  mul.s $f2, $f2, $f10
/* 0F9DD0 802D5420 00000000 */  nop   
/* 0F9DD4 802D5424 46081080 */  add.s $f2, $f2, $f8
/* 0F9DD8 802D5428 03E00008 */  jr    $ra
/* 0F9DDC 802D542C E4A20008 */   swc1  $f2, 8($a1)

/* 0F9DE0 802D5430 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F9DE4 802D5434 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F9DE8 802D5438 0080902D */  daddu $s2, $a0, $zero
/* 0F9DEC 802D543C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F9DF0 802D5440 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F9DF4 802D5444 AFB40020 */  sw    $s4, 0x20($sp)
/* 0F9DF8 802D5448 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F9DFC 802D544C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9E00 802D5450 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F9E04 802D5454 8E50000C */  lw    $s0, 0xc($s2)
/* 0F9E08 802D5458 8E050000 */  lw    $a1, ($s0)
/* 0F9E0C 802D545C 0C0B1EAF */  jal   func_802C7ABC
/* 0F9E10 802D5460 26100004 */   addiu $s0, $s0, 4
/* 0F9E14 802D5464 8E050000 */  lw    $a1, ($s0)
/* 0F9E18 802D5468 26100004 */  addiu $s0, $s0, 4
/* 0F9E1C 802D546C 0240202D */  daddu $a0, $s2, $zero
/* 0F9E20 802D5470 0C0B1EAF */  jal   func_802C7ABC
/* 0F9E24 802D5474 0040982D */   daddu $s3, $v0, $zero
/* 0F9E28 802D5478 8E050000 */  lw    $a1, ($s0)
/* 0F9E2C 802D547C 26100004 */  addiu $s0, $s0, 4
/* 0F9E30 802D5480 0240202D */  daddu $a0, $s2, $zero
/* 0F9E34 802D5484 0C0B1EAF */  jal   func_802C7ABC
/* 0F9E38 802D5488 0040A02D */   daddu $s4, $v0, $zero
/* 0F9E3C 802D548C 0240202D */  daddu $a0, $s2, $zero
/* 0F9E40 802D5490 8E050000 */  lw    $a1, ($s0)
/* 0F9E44 802D5494 0C0B1EAF */  jal   func_802C7ABC
/* 0F9E48 802D5498 0040882D */   daddu $s1, $v0, $zero
/* 0F9E4C 802D549C 2404001C */  addiu $a0, $zero, 0x1c
/* 0F9E50 802D54A0 0C00AB39 */  jal   func_8002ACE4
/* 0F9E54 802D54A4 0040A82D */   daddu $s5, $v0, $zero
/* 0F9E58 802D54A8 00112080 */  sll   $a0, $s1, 2
/* 0F9E5C 802D54AC 0040802D */  daddu $s0, $v0, $zero
/* 0F9E60 802D54B0 AE5000C0 */  sw    $s0, 0xc0($s2)
/* 0F9E64 802D54B4 0C00AB39 */  jal   func_8002ACE4
/* 0F9E68 802D54B8 AE110000 */   sw    $s1, ($s0)
/* 0F9E6C 802D54BC 00112040 */  sll   $a0, $s1, 1
/* 0F9E70 802D54C0 00912021 */  addu  $a0, $a0, $s1
/* 0F9E74 802D54C4 00042080 */  sll   $a0, $a0, 2
/* 0F9E78 802D54C8 AE020004 */  sw    $v0, 4($s0)
/* 0F9E7C 802D54CC 0C00AB39 */  jal   func_8002ACE4
/* 0F9E80 802D54D0 AE140008 */   sw    $s4, 8($s0)
/* 0F9E84 802D54D4 8E040000 */  lw    $a0, ($s0)
/* 0F9E88 802D54D8 8E050004 */  lw    $a1, 4($s0)
/* 0F9E8C 802D54DC 8E060008 */  lw    $a2, 8($s0)
/* 0F9E90 802D54E0 0040382D */  daddu $a3, $v0, $zero
/* 0F9E94 802D54E4 0C0B536B */  jal   func_802D4DAC
/* 0F9E98 802D54E8 AE02000C */   sw    $v0, 0xc($s0)
/* 0F9E9C 802D54EC 2673FFFF */  addiu $s3, $s3, -1
/* 0F9EA0 802D54F0 AE000010 */  sw    $zero, 0x10($s0)
/* 0F9EA4 802D54F4 AE130014 */  sw    $s3, 0x14($s0)
/* 0F9EA8 802D54F8 AE150018 */  sw    $s5, 0x18($s0)
/* 0F9EAC 802D54FC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F9EB0 802D5500 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F9EB4 802D5504 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F9EB8 802D5508 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F9EBC 802D550C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9EC0 802D5510 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9EC4 802D5514 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9EC8 802D5518 24020002 */  addiu $v0, $zero, 2
/* 0F9ECC 802D551C 03E00008 */  jr    $ra
/* 0F9ED0 802D5520 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F9ED4 802D5524 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F9ED8 802D5528 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0F9EDC 802D552C 0080882D */  daddu $s1, $a0, $zero
/* 0F9EE0 802D5530 AFBF0030 */  sw    $ra, 0x30($sp)
/* 0F9EE4 802D5534 AFB00028 */  sw    $s0, 0x28($sp)
/* 0F9EE8 802D5538 8E3000C0 */  lw    $s0, 0xc0($s1)
/* 0F9EEC 802D553C 8E030018 */  lw    $v1, 0x18($s0)
/* 0F9EF0 802D5540 24020001 */  addiu $v0, $zero, 1
/* 0F9EF4 802D5544 10620017 */  beq   $v1, $v0, .L802D55A4
/* 0F9EF8 802D5548 28620002 */   slti  $v0, $v1, 2
/* 0F9EFC 802D554C 10400005 */  beqz  $v0, .L802D5564
/* 0F9F00 802D5550 24020004 */   addiu $v0, $zero, 4
/* 0F9F04 802D5554 10600009 */  beqz  $v1, .L802D557C
/* 0F9F08 802D5558 00000000 */   nop   
/* 0F9F0C 802D555C 080B55A3 */  j     func_802D568C
/* 0F9F10 802D5560 00000000 */   nop   

.L802D5564:
/* 0F9F14 802D5564 10620022 */  beq   $v1, $v0, .L802D55F0
/* 0F9F18 802D5568 2402000A */   addiu $v0, $zero, 0xa
/* 0F9F1C 802D556C 10620032 */  beq   $v1, $v0, .L802D5638
/* 0F9F20 802D5570 00000000 */   nop   
/* 0F9F24 802D5574 080B55A3 */  j     func_802D568C
/* 0F9F28 802D5578 00000000 */   nop   

.L802D557C:
/* 0F9F2C 802D557C 3C013F80 */  lui   $at, 0x3f80
/* 0F9F30 802D5580 44810000 */  mtc1  $at, $f0
/* 0F9F34 802D5584 C6020014 */  lwc1  $f2, 0x14($s0)
/* 0F9F38 802D5588 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F3C 802D558C 46020003 */  div.s $f0, $f0, $f2
/* 0F9F40 802D5590 C6020010 */  lwc1  $f2, 0x10($s0)
/* 0F9F44 802D5594 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F48 802D5598 46020302 */  mul.s $f12, $f0, $f2
/* 0F9F4C 802D559C 080B55A4 */  j     func_802D5690
/* 0F9F50 802D55A0 00000000 */   nop   

.L802D55A4:
/* 0F9F54 802D55A4 8E020014 */  lw    $v0, 0x14($s0)
/* 0F9F58 802D55A8 00420018 */  mult  $v0, $v0
/* 0F9F5C 802D55AC 00001812 */  mflo  $v1
/* 0F9F60 802D55B0 8E020010 */  lw    $v0, 0x10($s0)
/* 0F9F64 802D55B4 00000000 */  nop   
/* 0F9F68 802D55B8 00420018 */  mult  $v0, $v0
/* 0F9F6C 802D55BC 3C013F80 */  lui   $at, 0x3f80
/* 0F9F70 802D55C0 44810000 */  mtc1  $at, $f0
/* 0F9F74 802D55C4 44831000 */  mtc1  $v1, $f2
/* 0F9F78 802D55C8 00000000 */  nop   
/* 0F9F7C 802D55CC 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F80 802D55D0 00001012 */  mflo  $v0
/* 0F9F84 802D55D4 46020003 */  div.s $f0, $f0, $f2
/* 0F9F88 802D55D8 44821000 */  mtc1  $v0, $f2
/* 0F9F8C 802D55DC 00000000 */  nop   
/* 0F9F90 802D55E0 468010A0 */  cvt.s.w $f2, $f2
/* 0F9F94 802D55E4 46020302 */  mul.s $f12, $f0, $f2
/* 0F9F98 802D55E8 080B55A4 */  j     func_802D5690
/* 0F9F9C 802D55EC 00000000 */   nop   

.L802D55F0:
/* 0F9FA0 802D55F0 8E020014 */  lw    $v0, 0x14($s0)
/* 0F9FA4 802D55F4 00420018 */  mult  $v0, $v0
/* 0F9FA8 802D55F8 8E030010 */  lw    $v1, 0x10($s0)
/* 0F9FAC 802D55FC 00431023 */  subu  $v0, $v0, $v1
/* 0F9FB0 802D5600 44820000 */  mtc1  $v0, $f0
/* 0F9FB4 802D5604 00000000 */  nop   
/* 0F9FB8 802D5608 46800020 */  cvt.s.w $f0, $f0
/* 0F9FBC 802D560C 46000002 */  mul.s $f0, $f0, $f0
/* 0F9FC0 802D5610 00000000 */  nop   
/* 0F9FC4 802D5614 3C013F80 */  lui   $at, 0x3f80
/* 0F9FC8 802D5618 44812000 */  mtc1  $at, $f4
/* 0F9FCC 802D561C 00004012 */  mflo  $t0
/* 0F9FD0 802D5620 44881000 */  mtc1  $t0, $f2
/* 0F9FD4 802D5624 00000000 */  nop   
/* 0F9FD8 802D5628 468010A0 */  cvt.s.w $f2, $f2
/* 0F9FDC 802D562C 46020003 */  div.s $f0, $f0, $f2
/* 0F9FE0 802D5630 080B55A4 */  j     func_802D5690
/* 0F9FE4 802D5634 46002301 */   sub.s $f12, $f4, $f0

.L802D5638:
/* 0F9FE8 802D5638 3C014049 */  lui   $at, 0x4049
/* 0F9FEC 802D563C 34210FD8 */  ori   $at, $at, 0xfd8
/* 0F9FF0 802D5640 44816000 */  mtc1  $at, $f12
/* 0F9FF4 802D5644 C6000014 */  lwc1  $f0, 0x14($s0)
/* 0F9FF8 802D5648 46800020 */  cvt.s.w $f0, $f0
/* 0F9FFC 802D564C 46006303 */  div.s $f12, $f12, $f0
/* 0FA000 802D5650 C6000010 */  lwc1  $f0, 0x10($s0)
/* 0FA004 802D5654 46800020 */  cvt.s.w $f0, $f0
/* 0FA008 802D5658 46006302 */  mul.s $f12, $f12, $f0
/* 0FA00C 802D565C 0C00A874 */  jal   func_8002A1D0
/* 0FA010 802D5660 00000000 */   nop   
/* 0FA014 802D5664 3C013F80 */  lui   $at, 0x3f80
/* 0FA018 802D5668 44811000 */  mtc1  $at, $f2
/* 0FA01C 802D566C 00000000 */  nop   
/* 0FA020 802D5670 46001081 */  sub.s $f2, $f2, $f0
/* 0FA024 802D5674 3C013F00 */  lui   $at, 0x3f00
/* 0FA028 802D5678 44810000 */  mtc1  $at, $f0
/* 0FA02C 802D567C 00000000 */  nop   
/* 0FA030 802D5680 46001302 */  mul.s $f12, $f2, $f0
/* 0FA034 802D5684 080B55A4 */  j     func_802D5690
/* 0FA038 802D5688 00000000 */   nop   

func_802D568C:
/* 0FA03C 802D568C 44806000 */  mtc1  $zero, $f12
func_802D5690:
/* 0FA040 802D5690 8E020008 */  lw    $v0, 8($s0)
/* 0FA044 802D5694 AFA20010 */  sw    $v0, 0x10($sp)
/* 0FA048 802D5698 8E02000C */  lw    $v0, 0xc($s0)
/* 0FA04C 802D569C AFA20014 */  sw    $v0, 0x14($sp)
/* 0FA050 802D56A0 8E060000 */  lw    $a2, ($s0)
/* 0FA054 802D56A4 8E070004 */  lw    $a3, 4($s0)
/* 0FA058 802D56A8 0C0B549C */  jal   func_802D5270
/* 0FA05C 802D56AC 27A50018 */   addiu $a1, $sp, 0x18
/* 0FA060 802D56B0 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 0FA064 802D56B4 3C014480 */  lui   $at, 0x4480
/* 0FA068 802D56B8 44812000 */  mtc1  $at, $f4
/* 0FA06C 802D56BC 00000000 */  nop   
/* 0FA070 802D56C0 46040002 */  mul.s $f0, $f0, $f4
/* 0FA074 802D56C4 00000000 */  nop   
/* 0FA078 802D56C8 3C01CD5B */  lui   $at, 0xcd5b
/* 0FA07C 802D56CC 34215858 */  ori   $at, $at, 0x5858
/* 0FA080 802D56D0 44811000 */  mtc1  $at, $f2
/* 0FA084 802D56D4 00000000 */  nop   
/* 0FA088 802D56D8 46020000 */  add.s $f0, $f0, $f2
/* 0FA08C 802D56DC 4600018D */  trunc.w.s $f6, $f0
/* 0FA090 802D56E0 E6260088 */  swc1  $f6, 0x88($s1)
/* 0FA094 802D56E4 C7A0001C */  lwc1  $f0, 0x1c($sp)
/* 0FA098 802D56E8 46040002 */  mul.s $f0, $f0, $f4
/* 0FA09C 802D56EC 00000000 */  nop   
/* 0FA0A0 802D56F0 46020000 */  add.s $f0, $f0, $f2
/* 0FA0A4 802D56F4 4600018D */  trunc.w.s $f6, $f0
/* 0FA0A8 802D56F8 E626008C */  swc1  $f6, 0x8c($s1)
/* 0FA0AC 802D56FC C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0FA0B0 802D5700 46040002 */  mul.s $f0, $f0, $f4
/* 0FA0B4 802D5704 00000000 */  nop   
/* 0FA0B8 802D5708 46020000 */  add.s $f0, $f0, $f2
/* 0FA0BC 802D570C 4600018D */  trunc.w.s $f6, $f0
/* 0FA0C0 802D5710 E6260090 */  swc1  $f6, 0x90($s1)
/* 0FA0C4 802D5714 8E030010 */  lw    $v1, 0x10($s0)
/* 0FA0C8 802D5718 8E020014 */  lw    $v0, 0x14($s0)
/* 0FA0CC 802D571C 0062102A */  slt   $v0, $v1, $v0
/* 0FA0D0 802D5720 10400005 */  beqz  $v0, .L802D5738
/* 0FA0D4 802D5724 24620001 */   addiu $v0, $v1, 1
/* 0FA0D8 802D5728 AE020010 */  sw    $v0, 0x10($s0)
/* 0FA0DC 802D572C 24020001 */  addiu $v0, $zero, 1
/* 0FA0E0 802D5730 080B55D6 */  j     func_802D5758
/* 0FA0E4 802D5734 AE220084 */   sw    $v0, 0x84($s1)

.L802D5738:
/* 0FA0E8 802D5738 8E040004 */  lw    $a0, 4($s0)
/* 0FA0EC 802D573C 0C00AB4B */  jal   func_8002AD2C
/* 0FA0F0 802D5740 00000000 */   nop   
/* 0FA0F4 802D5744 0C00AB4B */  jal   func_8002AD2C
/* 0FA0F8 802D5748 8E04000C */   lw    $a0, 0xc($s0)
/* 0FA0FC 802D574C 0C00AB4B */  jal   func_8002AD2C
/* 0FA100 802D5750 8E2400C0 */   lw    $a0, 0xc0($s1)
/* 0FA104 802D5754 AE200084 */  sw    $zero, 0x84($s1)
func_802D5758:
/* 0FA108 802D5758 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0FA10C 802D575C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0FA110 802D5760 8FB00028 */  lw    $s0, 0x28($sp)
/* 0FA114 802D5764 24020002 */  addiu $v0, $zero, 2
/* 0FA118 802D5768 03E00008 */  jr    $ra
/* 0FA11C 802D576C 27BD0038 */   addiu $sp, $sp, 0x38

/* 0FA120 802D5770 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FA124 802D5774 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA128 802D5778 0080882D */  daddu $s1, $a0, $zero
/* 0FA12C 802D577C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FA130 802D5780 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FA134 802D5784 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA138 802D5788 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0FA13C 802D578C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0FA140 802D5790 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0FA144 802D5794 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA148 802D5798 8E120000 */  lw    $s2, ($s0)
/* 0FA14C 802D579C 26100004 */  addiu $s0, $s0, 4
/* 0FA150 802D57A0 8E050000 */  lw    $a1, ($s0)
/* 0FA154 802D57A4 0C0B210B */  jal   func_802C842C
/* 0FA158 802D57A8 26100004 */   addiu $s0, $s0, 4
/* 0FA15C 802D57AC 8E050000 */  lw    $a1, ($s0)
/* 0FA160 802D57B0 26100004 */  addiu $s0, $s0, 4
/* 0FA164 802D57B4 0220202D */  daddu $a0, $s1, $zero
/* 0FA168 802D57B8 0C0B210B */  jal   func_802C842C
/* 0FA16C 802D57BC 46000606 */   mov.s $f24, $f0
/* 0FA170 802D57C0 8E050000 */  lw    $a1, ($s0)
/* 0FA174 802D57C4 26100004 */  addiu $s0, $s0, 4
/* 0FA178 802D57C8 0220202D */  daddu $a0, $s1, $zero
/* 0FA17C 802D57CC 0C0B210B */  jal   func_802C842C
/* 0FA180 802D57D0 46000586 */   mov.s $f22, $f0
/* 0FA184 802D57D4 0220202D */  daddu $a0, $s1, $zero
/* 0FA188 802D57D8 8E050000 */  lw    $a1, ($s0)
/* 0FA18C 802D57DC 0C0B210B */  jal   func_802C842C
/* 0FA190 802D57E0 46000506 */   mov.s $f20, $f0
/* 0FA194 802D57E4 4600C306 */  mov.s $f12, $f24
/* 0FA198 802D57E8 4406A000 */  mfc1  $a2, $f20
/* 0FA19C 802D57EC 44070000 */  mfc1  $a3, $f0
/* 0FA1A0 802D57F0 0C00A7B5 */  jal   func_80029ED4
/* 0FA1A4 802D57F4 4600B386 */   mov.s $f14, $f22
/* 0FA1A8 802D57F8 0220202D */  daddu $a0, $s1, $zero
/* 0FA1AC 802D57FC 44060000 */  mfc1  $a2, $f0
/* 0FA1B0 802D5800 0C0B2190 */  jal   func_802C8640
/* 0FA1B4 802D5804 0240282D */   daddu $a1, $s2, $zero
/* 0FA1B8 802D5808 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FA1BC 802D580C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FA1C0 802D5810 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA1C4 802D5814 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA1C8 802D5818 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0FA1CC 802D581C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0FA1D0 802D5820 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0FA1D4 802D5824 24020002 */  addiu $v0, $zero, 2
/* 0FA1D8 802D5828 03E00008 */  jr    $ra
/* 0FA1DC 802D582C 27BD0038 */   addiu $sp, $sp, 0x38

/* 0FA1E0 802D5830 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA1E4 802D5834 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA1E8 802D5838 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA1EC 802D583C 0C0B1EAF */  jal   func_802C7ABC
/* 0FA1F0 802D5840 8C450000 */   lw    $a1, ($v0)
/* 0FA1F4 802D5844 0C009C22 */  jal   func_80027088
/* 0FA1F8 802D5848 0040202D */   daddu $a0, $v0, $zero
/* 0FA1FC 802D584C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA200 802D5850 24020002 */  addiu $v0, $zero, 2
/* 0FA204 802D5854 03E00008 */  jr    $ra
/* 0FA208 802D5858 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA20C 802D585C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA210 802D5860 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA214 802D5864 0080882D */  daddu $s1, $a0, $zero
/* 0FA218 802D5868 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA21C 802D586C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA220 802D5870 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA224 802D5874 8E050000 */  lw    $a1, ($s0)
/* 0FA228 802D5878 0C0B1EAF */  jal   func_802C7ABC
/* 0FA22C 802D587C 26100004 */   addiu $s0, $s0, 4
/* 0FA230 802D5880 0220202D */  daddu $a0, $s1, $zero
/* 0FA234 802D5884 8E050000 */  lw    $a1, ($s0)
/* 0FA238 802D5888 0C0B1EAF */  jal   func_802C7ABC
/* 0FA23C 802D588C 0040802D */   daddu $s0, $v0, $zero
/* 0FA240 802D5890 12000007 */  beqz  $s0, .L802D58B0
/* 0FA244 802D5894 0040202D */   daddu $a0, $v0, $zero
/* 0FA248 802D5898 3C03800A */  lui   $v1, 0x800a
/* 0FA24C 802D589C 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0FA250 802D58A0 8C620000 */  lw    $v0, ($v1)
/* 0FA254 802D58A4 00441025 */  or    $v0, $v0, $a0
/* 0FA258 802D58A8 080B5632 */  j     func_802D58C8
/* 0FA25C 802D58AC AC620000 */   sw    $v0, ($v1)

.L802D58B0:
/* 0FA260 802D58B0 3C02800A */  lui   $v0, 0x800a
/* 0FA264 802D58B4 2442A650 */  addiu $v0, $v0, -0x59b0
/* 0FA268 802D58B8 8C430000 */  lw    $v1, ($v0)
/* 0FA26C 802D58BC 00042027 */  nor   $a0, $zero, $a0
/* 0FA270 802D58C0 00641824 */  and   $v1, $v1, $a0
/* 0FA274 802D58C4 AC430000 */  sw    $v1, ($v0)
func_802D58C8:
/* 0FA278 802D58C8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA27C 802D58CC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA280 802D58D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA284 802D58D4 24020002 */  addiu $v0, $zero, 2
/* 0FA288 802D58D8 03E00008 */  jr    $ra
/* 0FA28C 802D58DC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA290 802D58E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA294 802D58E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA298 802D58E8 0080882D */  daddu $s1, $a0, $zero
/* 0FA29C 802D58EC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA2A0 802D58F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA2A4 802D58F4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA2A8 802D58F8 8E050000 */  lw    $a1, ($s0)
/* 0FA2AC 802D58FC 0C0B1EAF */  jal   func_802C7ABC
/* 0FA2B0 802D5900 26100004 */   addiu $s0, $s0, 4
/* 0FA2B4 802D5904 0220202D */  daddu $a0, $s1, $zero
/* 0FA2B8 802D5908 8E050000 */  lw    $a1, ($s0)
/* 0FA2BC 802D590C 0C0B1EAF */  jal   func_802C7ABC
/* 0FA2C0 802D5910 0040802D */   daddu $s0, $v0, $zero
/* 0FA2C4 802D5914 0220202D */  daddu $a0, $s1, $zero
/* 0FA2C8 802D5918 0200282D */  daddu $a1, $s0, $zero
/* 0FA2CC 802D591C 0C0B2026 */  jal   func_802C8098
/* 0FA2D0 802D5920 0040302D */   daddu $a2, $v0, $zero
/* 0FA2D4 802D5924 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA2D8 802D5928 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA2DC 802D592C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA2E0 802D5930 24020002 */  addiu $v0, $zero, 2
/* 0FA2E4 802D5934 03E00008 */  jr    $ra
/* 0FA2E8 802D5938 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA2EC 802D593C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA2F0 802D5940 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA2F4 802D5944 0080882D */  daddu $s1, $a0, $zero
/* 0FA2F8 802D5948 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA2FC 802D594C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA300 802D5950 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA304 802D5954 8E050000 */  lw    $a1, ($s0)
/* 0FA308 802D5958 0C0B1EAF */  jal   func_802C7ABC
/* 0FA30C 802D595C 26100004 */   addiu $s0, $s0, 4
/* 0FA310 802D5960 0220202D */  daddu $a0, $s1, $zero
/* 0FA314 802D5964 8E100000 */  lw    $s0, ($s0)
/* 0FA318 802D5968 0C0B1EAF */  jal   func_802C7ABC
/* 0FA31C 802D596C 0040282D */   daddu $a1, $v0, $zero
/* 0FA320 802D5970 0220202D */  daddu $a0, $s1, $zero
/* 0FA324 802D5974 0040302D */  daddu $a2, $v0, $zero
/* 0FA328 802D5978 0C0B2026 */  jal   func_802C8098
/* 0FA32C 802D597C 0200282D */   daddu $a1, $s0, $zero
/* 0FA330 802D5980 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA334 802D5984 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA338 802D5988 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA33C 802D598C 24020002 */  addiu $v0, $zero, 2
/* 0FA340 802D5990 03E00008 */  jr    $ra
/* 0FA344 802D5994 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA348 802D5998 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA34C 802D599C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA350 802D59A0 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA354 802D59A4 0C0B1EAF */  jal   func_802C7ABC
/* 0FA358 802D59A8 8C450000 */   lw    $a1, ($v0)
/* 0FA35C 802D59AC 10400005 */  beqz  $v0, .L802D59C4
/* 0FA360 802D59B0 00000000 */   nop   
/* 0FA364 802D59B4 0C03A6CC */  jal   func_800E9B30
/* 0FA368 802D59B8 00000000 */   nop   
/* 0FA36C 802D59BC 080B5673 */  j     func_802D59CC
/* 0FA370 802D59C0 00000000 */   nop   

.L802D59C4:
/* 0FA374 802D59C4 0C03A6D5 */  jal   func_800E9B54
/* 0FA378 802D59C8 00000000 */   nop   
func_802D59CC:
/* 0FA37C 802D59CC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA380 802D59D0 24020002 */  addiu $v0, $zero, 2
/* 0FA384 802D59D4 03E00008 */  jr    $ra
/* 0FA388 802D59D8 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA38C 802D59DC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA390 802D59E0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA394 802D59E4 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA398 802D59E8 0C0B1EAF */  jal   func_802C7ABC
/* 0FA39C 802D59EC 8C450000 */   lw    $a1, ($v0)
/* 0FA3A0 802D59F0 10400007 */  beqz  $v0, .L802D5A10
/* 0FA3A4 802D59F4 00000000 */   nop   
/* 0FA3A8 802D59F8 0C03A625 */  jal   func_800E9894
/* 0FA3AC 802D59FC 00000000 */   nop   
/* 0FA3B0 802D5A00 0C03A5EE */  jal   func_800E97B8
/* 0FA3B4 802D5A04 00000000 */   nop   
/* 0FA3B8 802D5A08 080B5686 */  j     func_802D5A18
/* 0FA3BC 802D5A0C 00000000 */   nop   

.L802D5A10:
/* 0FA3C0 802D5A10 0C03A631 */  jal   func_800E98C4
/* 0FA3C4 802D5A14 00000000 */   nop   
func_802D5A18:
/* 0FA3C8 802D5A18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA3CC 802D5A1C 24020002 */  addiu $v0, $zero, 2
/* 0FA3D0 802D5A20 03E00008 */  jr    $ra
/* 0FA3D4 802D5A24 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA3D8 802D5A28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA3DC 802D5A2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA3E0 802D5A30 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA3E4 802D5A34 0C0B1EAF */  jal   func_802C7ABC
/* 0FA3E8 802D5A38 8C450000 */   lw    $a1, ($v0)
/* 0FA3EC 802D5A3C 00021400 */  sll   $v0, $v0, 0x10
/* 0FA3F0 802D5A40 0C00CD3C */  jal   func_800334F0
/* 0FA3F4 802D5A44 00022403 */   sra   $a0, $v0, 0x10
/* 0FA3F8 802D5A48 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA3FC 802D5A4C 24020002 */  addiu $v0, $zero, 2
/* 0FA400 802D5A50 03E00008 */  jr    $ra
/* 0FA404 802D5A54 27BD0018 */   addiu $sp, $sp, 0x18

/* 0FA408 802D5A58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA40C 802D5A5C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA410 802D5A60 0080802D */  daddu $s0, $a0, $zero
/* 0FA414 802D5A64 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA418 802D5A68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA41C 802D5A6C 8E11000C */  lw    $s1, 0xc($s0)
/* 0FA420 802D5A70 0C0B1EAF */  jal   func_802C7ABC
/* 0FA424 802D5A74 8E250000 */   lw    $a1, ($s1)
/* 0FA428 802D5A78 44826000 */  mtc1  $v0, $f12
/* 0FA42C 802D5A7C 00000000 */  nop   
/* 0FA430 802D5A80 0C00A6C9 */  jal   func_80029B24
/* 0FA434 802D5A84 46806320 */   cvt.s.w $f12, $f12
/* 0FA438 802D5A88 8E250000 */  lw    $a1, ($s1)
/* 0FA43C 802D5A8C 4600008D */  trunc.w.s $f2, $f0
/* 0FA440 802D5A90 44061000 */  mfc1  $a2, $f2
/* 0FA444 802D5A94 0C0B2026 */  jal   func_802C8098
/* 0FA448 802D5A98 0200202D */   daddu $a0, $s0, $zero
/* 0FA44C 802D5A9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA450 802D5AA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA454 802D5AA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA458 802D5AA8 24020002 */  addiu $v0, $zero, 2
/* 0FA45C 802D5AAC 03E00008 */  jr    $ra
/* 0FA460 802D5AB0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA464 802D5AB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA468 802D5AB8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA46C 802D5ABC 0080802D */  daddu $s0, $a0, $zero
/* 0FA470 802D5AC0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA474 802D5AC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA478 802D5AC8 8E11000C */  lw    $s1, 0xc($s0)
/* 0FA47C 802D5ACC 0C0B210B */  jal   func_802C842C
/* 0FA480 802D5AD0 8E250000 */   lw    $a1, ($s1)
/* 0FA484 802D5AD4 0C00A6C9 */  jal   func_80029B24
/* 0FA488 802D5AD8 46000306 */   mov.s $f12, $f0
/* 0FA48C 802D5ADC 8E250000 */  lw    $a1, ($s1)
/* 0FA490 802D5AE0 44060000 */  mfc1  $a2, $f0
/* 0FA494 802D5AE4 0C0B2190 */  jal   func_802C8640
/* 0FA498 802D5AE8 0200202D */   daddu $a0, $s0, $zero
/* 0FA49C 802D5AEC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA4A0 802D5AF0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA4A4 802D5AF4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA4A8 802D5AF8 24020002 */  addiu $v0, $zero, 2
/* 0FA4AC 802D5AFC 03E00008 */  jr    $ra
/* 0FA4B0 802D5B00 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FA4B4 802D5B04 00000000 */  nop   
/* 0FA4B8 802D5B08 00000000 */  nop   
/* 0FA4BC 802D5B0C 00000000 */  nop   
