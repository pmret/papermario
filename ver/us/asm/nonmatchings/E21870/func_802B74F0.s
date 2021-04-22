.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B74F0
/* E21D60 802B74F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E21D64 802B74F4 AFB00010 */  sw        $s0, 0x10($sp)
/* E21D68 802B74F8 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E21D6C 802B74FC 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E21D70 802B7500 AFB10014 */  sw        $s1, 0x14($sp)
/* E21D74 802B7504 3C11802B */  lui       $s1, %hi(D_802B7D18_E22588)
/* E21D78 802B7508 26317D18 */  addiu     $s1, $s1, %lo(D_802B7D18_E22588)
/* E21D7C 802B750C AFBF0018 */  sw        $ra, 0x18($sp)
/* E21D80 802B7510 860200B0 */  lh        $v0, 0xb0($s0)
/* E21D84 802B7514 C600002C */  lwc1      $f0, 0x2c($s0)
/* E21D88 802B7518 44821000 */  mtc1      $v0, $f2
/* E21D8C 802B751C 00000000 */  nop
/* E21D90 802B7520 468010A0 */  cvt.s.w   $f2, $f2
/* E21D94 802B7524 46020000 */  add.s     $f0, $f0, $f2
/* E21D98 802B7528 3C014120 */  lui       $at, 0x4120
/* E21D9C 802B752C 44811000 */  mtc1      $at, $f2
/* E21DA0 802B7530 8E220000 */  lw        $v0, ($s1)
/* E21DA4 802B7534 46020000 */  add.s     $f0, $f0, $f2
/* E21DA8 802B7538 C4420004 */  lwc1      $f2, 4($v0)
/* E21DAC 802B753C 46020001 */  sub.s     $f0, $f0, $f2
/* E21DB0 802B7540 3C013FC0 */  lui       $at, 0x3fc0
/* E21DB4 802B7544 44812000 */  mtc1      $at, $f4
/* E21DB8 802B7548 00000000 */  nop
/* E21DBC 802B754C 46040003 */  div.s     $f0, $f0, $f4
/* E21DC0 802B7550 46001080 */  add.s     $f2, $f2, $f0
/* E21DC4 802B7554 E4420004 */  swc1      $f2, 4($v0)
/* E21DC8 802B7558 C6000028 */  lwc1      $f0, 0x28($s0)
/* E21DCC 802B755C E4400000 */  swc1      $f0, ($v0)
/* E21DD0 802B7560 C6000030 */  lwc1      $f0, 0x30($s0)
/* E21DD4 802B7564 0C0ADC13 */  jal       func_802B704C
/* E21DD8 802B7568 E4400008 */   swc1     $f0, 8($v0)
/* E21DDC 802B756C 14400008 */  bnez      $v0, .L802B7590
/* E21DE0 802B7570 24020001 */   addiu    $v0, $zero, 1
/* E21DE4 802B7574 8E020004 */  lw        $v0, 4($s0)
/* E21DE8 802B7578 2403FFBF */  addiu     $v1, $zero, -0x41
/* E21DEC 802B757C 3C018011 */  lui       $at, %hi(D_8010C920)
/* E21DF0 802B7580 AC20C920 */  sw        $zero, %lo(D_8010C920)($at)
/* E21DF4 802B7584 00431024 */  and       $v0, $v0, $v1
/* E21DF8 802B7588 080ADD8B */  j         .L802B762C
/* E21DFC 802B758C AE020004 */   sw       $v0, 4($s0)
.L802B7590:
/* E21E00 802B7590 8E240000 */  lw        $a0, ($s1)
/* E21E04 802B7594 8C830024 */  lw        $v1, 0x24($a0)
/* E21E08 802B7598 10620017 */  beq       $v1, $v0, .L802B75F8
/* E21E0C 802B759C 28620002 */   slti     $v0, $v1, 2
/* E21E10 802B75A0 50400005 */  beql      $v0, $zero, .L802B75B8
/* E21E14 802B75A4 24020002 */   addiu    $v0, $zero, 2
/* E21E18 802B75A8 10600007 */  beqz      $v1, .L802B75C8
/* E21E1C 802B75AC 00000000 */   nop
/* E21E20 802B75B0 080ADD8B */  j         .L802B762C
/* E21E24 802B75B4 00000000 */   nop
.L802B75B8:
/* E21E28 802B75B8 10620015 */  beq       $v1, $v0, .L802B7610
/* E21E2C 802B75BC 00000000 */   nop
/* E21E30 802B75C0 080ADD8B */  j         .L802B762C
/* E21E34 802B75C4 00000000 */   nop
.L802B75C8:
/* E21E38 802B75C8 8C820018 */  lw        $v0, 0x18($a0)
/* E21E3C 802B75CC 0040182D */  daddu     $v1, $v0, $zero
/* E21E40 802B75D0 24420001 */  addiu     $v0, $v0, 1
/* E21E44 802B75D4 28630006 */  slti      $v1, $v1, 6
/* E21E48 802B75D8 14600014 */  bnez      $v1, .L802B762C
/* E21E4C 802B75DC AC820018 */   sw       $v0, 0x18($a0)
/* E21E50 802B75E0 8C820024 */  lw        $v0, 0x24($a0)
/* E21E54 802B75E4 3C013EB8 */  lui       $at, 0x3eb8
/* E21E58 802B75E8 342151EC */  ori       $at, $at, 0x51ec
/* E21E5C 802B75EC 44810000 */  mtc1      $at, $f0
/* E21E60 802B75F0 080ADD89 */  j         .L802B7624
/* E21E64 802B75F4 24420001 */   addiu    $v0, $v0, 1
.L802B75F8:
/* E21E68 802B75F8 8C820024 */  lw        $v0, 0x24($a0)
/* E21E6C 802B75FC 3C013F11 */  lui       $at, 0x3f11
/* E21E70 802B7600 3421EB85 */  ori       $at, $at, 0xeb85
/* E21E74 802B7604 44810000 */  mtc1      $at, $f0
/* E21E78 802B7608 080ADD89 */  j         .L802B7624
/* E21E7C 802B760C 24420001 */   addiu    $v0, $v0, 1
.L802B7610:
/* E21E80 802B7610 8C820024 */  lw        $v0, 0x24($a0)
/* E21E84 802B7614 3C013F07 */  lui       $at, 0x3f07
/* E21E88 802B7618 3421AE14 */  ori       $at, $at, 0xae14
/* E21E8C 802B761C 44810000 */  mtc1      $at, $f0
/* E21E90 802B7620 24420001 */  addiu     $v0, $v0, 1
.L802B7624:
/* E21E94 802B7624 E480000C */  swc1      $f0, 0xc($a0)
/* E21E98 802B7628 AC820024 */  sw        $v0, 0x24($a0)
.L802B762C:
/* E21E9C 802B762C 8FBF0018 */  lw        $ra, 0x18($sp)
/* E21EA0 802B7630 8FB10014 */  lw        $s1, 0x14($sp)
/* E21EA4 802B7634 8FB00010 */  lw        $s0, 0x10($sp)
/* E21EA8 802B7638 03E00008 */  jr        $ra
/* E21EAC 802B763C 27BD0020 */   addiu    $sp, $sp, 0x20
