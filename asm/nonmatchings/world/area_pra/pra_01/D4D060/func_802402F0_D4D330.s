.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D4D330
/* D4D330 802402F0 3C03800A */  lui       $v1, 0x800a
/* D4D334 802402F4 8463A634 */  lh        $v1, -0x59cc($v1)
/* D4D338 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D4D33C 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D4D340 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D4D344 80240304 4480A000 */  mtc1      $zero, $f20
/* D4D348 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D4D34C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D4D350 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D4D354 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D4D358 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D4D35C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D4D360 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D4D364 80240324 00031080 */  sll       $v0, $v1, 2
/* D4D368 80240328 00431021 */  addu      $v0, $v0, $v1
/* D4D36C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D4D370 80240330 00431023 */  subu      $v0, $v0, $v1
/* D4D374 80240334 000218C0 */  sll       $v1, $v0, 3
/* D4D378 80240338 00431021 */  addu      $v0, $v0, $v1
/* D4D37C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D4D380 80240340 3C01800B */  lui       $at, 0x800b
/* D4D384 80240344 00220821 */  addu      $at, $at, $v0
/* D4D388 80240348 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D4D38C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D4D390 80240350 4600B587 */  neg.s     $f22, $f22
/* D4D394 80240354 4405B000 */  mfc1      $a1, $f22
/* D4D398 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D4D39C 8024035C 0C019EC8 */  jal       guRotateF
/* D4D3A0 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D4D3A4 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D4D3A8 80240368 0C00A6C9 */  jal       clamp_angle
/* D4D3AC 8024036C 00000000 */   nop      
/* D4D3B0 80240370 44050000 */  mfc1      $a1, $f0
/* D4D3B4 80240374 4406A000 */  mfc1      $a2, $f20
/* D4D3B8 80240378 4407A000 */  mfc1      $a3, $f20
/* D4D3BC 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D4D3C0 80240380 4481C000 */  mtc1      $at, $f24
/* D4D3C4 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D3C8 80240388 0C019EC8 */  jal       guRotateF
/* D4D3CC 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D4D3D0 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D4D3D4 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D4D3D8 80240398 0C019D80 */  jal       guMtxCatF
/* D4D3DC 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D4D3E0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D4D3E4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D4D3E8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D4D3EC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D4D3F0 802403B0 0C019EC8 */  jal       guRotateF
/* D4D3F4 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D4D3F8 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D3FC 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D4D400 802403C0 0C019D80 */  jal       guMtxCatF
/* D4D404 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D4D408 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D4D40C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D4D410 802403D0 4406A000 */  mfc1      $a2, $f20
/* D4D414 802403D4 4407C000 */  mfc1      $a3, $f24
/* D4D418 802403D8 0C019EC8 */  jal       guRotateF
/* D4D41C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D4D420 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D424 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D4D428 802403E8 0C019D80 */  jal       guMtxCatF
/* D4D42C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D4D430 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D4D434 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D4D438 802403F8 44810000 */  mtc1      $at, $f0
/* D4D43C 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D4D440 80240400 44050000 */  mfc1      $a1, $f0
/* D4D444 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D4D448 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D4D44C 8024040C 0C019DF0 */  jal       guScaleF
/* D4D450 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D4D454 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D458 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D4D45C 8024041C 0C019D80 */  jal       guMtxCatF
/* D4D460 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D4D464 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D4D468 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D4D46C 8024042C 3C014040 */  lui       $at, 0x4040
/* D4D470 80240430 44811000 */  mtc1      $at, $f2
/* D4D474 80240434 46000007 */  neg.s     $f0, $f0
/* D4D478 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D4D47C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D4D480 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D4D484 80240444 44070000 */  mfc1      $a3, $f0
/* D4D488 80240448 0C019E40 */  jal       guTranslateF
/* D4D48C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D4D490 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D494 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D4D498 80240458 0C019D80 */  jal       guMtxCatF
/* D4D49C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D4D4A0 80240460 24040002 */  addiu     $a0, $zero, 2
/* D4D4A4 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D4D4A8 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D4D4AC 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D4D4B0 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D4D4B4 80240474 0C0B7710 */  jal       render_sprite
/* D4D4B8 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D4D4BC 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D4D4C0 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D4D4C4 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D4D4C8 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D4D4CC 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D4D4D0 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D4D4D4 80240494 03E00008 */  jr        $ra
/* D4D4D8 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
