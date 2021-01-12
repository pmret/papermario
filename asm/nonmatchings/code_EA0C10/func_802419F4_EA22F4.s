.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419F4_EA22F4
/* EA22F4 802419F4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EA22F8 802419F8 AFB40040 */  sw        $s4, 0x40($sp)
/* EA22FC 802419FC 0080A02D */  daddu     $s4, $a0, $zero
/* EA2300 80241A00 AFBF0044 */  sw        $ra, 0x44($sp)
/* EA2304 80241A04 AFB3003C */  sw        $s3, 0x3c($sp)
/* EA2308 80241A08 AFB20038 */  sw        $s2, 0x38($sp)
/* EA230C 80241A0C AFB10034 */  sw        $s1, 0x34($sp)
/* EA2310 80241A10 AFB00030 */  sw        $s0, 0x30($sp)
/* EA2314 80241A14 8E910148 */  lw        $s1, 0x148($s4)
/* EA2318 80241A18 00A0902D */  daddu     $s2, $a1, $zero
/* EA231C 80241A1C 86240008 */  lh        $a0, 8($s1)
/* EA2320 80241A20 0C00F92F */  jal       func_8003E4BC
/* EA2324 80241A24 00C0982D */   daddu    $s3, $a2, $zero
/* EA2328 80241A28 0040802D */  daddu     $s0, $v0, $zero
/* EA232C 80241A2C 9602008E */  lhu       $v0, 0x8e($s0)
/* EA2330 80241A30 2442FFFF */  addiu     $v0, $v0, -1
/* EA2334 80241A34 A602008E */  sh        $v0, 0x8e($s0)
/* EA2338 80241A38 00021400 */  sll       $v0, $v0, 0x10
/* EA233C 80241A3C 14400020 */  bnez      $v0, .L80241AC0
/* EA2340 80241A40 0260202D */   daddu    $a0, $s3, $zero
/* EA2344 80241A44 AFA00010 */  sw        $zero, 0x10($sp)
/* EA2348 80241A48 8E46000C */  lw        $a2, 0xc($s2)
/* EA234C 80241A4C 8E470010 */  lw        $a3, 0x10($s2)
/* EA2350 80241A50 0C013469 */  jal       func_8004D1A4
/* EA2354 80241A54 0220282D */   daddu    $a1, $s1, $zero
/* EA2358 80241A58 54400018 */  bnel      $v0, $zero, .L80241ABC
/* EA235C 80241A5C A600008E */   sh       $zero, 0x8e($s0)
/* EA2360 80241A60 24040002 */  addiu     $a0, $zero, 2
/* EA2364 80241A64 0200282D */  daddu     $a1, $s0, $zero
/* EA2368 80241A68 0000302D */  daddu     $a2, $zero, $zero
/* EA236C 80241A6C 860300A8 */  lh        $v1, 0xa8($s0)
/* EA2370 80241A70 3C013F80 */  lui       $at, 0x3f80
/* EA2374 80241A74 44810000 */  mtc1      $at, $f0
/* EA2378 80241A78 3C014000 */  lui       $at, 0x4000
/* EA237C 80241A7C 44811000 */  mtc1      $at, $f2
/* EA2380 80241A80 3C01C1A0 */  lui       $at, 0xc1a0
/* EA2384 80241A84 44812000 */  mtc1      $at, $f4
/* EA2388 80241A88 2402000F */  addiu     $v0, $zero, 0xf
/* EA238C 80241A8C AFA2001C */  sw        $v0, 0x1c($sp)
/* EA2390 80241A90 44833000 */  mtc1      $v1, $f6
/* EA2394 80241A94 00000000 */  nop       
/* EA2398 80241A98 468031A0 */  cvt.s.w   $f6, $f6
/* EA239C 80241A9C 44073000 */  mfc1      $a3, $f6
/* EA23A0 80241AA0 27A20028 */  addiu     $v0, $sp, 0x28
/* EA23A4 80241AA4 AFA20020 */  sw        $v0, 0x20($sp)
/* EA23A8 80241AA8 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA23AC 80241AAC E7A20014 */  swc1      $f2, 0x14($sp)
/* EA23B0 80241AB0 0C01D444 */  jal       func_80075110
/* EA23B4 80241AB4 E7A40018 */   swc1     $f4, 0x18($sp)
/* EA23B8 80241AB8 A600008E */  sh        $zero, 0x8e($s0)
.L80241ABC:
/* EA23BC 80241ABC AE800070 */  sw        $zero, 0x70($s4)
.L80241AC0:
/* EA23C0 80241AC0 8FBF0044 */  lw        $ra, 0x44($sp)
/* EA23C4 80241AC4 8FB40040 */  lw        $s4, 0x40($sp)
/* EA23C8 80241AC8 8FB3003C */  lw        $s3, 0x3c($sp)
/* EA23CC 80241ACC 8FB20038 */  lw        $s2, 0x38($sp)
/* EA23D0 80241AD0 8FB10034 */  lw        $s1, 0x34($sp)
/* EA23D4 80241AD4 8FB00030 */  lw        $s0, 0x30($sp)
/* EA23D8 80241AD8 03E00008 */  jr        $ra
/* EA23DC 80241ADC 27BD0048 */   addiu    $sp, $sp, 0x48
