.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D5FB20
/* D5FB20 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D5FB24 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D5FB28 80240878 4480B000 */  mtc1      $zero, $f22
/* D5FB2C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D5FB30 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D5FB34 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D5FB38 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D5FB3C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D5FB40 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D5FB44 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D5FB48 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D5FB4C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D5FB50 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D5FB54 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D5FB58 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D5FB5C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D5FB60 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D5FB64 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D5FB68 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D5FB6C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D5FB70 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D5FB74 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D5FB78 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D5FB7C 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D5FB80 802408D0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D5FB84 802408D4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D5FB88 802408D8 00031080 */  sll       $v0, $v1, 2
/* D5FB8C 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D5FB90 802408E0 00021080 */  sll       $v0, $v0, 2
/* D5FB94 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D5FB98 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D5FB9C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D5FBA0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D5FBA4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D5FBA8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D5FBAC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D5FBB0 80240900 46000507 */   neg.s    $f20, $f0
/* D5FBB4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D5FBB8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D5FBBC 8024090C 44810000 */  mtc1      $at, $f0
/* D5FBC0 80240910 00000000 */  nop
/* D5FBC4 80240914 4602003C */  c.lt.s    $f0, $f2
/* D5FBC8 80240918 00000000 */  nop
/* D5FBCC 8024091C 4500000A */  bc1f      .L80240948
/* D5FBD0 80240920 00000000 */   nop
/* D5FBD4 80240924 3C014334 */  lui       $at, 0x4334
/* D5FBD8 80240928 44812000 */  mtc1      $at, $f4
/* D5FBDC 8024092C 00000000 */  nop
/* D5FBE0 80240930 4604103E */  c.le.s    $f2, $f4
/* D5FBE4 80240934 00000000 */  nop
/* D5FBE8 80240938 45000003 */  bc1f      .L80240948
/* D5FBEC 8024093C 00000000 */   nop
/* D5FBF0 80240940 08090276 */  j         .L802409D8
/* D5FBF4 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D5FBF8 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D5FBFC 8024094C 3C014334 */  lui       $at, 0x4334
/* D5FC00 80240950 44812000 */  mtc1      $at, $f4
/* D5FC04 80240954 00000000 */  nop
/* D5FC08 80240958 4600203C */  c.lt.s    $f4, $f0
/* D5FC0C 8024095C 00000000 */  nop
/* D5FC10 80240960 4500000C */  bc1f      .L80240994
/* D5FC14 80240964 00000000 */   nop
/* D5FC18 80240968 3C014387 */  lui       $at, 0x4387
/* D5FC1C 8024096C 44812000 */  mtc1      $at, $f4
/* D5FC20 80240970 00000000 */  nop
/* D5FC24 80240974 4604003E */  c.le.s    $f0, $f4
/* D5FC28 80240978 00000000 */  nop
/* D5FC2C 8024097C 45000008 */  bc1f      .L802409A0
/* D5FC30 80240980 00000000 */   nop
/* D5FC34 80240984 3C014334 */  lui       $at, 0x4334
/* D5FC38 80240988 44812000 */  mtc1      $at, $f4
/* D5FC3C 8024098C 08090276 */  j         .L802409D8
/* D5FC40 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D5FC44 80240994 3C014387 */  lui       $at, 0x4387
/* D5FC48 80240998 44812000 */  mtc1      $at, $f4
/* D5FC4C 8024099C 00000000 */  nop
.L802409A0:
/* D5FC50 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D5FC54 802409A4 00000000 */  nop
/* D5FC58 802409A8 4500000A */  bc1f      .L802409D4
/* D5FC5C 802409AC 00000000 */   nop
/* D5FC60 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D5FC64 802409B4 44811000 */  mtc1      $at, $f2
/* D5FC68 802409B8 00000000 */  nop
/* D5FC6C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D5FC70 802409C0 00000000 */  nop
/* D5FC74 802409C4 45000003 */  bc1f      .L802409D4
/* D5FC78 802409C8 00000000 */   nop
/* D5FC7C 802409CC 08090276 */  j         .L802409D8
/* D5FC80 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D5FC84 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D5FC88 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D5FC8C 802409DC 44810000 */  mtc1      $at, $f0
/* D5FC90 802409E0 00000000 */  nop
/* D5FC94 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D5FC98 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D5FC9C 802409EC 44072000 */  mfc1      $a3, $f4
/* D5FCA0 802409F0 00000000 */  nop
/* D5FCA4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D5FCA8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D5FCAC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D5FCB0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D5FCB4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D5FCB8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D5FCBC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D5FCC0 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D5FCC4 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D5FCC8 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D5FCCC 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D5FCD0 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D5FCD4 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D5FCD8 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D5FCDC 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D5FCE0 80240A30 4405A000 */  mfc1      $a1, $f20
/* D5FCE4 80240A34 4406B000 */  mfc1      $a2, $f22
/* D5FCE8 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D5FCEC 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D5FCF0 80240A40 0C019EC8 */  jal       guRotateF
/* D5FCF4 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D5FCF8 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D5FCFC 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D5FD00 80240A50 00000000 */   nop
/* D5FD04 80240A54 44050000 */  mfc1      $a1, $f0
/* D5FD08 80240A58 4406B000 */  mfc1      $a2, $f22
/* D5FD0C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D5FD10 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D5FD14 80240A64 44812000 */  mtc1      $at, $f4
/* D5FD18 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FD1C 80240A6C 0C019EC8 */  jal       guRotateF
/* D5FD20 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D5FD24 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D5FD28 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D5FD2C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D5FD30 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D5FD34 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D5FD38 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D5FD3C 80240A8C 080902D6 */  j         .L80240B58
/* D5FD40 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D5FD44 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D5FD48 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D5FD4C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D5FD50 80240AA0 0C03964E */  jal       func_800E5938
/* D5FD54 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D5FD58 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D5FD5C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D5FD60 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D5FD64 80240AB4 46000606 */   mov.s    $f24, $f0
/* D5FD68 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D5FD6C 80240ABC 080902B5 */  j         .L80240AD4
/* D5FD70 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D5FD74 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D5FD78 80240AC8 00000000 */  nop
/* D5FD7C 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D5FD80 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D5FD84 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D5FD88 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D5FD8C 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D5FD90 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D5FD94 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D5FD98 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D5FD9C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D5FDA0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D5FDA4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D5FDA8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D5FDAC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D5FDB0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D5FDB4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D5FDB8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D5FDBC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FDC0 80240B10 0C019EC8 */  jal       guRotateF
/* D5FDC4 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D5FDC8 80240B18 4405A000 */  mfc1      $a1, $f20
/* D5FDCC 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D5FDD0 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D5FDD4 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D5FDD8 80240B28 0C019EC8 */  jal       guRotateF
/* D5FDDC 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D5FDE0 80240B30 4405C000 */  mfc1      $a1, $f24
/* D5FDE4 80240B34 4406B000 */  mfc1      $a2, $f22
/* D5FDE8 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D5FDEC 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FDF0 80240B40 0C019EC8 */  jal       guRotateF
/* D5FDF4 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D5FDF8 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D5FDFC 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D5FE00 80240B50 0C019D80 */  jal       guMtxCatF
/* D5FE04 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D5FE08 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D5FE0C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D5FE10 80240B60 44812000 */  mtc1      $at, $f4
/* D5FE14 80240B64 00021023 */  negu      $v0, $v0
/* D5FE18 80240B68 44820000 */  mtc1      $v0, $f0
/* D5FE1C 80240B6C 00000000 */  nop
/* D5FE20 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D5FE24 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D5FE28 80240B78 00000000 */  nop
/* D5FE2C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D5FE30 80240B80 4407B000 */  mfc1      $a3, $f22
/* D5FE34 80240B84 44062000 */  mfc1      $a2, $f4
/* D5FE38 80240B88 0C019E40 */  jal       guTranslateF
/* D5FE3C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D5FE40 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D5FE44 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D5FE48 80240B98 0C019D80 */  jal       guMtxCatF
/* D5FE4C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D5FE50 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D5FE54 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D5FE58 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D5FE5C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D5FE60 80240BB0 0C019EC8 */  jal       guRotateF
/* D5FE64 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D5FE68 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FE6C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D5FE70 80240BC0 0C019D80 */  jal       guMtxCatF
/* D5FE74 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D5FE78 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D5FE7C 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D5FE80 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D5FE84 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D5FE88 80240BD8 0C019EC8 */  jal       guRotateF
/* D5FE8C 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D5FE90 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FE94 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D5FE98 80240BE8 0C019D80 */  jal       guMtxCatF
/* D5FE9C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D5FEA0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D5FEA4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D5FEA8 80240BF8 44812000 */  mtc1      $at, $f4
/* D5FEAC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D5FEB0 80240C00 00000000 */  nop
/* D5FEB4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D5FEB8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D5FEBC 80240C0C 00000000 */  nop
/* D5FEC0 80240C10 4405B000 */  mfc1      $a1, $f22
/* D5FEC4 80240C14 4407B000 */  mfc1      $a3, $f22
/* D5FEC8 80240C18 44062000 */  mfc1      $a2, $f4
/* D5FECC 80240C1C 0C019E40 */  jal       guTranslateF
/* D5FED0 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D5FED4 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FED8 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D5FEDC 80240C2C 0C019D80 */  jal       guMtxCatF
/* D5FEE0 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D5FEE4 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D5FEE8 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D5FEEC 80240C3C 44810000 */  mtc1      $at, $f0
/* D5FEF0 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D5FEF4 80240C44 44050000 */  mfc1      $a1, $f0
/* D5FEF8 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D5FEFC 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D5FF00 80240C50 0C019DF0 */  jal       guScaleF
/* D5FF04 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D5FF08 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FF0C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D5FF10 80240C60 0C019D80 */  jal       guMtxCatF
/* D5FF14 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D5FF18 80240C68 4600D687 */  neg.s     $f26, $f26
/* D5FF1C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D5FF20 80240C70 4407E000 */  mfc1      $a3, $f28
/* D5FF24 80240C74 4406D000 */  mfc1      $a2, $f26
/* D5FF28 80240C78 0C019E40 */  jal       guTranslateF
/* D5FF2C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D5FF30 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D5FF34 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D5FF38 80240C88 0C019D80 */  jal       guMtxCatF
/* D5FF3C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D5FF40 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D5FF44 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D5FF48 80240C98 44810000 */  mtc1      $at, $f0
/* D5FF4C 80240C9C 00000000 */  nop
/* D5FF50 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D5FF54 80240CA4 00000000 */  nop
/* D5FF58 80240CA8 4500000A */  bc1f      .L80240CD4
/* D5FF5C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D5FF60 80240CB0 3C014387 */  lui       $at, 0x4387
/* D5FF64 80240CB4 44812000 */  mtc1      $at, $f4
/* D5FF68 80240CB8 00000000 */  nop
/* D5FF6C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D5FF70 80240CC0 00000000 */  nop
/* D5FF74 80240CC4 45000004 */  bc1f      .L80240CD8
/* D5FF78 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D5FF7C 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D5FF80 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D5FF84 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D5FF88 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D5FF8C 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D5FF90 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D5FF94 80240CE4 0C0B7710 */  jal       render_sprite
/* D5FF98 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D5FF9C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D5FFA0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D5FFA4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D5FFA8 80240CF8 00000000 */   nop
/* D5FFAC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D5FFB0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D5FFB4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D5FFB8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D5FFBC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D5FFC0 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D5FFC4 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D5FFC8 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D5FFCC 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D5FFD0 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D5FFD4 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D5FFD8 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D5FFDC 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D5FFE0 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D5FFE4 80240D34 03E00008 */  jr        $ra
/* D5FFE8 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
