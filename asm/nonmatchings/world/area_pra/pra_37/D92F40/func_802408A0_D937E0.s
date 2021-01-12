.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A0_D937E0
/* D937E0 802408A0 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D937E4 802408A4 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D937E8 802408A8 4480B000 */  mtc1      $zero, $f22
/* D937EC 802408AC AFB10134 */  sw        $s1, 0x134($sp)
/* D937F0 802408B0 0080882D */  daddu     $s1, $a0, $zero
/* D937F4 802408B4 AFB3013C */  sw        $s3, 0x13c($sp)
/* D937F8 802408B8 0000982D */  daddu     $s3, $zero, $zero
/* D937FC 802408BC AFB60148 */  sw        $s6, 0x148($sp)
/* D93800 802408C0 3C16800B */  lui       $s6, %hi(gCameras)
/* D93804 802408C4 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D93808 802408C8 AFB50144 */  sw        $s5, 0x144($sp)
/* D9380C 802408CC 241500FF */  addiu     $s5, $zero, 0xff
/* D93810 802408D0 AFB00130 */  sw        $s0, 0x130($sp)
/* D93814 802408D4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D93818 802408D8 AFB20138 */  sw        $s2, 0x138($sp)
/* D9381C 802408DC 27B20060 */  addiu     $s2, $sp, 0x60
/* D93820 802408E0 AFB40140 */  sw        $s4, 0x140($sp)
/* D93824 802408E4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D93828 802408E8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D9382C 802408EC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D93830 802408F0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D93834 802408F4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D93838 802408F8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D9383C 802408FC F7B40150 */  sdc1      $f20, 0x150($sp)
.L80240900:
/* D93840 80240900 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D93844 80240904 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D93848 80240908 00031080 */  sll       $v0, $v1, 2
/* D9384C 8024090C 00431021 */  addu      $v0, $v0, $v1
/* D93850 80240910 00021080 */  sll       $v0, $v0, 2
/* D93854 80240914 00431023 */  subu      $v0, $v0, $v1
/* D93858 80240918 000218C0 */  sll       $v1, $v0, 3
/* D9385C 8024091C 00431021 */  addu      $v0, $v0, $v1
/* D93860 80240920 000210C0 */  sll       $v0, $v0, 3
/* D93864 80240924 00561021 */  addu      $v0, $v0, $s6
/* D93868 80240928 C440006C */  lwc1      $f0, 0x6c($v0)
/* D9386C 8024092C 16600065 */  bnez      $s3, .L80240AC4
/* D93870 80240930 46000507 */   neg.s    $f20, $f0
/* D93874 80240934 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D93878 80240938 3C0142B4 */  lui       $at, 0x42b4
/* D9387C 8024093C 44810000 */  mtc1      $at, $f0
/* D93880 80240940 00000000 */  nop
/* D93884 80240944 4602003C */  c.lt.s    $f0, $f2
/* D93888 80240948 00000000 */  nop
/* D9388C 8024094C 4500000A */  bc1f      .L80240978
/* D93890 80240950 00000000 */   nop
/* D93894 80240954 3C014334 */  lui       $at, 0x4334
/* D93898 80240958 44812000 */  mtc1      $at, $f4
/* D9389C 8024095C 00000000 */  nop
/* D938A0 80240960 4604103E */  c.le.s    $f2, $f4
/* D938A4 80240964 00000000 */  nop
/* D938A8 80240968 45000003 */  bc1f      .L80240978
/* D938AC 8024096C 00000000 */   nop
/* D938B0 80240970 08090282 */  j         .L80240A08
/* D938B4 80240974 46022501 */   sub.s    $f20, $f4, $f2
.L80240978:
/* D938B8 80240978 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D938BC 8024097C 3C014334 */  lui       $at, 0x4334
/* D938C0 80240980 44812000 */  mtc1      $at, $f4
/* D938C4 80240984 00000000 */  nop
/* D938C8 80240988 4600203C */  c.lt.s    $f4, $f0
/* D938CC 8024098C 00000000 */  nop
/* D938D0 80240990 4500000C */  bc1f      .L802409C4
/* D938D4 80240994 00000000 */   nop
/* D938D8 80240998 3C014387 */  lui       $at, 0x4387
/* D938DC 8024099C 44812000 */  mtc1      $at, $f4
/* D938E0 802409A0 00000000 */  nop
/* D938E4 802409A4 4604003E */  c.le.s    $f0, $f4
/* D938E8 802409A8 00000000 */  nop
/* D938EC 802409AC 45000008 */  bc1f      .L802409D0
/* D938F0 802409B0 00000000 */   nop
/* D938F4 802409B4 3C014334 */  lui       $at, 0x4334
/* D938F8 802409B8 44812000 */  mtc1      $at, $f4
/* D938FC 802409BC 08090282 */  j         .L80240A08
/* D93900 802409C0 46040501 */   sub.s    $f20, $f0, $f4
.L802409C4:
/* D93904 802409C4 3C014387 */  lui       $at, 0x4387
/* D93908 802409C8 44812000 */  mtc1      $at, $f4
/* D9390C 802409CC 00000000 */  nop
.L802409D0:
/* D93910 802409D0 4600203C */  c.lt.s    $f4, $f0
/* D93914 802409D4 00000000 */  nop
/* D93918 802409D8 4500000A */  bc1f      .L80240A04
/* D9391C 802409DC 00000000 */   nop
/* D93920 802409E0 3C0143B4 */  lui       $at, 0x43b4
/* D93924 802409E4 44811000 */  mtc1      $at, $f2
/* D93928 802409E8 00000000 */  nop
/* D9392C 802409EC 4602003E */  c.le.s    $f0, $f2
/* D93930 802409F0 00000000 */  nop
/* D93934 802409F4 45000003 */  bc1f      .L80240A04
/* D93938 802409F8 00000000 */   nop
/* D9393C 802409FC 08090282 */  j         .L80240A08
/* D93940 80240A00 46001501 */   sub.s    $f20, $f2, $f0
.L80240A04:
/* D93944 80240A04 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L80240A08:
/* D93948 80240A08 3C0141C8 */  lui       $at, 0x41c8
/* D9394C 80240A0C 44810000 */  mtc1      $at, $f0
/* D93950 80240A10 00000000 */  nop
/* D93954 80240A14 4600A003 */  div.s     $f0, $f20, $f0
/* D93958 80240A18 4600010D */  trunc.w.s $f4, $f0
/* D9395C 80240A1C 44072000 */  mfc1      $a3, $f4
/* D93960 80240A20 00000000 */  nop
/* D93964 80240A24 00071100 */  sll       $v0, $a3, 4
/* D93968 80240A28 00471023 */  subu      $v0, $v0, $a3
/* D9396C 80240A2C 00021080 */  sll       $v0, $v0, 2
/* D93970 80240A30 02A23823 */  subu      $a3, $s5, $v0
/* D93974 80240A34 28E20064 */  slti      $v0, $a3, 0x64
/* D93978 80240A38 54400001 */  bnel      $v0, $zero, .L80240A40
/* D9397C 80240A3C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A40:
/* D93980 80240A40 24040001 */  addiu     $a0, $zero, 1
/* D93984 80240A44 2405FFFF */  addiu     $a1, $zero, -1
/* D93988 80240A48 24060006 */  addiu     $a2, $zero, 6
/* D9398C 80240A4C AFA70010 */  sw        $a3, 0x10($sp)
/* D93990 80240A50 AFA70014 */  sw        $a3, 0x14($sp)
/* D93994 80240A54 AFB50018 */  sw        $s5, 0x18($sp)
/* D93998 80240A58 0C0B77B9 */  jal       func_802DDEE4
/* D9399C 80240A5C AFA0001C */   sw       $zero, 0x1c($sp)
/* D939A0 80240A60 4405A000 */  mfc1      $a1, $f20
/* D939A4 80240A64 4406B000 */  mfc1      $a2, $f22
/* D939A8 80240A68 3C07BF80 */  lui       $a3, 0xbf80
/* D939AC 80240A6C 0200202D */  daddu     $a0, $s0, $zero
/* D939B0 80240A70 0C019EC8 */  jal       guRotateF
/* D939B4 80240A74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D939B8 80240A78 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D939BC 80240A7C 0C00A6C9 */  jal       clamp_angle
/* D939C0 80240A80 00000000 */   nop
/* D939C4 80240A84 44050000 */  mfc1      $a1, $f0
/* D939C8 80240A88 4406B000 */  mfc1      $a2, $f22
/* D939CC 80240A8C 4407B000 */  mfc1      $a3, $f22
/* D939D0 80240A90 3C013F80 */  lui       $at, 0x3f80
/* D939D4 80240A94 44812000 */  mtc1      $at, $f4
/* D939D8 80240A98 27A40020 */  addiu     $a0, $sp, 0x20
/* D939DC 80240A9C 0C019EC8 */  jal       guRotateF
/* D939E0 80240AA0 E7A40010 */   swc1     $f4, 0x10($sp)
/* D939E4 80240AA4 0200202D */  daddu     $a0, $s0, $zero
/* D939E8 80240AA8 27A50020 */  addiu     $a1, $sp, 0x20
/* D939EC 80240AAC 0C019D80 */  jal       guMtxCatF
/* D939F0 80240AB0 00A0302D */   daddu    $a2, $a1, $zero
/* D939F4 80240AB4 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D939F8 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D939FC 80240ABC 080902E2 */  j         .L80240B88
/* D93A00 80240AC0 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240AC4:
/* D93A04 80240AC4 0260202D */  daddu     $a0, $s3, $zero
/* D93A08 80240AC8 27A50120 */  addiu     $a1, $sp, 0x120
/* D93A0C 80240ACC 27A60124 */  addiu     $a2, $sp, 0x124
/* D93A10 80240AD0 0C03964E */  jal       func_800E5938
/* D93A14 80240AD4 27A70128 */   addiu    $a3, $sp, 0x128
/* D93A18 80240AD8 8FA60124 */  lw        $a2, 0x124($sp)
/* D93A1C 80240ADC 3C028000 */  lui       $v0, 0x8000
/* D93A20 80240AE0 14C20004 */  bne       $a2, $v0, .L80240AF4
/* D93A24 80240AE4 46000606 */   mov.s    $f24, $f0
/* D93A28 80240AE8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D93A2C 80240AEC 080902C1 */  j         .L80240B04
/* D93A30 80240AF0 24040001 */   addiu    $a0, $zero, 1
.L80240AF4:
/* D93A34 80240AF4 4486D000 */  mtc1      $a2, $f26
/* D93A38 80240AF8 00000000 */  nop
/* D93A3C 80240AFC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D93A40 80240B00 24040001 */  addiu     $a0, $zero, 1
.L80240B04:
/* D93A44 80240B04 2405FFFF */  addiu     $a1, $zero, -1
/* D93A48 80240B08 24060007 */  addiu     $a2, $zero, 7
/* D93A4C 80240B0C 0000382D */  daddu     $a3, $zero, $zero
/* D93A50 80240B10 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D93A54 80240B14 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D93A58 80240B18 24020040 */  addiu     $v0, $zero, 0x40
/* D93A5C 80240B1C AFA00010 */  sw        $zero, 0x10($sp)
/* D93A60 80240B20 AFA00014 */  sw        $zero, 0x14($sp)
/* D93A64 80240B24 AFA20018 */  sw        $v0, 0x18($sp)
/* D93A68 80240B28 0C0B77B9 */  jal       func_802DDEE4
/* D93A6C 80240B2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D93A70 80240B30 4405A000 */  mfc1      $a1, $f20
/* D93A74 80240B34 4406B000 */  mfc1      $a2, $f22
/* D93A78 80240B38 3C07BF80 */  lui       $a3, 0xbf80
/* D93A7C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D93A80 80240B40 0C019EC8 */  jal       guRotateF
/* D93A84 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D93A88 80240B48 4405A000 */  mfc1      $a1, $f20
/* D93A8C 80240B4C 4406B000 */  mfc1      $a2, $f22
/* D93A90 80240B50 3C07BF80 */  lui       $a3, 0xbf80
/* D93A94 80240B54 0200202D */  daddu     $a0, $s0, $zero
/* D93A98 80240B58 0C019EC8 */  jal       guRotateF
/* D93A9C 80240B5C E7B60010 */   swc1     $f22, 0x10($sp)
/* D93AA0 80240B60 4405C000 */  mfc1      $a1, $f24
/* D93AA4 80240B64 4406B000 */  mfc1      $a2, $f22
/* D93AA8 80240B68 3C073F80 */  lui       $a3, 0x3f80
/* D93AAC 80240B6C 27A40020 */  addiu     $a0, $sp, 0x20
/* D93AB0 80240B70 0C019EC8 */  jal       guRotateF
/* D93AB4 80240B74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D93AB8 80240B78 0200202D */  daddu     $a0, $s0, $zero
/* D93ABC 80240B7C 27A50020 */  addiu     $a1, $sp, 0x20
/* D93AC0 80240B80 0C019D80 */  jal       guMtxCatF
/* D93AC4 80240B84 00A0302D */   daddu    $a2, $a1, $zero
.L80240B88:
/* D93AC8 80240B88 862200B0 */  lh        $v0, 0xb0($s1)
/* D93ACC 80240B8C 3C013F00 */  lui       $at, 0x3f00
/* D93AD0 80240B90 44812000 */  mtc1      $at, $f4
/* D93AD4 80240B94 00021023 */  negu      $v0, $v0
/* D93AD8 80240B98 44820000 */  mtc1      $v0, $f0
/* D93ADC 80240B9C 00000000 */  nop
/* D93AE0 80240BA0 46800020 */  cvt.s.w   $f0, $f0
/* D93AE4 80240BA4 46040102 */  mul.s     $f4, $f0, $f4
/* D93AE8 80240BA8 00000000 */  nop
/* D93AEC 80240BAC 4405B000 */  mfc1      $a1, $f22
/* D93AF0 80240BB0 4407B000 */  mfc1      $a3, $f22
/* D93AF4 80240BB4 44062000 */  mfc1      $a2, $f4
/* D93AF8 80240BB8 0C019E40 */  jal       guTranslateF
/* D93AFC 80240BBC 0240202D */   daddu    $a0, $s2, $zero
/* D93B00 80240BC0 0240202D */  daddu     $a0, $s2, $zero
/* D93B04 80240BC4 27A50020 */  addiu     $a1, $sp, 0x20
/* D93B08 80240BC8 0C019D80 */  jal       guMtxCatF
/* D93B0C 80240BCC 00A0302D */   daddu    $a2, $a1, $zero
/* D93B10 80240BD0 4405A000 */  mfc1      $a1, $f20
/* D93B14 80240BD4 4406B000 */  mfc1      $a2, $f22
/* D93B18 80240BD8 3C073F80 */  lui       $a3, 0x3f80
/* D93B1C 80240BDC 0200202D */  daddu     $a0, $s0, $zero
/* D93B20 80240BE0 0C019EC8 */  jal       guRotateF
/* D93B24 80240BE4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D93B28 80240BE8 27A40020 */  addiu     $a0, $sp, 0x20
/* D93B2C 80240BEC 0200282D */  daddu     $a1, $s0, $zero
/* D93B30 80240BF0 0C019D80 */  jal       guMtxCatF
/* D93B34 80240BF4 0080302D */   daddu    $a2, $a0, $zero
/* D93B38 80240BF8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D93B3C 80240BFC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D93B40 80240C00 4406B000 */  mfc1      $a2, $f22
/* D93B44 80240C04 3C073F80 */  lui       $a3, 0x3f80
/* D93B48 80240C08 0C019EC8 */  jal       guRotateF
/* D93B4C 80240C0C 0200202D */   daddu    $a0, $s0, $zero
/* D93B50 80240C10 27A40020 */  addiu     $a0, $sp, 0x20
/* D93B54 80240C14 0200282D */  daddu     $a1, $s0, $zero
/* D93B58 80240C18 0C019D80 */  jal       guMtxCatF
/* D93B5C 80240C1C 0080302D */   daddu    $a2, $a0, $zero
/* D93B60 80240C20 862200B0 */  lh        $v0, 0xb0($s1)
/* D93B64 80240C24 3C013F00 */  lui       $at, 0x3f00
/* D93B68 80240C28 44812000 */  mtc1      $at, $f4
/* D93B6C 80240C2C 44820000 */  mtc1      $v0, $f0
/* D93B70 80240C30 00000000 */  nop
/* D93B74 80240C34 46800020 */  cvt.s.w   $f0, $f0
/* D93B78 80240C38 46040102 */  mul.s     $f4, $f0, $f4
/* D93B7C 80240C3C 00000000 */  nop
/* D93B80 80240C40 4405B000 */  mfc1      $a1, $f22
/* D93B84 80240C44 4407B000 */  mfc1      $a3, $f22
/* D93B88 80240C48 44062000 */  mfc1      $a2, $f4
/* D93B8C 80240C4C 0C019E40 */  jal       guTranslateF
/* D93B90 80240C50 0240202D */   daddu    $a0, $s2, $zero
/* D93B94 80240C54 27A40020 */  addiu     $a0, $sp, 0x20
/* D93B98 80240C58 0240282D */  daddu     $a1, $s2, $zero
/* D93B9C 80240C5C 0C019D80 */  jal       guMtxCatF
/* D93BA0 80240C60 0080302D */   daddu    $a2, $a0, $zero
/* D93BA4 80240C64 3C013F36 */  lui       $at, 0x3f36
/* D93BA8 80240C68 3421DB6E */  ori       $at, $at, 0xdb6e
/* D93BAC 80240C6C 44810000 */  mtc1      $at, $f0
/* D93BB0 80240C70 0280202D */  daddu     $a0, $s4, $zero
/* D93BB4 80240C74 44050000 */  mfc1      $a1, $f0
/* D93BB8 80240C78 3C06BF36 */  lui       $a2, 0xbf36
/* D93BBC 80240C7C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D93BC0 80240C80 0C019DF0 */  jal       guScaleF
/* D93BC4 80240C84 00A0382D */   daddu    $a3, $a1, $zero
/* D93BC8 80240C88 27A40020 */  addiu     $a0, $sp, 0x20
/* D93BCC 80240C8C 0280282D */  daddu     $a1, $s4, $zero
/* D93BD0 80240C90 0C019D80 */  jal       guMtxCatF
/* D93BD4 80240C94 0080302D */   daddu    $a2, $a0, $zero
/* D93BD8 80240C98 4600D687 */  neg.s     $f26, $f26
/* D93BDC 80240C9C 4405F000 */  mfc1      $a1, $f30
/* D93BE0 80240CA0 4407E000 */  mfc1      $a3, $f28
/* D93BE4 80240CA4 4406D000 */  mfc1      $a2, $f26
/* D93BE8 80240CA8 0C019E40 */  jal       guTranslateF
/* D93BEC 80240CAC 0240202D */   daddu    $a0, $s2, $zero
/* D93BF0 80240CB0 27A40020 */  addiu     $a0, $sp, 0x20
/* D93BF4 80240CB4 0240282D */  daddu     $a1, $s2, $zero
/* D93BF8 80240CB8 0C019D80 */  jal       guMtxCatF
/* D93BFC 80240CBC 0080302D */   daddu    $a2, $a0, $zero
/* D93C00 80240CC0 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D93C04 80240CC4 3C0142B4 */  lui       $at, 0x42b4
/* D93C08 80240CC8 44810000 */  mtc1      $at, $f0
/* D93C0C 80240CCC 00000000 */  nop
/* D93C10 80240CD0 4602003E */  c.le.s    $f0, $f2
/* D93C14 80240CD4 00000000 */  nop
/* D93C18 80240CD8 4500000A */  bc1f      .L80240D04
/* D93C1C 80240CDC 24040001 */   addiu    $a0, $zero, 1
/* D93C20 80240CE0 3C014387 */  lui       $at, 0x4387
/* D93C24 80240CE4 44812000 */  mtc1      $at, $f4
/* D93C28 80240CE8 00000000 */  nop
/* D93C2C 80240CEC 4604103C */  c.lt.s    $f2, $f4
/* D93C30 80240CF0 00000000 */  nop
/* D93C34 80240CF4 45000004 */  bc1f      .L80240D08
/* D93C38 80240CF8 27A20020 */   addiu    $v0, $sp, 0x20
/* D93C3C 80240CFC 3C041000 */  lui       $a0, 0x1000
/* D93C40 80240D00 34840001 */  ori       $a0, $a0, 1
.L80240D04:
/* D93C44 80240D04 27A20020 */  addiu     $v0, $sp, 0x20
.L80240D08:
/* D93C48 80240D08 AFA20010 */  sw        $v0, 0x10($sp)
/* D93C4C 80240D0C 0000282D */  daddu     $a1, $zero, $zero
/* D93C50 80240D10 00A0302D */  daddu     $a2, $a1, $zero
/* D93C54 80240D14 0C0B7710 */  jal       render_sprite
/* D93C58 80240D18 00A0382D */   daddu    $a3, $a1, $zero
/* D93C5C 80240D1C 26730001 */  addiu     $s3, $s3, 1
/* D93C60 80240D20 2A620002 */  slti      $v0, $s3, 2
/* D93C64 80240D24 1440FEF6 */  bnez      $v0, .L80240900
/* D93C68 80240D28 00000000 */   nop
/* D93C6C 80240D2C 8FBF014C */  lw        $ra, 0x14c($sp)
/* D93C70 80240D30 8FB60148 */  lw        $s6, 0x148($sp)
/* D93C74 80240D34 8FB50144 */  lw        $s5, 0x144($sp)
/* D93C78 80240D38 8FB40140 */  lw        $s4, 0x140($sp)
/* D93C7C 80240D3C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D93C80 80240D40 8FB20138 */  lw        $s2, 0x138($sp)
/* D93C84 80240D44 8FB10134 */  lw        $s1, 0x134($sp)
/* D93C88 80240D48 8FB00130 */  lw        $s0, 0x130($sp)
/* D93C8C 80240D4C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D93C90 80240D50 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D93C94 80240D54 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D93C98 80240D58 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D93C9C 80240D5C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D93CA0 80240D60 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D93CA4 80240D64 03E00008 */  jr        $ra
/* D93CA8 80240D68 27BD0180 */   addiu    $sp, $sp, 0x180
