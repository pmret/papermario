.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D69E10
/* D69E10 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D69E14 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D69E18 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D69E1C 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D69E20 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D69E24 80240304 4480A000 */  mtc1      $zero, $f20
/* D69E28 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D69E2C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D69E30 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D69E34 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D69E38 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D69E3C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D69E40 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D69E44 80240324 00031080 */  sll       $v0, $v1, 2
/* D69E48 80240328 00431021 */  addu      $v0, $v0, $v1
/* D69E4C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D69E50 80240330 00431023 */  subu      $v0, $v0, $v1
/* D69E54 80240334 000218C0 */  sll       $v1, $v0, 3
/* D69E58 80240338 00431021 */  addu      $v0, $v0, $v1
/* D69E5C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D69E60 80240340 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D69E64 80240344 00220821 */  addu      $at, $at, $v0
/* D69E68 80240348 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D69E6C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D69E70 80240350 4600B587 */  neg.s     $f22, $f22
/* D69E74 80240354 4405B000 */  mfc1      $a1, $f22
/* D69E78 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D69E7C 8024035C 0C019EC8 */  jal       guRotateF
/* D69E80 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D69E84 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D69E88 80240368 0C00A6C9 */  jal       clamp_angle
/* D69E8C 8024036C 00000000 */   nop
/* D69E90 80240370 44050000 */  mfc1      $a1, $f0
/* D69E94 80240374 4406A000 */  mfc1      $a2, $f20
/* D69E98 80240378 4407A000 */  mfc1      $a3, $f20
/* D69E9C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D69EA0 80240380 4481C000 */  mtc1      $at, $f24
/* D69EA4 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D69EA8 80240388 0C019EC8 */  jal       guRotateF
/* D69EAC 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D69EB0 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D69EB4 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D69EB8 80240398 0C019D80 */  jal       guMtxCatF
/* D69EBC 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D69EC0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D69EC4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D69EC8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D69ECC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D69ED0 802403B0 0C019EC8 */  jal       guRotateF
/* D69ED4 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D69ED8 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D69EDC 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D69EE0 802403C0 0C019D80 */  jal       guMtxCatF
/* D69EE4 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D69EE8 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D69EEC 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D69EF0 802403D0 4406A000 */  mfc1      $a2, $f20
/* D69EF4 802403D4 4407C000 */  mfc1      $a3, $f24
/* D69EF8 802403D8 0C019EC8 */  jal       guRotateF
/* D69EFC 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D69F00 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D69F04 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D69F08 802403E8 0C019D80 */  jal       guMtxCatF
/* D69F0C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D69F10 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D69F14 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D69F18 802403F8 44810000 */  mtc1      $at, $f0
/* D69F1C 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D69F20 80240400 44050000 */  mfc1      $a1, $f0
/* D69F24 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D69F28 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D69F2C 8024040C 0C019DF0 */  jal       guScaleF
/* D69F30 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D69F34 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D69F38 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D69F3C 8024041C 0C019D80 */  jal       guMtxCatF
/* D69F40 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D69F44 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D69F48 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D69F4C 8024042C 3C014040 */  lui       $at, 0x4040
/* D69F50 80240430 44811000 */  mtc1      $at, $f2
/* D69F54 80240434 46000007 */  neg.s     $f0, $f0
/* D69F58 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D69F5C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D69F60 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D69F64 80240444 44070000 */  mfc1      $a3, $f0
/* D69F68 80240448 0C019E40 */  jal       guTranslateF
/* D69F6C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D69F70 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D69F74 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D69F78 80240458 0C019D80 */  jal       guMtxCatF
/* D69F7C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D69F80 80240460 24040002 */  addiu     $a0, $zero, 2
/* D69F84 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D69F88 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D69F8C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D69F90 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D69F94 80240474 0C0B7710 */  jal       render_sprite
/* D69F98 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D69F9C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D69FA0 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D69FA4 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D69FA8 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D69FAC 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D69FB0 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D69FB4 80240494 03E00008 */  jr        $ra
/* D69FB8 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
