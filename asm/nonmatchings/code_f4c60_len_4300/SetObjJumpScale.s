.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetObjJumpScale
/* 0F83AC 802D39FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F83B0 802D3A00 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F83B4 802D3A04 0080882D */  daddu $s1, $a0, $zero
/* 0F83B8 802D3A08 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F83BC 802D3A0C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F83C0 802D3A10 8E30000C */  lw    $s0, 0xc($s1)
/* 0F83C4 802D3A14 8E050000 */  lw    $a1, ($s0)
/* 0F83C8 802D3A18 0C0B1EAF */  jal   get_variable
/* 0F83CC 802D3A1C 26100004 */   addiu $s0, $s0, 4
/* 0F83D0 802D3A20 0220202D */  daddu $a0, $s1, $zero
/* 0F83D4 802D3A24 8E050000 */  lw    $a1, ($s0)
/* 0F83D8 802D3A28 0C0B210B */  jal   get_float_variable
/* 0F83DC 802D3A2C 0040802D */   daddu $s0, $v0, $zero
/* 0F83E0 802D3A30 3C02802E */  lui   $v0, 0x802e
/* 0F83E4 802D3A34 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F83E8 802D3A38 00108080 */  sll   $s0, $s0, 2
/* 0F83EC 802D3A3C 02028021 */  addu  $s0, $s0, $v0
/* 0F83F0 802D3A40 8E030000 */  lw    $v1, ($s0)
/* 0F83F4 802D3A44 E4600040 */  swc1  $f0, 0x40($v1)
/* 0F83F8 802D3A48 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F83FC 802D3A4C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8400 802D3A50 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8404 802D3A54 24020002 */  addiu $v0, $zero, 2
/* 0F8408 802D3A58 03E00008 */  jr    $ra
/* 0F840C 802D3A5C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F8410 802D3A60 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F8414 802D3A64 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8418 802D3A68 0080902D */  daddu $s2, $a0, $zero
/* 0F841C 802D3A6C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8420 802D3A70 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8424 802D3A74 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8428 802D3A78 F7BA0038 */  sdc1  $f26, 0x38($sp)
/* 0F842C 802D3A7C F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0F8430 802D3A80 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F8434 802D3A84 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F8438 802D3A88 8E51000C */  lw    $s1, 0xc($s2)
/* 0F843C 802D3A8C 54A00001 */  bnel  $a1, $zero, .L802D3A94
/* 0F8440 802D3A90 AE400070 */   sw    $zero, 0x70($s2)
.L802D3A94:
/* 0F8444 802D3A94 8E420070 */  lw    $v0, 0x70($s2)
/* 0F8448 802D3A98 14400049 */  bnez  $v0, .L802D3BC0
/* 0F844C 802D3A9C 00000000 */   nop   
/* 0F8450 802D3AA0 8E250000 */  lw    $a1, ($s1)
/* 0F8454 802D3AA4 26310004 */  addiu $s1, $s1, 4
/* 0F8458 802D3AA8 0C0B1EAF */  jal   get_variable
/* 0F845C 802D3AAC 0240202D */   daddu $a0, $s2, $zero
/* 0F8460 802D3AB0 8E250000 */  lw    $a1, ($s1)
/* 0F8464 802D3AB4 26310004 */  addiu $s1, $s1, 4
/* 0F8468 802D3AB8 0240202D */  daddu $a0, $s2, $zero
/* 0F846C 802D3ABC 0C0B1EAF */  jal   get_variable
/* 0F8470 802D3AC0 0040802D */   daddu $s0, $v0, $zero
/* 0F8474 802D3AC4 4482D000 */  mtc1  $v0, $f26
/* 0F8478 802D3AC8 00000000 */  nop   
/* 0F847C 802D3ACC 4680D6A0 */  cvt.s.w $f26, $f26
/* 0F8480 802D3AD0 8E250000 */  lw    $a1, ($s1)
/* 0F8484 802D3AD4 26310004 */  addiu $s1, $s1, 4
/* 0F8488 802D3AD8 0C0B1EAF */  jal   get_variable
/* 0F848C 802D3ADC 0240202D */   daddu $a0, $s2, $zero
/* 0F8490 802D3AE0 8E250000 */  lw    $a1, ($s1)
/* 0F8494 802D3AE4 26310004 */  addiu $s1, $s1, 4
/* 0F8498 802D3AE8 4482A000 */  mtc1  $v0, $f20
/* 0F849C 802D3AEC 00000000 */  nop   
/* 0F84A0 802D3AF0 4680A520 */  cvt.s.w $f20, $f20
/* 0F84A4 802D3AF4 0C0B1EAF */  jal   get_variable
/* 0F84A8 802D3AF8 0240202D */   daddu $a0, $s2, $zero
/* 0F84AC 802D3AFC 4482C000 */  mtc1  $v0, $f24
/* 0F84B0 802D3B00 00000000 */  nop   
/* 0F84B4 802D3B04 4680C620 */  cvt.s.w $f24, $f24
/* 0F84B8 802D3B08 8E250000 */  lw    $a1, ($s1)
/* 0F84BC 802D3B0C 0C0B1EAF */  jal   get_variable
/* 0F84C0 802D3B10 0240202D */   daddu $a0, $s2, $zero
/* 0F84C4 802D3B14 3C04802E */  lui   $a0, 0x802e
/* 0F84C8 802D3B18 8C84B7C0 */  lw    $a0, -0x4840($a0)
/* 0F84CC 802D3B1C 00101880 */  sll   $v1, $s0, 2
/* 0F84D0 802D3B20 00641821 */  addu  $v1, $v1, $a0
/* 0F84D4 802D3B24 8C710000 */  lw    $s1, ($v1)
/* 0F84D8 802D3B28 AE500074 */  sw    $s0, 0x74($s2)
/* 0F84DC 802D3B2C E63A0028 */  swc1  $f26, 0x28($s1)
/* 0F84E0 802D3B30 C63A0004 */  lwc1  $f26, 4($s1)
/* 0F84E4 802D3B34 E6380030 */  swc1  $f24, 0x30($s1)
/* 0F84E8 802D3B38 C638000C */  lwc1  $f24, 0xc($s1)
/* 0F84EC 802D3B3C E634002C */  swc1  $f20, 0x2c($s1)
/* 0F84F0 802D3B40 C6340028 */  lwc1  $f20, 0x28($s1)
/* 0F84F4 802D3B44 C6360030 */  lwc1  $f22, 0x30($s1)
/* 0F84F8 802D3B48 44820000 */  mtc1  $v0, $f0
/* 0F84FC 802D3B4C 00000000 */  nop   
/* 0F8500 802D3B50 46800020 */  cvt.s.w $f0, $f0
/* 0F8504 802D3B54 E6200048 */  swc1  $f0, 0x48($s1)
/* 0F8508 802D3B58 4600D306 */  mov.s $f12, $f26
/* 0F850C 802D3B5C 4406A000 */  mfc1  $a2, $f20
/* 0F8510 802D3B60 4407B000 */  mfc1  $a3, $f22
/* 0F8514 802D3B64 0C00A720 */  jal   atan2
/* 0F8518 802D3B68 4600C386 */   mov.s $f14, $f24
/* 0F851C 802D3B6C 4600D306 */  mov.s $f12, $f26
/* 0F8520 802D3B70 4406A000 */  mfc1  $a2, $f20
/* 0F8524 802D3B74 4407B000 */  mfc1  $a3, $f22
/* 0F8528 802D3B78 4600C386 */  mov.s $f14, $f24
/* 0F852C 802D3B7C 0C00A7B5 */  jal   dist2D
/* 0F8530 802D3B80 E6200038 */   swc1  $f0, 0x38($s1)
/* 0F8534 802D3B84 C6260048 */  lwc1  $f6, 0x48($s1)
/* 0F8538 802D3B88 44801000 */  mtc1  $zero, $f2
/* 0F853C 802D3B8C 46000106 */  mov.s $f4, $f0
/* 0F8540 802D3B90 46023032 */  c.eq.s $f6, $f2
/* 0F8544 802D3B94 00000000 */  nop   
/* 0F8548 802D3B98 45000005 */  bc1f  .L802D3BB0
/* 0F854C 802D3B9C E6240034 */   swc1  $f4, 0x34($s1)
/* 0F8550 802D3BA0 C620003C */  lwc1  $f0, 0x3c($s1)
/* 0F8554 802D3BA4 46002003 */  div.s $f0, $f4, $f0
/* 0F8558 802D3BA8 080B4EEE */  j     .L802D3BB8
/* 0F855C 802D3BAC E6200048 */   swc1  $f0, 0x48($s1)

