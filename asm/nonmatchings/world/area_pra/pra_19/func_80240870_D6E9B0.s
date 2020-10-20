.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D6F220
/* D6F220 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D6F224 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D6F228 80240878 4480B000 */  mtc1      $zero, $f22
/* D6F22C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D6F230 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D6F234 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D6F238 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D6F23C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D6F240 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D6F244 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D6F248 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D6F24C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D6F250 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D6F254 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D6F258 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D6F25C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D6F260 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D6F264 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D6F268 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D6F26C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D6F270 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D6F274 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D6F278 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D6F27C 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D6F280 802408D0 3C03800A */  lui       $v1, 0x800a
/* D6F284 802408D4 8463A634 */  lh        $v1, -0x59cc($v1)
/* D6F288 802408D8 00031080 */  sll       $v0, $v1, 2
/* D6F28C 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D6F290 802408E0 00021080 */  sll       $v0, $v0, 2
/* D6F294 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D6F298 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D6F29C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D6F2A0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D6F2A4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D6F2A8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D6F2AC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D6F2B0 80240900 46000507 */   neg.s    $f20, $f0
/* D6F2B4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D6F2B8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D6F2BC 8024090C 44810000 */  mtc1      $at, $f0
/* D6F2C0 80240910 00000000 */  nop       
/* D6F2C4 80240914 4602003C */  c.lt.s    $f0, $f2
/* D6F2C8 80240918 00000000 */  nop       
/* D6F2CC 8024091C 4500000A */  bc1f      .L80240948
/* D6F2D0 80240920 00000000 */   nop      
/* D6F2D4 80240924 3C014334 */  lui       $at, 0x4334
/* D6F2D8 80240928 44812000 */  mtc1      $at, $f4
/* D6F2DC 8024092C 00000000 */  nop       
/* D6F2E0 80240930 4604103E */  c.le.s    $f2, $f4
/* D6F2E4 80240934 00000000 */  nop       
/* D6F2E8 80240938 45000003 */  bc1f      .L80240948
/* D6F2EC 8024093C 00000000 */   nop      
/* D6F2F0 80240940 08090276 */  j         .L802409D8
/* D6F2F4 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D6F2F8 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D6F2FC 8024094C 3C014334 */  lui       $at, 0x4334
/* D6F300 80240950 44812000 */  mtc1      $at, $f4
/* D6F304 80240954 00000000 */  nop       
/* D6F308 80240958 4600203C */  c.lt.s    $f4, $f0
/* D6F30C 8024095C 00000000 */  nop       
/* D6F310 80240960 4500000C */  bc1f      .L80240994
/* D6F314 80240964 00000000 */   nop      
/* D6F318 80240968 3C014387 */  lui       $at, 0x4387
/* D6F31C 8024096C 44812000 */  mtc1      $at, $f4
/* D6F320 80240970 00000000 */  nop       
/* D6F324 80240974 4604003E */  c.le.s    $f0, $f4
/* D6F328 80240978 00000000 */  nop       
/* D6F32C 8024097C 45000008 */  bc1f      .L802409A0
/* D6F330 80240980 00000000 */   nop      
/* D6F334 80240984 3C014334 */  lui       $at, 0x4334
/* D6F338 80240988 44812000 */  mtc1      $at, $f4
/* D6F33C 8024098C 08090276 */  j         .L802409D8
/* D6F340 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D6F344 80240994 3C014387 */  lui       $at, 0x4387
/* D6F348 80240998 44812000 */  mtc1      $at, $f4
/* D6F34C 8024099C 00000000 */  nop       
.L802409A0:
/* D6F350 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D6F354 802409A4 00000000 */  nop       
/* D6F358 802409A8 4500000A */  bc1f      .L802409D4
/* D6F35C 802409AC 00000000 */   nop      
/* D6F360 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D6F364 802409B4 44811000 */  mtc1      $at, $f2
/* D6F368 802409B8 00000000 */  nop       
/* D6F36C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D6F370 802409C0 00000000 */  nop       
/* D6F374 802409C4 45000003 */  bc1f      .L802409D4
/* D6F378 802409C8 00000000 */   nop      
/* D6F37C 802409CC 08090276 */  j         .L802409D8
/* D6F380 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D6F384 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D6F388 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D6F38C 802409DC 44810000 */  mtc1      $at, $f0
/* D6F390 802409E0 00000000 */  nop       
/* D6F394 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D6F398 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D6F39C 802409EC 44072000 */  mfc1      $a3, $f4
/* D6F3A0 802409F0 00000000 */  nop       
/* D6F3A4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D6F3A8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D6F3AC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D6F3B0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D6F3B4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D6F3B8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D6F3BC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D6F3C0 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D6F3C4 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D6F3C8 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D6F3CC 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D6F3D0 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D6F3D4 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D6F3D8 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D6F3DC 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D6F3E0 80240A30 4405A000 */  mfc1      $a1, $f20
/* D6F3E4 80240A34 4406B000 */  mfc1      $a2, $f22
/* D6F3E8 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D6F3EC 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D6F3F0 80240A40 0C019EC8 */  jal       guRotateF
/* D6F3F4 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6F3F8 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D6F3FC 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D6F400 80240A50 00000000 */   nop      
/* D6F404 80240A54 44050000 */  mfc1      $a1, $f0
/* D6F408 80240A58 4406B000 */  mfc1      $a2, $f22
/* D6F40C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D6F410 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D6F414 80240A64 44812000 */  mtc1      $at, $f4
/* D6F418 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F41C 80240A6C 0C019EC8 */  jal       guRotateF
/* D6F420 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D6F424 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D6F428 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D6F42C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D6F430 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D6F434 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D6F438 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D6F43C 80240A8C 080902D6 */  j         .L80240B58
/* D6F440 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D6F444 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D6F448 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D6F44C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D6F450 80240AA0 0C03964E */  jal       func_800E5938
/* D6F454 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D6F458 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D6F45C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D6F460 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D6F464 80240AB4 46000606 */   mov.s    $f24, $f0
/* D6F468 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D6F46C 80240ABC 080902B5 */  j         .L80240AD4
/* D6F470 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D6F474 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D6F478 80240AC8 00000000 */  nop       
/* D6F47C 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D6F480 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D6F484 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D6F488 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D6F48C 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D6F490 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D6F494 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D6F498 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D6F49C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D6F4A0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D6F4A4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D6F4A8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D6F4AC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D6F4B0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D6F4B4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D6F4B8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D6F4BC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F4C0 80240B10 0C019EC8 */  jal       guRotateF
/* D6F4C4 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6F4C8 80240B18 4405A000 */  mfc1      $a1, $f20
/* D6F4CC 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D6F4D0 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D6F4D4 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D6F4D8 80240B28 0C019EC8 */  jal       guRotateF
/* D6F4DC 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D6F4E0 80240B30 4405C000 */  mfc1      $a1, $f24
/* D6F4E4 80240B34 4406B000 */  mfc1      $a2, $f22
/* D6F4E8 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D6F4EC 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F4F0 80240B40 0C019EC8 */  jal       guRotateF
/* D6F4F4 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6F4F8 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D6F4FC 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D6F500 80240B50 0C019D80 */  jal       guMtxCatF
/* D6F504 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D6F508 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D6F50C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D6F510 80240B60 44812000 */  mtc1      $at, $f4
/* D6F514 80240B64 00021023 */  negu      $v0, $v0
/* D6F518 80240B68 44820000 */  mtc1      $v0, $f0
/* D6F51C 80240B6C 00000000 */  nop       
/* D6F520 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D6F524 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D6F528 80240B78 00000000 */  nop       
/* D6F52C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D6F530 80240B80 4407B000 */  mfc1      $a3, $f22
/* D6F534 80240B84 44062000 */  mfc1      $a2, $f4
/* D6F538 80240B88 0C019E40 */  jal       guTranslateF
/* D6F53C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D6F540 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D6F544 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D6F548 80240B98 0C019D80 */  jal       guMtxCatF
/* D6F54C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D6F550 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D6F554 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D6F558 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D6F55C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D6F560 80240BB0 0C019EC8 */  jal       guRotateF
/* D6F564 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6F568 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F56C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D6F570 80240BC0 0C019D80 */  jal       guMtxCatF
/* D6F574 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D6F578 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D6F57C 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D6F580 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D6F584 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D6F588 80240BD8 0C019EC8 */  jal       guRotateF
/* D6F58C 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D6F590 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F594 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D6F598 80240BE8 0C019D80 */  jal       guMtxCatF
/* D6F59C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D6F5A0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D6F5A4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D6F5A8 80240BF8 44812000 */  mtc1      $at, $f4
/* D6F5AC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D6F5B0 80240C00 00000000 */  nop       
/* D6F5B4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D6F5B8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D6F5BC 80240C0C 00000000 */  nop       
/* D6F5C0 80240C10 4405B000 */  mfc1      $a1, $f22
/* D6F5C4 80240C14 4407B000 */  mfc1      $a3, $f22
/* D6F5C8 80240C18 44062000 */  mfc1      $a2, $f4
/* D6F5CC 80240C1C 0C019E40 */  jal       guTranslateF
/* D6F5D0 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D6F5D4 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F5D8 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D6F5DC 80240C2C 0C019D80 */  jal       guMtxCatF
/* D6F5E0 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D6F5E4 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D6F5E8 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6F5EC 80240C3C 44810000 */  mtc1      $at, $f0
/* D6F5F0 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D6F5F4 80240C44 44050000 */  mfc1      $a1, $f0
/* D6F5F8 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D6F5FC 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D6F600 80240C50 0C019DF0 */  jal       guScaleF
/* D6F604 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D6F608 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F60C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D6F610 80240C60 0C019D80 */  jal       guMtxCatF
/* D6F614 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D6F618 80240C68 4600D687 */  neg.s     $f26, $f26
/* D6F61C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D6F620 80240C70 4407E000 */  mfc1      $a3, $f28
/* D6F624 80240C74 4406D000 */  mfc1      $a2, $f26
/* D6F628 80240C78 0C019E40 */  jal       guTranslateF
/* D6F62C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D6F630 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D6F634 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D6F638 80240C88 0C019D80 */  jal       guMtxCatF
/* D6F63C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D6F640 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D6F644 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D6F648 80240C98 44810000 */  mtc1      $at, $f0
/* D6F64C 80240C9C 00000000 */  nop       
/* D6F650 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D6F654 80240CA4 00000000 */  nop       
/* D6F658 80240CA8 4500000A */  bc1f      .L80240CD4
/* D6F65C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D6F660 80240CB0 3C014387 */  lui       $at, 0x4387
/* D6F664 80240CB4 44812000 */  mtc1      $at, $f4
/* D6F668 80240CB8 00000000 */  nop       
/* D6F66C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D6F670 80240CC0 00000000 */  nop       
/* D6F674 80240CC4 45000004 */  bc1f      .L80240CD8
/* D6F678 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D6F67C 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D6F680 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D6F684 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D6F688 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D6F68C 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D6F690 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D6F694 80240CE4 0C0B7710 */  jal       render_sprite
/* D6F698 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D6F69C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D6F6A0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D6F6A4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D6F6A8 80240CF8 00000000 */   nop      
/* D6F6AC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D6F6B0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D6F6B4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D6F6B8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D6F6BC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D6F6C0 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D6F6C4 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D6F6C8 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D6F6CC 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D6F6D0 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D6F6D4 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D6F6D8 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D6F6DC 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D6F6E0 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D6F6E4 80240D34 03E00008 */  jr        $ra
/* D6F6E8 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
