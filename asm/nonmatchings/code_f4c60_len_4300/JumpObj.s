.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel JumpObj
/* 0F8608 802D3C58 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0F860C 802D3C5C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8610 802D3C60 0080902D */  daddu $s2, $a0, $zero
/* 0F8614 802D3C64 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8618 802D3C68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F861C 802D3C6C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8620 802D3C70 F7BC0040 */  sdc1  $f28, 0x40($sp)
/* 0F8624 802D3C74 F7BA0038 */  sdc1  $f26, 0x38($sp)
/* 0F8628 802D3C78 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0F862C 802D3C7C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F8630 802D3C80 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F8634 802D3C84 8E51000C */  lw    $s1, 0xc($s2)
/* 0F8638 802D3C88 54A00001 */  bnel  $a1, $zero, .L802D3C90
/* 0F863C 802D3C8C AE400070 */   sw    $zero, 0x70($s2)
.L802D3C90:
/* 0F8640 802D3C90 8E420070 */  lw    $v0, 0x70($s2)
/* 0F8644 802D3C94 14400058 */  bnez  $v0, .L802D3DF8
/* 0F8648 802D3C98 00000000 */   nop   
/* 0F864C 802D3C9C 8E250000 */  lw    $a1, ($s1)
/* 0F8650 802D3CA0 26310004 */  addiu $s1, $s1, 4
/* 0F8654 802D3CA4 0C0B1EAF */  jal   get_variable
/* 0F8658 802D3CA8 0240202D */   daddu $a0, $s2, $zero
/* 0F865C 802D3CAC 8E250000 */  lw    $a1, ($s1)
/* 0F8660 802D3CB0 26310004 */  addiu $s1, $s1, 4
/* 0F8664 802D3CB4 0240202D */  daddu $a0, $s2, $zero
/* 0F8668 802D3CB8 0C0B1EAF */  jal   get_variable
/* 0F866C 802D3CBC 0040802D */   daddu $s0, $v0, $zero
/* 0F8670 802D3CC0 4482D000 */  mtc1  $v0, $f26
/* 0F8674 802D3CC4 00000000 */  nop   
/* 0F8678 802D3CC8 4680D6A0 */  cvt.s.w $f26, $f26
/* 0F867C 802D3CCC 8E250000 */  lw    $a1, ($s1)
/* 0F8680 802D3CD0 26310004 */  addiu $s1, $s1, 4
/* 0F8684 802D3CD4 0C0B1EAF */  jal   get_variable
/* 0F8688 802D3CD8 0240202D */   daddu $a0, $s2, $zero
/* 0F868C 802D3CDC 4482E000 */  mtc1  $v0, $f28
/* 0F8690 802D3CE0 00000000 */  nop   
/* 0F8694 802D3CE4 4680E720 */  cvt.s.w $f28, $f28
/* 0F8698 802D3CE8 8E250000 */  lw    $a1, ($s1)
/* 0F869C 802D3CEC 26310004 */  addiu $s1, $s1, 4
/* 0F86A0 802D3CF0 0C0B1EAF */  jal   get_variable
/* 0F86A4 802D3CF4 0240202D */   daddu $a0, $s2, $zero
/* 0F86A8 802D3CF8 4482C000 */  mtc1  $v0, $f24
/* 0F86AC 802D3CFC 00000000 */  nop   
/* 0F86B0 802D3D00 4680C620 */  cvt.s.w $f24, $f24
/* 0F86B4 802D3D04 8E250000 */  lw    $a1, ($s1)
/* 0F86B8 802D3D08 0C0B1EAF */  jal   get_variable
/* 0F86BC 802D3D0C 0240202D */   daddu $a0, $s2, $zero
/* 0F86C0 802D3D10 3C04802E */  lui   $a0, 0x802e
/* 0F86C4 802D3D14 8C84B7C0 */  lw    $a0, -0x4840($a0)
/* 0F86C8 802D3D18 00101880 */  sll   $v1, $s0, 2
/* 0F86CC 802D3D1C 00641821 */  addu  $v1, $v1, $a0
/* 0F86D0 802D3D20 8C710000 */  lw    $s1, ($v1)
/* 0F86D4 802D3D24 AE500074 */  sw    $s0, 0x74($s2)
/* 0F86D8 802D3D28 E63A0028 */  swc1  $f26, 0x28($s1)
/* 0F86DC 802D3D2C C63A0004 */  lwc1  $f26, 4($s1)
/* 0F86E0 802D3D30 E63C002C */  swc1  $f28, 0x2c($s1)
/* 0F86E4 802D3D34 C63C0008 */  lwc1  $f28, 8($s1)
/* 0F86E8 802D3D38 E6380030 */  swc1  $f24, 0x30($s1)
/* 0F86EC 802D3D3C C638000C */  lwc1  $f24, 0xc($s1)
/* 0F86F0 802D3D40 C6360028 */  lwc1  $f22, 0x28($s1)
/* 0F86F4 802D3D44 C6340030 */  lwc1  $f20, 0x30($s1)
/* 0F86F8 802D3D48 44820000 */  mtc1  $v0, $f0
/* 0F86FC 802D3D4C 00000000 */  nop   
/* 0F8700 802D3D50 46800020 */  cvt.s.w $f0, $f0
/* 0F8704 802D3D54 E6200048 */  swc1  $f0, 0x48($s1)
/* 0F8708 802D3D58 C620002C */  lwc1  $f0, 0x2c($s1)
/* 0F870C 802D3D5C 4600D306 */  mov.s $f12, $f26
/* 0F8710 802D3D60 4600C386 */  mov.s $f14, $f24
/* 0F8714 802D3D64 4406B000 */  mfc1  $a2, $f22
/* 0F8718 802D3D68 4407A000 */  mfc1  $a3, $f20
/* 0F871C 802D3D6C 0C00A720 */  jal   atan2
/* 0F8720 802D3D70 461C0701 */   sub.s $f28, $f0, $f28
/* 0F8724 802D3D74 4600D306 */  mov.s $f12, $f26
/* 0F8728 802D3D78 4406B000 */  mfc1  $a2, $f22
/* 0F872C 802D3D7C 4407A000 */  mfc1  $a3, $f20
/* 0F8730 802D3D80 4600C386 */  mov.s $f14, $f24
/* 0F8734 802D3D84 0C00A7B5 */  jal   dist2D
/* 0F8738 802D3D88 E6200038 */   swc1  $f0, 0x38($s1)
/* 0F873C 802D3D8C C6260048 */  lwc1  $f6, 0x48($s1)
/* 0F8740 802D3D90 44801000 */  mtc1  $zero, $f2
/* 0F8744 802D3D94 46000106 */  mov.s $f4, $f0
/* 0F8748 802D3D98 46023032 */  c.eq.s $f6, $f2
/* 0F874C 802D3D9C 00000000 */  nop   
/* 0F8750 802D3DA0 45000005 */  bc1f  .L802D3DB8
/* 0F8754 802D3DA4 E6240034 */   swc1  $f4, 0x34($s1)
/* 0F8758 802D3DA8 C620003C */  lwc1  $f0, 0x3c($s1)
/* 0F875C 802D3DAC 46002003 */  div.s $f0, $f4, $f0
/* 0F8760 802D3DB0 080B4F70 */  j     .L802D3DC0
/* 0F8764 802D3DB4 E6200048 */   swc1  $f0, 0x48($s1)

