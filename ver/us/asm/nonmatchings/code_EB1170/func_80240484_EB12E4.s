.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240484_EB12E4
/* EB12E4 80240484 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EB12E8 80240488 AFB10014 */  sw        $s1, 0x14($sp)
/* EB12EC 8024048C 0080882D */  daddu     $s1, $a0, $zero
/* EB12F0 80240490 AFBF0024 */  sw        $ra, 0x24($sp)
/* EB12F4 80240494 AFB40020 */  sw        $s4, 0x20($sp)
/* EB12F8 80240498 AFB3001C */  sw        $s3, 0x1c($sp)
/* EB12FC 8024049C AFB20018 */  sw        $s2, 0x18($sp)
/* EB1300 802404A0 AFB00010 */  sw        $s0, 0x10($sp)
/* EB1304 802404A4 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* EB1308 802404A8 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* EB130C 802404AC F7B80038 */  sdc1      $f24, 0x38($sp)
/* EB1310 802404B0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* EB1314 802404B4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EB1318 802404B8 8E30000C */  lw        $s0, 0xc($s1)
/* EB131C 802404BC 8E130000 */  lw        $s3, ($s0)
/* EB1320 802404C0 26100004 */  addiu     $s0, $s0, 4
/* EB1324 802404C4 0C0B53A3 */  jal       dead_get_variable
/* EB1328 802404C8 0260282D */   daddu    $a1, $s3, $zero
/* EB132C 802404CC 4482E000 */  mtc1      $v0, $f28
/* EB1330 802404D0 00000000 */  nop
/* EB1334 802404D4 4680E720 */  cvt.s.w   $f28, $f28
/* EB1338 802404D8 8E140000 */  lw        $s4, ($s0)
/* EB133C 802404DC 26100004 */  addiu     $s0, $s0, 4
/* EB1340 802404E0 0220202D */  daddu     $a0, $s1, $zero
/* EB1344 802404E4 0C0B53A3 */  jal       dead_get_variable
/* EB1348 802404E8 0280282D */   daddu    $a1, $s4, $zero
/* EB134C 802404EC 4482D000 */  mtc1      $v0, $f26
/* EB1350 802404F0 00000000 */  nop
/* EB1354 802404F4 4680D6A0 */  cvt.s.w   $f26, $f26
/* EB1358 802404F8 8E100000 */  lw        $s0, ($s0)
/* EB135C 802404FC 0220202D */  daddu     $a0, $s1, $zero
/* EB1360 80240500 0C0B53A3 */  jal       dead_get_variable
/* EB1364 80240504 0200282D */   daddu    $a1, $s0, $zero
/* EB1368 80240508 4482C000 */  mtc1      $v0, $f24
/* EB136C 8024050C 00000000 */  nop
/* EB1370 80240510 4680C620 */  cvt.s.w   $f24, $f24
/* EB1374 80240514 3C128011 */  lui       $s2, %hi(D_80117578)
/* EB1378 80240518 26527578 */  addiu     $s2, $s2, %lo(D_80117578)
/* EB137C 8024051C 3C038008 */  lui       $v1, %hi(D_8007C760)
/* EB1380 80240520 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* EB1384 80240524 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* EB1388 80240528 44800000 */  mtc1      $zero, $f0
/* EB138C 8024052C 00031080 */  sll       $v0, $v1, 2
/* EB1390 80240530 00431021 */  addu      $v0, $v0, $v1
/* EB1394 80240534 00021080 */  sll       $v0, $v0, 2
/* EB1398 80240538 00431023 */  subu      $v0, $v0, $v1
/* EB139C 8024053C 000218C0 */  sll       $v1, $v0, 3
/* EB13A0 80240540 00431021 */  addu      $v0, $v0, $v1
/* EB13A4 80240544 000210C0 */  sll       $v0, $v0, 3
/* EB13A8 80240548 46001032 */  c.eq.s    $f2, $f0
/* EB13AC 8024054C 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EB13B0 80240550 00220821 */  addu      $at, $at, $v0
/* EB13B4 80240554 C4368DEC */  lwc1      $f22, %lo(D_800B8DEC)($at)
/* EB13B8 80240558 45000005 */  bc1f      .L80240570
/* EB13BC 8024055C 00000000 */   nop
/* EB13C0 80240560 3C0142C8 */  lui       $at, 0x42c8
/* EB13C4 80240564 44810000 */  mtc1      $at, $f0
/* EB13C8 80240568 08090160 */  j         .L80240580
/* EB13CC 8024056C 4600B581 */   sub.s    $f22, $f22, $f0
.L80240570:
/* EB13D0 80240570 3C0142C8 */  lui       $at, 0x42c8
/* EB13D4 80240574 44810000 */  mtc1      $at, $f0
/* EB13D8 80240578 00000000 */  nop
/* EB13DC 8024057C 4600B580 */  add.s     $f22, $f22, $f0
.L80240580:
/* EB13E0 80240580 0C00AB85 */  jal       func_8002AE14
/* EB13E4 80240584 4600B306 */   mov.s    $f12, $f22
/* EB13E8 80240588 46000586 */  mov.s     $f22, $f0
/* EB13EC 8024058C 3C014170 */  lui       $at, 0x4170
/* EB13F0 80240590 4481A000 */  mtc1      $at, $f20
/* EB13F4 80240594 0C00AD77 */  jal       func_8002B5DC
/* EB13F8 80240598 4600B306 */   mov.s    $f12, $f22
/* EB13FC 8024059C 46140002 */  mul.s     $f0, $f0, $f20
/* EB1400 802405A0 00000000 */  nop
/* EB1404 802405A4 864200B0 */  lh        $v0, 0xb0($s2)
/* EB1408 802405A8 3C013F00 */  lui       $at, 0x3f00
/* EB140C 802405AC 44812000 */  mtc1      $at, $f4
/* EB1410 802405B0 44821000 */  mtc1      $v0, $f2
/* EB1414 802405B4 00000000 */  nop
/* EB1418 802405B8 468010A0 */  cvt.s.w   $f2, $f2
/* EB141C 802405BC 46041082 */  mul.s     $f2, $f2, $f4
/* EB1420 802405C0 00000000 */  nop
/* EB1424 802405C4 4600E700 */  add.s     $f28, $f28, $f0
/* EB1428 802405C8 4602D680 */  add.s     $f26, $f26, $f2
/* EB142C 802405CC 0C00AD90 */  jal       func_8002B640
/* EB1430 802405D0 4600B306 */   mov.s    $f12, $f22
/* EB1434 802405D4 46140002 */  mul.s     $f0, $f0, $f20
/* EB1438 802405D8 00000000 */  nop
/* EB143C 802405DC 0220202D */  daddu     $a0, $s1, $zero
/* EB1440 802405E0 0260282D */  daddu     $a1, $s3, $zero
/* EB1444 802405E4 4600E18D */  trunc.w.s $f6, $f28
/* EB1448 802405E8 44063000 */  mfc1      $a2, $f6
/* EB144C 802405EC 0C0B551A */  jal       dead_set_variable
/* EB1450 802405F0 4600C601 */   sub.s    $f24, $f24, $f0
/* EB1454 802405F4 0220202D */  daddu     $a0, $s1, $zero
/* EB1458 802405F8 4600D18D */  trunc.w.s $f6, $f26
/* EB145C 802405FC 44063000 */  mfc1      $a2, $f6
/* EB1460 80240600 0C0B551A */  jal       dead_set_variable
/* EB1464 80240604 0280282D */   daddu    $a1, $s4, $zero
/* EB1468 80240608 0220202D */  daddu     $a0, $s1, $zero
/* EB146C 8024060C 4600C18D */  trunc.w.s $f6, $f24
/* EB1470 80240610 44063000 */  mfc1      $a2, $f6
/* EB1474 80240614 0C0B551A */  jal       dead_set_variable
/* EB1478 80240618 0200282D */   daddu    $a1, $s0, $zero
/* EB147C 8024061C 8FBF0024 */  lw        $ra, 0x24($sp)
/* EB1480 80240620 8FB40020 */  lw        $s4, 0x20($sp)
/* EB1484 80240624 8FB3001C */  lw        $s3, 0x1c($sp)
/* EB1488 80240628 8FB20018 */  lw        $s2, 0x18($sp)
/* EB148C 8024062C 8FB10014 */  lw        $s1, 0x14($sp)
/* EB1490 80240630 8FB00010 */  lw        $s0, 0x10($sp)
/* EB1494 80240634 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* EB1498 80240638 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* EB149C 8024063C D7B80038 */  ldc1      $f24, 0x38($sp)
/* EB14A0 80240640 D7B60030 */  ldc1      $f22, 0x30($sp)
/* EB14A4 80240644 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EB14A8 80240648 24020002 */  addiu     $v0, $zero, 2
/* EB14AC 8024064C 03E00008 */  jr        $ra
/* EB14B0 80240650 27BD0050 */   addiu    $sp, $sp, 0x50
