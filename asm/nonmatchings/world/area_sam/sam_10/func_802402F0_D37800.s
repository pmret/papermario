.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_D37AF0
/* D37AF0 802402F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D37AF4 802402F4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* D37AF8 802402F8 3C01439B */  lui       $at, 0x439b
/* D37AFC 802402FC 4481B000 */  mtc1      $at, $f22
/* D37B00 80240300 F7B40020 */  sdc1      $f20, 0x20($sp)
/* D37B04 80240304 3C0142C8 */  lui       $at, 0x42c8
/* D37B08 80240308 4481A000 */  mtc1      $at, $f20
/* D37B0C 8024030C AFB10014 */  sw        $s1, 0x14($sp)
/* D37B10 80240310 0080882D */  daddu     $s1, $a0, $zero
/* D37B14 80240314 AFBF0018 */  sw        $ra, 0x18($sp)
/* D37B18 80240318 AFB00010 */  sw        $s0, 0x10($sp)
/* D37B1C 8024031C 0C00A8BB */  jal       sin_deg
/* D37B20 80240320 4600B306 */   mov.s    $f12, $f22
/* D37B24 80240324 46140002 */  mul.s     $f0, $f0, $f20
/* D37B28 80240328 00000000 */  nop       
/* D37B2C 8024032C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D37B30 80240330 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D37B34 80240334 C6020028 */  lwc1      $f2, 0x28($s0)
/* D37B38 80240338 46001080 */  add.s     $f2, $f2, $f0
/* D37B3C 8024033C 4600110D */  trunc.w.s $f4, $f2
/* D37B40 80240340 E6240084 */  swc1      $f4, 0x84($s1)
/* D37B44 80240344 0C00A8D4 */  jal       cos_deg
/* D37B48 80240348 4600B306 */   mov.s    $f12, $f22
/* D37B4C 8024034C 46140002 */  mul.s     $f0, $f0, $f20
/* D37B50 80240350 00000000 */  nop       
/* D37B54 80240354 C6020030 */  lwc1      $f2, 0x30($s0)
/* D37B58 80240358 3C014302 */  lui       $at, 0x4302
/* D37B5C 8024035C 4481B000 */  mtc1      $at, $f22
/* D37B60 80240360 46001081 */  sub.s     $f2, $f2, $f0
/* D37B64 80240364 4600110D */  trunc.w.s $f4, $f2
/* D37B68 80240368 E6240088 */  swc1      $f4, 0x88($s1)
/* D37B6C 8024036C 0C00A8BB */  jal       sin_deg
/* D37B70 80240370 4600B306 */   mov.s    $f12, $f22
/* D37B74 80240374 46140002 */  mul.s     $f0, $f0, $f20
/* D37B78 80240378 00000000 */  nop       
/* D37B7C 8024037C C6020028 */  lwc1      $f2, 0x28($s0)
/* D37B80 80240380 46001080 */  add.s     $f2, $f2, $f0
/* D37B84 80240384 4600110D */  trunc.w.s $f4, $f2
/* D37B88 80240388 E624008C */  swc1      $f4, 0x8c($s1)
/* D37B8C 8024038C 0C00A8D4 */  jal       cos_deg
/* D37B90 80240390 4600B306 */   mov.s    $f12, $f22
/* D37B94 80240394 46140002 */  mul.s     $f0, $f0, $f20
/* D37B98 80240398 00000000 */  nop       
/* D37B9C 8024039C C6020030 */  lwc1      $f2, 0x30($s0)
/* D37BA0 802403A0 46001081 */  sub.s     $f2, $f2, $f0
/* D37BA4 802403A4 4600110D */  trunc.w.s $f4, $f2
/* D37BA8 802403A8 E6240090 */  swc1      $f4, 0x90($s1)
/* D37BAC 802403AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D37BB0 802403B0 8FB10014 */  lw        $s1, 0x14($sp)
/* D37BB4 802403B4 8FB00010 */  lw        $s0, 0x10($sp)
/* D37BB8 802403B8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* D37BBC 802403BC D7B40020 */  ldc1      $f20, 0x20($sp)
/* D37BC0 802403C0 24020002 */  addiu     $v0, $zero, 2
/* D37BC4 802403C4 03E00008 */  jr        $ra
/* D37BC8 802403C8 27BD0030 */   addiu    $sp, $sp, 0x30
/* D37BCC 802403CC 00000000 */  nop       
