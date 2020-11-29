.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D7D3C0
/* D7D3C0 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D7D3C4 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D7D3C8 80240878 4480B000 */  mtc1      $zero, $f22
/* D7D3CC 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D7D3D0 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D7D3D4 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D7D3D8 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D7D3DC 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D7D3E0 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D7D3E4 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D7D3E8 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D7D3EC 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D7D3F0 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D7D3F4 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D7D3F8 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D7D3FC 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D7D400 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D7D404 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D7D408 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D7D40C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D7D410 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D7D414 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D7D418 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D7D41C 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D7D420 802408D0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D7D424 802408D4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D7D428 802408D8 00031080 */  sll       $v0, $v1, 2
/* D7D42C 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D7D430 802408E0 00021080 */  sll       $v0, $v0, 2
/* D7D434 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D7D438 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D7D43C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D7D440 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D7D444 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D7D448 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D7D44C 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D7D450 80240900 46000507 */   neg.s    $f20, $f0
/* D7D454 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7D458 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D7D45C 8024090C 44810000 */  mtc1      $at, $f0
/* D7D460 80240910 00000000 */  nop       
/* D7D464 80240914 4602003C */  c.lt.s    $f0, $f2
/* D7D468 80240918 00000000 */  nop       
/* D7D46C 8024091C 4500000A */  bc1f      .L80240948
/* D7D470 80240920 00000000 */   nop      
/* D7D474 80240924 3C014334 */  lui       $at, 0x4334
/* D7D478 80240928 44812000 */  mtc1      $at, $f4
/* D7D47C 8024092C 00000000 */  nop       
/* D7D480 80240930 4604103E */  c.le.s    $f2, $f4
/* D7D484 80240934 00000000 */  nop       
/* D7D488 80240938 45000003 */  bc1f      .L80240948
/* D7D48C 8024093C 00000000 */   nop      
/* D7D490 80240940 08090276 */  j         .L802409D8
/* D7D494 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D7D498 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D7D49C 8024094C 3C014334 */  lui       $at, 0x4334
/* D7D4A0 80240950 44812000 */  mtc1      $at, $f4
/* D7D4A4 80240954 00000000 */  nop       
/* D7D4A8 80240958 4600203C */  c.lt.s    $f4, $f0
/* D7D4AC 8024095C 00000000 */  nop       
/* D7D4B0 80240960 4500000C */  bc1f      .L80240994
/* D7D4B4 80240964 00000000 */   nop      
/* D7D4B8 80240968 3C014387 */  lui       $at, 0x4387
/* D7D4BC 8024096C 44812000 */  mtc1      $at, $f4
/* D7D4C0 80240970 00000000 */  nop       
/* D7D4C4 80240974 4604003E */  c.le.s    $f0, $f4
/* D7D4C8 80240978 00000000 */  nop       
/* D7D4CC 8024097C 45000008 */  bc1f      .L802409A0
/* D7D4D0 80240980 00000000 */   nop      
/* D7D4D4 80240984 3C014334 */  lui       $at, 0x4334
/* D7D4D8 80240988 44812000 */  mtc1      $at, $f4
/* D7D4DC 8024098C 08090276 */  j         .L802409D8
/* D7D4E0 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D7D4E4 80240994 3C014387 */  lui       $at, 0x4387
/* D7D4E8 80240998 44812000 */  mtc1      $at, $f4
/* D7D4EC 8024099C 00000000 */  nop       
.L802409A0:
/* D7D4F0 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D7D4F4 802409A4 00000000 */  nop       
/* D7D4F8 802409A8 4500000A */  bc1f      .L802409D4
/* D7D4FC 802409AC 00000000 */   nop      
/* D7D500 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D7D504 802409B4 44811000 */  mtc1      $at, $f2
/* D7D508 802409B8 00000000 */  nop       
/* D7D50C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D7D510 802409C0 00000000 */  nop       
/* D7D514 802409C4 45000003 */  bc1f      .L802409D4
/* D7D518 802409C8 00000000 */   nop      
/* D7D51C 802409CC 08090276 */  j         .L802409D8
/* D7D520 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D7D524 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D7D528 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D7D52C 802409DC 44810000 */  mtc1      $at, $f0
/* D7D530 802409E0 00000000 */  nop       
/* D7D534 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D7D538 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D7D53C 802409EC 44072000 */  mfc1      $a3, $f4
/* D7D540 802409F0 00000000 */  nop       
/* D7D544 802409F4 00071100 */  sll       $v0, $a3, 4
/* D7D548 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D7D54C 802409FC 00021080 */  sll       $v0, $v0, 2
/* D7D550 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D7D554 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D7D558 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D7D55C 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D7D560 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D7D564 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D7D568 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D7D56C 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D7D570 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D7D574 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D7D578 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D7D57C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D7D580 80240A30 4405A000 */  mfc1      $a1, $f20
/* D7D584 80240A34 4406B000 */  mfc1      $a2, $f22
/* D7D588 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D7D58C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D7D590 80240A40 0C019EC8 */  jal       guRotateF
/* D7D594 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7D598 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7D59C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D7D5A0 80240A50 00000000 */   nop      
/* D7D5A4 80240A54 44050000 */  mfc1      $a1, $f0
/* D7D5A8 80240A58 4406B000 */  mfc1      $a2, $f22
/* D7D5AC 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D7D5B0 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D7D5B4 80240A64 44812000 */  mtc1      $at, $f4
/* D7D5B8 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D5BC 80240A6C 0C019EC8 */  jal       guRotateF
/* D7D5C0 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D7D5C4 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D7D5C8 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D7D5CC 80240A7C 0C019D80 */  jal       guMtxCatF
/* D7D5D0 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D7D5D4 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D7D5D8 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D7D5DC 80240A8C 080902D6 */  j         .L80240B58
/* D7D5E0 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D7D5E4 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D7D5E8 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D7D5EC 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D7D5F0 80240AA0 0C03964E */  jal       func_800E5938
/* D7D5F4 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D7D5F8 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D7D5FC 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D7D600 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D7D604 80240AB4 46000606 */   mov.s    $f24, $f0
/* D7D608 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D7D60C 80240ABC 080902B5 */  j         .L80240AD4
/* D7D610 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D7D614 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D7D618 80240AC8 00000000 */  nop       
/* D7D61C 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D7D620 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D7D624 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D7D628 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D7D62C 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D7D630 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D7D634 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D7D638 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D7D63C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D7D640 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D7D644 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D7D648 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D7D64C 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D7D650 80240B00 4405A000 */  mfc1      $a1, $f20
/* D7D654 80240B04 4406B000 */  mfc1      $a2, $f22
/* D7D658 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D7D65C 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D660 80240B10 0C019EC8 */  jal       guRotateF
/* D7D664 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7D668 80240B18 4405A000 */  mfc1      $a1, $f20
/* D7D66C 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D7D670 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D7D674 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D7D678 80240B28 0C019EC8 */  jal       guRotateF
/* D7D67C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D7D680 80240B30 4405C000 */  mfc1      $a1, $f24
/* D7D684 80240B34 4406B000 */  mfc1      $a2, $f22
/* D7D688 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D7D68C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D690 80240B40 0C019EC8 */  jal       guRotateF
/* D7D694 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7D698 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D7D69C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D7D6A0 80240B50 0C019D80 */  jal       guMtxCatF
/* D7D6A4 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D7D6A8 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D7D6AC 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D7D6B0 80240B60 44812000 */  mtc1      $at, $f4
/* D7D6B4 80240B64 00021023 */  negu      $v0, $v0
/* D7D6B8 80240B68 44820000 */  mtc1      $v0, $f0
/* D7D6BC 80240B6C 00000000 */  nop       
/* D7D6C0 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D7D6C4 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D7D6C8 80240B78 00000000 */  nop       
/* D7D6CC 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D7D6D0 80240B80 4407B000 */  mfc1      $a3, $f22
/* D7D6D4 80240B84 44062000 */  mfc1      $a2, $f4
/* D7D6D8 80240B88 0C019E40 */  jal       guTranslateF
/* D7D6DC 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D7D6E0 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D7D6E4 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D7D6E8 80240B98 0C019D80 */  jal       guMtxCatF
/* D7D6EC 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D7D6F0 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D7D6F4 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D7D6F8 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D7D6FC 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D7D700 80240BB0 0C019EC8 */  jal       guRotateF
/* D7D704 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D7D708 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D70C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D7D710 80240BC0 0C019D80 */  jal       guMtxCatF
/* D7D714 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D7D718 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D7D71C 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7D720 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D7D724 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D7D728 80240BD8 0C019EC8 */  jal       guRotateF
/* D7D72C 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D7D730 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D734 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D7D738 80240BE8 0C019D80 */  jal       guMtxCatF
/* D7D73C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D7D740 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D7D744 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D7D748 80240BF8 44812000 */  mtc1      $at, $f4
/* D7D74C 80240BFC 44820000 */  mtc1      $v0, $f0
/* D7D750 80240C00 00000000 */  nop       
/* D7D754 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D7D758 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D7D75C 80240C0C 00000000 */  nop       
/* D7D760 80240C10 4405B000 */  mfc1      $a1, $f22
/* D7D764 80240C14 4407B000 */  mfc1      $a3, $f22
/* D7D768 80240C18 44062000 */  mfc1      $a2, $f4
/* D7D76C 80240C1C 0C019E40 */  jal       guTranslateF
/* D7D770 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D7D774 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D778 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D7D77C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D7D780 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D7D784 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D7D788 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7D78C 80240C3C 44810000 */  mtc1      $at, $f0
/* D7D790 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D7D794 80240C44 44050000 */  mfc1      $a1, $f0
/* D7D798 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D7D79C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D7D7A0 80240C50 0C019DF0 */  jal       guScaleF
/* D7D7A4 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D7D7A8 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D7AC 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D7D7B0 80240C60 0C019D80 */  jal       guMtxCatF
/* D7D7B4 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D7D7B8 80240C68 4600D687 */  neg.s     $f26, $f26
/* D7D7BC 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D7D7C0 80240C70 4407E000 */  mfc1      $a3, $f28
/* D7D7C4 80240C74 4406D000 */  mfc1      $a2, $f26
/* D7D7C8 80240C78 0C019E40 */  jal       guTranslateF
/* D7D7CC 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D7D7D0 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D7D7D4 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D7D7D8 80240C88 0C019D80 */  jal       guMtxCatF
/* D7D7DC 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D7D7E0 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7D7E4 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D7D7E8 80240C98 44810000 */  mtc1      $at, $f0
/* D7D7EC 80240C9C 00000000 */  nop       
/* D7D7F0 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D7D7F4 80240CA4 00000000 */  nop       
/* D7D7F8 80240CA8 4500000A */  bc1f      .L80240CD4
/* D7D7FC 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D7D800 80240CB0 3C014387 */  lui       $at, 0x4387
/* D7D804 80240CB4 44812000 */  mtc1      $at, $f4
/* D7D808 80240CB8 00000000 */  nop       
/* D7D80C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D7D810 80240CC0 00000000 */  nop       
/* D7D814 80240CC4 45000004 */  bc1f      .L80240CD8
/* D7D818 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D7D81C 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D7D820 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D7D824 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D7D828 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D7D82C 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D7D830 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D7D834 80240CE4 0C0B7710 */  jal       render_sprite
/* D7D838 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D7D83C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D7D840 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D7D844 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D7D848 80240CF8 00000000 */   nop      
/* D7D84C 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D7D850 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D7D854 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D7D858 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D7D85C 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D7D860 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D7D864 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D7D868 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D7D86C 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D7D870 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D7D874 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D7D878 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D7D87C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D7D880 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D7D884 80240D34 03E00008 */  jr        $ra
/* D7D888 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
