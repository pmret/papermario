.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3C58
/* F8608 802D3C58 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* F860C 802D3C5C AFB20018 */  sw        $s2, 0x18($sp)
/* F8610 802D3C60 0080902D */  daddu     $s2, $a0, $zero
/* F8614 802D3C64 AFBF001C */  sw        $ra, 0x1c($sp)
/* F8618 802D3C68 AFB10014 */  sw        $s1, 0x14($sp)
/* F861C 802D3C6C AFB00010 */  sw        $s0, 0x10($sp)
/* F8620 802D3C70 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* F8624 802D3C74 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* F8628 802D3C78 F7B80030 */  sdc1      $f24, 0x30($sp)
/* F862C 802D3C7C F7B60028 */  sdc1      $f22, 0x28($sp)
/* F8630 802D3C80 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F8634 802D3C84 8E51000C */  lw        $s1, 0xc($s2)
/* F8638 802D3C88 54A00001 */  bnel      $a1, $zero, .L802D3C90
/* F863C 802D3C8C AE400070 */   sw       $zero, 0x70($s2)
.L802D3C90:
/* F8640 802D3C90 8E420070 */  lw        $v0, 0x70($s2)
/* F8644 802D3C94 14400058 */  bnez      $v0, .L802D3DF8
/* F8648 802D3C98 00000000 */   nop      
/* F864C 802D3C9C 8E250000 */  lw        $a1, ($s1)
/* F8650 802D3CA0 26310004 */  addiu     $s1, $s1, 4
/* F8654 802D3CA4 0C0B1EAF */  jal       get_variable
/* F8658 802D3CA8 0240202D */   daddu    $a0, $s2, $zero
/* F865C 802D3CAC 8E250000 */  lw        $a1, ($s1)
/* F8660 802D3CB0 26310004 */  addiu     $s1, $s1, 4
/* F8664 802D3CB4 0240202D */  daddu     $a0, $s2, $zero
/* F8668 802D3CB8 0C0B1EAF */  jal       get_variable
/* F866C 802D3CBC 0040802D */   daddu    $s0, $v0, $zero
/* F8670 802D3CC0 4482D000 */  mtc1      $v0, $f26
/* F8674 802D3CC4 00000000 */  nop       
/* F8678 802D3CC8 4680D6A0 */  cvt.s.w   $f26, $f26
/* F867C 802D3CCC 8E250000 */  lw        $a1, ($s1)
/* F8680 802D3CD0 26310004 */  addiu     $s1, $s1, 4
/* F8684 802D3CD4 0C0B1EAF */  jal       get_variable
/* F8688 802D3CD8 0240202D */   daddu    $a0, $s2, $zero
/* F868C 802D3CDC 4482E000 */  mtc1      $v0, $f28
/* F8690 802D3CE0 00000000 */  nop       
/* F8694 802D3CE4 4680E720 */  cvt.s.w   $f28, $f28
/* F8698 802D3CE8 8E250000 */  lw        $a1, ($s1)
/* F869C 802D3CEC 26310004 */  addiu     $s1, $s1, 4
/* F86A0 802D3CF0 0C0B1EAF */  jal       get_variable
/* F86A4 802D3CF4 0240202D */   daddu    $a0, $s2, $zero
/* F86A8 802D3CF8 4482C000 */  mtc1      $v0, $f24
/* F86AC 802D3CFC 00000000 */  nop       
/* F86B0 802D3D00 4680C620 */  cvt.s.w   $f24, $f24
/* F86B4 802D3D04 8E250000 */  lw        $a1, ($s1)
/* F86B8 802D3D08 0C0B1EAF */  jal       get_variable
/* F86BC 802D3D0C 0240202D */   daddu    $a0, $s2, $zero
/* F86C0 802D3D10 3C04802E */  lui       $a0, 0x802e
/* F86C4 802D3D14 8C84B7C0 */  lw        $a0, -0x4840($a0)
/* F86C8 802D3D18 00101880 */  sll       $v1, $s0, 2
/* F86CC 802D3D1C 00641821 */  addu      $v1, $v1, $a0
/* F86D0 802D3D20 8C710000 */  lw        $s1, ($v1)
/* F86D4 802D3D24 AE500074 */  sw        $s0, 0x74($s2)
/* F86D8 802D3D28 E63A0028 */  swc1      $f26, 0x28($s1)
/* F86DC 802D3D2C C63A0004 */  lwc1      $f26, 4($s1)
/* F86E0 802D3D30 E63C002C */  swc1      $f28, 0x2c($s1)
/* F86E4 802D3D34 C63C0008 */  lwc1      $f28, 8($s1)
/* F86E8 802D3D38 E6380030 */  swc1      $f24, 0x30($s1)
/* F86EC 802D3D3C C638000C */  lwc1      $f24, 0xc($s1)
/* F86F0 802D3D40 C6360028 */  lwc1      $f22, 0x28($s1)
/* F86F4 802D3D44 C6340030 */  lwc1      $f20, 0x30($s1)
/* F86F8 802D3D48 44820000 */  mtc1      $v0, $f0
/* F86FC 802D3D4C 00000000 */  nop       
/* F8700 802D3D50 46800020 */  cvt.s.w   $f0, $f0
/* F8704 802D3D54 E6200048 */  swc1      $f0, 0x48($s1)
/* F8708 802D3D58 C620002C */  lwc1      $f0, 0x2c($s1)
/* F870C 802D3D5C 4600D306 */  mov.s     $f12, $f26
/* F8710 802D3D60 4600C386 */  mov.s     $f14, $f24
/* F8714 802D3D64 4406B000 */  mfc1      $a2, $f22
/* F8718 802D3D68 4407A000 */  mfc1      $a3, $f20
/* F871C 802D3D6C 0C00A720 */  jal       atan2
/* F8720 802D3D70 461C0701 */   sub.s    $f28, $f0, $f28
/* F8724 802D3D74 4600D306 */  mov.s     $f12, $f26
/* F8728 802D3D78 4406B000 */  mfc1      $a2, $f22
/* F872C 802D3D7C 4407A000 */  mfc1      $a3, $f20
/* F8730 802D3D80 4600C386 */  mov.s     $f14, $f24
/* F8734 802D3D84 0C00A7B5 */  jal       dist2D
/* F8738 802D3D88 E6200038 */   swc1     $f0, 0x38($s1)
/* F873C 802D3D8C C6260048 */  lwc1      $f6, 0x48($s1)
/* F8740 802D3D90 44801000 */  mtc1      $zero, $f2
/* F8744 802D3D94 46000106 */  mov.s     $f4, $f0
/* F8748 802D3D98 46023032 */  c.eq.s    $f6, $f2
/* F874C 802D3D9C 00000000 */  nop       
/* F8750 802D3DA0 45000005 */  bc1f      .L802D3DB8
/* F8754 802D3DA4 E6240034 */   swc1     $f4, 0x34($s1)
/* F8758 802D3DA8 C620003C */  lwc1      $f0, 0x3c($s1)
/* F875C 802D3DAC 46002003 */  div.s     $f0, $f4, $f0
/* F8760 802D3DB0 080B4F70 */  j         .L802D3DC0
/* F8764 802D3DB4 E6200048 */   swc1     $f0, 0x48($s1)
.L802D3DB8:
/* F8768 802D3DB8 46062003 */  div.s     $f0, $f4, $f6
/* F876C 802D3DBC E620003C */  swc1      $f0, 0x3c($s1)
.L802D3DC0:
/* F8770 802D3DC0 C6200040 */  lwc1      $f0, 0x40($s1)
/* F8774 802D3DC4 C6220048 */  lwc1      $f2, 0x48($s1)
/* F8778 802D3DC8 46020002 */  mul.s     $f0, $f0, $f2
/* F877C 802D3DCC 00000000 */  nop       
/* F8780 802D3DD0 3C013F00 */  lui       $at, 0x3f00
/* F8784 802D3DD4 44812000 */  mtc1      $at, $f4
/* F8788 802D3DD8 00000000 */  nop       
/* F878C 802D3DDC 46040002 */  mul.s     $f0, $f0, $f4
/* F8790 802D3DE0 00000000 */  nop       
/* F8794 802D3DE4 4602E083 */  div.s     $f2, $f28, $f2
/* F8798 802D3DE8 46020000 */  add.s     $f0, $f0, $f2
/* F879C 802D3DEC 24020001 */  addiu     $v0, $zero, 1
/* F87A0 802D3DF0 E6200044 */  swc1      $f0, 0x44($s1)
/* F87A4 802D3DF4 AE420070 */  sw        $v0, 0x70($s2)
.L802D3DF8:
/* F87A8 802D3DF8 8E420074 */  lw        $v0, 0x74($s2)
/* F87AC 802D3DFC 3C03802E */  lui       $v1, 0x802e
/* F87B0 802D3E00 8C63B7C0 */  lw        $v1, -0x4840($v1)
/* F87B4 802D3E04 00021080 */  sll       $v0, $v0, 2
/* F87B8 802D3E08 00431021 */  addu      $v0, $v0, $v1
/* F87BC 802D3E0C 8C510000 */  lw        $s1, ($v0)
/* F87C0 802D3E10 C6240008 */  lwc1      $f4, 8($s1)
/* F87C4 802D3E14 C6200044 */  lwc1      $f0, 0x44($s1)
/* F87C8 802D3E18 8E25003C */  lw        $a1, 0x3c($s1)
/* F87CC 802D3E1C 46002100 */  add.s     $f4, $f4, $f0
/* F87D0 802D3E20 C6220040 */  lwc1      $f2, 0x40($s1)
/* F87D4 802D3E24 8E260038 */  lw        $a2, 0x38($s1)
/* F87D8 802D3E28 46020001 */  sub.s     $f0, $f0, $f2
/* F87DC 802D3E2C 0220202D */  daddu     $a0, $s1, $zero
/* F87E0 802D3E30 E6240008 */  swc1      $f4, 8($s1)
/* F87E4 802D3E34 0C0B4BCD */  jal       func_802D2F34
/* F87E8 802D3E38 E6200044 */   swc1     $f0, 0x44($s1)
/* F87EC 802D3E3C C6200048 */  lwc1      $f0, 0x48($s1)
/* F87F0 802D3E40 3C013F80 */  lui       $at, 0x3f80
/* F87F4 802D3E44 44811000 */  mtc1      $at, $f2
/* F87F8 802D3E48 00000000 */  nop       
/* F87FC 802D3E4C 46020001 */  sub.s     $f0, $f0, $f2
/* F8800 802D3E50 44801000 */  mtc1      $zero, $f2
/* F8804 802D3E54 00000000 */  nop       
/* F8808 802D3E58 4602003E */  c.le.s    $f0, $f2
/* F880C 802D3E5C 00000000 */  nop       
/* F8810 802D3E60 45010003 */  bc1t      .L802D3E70
/* F8814 802D3E64 E6200048 */   swc1     $f0, 0x48($s1)
/* F8818 802D3E68 080B4FA3 */  j         .L802D3E8C
/* F881C 802D3E6C 0000102D */   daddu    $v0, $zero, $zero
.L802D3E70:
/* F8820 802D3E70 C6200028 */  lwc1      $f0, 0x28($s1)
/* F8824 802D3E74 C622002C */  lwc1      $f2, 0x2c($s1)
/* F8828 802D3E78 C6240030 */  lwc1      $f4, 0x30($s1)
/* F882C 802D3E7C 24020001 */  addiu     $v0, $zero, 1
/* F8830 802D3E80 E6200004 */  swc1      $f0, 4($s1)
/* F8834 802D3E84 E6220008 */  swc1      $f2, 8($s1)
/* F8838 802D3E88 E624000C */  swc1      $f4, 0xc($s1)
.L802D3E8C:
/* F883C 802D3E8C 8FBF001C */  lw        $ra, 0x1c($sp)
/* F8840 802D3E90 8FB20018 */  lw        $s2, 0x18($sp)
/* F8844 802D3E94 8FB10014 */  lw        $s1, 0x14($sp)
/* F8848 802D3E98 8FB00010 */  lw        $s0, 0x10($sp)
/* F884C 802D3E9C D7BC0040 */  ldc1      $f28, 0x40($sp)
/* F8850 802D3EA0 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* F8854 802D3EA4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* F8858 802D3EA8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F885C 802D3EAC D7B40020 */  ldc1      $f20, 0x20($sp)
/* F8860 802D3EB0 03E00008 */  jr        $ra
/* F8864 802D3EB4 27BD0048 */   addiu    $sp, $sp, 0x48
