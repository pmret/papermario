.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241E30_AD5EC0
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_8024032C_AD43BC
/* AD43BC 8024032C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* AD43C0 80240330 AFB7004C */  sw        $s7, 0x4c($sp)
/* AD43C4 80240334 0080B82D */  daddu     $s7, $a0, $zero
/* AD43C8 80240338 AFBF0054 */  sw        $ra, 0x54($sp)
/* AD43CC 8024033C AFBE0050 */  sw        $fp, 0x50($sp)
/* AD43D0 80240340 AFB60048 */  sw        $s6, 0x48($sp)
/* AD43D4 80240344 AFB50044 */  sw        $s5, 0x44($sp)
/* AD43D8 80240348 AFB40040 */  sw        $s4, 0x40($sp)
/* AD43DC 8024034C AFB3003C */  sw        $s3, 0x3c($sp)
/* AD43E0 80240350 AFB20038 */  sw        $s2, 0x38($sp)
/* AD43E4 80240354 AFB10034 */  sw        $s1, 0x34($sp)
/* AD43E8 80240358 AFB00030 */  sw        $s0, 0x30($sp)
/* AD43EC 8024035C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* AD43F0 80240360 F7B80068 */  sdc1      $f24, 0x68($sp)
/* AD43F4 80240364 F7B60060 */  sdc1      $f22, 0x60($sp)
/* AD43F8 80240368 F7B40058 */  sdc1      $f20, 0x58($sp)
/* AD43FC 8024036C 8EE20148 */  lw        $v0, 0x148($s7)
/* AD4400 80240370 0C00EABB */  jal       get_npc_unsafe
/* AD4404 80240374 84440008 */   lh       $a0, 8($v0)
/* AD4408 80240378 27B50020 */  addiu     $s5, $sp, 0x20
/* AD440C 8024037C 02A0202D */  daddu     $a0, $s5, $zero
/* AD4410 80240380 0040882D */  daddu     $s1, $v0, $zero
/* AD4414 80240384 27B40024 */  addiu     $s4, $sp, 0x24
/* AD4418 80240388 8EE3000C */  lw        $v1, 0xc($s7)
/* AD441C 8024038C 3C0641F0 */  lui       $a2, 0x41f0
/* AD4420 80240390 8E27000C */  lw        $a3, 0xc($s1)
/* AD4424 80240394 C6200038 */  lwc1      $f0, 0x38($s1)
/* AD4428 80240398 C6220040 */  lwc1      $f2, 0x40($s1)
/* AD442C 8024039C 8C7E0000 */  lw        $fp, ($v1)
/* AD4430 802403A0 24630004 */  addiu     $v1, $v1, 4
/* AD4434 802403A4 C4740000 */  lwc1      $f20, ($v1)
/* AD4438 802403A8 4680A520 */  cvt.s.w   $f20, $f20
/* AD443C 802403AC 24630004 */  addiu     $v1, $v1, 4
/* AD4440 802403B0 C4760000 */  lwc1      $f22, ($v1)
/* AD4444 802403B4 4680B5A0 */  cvt.s.w   $f22, $f22
/* AD4448 802403B8 24630004 */  addiu     $v1, $v1, 4
/* AD444C 802403BC C4780000 */  lwc1      $f24, ($v1)
/* AD4450 802403C0 4680C620 */  cvt.s.w   $f24, $f24
/* AD4454 802403C4 24630004 */  addiu     $v1, $v1, 4
/* AD4458 802403C8 C47A0000 */  lwc1      $f26, ($v1)
/* AD445C 802403CC 4680D6A0 */  cvt.s.w   $f26, $f26
/* AD4460 802403D0 24630004 */  addiu     $v1, $v1, 4
/* AD4464 802403D4 8C760000 */  lw        $s6, ($v1)
/* AD4468 802403D8 8C700004 */  lw        $s0, 4($v1)
/* AD446C 802403DC 0280282D */  daddu     $a1, $s4, $zero
/* AD4470 802403E0 E7A00020 */  swc1      $f0, 0x20($sp)
/* AD4474 802403E4 0C00A7E7 */  jal       add_vec2D_polar
/* AD4478 802403E8 E7A20024 */   swc1     $f2, 0x24($sp)
/* AD447C 802403EC 3C038015 */  lui       $v1, %hi(D_80151328)
/* AD4480 802403F0 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* AD4484 802403F4 C7A00020 */  lwc1      $f0, 0x20($sp)
/* AD4488 802403F8 3C0141A0 */  lui       $at, 0x41a0
/* AD448C 802403FC 44811000 */  mtc1      $at, $f2
/* AD4490 80240400 00101040 */  sll       $v0, $s0, 1
/* AD4494 80240404 00501021 */  addu      $v0, $v0, $s0
/* AD4498 80240408 000210C0 */  sll       $v0, $v0, 3
/* AD449C 8024040C 24420004 */  addiu     $v0, $v0, 4
/* AD44A0 80240410 00621821 */  addu      $v1, $v1, $v0
/* AD44A4 80240414 E4600004 */  swc1      $f0, 4($v1)
/* AD44A8 80240418 C620003C */  lwc1      $f0, 0x3c($s1)
/* AD44AC 8024041C 4406A000 */  mfc1      $a2, $f20
/* AD44B0 80240420 46020000 */  add.s     $f0, $f0, $f2
/* AD44B4 80240424 C7A20024 */  lwc1      $f2, 0x24($sp)
/* AD44B8 80240428 02A0202D */  daddu     $a0, $s5, $zero
/* AD44BC 8024042C E462000C */  swc1      $f2, 0xc($v1)
/* AD44C0 80240430 E4600008 */  swc1      $f0, 8($v1)
/* AD44C4 80240434 8E27000C */  lw        $a3, 0xc($s1)
/* AD44C8 80240438 C6200038 */  lwc1      $f0, 0x38($s1)
/* AD44CC 8024043C C6220040 */  lwc1      $f2, 0x40($s1)
/* AD44D0 80240440 0280282D */  daddu     $a1, $s4, $zero
/* AD44D4 80240444 E7A00020 */  swc1      $f0, 0x20($sp)
/* AD44D8 80240448 0C00A7E7 */  jal       add_vec2D_polar
/* AD44DC 8024044C E7A20024 */   swc1     $f2, 0x24($sp)
/* AD44E0 80240450 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AD44E4 80240454 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AD44E8 80240458 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AD44EC 8024045C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AD44F0 80240460 8E460028 */  lw        $a2, 0x28($s2)
/* AD44F4 80240464 8E470030 */  lw        $a3, 0x30($s2)
/* AD44F8 80240468 0C00A7B5 */  jal       dist2D
/* AD44FC 8024046C 0000802D */   daddu    $s0, $zero, $zero
/* AD4500 80240470 4616003E */  c.le.s    $f0, $f22
/* AD4504 80240474 00000000 */  nop
/* AD4508 80240478 45000002 */  bc1f      .L80240484
/* AD450C 8024047C 0240982D */   daddu    $s3, $s2, $zero
/* AD4510 80240480 24100001 */  addiu     $s0, $zero, 1
.L80240484:
/* AD4514 80240484 4600B021 */  cvt.d.s   $f0, $f22
/* AD4518 80240488 46200000 */  add.d     $f0, $f0, $f0
/* AD451C 8024048C 3C014059 */  lui       $at, 0x4059
/* AD4520 80240490 44811800 */  mtc1      $at, $f3
/* AD4524 80240494 44801000 */  mtc1      $zero, $f2
/* AD4528 80240498 3C018024 */  lui       $at, %hi(D_80241E30_AD5EC0)
/* AD452C 8024049C D4241E30 */  ldc1      $f4, %lo(D_80241E30_AD5EC0)($at)
/* AD4530 802404A0 46220003 */  div.d     $f0, $f0, $f2
/* AD4534 802404A4 46240000 */  add.d     $f0, $f0, $f4
/* AD4538 802404A8 C7A20020 */  lwc1      $f2, 0x20($sp)
/* AD453C 802404AC C7A40024 */  lwc1      $f4, 0x24($sp)
/* AD4540 802404B0 44051000 */  mfc1      $a1, $f2
/* AD4544 802404B4 44072000 */  mfc1      $a3, $f4
/* AD4548 802404B8 46200020 */  cvt.s.d   $f0, $f0
/* AD454C 802404BC E7A00010 */  swc1      $f0, 0x10($sp)
/* AD4550 802404C0 8E26003C */  lw        $a2, 0x3c($s1)
/* AD4554 802404C4 0C0900A0 */  jal       func_80240280_AD4310
/* AD4558 802404C8 02C0202D */   daddu    $a0, $s6, $zero
/* AD455C 802404CC 02A0202D */  daddu     $a0, $s5, $zero
/* AD4560 802404D0 4406C000 */  mfc1      $a2, $f24
/* AD4564 802404D4 8E27000C */  lw        $a3, 0xc($s1)
/* AD4568 802404D8 C6200038 */  lwc1      $f0, 0x38($s1)
/* AD456C 802404DC C6220040 */  lwc1      $f2, 0x40($s1)
/* AD4570 802404E0 0280282D */  daddu     $a1, $s4, $zero
/* AD4574 802404E4 E7A00020 */  swc1      $f0, 0x20($sp)
/* AD4578 802404E8 0C00A7E7 */  jal       add_vec2D_polar
/* AD457C 802404EC E7A20024 */   swc1     $f2, 0x24($sp)
/* AD4580 802404F0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AD4584 802404F4 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AD4588 802404F8 8E460028 */  lw        $a2, 0x28($s2)
/* AD458C 802404FC 0C00A7B5 */  jal       dist2D
/* AD4590 80240500 8E470030 */   lw       $a3, 0x30($s2)
/* AD4594 80240504 461A003E */  c.le.s    $f0, $f26
/* AD4598 80240508 00000000 */  nop
/* AD459C 8024050C 45030001 */  bc1tl     .L80240514
/* AD45A0 80240510 36100010 */   ori      $s0, $s0, 0x10
.L80240514:
/* AD45A4 80240514 32020001 */  andi      $v0, $s0, 1
/* AD45A8 80240518 10400026 */  beqz      $v0, .L802405B4
/* AD45AC 8024051C 02E0202D */   daddu    $a0, $s7, $zero
/* AD45B0 80240520 C62C0038 */  lwc1      $f12, 0x38($s1)
/* AD45B4 80240524 C62E0040 */  lwc1      $f14, 0x40($s1)
/* AD45B8 80240528 8E660028 */  lw        $a2, 0x28($s3)
/* AD45BC 8024052C 8E670030 */  lw        $a3, 0x30($s3)
/* AD45C0 80240530 C622003C */  lwc1      $f2, 0x3c($s1)
/* AD45C4 80240534 46006006 */  mov.s     $f0, $f12
/* AD45C8 80240538 46007106 */  mov.s     $f4, $f14
/* AD45CC 8024053C E7A00020 */  swc1      $f0, 0x20($sp)
/* AD45D0 80240540 E7A20028 */  swc1      $f2, 0x28($sp)
/* AD45D4 80240544 0C00A7B5 */  jal       dist2D
/* AD45D8 80240548 E7A40024 */   swc1     $f4, 0x24($sp)
/* AD45DC 8024054C C62C0038 */  lwc1      $f12, 0x38($s1)
/* AD45E0 80240550 C62E0040 */  lwc1      $f14, 0x40($s1)
/* AD45E4 80240554 8E660028 */  lw        $a2, 0x28($s3)
/* AD45E8 80240558 8E670030 */  lw        $a3, 0x30($s3)
/* AD45EC 8024055C 0C00A720 */  jal       atan2
/* AD45F0 80240560 46000506 */   mov.s    $f20, $f0
/* AD45F4 80240564 0000202D */  daddu     $a0, $zero, $zero
/* AD45F8 80240568 02A0282D */  daddu     $a1, $s5, $zero
/* AD45FC 8024056C E7B40010 */  swc1      $f20, 0x10($sp)
/* AD4600 80240570 E7A00014 */  swc1      $f0, 0x14($sp)
/* AD4604 80240574 862200A6 */  lh        $v0, 0xa6($s1)
/* AD4608 80240578 27A60028 */  addiu     $a2, $sp, 0x28
/* AD460C 8024057C 44820000 */  mtc1      $v0, $f0
/* AD4610 80240580 00000000 */  nop
/* AD4614 80240584 46800020 */  cvt.s.w   $f0, $f0
/* AD4618 80240588 E7A00018 */  swc1      $f0, 0x18($sp)
/* AD461C 8024058C 862200A8 */  lh        $v0, 0xa8($s1)
/* AD4620 80240590 0280382D */  daddu     $a3, $s4, $zero
/* AD4624 80240594 44820000 */  mtc1      $v0, $f0
/* AD4628 80240598 00000000 */  nop
/* AD462C 8024059C 46800020 */  cvt.s.w   $f0, $f0
/* AD4630 802405A0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* AD4634 802405A4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* AD4638 802405A8 54400001 */  bnel      $v0, $zero, .L802405B0
/* AD463C 802405AC 0000802D */   daddu    $s0, $zero, $zero
.L802405B0:
/* AD4640 802405B0 02E0202D */  daddu     $a0, $s7, $zero
.L802405B4:
/* AD4644 802405B4 03C0282D */  daddu     $a1, $fp, $zero
/* AD4648 802405B8 0C0B2026 */  jal       evt_set_variable
/* AD464C 802405BC 0200302D */   daddu    $a2, $s0, $zero
/* AD4650 802405C0 8FBF0054 */  lw        $ra, 0x54($sp)
/* AD4654 802405C4 8FBE0050 */  lw        $fp, 0x50($sp)
/* AD4658 802405C8 8FB7004C */  lw        $s7, 0x4c($sp)
/* AD465C 802405CC 8FB60048 */  lw        $s6, 0x48($sp)
/* AD4660 802405D0 8FB50044 */  lw        $s5, 0x44($sp)
/* AD4664 802405D4 8FB40040 */  lw        $s4, 0x40($sp)
/* AD4668 802405D8 8FB3003C */  lw        $s3, 0x3c($sp)
/* AD466C 802405DC 8FB20038 */  lw        $s2, 0x38($sp)
/* AD4670 802405E0 8FB10034 */  lw        $s1, 0x34($sp)
/* AD4674 802405E4 8FB00030 */  lw        $s0, 0x30($sp)
/* AD4678 802405E8 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* AD467C 802405EC D7B80068 */  ldc1      $f24, 0x68($sp)
/* AD4680 802405F0 D7B60060 */  ldc1      $f22, 0x60($sp)
/* AD4684 802405F4 D7B40058 */  ldc1      $f20, 0x58($sp)
/* AD4688 802405F8 24020002 */  addiu     $v0, $zero, 2
/* AD468C 802405FC 03E00008 */  jr        $ra
/* AD4690 80240600 27BD0078 */   addiu    $sp, $sp, 0x78
