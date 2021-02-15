.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D99CA0
/* D99CA0 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D99CA4 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D99CA8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D99CAC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D99CB0 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D99CB4 80240304 4480A000 */  mtc1      $zero, $f20
/* D99CB8 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D99CBC 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D99CC0 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D99CC4 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D99CC8 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D99CCC 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D99CD0 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D99CD4 80240324 00031080 */  sll       $v0, $v1, 2
/* D99CD8 80240328 00431021 */  addu      $v0, $v0, $v1
/* D99CDC 8024032C 00021080 */  sll       $v0, $v0, 2
/* D99CE0 80240330 00431023 */  subu      $v0, $v0, $v1
/* D99CE4 80240334 000218C0 */  sll       $v1, $v0, 3
/* D99CE8 80240338 00431021 */  addu      $v0, $v0, $v1
/* D99CEC 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D99CF0 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D99CF4 80240344 00220821 */  addu      $at, $at, $v0
/* D99CF8 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D99CFC 8024034C 4406A000 */  mfc1      $a2, $f20
/* D99D00 80240350 4600B587 */  neg.s     $f22, $f22
/* D99D04 80240354 4405B000 */  mfc1      $a1, $f22
/* D99D08 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D99D0C 8024035C 0C019EC8 */  jal       guRotateF
/* D99D10 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D99D14 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D99D18 80240368 0C00A6C9 */  jal       clamp_angle
/* D99D1C 8024036C 00000000 */   nop
/* D99D20 80240370 44050000 */  mfc1      $a1, $f0
/* D99D24 80240374 4406A000 */  mfc1      $a2, $f20
/* D99D28 80240378 4407A000 */  mfc1      $a3, $f20
/* D99D2C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D99D30 80240380 4481C000 */  mtc1      $at, $f24
/* D99D34 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D99D38 80240388 0C019EC8 */  jal       guRotateF
/* D99D3C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D99D40 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D99D44 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D99D48 80240398 0C019D80 */  jal       guMtxCatF
/* D99D4C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D99D50 802403A0 4405B000 */  mfc1      $a1, $f22
/* D99D54 802403A4 4406A000 */  mfc1      $a2, $f20
/* D99D58 802403A8 4407C000 */  mfc1      $a3, $f24
/* D99D5C 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D99D60 802403B0 0C019EC8 */  jal       guRotateF
/* D99D64 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D99D68 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D99D6C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D99D70 802403C0 0C019D80 */  jal       guMtxCatF
/* D99D74 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D99D78 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D99D7C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D99D80 802403D0 4406A000 */  mfc1      $a2, $f20
/* D99D84 802403D4 4407C000 */  mfc1      $a3, $f24
/* D99D88 802403D8 0C019EC8 */  jal       guRotateF
/* D99D8C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D99D90 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D99D94 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D99D98 802403E8 0C019D80 */  jal       guMtxCatF
/* D99D9C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D99DA0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D99DA4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D99DA8 802403F8 44810000 */  mtc1      $at, $f0
/* D99DAC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D99DB0 80240400 44050000 */  mfc1      $a1, $f0
/* D99DB4 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D99DB8 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D99DBC 8024040C 0C019DF0 */  jal       guScaleF
/* D99DC0 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D99DC4 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D99DC8 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D99DCC 8024041C 0C019D80 */  jal       guMtxCatF
/* D99DD0 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D99DD4 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D99DD8 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D99DDC 8024042C 3C014040 */  lui       $at, 0x4040
/* D99DE0 80240430 44811000 */  mtc1      $at, $f2
/* D99DE4 80240434 46000007 */  neg.s     $f0, $f0
/* D99DE8 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D99DEC 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D99DF0 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D99DF4 80240444 44070000 */  mfc1      $a3, $f0
/* D99DF8 80240448 0C019E40 */  jal       guTranslateF
/* D99DFC 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D99E00 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D99E04 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D99E08 80240458 0C019D80 */  jal       guMtxCatF
/* D99E0C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D99E10 80240460 24040002 */  addiu     $a0, $zero, 2
/* D99E14 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D99E18 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D99E1C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D99E20 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D99E24 80240474 0C0B7710 */  jal       render_sprite
/* D99E28 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D99E2C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D99E30 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D99E34 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D99E38 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D99E3C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D99E40 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D99E44 80240494 03E00008 */  jr        $ra
/* D99E48 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
