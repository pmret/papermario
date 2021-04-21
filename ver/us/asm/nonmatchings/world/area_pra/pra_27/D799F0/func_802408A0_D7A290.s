.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A0_D7A290
/* D7A290 802408A0 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D7A294 802408A4 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D7A298 802408A8 4480B000 */  mtc1      $zero, $f22
/* D7A29C 802408AC AFB10134 */  sw        $s1, 0x134($sp)
/* D7A2A0 802408B0 0080882D */  daddu     $s1, $a0, $zero
/* D7A2A4 802408B4 AFB3013C */  sw        $s3, 0x13c($sp)
/* D7A2A8 802408B8 0000982D */  daddu     $s3, $zero, $zero
/* D7A2AC 802408BC AFB60148 */  sw        $s6, 0x148($sp)
/* D7A2B0 802408C0 3C16800B */  lui       $s6, %hi(gCameras)
/* D7A2B4 802408C4 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D7A2B8 802408C8 AFB50144 */  sw        $s5, 0x144($sp)
/* D7A2BC 802408CC 241500FF */  addiu     $s5, $zero, 0xff
/* D7A2C0 802408D0 AFB00130 */  sw        $s0, 0x130($sp)
/* D7A2C4 802408D4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D7A2C8 802408D8 AFB20138 */  sw        $s2, 0x138($sp)
/* D7A2CC 802408DC 27B20060 */  addiu     $s2, $sp, 0x60
/* D7A2D0 802408E0 AFB40140 */  sw        $s4, 0x140($sp)
/* D7A2D4 802408E4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D7A2D8 802408E8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D7A2DC 802408EC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D7A2E0 802408F0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D7A2E4 802408F4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D7A2E8 802408F8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D7A2EC 802408FC F7B40150 */  sdc1      $f20, 0x150($sp)
.L80240900:
/* D7A2F0 80240900 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D7A2F4 80240904 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D7A2F8 80240908 00031080 */  sll       $v0, $v1, 2
/* D7A2FC 8024090C 00431021 */  addu      $v0, $v0, $v1
/* D7A300 80240910 00021080 */  sll       $v0, $v0, 2
/* D7A304 80240914 00431023 */  subu      $v0, $v0, $v1
/* D7A308 80240918 000218C0 */  sll       $v1, $v0, 3
/* D7A30C 8024091C 00431021 */  addu      $v0, $v0, $v1
/* D7A310 80240920 000210C0 */  sll       $v0, $v0, 3
/* D7A314 80240924 00561021 */  addu      $v0, $v0, $s6
/* D7A318 80240928 C440006C */  lwc1      $f0, 0x6c($v0)
/* D7A31C 8024092C 16600065 */  bnez      $s3, .L80240AC4
/* D7A320 80240930 46000507 */   neg.s    $f20, $f0
/* D7A324 80240934 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7A328 80240938 3C0142B4 */  lui       $at, 0x42b4
/* D7A32C 8024093C 44810000 */  mtc1      $at, $f0
/* D7A330 80240940 00000000 */  nop
/* D7A334 80240944 4602003C */  c.lt.s    $f0, $f2
/* D7A338 80240948 00000000 */  nop
/* D7A33C 8024094C 4500000A */  bc1f      .L80240978
/* D7A340 80240950 00000000 */   nop
/* D7A344 80240954 3C014334 */  lui       $at, 0x4334
/* D7A348 80240958 44812000 */  mtc1      $at, $f4
/* D7A34C 8024095C 00000000 */  nop
/* D7A350 80240960 4604103E */  c.le.s    $f2, $f4
/* D7A354 80240964 00000000 */  nop
/* D7A358 80240968 45000003 */  bc1f      .L80240978
/* D7A35C 8024096C 00000000 */   nop
/* D7A360 80240970 08090282 */  j         .L80240A08
/* D7A364 80240974 46022501 */   sub.s    $f20, $f4, $f2
.L80240978:
/* D7A368 80240978 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D7A36C 8024097C 3C014334 */  lui       $at, 0x4334
/* D7A370 80240980 44812000 */  mtc1      $at, $f4
/* D7A374 80240984 00000000 */  nop
/* D7A378 80240988 4600203C */  c.lt.s    $f4, $f0
/* D7A37C 8024098C 00000000 */  nop
/* D7A380 80240990 4500000C */  bc1f      .L802409C4
/* D7A384 80240994 00000000 */   nop
/* D7A388 80240998 3C014387 */  lui       $at, 0x4387
/* D7A38C 8024099C 44812000 */  mtc1      $at, $f4
/* D7A390 802409A0 00000000 */  nop
/* D7A394 802409A4 4604003E */  c.le.s    $f0, $f4
/* D7A398 802409A8 00000000 */  nop
/* D7A39C 802409AC 45000008 */  bc1f      .L802409D0
/* D7A3A0 802409B0 00000000 */   nop
/* D7A3A4 802409B4 3C014334 */  lui       $at, 0x4334
/* D7A3A8 802409B8 44812000 */  mtc1      $at, $f4
/* D7A3AC 802409BC 08090282 */  j         .L80240A08
/* D7A3B0 802409C0 46040501 */   sub.s    $f20, $f0, $f4
.L802409C4:
/* D7A3B4 802409C4 3C014387 */  lui       $at, 0x4387
/* D7A3B8 802409C8 44812000 */  mtc1      $at, $f4
/* D7A3BC 802409CC 00000000 */  nop
.L802409D0:
/* D7A3C0 802409D0 4600203C */  c.lt.s    $f4, $f0
/* D7A3C4 802409D4 00000000 */  nop
/* D7A3C8 802409D8 4500000A */  bc1f      .L80240A04
/* D7A3CC 802409DC 00000000 */   nop
/* D7A3D0 802409E0 3C0143B4 */  lui       $at, 0x43b4
/* D7A3D4 802409E4 44811000 */  mtc1      $at, $f2
/* D7A3D8 802409E8 00000000 */  nop
/* D7A3DC 802409EC 4602003E */  c.le.s    $f0, $f2
/* D7A3E0 802409F0 00000000 */  nop
/* D7A3E4 802409F4 45000003 */  bc1f      .L80240A04
/* D7A3E8 802409F8 00000000 */   nop
/* D7A3EC 802409FC 08090282 */  j         .L80240A08
/* D7A3F0 80240A00 46001501 */   sub.s    $f20, $f2, $f0
.L80240A04:
/* D7A3F4 80240A04 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L80240A08:
/* D7A3F8 80240A08 3C0141C8 */  lui       $at, 0x41c8
/* D7A3FC 80240A0C 44810000 */  mtc1      $at, $f0
/* D7A400 80240A10 00000000 */  nop
/* D7A404 80240A14 4600A003 */  div.s     $f0, $f20, $f0
/* D7A408 80240A18 4600010D */  trunc.w.s $f4, $f0
/* D7A40C 80240A1C 44072000 */  mfc1      $a3, $f4
/* D7A410 80240A20 00000000 */  nop
/* D7A414 80240A24 00071100 */  sll       $v0, $a3, 4
/* D7A418 80240A28 00471023 */  subu      $v0, $v0, $a3
/* D7A41C 80240A2C 00021080 */  sll       $v0, $v0, 2
/* D7A420 80240A30 02A23823 */  subu      $a3, $s5, $v0
/* D7A424 80240A34 28E20064 */  slti      $v0, $a3, 0x64
/* D7A428 80240A38 54400001 */  bnel      $v0, $zero, .L80240A40
/* D7A42C 80240A3C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A40:
/* D7A430 80240A40 24040001 */  addiu     $a0, $zero, 1
/* D7A434 80240A44 2405FFFF */  addiu     $a1, $zero, -1
/* D7A438 80240A48 24060006 */  addiu     $a2, $zero, 6
/* D7A43C 80240A4C AFA70010 */  sw        $a3, 0x10($sp)
/* D7A440 80240A50 AFA70014 */  sw        $a3, 0x14($sp)
/* D7A444 80240A54 AFB50018 */  sw        $s5, 0x18($sp)
/* D7A448 80240A58 0C0B77B9 */  jal       func_802DDEE4
/* D7A44C 80240A5C AFA0001C */   sw       $zero, 0x1c($sp)
/* D7A450 80240A60 4405A000 */  mfc1      $a1, $f20
/* D7A454 80240A64 4406B000 */  mfc1      $a2, $f22
/* D7A458 80240A68 3C07BF80 */  lui       $a3, 0xbf80
/* D7A45C 80240A6C 0200202D */  daddu     $a0, $s0, $zero
/* D7A460 80240A70 0C019EC8 */  jal       guRotateF
/* D7A464 80240A74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7A468 80240A78 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7A46C 80240A7C 0C00A6C9 */  jal       clamp_angle
/* D7A470 80240A80 00000000 */   nop
/* D7A474 80240A84 44050000 */  mfc1      $a1, $f0
/* D7A478 80240A88 4406B000 */  mfc1      $a2, $f22
/* D7A47C 80240A8C 4407B000 */  mfc1      $a3, $f22
/* D7A480 80240A90 3C013F80 */  lui       $at, 0x3f80
/* D7A484 80240A94 44812000 */  mtc1      $at, $f4
/* D7A488 80240A98 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A48C 80240A9C 0C019EC8 */  jal       guRotateF
/* D7A490 80240AA0 E7A40010 */   swc1     $f4, 0x10($sp)
/* D7A494 80240AA4 0200202D */  daddu     $a0, $s0, $zero
/* D7A498 80240AA8 27A50020 */  addiu     $a1, $sp, 0x20
/* D7A49C 80240AAC 0C019D80 */  jal       guMtxCatF
/* D7A4A0 80240AB0 00A0302D */   daddu    $a2, $a1, $zero
/* D7A4A4 80240AB4 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D7A4A8 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D7A4AC 80240ABC 080902E2 */  j         .L80240B88
/* D7A4B0 80240AC0 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240AC4:
/* D7A4B4 80240AC4 0260202D */  daddu     $a0, $s3, $zero
/* D7A4B8 80240AC8 27A50120 */  addiu     $a1, $sp, 0x120
/* D7A4BC 80240ACC 27A60124 */  addiu     $a2, $sp, 0x124
/* D7A4C0 80240AD0 0C03964E */  jal       func_800E5938
/* D7A4C4 80240AD4 27A70128 */   addiu    $a3, $sp, 0x128
/* D7A4C8 80240AD8 8FA60124 */  lw        $a2, 0x124($sp)
/* D7A4CC 80240ADC 3C028000 */  lui       $v0, 0x8000
/* D7A4D0 80240AE0 14C20004 */  bne       $a2, $v0, .L80240AF4
/* D7A4D4 80240AE4 46000606 */   mov.s    $f24, $f0
/* D7A4D8 80240AE8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D7A4DC 80240AEC 080902C1 */  j         .L80240B04
/* D7A4E0 80240AF0 24040001 */   addiu    $a0, $zero, 1
.L80240AF4:
/* D7A4E4 80240AF4 4486D000 */  mtc1      $a2, $f26
/* D7A4E8 80240AF8 00000000 */  nop
/* D7A4EC 80240AFC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D7A4F0 80240B00 24040001 */  addiu     $a0, $zero, 1
.L80240B04:
/* D7A4F4 80240B04 2405FFFF */  addiu     $a1, $zero, -1
/* D7A4F8 80240B08 24060007 */  addiu     $a2, $zero, 7
/* D7A4FC 80240B0C 0000382D */  daddu     $a3, $zero, $zero
/* D7A500 80240B10 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D7A504 80240B14 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D7A508 80240B18 24020040 */  addiu     $v0, $zero, 0x40
/* D7A50C 80240B1C AFA00010 */  sw        $zero, 0x10($sp)
/* D7A510 80240B20 AFA00014 */  sw        $zero, 0x14($sp)
/* D7A514 80240B24 AFA20018 */  sw        $v0, 0x18($sp)
/* D7A518 80240B28 0C0B77B9 */  jal       func_802DDEE4
/* D7A51C 80240B2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D7A520 80240B30 4405A000 */  mfc1      $a1, $f20
/* D7A524 80240B34 4406B000 */  mfc1      $a2, $f22
/* D7A528 80240B38 3C07BF80 */  lui       $a3, 0xbf80
/* D7A52C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A530 80240B40 0C019EC8 */  jal       guRotateF
/* D7A534 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7A538 80240B48 4405A000 */  mfc1      $a1, $f20
/* D7A53C 80240B4C 4406B000 */  mfc1      $a2, $f22
/* D7A540 80240B50 3C07BF80 */  lui       $a3, 0xbf80
/* D7A544 80240B54 0200202D */  daddu     $a0, $s0, $zero
/* D7A548 80240B58 0C019EC8 */  jal       guRotateF
/* D7A54C 80240B5C E7B60010 */   swc1     $f22, 0x10($sp)
/* D7A550 80240B60 4405C000 */  mfc1      $a1, $f24
/* D7A554 80240B64 4406B000 */  mfc1      $a2, $f22
/* D7A558 80240B68 3C073F80 */  lui       $a3, 0x3f80
/* D7A55C 80240B6C 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A560 80240B70 0C019EC8 */  jal       guRotateF
/* D7A564 80240B74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7A568 80240B78 0200202D */  daddu     $a0, $s0, $zero
/* D7A56C 80240B7C 27A50020 */  addiu     $a1, $sp, 0x20
/* D7A570 80240B80 0C019D80 */  jal       guMtxCatF
/* D7A574 80240B84 00A0302D */   daddu    $a2, $a1, $zero
.L80240B88:
/* D7A578 80240B88 862200B0 */  lh        $v0, 0xb0($s1)
/* D7A57C 80240B8C 3C013F00 */  lui       $at, 0x3f00
/* D7A580 80240B90 44812000 */  mtc1      $at, $f4
/* D7A584 80240B94 00021023 */  negu      $v0, $v0
/* D7A588 80240B98 44820000 */  mtc1      $v0, $f0
/* D7A58C 80240B9C 00000000 */  nop
/* D7A590 80240BA0 46800020 */  cvt.s.w   $f0, $f0
/* D7A594 80240BA4 46040102 */  mul.s     $f4, $f0, $f4
/* D7A598 80240BA8 00000000 */  nop
/* D7A59C 80240BAC 4405B000 */  mfc1      $a1, $f22
/* D7A5A0 80240BB0 4407B000 */  mfc1      $a3, $f22
/* D7A5A4 80240BB4 44062000 */  mfc1      $a2, $f4
/* D7A5A8 80240BB8 0C019E40 */  jal       guTranslateF
/* D7A5AC 80240BBC 0240202D */   daddu    $a0, $s2, $zero
/* D7A5B0 80240BC0 0240202D */  daddu     $a0, $s2, $zero
/* D7A5B4 80240BC4 27A50020 */  addiu     $a1, $sp, 0x20
/* D7A5B8 80240BC8 0C019D80 */  jal       guMtxCatF
/* D7A5BC 80240BCC 00A0302D */   daddu    $a2, $a1, $zero
/* D7A5C0 80240BD0 4405A000 */  mfc1      $a1, $f20
/* D7A5C4 80240BD4 4406B000 */  mfc1      $a2, $f22
/* D7A5C8 80240BD8 3C073F80 */  lui       $a3, 0x3f80
/* D7A5CC 80240BDC 0200202D */  daddu     $a0, $s0, $zero
/* D7A5D0 80240BE0 0C019EC8 */  jal       guRotateF
/* D7A5D4 80240BE4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7A5D8 80240BE8 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A5DC 80240BEC 0200282D */  daddu     $a1, $s0, $zero
/* D7A5E0 80240BF0 0C019D80 */  jal       guMtxCatF
/* D7A5E4 80240BF4 0080302D */   daddu    $a2, $a0, $zero
/* D7A5E8 80240BF8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D7A5EC 80240BFC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7A5F0 80240C00 4406B000 */  mfc1      $a2, $f22
/* D7A5F4 80240C04 3C073F80 */  lui       $a3, 0x3f80
/* D7A5F8 80240C08 0C019EC8 */  jal       guRotateF
/* D7A5FC 80240C0C 0200202D */   daddu    $a0, $s0, $zero
/* D7A600 80240C10 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A604 80240C14 0200282D */  daddu     $a1, $s0, $zero
/* D7A608 80240C18 0C019D80 */  jal       guMtxCatF
/* D7A60C 80240C1C 0080302D */   daddu    $a2, $a0, $zero
/* D7A610 80240C20 862200B0 */  lh        $v0, 0xb0($s1)
/* D7A614 80240C24 3C013F00 */  lui       $at, 0x3f00
/* D7A618 80240C28 44812000 */  mtc1      $at, $f4
/* D7A61C 80240C2C 44820000 */  mtc1      $v0, $f0
/* D7A620 80240C30 00000000 */  nop
/* D7A624 80240C34 46800020 */  cvt.s.w   $f0, $f0
/* D7A628 80240C38 46040102 */  mul.s     $f4, $f0, $f4
/* D7A62C 80240C3C 00000000 */  nop
/* D7A630 80240C40 4405B000 */  mfc1      $a1, $f22
/* D7A634 80240C44 4407B000 */  mfc1      $a3, $f22
/* D7A638 80240C48 44062000 */  mfc1      $a2, $f4
/* D7A63C 80240C4C 0C019E40 */  jal       guTranslateF
/* D7A640 80240C50 0240202D */   daddu    $a0, $s2, $zero
/* D7A644 80240C54 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A648 80240C58 0240282D */  daddu     $a1, $s2, $zero
/* D7A64C 80240C5C 0C019D80 */  jal       guMtxCatF
/* D7A650 80240C60 0080302D */   daddu    $a2, $a0, $zero
/* D7A654 80240C64 3C013F36 */  lui       $at, 0x3f36
/* D7A658 80240C68 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7A65C 80240C6C 44810000 */  mtc1      $at, $f0
/* D7A660 80240C70 0280202D */  daddu     $a0, $s4, $zero
/* D7A664 80240C74 44050000 */  mfc1      $a1, $f0
/* D7A668 80240C78 3C06BF36 */  lui       $a2, 0xbf36
/* D7A66C 80240C7C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D7A670 80240C80 0C019DF0 */  jal       guScaleF
/* D7A674 80240C84 00A0382D */   daddu    $a3, $a1, $zero
/* D7A678 80240C88 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A67C 80240C8C 0280282D */  daddu     $a1, $s4, $zero
/* D7A680 80240C90 0C019D80 */  jal       guMtxCatF
/* D7A684 80240C94 0080302D */   daddu    $a2, $a0, $zero
/* D7A688 80240C98 4600D687 */  neg.s     $f26, $f26
/* D7A68C 80240C9C 4405F000 */  mfc1      $a1, $f30
/* D7A690 80240CA0 4407E000 */  mfc1      $a3, $f28
/* D7A694 80240CA4 4406D000 */  mfc1      $a2, $f26
/* D7A698 80240CA8 0C019E40 */  jal       guTranslateF
/* D7A69C 80240CAC 0240202D */   daddu    $a0, $s2, $zero
/* D7A6A0 80240CB0 27A40020 */  addiu     $a0, $sp, 0x20
/* D7A6A4 80240CB4 0240282D */  daddu     $a1, $s2, $zero
/* D7A6A8 80240CB8 0C019D80 */  jal       guMtxCatF
/* D7A6AC 80240CBC 0080302D */   daddu    $a2, $a0, $zero
/* D7A6B0 80240CC0 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7A6B4 80240CC4 3C0142B4 */  lui       $at, 0x42b4
/* D7A6B8 80240CC8 44810000 */  mtc1      $at, $f0
/* D7A6BC 80240CCC 00000000 */  nop
/* D7A6C0 80240CD0 4602003E */  c.le.s    $f0, $f2
/* D7A6C4 80240CD4 00000000 */  nop
/* D7A6C8 80240CD8 4500000A */  bc1f      .L80240D04
/* D7A6CC 80240CDC 24040001 */   addiu    $a0, $zero, 1
/* D7A6D0 80240CE0 3C014387 */  lui       $at, 0x4387
/* D7A6D4 80240CE4 44812000 */  mtc1      $at, $f4
/* D7A6D8 80240CE8 00000000 */  nop
/* D7A6DC 80240CEC 4604103C */  c.lt.s    $f2, $f4
/* D7A6E0 80240CF0 00000000 */  nop
/* D7A6E4 80240CF4 45000004 */  bc1f      .L80240D08
/* D7A6E8 80240CF8 27A20020 */   addiu    $v0, $sp, 0x20
/* D7A6EC 80240CFC 3C041000 */  lui       $a0, 0x1000
/* D7A6F0 80240D00 34840001 */  ori       $a0, $a0, 1
.L80240D04:
/* D7A6F4 80240D04 27A20020 */  addiu     $v0, $sp, 0x20
.L80240D08:
/* D7A6F8 80240D08 AFA20010 */  sw        $v0, 0x10($sp)
/* D7A6FC 80240D0C 0000282D */  daddu     $a1, $zero, $zero
/* D7A700 80240D10 00A0302D */  daddu     $a2, $a1, $zero
/* D7A704 80240D14 0C0B7710 */  jal       render_sprite
/* D7A708 80240D18 00A0382D */   daddu    $a3, $a1, $zero
/* D7A70C 80240D1C 26730001 */  addiu     $s3, $s3, 1
/* D7A710 80240D20 2A620002 */  slti      $v0, $s3, 2
/* D7A714 80240D24 1440FEF6 */  bnez      $v0, .L80240900
/* D7A718 80240D28 00000000 */   nop
/* D7A71C 80240D2C 8FBF014C */  lw        $ra, 0x14c($sp)
/* D7A720 80240D30 8FB60148 */  lw        $s6, 0x148($sp)
/* D7A724 80240D34 8FB50144 */  lw        $s5, 0x144($sp)
/* D7A728 80240D38 8FB40140 */  lw        $s4, 0x140($sp)
/* D7A72C 80240D3C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D7A730 80240D40 8FB20138 */  lw        $s2, 0x138($sp)
/* D7A734 80240D44 8FB10134 */  lw        $s1, 0x134($sp)
/* D7A738 80240D48 8FB00130 */  lw        $s0, 0x130($sp)
/* D7A73C 80240D4C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D7A740 80240D50 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D7A744 80240D54 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D7A748 80240D58 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D7A74C 80240D5C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D7A750 80240D60 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D7A754 80240D64 03E00008 */  jr        $ra
/* D7A758 80240D68 27BD0180 */   addiu    $sp, $sp, 0x180
