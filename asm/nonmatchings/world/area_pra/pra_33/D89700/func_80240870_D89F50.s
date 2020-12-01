.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D89F50
/* D89F50 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D89F54 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D89F58 80240878 4480B000 */  mtc1      $zero, $f22
/* D89F5C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D89F60 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D89F64 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D89F68 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D89F6C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D89F70 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D89F74 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D89F78 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D89F7C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D89F80 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D89F84 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D89F88 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D89F8C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D89F90 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D89F94 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D89F98 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D89F9C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D89FA0 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D89FA4 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D89FA8 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D89FAC 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D89FB0 802408D0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D89FB4 802408D4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D89FB8 802408D8 00031080 */  sll       $v0, $v1, 2
/* D89FBC 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D89FC0 802408E0 00021080 */  sll       $v0, $v0, 2
/* D89FC4 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D89FC8 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D89FCC 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D89FD0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D89FD4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D89FD8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D89FDC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D89FE0 80240900 46000507 */   neg.s    $f20, $f0
/* D89FE4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D89FE8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D89FEC 8024090C 44810000 */  mtc1      $at, $f0
/* D89FF0 80240910 00000000 */  nop       
/* D89FF4 80240914 4602003C */  c.lt.s    $f0, $f2
/* D89FF8 80240918 00000000 */  nop       
/* D89FFC 8024091C 4500000A */  bc1f      .L80240948
/* D8A000 80240920 00000000 */   nop      
/* D8A004 80240924 3C014334 */  lui       $at, 0x4334
/* D8A008 80240928 44812000 */  mtc1      $at, $f4
/* D8A00C 8024092C 00000000 */  nop       
/* D8A010 80240930 4604103E */  c.le.s    $f2, $f4
/* D8A014 80240934 00000000 */  nop       
/* D8A018 80240938 45000003 */  bc1f      .L80240948
/* D8A01C 8024093C 00000000 */   nop      
/* D8A020 80240940 08090276 */  j         .L802409D8
/* D8A024 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D8A028 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D8A02C 8024094C 3C014334 */  lui       $at, 0x4334
/* D8A030 80240950 44812000 */  mtc1      $at, $f4
/* D8A034 80240954 00000000 */  nop       
/* D8A038 80240958 4600203C */  c.lt.s    $f4, $f0
/* D8A03C 8024095C 00000000 */  nop       
/* D8A040 80240960 4500000C */  bc1f      .L80240994
/* D8A044 80240964 00000000 */   nop      
/* D8A048 80240968 3C014387 */  lui       $at, 0x4387
/* D8A04C 8024096C 44812000 */  mtc1      $at, $f4
/* D8A050 80240970 00000000 */  nop       
/* D8A054 80240974 4604003E */  c.le.s    $f0, $f4
/* D8A058 80240978 00000000 */  nop       
/* D8A05C 8024097C 45000008 */  bc1f      .L802409A0
/* D8A060 80240980 00000000 */   nop      
/* D8A064 80240984 3C014334 */  lui       $at, 0x4334
/* D8A068 80240988 44812000 */  mtc1      $at, $f4
/* D8A06C 8024098C 08090276 */  j         .L802409D8
/* D8A070 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D8A074 80240994 3C014387 */  lui       $at, 0x4387
/* D8A078 80240998 44812000 */  mtc1      $at, $f4
/* D8A07C 8024099C 00000000 */  nop       
.L802409A0:
/* D8A080 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D8A084 802409A4 00000000 */  nop       
/* D8A088 802409A8 4500000A */  bc1f      .L802409D4
/* D8A08C 802409AC 00000000 */   nop      
/* D8A090 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D8A094 802409B4 44811000 */  mtc1      $at, $f2
/* D8A098 802409B8 00000000 */  nop       
/* D8A09C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D8A0A0 802409C0 00000000 */  nop       
/* D8A0A4 802409C4 45000003 */  bc1f      .L802409D4
/* D8A0A8 802409C8 00000000 */   nop      
/* D8A0AC 802409CC 08090276 */  j         .L802409D8
/* D8A0B0 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D8A0B4 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D8A0B8 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D8A0BC 802409DC 44810000 */  mtc1      $at, $f0
/* D8A0C0 802409E0 00000000 */  nop       
/* D8A0C4 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D8A0C8 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D8A0CC 802409EC 44072000 */  mfc1      $a3, $f4
/* D8A0D0 802409F0 00000000 */  nop       
/* D8A0D4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D8A0D8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D8A0DC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D8A0E0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D8A0E4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D8A0E8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D8A0EC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D8A0F0 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D8A0F4 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D8A0F8 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D8A0FC 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D8A100 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D8A104 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D8A108 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D8A10C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D8A110 80240A30 4405A000 */  mfc1      $a1, $f20
/* D8A114 80240A34 4406B000 */  mfc1      $a2, $f22
/* D8A118 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D8A11C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D8A120 80240A40 0C019EC8 */  jal       guRotateF
/* D8A124 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8A128 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8A12C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D8A130 80240A50 00000000 */   nop      
/* D8A134 80240A54 44050000 */  mfc1      $a1, $f0
/* D8A138 80240A58 4406B000 */  mfc1      $a2, $f22
/* D8A13C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D8A140 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D8A144 80240A64 44812000 */  mtc1      $at, $f4
/* D8A148 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A14C 80240A6C 0C019EC8 */  jal       guRotateF
/* D8A150 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D8A154 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D8A158 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D8A15C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D8A160 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D8A164 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D8A168 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D8A16C 80240A8C 080902D6 */  j         .L80240B58
/* D8A170 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D8A174 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D8A178 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D8A17C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D8A180 80240AA0 0C03964E */  jal       func_800E5938
/* D8A184 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D8A188 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D8A18C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D8A190 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D8A194 80240AB4 46000606 */   mov.s    $f24, $f0
/* D8A198 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D8A19C 80240ABC 080902B5 */  j         .L80240AD4
/* D8A1A0 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D8A1A4 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D8A1A8 80240AC8 00000000 */  nop       
/* D8A1AC 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D8A1B0 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D8A1B4 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D8A1B8 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D8A1BC 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D8A1C0 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D8A1C4 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D8A1C8 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D8A1CC 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D8A1D0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D8A1D4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D8A1D8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D8A1DC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D8A1E0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D8A1E4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D8A1E8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D8A1EC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A1F0 80240B10 0C019EC8 */  jal       guRotateF
/* D8A1F4 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8A1F8 80240B18 4405A000 */  mfc1      $a1, $f20
/* D8A1FC 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D8A200 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D8A204 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D8A208 80240B28 0C019EC8 */  jal       guRotateF
/* D8A20C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D8A210 80240B30 4405C000 */  mfc1      $a1, $f24
/* D8A214 80240B34 4406B000 */  mfc1      $a2, $f22
/* D8A218 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D8A21C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A220 80240B40 0C019EC8 */  jal       guRotateF
/* D8A224 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8A228 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D8A22C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D8A230 80240B50 0C019D80 */  jal       guMtxCatF
/* D8A234 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D8A238 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D8A23C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D8A240 80240B60 44812000 */  mtc1      $at, $f4
/* D8A244 80240B64 00021023 */  negu      $v0, $v0
/* D8A248 80240B68 44820000 */  mtc1      $v0, $f0
/* D8A24C 80240B6C 00000000 */  nop       
/* D8A250 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D8A254 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D8A258 80240B78 00000000 */  nop       
/* D8A25C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D8A260 80240B80 4407B000 */  mfc1      $a3, $f22
/* D8A264 80240B84 44062000 */  mfc1      $a2, $f4
/* D8A268 80240B88 0C019E40 */  jal       guTranslateF
/* D8A26C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D8A270 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D8A274 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D8A278 80240B98 0C019D80 */  jal       guMtxCatF
/* D8A27C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D8A280 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D8A284 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D8A288 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D8A28C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D8A290 80240BB0 0C019EC8 */  jal       guRotateF
/* D8A294 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8A298 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A29C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D8A2A0 80240BC0 0C019D80 */  jal       guMtxCatF
/* D8A2A4 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D8A2A8 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D8A2AC 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8A2B0 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D8A2B4 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D8A2B8 80240BD8 0C019EC8 */  jal       guRotateF
/* D8A2BC 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D8A2C0 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A2C4 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D8A2C8 80240BE8 0C019D80 */  jal       guMtxCatF
/* D8A2CC 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D8A2D0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D8A2D4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D8A2D8 80240BF8 44812000 */  mtc1      $at, $f4
/* D8A2DC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D8A2E0 80240C00 00000000 */  nop       
/* D8A2E4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D8A2E8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D8A2EC 80240C0C 00000000 */  nop       
/* D8A2F0 80240C10 4405B000 */  mfc1      $a1, $f22
/* D8A2F4 80240C14 4407B000 */  mfc1      $a3, $f22
/* D8A2F8 80240C18 44062000 */  mfc1      $a2, $f4
/* D8A2FC 80240C1C 0C019E40 */  jal       guTranslateF
/* D8A300 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D8A304 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A308 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D8A30C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D8A310 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D8A314 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D8A318 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8A31C 80240C3C 44810000 */  mtc1      $at, $f0
/* D8A320 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D8A324 80240C44 44050000 */  mfc1      $a1, $f0
/* D8A328 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D8A32C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D8A330 80240C50 0C019DF0 */  jal       guScaleF
/* D8A334 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D8A338 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A33C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D8A340 80240C60 0C019D80 */  jal       guMtxCatF
/* D8A344 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D8A348 80240C68 4600D687 */  neg.s     $f26, $f26
/* D8A34C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D8A350 80240C70 4407E000 */  mfc1      $a3, $f28
/* D8A354 80240C74 4406D000 */  mfc1      $a2, $f26
/* D8A358 80240C78 0C019E40 */  jal       guTranslateF
/* D8A35C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D8A360 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D8A364 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D8A368 80240C88 0C019D80 */  jal       guMtxCatF
/* D8A36C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D8A370 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8A374 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D8A378 80240C98 44810000 */  mtc1      $at, $f0
/* D8A37C 80240C9C 00000000 */  nop       
/* D8A380 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D8A384 80240CA4 00000000 */  nop       
/* D8A388 80240CA8 4500000A */  bc1f      .L80240CD4
/* D8A38C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D8A390 80240CB0 3C014387 */  lui       $at, 0x4387
/* D8A394 80240CB4 44812000 */  mtc1      $at, $f4
/* D8A398 80240CB8 00000000 */  nop       
/* D8A39C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D8A3A0 80240CC0 00000000 */  nop       
/* D8A3A4 80240CC4 45000004 */  bc1f      .L80240CD8
/* D8A3A8 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D8A3AC 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D8A3B0 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D8A3B4 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D8A3B8 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D8A3BC 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D8A3C0 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D8A3C4 80240CE4 0C0B7710 */  jal       render_sprite
/* D8A3C8 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D8A3CC 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D8A3D0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D8A3D4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D8A3D8 80240CF8 00000000 */   nop      
/* D8A3DC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D8A3E0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D8A3E4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D8A3E8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D8A3EC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D8A3F0 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D8A3F4 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D8A3F8 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D8A3FC 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D8A400 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D8A404 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D8A408 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D8A40C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D8A410 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D8A414 80240D34 03E00008 */  jr        $ra
/* D8A418 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
