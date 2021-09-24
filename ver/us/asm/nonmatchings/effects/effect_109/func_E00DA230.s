.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DA230
/* 3D7470 E00DA230 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 3D7474 E00DA234 0080302D */  daddu     $a2, $a0, $zero
/* 3D7478 E00DA238 3C07DB06 */  lui       $a3, 0xdb06
/* 3D747C E00DA23C 34E70024 */  ori       $a3, $a3, 0x24
/* 3D7480 E00DA240 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D7484 E00DA244 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3D7488 E00DA248 3C160001 */  lui       $s6, 1
/* 3D748C E00DA24C AFB3009C */  sw        $s3, 0x9c($sp)
/* 3D7490 E00DA250 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3D7494 E00DA254 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3D7498 E00DA258 36D61630 */  ori       $s6, $s6, 0x1630
/* 3D749C E00DA25C AFBF00AC */  sw        $ra, 0xac($sp)
/* 3D74A0 E00DA260 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3D74A4 E00DA264 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3D74A8 E00DA268 AFB20098 */  sw        $s2, 0x98($sp)
/* 3D74AC E00DA26C AFB10094 */  sw        $s1, 0x94($sp)
/* 3D74B0 E00DA270 AFB00090 */  sw        $s0, 0x90($sp)
/* 3D74B4 E00DA274 F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 3D74B8 E00DA278 8E650000 */  lw        $a1, ($s3)
/* 3D74BC E00DA27C 8CD2000C */  lw        $s2, 0xc($a2)
/* 3D74C0 E00DA280 00A0182D */  daddu     $v1, $a1, $zero
/* 3D74C4 E00DA284 24A50008 */  addiu     $a1, $a1, 8
/* 3D74C8 E00DA288 AE650000 */  sw        $a1, ($s3)
/* 3D74CC E00DA28C 8E550024 */  lw        $s5, 0x24($s2)
/* 3D74D0 E00DA290 C6540028 */  lwc1      $f20, 0x28($s2)
/* 3D74D4 E00DA294 C640002C */  lwc1      $f0, 0x2c($s2)
/* 3D74D8 E00DA298 3C02E700 */  lui       $v0, 0xe700
/* 3D74DC E00DA29C AC620000 */  sw        $v0, ($v1)
/* 3D74E0 E00DA2A0 AC600004 */  sw        $zero, 4($v1)
/* 3D74E4 E00DA2A4 ACA70000 */  sw        $a3, ($a1)
/* 3D74E8 E00DA2A8 8CC30010 */  lw        $v1, 0x10($a2)
/* 3D74EC E00DA2AC 24A20008 */  addiu     $v0, $a1, 8
/* 3D74F0 E00DA2B0 AE620000 */  sw        $v0, ($s3)
/* 3D74F4 E00DA2B4 8C62001C */  lw        $v0, 0x1c($v1)
/* 3D74F8 E00DA2B8 3C038000 */  lui       $v1, 0x8000
/* 3D74FC E00DA2BC 4600A502 */  mul.s     $f20, $f20, $f0
/* 3D7500 E00DA2C0 00000000 */  nop
/* 3D7504 E00DA2C4 00431021 */  addu      $v0, $v0, $v1
/* 3D7508 E00DA2C8 3C03800B */  lui       $v1, %hi(gCameras)
/* 3D750C E00DA2CC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3D7510 E00DA2D0 ACA20004 */  sw        $v0, 4($a1)
/* 3D7514 E00DA2D4 8E450004 */  lw        $a1, 4($s2)
/* 3D7518 E00DA2D8 8E460008 */  lw        $a2, 8($s2)
/* 3D751C E00DA2DC 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3D7520 E00DA2E0 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3D7524 E00DA2E4 8E47000C */  lw        $a3, 0xc($s2)
/* 3D7528 E00DA2E8 00028880 */  sll       $s1, $v0, 2
/* 3D752C E00DA2EC 02228821 */  addu      $s1, $s1, $v0
/* 3D7530 E00DA2F0 00118880 */  sll       $s1, $s1, 2
/* 3D7534 E00DA2F4 02228823 */  subu      $s1, $s1, $v0
/* 3D7538 E00DA2F8 001110C0 */  sll       $v0, $s1, 3
/* 3D753C E00DA2FC 02228821 */  addu      $s1, $s1, $v0
/* 3D7540 E00DA300 001188C0 */  sll       $s1, $s1, 3
/* 3D7544 E00DA304 0C080108 */  jal       shim_guTranslateF
/* 3D7548 E00DA308 02238821 */   addu     $s1, $s1, $v1
/* 3D754C E00DA30C 27B00050 */  addiu     $s0, $sp, 0x50
/* 3D7550 E00DA310 4405A000 */  mfc1      $a1, $f20
/* 3D7554 E00DA314 0200202D */  daddu     $a0, $s0, $zero
/* 3D7558 E00DA318 00A0302D */  daddu     $a2, $a1, $zero
/* 3D755C E00DA31C 0C080110 */  jal       shim_guScaleF
/* 3D7560 E00DA320 00A0382D */   daddu    $a3, $a1, $zero
/* 3D7564 E00DA324 0200202D */  daddu     $a0, $s0, $zero
/* 3D7568 E00DA328 27A50010 */  addiu     $a1, $sp, 0x10
/* 3D756C E00DA32C 0C080114 */  jal       shim_guMtxCatF
/* 3D7570 E00DA330 00A0302D */   daddu    $a2, $a1, $zero
/* 3D7574 E00DA334 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D7578 E00DA338 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3D757C E00DA33C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3D7580 E00DA340 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3D7584 E00DA344 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3D7588 E00DA348 96050000 */  lhu       $a1, ($s0)
/* 3D758C E00DA34C 8E820000 */  lw        $v0, ($s4)
/* 3D7590 E00DA350 00052980 */  sll       $a1, $a1, 6
/* 3D7594 E00DA354 00B62821 */  addu      $a1, $a1, $s6
/* 3D7598 E00DA358 0C080118 */  jal       shim_guMtxF2L
/* 3D759C E00DA35C 00452821 */   addu     $a1, $v0, $a1
/* 3D75A0 E00DA360 3C03DA38 */  lui       $v1, 0xda38
/* 3D75A4 E00DA364 34630002 */  ori       $v1, $v1, 2
/* 3D75A8 E00DA368 3C06DA38 */  lui       $a2, 0xda38
/* 3D75AC E00DA36C 34C60001 */  ori       $a2, $a2, 1
/* 3D75B0 E00DA370 3C092AAA */  lui       $t1, 0x2aaa
/* 3D75B4 E00DA374 3529AAAB */  ori       $t1, $t1, 0xaaab
/* 3D75B8 E00DA378 3C08DE00 */  lui       $t0, 0xde00
/* 3D75BC E00DA37C 32B500FF */  andi      $s5, $s5, 0xff
/* 3D75C0 E00DA380 3C07D838 */  lui       $a3, 0xd838
/* 3D75C4 E00DA384 8E650000 */  lw        $a1, ($s3)
/* 3D75C8 E00DA388 96020000 */  lhu       $v0, ($s0)
/* 3D75CC E00DA38C 00A0202D */  daddu     $a0, $a1, $zero
/* 3D75D0 E00DA390 24A50008 */  addiu     $a1, $a1, 8
/* 3D75D4 E00DA394 AE650000 */  sw        $a1, ($s3)
/* 3D75D8 E00DA398 AC830000 */  sw        $v1, ($a0)
/* 3D75DC E00DA39C 24430001 */  addiu     $v1, $v0, 1
/* 3D75E0 E00DA3A0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D75E4 E00DA3A4 00021180 */  sll       $v0, $v0, 6
/* 3D75E8 E00DA3A8 A6030000 */  sh        $v1, ($s0)
/* 3D75EC E00DA3AC 8E830000 */  lw        $v1, ($s4)
/* 3D75F0 E00DA3B0 00561021 */  addu      $v0, $v0, $s6
/* 3D75F4 E00DA3B4 00621821 */  addu      $v1, $v1, $v0
/* 3D75F8 E00DA3B8 24A20008 */  addiu     $v0, $a1, 8
/* 3D75FC E00DA3BC AC830004 */  sw        $v1, 4($a0)
/* 3D7600 E00DA3C0 AE620000 */  sw        $v0, ($s3)
/* 3D7604 E00DA3C4 24A20010 */  addiu     $v0, $a1, 0x10
/* 3D7608 E00DA3C8 ACA60000 */  sw        $a2, ($a1)
/* 3D760C E00DA3CC AE620000 */  sw        $v0, ($s3)
/* 3D7610 E00DA3D0 8E230204 */  lw        $v1, 0x204($s1)
/* 3D7614 E00DA3D4 3C020900 */  lui       $v0, 0x900
/* 3D7618 E00DA3D8 24420240 */  addiu     $v0, $v0, 0x240
/* 3D761C E00DA3DC ACA2000C */  sw        $v0, 0xc($a1)
/* 3D7620 E00DA3E0 24A20018 */  addiu     $v0, $a1, 0x18
/* 3D7624 E00DA3E4 3C06FA00 */  lui       $a2, 0xfa00
/* 3D7628 E00DA3E8 ACA80008 */  sw        $t0, 8($a1)
/* 3D762C E00DA3EC AE620000 */  sw        $v0, ($s3)
/* 3D7630 E00DA3F0 ACA60010 */  sw        $a2, 0x10($a1)
/* 3D7634 E00DA3F4 ACA30004 */  sw        $v1, 4($a1)
/* 3D7638 E00DA3F8 9242001B */  lbu       $v0, 0x1b($s2)
/* 3D763C E00DA3FC 9244001F */  lbu       $a0, 0x1f($s2)
/* 3D7640 E00DA400 92430023 */  lbu       $v1, 0x23($s2)
/* 3D7644 E00DA404 00021600 */  sll       $v0, $v0, 0x18
/* 3D7648 E00DA408 00042400 */  sll       $a0, $a0, 0x10
/* 3D764C E00DA40C 00441025 */  or        $v0, $v0, $a0
/* 3D7650 E00DA410 00031A00 */  sll       $v1, $v1, 8
/* 3D7654 E00DA414 00431025 */  or        $v0, $v0, $v1
/* 3D7658 E00DA418 00551025 */  or        $v0, $v0, $s5
/* 3D765C E00DA41C ACA20014 */  sw        $v0, 0x14($a1)
/* 3D7660 E00DA420 8E420014 */  lw        $v0, 0x14($s2)
/* 3D7664 E00DA424 34E70002 */  ori       $a3, $a3, 2
/* 3D7668 E00DA428 00022040 */  sll       $a0, $v0, 1
/* 3D766C E00DA42C 00822021 */  addu      $a0, $a0, $v0
/* 3D7670 E00DA430 00890018 */  mult      $a0, $t1
/* 3D7674 E00DA434 24A20020 */  addiu     $v0, $a1, 0x20
/* 3D7678 E00DA438 AE620000 */  sw        $v0, ($s3)
/* 3D767C E00DA43C 000417C3 */  sra       $v0, $a0, 0x1f
/* 3D7680 E00DA440 ACA60018 */  sw        $a2, 0x18($a1)
/* 3D7684 E00DA444 00005010 */  mfhi      $t2
/* 3D7688 E00DA448 000A1883 */  sra       $v1, $t2, 2
/* 3D768C E00DA44C 00621823 */  subu      $v1, $v1, $v0
/* 3D7690 E00DA450 00031040 */  sll       $v0, $v1, 1
/* 3D7694 E00DA454 00431021 */  addu      $v0, $v0, $v1
/* 3D7698 E00DA458 000210C0 */  sll       $v0, $v0, 3
/* 3D769C E00DA45C 00822023 */  subu      $a0, $a0, $v0
/* 3D76A0 E00DA460 3C03E00E */  lui       $v1, %hi(D_E00DA500)
/* 3D76A4 E00DA464 00641821 */  addu      $v1, $v1, $a0
/* 3D76A8 E00DA468 9063A500 */  lbu       $v1, %lo(D_E00DA500)($v1)
/* 3D76AC E00DA46C 3C06E00E */  lui       $a2, %hi(D_E00DA501)
/* 3D76B0 E00DA470 00C43021 */  addu      $a2, $a2, $a0
/* 3D76B4 E00DA474 90C6A501 */  lbu       $a2, %lo(D_E00DA501)($a2)
/* 3D76B8 E00DA478 3C01E00E */  lui       $at, %hi(D_E00DA502)
/* 3D76BC E00DA47C 00240821 */  addu      $at, $at, $a0
/* 3D76C0 E00DA480 9024A502 */  lbu       $a0, %lo(D_E00DA502)($at)
/* 3D76C4 E00DA484 24A20028 */  addiu     $v0, $a1, 0x28
/* 3D76C8 E00DA488 AE620000 */  sw        $v0, ($s3)
/* 3D76CC E00DA48C 3C020900 */  lui       $v0, 0x900
/* 3D76D0 E00DA490 244202E0 */  addiu     $v0, $v0, 0x2e0
/* 3D76D4 E00DA494 ACA20024 */  sw        $v0, 0x24($a1)
/* 3D76D8 E00DA498 24A20030 */  addiu     $v0, $a1, 0x30
/* 3D76DC E00DA49C ACA80020 */  sw        $t0, 0x20($a1)
/* 3D76E0 E00DA4A0 AE620000 */  sw        $v0, ($s3)
/* 3D76E4 E00DA4A4 24020040 */  addiu     $v0, $zero, 0x40
/* 3D76E8 E00DA4A8 ACA70028 */  sw        $a3, 0x28($a1)
/* 3D76EC E00DA4AC ACA2002C */  sw        $v0, 0x2c($a1)
/* 3D76F0 E00DA4B0 00031E00 */  sll       $v1, $v1, 0x18
/* 3D76F4 E00DA4B4 00063400 */  sll       $a2, $a2, 0x10
/* 3D76F8 E00DA4B8 00661825 */  or        $v1, $v1, $a2
/* 3D76FC E00DA4BC 00042200 */  sll       $a0, $a0, 8
/* 3D7700 E00DA4C0 00641825 */  or        $v1, $v1, $a0
/* 3D7704 E00DA4C4 00751825 */  or        $v1, $v1, $s5
/* 3D7708 E00DA4C8 ACA3001C */  sw        $v1, 0x1c($a1)
/* 3D770C E00DA4CC 8FBF00AC */  lw        $ra, 0xac($sp)
/* 3D7710 E00DA4D0 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3D7714 E00DA4D4 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 3D7718 E00DA4D8 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 3D771C E00DA4DC 8FB3009C */  lw        $s3, 0x9c($sp)
/* 3D7720 E00DA4E0 8FB20098 */  lw        $s2, 0x98($sp)
/* 3D7724 E00DA4E4 8FB10094 */  lw        $s1, 0x94($sp)
/* 3D7728 E00DA4E8 8FB00090 */  lw        $s0, 0x90($sp)
/* 3D772C E00DA4EC D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 3D7730 E00DA4F0 03E00008 */  jr        $ra
/* 3D7734 E00DA4F4 27BD00B8 */   addiu    $sp, $sp, 0xb8
/* 3D7738 E00DA4F8 00000000 */  nop
/* 3D773C E00DA4FC 00000000 */  nop
