.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCurrentPartnerID
/* 0F4624 802CFC74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F4628 802CFC78 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F462C 802CFC7C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F4630 802CFC80 3C068011 */  lui   $a2, 0x8011
/* 0F4634 802CFC84 80C6F2A2 */  lb    $a2, -0xd5e($a2)
/* 0F4638 802CFC88 0C0B2026 */  jal   set_variable
/* 0F463C 802CFC8C 8C450000 */   lw    $a1, ($v0)
/* 0F4640 802CFC90 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F4644 802CFC94 24020002 */  addiu $v0, $zero, 2
/* 0F4648 802CFC98 03E00008 */  jr    $ra
/* 0F464C 802CFC9C 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F4650 802CFCA0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4654 802CFCA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F4658 802CFCA8 0080802D */  daddu $s0, $a0, $zero
/* 0F465C 802CFCAC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F4660 802CFCB0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F4664 802CFCB4 8E02000C */  lw    $v0, 0xc($s0)
/* 0F4668 802CFCB8 0C03AD0B */  jal   func_800EB42C
/* 0F466C 802CFCBC 8C510000 */   lw    $s1, ($v0)
/* 0F4670 802CFCC0 0200202D */  daddu $a0, $s0, $zero
/* 0F4674 802CFCC4 0040302D */  daddu $a2, $v0, $zero
/* 0F4678 802CFCC8 0C0B2026 */  jal   set_variable
/* 0F467C 802CFCCC 0220282D */   daddu $a1, $s1, $zero
/* 0F4680 802CFCD0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F4684 802CFCD4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F4688 802CFCD8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F468C 802CFCDC 24020002 */  addiu $v0, $zero, 2
/* 0F4690 802CFCE0 03E00008 */  jr    $ra
/* 0F4694 802CFCE4 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F4698 802CFCE8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F469C 802CFCEC AFB00010 */  sw    $s0, 0x10($sp)
/* 0F46A0 802CFCF0 0080802D */  daddu $s0, $a0, $zero
/* 0F46A4 802CFCF4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F46A8 802CFCF8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F46AC 802CFCFC 8E02000C */  lw    $v0, 0xc($s0)
/* 0F46B0 802CFD00 0C03A969 */  jal   func_800EA5A4
/* 0F46B4 802CFD04 8C510000 */   lw    $s1, ($v0)
/* 0F46B8 802CFD08 0200202D */  daddu $a0, $s0, $zero
/* 0F46BC 802CFD0C 0040302D */  daddu $a2, $v0, $zero
/* 0F46C0 802CFD10 0C0B2026 */  jal   set_variable
/* 0F46C4 802CFD14 0220282D */   daddu $a1, $s1, $zero
/* 0F46C8 802CFD18 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F46CC 802CFD1C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F46D0 802CFD20 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F46D4 802CFD24 24020002 */  addiu $v0, $zero, 2
/* 0F46D8 802CFD28 03E00008 */  jr    $ra
/* 0F46DC 802CFD2C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F46E0 802CFD30 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F46E4 802CFD34 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F46E8 802CFD38 0080882D */  daddu $s1, $a0, $zero
/* 0F46EC 802CFD3C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0F46F0 802CFD40 AFB60038 */  sw    $s6, 0x38($sp)
/* 0F46F4 802CFD44 AFB50034 */  sw    $s5, 0x34($sp)
/* 0F46F8 802CFD48 AFB40030 */  sw    $s4, 0x30($sp)
/* 0F46FC 802CFD4C AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F4700 802CFD50 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F4704 802CFD54 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F4708 802CFD58 8E30000C */  lw    $s0, 0xc($s1)
/* 0F470C 802CFD5C 8E050000 */  lw    $a1, ($s0)
/* 0F4710 802CFD60 0C0B1EAF */  jal   get_variable
/* 0F4714 802CFD64 26100004 */   addiu $s0, $s0, 4
/* 0F4718 802CFD68 8E050000 */  lw    $a1, ($s0)
/* 0F471C 802CFD6C 26100004 */  addiu $s0, $s0, 4
/* 0F4720 802CFD70 0220202D */  daddu $a0, $s1, $zero
/* 0F4724 802CFD74 0C0B1EAF */  jal   get_variable
/* 0F4728 802CFD78 0040902D */   daddu $s2, $v0, $zero
/* 0F472C 802CFD7C 8E050000 */  lw    $a1, ($s0)
/* 0F4730 802CFD80 26100004 */  addiu $s0, $s0, 4
/* 0F4734 802CFD84 0220202D */  daddu $a0, $s1, $zero
/* 0F4738 802CFD88 0C0B1EAF */  jal   get_variable
/* 0F473C 802CFD8C 0040B02D */   daddu $s6, $v0, $zero
/* 0F4740 802CFD90 8E050000 */  lw    $a1, ($s0)
/* 0F4744 802CFD94 26100004 */  addiu $s0, $s0, 4
/* 0F4748 802CFD98 0220202D */  daddu $a0, $s1, $zero
/* 0F474C 802CFD9C 0C0B1EAF */  jal   get_variable
/* 0F4750 802CFDA0 0040A82D */   daddu $s5, $v0, $zero
/* 0F4754 802CFDA4 8E050000 */  lw    $a1, ($s0)
/* 0F4758 802CFDA8 26100004 */  addiu $s0, $s0, 4
/* 0F475C 802CFDAC 0220202D */  daddu $a0, $s1, $zero
/* 0F4760 802CFDB0 0C0B1EAF */  jal   get_variable
/* 0F4764 802CFDB4 0040A02D */   daddu $s4, $v0, $zero
/* 0F4768 802CFDB8 0220202D */  daddu $a0, $s1, $zero
/* 0F476C 802CFDBC 8E050000 */  lw    $a1, ($s0)
/* 0F4770 802CFDC0 0C0B1EAF */  jal   get_variable
/* 0F4774 802CFDC4 0040982D */   daddu $s3, $v0, $zero
/* 0F4778 802CFDC8 0220202D */  daddu $a0, $s1, $zero
/* 0F477C 802CFDCC 0240282D */  daddu $a1, $s2, $zero
/* 0F4780 802CFDD0 0C0B36B0 */  jal   func_802CDAC0
/* 0F4784 802CFDD4 0040802D */   daddu $s0, $v0, $zero
/* 0F4788 802CFDD8 10400009 */  beqz  $v0, .L802CFE00
/* 0F478C 802CFDDC 0040202D */   daddu $a0, $v0, $zero
/* 0F4790 802CFDE0 02C0282D */  daddu $a1, $s6, $zero
/* 0F4794 802CFDE4 02A0302D */  daddu $a2, $s5, $zero
/* 0F4798 802CFDE8 AFB30010 */  sw    $s3, 0x10($sp)
/* 0F479C 802CFDEC AFB00014 */  sw    $s0, 0x14($sp)
/* 0F47A0 802CFDF0 948200A2 */  lhu   $v0, 0xa2($a0)
/* 0F47A4 802CFDF4 0280382D */  daddu $a3, $s4, $zero
/* 0F47A8 802CFDF8 0C00F589 */  jal   func_8003D624
/* 0F47AC 802CFDFC AFA20018 */   sw    $v0, 0x18($sp)
.L802CFE00:
/* 0F47B0 802CFE00 24020002 */  addiu $v0, $zero, 2
/* 0F47B4 802CFE04 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0F47B8 802CFE08 8FB60038 */  lw    $s6, 0x38($sp)
/* 0F47BC 802CFE0C 8FB50034 */  lw    $s5, 0x34($sp)
/* 0F47C0 802CFE10 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F47C4 802CFE14 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F47C8 802CFE18 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F47CC 802CFE1C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F47D0 802CFE20 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F47D4 802CFE24 03E00008 */  jr    $ra
/* 0F47D8 802CFE28 27BD0040 */   addiu $sp, $sp, 0x40