.L802D3DB8:
/* 0F8768 802D3DB8 46062003 */  div.s $f0, $f4, $f6
/* 0F876C 802D3DBC E620003C */  swc1  $f0, 0x3c($s1)
.L802D3DC0:
/* 0F8770 802D3DC0 C6200040 */  lwc1  $f0, 0x40($s1)
/* 0F8774 802D3DC4 C6220048 */  lwc1  $f2, 0x48($s1)
/* 0F8778 802D3DC8 46020002 */  mul.s $f0, $f0, $f2
/* 0F877C 802D3DCC 00000000 */  nop   
/* 0F8780 802D3DD0 3C013F00 */  lui   $at, 0x3f00
/* 0F8784 802D3DD4 44812000 */  mtc1  $at, $f4
/* 0F8788 802D3DD8 00000000 */  nop   
/* 0F878C 802D3DDC 46040002 */  mul.s $f0, $f0, $f4
/* 0F8790 802D3DE0 00000000 */  nop   
/* 0F8794 802D3DE4 4602E083 */  div.s $f2, $f28, $f2
/* 0F8798 802D3DE8 46020000 */  add.s $f0, $f0, $f2
/* 0F879C 802D3DEC 24020001 */  addiu $v0, $zero, 1
/* 0F87A0 802D3DF0 E6200044 */  swc1  $f0, 0x44($s1)
/* 0F87A4 802D3DF4 AE420070 */  sw    $v0, 0x70($s2)
.L802D3DF8:
/* 0F87A8 802D3DF8 8E420074 */  lw    $v0, 0x74($s2)
/* 0F87AC 802D3DFC 3C03802E */  lui   $v1, 0x802e
/* 0F87B0 802D3E00 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F87B4 802D3E04 00021080 */  sll   $v0, $v0, 2
/* 0F87B8 802D3E08 00431021 */  addu  $v0, $v0, $v1
/* 0F87BC 802D3E0C 8C510000 */  lw    $s1, ($v0)
/* 0F87C0 802D3E10 C6240008 */  lwc1  $f4, 8($s1)
/* 0F87C4 802D3E14 C6200044 */  lwc1  $f0, 0x44($s1)
/* 0F87C8 802D3E18 8E25003C */  lw    $a1, 0x3c($s1)
/* 0F87CC 802D3E1C 46002100 */  add.s $f4, $f4, $f0
/* 0F87D0 802D3E20 C6220040 */  lwc1  $f2, 0x40($s1)
/* 0F87D4 802D3E24 8E260038 */  lw    $a2, 0x38($s1)
/* 0F87D8 802D3E28 46020001 */  sub.s $f0, $f0, $f2
/* 0F87DC 802D3E2C 0220202D */  daddu $a0, $s1, $zero
/* 0F87E0 802D3E30 E6240008 */  swc1  $f4, 8($s1)
/* 0F87E4 802D3E34 0C0B4BCD */  jal   func_802D2F34
/* 0F87E8 802D3E38 E6200044 */   swc1  $f0, 0x44($s1)
/* 0F87EC 802D3E3C C6200048 */  lwc1  $f0, 0x48($s1)
/* 0F87F0 802D3E40 3C013F80 */  lui   $at, 0x3f80
/* 0F87F4 802D3E44 44811000 */  mtc1  $at, $f2
/* 0F87F8 802D3E48 00000000 */  nop   
/* 0F87FC 802D3E4C 46020001 */  sub.s $f0, $f0, $f2
/* 0F8800 802D3E50 44801000 */  mtc1  $zero, $f2
/* 0F8804 802D3E54 00000000 */  nop   
/* 0F8808 802D3E58 4602003E */  c.le.s $f0, $f2
/* 0F880C 802D3E5C 00000000 */  nop   
/* 0F8810 802D3E60 45010003 */  bc1t  .L802D3E70
/* 0F8814 802D3E64 E6200048 */   swc1  $f0, 0x48($s1)
/* 0F8818 802D3E68 080B4FA3 */  j     .L802D3E8C
/* 0F881C 802D3E6C 0000102D */   daddu $v0, $zero, $zero

