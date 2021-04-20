.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _npc_jump_to
/* F2DE4 802CE434 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* F2DE8 802CE438 AFB20018 */  sw        $s2, 0x18($sp)
/* F2DEC 802CE43C 0080902D */  daddu     $s2, $a0, $zero
/* F2DF0 802CE440 AFB40020 */  sw        $s4, 0x20($sp)
/* F2DF4 802CE444 00C0A02D */  daddu     $s4, $a2, $zero
/* F2DF8 802CE448 AFB3001C */  sw        $s3, 0x1c($sp)
/* F2DFC 802CE44C AFBF0024 */  sw        $ra, 0x24($sp)
/* F2E00 802CE450 AFB10014 */  sw        $s1, 0x14($sp)
/* F2E04 802CE454 AFB00010 */  sw        $s0, 0x10($sp)
/* F2E08 802CE458 F7B80038 */  sdc1      $f24, 0x38($sp)
/* F2E0C 802CE45C F7B60030 */  sdc1      $f22, 0x30($sp)
/* F2E10 802CE460 F7B40028 */  sdc1      $f20, 0x28($sp)
/* F2E14 802CE464 8E51000C */  lw        $s1, 0xc($s2)
/* F2E18 802CE468 10A00002 */  beqz      $a1, .L802CE474
/* F2E1C 802CE46C 26530078 */   addiu    $s3, $s2, 0x78
/* F2E20 802CE470 AE400070 */  sw        $zero, 0x70($s2)
.L802CE474:
/* F2E24 802CE474 8E420070 */  lw        $v0, 0x70($s2)
/* F2E28 802CE478 14400065 */  bnez      $v0, .L802CE610
/* F2E2C 802CE47C 00000000 */   nop
/* F2E30 802CE480 8E250000 */  lw        $a1, ($s1)
/* F2E34 802CE484 26310004 */  addiu     $s1, $s1, 4
/* F2E38 802CE488 0C0B1EAF */  jal       get_variable
/* F2E3C 802CE48C 0240202D */   daddu    $a0, $s2, $zero
/* F2E40 802CE490 8E250000 */  lw        $a1, ($s1)
/* F2E44 802CE494 26310004 */  addiu     $s1, $s1, 4
/* F2E48 802CE498 0240202D */  daddu     $a0, $s2, $zero
/* F2E4C 802CE49C 0C0B1EAF */  jal       get_variable
/* F2E50 802CE4A0 0040802D */   daddu    $s0, $v0, $zero
/* F2E54 802CE4A4 8E250000 */  lw        $a1, ($s1)
/* F2E58 802CE4A8 26310004 */  addiu     $s1, $s1, 4
/* F2E5C 802CE4AC 4482C000 */  mtc1      $v0, $f24
/* F2E60 802CE4B0 00000000 */  nop
/* F2E64 802CE4B4 4680C620 */  cvt.s.w   $f24, $f24
/* F2E68 802CE4B8 0C0B1EAF */  jal       get_variable
/* F2E6C 802CE4BC 0240202D */   daddu    $a0, $s2, $zero
/* F2E70 802CE4C0 4482B000 */  mtc1      $v0, $f22
/* F2E74 802CE4C4 00000000 */  nop
/* F2E78 802CE4C8 4680B5A0 */  cvt.s.w   $f22, $f22
/* F2E7C 802CE4CC 8E250000 */  lw        $a1, ($s1)
/* F2E80 802CE4D0 26310004 */  addiu     $s1, $s1, 4
/* F2E84 802CE4D4 0C0B1EAF */  jal       get_variable
/* F2E88 802CE4D8 0240202D */   daddu    $a0, $s2, $zero
/* F2E8C 802CE4DC 8E250000 */  lw        $a1, ($s1)
/* F2E90 802CE4E0 4482A000 */  mtc1      $v0, $f20
/* F2E94 802CE4E4 00000000 */  nop
/* F2E98 802CE4E8 4680A520 */  cvt.s.w   $f20, $f20
/* F2E9C 802CE4EC 0C0B1EAF */  jal       get_variable
/* F2EA0 802CE4F0 0240202D */   daddu    $a0, $s2, $zero
/* F2EA4 802CE4F4 0240202D */  daddu     $a0, $s2, $zero
/* F2EA8 802CE4F8 0200282D */  daddu     $a1, $s0, $zero
/* F2EAC 802CE4FC 0C0B36B0 */  jal       resolve_npc
/* F2EB0 802CE500 0040882D */   daddu    $s1, $v0, $zero
/* F2EB4 802CE504 0040802D */  daddu     $s0, $v0, $zero
/* F2EB8 802CE508 56000003 */  bnel      $s0, $zero, .L802CE518
/* F2EBC 802CE50C AE500074 */   sw       $s0, 0x74($s2)
/* F2EC0 802CE510 080B39A6 */  j         .L802CE698
/* F2EC4 802CE514 24020002 */   addiu    $v0, $zero, 2
.L802CE518:
/* F2EC8 802CE518 C60C0038 */  lwc1      $f12, 0x38($s0)
/* F2ECC 802CE51C C60E0040 */  lwc1      $f14, 0x40($s0)
/* F2ED0 802CE520 E6180060 */  swc1      $f24, 0x60($s0)
/* F2ED4 802CE524 4406C000 */  mfc1      $a2, $f24
/* F2ED8 802CE528 E6140068 */  swc1      $f20, 0x68($s0)
/* F2EDC 802CE52C 4407A000 */  mfc1      $a3, $f20
/* F2EE0 802CE530 E6160064 */  swc1      $f22, 0x64($s0)
/* F2EE4 802CE534 0C00A7B5 */  jal       dist2D
/* F2EE8 802CE538 A611008E */   sh       $s1, 0x8e($s0)
/* F2EEC 802CE53C 46000506 */  mov.s     $f20, $f0
/* F2EF0 802CE540 3C014000 */  lui       $at, 0x4000
/* F2EF4 802CE544 44811800 */  mtc1      $at, $f3
/* F2EF8 802CE548 44801000 */  mtc1      $zero, $f2
/* F2EFC 802CE54C 4600A021 */  cvt.d.s   $f0, $f20
/* F2F00 802CE550 4620103C */  c.lt.d    $f2, $f0
/* F2F04 802CE554 00000000 */  nop
/* F2F08 802CE558 45000009 */  bc1f      .L802CE580
/* F2F0C 802CE55C AE400078 */   sw       $zero, 0x78($s2)
/* F2F10 802CE560 C60C0038 */  lwc1      $f12, 0x38($s0)
/* F2F14 802CE564 C60E0040 */  lwc1      $f14, 0x40($s0)
/* F2F18 802CE568 8E060060 */  lw        $a2, 0x60($s0)
/* F2F1C 802CE56C 0C00A720 */  jal       atan2
/* F2F20 802CE570 8E070068 */   lw       $a3, 0x68($s0)
/* F2F24 802CE574 16800002 */  bnez      $s4, .L802CE580
/* F2F28 802CE578 E6400078 */   swc1     $f0, 0x78($s2)
/* F2F2C 802CE57C E600000C */  swc1      $f0, 0xc($s0)
.L802CE580:
/* F2F30 802CE580 C6020064 */  lwc1      $f2, 0x64($s0)
/* F2F34 802CE584 C600003C */  lwc1      $f0, 0x3c($s0)
/* F2F38 802CE588 8602008E */  lh        $v0, 0x8e($s0)
/* F2F3C 802CE58C 14400007 */  bnez      $v0, .L802CE5AC
/* F2F40 802CE590 46001581 */   sub.s    $f22, $f2, $f0
/* F2F44 802CE594 C6000018 */  lwc1      $f0, 0x18($s0)
/* F2F48 802CE598 4600A003 */  div.s     $f0, $f20, $f0
/* F2F4C 802CE59C 4600018D */  trunc.w.s $f6, $f0
/* F2F50 802CE5A0 44023000 */  mfc1      $v0, $f6
/* F2F54 802CE5A4 080B3970 */  j         .L802CE5C0
/* F2F58 802CE5A8 A602008E */   sh       $v0, 0x8e($s0)
.L802CE5AC:
/* F2F5C 802CE5AC 44820000 */  mtc1      $v0, $f0
/* F2F60 802CE5B0 00000000 */  nop
/* F2F64 802CE5B4 46800020 */  cvt.s.w   $f0, $f0
/* F2F68 802CE5B8 4600A003 */  div.s     $f0, $f20, $f0
/* F2F6C 802CE5BC E6000018 */  swc1      $f0, 0x18($s0)
.L802CE5C0:
/* F2F70 802CE5C0 8602008E */  lh        $v0, 0x8e($s0)
/* F2F74 802CE5C4 C6000014 */  lwc1      $f0, 0x14($s0)
/* F2F78 802CE5C8 44822000 */  mtc1      $v0, $f4
/* F2F7C 802CE5CC 00000000 */  nop
/* F2F80 802CE5D0 46802120 */  cvt.s.w   $f4, $f4
/* F2F84 802CE5D4 46040002 */  mul.s     $f0, $f0, $f4
/* F2F88 802CE5D8 00000000 */  nop
/* F2F8C 802CE5DC 3C013F00 */  lui       $at, 0x3f00
/* F2F90 802CE5E0 44811000 */  mtc1      $at, $f2
/* F2F94 802CE5E4 00000000 */  nop
/* F2F98 802CE5E8 46020002 */  mul.s     $f0, $f0, $f2
/* F2F9C 802CE5EC 00000000 */  nop
/* F2FA0 802CE5F0 8E020000 */  lw        $v0, ($s0)
/* F2FA4 802CE5F4 4604B103 */  div.s     $f4, $f22, $f4
/* F2FA8 802CE5F8 34420800 */  ori       $v0, $v0, 0x800
/* F2FAC 802CE5FC 46040000 */  add.s     $f0, $f0, $f4
/* F2FB0 802CE600 AE020000 */  sw        $v0, ($s0)
/* F2FB4 802CE604 24020001 */  addiu     $v0, $zero, 1
/* F2FB8 802CE608 E600001C */  swc1      $f0, 0x1c($s0)
/* F2FBC 802CE60C AE420070 */  sw        $v0, 0x70($s2)
.L802CE610:
/* F2FC0 802CE610 8E500074 */  lw        $s0, 0x74($s2)
/* F2FC4 802CE614 8E660000 */  lw        $a2, ($s3)
/* F2FC8 802CE618 8E050018 */  lw        $a1, 0x18($s0)
/* F2FCC 802CE61C 0C00EA95 */  jal       npc_move_heading
/* F2FD0 802CE620 0200202D */   daddu    $a0, $s0, $zero
/* F2FD4 802CE624 C604003C */  lwc1      $f4, 0x3c($s0)
/* F2FD8 802CE628 C600001C */  lwc1      $f0, 0x1c($s0)
/* F2FDC 802CE62C 9602008E */  lhu       $v0, 0x8e($s0)
/* F2FE0 802CE630 46002100 */  add.s     $f4, $f4, $f0
/* F2FE4 802CE634 C6020014 */  lwc1      $f2, 0x14($s0)
/* F2FE8 802CE638 2442FFFF */  addiu     $v0, $v0, -1
/* F2FEC 802CE63C 46020001 */  sub.s     $f0, $f0, $f2
/* F2FF0 802CE640 A602008E */  sh        $v0, 0x8e($s0)
/* F2FF4 802CE644 00021400 */  sll       $v0, $v0, 0x10
/* F2FF8 802CE648 E604003C */  swc1      $f4, 0x3c($s0)
/* F2FFC 802CE64C 04400003 */  bltz      $v0, .L802CE65C
/* F3000 802CE650 E600001C */   swc1     $f0, 0x1c($s0)
/* F3004 802CE654 080B39A6 */  j         .L802CE698
/* F3008 802CE658 0000102D */   daddu    $v0, $zero, $zero
.L802CE65C:
/* F300C 802CE65C 0200202D */  daddu     $a0, $s0, $zero
/* F3010 802CE660 24050002 */  addiu     $a1, $zero, 2
/* F3014 802CE664 C4800060 */  lwc1      $f0, 0x60($a0)
/* F3018 802CE668 C4820064 */  lwc1      $f2, 0x64($a0)
/* F301C 802CE66C C4840068 */  lwc1      $f4, 0x68($a0)
/* F3020 802CE670 8C820000 */  lw        $v0, ($a0)
/* F3024 802CE674 2403F7FF */  addiu     $v1, $zero, -0x801
/* F3028 802CE678 AC80001C */  sw        $zero, 0x1c($a0)
/* F302C 802CE67C 00431024 */  and       $v0, $v0, $v1
/* F3030 802CE680 E4800038 */  swc1      $f0, 0x38($a0)
/* F3034 802CE684 E482003C */  swc1      $f2, 0x3c($a0)
/* F3038 802CE688 E4840040 */  swc1      $f4, 0x40($a0)
/* F303C 802CE68C 0C00F598 */  jal       func_8003D660
/* F3040 802CE690 AC820000 */   sw       $v0, ($a0)
/* F3044 802CE694 24020001 */  addiu     $v0, $zero, 1
.L802CE698:
/* F3048 802CE698 8FBF0024 */  lw        $ra, 0x24($sp)
/* F304C 802CE69C 8FB40020 */  lw        $s4, 0x20($sp)
/* F3050 802CE6A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* F3054 802CE6A4 8FB20018 */  lw        $s2, 0x18($sp)
/* F3058 802CE6A8 8FB10014 */  lw        $s1, 0x14($sp)
/* F305C 802CE6AC 8FB00010 */  lw        $s0, 0x10($sp)
/* F3060 802CE6B0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* F3064 802CE6B4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* F3068 802CE6B8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* F306C 802CE6BC 03E00008 */  jr        $ra
/* F3070 802CE6C0 27BD0040 */   addiu    $sp, $sp, 0x40
