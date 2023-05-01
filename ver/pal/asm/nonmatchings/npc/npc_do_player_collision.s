.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel npc_do_player_collision
/* 14BC8 800397C8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 14BCC 800397CC AFB1001C */  sw        $s1, 0x1C($sp)
/* 14BD0 800397D0 0080882D */  daddu     $s1, $a0, $zero
/* 14BD4 800397D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 14BD8 800397D8 AFB00018 */  sw        $s0, 0x18($sp)
/* 14BDC 800397DC F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 14BE0 800397E0 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 14BE4 800397E4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 14BE8 800397E8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 14BEC 800397EC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 14BF0 800397F0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 14BF4 800397F4 8E230000 */  lw        $v1, 0x0($s1)
/* 14BF8 800397F8 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 14BFC 800397FC 2610DAC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 14C00 80039800 30620100 */  andi      $v0, $v1, 0x100
/* 14C04 80039804 144000D1 */  bnez      $v0, .LPAL_80039B4C
/* 14C08 80039808 0000102D */   daddu    $v0, $zero, $zero
/* 14C0C 8003980C 3C020400 */  lui       $v0, (0x4000000 >> 16)
/* 14C10 80039810 00621024 */  and       $v0, $v1, $v0
/* 14C14 80039814 10400003 */  beqz      $v0, .LPAL_80039824
/* 14C18 80039818 00000000 */   nop
.LPAL_8003981C:
/* 14C1C 8003981C 0800E6D3 */  j         .LPAL_80039B4C
/* 14C20 80039820 0000102D */   daddu    $v0, $zero, $zero
.LPAL_80039824:
/* 14C24 80039824 3C02800A */  lui       $v0, %hi(gNpcPlayerCollisionsEnabled)
/* 14C28 80039828 8042F304 */  lb        $v0, %lo(gNpcPlayerCollisionsEnabled)($v0)
/* 14C2C 8003982C 504000C7 */  beql      $v0, $zero, .LPAL_80039B4C
/* 14C30 80039830 0000102D */   daddu    $v0, $zero, $zero
/* 14C34 80039834 860200B0 */  lh        $v0, 0xB0($s0)
/* 14C38 80039838 C604002C */  lwc1      $f4, 0x2C($s0)
/* 14C3C 8003983C 44820000 */  mtc1      $v0, $f0
/* 14C40 80039840 00000000 */  nop
/* 14C44 80039844 46800020 */  cvt.s.w   $f0, $f0
/* 14C48 80039848 46002000 */  add.s     $f0, $f4, $f0
/* 14C4C 8003984C C622003C */  lwc1      $f2, 0x3C($s1)
/* 14C50 80039850 4602003C */  c.lt.s    $f0, $f2
/* 14C54 80039854 00000000 */  nop
/* 14C58 80039858 450100BC */  bc1t      .LPAL_80039B4C
/* 14C5C 8003985C 0000102D */   daddu    $v0, $zero, $zero
/* 14C60 80039860 862200A8 */  lh        $v0, 0xA8($s1)
/* 14C64 80039864 44820000 */  mtc1      $v0, $f0
/* 14C68 80039868 00000000 */  nop
/* 14C6C 8003986C 46800020 */  cvt.s.w   $f0, $f0
/* 14C70 80039870 46001000 */  add.s     $f0, $f2, $f0
/* 14C74 80039874 4604003C */  c.lt.s    $f0, $f4
/* 14C78 80039878 00000000 */  nop
/* 14C7C 8003987C 450100B3 */  bc1t      .LPAL_80039B4C
/* 14C80 80039880 0000102D */   daddu    $v0, $zero, $zero
/* 14C84 80039884 C63A0038 */  lwc1      $f26, 0x38($s1)
/* 14C88 80039888 C61E0028 */  lwc1      $f30, 0x28($s0)
/* 14C8C 8003988C C61C0030 */  lwc1      $f28, 0x30($s0)
/* 14C90 80039890 962200A6 */  lhu       $v0, 0xA6($s1)
/* 14C94 80039894 461AF581 */  sub.s     $f22, $f30, $f26
/* 14C98 80039898 960300B2 */  lhu       $v1, 0xB2($s0)
/* 14C9C 8003989C 00021400 */  sll       $v0, $v0, 16
/* 14CA0 800398A0 4616B082 */  mul.s     $f2, $f22, $f22
/* 14CA4 800398A4 00000000 */  nop
/* 14CA8 800398A8 00022403 */  sra       $a0, $v0, 16
/* 14CAC 800398AC 000217C2 */  srl       $v0, $v0, 31
/* 14CB0 800398B0 C6360040 */  lwc1      $f22, 0x40($s1)
/* 14CB4 800398B4 00822021 */  addu      $a0, $a0, $v0
/* 14CB8 800398B8 4616E501 */  sub.s     $f20, $f28, $f22
/* 14CBC 800398BC 00042043 */  sra       $a0, $a0, 1
/* 14CC0 800398C0 00031C00 */  sll       $v1, $v1, 16
/* 14CC4 800398C4 4614A002 */  mul.s     $f0, $f20, $f20
/* 14CC8 800398C8 00000000 */  nop
/* 14CCC 800398CC 00031403 */  sra       $v0, $v1, 16
/* 14CD0 800398D0 00031FC2 */  srl       $v1, $v1, 31
/* 14CD4 800398D4 00431021 */  addu      $v0, $v0, $v1
/* 14CD8 800398D8 00021043 */  sra       $v0, $v0, 1
/* 14CDC 800398DC 46001300 */  add.s     $f12, $f2, $f0
/* 14CE0 800398E0 4484B000 */  mtc1      $a0, $f22
/* 14CE4 800398E4 00000000 */  nop
/* 14CE8 800398E8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 14CEC 800398EC 4482A000 */  mtc1      $v0, $f20
/* 14CF0 800398F0 00000000 */  nop
/* 14CF4 800398F4 4680A520 */  cvt.s.w   $f20, $f20
/* 14CF8 800398F8 46006004 */  sqrt.s    $f0, $f12
/* 14CFC 800398FC 46000032 */  c.eq.s    $f0, $f0
/* 14D00 80039900 00000000 */  nop
/* 14D04 80039904 45010003 */  bc1t      .LPAL_80039914
/* 14D08 80039908 4614B580 */   add.s    $f22, $f22, $f20
/* 14D0C 8003990C 0C018B58 */  jal       sqrtf
/* 14D10 80039910 00000000 */   nop
.LPAL_80039914:
/* 14D14 80039914 4600B03C */  c.lt.s    $f22, $f0
/* 14D18 80039918 00000000 */  nop
/* 14D1C 8003991C 4501FFBF */  bc1t      .LPAL_8003981C
/* 14D20 80039920 E7B60010 */   swc1     $f22, 0x10($sp)
/* 14D24 80039924 8E020004 */  lw        $v0, 0x4($s0)
/* 14D28 80039928 34428000 */  ori       $v0, $v0, 0x8000
/* 14D2C 8003992C AE020004 */  sw        $v0, 0x4($s0)
/* 14D30 80039930 C63A006C */  lwc1      $f26, 0x6C($s1)
/* 14D34 80039934 461AF581 */  sub.s     $f22, $f30, $f26
/* 14D38 80039938 4616B082 */  mul.s     $f2, $f22, $f22
/* 14D3C 8003993C 00000000 */  nop
/* 14D40 80039940 C6360074 */  lwc1      $f22, 0x74($s1)
/* 14D44 80039944 4616E501 */  sub.s     $f20, $f28, $f22
/* 14D48 80039948 4614A002 */  mul.s     $f0, $f20, $f20
/* 14D4C 8003994C 00000000 */  nop
/* 14D50 80039950 46001300 */  add.s     $f12, $f2, $f0
/* 14D54 80039954 46006004 */  sqrt.s    $f0, $f12
/* 14D58 80039958 46000032 */  c.eq.s    $f0, $f0
/* 14D5C 8003995C 00000000 */  nop
/* 14D60 80039960 45010004 */  bc1t      .LPAL_80039974
/* 14D64 80039964 46000606 */   mov.s    $f24, $f0
/* 14D68 80039968 0C018B58 */  jal       sqrtf
/* 14D6C 8003996C 00000000 */   nop
/* 14D70 80039970 46000606 */  mov.s     $f24, $f0
.LPAL_80039974:
/* 14D74 80039974 4600F306 */  mov.s     $f12, $f30
/* 14D78 80039978 4406D000 */  mfc1      $a2, $f26
/* 14D7C 8003997C 4407B000 */  mfc1      $a3, $f22
/* 14D80 80039980 0C00A700 */  jal       atan2
/* 14D84 80039984 4600E386 */   mov.s    $f14, $f28
/* 14D88 80039988 3C0140C9 */  lui       $at, (0x40C90FD0 >> 16)
/* 14D8C 8003998C 34210FD0 */  ori       $at, $at, (0x40C90FD0 & 0xFFFF)
/* 14D90 80039990 4481A000 */  mtc1      $at, $f20
/* 14D94 80039994 46000686 */  mov.s     $f26, $f0
/* 14D98 80039998 4614D502 */  mul.s     $f20, $f26, $f20
/* 14D9C 8003999C 00000000 */  nop
/* 14DA0 800399A0 3C0143B4 */  lui       $at, (0x43B40000 >> 16)
/* 14DA4 800399A4 44810000 */  mtc1      $at, $f0
/* 14DA8 800399A8 C7A80010 */  lwc1      $f8, 0x10($sp)
/* 14DAC 800399AC C61C0080 */  lwc1      $f28, 0x80($s0)
/* 14DB0 800399B0 46184601 */  sub.s     $f24, $f8, $f24
/* 14DB4 800399B4 4600A503 */  div.s     $f20, $f20, $f0
/* 14DB8 800399B8 0C00A83B */  jal       sin_rad
/* 14DBC 800399BC 4600A306 */   mov.s    $f12, $f20
/* 14DC0 800399C0 4600C582 */  mul.s     $f22, $f24, $f0
/* 14DC4 800399C4 00000000 */  nop
/* 14DC8 800399C8 0C00A854 */  jal       cos_rad
/* 14DCC 800399CC 4600A306 */   mov.s    $f12, $f20
/* 14DD0 800399D0 3C030040 */  lui       $v1, (0x400000 >> 16)
/* 14DD4 800399D4 8E020004 */  lw        $v0, 0x4($s0)
/* 14DD8 800399D8 4600C087 */  neg.s     $f2, $f24
/* 14DDC 800399DC 46001502 */  mul.s     $f20, $f2, $f0
/* 14DE0 800399E0 00000000 */  nop
/* 14DE4 800399E4 00431024 */  and       $v0, $v0, $v1
/* 14DE8 800399E8 1040002D */  beqz      $v0, .LPAL_80039AA0
/* 14DEC 800399EC 4600D306 */   mov.s    $f12, $f26
/* 14DF0 800399F0 0C00A6EA */  jal       get_clamped_angle_diff
/* 14DF4 800399F4 4600E386 */   mov.s    $f14, $f28
/* 14DF8 800399F8 3C014234 */  lui       $at, (0x42340000 >> 16)
/* 14DFC 800399FC 44811000 */  mtc1      $at, $f2
/* 14E00 80039A00 46000005 */  abs.s     $f0, $f0
/* 14E04 80039A04 4602003C */  c.lt.s    $f0, $f2
/* 14E08 80039A08 00000000 */  nop
/* 14E0C 80039A0C 4500000E */  bc1f      .LPAL_80039A48
/* 14E10 80039A10 00000000 */   nop
/* 14E14 80039A14 C6020028 */  lwc1      $f2, 0x28($s0)
/* 14E18 80039A18 46161081 */  sub.s     $f2, $f2, $f22
/* 14E1C 80039A1C C6000030 */  lwc1      $f0, 0x30($s0)
/* 14E20 80039A20 3C028011 */  lui       $v0, %hi(wPartnerNpc)
/* 14E24 80039A24 8C42B420 */  lw        $v0, %lo(wPartnerNpc)($v0)
/* 14E28 80039A28 46140001 */  sub.s     $f0, $f0, $f20
/* 14E2C 80039A2C E6020028 */  swc1      $f2, 0x28($s0)
/* 14E30 80039A30 E6000030 */  swc1      $f0, 0x30($s0)
/* 14E34 80039A34 C4420038 */  lwc1      $f2, 0x38($v0)
/* 14E38 80039A38 46161081 */  sub.s     $f2, $f2, $f22
/* 14E3C 80039A3C C4400040 */  lwc1      $f0, 0x40($v0)
/* 14E40 80039A40 0800E6A5 */  j         .LPAL_80039A94
/* 14E44 80039A44 46140001 */   sub.s    $f0, $f0, $f20
.LPAL_80039A48:
/* 14E48 80039A48 3C013F00 */  lui       $at, (0x3F000000 >> 16)
/* 14E4C 80039A4C 44812000 */  mtc1      $at, $f4
/* 14E50 80039A50 00000000 */  nop
/* 14E54 80039A54 4604B182 */  mul.s     $f6, $f22, $f4
/* 14E58 80039A58 00000000 */  nop
/* 14E5C 80039A5C 4604A102 */  mul.s     $f4, $f20, $f4
/* 14E60 80039A60 00000000 */  nop
/* 14E64 80039A64 C6020028 */  lwc1      $f2, 0x28($s0)
/* 14E68 80039A68 46061081 */  sub.s     $f2, $f2, $f6
/* 14E6C 80039A6C C6000030 */  lwc1      $f0, 0x30($s0)
/* 14E70 80039A70 3C028011 */  lui       $v0, %hi(wPartnerNpc)
/* 14E74 80039A74 8C42B420 */  lw        $v0, %lo(wPartnerNpc)($v0)
/* 14E78 80039A78 46040001 */  sub.s     $f0, $f0, $f4
/* 14E7C 80039A7C E6020028 */  swc1      $f2, 0x28($s0)
/* 14E80 80039A80 E6000030 */  swc1      $f0, 0x30($s0)
/* 14E84 80039A84 C4420038 */  lwc1      $f2, 0x38($v0)
/* 14E88 80039A88 46061081 */  sub.s     $f2, $f2, $f6
/* 14E8C 80039A8C C4400040 */  lwc1      $f0, 0x40($v0)
/* 14E90 80039A90 46040001 */  sub.s     $f0, $f0, $f4
.LPAL_80039A94:
/* 14E94 80039A94 E4420038 */  swc1      $f2, 0x38($v0)
/* 14E98 80039A98 0800E6CC */  j         .LPAL_80039B30
/* 14E9C 80039A9C E4400040 */   swc1     $f0, 0x40($v0)
.LPAL_80039AA0:
/* 14EA0 80039AA0 8E020000 */  lw        $v0, 0x0($s0)
/* 14EA4 80039AA4 30420006 */  andi      $v0, $v0, 0x6
/* 14EA8 80039AA8 10400006 */  beqz      $v0, .LPAL_80039AC4
/* 14EAC 80039AAC 00000000 */   nop
/* 14EB0 80039AB0 3C013ECC */  lui       $at, (0x3ECCCCCD >> 16)
/* 14EB4 80039AB4 3421CCCD */  ori       $at, $at, (0x3ECCCCCD & 0xFFFF)
/* 14EB8 80039AB8 44812000 */  mtc1      $at, $f4
/* 14EBC 80039ABC 0800E6C2 */  j         .LPAL_80039B08
/* 14EC0 80039AC0 00000000 */   nop
.LPAL_80039AC4:
/* 14EC4 80039AC4 0C00A6EA */  jal       get_clamped_angle_diff
/* 14EC8 80039AC8 4600E386 */   mov.s    $f14, $f28
/* 14ECC 80039ACC 3C014234 */  lui       $at, (0x42340000 >> 16)
/* 14ED0 80039AD0 44811000 */  mtc1      $at, $f2
/* 14ED4 80039AD4 46000005 */  abs.s     $f0, $f0
/* 14ED8 80039AD8 4602003C */  c.lt.s    $f0, $f2
/* 14EDC 80039ADC 00000000 */  nop
/* 14EE0 80039AE0 45000006 */  bc1f      .LPAL_80039AFC
/* 14EE4 80039AE4 00000000 */   nop
/* 14EE8 80039AE8 C6020028 */  lwc1      $f2, 0x28($s0)
/* 14EEC 80039AEC 46161081 */  sub.s     $f2, $f2, $f22
/* 14EF0 80039AF0 C6000030 */  lwc1      $f0, 0x30($s0)
/* 14EF4 80039AF4 0800E6CA */  j         .LPAL_80039B28
/* 14EF8 80039AF8 46140001 */   sub.s    $f0, $f0, $f20
.LPAL_80039AFC:
/* 14EFC 80039AFC 3C013F00 */  lui       $at, (0x3F000000 >> 16)
/* 14F00 80039B00 44812000 */  mtc1      $at, $f4
/* 14F04 80039B04 00000000 */  nop
.LPAL_80039B08:
/* 14F08 80039B08 4604B002 */  mul.s     $f0, $f22, $f4
/* 14F0C 80039B0C 00000000 */  nop
/* 14F10 80039B10 4604A102 */  mul.s     $f4, $f20, $f4
/* 14F14 80039B14 00000000 */  nop
/* 14F18 80039B18 C6020028 */  lwc1      $f2, 0x28($s0)
/* 14F1C 80039B1C 46001081 */  sub.s     $f2, $f2, $f0
/* 14F20 80039B20 C6000030 */  lwc1      $f0, 0x30($s0)
/* 14F24 80039B24 46040001 */  sub.s     $f0, $f0, $f4
.LPAL_80039B28:
/* 14F28 80039B28 E6020028 */  swc1      $f2, 0x28($s0)
/* 14F2C 80039B2C E6000030 */  swc1      $f0, 0x30($s0)
.LPAL_80039B30:
/* 14F30 80039B30 C620006C */  lwc1      $f0, 0x6C($s1)
/* 14F34 80039B34 C6220070 */  lwc1      $f2, 0x70($s1)
/* 14F38 80039B38 C6240074 */  lwc1      $f4, 0x74($s1)
/* 14F3C 80039B3C 24020001 */  addiu     $v0, $zero, 0x1
/* 14F40 80039B40 E6200038 */  swc1      $f0, 0x38($s1)
/* 14F44 80039B44 E622003C */  swc1      $f2, 0x3C($s1)
/* 14F48 80039B48 E6240040 */  swc1      $f4, 0x40($s1)
.LPAL_80039B4C:
/* 14F4C 80039B4C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 14F50 80039B50 8FB1001C */  lw        $s1, 0x1C($sp)
/* 14F54 80039B54 8FB00018 */  lw        $s0, 0x18($sp)
/* 14F58 80039B58 D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 14F5C 80039B5C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 14F60 80039B60 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 14F64 80039B64 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 14F68 80039B68 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 14F6C 80039B6C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 14F70 80039B70 03E00008 */  jr        $ra
/* 14F74 80039B74 27BD0058 */   addiu    $sp, $sp, 0x58