/* 0F47DC 802CFE2C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F47E0 802CFE30 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F47E4 802CFE34 0080802D */  daddu $s0, $a0, $zero
/* 0F47E8 802CFE38 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F47EC 802CFE3C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F47F0 802CFE40 8E11000C */  lw    $s1, 0xc($s0)
/* 0F47F4 802CFE44 8E250000 */  lw    $a1, ($s1)
/* 0F47F8 802CFE48 0C0B1EAF */  jal   get_variable
/* 0F47FC 802CFE4C 26310004 */   addiu $s1, $s1, 4
/* 0F4800 802CFE50 0200202D */  daddu $a0, $s0, $zero
/* 0F4804 802CFE54 8E310000 */  lw    $s1, ($s1)
/* 0F4808 802CFE58 0C0B36B0 */  jal   func_802CDAC0
/* 0F480C 802CFE5C 0040282D */   daddu $a1, $v0, $zero
/* 0F4810 802CFE60 54400001 */  bnel  $v0, $zero, .L802CFE68
/* 0F4814 802CFE64 A45100A2 */   sh    $s1, 0xa2($v0)
.L802CFE68:
/* 0F4818 802CFE68 24020002 */  addiu $v0, $zero, 2
/* 0F481C 802CFE6C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F4820 802CFE70 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F4824 802CFE74 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F4828 802CFE78 03E00008 */  jr    $ra
/* 0F482C 802CFE7C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F4830 802CFE80 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4834 802CFE84 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F4838 802CFE88 0080882D */  daddu $s1, $a0, $zero
/* 0F483C 802CFE8C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F4840 802CFE90 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F4844 802CFE94 8E30000C */  lw    $s0, 0xc($s1)
/* 0F4848 802CFE98 8E050000 */  lw    $a1, ($s0)
/* 0F484C 802CFE9C 0C0B1EAF */  jal   get_variable
/* 0F4850 802CFEA0 26100004 */   addiu $s0, $s0, 4
/* 0F4854 802CFEA4 0220202D */  daddu $a0, $s1, $zero
/* 0F4858 802CFEA8 8E050000 */  lw    $a1, ($s0)
/* 0F485C 802CFEAC 0C0B1EAF */  jal   get_variable
/* 0F4860 802CFEB0 0040802D */   daddu $s0, $v0, $zero
/* 0F4864 802CFEB4 0220202D */  daddu $a0, $s1, $zero
/* 0F4868 802CFEB8 0200282D */  daddu $a1, $s0, $zero
/* 0F486C 802CFEBC 0C0B36B0 */  jal   func_802CDAC0
/* 0F4870 802CFEC0 0040802D */   daddu $s0, $v0, $zero
/* 0F4874 802CFEC4 10400003 */  beqz  $v0, .L802CFED4
/* 0F4878 802CFEC8 0040202D */   daddu $a0, $v0, $zero
/* 0F487C 802CFECC 0C00ECF4 */  jal   func_8003B3D0
/* 0F4880 802CFED0 0200282D */   daddu $a1, $s0, $zero
.L802CFED4:
/* 0F4884 802CFED4 24020002 */  addiu $v0, $zero, 2
/* 0F4888 802CFED8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F488C 802CFEDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F4890 802CFEE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F4894 802CFEE4 03E00008 */  jr    $ra
/* 0F4898 802CFEE8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F489C 802CFEEC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F48A0 802CFEF0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F48A4 802CFEF4 0080882D */  daddu $s1, $a0, $zero
/* 0F48A8 802CFEF8 AFBF0030 */  sw    $ra, 0x30($sp)
/* 0F48AC 802CFEFC AFB5002C */  sw    $s5, 0x2c($sp)
/* 0F48B0 802CFF00 AFB40028 */  sw    $s4, 0x28($sp)
/* 0F48B4 802CFF04 AFB30024 */  sw    $s3, 0x24($sp)
/* 0F48B8 802CFF08 AFB20020 */  sw    $s2, 0x20($sp)
/* 0F48BC 802CFF0C AFB00018 */  sw    $s0, 0x18($sp)
/* 0F48C0 802CFF10 8E30000C */  lw    $s0, 0xc($s1)
/* 0F48C4 802CFF14 8E050000 */  lw    $a1, ($s0)
/* 0F48C8 802CFF18 0C0B1EAF */  jal   get_variable
/* 0F48CC 802CFF1C 26100004 */   addiu $s0, $s0, 4
/* 0F48D0 802CFF20 8E050000 */  lw    $a1, ($s0)
/* 0F48D4 802CFF24 26100004 */  addiu $s0, $s0, 4
/* 0F48D8 802CFF28 0220202D */  daddu $a0, $s1, $zero
/* 0F48DC 802CFF2C 0C0B1EAF */  jal   get_variable
/* 0F48E0 802CFF30 0040902D */   daddu $s2, $v0, $zero
/* 0F48E4 802CFF34 8E050000 */  lw    $a1, ($s0)
/* 0F48E8 802CFF38 26100004 */  addiu $s0, $s0, 4
/* 0F48EC 802CFF3C 0220202D */  daddu $a0, $s1, $zero
/* 0F48F0 802CFF40 0C0B1EAF */  jal   get_variable
/* 0F48F4 802CFF44 0040A82D */   daddu $s5, $v0, $zero
/* 0F48F8 802CFF48 8E050000 */  lw    $a1, ($s0)
/* 0F48FC 802CFF4C 26100004 */  addiu $s0, $s0, 4
/* 0F4900 802CFF50 0220202D */  daddu $a0, $s1, $zero
/* 0F4904 802CFF54 0C0B1EAF */  jal   get_variable
/* 0F4908 802CFF58 0040A02D */   daddu $s4, $v0, $zero
/* 0F490C 802CFF5C 0220202D */  daddu $a0, $s1, $zero
/* 0F4910 802CFF60 8E050000 */  lw    $a1, ($s0)
/* 0F4914 802CFF64 0C0B1EAF */  jal   get_variable
/* 0F4918 802CFF68 0040982D */   daddu $s3, $v0, $zero
/* 0F491C 802CFF6C 0220202D */  daddu $a0, $s1, $zero
/* 0F4920 802CFF70 0240282D */  daddu $a1, $s2, $zero
/* 0F4924 802CFF74 0C0B36B0 */  jal   func_802CDAC0
/* 0F4928 802CFF78 0040802D */   daddu $s0, $v0, $zero
/* 0F492C 802CFF7C 10400006 */  beqz  $v0, .L802CFF98
/* 0F4930 802CFF80 0040202D */   daddu $a0, $v0, $zero
/* 0F4934 802CFF84 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F4938 802CFF88 02A0282D */  daddu $a1, $s5, $zero
/* 0F493C 802CFF8C 0280302D */  daddu $a2, $s4, $zero
/* 0F4940 802CFF90 0C00ED13 */  jal   func_8003B44C
/* 0F4944 802CFF94 0260382D */   daddu $a3, $s3, $zero
.L802CFF98:
/* 0F4948 802CFF98 24020002 */  addiu $v0, $zero, 2
/* 0F494C 802CFF9C 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0F4950 802CFFA0 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0F4954 802CFFA4 8FB40028 */  lw    $s4, 0x28($sp)
/* 0F4958 802CFFA8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0F495C 802CFFAC 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F4960 802CFFB0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F4964 802CFFB4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F4968 802CFFB8 03E00008 */  jr    $ra
/* 0F496C 802CFFBC 27BD0038 */   addiu $sp, $sp, 0x38

