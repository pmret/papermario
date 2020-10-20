.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DAC
/* 84497C 80241DAC 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 844980 80241DB0 AFB1009C */  sw        $s1, 0x9c($sp)
/* 844984 80241DB4 0080882D */  daddu     $s1, $a0, $zero
/* 844988 80241DB8 0000202D */  daddu     $a0, $zero, $zero
/* 84498C 80241DBC 3C05FD05 */  lui       $a1, 0xfd05
/* 844990 80241DC0 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* 844994 80241DC4 AFB00098 */  sw        $s0, 0x98($sp)
/* 844998 80241DC8 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* 84499C 80241DCC F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* 8449A0 80241DD0 0C0B210B */  jal       get_float_variable
/* 8449A4 80241DD4 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 8449A8 80241DD8 44801000 */  mtc1      $zero, $f2
/* 8449AC 80241DDC 3C013F80 */  lui       $at, 0x3f80
/* 8449B0 80241DE0 4481B000 */  mtc1      $at, $f22
/* 8449B4 80241DE4 27A40018 */  addiu     $a0, $sp, 0x18
/* 8449B8 80241DE8 E7A20010 */  swc1      $f2, 0x10($sp)
/* 8449BC 80241DEC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* 8449C0 80241DF0 44061000 */  mfc1      $a2, $f2
/* 8449C4 80241DF4 4407B000 */  mfc1      $a3, $f22
/* 8449C8 80241DF8 0C019EC8 */  jal       guRotateF
/* 8449CC 80241DFC 46000506 */   mov.s    $f20, $f0
/* 8449D0 80241E00 3C018025 */  lui       $at, 0x8025
/* 8449D4 80241E04 D420F580 */  ldc1      $f0, -0xa80($at)
/* 8449D8 80241E08 4600A521 */  cvt.d.s   $f20, $f20
/* 8449DC 80241E0C 4620A502 */  mul.d     $f20, $f20, $f0
/* 8449E0 80241E10 00000000 */  nop       
/* 8449E4 80241E14 27B00058 */  addiu     $s0, $sp, 0x58
/* 8449E8 80241E18 4620A520 */  cvt.s.d   $f20, $f20
/* 8449EC 80241E1C 4405A000 */  mfc1      $a1, $f20
/* 8449F0 80241E20 0200202D */  daddu     $a0, $s0, $zero
/* 8449F4 80241E24 00A0302D */  daddu     $a2, $a1, $zero
/* 8449F8 80241E28 0C019DF0 */  jal       guScaleF
/* 8449FC 80241E2C 00A0382D */   daddu    $a3, $a1, $zero
/* 844A00 80241E30 27A40018 */  addiu     $a0, $sp, 0x18
/* 844A04 80241E34 0200282D */  daddu     $a1, $s0, $zero
/* 844A08 80241E38 0C019D80 */  jal       guMtxCatF
/* 844A0C 80241E3C 0080302D */   daddu    $a2, $a0, $zero
/* 844A10 80241E40 8E250028 */  lw        $a1, 0x28($s1)
/* 844A14 80241E44 8E26002C */  lw        $a2, 0x2c($s1)
/* 844A18 80241E48 8E270030 */  lw        $a3, 0x30($s1)
/* 844A1C 80241E4C 0C019E40 */  jal       guTranslateF
/* 844A20 80241E50 0200202D */   daddu    $a0, $s0, $zero
/* 844A24 80241E54 27A40018 */  addiu     $a0, $sp, 0x18
/* 844A28 80241E58 0200282D */  daddu     $a1, $s0, $zero
/* 844A2C 80241E5C 0C019D80 */  jal       guMtxCatF
/* 844A30 80241E60 0080302D */   daddu    $a2, $a0, $zero
/* 844A34 80241E64 8E2500A4 */  lw        $a1, 0xa4($s1)
/* 844A38 80241E68 4406B000 */  mfc1      $a2, $f22
/* 844A3C 80241E6C 0C0B76A3 */  jal       func_802DDA8C
/* 844A40 80241E70 0000202D */   daddu    $a0, $zero, $zero
/* 844A44 80241E74 0000202D */  daddu     $a0, $zero, $zero
/* 844A48 80241E78 0080282D */  daddu     $a1, $a0, $zero
/* 844A4C 80241E7C 0080302D */  daddu     $a2, $a0, $zero
/* 844A50 80241E80 0080382D */  daddu     $a3, $a0, $zero
/* 844A54 80241E84 A62200BC */  sh        $v0, 0xbc($s1)
/* 844A58 80241E88 27A20018 */  addiu     $v0, $sp, 0x18
/* 844A5C 80241E8C 0C0B7710 */  jal       render_sprite
/* 844A60 80241E90 AFA20010 */   sw       $v0, 0x10($sp)
/* 844A64 80241E94 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* 844A68 80241E98 8FB1009C */  lw        $s1, 0x9c($sp)
/* 844A6C 80241E9C 8FB00098 */  lw        $s0, 0x98($sp)
/* 844A70 80241EA0 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* 844A74 80241EA4 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* 844A78 80241EA8 03E00008 */  jr        $ra
/* 844A7C 80241EAC 27BD00B8 */   addiu    $sp, $sp, 0xb8
