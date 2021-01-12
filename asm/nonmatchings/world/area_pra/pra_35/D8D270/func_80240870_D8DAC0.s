.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D8DAC0
/* D8DAC0 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D8DAC4 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D8DAC8 80240878 4480B000 */  mtc1      $zero, $f22
/* D8DACC 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D8DAD0 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D8DAD4 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D8DAD8 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D8DADC 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D8DAE0 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D8DAE4 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D8DAE8 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D8DAEC 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D8DAF0 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D8DAF4 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D8DAF8 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D8DAFC 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D8DB00 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D8DB04 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D8DB08 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D8DB0C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D8DB10 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D8DB14 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D8DB18 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D8DB1C 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D8DB20 802408D0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D8DB24 802408D4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D8DB28 802408D8 00031080 */  sll       $v0, $v1, 2
/* D8DB2C 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D8DB30 802408E0 00021080 */  sll       $v0, $v0, 2
/* D8DB34 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D8DB38 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D8DB3C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D8DB40 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D8DB44 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D8DB48 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D8DB4C 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D8DB50 80240900 46000507 */   neg.s    $f20, $f0
/* D8DB54 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8DB58 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D8DB5C 8024090C 44810000 */  mtc1      $at, $f0
/* D8DB60 80240910 00000000 */  nop
/* D8DB64 80240914 4602003C */  c.lt.s    $f0, $f2
/* D8DB68 80240918 00000000 */  nop
/* D8DB6C 8024091C 4500000A */  bc1f      .L80240948
/* D8DB70 80240920 00000000 */   nop
/* D8DB74 80240924 3C014334 */  lui       $at, 0x4334
/* D8DB78 80240928 44812000 */  mtc1      $at, $f4
/* D8DB7C 8024092C 00000000 */  nop
/* D8DB80 80240930 4604103E */  c.le.s    $f2, $f4
/* D8DB84 80240934 00000000 */  nop
/* D8DB88 80240938 45000003 */  bc1f      .L80240948
/* D8DB8C 8024093C 00000000 */   nop
/* D8DB90 80240940 08090276 */  j         .L802409D8
/* D8DB94 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D8DB98 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D8DB9C 8024094C 3C014334 */  lui       $at, 0x4334
/* D8DBA0 80240950 44812000 */  mtc1      $at, $f4
/* D8DBA4 80240954 00000000 */  nop
/* D8DBA8 80240958 4600203C */  c.lt.s    $f4, $f0
/* D8DBAC 8024095C 00000000 */  nop
/* D8DBB0 80240960 4500000C */  bc1f      .L80240994
/* D8DBB4 80240964 00000000 */   nop
/* D8DBB8 80240968 3C014387 */  lui       $at, 0x4387
/* D8DBBC 8024096C 44812000 */  mtc1      $at, $f4
/* D8DBC0 80240970 00000000 */  nop
/* D8DBC4 80240974 4604003E */  c.le.s    $f0, $f4
/* D8DBC8 80240978 00000000 */  nop
/* D8DBCC 8024097C 45000008 */  bc1f      .L802409A0
/* D8DBD0 80240980 00000000 */   nop
/* D8DBD4 80240984 3C014334 */  lui       $at, 0x4334
/* D8DBD8 80240988 44812000 */  mtc1      $at, $f4
/* D8DBDC 8024098C 08090276 */  j         .L802409D8
/* D8DBE0 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D8DBE4 80240994 3C014387 */  lui       $at, 0x4387
/* D8DBE8 80240998 44812000 */  mtc1      $at, $f4
/* D8DBEC 8024099C 00000000 */  nop
.L802409A0:
/* D8DBF0 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D8DBF4 802409A4 00000000 */  nop
/* D8DBF8 802409A8 4500000A */  bc1f      .L802409D4
/* D8DBFC 802409AC 00000000 */   nop
/* D8DC00 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D8DC04 802409B4 44811000 */  mtc1      $at, $f2
/* D8DC08 802409B8 00000000 */  nop
/* D8DC0C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D8DC10 802409C0 00000000 */  nop
/* D8DC14 802409C4 45000003 */  bc1f      .L802409D4
/* D8DC18 802409C8 00000000 */   nop
/* D8DC1C 802409CC 08090276 */  j         .L802409D8
/* D8DC20 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D8DC24 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D8DC28 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D8DC2C 802409DC 44810000 */  mtc1      $at, $f0
/* D8DC30 802409E0 00000000 */  nop
/* D8DC34 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D8DC38 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D8DC3C 802409EC 44072000 */  mfc1      $a3, $f4
/* D8DC40 802409F0 00000000 */  nop
/* D8DC44 802409F4 00071100 */  sll       $v0, $a3, 4
/* D8DC48 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D8DC4C 802409FC 00021080 */  sll       $v0, $v0, 2
/* D8DC50 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D8DC54 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D8DC58 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D8DC5C 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D8DC60 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D8DC64 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D8DC68 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D8DC6C 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D8DC70 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D8DC74 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D8DC78 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D8DC7C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D8DC80 80240A30 4405A000 */  mfc1      $a1, $f20
/* D8DC84 80240A34 4406B000 */  mfc1      $a2, $f22
/* D8DC88 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D8DC8C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D8DC90 80240A40 0C019EC8 */  jal       guRotateF
/* D8DC94 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8DC98 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8DC9C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D8DCA0 80240A50 00000000 */   nop
/* D8DCA4 80240A54 44050000 */  mfc1      $a1, $f0
/* D8DCA8 80240A58 4406B000 */  mfc1      $a2, $f22
/* D8DCAC 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D8DCB0 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D8DCB4 80240A64 44812000 */  mtc1      $at, $f4
/* D8DCB8 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DCBC 80240A6C 0C019EC8 */  jal       guRotateF
/* D8DCC0 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D8DCC4 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D8DCC8 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D8DCCC 80240A7C 0C019D80 */  jal       guMtxCatF
/* D8DCD0 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D8DCD4 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D8DCD8 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D8DCDC 80240A8C 080902D6 */  j         .L80240B58
/* D8DCE0 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D8DCE4 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D8DCE8 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D8DCEC 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D8DCF0 80240AA0 0C03964E */  jal       func_800E5938
/* D8DCF4 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D8DCF8 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D8DCFC 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D8DD00 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D8DD04 80240AB4 46000606 */   mov.s    $f24, $f0
/* D8DD08 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D8DD0C 80240ABC 080902B5 */  j         .L80240AD4
/* D8DD10 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D8DD14 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D8DD18 80240AC8 00000000 */  nop
/* D8DD1C 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D8DD20 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D8DD24 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D8DD28 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D8DD2C 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D8DD30 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D8DD34 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D8DD38 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D8DD3C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D8DD40 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D8DD44 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D8DD48 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D8DD4C 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D8DD50 80240B00 4405A000 */  mfc1      $a1, $f20
/* D8DD54 80240B04 4406B000 */  mfc1      $a2, $f22
/* D8DD58 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D8DD5C 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DD60 80240B10 0C019EC8 */  jal       guRotateF
/* D8DD64 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8DD68 80240B18 4405A000 */  mfc1      $a1, $f20
/* D8DD6C 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D8DD70 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D8DD74 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D8DD78 80240B28 0C019EC8 */  jal       guRotateF
/* D8DD7C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D8DD80 80240B30 4405C000 */  mfc1      $a1, $f24
/* D8DD84 80240B34 4406B000 */  mfc1      $a2, $f22
/* D8DD88 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D8DD8C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DD90 80240B40 0C019EC8 */  jal       guRotateF
/* D8DD94 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8DD98 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D8DD9C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D8DDA0 80240B50 0C019D80 */  jal       guMtxCatF
/* D8DDA4 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D8DDA8 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D8DDAC 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D8DDB0 80240B60 44812000 */  mtc1      $at, $f4
/* D8DDB4 80240B64 00021023 */  negu      $v0, $v0
/* D8DDB8 80240B68 44820000 */  mtc1      $v0, $f0
/* D8DDBC 80240B6C 00000000 */  nop
/* D8DDC0 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D8DDC4 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D8DDC8 80240B78 00000000 */  nop
/* D8DDCC 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D8DDD0 80240B80 4407B000 */  mfc1      $a3, $f22
/* D8DDD4 80240B84 44062000 */  mfc1      $a2, $f4
/* D8DDD8 80240B88 0C019E40 */  jal       guTranslateF
/* D8DDDC 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D8DDE0 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D8DDE4 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D8DDE8 80240B98 0C019D80 */  jal       guMtxCatF
/* D8DDEC 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D8DDF0 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D8DDF4 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D8DDF8 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D8DDFC 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D8DE00 80240BB0 0C019EC8 */  jal       guRotateF
/* D8DE04 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8DE08 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DE0C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D8DE10 80240BC0 0C019D80 */  jal       guMtxCatF
/* D8DE14 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D8DE18 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D8DE1C 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8DE20 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D8DE24 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D8DE28 80240BD8 0C019EC8 */  jal       guRotateF
/* D8DE2C 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D8DE30 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DE34 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D8DE38 80240BE8 0C019D80 */  jal       guMtxCatF
/* D8DE3C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D8DE40 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D8DE44 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D8DE48 80240BF8 44812000 */  mtc1      $at, $f4
/* D8DE4C 80240BFC 44820000 */  mtc1      $v0, $f0
/* D8DE50 80240C00 00000000 */  nop
/* D8DE54 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D8DE58 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D8DE5C 80240C0C 00000000 */  nop
/* D8DE60 80240C10 4405B000 */  mfc1      $a1, $f22
/* D8DE64 80240C14 4407B000 */  mfc1      $a3, $f22
/* D8DE68 80240C18 44062000 */  mfc1      $a2, $f4
/* D8DE6C 80240C1C 0C019E40 */  jal       guTranslateF
/* D8DE70 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D8DE74 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DE78 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D8DE7C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D8DE80 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D8DE84 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D8DE88 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8DE8C 80240C3C 44810000 */  mtc1      $at, $f0
/* D8DE90 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D8DE94 80240C44 44050000 */  mfc1      $a1, $f0
/* D8DE98 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D8DE9C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D8DEA0 80240C50 0C019DF0 */  jal       guScaleF
/* D8DEA4 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D8DEA8 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DEAC 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D8DEB0 80240C60 0C019D80 */  jal       guMtxCatF
/* D8DEB4 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D8DEB8 80240C68 4600D687 */  neg.s     $f26, $f26
/* D8DEBC 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D8DEC0 80240C70 4407E000 */  mfc1      $a3, $f28
/* D8DEC4 80240C74 4406D000 */  mfc1      $a2, $f26
/* D8DEC8 80240C78 0C019E40 */  jal       guTranslateF
/* D8DECC 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D8DED0 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D8DED4 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D8DED8 80240C88 0C019D80 */  jal       guMtxCatF
/* D8DEDC 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D8DEE0 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8DEE4 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D8DEE8 80240C98 44810000 */  mtc1      $at, $f0
/* D8DEEC 80240C9C 00000000 */  nop
/* D8DEF0 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D8DEF4 80240CA4 00000000 */  nop
/* D8DEF8 80240CA8 4500000A */  bc1f      .L80240CD4
/* D8DEFC 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D8DF00 80240CB0 3C014387 */  lui       $at, 0x4387
/* D8DF04 80240CB4 44812000 */  mtc1      $at, $f4
/* D8DF08 80240CB8 00000000 */  nop
/* D8DF0C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D8DF10 80240CC0 00000000 */  nop
/* D8DF14 80240CC4 45000004 */  bc1f      .L80240CD8
/* D8DF18 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D8DF1C 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D8DF20 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D8DF24 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D8DF28 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D8DF2C 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D8DF30 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D8DF34 80240CE4 0C0B7710 */  jal       render_sprite
/* D8DF38 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D8DF3C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D8DF40 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D8DF44 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D8DF48 80240CF8 00000000 */   nop
/* D8DF4C 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D8DF50 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D8DF54 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D8DF58 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D8DF5C 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D8DF60 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D8DF64 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D8DF68 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D8DF6C 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D8DF70 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D8DF74 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D8DF78 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D8DF7C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D8DF80 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D8DF84 80240D34 03E00008 */  jr        $ra
/* D8DF88 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
