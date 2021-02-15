.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D502E0
/* D502E0 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D502E4 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D502E8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D502EC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D502F0 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D502F4 80240304 4480A000 */  mtc1      $zero, $f20
/* D502F8 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D502FC 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D50300 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D50304 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D50308 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D5030C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D50310 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D50314 80240324 00031080 */  sll       $v0, $v1, 2
/* D50318 80240328 00431021 */  addu      $v0, $v0, $v1
/* D5031C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D50320 80240330 00431023 */  subu      $v0, $v0, $v1
/* D50324 80240334 000218C0 */  sll       $v1, $v0, 3
/* D50328 80240338 00431021 */  addu      $v0, $v0, $v1
/* D5032C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D50330 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D50334 80240344 00220821 */  addu      $at, $at, $v0
/* D50338 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D5033C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D50340 80240350 4600B587 */  neg.s     $f22, $f22
/* D50344 80240354 4405B000 */  mfc1      $a1, $f22
/* D50348 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D5034C 8024035C 0C019EC8 */  jal       guRotateF
/* D50350 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D50354 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D50358 80240368 0C00A6C9 */  jal       clamp_angle
/* D5035C 8024036C 00000000 */   nop
/* D50360 80240370 44050000 */  mfc1      $a1, $f0
/* D50364 80240374 4406A000 */  mfc1      $a2, $f20
/* D50368 80240378 4407A000 */  mfc1      $a3, $f20
/* D5036C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D50370 80240380 4481C000 */  mtc1      $at, $f24
/* D50374 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D50378 80240388 0C019EC8 */  jal       guRotateF
/* D5037C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D50380 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D50384 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D50388 80240398 0C019D80 */  jal       guMtxCatF
/* D5038C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D50390 802403A0 4405B000 */  mfc1      $a1, $f22
/* D50394 802403A4 4406A000 */  mfc1      $a2, $f20
/* D50398 802403A8 4407C000 */  mfc1      $a3, $f24
/* D5039C 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D503A0 802403B0 0C019EC8 */  jal       guRotateF
/* D503A4 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D503A8 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D503AC 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D503B0 802403C0 0C019D80 */  jal       guMtxCatF
/* D503B4 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D503B8 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D503BC 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D503C0 802403D0 4406A000 */  mfc1      $a2, $f20
/* D503C4 802403D4 4407C000 */  mfc1      $a3, $f24
/* D503C8 802403D8 0C019EC8 */  jal       guRotateF
/* D503CC 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D503D0 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D503D4 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D503D8 802403E8 0C019D80 */  jal       guMtxCatF
/* D503DC 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D503E0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D503E4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D503E8 802403F8 44810000 */  mtc1      $at, $f0
/* D503EC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D503F0 80240400 44050000 */  mfc1      $a1, $f0
/* D503F4 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D503F8 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D503FC 8024040C 0C019DF0 */  jal       guScaleF
/* D50400 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D50404 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D50408 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D5040C 8024041C 0C019D80 */  jal       guMtxCatF
/* D50410 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D50414 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D50418 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D5041C 8024042C 3C014040 */  lui       $at, 0x4040
/* D50420 80240430 44811000 */  mtc1      $at, $f2
/* D50424 80240434 46000007 */  neg.s     $f0, $f0
/* D50428 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D5042C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D50430 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D50434 80240444 44070000 */  mfc1      $a3, $f0
/* D50438 80240448 0C019E40 */  jal       guTranslateF
/* D5043C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D50440 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D50444 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D50448 80240458 0C019D80 */  jal       guMtxCatF
/* D5044C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D50450 80240460 24040002 */  addiu     $a0, $zero, 2
/* D50454 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D50458 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D5045C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D50460 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D50464 80240474 0C0B7710 */  jal       render_sprite
/* D50468 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D5046C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D50470 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D50474 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D50478 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D5047C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D50480 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D50484 80240494 03E00008 */  jr        $ra
/* D50488 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
