.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240724_9B1EB4
/* 9B1EB4 80240724 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B1EB8 80240728 24040001 */  addiu     $a0, $zero, 1
/* 9B1EBC 8024072C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 9B1EC0 80240730 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 9B1EC4 80240734 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9B1EC8 80240738 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B1ECC 8024073C 846200B2 */  lh        $v0, 0xb2($v1)
/* 9B1ED0 80240740 3C018024 */  lui       $at, %hi(D_802451C0)
/* 9B1ED4 80240744 D42051C0 */  ldc1      $f0, %lo(D_802451C0)($at)
/* 9B1ED8 80240748 3C013F36 */  lui       $at, 0x3f36
/* 9B1EDC 8024074C 3421DB6E */  ori       $at, $at, 0xdb6e
/* 9B1EE0 80240750 44813000 */  mtc1      $at, $f6
/* 9B1EE4 80240754 3C108024 */  lui       $s0, %hi(D_802451F0)
/* 9B1EE8 80240758 261051F0 */  addiu     $s0, $s0, %lo(D_802451F0)
/* 9B1EEC 8024075C AE000000 */  sw        $zero, ($s0)
/* 9B1EF0 80240760 AE000010 */  sw        $zero, 0x10($s0)
/* 9B1EF4 80240764 AE000020 */  sw        $zero, 0x20($s0)
/* 9B1EF8 80240768 AE000024 */  sw        $zero, 0x24($s0)
/* 9B1EFC 8024076C 44826000 */  mtc1      $v0, $f12
/* 9B1F00 80240770 00000000 */  nop       
/* 9B1F04 80240774 46806320 */  cvt.s.w   $f12, $f12
/* 9B1F08 80240778 46006121 */  cvt.d.s   $f4, $f12
/* 9B1F0C 8024077C 46202102 */  mul.d     $f4, $f4, $f0
/* 9B1F10 80240780 00000000 */  nop       
/* 9B1F14 80240784 AE000028 */  sw        $zero, 0x28($s0)
/* 9B1F18 80240788 3C013FE0 */  lui       $at, 0x3fe0
/* 9B1F1C 8024078C 44810800 */  mtc1      $at, $f1
/* 9B1F20 80240790 44800000 */  mtc1      $zero, $f0
/* 9B1F24 80240794 0080102D */  daddu     $v0, $a0, $zero
/* 9B1F28 80240798 AE02000C */  sw        $v0, 0xc($s0)
/* 9B1F2C 8024079C 846200B0 */  lh        $v0, 0xb0($v1)
/* 9B1F30 802407A0 C46A0028 */  lwc1      $f10, 0x28($v1)
/* 9B1F34 802407A4 C4680030 */  lwc1      $f8, 0x30($v1)
/* 9B1F38 802407A8 46202102 */  mul.d     $f4, $f4, $f0
/* 9B1F3C 802407AC 00000000 */  nop       
/* 9B1F40 802407B0 C460002C */  lwc1      $f0, 0x2c($v1)
/* 9B1F44 802407B4 44821000 */  mtc1      $v0, $f2
/* 9B1F48 802407B8 00000000 */  nop       
/* 9B1F4C 802407BC 468010A0 */  cvt.s.w   $f2, $f2
/* 9B1F50 802407C0 E6020038 */  swc1      $f2, 0x38($s0)
/* 9B1F54 802407C4 E60C003C */  swc1      $f12, 0x3c($s0)
/* 9B1F58 802407C8 E60A0014 */  swc1      $f10, 0x14($s0)
/* 9B1F5C 802407CC E608001C */  swc1      $f8, 0x1c($s0)
/* 9B1F60 802407D0 E606002C */  swc1      $f6, 0x2c($s0)
/* 9B1F64 802407D4 46000021 */  cvt.d.s   $f0, $f0
/* 9B1F68 802407D8 46240000 */  add.d     $f0, $f0, $f4
/* 9B1F6C 802407DC E6060030 */  swc1      $f6, 0x30($s0)
/* 9B1F70 802407E0 E6060034 */  swc1      $f6, 0x34($s0)
/* 9B1F74 802407E4 46200020 */  cvt.s.d   $f0, $f0
/* 9B1F78 802407E8 0C04E9C1 */  jal       func_8013A704
/* 9B1F7C 802407EC E6000018 */   swc1     $f0, 0x18($s0)
/* 9B1F80 802407F0 0000202D */  daddu     $a0, $zero, $zero
/* 9B1F84 802407F4 3C058024 */  lui       $a1, %hi(func_80240310_9B1AA0)
/* 9B1F88 802407F8 24A50310 */  addiu     $a1, $a1, %lo(func_80240310_9B1AA0)
/* 9B1F8C 802407FC 0C048C56 */  jal       bind_dynamic_entity_3
/* 9B1F90 80240800 AE020004 */   sw       $v0, 4($s0)
/* 9B1F94 80240804 AE020008 */  sw        $v0, 8($s0)
/* 9B1F98 80240808 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9B1F9C 8024080C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B1FA0 80240810 24020002 */  addiu     $v0, $zero, 2
/* 9B1FA4 80240814 03E00008 */  jr        $ra
/* 9B1FA8 80240818 27BD0018 */   addiu    $sp, $sp, 0x18
