.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243D88_A72168
.double 180.0

glabel D_80243D90_A72170
.double 270.0

.section .text

glabel func_80241870_A6FC50
/* A6FC50 80241870 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A6FC54 80241874 AFB20020 */  sw        $s2, 0x20($sp)
/* A6FC58 80241878 0080902D */  daddu     $s2, $a0, $zero
/* A6FC5C 8024187C AFBF0024 */  sw        $ra, 0x24($sp)
/* A6FC60 80241880 AFB1001C */  sw        $s1, 0x1c($sp)
/* A6FC64 80241884 AFB00018 */  sw        $s0, 0x18($sp)
/* A6FC68 80241888 F7B80038 */  sdc1      $f24, 0x38($sp)
/* A6FC6C 8024188C F7B60030 */  sdc1      $f22, 0x30($sp)
/* A6FC70 80241890 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A6FC74 80241894 8E510148 */  lw        $s1, 0x148($s2)
/* A6FC78 80241898 0C00EABB */  jal       get_npc_unsafe
/* A6FC7C 8024189C 86240008 */   lh       $a0, 8($s1)
/* A6FC80 802418A0 2404000B */  addiu     $a0, $zero, 0xb
/* A6FC84 802418A4 0040802D */  daddu     $s0, $v0, $zero
/* A6FC88 802418A8 C620007C */  lwc1      $f0, 0x7c($s1)
/* A6FC8C 802418AC 46800020 */  cvt.s.w   $f0, $f0
/* A6FC90 802418B0 46000021 */  cvt.d.s   $f0, $f0
/* A6FC94 802418B4 C6360080 */  lwc1      $f22, 0x80($s1)
/* A6FC98 802418B8 4680B5A0 */  cvt.s.w   $f22, $f22
/* A6FC9C 802418BC C6340084 */  lwc1      $f20, 0x84($s1)
/* A6FCA0 802418C0 4680A520 */  cvt.s.w   $f20, $f20
/* A6FCA4 802418C4 4600B5A1 */  cvt.d.s   $f22, $f22
/* A6FCA8 802418C8 4600A521 */  cvt.d.s   $f20, $f20
/* A6FCAC 802418CC 3C014059 */  lui       $at, 0x4059
/* A6FCB0 802418D0 44811800 */  mtc1      $at, $f3
/* A6FCB4 802418D4 44801000 */  mtc1      $zero, $f2
/* A6FCB8 802418D8 8607008E */  lh        $a3, 0x8e($s0)
/* A6FCBC 802418DC 8E220078 */  lw        $v0, 0x78($s1)
/* A6FCC0 802418E0 46220003 */  div.d     $f0, $f0, $f2
/* A6FCC4 802418E4 46200020 */  cvt.s.d   $f0, $f0
/* A6FCC8 802418E8 44050000 */  mfc1      $a1, $f0
/* A6FCCC 802418EC C6200070 */  lwc1      $f0, 0x70($s1)
/* A6FCD0 802418F0 46800020 */  cvt.s.w   $f0, $f0
/* A6FCD4 802418F4 46000021 */  cvt.d.s   $f0, $f0
/* A6FCD8 802418F8 46220003 */  div.d     $f0, $f0, $f2
/* A6FCDC 802418FC 46200620 */  cvt.s.d   $f24, $f0
/* A6FCE0 80241900 4622B583 */  div.d     $f22, $f22, $f2
/* A6FCE4 80241904 4620B5A0 */  cvt.s.d   $f22, $f22
/* A6FCE8 80241908 4622A503 */  div.d     $f20, $f20, $f2
/* A6FCEC 8024190C AFA20010 */  sw        $v0, 0x10($sp)
/* A6FCF0 80241910 8E060060 */  lw        $a2, 0x60($s0)
/* A6FCF4 80241914 0C00A8ED */  jal       update_lerp
/* A6FCF8 80241918 4620A520 */   cvt.s.d  $f20, $f20
/* A6FCFC 8024191C 4405A000 */  mfc1      $a1, $f20
/* A6FD00 80241920 8607008E */  lh        $a3, 0x8e($s0)
/* A6FD04 80241924 8E220078 */  lw        $v0, 0x78($s1)
/* A6FD08 80241928 2404000B */  addiu     $a0, $zero, 0xb
/* A6FD0C 8024192C AFA20010 */  sw        $v0, 0x10($sp)
/* A6FD10 80241930 8E060068 */  lw        $a2, 0x68($s0)
/* A6FD14 80241934 0C00A8ED */  jal       update_lerp
/* A6FD18 80241938 46000506 */   mov.s    $f20, $f0
/* A6FD1C 8024193C E6140038 */  swc1      $f20, 0x38($s0)
/* A6FD20 80241940 E6000040 */  swc1      $f0, 0x40($s0)
/* A6FD24 80241944 C6200078 */  lwc1      $f0, 0x78($s1)
/* A6FD28 80241948 46800020 */  cvt.s.w   $f0, $f0
/* A6FD2C 8024194C 46000021 */  cvt.d.s   $f0, $f0
/* A6FD30 80241950 8602008E */  lh        $v0, 0x8e($s0)
/* A6FD34 80241954 3C018024 */  lui       $at, %hi(D_80243D88_A72168)
/* A6FD38 80241958 D4343D88 */  ldc1      $f20, %lo(D_80243D88_A72168)($at)
/* A6FD3C 8024195C 44821000 */  mtc1      $v0, $f2
/* A6FD40 80241960 00000000 */  nop
/* A6FD44 80241964 468010A1 */  cvt.d.w   $f2, $f2
/* A6FD48 80241968 4620A003 */  div.d     $f0, $f20, $f0
/* A6FD4C 8024196C 46201082 */  mul.d     $f2, $f2, $f0
/* A6FD50 80241970 00000000 */  nop
/* A6FD54 80241974 4620110D */  trunc.w.d $f4, $f2
/* A6FD58 80241978 44022000 */  mfc1      $v0, $f4
/* A6FD5C 8024197C 00000000 */  nop
/* A6FD60 80241980 244200B4 */  addiu     $v0, $v0, 0xb4
/* A6FD64 80241984 44826000 */  mtc1      $v0, $f12
/* A6FD68 80241988 00000000 */  nop
/* A6FD6C 8024198C 0C00A8BB */  jal       sin_deg
/* A6FD70 80241990 46806320 */   cvt.s.w  $f12, $f12
/* A6FD74 80241994 3C014039 */  lui       $at, 0x4039
/* A6FD78 80241998 44811800 */  mtc1      $at, $f3
/* A6FD7C 8024199C 44801000 */  mtc1      $zero, $f2
/* A6FD80 802419A0 46000021 */  cvt.d.s   $f0, $f0
/* A6FD84 802419A4 46220002 */  mul.d     $f0, $f0, $f2
/* A6FD88 802419A8 00000000 */  nop
/* A6FD8C 802419AC 9602008E */  lhu       $v0, 0x8e($s0)
/* A6FD90 802419B0 4600B0A1 */  cvt.d.s   $f2, $f22
/* A6FD94 802419B4 24420001 */  addiu     $v0, $v0, 1
/* A6FD98 802419B8 46201080 */  add.d     $f2, $f2, $f0
/* A6FD9C 802419BC A602008E */  sh        $v0, 0x8e($s0)
/* A6FDA0 802419C0 00021400 */  sll       $v0, $v0, 0x10
/* A6FDA4 802419C4 462010A0 */  cvt.s.d   $f2, $f2
/* A6FDA8 802419C8 E602003C */  swc1      $f2, 0x3c($s0)
/* A6FDAC 802419CC 8E230078 */  lw        $v1, 0x78($s1)
/* A6FDB0 802419D0 00021403 */  sra       $v0, $v0, 0x10
/* A6FDB4 802419D4 2463FFF8 */  addiu     $v1, $v1, -8
/* A6FDB8 802419D8 14430009 */  bne       $v0, $v1, .L80241A00
/* A6FDBC 802419DC 00000000 */   nop
/* A6FDC0 802419E0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A6FDC4 802419E4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A6FDC8 802419E8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A6FDCC 802419EC C60E0040 */  lwc1      $f14, 0x40($s0)
/* A6FDD0 802419F0 8C460028 */  lw        $a2, 0x28($v0)
/* A6FDD4 802419F4 0C00A720 */  jal       atan2
/* A6FDD8 802419F8 8C470030 */   lw       $a3, 0x30($v0)
/* A6FDDC 802419FC E600000C */  swc1      $f0, 0xc($s0)
.L80241A00:
/* A6FDE0 80241A00 C600003C */  lwc1      $f0, 0x3c($s0)
/* A6FDE4 80241A04 4600C03E */  c.le.s    $f24, $f0
/* A6FDE8 80241A08 00000000 */  nop
/* A6FDEC 80241A0C 45000004 */  bc1f      .L80241A20
/* A6FDF0 80241A10 2402000A */   addiu    $v0, $zero, 0xa
/* A6FDF4 80241A14 E618003C */  swc1      $f24, 0x3c($s0)
/* A6FDF8 80241A18 080906A3 */  j         .L80241A8C
/* A6FDFC 80241A1C AE20006C */   sw       $zero, 0x6c($s1)
.L80241A20:
/* A6FE00 80241A20 8602008E */  lh        $v0, 0x8e($s0)
/* A6FE04 80241A24 8E230078 */  lw        $v1, 0x78($s1)
/* A6FE08 80241A28 0043102A */  slt       $v0, $v0, $v1
/* A6FE0C 80241A2C 14400018 */  bnez      $v0, .L80241A90
/* A6FE10 80241A30 00000000 */   nop
/* A6FE14 80241A34 8E23006C */  lw        $v1, 0x6c($s1)
/* A6FE18 80241A38 44831000 */  mtc1      $v1, $f2
/* A6FE1C 80241A3C 00000000 */  nop
/* A6FE20 80241A40 468010A1 */  cvt.d.w   $f2, $f2
/* A6FE24 80241A44 4622A03E */  c.le.d    $f20, $f2
/* A6FE28 80241A48 00000000 */  nop
/* A6FE2C 80241A4C 4500000F */  bc1f      .L80241A8C
/* A6FE30 80241A50 2402000A */   addiu    $v0, $zero, 0xa
/* A6FE34 80241A54 3C018024 */  lui       $at, %hi(D_80243D90_A72170)
/* A6FE38 80241A58 D4203D90 */  ldc1      $f0, %lo(D_80243D90_A72170)($at)
/* A6FE3C 80241A5C 4620103C */  c.lt.d    $f2, $f0
/* A6FE40 80241A60 00000000 */  nop
/* A6FE44 80241A64 45000008 */  bc1f      .L80241A88
/* A6FE48 80241A68 2402021C */   addiu    $v0, $zero, 0x21c
/* A6FE4C 80241A6C 00431023 */  subu      $v0, $v0, $v1
/* A6FE50 80241A70 44826000 */  mtc1      $v0, $f12
/* A6FE54 80241A74 00000000 */  nop
/* A6FE58 80241A78 0C00A6C9 */  jal       clamp_angle
/* A6FE5C 80241A7C 46806320 */   cvt.s.w  $f12, $f12
/* A6FE60 80241A80 4600010D */  trunc.w.s $f4, $f0
/* A6FE64 80241A84 E624006C */  swc1      $f4, 0x6c($s1)
.L80241A88:
/* A6FE68 80241A88 2402000A */  addiu     $v0, $zero, 0xa
.L80241A8C:
/* A6FE6C 80241A8C AE420070 */  sw        $v0, 0x70($s2)
.L80241A90:
/* A6FE70 80241A90 8FBF0024 */  lw        $ra, 0x24($sp)
/* A6FE74 80241A94 8FB20020 */  lw        $s2, 0x20($sp)
/* A6FE78 80241A98 8FB1001C */  lw        $s1, 0x1c($sp)
/* A6FE7C 80241A9C 8FB00018 */  lw        $s0, 0x18($sp)
/* A6FE80 80241AA0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* A6FE84 80241AA4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A6FE88 80241AA8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A6FE8C 80241AAC 03E00008 */  jr        $ra
/* A6FE90 80241AB0 27BD0040 */   addiu    $sp, $sp, 0x40
