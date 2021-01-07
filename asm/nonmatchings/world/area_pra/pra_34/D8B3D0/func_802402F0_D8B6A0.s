.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D8B6A0
/* D8B6A0 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D8B6A4 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D8B6A8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D8B6AC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D8B6B0 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D8B6B4 80240304 4480A000 */  mtc1      $zero, $f20
/* D8B6B8 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D8B6BC 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D8B6C0 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D8B6C4 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D8B6C8 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D8B6CC 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D8B6D0 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D8B6D4 80240324 00031080 */  sll       $v0, $v1, 2
/* D8B6D8 80240328 00431021 */  addu      $v0, $v0, $v1
/* D8B6DC 8024032C 00021080 */  sll       $v0, $v0, 2
/* D8B6E0 80240330 00431023 */  subu      $v0, $v0, $v1
/* D8B6E4 80240334 000218C0 */  sll       $v1, $v0, 3
/* D8B6E8 80240338 00431021 */  addu      $v0, $v0, $v1
/* D8B6EC 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D8B6F0 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D8B6F4 80240344 00220821 */  addu      $at, $at, $v0
/* D8B6F8 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D8B6FC 8024034C 4406A000 */  mfc1      $a2, $f20
/* D8B700 80240350 4600B587 */  neg.s     $f22, $f22
/* D8B704 80240354 4405B000 */  mfc1      $a1, $f22
/* D8B708 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D8B70C 8024035C 0C019EC8 */  jal       guRotateF
/* D8B710 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D8B714 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8B718 80240368 0C00A6C9 */  jal       clamp_angle
/* D8B71C 8024036C 00000000 */   nop      
/* D8B720 80240370 44050000 */  mfc1      $a1, $f0
/* D8B724 80240374 4406A000 */  mfc1      $a2, $f20
/* D8B728 80240378 4407A000 */  mfc1      $a3, $f20
/* D8B72C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D8B730 80240380 4481C000 */  mtc1      $at, $f24
/* D8B734 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D8B738 80240388 0C019EC8 */  jal       guRotateF
/* D8B73C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D8B740 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D8B744 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D8B748 80240398 0C019D80 */  jal       guMtxCatF
/* D8B74C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D8B750 802403A0 4405B000 */  mfc1      $a1, $f22
/* D8B754 802403A4 4406A000 */  mfc1      $a2, $f20
/* D8B758 802403A8 4407C000 */  mfc1      $a3, $f24
/* D8B75C 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D8B760 802403B0 0C019EC8 */  jal       guRotateF
/* D8B764 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D8B768 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D8B76C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D8B770 802403C0 0C019D80 */  jal       guMtxCatF
/* D8B774 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D8B778 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D8B77C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8B780 802403D0 4406A000 */  mfc1      $a2, $f20
/* D8B784 802403D4 4407C000 */  mfc1      $a3, $f24
/* D8B788 802403D8 0C019EC8 */  jal       guRotateF
/* D8B78C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D8B790 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D8B794 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D8B798 802403E8 0C019D80 */  jal       guMtxCatF
/* D8B79C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D8B7A0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D8B7A4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8B7A8 802403F8 44810000 */  mtc1      $at, $f0
/* D8B7AC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D8B7B0 80240400 44050000 */  mfc1      $a1, $f0
/* D8B7B4 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D8B7B8 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D8B7BC 8024040C 0C019DF0 */  jal       guScaleF
/* D8B7C0 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D8B7C4 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D8B7C8 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D8B7CC 8024041C 0C019D80 */  jal       guMtxCatF
/* D8B7D0 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D8B7D4 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D8B7D8 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D8B7DC 8024042C 3C014040 */  lui       $at, 0x4040
/* D8B7E0 80240430 44811000 */  mtc1      $at, $f2
/* D8B7E4 80240434 46000007 */  neg.s     $f0, $f0
/* D8B7E8 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D8B7EC 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D8B7F0 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D8B7F4 80240444 44070000 */  mfc1      $a3, $f0
/* D8B7F8 80240448 0C019E40 */  jal       guTranslateF
/* D8B7FC 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D8B800 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D8B804 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D8B808 80240458 0C019D80 */  jal       guMtxCatF
/* D8B80C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D8B810 80240460 24040002 */  addiu     $a0, $zero, 2
/* D8B814 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D8B818 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D8B81C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D8B820 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D8B824 80240474 0C0B7710 */  jal       render_sprite
/* D8B828 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D8B82C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D8B830 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D8B834 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D8B838 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D8B83C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D8B840 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D8B844 80240494 03E00008 */  jr        $ra
/* D8B848 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
