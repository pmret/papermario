.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240320_D63030
/* D63030 80240320 3C03800A */  lui       $v1, 0x800a
/* D63034 80240324 8463A634 */  lh        $v1, -0x59cc($v1)
/* D63038 80240328 3C07BF80 */  lui       $a3, 0xbf80
/* D6303C 8024032C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D63040 80240330 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D63044 80240334 4480A000 */  mtc1      $zero, $f20
/* D63048 80240338 AFB1011C */  sw        $s1, 0x11c($sp)
/* D6304C 8024033C 0080882D */  daddu     $s1, $a0, $zero
/* D63050 80240340 AFB00118 */  sw        $s0, 0x118($sp)
/* D63054 80240344 27B00098 */  addiu     $s0, $sp, 0x98
/* D63058 80240348 AFBF0120 */  sw        $ra, 0x120($sp)
/* D6305C 8024034C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D63060 80240350 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D63064 80240354 00031080 */  sll       $v0, $v1, 2
/* D63068 80240358 00431021 */  addu      $v0, $v0, $v1
/* D6306C 8024035C 00021080 */  sll       $v0, $v0, 2
/* D63070 80240360 00431023 */  subu      $v0, $v0, $v1
/* D63074 80240364 000218C0 */  sll       $v1, $v0, 3
/* D63078 80240368 00431021 */  addu      $v0, $v0, $v1
/* D6307C 8024036C 000210C0 */  sll       $v0, $v0, 3
/* D63080 80240370 3C01800B */  lui       $at, 0x800b
/* D63084 80240374 00220821 */  addu      $at, $at, $v0
/* D63088 80240378 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D6308C 8024037C 4406A000 */  mfc1      $a2, $f20
/* D63090 80240380 4600B587 */  neg.s     $f22, $f22
/* D63094 80240384 4405B000 */  mfc1      $a1, $f22
/* D63098 80240388 0200202D */  daddu     $a0, $s0, $zero
/* D6309C 8024038C 0C019EC8 */  jal       guRotateF
/* D630A0 80240390 E7B40010 */   swc1     $f20, 0x10($sp)
/* D630A4 80240394 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D630A8 80240398 0C00A6C9 */  jal       clamp_angle
/* D630AC 8024039C 00000000 */   nop      
/* D630B0 802403A0 44050000 */  mfc1      $a1, $f0
/* D630B4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D630B8 802403A8 4407A000 */  mfc1      $a3, $f20
/* D630BC 802403AC 3C013F80 */  lui       $at, 0x3f80
/* D630C0 802403B0 4481C000 */  mtc1      $at, $f24
/* D630C4 802403B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D630C8 802403B8 0C019EC8 */  jal       guRotateF
/* D630CC 802403BC E7B80010 */   swc1     $f24, 0x10($sp)
/* D630D0 802403C0 0200202D */  daddu     $a0, $s0, $zero
/* D630D4 802403C4 27A50018 */  addiu     $a1, $sp, 0x18
/* D630D8 802403C8 0C019D80 */  jal       guMtxCatF
/* D630DC 802403CC 00A0302D */   daddu    $a2, $a1, $zero
/* D630E0 802403D0 4405B000 */  mfc1      $a1, $f22
/* D630E4 802403D4 4406A000 */  mfc1      $a2, $f20
/* D630E8 802403D8 4407C000 */  mfc1      $a3, $f24
/* D630EC 802403DC 0200202D */  daddu     $a0, $s0, $zero
/* D630F0 802403E0 0C019EC8 */  jal       guRotateF
/* D630F4 802403E4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D630F8 802403E8 27A40018 */  addiu     $a0, $sp, 0x18
/* D630FC 802403EC 0200282D */  daddu     $a1, $s0, $zero
/* D63100 802403F0 0C019D80 */  jal       guMtxCatF
/* D63104 802403F4 0080302D */   daddu    $a2, $a0, $zero
/* D63108 802403F8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D6310C 802403FC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D63110 80240400 4406A000 */  mfc1      $a2, $f20
/* D63114 80240404 4407C000 */  mfc1      $a3, $f24
/* D63118 80240408 0C019EC8 */  jal       guRotateF
/* D6311C 8024040C 0200202D */   daddu    $a0, $s0, $zero
/* D63120 80240410 27A40018 */  addiu     $a0, $sp, 0x18
/* D63124 80240414 0200282D */  daddu     $a1, $s0, $zero
/* D63128 80240418 0C019D80 */  jal       guMtxCatF
/* D6312C 8024041C 0080302D */   daddu    $a2, $a0, $zero
/* D63130 80240420 3C013F36 */  lui       $at, 0x3f36
/* D63134 80240424 3421DB6E */  ori       $at, $at, 0xdb6e
/* D63138 80240428 44810000 */  mtc1      $at, $f0
/* D6313C 8024042C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D63140 80240430 44050000 */  mfc1      $a1, $f0
/* D63144 80240434 0200202D */  daddu     $a0, $s0, $zero
/* D63148 80240438 00A0302D */  daddu     $a2, $a1, $zero
/* D6314C 8024043C 0C019DF0 */  jal       guScaleF
/* D63150 80240440 00A0382D */   daddu    $a3, $a1, $zero
/* D63154 80240444 27A40018 */  addiu     $a0, $sp, 0x18
/* D63158 80240448 0200282D */  daddu     $a1, $s0, $zero
/* D6315C 8024044C 0C019D80 */  jal       guMtxCatF
/* D63160 80240450 0080302D */   daddu    $a2, $a0, $zero
/* D63164 80240454 27B00058 */  addiu     $s0, $sp, 0x58
/* D63168 80240458 C6200030 */  lwc1      $f0, 0x30($s1)
/* D6316C 8024045C 3C014040 */  lui       $at, 0x4040
/* D63170 80240460 44811000 */  mtc1      $at, $f2
/* D63174 80240464 46000007 */  neg.s     $f0, $f0
/* D63178 80240468 46020001 */  sub.s     $f0, $f0, $f2
/* D6317C 8024046C 8E250028 */  lw        $a1, 0x28($s1)
/* D63180 80240470 8E26002C */  lw        $a2, 0x2c($s1)
/* D63184 80240474 44070000 */  mfc1      $a3, $f0
/* D63188 80240478 0C019E40 */  jal       guTranslateF
/* D6318C 8024047C 0200202D */   daddu    $a0, $s0, $zero
/* D63190 80240480 27A40018 */  addiu     $a0, $sp, 0x18
/* D63194 80240484 0200282D */  daddu     $a1, $s0, $zero
/* D63198 80240488 0C019D80 */  jal       guMtxCatF
/* D6319C 8024048C 0080302D */   daddu    $a2, $a0, $zero
/* D631A0 80240490 24040002 */  addiu     $a0, $zero, 2
/* D631A4 80240494 0000282D */  daddu     $a1, $zero, $zero
/* D631A8 80240498 00A0302D */  daddu     $a2, $a1, $zero
/* D631AC 8024049C 00A0382D */  daddu     $a3, $a1, $zero
/* D631B0 802404A0 27A20018 */  addiu     $v0, $sp, 0x18
/* D631B4 802404A4 0C0B7710 */  jal       render_sprite
/* D631B8 802404A8 AFA20010 */   sw       $v0, 0x10($sp)
/* D631BC 802404AC 8FBF0120 */  lw        $ra, 0x120($sp)
/* D631C0 802404B0 8FB1011C */  lw        $s1, 0x11c($sp)
/* D631C4 802404B4 8FB00118 */  lw        $s0, 0x118($sp)
/* D631C8 802404B8 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D631CC 802404BC D7B60130 */  ldc1      $f22, 0x130($sp)
/* D631D0 802404C0 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D631D4 802404C4 03E00008 */  jr        $ra
/* D631D8 802404C8 27BD0140 */   addiu    $sp, $sp, 0x140
