.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240320_D7B5C0
/* D7B5C0 80240320 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D7B5C4 80240324 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D7B5C8 80240328 3C07BF80 */  lui       $a3, 0xbf80
/* D7B5CC 8024032C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D7B5D0 80240330 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D7B5D4 80240334 4480A000 */  mtc1      $zero, $f20
/* D7B5D8 80240338 AFB1011C */  sw        $s1, 0x11c($sp)
/* D7B5DC 8024033C 0080882D */  daddu     $s1, $a0, $zero
/* D7B5E0 80240340 AFB00118 */  sw        $s0, 0x118($sp)
/* D7B5E4 80240344 27B00098 */  addiu     $s0, $sp, 0x98
/* D7B5E8 80240348 AFBF0120 */  sw        $ra, 0x120($sp)
/* D7B5EC 8024034C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D7B5F0 80240350 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D7B5F4 80240354 00031080 */  sll       $v0, $v1, 2
/* D7B5F8 80240358 00431021 */  addu      $v0, $v0, $v1
/* D7B5FC 8024035C 00021080 */  sll       $v0, $v0, 2
/* D7B600 80240360 00431023 */  subu      $v0, $v0, $v1
/* D7B604 80240364 000218C0 */  sll       $v1, $v0, 3
/* D7B608 80240368 00431021 */  addu      $v0, $v0, $v1
/* D7B60C 8024036C 000210C0 */  sll       $v0, $v0, 3
/* D7B610 80240370 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D7B614 80240374 00220821 */  addu      $at, $at, $v0
/* D7B618 80240378 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D7B61C 8024037C 4406A000 */  mfc1      $a2, $f20
/* D7B620 80240380 4600B587 */  neg.s     $f22, $f22
/* D7B624 80240384 4405B000 */  mfc1      $a1, $f22
/* D7B628 80240388 0200202D */  daddu     $a0, $s0, $zero
/* D7B62C 8024038C 0C019EC8 */  jal       guRotateF
/* D7B630 80240390 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7B634 80240394 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7B638 80240398 0C00A6C9 */  jal       clamp_angle
/* D7B63C 8024039C 00000000 */   nop
/* D7B640 802403A0 44050000 */  mfc1      $a1, $f0
/* D7B644 802403A4 4406A000 */  mfc1      $a2, $f20
/* D7B648 802403A8 4407A000 */  mfc1      $a3, $f20
/* D7B64C 802403AC 3C013F80 */  lui       $at, 0x3f80
/* D7B650 802403B0 4481C000 */  mtc1      $at, $f24
/* D7B654 802403B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D7B658 802403B8 0C019EC8 */  jal       guRotateF
/* D7B65C 802403BC E7B80010 */   swc1     $f24, 0x10($sp)
/* D7B660 802403C0 0200202D */  daddu     $a0, $s0, $zero
/* D7B664 802403C4 27A50018 */  addiu     $a1, $sp, 0x18
/* D7B668 802403C8 0C019D80 */  jal       guMtxCatF
/* D7B66C 802403CC 00A0302D */   daddu    $a2, $a1, $zero
/* D7B670 802403D0 4405B000 */  mfc1      $a1, $f22
/* D7B674 802403D4 4406A000 */  mfc1      $a2, $f20
/* D7B678 802403D8 4407C000 */  mfc1      $a3, $f24
/* D7B67C 802403DC 0200202D */  daddu     $a0, $s0, $zero
/* D7B680 802403E0 0C019EC8 */  jal       guRotateF
/* D7B684 802403E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7B688 802403E8 27A40018 */  addiu     $a0, $sp, 0x18
/* D7B68C 802403EC 0200282D */  daddu     $a1, $s0, $zero
/* D7B690 802403F0 0C019D80 */  jal       guMtxCatF
/* D7B694 802403F4 0080302D */   daddu    $a2, $a0, $zero
/* D7B698 802403F8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D7B69C 802403FC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7B6A0 80240400 4406A000 */  mfc1      $a2, $f20
/* D7B6A4 80240404 4407C000 */  mfc1      $a3, $f24
/* D7B6A8 80240408 0C019EC8 */  jal       guRotateF
/* D7B6AC 8024040C 0200202D */   daddu    $a0, $s0, $zero
/* D7B6B0 80240410 27A40018 */  addiu     $a0, $sp, 0x18
/* D7B6B4 80240414 0200282D */  daddu     $a1, $s0, $zero
/* D7B6B8 80240418 0C019D80 */  jal       guMtxCatF
/* D7B6BC 8024041C 0080302D */   daddu    $a2, $a0, $zero
/* D7B6C0 80240420 3C013F36 */  lui       $at, 0x3f36
/* D7B6C4 80240424 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7B6C8 80240428 44810000 */  mtc1      $at, $f0
/* D7B6CC 8024042C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D7B6D0 80240430 44050000 */  mfc1      $a1, $f0
/* D7B6D4 80240434 0200202D */  daddu     $a0, $s0, $zero
/* D7B6D8 80240438 00A0302D */  daddu     $a2, $a1, $zero
/* D7B6DC 8024043C 0C019DF0 */  jal       guScaleF
/* D7B6E0 80240440 00A0382D */   daddu    $a3, $a1, $zero
/* D7B6E4 80240444 27A40018 */  addiu     $a0, $sp, 0x18
/* D7B6E8 80240448 0200282D */  daddu     $a1, $s0, $zero
/* D7B6EC 8024044C 0C019D80 */  jal       guMtxCatF
/* D7B6F0 80240450 0080302D */   daddu    $a2, $a0, $zero
/* D7B6F4 80240454 27B00058 */  addiu     $s0, $sp, 0x58
/* D7B6F8 80240458 C6200030 */  lwc1      $f0, 0x30($s1)
/* D7B6FC 8024045C 3C014040 */  lui       $at, 0x4040
/* D7B700 80240460 44811000 */  mtc1      $at, $f2
/* D7B704 80240464 46000007 */  neg.s     $f0, $f0
/* D7B708 80240468 46020001 */  sub.s     $f0, $f0, $f2
/* D7B70C 8024046C 8E250028 */  lw        $a1, 0x28($s1)
/* D7B710 80240470 8E26002C */  lw        $a2, 0x2c($s1)
/* D7B714 80240474 44070000 */  mfc1      $a3, $f0
/* D7B718 80240478 0C019E40 */  jal       guTranslateF
/* D7B71C 8024047C 0200202D */   daddu    $a0, $s0, $zero
/* D7B720 80240480 27A40018 */  addiu     $a0, $sp, 0x18
/* D7B724 80240484 0200282D */  daddu     $a1, $s0, $zero
/* D7B728 80240488 0C019D80 */  jal       guMtxCatF
/* D7B72C 8024048C 0080302D */   daddu    $a2, $a0, $zero
/* D7B730 80240490 24040002 */  addiu     $a0, $zero, 2
/* D7B734 80240494 0000282D */  daddu     $a1, $zero, $zero
/* D7B738 80240498 00A0302D */  daddu     $a2, $a1, $zero
/* D7B73C 8024049C 00A0382D */  daddu     $a3, $a1, $zero
/* D7B740 802404A0 27A20018 */  addiu     $v0, $sp, 0x18
/* D7B744 802404A4 0C0B7710 */  jal       render_sprite
/* D7B748 802404A8 AFA20010 */   sw       $v0, 0x10($sp)
/* D7B74C 802404AC 8FBF0120 */  lw        $ra, 0x120($sp)
/* D7B750 802404B0 8FB1011C */  lw        $s1, 0x11c($sp)
/* D7B754 802404B4 8FB00118 */  lw        $s0, 0x118($sp)
/* D7B758 802404B8 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D7B75C 802404BC D7B60130 */  ldc1      $f22, 0x130($sp)
/* D7B760 802404C0 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D7B764 802404C4 03E00008 */  jr        $ra
/* D7B768 802404C8 27BD0140 */   addiu    $sp, $sp, 0x140
