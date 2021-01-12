.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D899D0
/* D899D0 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D899D4 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D899D8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D899DC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D899E0 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D899E4 80240304 4480A000 */  mtc1      $zero, $f20
/* D899E8 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D899EC 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D899F0 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D899F4 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D899F8 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D899FC 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D89A00 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D89A04 80240324 00031080 */  sll       $v0, $v1, 2
/* D89A08 80240328 00431021 */  addu      $v0, $v0, $v1
/* D89A0C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D89A10 80240330 00431023 */  subu      $v0, $v0, $v1
/* D89A14 80240334 000218C0 */  sll       $v1, $v0, 3
/* D89A18 80240338 00431021 */  addu      $v0, $v0, $v1
/* D89A1C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D89A20 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D89A24 80240344 00220821 */  addu      $at, $at, $v0
/* D89A28 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D89A2C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D89A30 80240350 4600B587 */  neg.s     $f22, $f22
/* D89A34 80240354 4405B000 */  mfc1      $a1, $f22
/* D89A38 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D89A3C 8024035C 0C019EC8 */  jal       guRotateF
/* D89A40 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D89A44 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D89A48 80240368 0C00A6C9 */  jal       clamp_angle
/* D89A4C 8024036C 00000000 */   nop
/* D89A50 80240370 44050000 */  mfc1      $a1, $f0
/* D89A54 80240374 4406A000 */  mfc1      $a2, $f20
/* D89A58 80240378 4407A000 */  mfc1      $a3, $f20
/* D89A5C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D89A60 80240380 4481C000 */  mtc1      $at, $f24
/* D89A64 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D89A68 80240388 0C019EC8 */  jal       guRotateF
/* D89A6C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D89A70 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D89A74 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D89A78 80240398 0C019D80 */  jal       guMtxCatF
/* D89A7C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D89A80 802403A0 4405B000 */  mfc1      $a1, $f22
/* D89A84 802403A4 4406A000 */  mfc1      $a2, $f20
/* D89A88 802403A8 4407C000 */  mfc1      $a3, $f24
/* D89A8C 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D89A90 802403B0 0C019EC8 */  jal       guRotateF
/* D89A94 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D89A98 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D89A9C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D89AA0 802403C0 0C019D80 */  jal       guMtxCatF
/* D89AA4 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D89AA8 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D89AAC 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D89AB0 802403D0 4406A000 */  mfc1      $a2, $f20
/* D89AB4 802403D4 4407C000 */  mfc1      $a3, $f24
/* D89AB8 802403D8 0C019EC8 */  jal       guRotateF
/* D89ABC 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D89AC0 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D89AC4 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D89AC8 802403E8 0C019D80 */  jal       guMtxCatF
/* D89ACC 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D89AD0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D89AD4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D89AD8 802403F8 44810000 */  mtc1      $at, $f0
/* D89ADC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D89AE0 80240400 44050000 */  mfc1      $a1, $f0
/* D89AE4 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D89AE8 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D89AEC 8024040C 0C019DF0 */  jal       guScaleF
/* D89AF0 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D89AF4 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D89AF8 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D89AFC 8024041C 0C019D80 */  jal       guMtxCatF
/* D89B00 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D89B04 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D89B08 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D89B0C 8024042C 3C014040 */  lui       $at, 0x4040
/* D89B10 80240430 44811000 */  mtc1      $at, $f2
/* D89B14 80240434 46000007 */  neg.s     $f0, $f0
/* D89B18 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D89B1C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D89B20 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D89B24 80240444 44070000 */  mfc1      $a3, $f0
/* D89B28 80240448 0C019E40 */  jal       guTranslateF
/* D89B2C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D89B30 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D89B34 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D89B38 80240458 0C019D80 */  jal       guMtxCatF
/* D89B3C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D89B40 80240460 24040002 */  addiu     $a0, $zero, 2
/* D89B44 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D89B48 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D89B4C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D89B50 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D89B54 80240474 0C0B7710 */  jal       render_sprite
/* D89B58 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D89B5C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D89B60 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D89B64 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D89B68 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D89B6C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D89B70 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D89B74 80240494 03E00008 */  jr        $ra
/* D89B78 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
