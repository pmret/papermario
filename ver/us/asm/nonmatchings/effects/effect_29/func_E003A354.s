.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003A354
/* 34EFD4 E003A354 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 34EFD8 E003A358 AFBE0100 */  sw        $fp, 0x100($sp)
/* 34EFDC E003A35C 0080F02D */  daddu     $fp, $a0, $zero
/* 34EFE0 E003A360 3C07DB06 */  lui       $a3, 0xdb06
/* 34EFE4 E003A364 34E70024 */  ori       $a3, $a3, 0x24
/* 34EFE8 E003A368 27A40018 */  addiu     $a0, $sp, 0x18
/* 34EFEC E003A36C AFB200E8 */  sw        $s2, 0xe8($sp)
/* 34EFF0 E003A370 3C120001 */  lui       $s2, 1
/* 34EFF4 E003A374 AFB300EC */  sw        $s3, 0xec($sp)
/* 34EFF8 E003A378 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 34EFFC E003A37C 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 34F000 E003A380 AFBF0104 */  sw        $ra, 0x104($sp)
/* 34F004 E003A384 AFB700FC */  sw        $s7, 0xfc($sp)
/* 34F008 E003A388 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 34F00C E003A38C AFB500F4 */  sw        $s5, 0xf4($sp)
/* 34F010 E003A390 AFB400F0 */  sw        $s4, 0xf0($sp)
/* 34F014 E003A394 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 34F018 E003A398 AFB000E0 */  sw        $s0, 0xe0($sp)
/* 34F01C E003A39C 8E630000 */  lw        $v1, ($s3)
/* 34F020 E003A3A0 8FD4000C */  lw        $s4, 0xc($fp)
/* 34F024 E003A3A4 0060282D */  daddu     $a1, $v1, $zero
/* 34F028 E003A3A8 24630008 */  addiu     $v1, $v1, 8
/* 34F02C E003A3AC AE630000 */  sw        $v1, ($s3)
/* 34F030 E003A3B0 96970000 */  lhu       $s7, ($s4)
/* 34F034 E003A3B4 24620008 */  addiu     $v0, $v1, 8
/* 34F038 E003A3B8 AE620000 */  sw        $v0, ($s3)
/* 34F03C E003A3BC C6820030 */  lwc1      $f2, 0x30($s4)
/* 34F040 E003A3C0 00171080 */  sll       $v0, $s7, 2
/* 34F044 E003A3C4 3C09E004 */  lui       $t1, %hi(D_E003A800)
/* 34F048 E003A3C8 01224821 */  addu      $t1, $t1, $v0
/* 34F04C E003A3CC 8D29A800 */  lw        $t1, %lo(D_E003A800)($t1)
/* 34F050 E003A3D0 36521630 */  ori       $s2, $s2, 0x1630
/* 34F054 E003A3D4 AFA900D8 */  sw        $t1, 0xd8($sp)
/* 34F058 E003A3D8 3C06E004 */  lui       $a2, %hi(D_E003A80C)
/* 34F05C E003A3DC 00C23021 */  addu      $a2, $a2, $v0
/* 34F060 E003A3E0 8CC6A80C */  lw        $a2, %lo(D_E003A80C)($a2)
/* 34F064 E003A3E4 3C02E700 */  lui       $v0, 0xe700
/* 34F068 E003A3E8 4600110D */  trunc.w.s $f4, $f2
/* 34F06C E003A3EC 44152000 */  mfc1      $s5, $f4
/* 34F070 E003A3F0 00000000 */  nop
/* 34F074 E003A3F4 44950000 */  mtc1      $s5, $f0
/* 34F078 E003A3F8 00000000 */  nop
/* 34F07C E003A3FC 46800020 */  cvt.s.w   $f0, $f0
/* 34F080 E003A400 46001081 */  sub.s     $f2, $f2, $f0
/* 34F084 E003A404 ACA20000 */  sw        $v0, ($a1)
/* 34F088 E003A408 ACA00004 */  sw        $zero, 4($a1)
/* 34F08C E003A40C AC670000 */  sw        $a3, ($v1)
/* 34F090 E003A410 8FC50010 */  lw        $a1, 0x10($fp)
/* 34F094 E003A414 3C014380 */  lui       $at, 0x4380
/* 34F098 E003A418 44810000 */  mtc1      $at, $f0
/* 34F09C E003A41C 24620010 */  addiu     $v0, $v1, 0x10
/* 34F0A0 E003A420 AE620000 */  sw        $v0, ($s3)
/* 34F0A4 E003A424 8CA5001C */  lw        $a1, 0x1c($a1)
/* 34F0A8 E003A428 3C02DE00 */  lui       $v0, 0xde00
/* 34F0AC E003A42C AC620008 */  sw        $v0, 8($v1)
/* 34F0B0 E003A430 3C028000 */  lui       $v0, 0x8000
/* 34F0B4 E003A434 AC66000C */  sw        $a2, 0xc($v1)
/* 34F0B8 E003A438 00A22821 */  addu      $a1, $a1, $v0
/* 34F0BC E003A43C 3AA20007 */  xori      $v0, $s5, 7
/* 34F0C0 E003A440 46001082 */  mul.s     $f2, $f2, $f0
/* 34F0C4 E003A444 00000000 */  nop
/* 34F0C8 E003A448 AC650004 */  sw        $a1, 4($v1)
/* 34F0CC E003A44C 8E850004 */  lw        $a1, 4($s4)
/* 34F0D0 E003A450 8E860008 */  lw        $a2, 8($s4)
/* 34F0D4 E003A454 8E87000C */  lw        $a3, 0xc($s4)
/* 34F0D8 E003A458 2C420001 */  sltiu     $v0, $v0, 1
/* 34F0DC E003A45C 4600110D */  trunc.w.s $f4, $f2
/* 34F0E0 E003A460 44162000 */  mfc1      $s6, $f4
/* 34F0E4 E003A464 0C080108 */  jal       shim_guTranslateF
/* 34F0E8 E003A468 AFA200DC */   sw       $v0, 0xdc($sp)
/* 34F0EC E003A46C 27B00058 */  addiu     $s0, $sp, 0x58
/* 34F0F0 E003A470 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 34F0F4 E003A474 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 34F0F8 E003A478 44800000 */  mtc1      $zero, $f0
/* 34F0FC E003A47C 00031080 */  sll       $v0, $v1, 2
/* 34F100 E003A480 00431021 */  addu      $v0, $v0, $v1
/* 34F104 E003A484 00021080 */  sll       $v0, $v0, 2
/* 34F108 E003A488 00431023 */  subu      $v0, $v0, $v1
/* 34F10C E003A48C 000218C0 */  sll       $v1, $v0, 3
/* 34F110 E003A490 00431021 */  addu      $v0, $v0, $v1
/* 34F114 E003A494 000210C0 */  sll       $v0, $v0, 3
/* 34F118 E003A498 44060000 */  mfc1      $a2, $f0
/* 34F11C E003A49C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 34F120 E003A4A0 00220821 */  addu      $at, $at, $v0
/* 34F124 E003A4A4 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 34F128 E003A4A8 3C073F80 */  lui       $a3, 0x3f80
/* 34F12C E003A4AC 46000007 */  neg.s     $f0, $f0
/* 34F130 E003A4B0 44050000 */  mfc1      $a1, $f0
/* 34F134 E003A4B4 0200202D */  daddu     $a0, $s0, $zero
/* 34F138 E003A4B8 0C080104 */  jal       shim_guRotateF
/* 34F13C E003A4BC AFA60010 */   sw       $a2, 0x10($sp)
/* 34F140 E003A4C0 0200202D */  daddu     $a0, $s0, $zero
/* 34F144 E003A4C4 27A50018 */  addiu     $a1, $sp, 0x18
/* 34F148 E003A4C8 27B00098 */  addiu     $s0, $sp, 0x98
/* 34F14C E003A4CC 0C080114 */  jal       shim_guMtxCatF
/* 34F150 E003A4D0 0200302D */   daddu    $a2, $s0, $zero
/* 34F154 E003A4D4 0200202D */  daddu     $a0, $s0, $zero
/* 34F158 E003A4D8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 34F15C E003A4DC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 34F160 E003A4E0 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 34F164 E003A4E4 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 34F168 E003A4E8 96050000 */  lhu       $a1, ($s0)
/* 34F16C E003A4EC 8E220000 */  lw        $v0, ($s1)
/* 34F170 E003A4F0 00052980 */  sll       $a1, $a1, 6
/* 34F174 E003A4F4 00B22821 */  addu      $a1, $a1, $s2
/* 34F178 E003A4F8 0C080118 */  jal       shim_guMtxF2L
/* 34F17C E003A4FC 00452821 */   addu     $a1, $v0, $a1
/* 34F180 E003A500 8E650000 */  lw        $a1, ($s3)
/* 34F184 E003A504 00A0202D */  daddu     $a0, $a1, $zero
/* 34F188 E003A508 24A50008 */  addiu     $a1, $a1, 8
/* 34F18C E003A50C AE650000 */  sw        $a1, ($s3)
/* 34F190 E003A510 96020000 */  lhu       $v0, ($s0)
/* 34F194 E003A514 3C03DA38 */  lui       $v1, 0xda38
/* 34F198 E003A518 AC830000 */  sw        $v1, ($a0)
/* 34F19C E003A51C 24430001 */  addiu     $v1, $v0, 1
/* 34F1A0 E003A520 3042FFFF */  andi      $v0, $v0, 0xffff
/* 34F1A4 E003A524 00021180 */  sll       $v0, $v0, 6
/* 34F1A8 E003A528 A6030000 */  sh        $v1, ($s0)
/* 34F1AC E003A52C 8E230000 */  lw        $v1, ($s1)
/* 34F1B0 E003A530 00521021 */  addu      $v0, $v0, $s2
/* 34F1B4 E003A534 00621821 */  addu      $v1, $v1, $v0
/* 34F1B8 E003A538 2AE20002 */  slti      $v0, $s7, 2
/* 34F1BC E003A53C 10400009 */  beqz      $v0, .LE003A564
/* 34F1C0 E003A540 AC830004 */   sw       $v1, 4($a0)
/* 34F1C4 E003A544 3C02E6DE */  lui       $v0, 0xe6de
/* 34F1C8 E003A548 3442DE82 */  ori       $v0, $v0, 0xde82
/* 34F1CC E003A54C 24A30008 */  addiu     $v1, $a1, 8
/* 34F1D0 E003A550 AE630000 */  sw        $v1, ($s3)
/* 34F1D4 E003A554 3C03FA00 */  lui       $v1, 0xfa00
/* 34F1D8 E003A558 ACA30000 */  sw        $v1, ($a1)
/* 34F1DC E003A55C 0800E967 */  j         .LE003A59C
/* 34F1E0 E003A560 ACA20004 */   sw       $v0, 4($a1)
.LE003A564:
/* 34F1E4 E003A564 3C03FF28 */  lui       $v1, 0xff28
/* 34F1E8 E003A568 34630AA0 */  ori       $v1, $v1, 0xaa0
/* 34F1EC E003A56C 3C04E200 */  lui       $a0, 0xe200
/* 34F1F0 E003A570 34841E01 */  ori       $a0, $a0, 0x1e01
/* 34F1F4 E003A574 24A20008 */  addiu     $v0, $a1, 8
/* 34F1F8 E003A578 AE620000 */  sw        $v0, ($s3)
/* 34F1FC E003A57C 3C02FA00 */  lui       $v0, 0xfa00
/* 34F200 E003A580 ACA20000 */  sw        $v0, ($a1)
/* 34F204 E003A584 24A20010 */  addiu     $v0, $a1, 0x10
/* 34F208 E003A588 ACA30004 */  sw        $v1, 4($a1)
/* 34F20C E003A58C AE620000 */  sw        $v0, ($s3)
/* 34F210 E003A590 24020003 */  addiu     $v0, $zero, 3
/* 34F214 E003A594 ACA40008 */  sw        $a0, 8($a1)
/* 34F218 E003A598 ACA2000C */  sw        $v0, 0xc($a1)
.LE003A59C:
/* 34F21C E003A59C 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 34F220 E003A5A0 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 34F224 E003A5A4 3C02FB00 */  lui       $v0, 0xfb00
/* 34F228 E003A5A8 3C04F200 */  lui       $a0, 0xf200
/* 34F22C E003A5AC 8D050000 */  lw        $a1, ($t0)
/* 34F230 E003A5B0 00153940 */  sll       $a3, $s5, 5
/* 34F234 E003A5B4 00A0182D */  daddu     $v1, $a1, $zero
/* 34F238 E003A5B8 24A50008 */  addiu     $a1, $a1, 8
/* 34F23C E003A5BC AD050000 */  sw        $a1, ($t0)
/* 34F240 E003A5C0 AC620000 */  sw        $v0, ($v1)
/* 34F244 E003A5C4 32C200FF */  andi      $v0, $s6, 0xff
/* 34F248 E003A5C8 AC620004 */  sw        $v0, 4($v1)
/* 34F24C E003A5CC 24A20008 */  addiu     $v0, $a1, 8
/* 34F250 E003A5D0 AD020000 */  sw        $v0, ($t0)
/* 34F254 E003A5D4 001511C0 */  sll       $v0, $s5, 7
/* 34F258 E003A5D8 30420FFF */  andi      $v0, $v0, 0xfff
/* 34F25C E003A5DC 00021300 */  sll       $v0, $v0, 0xc
/* 34F260 E003A5E0 00441025 */  or        $v0, $v0, $a0
/* 34F264 E003A5E4 ACA20000 */  sw        $v0, ($a1)
/* 34F268 E003A5E8 24E20020 */  addiu     $v0, $a3, 0x20
/* 34F26C E003A5EC 00021080 */  sll       $v0, $v0, 2
/* 34F270 E003A5F0 30420FFF */  andi      $v0, $v0, 0xfff
/* 34F274 E003A5F4 00023300 */  sll       $a2, $v0, 0xc
/* 34F278 E003A5F8 34C20080 */  ori       $v0, $a2, 0x80
/* 34F27C E003A5FC ACA20004 */  sw        $v0, 4($a1)
/* 34F280 E003A600 8FA900DC */  lw        $t1, 0xdc($sp)
/* 34F284 E003A604 1120000E */  beqz      $t1, .LE003A640
/* 34F288 E003A608 0080182D */   daddu    $v1, $a0, $zero
/* 34F28C E003A60C 34630080 */  ori       $v1, $v1, 0x80
/* 34F290 E003A610 3C040100 */  lui       $a0, 0x100
/* 34F294 E003A614 34840100 */  ori       $a0, $a0, 0x100
/* 34F298 E003A618 24A20010 */  addiu     $v0, $a1, 0x10
/* 34F29C E003A61C 00C31825 */  or        $v1, $a2, $v1
/* 34F2A0 E003A620 AD020000 */  sw        $v0, ($t0)
/* 34F2A4 E003A624 24E20040 */  addiu     $v0, $a3, 0x40
/* 34F2A8 E003A628 00021080 */  sll       $v0, $v0, 2
/* 34F2AC E003A62C 30420FFF */  andi      $v0, $v0, 0xfff
/* 34F2B0 E003A630 00021300 */  sll       $v0, $v0, 0xc
/* 34F2B4 E003A634 00441025 */  or        $v0, $v0, $a0
/* 34F2B8 E003A638 0800E99B */  j         .LE003A66C
/* 34F2BC E003A63C ACA30008 */   sw       $v1, 8($a1)
.LE003A640:
/* 34F2C0 E003A640 3C030100 */  lui       $v1, 0x100
/* 34F2C4 E003A644 34630080 */  ori       $v1, $v1, 0x80
/* 34F2C8 E003A648 24A20010 */  addiu     $v0, $a1, 0x10
/* 34F2CC E003A64C AD020000 */  sw        $v0, ($t0)
/* 34F2D0 E003A650 00C41025 */  or        $v0, $a2, $a0
/* 34F2D4 E003A654 ACA20008 */  sw        $v0, 8($a1)
/* 34F2D8 E003A658 24E20040 */  addiu     $v0, $a3, 0x40
/* 34F2DC E003A65C 00021080 */  sll       $v0, $v0, 2
/* 34F2E0 E003A660 30420FFF */  andi      $v0, $v0, 0xfff
/* 34F2E4 E003A664 00021300 */  sll       $v0, $v0, 0xc
/* 34F2E8 E003A668 00431025 */  or        $v0, $v0, $v1
.LE003A66C:
/* 34F2EC E003A66C ACA2000C */  sw        $v0, 0xc($a1)
/* 34F2F0 E003A670 8FC20008 */  lw        $v0, 8($fp)
/* 34F2F4 E003A674 24110001 */  addiu     $s1, $zero, 1
/* 34F2F8 E003A678 0222102A */  slt       $v0, $s1, $v0
/* 34F2FC E003A67C 10400037 */  beqz      $v0, .LE003A75C
/* 34F300 E003A680 26940034 */   addiu    $s4, $s4, 0x34
/* 34F304 E003A684 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 34F308 E003A688 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 34F30C E003A68C 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 34F310 E003A690 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 34F314 E003A694 3C130001 */  lui       $s3, 1
/* 34F318 E003A698 36731630 */  ori       $s3, $s3, 0x1630
/* 34F31C E003A69C 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 34F320 E003A6A0 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 34F324 E003A6A4 2690000C */  addiu     $s0, $s4, 0xc
.LE003A6A8:
/* 34F328 E003A6A8 27A40018 */  addiu     $a0, $sp, 0x18
/* 34F32C E003A6AC 26310001 */  addiu     $s1, $s1, 1
/* 34F330 E003A6B0 8E05FFF8 */  lw        $a1, -8($s0)
/* 34F334 E003A6B4 8E06FFFC */  lw        $a2, -4($s0)
/* 34F338 E003A6B8 8E070000 */  lw        $a3, ($s0)
/* 34F33C E003A6BC 0C080108 */  jal       shim_guTranslateF
/* 34F340 E003A6C0 26100034 */   addiu    $s0, $s0, 0x34
/* 34F344 E003A6C4 27A40018 */  addiu     $a0, $sp, 0x18
/* 34F348 E003A6C8 96A50000 */  lhu       $a1, ($s5)
/* 34F34C E003A6CC 8EC20000 */  lw        $v0, ($s6)
/* 34F350 E003A6D0 00052980 */  sll       $a1, $a1, 6
/* 34F354 E003A6D4 00B32821 */  addu      $a1, $a1, $s3
/* 34F358 E003A6D8 0C080118 */  jal       shim_guMtxF2L
/* 34F35C E003A6DC 00452821 */   addu     $a1, $v0, $a1
/* 34F360 E003A6E0 3C06D838 */  lui       $a2, 0xd838
/* 34F364 E003A6E4 8E440000 */  lw        $a0, ($s2)
/* 34F368 E003A6E8 34C60002 */  ori       $a2, $a2, 2
/* 34F36C E003A6EC 0080282D */  daddu     $a1, $a0, $zero
/* 34F370 E003A6F0 24840008 */  addiu     $a0, $a0, 8
/* 34F374 E003A6F4 AE440000 */  sw        $a0, ($s2)
/* 34F378 E003A6F8 96A20000 */  lhu       $v0, ($s5)
/* 34F37C E003A6FC 3C03DA38 */  lui       $v1, 0xda38
/* 34F380 E003A700 ACA30000 */  sw        $v1, ($a1)
/* 34F384 E003A704 24430001 */  addiu     $v1, $v0, 1
/* 34F388 E003A708 3042FFFF */  andi      $v0, $v0, 0xffff
/* 34F38C E003A70C 00021180 */  sll       $v0, $v0, 6
/* 34F390 E003A710 A6A30000 */  sh        $v1, ($s5)
/* 34F394 E003A714 8EC30000 */  lw        $v1, ($s6)
/* 34F398 E003A718 00531021 */  addu      $v0, $v0, $s3
/* 34F39C E003A71C 00621821 */  addu      $v1, $v1, $v0
/* 34F3A0 E003A720 24820008 */  addiu     $v0, $a0, 8
/* 34F3A4 E003A724 ACA30004 */  sw        $v1, 4($a1)
/* 34F3A8 E003A728 AE420000 */  sw        $v0, ($s2)
/* 34F3AC E003A72C 3C02DE00 */  lui       $v0, 0xde00
/* 34F3B0 E003A730 AC820000 */  sw        $v0, ($a0)
/* 34F3B4 E003A734 8FA900D8 */  lw        $t1, 0xd8($sp)
/* 34F3B8 E003A738 24020040 */  addiu     $v0, $zero, 0x40
/* 34F3BC E003A73C AC860008 */  sw        $a2, 8($a0)
/* 34F3C0 E003A740 AC82000C */  sw        $v0, 0xc($a0)
/* 34F3C4 E003A744 AC890004 */  sw        $t1, 4($a0)
/* 34F3C8 E003A748 8FC20008 */  lw        $v0, 8($fp)
/* 34F3CC E003A74C 24840010 */  addiu     $a0, $a0, 0x10
/* 34F3D0 E003A750 0222102A */  slt       $v0, $s1, $v0
/* 34F3D4 E003A754 1440FFD4 */  bnez      $v0, .LE003A6A8
/* 34F3D8 E003A758 AE440000 */   sw       $a0, ($s2)
.LE003A75C:
/* 34F3DC E003A75C 3C02D838 */  lui       $v0, 0xd838
/* 34F3E0 E003A760 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 34F3E4 E003A764 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 34F3E8 E003A768 8CA40000 */  lw        $a0, ($a1)
/* 34F3EC E003A76C 34420002 */  ori       $v0, $v0, 2
/* 34F3F0 E003A770 0080182D */  daddu     $v1, $a0, $zero
/* 34F3F4 E003A774 24840008 */  addiu     $a0, $a0, 8
/* 34F3F8 E003A778 ACA40000 */  sw        $a0, ($a1)
/* 34F3FC E003A77C AC620000 */  sw        $v0, ($v1)
/* 34F400 E003A780 24020040 */  addiu     $v0, $zero, 0x40
/* 34F404 E003A784 AC620004 */  sw        $v0, 4($v1)
/* 34F408 E003A788 24020002 */  addiu     $v0, $zero, 2
/* 34F40C E003A78C 16E20006 */  bne       $s7, $v0, .LE003A7A8
/* 34F410 E003A790 3C03E200 */   lui      $v1, 0xe200
/* 34F414 E003A794 34631E01 */  ori       $v1, $v1, 0x1e01
/* 34F418 E003A798 24820008 */  addiu     $v0, $a0, 8
/* 34F41C E003A79C ACA20000 */  sw        $v0, ($a1)
/* 34F420 E003A7A0 AC830000 */  sw        $v1, ($a0)
/* 34F424 E003A7A4 AC800004 */  sw        $zero, 4($a0)
.LE003A7A8:
/* 34F428 E003A7A8 8CA20000 */  lw        $v0, ($a1)
/* 34F42C E003A7AC 0040182D */  daddu     $v1, $v0, $zero
/* 34F430 E003A7B0 24420008 */  addiu     $v0, $v0, 8
/* 34F434 E003A7B4 ACA20000 */  sw        $v0, ($a1)
/* 34F438 E003A7B8 3C02E700 */  lui       $v0, 0xe700
/* 34F43C E003A7BC AC620000 */  sw        $v0, ($v1)
/* 34F440 E003A7C0 AC600004 */  sw        $zero, 4($v1)
/* 34F444 E003A7C4 8FBF0104 */  lw        $ra, 0x104($sp)
/* 34F448 E003A7C8 8FBE0100 */  lw        $fp, 0x100($sp)
/* 34F44C E003A7CC 8FB700FC */  lw        $s7, 0xfc($sp)
/* 34F450 E003A7D0 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 34F454 E003A7D4 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 34F458 E003A7D8 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 34F45C E003A7DC 8FB300EC */  lw        $s3, 0xec($sp)
/* 34F460 E003A7E0 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 34F464 E003A7E4 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 34F468 E003A7E8 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 34F46C E003A7EC 03E00008 */  jr        $ra
/* 34F470 E003A7F0 27BD0108 */   addiu    $sp, $sp, 0x108
/* 34F474 E003A7F4 00000000 */  nop
/* 34F478 E003A7F8 00000000 */  nop
/* 34F47C E003A7FC 00000000 */  nop