.L802D3E70:
/* 0F8820 802D3E70 C6200028 */  lwc1  $f0, 0x28($s1)
/* 0F8824 802D3E74 C622002C */  lwc1  $f2, 0x2c($s1)
/* 0F8828 802D3E78 C6240030 */  lwc1  $f4, 0x30($s1)
/* 0F882C 802D3E7C 24020001 */  addiu $v0, $zero, 1
/* 0F8830 802D3E80 E6200004 */  swc1  $f0, 4($s1)
/* 0F8834 802D3E84 E6220008 */  swc1  $f2, 8($s1)
/* 0F8838 802D3E88 E624000C */  swc1  $f4, 0xc($s1)
.L802D3E8C:
/* 0F883C 802D3E8C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F8840 802D3E90 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8844 802D3E94 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8848 802D3E98 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F884C 802D3E9C D7BC0040 */  ldc1  $f28, 0x40($sp)
/* 0F8850 802D3EA0 D7BA0038 */  ldc1  $f26, 0x38($sp)
/* 0F8854 802D3EA4 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0F8858 802D3EA8 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F885C 802D3EAC D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F8860 802D3EB0 03E00008 */  jr    $ra
/* 0F8864 802D3EB4 27BD0048 */   addiu $sp, $sp, 0x48

/* 0F8868 802D3EB8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F886C 802D3EBC AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8870 802D3EC0 0080802D */  daddu $s0, $a0, $zero
/* 0F8874 802D3EC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F8878 802D3EC8 8E03000C */  lw    $v1, 0xc($s0)
/* 0F887C 802D3ECC 54A00001 */  bnel  $a1, $zero, .L802D3ED4
/* 0F8880 802D3ED0 AE000070 */   sw    $zero, 0x70($s0)
.L802D3ED4:
/* 0F8884 802D3ED4 8E020070 */  lw    $v0, 0x70($s0)
/* 0F8888 802D3ED8 14400007 */  bnez  $v0, .L802D3EF8
/* 0F888C 802D3EDC 00000000 */   nop   
/* 0F8890 802D3EE0 8C650000 */  lw    $a1, ($v1)
/* 0F8894 802D3EE4 0C0B1EAF */  jal   get_variable
/* 0F8898 802D3EE8 0200202D */   daddu $a0, $s0, $zero
/* 0F889C 802D3EEC AE020074 */  sw    $v0, 0x74($s0)
/* 0F88A0 802D3EF0 24020001 */  addiu $v0, $zero, 1
/* 0F88A4 802D3EF4 AE020070 */  sw    $v0, 0x70($s0)
.L802D3EF8:
/* 0F88A8 802D3EF8 8E020074 */  lw    $v0, 0x74($s0)
/* 0F88AC 802D3EFC 3C03802E */  lui   $v1, 0x802e
/* 0F88B0 802D3F00 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F88B4 802D3F04 00021080 */  sll   $v0, $v0, 2
/* 0F88B8 802D3F08 00431021 */  addu  $v0, $v0, $v1
/* 0F88BC 802D3F0C 8C500000 */  lw    $s0, ($v0)
/* 0F88C0 802D3F10 C6040008 */  lwc1  $f4, 8($s0)
/* 0F88C4 802D3F14 C6000044 */  lwc1  $f0, 0x44($s0)
/* 0F88C8 802D3F18 C6020040 */  lwc1  $f2, 0x40($s0)
/* 0F88CC 802D3F1C 46002100 */  add.s $f4, $f4, $f0
/* 0F88D0 802D3F20 8E05003C */  lw    $a1, 0x3c($s0)
/* 0F88D4 802D3F24 8E060038 */  lw    $a2, 0x38($s0)
/* 0F88D8 802D3F28 46020001 */  sub.s $f0, $f0, $f2
/* 0F88DC 802D3F2C 0200202D */  daddu $a0, $s0, $zero
/* 0F88E0 802D3F30 E6040008 */  swc1  $f4, 8($s0)
/* 0F88E4 802D3F34 0C0B4BCD */  jal   func_802D2F34
/* 0F88E8 802D3F38 E6000044 */   swc1  $f0, 0x44($s0)
/* 0F88EC 802D3F3C C6000008 */  lwc1  $f0, 8($s0)
/* 0F88F0 802D3F40 44801000 */  mtc1  $zero, $f2
/* 0F88F4 802D3F44 00000000 */  nop   
/* 0F88F8 802D3F48 4602003C */  c.lt.s $f0, $f2
/* 0F88FC 802D3F4C 00000000 */  nop   
/* 0F8900 802D3F50 45030003 */  bc1tl .L802D3F60
/* 0F8904 802D3F54 E6020008 */   swc1  $f2, 8($s0)
/* 0F8908 802D3F58 080B4FD9 */  j     .L802D3F64
/* 0F890C 802D3F5C 0000102D */   daddu $v0, $zero, $zero

