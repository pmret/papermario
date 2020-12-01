.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D8D540
/* D8D540 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D8D544 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D8D548 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D8D54C 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D8D550 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D8D554 80240304 4480A000 */  mtc1      $zero, $f20
/* D8D558 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D8D55C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D8D560 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D8D564 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D8D568 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D8D56C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D8D570 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D8D574 80240324 00031080 */  sll       $v0, $v1, 2
/* D8D578 80240328 00431021 */  addu      $v0, $v0, $v1
/* D8D57C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D8D580 80240330 00431023 */  subu      $v0, $v0, $v1
/* D8D584 80240334 000218C0 */  sll       $v1, $v0, 3
/* D8D588 80240338 00431021 */  addu      $v0, $v0, $v1
/* D8D58C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D8D590 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D8D594 80240344 00220821 */  addu      $at, $at, $v0
/* D8D598 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D8D59C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D8D5A0 80240350 4600B587 */  neg.s     $f22, $f22
/* D8D5A4 80240354 4405B000 */  mfc1      $a1, $f22
/* D8D5A8 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D8D5AC 8024035C 0C019EC8 */  jal       guRotateF
/* D8D5B0 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D8D5B4 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8D5B8 80240368 0C00A6C9 */  jal       clamp_angle
/* D8D5BC 8024036C 00000000 */   nop      
/* D8D5C0 80240370 44050000 */  mfc1      $a1, $f0
/* D8D5C4 80240374 4406A000 */  mfc1      $a2, $f20
/* D8D5C8 80240378 4407A000 */  mfc1      $a3, $f20
/* D8D5CC 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D8D5D0 80240380 4481C000 */  mtc1      $at, $f24
/* D8D5D4 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D5D8 80240388 0C019EC8 */  jal       guRotateF
/* D8D5DC 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D8D5E0 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D8D5E4 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D8D5E8 80240398 0C019D80 */  jal       guMtxCatF
/* D8D5EC 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D8D5F0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D8D5F4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D8D5F8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D8D5FC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D8D600 802403B0 0C019EC8 */  jal       guRotateF
/* D8D604 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D8D608 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D60C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D8D610 802403C0 0C019D80 */  jal       guMtxCatF
/* D8D614 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D8D618 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D8D61C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8D620 802403D0 4406A000 */  mfc1      $a2, $f20
/* D8D624 802403D4 4407C000 */  mfc1      $a3, $f24
/* D8D628 802403D8 0C019EC8 */  jal       guRotateF
/* D8D62C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D8D630 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D634 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D8D638 802403E8 0C019D80 */  jal       guMtxCatF
/* D8D63C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D8D640 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D8D644 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8D648 802403F8 44810000 */  mtc1      $at, $f0
/* D8D64C 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D8D650 80240400 44050000 */  mfc1      $a1, $f0
/* D8D654 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D8D658 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D8D65C 8024040C 0C019DF0 */  jal       guScaleF
/* D8D660 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D8D664 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D668 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D8D66C 8024041C 0C019D80 */  jal       guMtxCatF
/* D8D670 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D8D674 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D8D678 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D8D67C 8024042C 3C014040 */  lui       $at, 0x4040
/* D8D680 80240430 44811000 */  mtc1      $at, $f2
/* D8D684 80240434 46000007 */  neg.s     $f0, $f0
/* D8D688 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D8D68C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D8D690 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D8D694 80240444 44070000 */  mfc1      $a3, $f0
/* D8D698 80240448 0C019E40 */  jal       guTranslateF
/* D8D69C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D8D6A0 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D6A4 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D8D6A8 80240458 0C019D80 */  jal       guMtxCatF
/* D8D6AC 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D8D6B0 80240460 24040002 */  addiu     $a0, $zero, 2
/* D8D6B4 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D8D6B8 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D8D6BC 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D8D6C0 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D8D6C4 80240474 0C0B7710 */  jal       render_sprite
/* D8D6C8 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D8D6CC 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D8D6D0 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D8D6D4 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D8D6D8 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D8D6DC 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D8D6E0 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D8D6E4 80240494 03E00008 */  jr        $ra
/* D8D6E8 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