/* 0F4970 802CFFC0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0F4974 802CFFC4 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F4978 802CFFC8 0080882D */  daddu $s1, $a0, $zero
/* 0F497C 802CFFCC AFBF0044 */  sw    $ra, 0x44($sp)
/* 0F4980 802CFFD0 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0F4984 802CFFD4 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0F4988 802CFFD8 AFB60038 */  sw    $s6, 0x38($sp)
/* 0F498C 802CFFDC AFB50034 */  sw    $s5, 0x34($sp)
/* 0F4990 802CFFE0 AFB40030 */  sw    $s4, 0x30($sp)
/* 0F4994 802CFFE4 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F4998 802CFFE8 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F499C 802CFFEC AFB00020 */  sw    $s0, 0x20($sp)
/* 0F49A0 802CFFF0 8E30000C */  lw    $s0, 0xc($s1)
/* 0F49A4 802CFFF4 8E050000 */  lw    $a1, ($s0)
/* 0F49A8 802CFFF8 0C0B1EAF */  jal   get_variable
/* 0F49AC 802CFFFC 26100004 */   addiu $s0, $s0, 4
/* 0F49B0 802D0000 8E050000 */  lw    $a1, ($s0)
/* 0F49B4 802D0004 26100004 */  addiu $s0, $s0, 4
/* 0F49B8 802D0008 0220202D */  daddu $a0, $s1, $zero
/* 0F49BC 802D000C 0C0B1EAF */  jal   get_variable
/* 0F49C0 802D0010 0040902D */   daddu $s2, $v0, $zero
/* 0F49C4 802D0014 8E050000 */  lw    $a1, ($s0)
/* 0F49C8 802D0018 26100004 */  addiu $s0, $s0, 4
/* 0F49CC 802D001C 0220202D */  daddu $a0, $s1, $zero
/* 0F49D0 802D0020 0C0B1EAF */  jal   get_variable
/* 0F49D4 802D0024 AFA20018 */   sw    $v0, 0x18($sp)
/* 0F49D8 802D0028 8E050000 */  lw    $a1, ($s0)
/* 0F49DC 802D002C 26100004 */  addiu $s0, $s0, 4
/* 0F49E0 802D0030 0220202D */  daddu $a0, $s1, $zero
/* 0F49E4 802D0034 0C0B1EAF */  jal   get_variable
/* 0F49E8 802D0038 0040F02D */   daddu $fp, $v0, $zero
/* 0F49EC 802D003C 8E050000 */  lw    $a1, ($s0)
/* 0F49F0 802D0040 26100004 */  addiu $s0, $s0, 4
/* 0F49F4 802D0044 0220202D */  daddu $a0, $s1, $zero
/* 0F49F8 802D0048 0C0B1EAF */  jal   get_variable
/* 0F49FC 802D004C 0040B82D */   daddu $s7, $v0, $zero
/* 0F4A00 802D0050 8E050000 */  lw    $a1, ($s0)
/* 0F4A04 802D0054 26100004 */  addiu $s0, $s0, 4
/* 0F4A08 802D0058 0220202D */  daddu $a0, $s1, $zero
/* 0F4A0C 802D005C 0C0B1EAF */  jal   get_variable
/* 0F4A10 802D0060 0040B02D */   daddu $s6, $v0, $zero
/* 0F4A14 802D0064 8E050000 */  lw    $a1, ($s0)
/* 0F4A18 802D0068 26100004 */  addiu $s0, $s0, 4
/* 0F4A1C 802D006C 0220202D */  daddu $a0, $s1, $zero
/* 0F4A20 802D0070 0C0B1EAF */  jal   get_variable
/* 0F4A24 802D0074 0040A82D */   daddu $s5, $v0, $zero
/* 0F4A28 802D0078 8E050000 */  lw    $a1, ($s0)
/* 0F4A2C 802D007C 26100004 */  addiu $s0, $s0, 4
/* 0F4A30 802D0080 0220202D */  daddu $a0, $s1, $zero
/* 0F4A34 802D0084 0C0B1EAF */  jal   get_variable
/* 0F4A38 802D0088 0040A02D */   daddu $s4, $v0, $zero
/* 0F4A3C 802D008C 0220202D */  daddu $a0, $s1, $zero
/* 0F4A40 802D0090 8E050000 */  lw    $a1, ($s0)
/* 0F4A44 802D0094 0C0B1EAF */  jal   get_variable
/* 0F4A48 802D0098 0040982D */   daddu $s3, $v0, $zero
/* 0F4A4C 802D009C 0220202D */  daddu $a0, $s1, $zero
/* 0F4A50 802D00A0 0240282D */  daddu $a1, $s2, $zero
/* 0F4A54 802D00A4 0C0B36B0 */  jal   func_802CDAC0
/* 0F4A58 802D00A8 0040882D */   daddu $s1, $v0, $zero
/* 0F4A5C 802D00AC 0040802D */  daddu $s0, $v0, $zero
/* 0F4A60 802D00B0 1200000C */  beqz  $s0, .L802D00E4
/* 0F4A64 802D00B4 0200202D */   daddu $a0, $s0, $zero
/* 0F4A68 802D00B8 03C0302D */  daddu $a2, $fp, $zero
/* 0F4A6C 802D00BC 8FA50018 */  lw    $a1, 0x18($sp)
/* 0F4A70 802D00C0 02E0382D */  daddu $a3, $s7, $zero
/* 0F4A74 802D00C4 0C00ED13 */  jal   func_8003B44C
/* 0F4A78 802D00C8 AFB60010 */   sw    $s6, 0x10($sp)
/* 0F4A7C 802D00CC 0200202D */  daddu $a0, $s0, $zero
/* 0F4A80 802D00D0 02A0282D */  daddu $a1, $s5, $zero
/* 0F4A84 802D00D4 0280302D */  daddu $a2, $s4, $zero
/* 0F4A88 802D00D8 0260382D */  daddu $a3, $s3, $zero
/* 0F4A8C 802D00DC 0C00ED19 */  jal   func_8003B464
/* 0F4A90 802D00E0 AFB10010 */   sw    $s1, 0x10($sp)
.L802D00E4:
/* 0F4A94 802D00E4 24020002 */  addiu $v0, $zero, 2
/* 0F4A98 802D00E8 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0F4A9C 802D00EC 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0F4AA0 802D00F0 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0F4AA4 802D00F4 8FB60038 */  lw    $s6, 0x38($sp)
/* 0F4AA8 802D00F8 8FB50034 */  lw    $s5, 0x34($sp)
/* 0F4AAC 802D00FC 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F4AB0 802D0100 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F4AB4 802D0104 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F4AB8 802D0108 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F4ABC 802D010C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F4AC0 802D0110 03E00008 */  jr    $ra
/* 0F4AC4 802D0114 27BD0048 */   addiu $sp, $sp, 0x48

