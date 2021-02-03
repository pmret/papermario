.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D0_BC4B50
/* BC4B50 802408D0 27BDFF70 */  addiu     $sp, $sp, -0x90
/* BC4B54 802408D4 AFB20070 */  sw        $s2, 0x70($sp)
/* BC4B58 802408D8 AFB30074 */  sw        $s3, 0x74($sp)
/* BC4B5C 802408DC 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* BC4B60 802408E0 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* BC4B64 802408E4 AFB00068 */  sw        $s0, 0x68($sp)
/* BC4B68 802408E8 3C108016 */  lui       $s0, %hi(gCollisionStatus)
/* BC4B6C 802408EC 2610A550 */  addiu     $s0, $s0, %lo(gCollisionStatus)
/* BC4B70 802408F0 AFBF0078 */  sw        $ra, 0x78($sp)
/* BC4B74 802408F4 AFB1006C */  sw        $s1, 0x6c($sp)
/* BC4B78 802408F8 F7B60088 */  sdc1      $f22, 0x88($sp)
/* BC4B7C 802408FC F7B40080 */  sdc1      $f20, 0x80($sp)
/* BC4B80 80240900 10A00014 */  beqz      $a1, .L80240954
/* BC4B84 80240904 0080902D */   daddu    $s2, $a0, $zero
/* BC4B88 80240908 0C00AB39 */  jal       heap_malloc
/* BC4B8C 8024090C 24040020 */   addiu    $a0, $zero, 0x20
/* BC4B90 80240910 3C013DCC */  lui       $at, 0x3dcc
/* BC4B94 80240914 3421CCCD */  ori       $at, $at, 0xcccd
/* BC4B98 80240918 44810000 */  mtc1      $at, $f0
/* BC4B9C 8024091C 3C014040 */  lui       $at, 0x4040
/* BC4BA0 80240920 44811000 */  mtc1      $at, $f2
/* BC4BA4 80240924 0040882D */  daddu     $s1, $v0, $zero
/* BC4BA8 80240928 AE510074 */  sw        $s1, 0x74($s2)
/* BC4BAC 8024092C AE200000 */  sw        $zero, ($s1)
/* BC4BB0 80240930 AE20000C */  sw        $zero, 0xc($s1)
/* BC4BB4 80240934 AE200008 */  sw        $zero, 8($s1)
/* BC4BB8 80240938 AE200010 */  sw        $zero, 0x10($s1)
/* BC4BBC 8024093C AE200014 */  sw        $zero, 0x14($s1)
/* BC4BC0 80240940 E6200004 */  swc1      $f0, 4($s1)
/* BC4BC4 80240944 E6220018 */  swc1      $f2, 0x18($s1)
/* BC4BC8 80240948 AE400070 */  sw        $zero, 0x70($s2)
/* BC4BCC 8024094C AE400078 */  sw        $zero, 0x78($s2)
/* BC4BD0 80240950 AE40007C */  sw        $zero, 0x7c($s2)
.L80240954:
/* BC4BD4 80240954 24040001 */  addiu     $a0, $zero, 1
/* BC4BD8 80240958 8E430070 */  lw        $v1, 0x70($s2)
/* BC4BDC 8024095C 8E510074 */  lw        $s1, 0x74($s2)
/* BC4BE0 80240960 10640022 */  beq       $v1, $a0, .L802409EC
/* BC4BE4 80240964 28620002 */   slti     $v0, $v1, 2
/* BC4BE8 80240968 50400005 */  beql      $v0, $zero, .L80240980
/* BC4BEC 8024096C 24020002 */   addiu    $v0, $zero, 2
/* BC4BF0 80240970 10600007 */  beqz      $v1, .L80240990
/* BC4BF4 80240974 2402003C */   addiu    $v0, $zero, 0x3c
/* BC4BF8 80240978 0809037C */  j         .L80240DF0
/* BC4BFC 8024097C 00000000 */   nop
.L80240980:
/* BC4C00 80240980 106200BF */  beq       $v1, $v0, .L80240C80
/* BC4C04 80240984 2402003C */   addiu    $v0, $zero, 0x3c
/* BC4C08 80240988 0809037C */  j         .L80240DF0
/* BC4C0C 8024098C 00000000 */   nop
.L80240990:
/* BC4C10 80240990 86030002 */  lh        $v1, 2($s0)
/* BC4C14 80240994 50620001 */  beql      $v1, $v0, .L8024099C
/* BC4C18 80240998 AE440070 */   sw       $a0, 0x70($s2)
.L8024099C:
/* BC4C1C 8024099C 86030002 */  lh        $v1, 2($s0)
/* BC4C20 802409A0 2402003B */  addiu     $v0, $zero, 0x3b
/* BC4C24 802409A4 50620001 */  beql      $v1, $v0, .L802409AC
/* BC4C28 802409A8 AE440070 */   sw       $a0, 0x70($s2)
.L802409AC:
/* BC4C2C 802409AC 3C013DCC */  lui       $at, 0x3dcc
/* BC4C30 802409B0 3421CCCD */  ori       $at, $at, 0xcccd
/* BC4C34 802409B4 44810000 */  mtc1      $at, $f0
/* BC4C38 802409B8 3C014040 */  lui       $at, 0x4040
/* BC4C3C 802409BC 44811000 */  mtc1      $at, $f2
/* BC4C40 802409C0 3C0141A0 */  lui       $at, 0x41a0
/* BC4C44 802409C4 44812000 */  mtc1      $at, $f4
/* BC4C48 802409C8 AE200000 */  sw        $zero, ($s1)
/* BC4C4C 802409CC AE20000C */  sw        $zero, 0xc($s1)
/* BC4C50 802409D0 AE200010 */  sw        $zero, 0x10($s1)
/* BC4C54 802409D4 AE200014 */  sw        $zero, 0x14($s1)
/* BC4C58 802409D8 AE200008 */  sw        $zero, 8($s1)
/* BC4C5C 802409DC E6200004 */  swc1      $f0, 4($s1)
/* BC4C60 802409E0 E6220018 */  swc1      $f2, 0x18($s1)
/* BC4C64 802409E4 0809037C */  j         .L80240DF0
/* BC4C68 802409E8 E624001C */   swc1     $f4, 0x1c($s1)
.L802409EC:
/* BC4C6C 802409EC 86030002 */  lh        $v1, 2($s0)
/* BC4C70 802409F0 2402003C */  addiu     $v0, $zero, 0x3c
/* BC4C74 802409F4 10620006 */  beq       $v1, $v0, .L80240A10
/* BC4C78 802409F8 2402003B */   addiu    $v0, $zero, 0x3b
/* BC4C7C 802409FC 10620004 */  beq       $v1, $v0, .L80240A10
/* BC4C80 80240A00 24020078 */   addiu    $v0, $zero, 0x78
/* BC4C84 80240A04 AE42007C */  sw        $v0, 0x7c($s2)
/* BC4C88 80240A08 24020002 */  addiu     $v0, $zero, 2
/* BC4C8C 80240A0C AE420070 */  sw        $v0, 0x70($s2)
.L80240A10:
/* BC4C90 80240A10 C6200008 */  lwc1      $f0, 8($s1)
/* BC4C94 80240A14 3C0140A0 */  lui       $at, 0x40a0
/* BC4C98 80240A18 44811000 */  mtc1      $at, $f2
/* BC4C9C 80240A1C 46000005 */  abs.s     $f0, $f0
/* BC4CA0 80240A20 4602003C */  c.lt.s    $f0, $f2
/* BC4CA4 80240A24 00000000 */  nop
/* BC4CA8 80240A28 4500000D */  bc1f      .L80240A60
/* BC4CAC 80240A2C 00000000 */   nop
/* BC4CB0 80240A30 C6600028 */  lwc1      $f0, 0x28($s3)
/* BC4CB4 80240A34 3C018024 */  lui       $at, %hi(D_80243BD0_BC7E50)
/* BC4CB8 80240A38 D4223BD0 */  ldc1      $f2, %lo(D_80243BD0_BC7E50)($at)
/* BC4CBC 80240A3C 46000021 */  cvt.d.s   $f0, $f0
/* BC4CC0 80240A40 46201081 */  sub.d     $f2, $f2, $f0
/* BC4CC4 80240A44 3C014348 */  lui       $at, 0x4348
/* BC4CC8 80240A48 44810000 */  mtc1      $at, $f0
/* BC4CCC 80240A4C 462010A0 */  cvt.s.d   $f2, $f2
/* BC4CD0 80240A50 46001085 */  abs.s     $f2, $f2
/* BC4CD4 80240A54 46001083 */  div.s     $f2, $f2, $f0
/* BC4CD8 80240A58 0809029D */  j         .L80240A74
/* BC4CDC 80240A5C E6220004 */   swc1     $f2, 4($s1)
.L80240A60:
/* BC4CE0 80240A60 3C013DCC */  lui       $at, 0x3dcc
/* BC4CE4 80240A64 3421CCCD */  ori       $at, $at, 0xcccd
/* BC4CE8 80240A68 44810000 */  mtc1      $at, $f0
/* BC4CEC 80240A6C 00000000 */  nop
/* BC4CF0 80240A70 E6200004 */  swc1      $f0, 4($s1)
.L80240A74:
/* BC4CF4 80240A74 C6600028 */  lwc1      $f0, 0x28($s3)
/* BC4CF8 80240A78 3C018024 */  lui       $at, %hi(D_80243BD8_BC7E58)
/* BC4CFC 80240A7C D4243BD8 */  ldc1      $f4, %lo(D_80243BD8_BC7E58)($at)
/* BC4D00 80240A80 46000021 */  cvt.d.s   $f0, $f0
/* BC4D04 80240A84 4624003E */  c.le.d    $f0, $f4
/* BC4D08 80240A88 00000000 */  nop
/* BC4D0C 80240A8C 45000024 */  bc1f      .L80240B20
/* BC4D10 80240A90 00000000 */   nop
/* BC4D14 80240A94 C6200010 */  lwc1      $f0, 0x10($s1)
/* BC4D18 80240A98 C6220004 */  lwc1      $f2, 4($s1)
/* BC4D1C 80240A9C 46020000 */  add.s     $f0, $f0, $f2
/* BC4D20 80240AA0 E6200010 */  swc1      $f0, 0x10($s1)
/* BC4D24 80240AA4 C6600028 */  lwc1      $f0, 0x28($s3)
/* BC4D28 80240AA8 46000021 */  cvt.d.s   $f0, $f0
/* BC4D2C 80240AAC 46202001 */  sub.d     $f0, $f4, $f0
/* BC4D30 80240AB0 46200020 */  cvt.s.d   $f0, $f0
/* BC4D34 80240AB4 46000005 */  abs.s     $f0, $f0
/* BC4D38 80240AB8 46000002 */  mul.s     $f0, $f0, $f0
/* BC4D3C 80240ABC 00000000 */  nop
/* BC4D40 80240AC0 3C014248 */  lui       $at, 0x4248
/* BC4D44 80240AC4 44811000 */  mtc1      $at, $f2
/* BC4D48 80240AC8 3C014170 */  lui       $at, 0x4170
/* BC4D4C 80240ACC 44812000 */  mtc1      $at, $f4
/* BC4D50 80240AD0 46020003 */  div.s     $f0, $f0, $f2
/* BC4D54 80240AD4 4600203C */  c.lt.s    $f4, $f0
/* BC4D58 80240AD8 00000000 */  nop
/* BC4D5C 80240ADC 45000002 */  bc1f      .L80240AE8
/* BC4D60 80240AE0 E620001C */   swc1     $f0, 0x1c($s1)
/* BC4D64 80240AE4 E624001C */  swc1      $f4, 0x1c($s1)
.L80240AE8:
/* BC4D68 80240AE8 C6220008 */  lwc1      $f2, 8($s1)
/* BC4D6C 80240AEC C620001C */  lwc1      $f0, 0x1c($s1)
/* BC4D70 80240AF0 4602003C */  c.lt.s    $f0, $f2
/* BC4D74 80240AF4 00000000 */  nop
/* BC4D78 80240AF8 45000031 */  bc1f      .L80240BC0
/* BC4D7C 80240AFC 00000000 */   nop
/* BC4D80 80240B00 C6200004 */  lwc1      $f0, 4($s1)
/* BC4D84 80240B04 C6220018 */  lwc1      $f2, 0x18($s1)
/* BC4D88 80240B08 46020002 */  mul.s     $f0, $f0, $f2
/* BC4D8C 80240B0C 00000000 */  nop
/* BC4D90 80240B10 C6220014 */  lwc1      $f2, 0x14($s1)
/* BC4D94 80240B14 46001080 */  add.s     $f2, $f2, $f0
/* BC4D98 80240B18 080902F0 */  j         .L80240BC0
/* BC4D9C 80240B1C E6220014 */   swc1     $f2, 0x14($s1)
.L80240B20:
/* BC4DA0 80240B20 C6200014 */  lwc1      $f0, 0x14($s1)
/* BC4DA4 80240B24 C6220004 */  lwc1      $f2, 4($s1)
/* BC4DA8 80240B28 46020000 */  add.s     $f0, $f0, $f2
/* BC4DAC 80240B2C E6200014 */  swc1      $f0, 0x14($s1)
/* BC4DB0 80240B30 C6600028 */  lwc1      $f0, 0x28($s3)
/* BC4DB4 80240B34 46000021 */  cvt.d.s   $f0, $f0
/* BC4DB8 80240B38 46202001 */  sub.d     $f0, $f4, $f0
/* BC4DBC 80240B3C 3C013F00 */  lui       $at, 0x3f00
/* BC4DC0 80240B40 44811000 */  mtc1      $at, $f2
/* BC4DC4 80240B44 46200020 */  cvt.s.d   $f0, $f0
/* BC4DC8 80240B48 46000005 */  abs.s     $f0, $f0
/* BC4DCC 80240B4C 46000007 */  neg.s     $f0, $f0
/* BC4DD0 80240B50 46020002 */  mul.s     $f0, $f0, $f2
/* BC4DD4 80240B54 00000000 */  nop
/* BC4DD8 80240B58 46000002 */  mul.s     $f0, $f0, $f0
/* BC4DDC 80240B5C 00000000 */  nop
/* BC4DE0 80240B60 3C01C0A0 */  lui       $at, 0xc0a0
/* BC4DE4 80240B64 44812000 */  mtc1      $at, $f4
/* BC4DE8 80240B68 3C014248 */  lui       $at, 0x4248
/* BC4DEC 80240B6C 44811000 */  mtc1      $at, $f2
/* BC4DF0 80240B70 46000007 */  neg.s     $f0, $f0
/* BC4DF4 80240B74 46020003 */  div.s     $f0, $f0, $f2
/* BC4DF8 80240B78 4604003C */  c.lt.s    $f0, $f4
/* BC4DFC 80240B7C 00000000 */  nop
/* BC4E00 80240B80 45000002 */  bc1f      .L80240B8C
/* BC4E04 80240B84 E620001C */   swc1     $f0, 0x1c($s1)
/* BC4E08 80240B88 E624001C */  swc1      $f4, 0x1c($s1)
.L80240B8C:
/* BC4E0C 80240B8C C6220008 */  lwc1      $f2, 8($s1)
/* BC4E10 80240B90 C620001C */  lwc1      $f0, 0x1c($s1)
/* BC4E14 80240B94 4600103C */  c.lt.s    $f2, $f0
/* BC4E18 80240B98 00000000 */  nop
/* BC4E1C 80240B9C 45000008 */  bc1f      .L80240BC0
/* BC4E20 80240BA0 00000000 */   nop
/* BC4E24 80240BA4 C6200004 */  lwc1      $f0, 4($s1)
/* BC4E28 80240BA8 C6220018 */  lwc1      $f2, 0x18($s1)
/* BC4E2C 80240BAC 46020002 */  mul.s     $f0, $f0, $f2
/* BC4E30 80240BB0 00000000 */  nop
/* BC4E34 80240BB4 C6220010 */  lwc1      $f2, 0x10($s1)
/* BC4E38 80240BB8 46001080 */  add.s     $f2, $f2, $f0
/* BC4E3C 80240BBC E6220010 */  swc1      $f2, 0x10($s1)
.L80240BC0:
/* BC4E40 80240BC0 C6200010 */  lwc1      $f0, 0x10($s1)
/* BC4E44 80240BC4 3C014059 */  lui       $at, 0x4059
/* BC4E48 80240BC8 44812800 */  mtc1      $at, $f5
/* BC4E4C 80240BCC 44802000 */  mtc1      $zero, $f4
/* BC4E50 80240BD0 460000A1 */  cvt.d.s   $f2, $f0
/* BC4E54 80240BD4 4622203C */  c.lt.d    $f4, $f2
/* BC4E58 80240BD8 00000000 */  nop
/* BC4E5C 80240BDC 4500000F */  bc1f      .L80240C1C
/* BC4E60 80240BE0 00000000 */   nop
/* BC4E64 80240BE4 C6200014 */  lwc1      $f0, 0x14($s1)
/* BC4E68 80240BE8 46000021 */  cvt.d.s   $f0, $f0
/* BC4E6C 80240BEC 4620203C */  c.lt.d    $f4, $f0
/* BC4E70 80240BF0 00000000 */  nop
/* BC4E74 80240BF4 45000009 */  bc1f      .L80240C1C
/* BC4E78 80240BF8 00000000 */   nop
/* BC4E7C 80240BFC C6200014 */  lwc1      $f0, 0x14($s1)
/* BC4E80 80240C00 46241081 */  sub.d     $f2, $f2, $f4
/* BC4E84 80240C04 46000021 */  cvt.d.s   $f0, $f0
/* BC4E88 80240C08 46240001 */  sub.d     $f0, $f0, $f4
/* BC4E8C 80240C0C 462010A0 */  cvt.s.d   $f2, $f2
/* BC4E90 80240C10 E6220010 */  swc1      $f2, 0x10($s1)
/* BC4E94 80240C14 46200020 */  cvt.s.d   $f0, $f0
/* BC4E98 80240C18 E6200014 */  swc1      $f0, 0x14($s1)
.L80240C1C:
/* BC4E9C 80240C1C C6240010 */  lwc1      $f4, 0x10($s1)
/* BC4EA0 80240C20 C6220014 */  lwc1      $f2, 0x14($s1)
/* BC4EA4 80240C24 46022001 */  sub.s     $f0, $f4, $f2
/* BC4EA8 80240C28 3C013FF8 */  lui       $at, 0x3ff8
/* BC4EAC 80240C2C 44813800 */  mtc1      $at, $f7
/* BC4EB0 80240C30 44803000 */  mtc1      $zero, $f6
/* BC4EB4 80240C34 46000005 */  abs.s     $f0, $f0
/* BC4EB8 80240C38 46000021 */  cvt.d.s   $f0, $f0
/* BC4EBC 80240C3C 4620303C */  c.lt.d    $f6, $f0
/* BC4EC0 80240C40 00000000 */  nop
/* BC4EC4 80240C44 45000063 */  bc1f      .L80240DD4
/* BC4EC8 80240C48 00000000 */   nop
/* BC4ECC 80240C4C 4602203C */  c.lt.s    $f4, $f2
/* BC4ED0 80240C50 00000000 */  nop
/* BC4ED4 80240C54 45020006 */  bc1fl     .L80240C70
/* BC4ED8 80240C58 46001021 */   cvt.d.s  $f0, $f2
/* BC4EDC 80240C5C 46002021 */  cvt.d.s   $f0, $f4
/* BC4EE0 80240C60 46260000 */  add.d     $f0, $f0, $f6
/* BC4EE4 80240C64 46200020 */  cvt.s.d   $f0, $f0
/* BC4EE8 80240C68 08090375 */  j         .L80240DD4
/* BC4EEC 80240C6C E6200014 */   swc1     $f0, 0x14($s1)
.L80240C70:
/* BC4EF0 80240C70 46260000 */  add.d     $f0, $f0, $f6
/* BC4EF4 80240C74 46200020 */  cvt.s.d   $f0, $f0
/* BC4EF8 80240C78 08090375 */  j         .L80240DD4
/* BC4EFC 80240C7C E6200010 */   swc1     $f0, 0x10($s1)
.L80240C80:
/* BC4F00 80240C80 86030002 */  lh        $v1, 2($s0)
/* BC4F04 80240C84 50620001 */  beql      $v1, $v0, .L80240C8C
/* BC4F08 80240C88 AE440070 */   sw       $a0, 0x70($s2)
.L80240C8C:
/* BC4F0C 80240C8C 86030002 */  lh        $v1, 2($s0)
/* BC4F10 80240C90 2402003B */  addiu     $v0, $zero, 0x3b
/* BC4F14 80240C94 50620001 */  beql      $v1, $v0, .L80240C9C
/* BC4F18 80240C98 AE440070 */   sw       $a0, 0x70($s2)
.L80240C9C:
/* BC4F1C 80240C9C 3C013DCC */  lui       $at, 0x3dcc
/* BC4F20 80240CA0 3421CCCD */  ori       $at, $at, 0xcccd
/* BC4F24 80240CA4 44810000 */  mtc1      $at, $f0
/* BC4F28 80240CA8 C6220010 */  lwc1      $f2, 0x10($s1)
/* BC4F2C 80240CAC C6240008 */  lwc1      $f4, 8($s1)
/* BC4F30 80240CB0 AE20001C */  sw        $zero, 0x1c($s1)
/* BC4F34 80240CB4 46001080 */  add.s     $f2, $f2, $f0
/* BC4F38 80240CB8 E6200004 */  swc1      $f0, 4($s1)
/* BC4F3C 80240CBC C620001C */  lwc1      $f0, 0x1c($s1)
/* BC4F40 80240CC0 4604003C */  c.lt.s    $f0, $f4
/* BC4F44 80240CC4 00000000 */  nop
/* BC4F48 80240CC8 45000008 */  bc1f      .L80240CEC
/* BC4F4C 80240CCC E6220010 */   swc1     $f2, 0x10($s1)
/* BC4F50 80240CD0 C6200004 */  lwc1      $f0, 4($s1)
/* BC4F54 80240CD4 C6220018 */  lwc1      $f2, 0x18($s1)
/* BC4F58 80240CD8 46020002 */  mul.s     $f0, $f0, $f2
/* BC4F5C 80240CDC 00000000 */  nop
/* BC4F60 80240CE0 C6220014 */  lwc1      $f2, 0x14($s1)
/* BC4F64 80240CE4 46001080 */  add.s     $f2, $f2, $f0
/* BC4F68 80240CE8 E6220014 */  swc1      $f2, 0x14($s1)
.L80240CEC:
/* BC4F6C 80240CEC C6200010 */  lwc1      $f0, 0x10($s1)
/* BC4F70 80240CF0 3C014059 */  lui       $at, 0x4059
/* BC4F74 80240CF4 44812800 */  mtc1      $at, $f5
/* BC4F78 80240CF8 44802000 */  mtc1      $zero, $f4
/* BC4F7C 80240CFC 460000A1 */  cvt.d.s   $f2, $f0
/* BC4F80 80240D00 4622203C */  c.lt.d    $f4, $f2
/* BC4F84 80240D04 00000000 */  nop
/* BC4F88 80240D08 4500000F */  bc1f      .L80240D48
/* BC4F8C 80240D0C 00000000 */   nop
/* BC4F90 80240D10 C6200014 */  lwc1      $f0, 0x14($s1)
/* BC4F94 80240D14 46000021 */  cvt.d.s   $f0, $f0
/* BC4F98 80240D18 4620203C */  c.lt.d    $f4, $f0
/* BC4F9C 80240D1C 00000000 */  nop
/* BC4FA0 80240D20 45000009 */  bc1f      .L80240D48
/* BC4FA4 80240D24 00000000 */   nop
/* BC4FA8 80240D28 C6200014 */  lwc1      $f0, 0x14($s1)
/* BC4FAC 80240D2C 46241081 */  sub.d     $f2, $f2, $f4
/* BC4FB0 80240D30 46000021 */  cvt.d.s   $f0, $f0
/* BC4FB4 80240D34 46240001 */  sub.d     $f0, $f0, $f4
/* BC4FB8 80240D38 462010A0 */  cvt.s.d   $f2, $f2
/* BC4FBC 80240D3C E6220010 */  swc1      $f2, 0x10($s1)
/* BC4FC0 80240D40 46200020 */  cvt.s.d   $f0, $f0
/* BC4FC4 80240D44 E6200014 */  swc1      $f0, 0x14($s1)
.L80240D48:
/* BC4FC8 80240D48 C6240010 */  lwc1      $f4, 0x10($s1)
/* BC4FCC 80240D4C C6220014 */  lwc1      $f2, 0x14($s1)
/* BC4FD0 80240D50 46022001 */  sub.s     $f0, $f4, $f2
/* BC4FD4 80240D54 3C013FE0 */  lui       $at, 0x3fe0
/* BC4FD8 80240D58 44813800 */  mtc1      $at, $f7
/* BC4FDC 80240D5C 44803000 */  mtc1      $zero, $f6
/* BC4FE0 80240D60 46000005 */  abs.s     $f0, $f0
/* BC4FE4 80240D64 46000021 */  cvt.d.s   $f0, $f0
/* BC4FE8 80240D68 4620303C */  c.lt.d    $f6, $f0
/* BC4FEC 80240D6C 00000000 */  nop
/* BC4FF0 80240D70 4500000D */  bc1f      .L80240DA8
/* BC4FF4 80240D74 00000000 */   nop
/* BC4FF8 80240D78 4602203C */  c.lt.s    $f4, $f2
/* BC4FFC 80240D7C 00000000 */  nop
/* BC5000 80240D80 45020006 */  bc1fl     .L80240D9C
/* BC5004 80240D84 46001021 */   cvt.d.s  $f0, $f2
/* BC5008 80240D88 46002021 */  cvt.d.s   $f0, $f4
/* BC500C 80240D8C 46260000 */  add.d     $f0, $f0, $f6
/* BC5010 80240D90 46200020 */  cvt.s.d   $f0, $f0
/* BC5014 80240D94 0809036A */  j         .L80240DA8
/* BC5018 80240D98 E6200014 */   swc1     $f0, 0x14($s1)
.L80240D9C:
/* BC501C 80240D9C 46260000 */  add.d     $f0, $f0, $f6
/* BC5020 80240DA0 46200020 */  cvt.s.d   $f0, $f0
/* BC5024 80240DA4 E6200010 */  swc1      $f0, 0x10($s1)
.L80240DA8:
/* BC5028 80240DA8 8E42007C */  lw        $v0, 0x7c($s2)
/* BC502C 80240DAC 04410008 */  bgez      $v0, .L80240DD0
/* BC5030 80240DB0 2442FFFF */   addiu    $v0, $v0, -1
/* BC5034 80240DB4 44800000 */  mtc1      $zero, $f0
/* BC5038 80240DB8 00000000 */  nop
/* BC503C 80240DBC E6200014 */  swc1      $f0, 0x14($s1)
/* BC5040 80240DC0 E6200010 */  swc1      $f0, 0x10($s1)
/* BC5044 80240DC4 E6200000 */  swc1      $f0, ($s1)
/* BC5048 80240DC8 08090375 */  j         .L80240DD4
/* BC504C 80240DCC E6200008 */   swc1     $f0, 8($s1)
.L80240DD0:
/* BC5050 80240DD0 AE42007C */  sw        $v0, 0x7c($s2)
.L80240DD4:
/* BC5054 80240DD4 C6200010 */  lwc1      $f0, 0x10($s1)
/* BC5058 80240DD8 C6220014 */  lwc1      $f2, 0x14($s1)
/* BC505C 80240DDC 46020001 */  sub.s     $f0, $f0, $f2
/* BC5060 80240DE0 C6220008 */  lwc1      $f2, 8($s1)
/* BC5064 80240DE4 46001080 */  add.s     $f2, $f2, $f0
/* BC5068 80240DE8 E6200000 */  swc1      $f0, ($s1)
/* BC506C 80240DEC E6220008 */  swc1      $f2, 8($s1)
.L80240DF0:
/* BC5070 80240DF0 C6220008 */  lwc1      $f2, 8($s1)
/* BC5074 80240DF4 3C01C0E0 */  lui       $at, 0xc0e0
/* BC5078 80240DF8 44810000 */  mtc1      $at, $f0
/* BC507C 80240DFC 00000000 */  nop
/* BC5080 80240E00 4600103E */  c.le.s    $f2, $f0
/* BC5084 80240E04 00000000 */  nop
/* BC5088 80240E08 45000013 */  bc1f      .L80240E58
/* BC508C 80240E0C 2410FFFF */   addiu    $s0, $zero, -1
/* BC5090 80240E10 8E420078 */  lw        $v0, 0x78($s2)
/* BC5094 80240E14 10500011 */  beq       $v0, $s0, .L80240E5C
/* BC5098 80240E18 27A50058 */   addiu    $a1, $sp, 0x58
/* BC509C 80240E1C 2404003C */  addiu     $a0, $zero, 0x3c
/* BC50A0 80240E20 27A6005C */  addiu     $a2, $sp, 0x5c
/* BC50A4 80240E24 0C016F84 */  jal       get_collider_center
/* BC50A8 80240E28 27A70060 */   addiu    $a3, $sp, 0x60
/* BC50AC 80240E2C 240401D6 */  addiu     $a0, $zero, 0x1d6
/* BC50B0 80240E30 C7A00058 */  lwc1      $f0, 0x58($sp)
/* BC50B4 80240E34 C7A2005C */  lwc1      $f2, 0x5c($sp)
/* BC50B8 80240E38 44060000 */  mfc1      $a2, $f0
/* BC50BC 80240E3C 44071000 */  mfc1      $a3, $f2
/* BC50C0 80240E40 C7A00060 */  lwc1      $f0, 0x60($sp)
/* BC50C4 80240E44 0000282D */  daddu     $a1, $zero, $zero
/* BC50C8 80240E48 0C052757 */  jal       play_sound_at_position
/* BC50CC 80240E4C E7A00010 */   swc1     $f0, 0x10($sp)
/* BC50D0 80240E50 08090397 */  j         .L80240E5C
/* BC50D4 80240E54 AE500078 */   sw       $s0, 0x78($s2)
.L80240E58:
/* BC50D8 80240E58 AE400078 */  sw        $zero, 0x78($s2)
.L80240E5C:
/* BC50DC 80240E5C C6200008 */  lwc1      $f0, 8($s1)
/* BC50E0 80240E60 46000002 */  mul.s     $f0, $f0, $f0
/* BC50E4 80240E64 00000000 */  nop
/* BC50E8 80240E68 3C0142B4 */  lui       $at, 0x42b4
/* BC50EC 80240E6C 44811000 */  mtc1      $at, $f2
/* BC50F0 80240E70 24040081 */  addiu     $a0, $zero, 0x81
/* BC50F4 80240E74 46020003 */  div.s     $f0, $f0, $f2
/* BC50F8 80240E78 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BC50FC 80240E7C E620000C */   swc1     $f0, 0xc($s1)
/* BC5100 80240E80 0C046B4C */  jal       get_model_from_list_index
/* BC5104 80240E84 0040202D */   daddu    $a0, $v0, $zero
/* BC5108 80240E88 0040182D */  daddu     $v1, $v0, $zero
/* BC510C 80240E8C 24700058 */  addiu     $s0, $v1, 0x58
/* BC5110 80240E90 4480A000 */  mtc1      $zero, $f20
/* BC5114 80240E94 94620000 */  lhu       $v0, ($v1)
/* BC5118 80240E98 4405A000 */  mfc1      $a1, $f20
/* BC511C 80240E9C 4407A000 */  mfc1      $a3, $f20
/* BC5120 80240EA0 34421400 */  ori       $v0, $v0, 0x1400
/* BC5124 80240EA4 A4620000 */  sh        $v0, ($v1)
/* BC5128 80240EA8 8E26000C */  lw        $a2, 0xc($s1)
/* BC512C 80240EAC 3C013F80 */  lui       $at, 0x3f80
/* BC5130 80240EB0 4481B000 */  mtc1      $at, $f22
/* BC5134 80240EB4 0C019E40 */  jal       guTranslateF
/* BC5138 80240EB8 0200202D */   daddu    $a0, $s0, $zero
/* BC513C 80240EBC E7B60010 */  swc1      $f22, 0x10($sp)
/* BC5140 80240EC0 8E250008 */  lw        $a1, 8($s1)
/* BC5144 80240EC4 4406A000 */  mfc1      $a2, $f20
/* BC5148 80240EC8 4407A000 */  mfc1      $a3, $f20
/* BC514C 80240ECC 0C019EC8 */  jal       guRotateF
/* BC5150 80240ED0 27A40018 */   addiu    $a0, $sp, 0x18
/* BC5154 80240ED4 0200202D */  daddu     $a0, $s0, $zero
/* BC5158 80240ED8 27A50018 */  addiu     $a1, $sp, 0x18
/* BC515C 80240EDC 0C019D80 */  jal       guMtxCatF
/* BC5160 80240EE0 0080302D */   daddu    $a2, $a0, $zero
/* BC5164 80240EE4 0C016E89 */  jal       update_collider_transform
/* BC5168 80240EE8 2404003C */   addiu    $a0, $zero, 0x3c
/* BC516C 80240EEC 0C016E89 */  jal       update_collider_transform
/* BC5170 80240EF0 2404003B */   addiu    $a0, $zero, 0x3b
/* BC5174 80240EF4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BC5178 80240EF8 24040080 */   addiu    $a0, $zero, 0x80
/* BC517C 80240EFC 0C046B4C */  jal       get_model_from_list_index
/* BC5180 80240F00 0040202D */   daddu    $a0, $v0, $zero
/* BC5184 80240F04 0040182D */  daddu     $v1, $v0, $zero
/* BC5188 80240F08 24700058 */  addiu     $s0, $v1, 0x58
/* BC518C 80240F0C 4405A000 */  mfc1      $a1, $f20
/* BC5190 80240F10 94620000 */  lhu       $v0, ($v1)
/* BC5194 80240F14 4407A000 */  mfc1      $a3, $f20
/* BC5198 80240F18 34421400 */  ori       $v0, $v0, 0x1400
/* BC519C 80240F1C A4620000 */  sh        $v0, ($v1)
/* BC51A0 80240F20 8E26000C */  lw        $a2, 0xc($s1)
/* BC51A4 80240F24 0C019E40 */  jal       guTranslateF
/* BC51A8 80240F28 0200202D */   daddu    $a0, $s0, $zero
/* BC51AC 80240F2C E7B60010 */  swc1      $f22, 0x10($sp)
/* BC51B0 80240F30 8E250008 */  lw        $a1, 8($s1)
/* BC51B4 80240F34 4406A000 */  mfc1      $a2, $f20
/* BC51B8 80240F38 4407A000 */  mfc1      $a3, $f20
/* BC51BC 80240F3C 0C019EC8 */  jal       guRotateF
/* BC51C0 80240F40 27A40018 */   addiu    $a0, $sp, 0x18
/* BC51C4 80240F44 0200202D */  daddu     $a0, $s0, $zero
/* BC51C8 80240F48 27A50018 */  addiu     $a1, $sp, 0x18
/* BC51CC 80240F4C 0C019D80 */  jal       guMtxCatF
/* BC51D0 80240F50 0080302D */   daddu    $a2, $a0, $zero
/* BC51D4 80240F54 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BC51D8 80240F58 2404007F */   addiu    $a0, $zero, 0x7f
/* BC51DC 80240F5C 0C046B4C */  jal       get_model_from_list_index
/* BC51E0 80240F60 0040202D */   daddu    $a0, $v0, $zero
/* BC51E4 80240F64 0040182D */  daddu     $v1, $v0, $zero
/* BC51E8 80240F68 24700058 */  addiu     $s0, $v1, 0x58
/* BC51EC 80240F6C 4405A000 */  mfc1      $a1, $f20
/* BC51F0 80240F70 94620000 */  lhu       $v0, ($v1)
/* BC51F4 80240F74 4407A000 */  mfc1      $a3, $f20
/* BC51F8 80240F78 34421400 */  ori       $v0, $v0, 0x1400
/* BC51FC 80240F7C A4620000 */  sh        $v0, ($v1)
/* BC5200 80240F80 8E26000C */  lw        $a2, 0xc($s1)
/* BC5204 80240F84 0C019E40 */  jal       guTranslateF
/* BC5208 80240F88 0200202D */   daddu    $a0, $s0, $zero
/* BC520C 80240F8C 4406A000 */  mfc1      $a2, $f20
/* BC5210 80240F90 27A40018 */  addiu     $a0, $sp, 0x18
/* BC5214 80240F94 E7B60010 */  swc1      $f22, 0x10($sp)
/* BC5218 80240F98 8E250008 */  lw        $a1, 8($s1)
/* BC521C 80240F9C 0C019EC8 */  jal       guRotateF
/* BC5220 80240FA0 00C0382D */   daddu    $a3, $a2, $zero
/* BC5224 80240FA4 0200202D */  daddu     $a0, $s0, $zero
/* BC5228 80240FA8 27A50018 */  addiu     $a1, $sp, 0x18
/* BC522C 80240FAC 0C019D80 */  jal       guMtxCatF
/* BC5230 80240FB0 0080302D */   daddu    $a2, $a0, $zero
/* BC5234 80240FB4 0C016E89 */  jal       update_collider_transform
/* BC5238 80240FB8 2404003A */   addiu    $a0, $zero, 0x3a
/* BC523C 80240FBC 8FBF0078 */  lw        $ra, 0x78($sp)
/* BC5240 80240FC0 8FB30074 */  lw        $s3, 0x74($sp)
/* BC5244 80240FC4 8FB20070 */  lw        $s2, 0x70($sp)
/* BC5248 80240FC8 8FB1006C */  lw        $s1, 0x6c($sp)
/* BC524C 80240FCC 8FB00068 */  lw        $s0, 0x68($sp)
/* BC5250 80240FD0 D7B60088 */  ldc1      $f22, 0x88($sp)
/* BC5254 80240FD4 D7B40080 */  ldc1      $f20, 0x80($sp)
/* BC5258 80240FD8 0000102D */  daddu     $v0, $zero, $zero
/* BC525C 80240FDC 03E00008 */  jr        $ra
/* BC5260 80240FE0 27BD0090 */   addiu    $sp, $sp, 0x90
/* BC5264 80240FE4 00000000 */  nop
/* BC5268 80240FE8 00000000 */  nop
/* BC526C 80240FEC 00000000 */  nop
