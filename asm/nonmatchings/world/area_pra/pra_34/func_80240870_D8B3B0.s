.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D8BC20
/* D8BC20 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D8BC24 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D8BC28 80240878 4480B000 */  mtc1      $zero, $f22
/* D8BC2C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D8BC30 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D8BC34 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D8BC38 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D8BC3C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D8BC40 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D8BC44 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D8BC48 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D8BC4C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D8BC50 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D8BC54 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D8BC58 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D8BC5C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D8BC60 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D8BC64 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D8BC68 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D8BC6C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D8BC70 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D8BC74 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D8BC78 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D8BC7C 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D8BC80 802408D0 3C03800A */  lui       $v1, 0x800a
/* D8BC84 802408D4 8463A634 */  lh        $v1, -0x59cc($v1)
/* D8BC88 802408D8 00031080 */  sll       $v0, $v1, 2
/* D8BC8C 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D8BC90 802408E0 00021080 */  sll       $v0, $v0, 2
/* D8BC94 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D8BC98 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D8BC9C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D8BCA0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D8BCA4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D8BCA8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D8BCAC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D8BCB0 80240900 46000507 */   neg.s    $f20, $f0
/* D8BCB4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8BCB8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D8BCBC 8024090C 44810000 */  mtc1      $at, $f0
/* D8BCC0 80240910 00000000 */  nop       
/* D8BCC4 80240914 4602003C */  c.lt.s    $f0, $f2
/* D8BCC8 80240918 00000000 */  nop       
/* D8BCCC 8024091C 4500000A */  bc1f      .L80240948
/* D8BCD0 80240920 00000000 */   nop      
/* D8BCD4 80240924 3C014334 */  lui       $at, 0x4334
/* D8BCD8 80240928 44812000 */  mtc1      $at, $f4
/* D8BCDC 8024092C 00000000 */  nop       
/* D8BCE0 80240930 4604103E */  c.le.s    $f2, $f4
/* D8BCE4 80240934 00000000 */  nop       
/* D8BCE8 80240938 45000003 */  bc1f      .L80240948
/* D8BCEC 8024093C 00000000 */   nop      
/* D8BCF0 80240940 08090276 */  j         .L802409D8
/* D8BCF4 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D8BCF8 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D8BCFC 8024094C 3C014334 */  lui       $at, 0x4334
/* D8BD00 80240950 44812000 */  mtc1      $at, $f4
/* D8BD04 80240954 00000000 */  nop       
/* D8BD08 80240958 4600203C */  c.lt.s    $f4, $f0
/* D8BD0C 8024095C 00000000 */  nop       
/* D8BD10 80240960 4500000C */  bc1f      .L80240994
/* D8BD14 80240964 00000000 */   nop      
/* D8BD18 80240968 3C014387 */  lui       $at, 0x4387
/* D8BD1C 8024096C 44812000 */  mtc1      $at, $f4
/* D8BD20 80240970 00000000 */  nop       
/* D8BD24 80240974 4604003E */  c.le.s    $f0, $f4
/* D8BD28 80240978 00000000 */  nop       
/* D8BD2C 8024097C 45000008 */  bc1f      .L802409A0
/* D8BD30 80240980 00000000 */   nop      
/* D8BD34 80240984 3C014334 */  lui       $at, 0x4334
/* D8BD38 80240988 44812000 */  mtc1      $at, $f4
/* D8BD3C 8024098C 08090276 */  j         .L802409D8
/* D8BD40 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D8BD44 80240994 3C014387 */  lui       $at, 0x4387
/* D8BD48 80240998 44812000 */  mtc1      $at, $f4
/* D8BD4C 8024099C 00000000 */  nop       
.L802409A0:
/* D8BD50 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D8BD54 802409A4 00000000 */  nop       
/* D8BD58 802409A8 4500000A */  bc1f      .L802409D4
/* D8BD5C 802409AC 00000000 */   nop      
/* D8BD60 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D8BD64 802409B4 44811000 */  mtc1      $at, $f2
/* D8BD68 802409B8 00000000 */  nop       
/* D8BD6C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D8BD70 802409C0 00000000 */  nop       
/* D8BD74 802409C4 45000003 */  bc1f      .L802409D4
/* D8BD78 802409C8 00000000 */   nop      
/* D8BD7C 802409CC 08090276 */  j         .L802409D8
/* D8BD80 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D8BD84 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D8BD88 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D8BD8C 802409DC 44810000 */  mtc1      $at, $f0
/* D8BD90 802409E0 00000000 */  nop       
/* D8BD94 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D8BD98 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D8BD9C 802409EC 44072000 */  mfc1      $a3, $f4
/* D8BDA0 802409F0 00000000 */  nop       
/* D8BDA4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D8BDA8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D8BDAC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D8BDB0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D8BDB4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D8BDB8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D8BDBC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D8BDC0 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D8BDC4 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D8BDC8 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D8BDCC 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D8BDD0 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D8BDD4 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D8BDD8 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D8BDDC 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D8BDE0 80240A30 4405A000 */  mfc1      $a1, $f20
/* D8BDE4 80240A34 4406B000 */  mfc1      $a2, $f22
/* D8BDE8 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D8BDEC 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D8BDF0 80240A40 0C019EC8 */  jal       guRotateF
/* D8BDF4 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8BDF8 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8BDFC 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D8BE00 80240A50 00000000 */   nop      
/* D8BE04 80240A54 44050000 */  mfc1      $a1, $f0
/* D8BE08 80240A58 4406B000 */  mfc1      $a2, $f22
/* D8BE0C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D8BE10 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D8BE14 80240A64 44812000 */  mtc1      $at, $f4
/* D8BE18 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D8BE1C 80240A6C 0C019EC8 */  jal       guRotateF
/* D8BE20 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D8BE24 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D8BE28 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D8BE2C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D8BE30 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D8BE34 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D8BE38 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D8BE3C 80240A8C 080902D6 */  j         .L80240B58
/* D8BE40 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D8BE44 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D8BE48 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D8BE4C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D8BE50 80240AA0 0C03964E */  jal       func_800E5938
/* D8BE54 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D8BE58 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D8BE5C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D8BE60 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D8BE64 80240AB4 46000606 */   mov.s    $f24, $f0
/* D8BE68 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D8BE6C 80240ABC 080902B5 */  j         .L80240AD4
/* D8BE70 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D8BE74 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D8BE78 80240AC8 00000000 */  nop       
/* D8BE7C 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D8BE80 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D8BE84 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D8BE88 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D8BE8C 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D8BE90 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D8BE94 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D8BE98 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D8BE9C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D8BEA0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D8BEA4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D8BEA8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D8BEAC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D8BEB0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D8BEB4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D8BEB8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D8BEBC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D8BEC0 80240B10 0C019EC8 */  jal       guRotateF
/* D8BEC4 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8BEC8 80240B18 4405A000 */  mfc1      $a1, $f20
/* D8BECC 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D8BED0 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D8BED4 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D8BED8 80240B28 0C019EC8 */  jal       guRotateF
/* D8BEDC 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D8BEE0 80240B30 4405C000 */  mfc1      $a1, $f24
/* D8BEE4 80240B34 4406B000 */  mfc1      $a2, $f22
/* D8BEE8 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D8BEEC 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D8BEF0 80240B40 0C019EC8 */  jal       guRotateF
/* D8BEF4 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8BEF8 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D8BEFC 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D8BF00 80240B50 0C019D80 */  jal       guMtxCatF
/* D8BF04 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D8BF08 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D8BF0C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D8BF10 80240B60 44812000 */  mtc1      $at, $f4
/* D8BF14 80240B64 00021023 */  negu      $v0, $v0
/* D8BF18 80240B68 44820000 */  mtc1      $v0, $f0
/* D8BF1C 80240B6C 00000000 */  nop       
/* D8BF20 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D8BF24 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D8BF28 80240B78 00000000 */  nop       
/* D8BF2C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D8BF30 80240B80 4407B000 */  mfc1      $a3, $f22
/* D8BF34 80240B84 44062000 */  mfc1      $a2, $f4
/* D8BF38 80240B88 0C019E40 */  jal       guTranslateF
/* D8BF3C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D8BF40 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D8BF44 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D8BF48 80240B98 0C019D80 */  jal       guMtxCatF
/* D8BF4C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D8BF50 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D8BF54 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D8BF58 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D8BF5C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D8BF60 80240BB0 0C019EC8 */  jal       guRotateF
/* D8BF64 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D8BF68 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D8BF6C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D8BF70 80240BC0 0C019D80 */  jal       guMtxCatF
/* D8BF74 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D8BF78 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D8BF7C 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8BF80 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D8BF84 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D8BF88 80240BD8 0C019EC8 */  jal       guRotateF
/* D8BF8C 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D8BF90 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D8BF94 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D8BF98 80240BE8 0C019D80 */  jal       guMtxCatF
/* D8BF9C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D8BFA0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D8BFA4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D8BFA8 80240BF8 44812000 */  mtc1      $at, $f4
/* D8BFAC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D8BFB0 80240C00 00000000 */  nop       
/* D8BFB4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D8BFB8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D8BFBC 80240C0C 00000000 */  nop       
/* D8BFC0 80240C10 4405B000 */  mfc1      $a1, $f22
/* D8BFC4 80240C14 4407B000 */  mfc1      $a3, $f22
/* D8BFC8 80240C18 44062000 */  mfc1      $a2, $f4
/* D8BFCC 80240C1C 0C019E40 */  jal       guTranslateF
/* D8BFD0 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D8BFD4 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D8BFD8 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D8BFDC 80240C2C 0C019D80 */  jal       guMtxCatF
/* D8BFE0 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D8BFE4 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D8BFE8 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8BFEC 80240C3C 44810000 */  mtc1      $at, $f0
/* D8BFF0 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D8BFF4 80240C44 44050000 */  mfc1      $a1, $f0
/* D8BFF8 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D8BFFC 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D8C000 80240C50 0C019DF0 */  jal       guScaleF
/* D8C004 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D8C008 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D8C00C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D8C010 80240C60 0C019D80 */  jal       guMtxCatF
/* D8C014 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D8C018 80240C68 4600D687 */  neg.s     $f26, $f26
/* D8C01C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D8C020 80240C70 4407E000 */  mfc1      $a3, $f28
/* D8C024 80240C74 4406D000 */  mfc1      $a2, $f26
/* D8C028 80240C78 0C019E40 */  jal       guTranslateF
/* D8C02C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D8C030 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D8C034 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D8C038 80240C88 0C019D80 */  jal       guMtxCatF
/* D8C03C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D8C040 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8C044 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D8C048 80240C98 44810000 */  mtc1      $at, $f0
/* D8C04C 80240C9C 00000000 */  nop       
/* D8C050 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D8C054 80240CA4 00000000 */  nop       
/* D8C058 80240CA8 4500000A */  bc1f      .L80240CD4
/* D8C05C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D8C060 80240CB0 3C014387 */  lui       $at, 0x4387
/* D8C064 80240CB4 44812000 */  mtc1      $at, $f4
/* D8C068 80240CB8 00000000 */  nop       
/* D8C06C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D8C070 80240CC0 00000000 */  nop       
/* D8C074 80240CC4 45000004 */  bc1f      .L80240CD8
/* D8C078 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D8C07C 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D8C080 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D8C084 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D8C088 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D8C08C 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D8C090 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D8C094 80240CE4 0C0B7710 */  jal       render_sprite
/* D8C098 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D8C09C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D8C0A0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D8C0A4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D8C0A8 80240CF8 00000000 */   nop      
/* D8C0AC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D8C0B0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D8C0B4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D8C0B8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D8C0BC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D8C0C0 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D8C0C4 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D8C0C8 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D8C0CC 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D8C0D0 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D8C0D4 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D8C0D8 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D8C0DC 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D8C0E0 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D8C0E4 80240D34 03E00008 */  jr        $ra
/* D8C0E8 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
