.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D64E50
/* D64E50 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D64E54 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D64E58 80240878 4480B000 */  mtc1      $zero, $f22
/* D64E5C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D64E60 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D64E64 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D64E68 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D64E6C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D64E70 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D64E74 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D64E78 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D64E7C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D64E80 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D64E84 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D64E88 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D64E8C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D64E90 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D64E94 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D64E98 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D64E9C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D64EA0 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D64EA4 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D64EA8 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D64EAC 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D64EB0 802408D0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D64EB4 802408D4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D64EB8 802408D8 00031080 */  sll       $v0, $v1, 2
/* D64EBC 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D64EC0 802408E0 00021080 */  sll       $v0, $v0, 2
/* D64EC4 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D64EC8 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D64ECC 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D64ED0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D64ED4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D64ED8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D64EDC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D64EE0 80240900 46000507 */   neg.s    $f20, $f0
/* D64EE4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D64EE8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D64EEC 8024090C 44810000 */  mtc1      $at, $f0
/* D64EF0 80240910 00000000 */  nop
/* D64EF4 80240914 4602003C */  c.lt.s    $f0, $f2
/* D64EF8 80240918 00000000 */  nop
/* D64EFC 8024091C 4500000A */  bc1f      .L80240948
/* D64F00 80240920 00000000 */   nop
/* D64F04 80240924 3C014334 */  lui       $at, 0x4334
/* D64F08 80240928 44812000 */  mtc1      $at, $f4
/* D64F0C 8024092C 00000000 */  nop
/* D64F10 80240930 4604103E */  c.le.s    $f2, $f4
/* D64F14 80240934 00000000 */  nop
/* D64F18 80240938 45000003 */  bc1f      .L80240948
/* D64F1C 8024093C 00000000 */   nop
/* D64F20 80240940 08090276 */  j         .L802409D8
/* D64F24 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D64F28 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D64F2C 8024094C 3C014334 */  lui       $at, 0x4334
/* D64F30 80240950 44812000 */  mtc1      $at, $f4
/* D64F34 80240954 00000000 */  nop
/* D64F38 80240958 4600203C */  c.lt.s    $f4, $f0
/* D64F3C 8024095C 00000000 */  nop
/* D64F40 80240960 4500000C */  bc1f      .L80240994
/* D64F44 80240964 00000000 */   nop
/* D64F48 80240968 3C014387 */  lui       $at, 0x4387
/* D64F4C 8024096C 44812000 */  mtc1      $at, $f4
/* D64F50 80240970 00000000 */  nop
/* D64F54 80240974 4604003E */  c.le.s    $f0, $f4
/* D64F58 80240978 00000000 */  nop
/* D64F5C 8024097C 45000008 */  bc1f      .L802409A0
/* D64F60 80240980 00000000 */   nop
/* D64F64 80240984 3C014334 */  lui       $at, 0x4334
/* D64F68 80240988 44812000 */  mtc1      $at, $f4
/* D64F6C 8024098C 08090276 */  j         .L802409D8
/* D64F70 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D64F74 80240994 3C014387 */  lui       $at, 0x4387
/* D64F78 80240998 44812000 */  mtc1      $at, $f4
/* D64F7C 8024099C 00000000 */  nop
.L802409A0:
/* D64F80 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D64F84 802409A4 00000000 */  nop
/* D64F88 802409A8 4500000A */  bc1f      .L802409D4
/* D64F8C 802409AC 00000000 */   nop
/* D64F90 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D64F94 802409B4 44811000 */  mtc1      $at, $f2
/* D64F98 802409B8 00000000 */  nop
/* D64F9C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D64FA0 802409C0 00000000 */  nop
/* D64FA4 802409C4 45000003 */  bc1f      .L802409D4
/* D64FA8 802409C8 00000000 */   nop
/* D64FAC 802409CC 08090276 */  j         .L802409D8
/* D64FB0 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D64FB4 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D64FB8 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D64FBC 802409DC 44810000 */  mtc1      $at, $f0
/* D64FC0 802409E0 00000000 */  nop
/* D64FC4 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D64FC8 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D64FCC 802409EC 44072000 */  mfc1      $a3, $f4
/* D64FD0 802409F0 00000000 */  nop
/* D64FD4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D64FD8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D64FDC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D64FE0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D64FE4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D64FE8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D64FEC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D64FF0 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D64FF4 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D64FF8 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D64FFC 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D65000 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D65004 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D65008 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D6500C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D65010 80240A30 4405A000 */  mfc1      $a1, $f20
/* D65014 80240A34 4406B000 */  mfc1      $a2, $f22
/* D65018 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D6501C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D65020 80240A40 0C019EC8 */  jal       guRotateF
/* D65024 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D65028 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D6502C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D65030 80240A50 00000000 */   nop
/* D65034 80240A54 44050000 */  mfc1      $a1, $f0
/* D65038 80240A58 4406B000 */  mfc1      $a2, $f22
/* D6503C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D65040 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D65044 80240A64 44812000 */  mtc1      $at, $f4
/* D65048 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D6504C 80240A6C 0C019EC8 */  jal       guRotateF
/* D65050 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D65054 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D65058 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D6505C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D65060 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D65064 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D65068 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D6506C 80240A8C 080902D6 */  j         .L80240B58
/* D65070 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D65074 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D65078 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D6507C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D65080 80240AA0 0C03964E */  jal       func_800E5938
/* D65084 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D65088 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D6508C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D65090 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D65094 80240AB4 46000606 */   mov.s    $f24, $f0
/* D65098 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D6509C 80240ABC 080902B5 */  j         .L80240AD4
/* D650A0 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D650A4 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D650A8 80240AC8 00000000 */  nop
/* D650AC 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D650B0 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D650B4 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D650B8 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D650BC 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D650C0 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D650C4 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D650C8 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D650CC 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D650D0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D650D4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D650D8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D650DC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D650E0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D650E4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D650E8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D650EC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D650F0 80240B10 0C019EC8 */  jal       guRotateF
/* D650F4 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D650F8 80240B18 4405A000 */  mfc1      $a1, $f20
/* D650FC 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D65100 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D65104 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D65108 80240B28 0C019EC8 */  jal       guRotateF
/* D6510C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D65110 80240B30 4405C000 */  mfc1      $a1, $f24
/* D65114 80240B34 4406B000 */  mfc1      $a2, $f22
/* D65118 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D6511C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D65120 80240B40 0C019EC8 */  jal       guRotateF
/* D65124 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D65128 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D6512C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D65130 80240B50 0C019D80 */  jal       guMtxCatF
/* D65134 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D65138 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D6513C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D65140 80240B60 44812000 */  mtc1      $at, $f4
/* D65144 80240B64 00021023 */  negu      $v0, $v0
/* D65148 80240B68 44820000 */  mtc1      $v0, $f0
/* D6514C 80240B6C 00000000 */  nop
/* D65150 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D65154 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D65158 80240B78 00000000 */  nop
/* D6515C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D65160 80240B80 4407B000 */  mfc1      $a3, $f22
/* D65164 80240B84 44062000 */  mfc1      $a2, $f4
/* D65168 80240B88 0C019E40 */  jal       guTranslateF
/* D6516C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D65170 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D65174 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D65178 80240B98 0C019D80 */  jal       guMtxCatF
/* D6517C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D65180 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D65184 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D65188 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D6518C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D65190 80240BB0 0C019EC8 */  jal       guRotateF
/* D65194 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D65198 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D6519C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D651A0 80240BC0 0C019D80 */  jal       guMtxCatF
/* D651A4 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D651A8 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D651AC 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D651B0 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D651B4 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D651B8 80240BD8 0C019EC8 */  jal       guRotateF
/* D651BC 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D651C0 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D651C4 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D651C8 80240BE8 0C019D80 */  jal       guMtxCatF
/* D651CC 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D651D0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D651D4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D651D8 80240BF8 44812000 */  mtc1      $at, $f4
/* D651DC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D651E0 80240C00 00000000 */  nop
/* D651E4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D651E8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D651EC 80240C0C 00000000 */  nop
/* D651F0 80240C10 4405B000 */  mfc1      $a1, $f22
/* D651F4 80240C14 4407B000 */  mfc1      $a3, $f22
/* D651F8 80240C18 44062000 */  mfc1      $a2, $f4
/* D651FC 80240C1C 0C019E40 */  jal       guTranslateF
/* D65200 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D65204 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D65208 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D6520C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D65210 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D65214 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D65218 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6521C 80240C3C 44810000 */  mtc1      $at, $f0
/* D65220 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D65224 80240C44 44050000 */  mfc1      $a1, $f0
/* D65228 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D6522C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D65230 80240C50 0C019DF0 */  jal       guScaleF
/* D65234 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D65238 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D6523C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D65240 80240C60 0C019D80 */  jal       guMtxCatF
/* D65244 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D65248 80240C68 4600D687 */  neg.s     $f26, $f26
/* D6524C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D65250 80240C70 4407E000 */  mfc1      $a3, $f28
/* D65254 80240C74 4406D000 */  mfc1      $a2, $f26
/* D65258 80240C78 0C019E40 */  jal       guTranslateF
/* D6525C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D65260 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D65264 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D65268 80240C88 0C019D80 */  jal       guMtxCatF
/* D6526C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D65270 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D65274 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D65278 80240C98 44810000 */  mtc1      $at, $f0
/* D6527C 80240C9C 00000000 */  nop
/* D65280 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D65284 80240CA4 00000000 */  nop
/* D65288 80240CA8 4500000A */  bc1f      .L80240CD4
/* D6528C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D65290 80240CB0 3C014387 */  lui       $at, 0x4387
/* D65294 80240CB4 44812000 */  mtc1      $at, $f4
/* D65298 80240CB8 00000000 */  nop
/* D6529C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D652A0 80240CC0 00000000 */  nop
/* D652A4 80240CC4 45000004 */  bc1f      .L80240CD8
/* D652A8 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D652AC 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D652B0 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D652B4 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D652B8 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D652BC 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D652C0 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D652C4 80240CE4 0C0B7710 */  jal       render_sprite
/* D652C8 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D652CC 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D652D0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D652D4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D652D8 80240CF8 00000000 */   nop
/* D652DC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D652E0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D652E4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D652E8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D652EC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D652F0 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D652F4 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D652F8 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D652FC 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D65300 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D65304 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D65308 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D6530C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D65310 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D65314 80240D34 03E00008 */  jr        $ra
/* D65318 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