.L802D3F60:
/* 0F8910 802D3F60 24020001 */  addiu $v0, $zero, 1
.L802D3F64:
/* 0F8914 802D3F64 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F8918 802D3F68 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F891C 802D3F6C 03E00008 */  jr    $ra
/* 0F8920 802D3F70 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F8924 802D3F74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F8928 802D3F78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F892C 802D3F7C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8930 802D3F80 8C90000C */  lw    $s0, 0xc($a0)
/* 0F8934 802D3F84 8E050000 */  lw    $a1, ($s0)
/* 0F8938 802D3F88 0C0B1EAF */  jal   get_variable
/* 0F893C 802D3F8C 26100004 */   addiu $s0, $s0, 4
/* 0F8940 802D3F90 3C03802E */  lui   $v1, 0x802e
/* 0F8944 802D3F94 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F8948 802D3F98 00021080 */  sll   $v0, $v0, 2
/* 0F894C 802D3F9C 00431021 */  addu  $v0, $v0, $v1
/* 0F8950 802D3FA0 8C420000 */  lw    $v0, ($v0)
/* 0F8954 802D3FA4 8C440000 */  lw    $a0, ($v0)
/* 0F8958 802D3FA8 0C048B77 */  jal   func_80122DDC
/* 0F895C 802D3FAC 8E100000 */   lw    $s0, ($s0)
/* 0F8960 802D3FB0 AC500000 */  sw    $s0, ($v0)
/* 0F8964 802D3FB4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F8968 802D3FB8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F896C 802D3FBC 24020002 */  addiu $v0, $zero, 2
/* 0F8970 802D3FC0 03E00008 */  jr    $ra
/* 0F8974 802D3FC4 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F8978 802D3FC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F897C 802D3FCC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8980 802D3FD0 0080882D */  daddu $s1, $a0, $zero
/* 0F8984 802D3FD4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8988 802D3FD8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F898C 802D3FDC 8E30000C */  lw    $s0, 0xc($s1)
/* 0F8990 802D3FE0 8E050000 */  lw    $a1, ($s0)
/* 0F8994 802D3FE4 0C0B1EAF */  jal   get_variable
/* 0F8998 802D3FE8 26100004 */   addiu $s0, $s0, 4
/* 0F899C 802D3FEC 0220202D */  daddu $a0, $s1, $zero
/* 0F89A0 802D3FF0 8E050004 */  lw    $a1, 4($s0)
/* 0F89A4 802D3FF4 8E100000 */  lw    $s0, ($s0)
/* 0F89A8 802D3FF8 0C0B1EAF */  jal   get_variable
/* 0F89AC 802D3FFC 0040882D */   daddu $s1, $v0, $zero
/* 0F89B0 802D4000 3C03802E */  lui   $v1, 0x802e
/* 0F89B4 802D4004 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F89B8 802D4008 00118880 */  sll   $s1, $s1, 2
/* 0F89BC 802D400C 02238821 */  addu  $s1, $s1, $v1
/* 0F89C0 802D4010 10400006 */  beqz  $v0, .L802D402C
/* 0F89C4 802D4014 8E240000 */   lw    $a0, ($s1)
/* 0F89C8 802D4018 8C840000 */  lw    $a0, ($a0)
/* 0F89CC 802D401C 0C048BBA */  jal   func_80122EE8
/* 0F89D0 802D4020 0200282D */   daddu $a1, $s0, $zero
/* 0F89D4 802D4024 080B500E */  j     .L802D4038
/* 0F89D8 802D4028 00000000 */   nop   

