.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004A098
/* 25498 8004A098 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2549C 8004A09C AFB20018 */  sw        $s2, 0x18($sp)
/* 254A0 8004A0A0 0080902D */  daddu     $s2, $a0, $zero
/* 254A4 8004A0A4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 254A8 8004A0A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 254AC 8004A0AC AFB00010 */  sw        $s0, 0x10($sp)
/* 254B0 8004A0B0 8E510148 */  lw        $s1, 0x148($s2)
/* 254B4 8004A0B4 0C00E9EB */  jal       func_8003A7AC
/* 254B8 8004A0B8 86240008 */   lh       $a0, 8($s1)
/* 254BC 8004A0BC 0040802D */  daddu     $s0, $v0, $zero
/* 254C0 8004A0C0 9602008E */  lhu       $v0, 0x8e($s0)
/* 254C4 8004A0C4 2442FFFF */  addiu     $v0, $v0, -1
/* 254C8 8004A0C8 A602008E */  sh        $v0, 0x8e($s0)
/* 254CC 8004A0CC 00021400 */  sll       $v0, $v0, 0x10
/* 254D0 8004A0D0 14400010 */  bnez      $v0, .L8004A114
/* 254D4 8004A0D4 00000000 */   nop
/* 254D8 8004A0D8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 254DC 8004A0DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 254E0 8004A0E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 254E4 8004A0E4 C4420000 */  lwc1      $f2, ($v0)
/* 254E8 8004A0E8 468010A0 */  cvt.s.w   $f2, $f2
/* 254EC 8004A0EC 44061000 */  mfc1      $a2, $f2
/* 254F0 8004A0F0 C4420008 */  lwc1      $f2, 8($v0)
/* 254F4 8004A0F4 468010A0 */  cvt.s.w   $f2, $f2
/* 254F8 8004A0F8 44071000 */  mfc1      $a3, $f2
/* 254FC 8004A0FC 0C00A710 */  jal       func_80029C40
/* 25500 8004A100 00000000 */   nop
/* 25504 8004A104 0C00A6B9 */  jal       func_80029AE4
/* 25508 8004A108 46000306 */   mov.s    $f12, $f0
/* 2550C 8004A10C E600000C */  swc1      $f0, 0xc($s0)
/* 25510 8004A110 AE400070 */  sw        $zero, 0x70($s2)
.L8004A114:
/* 25514 8004A114 8FBF001C */  lw        $ra, 0x1c($sp)
/* 25518 8004A118 8FB20018 */  lw        $s2, 0x18($sp)
/* 2551C 8004A11C 8FB10014 */  lw        $s1, 0x14($sp)
/* 25520 8004A120 8FB00010 */  lw        $s0, 0x10($sp)
/* 25524 8004A124 03E00008 */  jr        $ra
/* 25528 8004A128 27BD0020 */   addiu    $sp, $sp, 0x20