.L802D3BB0:
/* 0F8560 802D3BB0 46062003 */  div.s $f0, $f4, $f6
/* 0F8564 802D3BB4 E620003C */  swc1  $f0, 0x3c($s1)
.L802D3BB8:
/* 0F8568 802D3BB8 24020001 */  addiu $v0, $zero, 1
/* 0F856C 802D3BBC AE420070 */  sw    $v0, 0x70($s2)
.L802D3BC0:
/* 0F8570 802D3BC0 8E420074 */  lw    $v0, 0x74($s2)
/* 0F8574 802D3BC4 3C03802E */  lui   $v1, 0x802e
/* 0F8578 802D3BC8 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F857C 802D3BCC 00021080 */  sll   $v0, $v0, 2
/* 0F8580 802D3BD0 00431021 */  addu  $v0, $v0, $v1
/* 0F8584 802D3BD4 8C510000 */  lw    $s1, ($v0)
/* 0F8588 802D3BD8 8E25003C */  lw    $a1, 0x3c($s1)
/* 0F858C 802D3BDC 8E260038 */  lw    $a2, 0x38($s1)
/* 0F8590 802D3BE0 0C0B4BCD */  jal   func_802D2F34
/* 0F8594 802D3BE4 0220202D */   daddu $a0, $s1, $zero
/* 0F8598 802D3BE8 C6200048 */  lwc1  $f0, 0x48($s1)
/* 0F859C 802D3BEC 3C013F80 */  lui   $at, 0x3f80
/* 0F85A0 802D3BF0 44811000 */  mtc1  $at, $f2
/* 0F85A4 802D3BF4 00000000 */  nop   
/* 0F85A8 802D3BF8 46020001 */  sub.s $f0, $f0, $f2
/* 0F85AC 802D3BFC 44801000 */  mtc1  $zero, $f2
/* 0F85B0 802D3C00 00000000 */  nop   
/* 0F85B4 802D3C04 4602003E */  c.le.s $f0, $f2
/* 0F85B8 802D3C08 00000000 */  nop   
/* 0F85BC 802D3C0C 45010003 */  bc1t  .L802D3C1C
/* 0F85C0 802D3C10 E6200048 */   swc1  $f0, 0x48($s1)
/* 0F85C4 802D3C14 080B4F0C */  j     .L802D3C30
/* 0F85C8 802D3C18 0000102D */   daddu $v0, $zero, $zero

.L802D3C1C:
/* 0F85CC 802D3C1C C6200028 */  lwc1  $f0, 0x28($s1)
/* 0F85D0 802D3C20 C6220030 */  lwc1  $f2, 0x30($s1)
/* 0F85D4 802D3C24 24020001 */  addiu $v0, $zero, 1
/* 0F85D8 802D3C28 E6200004 */  swc1  $f0, 4($s1)
/* 0F85DC 802D3C2C E622000C */  swc1  $f2, 0xc($s1)
.L802D3C30:
/* 0F85E0 802D3C30 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F85E4 802D3C34 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F85E8 802D3C38 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F85EC 802D3C3C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F85F0 802D3C40 D7BA0038 */  ldc1  $f26, 0x38($sp)
/* 0F85F4 802D3C44 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0F85F8 802D3C48 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F85FC 802D3C4C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F8600 802D3C50 03E00008 */  jr    $ra
/* 0F8604 802D3C54 27BD0040 */   addiu $sp, $sp, 0x40

