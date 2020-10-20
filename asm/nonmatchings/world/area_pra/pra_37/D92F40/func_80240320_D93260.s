.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240320_D93260
/* D93260 80240320 3C03800A */  lui       $v1, 0x800a
/* D93264 80240324 8463A634 */  lh        $v1, -0x59cc($v1)
/* D93268 80240328 3C07BF80 */  lui       $a3, 0xbf80
/* D9326C 8024032C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D93270 80240330 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D93274 80240334 4480A000 */  mtc1      $zero, $f20
/* D93278 80240338 AFB1011C */  sw        $s1, 0x11c($sp)
/* D9327C 8024033C 0080882D */  daddu     $s1, $a0, $zero
/* D93280 80240340 AFB00118 */  sw        $s0, 0x118($sp)
/* D93284 80240344 27B00098 */  addiu     $s0, $sp, 0x98
/* D93288 80240348 AFBF0120 */  sw        $ra, 0x120($sp)
/* D9328C 8024034C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D93290 80240350 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D93294 80240354 00031080 */  sll       $v0, $v1, 2
/* D93298 80240358 00431021 */  addu      $v0, $v0, $v1
/* D9329C 8024035C 00021080 */  sll       $v0, $v0, 2
/* D932A0 80240360 00431023 */  subu      $v0, $v0, $v1
/* D932A4 80240364 000218C0 */  sll       $v1, $v0, 3
/* D932A8 80240368 00431021 */  addu      $v0, $v0, $v1
/* D932AC 8024036C 000210C0 */  sll       $v0, $v0, 3
/* D932B0 80240370 3C01800B */  lui       $at, 0x800b
/* D932B4 80240374 00220821 */  addu      $at, $at, $v0
/* D932B8 80240378 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D932BC 8024037C 4406A000 */  mfc1      $a2, $f20
/* D932C0 80240380 4600B587 */  neg.s     $f22, $f22
/* D932C4 80240384 4405B000 */  mfc1      $a1, $f22
/* D932C8 80240388 0200202D */  daddu     $a0, $s0, $zero
/* D932CC 8024038C 0C019EC8 */  jal       guRotateF
/* D932D0 80240390 E7B40010 */   swc1     $f20, 0x10($sp)
/* D932D4 80240394 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D932D8 80240398 0C00A6C9 */  jal       clamp_angle
/* D932DC 8024039C 00000000 */   nop      
/* D932E0 802403A0 44050000 */  mfc1      $a1, $f0
/* D932E4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D932E8 802403A8 4407A000 */  mfc1      $a3, $f20
/* D932EC 802403AC 3C013F80 */  lui       $at, 0x3f80
/* D932F0 802403B0 4481C000 */  mtc1      $at, $f24
/* D932F4 802403B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D932F8 802403B8 0C019EC8 */  jal       guRotateF
/* D932FC 802403BC E7B80010 */   swc1     $f24, 0x10($sp)
/* D93300 802403C0 0200202D */  daddu     $a0, $s0, $zero
/* D93304 802403C4 27A50018 */  addiu     $a1, $sp, 0x18
/* D93308 802403C8 0C019D80 */  jal       guMtxCatF
/* D9330C 802403CC 00A0302D */   daddu    $a2, $a1, $zero
/* D93310 802403D0 4405B000 */  mfc1      $a1, $f22
/* D93314 802403D4 4406A000 */  mfc1      $a2, $f20
/* D93318 802403D8 4407C000 */  mfc1      $a3, $f24
/* D9331C 802403DC 0200202D */  daddu     $a0, $s0, $zero
/* D93320 802403E0 0C019EC8 */  jal       guRotateF
/* D93324 802403E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D93328 802403E8 27A40018 */  addiu     $a0, $sp, 0x18
/* D9332C 802403EC 0200282D */  daddu     $a1, $s0, $zero
/* D93330 802403F0 0C019D80 */  jal       guMtxCatF
/* D93334 802403F4 0080302D */   daddu    $a2, $a0, $zero
/* D93338 802403F8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D9333C 802403FC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D93340 80240400 4406A000 */  mfc1      $a2, $f20
/* D93344 80240404 4407C000 */  mfc1      $a3, $f24
/* D93348 80240408 0C019EC8 */  jal       guRotateF
/* D9334C 8024040C 0200202D */   daddu    $a0, $s0, $zero
/* D93350 80240410 27A40018 */  addiu     $a0, $sp, 0x18
/* D93354 80240414 0200282D */  daddu     $a1, $s0, $zero
/* D93358 80240418 0C019D80 */  jal       guMtxCatF
/* D9335C 8024041C 0080302D */   daddu    $a2, $a0, $zero
/* D93360 80240420 3C013F36 */  lui       $at, 0x3f36
/* D93364 80240424 3421DB6E */  ori       $at, $at, 0xdb6e
/* D93368 80240428 44810000 */  mtc1      $at, $f0
/* D9336C 8024042C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D93370 80240430 44050000 */  mfc1      $a1, $f0
/* D93374 80240434 0200202D */  daddu     $a0, $s0, $zero
/* D93378 80240438 00A0302D */  daddu     $a2, $a1, $zero
/* D9337C 8024043C 0C019DF0 */  jal       guScaleF
/* D93380 80240440 00A0382D */   daddu    $a3, $a1, $zero
/* D93384 80240444 27A40018 */  addiu     $a0, $sp, 0x18
/* D93388 80240448 0200282D */  daddu     $a1, $s0, $zero
/* D9338C 8024044C 0C019D80 */  jal       guMtxCatF
/* D93390 80240450 0080302D */   daddu    $a2, $a0, $zero
/* D93394 80240454 27B00058 */  addiu     $s0, $sp, 0x58
/* D93398 80240458 C6200030 */  lwc1      $f0, 0x30($s1)
/* D9339C 8024045C 3C014040 */  lui       $at, 0x4040
/* D933A0 80240460 44811000 */  mtc1      $at, $f2
/* D933A4 80240464 46000007 */  neg.s     $f0, $f0
/* D933A8 80240468 46020001 */  sub.s     $f0, $f0, $f2
/* D933AC 8024046C 8E250028 */  lw        $a1, 0x28($s1)
/* D933B0 80240470 8E26002C */  lw        $a2, 0x2c($s1)
/* D933B4 80240474 44070000 */  mfc1      $a3, $f0
/* D933B8 80240478 0C019E40 */  jal       guTranslateF
/* D933BC 8024047C 0200202D */   daddu    $a0, $s0, $zero
/* D933C0 80240480 27A40018 */  addiu     $a0, $sp, 0x18
/* D933C4 80240484 0200282D */  daddu     $a1, $s0, $zero
/* D933C8 80240488 0C019D80 */  jal       guMtxCatF
/* D933CC 8024048C 0080302D */   daddu    $a2, $a0, $zero
/* D933D0 80240490 24040002 */  addiu     $a0, $zero, 2
/* D933D4 80240494 0000282D */  daddu     $a1, $zero, $zero
/* D933D8 80240498 00A0302D */  daddu     $a2, $a1, $zero
/* D933DC 8024049C 00A0382D */  daddu     $a3, $a1, $zero
/* D933E0 802404A0 27A20018 */  addiu     $v0, $sp, 0x18
/* D933E4 802404A4 0C0B7710 */  jal       render_sprite
/* D933E8 802404A8 AFA20010 */   sw       $v0, 0x10($sp)
/* D933EC 802404AC 8FBF0120 */  lw        $ra, 0x120($sp)
/* D933F0 802404B0 8FB1011C */  lw        $s1, 0x11c($sp)
/* D933F4 802404B4 8FB00118 */  lw        $s0, 0x118($sp)
/* D933F8 802404B8 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D933FC 802404BC D7B60130 */  ldc1      $f22, 0x130($sp)
/* D93400 802404C0 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D93404 802404C4 03E00008 */  jr        $ra
/* D93408 802404C8 27BD0140 */   addiu    $sp, $sp, 0x140
