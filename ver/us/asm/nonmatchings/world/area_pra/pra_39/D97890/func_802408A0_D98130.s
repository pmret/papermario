.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A0_D98130
/* D98130 802408A0 27BDFE80 */  addiu     $sp, $sp, -0x180
/* D98134 802408A4 F7B60158 */  sdc1      $f22, 0x158($sp)
/* D98138 802408A8 4480B000 */  mtc1      $zero, $f22
/* D9813C 802408AC AFB10134 */  sw        $s1, 0x134($sp)
/* D98140 802408B0 0080882D */  daddu     $s1, $a0, $zero
/* D98144 802408B4 AFB3013C */  sw        $s3, 0x13c($sp)
/* D98148 802408B8 0000982D */  daddu     $s3, $zero, $zero
/* D9814C 802408BC AFB60148 */  sw        $s6, 0x148($sp)
/* D98150 802408C0 3C16800B */  lui       $s6, %hi(gCameras)
/* D98154 802408C4 26D61D80 */  addiu     $s6, $s6, %lo(gCameras)
/* D98158 802408C8 AFB50144 */  sw        $s5, 0x144($sp)
/* D9815C 802408CC 241500FF */  addiu     $s5, $zero, 0xff
/* D98160 802408D0 AFB00130 */  sw        $s0, 0x130($sp)
/* D98164 802408D4 27B000A0 */  addiu     $s0, $sp, 0xa0
/* D98168 802408D8 AFB20138 */  sw        $s2, 0x138($sp)
/* D9816C 802408DC 27B20060 */  addiu     $s2, $sp, 0x60
/* D98170 802408E0 AFB40140 */  sw        $s4, 0x140($sp)
/* D98174 802408E4 27B400E0 */  addiu     $s4, $sp, 0xe0
/* D98178 802408E8 AFBF014C */  sw        $ra, 0x14c($sp)
/* D9817C 802408EC F7BE0178 */  sdc1      $f30, 0x178($sp)
/* D98180 802408F0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* D98184 802408F4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* D98188 802408F8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* D9818C 802408FC F7B40150 */  sdc1      $f20, 0x150($sp)
.L80240900:
/* D98190 80240900 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D98194 80240904 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D98198 80240908 00031080 */  sll       $v0, $v1, 2
/* D9819C 8024090C 00431021 */  addu      $v0, $v0, $v1
/* D981A0 80240910 00021080 */  sll       $v0, $v0, 2
/* D981A4 80240914 00431023 */  subu      $v0, $v0, $v1
/* D981A8 80240918 000218C0 */  sll       $v1, $v0, 3
/* D981AC 8024091C 00431021 */  addu      $v0, $v0, $v1
/* D981B0 80240920 000210C0 */  sll       $v0, $v0, 3
/* D981B4 80240924 00561021 */  addu      $v0, $v0, $s6
/* D981B8 80240928 C440006C */  lwc1      $f0, 0x6c($v0)
/* D981BC 8024092C 16600065 */  bnez      $s3, .L80240AC4
/* D981C0 80240930 46000507 */   neg.s    $f20, $f0
/* D981C4 80240934 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D981C8 80240938 3C0142B4 */  lui       $at, 0x42b4
/* D981CC 8024093C 44810000 */  mtc1      $at, $f0
/* D981D0 80240940 00000000 */  nop
/* D981D4 80240944 4602003C */  c.lt.s    $f0, $f2
/* D981D8 80240948 00000000 */  nop
/* D981DC 8024094C 4500000A */  bc1f      .L80240978
/* D981E0 80240950 00000000 */   nop
/* D981E4 80240954 3C014334 */  lui       $at, 0x4334
/* D981E8 80240958 44812000 */  mtc1      $at, $f4
/* D981EC 8024095C 00000000 */  nop
/* D981F0 80240960 4604103E */  c.le.s    $f2, $f4
/* D981F4 80240964 00000000 */  nop
/* D981F8 80240968 45000003 */  bc1f      .L80240978
/* D981FC 8024096C 00000000 */   nop
/* D98200 80240970 08090282 */  j         .L80240A08
/* D98204 80240974 46022501 */   sub.s    $f20, $f4, $f2
.L80240978:
/* D98208 80240978 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* D9820C 8024097C 3C014334 */  lui       $at, 0x4334
/* D98210 80240980 44812000 */  mtc1      $at, $f4
/* D98214 80240984 00000000 */  nop
/* D98218 80240988 4600203C */  c.lt.s    $f4, $f0
/* D9821C 8024098C 00000000 */  nop
/* D98220 80240990 4500000C */  bc1f      .L802409C4
/* D98224 80240994 00000000 */   nop
/* D98228 80240998 3C014387 */  lui       $at, 0x4387
/* D9822C 8024099C 44812000 */  mtc1      $at, $f4
/* D98230 802409A0 00000000 */  nop
/* D98234 802409A4 4604003E */  c.le.s    $f0, $f4
/* D98238 802409A8 00000000 */  nop
/* D9823C 802409AC 45000008 */  bc1f      .L802409D0
/* D98240 802409B0 00000000 */   nop
/* D98244 802409B4 3C014334 */  lui       $at, 0x4334
/* D98248 802409B8 44812000 */  mtc1      $at, $f4
/* D9824C 802409BC 08090282 */  j         .L80240A08
/* D98250 802409C0 46040501 */   sub.s    $f20, $f0, $f4
.L802409C4:
/* D98254 802409C4 3C014387 */  lui       $at, 0x4387
/* D98258 802409C8 44812000 */  mtc1      $at, $f4
/* D9825C 802409CC 00000000 */  nop
.L802409D0:
/* D98260 802409D0 4600203C */  c.lt.s    $f4, $f0
/* D98264 802409D4 00000000 */  nop
/* D98268 802409D8 4500000A */  bc1f      .L80240A04
/* D9826C 802409DC 00000000 */   nop
/* D98270 802409E0 3C0143B4 */  lui       $at, 0x43b4
/* D98274 802409E4 44811000 */  mtc1      $at, $f2
/* D98278 802409E8 00000000 */  nop
/* D9827C 802409EC 4602003E */  c.le.s    $f0, $f2
/* D98280 802409F0 00000000 */  nop
/* D98284 802409F4 45000003 */  bc1f      .L80240A04
/* D98288 802409F8 00000000 */   nop
/* D9828C 802409FC 08090282 */  j         .L80240A08
/* D98290 80240A00 46001501 */   sub.s    $f20, $f2, $f0
.L80240A04:
/* D98294 80240A04 C63400A8 */  lwc1      $f20, 0xa8($s1)
.L80240A08:
/* D98298 80240A08 3C0141C8 */  lui       $at, 0x41c8
/* D9829C 80240A0C 44810000 */  mtc1      $at, $f0
/* D982A0 80240A10 00000000 */  nop
/* D982A4 80240A14 4600A003 */  div.s     $f0, $f20, $f0
/* D982A8 80240A18 4600010D */  trunc.w.s $f4, $f0
/* D982AC 80240A1C 44072000 */  mfc1      $a3, $f4
/* D982B0 80240A20 00000000 */  nop
/* D982B4 80240A24 00071100 */  sll       $v0, $a3, 4
/* D982B8 80240A28 00471023 */  subu      $v0, $v0, $a3
/* D982BC 80240A2C 00021080 */  sll       $v0, $v0, 2
/* D982C0 80240A30 02A23823 */  subu      $a3, $s5, $v0
/* D982C4 80240A34 28E20064 */  slti      $v0, $a3, 0x64
/* D982C8 80240A38 54400001 */  bnel      $v0, $zero, .L80240A40
/* D982CC 80240A3C 24070064 */   addiu    $a3, $zero, 0x64
.L80240A40:
/* D982D0 80240A40 24040001 */  addiu     $a0, $zero, 1
/* D982D4 80240A44 2405FFFF */  addiu     $a1, $zero, -1
/* D982D8 80240A48 24060006 */  addiu     $a2, $zero, 6
/* D982DC 80240A4C AFA70010 */  sw        $a3, 0x10($sp)
/* D982E0 80240A50 AFA70014 */  sw        $a3, 0x14($sp)
/* D982E4 80240A54 AFB50018 */  sw        $s5, 0x18($sp)
/* D982E8 80240A58 0C0B77B9 */  jal       func_802DDEE4
/* D982EC 80240A5C AFA0001C */   sw       $zero, 0x1c($sp)
/* D982F0 80240A60 4405A000 */  mfc1      $a1, $f20
/* D982F4 80240A64 4406B000 */  mfc1      $a2, $f22
/* D982F8 80240A68 3C07BF80 */  lui       $a3, 0xbf80
/* D982FC 80240A6C 0200202D */  daddu     $a0, $s0, $zero
/* D98300 80240A70 0C019EC8 */  jal       guRotateF
/* D98304 80240A74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D98308 80240A78 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D9830C 80240A7C 0C00A6C9 */  jal       clamp_angle
/* D98310 80240A80 00000000 */   nop
/* D98314 80240A84 44050000 */  mfc1      $a1, $f0
/* D98318 80240A88 4406B000 */  mfc1      $a2, $f22
/* D9831C 80240A8C 4407B000 */  mfc1      $a3, $f22
/* D98320 80240A90 3C013F80 */  lui       $at, 0x3f80
/* D98324 80240A94 44812000 */  mtc1      $at, $f4
/* D98328 80240A98 27A40020 */  addiu     $a0, $sp, 0x20
/* D9832C 80240A9C 0C019EC8 */  jal       guRotateF
/* D98330 80240AA0 E7A40010 */   swc1     $f4, 0x10($sp)
/* D98334 80240AA4 0200202D */  daddu     $a0, $s0, $zero
/* D98338 80240AA8 27A50020 */  addiu     $a1, $sp, 0x20
/* D9833C 80240AAC 0C019D80 */  jal       guMtxCatF
/* D98340 80240AB0 00A0302D */   daddu    $a2, $a1, $zero
/* D98344 80240AB4 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D98348 80240AB8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D9834C 80240ABC 080902E2 */  j         .L80240B88
/* D98350 80240AC0 C63C0030 */   lwc1     $f28, 0x30($s1)
.L80240AC4:
/* D98354 80240AC4 0260202D */  daddu     $a0, $s3, $zero
/* D98358 80240AC8 27A50120 */  addiu     $a1, $sp, 0x120
/* D9835C 80240ACC 27A60124 */  addiu     $a2, $sp, 0x124
/* D98360 80240AD0 0C03964E */  jal       func_800E5938
/* D98364 80240AD4 27A70128 */   addiu    $a3, $sp, 0x128
/* D98368 80240AD8 8FA60124 */  lw        $a2, 0x124($sp)
/* D9836C 80240ADC 3C028000 */  lui       $v0, 0x8000
/* D98370 80240AE0 14C20004 */  bne       $a2, $v0, .L80240AF4
/* D98374 80240AE4 46000606 */   mov.s    $f24, $f0
/* D98378 80240AE8 C63A002C */  lwc1      $f26, 0x2c($s1)
/* D9837C 80240AEC 080902C1 */  j         .L80240B04
/* D98380 80240AF0 24040001 */   addiu    $a0, $zero, 1
.L80240AF4:
/* D98384 80240AF4 4486D000 */  mtc1      $a2, $f26
/* D98388 80240AF8 00000000 */  nop
/* D9838C 80240AFC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D98390 80240B00 24040001 */  addiu     $a0, $zero, 1
.L80240B04:
/* D98394 80240B04 2405FFFF */  addiu     $a1, $zero, -1
/* D98398 80240B08 24060007 */  addiu     $a2, $zero, 7
/* D9839C 80240B0C 0000382D */  daddu     $a3, $zero, $zero
/* D983A0 80240B10 C63E0028 */  lwc1      $f30, 0x28($s1)
/* D983A4 80240B14 C63C0030 */  lwc1      $f28, 0x30($s1)
/* D983A8 80240B18 24020040 */  addiu     $v0, $zero, 0x40
/* D983AC 80240B1C AFA00010 */  sw        $zero, 0x10($sp)
/* D983B0 80240B20 AFA00014 */  sw        $zero, 0x14($sp)
/* D983B4 80240B24 AFA20018 */  sw        $v0, 0x18($sp)
/* D983B8 80240B28 0C0B77B9 */  jal       func_802DDEE4
/* D983BC 80240B2C AFA0001C */   sw       $zero, 0x1c($sp)
/* D983C0 80240B30 4405A000 */  mfc1      $a1, $f20
/* D983C4 80240B34 4406B000 */  mfc1      $a2, $f22
/* D983C8 80240B38 3C07BF80 */  lui       $a3, 0xbf80
/* D983CC 80240B3C 27A40020 */  addiu     $a0, $sp, 0x20
/* D983D0 80240B40 0C019EC8 */  jal       guRotateF
/* D983D4 80240B44 E7B60010 */   swc1     $f22, 0x10($sp)
/* D983D8 80240B48 4405A000 */  mfc1      $a1, $f20
/* D983DC 80240B4C 4406B000 */  mfc1      $a2, $f22
/* D983E0 80240B50 3C07BF80 */  lui       $a3, 0xbf80
/* D983E4 80240B54 0200202D */  daddu     $a0, $s0, $zero
/* D983E8 80240B58 0C019EC8 */  jal       guRotateF
/* D983EC 80240B5C E7B60010 */   swc1     $f22, 0x10($sp)
/* D983F0 80240B60 4405C000 */  mfc1      $a1, $f24
/* D983F4 80240B64 4406B000 */  mfc1      $a2, $f22
/* D983F8 80240B68 3C073F80 */  lui       $a3, 0x3f80
/* D983FC 80240B6C 27A40020 */  addiu     $a0, $sp, 0x20
/* D98400 80240B70 0C019EC8 */  jal       guRotateF
/* D98404 80240B74 E7B60010 */   swc1     $f22, 0x10($sp)
/* D98408 80240B78 0200202D */  daddu     $a0, $s0, $zero
/* D9840C 80240B7C 27A50020 */  addiu     $a1, $sp, 0x20
/* D98410 80240B80 0C019D80 */  jal       guMtxCatF
/* D98414 80240B84 00A0302D */   daddu    $a2, $a1, $zero
.L80240B88:
/* D98418 80240B88 862200B0 */  lh        $v0, 0xb0($s1)
/* D9841C 80240B8C 3C013F00 */  lui       $at, 0x3f00
/* D98420 80240B90 44812000 */  mtc1      $at, $f4
/* D98424 80240B94 00021023 */  negu      $v0, $v0
/* D98428 80240B98 44820000 */  mtc1      $v0, $f0
/* D9842C 80240B9C 00000000 */  nop
/* D98430 80240BA0 46800020 */  cvt.s.w   $f0, $f0
/* D98434 80240BA4 46040102 */  mul.s     $f4, $f0, $f4
/* D98438 80240BA8 00000000 */  nop
/* D9843C 80240BAC 4405B000 */  mfc1      $a1, $f22
/* D98440 80240BB0 4407B000 */  mfc1      $a3, $f22
/* D98444 80240BB4 44062000 */  mfc1      $a2, $f4
/* D98448 80240BB8 0C019E40 */  jal       guTranslateF
/* D9844C 80240BBC 0240202D */   daddu    $a0, $s2, $zero
/* D98450 80240BC0 0240202D */  daddu     $a0, $s2, $zero
/* D98454 80240BC4 27A50020 */  addiu     $a1, $sp, 0x20
/* D98458 80240BC8 0C019D80 */  jal       guMtxCatF
/* D9845C 80240BCC 00A0302D */   daddu    $a2, $a1, $zero
/* D98460 80240BD0 4405A000 */  mfc1      $a1, $f20
/* D98464 80240BD4 4406B000 */  mfc1      $a2, $f22
/* D98468 80240BD8 3C073F80 */  lui       $a3, 0x3f80
/* D9846C 80240BDC 0200202D */  daddu     $a0, $s0, $zero
/* D98470 80240BE0 0C019EC8 */  jal       guRotateF
/* D98474 80240BE4 E7B60010 */   swc1     $f22, 0x10($sp)
/* D98478 80240BE8 27A40020 */  addiu     $a0, $sp, 0x20
/* D9847C 80240BEC 0200282D */  daddu     $a1, $s0, $zero
/* D98480 80240BF0 0C019D80 */  jal       guMtxCatF
/* D98484 80240BF4 0080302D */   daddu    $a2, $a0, $zero
/* D98488 80240BF8 E7B60010 */  swc1      $f22, 0x10($sp)
/* D9848C 80240BFC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D98490 80240C00 4406B000 */  mfc1      $a2, $f22
/* D98494 80240C04 3C073F80 */  lui       $a3, 0x3f80
/* D98498 80240C08 0C019EC8 */  jal       guRotateF
/* D9849C 80240C0C 0200202D */   daddu    $a0, $s0, $zero
/* D984A0 80240C10 27A40020 */  addiu     $a0, $sp, 0x20
/* D984A4 80240C14 0200282D */  daddu     $a1, $s0, $zero
/* D984A8 80240C18 0C019D80 */  jal       guMtxCatF
/* D984AC 80240C1C 0080302D */   daddu    $a2, $a0, $zero
/* D984B0 80240C20 862200B0 */  lh        $v0, 0xb0($s1)
/* D984B4 80240C24 3C013F00 */  lui       $at, 0x3f00
/* D984B8 80240C28 44812000 */  mtc1      $at, $f4
/* D984BC 80240C2C 44820000 */  mtc1      $v0, $f0
/* D984C0 80240C30 00000000 */  nop
/* D984C4 80240C34 46800020 */  cvt.s.w   $f0, $f0
/* D984C8 80240C38 46040102 */  mul.s     $f4, $f0, $f4
/* D984CC 80240C3C 00000000 */  nop
/* D984D0 80240C40 4405B000 */  mfc1      $a1, $f22
/* D984D4 80240C44 4407B000 */  mfc1      $a3, $f22
/* D984D8 80240C48 44062000 */  mfc1      $a2, $f4
/* D984DC 80240C4C 0C019E40 */  jal       guTranslateF
/* D984E0 80240C50 0240202D */   daddu    $a0, $s2, $zero
/* D984E4 80240C54 27A40020 */  addiu     $a0, $sp, 0x20
/* D984E8 80240C58 0240282D */  daddu     $a1, $s2, $zero
/* D984EC 80240C5C 0C019D80 */  jal       guMtxCatF
/* D984F0 80240C60 0080302D */   daddu    $a2, $a0, $zero
/* D984F4 80240C64 3C013F36 */  lui       $at, 0x3f36
/* D984F8 80240C68 3421DB6E */  ori       $at, $at, 0xdb6e
/* D984FC 80240C6C 44810000 */  mtc1      $at, $f0
/* D98500 80240C70 0280202D */  daddu     $a0, $s4, $zero
/* D98504 80240C74 44050000 */  mfc1      $a1, $f0
/* D98508 80240C78 3C06BF36 */  lui       $a2, 0xbf36
/* D9850C 80240C7C 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D98510 80240C80 0C019DF0 */  jal       guScaleF
/* D98514 80240C84 00A0382D */   daddu    $a3, $a1, $zero
/* D98518 80240C88 27A40020 */  addiu     $a0, $sp, 0x20
/* D9851C 80240C8C 0280282D */  daddu     $a1, $s4, $zero
/* D98520 80240C90 0C019D80 */  jal       guMtxCatF
/* D98524 80240C94 0080302D */   daddu    $a2, $a0, $zero
/* D98528 80240C98 4600D687 */  neg.s     $f26, $f26
/* D9852C 80240C9C 4405F000 */  mfc1      $a1, $f30
/* D98530 80240CA0 4407E000 */  mfc1      $a3, $f28
/* D98534 80240CA4 4406D000 */  mfc1      $a2, $f26
/* D98538 80240CA8 0C019E40 */  jal       guTranslateF
/* D9853C 80240CAC 0240202D */   daddu    $a0, $s2, $zero
/* D98540 80240CB0 27A40020 */  addiu     $a0, $sp, 0x20
/* D98544 80240CB4 0240282D */  daddu     $a1, $s2, $zero
/* D98548 80240CB8 0C019D80 */  jal       guMtxCatF
/* D9854C 80240CBC 0080302D */   daddu    $a2, $a0, $zero
/* D98550 80240CC0 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D98554 80240CC4 3C0142B4 */  lui       $at, 0x42b4
/* D98558 80240CC8 44810000 */  mtc1      $at, $f0
/* D9855C 80240CCC 00000000 */  nop
/* D98560 80240CD0 4602003E */  c.le.s    $f0, $f2
/* D98564 80240CD4 00000000 */  nop
/* D98568 80240CD8 4500000A */  bc1f      .L80240D04
/* D9856C 80240CDC 24040001 */   addiu    $a0, $zero, 1
/* D98570 80240CE0 3C014387 */  lui       $at, 0x4387
/* D98574 80240CE4 44812000 */  mtc1      $at, $f4
/* D98578 80240CE8 00000000 */  nop
/* D9857C 80240CEC 4604103C */  c.lt.s    $f2, $f4
/* D98580 80240CF0 00000000 */  nop
/* D98584 80240CF4 45000004 */  bc1f      .L80240D08
/* D98588 80240CF8 27A20020 */   addiu    $v0, $sp, 0x20
/* D9858C 80240CFC 3C041000 */  lui       $a0, 0x1000
/* D98590 80240D00 34840001 */  ori       $a0, $a0, 1
.L80240D04:
/* D98594 80240D04 27A20020 */  addiu     $v0, $sp, 0x20
.L80240D08:
/* D98598 80240D08 AFA20010 */  sw        $v0, 0x10($sp)
/* D9859C 80240D0C 0000282D */  daddu     $a1, $zero, $zero
/* D985A0 80240D10 00A0302D */  daddu     $a2, $a1, $zero
/* D985A4 80240D14 0C0B7710 */  jal       render_sprite
/* D985A8 80240D18 00A0382D */   daddu    $a3, $a1, $zero
/* D985AC 80240D1C 26730001 */  addiu     $s3, $s3, 1
/* D985B0 80240D20 2A620002 */  slti      $v0, $s3, 2
/* D985B4 80240D24 1440FEF6 */  bnez      $v0, .L80240900
/* D985B8 80240D28 00000000 */   nop
/* D985BC 80240D2C 8FBF014C */  lw        $ra, 0x14c($sp)
/* D985C0 80240D30 8FB60148 */  lw        $s6, 0x148($sp)
/* D985C4 80240D34 8FB50144 */  lw        $s5, 0x144($sp)
/* D985C8 80240D38 8FB40140 */  lw        $s4, 0x140($sp)
/* D985CC 80240D3C 8FB3013C */  lw        $s3, 0x13c($sp)
/* D985D0 80240D40 8FB20138 */  lw        $s2, 0x138($sp)
/* D985D4 80240D44 8FB10134 */  lw        $s1, 0x134($sp)
/* D985D8 80240D48 8FB00130 */  lw        $s0, 0x130($sp)
/* D985DC 80240D4C D7BE0178 */  ldc1      $f30, 0x178($sp)
/* D985E0 80240D50 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* D985E4 80240D54 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* D985E8 80240D58 D7B80160 */  ldc1      $f24, 0x160($sp)
/* D985EC 80240D5C D7B60158 */  ldc1      $f22, 0x158($sp)
/* D985F0 80240D60 D7B40150 */  ldc1      $f20, 0x150($sp)
/* D985F4 80240D64 03E00008 */  jr        $ra
/* D985F8 80240D68 27BD0180 */   addiu    $sp, $sp, 0x180
