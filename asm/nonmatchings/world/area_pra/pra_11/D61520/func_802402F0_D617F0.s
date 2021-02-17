.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D617F0
/* D617F0 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D617F4 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D617F8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D617FC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D61800 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D61804 80240304 4480A000 */  mtc1      $zero, $f20
/* D61808 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D6180C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D61810 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D61814 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D61818 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D6181C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D61820 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D61824 80240324 00031080 */  sll       $v0, $v1, 2
/* D61828 80240328 00431021 */  addu      $v0, $v0, $v1
/* D6182C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D61830 80240330 00431023 */  subu      $v0, $v0, $v1
/* D61834 80240334 000218C0 */  sll       $v1, $v0, 3
/* D61838 80240338 00431021 */  addu      $v0, $v0, $v1
/* D6183C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D61840 80240340 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D61844 80240344 00220821 */  addu      $at, $at, $v0
/* D61848 80240348 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D6184C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D61850 80240350 4600B587 */  neg.s     $f22, $f22
/* D61854 80240354 4405B000 */  mfc1      $a1, $f22
/* D61858 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D6185C 8024035C 0C019EC8 */  jal       guRotateF
/* D61860 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D61864 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D61868 80240368 0C00A6C9 */  jal       clamp_angle
/* D6186C 8024036C 00000000 */   nop
/* D61870 80240370 44050000 */  mfc1      $a1, $f0
/* D61874 80240374 4406A000 */  mfc1      $a2, $f20
/* D61878 80240378 4407A000 */  mfc1      $a3, $f20
/* D6187C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D61880 80240380 4481C000 */  mtc1      $at, $f24
/* D61884 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D61888 80240388 0C019EC8 */  jal       guRotateF
/* D6188C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D61890 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D61894 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D61898 80240398 0C019D80 */  jal       guMtxCatF
/* D6189C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D618A0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D618A4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D618A8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D618AC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D618B0 802403B0 0C019EC8 */  jal       guRotateF
/* D618B4 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D618B8 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D618BC 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D618C0 802403C0 0C019D80 */  jal       guMtxCatF
/* D618C4 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D618C8 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D618CC 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D618D0 802403D0 4406A000 */  mfc1      $a2, $f20
/* D618D4 802403D4 4407C000 */  mfc1      $a3, $f24
/* D618D8 802403D8 0C019EC8 */  jal       guRotateF
/* D618DC 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D618E0 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D618E4 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D618E8 802403E8 0C019D80 */  jal       guMtxCatF
/* D618EC 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D618F0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D618F4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D618F8 802403F8 44810000 */  mtc1      $at, $f0
/* D618FC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D61900 80240400 44050000 */  mfc1      $a1, $f0
/* D61904 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D61908 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D6190C 8024040C 0C019DF0 */  jal       guScaleF
/* D61910 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D61914 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D61918 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D6191C 8024041C 0C019D80 */  jal       guMtxCatF
/* D61920 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D61924 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D61928 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D6192C 8024042C 3C014040 */  lui       $at, 0x4040
/* D61930 80240430 44811000 */  mtc1      $at, $f2
/* D61934 80240434 46000007 */  neg.s     $f0, $f0
/* D61938 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D6193C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D61940 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D61944 80240444 44070000 */  mfc1      $a3, $f0
/* D61948 80240448 0C019E40 */  jal       guTranslateF
/* D6194C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D61950 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D61954 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D61958 80240458 0C019D80 */  jal       guMtxCatF
/* D6195C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D61960 80240460 24040002 */  addiu     $a0, $zero, 2
/* D61964 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D61968 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D6196C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D61970 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D61974 80240474 0C0B7710 */  jal       render_sprite
/* D61978 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D6197C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D61980 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D61984 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D61988 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D6198C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D61990 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D61994 80240494 03E00008 */  jr        $ra
/* D61998 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
