.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel input_to_move_vector
/* 7B7B4 800E2304 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7B7B8 800E2308 AFB10014 */  sw        $s1, 0x14($sp)
/* 7B7BC 800E230C 0080882D */  daddu     $s1, $a0, $zero
/* 7B7C0 800E2310 AFB20018 */  sw        $s2, 0x18($sp)
/* 7B7C4 800E2314 00A0902D */  daddu     $s2, $a1, $zero
/* 7B7C8 800E2318 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 7B7CC 800E231C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7B7D0 800E2320 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7B7D4 800E2324 AFB00010 */  sw        $s0, 0x10($sp)
/* 7B7D8 800E2328 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 7B7DC 800E232C F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 7B7E0 800E2330 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 7B7E4 800E2334 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 7B7E8 800E2338 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 7B7EC 800E233C C47C00E8 */  lwc1      $f28, 0xe8($v1)
/* 7B7F0 800E2340 4680E720 */  cvt.s.w   $f28, $f28
/* 7B7F4 800E2344 0060802D */  daddu     $s0, $v1, $zero
/* 7B7F8 800E2348 4480D000 */  mtc1      $zero, $f26
/* 7B7FC 800E234C 4406E000 */  mfc1      $a2, $f28
/* 7B800 800E2350 8C6200EC */  lw        $v0, 0xec($v1)
/* 7B804 800E2354 4600D306 */  mov.s     $f12, $f26
/* 7B808 800E2358 00021023 */  negu      $v0, $v0
/* 7B80C 800E235C 4482C000 */  mtc1      $v0, $f24
/* 7B810 800E2360 00000000 */  nop       
/* 7B814 800E2364 4680C620 */  cvt.s.w   $f24, $f24
/* 7B818 800E2368 4407C000 */  mfc1      $a3, $f24
/* 7B81C 800E236C 0C00A7B5 */  jal       dist2D
/* 7B820 800E2370 4600D386 */   mov.s    $f14, $f26
/* 7B824 800E2374 3C01428C */  lui       $at, 0x428c
/* 7B828 800E2378 4481B000 */  mtc1      $at, $f22
/* 7B82C 800E237C 46000506 */  mov.s     $f20, $f0
/* 7B830 800E2380 4614B03E */  c.le.s    $f22, $f20
/* 7B834 800E2384 00000000 */  nop       
/* 7B838 800E2388 45030001 */  bc1tl     .L800E2390
/* 7B83C 800E238C 4600B506 */   mov.s    $f20, $f22
.L800E2390:
/* 7B840 800E2390 4600D306 */  mov.s     $f12, $f26
/* 7B844 800E2394 4406E000 */  mfc1      $a2, $f28
/* 7B848 800E2398 4407C000 */  mfc1      $a3, $f24
/* 7B84C 800E239C 0C00A720 */  jal       atan2
/* 7B850 800E23A0 4600D386 */   mov.s    $f14, $f26
/* 7B854 800E23A4 3C01800B */  lui       $at, 0x800b
/* 7B858 800E23A8 C42C1DEC */  lwc1      $f12, 0x1dec($at)
/* 7B85C 800E23AC 0C00A6C9 */  jal       clamp_angle
/* 7B860 800E23B0 460C0300 */   add.s    $f12, $f0, $f12
/* 7B864 800E23B4 461AA032 */  c.eq.s    $f20, $f26
/* 7B868 800E23B8 00000000 */  nop       
/* 7B86C 800E23BC 45020003 */  bc1fl     .L800E23CC
/* 7B870 800E23C0 E6200000 */   swc1     $f0, ($s1)
/* 7B874 800E23C4 C6000080 */  lwc1      $f0, 0x80($s0)
/* 7B878 800E23C8 E6200000 */  swc1      $f0, ($s1)
.L800E23CC:
/* 7B87C 800E23CC E6540000 */  swc1      $f20, ($s2)
/* 7B880 800E23D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7B884 800E23D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 7B888 800E23D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 7B88C 800E23DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7B890 800E23E0 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 7B894 800E23E4 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 7B898 800E23E8 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 7B89C 800E23EC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 7B8A0 800E23F0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 7B8A4 800E23F4 03E00008 */  jr        $ra
/* 7B8A8 800E23F8 27BD0048 */   addiu    $sp, $sp, 0x48