.L802D402C:
/* 0F89DC 802D402C 8C840000 */  lw    $a0, ($a0)
/* 0F89E0 802D4030 0C048BC9 */  jal   func_80122F24
/* 0F89E4 802D4034 0200282D */   daddu $a1, $s0, $zero
.L802D4038:
/* 0F89E8 802D4038 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F89EC 802D403C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F89F0 802D4040 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F89F4 802D4044 24020002 */  addiu $v0, $zero, 2
/* 0F89F8 802D4048 03E00008 */  jr    $ra
/* 0F89FC 802D404C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8A00 802D4050 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8A04 802D4054 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8A08 802D4058 0080902D */  daddu $s2, $a0, $zero
/* 0F8A0C 802D405C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8A10 802D4060 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8A14 802D4064 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8A18 802D4068 8E51000C */  lw    $s1, 0xc($s2)
/* 0F8A1C 802D406C 8E250000 */  lw    $a1, ($s1)
/* 0F8A20 802D4070 0C0B1EAF */  jal   get_variable
/* 0F8A24 802D4074 26310004 */   addiu $s1, $s1, 4
/* 0F8A28 802D4078 0240202D */  daddu $a0, $s2, $zero
/* 0F8A2C 802D407C 8E250000 */  lw    $a1, ($s1)
/* 0F8A30 802D4080 0C0B1EAF */  jal   get_variable
/* 0F8A34 802D4084 0040802D */   daddu $s0, $v0, $zero
/* 0F8A38 802D4088 3C03802E */  lui   $v1, 0x802e
/* 0F8A3C 802D408C 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F8A40 802D4090 00108080 */  sll   $s0, $s0, 2
/* 0F8A44 802D4094 02038021 */  addu  $s0, $s0, $v1
/* 0F8A48 802D4098 8E030000 */  lw    $v1, ($s0)
/* 0F8A4C 802D409C 26310004 */  addiu $s1, $s1, 4
/* 0F8A50 802D40A0 8C640000 */  lw    $a0, ($v1)
/* 0F8A54 802D40A4 0C048B77 */  jal   func_80122DDC
/* 0F8A58 802D40A8 0040802D */   daddu $s0, $v0, $zero
/* 0F8A5C 802D40AC 0040182D */  daddu $v1, $v0, $zero
/* 0F8A60 802D40B0 26100001 */  addiu $s0, $s0, 1
/* 0F8A64 802D40B4 2E020006 */  sltiu $v0, $s0, 6
/* 0F8A68 802D40B8 10400023 */  beqz  $v0, .L802D4148
/* 0F8A6C 802D40BC 00101080 */   sll   $v0, $s0, 2
/* 0F8A70 802D40C0 3C01802E */  lui   $at, 0x802e
/* 0F8A74 802D40C4 00220821 */  addu  $at, $at, $v0
/* 0F8A78 802D40C8 8C22A240 */  lw    $v0, -0x5dc0($at)
/* 0F8A7C 802D40CC 00400008 */  jr    $v0
/* 0F8A80 802D40D0 00000000 */   nop   
/* 0F8A84 802D40D4 24020001 */  addiu $v0, $zero, 1
/* 0F8A88 802D40D8 080B5052 */  j     .L802D4148
/* 0F8A8C 802D40DC A0620004 */   sb    $v0, 4($v1)

