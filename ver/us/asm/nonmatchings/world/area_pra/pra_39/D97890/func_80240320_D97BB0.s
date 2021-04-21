.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240320_D97BB0
/* D97BB0 80240320 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D97BB4 80240324 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D97BB8 80240328 3C07BF80 */  lui       $a3, 0xbf80
/* D97BBC 8024032C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D97BC0 80240330 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D97BC4 80240334 4480A000 */  mtc1      $zero, $f20
/* D97BC8 80240338 AFB1011C */  sw        $s1, 0x11c($sp)
/* D97BCC 8024033C 0080882D */  daddu     $s1, $a0, $zero
/* D97BD0 80240340 AFB00118 */  sw        $s0, 0x118($sp)
/* D97BD4 80240344 27B00098 */  addiu     $s0, $sp, 0x98
/* D97BD8 80240348 AFBF0120 */  sw        $ra, 0x120($sp)
/* D97BDC 8024034C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D97BE0 80240350 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D97BE4 80240354 00031080 */  sll       $v0, $v1, 2
/* D97BE8 80240358 00431021 */  addu      $v0, $v0, $v1
/* D97BEC 8024035C 00021080 */  sll       $v0, $v0, 2
/* D97BF0 80240360 00431023 */  subu      $v0, $v0, $v1
/* D97BF4 80240364 000218C0 */  sll       $v1, $v0, 3
/* D97BF8 80240368 00431021 */  addu      $v0, $v0, $v1
/* D97BFC 8024036C 000210C0 */  sll       $v0, $v0, 3
/* D97C00 80240370 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D97C04 80240374 00220821 */  addu      $at, $at, $v0
/* D97C08 80240378 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D97C0C 8024037C 4406A000 */  mfc1      $a2, $f20
/* D97C10 80240380 4600B587 */  neg.s     $f22, $f22
/* D97C14 80240384 4405B000 */  mfc1      $a1, $f22
/* D97C18 80240388 0200202D */  daddu     $a0, $s0, $zero
/* D97C1C 8024038C 0C019EC8 */  jal       guRotateF
/* D97C20 80240390 E7B40010 */   swc1     $f20, 0x10($sp)
/* D97C24 80240394 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D97C28 80240398 0C00A6C9 */  jal       clamp_angle
/* D97C2C 8024039C 00000000 */   nop
/* D97C30 802403A0 44050000 */  mfc1      $a1, $f0
/* D97C34 802403A4 4406A000 */  mfc1      $a2, $f20
/* D97C38 802403A8 4407A000 */  mfc1      $a3, $f20
/* D97C3C 802403AC 3C013F80 */  lui       $at, 0x3f80
/* D97C40 802403B0 4481C000 */  mtc1      $at, $f24
/* D97C44 802403B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D97C48 802403B8 0C019EC8 */  jal       guRotateF
/* D97C4C 802403BC E7B80010 */   swc1     $f24, 0x10($sp)
/* D97C50 802403C0 0200202D */  daddu     $a0, $s0, $zero
/* D97C54 802403C4 27A50018 */  addiu     $a1, $sp, 0x18
/* D97C58 802403C8 0C019D80 */  jal       guMtxCatF
/* D97C5C 802403CC 00A0302D */   daddu    $a2, $a1, $zero
/* D97C60 802403D0 4405B000 */  mfc1      $a1, $f22
/* D97C64 802403D4 4406A000 */  mfc1      $a2, $f20
/* D97C68 802403D8 4407C000 */  mfc1      $a3, $f24
/* D97C6C 802403DC 0200202D */  daddu     $a0, $s0, $zero
/* D97C70 802403E0 0C019EC8 */  jal       guRotateF
/* D97C74 802403E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D97C78 802403E8 27A40018 */  addiu     $a0, $sp, 0x18
/* D97C7C 802403EC 0200282D */  daddu     $a1, $s0, $zero
/* D97C80 802403F0 0C019D80 */  jal       guMtxCatF
/* D97C84 802403F4 0080302D */   daddu    $a2, $a0, $zero
/* D97C88 802403F8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D97C8C 802403FC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D97C90 80240400 4406A000 */  mfc1      $a2, $f20
/* D97C94 80240404 4407C000 */  mfc1      $a3, $f24
/* D97C98 80240408 0C019EC8 */  jal       guRotateF
/* D97C9C 8024040C 0200202D */   daddu    $a0, $s0, $zero
/* D97CA0 80240410 27A40018 */  addiu     $a0, $sp, 0x18
/* D97CA4 80240414 0200282D */  daddu     $a1, $s0, $zero
/* D97CA8 80240418 0C019D80 */  jal       guMtxCatF
/* D97CAC 8024041C 0080302D */   daddu    $a2, $a0, $zero
/* D97CB0 80240420 3C013F36 */  lui       $at, 0x3f36
/* D97CB4 80240424 3421DB6E */  ori       $at, $at, 0xdb6e
/* D97CB8 80240428 44810000 */  mtc1      $at, $f0
/* D97CBC 8024042C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D97CC0 80240430 44050000 */  mfc1      $a1, $f0
/* D97CC4 80240434 0200202D */  daddu     $a0, $s0, $zero
/* D97CC8 80240438 00A0302D */  daddu     $a2, $a1, $zero
/* D97CCC 8024043C 0C019DF0 */  jal       guScaleF
/* D97CD0 80240440 00A0382D */   daddu    $a3, $a1, $zero
/* D97CD4 80240444 27A40018 */  addiu     $a0, $sp, 0x18
/* D97CD8 80240448 0200282D */  daddu     $a1, $s0, $zero
/* D97CDC 8024044C 0C019D80 */  jal       guMtxCatF
/* D97CE0 80240450 0080302D */   daddu    $a2, $a0, $zero
/* D97CE4 80240454 27B00058 */  addiu     $s0, $sp, 0x58
/* D97CE8 80240458 C6200030 */  lwc1      $f0, 0x30($s1)
/* D97CEC 8024045C 3C014040 */  lui       $at, 0x4040
/* D97CF0 80240460 44811000 */  mtc1      $at, $f2
/* D97CF4 80240464 46000007 */  neg.s     $f0, $f0
/* D97CF8 80240468 46020001 */  sub.s     $f0, $f0, $f2
/* D97CFC 8024046C 8E250028 */  lw        $a1, 0x28($s1)
/* D97D00 80240470 8E26002C */  lw        $a2, 0x2c($s1)
/* D97D04 80240474 44070000 */  mfc1      $a3, $f0
/* D97D08 80240478 0C019E40 */  jal       guTranslateF
/* D97D0C 8024047C 0200202D */   daddu    $a0, $s0, $zero
/* D97D10 80240480 27A40018 */  addiu     $a0, $sp, 0x18
/* D97D14 80240484 0200282D */  daddu     $a1, $s0, $zero
/* D97D18 80240488 0C019D80 */  jal       guMtxCatF
/* D97D1C 8024048C 0080302D */   daddu    $a2, $a0, $zero
/* D97D20 80240490 24040002 */  addiu     $a0, $zero, 2
/* D97D24 80240494 0000282D */  daddu     $a1, $zero, $zero
/* D97D28 80240498 00A0302D */  daddu     $a2, $a1, $zero
/* D97D2C 8024049C 00A0382D */  daddu     $a3, $a1, $zero
/* D97D30 802404A0 27A20018 */  addiu     $v0, $sp, 0x18
/* D97D34 802404A4 0C0B7710 */  jal       render_sprite
/* D97D38 802404A8 AFA20010 */   sw       $v0, 0x10($sp)
/* D97D3C 802404AC 8FBF0120 */  lw        $ra, 0x120($sp)
/* D97D40 802404B0 8FB1011C */  lw        $s1, 0x11c($sp)
/* D97D44 802404B4 8FB00118 */  lw        $s0, 0x118($sp)
/* D97D48 802404B8 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D97D4C 802404BC D7B60130 */  ldc1      $f22, 0x130($sp)
/* D97D50 802404C0 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D97D54 802404C4 03E00008 */  jr        $ra
/* D97D58 802404C8 27BD0140 */   addiu    $sp, $sp, 0x140
