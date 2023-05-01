.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel update_camera_mode_2
/* A418 8002F018 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A41C 8002F01C AFB00010 */  sw        $s0, 0x10($sp)
/* A420 8002F020 0080802D */  daddu     $s0, $a0, $zero
/* A424 8002F024 AFBF0014 */  sw        $ra, 0x14($sp)
/* A428 8002F028 F7BE0040 */  sdc1      $f30, 0x40($sp)
/* A42C 8002F02C F7BC0038 */  sdc1      $f28, 0x38($sp)
/* A430 8002F030 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* A434 8002F034 F7B80028 */  sdc1      $f24, 0x28($sp)
/* A438 8002F038 F7B60020 */  sdc1      $f22, 0x20($sp)
/* A43C 8002F03C F7B40018 */  sdc1      $f20, 0x18($sp)
/* A440 8002F040 86020020 */  lh        $v0, 0x20($s0)
/* A444 8002F044 3C018009 */  lui       $at, %hi(D_8009A5EC)
/* A448 8002F048 C42669C0 */  lwc1      $f6, %lo(D_8009A5EC)($at)
/* A44C 8002F04C 86030022 */  lh        $v1, 0x22($s0)
/* A450 8002F050 44822000 */  mtc1      $v0, $f4
/* A454 8002F054 00000000 */  nop
/* A458 8002F058 46802120 */  cvt.s.w   $f4, $f4
/* A45C 8002F05C 44831000 */  mtc1      $v1, $f2
/* A460 8002F060 00000000 */  nop
/* A464 8002F064 468010A0 */  cvt.s.w   $f2, $f2
/* A468 8002F068 46062102 */  mul.s     $f4, $f4, $f6
/* A46C 8002F06C 00000000 */  nop
/* A470 8002F070 8602001E */  lh        $v0, 0x1E($s0)
/* A474 8002F074 86030006 */  lh        $v1, 0x6($s0)
/* A478 8002F078 44820000 */  mtc1      $v0, $f0
/* A47C 8002F07C 00000000 */  nop
/* A480 8002F080 46800020 */  cvt.s.w   $f0, $f0
/* A484 8002F084 8602001C */  lh        $v0, 0x1C($s0)
/* A488 8002F088 46061082 */  mul.s     $f2, $f2, $f6
/* A48C 8002F08C 00000000 */  nop
/* A490 8002F090 E6000070 */  swc1      $f0, 0x70($s0)
/* A494 8002F094 46000186 */  mov.s     $f6, $f0
/* A498 8002F098 E6060084 */  swc1      $f6, 0x84($s0)
/* A49C 8002F09C 44820000 */  mtc1      $v0, $f0
/* A4A0 8002F0A0 00000000 */  nop
/* A4A4 8002F0A4 46800020 */  cvt.s.w   $f0, $f0
/* A4A8 8002F0A8 E6000074 */  swc1      $f0, 0x74($s0)
/* A4AC 8002F0AC E6040078 */  swc1      $f4, 0x78($s0)
/* A4B0 8002F0B0 10600047 */  beqz      $v1, .LPAL_8002F1D0
/* A4B4 8002F0B4 E602007C */   swc1     $f2, 0x7C($s0)
/* A4B8 8002F0B8 46000086 */  mov.s     $f2, $f0
/* A4BC 8002F0BC 4480C000 */  mtc1      $zero, $f24
/* A4C0 8002F0C0 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* A4C4 8002F0C4 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* A4C8 8002F0C8 4481B000 */  mtc1      $at, $f22
/* A4CC 8002F0CC C6080054 */  lwc1      $f8, 0x54($s0)
/* A4D0 8002F0D0 C6000058 */  lwc1      $f0, 0x58($s0)
/* A4D4 8002F0D4 C604007C */  lwc1      $f4, 0x7C($s0)
/* A4D8 8002F0D8 C606005C */  lwc1      $f6, 0x5C($s0)
/* A4DC 8002F0DC 3C0143B4 */  lui       $at, (0x43B40000 >> 16)
/* A4E0 8002F0E0 4481A000 */  mtc1      $at, $f20
/* A4E4 8002F0E4 46161082 */  mul.s     $f2, $f2, $f22
/* A4E8 8002F0E8 00000000 */  nop
/* A4EC 8002F0EC A6000006 */  sh        $zero, 0x6($s0)
/* A4F0 8002F0F0 E6180098 */  swc1      $f24, 0x98($s0)
/* A4F4 8002F0F4 E618009C */  swc1      $f24, 0x9C($s0)
/* A4F8 8002F0F8 46040000 */  add.s     $f0, $f0, $f4
/* A4FC 8002F0FC E6080048 */  swc1      $f8, 0x48($s0)
/* A500 8002F100 E6060050 */  swc1      $f6, 0x50($s0)
/* A504 8002F104 E600004C */  swc1      $f0, 0x4C($s0)
/* A508 8002F108 46141683 */  div.s     $f26, $f2, $f20
/* A50C 8002F10C 0C00A83B */  jal       sin_rad
/* A510 8002F110 4600D306 */   mov.s    $f12, $f26
/* A514 8002F114 46000786 */  mov.s     $f30, $f0
/* A518 8002F118 0C00A854 */  jal       cos_rad
/* A51C 8002F11C 4600D306 */   mov.s    $f12, $f26
/* A520 8002F120 46000306 */  mov.s     $f12, $f0
/* A524 8002F124 46186202 */  mul.s     $f8, $f12, $f24
/* A528 8002F128 00000000 */  nop
/* A52C 8002F12C 4600C087 */  neg.s     $f2, $f24
/* A530 8002F130 4602F082 */  mul.s     $f2, $f30, $f2
/* A534 8002F134 00000000 */  nop
/* A538 8002F138 C61C0078 */  lwc1      $f28, 0x78($s0)
/* A53C 8002F13C 461EE102 */  mul.s     $f4, $f28, $f30
/* A540 8002F140 00000000 */  nop
/* A544 8002F144 460CE182 */  mul.s     $f6, $f28, $f12
/* A548 8002F148 00000000 */  nop
/* A54C 8002F14C C6000070 */  lwc1      $f0, 0x70($s0)
/* A550 8002F150 46160002 */  mul.s     $f0, $f0, $f22
/* A554 8002F154 00000000 */  nop
/* A558 8002F158 4600C286 */  mov.s     $f10, $f24
/* A55C 8002F15C 46005586 */  mov.s     $f22, $f10
/* A560 8002F160 46044600 */  add.s     $f24, $f8, $f4
/* A564 8002F164 46140683 */  div.s     $f26, $f0, $f20
/* A568 8002F168 4600D306 */  mov.s     $f12, $f26
/* A56C 8002F16C 0C00A83B */  jal       sin_rad
/* A570 8002F170 46061700 */   add.s    $f28, $f2, $f6
/* A574 8002F174 46000786 */  mov.s     $f30, $f0
/* A578 8002F178 0C00A854 */  jal       cos_rad
/* A57C 8002F17C 4600D306 */   mov.s    $f12, $f26
/* A580 8002F180 46000306 */  mov.s     $f12, $f0
/* A584 8002F184 46166202 */  mul.s     $f8, $f12, $f22
/* A588 8002F188 00000000 */  nop
/* A58C 8002F18C 4616F182 */  mul.s     $f6, $f30, $f22
/* A590 8002F190 00000000 */  nop
/* A594 8002F194 461EE102 */  mul.s     $f4, $f28, $f30
/* A598 8002F198 00000000 */  nop
/* A59C 8002F19C 460CE082 */  mul.s     $f2, $f28, $f12
/* A5A0 8002F1A0 00000000 */  nop
/* A5A4 8002F1A4 C600004C */  lwc1      $f0, 0x4C($s0)
/* A5A8 8002F1A8 46180400 */  add.s     $f16, $f0, $f24
/* A5AC 8002F1AC 46044281 */  sub.s     $f10, $f8, $f4
/* A5B0 8002F1B0 46023080 */  add.s     $f2, $f6, $f2
/* A5B4 8002F1B4 C6000048 */  lwc1      $f0, 0x48($s0)
/* A5B8 8002F1B8 460A0100 */  add.s     $f4, $f0, $f10
/* A5BC 8002F1BC C6000050 */  lwc1      $f0, 0x50($s0)
/* A5C0 8002F1C0 46020200 */  add.s     $f8, $f0, $f2
/* A5C4 8002F1C4 E6100040 */  swc1      $f16, 0x40($s0)
/* A5C8 8002F1C8 E604003C */  swc1      $f4, 0x3C($s0)
/* A5CC 8002F1CC E6080044 */  swc1      $f8, 0x44($s0)
.LPAL_8002F1D0:
/* A5D0 8002F1D0 C6020054 */  lwc1      $f2, 0x54($s0)
/* A5D4 8002F1D4 C6000048 */  lwc1      $f0, 0x48($s0)
/* A5D8 8002F1D8 46001101 */  sub.s     $f4, $f2, $f0
/* A5DC 8002F1DC C602005C */  lwc1      $f2, 0x5C($s0)
/* A5E0 8002F1E0 C6000050 */  lwc1      $f0, 0x50($s0)
/* A5E4 8002F1E4 46001201 */  sub.s     $f8, $f2, $f0
/* A5E8 8002F1E8 C6000058 */  lwc1      $f0, 0x58($s0)
/* A5EC 8002F1EC C602007C */  lwc1      $f2, 0x7C($s0)
/* A5F0 8002F1F0 46020000 */  add.s     $f0, $f0, $f2
/* A5F4 8002F1F4 C602004C */  lwc1      $f2, 0x4C($s0)
/* A5F8 8002F1F8 46020401 */  sub.s     $f16, $f0, $f2
/* A5FC 8002F1FC 3C014180 */  lui       $at, (0x41800000 >> 16)
/* A600 8002F200 44811000 */  mtc1      $at, $f2
/* A604 8002F204 46002005 */  abs.s     $f0, $f4
/* A608 8002F208 4600103C */  c.lt.s    $f2, $f0
/* A60C 8002F20C 00000000 */  nop
/* A610 8002F210 4502000C */  bc1fl     .LPAL_8002F244
/* A614 8002F214 46008005 */   abs.s    $f0, $f16
/* A618 8002F218 44800000 */  mtc1      $zero, $f0
/* A61C 8002F21C 00000000 */  nop
/* A620 8002F220 4600203C */  c.lt.s    $f4, $f0
/* A624 8002F224 00000000 */  nop
/* A628 8002F228 45000005 */  bc1f      .LPAL_8002F240
/* A62C 8002F22C 46001106 */   mov.s    $f4, $f2
/* A630 8002F230 3C01C180 */  lui       $at, (0xC1800000 >> 16)
/* A634 8002F234 44812000 */  mtc1      $at, $f4
/* A638 8002F238 3C014180 */  lui       $at, (0x41800000 >> 16)
/* A63C 8002F23C 44811000 */  mtc1      $at, $f2
.LPAL_8002F240:
/* A640 8002F240 46008005 */  abs.s     $f0, $f16
.LPAL_8002F244:
/* A644 8002F244 4600103C */  c.lt.s    $f2, $f0
/* A648 8002F248 00000000 */  nop
/* A64C 8002F24C 45000009 */  bc1f      .LPAL_8002F274
/* A650 8002F250 00000000 */   nop
/* A654 8002F254 44800000 */  mtc1      $zero, $f0
/* A658 8002F258 00000000 */  nop
/* A65C 8002F25C 4600803C */  c.lt.s    $f16, $f0
/* A660 8002F260 00000000 */  nop
/* A664 8002F264 45000003 */  bc1f      .LPAL_8002F274
/* A668 8002F268 46001406 */   mov.s    $f16, $f2
/* A66C 8002F26C 3C01C180 */  lui       $at, (0xC1800000 >> 16)
/* A670 8002F270 44818000 */  mtc1      $at, $f16
.LPAL_8002F274:
/* A674 8002F274 3C014180 */  lui       $at, (0x41800000 >> 16)
/* A678 8002F278 44811000 */  mtc1      $at, $f2
/* A67C 8002F27C 46004005 */  abs.s     $f0, $f8
/* A680 8002F280 4600103C */  c.lt.s    $f2, $f0
/* A684 8002F284 00000000 */  nop
/* A688 8002F288 45000009 */  bc1f      .LPAL_8002F2B0
/* A68C 8002F28C 00000000 */   nop
/* A690 8002F290 44800000 */  mtc1      $zero, $f0
/* A694 8002F294 00000000 */  nop
/* A698 8002F298 4600403C */  c.lt.s    $f8, $f0
/* A69C 8002F29C 00000000 */  nop
/* A6A0 8002F2A0 45000003 */  bc1f      .LPAL_8002F2B0
/* A6A4 8002F2A4 46001206 */   mov.s    $f8, $f2
/* A6A8 8002F2A8 3C01C180 */  lui       $at, (0xC1800000 >> 16)
/* A6AC 8002F2AC 44814000 */  mtc1      $at, $f8
.LPAL_8002F2B0:
/* A6B0 8002F2B0 3C013F00 */  lui       $at, (0x3F000000 >> 16)
/* A6B4 8002F2B4 4481A000 */  mtc1      $at, $f20
/* A6B8 8002F2B8 00000000 */  nop
/* A6BC 8002F2BC 46142082 */  mul.s     $f2, $f4, $f20
/* A6C0 8002F2C0 00000000 */  nop
/* A6C4 8002F2C4 46148182 */  mul.s     $f6, $f16, $f20
/* A6C8 8002F2C8 00000000 */  nop
/* A6CC 8002F2CC 46144202 */  mul.s     $f8, $f8, $f20
/* A6D0 8002F2D0 00000000 */  nop
/* A6D4 8002F2D4 C6000074 */  lwc1      $f0, 0x74($s0)
/* A6D8 8002F2D8 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* A6DC 8002F2DC 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* A6E0 8002F2E0 4481B000 */  mtc1      $at, $f22
/* A6E4 8002F2E4 00000000 */  nop
/* A6E8 8002F2E8 46160002 */  mul.s     $f0, $f0, $f22
/* A6EC 8002F2EC 00000000 */  nop
/* A6F0 8002F2F0 4480C000 */  mtc1      $zero, $f24
/* A6F4 8002F2F4 C6040048 */  lwc1      $f4, 0x48($s0)
/* A6F8 8002F2F8 3C0143B4 */  lui       $at, (0x43B40000 >> 16)
/* A6FC 8002F2FC 44819000 */  mtc1      $at, $f18
/* A700 8002F300 46022100 */  add.s     $f4, $f4, $f2
/* A704 8002F304 C602004C */  lwc1      $f2, 0x4C($s0)
/* A708 8002F308 46120683 */  div.s     $f26, $f0, $f18
/* A70C 8002F30C 46061080 */  add.s     $f2, $f2, $f6
/* A710 8002F310 C6000050 */  lwc1      $f0, 0x50($s0)
/* A714 8002F314 4600D306 */  mov.s     $f12, $f26
/* A718 8002F318 46080000 */  add.s     $f0, $f0, $f8
/* A71C 8002F31C E6040048 */  swc1      $f4, 0x48($s0)
/* A720 8002F320 E602004C */  swc1      $f2, 0x4C($s0)
/* A724 8002F324 0C00A83B */  jal       sin_rad
/* A728 8002F328 E6000050 */   swc1     $f0, 0x50($s0)
/* A72C 8002F32C 46000786 */  mov.s     $f30, $f0
/* A730 8002F330 0C00A854 */  jal       cos_rad
/* A734 8002F334 4600D306 */   mov.s    $f12, $f26
/* A738 8002F338 46000306 */  mov.s     $f12, $f0
/* A73C 8002F33C 46186202 */  mul.s     $f8, $f12, $f24
/* A740 8002F340 00000000 */  nop
/* A744 8002F344 4600C087 */  neg.s     $f2, $f24
/* A748 8002F348 4602F082 */  mul.s     $f2, $f30, $f2
/* A74C 8002F34C 00000000 */  nop
/* A750 8002F350 C61C0078 */  lwc1      $f28, 0x78($s0)
/* A754 8002F354 461EE102 */  mul.s     $f4, $f28, $f30
/* A758 8002F358 00000000 */  nop
/* A75C 8002F35C 460CE182 */  mul.s     $f6, $f28, $f12
/* A760 8002F360 00000000 */  nop
/* A764 8002F364 C6000070 */  lwc1      $f0, 0x70($s0)
/* A768 8002F368 46160002 */  mul.s     $f0, $f0, $f22
/* A76C 8002F36C 00000000 */  nop
/* A770 8002F370 4600C286 */  mov.s     $f10, $f24
/* A774 8002F374 3C0143B4 */  lui       $at, (0x43B40000 >> 16)
/* A778 8002F378 44819000 */  mtc1      $at, $f18
/* A77C 8002F37C 46005586 */  mov.s     $f22, $f10
/* A780 8002F380 46044600 */  add.s     $f24, $f8, $f4
/* A784 8002F384 46120683 */  div.s     $f26, $f0, $f18
/* A788 8002F388 4600D306 */  mov.s     $f12, $f26
/* A78C 8002F38C 0C00A83B */  jal       sin_rad
/* A790 8002F390 46061700 */   add.s    $f28, $f2, $f6
/* A794 8002F394 46000786 */  mov.s     $f30, $f0
/* A798 8002F398 0C00A854 */  jal       cos_rad
/* A79C 8002F39C 4600D306 */   mov.s    $f12, $f26
/* A7A0 8002F3A0 46000306 */  mov.s     $f12, $f0
/* A7A4 8002F3A4 461EE002 */  mul.s     $f0, $f28, $f30
/* A7A8 8002F3A8 00000000 */  nop
/* A7AC 8002F3AC C602004C */  lwc1      $f2, 0x4C($s0)
/* A7B0 8002F3B0 46181400 */  add.s     $f16, $f2, $f24
/* A7B4 8002F3B4 C6020040 */  lwc1      $f2, 0x40($s0)
/* A7B8 8002F3B8 46028081 */  sub.s     $f2, $f16, $f2
/* A7BC 8002F3BC 46141402 */  mul.s     $f16, $f2, $f20
/* A7C0 8002F3C0 00000000 */  nop
/* A7C4 8002F3C4 46166082 */  mul.s     $f2, $f12, $f22
/* A7C8 8002F3C8 00000000 */  nop
/* A7CC 8002F3CC 46001281 */  sub.s     $f10, $f2, $f0
/* A7D0 8002F3D0 4616F082 */  mul.s     $f2, $f30, $f22
/* A7D4 8002F3D4 00000000 */  nop
/* A7D8 8002F3D8 C6000048 */  lwc1      $f0, 0x48($s0)
/* A7DC 8002F3DC 460A0100 */  add.s     $f4, $f0, $f10
/* A7E0 8002F3E0 C600003C */  lwc1      $f0, 0x3C($s0)
/* A7E4 8002F3E4 46002001 */  sub.s     $f0, $f4, $f0
/* A7E8 8002F3E8 46140102 */  mul.s     $f4, $f0, $f20
/* A7EC 8002F3EC 00000000 */  nop
/* A7F0 8002F3F0 460CE002 */  mul.s     $f0, $f28, $f12
/* A7F4 8002F3F4 00000000 */  nop
/* A7F8 8002F3F8 46001080 */  add.s     $f2, $f2, $f0
/* A7FC 8002F3FC C6000050 */  lwc1      $f0, 0x50($s0)
/* A800 8002F400 46020200 */  add.s     $f8, $f0, $f2
/* A804 8002F404 C6000044 */  lwc1      $f0, 0x44($s0)
/* A808 8002F408 46004001 */  sub.s     $f0, $f8, $f0
/* A80C 8002F40C 46140202 */  mul.s     $f8, $f0, $f20
/* A810 8002F410 00000000 */  nop
/* A814 8002F414 3C014180 */  lui       $at, (0x41800000 >> 16)
/* A818 8002F418 44811000 */  mtc1      $at, $f2
/* A81C 8002F41C 46002005 */  abs.s     $f0, $f4
/* A820 8002F420 4600103C */  c.lt.s    $f2, $f0
/* A824 8002F424 00000000 */  nop
/* A828 8002F428 4502000A */  bc1fl     .LPAL_8002F454
/* A82C 8002F42C 46008005 */   abs.s    $f0, $f16
/* A830 8002F430 4616203C */  c.lt.s    $f4, $f22
/* A834 8002F434 00000000 */  nop
/* A838 8002F438 45000005 */  bc1f      .LPAL_8002F450
/* A83C 8002F43C 46001106 */   mov.s    $f4, $f2
/* A840 8002F440 3C01C180 */  lui       $at, (0xC1800000 >> 16)
/* A844 8002F444 44812000 */  mtc1      $at, $f4
/* A848 8002F448 3C014180 */  lui       $at, (0x41800000 >> 16)
/* A84C 8002F44C 44811000 */  mtc1      $at, $f2
.LPAL_8002F450:
/* A850 8002F450 46008005 */  abs.s     $f0, $f16
.LPAL_8002F454:
/* A854 8002F454 4600103C */  c.lt.s    $f2, $f0
/* A858 8002F458 00000000 */  nop
/* A85C 8002F45C 45000009 */  bc1f      .LPAL_8002F484
/* A860 8002F460 00000000 */   nop
/* A864 8002F464 44800000 */  mtc1      $zero, $f0
/* A868 8002F468 00000000 */  nop
/* A86C 8002F46C 4600803C */  c.lt.s    $f16, $f0
/* A870 8002F470 00000000 */  nop
/* A874 8002F474 45000003 */  bc1f      .LPAL_8002F484
/* A878 8002F478 46001406 */   mov.s    $f16, $f2
/* A87C 8002F47C 3C01C180 */  lui       $at, (0xC1800000 >> 16)
/* A880 8002F480 44818000 */  mtc1      $at, $f16
.LPAL_8002F484:
/* A884 8002F484 3C014180 */  lui       $at, (0x41800000 >> 16)
/* A888 8002F488 44811000 */  mtc1      $at, $f2
/* A88C 8002F48C 46004005 */  abs.s     $f0, $f8
/* A890 8002F490 4600103C */  c.lt.s    $f2, $f0
/* A894 8002F494 00000000 */  nop
/* A898 8002F498 45000009 */  bc1f      .LPAL_8002F4C0
/* A89C 8002F49C 00000000 */   nop
/* A8A0 8002F4A0 44800000 */  mtc1      $zero, $f0
/* A8A4 8002F4A4 00000000 */  nop
/* A8A8 8002F4A8 4600403C */  c.lt.s    $f8, $f0
/* A8AC 8002F4AC 00000000 */  nop
/* A8B0 8002F4B0 45000003 */  bc1f      .LPAL_8002F4C0
/* A8B4 8002F4B4 46001206 */   mov.s    $f8, $f2
/* A8B8 8002F4B8 3C01C180 */  lui       $at, (0xC1800000 >> 16)
/* A8BC 8002F4BC 44814000 */  mtc1      $at, $f8
.LPAL_8002F4C0:
/* A8C0 8002F4C0 C600003C */  lwc1      $f0, 0x3C($s0)
/* A8C4 8002F4C4 46040000 */  add.s     $f0, $f0, $f4
/* A8C8 8002F4C8 C60E0044 */  lwc1      $f14, 0x44($s0)
/* A8CC 8002F4CC 8E060048 */  lw        $a2, 0x48($s0)
/* A8D0 8002F4D0 46087380 */  add.s     $f14, $f14, $f8
/* A8D4 8002F4D4 C6020040 */  lwc1      $f2, 0x40($s0)
/* A8D8 8002F4D8 8E070050 */  lw        $a3, 0x50($s0)
/* A8DC 8002F4DC 46101080 */  add.s     $f2, $f2, $f16
/* A8E0 8002F4E0 E600003C */  swc1      $f0, 0x3C($s0)
/* A8E4 8002F4E4 46000306 */  mov.s     $f12, $f0
/* A8E8 8002F4E8 E6020040 */  swc1      $f2, 0x40($s0)
/* A8EC 8002F4EC 0C00A700 */  jal       atan2
/* A8F0 8002F4F0 E60E0044 */   swc1     $f14, 0x44($s0)
/* A8F4 8002F4F4 C6040048 */  lwc1      $f4, 0x48($s0)
/* A8F8 8002F4F8 4480A000 */  mtc1      $zero, $f20
/* A8FC 8002F4FC C602003C */  lwc1      $f2, 0x3C($s0)
/* A900 8002F500 E600006C */  swc1      $f0, 0x6C($s0)
/* A904 8002F504 46022581 */  sub.s     $f22, $f4, $f2
/* A908 8002F508 C6040050 */  lwc1      $f4, 0x50($s0)
/* A90C 8002F50C C6020044 */  lwc1      $f2, 0x44($s0)
/* A910 8002F510 4600A306 */  mov.s     $f12, $f20
/* A914 8002F514 46022701 */  sub.s     $f28, $f4, $f2
/* A918 8002F518 C604004C */  lwc1      $f4, 0x4C($s0)
/* A91C 8002F51C C6020040 */  lwc1      $f2, 0x40($s0)
/* A920 8002F520 4406B000 */  mfc1      $a2, $f22
/* A924 8002F524 46022601 */  sub.s     $f24, $f4, $f2
/* A928 8002F528 4407E000 */  mfc1      $a3, $f28
/* A92C 8002F52C 0C00A700 */  jal       atan2
/* A930 8002F530 4600A386 */   mov.s    $f14, $f20
/* A934 8002F534 4616B102 */  mul.s     $f4, $f22, $f22
/* A938 8002F538 00000000 */  nop
/* A93C 8002F53C 461CE082 */  mul.s     $f2, $f28, $f28
/* A940 8002F540 00000000 */  nop
/* A944 8002F544 46022300 */  add.s     $f12, $f4, $f2
/* A948 8002F548 46000007 */  neg.s     $f0, $f0
/* A94C 8002F54C E6000090 */  swc1      $f0, 0x90($s0)
/* A950 8002F550 46006004 */  sqrt.s    $f0, $f12
/* A954 8002F554 46000032 */  c.eq.s    $f0, $f0
/* A958 8002F558 00000000 */  nop
/* A95C 8002F55C 45030004 */  bc1tl     .LPAL_8002F570
/* A960 8002F560 4600A306 */   mov.s    $f12, $f20
/* A964 8002F564 0C018B58 */  jal       sqrtf
/* A968 8002F568 00000000 */   nop
/* A96C 8002F56C 4600A306 */  mov.s     $f12, $f20
.LPAL_8002F570:
/* A970 8002F570 46000007 */  neg.s     $f0, $f0
/* A974 8002F574 4406C000 */  mfc1      $a2, $f24
/* A978 8002F578 44070000 */  mfc1      $a3, $f0
/* A97C 8002F57C 0C00A700 */  jal       atan2
/* A980 8002F580 46006386 */   mov.s    $f14, $f12
/* A984 8002F584 E6000094 */  swc1      $f0, 0x94($s0)
/* A988 8002F588 8FBF0014 */  lw        $ra, 0x14($sp)
/* A98C 8002F58C 8FB00010 */  lw        $s0, 0x10($sp)
/* A990 8002F590 D7BE0040 */  ldc1      $f30, 0x40($sp)
/* A994 8002F594 D7BC0038 */  ldc1      $f28, 0x38($sp)
/* A998 8002F598 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* A99C 8002F59C D7B80028 */  ldc1      $f24, 0x28($sp)
/* A9A0 8002F5A0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* A9A4 8002F5A4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* A9A8 8002F5A8 03E00008 */  jr        $ra
/* A9AC 8002F5AC 27BD0048 */   addiu    $sp, $sp, 0x48