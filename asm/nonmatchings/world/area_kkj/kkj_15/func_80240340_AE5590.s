.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_AE58D0
/* AE58D0 80240340 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AE58D4 80240344 AFB00010 */  sw        $s0, 0x10($sp)
/* AE58D8 80240348 0080802D */  daddu     $s0, $a0, $zero
/* AE58DC 8024034C AFBF001C */  sw        $ra, 0x1c($sp)
/* AE58E0 80240350 AFB20018 */  sw        $s2, 0x18($sp)
/* AE58E4 80240354 AFB10014 */  sw        $s1, 0x14($sp)
/* AE58E8 80240358 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* AE58EC 8024035C F7BA0038 */  sdc1      $f26, 0x38($sp)
/* AE58F0 80240360 F7B80030 */  sdc1      $f24, 0x30($sp)
/* AE58F4 80240364 F7B60028 */  sdc1      $f22, 0x28($sp)
/* AE58F8 80240368 F7B40020 */  sdc1      $f20, 0x20($sp)
/* AE58FC 8024036C 0C00EAD2 */  jal       get_npc_safe
/* AE5900 80240370 2404FFFC */   addiu    $a0, $zero, -4
/* AE5904 80240374 3C040DB5 */  lui       $a0, 0xdb5
/* AE5908 80240378 34848580 */  ori       $a0, $a0, 0x8580
/* AE590C 8024037C C60200A0 */  lwc1      $f2, 0xa0($s0)
/* AE5910 80240380 468010A0 */  cvt.s.w   $f2, $f2
/* AE5914 80240384 44061000 */  mfc1      $a2, $f2
/* AE5918 80240388 C60200A4 */  lwc1      $f2, 0xa4($s0)
/* AE591C 8024038C 468010A0 */  cvt.s.w   $f2, $f2
/* AE5920 80240390 0040902D */  daddu     $s2, $v0, $zero
/* AE5924 80240394 8E03008C */  lw        $v1, 0x8c($s0)
/* AE5928 80240398 44071000 */  mfc1      $a3, $f2
/* AE592C 8024039C 3C014248 */  lui       $at, 0x4248
/* AE5930 802403A0 4481B000 */  mtc1      $at, $f22
/* AE5934 802403A4 3C01C348 */  lui       $at, 0xc348
/* AE5938 802403A8 4481A000 */  mtc1      $at, $f20
/* AE593C 802403AC 3C013A80 */  lui       $at, 0x3a80
/* AE5940 802403B0 44810000 */  mtc1      $at, $f0
/* AE5944 802403B4 00641821 */  addu      $v1, $v1, $a0
/* AE5948 802403B8 4483C000 */  mtc1      $v1, $f24
/* AE594C 802403BC 00000000 */  nop       
/* AE5950 802403C0 4680C620 */  cvt.s.w   $f24, $f24
/* AE5954 802403C4 4600B306 */  mov.s     $f12, $f22
/* AE5958 802403C8 4600C602 */  mul.s     $f24, $f24, $f0
/* AE595C 802403CC 00000000 */  nop       
/* AE5960 802403D0 0C00A7B5 */  jal       dist2D
/* AE5964 802403D4 4600A386 */   mov.s    $f14, $f20
/* AE5968 802403D8 46000706 */  mov.s     $f28, $f0
/* AE596C 802403DC 4600B306 */  mov.s     $f12, $f22
/* AE5970 802403E0 C60200A0 */  lwc1      $f2, 0xa0($s0)
/* AE5974 802403E4 468010A0 */  cvt.s.w   $f2, $f2
/* AE5978 802403E8 44061000 */  mfc1      $a2, $f2
/* AE597C 802403EC C60200A4 */  lwc1      $f2, 0xa4($s0)
/* AE5980 802403F0 468010A0 */  cvt.s.w   $f2, $f2
/* AE5984 802403F4 44071000 */  mfc1      $a3, $f2
/* AE5988 802403F8 0C00A720 */  jal       atan2
/* AE598C 802403FC 4600A386 */   mov.s    $f14, $f20
/* AE5990 80240400 0C00A6C9 */  jal       clamp_angle
/* AE5994 80240404 46180301 */   sub.s    $f12, $f0, $f24
/* AE5998 80240408 46000686 */  mov.s     $f26, $f0
/* AE599C 8024040C 0C00A8BB */  jal       sin_deg
/* AE59A0 80240410 4600D306 */   mov.s    $f12, $f26
/* AE59A4 80240414 4600E002 */  mul.s     $f0, $f28, $f0
/* AE59A8 80240418 00000000 */  nop       
/* AE59AC 8024041C 46160000 */  add.s     $f0, $f0, $f22
/* AE59B0 80240420 4600D306 */  mov.s     $f12, $f26
/* AE59B4 80240424 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* AE59B8 80240428 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* AE59BC 8024042C 0C00A8D4 */  jal       cos_deg
/* AE59C0 80240430 E6200028 */   swc1     $f0, 0x28($s1)
/* AE59C4 80240434 4600E002 */  mul.s     $f0, $f28, $f0
/* AE59C8 80240438 00000000 */  nop       
/* AE59CC 8024043C 4600A001 */  sub.s     $f0, $f20, $f0
/* AE59D0 80240440 4600B306 */  mov.s     $f12, $f22
/* AE59D4 80240444 E6200030 */  swc1      $f0, 0x30($s1)
/* AE59D8 80240448 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* AE59DC 8024044C 468010A0 */  cvt.s.w   $f2, $f2
/* AE59E0 80240450 44061000 */  mfc1      $a2, $f2
/* AE59E4 80240454 C60200AC */  lwc1      $f2, 0xac($s0)
/* AE59E8 80240458 468010A0 */  cvt.s.w   $f2, $f2
/* AE59EC 8024045C 44071000 */  mfc1      $a3, $f2
/* AE59F0 80240460 0C00A7B5 */  jal       dist2D
/* AE59F4 80240464 4600A386 */   mov.s    $f14, $f20
/* AE59F8 80240468 46000706 */  mov.s     $f28, $f0
/* AE59FC 8024046C 4600B306 */  mov.s     $f12, $f22
/* AE5A00 80240470 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* AE5A04 80240474 468010A0 */  cvt.s.w   $f2, $f2
/* AE5A08 80240478 44061000 */  mfc1      $a2, $f2
/* AE5A0C 8024047C C60200AC */  lwc1      $f2, 0xac($s0)
/* AE5A10 80240480 468010A0 */  cvt.s.w   $f2, $f2
/* AE5A14 80240484 44071000 */  mfc1      $a3, $f2
/* AE5A18 80240488 0C00A720 */  jal       atan2
/* AE5A1C 8024048C 4600A386 */   mov.s    $f14, $f20
/* AE5A20 80240490 0C00A6C9 */  jal       clamp_angle
/* AE5A24 80240494 46180301 */   sub.s    $f12, $f0, $f24
/* AE5A28 80240498 46000686 */  mov.s     $f26, $f0
/* AE5A2C 8024049C 0C00A8BB */  jal       sin_deg
/* AE5A30 802404A0 4600D306 */   mov.s    $f12, $f26
/* AE5A34 802404A4 4600E002 */  mul.s     $f0, $f28, $f0
/* AE5A38 802404A8 00000000 */  nop       
/* AE5A3C 802404AC 46160000 */  add.s     $f0, $f0, $f22
/* AE5A40 802404B0 4600D306 */  mov.s     $f12, $f26
/* AE5A44 802404B4 0C00A8D4 */  jal       cos_deg
/* AE5A48 802404B8 E6400038 */   swc1     $f0, 0x38($s2)
/* AE5A4C 802404BC 4600E002 */  mul.s     $f0, $f28, $f0
/* AE5A50 802404C0 00000000 */  nop       
/* AE5A54 802404C4 4600A501 */  sub.s     $f20, $f20, $f0
/* AE5A58 802404C8 E6540040 */  swc1      $f20, 0x40($s2)
/* AE5A5C 802404CC 8FBF001C */  lw        $ra, 0x1c($sp)
/* AE5A60 802404D0 8FB20018 */  lw        $s2, 0x18($sp)
/* AE5A64 802404D4 8FB10014 */  lw        $s1, 0x14($sp)
/* AE5A68 802404D8 8FB00010 */  lw        $s0, 0x10($sp)
/* AE5A6C 802404DC D7BC0040 */  ldc1      $f28, 0x40($sp)
/* AE5A70 802404E0 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* AE5A74 802404E4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* AE5A78 802404E8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* AE5A7C 802404EC D7B40020 */  ldc1      $f20, 0x20($sp)
/* AE5A80 802404F0 24020002 */  addiu     $v0, $zero, 2
/* AE5A84 802404F4 03E00008 */  jr        $ra
/* AE5A88 802404F8 27BD0048 */   addiu    $sp, $sp, 0x48
/* AE5A8C 802404FC 00000000 */  nop       