/* 0F8A90 802D40E0 24020001 */  addiu $v0, $zero, 1
/* 0F8A94 802D40E4 080B5047 */  j     .L802D411C
/* 0F8A98 802D40E8 A0620004 */   sb    $v0, 4($v1)

/* 0F8A9C 802D40EC 2402000D */  addiu $v0, $zero, 0xd
/* 0F8AA0 802D40F0 080B5047 */  j     .L802D411C
/* 0F8AA4 802D40F4 A0620004 */   sb    $v0, 4($v1)

/* 0F8AA8 802D40F8 24020016 */  addiu $v0, $zero, 0x16
/* 0F8AAC 802D40FC 080B504F */  j     .L802D413C
/* 0F8AB0 802D4100 A0620004 */   sb    $v0, 4($v1)

/* 0F8AB4 802D4104 24020016 */  addiu $v0, $zero, 0x16
/* 0F8AB8 802D4108 A0620004 */  sb    $v0, 4($v1)
/* 0F8ABC 802D410C 8E250000 */  lw    $a1, ($s1)
/* 0F8AC0 802D4110 26310004 */  addiu $s1, $s1, 4
/* 0F8AC4 802D4114 0C0B1EAF */  jal   get_variable
/* 0F8AC8 802D4118 0240202D */   daddu $a0, $s2, $zero
.L802D411C:
/* 0F8ACC 802D411C 8E250000 */  lw    $a1, ($s1)
/* 0F8AD0 802D4120 26310004 */  addiu $s1, $s1, 4
/* 0F8AD4 802D4124 0C0B1EAF */  jal   get_variable
/* 0F8AD8 802D4128 0240202D */   daddu $a0, $s2, $zero
/* 0F8ADC 802D412C 8E250000 */  lw    $a1, ($s1)
/* 0F8AE0 802D4130 26310004 */  addiu $s1, $s1, 4
/* 0F8AE4 802D4134 0C0B1EAF */  jal   get_variable
/* 0F8AE8 802D4138 0240202D */   daddu $a0, $s2, $zero
.L802D413C:
/* 0F8AEC 802D413C 8E250000 */  lw    $a1, ($s1)
/* 0F8AF0 802D4140 0C0B1EAF */  jal   get_variable
/* 0F8AF4 802D4144 0240202D */   daddu $a0, $s2, $zero
.L802D4148:
/* 0F8AF8 802D4148 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F8AFC 802D414C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8B00 802D4150 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8B04 802D4154 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8B08 802D4158 24020002 */  addiu $v0, $zero, 2
/* 0F8B0C 802D415C 03E00008 */  jr    $ra
/* 0F8B10 802D4160 27BD0020 */   addiu $sp, $sp, 0x20

