.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F0C4
/* 1A4C4 8003F0C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A4C8 8003F0C8 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A4CC 8003F0CC 0080902D */  daddu     $s2, $a0, $zero
/* 1A4D0 8003F0D0 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A4D4 8003F0D4 00A0802D */  daddu     $s0, $a1, $zero
/* 1A4D8 8003F0D8 2404FFF6 */  addiu     $a0, $zero, -0xa
/* 1A4DC 8003F0DC AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A4E0 8003F0E0 0C00EABB */  jal       get_npc_unsafe
/* 1A4E4 8003F0E4 AFB1001C */   sw       $s1, 0x1c($sp)
/* 1A4E8 8003F0E8 12000024 */  beqz      $s0, .L8003F17C
/* 1A4EC 8003F0EC 0040882D */   daddu    $s1, $v0, $zero
/* 1A4F0 8003F0F0 AE400074 */  sw        $zero, 0x74($s2)
/* 1A4F4 8003F0F4 C622003C */  lwc1      $f2, 0x3c($s1)
/* 1A4F8 8003F0F8 3C013ECC */  lui       $at, 0x3ecc
/* 1A4FC 8003F0FC 3421CCCD */  ori       $at, $at, 0xcccd
/* 1A500 8003F100 44810000 */  mtc1      $at, $f0
/* 1A504 8003F104 AFA00014 */  sw        $zero, 0x14($sp)
/* 1A508 8003F108 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A50C 8003F10C 8E250038 */  lw        $a1, 0x38($s1)
/* 1A510 8003F110 8E26003C */  lw        $a2, 0x3c($s1)
/* 1A514 8003F114 8E270040 */  lw        $a3, 0x40($s1)
/* 1A518 8003F118 3C01800A */  lui       $at, %hi(D_800A0BA4)
/* 1A51C 8003F11C E4220BA4 */  swc1      $f2, %lo(D_800A0BA4)($at)
/* 1A520 8003F120 0C01C5D4 */  jal       func_80071750
/* 1A524 8003F124 0000202D */   daddu    $a0, $zero, $zero
/* 1A528 8003F128 3C013727 */  lui       $at, 0x3727
/* 1A52C 8003F12C 3421C5AC */  ori       $at, $at, 0xc5ac
/* 1A530 8003F130 44810000 */  mtc1      $at, $f0
/* 1A534 8003F134 AFA00014 */  sw        $zero, 0x14($sp)
/* 1A538 8003F138 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A53C 8003F13C 8E250038 */  lw        $a1, 0x38($s1)
/* 1A540 8003F140 8E26003C */  lw        $a2, 0x3c($s1)
/* 1A544 8003F144 8E270040 */  lw        $a3, 0x40($s1)
/* 1A548 8003F148 3C01800A */  lui       $at, %hi(D_800A0BA8)
/* 1A54C 8003F14C AC220BA8 */  sw        $v0, %lo(D_800A0BA8)($at)
/* 1A550 8003F150 0C01C5D4 */  jal       func_80071750
/* 1A554 8003F154 24040003 */   addiu    $a0, $zero, 3
/* 1A558 8003F158 3C01800A */  lui       $at, %hi(D_800A0BAC)
/* 1A55C 8003F15C AC220BAC */  sw        $v0, %lo(D_800A0BAC)($at)
/* 1A560 8003F160 2402000C */  addiu     $v0, $zero, 0xc
/* 1A564 8003F164 3C01800A */  lui       $at, %hi(D_800A0BB8)
/* 1A568 8003F168 A4200BB8 */  sh        $zero, %lo(D_800A0BB8)($at)
/* 1A56C 8003F16C 3C01800A */  lui       $at, %hi(D_800A0BA0)
/* 1A570 8003F170 AC220BA0 */  sw        $v0, %lo(D_800A0BA0)($at)
/* 1A574 8003F174 0C05272D */  jal       play_sound
/* 1A578 8003F178 24042074 */   addiu    $a0, $zero, 0x2074
.L8003F17C:
/* 1A57C 8003F17C 3C0140C9 */  lui       $at, 0x40c9
/* 1A580 8003F180 34210FD0 */  ori       $at, $at, 0xfd0
/* 1A584 8003F184 44810000 */  mtc1      $at, $f0
/* 1A588 8003F188 C64C0074 */  lwc1      $f12, 0x74($s2)
/* 1A58C 8003F18C 46806320 */  cvt.s.w   $f12, $f12
/* 1A590 8003F190 46006302 */  mul.s     $f12, $f12, $f0
/* 1A594 8003F194 00000000 */  nop       
/* 1A598 8003F198 3C0143B4 */  lui       $at, 0x43b4
/* 1A59C 8003F19C 44810000 */  mtc1      $at, $f0
/* 1A5A0 8003F1A0 0C00A85B */  jal       sin_rad
/* 1A5A4 8003F1A4 46006303 */   div.s    $f12, $f12, $f0
/* 1A5A8 8003F1A8 3C014040 */  lui       $at, 0x4040
/* 1A5AC 8003F1AC 44811000 */  mtc1      $at, $f2
/* 1A5B0 8003F1B0 00000000 */  nop       
/* 1A5B4 8003F1B4 46020002 */  mul.s     $f0, $f0, $f2
/* 1A5B8 8003F1B8 00000000 */  nop       
/* 1A5BC 8003F1BC 3C01800A */  lui       $at, %hi(D_800A0BA4)
/* 1A5C0 8003F1C0 C4220BA4 */  lwc1      $f2, %lo(D_800A0BA4)($at)
/* 1A5C4 8003F1C4 46001080 */  add.s     $f2, $f2, $f0
/* 1A5C8 8003F1C8 E622003C */  swc1      $f2, 0x3c($s1)
/* 1A5CC 8003F1CC 8E420074 */  lw        $v0, 0x74($s2)
/* 1A5D0 8003F1D0 2442000A */  addiu     $v0, $v0, 0xa
/* 1A5D4 8003F1D4 44826000 */  mtc1      $v0, $f12
/* 1A5D8 8003F1D8 00000000 */  nop       
/* 1A5DC 8003F1DC 46806320 */  cvt.s.w   $f12, $f12
/* 1A5E0 8003F1E0 0C00A6C9 */  jal       clamp_angle
/* 1A5E4 8003F1E4 AE420074 */   sw       $v0, 0x74($s2)
/* 1A5E8 8003F1E8 4600018D */  trunc.w.s $f6, $f0
/* 1A5EC 8003F1EC E6460074 */  swc1      $f6, 0x74($s2)
/* 1A5F0 8003F1F0 3C05800A */  lui       $a1, %hi(D_800A0BA8)
/* 1A5F4 8003F1F4 8CA50BA8 */  lw        $a1, %lo(D_800A0BA8)($a1)
/* 1A5F8 8003F1F8 C6200038 */  lwc1      $f0, 0x38($s1)
/* 1A5FC 8003F1FC 3C014180 */  lui       $at, 0x4180
/* 1A600 8003F200 44811000 */  mtc1      $at, $f2
/* 1A604 8003F204 8CA2000C */  lw        $v0, 0xc($a1)
/* 1A608 8003F208 E4400004 */  swc1      $f0, 4($v0)
/* 1A60C 8003F20C C620003C */  lwc1      $f0, 0x3c($s1)
/* 1A610 8003F210 46020000 */  add.s     $f0, $f0, $f2
/* 1A614 8003F214 3C08800A */  lui       $t0, %hi(D_800A0BAC)
/* 1A618 8003F218 25080BAC */  addiu     $t0, $t0, %lo(D_800A0BAC)
/* 1A61C 8003F21C E4400008 */  swc1      $f0, 8($v0)
/* 1A620 8003F220 C6200040 */  lwc1      $f0, 0x40($s1)
/* 1A624 8003F224 8D040000 */  lw        $a0, ($t0)
/* 1A628 8003F228 E440000C */  swc1      $f0, 0xc($v0)
/* 1A62C 8003F22C 8C82000C */  lw        $v0, 0xc($a0)
/* 1A630 8003F230 C6200038 */  lwc1      $f0, 0x38($s1)
/* 1A634 8003F234 E4400004 */  swc1      $f0, 4($v0)
/* 1A638 8003F238 C620003C */  lwc1      $f0, 0x3c($s1)
/* 1A63C 8003F23C 46020000 */  add.s     $f0, $f0, $f2
/* 1A640 8003F240 3C0140A0 */  lui       $at, 0x40a0
/* 1A644 8003F244 44811000 */  mtc1      $at, $f2
/* 1A648 8003F248 E4400008 */  swc1      $f0, 8($v0)
/* 1A64C 8003F24C C6200040 */  lwc1      $f0, 0x40($s1)
/* 1A650 8003F250 46020000 */  add.s     $f0, $f0, $f2
/* 1A654 8003F254 3C07800A */  lui       $a3, %hi(D_800A0BB8)
/* 1A658 8003F258 24E70BB8 */  addiu     $a3, $a3, %lo(D_800A0BB8)
/* 1A65C 8003F25C E440000C */  swc1      $f0, 0xc($v0)
/* 1A660 8003F260 84E30000 */  lh        $v1, ($a3)
/* 1A664 8003F264 24060002 */  addiu     $a2, $zero, 2
/* 1A668 8003F268 14660011 */  bne       $v1, $a2, .L8003F2B0
/* 1A66C 8003F26C 24020001 */   addiu    $v0, $zero, 1
/* 1A670 8003F270 8CA2000C */  lw        $v0, 0xc($a1)
/* 1A674 8003F274 3C013727 */  lui       $at, 0x3727
/* 1A678 8003F278 3421C5AC */  ori       $at, $at, 0xc5ac
/* 1A67C 8003F27C 44810000 */  mtc1      $at, $f0
/* 1A680 8003F280 00000000 */  nop       
/* 1A684 8003F284 E4400030 */  swc1      $f0, 0x30($v0)
/* 1A688 8003F288 8C82000C */  lw        $v0, 0xc($a0)
/* 1A68C 8003F28C E4400030 */  swc1      $f0, 0x30($v0)
/* 1A690 8003F290 8CA20000 */  lw        $v0, ($a1)
/* 1A694 8003F294 34420010 */  ori       $v0, $v0, 0x10
/* 1A698 8003F298 ACA20000 */  sw        $v0, ($a1)
/* 1A69C 8003F29C 8C830000 */  lw        $v1, ($a0)
/* 1A6A0 8003F2A0 24020001 */  addiu     $v0, $zero, 1
/* 1A6A4 8003F2A4 34630010 */  ori       $v1, $v1, 0x10
/* 1A6A8 8003F2A8 0800FCDB */  j         .L8003F36C
/* 1A6AC 8003F2AC AC830000 */   sw       $v1, ($a0)
.L8003F2B0:
/* 1A6B0 8003F2B0 1462002E */  bne       $v1, $v0, .L8003F36C
/* 1A6B4 8003F2B4 0000102D */   daddu    $v0, $zero, $zero
/* 1A6B8 8003F2B8 8CA2000C */  lw        $v0, 0xc($a1)
/* 1A6BC 8003F2BC C4400030 */  lwc1      $f0, 0x30($v0)
/* 1A6C0 8003F2C0 3C01800A */  lui       $at, %hi(D_800985F0)
/* 1A6C4 8003F2C4 D42285F0 */  ldc1      $f2, %lo(D_800985F0)($at)
/* 1A6C8 8003F2C8 46000021 */  cvt.d.s   $f0, $f0
/* 1A6CC 8003F2CC 46220000 */  add.d     $f0, $f0, $f2
/* 1A6D0 8003F2D0 3C01400C */  lui       $at, 0x400c
/* 1A6D4 8003F2D4 44812800 */  mtc1      $at, $f5
/* 1A6D8 8003F2D8 44802000 */  mtc1      $zero, $f4
/* 1A6DC 8003F2DC 46200020 */  cvt.s.d   $f0, $f0
/* 1A6E0 8003F2E0 460000A1 */  cvt.d.s   $f2, $f0
/* 1A6E4 8003F2E4 4622203C */  c.lt.d    $f4, $f2
/* 1A6E8 8003F2E8 00000000 */  nop       
/* 1A6EC 8003F2EC 45000005 */  bc1f      .L8003F304
/* 1A6F0 8003F2F0 E4400030 */   swc1     $f0, 0x30($v0)
/* 1A6F4 8003F2F4 3C014060 */  lui       $at, 0x4060
/* 1A6F8 8003F2F8 44810000 */  mtc1      $at, $f0
/* 1A6FC 8003F2FC 00000000 */  nop       
/* 1A700 8003F300 E4400030 */  swc1      $f0, 0x30($v0)
.L8003F304:
/* 1A704 8003F304 3C03800A */  lui       $v1, %hi(D_800A0BA0)
/* 1A708 8003F308 24630BA0 */  addiu     $v1, $v1, %lo(D_800A0BA0)
/* 1A70C 8003F30C 8C620000 */  lw        $v0, ($v1)
/* 1A710 8003F310 10400003 */  beqz      $v0, .L8003F320
/* 1A714 8003F314 2442FFFF */   addiu    $v0, $v0, -1
/* 1A718 8003F318 0800FCDA */  j         .L8003F368
/* 1A71C 8003F31C AC620000 */   sw       $v0, ($v1)
.L8003F320:
/* 1A720 8003F320 8D020000 */  lw        $v0, ($t0)
/* 1A724 8003F324 8C42000C */  lw        $v0, 0xc($v0)
/* 1A728 8003F328 C4400030 */  lwc1      $f0, 0x30($v0)
/* 1A72C 8003F32C 3C013FE0 */  lui       $at, 0x3fe0
/* 1A730 8003F330 44811800 */  mtc1      $at, $f3
/* 1A734 8003F334 44801000 */  mtc1      $zero, $f2
/* 1A738 8003F338 46000021 */  cvt.d.s   $f0, $f0
/* 1A73C 8003F33C 46220000 */  add.d     $f0, $f0, $f2
/* 1A740 8003F340 3C014014 */  lui       $at, 0x4014
/* 1A744 8003F344 44812800 */  mtc1      $at, $f5
/* 1A748 8003F348 44802000 */  mtc1      $zero, $f4
/* 1A74C 8003F34C 46200020 */  cvt.s.d   $f0, $f0
/* 1A750 8003F350 460000A1 */  cvt.d.s   $f2, $f0
/* 1A754 8003F354 4622203C */  c.lt.d    $f4, $f2
/* 1A758 8003F358 00000000 */  nop       
/* 1A75C 8003F35C 45000002 */  bc1f      .L8003F368
/* 1A760 8003F360 E4400030 */   swc1     $f0, 0x30($v0)
/* 1A764 8003F364 A4E60000 */  sh        $a2, ($a3)
.L8003F368:
/* 1A768 8003F368 0000102D */  daddu     $v0, $zero, $zero
.L8003F36C:
/* 1A76C 8003F36C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A770 8003F370 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A774 8003F374 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A778 8003F378 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A77C 8003F37C 03E00008 */  jr        $ra
/* 1A780 8003F380 27BD0028 */   addiu    $sp, $sp, 0x28
