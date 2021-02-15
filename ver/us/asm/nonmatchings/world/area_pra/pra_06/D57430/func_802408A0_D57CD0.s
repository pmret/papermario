.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A0_D57CD0
/* D57CD0 802408A0 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D57CD4 802408A4 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D57CD8 802408A8 4480B000 */  mtc1      $zero, $f22
/* D57CDC 802408AC AFB10134 */  sw        $s1, 0x134($sp)
/* D57CE0 802408B0 0080882D */  daddu     $s1, $a0, $zero
/* D57CE4 802408B4 AFB3013C */  sw        $s3, 0x13c($sp)
/* D57CE8 802408B8 0000982D */  daddu     $s3, $zero, $zero
/* D57CEC 802408BC AFB60148 */  sw        $s6, 0x148($sp)
/* D57CF0 802408C0 3C16800B */  lui       $s6, %hi(gCameras)
/* D57CF4 802408C4 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D57CF8 802408C8 AFB50144 */  sw        $s5, 0x144($sp)
/* D57CFC 802408CC 241500FF */  addiu     $s5, $zero, 0xff
/* D57D00 802408D0 AFB00130 */  sw        $s0, 0x130($sp)
/* D57D04 802408D4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D57D08 802408D8 AFB20138 */  sw        $s2, 0x138($sp)
/* D57D0C 802408DC 27B20060 */  addiu     $s2, $sp, 0x60
/* D57D10 802408E0 AFB40140 */  sw        $s4, 0x140($sp)
/* D57D14 802408E4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D57D18 802408E8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D57D1C 802408EC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D57D20 802408F0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D57D24 802408F4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D57D28 802408F8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D57D2C 802408FC F7B40150 */  sdc1      $f20, 0x150($sp)
.L80240900:
/* D57D30 80240900 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D57D34 80240904 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D57D38 80240908 00031080 */  sll       $v0, $v1, 2
/* D57D3C 8024090C 00431021 */  addu      $v0, $v0, $v1
/* D57D40 80240910 00021080 */  sll       $v0, $v0, 2
/* D57D44 80240914 00431023 */  subu      $v0, $v0, $v1
/* D57D48 80240918 000218C0 */  sll       $v1, $v0, 3
/* D57D4C 8024091C 00431021 */  addu      $v0, $v0, $v1
/* D57D50 80240920 000210C0 */  sll       $v0, $v0, 3
/* D57D54 80240924 00561021 */  addu      $v0, $v0, $s6
/* D57D58 80240928 C440006C */  lwc1      $f0, 0x6c($v0)
/* D57D5C 8024092C 16600065 */  bnez      $s3, .L80240AC4
/* D57D60 80240930 46000507 */   neg.s    $f20, $f0
/* D57D64 80240934 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D57D68 80240938 3C0142B4 */  lui       $at, 0x42b4
/* D57D6C 8024093C 44810000 */  mtc1      $at, $f0
/* D57D70 80240940 00000000 */  nop
/* D57D74 80240944 4602003C */  c.lt.s    $f0, $f2
/* D57D78 80240948 00000000 */  nop
/* D57D7C 8024094C 4500000A */  bc1f      .L80240978
/* D57D80 80240950 00000000 */   nop
/* D57D84 80240954 3C014334 */  lui       $at, 0x4334
/* D57D88 80240958 44812000 */  mtc1      $at, $f4
/* D57D8C 8024095C 00000000 */  nop
/* D57D90 80240960 4604103E */  c.le.s    $f2, $f4
/* D57D94 80240964 00000000 */  nop
/* D57D98 80240968 45000003 */  bc1f      .L80240978
/* D57D9C 8024096C 00000000 */   nop
/* D57DA0 80240970 08090282 */  j         .L80240A08
/* D57DA4 80240974 46022501 */   sub.s    $f20, $f4, $f2
.L80240978:
/* D57DA8 80240978 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D57DAC 8024097C 3C014334 */  lui       $at, 0x4334
/* D57DB0 80240980 44812000 */  mtc1      $at, $f4
/* D57DB4 80240984 00000000 */  nop
/* D57DB8 80240988 4600203C */  c.lt.s    $f4, $f0
/* D57DBC 8024098C 00000000 */  nop
/* D57DC0 80240990 4500000C */  bc1f      .L802409C4
/* D57DC4 80240994 00000000 */   nop
/* D57DC8 80240998 3C014387 */  lui       $at, 0x4387
/* D57DCC 8024099C 44812000 */  mtc1      $at, $f4
/* D57DD0 802409A0 00000000 */  nop
/* D57DD4 802409A4 4604003E */  c.le.s    $f0, $f4
/* D57DD8 802409A8 00000000 */  nop
/* D57DDC 802409AC 45000008 */  bc1f      .L802409D0
/* D57DE0 802409B0 00000000 */   nop
/* D57DE4 802409B4 3C014334 */  lui       $at, 0x4334
/* D57DE8 802409B8 44812000 */  mtc1      $at, $f4
/* D57DEC 802409BC 08090282 */  j         .L80240A08
/* D57DF0 802409C0 46040501 */   sub.s    $f20, $f0, $f4
.L802409C4:
/* D57DF4 802409C4 3C014387 */  lui       $at, 0x4387
/* D57DF8 802409C8 44812000 */  mtc1      $at, $f4
/* D57DFC 802409CC 00000000 */  nop
.L802409D0:
/* D57E00 802409D0 4600203C */  c.lt.s    $f4, $f0
/* D57E04 802409D4 00000000 */  nop
/* D57E08 802409D8 4500000A */  bc1f      .L80240A04
/* D57E0C 802409DC 00000000 */   nop
/* D57E10 802409E0 3C0143B4 */  lui       $at, 0x43b4
/* D57E14 802409E4 44811000 */  mtc1      $at, $f2
/* D57E18 802409E8 00000000 */  nop
/* D57E1C 802409EC 4602003E */  c.le.s    $f0, $f2
/* D57E20 802409F0 00000000 */  nop
/* D57E24 802409F4 45000003 */  bc1f      .L80240A04
/* D57E28 802409F8 00000000 */   nop
/* D57E2C 802409FC 08090282 */  j         .L80240A08
/* D57E30 80240A00 46001501 */   sub.s    $f20, $f2, $f0
.L80240A04:
/* D57E34 80240A04 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L80240A08:
/* D57E38 80240A08 3C0141C8 */  lui       $at, 0x41c8
/* D57E3C 80240A0C 44810000 */  mtc1      $at, $f0
/* D57E40 80240A10 00000000 */  nop
/* D57E44 80240A14 4600A003 */  div.s     $f0, $f20, $f0
/* D57E48 80240A18 4600010D */  trunc.w.s $f4, $f0
/* D57E4C 80240A1C 44072000 */  mfc1      $a3, $f4
/* D57E50 80240A20 00000000 */  nop
/* D57E54 80240A24 00071100 */  sll       $v0, $a3, 4
/* D57E58 80240A28 00471023 */  subu      $v0, $v0, $a3
/* D57E5C 80240A2C 00021080 */  sll       $v0, $v0, 2
/* D57E60 80240A30 02A23823 */  subu      $a3, $s5, $v0
/* D57E64 80240A34 28E20064 */  slti      $v0, $a3, 0x64
/* D57E68 80240A38 54400001 */  bnel      $v0, $zero, .L80240A40
/* D57E6C 80240A3C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A40:
/* D57E70 80240A40 24040001 */  addiu     $a0, $zero, 1
/* D57E74 80240A44 2405FFFF */  addiu     $a1, $zero, -1
/* D57E78 80240A48 24060006 */  addiu     $a2, $zero, 6
/* D57E7C 80240A4C AFA70010 */  sw        $a3, 0x10($sp)
/* D57E80 80240A50 AFA70014 */  sw        $a3, 0x14($sp)
/* D57E84 80240A54 AFB50018 */  sw        $s5, 0x18($sp)
/* D57E88 80240A58 0C0B77B9 */  jal       func_802DDEE4
/* D57E8C 80240A5C AFA0001C */   sw       $zero, 0x1c($sp)
/* D57E90 80240A60 4405A000 */  mfc1      $a1, $f20
/* D57E94 80240A64 4406B000 */  mfc1      $a2, $f22
/* D57E98 80240A68 3C07BF80 */  lui       $a3, 0xbf80
/* D57E9C 80240A6C 0200202D */  daddu     $a0, $s0, $zero
/* D57EA0 80240A70 0C019EC8 */  jal       guRotateF
/* D57EA4 80240A74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D57EA8 80240A78 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D57EAC 80240A7C 0C00A6C9 */  jal       clamp_angle
/* D57EB0 80240A80 00000000 */   nop
/* D57EB4 80240A84 44050000 */  mfc1      $a1, $f0
/* D57EB8 80240A88 4406B000 */  mfc1      $a2, $f22
/* D57EBC 80240A8C 4407B000 */  mfc1      $a3, $f22
/* D57EC0 80240A90 3C013F80 */  lui       $at, 0x3f80
/* D57EC4 80240A94 44812000 */  mtc1      $at, $f4
/* D57EC8 80240A98 27A40020 */  addiu     $a0, $sp, 0x20
/* D57ECC 80240A9C 0C019EC8 */  jal       guRotateF
/* D57ED0 80240AA0 E7A40010 */   swc1     $f4, 0x10($sp)
/* D57ED4 80240AA4 0200202D */  daddu     $a0, $s0, $zero
/* D57ED8 80240AA8 27A50020 */  addiu     $a1, $sp, 0x20
/* D57EDC 80240AAC 0C019D80 */  jal       guMtxCatF
/* D57EE0 80240AB0 00A0302D */   daddu    $a2, $a1, $zero
/* D57EE4 80240AB4 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D57EE8 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D57EEC 80240ABC 080902E2 */  j         .L80240B88
/* D57EF0 80240AC0 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240AC4:
/* D57EF4 80240AC4 0260202D */  daddu     $a0, $s3, $zero
/* D57EF8 80240AC8 27A50120 */  addiu     $a1, $sp, 0x120
/* D57EFC 80240ACC 27A60124 */  addiu     $a2, $sp, 0x124
/* D57F00 80240AD0 0C03964E */  jal       func_800E5938
/* D57F04 80240AD4 27A70128 */   addiu    $a3, $sp, 0x128
/* D57F08 80240AD8 8FA60124 */  lw        $a2, 0x124($sp)
/* D57F0C 80240ADC 3C028000 */  lui       $v0, 0x8000
/* D57F10 80240AE0 14C20004 */  bne       $a2, $v0, .L80240AF4
/* D57F14 80240AE4 46000606 */   mov.s    $f24, $f0
/* D57F18 80240AE8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D57F1C 80240AEC 080902C1 */  j         .L80240B04
/* D57F20 80240AF0 24040001 */   addiu    $a0, $zero, 1
.L80240AF4:
/* D57F24 80240AF4 4486D000 */  mtc1      $a2, $f26
/* D57F28 80240AF8 00000000 */  nop
/* D57F2C 80240AFC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D57F30 80240B00 24040001 */  addiu     $a0, $zero, 1
.L80240B04:
/* D57F34 80240B04 2405FFFF */  addiu     $a1, $zero, -1
/* D57F38 80240B08 24060007 */  addiu     $a2, $zero, 7
/* D57F3C 80240B0C 0000382D */  daddu     $a3, $zero, $zero
/* D57F40 80240B10 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D57F44 80240B14 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D57F48 80240B18 24020040 */  addiu     $v0, $zero, 0x40
/* D57F4C 80240B1C AFA00010 */  sw        $zero, 0x10($sp)
/* D57F50 80240B20 AFA00014 */  sw        $zero, 0x14($sp)
/* D57F54 80240B24 AFA20018 */  sw        $v0, 0x18($sp)
/* D57F58 80240B28 0C0B77B9 */  jal       func_802DDEE4
/* D57F5C 80240B2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D57F60 80240B30 4405A000 */  mfc1      $a1, $f20
/* D57F64 80240B34 4406B000 */  mfc1      $a2, $f22
/* D57F68 80240B38 3C07BF80 */  lui       $a3, 0xbf80
/* D57F6C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D57F70 80240B40 0C019EC8 */  jal       guRotateF
/* D57F74 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D57F78 80240B48 4405A000 */  mfc1      $a1, $f20
/* D57F7C 80240B4C 4406B000 */  mfc1      $a2, $f22
/* D57F80 80240B50 3C07BF80 */  lui       $a3, 0xbf80
/* D57F84 80240B54 0200202D */  daddu     $a0, $s0, $zero
/* D57F88 80240B58 0C019EC8 */  jal       guRotateF
/* D57F8C 80240B5C E7B60010 */   swc1     $f22, 0x10($sp)
/* D57F90 80240B60 4405C000 */  mfc1      $a1, $f24
/* D57F94 80240B64 4406B000 */  mfc1      $a2, $f22
/* D57F98 80240B68 3C073F80 */  lui       $a3, 0x3f80
/* D57F9C 80240B6C 27A40020 */  addiu     $a0, $sp, 0x20
/* D57FA0 80240B70 0C019EC8 */  jal       guRotateF
/* D57FA4 80240B74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D57FA8 80240B78 0200202D */  daddu     $a0, $s0, $zero
/* D57FAC 80240B7C 27A50020 */  addiu     $a1, $sp, 0x20
/* D57FB0 80240B80 0C019D80 */  jal       guMtxCatF
/* D57FB4 80240B84 00A0302D */   daddu    $a2, $a1, $zero
.L80240B88:
/* D57FB8 80240B88 862200B0 */  lh        $v0, 0xb0($s1)
/* D57FBC 80240B8C 3C013F00 */  lui       $at, 0x3f00
/* D57FC0 80240B90 44812000 */  mtc1      $at, $f4
/* D57FC4 80240B94 00021023 */  negu      $v0, $v0
/* D57FC8 80240B98 44820000 */  mtc1      $v0, $f0
/* D57FCC 80240B9C 00000000 */  nop
/* D57FD0 80240BA0 46800020 */  cvt.s.w   $f0, $f0
/* D57FD4 80240BA4 46040102 */  mul.s     $f4, $f0, $f4
/* D57FD8 80240BA8 00000000 */  nop
/* D57FDC 80240BAC 4405B000 */  mfc1      $a1, $f22
/* D57FE0 80240BB0 4407B000 */  mfc1      $a3, $f22
/* D57FE4 80240BB4 44062000 */  mfc1      $a2, $f4
/* D57FE8 80240BB8 0C019E40 */  jal       guTranslateF
/* D57FEC 80240BBC 0240202D */   daddu    $a0, $s2, $zero
/* D57FF0 80240BC0 0240202D */  daddu     $a0, $s2, $zero
/* D57FF4 80240BC4 27A50020 */  addiu     $a1, $sp, 0x20
/* D57FF8 80240BC8 0C019D80 */  jal       guMtxCatF
/* D57FFC 80240BCC 00A0302D */   daddu    $a2, $a1, $zero
/* D58000 80240BD0 4405A000 */  mfc1      $a1, $f20
/* D58004 80240BD4 4406B000 */  mfc1      $a2, $f22
/* D58008 80240BD8 3C073F80 */  lui       $a3, 0x3f80
/* D5800C 80240BDC 0200202D */  daddu     $a0, $s0, $zero
/* D58010 80240BE0 0C019EC8 */  jal       guRotateF
/* D58014 80240BE4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D58018 80240BE8 27A40020 */  addiu     $a0, $sp, 0x20
/* D5801C 80240BEC 0200282D */  daddu     $a1, $s0, $zero
/* D58020 80240BF0 0C019D80 */  jal       guMtxCatF
/* D58024 80240BF4 0080302D */   daddu    $a2, $a0, $zero
/* D58028 80240BF8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D5802C 80240BFC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D58030 80240C00 4406B000 */  mfc1      $a2, $f22
/* D58034 80240C04 3C073F80 */  lui       $a3, 0x3f80
/* D58038 80240C08 0C019EC8 */  jal       guRotateF
/* D5803C 80240C0C 0200202D */   daddu    $a0, $s0, $zero
/* D58040 80240C10 27A40020 */  addiu     $a0, $sp, 0x20
/* D58044 80240C14 0200282D */  daddu     $a1, $s0, $zero
/* D58048 80240C18 0C019D80 */  jal       guMtxCatF
/* D5804C 80240C1C 0080302D */   daddu    $a2, $a0, $zero
/* D58050 80240C20 862200B0 */  lh        $v0, 0xb0($s1)
/* D58054 80240C24 3C013F00 */  lui       $at, 0x3f00
/* D58058 80240C28 44812000 */  mtc1      $at, $f4
/* D5805C 80240C2C 44820000 */  mtc1      $v0, $f0
/* D58060 80240C30 00000000 */  nop
/* D58064 80240C34 46800020 */  cvt.s.w   $f0, $f0
/* D58068 80240C38 46040102 */  mul.s     $f4, $f0, $f4
/* D5806C 80240C3C 00000000 */  nop
/* D58070 80240C40 4405B000 */  mfc1      $a1, $f22
/* D58074 80240C44 4407B000 */  mfc1      $a3, $f22
/* D58078 80240C48 44062000 */  mfc1      $a2, $f4
/* D5807C 80240C4C 0C019E40 */  jal       guTranslateF
/* D58080 80240C50 0240202D */   daddu    $a0, $s2, $zero
/* D58084 80240C54 27A40020 */  addiu     $a0, $sp, 0x20
/* D58088 80240C58 0240282D */  daddu     $a1, $s2, $zero
/* D5808C 80240C5C 0C019D80 */  jal       guMtxCatF
/* D58090 80240C60 0080302D */   daddu    $a2, $a0, $zero
/* D58094 80240C64 3C013F36 */  lui       $at, 0x3f36
/* D58098 80240C68 3421DB6E */  ori       $at, $at, 0xdb6e
/* D5809C 80240C6C 44810000 */  mtc1      $at, $f0
/* D580A0 80240C70 0280202D */  daddu     $a0, $s4, $zero
/* D580A4 80240C74 44050000 */  mfc1      $a1, $f0
/* D580A8 80240C78 3C06BF36 */  lui       $a2, 0xbf36
/* D580AC 80240C7C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D580B0 80240C80 0C019DF0 */  jal       guScaleF
/* D580B4 80240C84 00A0382D */   daddu    $a3, $a1, $zero
/* D580B8 80240C88 27A40020 */  addiu     $a0, $sp, 0x20
/* D580BC 80240C8C 0280282D */  daddu     $a1, $s4, $zero
/* D580C0 80240C90 0C019D80 */  jal       guMtxCatF
/* D580C4 80240C94 0080302D */   daddu    $a2, $a0, $zero
/* D580C8 80240C98 4600D687 */  neg.s     $f26, $f26
/* D580CC 80240C9C 4405F000 */  mfc1      $a1, $f30
/* D580D0 80240CA0 4407E000 */  mfc1      $a3, $f28
/* D580D4 80240CA4 4406D000 */  mfc1      $a2, $f26
/* D580D8 80240CA8 0C019E40 */  jal       guTranslateF
/* D580DC 80240CAC 0240202D */   daddu    $a0, $s2, $zero
/* D580E0 80240CB0 27A40020 */  addiu     $a0, $sp, 0x20
/* D580E4 80240CB4 0240282D */  daddu     $a1, $s2, $zero
/* D580E8 80240CB8 0C019D80 */  jal       guMtxCatF
/* D580EC 80240CBC 0080302D */   daddu    $a2, $a0, $zero
/* D580F0 80240CC0 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D580F4 80240CC4 3C0142B4 */  lui       $at, 0x42b4
/* D580F8 80240CC8 44810000 */  mtc1      $at, $f0
/* D580FC 80240CCC 00000000 */  nop
/* D58100 80240CD0 4602003E */  c.le.s    $f0, $f2
/* D58104 80240CD4 00000000 */  nop
/* D58108 80240CD8 4500000A */  bc1f      .L80240D04
/* D5810C 80240CDC 24040001 */   addiu    $a0, $zero, 1
/* D58110 80240CE0 3C014387 */  lui       $at, 0x4387
/* D58114 80240CE4 44812000 */  mtc1      $at, $f4
/* D58118 80240CE8 00000000 */  nop
/* D5811C 80240CEC 4604103C */  c.lt.s    $f2, $f4
/* D58120 80240CF0 00000000 */  nop
/* D58124 80240CF4 45000004 */  bc1f      .L80240D08
/* D58128 80240CF8 27A20020 */   addiu    $v0, $sp, 0x20
/* D5812C 80240CFC 3C041000 */  lui       $a0, 0x1000
/* D58130 80240D00 34840001 */  ori       $a0, $a0, 1
.L80240D04:
/* D58134 80240D04 27A20020 */  addiu     $v0, $sp, 0x20
.L80240D08:
/* D58138 80240D08 AFA20010 */  sw        $v0, 0x10($sp)
/* D5813C 80240D0C 0000282D */  daddu     $a1, $zero, $zero
/* D58140 80240D10 00A0302D */  daddu     $a2, $a1, $zero
/* D58144 80240D14 0C0B7710 */  jal       render_sprite
/* D58148 80240D18 00A0382D */   daddu    $a3, $a1, $zero
/* D5814C 80240D1C 26730001 */  addiu     $s3, $s3, 1
/* D58150 80240D20 2A620002 */  slti      $v0, $s3, 2
/* D58154 80240D24 1440FEF6 */  bnez      $v0, .L80240900
/* D58158 80240D28 00000000 */   nop
/* D5815C 80240D2C 8FBF014C */  lw        $ra, 0x14c($sp)
/* D58160 80240D30 8FB60148 */  lw        $s6, 0x148($sp)
/* D58164 80240D34 8FB50144 */  lw        $s5, 0x144($sp)
/* D58168 80240D38 8FB40140 */  lw        $s4, 0x140($sp)
/* D5816C 80240D3C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D58170 80240D40 8FB20138 */  lw        $s2, 0x138($sp)
/* D58174 80240D44 8FB10134 */  lw        $s1, 0x134($sp)
/* D58178 80240D48 8FB00130 */  lw        $s0, 0x130($sp)
/* D5817C 80240D4C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D58180 80240D50 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D58184 80240D54 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D58188 80240D58 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D5818C 80240D5C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D58190 80240D60 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D58194 80240D64 03E00008 */  jr        $ra
/* D58198 80240D68 27BD0180 */   addiu    $sp, $sp, 0x180
