.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D55EA0
/* D55EA0 802402F0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D55EA4 802402F4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D55EA8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D55EAC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D55EB0 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D55EB4 80240304 4480A000 */  mtc1      $zero, $f20
/* D55EB8 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D55EBC 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D55EC0 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D55EC4 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D55EC8 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D55ECC 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D55ED0 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D55ED4 80240324 00031080 */  sll       $v0, $v1, 2
/* D55ED8 80240328 00431021 */  addu      $v0, $v0, $v1
/* D55EDC 8024032C 00021080 */  sll       $v0, $v0, 2
/* D55EE0 80240330 00431023 */  subu      $v0, $v0, $v1
/* D55EE4 80240334 000218C0 */  sll       $v1, $v0, 3
/* D55EE8 80240338 00431021 */  addu      $v0, $v0, $v1
/* D55EEC 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D55EF0 80240340 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D55EF4 80240344 00220821 */  addu      $at, $at, $v0
/* D55EF8 80240348 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D55EFC 8024034C 4406A000 */  mfc1      $a2, $f20
/* D55F00 80240350 4600B587 */  neg.s     $f22, $f22
/* D55F04 80240354 4405B000 */  mfc1      $a1, $f22
/* D55F08 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D55F0C 8024035C 0C019EC8 */  jal       guRotateF
/* D55F10 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D55F14 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D55F18 80240368 0C00A6C9 */  jal       clamp_angle
/* D55F1C 8024036C 00000000 */   nop
/* D55F20 80240370 44050000 */  mfc1      $a1, $f0
/* D55F24 80240374 4406A000 */  mfc1      $a2, $f20
/* D55F28 80240378 4407A000 */  mfc1      $a3, $f20
/* D55F2C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D55F30 80240380 4481C000 */  mtc1      $at, $f24
/* D55F34 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D55F38 80240388 0C019EC8 */  jal       guRotateF
/* D55F3C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D55F40 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D55F44 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D55F48 80240398 0C019D80 */  jal       guMtxCatF
/* D55F4C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D55F50 802403A0 4405B000 */  mfc1      $a1, $f22
/* D55F54 802403A4 4406A000 */  mfc1      $a2, $f20
/* D55F58 802403A8 4407C000 */  mfc1      $a3, $f24
/* D55F5C 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D55F60 802403B0 0C019EC8 */  jal       guRotateF
/* D55F64 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D55F68 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D55F6C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D55F70 802403C0 0C019D80 */  jal       guMtxCatF
/* D55F74 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D55F78 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D55F7C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D55F80 802403D0 4406A000 */  mfc1      $a2, $f20
/* D55F84 802403D4 4407C000 */  mfc1      $a3, $f24
/* D55F88 802403D8 0C019EC8 */  jal       guRotateF
/* D55F8C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D55F90 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D55F94 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D55F98 802403E8 0C019D80 */  jal       guMtxCatF
/* D55F9C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D55FA0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D55FA4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D55FA8 802403F8 44810000 */  mtc1      $at, $f0
/* D55FAC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D55FB0 80240400 44050000 */  mfc1      $a1, $f0
/* D55FB4 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D55FB8 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D55FBC 8024040C 0C019DF0 */  jal       guScaleF
/* D55FC0 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D55FC4 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D55FC8 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D55FCC 8024041C 0C019D80 */  jal       guMtxCatF
/* D55FD0 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D55FD4 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D55FD8 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D55FDC 8024042C 3C014040 */  lui       $at, 0x4040
/* D55FE0 80240430 44811000 */  mtc1      $at, $f2
/* D55FE4 80240434 46000007 */  neg.s     $f0, $f0
/* D55FE8 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D55FEC 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D55FF0 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D55FF4 80240444 44070000 */  mfc1      $a3, $f0
/* D55FF8 80240448 0C019E40 */  jal       guTranslateF
/* D55FFC 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D56000 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D56004 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D56008 80240458 0C019D80 */  jal       guMtxCatF
/* D5600C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D56010 80240460 24040002 */  addiu     $a0, $zero, 2
/* D56014 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D56018 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D5601C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D56020 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D56024 80240474 0C0B7710 */  jal       render_sprite
/* D56028 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D5602C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D56030 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D56034 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D56038 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D5603C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D56040 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D56044 80240494 03E00008 */  jr        $ra
/* D56048 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
