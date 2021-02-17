.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D048C
/* 3D42AC E00D048C 27BDFED8 */  addiu     $sp, $sp, -0x128
/* 3D42B0 E00D0490 3C07DB06 */  lui       $a3, 0xdb06
/* 3D42B4 E00D0494 34E70024 */  ori       $a3, $a3, 0x24
/* 3D42B8 E00D0498 AFA40128 */  sw        $a0, 0x128($sp)
/* 3D42BC E00D049C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D42C0 E00D04A0 AFB000D8 */  sw        $s0, 0xd8($sp)
/* 3D42C4 E00D04A4 3C100001 */  lui       $s0, 1
/* 3D42C8 E00D04A8 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 3D42CC E00D04AC 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3D42D0 E00D04B0 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3D42D4 E00D04B4 36101630 */  ori       $s0, $s0, 0x1630
/* 3D42D8 E00D04B8 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 3D42DC E00D04BC AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 3D42E0 E00D04C0 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 3D42E4 E00D04C4 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 3D42E8 E00D04C8 AFB500EC */  sw        $s5, 0xec($sp)
/* 3D42EC E00D04CC AFB400E8 */  sw        $s4, 0xe8($sp)
/* 3D42F0 E00D04D0 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 3D42F4 E00D04D4 AFB100DC */  sw        $s1, 0xdc($sp)
/* 3D42F8 E00D04D8 F7BC0120 */  sdc1      $f28, 0x120($sp)
/* 3D42FC E00D04DC F7BA0118 */  sdc1      $f26, 0x118($sp)
/* 3D4300 E00D04E0 F7B80110 */  sdc1      $f24, 0x110($sp)
/* 3D4304 E00D04E4 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 3D4308 E00D04E8 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 3D430C E00D04EC 8E660000 */  lw        $a2, ($s3)
/* 3D4310 E00D04F0 8FAD0128 */  lw        $t5, 0x128($sp)
/* 3D4314 E00D04F4 4480A000 */  mtc1      $zero, $f20
/* 3D4318 E00D04F8 3C01E00D */  lui       $at, %hi(D_E00D0B40)
/* 3D431C E00D04FC D4200B40 */  ldc1      $f0, %lo(D_E00D0B40)($at)
/* 3D4320 E00D0500 3C013F80 */  lui       $at, 0x3f80
/* 3D4324 E00D0504 4481B000 */  mtc1      $at, $f22
/* 3D4328 E00D0508 00C0182D */  daddu     $v1, $a2, $zero
/* 3D432C E00D050C 24C60008 */  addiu     $a2, $a2, 8
/* 3D4330 E00D0510 8DB1000C */  lw        $s1, 0xc($t5)
/* 3D4334 E00D0514 4405A000 */  mfc1      $a1, $f20
/* 3D4338 E00D0518 96220000 */  lhu       $v0, ($s1)
/* 3D433C E00D051C C624001C */  lwc1      $f4, 0x1c($s1)
/* 3D4340 E00D0520 C6260020 */  lwc1      $f6, 0x20($s1)
/* 3D4344 E00D0524 C6280024 */  lwc1      $f8, 0x24($s1)
/* 3D4348 E00D0528 922D0050 */  lbu       $t5, 0x50($s1)
/* 3D434C E00D052C 00021080 */  sll       $v0, $v0, 2
/* 3D4350 E00D0530 3C08E00D */  lui       $t0, %hi(D_E00D0B10)
/* 3D4354 E00D0534 01024021 */  addu      $t0, $t0, $v0
/* 3D4358 E00D0538 8D080B10 */  lw        $t0, %lo(D_E00D0B10)($t0)
/* 3D435C E00D053C 46002121 */  cvt.d.s   $f4, $f4
/* 3D4360 E00D0540 AFAD00A4 */  sw        $t5, 0xa4($sp)
/* 3D4364 E00D0544 922D0051 */  lbu       $t5, 0x51($s1)
/* 3D4368 E00D0548 46202102 */  mul.d     $f4, $f4, $f0
/* 3D436C E00D054C 00000000 */  nop
/* 3D4370 E00D0550 AFAD00A8 */  sw        $t5, 0xa8($sp)
/* 3D4374 E00D0554 922D0052 */  lbu       $t5, 0x52($s1)
/* 3D4378 E00D0558 3C02E700 */  lui       $v0, 0xe700
/* 3D437C E00D055C AFAD00AC */  sw        $t5, 0xac($sp)
/* 3D4380 E00D0560 922D0053 */  lbu       $t5, 0x53($s1)
/* 3D4384 E00D0564 460031A1 */  cvt.d.s   $f6, $f6
/* 3D4388 E00D0568 AFAD00B0 */  sw        $t5, 0xb0($sp)
/* 3D438C E00D056C 922D0054 */  lbu       $t5, 0x54($s1)
/* 3D4390 E00D0570 46203182 */  mul.d     $f6, $f6, $f0
/* 3D4394 E00D0574 00000000 */  nop
/* 3D4398 E00D0578 AFAD00B4 */  sw        $t5, 0xb4($sp)
/* 3D439C E00D057C 922D0055 */  lbu       $t5, 0x55($s1)
/* 3D43A0 E00D0580 46004221 */  cvt.d.s   $f8, $f8
/* 3D43A4 E00D0584 AFAD00B8 */  sw        $t5, 0xb8($sp)
/* 3D43A8 E00D0588 AC620000 */  sw        $v0, ($v1)
/* 3D43AC E00D058C AC600004 */  sw        $zero, 4($v1)
/* 3D43B0 E00D0590 ACC70000 */  sw        $a3, ($a2)
/* 3D43B4 E00D0594 8FAD0128 */  lw        $t5, 0x128($sp)
/* 3D43B8 E00D0598 46204202 */  mul.d     $f8, $f8, $f0
/* 3D43BC E00D059C 00000000 */  nop
/* 3D43C0 E00D05A0 8DA20010 */  lw        $v0, 0x10($t5)
/* 3D43C4 E00D05A4 4407A000 */  mfc1      $a3, $f20
/* 3D43C8 E00D05A8 8C43001C */  lw        $v1, 0x1c($v0)
/* 3D43CC E00D05AC 3C02DE00 */  lui       $v0, 0xde00
/* 3D43D0 E00D05B0 ACC20008 */  sw        $v0, 8($a2)
/* 3D43D4 E00D05B4 3C028000 */  lui       $v0, 0x8000
/* 3D43D8 E00D05B8 00621821 */  addu      $v1, $v1, $v0
/* 3D43DC E00D05BC ACC30004 */  sw        $v1, 4($a2)
/* 3D43E0 E00D05C0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3D43E4 E00D05C4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3D43E8 E00D05C8 46202720 */  cvt.s.d   $f28, $f4
/* 3D43EC E00D05CC ACC8000C */  sw        $t0, 0xc($a2)
/* 3D43F0 E00D05D0 00031080 */  sll       $v0, $v1, 2
/* 3D43F4 E00D05D4 00431021 */  addu      $v0, $v0, $v1
/* 3D43F8 E00D05D8 00021080 */  sll       $v0, $v0, 2
/* 3D43FC E00D05DC 00431023 */  subu      $v0, $v0, $v1
/* 3D4400 E00D05E0 000218C0 */  sll       $v1, $v0, 3
/* 3D4404 E00D05E4 00431021 */  addu      $v0, $v0, $v1
/* 3D4408 E00D05E8 000210C0 */  sll       $v0, $v0, 3
/* 3D440C E00D05EC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 3D4410 E00D05F0 00220821 */  addu      $at, $at, $v0
/* 3D4414 E00D05F4 C42A1DEC */  lwc1      $f10, %lo(gCameras+0x6C)($at)
/* 3D4418 E00D05F8 24C20008 */  addiu     $v0, $a2, 8
/* 3D441C E00D05FC AE660000 */  sw        $a2, ($s3)
/* 3D4420 E00D0600 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3D4424 E00D0604 C6220004 */  lwc1      $f2, 4($s1)
/* 3D4428 E00D0608 24C60010 */  addiu     $a2, $a2, 0x10
/* 3D442C E00D060C AE620000 */  sw        $v0, ($s3)
/* 3D4430 E00D0610 E7A20014 */  swc1      $f2, 0x14($sp)
/* 3D4434 E00D0614 C6200008 */  lwc1      $f0, 8($s1)
/* 3D4438 E00D0618 46005287 */  neg.s     $f10, $f10
/* 3D443C E00D061C AE660000 */  sw        $a2, ($s3)
/* 3D4440 E00D0620 44065000 */  mfc1      $a2, $f10
/* 3D4444 E00D0624 462036A0 */  cvt.s.d   $f26, $f6
/* 3D4448 E00D0628 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3D444C E00D062C C620000C */  lwc1      $f0, 0xc($s1)
/* 3D4450 E00D0630 46204620 */  cvt.s.d   $f24, $f8
/* 3D4454 E00D0634 0C080180 */  jal       func_E0200600
/* 3D4458 E00D0638 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3D445C E00D063C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D4460 E00D0640 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 3D4464 E00D0644 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 3D4468 E00D0648 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 3D446C E00D064C 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 3D4470 E00D0650 96A50000 */  lhu       $a1, ($s5)
/* 3D4474 E00D0654 8EC20000 */  lw        $v0, ($s6)
/* 3D4478 E00D0658 00052980 */  sll       $a1, $a1, 6
/* 3D447C E00D065C 00B02821 */  addu      $a1, $a1, $s0
/* 3D4480 E00D0660 0C080118 */  jal       func_E0200460
/* 3D4484 E00D0664 00452821 */   addu     $a1, $v0, $a1
/* 3D4488 E00D0668 24140001 */  addiu     $s4, $zero, 1
/* 3D448C E00D066C 3C02DA38 */  lui       $v0, 0xda38
/* 3D4490 E00D0670 8E650000 */  lw        $a1, ($s3)
/* 3D4494 E00D0674 96A40000 */  lhu       $a0, ($s5)
/* 3D4498 E00D0678 00A0302D */  daddu     $a2, $a1, $zero
/* 3D449C E00D067C 24A50008 */  addiu     $a1, $a1, 8
/* 3D44A0 E00D0680 ACC20000 */  sw        $v0, ($a2)
/* 3D44A4 E00D0684 3082FFFF */  andi      $v0, $a0, 0xffff
/* 3D44A8 E00D0688 00021180 */  sll       $v0, $v0, 6
/* 3D44AC E00D068C 00501021 */  addu      $v0, $v0, $s0
/* 3D44B0 E00D0690 00942021 */  addu      $a0, $a0, $s4
/* 3D44B4 E00D0694 8EC30000 */  lw        $v1, ($s6)
/* 3D44B8 E00D0698 00A0B82D */  daddu     $s7, $a1, $zero
/* 3D44BC E00D069C 00621821 */  addu      $v1, $v1, $v0
/* 3D44C0 E00D06A0 ACC30004 */  sw        $v1, 4($a2)
/* 3D44C4 E00D06A4 8E2D0038 */  lw        $t5, 0x38($s1)
/* 3D44C8 E00D06A8 26E30008 */  addiu     $v1, $s7, 8
/* 3D44CC E00D06AC AFAD00A0 */  sw        $t5, 0xa0($sp)
/* 3D44D0 E00D06B0 AE650000 */  sw        $a1, ($s3)
/* 3D44D4 E00D06B4 A6A40000 */  sh        $a0, ($s5)
/* 3D44D8 E00D06B8 AE630000 */  sw        $v1, ($s3)
/* 3D44DC E00D06BC 8FAD00A4 */  lw        $t5, 0xa4($sp)
/* 3D44E0 E00D06C0 AFAD00BC */  sw        $t5, 0xbc($sp)
/* 3D44E4 E00D06C4 8FAD00A8 */  lw        $t5, 0xa8($sp)
/* 3D44E8 E00D06C8 AFAD00C0 */  sw        $t5, 0xc0($sp)
/* 3D44EC E00D06CC 8FAD00AC */  lw        $t5, 0xac($sp)
/* 3D44F0 E00D06D0 AFAD00C4 */  sw        $t5, 0xc4($sp)
/* 3D44F4 E00D06D4 8FAD00B0 */  lw        $t5, 0xb0($sp)
/* 3D44F8 E00D06D8 AFAD00C8 */  sw        $t5, 0xc8($sp)
/* 3D44FC E00D06DC 8FAD00B4 */  lw        $t5, 0xb4($sp)
/* 3D4500 E00D06E0 AFAD00CC */  sw        $t5, 0xcc($sp)
/* 3D4504 E00D06E4 8FAD00B8 */  lw        $t5, 0xb8($sp)
/* 3D4508 E00D06E8 AFAD00D0 */  sw        $t5, 0xd0($sp)
/* 3D450C E00D06EC 8FAD0128 */  lw        $t5, 0x128($sp)
/* 3D4510 E00D06F0 8DA20008 */  lw        $v0, 8($t5)
/* 3D4514 E00D06F4 26310058 */  addiu     $s1, $s1, 0x58
/* 3D4518 E00D06F8 0282102A */  slt       $v0, $s4, $v0
/* 3D451C E00D06FC 10400087 */  beqz      $v0, .LE00D091C
/* 3D4520 E00D0700 AFA300D4 */   sw       $v1, 0xd4($sp)
/* 3D4524 E00D0704 27B20060 */  addiu     $s2, $sp, 0x60
/* 3D4528 E00D0708 02A0B02D */  daddu     $s6, $s5, $zero
/* 3D452C E00D070C 3C150001 */  lui       $s5, 1
/* 3D4530 E00D0710 36B51630 */  ori       $s5, $s5, 0x1630
/* 3D4534 E00D0714 3C1EF200 */  lui       $fp, 0xf200
/* 3D4538 E00D0718 26300044 */  addiu     $s0, $s1, 0x44
.LE00D071C:
/* 3D453C E00D071C 8E020008 */  lw        $v0, 8($s0)
/* 3D4540 E00D0720 04400078 */  bltz      $v0, .LE00D0904
/* 3D4544 E00D0724 00000000 */   nop
/* 3D4548 E00D0728 8E05FFC0 */  lw        $a1, -0x40($s0)
/* 3D454C E00D072C 8E06FFC4 */  lw        $a2, -0x3c($s0)
/* 3D4550 E00D0730 8E07FFC8 */  lw        $a3, -0x38($s0)
/* 3D4554 E00D0734 0C080108 */  jal       func_E0200420
/* 3D4558 E00D0738 27A40020 */   addiu    $a0, $sp, 0x20
/* 3D455C E00D073C E7B60010 */  swc1      $f22, 0x10($sp)
/* 3D4560 E00D0740 8E05FFF0 */  lw        $a1, -0x10($s0)
/* 3D4564 E00D0744 4406A000 */  mfc1      $a2, $f20
/* 3D4568 E00D0748 4407A000 */  mfc1      $a3, $f20
/* 3D456C E00D074C 0C080104 */  jal       func_E0200410
/* 3D4570 E00D0750 0240202D */   daddu    $a0, $s2, $zero
/* 3D4574 E00D0754 0240202D */  daddu     $a0, $s2, $zero
/* 3D4578 E00D0758 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D457C E00D075C 0C080114 */  jal       func_E0200450
/* 3D4580 E00D0760 00A0302D */   daddu    $a2, $a1, $zero
/* 3D4584 E00D0764 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 3D4588 E00D0768 461C0002 */  mul.s     $f0, $f0, $f28
/* 3D458C E00D076C 00000000 */  nop
/* 3D4590 E00D0770 44050000 */  mfc1      $a1, $f0
/* 3D4594 E00D0774 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 3D4598 E00D0778 461A0002 */  mul.s     $f0, $f0, $f26
/* 3D459C E00D077C 00000000 */  nop
/* 3D45A0 E00D0780 44060000 */  mfc1      $a2, $f0
/* 3D45A4 E00D0784 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 3D45A8 E00D0788 46180002 */  mul.s     $f0, $f0, $f24
/* 3D45AC E00D078C 00000000 */  nop
/* 3D45B0 E00D0790 44070000 */  mfc1      $a3, $f0
/* 3D45B4 E00D0794 0C080110 */  jal       func_E0200440
/* 3D45B8 E00D0798 0240202D */   daddu    $a0, $s2, $zero
/* 3D45BC E00D079C 0240202D */  daddu     $a0, $s2, $zero
/* 3D45C0 E00D07A0 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D45C4 E00D07A4 0C080114 */  jal       func_E0200450
/* 3D45C8 E00D07A8 00A0302D */   daddu    $a2, $a1, $zero
/* 3D45CC E00D07AC E7B40010 */  swc1      $f20, 0x10($sp)
/* 3D45D0 E00D07B0 8E05FFEC */  lw        $a1, -0x14($s0)
/* 3D45D4 E00D07B4 4406A000 */  mfc1      $a2, $f20
/* 3D45D8 E00D07B8 4407B000 */  mfc1      $a3, $f22
/* 3D45DC E00D07BC 0C080104 */  jal       func_E0200410
/* 3D45E0 E00D07C0 0240202D */   daddu    $a0, $s2, $zero
/* 3D45E4 E00D07C4 0240202D */  daddu     $a0, $s2, $zero
/* 3D45E8 E00D07C8 27A50020 */  addiu     $a1, $sp, 0x20
/* 3D45EC E00D07CC 0C080114 */  jal       func_E0200450
/* 3D45F0 E00D07D0 00A0302D */   daddu    $a2, $a1, $zero
/* 3D45F4 E00D07D4 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D45F8 E00D07D8 96C50000 */  lhu       $a1, ($s6)
/* 3D45FC E00D07DC 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3D4600 E00D07E0 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3D4604 E00D07E4 00052980 */  sll       $a1, $a1, 6
/* 3D4608 E00D07E8 00B52821 */  addu      $a1, $a1, $s5
/* 3D460C E00D07EC 0C080118 */  jal       func_E0200460
/* 3D4610 E00D07F0 00452821 */   addu     $a1, $v0, $a1
/* 3D4614 E00D07F4 3C06000F */  lui       $a2, 0xf
/* 3D4618 E00D07F8 34C6C000 */  ori       $a2, $a2, 0xc000
/* 3D461C E00D07FC 3C080107 */  lui       $t0, 0x107
/* 3D4620 E00D0800 3508C000 */  ori       $t0, $t0, 0xc000
/* 3D4624 E00D0804 3C07D838 */  lui       $a3, 0xd838
/* 3D4628 E00D0808 34E70002 */  ori       $a3, $a3, 2
/* 3D462C E00D080C 8E630000 */  lw        $v1, ($s3)
/* 3D4630 E00D0810 C600FFF8 */  lwc1      $f0, -8($s0)
/* 3D4634 E00D0814 0060282D */  daddu     $a1, $v1, $zero
/* 3D4638 E00D0818 24630008 */  addiu     $v1, $v1, 8
/* 3D463C E00D081C 4600030D */  trunc.w.s $f12, $f0
/* 3D4640 E00D0820 44026000 */  mfc1      $v0, $f12
/* 3D4644 E00D0824 00000000 */  nop
/* 3D4648 E00D0828 30420FFF */  andi      $v0, $v0, 0xfff
/* 3D464C E00D082C 005E1025 */  or        $v0, $v0, $fp
/* 3D4650 E00D0830 AE630000 */  sw        $v1, ($s3)
/* 3D4654 E00D0834 ACA20000 */  sw        $v0, ($a1)
/* 3D4658 E00D0838 24620008 */  addiu     $v0, $v1, 8
/* 3D465C E00D083C AE620000 */  sw        $v0, ($s3)
/* 3D4660 E00D0840 96C40000 */  lhu       $a0, ($s6)
/* 3D4664 E00D0844 24620010 */  addiu     $v0, $v1, 0x10
/* 3D4668 E00D0848 AE620000 */  sw        $v0, ($s3)
/* 3D466C E00D084C 24820001 */  addiu     $v0, $a0, 1
/* 3D4670 E00D0850 A6C20000 */  sh        $v0, ($s6)
/* 3D4674 E00D0854 24620018 */  addiu     $v0, $v1, 0x18
/* 3D4678 E00D0858 3084FFFF */  andi      $a0, $a0, 0xffff
/* 3D467C E00D085C 00042180 */  sll       $a0, $a0, 6
/* 3D4680 E00D0860 C600FFF8 */  lwc1      $f0, -8($s0)
/* 3D4684 E00D0864 00952021 */  addu      $a0, $a0, $s5
/* 3D4688 E00D0868 AE620000 */  sw        $v0, ($s3)
/* 3D468C E00D086C 4600030D */  trunc.w.s $f12, $f0
/* 3D4690 E00D0870 44026000 */  mfc1      $v0, $f12
/* 3D4694 E00D0874 00000000 */  nop
/* 3D4698 E00D0878 2442007C */  addiu     $v0, $v0, 0x7c
/* 3D469C E00D087C 30420FFF */  andi      $v0, $v0, 0xfff
/* 3D46A0 E00D0880 00461025 */  or        $v0, $v0, $a2
/* 3D46A4 E00D0884 ACA20004 */  sw        $v0, 4($a1)
/* 3D46A8 E00D0888 C6000000 */  lwc1      $f0, ($s0)
/* 3D46AC E00D088C 24620020 */  addiu     $v0, $v1, 0x20
/* 3D46B0 E00D0890 AE620000 */  sw        $v0, ($s3)
/* 3D46B4 E00D0894 4600030D */  trunc.w.s $f12, $f0
/* 3D46B8 E00D0898 44026000 */  mfc1      $v0, $f12
/* 3D46BC E00D089C 00000000 */  nop
/* 3D46C0 E00D08A0 30420FFF */  andi      $v0, $v0, 0xfff
/* 3D46C4 E00D08A4 005E1025 */  or        $v0, $v0, $fp
/* 3D46C8 E00D08A8 AC620000 */  sw        $v0, ($v1)
/* 3D46CC E00D08AC C6000000 */  lwc1      $f0, ($s0)
/* 3D46D0 E00D08B0 3C02DA38 */  lui       $v0, 0xda38
/* 3D46D4 E00D08B4 AC620008 */  sw        $v0, 8($v1)
/* 3D46D8 E00D08B8 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3D46DC E00D08BC 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3D46E0 E00D08C0 3C0D0900 */  lui       $t5, 0x900
/* 3D46E4 E00D08C4 25AD0940 */  addiu     $t5, $t5, 0x940
/* 3D46E8 E00D08C8 AC6D0014 */  sw        $t5, 0x14($v1)
/* 3D46EC E00D08CC AC670018 */  sw        $a3, 0x18($v1)
/* 3D46F0 E00D08D0 00441021 */  addu      $v0, $v0, $a0
/* 3D46F4 E00D08D4 AC62000C */  sw        $v0, 0xc($v1)
/* 3D46F8 E00D08D8 3C02DE00 */  lui       $v0, 0xde00
/* 3D46FC E00D08DC AC620010 */  sw        $v0, 0x10($v1)
/* 3D4700 E00D08E0 24020040 */  addiu     $v0, $zero, 0x40
/* 3D4704 E00D08E4 AC62001C */  sw        $v0, 0x1c($v1)
/* 3D4708 E00D08E8 4600030D */  trunc.w.s $f12, $f0
/* 3D470C E00D08EC 44026000 */  mfc1      $v0, $f12
/* 3D4710 E00D08F0 00000000 */  nop
/* 3D4714 E00D08F4 2442007C */  addiu     $v0, $v0, 0x7c
/* 3D4718 E00D08F8 30420FFF */  andi      $v0, $v0, 0xfff
/* 3D471C E00D08FC 00481025 */  or        $v0, $v0, $t0
/* 3D4720 E00D0900 AC620004 */  sw        $v0, 4($v1)
.LE00D0904:
/* 3D4724 E00D0904 8FAD0128 */  lw        $t5, 0x128($sp)
/* 3D4728 E00D0908 26940001 */  addiu     $s4, $s4, 1
/* 3D472C E00D090C 8DA20008 */  lw        $v0, 8($t5)
/* 3D4730 E00D0910 0282102A */  slt       $v0, $s4, $v0
/* 3D4734 E00D0914 1440FF81 */  bnez      $v0, .LE00D071C
/* 3D4738 E00D0918 26100058 */   addiu    $s0, $s0, 0x58
.LE00D091C:
/* 3D473C E00D091C 3C0AD9FF */  lui       $t2, 0xd9ff
/* 3D4740 E00D0920 354AF9FF */  ori       $t2, $t2, 0xf9ff
/* 3D4744 E00D0924 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 3D4748 E00D0928 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 3D474C E00D092C 3C02DF00 */  lui       $v0, 0xdf00
/* 3D4750 E00D0930 8CA30000 */  lw        $v1, ($a1)
/* 3D4754 E00D0934 3C09FA00 */  lui       $t1, 0xfa00
/* 3D4758 E00D0938 0060202D */  daddu     $a0, $v1, $zero
/* 3D475C E00D093C 24630008 */  addiu     $v1, $v1, 8
/* 3D4760 E00D0940 ACA30000 */  sw        $v1, ($a1)
/* 3D4764 E00D0944 AC820000 */  sw        $v0, ($a0)
/* 3D4768 E00D0948 3C02DE01 */  lui       $v0, 0xde01
/* 3D476C E00D094C AC800004 */  sw        $zero, 4($a0)
/* 3D4770 E00D0950 AEE20000 */  sw        $v0, ($s7)
/* 3D4774 E00D0954 24620008 */  addiu     $v0, $v1, 8
/* 3D4778 E00D0958 AEE30004 */  sw        $v1, 4($s7)
/* 3D477C E00D095C ACA20000 */  sw        $v0, ($a1)
/* 3D4780 E00D0960 AC690000 */  sw        $t1, ($v1)
/* 3D4784 E00D0964 8FAD00BC */  lw        $t5, 0xbc($sp)
/* 3D4788 E00D0968 3C0BD9FF */  lui       $t3, 0xd9ff
/* 3D478C E00D096C 000D1600 */  sll       $v0, $t5, 0x18
/* 3D4790 E00D0970 8FAD00C0 */  lw        $t5, 0xc0($sp)
/* 3D4794 E00D0974 3C07FB00 */  lui       $a3, 0xfb00
/* 3D4798 E00D0978 000D2400 */  sll       $a0, $t5, 0x10
/* 3D479C E00D097C 8FAD00C4 */  lw        $t5, 0xc4($sp)
/* 3D47A0 E00D0980 00441025 */  or        $v0, $v0, $a0
/* 3D47A4 E00D0984 000D2200 */  sll       $a0, $t5, 8
/* 3D47A8 E00D0988 8FAD00A0 */  lw        $t5, 0xa0($sp)
/* 3D47AC E00D098C 00441025 */  or        $v0, $v0, $a0
/* 3D47B0 E00D0990 31A800FF */  andi      $t0, $t5, 0xff
/* 3D47B4 E00D0994 00481025 */  or        $v0, $v0, $t0
/* 3D47B8 E00D0998 AC620004 */  sw        $v0, 4($v1)
/* 3D47BC E00D099C 24620010 */  addiu     $v0, $v1, 0x10
/* 3D47C0 E00D09A0 ACA20000 */  sw        $v0, ($a1)
/* 3D47C4 E00D09A4 AC670008 */  sw        $a3, 8($v1)
/* 3D47C8 E00D09A8 8FAD00C8 */  lw        $t5, 0xc8($sp)
/* 3D47CC E00D09AC 356BFFFF */  ori       $t3, $t3, 0xffff
/* 3D47D0 E00D09B0 000D1600 */  sll       $v0, $t5, 0x18
/* 3D47D4 E00D09B4 8FAD00CC */  lw        $t5, 0xcc($sp)
/* 3D47D8 E00D09B8 3C06DE00 */  lui       $a2, 0xde00
/* 3D47DC E00D09BC 000D2400 */  sll       $a0, $t5, 0x10
/* 3D47E0 E00D09C0 8FAD00D0 */  lw        $t5, 0xd0($sp)
/* 3D47E4 E00D09C4 00441025 */  or        $v0, $v0, $a0
/* 3D47E8 E00D09C8 000D2200 */  sll       $a0, $t5, 8
/* 3D47EC E00D09CC 00441025 */  or        $v0, $v0, $a0
/* 3D47F0 E00D09D0 AC62000C */  sw        $v0, 0xc($v1)
/* 3D47F4 E00D09D4 24620018 */  addiu     $v0, $v1, 0x18
/* 3D47F8 E00D09D8 ACA20000 */  sw        $v0, ($a1)
/* 3D47FC E00D09DC 24620020 */  addiu     $v0, $v1, 0x20
/* 3D4800 E00D09E0 AC6A0010 */  sw        $t2, 0x10($v1)
/* 3D4804 E00D09E4 AC600014 */  sw        $zero, 0x14($v1)
/* 3D4808 E00D09E8 ACA20000 */  sw        $v0, ($a1)
/* 3D480C E00D09EC 24020200 */  addiu     $v0, $zero, 0x200
/* 3D4810 E00D09F0 AC62001C */  sw        $v0, 0x1c($v1)
/* 3D4814 E00D09F4 24620028 */  addiu     $v0, $v1, 0x28
/* 3D4818 E00D09F8 AC6B0018 */  sw        $t3, 0x18($v1)
/* 3D481C E00D09FC ACA20000 */  sw        $v0, ($a1)
/* 3D4820 E00D0A00 AC660020 */  sw        $a2, 0x20($v1)
/* 3D4824 E00D0A04 8FAD00D4 */  lw        $t5, 0xd4($sp)
/* 3D4828 E00D0A08 24620030 */  addiu     $v0, $v1, 0x30
/* 3D482C E00D0A0C AC6D0024 */  sw        $t5, 0x24($v1)
/* 3D4830 E00D0A10 ACA20000 */  sw        $v0, ($a1)
/* 3D4834 E00D0A14 AC690028 */  sw        $t1, 0x28($v1)
/* 3D4838 E00D0A18 8FAD00A4 */  lw        $t5, 0xa4($sp)
/* 3D483C E00D0A1C 000D1600 */  sll       $v0, $t5, 0x18
/* 3D4840 E00D0A20 8FAD00A8 */  lw        $t5, 0xa8($sp)
/* 3D4844 E00D0A24 000D2400 */  sll       $a0, $t5, 0x10
/* 3D4848 E00D0A28 8FAD00AC */  lw        $t5, 0xac($sp)
/* 3D484C E00D0A2C 00441025 */  or        $v0, $v0, $a0
/* 3D4850 E00D0A30 000D2200 */  sll       $a0, $t5, 8
/* 3D4854 E00D0A34 00441025 */  or        $v0, $v0, $a0
/* 3D4858 E00D0A38 00481025 */  or        $v0, $v0, $t0
/* 3D485C E00D0A3C AC62002C */  sw        $v0, 0x2c($v1)
/* 3D4860 E00D0A40 24620038 */  addiu     $v0, $v1, 0x38
/* 3D4864 E00D0A44 ACA20000 */  sw        $v0, ($a1)
/* 3D4868 E00D0A48 AC670030 */  sw        $a3, 0x30($v1)
/* 3D486C E00D0A4C 8FAD00B0 */  lw        $t5, 0xb0($sp)
/* 3D4870 E00D0A50 3C0CD838 */  lui       $t4, 0xd838
/* 3D4874 E00D0A54 000D1600 */  sll       $v0, $t5, 0x18
/* 3D4878 E00D0A58 8FAD00B4 */  lw        $t5, 0xb4($sp)
/* 3D487C E00D0A5C 358C0002 */  ori       $t4, $t4, 2
/* 3D4880 E00D0A60 000D2400 */  sll       $a0, $t5, 0x10
/* 3D4884 E00D0A64 8FAD00B8 */  lw        $t5, 0xb8($sp)
/* 3D4888 E00D0A68 00441025 */  or        $v0, $v0, $a0
/* 3D488C E00D0A6C 000D2200 */  sll       $a0, $t5, 8
/* 3D4890 E00D0A70 00441025 */  or        $v0, $v0, $a0
/* 3D4894 E00D0A74 AC620034 */  sw        $v0, 0x34($v1)
/* 3D4898 E00D0A78 24620040 */  addiu     $v0, $v1, 0x40
/* 3D489C E00D0A7C ACA20000 */  sw        $v0, ($a1)
/* 3D48A0 E00D0A80 24620048 */  addiu     $v0, $v1, 0x48
/* 3D48A4 E00D0A84 AC6A0038 */  sw        $t2, 0x38($v1)
/* 3D48A8 E00D0A88 AC60003C */  sw        $zero, 0x3c($v1)
/* 3D48AC E00D0A8C ACA20000 */  sw        $v0, ($a1)
/* 3D48B0 E00D0A90 24020400 */  addiu     $v0, $zero, 0x400
/* 3D48B4 E00D0A94 AC620044 */  sw        $v0, 0x44($v1)
/* 3D48B8 E00D0A98 24620050 */  addiu     $v0, $v1, 0x50
/* 3D48BC E00D0A9C AC6B0040 */  sw        $t3, 0x40($v1)
/* 3D48C0 E00D0AA0 ACA20000 */  sw        $v0, ($a1)
/* 3D48C4 E00D0AA4 AC660048 */  sw        $a2, 0x48($v1)
/* 3D48C8 E00D0AA8 8FAD00D4 */  lw        $t5, 0xd4($sp)
/* 3D48CC E00D0AAC 24620058 */  addiu     $v0, $v1, 0x58
/* 3D48D0 E00D0AB0 AC6D004C */  sw        $t5, 0x4c($v1)
/* 3D48D4 E00D0AB4 ACA20000 */  sw        $v0, ($a1)
/* 3D48D8 E00D0AB8 24020040 */  addiu     $v0, $zero, 0x40
/* 3D48DC E00D0ABC AC6C0050 */  sw        $t4, 0x50($v1)
/* 3D48E0 E00D0AC0 AC620054 */  sw        $v0, 0x54($v1)
/* 3D48E4 E00D0AC4 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 3D48E8 E00D0AC8 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 3D48EC E00D0ACC 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 3D48F0 E00D0AD0 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 3D48F4 E00D0AD4 8FB500EC */  lw        $s5, 0xec($sp)
/* 3D48F8 E00D0AD8 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 3D48FC E00D0ADC 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 3D4900 E00D0AE0 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 3D4904 E00D0AE4 8FB100DC */  lw        $s1, 0xdc($sp)
/* 3D4908 E00D0AE8 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 3D490C E00D0AEC D7BC0120 */  ldc1      $f28, 0x120($sp)
/* 3D4910 E00D0AF0 D7BA0118 */  ldc1      $f26, 0x118($sp)
/* 3D4914 E00D0AF4 D7B80110 */  ldc1      $f24, 0x110($sp)
/* 3D4918 E00D0AF8 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 3D491C E00D0AFC D7B40100 */  ldc1      $f20, 0x100($sp)
/* 3D4920 E00D0B00 03E00008 */  jr        $ra
/* 3D4924 E00D0B04 27BD0128 */   addiu    $sp, $sp, 0x128
/* 3D4928 E00D0B08 00000000 */  nop
/* 3D492C E00D0B0C 00000000 */  nop
