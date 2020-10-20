.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_CC1220
/* CC1220 802403F0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CC1224 802403F4 AFB10014 */  sw        $s1, 0x14($sp)
/* CC1228 802403F8 0080882D */  daddu     $s1, $a0, $zero
/* CC122C 802403FC AFBF0024 */  sw        $ra, 0x24($sp)
/* CC1230 80240400 AFB40020 */  sw        $s4, 0x20($sp)
/* CC1234 80240404 AFB3001C */  sw        $s3, 0x1c($sp)
/* CC1238 80240408 AFB20018 */  sw        $s2, 0x18($sp)
/* CC123C 8024040C AFB00010 */  sw        $s0, 0x10($sp)
/* CC1240 80240410 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CC1244 80240414 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CC1248 80240418 F7B80038 */  sdc1      $f24, 0x38($sp)
/* CC124C 8024041C F7B60030 */  sdc1      $f22, 0x30($sp)
/* CC1250 80240420 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CC1254 80240424 8E30000C */  lw        $s0, 0xc($s1)
/* CC1258 80240428 8E130000 */  lw        $s3, ($s0)
/* CC125C 8024042C 26100004 */  addiu     $s0, $s0, 4
/* CC1260 80240430 0C0B1EAF */  jal       get_variable
/* CC1264 80240434 0260282D */   daddu    $a1, $s3, $zero
/* CC1268 80240438 4482E000 */  mtc1      $v0, $f28
/* CC126C 8024043C 00000000 */  nop       
/* CC1270 80240440 4680E720 */  cvt.s.w   $f28, $f28
/* CC1274 80240444 8E140000 */  lw        $s4, ($s0)
/* CC1278 80240448 26100004 */  addiu     $s0, $s0, 4
/* CC127C 8024044C 0220202D */  daddu     $a0, $s1, $zero
/* CC1280 80240450 0C0B1EAF */  jal       get_variable
/* CC1284 80240454 0280282D */   daddu    $a1, $s4, $zero
/* CC1288 80240458 4482D000 */  mtc1      $v0, $f26
/* CC128C 8024045C 00000000 */  nop       
/* CC1290 80240460 4680D6A0 */  cvt.s.w   $f26, $f26
/* CC1294 80240464 8E100000 */  lw        $s0, ($s0)
/* CC1298 80240468 0220202D */  daddu     $a0, $s1, $zero
/* CC129C 8024046C 0C0B1EAF */  jal       get_variable
/* CC12A0 80240470 0200282D */   daddu    $a1, $s0, $zero
/* CC12A4 80240474 4482C000 */  mtc1      $v0, $f24
/* CC12A8 80240478 00000000 */  nop       
/* CC12AC 8024047C 4680C620 */  cvt.s.w   $f24, $f24
/* CC12B0 80240480 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CC12B4 80240484 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CC12B8 80240488 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CC12BC 8024048C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CC12C0 80240490 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* CC12C4 80240494 44800000 */  mtc1      $zero, $f0
/* CC12C8 80240498 00031080 */  sll       $v0, $v1, 2
/* CC12CC 8024049C 00431021 */  addu      $v0, $v0, $v1
/* CC12D0 802404A0 00021080 */  sll       $v0, $v0, 2
/* CC12D4 802404A4 00431023 */  subu      $v0, $v0, $v1
/* CC12D8 802404A8 000218C0 */  sll       $v1, $v0, 3
/* CC12DC 802404AC 00431021 */  addu      $v0, $v0, $v1
/* CC12E0 802404B0 000210C0 */  sll       $v0, $v0, 3
/* CC12E4 802404B4 46001032 */  c.eq.s    $f2, $f0
/* CC12E8 802404B8 3C01800B */  lui       $at, 0x800b
/* CC12EC 802404BC 00220821 */  addu      $at, $at, $v0
/* CC12F0 802404C0 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* CC12F4 802404C4 45000005 */  bc1f      .L802404DC
/* CC12F8 802404C8 00000000 */   nop      
/* CC12FC 802404CC 3C0142C8 */  lui       $at, 0x42c8
/* CC1300 802404D0 44810000 */  mtc1      $at, $f0
/* CC1304 802404D4 0809013B */  j         .L802404EC
/* CC1308 802404D8 4600B581 */   sub.s    $f22, $f22, $f0
.L802404DC:
/* CC130C 802404DC 3C0142C8 */  lui       $at, 0x42c8
/* CC1310 802404E0 44810000 */  mtc1      $at, $f0
/* CC1314 802404E4 00000000 */  nop       
/* CC1318 802404E8 4600B580 */  add.s     $f22, $f22, $f0
.L802404EC:
/* CC131C 802404EC 0C00A6C9 */  jal       clamp_angle
/* CC1320 802404F0 4600B306 */   mov.s    $f12, $f22
/* CC1324 802404F4 46000586 */  mov.s     $f22, $f0
/* CC1328 802404F8 3C014170 */  lui       $at, 0x4170
/* CC132C 802404FC 4481A000 */  mtc1      $at, $f20
/* CC1330 80240500 0C00A8BB */  jal       sin_deg
/* CC1334 80240504 4600B306 */   mov.s    $f12, $f22
/* CC1338 80240508 46140002 */  mul.s     $f0, $f0, $f20
/* CC133C 8024050C 00000000 */  nop       
/* CC1340 80240510 864200B0 */  lh        $v0, 0xb0($s2)
/* CC1344 80240514 3C013F00 */  lui       $at, 0x3f00
/* CC1348 80240518 44812000 */  mtc1      $at, $f4
/* CC134C 8024051C 44821000 */  mtc1      $v0, $f2
/* CC1350 80240520 00000000 */  nop       
/* CC1354 80240524 468010A0 */  cvt.s.w   $f2, $f2
/* CC1358 80240528 46041082 */  mul.s     $f2, $f2, $f4
/* CC135C 8024052C 00000000 */  nop       
/* CC1360 80240530 4600E700 */  add.s     $f28, $f28, $f0
/* CC1364 80240534 4602D680 */  add.s     $f26, $f26, $f2
/* CC1368 80240538 0C00A8D4 */  jal       cos_deg
/* CC136C 8024053C 4600B306 */   mov.s    $f12, $f22
/* CC1370 80240540 46140002 */  mul.s     $f0, $f0, $f20
/* CC1374 80240544 00000000 */  nop       
/* CC1378 80240548 0220202D */  daddu     $a0, $s1, $zero
/* CC137C 8024054C 0260282D */  daddu     $a1, $s3, $zero
/* CC1380 80240550 4600E18D */  trunc.w.s $f6, $f28
/* CC1384 80240554 44063000 */  mfc1      $a2, $f6
/* CC1388 80240558 0C0B2026 */  jal       set_variable
/* CC138C 8024055C 4600C601 */   sub.s    $f24, $f24, $f0
/* CC1390 80240560 0220202D */  daddu     $a0, $s1, $zero
/* CC1394 80240564 4600D18D */  trunc.w.s $f6, $f26
/* CC1398 80240568 44063000 */  mfc1      $a2, $f6
/* CC139C 8024056C 0C0B2026 */  jal       set_variable
/* CC13A0 80240570 0280282D */   daddu    $a1, $s4, $zero
/* CC13A4 80240574 0220202D */  daddu     $a0, $s1, $zero
/* CC13A8 80240578 4600C18D */  trunc.w.s $f6, $f24
/* CC13AC 8024057C 44063000 */  mfc1      $a2, $f6
/* CC13B0 80240580 0C0B2026 */  jal       set_variable
/* CC13B4 80240584 0200282D */   daddu    $a1, $s0, $zero
/* CC13B8 80240588 8FBF0024 */  lw        $ra, 0x24($sp)
/* CC13BC 8024058C 8FB40020 */  lw        $s4, 0x20($sp)
/* CC13C0 80240590 8FB3001C */  lw        $s3, 0x1c($sp)
/* CC13C4 80240594 8FB20018 */  lw        $s2, 0x18($sp)
/* CC13C8 80240598 8FB10014 */  lw        $s1, 0x14($sp)
/* CC13CC 8024059C 8FB00010 */  lw        $s0, 0x10($sp)
/* CC13D0 802405A0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CC13D4 802405A4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CC13D8 802405A8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CC13DC 802405AC D7B60030 */  ldc1      $f22, 0x30($sp)
/* CC13E0 802405B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* CC13E4 802405B4 24020002 */  addiu     $v0, $zero, 2
/* CC13E8 802405B8 03E00008 */  jr        $ra
/* CC13EC 802405BC 27BD0050 */   addiu    $sp, $sp, 0x50
