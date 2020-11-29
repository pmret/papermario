.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D6BE90
/* D6BE90 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D6BE94 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D6BE98 80240878 4480B000 */  mtc1      $zero, $f22
/* D6BE9C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D6BEA0 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D6BEA4 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D6BEA8 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D6BEAC 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D6BEB0 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D6BEB4 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D6BEB8 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D6BEBC 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D6BEC0 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D6BEC4 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D6BEC8 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D6BECC 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D6BED0 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D6BED4 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D6BED8 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D6BEDC 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D6BEE0 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D6BEE4 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D6BEE8 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D6BEEC 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D6BEF0 802408D0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D6BEF4 802408D4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D6BEF8 802408D8 00031080 */  sll       $v0, $v1, 2
/* D6BEFC 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D6BF00 802408E0 00021080 */  sll       $v0, $v0, 2
/* D6BF04 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D6BF08 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D6BF0C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D6BF10 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D6BF14 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D6BF18 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D6BF1C 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D6BF20 80240900 46000507 */   neg.s    $f20, $f0
/* D6BF24 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D6BF28 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D6BF2C 8024090C 44810000 */  mtc1      $at, $f0
/* D6BF30 80240910 00000000 */  nop       
/* D6BF34 80240914 4602003C */  c.lt.s    $f0, $f2
/* D6BF38 80240918 00000000 */  nop       
/* D6BF3C 8024091C 4500000A */  bc1f      .L80240948
/* D6BF40 80240920 00000000 */   nop      
/* D6BF44 80240924 3C014334 */  lui       $at, 0x4334
/* D6BF48 80240928 44812000 */  mtc1      $at, $f4
/* D6BF4C 8024092C 00000000 */  nop       
/* D6BF50 80240930 4604103E */  c.le.s    $f2, $f4
/* D6BF54 80240934 00000000 */  nop       
/* D6BF58 80240938 45000003 */  bc1f      .L80240948
/* D6BF5C 8024093C 00000000 */   nop      
/* D6BF60 80240940 08090276 */  j         .L802409D8
/* D6BF64 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D6BF68 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D6BF6C 8024094C 3C014334 */  lui       $at, 0x4334
/* D6BF70 80240950 44812000 */  mtc1      $at, $f4
/* D6BF74 80240954 00000000 */  nop       
/* D6BF78 80240958 4600203C */  c.lt.s    $f4, $f0
/* D6BF7C 8024095C 00000000 */  nop       
/* D6BF80 80240960 4500000C */  bc1f      .L80240994
/* D6BF84 80240964 00000000 */   nop      
/* D6BF88 80240968 3C014387 */  lui       $at, 0x4387
/* D6BF8C 8024096C 44812000 */  mtc1      $at, $f4
/* D6BF90 80240970 00000000 */  nop       
/* D6BF94 80240974 4604003E */  c.le.s    $f0, $f4
/* D6BF98 80240978 00000000 */  nop       
/* D6BF9C 8024097C 45000008 */  bc1f      .L802409A0
/* D6BFA0 80240980 00000000 */   nop      
/* D6BFA4 80240984 3C014334 */  lui       $at, 0x4334
/* D6BFA8 80240988 44812000 */  mtc1      $at, $f4
/* D6BFAC 8024098C 08090276 */  j         .L802409D8
/* D6BFB0 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D6BFB4 80240994 3C014387 */  lui       $at, 0x4387
/* D6BFB8 80240998 44812000 */  mtc1      $at, $f4
/* D6BFBC 8024099C 00000000 */  nop       
.L802409A0:
/* D6BFC0 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D6BFC4 802409A4 00000000 */  nop       
/* D6BFC8 802409A8 4500000A */  bc1f      .L802409D4
/* D6BFCC 802409AC 00000000 */   nop      
/* D6BFD0 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D6BFD4 802409B4 44811000 */  mtc1      $at, $f2
/* D6BFD8 802409B8 00000000 */  nop       
/* D6BFDC 802409BC 4602003E */  c.le.s    $f0, $f2
/* D6BFE0 802409C0 00000000 */  nop       
/* D6BFE4 802409C4 45000003 */  bc1f      .L802409D4
/* D6BFE8 802409C8 00000000 */   nop      
/* D6BFEC 802409CC 08090276 */  j         .L802409D8
/* D6BFF0 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D6BFF4 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D6BFF8 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D6BFFC 802409DC 44810000 */  mtc1      $at, $f0
/* D6C000 802409E0 00000000 */  nop       
/* D6C004 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D6C008 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D6C00C 802409EC 44072000 */  mfc1      $a3, $f4
/* D6C010 802409F0 00000000 */  nop       
/* D6C014 802409F4 00071100 */  sll       $v0, $a3, 4
/* D6C018 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D6C01C 802409FC 00021080 */  sll       $v0, $v0, 2
/* D6C020 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D6C024 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D6C028 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D6C02C 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D6C030 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D6C034 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D6C038 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D6C03C 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D6C040 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D6C044 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D6C048 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D6C04C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D6C050 80240A30 4405A000 */  mfc1      $a1, $f20
/* D6C054 80240A34 4406B000 */  mfc1      $a2, $f22
/* D6C058 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D6C05C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D6C060 80240A40 0C019EC8 */  jal       guRotateF
/* D6C064 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6C068 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D6C06C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D6C070 80240A50 00000000 */   nop      
/* D6C074 80240A54 44050000 */  mfc1      $a1, $f0
/* D6C078 80240A58 4406B000 */  mfc1      $a2, $f22
/* D6C07C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D6C080 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D6C084 80240A64 44812000 */  mtc1      $at, $f4
/* D6C088 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C08C 80240A6C 0C019EC8 */  jal       guRotateF
/* D6C090 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D6C094 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D6C098 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D6C09C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D6C0A0 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D6C0A4 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D6C0A8 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D6C0AC 80240A8C 080902D6 */  j         .L80240B58
/* D6C0B0 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D6C0B4 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D6C0B8 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D6C0BC 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D6C0C0 80240AA0 0C03964E */  jal       func_800E5938
/* D6C0C4 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D6C0C8 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D6C0CC 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D6C0D0 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D6C0D4 80240AB4 46000606 */   mov.s    $f24, $f0
/* D6C0D8 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D6C0DC 80240ABC 080902B5 */  j         .L80240AD4
/* D6C0E0 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D6C0E4 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D6C0E8 80240AC8 00000000 */  nop       
/* D6C0EC 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D6C0F0 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D6C0F4 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D6C0F8 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D6C0FC 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D6C100 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D6C104 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D6C108 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D6C10C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D6C110 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D6C114 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D6C118 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D6C11C 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D6C120 80240B00 4405A000 */  mfc1      $a1, $f20
/* D6C124 80240B04 4406B000 */  mfc1      $a2, $f22
/* D6C128 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D6C12C 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C130 80240B10 0C019EC8 */  jal       guRotateF
/* D6C134 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6C138 80240B18 4405A000 */  mfc1      $a1, $f20
/* D6C13C 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D6C140 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D6C144 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D6C148 80240B28 0C019EC8 */  jal       guRotateF
/* D6C14C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D6C150 80240B30 4405C000 */  mfc1      $a1, $f24
/* D6C154 80240B34 4406B000 */  mfc1      $a2, $f22
/* D6C158 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D6C15C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C160 80240B40 0C019EC8 */  jal       guRotateF
/* D6C164 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6C168 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D6C16C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D6C170 80240B50 0C019D80 */  jal       guMtxCatF
/* D6C174 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D6C178 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D6C17C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D6C180 80240B60 44812000 */  mtc1      $at, $f4
/* D6C184 80240B64 00021023 */  negu      $v0, $v0
/* D6C188 80240B68 44820000 */  mtc1      $v0, $f0
/* D6C18C 80240B6C 00000000 */  nop       
/* D6C190 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D6C194 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D6C198 80240B78 00000000 */  nop       
/* D6C19C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D6C1A0 80240B80 4407B000 */  mfc1      $a3, $f22
/* D6C1A4 80240B84 44062000 */  mfc1      $a2, $f4
/* D6C1A8 80240B88 0C019E40 */  jal       guTranslateF
/* D6C1AC 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D6C1B0 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D6C1B4 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D6C1B8 80240B98 0C019D80 */  jal       guMtxCatF
/* D6C1BC 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D6C1C0 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D6C1C4 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D6C1C8 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D6C1CC 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D6C1D0 80240BB0 0C019EC8 */  jal       guRotateF
/* D6C1D4 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D6C1D8 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C1DC 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D6C1E0 80240BC0 0C019D80 */  jal       guMtxCatF
/* D6C1E4 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D6C1E8 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D6C1EC 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D6C1F0 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D6C1F4 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D6C1F8 80240BD8 0C019EC8 */  jal       guRotateF
/* D6C1FC 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D6C200 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C204 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D6C208 80240BE8 0C019D80 */  jal       guMtxCatF
/* D6C20C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D6C210 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D6C214 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D6C218 80240BF8 44812000 */  mtc1      $at, $f4
/* D6C21C 80240BFC 44820000 */  mtc1      $v0, $f0
/* D6C220 80240C00 00000000 */  nop       
/* D6C224 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D6C228 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D6C22C 80240C0C 00000000 */  nop       
/* D6C230 80240C10 4405B000 */  mfc1      $a1, $f22
/* D6C234 80240C14 4407B000 */  mfc1      $a3, $f22
/* D6C238 80240C18 44062000 */  mfc1      $a2, $f4
/* D6C23C 80240C1C 0C019E40 */  jal       guTranslateF
/* D6C240 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D6C244 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C248 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D6C24C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D6C250 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D6C254 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D6C258 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6C25C 80240C3C 44810000 */  mtc1      $at, $f0
/* D6C260 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D6C264 80240C44 44050000 */  mfc1      $a1, $f0
/* D6C268 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D6C26C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D6C270 80240C50 0C019DF0 */  jal       guScaleF
/* D6C274 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D6C278 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C27C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D6C280 80240C60 0C019D80 */  jal       guMtxCatF
/* D6C284 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D6C288 80240C68 4600D687 */  neg.s     $f26, $f26
/* D6C28C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D6C290 80240C70 4407E000 */  mfc1      $a3, $f28
/* D6C294 80240C74 4406D000 */  mfc1      $a2, $f26
/* D6C298 80240C78 0C019E40 */  jal       guTranslateF
/* D6C29C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D6C2A0 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D6C2A4 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D6C2A8 80240C88 0C019D80 */  jal       guMtxCatF
/* D6C2AC 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D6C2B0 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D6C2B4 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D6C2B8 80240C98 44810000 */  mtc1      $at, $f0
/* D6C2BC 80240C9C 00000000 */  nop       
/* D6C2C0 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D6C2C4 80240CA4 00000000 */  nop       
/* D6C2C8 80240CA8 4500000A */  bc1f      .L80240CD4
/* D6C2CC 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D6C2D0 80240CB0 3C014387 */  lui       $at, 0x4387
/* D6C2D4 80240CB4 44812000 */  mtc1      $at, $f4
/* D6C2D8 80240CB8 00000000 */  nop       
/* D6C2DC 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D6C2E0 80240CC0 00000000 */  nop       
/* D6C2E4 80240CC4 45000004 */  bc1f      .L80240CD8
/* D6C2E8 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D6C2EC 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D6C2F0 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D6C2F4 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D6C2F8 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D6C2FC 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D6C300 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D6C304 80240CE4 0C0B7710 */  jal       render_sprite
/* D6C308 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D6C30C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D6C310 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D6C314 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D6C318 80240CF8 00000000 */   nop      
/* D6C31C 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D6C320 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D6C324 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D6C328 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D6C32C 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D6C330 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D6C334 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D6C338 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D6C33C 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D6C340 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D6C344 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D6C348 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D6C34C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D6C350 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D6C354 80240D34 03E00008 */  jr        $ra
/* D6C358 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
