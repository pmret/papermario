.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_D61D70
/* D61D70 80240870 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D61D74 80240874 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D61D78 80240878 4480B000 */  mtc1      $zero, $f22
/* D61D7C 8024087C AFB10134 */  sw        $s1, 0x134($sp)
/* D61D80 80240880 0080882D */  daddu     $s1, $a0, $zero
/* D61D84 80240884 AFB3013C */  sw        $s3, 0x13c($sp)
/* D61D88 80240888 0000982D */  daddu     $s3, $zero, $zero
/* D61D8C 8024088C AFB60148 */  sw        $s6, 0x148($sp)
/* D61D90 80240890 3C16800B */  lui       $s6, %hi(gCameras)
/* D61D94 80240894 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D61D98 80240898 AFB50144 */  sw        $s5, 0x144($sp)
/* D61D9C 8024089C 241500FF */  addiu     $s5, $zero, 0xff
/* D61DA0 802408A0 AFB00130 */  sw        $s0, 0x130($sp)
/* D61DA4 802408A4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D61DA8 802408A8 AFB20138 */  sw        $s2, 0x138($sp)
/* D61DAC 802408AC 27B20060 */  addiu     $s2, $sp, 0x60
/* D61DB0 802408B0 AFB40140 */  sw        $s4, 0x140($sp)
/* D61DB4 802408B4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D61DB8 802408B8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D61DBC 802408BC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D61DC0 802408C0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D61DC4 802408C4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D61DC8 802408C8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D61DCC 802408CC F7B40150 */  sdc1      $f20, 0x150($sp)
.L802408D0:
/* D61DD0 802408D0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D61DD4 802408D4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D61DD8 802408D8 00031080 */  sll       $v0, $v1, 2
/* D61DDC 802408DC 00431021 */  addu      $v0, $v0, $v1
/* D61DE0 802408E0 00021080 */  sll       $v0, $v0, 2
/* D61DE4 802408E4 00431023 */  subu      $v0, $v0, $v1
/* D61DE8 802408E8 000218C0 */  sll       $v1, $v0, 3
/* D61DEC 802408EC 00431021 */  addu      $v0, $v0, $v1
/* D61DF0 802408F0 000210C0 */  sll       $v0, $v0, 3
/* D61DF4 802408F4 00561021 */  addu      $v0, $v0, $s6
/* D61DF8 802408F8 C440006C */  lwc1      $f0, 0x6c($v0)
/* D61DFC 802408FC 16600065 */  bnez      $s3, .L80240A94
/* D61E00 80240900 46000507 */   neg.s    $f20, $f0
/* D61E04 80240904 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D61E08 80240908 3C0142B4 */  lui       $at, 0x42b4
/* D61E0C 8024090C 44810000 */  mtc1      $at, $f0
/* D61E10 80240910 00000000 */  nop
/* D61E14 80240914 4602003C */  c.lt.s    $f0, $f2
/* D61E18 80240918 00000000 */  nop
/* D61E1C 8024091C 4500000A */  bc1f      .L80240948
/* D61E20 80240920 00000000 */   nop
/* D61E24 80240924 3C014334 */  lui       $at, 0x4334
/* D61E28 80240928 44812000 */  mtc1      $at, $f4
/* D61E2C 8024092C 00000000 */  nop
/* D61E30 80240930 4604103E */  c.le.s    $f2, $f4
/* D61E34 80240934 00000000 */  nop
/* D61E38 80240938 45000003 */  bc1f      .L80240948
/* D61E3C 8024093C 00000000 */   nop
/* D61E40 80240940 08090276 */  j         .L802409D8
/* D61E44 80240944 46022501 */   sub.s    $f20, $f4, $f2
.L80240948:
/* D61E48 80240948 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D61E4C 8024094C 3C014334 */  lui       $at, 0x4334
/* D61E50 80240950 44812000 */  mtc1      $at, $f4
/* D61E54 80240954 00000000 */  nop
/* D61E58 80240958 4600203C */  c.lt.s    $f4, $f0
/* D61E5C 8024095C 00000000 */  nop
/* D61E60 80240960 4500000C */  bc1f      .L80240994
/* D61E64 80240964 00000000 */   nop
/* D61E68 80240968 3C014387 */  lui       $at, 0x4387
/* D61E6C 8024096C 44812000 */  mtc1      $at, $f4
/* D61E70 80240970 00000000 */  nop
/* D61E74 80240974 4604003E */  c.le.s    $f0, $f4
/* D61E78 80240978 00000000 */  nop
/* D61E7C 8024097C 45000008 */  bc1f      .L802409A0
/* D61E80 80240980 00000000 */   nop
/* D61E84 80240984 3C014334 */  lui       $at, 0x4334
/* D61E88 80240988 44812000 */  mtc1      $at, $f4
/* D61E8C 8024098C 08090276 */  j         .L802409D8
/* D61E90 80240990 46040501 */   sub.s    $f20, $f0, $f4
.L80240994:
/* D61E94 80240994 3C014387 */  lui       $at, 0x4387
/* D61E98 80240998 44812000 */  mtc1      $at, $f4
/* D61E9C 8024099C 00000000 */  nop
.L802409A0:
/* D61EA0 802409A0 4600203C */  c.lt.s    $f4, $f0
/* D61EA4 802409A4 00000000 */  nop
/* D61EA8 802409A8 4500000A */  bc1f      .L802409D4
/* D61EAC 802409AC 00000000 */   nop
/* D61EB0 802409B0 3C0143B4 */  lui       $at, 0x43b4
/* D61EB4 802409B4 44811000 */  mtc1      $at, $f2
/* D61EB8 802409B8 00000000 */  nop
/* D61EBC 802409BC 4602003E */  c.le.s    $f0, $f2
/* D61EC0 802409C0 00000000 */  nop
/* D61EC4 802409C4 45000003 */  bc1f      .L802409D4
/* D61EC8 802409C8 00000000 */   nop
/* D61ECC 802409CC 08090276 */  j         .L802409D8
/* D61ED0 802409D0 46001501 */   sub.s    $f20, $f2, $f0
.L802409D4:
/* D61ED4 802409D4 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L802409D8:
/* D61ED8 802409D8 3C0141C8 */  lui       $at, 0x41c8
/* D61EDC 802409DC 44810000 */  mtc1      $at, $f0
/* D61EE0 802409E0 00000000 */  nop
/* D61EE4 802409E4 4600A003 */  div.s     $f0, $f20, $f0
/* D61EE8 802409E8 4600010D */  trunc.w.s $f4, $f0
/* D61EEC 802409EC 44072000 */  mfc1      $a3, $f4
/* D61EF0 802409F0 00000000 */  nop
/* D61EF4 802409F4 00071100 */  sll       $v0, $a3, 4
/* D61EF8 802409F8 00471023 */  subu      $v0, $v0, $a3
/* D61EFC 802409FC 00021080 */  sll       $v0, $v0, 2
/* D61F00 80240A00 02A23823 */  subu      $a3, $s5, $v0
/* D61F04 80240A04 28E20064 */  slti      $v0, $a3, 0x64
/* D61F08 80240A08 54400001 */  bnel      $v0, $zero, .L80240A10
/* D61F0C 80240A0C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A10:
/* D61F10 80240A10 24040001 */  addiu     $a0, $zero, 1
/* D61F14 80240A14 2405FFFF */  addiu     $a1, $zero, -1
/* D61F18 80240A18 24060006 */  addiu     $a2, $zero, 6
/* D61F1C 80240A1C AFA70010 */  sw        $a3, 0x10($sp)
/* D61F20 80240A20 AFA70014 */  sw        $a3, 0x14($sp)
/* D61F24 80240A24 AFB50018 */  sw        $s5, 0x18($sp)
/* D61F28 80240A28 0C0B77B9 */  jal       func_802DDEE4
/* D61F2C 80240A2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D61F30 80240A30 4405A000 */  mfc1      $a1, $f20
/* D61F34 80240A34 4406B000 */  mfc1      $a2, $f22
/* D61F38 80240A38 3C07BF80 */  lui       $a3, 0xbf80
/* D61F3C 80240A3C 0200202D */  daddu     $a0, $s0, $zero
/* D61F40 80240A40 0C019EC8 */  jal       guRotateF
/* D61F44 80240A44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D61F48 80240A48 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D61F4C 80240A4C 0C00A6C9 */  jal       clamp_angle
/* D61F50 80240A50 00000000 */   nop
/* D61F54 80240A54 44050000 */  mfc1      $a1, $f0
/* D61F58 80240A58 4406B000 */  mfc1      $a2, $f22
/* D61F5C 80240A5C 4407B000 */  mfc1      $a3, $f22
/* D61F60 80240A60 3C013F80 */  lui       $at, 0x3f80
/* D61F64 80240A64 44812000 */  mtc1      $at, $f4
/* D61F68 80240A68 27A40020 */  addiu     $a0, $sp, 0x20
/* D61F6C 80240A6C 0C019EC8 */  jal       guRotateF
/* D61F70 80240A70 E7A40010 */   swc1     $f4, 0x10($sp)
/* D61F74 80240A74 0200202D */  daddu     $a0, $s0, $zero
/* D61F78 80240A78 27A50020 */  addiu     $a1, $sp, 0x20
/* D61F7C 80240A7C 0C019D80 */  jal       guMtxCatF
/* D61F80 80240A80 00A0302D */   daddu    $a2, $a1, $zero
/* D61F84 80240A84 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D61F88 80240A88 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D61F8C 80240A8C 080902D6 */  j         .L80240B58
/* D61F90 80240A90 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240A94:
/* D61F94 80240A94 0260202D */  daddu     $a0, $s3, $zero
/* D61F98 80240A98 27A50120 */  addiu     $a1, $sp, 0x120
/* D61F9C 80240A9C 27A60124 */  addiu     $a2, $sp, 0x124
/* D61FA0 80240AA0 0C03964E */  jal       func_800E5938
/* D61FA4 80240AA4 27A70128 */   addiu    $a3, $sp, 0x128
/* D61FA8 80240AA8 8FA60124 */  lw        $a2, 0x124($sp)
/* D61FAC 80240AAC 3C028000 */  lui       $v0, 0x8000
/* D61FB0 80240AB0 14C20004 */  bne       $a2, $v0, .L80240AC4
/* D61FB4 80240AB4 46000606 */   mov.s    $f24, $f0
/* D61FB8 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D61FBC 80240ABC 080902B5 */  j         .L80240AD4
/* D61FC0 80240AC0 24040001 */   addiu    $a0, $zero, 1
.L80240AC4:
/* D61FC4 80240AC4 4486D000 */  mtc1      $a2, $f26
/* D61FC8 80240AC8 00000000 */  nop
/* D61FCC 80240ACC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D61FD0 80240AD0 24040001 */  addiu     $a0, $zero, 1
.L80240AD4:
/* D61FD4 80240AD4 2405FFFF */  addiu     $a1, $zero, -1
/* D61FD8 80240AD8 24060007 */  addiu     $a2, $zero, 7
/* D61FDC 80240ADC 0000382D */  daddu     $a3, $zero, $zero
/* D61FE0 80240AE0 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D61FE4 80240AE4 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D61FE8 80240AE8 24020040 */  addiu     $v0, $zero, 0x40
/* D61FEC 80240AEC AFA00010 */  sw        $zero, 0x10($sp)
/* D61FF0 80240AF0 AFA00014 */  sw        $zero, 0x14($sp)
/* D61FF4 80240AF4 AFA20018 */  sw        $v0, 0x18($sp)
/* D61FF8 80240AF8 0C0B77B9 */  jal       func_802DDEE4
/* D61FFC 80240AFC AFA0001C */   sw       $zero, 0x1c($sp)
/* D62000 80240B00 4405A000 */  mfc1      $a1, $f20
/* D62004 80240B04 4406B000 */  mfc1      $a2, $f22
/* D62008 80240B08 3C07BF80 */  lui       $a3, 0xbf80
/* D6200C 80240B0C 27A40020 */  addiu     $a0, $sp, 0x20
/* D62010 80240B10 0C019EC8 */  jal       guRotateF
/* D62014 80240B14 E7B60010 */   swc1     $f22, 0x10($sp)
/* D62018 80240B18 4405A000 */  mfc1      $a1, $f20
/* D6201C 80240B1C 4406B000 */  mfc1      $a2, $f22
/* D62020 80240B20 3C07BF80 */  lui       $a3, 0xbf80
/* D62024 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* D62028 80240B28 0C019EC8 */  jal       guRotateF
/* D6202C 80240B2C E7B60010 */   swc1     $f22, 0x10($sp)
/* D62030 80240B30 4405C000 */  mfc1      $a1, $f24
/* D62034 80240B34 4406B000 */  mfc1      $a2, $f22
/* D62038 80240B38 3C073F80 */  lui       $a3, 0x3f80
/* D6203C 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D62040 80240B40 0C019EC8 */  jal       guRotateF
/* D62044 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D62048 80240B48 0200202D */  daddu     $a0, $s0, $zero
/* D6204C 80240B4C 27A50020 */  addiu     $a1, $sp, 0x20
/* D62050 80240B50 0C019D80 */  jal       guMtxCatF
/* D62054 80240B54 00A0302D */   daddu    $a2, $a1, $zero
.L80240B58:
/* D62058 80240B58 862200B0 */  lh        $v0, 0xb0($s1)
/* D6205C 80240B5C 3C013F00 */  lui       $at, 0x3f00
/* D62060 80240B60 44812000 */  mtc1      $at, $f4
/* D62064 80240B64 00021023 */  negu      $v0, $v0
/* D62068 80240B68 44820000 */  mtc1      $v0, $f0
/* D6206C 80240B6C 00000000 */  nop
/* D62070 80240B70 46800020 */  cvt.s.w   $f0, $f0
/* D62074 80240B74 46040102 */  mul.s     $f4, $f0, $f4
/* D62078 80240B78 00000000 */  nop
/* D6207C 80240B7C 4405B000 */  mfc1      $a1, $f22
/* D62080 80240B80 4407B000 */  mfc1      $a3, $f22
/* D62084 80240B84 44062000 */  mfc1      $a2, $f4
/* D62088 80240B88 0C019E40 */  jal       guTranslateF
/* D6208C 80240B8C 0240202D */   daddu    $a0, $s2, $zero
/* D62090 80240B90 0240202D */  daddu     $a0, $s2, $zero
/* D62094 80240B94 27A50020 */  addiu     $a1, $sp, 0x20
/* D62098 80240B98 0C019D80 */  jal       guMtxCatF
/* D6209C 80240B9C 00A0302D */   daddu    $a2, $a1, $zero
/* D620A0 80240BA0 4405A000 */  mfc1      $a1, $f20
/* D620A4 80240BA4 4406B000 */  mfc1      $a2, $f22
/* D620A8 80240BA8 3C073F80 */  lui       $a3, 0x3f80
/* D620AC 80240BAC 0200202D */  daddu     $a0, $s0, $zero
/* D620B0 80240BB0 0C019EC8 */  jal       guRotateF
/* D620B4 80240BB4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D620B8 80240BB8 27A40020 */  addiu     $a0, $sp, 0x20
/* D620BC 80240BBC 0200282D */  daddu     $a1, $s0, $zero
/* D620C0 80240BC0 0C019D80 */  jal       guMtxCatF
/* D620C4 80240BC4 0080302D */   daddu    $a2, $a0, $zero
/* D620C8 80240BC8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D620CC 80240BCC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D620D0 80240BD0 4406B000 */  mfc1      $a2, $f22
/* D620D4 80240BD4 3C073F80 */  lui       $a3, 0x3f80
/* D620D8 80240BD8 0C019EC8 */  jal       guRotateF
/* D620DC 80240BDC 0200202D */   daddu    $a0, $s0, $zero
/* D620E0 80240BE0 27A40020 */  addiu     $a0, $sp, 0x20
/* D620E4 80240BE4 0200282D */  daddu     $a1, $s0, $zero
/* D620E8 80240BE8 0C019D80 */  jal       guMtxCatF
/* D620EC 80240BEC 0080302D */   daddu    $a2, $a0, $zero
/* D620F0 80240BF0 862200B0 */  lh        $v0, 0xb0($s1)
/* D620F4 80240BF4 3C013F00 */  lui       $at, 0x3f00
/* D620F8 80240BF8 44812000 */  mtc1      $at, $f4
/* D620FC 80240BFC 44820000 */  mtc1      $v0, $f0
/* D62100 80240C00 00000000 */  nop
/* D62104 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* D62108 80240C08 46040102 */  mul.s     $f4, $f0, $f4
/* D6210C 80240C0C 00000000 */  nop
/* D62110 80240C10 4405B000 */  mfc1      $a1, $f22
/* D62114 80240C14 4407B000 */  mfc1      $a3, $f22
/* D62118 80240C18 44062000 */  mfc1      $a2, $f4
/* D6211C 80240C1C 0C019E40 */  jal       guTranslateF
/* D62120 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* D62124 80240C24 27A40020 */  addiu     $a0, $sp, 0x20
/* D62128 80240C28 0240282D */  daddu     $a1, $s2, $zero
/* D6212C 80240C2C 0C019D80 */  jal       guMtxCatF
/* D62130 80240C30 0080302D */   daddu    $a2, $a0, $zero
/* D62134 80240C34 3C013F36 */  lui       $at, 0x3f36
/* D62138 80240C38 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6213C 80240C3C 44810000 */  mtc1      $at, $f0
/* D62140 80240C40 0280202D */  daddu     $a0, $s4, $zero
/* D62144 80240C44 44050000 */  mfc1      $a1, $f0
/* D62148 80240C48 3C06BF36 */  lui       $a2, 0xbf36
/* D6214C 80240C4C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D62150 80240C50 0C019DF0 */  jal       guScaleF
/* D62154 80240C54 00A0382D */   daddu    $a3, $a1, $zero
/* D62158 80240C58 27A40020 */  addiu     $a0, $sp, 0x20
/* D6215C 80240C5C 0280282D */  daddu     $a1, $s4, $zero
/* D62160 80240C60 0C019D80 */  jal       guMtxCatF
/* D62164 80240C64 0080302D */   daddu    $a2, $a0, $zero
/* D62168 80240C68 4600D687 */  neg.s     $f26, $f26
/* D6216C 80240C6C 4405F000 */  mfc1      $a1, $f30
/* D62170 80240C70 4407E000 */  mfc1      $a3, $f28
/* D62174 80240C74 4406D000 */  mfc1      $a2, $f26
/* D62178 80240C78 0C019E40 */  jal       guTranslateF
/* D6217C 80240C7C 0240202D */   daddu    $a0, $s2, $zero
/* D62180 80240C80 27A40020 */  addiu     $a0, $sp, 0x20
/* D62184 80240C84 0240282D */  daddu     $a1, $s2, $zero
/* D62188 80240C88 0C019D80 */  jal       guMtxCatF
/* D6218C 80240C8C 0080302D */   daddu    $a2, $a0, $zero
/* D62190 80240C90 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D62194 80240C94 3C0142B4 */  lui       $at, 0x42b4
/* D62198 80240C98 44810000 */  mtc1      $at, $f0
/* D6219C 80240C9C 00000000 */  nop
/* D621A0 80240CA0 4602003E */  c.le.s    $f0, $f2
/* D621A4 80240CA4 00000000 */  nop
/* D621A8 80240CA8 4500000A */  bc1f      .L80240CD4
/* D621AC 80240CAC 24040001 */   addiu    $a0, $zero, 1
/* D621B0 80240CB0 3C014387 */  lui       $at, 0x4387
/* D621B4 80240CB4 44812000 */  mtc1      $at, $f4
/* D621B8 80240CB8 00000000 */  nop
/* D621BC 80240CBC 4604103C */  c.lt.s    $f2, $f4
/* D621C0 80240CC0 00000000 */  nop
/* D621C4 80240CC4 45000004 */  bc1f      .L80240CD8
/* D621C8 80240CC8 27A20020 */   addiu    $v0, $sp, 0x20
/* D621CC 80240CCC 3C041000 */  lui       $a0, 0x1000
/* D621D0 80240CD0 34840001 */  ori       $a0, $a0, 1
.L80240CD4:
/* D621D4 80240CD4 27A20020 */  addiu     $v0, $sp, 0x20
.L80240CD8:
/* D621D8 80240CD8 AFA20010 */  sw        $v0, 0x10($sp)
/* D621DC 80240CDC 0000282D */  daddu     $a1, $zero, $zero
/* D621E0 80240CE0 00A0302D */  daddu     $a2, $a1, $zero
/* D621E4 80240CE4 0C0B7710 */  jal       render_sprite
/* D621E8 80240CE8 00A0382D */   daddu    $a3, $a1, $zero
/* D621EC 80240CEC 26730001 */  addiu     $s3, $s3, 1
/* D621F0 80240CF0 2A620002 */  slti      $v0, $s3, 2
/* D621F4 80240CF4 1440FEF6 */  bnez      $v0, .L802408D0
/* D621F8 80240CF8 00000000 */   nop
/* D621FC 80240CFC 8FBF014C */  lw        $ra, 0x14c($sp)
/* D62200 80240D00 8FB60148 */  lw        $s6, 0x148($sp)
/* D62204 80240D04 8FB50144 */  lw        $s5, 0x144($sp)
/* D62208 80240D08 8FB40140 */  lw        $s4, 0x140($sp)
/* D6220C 80240D0C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D62210 80240D10 8FB20138 */  lw        $s2, 0x138($sp)
/* D62214 80240D14 8FB10134 */  lw        $s1, 0x134($sp)
/* D62218 80240D18 8FB00130 */  lw        $s0, 0x130($sp)
/* D6221C 80240D1C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D62220 80240D20 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D62224 80240D24 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D62228 80240D28 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D6222C 80240D2C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D62230 80240D30 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D62234 80240D34 03E00008 */  jr        $ra
/* D62238 80240D38 27BD0180 */   addiu    $sp, $sp, 0x180
