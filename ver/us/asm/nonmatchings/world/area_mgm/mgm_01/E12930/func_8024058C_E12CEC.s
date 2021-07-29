.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802435E0_E15D40
.double 35.0

.section .text

glabel func_8024058C_E12CEC
/* E12CEC 8024058C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E12CF0 80240590 AFB00010 */  sw        $s0, 0x10($sp)
/* E12CF4 80240594 0080802D */  daddu     $s0, $a0, $zero
/* E12CF8 80240598 AFBF0014 */  sw        $ra, 0x14($sp)
/* E12CFC 8024059C 0C00FB3A */  jal       get_enemy
/* E12D00 802405A0 0000202D */   daddu    $a0, $zero, $zero
/* E12D04 802405A4 8E03000C */  lw        $v1, 0xc($s0)
/* E12D08 802405A8 0200202D */  daddu     $a0, $s0, $zero
/* E12D0C 802405AC 8C650000 */  lw        $a1, ($v1)
/* E12D10 802405B0 0C0B1EAF */  jal       get_variable
/* E12D14 802405B4 8C500080 */   lw       $s0, 0x80($v0)
/* E12D18 802405B8 00021840 */  sll       $v1, $v0, 1
/* E12D1C 802405BC 00621821 */  addu      $v1, $v1, $v0
/* E12D20 802405C0 000318C0 */  sll       $v1, $v1, 3
/* E12D24 802405C4 00621823 */  subu      $v1, $v1, $v0
/* E12D28 802405C8 00031880 */  sll       $v1, $v1, 2
/* E12D2C 802405CC 02038021 */  addu      $s0, $s0, $v1
/* E12D30 802405D0 8E030080 */  lw        $v1, 0x80($s0)
/* E12D34 802405D4 24020005 */  addiu     $v0, $zero, 5
/* E12D38 802405D8 AE00008C */  sw        $zero, 0x8c($s0)
/* E12D3C 802405DC AE020090 */  sw        $v0, 0x90($s0)
/* E12D40 802405E0 3C028024 */  lui       $v0, %hi(D_80241AC8_E14228)
/* E12D44 802405E4 00431021 */  addu      $v0, $v0, $v1
/* E12D48 802405E8 80421AC8 */  lb        $v0, %lo(D_80241AC8_E14228)($v0)
/* E12D4C 802405EC 44820000 */  mtc1      $v0, $f0
/* E12D50 802405F0 00000000 */  nop
/* E12D54 802405F4 46800020 */  cvt.s.w   $f0, $f0
/* E12D58 802405F8 E6000094 */  swc1      $f0, 0x94($s0)
/* E12D5C 802405FC 3C028024 */  lui       $v0, %hi(D_80241AD4_E14234)
/* E12D60 80240600 00431021 */  addu      $v0, $v0, $v1
/* E12D64 80240604 80421AD4 */  lb        $v0, %lo(D_80241AD4_E14234)($v0)
/* E12D68 80240608 3C01402E */  lui       $at, 0x402e
/* E12D6C 8024060C 44811800 */  mtc1      $at, $f3
/* E12D70 80240610 44801000 */  mtc1      $zero, $f2
/* E12D74 80240614 44820000 */  mtc1      $v0, $f0
/* E12D78 80240618 00000000 */  nop
/* E12D7C 8024061C 46800021 */  cvt.d.w   $f0, $f0
/* E12D80 80240620 46220000 */  add.d     $f0, $f0, $f2
/* E12D84 80240624 3C014000 */  lui       $at, 0x4000
/* E12D88 80240628 44813000 */  mtc1      $at, $f6
/* E12D8C 8024062C C6020094 */  lwc1      $f2, 0x94($s0)
/* E12D90 80240630 46200020 */  cvt.s.d   $f0, $f0
/* E12D94 80240634 E6000098 */  swc1      $f0, 0x98($s0)
/* E12D98 80240638 3C018024 */  lui       $at, %hi(D_80241AE0_E14240)
/* E12D9C 8024063C 00230821 */  addu      $at, $at, $v1
/* E12DA0 80240640 80231AE0 */  lb        $v1, %lo(D_80241AE0_E14240)($at)
/* E12DA4 80240644 3C013F80 */  lui       $at, 0x3f80
/* E12DA8 80240648 44810000 */  mtc1      $at, $f0
/* E12DAC 8024064C 46001106 */  mov.s     $f4, $f2
/* E12DB0 80240650 E60400AC */  swc1      $f4, 0xac($s0)
/* E12DB4 80240654 C6040098 */  lwc1      $f4, 0x98($s0)
/* E12DB8 80240658 E60200A0 */  swc1      $f2, 0xa0($s0)
/* E12DBC 8024065C AE0000B8 */  sw        $zero, 0xb8($s0)
/* E12DC0 80240660 E60600CC */  swc1      $f6, 0xcc($s0)
/* E12DC4 80240664 2463000C */  addiu     $v1, $v1, 0xc
/* E12DC8 80240668 E60000C4 */  swc1      $f0, 0xc4($s0)
/* E12DCC 8024066C E60000C8 */  swc1      $f0, 0xc8($s0)
/* E12DD0 80240670 46002006 */  mov.s     $f0, $f4
/* E12DD4 80240674 44831000 */  mtc1      $v1, $f2
/* E12DD8 80240678 00000000 */  nop
/* E12DDC 8024067C 468010A0 */  cvt.s.w   $f2, $f2
/* E12DE0 80240680 E602009C */  swc1      $f2, 0x9c($s0)
/* E12DE4 80240684 46001186 */  mov.s     $f6, $f2
/* E12DE8 80240688 3C018024 */  lui       $at, %hi(D_802435E0_E15D40)
/* E12DEC 8024068C D42235E0 */  ldc1      $f2, %lo(D_802435E0_E15D40)($at)
/* E12DF0 80240690 46000021 */  cvt.d.s   $f0, $f0
/* E12DF4 80240694 E60400A4 */  swc1      $f4, 0xa4($s0)
/* E12DF8 80240698 46003106 */  mov.s     $f4, $f6
/* E12DFC 8024069C 46220000 */  add.d     $f0, $f0, $f2
/* E12E00 802406A0 E60600A8 */  swc1      $f6, 0xa8($s0)
/* E12E04 802406A4 E60400B4 */  swc1      $f4, 0xb4($s0)
/* E12E08 802406A8 46200020 */  cvt.s.d   $f0, $f0
/* E12E0C 802406AC E60000B0 */  swc1      $f0, 0xb0($s0)
/* E12E10 802406B0 8FBF0014 */  lw        $ra, 0x14($sp)
/* E12E14 802406B4 8FB00010 */  lw        $s0, 0x10($sp)
/* E12E18 802406B8 24020002 */  addiu     $v0, $zero, 2
/* E12E1C 802406BC 03E00008 */  jr        $ra
/* E12E20 802406C0 27BD0018 */   addiu    $sp, $sp, 0x18
