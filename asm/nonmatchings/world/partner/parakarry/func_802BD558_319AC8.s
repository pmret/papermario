.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD558_319AC8
/* 319AC8 802BD558 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 319ACC 802BD55C AFB00048 */  sw        $s0, 0x48($sp)
/* 319AD0 802BD560 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 319AD4 802BD564 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 319AD8 802BD568 AFBF0050 */  sw        $ra, 0x50($sp)
/* 319ADC 802BD56C AFB1004C */  sw        $s1, 0x4c($sp)
/* 319AE0 802BD570 860200B0 */  lh        $v0, 0xb0($s0)
/* 319AE4 802BD574 3C013FE0 */  lui       $at, 0x3fe0
/* 319AE8 802BD578 44810800 */  mtc1      $at, $f1
/* 319AEC 802BD57C 44800000 */  mtc1      $zero, $f0
/* 319AF0 802BD580 44823000 */  mtc1      $v0, $f6
/* 319AF4 802BD584 00000000 */  nop
/* 319AF8 802BD588 468031A0 */  cvt.s.w   $f6, $f6
/* 319AFC 802BD58C 460030A1 */  cvt.d.s   $f2, $f6
/* 319B00 802BD590 46201082 */  mul.d     $f2, $f2, $f0
/* 319B04 802BD594 00000000 */  nop
/* 319B08 802BD598 0200202D */  daddu     $a0, $s0, $zero
/* 319B0C 802BD59C 27A50028 */  addiu     $a1, $sp, 0x28
/* 319B10 802BD5A0 27A6002C */  addiu     $a2, $sp, 0x2c
/* 319B14 802BD5A4 27A70030 */  addiu     $a3, $sp, 0x30
/* 319B18 802BD5A8 3C013F00 */  lui       $at, 0x3f00
/* 319B1C 802BD5AC 44810000 */  mtc1      $at, $f0
/* 319B20 802BD5B0 C6040028 */  lwc1      $f4, 0x28($s0)
/* 319B24 802BD5B4 46003182 */  mul.s     $f6, $f6, $f0
/* 319B28 802BD5B8 00000000 */  nop
/* 319B2C 802BD5BC C600002C */  lwc1      $f0, 0x2c($s0)
/* 319B30 802BD5C0 27A20034 */  addiu     $v0, $sp, 0x34
/* 319B34 802BD5C4 E7A40028 */  swc1      $f4, 0x28($sp)
/* 319B38 802BD5C8 C6040030 */  lwc1      $f4, 0x30($s0)
/* 319B3C 802BD5CC 46000021 */  cvt.d.s   $f0, $f0
/* 319B40 802BD5D0 46220000 */  add.d     $f0, $f0, $f2
/* 319B44 802BD5D4 E7A40030 */  swc1      $f4, 0x30($sp)
/* 319B48 802BD5D8 E7A60034 */  swc1      $f6, 0x34($sp)
/* 319B4C 802BD5DC 46200020 */  cvt.s.d   $f0, $f0
/* 319B50 802BD5E0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 319B54 802BD5E4 AFA20010 */  sw        $v0, 0x10($sp)
/* 319B58 802BD5E8 27A20038 */  addiu     $v0, $sp, 0x38
/* 319B5C 802BD5EC AFA20014 */  sw        $v0, 0x14($sp)
/* 319B60 802BD5F0 27A2003C */  addiu     $v0, $sp, 0x3c
/* 319B64 802BD5F4 AFA20018 */  sw        $v0, 0x18($sp)
/* 319B68 802BD5F8 27A20040 */  addiu     $v0, $sp, 0x40
/* 319B6C 802BD5FC AFA2001C */  sw        $v0, 0x1c($sp)
/* 319B70 802BD600 27A20044 */  addiu     $v0, $sp, 0x44
/* 319B74 802BD604 0C03791B */  jal       func_800DE46C
/* 319B78 802BD608 AFA20020 */   sw       $v0, 0x20($sp)
/* 319B7C 802BD60C 0040882D */  daddu     $s1, $v0, $zero
/* 319B80 802BD610 0C016F6A */  jal       get_collider_type_by_id
/* 319B84 802BD614 0220202D */   daddu    $a0, $s1, $zero
/* 319B88 802BD618 304200FF */  andi      $v0, $v0, 0xff
/* 319B8C 802BD61C 2442FFFE */  addiu     $v0, $v0, -2
/* 319B90 802BD620 2C420002 */  sltiu     $v0, $v0, 2
/* 319B94 802BD624 10400008 */  beqz      $v0, .L802BD648
/* 319B98 802BD628 24020002 */   addiu    $v0, $zero, 2
/* 319B9C 802BD62C A20200BF */  sb        $v0, 0xbf($s0)
/* 319BA0 802BD630 8E020000 */  lw        $v0, ($s0)
/* 319BA4 802BD634 24030015 */  addiu     $v1, $zero, 0x15
/* 319BA8 802BD638 3C01802C */  lui       $at, %hi(D_802BEBC0)
/* 319BAC 802BD63C AC23EBC0 */  sw        $v1, %lo(D_802BEBC0)($at)
/* 319BB0 802BD640 34420800 */  ori       $v0, $v0, 0x800
/* 319BB4 802BD644 AE020000 */  sw        $v0, ($s0)
.L802BD648:
/* 319BB8 802BD648 0220102D */  daddu     $v0, $s1, $zero
/* 319BBC 802BD64C 8FBF0050 */  lw        $ra, 0x50($sp)
/* 319BC0 802BD650 8FB1004C */  lw        $s1, 0x4c($sp)
/* 319BC4 802BD654 8FB00048 */  lw        $s0, 0x48($sp)
/* 319BC8 802BD658 03E00008 */  jr        $ra
/* 319BCC 802BD65C 27BD0058 */   addiu    $sp, $sp, 0x58
