.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D76C10
/* D76C10 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D76C14 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D76C18 80240878 4480B000 */  mtc1      $zero, $f22
/* D76C1C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D76C20 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D76C24 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D76C28 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D76C2C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D76C30 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D76C34 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D76C38 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D76C3C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D76C40 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D76C44 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D76C48 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D76C4C 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D76C50 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D76C54 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D76C58 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D76C5C 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D76C60 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D76C64 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D76C68 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D76C6C 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D76C70 802408D0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D76C74 802408D4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D76C78 802408D8 00031080 */  sll       $v0, $v1, 2
/* D76C7C 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D76C80 802408E0 00021080 */  sll       $v0, $v0, 2
/* D76C84 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D76C88 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D76C8C 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D76C90 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D76C94 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D76C98 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D76C9C 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D76CA0 80240900 46000507 */   neg.s    $f20, $f0
/* D76CA4 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D76CA8 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D76CAC 8024090C 44810000 */  mtc1      $at, $f0
/* D76CB0 80240910 00000000 */  nop
/* D76CB4 80240914 4602003C */  c.lt.s    $f0, $f2
/* D76CB8 80240918 00000000 */  nop
/* D76CBC 8024091C 4500000A */  bc1f      .L80240948
/* D76CC0 80240920 00000000 */   nop
/* D76CC4 80240924 3C014334 */  lui       $at, 0x4334
/* D76CC8 80240928 44812000 */  mtc1      $at, $f4
/* D76CCC 8024092C 00000000 */  nop
/* D76CD0 80240930 4604103E */  c.le.s    $f2, $f4
/* D76CD4 80240934 00000000 */  nop
/* D76CD8 80240938 45000003 */  bc1f      .L80240948
/* D76CDC 8024093C 00000000 */   nop
/* D76CE0 80240940 08090276 */  j         .L802409D8
/* D76CE4 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D76CE8 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D76CEC 8024094C 3C014334 */  lui       $at, 0x4334
/* D76CF0 80240950 44812000 */  mtc1      $at, $f4
/* D76CF4 80240954 00000000 */  nop
/* D76CF8 80240958 4600203C */  c.lt.s    $f4, $f0
/* D76CFC 8024095C 00000000 */  nop
/* D76D00 80240960 4500000C */  bc1f      .L80240994
/* D76D04 80240964 00000000 */   nop
/* D76D08 80240968 3C014387 */  lui       $at, 0x4387
/* D76D0C 8024096C 44812000 */  mtc1      $at, $f4
/* D76D10 80240970 00000000 */  nop
/* D76D14 80240974 4604003E */  c.le.s    $f0, $f4
/* D76D18 80240978 00000000 */  nop
/* D76D1C 8024097C 45000008 */  bc1f      .L802409A0
/* D76D20 80240980 00000000 */   nop
/* D76D24 80240984 3C014334 */  lui       $at, 0x4334
/* D76D28 80240988 44812000 */  mtc1      $at, $f4
/* D76D2C 8024098C 08090276 */  j         .L802409D8
/* D76D30 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D76D34 80240994 3C014387 */  lui       $at, 0x4387
/* D76D38 80240998 44812000 */  mtc1      $at, $f4
/* D76D3C 8024099C 00000000 */  nop
.L802409A0:
/* D76D40 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D76D44 802409A4 00000000 */  nop
/* D76D48 802409A8 4500000A */  bc1f      .L802409D4
/* D76D4C 802409AC 00000000 */   nop
/* D76D50 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D76D54 802409B4 44811000 */  mtc1      $at, $f2
/* D76D58 802409B8 00000000 */  nop
/* D76D5C 802409BC 4602003E */  c.le.s    $f0, $f2
/* D76D60 802409C0 00000000 */  nop
/* D76D64 802409C4 45000003 */  bc1f      .L802409D4
/* D76D68 802409C8 00000000 */   nop
/* D76D6C 802409CC 08090276 */  j         .L802409D8
/* D76D70 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D76D74 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D76D78 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D76D7C 802409DC 44810000 */  mtc1      $at, $f0
/* D76D80 802409E0 00000000 */  nop
/* D76D84 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D76D88 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D76D8C 802409EC 44072000 */  mfc1      $a3, $f4
/* D76D90 802409F0 00000000 */  nop
/* D76D94 802409F4 00071100 */  sll       $v0, $a3, 4
/* D76D98 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D76D9C 802409FC 00021080 */  sll       $v0, $v0, 2
/* D76DA0 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D76DA4 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D76DA8 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D76DAC 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D76DB0 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D76DB4 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D76DB8 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D76DBC 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D76DC0 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D76DC4 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D76DC8 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D76DCC 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D76DD0 80240A30 4405A000 */  mfc1      $a1, $f20
/* D76DD4 80240A34 4406B000 */  mfc1      $a2, $f22
/* D76DD8 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D76DDC 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D76DE0 80240A40 0C019EC8 */  jal       guRotateF
/* D76DE4 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D76DE8 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D76DEC 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D76DF0 80240A50 00000000 */   nop
/* D76DF4 80240A54 44050000 */  mfc1      $a1, $f0
/* D76DF8 80240A58 4406B000 */  mfc1      $a2, $f22
/* D76DFC 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D76E00 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D76E04 80240A64 44812000 */  mtc1      $at, $f4
/* D76E08 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D76E0C 80240A6C 0C019EC8 */  jal       guRotateF
/* D76E10 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D76E14 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D76E18 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D76E1C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D76E20 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D76E24 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D76E28 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D76E2C 80240A8C 080902D6 */  j         .L80240B58
/* D76E30 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D76E34 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D76E38 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D76E3C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D76E40 80240AA0 0C03964E */  jal       func_800E5938
/* D76E44 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D76E48 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D76E4C 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D76E50 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D76E54 80240AB4 46000606 */   mov.s    $f24, $f0
/* D76E58 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D76E5C 80240ABC 080902B5 */  j         .L80240AD4
/* D76E60 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D76E64 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D76E68 80240AC8 00000000 */  nop
/* D76E6C 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D76E70 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D76E74 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D76E78 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D76E7C 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D76E80 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D76E84 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D76E88 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D76E8C 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D76E90 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D76E94 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D76E98 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D76E9C 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D76EA0 80240B00 4405A000 */  mfc1      $a1, $f20
/* D76EA4 80240B04 4406B000 */  mfc1      $a2, $f22
/* D76EA8 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D76EAC 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D76EB0 80240B10 0C019EC8 */  jal       guRotateF
/* D76EB4 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D76EB8 80240B18 4405A000 */  mfc1      $a1, $f20
/* D76EBC 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D76EC0 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D76EC4 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D76EC8 80240B28 0C019EC8 */  jal       guRotateF
/* D76ECC 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D76ED0 80240B30 4405C000 */  mfc1      $a1, $f24
/* D76ED4 80240B34 4406B000 */  mfc1      $a2, $f22
/* D76ED8 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D76EDC 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D76EE0 80240B40 0C019EC8 */  jal       guRotateF
/* D76EE4 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D76EE8 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D76EEC 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D76EF0 80240B50 0C019D80 */  jal       guMtxCatF
/* D76EF4 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D76EF8 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D76EFC 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D76F00 80240B60 44812000 */  mtc1      $at, $f4
/* D76F04 80240B64 00021023 */  negu      $v0, $v0
/* D76F08 80240B68 44820000 */  mtc1      $v0, $f0
/* D76F0C 80240B6C 00000000 */  nop
/* D76F10 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D76F14 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D76F18 80240B78 00000000 */  nop
/* D76F1C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D76F20 80240B80 4407B000 */  mfc1      $a3, $f22
/* D76F24 80240B84 44062000 */  mfc1      $a2, $f4
/* D76F28 80240B88 0C019E40 */  jal       guTranslateF
/* D76F2C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D76F30 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D76F34 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D76F38 80240B98 0C019D80 */  jal       guMtxCatF
/* D76F3C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D76F40 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D76F44 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D76F48 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D76F4C 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D76F50 80240BB0 0C019EC8 */  jal       guRotateF
/* D76F54 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D76F58 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D76F5C 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D76F60 80240BC0 0C019D80 */  jal       guMtxCatF
/* D76F64 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D76F68 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D76F6C 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D76F70 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D76F74 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D76F78 80240BD8 0C019EC8 */  jal       guRotateF
/* D76F7C 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D76F80 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D76F84 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D76F88 80240BE8 0C019D80 */  jal       guMtxCatF
/* D76F8C 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D76F90 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D76F94 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D76F98 80240BF8 44812000 */  mtc1      $at, $f4
/* D76F9C 80240BFC 44820000 */  mtc1      $v0, $f0
/* D76FA0 80240C00 00000000 */  nop
/* D76FA4 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D76FA8 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D76FAC 80240C0C 00000000 */  nop
/* D76FB0 80240C10 4405B000 */  mfc1      $a1, $f22
/* D76FB4 80240C14 4407B000 */  mfc1      $a3, $f22
/* D76FB8 80240C18 44062000 */  mfc1      $a2, $f4
/* D76FBC 80240C1C 0C019E40 */  jal       guTranslateF
/* D76FC0 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D76FC4 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D76FC8 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D76FCC 80240C2C 0C019D80 */  jal       guMtxCatF
/* D76FD0 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D76FD4 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D76FD8 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D76FDC 80240C3C 44810000 */  mtc1      $at, $f0
/* D76FE0 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D76FE4 80240C44 44050000 */  mfc1      $a1, $f0
/* D76FE8 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D76FEC 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D76FF0 80240C50 0C019DF0 */  jal       guScaleF
/* D76FF4 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D76FF8 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D76FFC 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D77000 80240C60 0C019D80 */  jal       guMtxCatF
/* D77004 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D77008 80240C68 4600D687 */  neg.s     $f26, $f26
/* D7700C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D77010 80240C70 4407E000 */  mfc1      $a3, $f28
/* D77014 80240C74 4406D000 */  mfc1      $a2, $f26
/* D77018 80240C78 0C019E40 */  jal       guTranslateF
/* D7701C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D77020 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D77024 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D77028 80240C88 0C019D80 */  jal       guMtxCatF
/* D7702C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D77030 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D77034 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D77038 80240C98 44810000 */  mtc1      $at, $f0
/* D7703C 80240C9C 00000000 */  nop
/* D77040 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D77044 80240CA4 00000000 */  nop
/* D77048 80240CA8 4500000A */  bc1f      .L80240CD4
/* D7704C 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D77050 80240CB0 3C014387 */  lui       $at, 0x4387
/* D77054 80240CB4 44812000 */  mtc1      $at, $f4
/* D77058 80240CB8 00000000 */  nop
/* D7705C 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D77060 80240CC0 00000000 */  nop
/* D77064 80240CC4 45000004 */  bc1f      .L80240CD8
/* D77068 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D7706C 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D77070 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D77074 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D77078 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D7707C 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D77080 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D77084 80240CE4 0C0B7710 */  jal       render_sprite
/* D77088 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D7708C 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D77090 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D77094 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D77098 80240CF8 00000000 */   nop
/* D7709C 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D770A0 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D770A4 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D770A8 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D770AC 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D770B0 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D770B4 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D770B8 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D770BC 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D770C0 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D770C4 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D770C8 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D770CC 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D770D0 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D770D4 80240D34 03E00008 */  jr        $ra
/* D770D8 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
