.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8024F1F0_A39430
.word L8024297C_A2CBBC, L802429EC_A2CC2C, L80242A5C_A2CC9C, L80242ACC_A2CD0C, L80242BB8_A2CDF8, L80242C28_A2CE68

glabel D_8024F208_A39448
.double 51.43

glabel D_8024F210_A39450
.double 360.01

glabel D_8024F218_A39458
.double 154.29

glabel D_8024F220_A39460
.double 205.72

glabel D_8024F228_A39468
.double 308.58

glabel D_8024F230_A39470
.double 102.86

glabel D_8024F238_A39478
.double 257.15

.section .text

glabel func_802428C8_A2CB08
/* A2CB08 802428C8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A2CB0C 802428CC AFB30024 */  sw        $s3, 0x24($sp)
/* A2CB10 802428D0 0080982D */  daddu     $s3, $a0, $zero
/* A2CB14 802428D4 AFBF0034 */  sw        $ra, 0x34($sp)
/* A2CB18 802428D8 AFB60030 */  sw        $s6, 0x30($sp)
/* A2CB1C 802428DC AFB5002C */  sw        $s5, 0x2c($sp)
/* A2CB20 802428E0 AFB40028 */  sw        $s4, 0x28($sp)
/* A2CB24 802428E4 AFB20020 */  sw        $s2, 0x20($sp)
/* A2CB28 802428E8 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2CB2C 802428EC AFB00018 */  sw        $s0, 0x18($sp)
/* A2CB30 802428F0 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A2CB34 802428F4 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A2CB38 802428F8 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A2CB3C 802428FC F7B80048 */  sdc1      $f24, 0x48($sp)
/* A2CB40 80242900 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A2CB44 80242904 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A2CB48 80242908 8E70000C */  lw        $s0, 0xc($s3)
/* A2CB4C 8024290C 8E050000 */  lw        $a1, ($s0)
/* A2CB50 80242910 0C0B1EAF */  jal       evt_get_variable
/* A2CB54 80242914 26100004 */   addiu    $s0, $s0, 4
/* A2CB58 80242918 8E050000 */  lw        $a1, ($s0)
/* A2CB5C 8024291C 26100004 */  addiu     $s0, $s0, 4
/* A2CB60 80242920 0260202D */  daddu     $a0, $s3, $zero
/* A2CB64 80242924 0C0B210B */  jal       evt_get_float_variable
/* A2CB68 80242928 0040B02D */   daddu    $s6, $v0, $zero
/* A2CB6C 8024292C 8E050000 */  lw        $a1, ($s0)
/* A2CB70 80242930 0260202D */  daddu     $a0, $s3, $zero
/* A2CB74 80242934 0C0B210B */  jal       evt_get_float_variable
/* A2CB78 80242938 E7A00010 */   swc1     $f0, 0x10($sp)
/* A2CB7C 8024293C 0260202D */  daddu     $a0, $s3, $zero
/* A2CB80 80242940 3C05F4AC */  lui       $a1, 0xf4ac
/* A2CB84 80242944 34A5D480 */  ori       $a1, $a1, 0xd480
/* A2CB88 80242948 0C0B1EAF */  jal       evt_get_variable
/* A2CB8C 8024294C 46000706 */   mov.s    $f28, $f0
/* A2CB90 80242950 0040202D */  daddu     $a0, $v0, $zero
/* A2CB94 80242954 26C3FFFF */  addiu     $v1, $s6, -1
/* A2CB98 80242958 2C620006 */  sltiu     $v0, $v1, 6
/* A2CB9C 8024295C 104000CE */  beqz      $v0, .L80242C98
/* A2CBA0 80242960 0080882D */   daddu    $s1, $a0, $zero
/* A2CBA4 80242964 00031080 */  sll       $v0, $v1, 2
/* A2CBA8 80242968 3C018025 */  lui       $at, %hi(jtbl_8024F1F0_A39430)
/* A2CBAC 8024296C 00220821 */  addu      $at, $at, $v0
/* A2CBB0 80242970 8C22F1F0 */  lw        $v0, %lo(jtbl_8024F1F0_A39430)($at)
/* A2CBB4 80242974 00400008 */  jr        $v0
/* A2CBB8 80242978 00000000 */   nop
glabel L8024297C_A2CBBC
/* A2CBBC 8024297C 3C108025 */  lui       $s0, %hi(D_8024F3F8)
/* A2CBC0 80242980 2610F3F8 */  addiu     $s0, $s0, %lo(D_8024F3F8)
/* A2CBC4 80242984 0200902D */  daddu     $s2, $s0, $zero
/* A2CBC8 80242988 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CBCC 8024298C 8E22000C */  lw        $v0, 0xc($s1)
/* A2CBD0 80242990 8C420014 */  lw        $v0, 0x14($v0)
/* A2CBD4 80242994 3C0142B4 */  lui       $at, 0x42b4
/* A2CBD8 80242998 4481F000 */  mtc1      $at, $f30
/* A2CBDC 8024299C 00551021 */  addu      $v0, $v0, $s5
/* A2CBE0 802429A0 44821000 */  mtc1      $v0, $f2
/* A2CBE4 802429A4 00000000 */  nop
/* A2CBE8 802429A8 468010A1 */  cvt.d.w   $f2, $f2
/* A2CBEC 802429AC 04410006 */  bgez      $v0, .L802429C8
/* A2CBF0 802429B0 24140003 */   addiu    $s4, $zero, 3
/* A2CBF4 802429B4 3C0141F0 */  lui       $at, 0x41f0
/* A2CBF8 802429B8 44810800 */  mtc1      $at, $f1
/* A2CBFC 802429BC 44800000 */  mtc1      $zero, $f0
/* A2CC00 802429C0 00000000 */  nop
/* A2CC04 802429C4 46201080 */  add.d     $f2, $f2, $f0
.L802429C8:
/* A2CC08 802429C8 3C014080 */  lui       $at, 0x4080
/* A2CC0C 802429CC 44810000 */  mtc1      $at, $f0
/* A2CC10 802429D0 46201520 */  cvt.s.d   $f20, $f2
/* A2CC14 802429D4 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CC18 802429D8 00000000 */  nop
/* A2CC1C 802429DC 3C018025 */  lui       $at, %hi(D_8024F208_A39448)
/* A2CC20 802429E0 D420F208 */  ldc1      $f0, %lo(D_8024F208_A39448)($at)
/* A2CC24 802429E4 08090B41 */  j         .L80242D04
/* A2CC28 802429E8 4600A521 */   cvt.d.s  $f20, $f20
glabel L802429EC_A2CC2C
/* A2CC2C 802429EC 3C108025 */  lui       $s0, %hi(D_8024F420_C0CCA0)
/* A2CC30 802429F0 2610F420 */  addiu     $s0, $s0, %lo(D_8024F420_C0CCA0)
/* A2CC34 802429F4 0200902D */  daddu     $s2, $s0, $zero
/* A2CC38 802429F8 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CC3C 802429FC 8E22000C */  lw        $v0, 0xc($s1)
/* A2CC40 80242A00 8C420014 */  lw        $v0, 0x14($v0)
/* A2CC44 80242A04 3C0142B4 */  lui       $at, 0x42b4
/* A2CC48 80242A08 4481F000 */  mtc1      $at, $f30
/* A2CC4C 80242A0C 00551021 */  addu      $v0, $v0, $s5
/* A2CC50 80242A10 44821000 */  mtc1      $v0, $f2
/* A2CC54 80242A14 00000000 */  nop
/* A2CC58 80242A18 468010A1 */  cvt.d.w   $f2, $f2
/* A2CC5C 80242A1C 04410006 */  bgez      $v0, .L80242A38
/* A2CC60 80242A20 24140003 */   addiu    $s4, $zero, 3
/* A2CC64 80242A24 3C0141F0 */  lui       $at, 0x41f0
/* A2CC68 80242A28 44810800 */  mtc1      $at, $f1
/* A2CC6C 80242A2C 44800000 */  mtc1      $zero, $f0
/* A2CC70 80242A30 00000000 */  nop
/* A2CC74 80242A34 46201080 */  add.d     $f2, $f2, $f0
.L80242A38:
/* A2CC78 80242A38 3C014080 */  lui       $at, 0x4080
/* A2CC7C 80242A3C 44810000 */  mtc1      $at, $f0
/* A2CC80 80242A40 46201520 */  cvt.s.d   $f20, $f2
/* A2CC84 80242A44 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CC88 80242A48 00000000 */  nop
/* A2CC8C 80242A4C 3C018025 */  lui       $at, %hi(D_8024F210_A39450)
/* A2CC90 80242A50 D420F210 */  ldc1      $f0, %lo(D_8024F210_A39450)($at)
/* A2CC94 80242A54 08090B41 */  j         .L80242D04
/* A2CC98 80242A58 4600A521 */   cvt.d.s  $f20, $f20
glabel L80242A5C_A2CC9C
/* A2CC9C 80242A5C 3C108025 */  lui       $s0, %hi(D_8024F448)
/* A2CCA0 80242A60 2610F448 */  addiu     $s0, $s0, %lo(D_8024F448)
/* A2CCA4 80242A64 0200902D */  daddu     $s2, $s0, $zero
/* A2CCA8 80242A68 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CCAC 80242A6C 8E22000C */  lw        $v0, 0xc($s1)
/* A2CCB0 80242A70 8C420014 */  lw        $v0, 0x14($v0)
/* A2CCB4 80242A74 3C0142B4 */  lui       $at, 0x42b4
/* A2CCB8 80242A78 4481F000 */  mtc1      $at, $f30
/* A2CCBC 80242A7C 00551021 */  addu      $v0, $v0, $s5
/* A2CCC0 80242A80 44821000 */  mtc1      $v0, $f2
/* A2CCC4 80242A84 00000000 */  nop
/* A2CCC8 80242A88 468010A1 */  cvt.d.w   $f2, $f2
/* A2CCCC 80242A8C 04410006 */  bgez      $v0, .L80242AA8
/* A2CCD0 80242A90 24140003 */   addiu    $s4, $zero, 3
/* A2CCD4 80242A94 3C0141F0 */  lui       $at, 0x41f0
/* A2CCD8 80242A98 44810800 */  mtc1      $at, $f1
/* A2CCDC 80242A9C 44800000 */  mtc1      $zero, $f0
/* A2CCE0 80242AA0 00000000 */  nop
/* A2CCE4 80242AA4 46201080 */  add.d     $f2, $f2, $f0
.L80242AA8:
/* A2CCE8 80242AA8 3C014080 */  lui       $at, 0x4080
/* A2CCEC 80242AAC 44810000 */  mtc1      $at, $f0
/* A2CCF0 80242AB0 46201520 */  cvt.s.d   $f20, $f2
/* A2CCF4 80242AB4 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CCF8 80242AB8 00000000 */  nop
/* A2CCFC 80242ABC 3C018025 */  lui       $at, %hi(D_8024F218_A39458)
/* A2CD00 80242AC0 D420F218 */  ldc1      $f0, %lo(D_8024F218_A39458)($at)
/* A2CD04 80242AC4 08090B41 */  j         .L80242D04
/* A2CD08 80242AC8 4600A521 */   cvt.d.s  $f20, $f20
glabel L80242ACC_A2CD0C
/* A2CD0C 80242ACC 3C108025 */  lui       $s0, %hi(D_8024F470)
/* A2CD10 80242AD0 2610F470 */  addiu     $s0, $s0, %lo(D_8024F470)
/* A2CD14 80242AD4 8E22000C */  lw        $v0, 0xc($s1)
/* A2CD18 80242AD8 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CD1C 80242ADC 8C420014 */  lw        $v0, 0x14($v0)
/* A2CD20 80242AE0 3C0142B4 */  lui       $at, 0x42b4
/* A2CD24 80242AE4 4481F000 */  mtc1      $at, $f30
/* A2CD28 80242AE8 00551021 */  addu      $v0, $v0, $s5
/* A2CD2C 80242AEC 44821000 */  mtc1      $v0, $f2
/* A2CD30 80242AF0 00000000 */  nop
/* A2CD34 80242AF4 468010A1 */  cvt.d.w   $f2, $f2
/* A2CD38 80242AF8 04410006 */  bgez      $v0, .L80242B14
/* A2CD3C 80242AFC 0200902D */   daddu    $s2, $s0, $zero
/* A2CD40 80242B00 3C0141F0 */  lui       $at, 0x41f0
/* A2CD44 80242B04 44810800 */  mtc1      $at, $f1
/* A2CD48 80242B08 44800000 */  mtc1      $zero, $f0
/* A2CD4C 80242B0C 00000000 */  nop
/* A2CD50 80242B10 46201080 */  add.d     $f2, $f2, $f0
.L80242B14:
/* A2CD54 80242B14 3C014080 */  lui       $at, 0x4080
/* A2CD58 80242B18 44810000 */  mtc1      $at, $f0
/* A2CD5C 80242B1C 46201520 */  cvt.s.d   $f20, $f2
/* A2CD60 80242B20 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CD64 80242B24 00000000 */  nop
/* A2CD68 80242B28 3C018025 */  lui       $at, %hi(D_8024F220_A39460)
/* A2CD6C 80242B2C D420F220 */  ldc1      $f0, %lo(D_8024F220_A39460)($at)
/* A2CD70 80242B30 4600A521 */  cvt.d.s   $f20, $f20
/* A2CD74 80242B34 4620A500 */  add.d     $f20, $f20, $f0
/* A2CD78 80242B38 4620A520 */  cvt.s.d   $f20, $f20
/* A2CD7C 80242B3C 0C00A8BB */  jal       sin_deg
/* A2CD80 80242B40 4600A306 */   mov.s    $f12, $f20
/* A2CD84 80242B44 4600F306 */  mov.s     $f12, $f30
/* A2CD88 80242B48 3C014248 */  lui       $at, 0x4248
/* A2CD8C 80242B4C 4481B000 */  mtc1      $at, $f22
/* A2CD90 80242B50 0C00A8BB */  jal       sin_deg
/* A2CD94 80242B54 46000606 */   mov.s    $f24, $f0
/* A2CD98 80242B58 46160002 */  mul.s     $f0, $f0, $f22
/* A2CD9C 80242B5C 00000000 */  nop
/* A2CDA0 80242B60 46180002 */  mul.s     $f0, $f0, $f24
/* A2CDA4 80242B64 00000000 */  nop
/* A2CDA8 80242B68 8E22000C */  lw        $v0, 0xc($s1)
/* A2CDAC 80242B6C C4420004 */  lwc1      $f2, 4($v0)
/* A2CDB0 80242B70 46001680 */  add.s     $f26, $f2, $f0
/* A2CDB4 80242B74 0C00A8D4 */  jal       cos_deg
/* A2CDB8 80242B78 4600A306 */   mov.s    $f12, $f20
/* A2CDBC 80242B7C 46160002 */  mul.s     $f0, $f0, $f22
/* A2CDC0 80242B80 00000000 */  nop
/* A2CDC4 80242B84 8E22000C */  lw        $v0, 0xc($s1)
/* A2CDC8 80242B88 C4420008 */  lwc1      $f2, 8($v0)
/* A2CDCC 80242B8C 46001500 */  add.s     $f20, $f2, $f0
/* A2CDD0 80242B90 0C00A8BB */  jal       sin_deg
/* A2CDD4 80242B94 4600F306 */   mov.s    $f12, $f30
/* A2CDD8 80242B98 46160002 */  mul.s     $f0, $f0, $f22
/* A2CDDC 80242B9C 00000000 */  nop
/* A2CDE0 80242BA0 46180002 */  mul.s     $f0, $f0, $f24
/* A2CDE4 80242BA4 00000000 */  nop
/* A2CDE8 80242BA8 8E22000C */  lw        $v0, 0xc($s1)
/* A2CDEC 80242BAC C442000C */  lwc1      $f2, 0xc($v0)
/* A2CDF0 80242BB0 08090B60 */  j         .L80242D80
/* A2CDF4 80242BB4 24140003 */   addiu    $s4, $zero, 3
glabel L80242BB8_A2CDF8
/* A2CDF8 80242BB8 3C108025 */  lui       $s0, %hi(D_8024F498)
/* A2CDFC 80242BBC 2610F498 */  addiu     $s0, $s0, %lo(D_8024F498)
/* A2CE00 80242BC0 0200902D */  daddu     $s2, $s0, $zero
/* A2CE04 80242BC4 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CE08 80242BC8 8E22000C */  lw        $v0, 0xc($s1)
/* A2CE0C 80242BCC 8C420014 */  lw        $v0, 0x14($v0)
/* A2CE10 80242BD0 3C0142B4 */  lui       $at, 0x42b4
/* A2CE14 80242BD4 4481F000 */  mtc1      $at, $f30
/* A2CE18 80242BD8 00551021 */  addu      $v0, $v0, $s5
/* A2CE1C 80242BDC 44821000 */  mtc1      $v0, $f2
/* A2CE20 80242BE0 00000000 */  nop
/* A2CE24 80242BE4 468010A1 */  cvt.d.w   $f2, $f2
/* A2CE28 80242BE8 04410006 */  bgez      $v0, .L80242C04
/* A2CE2C 80242BEC 24140003 */   addiu    $s4, $zero, 3
/* A2CE30 80242BF0 3C0141F0 */  lui       $at, 0x41f0
/* A2CE34 80242BF4 44810800 */  mtc1      $at, $f1
/* A2CE38 80242BF8 44800000 */  mtc1      $zero, $f0
/* A2CE3C 80242BFC 00000000 */  nop
/* A2CE40 80242C00 46201080 */  add.d     $f2, $f2, $f0
.L80242C04:
/* A2CE44 80242C04 3C014080 */  lui       $at, 0x4080
/* A2CE48 80242C08 44810000 */  mtc1      $at, $f0
/* A2CE4C 80242C0C 46201520 */  cvt.s.d   $f20, $f2
/* A2CE50 80242C10 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CE54 80242C14 00000000 */  nop
/* A2CE58 80242C18 3C018025 */  lui       $at, %hi(D_8024F228_A39468)
/* A2CE5C 80242C1C D420F228 */  ldc1      $f0, %lo(D_8024F228_A39468)($at)
/* A2CE60 80242C20 08090B41 */  j         .L80242D04
/* A2CE64 80242C24 4600A521 */   cvt.d.s  $f20, $f20
glabel L80242C28_A2CE68
/* A2CE68 80242C28 3C108025 */  lui       $s0, %hi(D_8024F4C0_C0CD40)
/* A2CE6C 80242C2C 2610F4C0 */  addiu     $s0, $s0, %lo(D_8024F4C0_C0CD40)
/* A2CE70 80242C30 0200902D */  daddu     $s2, $s0, $zero
/* A2CE74 80242C34 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CE78 80242C38 8E22000C */  lw        $v0, 0xc($s1)
/* A2CE7C 80242C3C 8C420014 */  lw        $v0, 0x14($v0)
/* A2CE80 80242C40 3C0142B4 */  lui       $at, 0x42b4
/* A2CE84 80242C44 4481F000 */  mtc1      $at, $f30
/* A2CE88 80242C48 00551021 */  addu      $v0, $v0, $s5
/* A2CE8C 80242C4C 44821000 */  mtc1      $v0, $f2
/* A2CE90 80242C50 00000000 */  nop
/* A2CE94 80242C54 468010A1 */  cvt.d.w   $f2, $f2
/* A2CE98 80242C58 04410006 */  bgez      $v0, .L80242C74
/* A2CE9C 80242C5C 24140003 */   addiu    $s4, $zero, 3
/* A2CEA0 80242C60 3C0141F0 */  lui       $at, 0x41f0
/* A2CEA4 80242C64 44810800 */  mtc1      $at, $f1
/* A2CEA8 80242C68 44800000 */  mtc1      $zero, $f0
/* A2CEAC 80242C6C 00000000 */  nop
/* A2CEB0 80242C70 46201080 */  add.d     $f2, $f2, $f0
.L80242C74:
/* A2CEB4 80242C74 3C014080 */  lui       $at, 0x4080
/* A2CEB8 80242C78 44810000 */  mtc1      $at, $f0
/* A2CEBC 80242C7C 46201520 */  cvt.s.d   $f20, $f2
/* A2CEC0 80242C80 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CEC4 80242C84 00000000 */  nop
/* A2CEC8 80242C88 3C018025 */  lui       $at, %hi(D_8024F230_A39470)
/* A2CECC 80242C8C D420F230 */  ldc1      $f0, %lo(D_8024F230_A39470)($at)
/* A2CED0 80242C90 08090B41 */  j         .L80242D04
/* A2CED4 80242C94 4600A521 */   cvt.d.s  $f20, $f20
.L80242C98:
/* A2CED8 80242C98 3C108025 */  lui       $s0, %hi(D_8024F4E8)
/* A2CEDC 80242C9C 2610F4E8 */  addiu     $s0, $s0, %lo(D_8024F4E8)
/* A2CEE0 80242CA0 0200902D */  daddu     $s2, $s0, $zero
/* A2CEE4 80242CA4 2415001E */  addiu     $s5, $zero, 0x1e
/* A2CEE8 80242CA8 8C82000C */  lw        $v0, 0xc($a0)
/* A2CEEC 80242CAC 8C420014 */  lw        $v0, 0x14($v0)
/* A2CEF0 80242CB0 3C0142B4 */  lui       $at, 0x42b4
/* A2CEF4 80242CB4 4481F000 */  mtc1      $at, $f30
/* A2CEF8 80242CB8 00551021 */  addu      $v0, $v0, $s5
/* A2CEFC 80242CBC 44821000 */  mtc1      $v0, $f2
/* A2CF00 80242CC0 00000000 */  nop
/* A2CF04 80242CC4 468010A1 */  cvt.d.w   $f2, $f2
/* A2CF08 80242CC8 04410006 */  bgez      $v0, .L80242CE4
/* A2CF0C 80242CCC 24140003 */   addiu    $s4, $zero, 3
/* A2CF10 80242CD0 3C0141F0 */  lui       $at, 0x41f0
/* A2CF14 80242CD4 44810800 */  mtc1      $at, $f1
/* A2CF18 80242CD8 44800000 */  mtc1      $zero, $f0
/* A2CF1C 80242CDC 00000000 */  nop
/* A2CF20 80242CE0 46201080 */  add.d     $f2, $f2, $f0
.L80242CE4:
/* A2CF24 80242CE4 3C014080 */  lui       $at, 0x4080
/* A2CF28 80242CE8 44810000 */  mtc1      $at, $f0
/* A2CF2C 80242CEC 46201520 */  cvt.s.d   $f20, $f2
/* A2CF30 80242CF0 4600A502 */  mul.s     $f20, $f20, $f0
/* A2CF34 80242CF4 00000000 */  nop
/* A2CF38 80242CF8 3C018025 */  lui       $at, %hi(D_8024F238_A39478)
/* A2CF3C 80242CFC D420F238 */  ldc1      $f0, %lo(D_8024F238_A39478)($at)
/* A2CF40 80242D00 4600A521 */  cvt.d.s   $f20, $f20
.L80242D04:
/* A2CF44 80242D04 4620A500 */  add.d     $f20, $f20, $f0
/* A2CF48 80242D08 4620A520 */  cvt.s.d   $f20, $f20
/* A2CF4C 80242D0C 0C00A8BB */  jal       sin_deg
/* A2CF50 80242D10 4600A306 */   mov.s    $f12, $f20
/* A2CF54 80242D14 4600F306 */  mov.s     $f12, $f30
/* A2CF58 80242D18 3C014248 */  lui       $at, 0x4248
/* A2CF5C 80242D1C 4481B000 */  mtc1      $at, $f22
/* A2CF60 80242D20 0C00A8BB */  jal       sin_deg
/* A2CF64 80242D24 46000606 */   mov.s    $f24, $f0
/* A2CF68 80242D28 46160002 */  mul.s     $f0, $f0, $f22
/* A2CF6C 80242D2C 00000000 */  nop
/* A2CF70 80242D30 46180002 */  mul.s     $f0, $f0, $f24
/* A2CF74 80242D34 00000000 */  nop
/* A2CF78 80242D38 8E22000C */  lw        $v0, 0xc($s1)
/* A2CF7C 80242D3C C4420004 */  lwc1      $f2, 4($v0)
/* A2CF80 80242D40 46001680 */  add.s     $f26, $f2, $f0
/* A2CF84 80242D44 0C00A8D4 */  jal       cos_deg
/* A2CF88 80242D48 4600A306 */   mov.s    $f12, $f20
/* A2CF8C 80242D4C 46160002 */  mul.s     $f0, $f0, $f22
/* A2CF90 80242D50 00000000 */  nop
/* A2CF94 80242D54 8E22000C */  lw        $v0, 0xc($s1)
/* A2CF98 80242D58 C4420008 */  lwc1      $f2, 8($v0)
/* A2CF9C 80242D5C 46001500 */  add.s     $f20, $f2, $f0
/* A2CFA0 80242D60 0C00A8BB */  jal       sin_deg
/* A2CFA4 80242D64 4600F306 */   mov.s    $f12, $f30
/* A2CFA8 80242D68 46160002 */  mul.s     $f0, $f0, $f22
/* A2CFAC 80242D6C 00000000 */  nop
/* A2CFB0 80242D70 46180002 */  mul.s     $f0, $f0, $f24
/* A2CFB4 80242D74 00000000 */  nop
/* A2CFB8 80242D78 8E22000C */  lw        $v0, 0xc($s1)
/* A2CFBC 80242D7C C442000C */  lwc1      $f2, 0xc($v0)
.L80242D80:
/* A2CFC0 80242D80 46001080 */  add.s     $f2, $f2, $f0
/* A2CFC4 80242D84 E61A0018 */  swc1      $f26, 0x18($s0)
/* A2CFC8 80242D88 E614001C */  swc1      $f20, 0x1c($s0)
/* A2CFCC 80242D8C E6020020 */  swc1      $f2, 0x20($s0)
/* A2CFD0 80242D90 0260202D */  daddu     $a0, $s3, $zero
/* A2CFD4 80242D94 3C05FE36 */  lui       $a1, 0xfe36
/* A2CFD8 80242D98 0C0B210B */  jal       evt_get_float_variable
/* A2CFDC 80242D9C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* A2CFE0 80242DA0 0260202D */  daddu     $a0, $s3, $zero
/* A2CFE4 80242DA4 3C05FE36 */  lui       $a1, 0xfe36
/* A2CFE8 80242DA8 34A53C81 */  ori       $a1, $a1, 0x3c81
/* A2CFEC 80242DAC 0C0B210B */  jal       evt_get_float_variable
/* A2CFF0 80242DB0 E6400000 */   swc1     $f0, ($s2)
/* A2CFF4 80242DB4 0260202D */  daddu     $a0, $s3, $zero
/* A2CFF8 80242DB8 3C05FE36 */  lui       $a1, 0xfe36
/* A2CFFC 80242DBC 34A53C82 */  ori       $a1, $a1, 0x3c82
/* A2D000 80242DC0 0C0B210B */  jal       evt_get_float_variable
/* A2D004 80242DC4 E6400004 */   swc1     $f0, 4($s2)
/* A2D008 80242DC8 26510018 */  addiu     $s1, $s2, 0x18
/* A2D00C 80242DCC E6400008 */  swc1      $f0, 8($s2)
/* A2D010 80242DD0 24020002 */  addiu     $v0, $zero, 2
/* A2D014 80242DD4 12C20028 */  beq       $s6, $v0, .L80242E78
/* A2D018 80242DD8 2652000C */   addiu    $s2, $s2, 0xc
/* A2D01C 80242DDC 0260202D */  daddu     $a0, $s3, $zero
/* A2D020 80242DE0 3C05FE36 */  lui       $a1, 0xfe36
/* A2D024 80242DE4 0C0B210B */  jal       evt_get_float_variable
/* A2D028 80242DE8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* A2D02C 80242DEC 461C0002 */  mul.s     $f0, $f0, $f28
/* A2D030 80242DF0 00000000 */  nop
/* A2D034 80242DF4 3C013F80 */  lui       $at, 0x3f80
/* A2D038 80242DF8 4481A000 */  mtc1      $at, $f20
/* A2D03C 80242DFC 00000000 */  nop
/* A2D040 80242E00 461CA501 */  sub.s     $f20, $f20, $f28
/* A2D044 80242E04 C6220000 */  lwc1      $f2, ($s1)
/* A2D048 80242E08 46141082 */  mul.s     $f2, $f2, $f20
/* A2D04C 80242E0C 00000000 */  nop
/* A2D050 80242E10 0260202D */  daddu     $a0, $s3, $zero
/* A2D054 80242E14 46020000 */  add.s     $f0, $f0, $f2
/* A2D058 80242E18 3C05FE36 */  lui       $a1, 0xfe36
/* A2D05C 80242E1C 34A53C81 */  ori       $a1, $a1, 0x3c81
/* A2D060 80242E20 0C0B210B */  jal       evt_get_float_variable
/* A2D064 80242E24 E6400000 */   swc1     $f0, ($s2)
/* A2D068 80242E28 461C0002 */  mul.s     $f0, $f0, $f28
/* A2D06C 80242E2C 00000000 */  nop
/* A2D070 80242E30 C6220004 */  lwc1      $f2, 4($s1)
/* A2D074 80242E34 46141082 */  mul.s     $f2, $f2, $f20
/* A2D078 80242E38 00000000 */  nop
/* A2D07C 80242E3C 46020000 */  add.s     $f0, $f0, $f2
/* A2D080 80242E40 C7A40010 */  lwc1      $f4, 0x10($sp)
/* A2D084 80242E44 0260202D */  daddu     $a0, $s3, $zero
/* A2D088 80242E48 46040000 */  add.s     $f0, $f0, $f4
/* A2D08C 80242E4C 3C05FE36 */  lui       $a1, 0xfe36
/* A2D090 80242E50 34A53C82 */  ori       $a1, $a1, 0x3c82
/* A2D094 80242E54 0C0B210B */  jal       evt_get_float_variable
/* A2D098 80242E58 E6400004 */   swc1     $f0, 4($s2)
/* A2D09C 80242E5C 461C0002 */  mul.s     $f0, $f0, $f28
/* A2D0A0 80242E60 00000000 */  nop
/* A2D0A4 80242E64 C6220008 */  lwc1      $f2, 8($s1)
/* A2D0A8 80242E68 46141082 */  mul.s     $f2, $f2, $f20
/* A2D0AC 80242E6C 00000000 */  nop
/* A2D0B0 80242E70 08090BC8 */  j         .L80242F20
/* A2D0B4 80242E74 46020000 */   add.s    $f0, $f0, $f2
.L80242E78:
/* A2D0B8 80242E78 0260202D */  daddu     $a0, $s3, $zero
/* A2D0BC 80242E7C 3C05FE36 */  lui       $a1, 0xfe36
/* A2D0C0 80242E80 0C0B210B */  jal       evt_get_float_variable
/* A2D0C4 80242E84 34A53C80 */   ori      $a1, $a1, 0x3c80
/* A2D0C8 80242E88 461C0002 */  mul.s     $f0, $f0, $f28
/* A2D0CC 80242E8C 00000000 */  nop
/* A2D0D0 80242E90 3C013F80 */  lui       $at, 0x3f80
/* A2D0D4 80242E94 4481A000 */  mtc1      $at, $f20
/* A2D0D8 80242E98 00000000 */  nop
/* A2D0DC 80242E9C 461CA501 */  sub.s     $f20, $f20, $f28
/* A2D0E0 80242EA0 C6220000 */  lwc1      $f2, ($s1)
/* A2D0E4 80242EA4 46141082 */  mul.s     $f2, $f2, $f20
/* A2D0E8 80242EA8 00000000 */  nop
/* A2D0EC 80242EAC 46020000 */  add.s     $f0, $f0, $f2
/* A2D0F0 80242EB0 3C014248 */  lui       $at, 0x4248
/* A2D0F4 80242EB4 4481B000 */  mtc1      $at, $f22
/* A2D0F8 80242EB8 0260202D */  daddu     $a0, $s3, $zero
/* A2D0FC 80242EBC 46160001 */  sub.s     $f0, $f0, $f22
/* A2D100 80242EC0 3C05FE36 */  lui       $a1, 0xfe36
/* A2D104 80242EC4 34A53C81 */  ori       $a1, $a1, 0x3c81
/* A2D108 80242EC8 0C0B210B */  jal       evt_get_float_variable
/* A2D10C 80242ECC E6400000 */   swc1     $f0, ($s2)
/* A2D110 80242ED0 461C0002 */  mul.s     $f0, $f0, $f28
/* A2D114 80242ED4 00000000 */  nop
/* A2D118 80242ED8 C6220004 */  lwc1      $f2, 4($s1)
/* A2D11C 80242EDC 46141082 */  mul.s     $f2, $f2, $f20
/* A2D120 80242EE0 00000000 */  nop
/* A2D124 80242EE4 46020000 */  add.s     $f0, $f0, $f2
/* A2D128 80242EE8 C7A40010 */  lwc1      $f4, 0x10($sp)
/* A2D12C 80242EEC 0260202D */  daddu     $a0, $s3, $zero
/* A2D130 80242EF0 46040000 */  add.s     $f0, $f0, $f4
/* A2D134 80242EF4 3C05FE36 */  lui       $a1, 0xfe36
/* A2D138 80242EF8 34A53C82 */  ori       $a1, $a1, 0x3c82
/* A2D13C 80242EFC 0C0B210B */  jal       evt_get_float_variable
/* A2D140 80242F00 E6400004 */   swc1     $f0, 4($s2)
/* A2D144 80242F04 461C0002 */  mul.s     $f0, $f0, $f28
/* A2D148 80242F08 00000000 */  nop
/* A2D14C 80242F0C C6220008 */  lwc1      $f2, 8($s1)
/* A2D150 80242F10 46141082 */  mul.s     $f2, $f2, $f20
/* A2D154 80242F14 00000000 */  nop
/* A2D158 80242F18 46020000 */  add.s     $f0, $f0, $f2
/* A2D15C 80242F1C 46160001 */  sub.s     $f0, $f0, $f22
.L80242F20:
/* A2D160 80242F20 E6400008 */  swc1      $f0, 8($s2)
/* A2D164 80242F24 AE750084 */  sw        $s5, 0x84($s3)
/* A2D168 80242F28 AE700088 */  sw        $s0, 0x88($s3)
/* A2D16C 80242F2C AE74008C */  sw        $s4, 0x8c($s3)
/* A2D170 80242F30 8FBF0034 */  lw        $ra, 0x34($sp)
/* A2D174 80242F34 8FB60030 */  lw        $s6, 0x30($sp)
/* A2D178 80242F38 8FB5002C */  lw        $s5, 0x2c($sp)
/* A2D17C 80242F3C 8FB40028 */  lw        $s4, 0x28($sp)
/* A2D180 80242F40 8FB30024 */  lw        $s3, 0x24($sp)
/* A2D184 80242F44 8FB20020 */  lw        $s2, 0x20($sp)
/* A2D188 80242F48 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2D18C 80242F4C 8FB00018 */  lw        $s0, 0x18($sp)
/* A2D190 80242F50 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A2D194 80242F54 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A2D198 80242F58 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A2D19C 80242F5C D7B80048 */  ldc1      $f24, 0x48($sp)
/* A2D1A0 80242F60 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A2D1A4 80242F64 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A2D1A8 80242F68 24020002 */  addiu     $v0, $zero, 2
/* A2D1AC 80242F6C 03E00008 */  jr        $ra
/* A2D1B0 80242F70 27BD0068 */   addiu    $sp, $sp, 0x68
