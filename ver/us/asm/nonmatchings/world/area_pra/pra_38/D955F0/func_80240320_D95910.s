.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240320_D95910
/* D95910 80240320 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D95914 80240324 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D95918 80240328 3C07BF80 */  lui       $a3, 0xbf80
/* D9591C 8024032C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D95920 80240330 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D95924 80240334 4480A000 */  mtc1      $zero, $f20
/* D95928 80240338 AFB1011C */  sw        $s1, 0x11c($sp)
/* D9592C 8024033C 0080882D */  daddu     $s1, $a0, $zero
/* D95930 80240340 AFB00118 */  sw        $s0, 0x118($sp)
/* D95934 80240344 27B00098 */  addiu     $s0, $sp, 0x98
/* D95938 80240348 AFBF0120 */  sw        $ra, 0x120($sp)
/* D9593C 8024034C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D95940 80240350 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D95944 80240354 00031080 */  sll       $v0, $v1, 2
/* D95948 80240358 00431021 */  addu      $v0, $v0, $v1
/* D9594C 8024035C 00021080 */  sll       $v0, $v0, 2
/* D95950 80240360 00431023 */  subu      $v0, $v0, $v1
/* D95954 80240364 000218C0 */  sll       $v1, $v0, 3
/* D95958 80240368 00431021 */  addu      $v0, $v0, $v1
/* D9595C 8024036C 000210C0 */  sll       $v0, $v0, 3
/* D95960 80240370 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D95964 80240374 00220821 */  addu      $at, $at, $v0
/* D95968 80240378 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D9596C 8024037C 4406A000 */  mfc1      $a2, $f20
/* D95970 80240380 4600B587 */  neg.s     $f22, $f22
/* D95974 80240384 4405B000 */  mfc1      $a1, $f22
/* D95978 80240388 0200202D */  daddu     $a0, $s0, $zero
/* D9597C 8024038C 0C019EC8 */  jal       guRotateF
/* D95980 80240390 E7B40010 */   swc1     $f20, 0x10($sp)
/* D95984 80240394 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D95988 80240398 0C00A6C9 */  jal       clamp_angle
/* D9598C 8024039C 00000000 */   nop
/* D95990 802403A0 44050000 */  mfc1      $a1, $f0
/* D95994 802403A4 4406A000 */  mfc1      $a2, $f20
/* D95998 802403A8 4407A000 */  mfc1      $a3, $f20
/* D9599C 802403AC 3C013F80 */  lui       $at, 0x3f80
/* D959A0 802403B0 4481C000 */  mtc1      $at, $f24
/* D959A4 802403B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D959A8 802403B8 0C019EC8 */  jal       guRotateF
/* D959AC 802403BC E7B80010 */   swc1     $f24, 0x10($sp)
/* D959B0 802403C0 0200202D */  daddu     $a0, $s0, $zero
/* D959B4 802403C4 27A50018 */  addiu     $a1, $sp, 0x18
/* D959B8 802403C8 0C019D80 */  jal       guMtxCatF
/* D959BC 802403CC 00A0302D */   daddu    $a2, $a1, $zero
/* D959C0 802403D0 4405B000 */  mfc1      $a1, $f22
/* D959C4 802403D4 4406A000 */  mfc1      $a2, $f20
/* D959C8 802403D8 4407C000 */  mfc1      $a3, $f24
/* D959CC 802403DC 0200202D */  daddu     $a0, $s0, $zero
/* D959D0 802403E0 0C019EC8 */  jal       guRotateF
/* D959D4 802403E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D959D8 802403E8 27A40018 */  addiu     $a0, $sp, 0x18
/* D959DC 802403EC 0200282D */  daddu     $a1, $s0, $zero
/* D959E0 802403F0 0C019D80 */  jal       guMtxCatF
/* D959E4 802403F4 0080302D */   daddu    $a2, $a0, $zero
/* D959E8 802403F8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D959EC 802403FC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D959F0 80240400 4406A000 */  mfc1      $a2, $f20
/* D959F4 80240404 4407C000 */  mfc1      $a3, $f24
/* D959F8 80240408 0C019EC8 */  jal       guRotateF
/* D959FC 8024040C 0200202D */   daddu    $a0, $s0, $zero
/* D95A00 80240410 27A40018 */  addiu     $a0, $sp, 0x18
/* D95A04 80240414 0200282D */  daddu     $a1, $s0, $zero
/* D95A08 80240418 0C019D80 */  jal       guMtxCatF
/* D95A0C 8024041C 0080302D */   daddu    $a2, $a0, $zero
/* D95A10 80240420 3C013F36 */  lui       $at, 0x3f36
/* D95A14 80240424 3421DB6E */  ori       $at, $at, 0xdb6e
/* D95A18 80240428 44810000 */  mtc1      $at, $f0
/* D95A1C 8024042C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D95A20 80240430 44050000 */  mfc1      $a1, $f0
/* D95A24 80240434 0200202D */  daddu     $a0, $s0, $zero
/* D95A28 80240438 00A0302D */  daddu     $a2, $a1, $zero
/* D95A2C 8024043C 0C019DF0 */  jal       guScaleF
/* D95A30 80240440 00A0382D */   daddu    $a3, $a1, $zero
/* D95A34 80240444 27A40018 */  addiu     $a0, $sp, 0x18
/* D95A38 80240448 0200282D */  daddu     $a1, $s0, $zero
/* D95A3C 8024044C 0C019D80 */  jal       guMtxCatF
/* D95A40 80240450 0080302D */   daddu    $a2, $a0, $zero
/* D95A44 80240454 27B00058 */  addiu     $s0, $sp, 0x58
/* D95A48 80240458 C6200030 */  lwc1      $f0, 0x30($s1)
/* D95A4C 8024045C 3C014040 */  lui       $at, 0x4040
/* D95A50 80240460 44811000 */  mtc1      $at, $f2
/* D95A54 80240464 46000007 */  neg.s     $f0, $f0
/* D95A58 80240468 46020001 */  sub.s     $f0, $f0, $f2
/* D95A5C 8024046C 8E250028 */  lw        $a1, 0x28($s1)
/* D95A60 80240470 8E26002C */  lw        $a2, 0x2c($s1)
/* D95A64 80240474 44070000 */  mfc1      $a3, $f0
/* D95A68 80240478 0C019E40 */  jal       guTranslateF
/* D95A6C 8024047C 0200202D */   daddu    $a0, $s0, $zero
/* D95A70 80240480 27A40018 */  addiu     $a0, $sp, 0x18
/* D95A74 80240484 0200282D */  daddu     $a1, $s0, $zero
/* D95A78 80240488 0C019D80 */  jal       guMtxCatF
/* D95A7C 8024048C 0080302D */   daddu    $a2, $a0, $zero
/* D95A80 80240490 24040002 */  addiu     $a0, $zero, 2
/* D95A84 80240494 0000282D */  daddu     $a1, $zero, $zero
/* D95A88 80240498 00A0302D */  daddu     $a2, $a1, $zero
/* D95A8C 8024049C 00A0382D */  daddu     $a3, $a1, $zero
/* D95A90 802404A0 27A20018 */  addiu     $v0, $sp, 0x18
/* D95A94 802404A4 0C0B7710 */  jal       render_sprite
/* D95A98 802404A8 AFA20010 */   sw       $v0, 0x10($sp)
/* D95A9C 802404AC 8FBF0120 */  lw        $ra, 0x120($sp)
/* D95AA0 802404B0 8FB1011C */  lw        $s1, 0x11c($sp)
/* D95AA4 802404B4 8FB00118 */  lw        $s0, 0x118($sp)
/* D95AA8 802404B8 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D95AAC 802404BC D7B60130 */  ldc1      $f22, 0x130($sp)
/* D95AB0 802404C0 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D95AB4 802404C4 03E00008 */  jr        $ra
/* D95AB8 802404C8 27BD0140 */   addiu    $sp, $sp, 0x140
