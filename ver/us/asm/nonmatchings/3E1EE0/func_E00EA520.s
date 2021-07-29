.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00EA520
/* 3E2400 E00EA520 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3E2404 E00EA524 AFB1004C */  sw        $s1, 0x4c($sp)
/* 3E2408 E00EA528 0080882D */  daddu     $s1, $a0, $zero
/* 3E240C E00EA52C AFBF0050 */  sw        $ra, 0x50($sp)
/* 3E2410 E00EA530 AFB00048 */  sw        $s0, 0x48($sp)
/* 3E2414 E00EA534 8E27000C */  lw        $a3, 0xc($s1)
/* 3E2418 E00EA538 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3E241C E00EA53C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3E2420 E00EA540 3C013F80 */  lui       $at, 0x3f80
/* 3E2424 E00EA544 44810000 */  mtc1      $at, $f0
/* 3E2428 E00EA548 27A20038 */  addiu     $v0, $sp, 0x38
/* 3E242C E00EA54C AFA20014 */  sw        $v0, 0x14($sp)
/* 3E2430 E00EA550 27A2003C */  addiu     $v0, $sp, 0x3c
/* 3E2434 E00EA554 AFA20018 */  sw        $v0, 0x18($sp)
/* 3E2438 E00EA558 27A20040 */  addiu     $v0, $sp, 0x40
/* 3E243C E00EA55C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E2440 E00EA560 27A20044 */  addiu     $v0, $sp, 0x44
/* 3E2444 E00EA564 AFA20020 */  sw        $v0, 0x20($sp)
/* 3E2448 E00EA568 00032080 */  sll       $a0, $v1, 2
/* 3E244C E00EA56C 00832021 */  addu      $a0, $a0, $v1
/* 3E2450 E00EA570 00042080 */  sll       $a0, $a0, 2
/* 3E2454 E00EA574 00832023 */  subu      $a0, $a0, $v1
/* 3E2458 E00EA578 000410C0 */  sll       $v0, $a0, 3
/* 3E245C E00EA57C 00822021 */  addu      $a0, $a0, $v0
/* 3E2460 E00EA580 000420C0 */  sll       $a0, $a0, 3
/* 3E2464 E00EA584 3C02800B */  lui       $v0, %hi(gCameras+0xD4)
/* 3E2468 E00EA588 24421E54 */  addiu     $v0, $v0, %lo(gCameras+0xD4)
/* 3E246C E00EA58C E7A00010 */  swc1      $f0, 0x10($sp)
/* 3E2470 E00EA590 8CE50004 */  lw        $a1, 4($a3)
/* 3E2474 E00EA594 8CE60008 */  lw        $a2, 8($a3)
/* 3E2478 E00EA598 8CE7000C */  lw        $a3, 0xc($a3)
/* 3E247C E00EA59C 0C080168 */  jal       func_E02005A0
/* 3E2480 E00EA5A0 00822021 */   addu     $a0, $a0, $v0
/* 3E2484 E00EA5A4 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 3E2488 E00EA5A8 3C01459C */  lui       $at, 0x459c
/* 3E248C E00EA5AC 34214000 */  ori       $at, $at, 0x4000
/* 3E2490 E00EA5B0 44811000 */  mtc1      $at, $f2
/* 3E2494 E00EA5B4 00000000 */  nop
/* 3E2498 E00EA5B8 46020000 */  add.s     $f0, $f0, $f2
/* 3E249C E00EA5BC 4600010D */  trunc.w.s $f4, $f0
/* 3E24A0 E00EA5C0 44032000 */  mfc1      $v1, $f4
/* 3E24A4 E00EA5C4 00000000 */  nop
/* 3E24A8 E00EA5C8 04610003 */  bgez      $v1, .LE00EA5D8
/* 3E24AC E00EA5CC 27B00028 */   addiu    $s0, $sp, 0x28
/* 3E24B0 E00EA5D0 0803A979 */  j         .LE00EA5E4
/* 3E24B4 E00EA5D4 0000182D */   daddu    $v1, $zero, $zero
.LE00EA5D8:
/* 3E24B8 E00EA5D8 28622711 */  slti      $v0, $v1, 0x2711
/* 3E24BC E00EA5DC 50400001 */  beql      $v0, $zero, .LE00EA5E4
/* 3E24C0 E00EA5E0 24032710 */   addiu    $v1, $zero, 0x2710
.LE00EA5E4:
/* 3E24C4 E00EA5E4 C7A20044 */  lwc1      $f2, 0x44($sp)
/* 3E24C8 E00EA5E8 3C01E00F */  lui       $at, %hi(D_E00EAA68)
/* 3E24CC E00EA5EC D420AA68 */  ldc1      $f0, %lo(D_E00EAA68)($at)
/* 3E24D0 E00EA5F0 460010A1 */  cvt.d.s   $f2, $f2
/* 3E24D4 E00EA5F4 4620103C */  c.lt.d    $f2, $f0
/* 3E24D8 E00EA5F8 00000000 */  nop
/* 3E24DC E00EA5FC 45000008 */  bc1f      .LE00EA620
/* 3E24E0 E00EA600 0200202D */   daddu    $a0, $s0, $zero
/* 3E24E4 E00EA604 3C01E00F */  lui       $at, %hi(D_E00EAA70)
/* 3E24E8 E00EA608 D420AA70 */  ldc1      $f0, %lo(D_E00EAA70)($at)
/* 3E24EC E00EA60C 4622003C */  c.lt.d    $f0, $f2
/* 3E24F0 E00EA610 00000000 */  nop
/* 3E24F4 E00EA614 45030002 */  bc1tl     .LE00EA620
/* 3E24F8 E00EA618 0000182D */   daddu    $v1, $zero, $zero
/* 3E24FC E00EA61C 0200202D */  daddu     $a0, $s0, $zero
.LE00EA620:
/* 3E2500 E00EA620 3C02E00F */  lui       $v0, %hi(func_E00EA66C)
/* 3E2504 E00EA624 2442A66C */  addiu     $v0, $v0, %lo(func_E00EA66C)
/* 3E2508 E00EA628 AC82000C */  sw        $v0, 0xc($a0)
/* 3E250C E00EA62C 00031023 */  negu      $v0, $v1
/* 3E2510 E00EA630 AC820004 */  sw        $v0, 4($a0)
/* 3E2514 E00EA634 24020011 */  addiu     $v0, $zero, 0x11
/* 3E2518 E00EA638 AC910008 */  sw        $s1, 8($a0)
/* 3E251C E00EA63C 0C080120 */  jal       func_E0200480
/* 3E2520 E00EA640 AC820000 */   sw       $v0, ($a0)
/* 3E2524 E00EA644 8C430000 */  lw        $v1, ($v0)
/* 3E2528 E00EA648 34630002 */  ori       $v1, $v1, 2
/* 3E252C E00EA64C AC430000 */  sw        $v1, ($v0)
/* 3E2530 E00EA650 8FBF0050 */  lw        $ra, 0x50($sp)
/* 3E2534 E00EA654 8FB1004C */  lw        $s1, 0x4c($sp)
/* 3E2538 E00EA658 8FB00048 */  lw        $s0, 0x48($sp)
/* 3E253C E00EA65C 03E00008 */  jr        $ra
/* 3E2540 E00EA660 27BD0058 */   addiu    $sp, $sp, 0x58
