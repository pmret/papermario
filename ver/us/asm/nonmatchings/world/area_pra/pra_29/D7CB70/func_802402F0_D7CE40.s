.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D7CE40
/* D7CE40 802402F0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D7CE44 802402F4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D7CE48 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D7CE4C 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D7CE50 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D7CE54 80240304 4480A000 */  mtc1      $zero, $f20
/* D7CE58 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D7CE5C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D7CE60 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D7CE64 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D7CE68 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D7CE6C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D7CE70 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D7CE74 80240324 00031080 */  sll       $v0, $v1, 2
/* D7CE78 80240328 00431021 */  addu      $v0, $v0, $v1
/* D7CE7C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D7CE80 80240330 00431023 */  subu      $v0, $v0, $v1
/* D7CE84 80240334 000218C0 */  sll       $v1, $v0, 3
/* D7CE88 80240338 00431021 */  addu      $v0, $v0, $v1
/* D7CE8C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D7CE90 80240340 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D7CE94 80240344 00220821 */  addu      $at, $at, $v0
/* D7CE98 80240348 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D7CE9C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D7CEA0 80240350 4600B587 */  neg.s     $f22, $f22
/* D7CEA4 80240354 4405B000 */  mfc1      $a1, $f22
/* D7CEA8 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D7CEAC 8024035C 0C019EC8 */  jal       guRotateF
/* D7CEB0 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7CEB4 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7CEB8 80240368 0C00A6C9 */  jal       clamp_angle
/* D7CEBC 8024036C 00000000 */   nop
/* D7CEC0 80240370 44050000 */  mfc1      $a1, $f0
/* D7CEC4 80240374 4406A000 */  mfc1      $a2, $f20
/* D7CEC8 80240378 4407A000 */  mfc1      $a3, $f20
/* D7CECC 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D7CED0 80240380 4481C000 */  mtc1      $at, $f24
/* D7CED4 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D7CED8 80240388 0C019EC8 */  jal       guRotateF
/* D7CEDC 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D7CEE0 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D7CEE4 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D7CEE8 80240398 0C019D80 */  jal       guMtxCatF
/* D7CEEC 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D7CEF0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D7CEF4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D7CEF8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D7CEFC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D7CF00 802403B0 0C019EC8 */  jal       guRotateF
/* D7CF04 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7CF08 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D7CF0C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D7CF10 802403C0 0C019D80 */  jal       guMtxCatF
/* D7CF14 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D7CF18 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D7CF1C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7CF20 802403D0 4406A000 */  mfc1      $a2, $f20
/* D7CF24 802403D4 4407C000 */  mfc1      $a3, $f24
/* D7CF28 802403D8 0C019EC8 */  jal       guRotateF
/* D7CF2C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D7CF30 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D7CF34 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D7CF38 802403E8 0C019D80 */  jal       guMtxCatF
/* D7CF3C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D7CF40 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D7CF44 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7CF48 802403F8 44810000 */  mtc1      $at, $f0
/* D7CF4C 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D7CF50 80240400 44050000 */  mfc1      $a1, $f0
/* D7CF54 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D7CF58 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D7CF5C 8024040C 0C019DF0 */  jal       guScaleF
/* D7CF60 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D7CF64 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D7CF68 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D7CF6C 8024041C 0C019D80 */  jal       guMtxCatF
/* D7CF70 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D7CF74 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D7CF78 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D7CF7C 8024042C 3C014040 */  lui       $at, 0x4040
/* D7CF80 80240430 44811000 */  mtc1      $at, $f2
/* D7CF84 80240434 46000007 */  neg.s     $f0, $f0
/* D7CF88 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D7CF8C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D7CF90 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D7CF94 80240444 44070000 */  mfc1      $a3, $f0
/* D7CF98 80240448 0C019E40 */  jal       guTranslateF
/* D7CF9C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D7CFA0 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D7CFA4 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D7CFA8 80240458 0C019D80 */  jal       guMtxCatF
/* D7CFAC 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D7CFB0 80240460 24040002 */  addiu     $a0, $zero, 2
/* D7CFB4 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D7CFB8 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D7CFBC 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D7CFC0 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D7CFC4 80240474 0C0B7710 */  jal       render_sprite
/* D7CFC8 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D7CFCC 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D7CFD0 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D7CFD4 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D7CFD8 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D7CFDC 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D7CFE0 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D7CFE4 80240494 03E00008 */  jr        $ra
/* D7CFE8 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
