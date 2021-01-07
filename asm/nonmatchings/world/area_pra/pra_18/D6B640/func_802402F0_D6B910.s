.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D6B910
/* D6B910 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D6B914 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D6B918 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D6B91C 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D6B920 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D6B924 80240304 4480A000 */  mtc1      $zero, $f20
/* D6B928 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D6B92C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D6B930 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D6B934 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D6B938 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D6B93C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D6B940 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D6B944 80240324 00031080 */  sll       $v0, $v1, 2
/* D6B948 80240328 00431021 */  addu      $v0, $v0, $v1
/* D6B94C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D6B950 80240330 00431023 */  subu      $v0, $v0, $v1
/* D6B954 80240334 000218C0 */  sll       $v1, $v0, 3
/* D6B958 80240338 00431021 */  addu      $v0, $v0, $v1
/* D6B95C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D6B960 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D6B964 80240344 00220821 */  addu      $at, $at, $v0
/* D6B968 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D6B96C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D6B970 80240350 4600B587 */  neg.s     $f22, $f22
/* D6B974 80240354 4405B000 */  mfc1      $a1, $f22
/* D6B978 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D6B97C 8024035C 0C019EC8 */  jal       guRotateF
/* D6B980 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D6B984 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D6B988 80240368 0C00A6C9 */  jal       clamp_angle
/* D6B98C 8024036C 00000000 */   nop      
/* D6B990 80240370 44050000 */  mfc1      $a1, $f0
/* D6B994 80240374 4406A000 */  mfc1      $a2, $f20
/* D6B998 80240378 4407A000 */  mfc1      $a3, $f20
/* D6B99C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D6B9A0 80240380 4481C000 */  mtc1      $at, $f24
/* D6B9A4 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D6B9A8 80240388 0C019EC8 */  jal       guRotateF
/* D6B9AC 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D6B9B0 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D6B9B4 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D6B9B8 80240398 0C019D80 */  jal       guMtxCatF
/* D6B9BC 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D6B9C0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D6B9C4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D6B9C8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D6B9CC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D6B9D0 802403B0 0C019EC8 */  jal       guRotateF
/* D6B9D4 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D6B9D8 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D6B9DC 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D6B9E0 802403C0 0C019D80 */  jal       guMtxCatF
/* D6B9E4 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D6B9E8 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D6B9EC 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D6B9F0 802403D0 4406A000 */  mfc1      $a2, $f20
/* D6B9F4 802403D4 4407C000 */  mfc1      $a3, $f24
/* D6B9F8 802403D8 0C019EC8 */  jal       guRotateF
/* D6B9FC 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D6BA00 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BA04 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D6BA08 802403E8 0C019D80 */  jal       guMtxCatF
/* D6BA0C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D6BA10 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D6BA14 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6BA18 802403F8 44810000 */  mtc1      $at, $f0
/* D6BA1C 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D6BA20 80240400 44050000 */  mfc1      $a1, $f0
/* D6BA24 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D6BA28 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D6BA2C 8024040C 0C019DF0 */  jal       guScaleF
/* D6BA30 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D6BA34 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BA38 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D6BA3C 8024041C 0C019D80 */  jal       guMtxCatF
/* D6BA40 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D6BA44 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D6BA48 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D6BA4C 8024042C 3C014040 */  lui       $at, 0x4040
/* D6BA50 80240430 44811000 */  mtc1      $at, $f2
/* D6BA54 80240434 46000007 */  neg.s     $f0, $f0
/* D6BA58 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D6BA5C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D6BA60 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D6BA64 80240444 44070000 */  mfc1      $a3, $f0
/* D6BA68 80240448 0C019E40 */  jal       guTranslateF
/* D6BA6C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D6BA70 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BA74 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D6BA78 80240458 0C019D80 */  jal       guMtxCatF
/* D6BA7C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D6BA80 80240460 24040002 */  addiu     $a0, $zero, 2
/* D6BA84 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D6BA88 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D6BA8C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D6BA90 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D6BA94 80240474 0C0B7710 */  jal       render_sprite
/* D6BA98 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D6BA9C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D6BAA0 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D6BAA4 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D6BAA8 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D6BAAC 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D6BAB0 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D6BAB4 80240494 03E00008 */  jr        $ra
/* D6BAB8 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
