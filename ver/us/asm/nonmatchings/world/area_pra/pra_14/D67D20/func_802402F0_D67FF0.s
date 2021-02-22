.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D67FF0
/* D67FF0 802402F0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D67FF4 802402F4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D67FF8 802402F8 3C07BF80 */  lui       $a3, 0xbf80
/* D67FFC 802402FC 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D68000 80240300 F7B40128 */  sdc1      $f20, 0x128($sp)
/* D68004 80240304 4480A000 */  mtc1      $zero, $f20
/* D68008 80240308 AFB1011C */  sw        $s1, 0x11c($sp)
/* D6800C 8024030C 0080882D */  daddu     $s1, $a0, $zero
/* D68010 80240310 AFB00118 */  sw        $s0, 0x118($sp)
/* D68014 80240314 27B00098 */  addiu     $s0, $sp, 0x98
/* D68018 80240318 AFBF0120 */  sw        $ra, 0x120($sp)
/* D6801C 8024031C F7B80138 */  sdc1      $f24, 0x138($sp)
/* D68020 80240320 F7B60130 */  sdc1      $f22, 0x130($sp)
/* D68024 80240324 00031080 */  sll       $v0, $v1, 2
/* D68028 80240328 00431021 */  addu      $v0, $v0, $v1
/* D6802C 8024032C 00021080 */  sll       $v0, $v0, 2
/* D68030 80240330 00431023 */  subu      $v0, $v0, $v1
/* D68034 80240334 000218C0 */  sll       $v1, $v0, 3
/* D68038 80240338 00431021 */  addu      $v0, $v0, $v1
/* D6803C 8024033C 000210C0 */  sll       $v0, $v0, 3
/* D68040 80240340 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D68044 80240344 00220821 */  addu      $at, $at, $v0
/* D68048 80240348 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D6804C 8024034C 4406A000 */  mfc1      $a2, $f20
/* D68050 80240350 4600B587 */  neg.s     $f22, $f22
/* D68054 80240354 4405B000 */  mfc1      $a1, $f22
/* D68058 80240358 0200202D */  daddu     $a0, $s0, $zero
/* D6805C 8024035C 0C019EC8 */  jal       guRotateF
/* D68060 80240360 E7B40010 */   swc1     $f20, 0x10($sp)
/* D68064 80240364 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D68068 80240368 0C00A6C9 */  jal       clamp_angle
/* D6806C 8024036C 00000000 */   nop
/* D68070 80240370 44050000 */  mfc1      $a1, $f0
/* D68074 80240374 4406A000 */  mfc1      $a2, $f20
/* D68078 80240378 4407A000 */  mfc1      $a3, $f20
/* D6807C 8024037C 3C013F80 */  lui       $at, 0x3f80
/* D68080 80240380 4481C000 */  mtc1      $at, $f24
/* D68084 80240384 27A40018 */  addiu     $a0, $sp, 0x18
/* D68088 80240388 0C019EC8 */  jal       guRotateF
/* D6808C 8024038C E7B80010 */   swc1     $f24, 0x10($sp)
/* D68090 80240390 0200202D */  daddu     $a0, $s0, $zero
/* D68094 80240394 27A50018 */  addiu     $a1, $sp, 0x18
/* D68098 80240398 0C019D80 */  jal       guMtxCatF
/* D6809C 8024039C 00A0302D */   daddu    $a2, $a1, $zero
/* D680A0 802403A0 4405B000 */  mfc1      $a1, $f22
/* D680A4 802403A4 4406A000 */  mfc1      $a2, $f20
/* D680A8 802403A8 4407C000 */  mfc1      $a3, $f24
/* D680AC 802403AC 0200202D */  daddu     $a0, $s0, $zero
/* D680B0 802403B0 0C019EC8 */  jal       guRotateF
/* D680B4 802403B4 E7B40010 */   swc1     $f20, 0x10($sp)
/* D680B8 802403B8 27A40018 */  addiu     $a0, $sp, 0x18
/* D680BC 802403BC 0200282D */  daddu     $a1, $s0, $zero
/* D680C0 802403C0 0C019D80 */  jal       guMtxCatF
/* D680C4 802403C4 0080302D */   daddu    $a2, $a0, $zero
/* D680C8 802403C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* D680CC 802403CC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D680D0 802403D0 4406A000 */  mfc1      $a2, $f20
/* D680D4 802403D4 4407C000 */  mfc1      $a3, $f24
/* D680D8 802403D8 0C019EC8 */  jal       guRotateF
/* D680DC 802403DC 0200202D */   daddu    $a0, $s0, $zero
/* D680E0 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* D680E4 802403E4 0200282D */  daddu     $a1, $s0, $zero
/* D680E8 802403E8 0C019D80 */  jal       guMtxCatF
/* D680EC 802403EC 0080302D */   daddu    $a2, $a0, $zero
/* D680F0 802403F0 3C013F36 */  lui       $at, 0x3f36
/* D680F4 802403F4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D680F8 802403F8 44810000 */  mtc1      $at, $f0
/* D680FC 802403FC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D68100 80240400 44050000 */  mfc1      $a1, $f0
/* D68104 80240404 0200202D */  daddu     $a0, $s0, $zero
/* D68108 80240408 00A0302D */  daddu     $a2, $a1, $zero
/* D6810C 8024040C 0C019DF0 */  jal       guScaleF
/* D68110 80240410 00A0382D */   daddu    $a3, $a1, $zero
/* D68114 80240414 27A40018 */  addiu     $a0, $sp, 0x18
/* D68118 80240418 0200282D */  daddu     $a1, $s0, $zero
/* D6811C 8024041C 0C019D80 */  jal       guMtxCatF
/* D68120 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D68124 80240424 27B00058 */  addiu     $s0, $sp, 0x58
/* D68128 80240428 C6200030 */  lwc1      $f0, 0x30($s1)
/* D6812C 8024042C 3C014040 */  lui       $at, 0x4040
/* D68130 80240430 44811000 */  mtc1      $at, $f2
/* D68134 80240434 46000007 */  neg.s     $f0, $f0
/* D68138 80240438 46020001 */  sub.s     $f0, $f0, $f2
/* D6813C 8024043C 8E250028 */  lw        $a1, 0x28($s1)
/* D68140 80240440 8E26002C */  lw        $a2, 0x2c($s1)
/* D68144 80240444 44070000 */  mfc1      $a3, $f0
/* D68148 80240448 0C019E40 */  jal       guTranslateF
/* D6814C 8024044C 0200202D */   daddu    $a0, $s0, $zero
/* D68150 80240450 27A40018 */  addiu     $a0, $sp, 0x18
/* D68154 80240454 0200282D */  daddu     $a1, $s0, $zero
/* D68158 80240458 0C019D80 */  jal       guMtxCatF
/* D6815C 8024045C 0080302D */   daddu    $a2, $a0, $zero
/* D68160 80240460 24040002 */  addiu     $a0, $zero, 2
/* D68164 80240464 0000282D */  daddu     $a1, $zero, $zero
/* D68168 80240468 00A0302D */  daddu     $a2, $a1, $zero
/* D6816C 8024046C 00A0382D */  daddu     $a3, $a1, $zero
/* D68170 80240470 27A20018 */  addiu     $v0, $sp, 0x18
/* D68174 80240474 0C0B7710 */  jal       render_sprite
/* D68178 80240478 AFA20010 */   sw       $v0, 0x10($sp)
/* D6817C 8024047C 8FBF0120 */  lw        $ra, 0x120($sp)
/* D68180 80240480 8FB1011C */  lw        $s1, 0x11c($sp)
/* D68184 80240484 8FB00118 */  lw        $s0, 0x118($sp)
/* D68188 80240488 D7B80138 */  ldc1      $f24, 0x138($sp)
/* D6818C 8024048C D7B60130 */  ldc1      $f22, 0x130($sp)
/* D68190 80240490 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D68194 80240494 03E00008 */  jr        $ra
/* D68198 80240498 27BD0140 */   addiu    $sp, $sp, 0x140
