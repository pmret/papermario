.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D58B80
/* D58B80 802402F0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D58B84 802402F4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D58B88 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D58B8C 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D58B90 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D58B94 80240304 4480A000 */  mtc1      $zero, $f20
/* D58B98 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D58B9C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D58BA0 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D58BA4 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D58BA8 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D58BAC 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D58BB0 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D58BB4 80240324 00031080 */  sll       $v0, $v1, 2
/* D58BB8 80240328 00431021 */  addu      $v0, $v0, $v1
/* D58BBC 8024032C 00021080 */  sll       $v0, $v0, 2
/* D58BC0 80240330 00431023 */  subu      $v0, $v0, $v1
/* D58BC4 80240334 000218C0 */  sll       $v1, $v0, 3
/* D58BC8 80240338 00431021 */  addu      $v0, $v0, $v1
/* D58BCC 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D58BD0 80240340 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D58BD4 80240344 00220821 */  addu      $at, $at, $v0
/* D58BD8 80240348 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D58BDC 8024034C 4406A000 */  mfc1      $a2, $f20
/* D58BE0 80240350 4600B587 */  neg.s     $f22, $f22
/* D58BE4 80240354 4405B000 */  mfc1      $a1, $f22
/* D58BE8 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D58BEC 8024035C 0C019EC8 */  jal       guRotateF
/* D58BF0 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D58BF4 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D58BF8 80240368 0C00A6C9 */  jal       clamp_angle
/* D58BFC 8024036C 00000000 */   nop
/* D58C00 80240370 44050000 */  mfc1      $a1, $f0
/* D58C04 80240374 4406A000 */  mfc1      $a2, $f20
/* D58C08 80240378 4407A000 */  mfc1      $a3, $f20
/* D58C0C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D58C10 80240380 4481C000 */  mtc1      $at, $f24
/* D58C14 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D58C18 80240388 0C019EC8 */  jal       guRotateF
/* D58C1C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D58C20 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D58C24 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D58C28 80240398 0C019D80 */  jal       guMtxCatF
/* D58C2C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D58C30 802403A0 4405B000 */  mfc1      $a1, $f22
/* D58C34 802403A4 4406A000 */  mfc1      $a2, $f20
/* D58C38 802403A8 4407C000 */  mfc1      $a3, $f24
/* D58C3C 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D58C40 802403B0 0C019EC8 */  jal       guRotateF
/* D58C44 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D58C48 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D58C4C 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D58C50 802403C0 0C019D80 */  jal       guMtxCatF
/* D58C54 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D58C58 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D58C5C 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D58C60 802403D0 4406A000 */  mfc1      $a2, $f20
/* D58C64 802403D4 4407C000 */  mfc1      $a3, $f24
/* D58C68 802403D8 0C019EC8 */  jal       guRotateF
/* D58C6C 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D58C70 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D58C74 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D58C78 802403E8 0C019D80 */  jal       guMtxCatF
/* D58C7C 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D58C80 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D58C84 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D58C88 802403F8 44810000 */  mtc1      $at, $f0
/* D58C8C 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D58C90 80240400 44050000 */  mfc1      $a1, $f0
/* D58C94 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D58C98 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D58C9C 8024040C 0C019DF0 */  jal       guScaleF
/* D58CA0 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D58CA4 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D58CA8 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D58CAC 8024041C 0C019D80 */  jal       guMtxCatF
/* D58CB0 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D58CB4 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D58CB8 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D58CBC 8024042C 3C014040 */  lui       $at, 0x4040
/* D58CC0 80240430 44811000 */  mtc1      $at, $f2
/* D58CC4 80240434 46000007 */  neg.s     $f0, $f0
/* D58CC8 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D58CCC 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D58CD0 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D58CD4 80240444 44070000 */  mfc1      $a3, $f0
/* D58CD8 80240448 0C019E40 */  jal       guTranslateF
/* D58CDC 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D58CE0 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D58CE4 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D58CE8 80240458 0C019D80 */  jal       guMtxCatF
/* D58CEC 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D58CF0 80240460 24040002 */  addiu     $a0, $zero, 2
/* D58CF4 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D58CF8 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D58CFC 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D58D00 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D58D04 80240474 0C0B7710 */  jal       render_sprite
/* D58D08 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D58D0C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D58D10 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D58D14 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D58D18 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D58D1C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D58D20 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D58D24 80240494 03E00008 */  jr        $ra
/* D58D28 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
