.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242F38_980A08
.double 0.7142857142857143

.section .text

glabel func_80241B28_97F5F8
/* 97F5F8 80241B28 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 97F5FC 80241B2C AFBF0028 */  sw        $ra, 0x28($sp)
/* 97F600 80241B30 AFB10024 */  sw        $s1, 0x24($sp)
/* 97F604 80241B34 AFB00020 */  sw        $s0, 0x20($sp)
/* 97F608 80241B38 8C820148 */  lw        $v0, 0x148($a0)
/* 97F60C 80241B3C 0C00EABB */  jal       get_npc_unsafe
/* 97F610 80241B40 84440008 */   lh       $a0, 8($v0)
/* 97F614 80241B44 27A40010 */  addiu     $a0, $sp, 0x10
/* 97F618 80241B48 24050035 */  addiu     $a1, $zero, 0x35
/* 97F61C 80241B4C 3C108024 */  lui       $s0, %hi(D_80242614_9800E4)
/* 97F620 80241B50 26102614 */  addiu     $s0, $s0, %lo(D_80242614_9800E4)
/* 97F624 80241B54 00A0182D */  daddu     $v1, $a1, $zero
/* 97F628 80241B58 0040882D */  daddu     $s1, $v0, $zero
/* 97F62C 80241B5C 0000302D */  daddu     $a2, $zero, $zero
/* 97F630 80241B60 AE030008 */  sw        $v1, 8($s0)
/* 97F634 80241B64 0C0B7A76 */  jal       spr_get_npc_raster_info
/* 97F638 80241B68 AE00000C */   sw       $zero, 0xc($s0)
/* 97F63C 80241B6C C7A6001C */  lwc1      $f6, 0x1c($sp)
/* 97F640 80241B70 468031A0 */  cvt.s.w   $f6, $f6
/* 97F644 80241B74 3C018024 */  lui       $at, %hi(D_80242F38_980A08)
/* 97F648 80241B78 D4202F38 */  ldc1      $f0, %lo(D_80242F38_980A08)($at)
/* 97F64C 80241B7C 460030A1 */  cvt.d.s   $f2, $f6
/* 97F650 80241B80 46201082 */  mul.d     $f2, $f2, $f0
/* 97F654 80241B84 00000000 */  nop
/* 97F658 80241B88 3C013FE0 */  lui       $at, 0x3fe0
/* 97F65C 80241B8C 44812800 */  mtc1      $at, $f5
/* 97F660 80241B90 44802000 */  mtc1      $zero, $f4
/* 97F664 80241B94 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 97F668 80241B98 46800020 */  cvt.s.w   $f0, $f0
/* 97F66C 80241B9C E600003C */  swc1      $f0, 0x3c($s0)
/* 97F670 80241BA0 46241082 */  mul.d     $f2, $f2, $f4
/* 97F674 80241BA4 00000000 */  nop
/* 97F678 80241BA8 E6060040 */  swc1      $f6, 0x40($s0)
/* 97F67C 80241BAC C6200038 */  lwc1      $f0, 0x38($s1)
/* 97F680 80241BB0 E6000010 */  swc1      $f0, 0x10($s0)
/* 97F684 80241BB4 C620003C */  lwc1      $f0, 0x3c($s1)
/* 97F688 80241BB8 46000021 */  cvt.d.s   $f0, $f0
/* 97F68C 80241BBC 46220000 */  add.d     $f0, $f0, $f2
/* 97F690 80241BC0 0000202D */  daddu     $a0, $zero, $zero
/* 97F694 80241BC4 3C0142AA */  lui       $at, 0x42aa
/* 97F698 80241BC8 44811000 */  mtc1      $at, $f2
/* 97F69C 80241BCC 46200020 */  cvt.s.d   $f0, $f0
/* 97F6A0 80241BD0 E6000014 */  swc1      $f0, 0x14($s0)
/* 97F6A4 80241BD4 C6240040 */  lwc1      $f4, 0x40($s1)
/* 97F6A8 80241BD8 3C013F36 */  lui       $at, 0x3f36
/* 97F6AC 80241BDC 3421DB6E */  ori       $at, $at, 0xdb6e
/* 97F6B0 80241BE0 44810000 */  mtc1      $at, $f0
/* 97F6B4 80241BE4 3C058024 */  lui       $a1, %hi(func_80241610_97F0E0)
/* 97F6B8 80241BE8 24A51610 */  addiu     $a1, $a1, %lo(func_80241610_97F0E0)
/* 97F6BC 80241BEC AE00001C */  sw        $zero, 0x1c($s0)
/* 97F6C0 80241BF0 AE000020 */  sw        $zero, 0x20($s0)
/* 97F6C4 80241BF4 AE000024 */  sw        $zero, 0x24($s0)
/* 97F6C8 80241BF8 E6020034 */  swc1      $f2, 0x34($s0)
/* 97F6CC 80241BFC AE000038 */  sw        $zero, 0x38($s0)
/* 97F6D0 80241C00 AE000000 */  sw        $zero, ($s0)
/* 97F6D4 80241C04 E6000028 */  swc1      $f0, 0x28($s0)
/* 97F6D8 80241C08 E600002C */  swc1      $f0, 0x2c($s0)
/* 97F6DC 80241C0C E6000030 */  swc1      $f0, 0x30($s0)
/* 97F6E0 80241C10 0C048C8F */  jal       create_generic_entity_frontUI
/* 97F6E4 80241C14 E6040018 */   swc1     $f4, 0x18($s0)
/* 97F6E8 80241C18 AE020004 */  sw        $v0, 4($s0)
/* 97F6EC 80241C1C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 97F6F0 80241C20 8FB10024 */  lw        $s1, 0x24($sp)
/* 97F6F4 80241C24 8FB00020 */  lw        $s0, 0x20($sp)
/* 97F6F8 80241C28 24020002 */  addiu     $v0, $zero, 2
/* 97F6FC 80241C2C 03E00008 */  jr        $ra
/* 97F700 80241C30 27BD0030 */   addiu    $sp, $sp, 0x30
