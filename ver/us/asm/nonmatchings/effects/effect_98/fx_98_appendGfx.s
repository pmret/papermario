.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_98_appendGfx
/* 3CB0F8 E00C4308 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 3CB0FC E00C430C 0080302D */  daddu     $a2, $a0, $zero
/* 3CB100 E00C4310 3C07DB06 */  lui       $a3, 0xdb06
/* 3CB104 E00C4314 34E70024 */  ori       $a3, $a3, 0x24
/* 3CB108 E00C4318 27A40020 */  addiu     $a0, $sp, 0x20
/* 3CB10C E00C431C 3C0F0001 */  lui       $t7, 1
/* 3CB110 E00C4320 35EF1630 */  ori       $t7, $t7, 0x1630
/* 3CB114 E00C4324 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3CB118 E00C4328 0000B02D */  daddu     $s6, $zero, $zero
/* 3CB11C E00C432C AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3CB120 E00C4330 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 3CB124 E00C4334 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 3CB128 E00C4338 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3CB12C E00C433C 02C0A82D */  daddu     $s5, $s6, $zero
/* 3CB130 E00C4340 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3CB134 E00C4344 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3CB138 E00C4348 AFB700CC */  sw        $s7, 0xcc($sp)
/* 3CB13C E00C434C AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3CB140 E00C4350 AFB300BC */  sw        $s3, 0xbc($sp)
/* 3CB144 E00C4354 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3CB148 E00C4358 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3CB14C E00C435C F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 3CB150 E00C4360 AFAF00A8 */  sw        $t7, 0xa8($sp)
/* 3CB154 E00C4364 8E450000 */  lw        $a1, ($s2)
/* 3CB158 E00C4368 8CDE000C */  lw        $fp, 0xc($a2)
/* 3CB15C E00C436C 00A0182D */  daddu     $v1, $a1, $zero
/* 3CB160 E00C4370 24A50008 */  addiu     $a1, $a1, 8
/* 3CB164 E00C4374 AE450000 */  sw        $a1, ($s2)
/* 3CB168 E00C4378 8FD40014 */  lw        $s4, 0x14($fp)
/* 3CB16C E00C437C 8FCF0024 */  lw        $t7, 0x24($fp)
/* 3CB170 E00C4380 3C02E700 */  lui       $v0, 0xe700
/* 3CB174 E00C4384 AFAF00A0 */  sw        $t7, 0xa0($sp)
/* 3CB178 E00C4388 AC620000 */  sw        $v0, ($v1)
/* 3CB17C E00C438C AC600004 */  sw        $zero, 4($v1)
/* 3CB180 E00C4390 ACA70000 */  sw        $a3, ($a1)
/* 3CB184 E00C4394 8CC30010 */  lw        $v1, 0x10($a2)
/* 3CB188 E00C4398 24A20008 */  addiu     $v0, $a1, 8
/* 3CB18C E00C439C AE420000 */  sw        $v0, ($s2)
/* 3CB190 E00C43A0 8C62001C */  lw        $v0, 0x1c($v1)
/* 3CB194 E00C43A4 3C038000 */  lui       $v1, 0x8000
/* 3CB198 E00C43A8 00431021 */  addu      $v0, $v0, $v1
/* 3CB19C E00C43AC 3C03800B */  lui       $v1, %hi(gCameras)
/* 3CB1A0 E00C43B0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3CB1A4 E00C43B4 ACA20004 */  sw        $v0, 4($a1)
/* 3CB1A8 E00C43B8 8FC50004 */  lw        $a1, 4($fp)
/* 3CB1AC E00C43BC 8FC60008 */  lw        $a2, 8($fp)
/* 3CB1B0 E00C43C0 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3CB1B4 E00C43C4 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3CB1B8 E00C43C8 8FC7000C */  lw        $a3, 0xc($fp)
/* 3CB1BC E00C43CC 00028080 */  sll       $s0, $v0, 2
/* 3CB1C0 E00C43D0 02028021 */  addu      $s0, $s0, $v0
/* 3CB1C4 E00C43D4 00108080 */  sll       $s0, $s0, 2
/* 3CB1C8 E00C43D8 02028023 */  subu      $s0, $s0, $v0
/* 3CB1CC E00C43DC 001010C0 */  sll       $v0, $s0, 3
/* 3CB1D0 E00C43E0 02028021 */  addu      $s0, $s0, $v0
/* 3CB1D4 E00C43E4 001080C0 */  sll       $s0, $s0, 3
/* 3CB1D8 E00C43E8 0C080108 */  jal       shim_guTranslateF
/* 3CB1DC E00C43EC 02038021 */   addu     $s0, $s0, $v1
/* 3CB1E0 E00C43F0 27B10060 */  addiu     $s1, $sp, 0x60
/* 3CB1E4 E00C43F4 8FC50028 */  lw        $a1, 0x28($fp)
/* 3CB1E8 E00C43F8 0220202D */  daddu     $a0, $s1, $zero
/* 3CB1EC E00C43FC 00A0302D */  daddu     $a2, $a1, $zero
/* 3CB1F0 E00C4400 0C080110 */  jal       shim_guScaleF
/* 3CB1F4 E00C4404 00A0382D */   daddu    $a3, $a1, $zero
/* 3CB1F8 E00C4408 0220202D */  daddu     $a0, $s1, $zero
/* 3CB1FC E00C440C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3CB200 E00C4410 0C080114 */  jal       shim_guMtxCatF
/* 3CB204 E00C4414 00A0302D */   daddu    $a2, $a1, $zero
/* 3CB208 E00C4418 27A40020 */  addiu     $a0, $sp, 0x20
/* 3CB20C E00C441C 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3CB210 E00C4420 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3CB214 E00C4424 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 3CB218 E00C4428 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 3CB21C E00C442C 96250000 */  lhu       $a1, ($s1)
/* 3CB220 E00C4430 8E620000 */  lw        $v0, ($s3)
/* 3CB224 E00C4434 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 3CB228 E00C4438 00052980 */  sll       $a1, $a1, 6
/* 3CB22C E00C443C 00AF2821 */  addu      $a1, $a1, $t7
/* 3CB230 E00C4440 0C080118 */  jal       shim_guMtxF2L
/* 3CB234 E00C4444 00452821 */   addu     $a1, $v0, $a1
/* 3CB238 E00C4448 3C03DA38 */  lui       $v1, 0xda38
/* 3CB23C E00C444C 34630002 */  ori       $v1, $v1, 2
/* 3CB240 E00C4450 3C06DA38 */  lui       $a2, 0xda38
/* 3CB244 E00C4454 34C60001 */  ori       $a2, $a2, 1
/* 3CB248 E00C4458 00141080 */  sll       $v0, $s4, 2
/* 3CB24C E00C445C 00541021 */  addu      $v0, $v0, $s4
/* 3CB250 E00C4460 0002A040 */  sll       $s4, $v0, 1
/* 3CB254 E00C4464 0280B82D */  daddu     $s7, $s4, $zero
/* 3CB258 E00C4468 8E440000 */  lw        $a0, ($s2)
/* 3CB25C E00C446C 96220000 */  lhu       $v0, ($s1)
/* 3CB260 E00C4470 0080282D */  daddu     $a1, $a0, $zero
/* 3CB264 E00C4474 24840008 */  addiu     $a0, $a0, 8
/* 3CB268 E00C4478 248F0020 */  addiu     $t7, $a0, 0x20
/* 3CB26C E00C447C AFAF00A4 */  sw        $t7, 0xa4($sp)
/* 3CB270 E00C4480 AE440000 */  sw        $a0, ($s2)
/* 3CB274 E00C4484 ACA30000 */  sw        $v1, ($a1)
/* 3CB278 E00C4488 24430001 */  addiu     $v1, $v0, 1
/* 3CB27C E00C448C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3CB280 E00C4490 00021180 */  sll       $v0, $v0, 6
/* 3CB284 E00C4494 A6230000 */  sh        $v1, ($s1)
/* 3CB288 E00C4498 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 3CB28C E00C449C 8E630000 */  lw        $v1, ($s3)
/* 3CB290 E00C44A0 004F1021 */  addu      $v0, $v0, $t7
/* 3CB294 E00C44A4 00621821 */  addu      $v1, $v1, $v0
/* 3CB298 E00C44A8 24820008 */  addiu     $v0, $a0, 8
/* 3CB29C E00C44AC ACA30004 */  sw        $v1, 4($a1)
/* 3CB2A0 E00C44B0 AE420000 */  sw        $v0, ($s2)
/* 3CB2A4 E00C44B4 24820010 */  addiu     $v0, $a0, 0x10
/* 3CB2A8 E00C44B8 AC860000 */  sw        $a2, ($a0)
/* 3CB2AC E00C44BC AE420000 */  sw        $v0, ($s2)
/* 3CB2B0 E00C44C0 8E030204 */  lw        $v1, 0x204($s0)
/* 3CB2B4 E00C44C4 3C02DE00 */  lui       $v0, 0xde00
/* 3CB2B8 E00C44C8 AC820008 */  sw        $v0, 8($a0)
/* 3CB2BC E00C44CC 3C020900 */  lui       $v0, 0x900
/* 3CB2C0 E00C44D0 24421000 */  addiu     $v0, $v0, 0x1000
/* 3CB2C4 E00C44D4 AC82000C */  sw        $v0, 0xc($a0)
/* 3CB2C8 E00C44D8 24820018 */  addiu     $v0, $a0, 0x18
/* 3CB2CC E00C44DC AE420000 */  sw        $v0, ($s2)
/* 3CB2D0 E00C44E0 3C02FB00 */  lui       $v0, 0xfb00
/* 3CB2D4 E00C44E4 AC820010 */  sw        $v0, 0x10($a0)
/* 3CB2D8 E00C44E8 AC830004 */  sw        $v1, 4($a0)
/* 3CB2DC E00C44EC 93C3002F */  lbu       $v1, 0x2f($fp)
/* 3CB2E0 E00C44F0 3C02DE01 */  lui       $v0, 0xde01
/* 3CB2E4 E00C44F4 AC820018 */  sw        $v0, 0x18($a0)
/* 3CB2E8 E00C44F8 24820220 */  addiu     $v0, $a0, 0x220
/* 3CB2EC E00C44FC AC82001C */  sw        $v0, 0x1c($a0)
/* 3CB2F0 E00C4500 AE420000 */  sw        $v0, ($s2)
/* 3CB2F4 E00C4504 AC830014 */  sw        $v1, 0x14($a0)
.LE00C4508:
/* 3CB2F8 E00C4508 00168140 */  sll       $s0, $s6, 5
/* 3CB2FC E00C450C 44976000 */  mtc1      $s7, $f12
/* 3CB300 E00C4510 00000000 */  nop
/* 3CB304 E00C4514 46806320 */  cvt.s.w   $f12, $f12
/* 3CB308 E00C4518 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 3CB30C E00C451C C7D40030 */  lwc1      $f20, 0x30($fp)
/* 3CB310 E00C4520 0C080140 */  jal       shim_sin_deg
/* 3CB314 E00C4524 01F08021 */   addu     $s0, $t7, $s0
/* 3CB318 E00C4528 3C0143FA */  lui       $at, 0x43fa
/* 3CB31C E00C452C 44811000 */  mtc1      $at, $f2
/* 3CB320 E00C4530 00000000 */  nop
/* 3CB324 E00C4534 46020002 */  mul.s     $f0, $f0, $f2
/* 3CB328 E00C4538 00000000 */  nop
/* 3CB32C E00C453C 46140002 */  mul.s     $f0, $f0, $f20
/* 3CB330 E00C4540 00000000 */  nop
/* 3CB334 E00C4544 44946000 */  mtc1      $s4, $f12
/* 3CB338 E00C4548 00000000 */  nop
/* 3CB33C E00C454C 46806320 */  cvt.s.w   $f12, $f12
/* 3CB340 E00C4550 4600010D */  trunc.w.s $f4, $f0
/* 3CB344 E00C4554 44112000 */  mfc1      $s1, $f4
/* 3CB348 E00C4558 0C080140 */  jal       shim_sin_deg
/* 3CB34C E00C455C 26940006 */   addiu    $s4, $s4, 6
/* 3CB350 E00C4560 3C014348 */  lui       $at, 0x4348
/* 3CB354 E00C4564 44811000 */  mtc1      $at, $f2
/* 3CB358 E00C4568 26F7003C */  addiu     $s7, $s7, 0x3c
/* 3CB35C E00C456C 46020002 */  mul.s     $f0, $f0, $f2
/* 3CB360 E00C4570 00000000 */  nop
/* 3CB364 E00C4574 001619C0 */  sll       $v1, $s6, 7
/* 3CB368 E00C4578 26D60001 */  addiu     $s6, $s6, 1
/* 3CB36C E00C457C 2622F380 */  addiu     $v0, $s1, -0xc80
/* 3CB370 E00C4580 26310C80 */  addiu     $s1, $s1, 0xc80
/* 3CB374 E00C4584 46140002 */  mul.s     $f0, $f0, $f20
/* 3CB378 E00C4588 00000000 */  nop
/* 3CB37C E00C458C A6020000 */  sh        $v0, ($s0)
/* 3CB380 E00C4590 A6000004 */  sh        $zero, 4($s0)
/* 3CB384 E00C4594 A6000008 */  sh        $zero, 8($s0)
/* 3CB388 E00C4598 A603000A */  sh        $v1, 0xa($s0)
/* 3CB38C E00C459C 4600010D */  trunc.w.s $f4, $f0
/* 3CB390 E00C45A0 44022000 */  mfc1      $v0, $f4
/* 3CB394 E00C45A4 00000000 */  nop
/* 3CB398 E00C45A8 02A21021 */  addu      $v0, $s5, $v0
/* 3CB39C E00C45AC 2442F448 */  addiu     $v0, $v0, -0xbb8
/* 3CB3A0 E00C45B0 A6020002 */  sh        $v0, 2($s0)
/* 3CB3A4 E00C45B4 26100010 */  addiu     $s0, $s0, 0x10
/* 3CB3A8 E00C45B8 26B50190 */  addiu     $s5, $s5, 0x190
/* 3CB3AC E00C45BC A6020002 */  sh        $v0, 2($s0)
/* 3CB3B0 E00C45C0 24020800 */  addiu     $v0, $zero, 0x800
/* 3CB3B4 E00C45C4 A6020008 */  sh        $v0, 8($s0)
/* 3CB3B8 E00C45C8 2AC20010 */  slti      $v0, $s6, 0x10
/* 3CB3BC E00C45CC A6110000 */  sh        $s1, ($s0)
/* 3CB3C0 E00C45D0 A6000004 */  sh        $zero, 4($s0)
/* 3CB3C4 E00C45D4 1440FFCC */  bnez      $v0, .LE00C4508
/* 3CB3C8 E00C45D8 A603000A */   sh       $v1, 0xa($s0)
/* 3CB3CC E00C45DC 27A40020 */  addiu     $a0, $sp, 0x20
/* 3CB3D0 E00C45E0 3C130001 */  lui       $s3, 1
/* 3CB3D4 E00C45E4 36731630 */  ori       $s3, $s3, 0x1630
/* 3CB3D8 E00C45E8 0000B02D */  daddu     $s6, $zero, $zero
/* 3CB3DC E00C45EC 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 3CB3E0 E00C45F0 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 3CB3E4 E00C45F4 3C013C23 */  lui       $at, 0x3c23
/* 3CB3E8 E00C45F8 3421D70A */  ori       $at, $at, 0xd70a
/* 3CB3EC E00C45FC 44810000 */  mtc1      $at, $f0
/* 3CB3F0 E00C4600 8E020000 */  lw        $v0, ($s0)
/* 3CB3F4 E00C4604 3C03DE01 */  lui       $v1, 0xde01
/* 3CB3F8 E00C4608 AC430000 */  sw        $v1, ($v0)
/* 3CB3FC E00C460C 244300A0 */  addiu     $v1, $v0, 0xa0
/* 3CB400 E00C4610 AC430004 */  sw        $v1, 4($v0)
/* 3CB404 E00C4614 24420008 */  addiu     $v0, $v0, 8
/* 3CB408 E00C4618 44050000 */  mfc1      $a1, $f0
/* 3CB40C E00C461C 0040A82D */  daddu     $s5, $v0, $zero
/* 3CB410 E00C4620 AE020000 */  sw        $v0, ($s0)
/* 3CB414 E00C4624 00A0302D */  daddu     $a2, $a1, $zero
/* 3CB418 E00C4628 0C080110 */  jal       shim_guScaleF
/* 3CB41C E00C462C 00A0382D */   daddu    $a3, $a1, $zero
/* 3CB420 E00C4630 27A40020 */  addiu     $a0, $sp, 0x20
/* 3CB424 E00C4634 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3CB428 E00C4638 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3CB42C E00C463C 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3CB430 E00C4640 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3CB434 E00C4644 96250000 */  lhu       $a1, ($s1)
/* 3CB438 E00C4648 8E420000 */  lw        $v0, ($s2)
/* 3CB43C E00C464C 00052980 */  sll       $a1, $a1, 6
/* 3CB440 E00C4650 00B32821 */  addu      $a1, $a1, $s3
/* 3CB444 E00C4654 0C080118 */  jal       shim_guMtxF2L
/* 3CB448 E00C4658 00452821 */   addu     $a1, $v0, $a1
/* 3CB44C E00C465C 3C060102 */  lui       $a2, 0x102
/* 3CB450 E00C4660 34C60040 */  ori       $a2, $a2, 0x40
/* 3CB454 E00C4664 3C0B0600 */  lui       $t3, 0x600
/* 3CB458 E00C4668 240A0001 */  addiu     $t2, $zero, 1
/* 3CB45C E00C466C 3C0E0606 */  lui       $t6, 0x606
/* 3CB460 E00C4670 35CE0402 */  ori       $t6, $t6, 0x402
/* 3CB464 E00C4674 3C0D0002 */  lui       $t5, 2
/* 3CB468 E00C4678 35AD0406 */  ori       $t5, $t5, 0x406
/* 3CB46C E00C467C 3C0C0006 */  lui       $t4, 6
/* 3CB470 E00C4680 358C0804 */  ori       $t4, $t4, 0x804
/* 3CB474 E00C4684 24080004 */  addiu     $t0, $zero, 4
/* 3CB478 E00C4688 8E040000 */  lw        $a0, ($s0)
/* 3CB47C E00C468C 24090006 */  addiu     $t1, $zero, 6
/* 3CB480 E00C4690 0080282D */  daddu     $a1, $a0, $zero
/* 3CB484 E00C4694 24840008 */  addiu     $a0, $a0, 8
/* 3CB488 E00C4698 AE040000 */  sw        $a0, ($s0)
/* 3CB48C E00C469C 96220000 */  lhu       $v0, ($s1)
/* 3CB490 E00C46A0 3C03DA38 */  lui       $v1, 0xda38
/* 3CB494 E00C46A4 ACA30000 */  sw        $v1, ($a1)
/* 3CB498 E00C46A8 004A1821 */  addu      $v1, $v0, $t2
/* 3CB49C E00C46AC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3CB4A0 E00C46B0 01221004 */  sllv      $v0, $v0, $t1
/* 3CB4A4 E00C46B4 A6230000 */  sh        $v1, ($s1)
/* 3CB4A8 E00C46B8 8E430000 */  lw        $v1, ($s2)
/* 3CB4AC E00C46BC 00531021 */  addu      $v0, $v0, $s3
/* 3CB4B0 E00C46C0 00621821 */  addu      $v1, $v1, $v0
/* 3CB4B4 E00C46C4 24820008 */  addiu     $v0, $a0, 8
/* 3CB4B8 E00C46C8 ACA30004 */  sw        $v1, 4($a1)
/* 3CB4BC E00C46CC AE020000 */  sw        $v0, ($s0)
/* 3CB4C0 E00C46D0 AC860000 */  sw        $a2, ($a0)
/* 3CB4C4 E00C46D4 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 3CB4C8 E00C46D8 24070002 */  addiu     $a3, $zero, 2
/* 3CB4CC E00C46DC AC8F0004 */  sw        $t7, 4($a0)
.LE00C46E0:
/* 3CB4D0 E00C46E0 8E040000 */  lw        $a0, ($s0)
/* 3CB4D4 E00C46E4 00162840 */  sll       $a1, $s6, 1
/* 3CB4D8 E00C46E8 24820008 */  addiu     $v0, $a0, 8
/* 3CB4DC E00C46EC 14A00004 */  bnez      $a1, .LE00C4700
/* 3CB4E0 E00C46F0 AE020000 */   sw       $v0, ($s0)
/* 3CB4E4 E00C46F4 00161440 */  sll       $v0, $s6, 0x11
/* 3CB4E8 E00C46F8 080311CA */  j         .LE00C4728
/* 3CB4EC E00C46FC 34420402 */   ori      $v0, $v0, 0x402
.LE00C4700:
/* 3CB4F0 E00C4700 14AA0003 */  bne       $a1, $t2, .LE00C4710
/* 3CB4F4 E00C4704 30E200FF */   andi     $v0, $a3, 0xff
/* 3CB4F8 E00C4708 080311CC */  j         .LE00C4730
/* 3CB4FC E00C470C AC8E0000 */   sw       $t6, ($a0)
.LE00C4710:
/* 3CB500 E00C4710 00021400 */  sll       $v0, $v0, 0x10
/* 3CB504 E00C4714 00161A80 */  sll       $v1, $s6, 0xa
/* 3CB508 E00C4718 3063FC00 */  andi      $v1, $v1, 0xfc00
/* 3CB50C E00C471C 00431025 */  or        $v0, $v0, $v1
/* 3CB510 E00C4720 310300FF */  andi      $v1, $t0, 0xff
/* 3CB514 E00C4724 00431025 */  or        $v0, $v0, $v1
.LE00C4728:
/* 3CB518 E00C4728 004B1025 */  or        $v0, $v0, $t3
/* 3CB51C E00C472C AC820000 */  sw        $v0, ($a0)
.LE00C4730:
/* 3CB520 E00C4730 14A00003 */  bnez      $a1, .LE00C4740
/* 3CB524 E00C4734 00000000 */   nop
/* 3CB528 E00C4738 080311DB */  j         .LE00C476C
/* 3CB52C E00C473C AC8D0004 */   sw       $t5, 4($a0)
.LE00C4740:
/* 3CB530 E00C4740 14AA0003 */  bne       $a1, $t2, .LE00C4750
/* 3CB534 E00C4744 312200FF */   andi     $v0, $t1, 0xff
/* 3CB538 E00C4748 080311DB */  j         .LE00C476C
/* 3CB53C E00C474C AC8C0004 */   sw       $t4, 4($a0)
.LE00C4750:
/* 3CB540 E00C4750 00021400 */  sll       $v0, $v0, 0x10
/* 3CB544 E00C4754 30E300FF */  andi      $v1, $a3, 0xff
/* 3CB548 E00C4758 00031A00 */  sll       $v1, $v1, 8
/* 3CB54C E00C475C 00431025 */  or        $v0, $v0, $v1
/* 3CB550 E00C4760 310300FF */  andi      $v1, $t0, 0xff
/* 3CB554 E00C4764 00431025 */  or        $v0, $v0, $v1
/* 3CB558 E00C4768 AC820004 */  sw        $v0, 4($a0)
.LE00C476C:
/* 3CB55C E00C476C 25080004 */  addiu     $t0, $t0, 4
/* 3CB560 E00C4770 24E70004 */  addiu     $a3, $a3, 4
/* 3CB564 E00C4774 26D60001 */  addiu     $s6, $s6, 1
/* 3CB568 E00C4778 2AC2000F */  slti      $v0, $s6, 0xf
/* 3CB56C E00C477C 1440FFD8 */  bnez      $v0, .LE00C46E0
/* 3CB570 E00C4780 25290004 */   addiu    $t1, $t1, 4
/* 3CB574 E00C4784 3C03D838 */  lui       $v1, 0xd838
/* 3CB578 E00C4788 34630002 */  ori       $v1, $v1, 2
/* 3CB57C E00C478C 0000B02D */  daddu     $s6, $zero, $zero
/* 3CB580 E00C4790 3C17E00C */  lui       $s7, %hi(D_E00C49D0)
/* 3CB584 E00C4794 26F749D0 */  addiu     $s7, $s7, %lo(D_E00C49D0)
/* 3CB588 E00C4798 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3CB58C E00C479C 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3CB590 E00C47A0 3C138007 */  lui       $s3, %hi(gMatrixListPos)
/* 3CB594 E00C47A4 267341F0 */  addiu     $s3, $s3, %lo(gMatrixListPos)
/* 3CB598 E00C47A8 3C120001 */  lui       $s2, 1
/* 3CB59C E00C47AC 36521630 */  ori       $s2, $s2, 0x1630
/* 3CB5A0 E00C47B0 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3CB5A4 E00C47B4 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3CB5A8 E00C47B8 0040882D */  daddu     $s1, $v0, $zero
/* 3CB5AC E00C47BC 8E220000 */  lw        $v0, ($s1)
/* 3CB5B0 E00C47C0 03C0802D */  daddu     $s0, $fp, $zero
/* 3CB5B4 E00C47C4 0040202D */  daddu     $a0, $v0, $zero
/* 3CB5B8 E00C47C8 24420008 */  addiu     $v0, $v0, 8
/* 3CB5BC E00C47CC AE220000 */  sw        $v0, ($s1)
/* 3CB5C0 E00C47D0 AC830000 */  sw        $v1, ($a0)
/* 3CB5C4 E00C47D4 24030040 */  addiu     $v1, $zero, 0x40
/* 3CB5C8 E00C47D8 AC830004 */  sw        $v1, 4($a0)
/* 3CB5CC E00C47DC 24430008 */  addiu     $v1, $v0, 8
/* 3CB5D0 E00C47E0 AE230000 */  sw        $v1, ($s1)
/* 3CB5D4 E00C47E4 3C03DF00 */  lui       $v1, 0xdf00
/* 3CB5D8 E00C47E8 AC430000 */  sw        $v1, ($v0)
/* 3CB5DC E00C47EC AC400004 */  sw        $zero, 4($v0)
.LE00C47F0:
/* 3CB5E0 E00C47F0 06C10002 */  bgez      $s6, .LE00C47FC
/* 3CB5E4 E00C47F4 02C0102D */   daddu    $v0, $s6, $zero
/* 3CB5E8 E00C47F8 26C20003 */  addiu     $v0, $s6, 3
.LE00C47FC:
/* 3CB5EC E00C47FC 00021083 */  sra       $v0, $v0, 2
/* 3CB5F0 E00C4800 00021080 */  sll       $v0, $v0, 2
/* 3CB5F4 E00C4804 02C21023 */  subu      $v0, $s6, $v0
/* 3CB5F8 E00C4808 00571021 */  addu      $v0, $v0, $s7
/* 3CB5FC E00C480C 90420000 */  lbu       $v0, ($v0)
/* 3CB600 E00C4810 3C01E00C */  lui       $at, %hi(D_E00C4A98)
/* 3CB604 E00C4814 D4224A98 */  ldc1      $f2, %lo(D_E00C4A98)($at)
/* 3CB608 E00C4818 44820000 */  mtc1      $v0, $f0
/* 3CB60C E00C481C 00000000 */  nop
/* 3CB610 E00C4820 46800021 */  cvt.d.w   $f0, $f0
/* 3CB614 E00C4824 46220002 */  mul.d     $f0, $f0, $f2
/* 3CB618 E00C4828 00000000 */  nop
/* 3CB61C E00C482C 46200020 */  cvt.s.d   $f0, $f0
/* 3CB620 E00C4830 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3CB624 E00C4834 C6000034 */  lwc1      $f0, 0x34($s0)
/* 3CB628 E00C4838 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3CB62C E00C483C C600005C */  lwc1      $f0, 0x5c($s0)
/* 3CB630 E00C4840 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3CB634 E00C4844 C6000084 */  lwc1      $f0, 0x84($s0)
/* 3CB638 E00C4848 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 3CB63C E00C484C 8E0500AC */  lw        $a1, 0xac($s0)
/* 3CB640 E00C4850 8E0600D4 */  lw        $a2, 0xd4($s0)
/* 3CB644 E00C4854 8E0700FC */  lw        $a3, 0xfc($s0)
/* 3CB648 E00C4858 0C080180 */  jal       shim_guPositionF
/* 3CB64C E00C485C 27A40020 */   addiu    $a0, $sp, 0x20
/* 3CB650 E00C4860 27A40020 */  addiu     $a0, $sp, 0x20
/* 3CB654 E00C4864 96650000 */  lhu       $a1, ($s3)
/* 3CB658 E00C4868 8E820000 */  lw        $v0, ($s4)
/* 3CB65C E00C486C 00052980 */  sll       $a1, $a1, 6
/* 3CB660 E00C4870 00B22821 */  addu      $a1, $a1, $s2
/* 3CB664 E00C4874 0C080118 */  jal       shim_guMtxF2L
/* 3CB668 E00C4878 00452821 */   addu     $a1, $v0, $a1
/* 3CB66C E00C487C 3C088080 */  lui       $t0, 0x8080
/* 3CB670 E00C4880 35088081 */  ori       $t0, $t0, 0x8081
/* 3CB674 E00C4884 3C0AD838 */  lui       $t2, 0xd838
/* 3CB678 E00C4888 3C02DA38 */  lui       $v0, 0xda38
/* 3CB67C E00C488C 8E240000 */  lw        $a0, ($s1)
/* 3CB680 E00C4890 96660000 */  lhu       $a2, ($s3)
/* 3CB684 E00C4894 0080282D */  daddu     $a1, $a0, $zero
/* 3CB688 E00C4898 24840008 */  addiu     $a0, $a0, 8
/* 3CB68C E00C489C ACA20000 */  sw        $v0, ($a1)
/* 3CB690 E00C48A0 30C2FFFF */  andi      $v0, $a2, 0xffff
/* 3CB694 E00C48A4 00021180 */  sll       $v0, $v0, 6
/* 3CB698 E00C48A8 00521021 */  addu      $v0, $v0, $s2
/* 3CB69C E00C48AC 8E830000 */  lw        $v1, ($s4)
/* 3CB6A0 E00C48B0 24C60001 */  addiu     $a2, $a2, 1
/* 3CB6A4 E00C48B4 00621821 */  addu      $v1, $v1, $v0
/* 3CB6A8 E00C48B8 3C02FA00 */  lui       $v0, 0xfa00
/* 3CB6AC E00C48BC ACA30004 */  sw        $v1, 4($a1)
/* 3CB6B0 E00C48C0 AC820000 */  sw        $v0, ($a0)
/* 3CB6B4 E00C48C4 8E050124 */  lw        $a1, 0x124($s0)
/* 3CB6B8 E00C48C8 24820008 */  addiu     $v0, $a0, 8
/* 3CB6BC E00C48CC AE240000 */  sw        $a0, ($s1)
/* 3CB6C0 E00C48D0 A6660000 */  sh        $a2, ($s3)
/* 3CB6C4 E00C48D4 AE220000 */  sw        $v0, ($s1)
/* 3CB6C8 E00C48D8 3C03E00C */  lui       $v1, %hi(D_E00C49D4)
/* 3CB6CC E00C48DC 00761821 */  addu      $v1, $v1, $s6
/* 3CB6D0 E00C48E0 906349D4 */  lbu       $v1, %lo(D_E00C49D4)($v1)
/* 3CB6D4 E00C48E4 3C06E00C */  lui       $a2, %hi(D_E00C49E8)
/* 3CB6D8 E00C48E8 00D63021 */  addu      $a2, $a2, $s6
/* 3CB6DC E00C48EC 90C649E8 */  lbu       $a2, %lo(D_E00C49E8)($a2)
/* 3CB6E0 E00C48F0 3C07E00C */  lui       $a3, %hi(D_E00C49FC)
/* 3CB6E4 E00C48F4 00F63821 */  addu      $a3, $a3, $s6
/* 3CB6E8 E00C48F8 90E749FC */  lbu       $a3, %lo(D_E00C49FC)($a3)
/* 3CB6EC E00C48FC 24820010 */  addiu     $v0, $a0, 0x10
/* 3CB6F0 E00C4900 AE220000 */  sw        $v0, ($s1)
/* 3CB6F4 E00C4904 3C02DE00 */  lui       $v0, 0xde00
/* 3CB6F8 E00C4908 AC820008 */  sw        $v0, 8($a0)
/* 3CB6FC E00C490C 24820018 */  addiu     $v0, $a0, 0x18
/* 3CB700 E00C4910 AC95000C */  sw        $s5, 0xc($a0)
/* 3CB704 E00C4914 AE220000 */  sw        $v0, ($s1)
/* 3CB708 E00C4918 8FAF00A0 */  lw        $t7, 0xa0($sp)
/* 3CB70C E00C491C 354A0002 */  ori       $t2, $t2, 2
/* 3CB710 E00C4920 01E50018 */  mult      $t7, $a1
/* 3CB714 E00C4924 24090040 */  addiu     $t1, $zero, 0x40
/* 3CB718 E00C4928 26100004 */  addiu     $s0, $s0, 4
/* 3CB71C E00C492C 26D60001 */  addiu     $s6, $s6, 1
/* 3CB720 E00C4930 AC8A0010 */  sw        $t2, 0x10($a0)
/* 3CB724 E00C4934 00002812 */  mflo      $a1
/* 3CB728 E00C4938 AC890014 */  sw        $t1, 0x14($a0)
/* 3CB72C E00C493C 00031E00 */  sll       $v1, $v1, 0x18
/* 3CB730 E00C4940 00A80018 */  mult      $a1, $t0
/* 3CB734 E00C4944 00063400 */  sll       $a2, $a2, 0x10
/* 3CB738 E00C4948 00661825 */  or        $v1, $v1, $a2
/* 3CB73C E00C494C 00073A00 */  sll       $a3, $a3, 8
/* 3CB740 E00C4950 00671825 */  or        $v1, $v1, $a3
/* 3CB744 E00C4954 00001010 */  mfhi      $v0
/* 3CB748 E00C4958 00451021 */  addu      $v0, $v0, $a1
/* 3CB74C E00C495C 000211C3 */  sra       $v0, $v0, 7
/* 3CB750 E00C4960 00052FC3 */  sra       $a1, $a1, 0x1f
/* 3CB754 E00C4964 00451023 */  subu      $v0, $v0, $a1
/* 3CB758 E00C4968 304200FF */  andi      $v0, $v0, 0xff
/* 3CB75C E00C496C 00621825 */  or        $v1, $v1, $v0
/* 3CB760 E00C4970 2AC2000A */  slti      $v0, $s6, 0xa
/* 3CB764 E00C4974 1440FF9E */  bnez      $v0, .LE00C47F0
/* 3CB768 E00C4978 AC830004 */   sw       $v1, 4($a0)
/* 3CB76C E00C497C 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3CB770 E00C4980 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3CB774 E00C4984 8C430000 */  lw        $v1, ($v0)
/* 3CB778 E00C4988 0060202D */  daddu     $a0, $v1, $zero
/* 3CB77C E00C498C 24630008 */  addiu     $v1, $v1, 8
/* 3CB780 E00C4990 AC430000 */  sw        $v1, ($v0)
/* 3CB784 E00C4994 AC8A0000 */  sw        $t2, ($a0)
/* 3CB788 E00C4998 AC890004 */  sw        $t1, 4($a0)
/* 3CB78C E00C499C 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3CB790 E00C49A0 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3CB794 E00C49A4 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3CB798 E00C49A8 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3CB79C E00C49AC 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3CB7A0 E00C49B0 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3CB7A4 E00C49B4 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3CB7A8 E00C49B8 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3CB7AC E00C49BC 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3CB7B0 E00C49C0 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3CB7B4 E00C49C4 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 3CB7B8 E00C49C8 03E00008 */  jr        $ra
/* 3CB7BC E00C49CC 27BD00E0 */   addiu    $sp, $sp, 0xe0
