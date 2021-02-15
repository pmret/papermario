.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_B1B8D0
/* B1B8D0 80240360 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B1B8D4 80240364 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B1B8D8 80240368 3C07BF80 */  lui       $a3, 0xbf80
/* B1B8DC 8024036C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* B1B8E0 80240370 F7B40128 */  sdc1      $f20, 0x128($sp)
/* B1B8E4 80240374 4480A000 */  mtc1      $zero, $f20
/* B1B8E8 80240378 AFB1011C */  sw        $s1, 0x11c($sp)
/* B1B8EC 8024037C 0080882D */  daddu     $s1, $a0, $zero
/* B1B8F0 80240380 AFB00118 */  sw        $s0, 0x118($sp)
/* B1B8F4 80240384 27B00098 */  addiu     $s0, $sp, 0x98
/* B1B8F8 80240388 AFBF0120 */  sw        $ra, 0x120($sp)
/* B1B8FC 8024038C F7B80138 */  sdc1      $f24, 0x138($sp)
/* B1B900 80240390 F7B60130 */  sdc1      $f22, 0x130($sp)
/* B1B904 80240394 00031080 */  sll       $v0, $v1, 2
/* B1B908 80240398 00431021 */  addu      $v0, $v0, $v1
/* B1B90C 8024039C 00021080 */  sll       $v0, $v0, 2
/* B1B910 802403A0 00431023 */  subu      $v0, $v0, $v1
/* B1B914 802403A4 000218C0 */  sll       $v1, $v0, 3
/* B1B918 802403A8 00431021 */  addu      $v0, $v0, $v1
/* B1B91C 802403AC 000210C0 */  sll       $v0, $v0, 3
/* B1B920 802403B0 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* B1B924 802403B4 00220821 */  addu      $at, $at, $v0
/* B1B928 802403B8 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* B1B92C 802403BC 4406A000 */  mfc1      $a2, $f20
/* B1B930 802403C0 4600B587 */  neg.s     $f22, $f22
/* B1B934 802403C4 4405B000 */  mfc1      $a1, $f22
/* B1B938 802403C8 0200202D */  daddu     $a0, $s0, $zero
/* B1B93C 802403CC 0C019EC8 */  jal       guRotateF
/* B1B940 802403D0 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1B944 802403D4 C62C008C */  lwc1      $f12, 0x8c($s1)
/* B1B948 802403D8 0C00A6C9 */  jal       clamp_angle
/* B1B94C 802403DC 00000000 */   nop
/* B1B950 802403E0 44050000 */  mfc1      $a1, $f0
/* B1B954 802403E4 4406A000 */  mfc1      $a2, $f20
/* B1B958 802403E8 4407A000 */  mfc1      $a3, $f20
/* B1B95C 802403EC 3C013F80 */  lui       $at, 0x3f80
/* B1B960 802403F0 4481C000 */  mtc1      $at, $f24
/* B1B964 802403F4 27A40018 */  addiu     $a0, $sp, 0x18
/* B1B968 802403F8 0C019EC8 */  jal       guRotateF
/* B1B96C 802403FC E7B80010 */   swc1     $f24, 0x10($sp)
/* B1B970 80240400 0200202D */  daddu     $a0, $s0, $zero
/* B1B974 80240404 27A50018 */  addiu     $a1, $sp, 0x18
/* B1B978 80240408 0C019D80 */  jal       guMtxCatF
/* B1B97C 8024040C 00A0302D */   daddu    $a2, $a1, $zero
/* B1B980 80240410 4405B000 */  mfc1      $a1, $f22
/* B1B984 80240414 4406A000 */  mfc1      $a2, $f20
/* B1B988 80240418 4407C000 */  mfc1      $a3, $f24
/* B1B98C 8024041C 0200202D */  daddu     $a0, $s0, $zero
/* B1B990 80240420 0C019EC8 */  jal       guRotateF
/* B1B994 80240424 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1B998 80240428 27A40018 */  addiu     $a0, $sp, 0x18
/* B1B99C 8024042C 0200282D */  daddu     $a1, $s0, $zero
/* B1B9A0 80240430 0C019D80 */  jal       guMtxCatF
/* B1B9A4 80240434 0080302D */   daddu    $a2, $a0, $zero
/* B1B9A8 80240438 E7B40010 */  swc1      $f20, 0x10($sp)
/* B1B9AC 8024043C 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B1B9B0 80240440 4406A000 */  mfc1      $a2, $f20
/* B1B9B4 80240444 4407C000 */  mfc1      $a3, $f24
/* B1B9B8 80240448 0C019EC8 */  jal       guRotateF
/* B1B9BC 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* B1B9C0 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* B1B9C4 80240454 0200282D */  daddu     $a1, $s0, $zero
/* B1B9C8 80240458 0C019D80 */  jal       guMtxCatF
/* B1B9CC 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* B1B9D0 80240460 3C013F36 */  lui       $at, 0x3f36
/* B1B9D4 80240464 3421DB6E */  ori       $at, $at, 0xdb6e
/* B1B9D8 80240468 44810000 */  mtc1      $at, $f0
/* B1B9DC 8024046C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* B1B9E0 80240470 44050000 */  mfc1      $a1, $f0
/* B1B9E4 80240474 0200202D */  daddu     $a0, $s0, $zero
/* B1B9E8 80240478 00A0302D */  daddu     $a2, $a1, $zero
/* B1B9EC 8024047C 0C019DF0 */  jal       guScaleF
/* B1B9F0 80240480 00A0382D */   daddu    $a3, $a1, $zero
/* B1B9F4 80240484 27A40018 */  addiu     $a0, $sp, 0x18
/* B1B9F8 80240488 0200282D */  daddu     $a1, $s0, $zero
/* B1B9FC 8024048C 0C019D80 */  jal       guMtxCatF
/* B1BA00 80240490 0080302D */   daddu    $a2, $a0, $zero
/* B1BA04 80240494 27B00058 */  addiu     $s0, $sp, 0x58
/* B1BA08 80240498 8E250028 */  lw        $a1, 0x28($s1)
/* B1BA0C 8024049C C6200030 */  lwc1      $f0, 0x30($s1)
/* B1BA10 802404A0 8E26002C */  lw        $a2, 0x2c($s1)
/* B1BA14 802404A4 46000007 */  neg.s     $f0, $f0
/* B1BA18 802404A8 44070000 */  mfc1      $a3, $f0
/* B1BA1C 802404AC 0C019E40 */  jal       guTranslateF
/* B1BA20 802404B0 0200202D */   daddu    $a0, $s0, $zero
/* B1BA24 802404B4 27A40018 */  addiu     $a0, $sp, 0x18
/* B1BA28 802404B8 0200282D */  daddu     $a1, $s0, $zero
/* B1BA2C 802404BC 0C019D80 */  jal       guMtxCatF
/* B1BA30 802404C0 0080302D */   daddu    $a2, $a0, $zero
/* B1BA34 802404C4 8E2500A4 */  lw        $a1, 0xa4($s1)
/* B1BA38 802404C8 4406C000 */  mfc1      $a2, $f24
/* B1BA3C 802404CC 0C0B76A3 */  jal       func_802DDA8C
/* B1BA40 802404D0 24040001 */   addiu    $a0, $zero, 1
/* B1BA44 802404D4 24040001 */  addiu     $a0, $zero, 1
/* B1BA48 802404D8 0000282D */  daddu     $a1, $zero, $zero
/* B1BA4C 802404DC 00A0302D */  daddu     $a2, $a1, $zero
/* B1BA50 802404E0 00A0382D */  daddu     $a3, $a1, $zero
/* B1BA54 802404E4 27A20018 */  addiu     $v0, $sp, 0x18
/* B1BA58 802404E8 0C0B7710 */  jal       render_sprite
/* B1BA5C 802404EC AFA20010 */   sw       $v0, 0x10($sp)
/* B1BA60 802404F0 8FBF0120 */  lw        $ra, 0x120($sp)
/* B1BA64 802404F4 8FB1011C */  lw        $s1, 0x11c($sp)
/* B1BA68 802404F8 8FB00118 */  lw        $s0, 0x118($sp)
/* B1BA6C 802404FC D7B80138 */  ldc1      $f24, 0x138($sp)
/* B1BA70 80240500 D7B60130 */  ldc1      $f22, 0x130($sp)
/* B1BA74 80240504 D7B40128 */  ldc1      $f20, 0x128($sp)
/* B1BA78 80240508 03E00008 */  jr        $ra
/* B1BA7C 8024050C 27BD0140 */   addiu    $sp, $sp, 0x140
