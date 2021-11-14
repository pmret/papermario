.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80150580
.double 0.6

.section .text

glabel msg_get_draw_char_width
/* BC4F4 80125DF4 288200F0 */  slti      $v0, $a0, 0xf0
/* BC4F8 80125DF8 44871000 */  mtc1      $a3, $f2
/* BC4FC 80125DFC 8FA70010 */  lw        $a3, 0x10($sp)
/* BC500 80125E00 97A30016 */  lhu       $v1, 0x16($sp)
/* BC504 80125E04 14400004 */  bnez      $v0, .L80125E18
/* BC508 80125E08 2482FF0B */   addiu    $v0, $a0, -0xf5
/* BC50C 80125E0C 2C420003 */  sltiu     $v0, $v0, 3
/* BC510 80125E10 10400037 */  beqz      $v0, .L80125EF0
/* BC514 80125E14 0000102D */   daddu    $v0, $zero, $zero
.L80125E18:
/* BC518 80125E18 10E00005 */  beqz      $a3, .L80125E30
/* BC51C 80125E1C 240200F5 */   addiu    $v0, $zero, 0xf5
/* BC520 80125E20 44870000 */  mtc1      $a3, $f0
/* BC524 80125E24 00000000 */  nop
/* BC528 80125E28 080497B1 */  j         .L80125EC4
/* BC52C 80125E2C 46800020 */   cvt.s.w  $f0, $f0
.L80125E30:
/* BC530 80125E30 30620100 */  andi      $v0, $v1, 0x100
/* BC534 80125E34 10400015 */  beqz      $v0, .L80125E8C
/* BC538 80125E38 00051880 */   sll      $v1, $a1, 2
/* BC53C 80125E3C 00061040 */  sll       $v0, $a2, 1
/* BC540 80125E40 3C01802F */  lui       $at, %hi(gMsgCharsets)
/* BC544 80125E44 00230821 */  addu      $at, $at, $v1
/* BC548 80125E48 8C23B5A8 */  lw        $v1, %lo(gMsgCharsets)($at)
/* BC54C 80125E4C 00461021 */  addu      $v0, $v0, $a2
/* BC550 80125E50 8C630008 */  lw        $v1, 8($v1)
/* BC554 80125E54 00021080 */  sll       $v0, $v0, 2
/* BC558 80125E58 00431021 */  addu      $v0, $v0, $v1
/* BC55C 80125E5C 8C430004 */  lw        $v1, 4($v0)
/* BC560 80125E60 1060000A */  beqz      $v1, .L80125E8C
/* BC564 80125E64 240200F5 */   addiu    $v0, $zero, 0xf5
/* BC568 80125E68 10820008 */  beq       $a0, $v0, .L80125E8C
/* BC56C 80125E6C 240200F6 */   addiu    $v0, $zero, 0xf6
/* BC570 80125E70 10820006 */  beq       $a0, $v0, .L80125E8C
/* BC574 80125E74 240200F7 */   addiu    $v0, $zero, 0xf7
/* BC578 80125E78 10820004 */  beq       $a0, $v0, .L80125E8C
/* BC57C 80125E7C 00641021 */   addu     $v0, $v1, $a0
/* BC580 80125E80 90420000 */  lbu       $v0, ($v0)
/* BC584 80125E84 080497AD */  j         .L80125EB4
/* BC588 80125E88 00000000 */   nop
.L80125E8C:
/* BC58C 80125E8C 00051880 */  sll       $v1, $a1, 2
/* BC590 80125E90 00061040 */  sll       $v0, $a2, 1
/* BC594 80125E94 3C01802F */  lui       $at, %hi(gMsgCharsets)
/* BC598 80125E98 00230821 */  addu      $at, $at, $v1
/* BC59C 80125E9C 8C23B5A8 */  lw        $v1, %lo(gMsgCharsets)($at)
/* BC5A0 80125EA0 00461021 */  addu      $v0, $v0, $a2
/* BC5A4 80125EA4 8C630008 */  lw        $v1, 8($v1)
/* BC5A8 80125EA8 00021080 */  sll       $v0, $v0, 2
/* BC5AC 80125EAC 00431021 */  addu      $v0, $v0, $v1
/* BC5B0 80125EB0 90420008 */  lbu       $v0, 8($v0)
.L80125EB4:
/* BC5B4 80125EB4 44820000 */  mtc1      $v0, $f0
/* BC5B8 80125EB8 00000000 */  nop
/* BC5BC 80125EBC 46800020 */  cvt.s.w   $f0, $f0
/* BC5C0 80125EC0 240200F5 */  addiu     $v0, $zero, 0xf5
.L80125EC4:
/* BC5C4 80125EC4 1482000C */  bne       $a0, $v0, .L80125EF8
/* BC5C8 80125EC8 240200F6 */   addiu    $v0, $zero, 0xf6
/* BC5CC 80125ECC 46020002 */  mul.s     $f0, $f0, $f2
/* BC5D0 80125ED0 00000000 */  nop
/* BC5D4 80125ED4 3C018015 */  lui       $at, %hi(D_80150580)
/* BC5D8 80125ED8 D4220580 */  ldc1      $f2, %lo(D_80150580)($at)
/* BC5DC 80125EDC 46000021 */  cvt.d.s   $f0, $f0
.L80125EE0:
/* BC5E0 80125EE0 46220002 */  mul.d     $f0, $f0, $f2
/* BC5E4 80125EE4 00000000 */  nop
/* BC5E8 80125EE8 4620010D */  trunc.w.d $f4, $f0
/* BC5EC 80125EEC 44022000 */  mfc1      $v0, $f4
.L80125EF0:
/* BC5F0 80125EF0 03E00008 */  jr        $ra
/* BC5F4 80125EF4 00000000 */   nop
.L80125EF8:
/* BC5F8 80125EF8 14820008 */  bne       $a0, $v0, .L80125F1C
/* BC5FC 80125EFC 240200F7 */   addiu    $v0, $zero, 0xf7
/* BC600 80125F00 46020002 */  mul.s     $f0, $f0, $f2
/* BC604 80125F04 00000000 */  nop
/* BC608 80125F08 46000021 */  cvt.d.s   $f0, $f0
/* BC60C 80125F0C 4620010D */  trunc.w.d $f4, $f0
/* BC610 80125F10 44022000 */  mfc1      $v0, $f4
/* BC614 80125F14 03E00008 */  jr        $ra
/* BC618 80125F18 00000000 */   nop
.L80125F1C:
/* BC61C 80125F1C 14820008 */  bne       $a0, $v0, .L80125F40
/* BC620 80125F20 288200F0 */   slti     $v0, $a0, 0xf0
/* BC624 80125F24 46020002 */  mul.s     $f0, $f0, $f2
/* BC628 80125F28 00000000 */  nop
/* BC62C 80125F2C 3C013FE0 */  lui       $at, 0x3fe0
/* BC630 80125F30 44811800 */  mtc1      $at, $f3
/* BC634 80125F34 44801000 */  mtc1      $zero, $f2
/* BC638 80125F38 080497B8 */  j         .L80125EE0
/* BC63C 80125F3C 46000021 */   cvt.d.s  $f0, $f0
.L80125F40:
/* BC640 80125F40 10400007 */  beqz      $v0, .L80125F60
/* BC644 80125F44 00000000 */   nop
/* BC648 80125F48 46020002 */  mul.s     $f0, $f0, $f2
/* BC64C 80125F4C 00000000 */  nop
/* BC650 80125F50 4600010D */  trunc.w.s $f4, $f0
/* BC654 80125F54 44022000 */  mfc1      $v0, $f4
/* BC658 80125F58 03E00008 */  jr        $ra
/* BC65C 80125F5C 00000000 */   nop
.L80125F60:
/* BC660 80125F60 03E00008 */  jr        $ra
/* BC664 80125F64 0000102D */   daddu    $v0, $zero, $zero
