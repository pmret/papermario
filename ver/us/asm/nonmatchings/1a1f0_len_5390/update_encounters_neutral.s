.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_800985F8
.word L80040320_1B720, L80040320_1B720, L80040594_1B994, L80040594_1B994, L80040594_1B994, L80040320_1B720, L80040320_1B720, L80040320_1B720, L80040320_1B720, L80040594_1B994, L80040320_1B720, L80040320_1B720, L80040320_1B720, L80040320_1B720, L80040594_1B994, L8003FFA0_1B3A0

dlabel jtbl_80098638
.word L80040540_1B940, L80040540_1B940, L8004055C_1B95C, L8004055C_1B95C, L8004055C_1B95C, L80040540_1B940, L80040540_1B940, L80040540_1B940, L80040540_1B940, L8004055C_1B95C, L80040548_1B948, L80040548_1B948, L80040554_1B954, L80040554_1B954

dlabel D_80098670
.double 0.8

dlabel jtbl_80098678
.word L80041314_1C714, L80040918_1BD18, L80040BF4_1BFF4, L80040ABC_1BEBC, L80040E34_1C234, L800410BC_1C4BC, L8004115C_1C55C, 0

.section .text

glabel update_encounters_neutral
/* 1ABCC 8003F7CC 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 1ABD0 8003F7D0 AFB30074 */  sw        $s3, 0x74($sp)
/* 1ABD4 8003F7D4 3C13800B */  lui       $s3, %hi(gCurrentEncounter)
/* 1ABD8 8003F7D8 26730F10 */  addiu     $s3, $s3, %lo(gCurrentEncounter)
/* 1ABDC 8003F7DC AFB40078 */  sw        $s4, 0x78($sp)
/* 1ABE0 8003F7E0 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* 1ABE4 8003F7E4 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* 1ABE8 8003F7E8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 1ABEC 8003F7EC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 1ABF0 8003F7F0 3C04800B */  lui       $a0, %hi(gCameras)
/* 1ABF4 8003F7F4 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 1ABF8 8003F7F8 AFBF008C */  sw        $ra, 0x8c($sp)
/* 1ABFC 8003F7FC AFBE0088 */  sw        $fp, 0x88($sp)
/* 1AC00 8003F800 AFB70084 */  sw        $s7, 0x84($sp)
/* 1AC04 8003F804 AFB60080 */  sw        $s6, 0x80($sp)
/* 1AC08 8003F808 AFB5007C */  sw        $s5, 0x7c($sp)
/* 1AC0C 8003F80C AFB20070 */  sw        $s2, 0x70($sp)
/* 1AC10 8003F810 AFB1006C */  sw        $s1, 0x6c($sp)
/* 1AC14 8003F814 AFB00068 */  sw        $s0, 0x68($sp)
/* 1AC18 8003F818 F7BE00B8 */  sdc1      $f30, 0xb8($sp)
/* 1AC1C 8003F81C F7BC00B0 */  sdc1      $f28, 0xb0($sp)
/* 1AC20 8003F820 F7BA00A8 */  sdc1      $f26, 0xa8($sp)
/* 1AC24 8003F824 F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 1AC28 8003F828 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 1AC2C 8003F82C F7B40090 */  sdc1      $f20, 0x90($sp)
/* 1AC30 8003F830 00031080 */  sll       $v0, $v1, 2
/* 1AC34 8003F834 00431021 */  addu      $v0, $v0, $v1
/* 1AC38 8003F838 00021080 */  sll       $v0, $v0, 2
/* 1AC3C 8003F83C 00431023 */  subu      $v0, $v0, $v1
/* 1AC40 8003F840 000218C0 */  sll       $v1, $v0, 3
/* 1AC44 8003F844 00431021 */  addu      $v0, $v0, $v1
/* 1AC48 8003F848 000210C0 */  sll       $v0, $v0, 3
/* 1AC4C 8003F84C 00441021 */  addu      $v0, $v0, $a0
/* 1AC50 8003F850 AFA20048 */  sw        $v0, 0x48($sp)
/* 1AC54 8003F854 82630005 */  lb        $v1, 5($s3)
/* 1AC58 8003F858 24020005 */  addiu     $v0, $zero, 5
/* 1AC5C 8003F85C 10620426 */  beq       $v1, $v0, .L800408F8
/* 1AC60 8003F860 2402FFFF */   addiu    $v0, $zero, -1
/* 1AC64 8003F864 C69000A8 */  lwc1      $f16, 0xa8($s4)
/* 1AC68 8003F868 3C014334 */  lui       $at, 0x4334
/* 1AC6C 8003F86C 44810000 */  mtc1      $at, $f0
/* 1AC70 8003F870 E7B0005C */  swc1      $f16, 0x5c($sp)
/* 1AC74 8003F874 AE620014 */  sw        $v0, 0x14($s3)
/* 1AC78 8003F878 AE620018 */  sw        $v0, 0x18($s3)
/* 1AC7C 8003F87C 8E620000 */  lw        $v0, ($s3)
/* 1AC80 8003F880 2403FFFE */  addiu     $v1, $zero, -2
/* 1AC84 8003F884 A2600005 */  sb        $zero, 5($s3)
/* 1AC88 8003F888 A2600011 */  sb        $zero, 0x11($s3)
/* 1AC8C 8003F88C A2600013 */  sb        $zero, 0x13($s3)
/* 1AC90 8003F890 4600803C */  c.lt.s    $f16, $f0
/* 1AC94 8003F894 00431024 */  and       $v0, $v0, $v1
/* 1AC98 8003F898 2403FFFD */  addiu     $v1, $zero, -3
/* 1AC9C 8003F89C 00431024 */  and       $v0, $v0, $v1
/* 1ACA0 8003F8A0 2403FFFB */  addiu     $v1, $zero, -5
/* 1ACA4 8003F8A4 00431024 */  and       $v0, $v0, $v1
/* 1ACA8 8003F8A8 AE620000 */  sw        $v0, ($s3)
/* 1ACAC 8003F8AC C6920028 */  lwc1      $f18, 0x28($s4)
/* 1ACB0 8003F8B0 E7B20050 */  swc1      $f18, 0x50($sp)
/* 1ACB4 8003F8B4 C690002C */  lwc1      $f16, 0x2c($s4)
/* 1ACB8 8003F8B8 E7B00054 */  swc1      $f16, 0x54($sp)
/* 1ACBC 8003F8BC C6920030 */  lwc1      $f18, 0x30($s4)
/* 1ACC0 8003F8C0 45000007 */  bc1f      .L8003F8E0
/* 1ACC4 8003F8C4 E7B20058 */   swc1     $f18, 0x58($sp)
/* 1ACC8 8003F8C8 8FA80048 */  lw        $t0, 0x48($sp)
/* 1ACCC 8003F8CC 3C0142B4 */  lui       $at, 0x42b4
/* 1ACD0 8003F8D0 44816000 */  mtc1      $at, $f12
/* 1ACD4 8003F8D4 C500006C */  lwc1      $f0, 0x6c($t0)
/* 1ACD8 8003F8D8 0800FE3D */  j         .L8003F8F4
/* 1ACDC 8003F8DC 460C0301 */   sub.s    $f12, $f0, $f12
.L8003F8E0:
/* 1ACE0 8003F8E0 8FA80048 */  lw        $t0, 0x48($sp)
/* 1ACE4 8003F8E4 3C0142B4 */  lui       $at, 0x42b4
/* 1ACE8 8003F8E8 44816000 */  mtc1      $at, $f12
/* 1ACEC 8003F8EC C500006C */  lwc1      $f0, 0x6c($t0)
/* 1ACF0 8003F8F0 460C0300 */  add.s     $f12, $f0, $f12
.L8003F8F4:
/* 1ACF4 8003F8F4 0C00A6C9 */  jal       clamp_angle
/* 1ACF8 8003F8F8 00000000 */   nop
/* 1ACFC 8003F8FC E7A0005C */  swc1      $f0, 0x5c($sp)
/* 1AD00 8003F900 8262000A */  lb        $v0, 0xa($s3)
/* 1AD04 8003F904 10400059 */  beqz      $v0, .L8003FA6C
/* 1AD08 8003F908 9263000A */   lbu      $v1, 0xa($s3)
/* 1AD0C 8003F90C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 1AD10 8003F910 8C42A650 */  lw        $v0, %lo(gOverrideFlags)($v0)
/* 1AD14 8003F914 30420040 */  andi      $v0, $v0, 0x40
/* 1AD18 8003F918 14400002 */  bnez      $v0, .L8003F924
/* 1AD1C 8003F91C 2462FFFF */   addiu    $v0, $v1, -1
/* 1AD20 8003F920 A262000A */  sb        $v0, 0xa($s3)
.L8003F924:
/* 1AD24 8003F924 86820010 */  lh        $v0, 0x10($s4)
/* 1AD28 8003F928 10400050 */  beqz      $v0, .L8003FA6C
/* 1AD2C 8003F92C 00000000 */   nop
/* 1AD30 8003F930 8E820000 */  lw        $v0, ($s4)
/* 1AD34 8003F934 30422000 */  andi      $v0, $v0, 0x2000
/* 1AD38 8003F938 5440004B */  bnel      $v0, $zero, .L8003FA68
/* 1AD3C 8003F93C 24020001 */   addiu    $v0, $zero, 1
/* 1AD40 8003F940 9262000A */  lbu       $v0, 0xa($s3)
/* 1AD44 8003F944 00021600 */  sll       $v0, $v0, 0x18
/* 1AD48 8003F948 0800FE9A */  j         .L8003FA68
/* 1AD4C 8003F94C 00021603 */   sra      $v0, $v0, 0x18
.L8003F950:
/* 1AD50 8003F950 24020001 */  addiu     $v0, $zero, 1
/* 1AD54 8003F954 A2620005 */  sb        $v0, 5($s3)
/* 1AD58 8003F958 A2220005 */  sb        $v0, 5($s1)
/* 1AD5C 8003F95C AE760088 */  sw        $s6, 0x88($s3)
/* 1AD60 8003F960 AE71008C */  sw        $s1, 0x8c($s3)
/* 1AD64 8003F964 A2600004 */  sb        $zero, 4($s3)
/* 1AD68 8003F968 0801023D */  j         .L800408F4
/* 1AD6C 8003F96C A2600006 */   sb       $zero, 6($s3)
.L8003F970:
/* 1AD70 8003F970 8E860028 */  lw        $a2, 0x28($s4)
/* 1AD74 8003F974 8E87002C */  lw        $a3, 0x2c($s4)
/* 1AD78 8003F978 C6800030 */  lwc1      $f0, 0x30($s4)
/* 1AD7C 8003F97C 0000282D */  daddu     $a1, $zero, $zero
/* 1AD80 8003F980 0C052757 */  jal       sfx_play_sound_at_position
/* 1AD84 8003F984 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1AD88 8003F988 C6480038 */  lwc1      $f8, 0x38($s2)
/* 1AD8C 8003F98C C68C0028 */  lwc1      $f12, 0x28($s4)
/* 1AD90 8003F990 460C4201 */  sub.s     $f8, $f8, $f12
/* 1AD94 8003F994 3C013F00 */  lui       $at, 0x3f00
/* 1AD98 8003F998 44815000 */  mtc1      $at, $f10
/* 1AD9C 8003F99C 00000000 */  nop
/* 1ADA0 8003F9A0 460A4202 */  mul.s     $f8, $f8, $f10
/* 1ADA4 8003F9A4 00000000 */  nop
/* 1ADA8 8003F9A8 864200A8 */  lh        $v0, 0xa8($s2)
/* 1ADAC 8003F9AC C642003C */  lwc1      $f2, 0x3c($s2)
/* 1ADB0 8003F9B0 44820000 */  mtc1      $v0, $f0
/* 1ADB4 8003F9B4 00000000 */  nop
/* 1ADB8 8003F9B8 46800020 */  cvt.s.w   $f0, $f0
/* 1ADBC 8003F9BC 46001080 */  add.s     $f2, $f2, $f0
/* 1ADC0 8003F9C0 868200B0 */  lh        $v0, 0xb0($s4)
/* 1ADC4 8003F9C4 C686002C */  lwc1      $f6, 0x2c($s4)
/* 1ADC8 8003F9C8 44820000 */  mtc1      $v0, $f0
/* 1ADCC 8003F9CC 00000000 */  nop
/* 1ADD0 8003F9D0 46800020 */  cvt.s.w   $f0, $f0
/* 1ADD4 8003F9D4 46003000 */  add.s     $f0, $f6, $f0
/* 1ADD8 8003F9D8 46001081 */  sub.s     $f2, $f2, $f0
/* 1ADDC 8003F9DC 460A1082 */  mul.s     $f2, $f2, $f10
/* 1ADE0 8003F9E0 00000000 */  nop
/* 1ADE4 8003F9E4 C6840030 */  lwc1      $f4, 0x30($s4)
/* 1ADE8 8003F9E8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1ADEC 8003F9EC 46040001 */  sub.s     $f0, $f0, $f4
/* 1ADF0 8003F9F0 460A0002 */  mul.s     $f0, $f0, $f10
/* 1ADF4 8003F9F4 00000000 */  nop
/* 1ADF8 8003F9F8 46086300 */  add.s     $f12, $f12, $f8
/* 1ADFC 8003F9FC 46023180 */  add.s     $f6, $f6, $f2
/* 1AE00 8003FA00 24040003 */  addiu     $a0, $zero, 3
/* 1AE04 8003FA04 44056000 */  mfc1      $a1, $f12
/* 1AE08 8003FA08 46002100 */  add.s     $f4, $f4, $f0
/* 1AE0C 8003FA0C 3C01BF80 */  lui       $at, 0xbf80
/* 1AE10 8003FA10 44810000 */  mtc1      $at, $f0
/* 1AE14 8003FA14 44063000 */  mfc1      $a2, $f6
/* 1AE18 8003FA18 44072000 */  mfc1      $a3, $f4
/* 1AE1C 8003FA1C 0080802D */  daddu     $s0, $a0, $zero
/* 1AE20 8003FA20 AFA5003C */  sw        $a1, 0x3c($sp)
/* 1AE24 8003FA24 AFA60040 */  sw        $a2, 0x40($sp)
/* 1AE28 8003FA28 AFA70044 */  sw        $a3, 0x44($sp)
/* 1AE2C 8003FA2C AFA00010 */  sw        $zero, 0x10($sp)
/* 1AE30 8003FA30 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1AE34 8003FA34 AFA00018 */  sw        $zero, 0x18($sp)
/* 1AE38 8003FA38 0C01C064 */  jal       playFX_18
/* 1AE3C 8003FA3C AFB0001C */   sw       $s0, 0x1c($sp)
/* 1AE40 8003FA40 A2700005 */  sb        $s0, 5($s3)
/* 1AE44 8003FA44 8E820004 */  lw        $v0, 4($s4)
/* 1AE48 8003FA48 3C030002 */  lui       $v1, 2
/* 1AE4C 8003FA4C 00431025 */  or        $v0, $v0, $v1
/* 1AE50 8003FA50 AE820004 */  sw        $v0, 4($s4)
/* 1AE54 8003FA54 A2300005 */  sb        $s0, 5($s1)
/* 1AE58 8003FA58 AE760088 */  sw        $s6, 0x88($s3)
/* 1AE5C 8003FA5C AE71008C */  sw        $s1, 0x8c($s3)
/* 1AE60 8003FA60 0801023D */  j         .L800408F4
/* 1AE64 8003FA64 A2600004 */   sb       $zero, 4($s3)
.L8003FA68:
/* 1AE68 8003FA68 A6820010 */  sh        $v0, 0x10($s4)
.L8003FA6C:
/* 1AE6C 8003FA6C 8262001C */  lb        $v0, 0x1c($s3)
/* 1AE70 8003FA70 184003A0 */  blez      $v0, .L800408F4
/* 1AE74 8003FA74 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1AE78 8003FA78 3C087FFF */  lui       $t0, 0x7fff
/* 1AE7C 8003FA7C 3508FFFF */  ori       $t0, $t0, 0xffff
/* 1AE80 8003FA80 AFA80060 */  sw        $t0, 0x60($sp)
/* 1AE84 8003FA84 27A8003C */  addiu     $t0, $sp, 0x3c
/* 1AE88 8003FA88 AFA80064 */  sw        $t0, 0x64($sp)
.L8003FA8C:
/* 1AE8C 8003FA8C 8FA8004C */  lw        $t0, 0x4c($sp)
/* 1AE90 8003FA90 00081080 */  sll       $v0, $t0, 2
/* 1AE94 8003FA94 02621021 */  addu      $v0, $s3, $v0
/* 1AE98 8003FA98 8C560028 */  lw        $s6, 0x28($v0)
/* 1AE9C 8003FA9C 12C00390 */  beqz      $s6, .L800408E0
/* 1AEA0 8003FAA0 00000000 */   nop
/* 1AEA4 8003FAA4 8EC20000 */  lw        $v0, ($s6)
/* 1AEA8 8003FAA8 1840038D */  blez      $v0, .L800408E0
/* 1AEAC 8003FAAC 0000A82D */   daddu    $s5, $zero, $zero
/* 1AEB0 8003FAB0 27BE0040 */  addiu     $fp, $sp, 0x40
/* 1AEB4 8003FAB4 27B70044 */  addiu     $s7, $sp, 0x44
/* 1AEB8 8003FAB8 00151080 */  sll       $v0, $s5, 2
.L8003FABC:
/* 1AEBC 8003FABC 02C21021 */  addu      $v0, $s6, $v0
/* 1AEC0 8003FAC0 8C510004 */  lw        $s1, 4($v0)
/* 1AEC4 8003FAC4 12200380 */  beqz      $s1, .L800408C8
/* 1AEC8 8003FAC8 00000000 */   nop
/* 1AECC 8003FACC 8E220000 */  lw        $v0, ($s1)
/* 1AED0 8003FAD0 30420020 */  andi      $v0, $v0, 0x20
/* 1AED4 8003FAD4 1440037C */  bnez      $v0, .L800408C8
/* 1AED8 8003FAD8 00000000 */   nop
/* 1AEDC 8003FADC 0C00EABB */  jal       get_npc_unsafe
/* 1AEE0 8003FAE0 86240008 */   lh       $a0, 8($s1)
/* 1AEE4 8003FAE4 0040902D */  daddu     $s2, $v0, $zero
/* 1AEE8 8003FAE8 822200B4 */  lb        $v0, 0xb4($s1)
/* 1AEEC 8003FAEC 922300B4 */  lbu       $v1, 0xb4($s1)
/* 1AEF0 8003FAF0 50400030 */  beql      $v0, $zero, .L8003FBB4
/* 1AEF4 8003FAF4 3C030020 */   lui      $v1, 0x20
/* 1AEF8 8003FAF8 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 1AEFC 8003FAFC 8C42A650 */  lw        $v0, %lo(gOverrideFlags)($v0)
/* 1AF00 8003FB00 30420040 */  andi      $v0, $v0, 0x40
/* 1AF04 8003FB04 54400005 */  bnel      $v0, $zero, .L8003FB1C
/* 1AF08 8003FB08 0000102D */   daddu    $v0, $zero, $zero
/* 1AF0C 8003FB0C 2462FFFF */  addiu     $v0, $v1, -1
/* 1AF10 8003FB10 A22200B4 */  sb        $v0, 0xb4($s1)
/* 1AF14 8003FB14 00021600 */  sll       $v0, $v0, 0x18
/* 1AF18 8003FB18 00021603 */  sra       $v0, $v0, 0x18
.L8003FB1C:
/* 1AF1C 8003FB1C 30420001 */  andi      $v0, $v0, 1
/* 1AF20 8003FB20 10400007 */  beqz      $v0, .L8003FB40
/* 1AF24 8003FB24 3C088000 */   lui      $t0, 0x8000
/* 1AF28 8003FB28 8E420000 */  lw        $v0, ($s2)
/* 1AF2C 8003FB2C 00481025 */  or        $v0, $v0, $t0
/* 1AF30 8003FB30 AE420000 */  sw        $v0, ($s2)
/* 1AF34 8003FB34 8E220000 */  lw        $v0, ($s1)
/* 1AF38 8003FB38 0800FED6 */  j         .L8003FB58
/* 1AF3C 8003FB3C 00481025 */   or       $v0, $v0, $t0
.L8003FB40:
/* 1AF40 8003FB40 8E420000 */  lw        $v0, ($s2)
/* 1AF44 8003FB44 8FA80060 */  lw        $t0, 0x60($sp)
/* 1AF48 8003FB48 00481024 */  and       $v0, $v0, $t0
/* 1AF4C 8003FB4C AE420000 */  sw        $v0, ($s2)
/* 1AF50 8003FB50 8E220000 */  lw        $v0, ($s1)
/* 1AF54 8003FB54 00481024 */  and       $v0, $v0, $t0
.L8003FB58:
/* 1AF58 8003FB58 AE220000 */  sw        $v0, ($s1)
/* 1AF5C 8003FB5C 0C0B11EA */  jal       get_script_by_id
/* 1AF60 8003FB60 8E24005C */   lw       $a0, 0x5c($s1)
/* 1AF64 8003FB64 0040202D */  daddu     $a0, $v0, $zero
/* 1AF68 8003FB68 10800003 */  beqz      $a0, .L8003FB78
/* 1AF6C 8003FB6C 00000000 */   nop
/* 1AF70 8003FB70 0C0B11FA */  jal       set_script_flags
/* 1AF74 8003FB74 24050080 */   addiu    $a1, $zero, 0x80
.L8003FB78:
/* 1AF78 8003FB78 8E240054 */  lw        $a0, 0x54($s1)
/* 1AF7C 8003FB7C 0C0B11EA */  jal       get_script_by_id
/* 1AF80 8003FB80 00000000 */   nop
/* 1AF84 8003FB84 0040202D */  daddu     $a0, $v0, $zero
/* 1AF88 8003FB88 10800003 */  beqz      $a0, .L8003FB98
/* 1AF8C 8003FB8C 00000000 */   nop
/* 1AF90 8003FB90 0C0B11FA */  jal       set_script_flags
/* 1AF94 8003FB94 24050080 */   addiu    $a1, $zero, 0x80
.L8003FB98:
/* 1AF98 8003FB98 8E220000 */  lw        $v0, ($s1)
/* 1AF9C 8003FB9C 3C030008 */  lui       $v1, 8
/* 1AFA0 8003FBA0 00431024 */  and       $v0, $v0, $v1
/* 1AFA4 8003FBA4 10400052 */  beqz      $v0, .L8003FCF0
/* 1AFA8 8003FBA8 00000000 */   nop
/* 1AFAC 8003FBAC 0800FF2D */  j         .L8003FCB4
/* 1AFB0 8003FBB0 8E24005C */   lw       $a0, 0x5c($s1)
.L8003FBB4:
/* 1AFB4 8003FBB4 8E220000 */  lw        $v0, ($s1)
/* 1AFB8 8003FBB8 00431024 */  and       $v0, $v0, $v1
/* 1AFBC 8003FBBC 14400035 */  bnez      $v0, .L8003FC94
/* 1AFC0 8003FBC0 27A20020 */   addiu    $v0, $sp, 0x20
/* 1AFC4 8003FBC4 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 1AFC8 8003FBC8 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 1AFCC 8003FBCC AFA20010 */  sw        $v0, 0x10($sp)
/* 1AFD0 8003FBD0 27A20024 */  addiu     $v0, $sp, 0x24
/* 1AFD4 8003FBD4 AFA20014 */  sw        $v0, 0x14($sp)
/* 1AFD8 8003FBD8 27A20028 */  addiu     $v0, $sp, 0x28
/* 1AFDC 8003FBDC AFA20018 */  sw        $v0, 0x18($sp)
/* 1AFE0 8003FBE0 8E450038 */  lw        $a1, 0x38($s2)
/* 1AFE4 8003FBE4 8E46003C */  lw        $a2, 0x3c($s2)
/* 1AFE8 8003FBE8 0C00B94E */  jal       get_screen_coords
/* 1AFEC 8003FBEC 8E470040 */   lw       $a3, 0x40($s2)
/* 1AFF0 8003FBF0 8FA20020 */  lw        $v0, 0x20($sp)
/* 1AFF4 8003FBF4 244200A0 */  addiu     $v0, $v0, 0xa0
/* 1AFF8 8003FBF8 2C420281 */  sltiu     $v0, $v0, 0x281
/* 1AFFC 8003FBFC 1040000A */  beqz      $v0, .L8003FC28
/* 1B000 8003FC00 00000000 */   nop
/* 1B004 8003FC04 8FA30024 */  lw        $v1, 0x24($sp)
/* 1B008 8003FC08 2862FF88 */  slti      $v0, $v1, -0x78
/* 1B00C 8003FC0C 14400006 */  bnez      $v0, .L8003FC28
/* 1B010 8003FC10 28620169 */   slti     $v0, $v1, 0x169
/* 1B014 8003FC14 10400004 */  beqz      $v0, .L8003FC28
/* 1B018 8003FC18 00000000 */   nop
/* 1B01C 8003FC1C 8FA20028 */  lw        $v0, 0x28($sp)
/* 1B020 8003FC20 0441001C */  bgez      $v0, .L8003FC94
/* 1B024 8003FC24 00000000 */   nop
.L8003FC28:
/* 1B028 8003FC28 8E220000 */  lw        $v0, ($s1)
/* 1B02C 8003FC2C 30420001 */  andi      $v0, $v0, 1
/* 1B030 8003FC30 14400018 */  bnez      $v0, .L8003FC94
/* 1B034 8003FC34 3C088000 */   lui      $t0, 0x8000
/* 1B038 8003FC38 8E420000 */  lw        $v0, ($s2)
/* 1B03C 8003FC3C 00481025 */  or        $v0, $v0, $t0
/* 1B040 8003FC40 AE420000 */  sw        $v0, ($s2)
/* 1B044 8003FC44 8E220000 */  lw        $v0, ($s1)
/* 1B048 8003FC48 8E24005C */  lw        $a0, 0x5c($s1)
/* 1B04C 8003FC4C 00481025 */  or        $v0, $v0, $t0
/* 1B050 8003FC50 0C0B11EA */  jal       get_script_by_id
/* 1B054 8003FC54 AE220000 */   sw       $v0, ($s1)
/* 1B058 8003FC58 0040202D */  daddu     $a0, $v0, $zero
/* 1B05C 8003FC5C 10800003 */  beqz      $a0, .L8003FC6C
/* 1B060 8003FC60 00000000 */   nop
/* 1B064 8003FC64 0C0B11FA */  jal       set_script_flags
/* 1B068 8003FC68 24050080 */   addiu    $a1, $zero, 0x80
.L8003FC6C:
/* 1B06C 8003FC6C 8E240054 */  lw        $a0, 0x54($s1)
/* 1B070 8003FC70 0C0B11EA */  jal       get_script_by_id
/* 1B074 8003FC74 00000000 */   nop
/* 1B078 8003FC78 0040202D */  daddu     $a0, $v0, $zero
/* 1B07C 8003FC7C 1080001C */  beqz      $a0, .L8003FCF0
/* 1B080 8003FC80 00000000 */   nop
/* 1B084 8003FC84 0C0B11FA */  jal       set_script_flags
/* 1B088 8003FC88 24050080 */   addiu    $a1, $zero, 0x80
/* 1B08C 8003FC8C 0800FF3C */  j         .L8003FCF0
/* 1B090 8003FC90 00000000 */   nop
.L8003FC94:
/* 1B094 8003FC94 8E420000 */  lw        $v0, ($s2)
/* 1B098 8003FC98 8FA80060 */  lw        $t0, 0x60($sp)
/* 1B09C 8003FC9C 00481024 */  and       $v0, $v0, $t0
/* 1B0A0 8003FCA0 AE420000 */  sw        $v0, ($s2)
/* 1B0A4 8003FCA4 8E220000 */  lw        $v0, ($s1)
/* 1B0A8 8003FCA8 8E24005C */  lw        $a0, 0x5c($s1)
/* 1B0AC 8003FCAC 00481024 */  and       $v0, $v0, $t0
/* 1B0B0 8003FCB0 AE220000 */  sw        $v0, ($s1)
.L8003FCB4:
/* 1B0B4 8003FCB4 0C0B11EA */  jal       get_script_by_id
/* 1B0B8 8003FCB8 00000000 */   nop
/* 1B0BC 8003FCBC 0040202D */  daddu     $a0, $v0, $zero
/* 1B0C0 8003FCC0 10800003 */  beqz      $a0, .L8003FCD0
/* 1B0C4 8003FCC4 00000000 */   nop
/* 1B0C8 8003FCC8 0C0B1220 */  jal       clear_script_flags
/* 1B0CC 8003FCCC 24050080 */   addiu    $a1, $zero, 0x80
.L8003FCD0:
/* 1B0D0 8003FCD0 8E240054 */  lw        $a0, 0x54($s1)
/* 1B0D4 8003FCD4 0C0B11EA */  jal       get_script_by_id
/* 1B0D8 8003FCD8 00000000 */   nop
/* 1B0DC 8003FCDC 0040202D */  daddu     $a0, $v0, $zero
/* 1B0E0 8003FCE0 10800003 */  beqz      $a0, .L8003FCF0
/* 1B0E4 8003FCE4 00000000 */   nop
/* 1B0E8 8003FCE8 0C0B1220 */  jal       clear_script_flags
/* 1B0EC 8003FCEC 24050080 */   addiu    $a1, $zero, 0x80
.L8003FCF0:
/* 1B0F0 8003FCF0 8E230000 */  lw        $v1, ($s1)
/* 1B0F4 8003FCF4 3C088000 */  lui       $t0, 0x8000
/* 1B0F8 8003FCF8 00681024 */  and       $v0, $v1, $t0
/* 1B0FC 8003FCFC 144002F2 */  bnez      $v0, .L800408C8
/* 1B100 8003FD00 30620001 */   andi     $v0, $v1, 1
/* 1B104 8003FD04 1040002A */  beqz      $v0, .L8003FDB0
/* 1B108 8003FD08 3C020040 */   lui      $v0, 0x40
/* 1B10C 8003FD0C 00621024 */  and       $v0, $v1, $v0
/* 1B110 8003FD10 14400020 */  bnez      $v0, .L8003FD94
/* 1B114 8003FD14 00000000 */   nop
/* 1B118 8003FD18 8E8200C8 */  lw        $v0, 0xc8($s4)
/* 1B11C 8003FD1C 16420015 */  bne       $s2, $v0, .L8003FD74
/* 1B120 8003FD20 24033039 */   addiu    $v1, $zero, 0x3039
/* 1B124 8003FD24 C640000C */  lwc1      $f0, 0xc($s2)
/* 1B128 8003FD28 4600040D */  trunc.w.s $f16, $f0
/* 1B12C 8003FD2C 44028000 */  mfc1      $v0, $f16
/* 1B130 8003FD30 00000000 */  nop
/* 1B134 8003FD34 A62200E0 */  sh        $v0, 0xe0($s1)
/* 1B138 8003FD38 C64C0038 */  lwc1      $f12, 0x38($s2)
/* 1B13C 8003FD3C C64E0040 */  lwc1      $f14, 0x40($s2)
/* 1B140 8003FD40 8E860028 */  lw        $a2, 0x28($s4)
/* 1B144 8003FD44 0C00A720 */  jal       atan2
/* 1B148 8003FD48 8E870030 */   lw       $a3, 0x30($s4)
/* 1B14C 8003FD4C E640000C */  swc1      $f0, 0xc($s2)
/* 1B150 8003FD50 0C0B11EA */  jal       get_script_by_id
/* 1B154 8003FD54 8E240054 */   lw       $a0, 0x54($s1)
/* 1B158 8003FD58 0040202D */  daddu     $a0, $v0, $zero
/* 1B15C 8003FD5C 10800014 */  beqz      $a0, .L8003FDB0
/* 1B160 8003FD60 00000000 */   nop
/* 1B164 8003FD64 0C0B11FA */  jal       set_script_flags
/* 1B168 8003FD68 24050080 */   addiu    $a1, $zero, 0x80
/* 1B16C 8003FD6C 0800FF6C */  j         .L8003FDB0
/* 1B170 8003FD70 00000000 */   nop
.L8003FD74:
/* 1B174 8003FD74 862200E0 */  lh        $v0, 0xe0($s1)
/* 1B178 8003FD78 10430006 */  beq       $v0, $v1, .L8003FD94
/* 1B17C 8003FD7C 00000000 */   nop
/* 1B180 8003FD80 44820000 */  mtc1      $v0, $f0
/* 1B184 8003FD84 00000000 */  nop
/* 1B188 8003FD88 46800020 */  cvt.s.w   $f0, $f0
/* 1B18C 8003FD8C E640000C */  swc1      $f0, 0xc($s2)
/* 1B190 8003FD90 A62300E0 */  sh        $v1, 0xe0($s1)
.L8003FD94:
/* 1B194 8003FD94 0C0B11EA */  jal       get_script_by_id
/* 1B198 8003FD98 8E240054 */   lw       $a0, 0x54($s1)
/* 1B19C 8003FD9C 0040202D */  daddu     $a0, $v0, $zero
/* 1B1A0 8003FDA0 10800003 */  beqz      $a0, .L8003FDB0
/* 1B1A4 8003FDA4 00000000 */   nop
/* 1B1A8 8003FDA8 0C0B1220 */  jal       clear_script_flags
/* 1B1AC 8003FDAC 24050080 */   addiu    $a1, $zero, 0x80
.L8003FDB0:
/* 1B1B0 8003FDB0 8262000A */  lb        $v0, 0xa($s3)
/* 1B1B4 8003FDB4 144002C4 */  bnez      $v0, .L800408C8
/* 1B1B8 8003FDB8 24080001 */   addiu    $t0, $zero, 1
/* 1B1BC 8003FDBC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1B1C0 8003FDC0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1B1C4 8003FDC4 80420074 */  lb        $v0, 0x74($v0)
/* 1B1C8 8003FDC8 104802BF */  beq       $v0, $t0, .L800408C8
/* 1B1CC 8003FDCC 3C030008 */   lui      $v1, 8
/* 1B1D0 8003FDD0 8E820000 */  lw        $v0, ($s4)
/* 1B1D4 8003FDD4 00431024 */  and       $v0, $v0, $v1
/* 1B1D8 8003FDD8 144002BB */  bnez      $v0, .L800408C8
/* 1B1DC 8003FDDC 00000000 */   nop
/* 1B1E0 8003FDE0 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* 1B1E4 8003FDE4 8C84A650 */  lw        $a0, %lo(gOverrideFlags)($a0)
/* 1B1E8 8003FDE8 30820040 */  andi      $v0, $a0, 0x40
/* 1B1EC 8003FDEC 144002B6 */  bnez      $v0, .L800408C8
/* 1B1F0 8003FDF0 24020009 */   addiu    $v0, $zero, 9
/* 1B1F4 8003FDF4 3C038011 */  lui       $v1, %hi(gPartnerActionStatus+0x3)
/* 1B1F8 8003FDF8 8063EBB3 */  lb        $v1, %lo(gPartnerActionStatus+0x3)($v1)
/* 1B1FC 8003FDFC 106202B2 */  beq       $v1, $v0, .L800408C8
/* 1B200 8003FE00 00000000 */   nop
/* 1B204 8003FE04 8E220000 */  lw        $v0, ($s1)
/* 1B208 8003FE08 00481024 */  and       $v0, $v0, $t0
/* 1B20C 8003FE0C 144002AE */  bnez      $v0, .L800408C8
/* 1B210 8003FE10 30820F00 */   andi     $v0, $a0, 0xf00
/* 1B214 8003FE14 144002AC */  bnez      $v0, .L800408C8
/* 1B218 8003FE18 00000000 */   nop
/* 1B21C 8003FE1C 0C04D07A */  jal       is_picking_up_item
/* 1B220 8003FE20 00000000 */   nop
/* 1B224 8003FE24 144002A8 */  bnez      $v0, .L800408C8
/* 1B228 8003FE28 3C021000 */   lui      $v0, 0x1000
/* 1B22C 8003FE2C 8E230000 */  lw        $v1, ($s1)
/* 1B230 8003FE30 00621824 */  and       $v1, $v1, $v0
/* 1B234 8003FE34 14600007 */  bnez      $v1, .L8003FE54
/* 1B238 8003FE38 00000000 */   nop
/* 1B23C 8003FE3C 0C03AD79 */  jal       partner_test_enemy_collision
/* 1B240 8003FE40 0240202D */   daddu    $a0, $s2, $zero
/* 1B244 8003FE44 10400003 */  beqz      $v0, .L8003FE54
/* 1B248 8003FE48 24020006 */   addiu    $v0, $zero, 6
/* 1B24C 8003FE4C 0801015F */  j         .L8004057C
/* 1B250 8003FE50 A2620005 */   sb       $v0, 5($s3)
.L8003FE54:
/* 1B254 8003FE54 C6400038 */  lwc1      $f0, 0x38($s2)
/* 1B258 8003FE58 C65A003C */  lwc1      $f26, 0x3c($s2)
/* 1B25C 8003FE5C C658000C */  lwc1      $f24, 0xc($s2)
/* 1B260 8003FE60 C6420040 */  lwc1      $f2, 0x40($s2)
/* 1B264 8003FE64 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 1B268 8003FE68 E7A20030 */  swc1      $f2, 0x30($sp)
/* 1B26C 8003FE6C 864300A8 */  lh        $v1, 0xa8($s2)
/* 1B270 8003FE70 964200A6 */  lhu       $v0, 0xa6($s2)
/* 1B274 8003FE74 4483E000 */  mtc1      $v1, $f28
/* 1B278 8003FE78 00000000 */  nop
/* 1B27C 8003FE7C 4680E720 */  cvt.s.w   $f28, $f28
/* 1B280 8003FE80 00021400 */  sll       $v0, $v0, 0x10
/* 1B284 8003FE84 00021C03 */  sra       $v1, $v0, 0x10
/* 1B288 8003FE88 000217C2 */  srl       $v0, $v0, 0x1f
/* 1B28C 8003FE8C 00621821 */  addu      $v1, $v1, $v0
/* 1B290 8003FE90 00031843 */  sra       $v1, $v1, 1
/* 1B294 8003FE94 8E2200DC */  lw        $v0, 0xdc($s1)
/* 1B298 8003FE98 4483F000 */  mtc1      $v1, $f30
/* 1B29C 8003FE9C 00000000 */  nop
/* 1B2A0 8003FEA0 10400020 */  beqz      $v0, .L8003FF24
/* 1B2A4 8003FEA4 4680F7A0 */   cvt.s.w  $f30, $f30
/* 1B2A8 8003FEA8 8642008A */  lh        $v0, 0x8a($s2)
/* 1B2AC 8003FEAC 3C014334 */  lui       $at, 0x4334
/* 1B2B0 8003FEB0 44810000 */  mtc1      $at, $f0
/* 1B2B4 8003FEB4 4482C000 */  mtc1      $v0, $f24
/* 1B2B8 8003FEB8 00000000 */  nop
/* 1B2BC 8003FEBC 4680C620 */  cvt.s.w   $f24, $f24
/* 1B2C0 8003FEC0 4600C03C */  c.lt.s    $f24, $f0
/* 1B2C4 8003FEC4 00000000 */  nop
/* 1B2C8 8003FEC8 45000007 */  bc1f      .L8003FEE8
/* 1B2CC 8003FECC 00000000 */   nop
/* 1B2D0 8003FED0 8FA80048 */  lw        $t0, 0x48($sp)
/* 1B2D4 8003FED4 3C0142B4 */  lui       $at, 0x42b4
/* 1B2D8 8003FED8 44818000 */  mtc1      $at, $f16
/* 1B2DC 8003FEDC C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1B2E0 8003FEE0 0800FFBF */  j         .L8003FEFC
/* 1B2E4 8003FEE4 46106301 */   sub.s    $f12, $f12, $f16
.L8003FEE8:
/* 1B2E8 8003FEE8 8FA80048 */  lw        $t0, 0x48($sp)
/* 1B2EC 8003FEEC 3C0142B4 */  lui       $at, 0x42b4
/* 1B2F0 8003FEF0 44818000 */  mtc1      $at, $f16
/* 1B2F4 8003FEF4 C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1B2F8 8003FEF8 46106300 */  add.s     $f12, $f12, $f16
.L8003FEFC:
/* 1B2FC 8003FEFC 0C00A6C9 */  jal       clamp_angle
/* 1B300 8003FF00 00000000 */   nop
/* 1B304 8003FF04 46000606 */  mov.s     $f24, $f0
/* 1B308 8003FF08 27A4002C */  addiu     $a0, $sp, 0x2c
/* 1B30C 8003FF0C C63200DC */  lwc1      $f18, 0xdc($s1)
/* 1B310 8003FF10 468094A0 */  cvt.s.w   $f18, $f18
/* 1B314 8003FF14 4407C000 */  mfc1      $a3, $f24
/* 1B318 8003FF18 44069000 */  mfc1      $a2, $f18
/* 1B31C 8003FF1C 0C00A7E7 */  jal       add_vec2D_polar
/* 1B320 8003FF20 27A50030 */   addiu    $a1, $sp, 0x30
.L8003FF24:
/* 1B324 8003FF24 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 1B328 8003FF28 C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B32C 8003FF2C 46100001 */  sub.s     $f0, $f0, $f16
/* 1B330 8003FF30 46000082 */  mul.s     $f2, $f0, $f0
/* 1B334 8003FF34 00000000 */  nop
/* 1B338 8003FF38 C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B33C 8003FF3C C7A00030 */  lwc1      $f0, 0x30($sp)
/* 1B340 8003FF40 46120001 */  sub.s     $f0, $f0, $f18
/* 1B344 8003FF44 46000002 */  mul.s     $f0, $f0, $f0
/* 1B348 8003FF48 00000000 */  nop
/* 1B34C 8003FF4C 46001300 */  add.s     $f12, $f2, $f0
/* 1B350 8003FF50 46006004 */  sqrt.s    $f0, $f12
/* 1B354 8003FF54 46000032 */  c.eq.s    $f0, $f0
/* 1B358 8003FF58 00000000 */  nop
/* 1B35C 8003FF5C 45010003 */  bc1t      .L8003FF6C
/* 1B360 8003FF60 00000000 */   nop
/* 1B364 8003FF64 0C0187BC */  jal       sqrtf
/* 1B368 8003FF68 00000000 */   nop
.L8003FF6C:
/* 1B36C 8003FF6C 928200B4 */  lbu       $v0, 0xb4($s4)
/* 1B370 8003FF70 2442FFFD */  addiu     $v0, $v0, -3
/* 1B374 8003FF74 00021600 */  sll       $v0, $v0, 0x18
/* 1B378 8003FF78 00021E03 */  sra       $v1, $v0, 0x18
/* 1B37C 8003FF7C 2C620010 */  sltiu     $v0, $v1, 0x10
/* 1B380 8003FF80 10400184 */  beqz      $v0, L80040594_1B994
/* 1B384 8003FF84 46000586 */   mov.s    $f22, $f0
/* 1B388 8003FF88 00031080 */  sll       $v0, $v1, 2
/* 1B38C 8003FF8C 3C01800A */  lui       $at, %hi(jtbl_800985F8)
/* 1B390 8003FF90 00220821 */  addu      $at, $at, $v0
/* 1B394 8003FF94 8C2285F8 */  lw        $v0, %lo(jtbl_800985F8)($at)
/* 1B398 8003FF98 00400008 */  jr        $v0
/* 1B39C 8003FF9C 00000000 */   nop
dlabel L8003FFA0_1B3A0
/* 1B3A0 8003FFA0 C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B3A4 8003FFA4 C68C00A8 */  lwc1      $f12, 0xa8($s4)
/* 1B3A8 8003FFA8 C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B3AC 8003FFAC E7B00034 */  swc1      $f16, 0x34($sp)
/* 1B3B0 8003FFB0 0C00A6C9 */  jal       clamp_angle
/* 1B3B4 8003FFB4 E7B20038 */   swc1     $f18, 0x38($sp)
/* 1B3B8 8003FFB8 3C014334 */  lui       $at, 0x4334
/* 1B3BC 8003FFBC 44811000 */  mtc1      $at, $f2
/* 1B3C0 8003FFC0 C7B40054 */  lwc1      $f20, 0x54($sp)
/* 1B3C4 8003FFC4 4602003C */  c.lt.s    $f0, $f2
/* 1B3C8 8003FFC8 00000000 */  nop
/* 1B3CC 8003FFCC 45000010 */  bc1f      .L80040010
/* 1B3D0 8003FFD0 00000000 */   nop
/* 1B3D4 8003FFD4 8FA80048 */  lw        $t0, 0x48($sp)
/* 1B3D8 8003FFD8 3C0142B4 */  lui       $at, 0x42b4
/* 1B3DC 8003FFDC 44818000 */  mtc1      $at, $f16
/* 1B3E0 8003FFE0 C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1B3E4 8003FFE4 0C00A6C9 */  jal       clamp_angle
/* 1B3E8 8003FFE8 46106301 */   sub.s    $f12, $f12, $f16
/* 1B3EC 8003FFEC 8E8200A4 */  lw        $v0, 0xa4($s4)
/* 1B3F0 8003FFF0 3C030100 */  lui       $v1, 0x100
/* 1B3F4 8003FFF4 00431024 */  and       $v0, $v0, $v1
/* 1B3F8 8003FFF8 10400017 */  beqz      $v0, .L80040058
/* 1B3FC 8003FFFC 27A40034 */   addiu    $a0, $sp, 0x34
/* 1B400 80040000 3C0141F0 */  lui       $at, 0x41f0
/* 1B404 80040004 44816000 */  mtc1      $at, $f12
/* 1B408 80040008 08010013 */  j         .L8004004C
/* 1B40C 8004000C 460C0300 */   add.s    $f12, $f0, $f12
.L80040010:
/* 1B410 80040010 8FA80048 */  lw        $t0, 0x48($sp)
/* 1B414 80040014 3C0142B4 */  lui       $at, 0x42b4
/* 1B418 80040018 44818000 */  mtc1      $at, $f16
/* 1B41C 8004001C C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1B420 80040020 0C00A6C9 */  jal       clamp_angle
/* 1B424 80040024 46106300 */   add.s    $f12, $f12, $f16
/* 1B428 80040028 8E8200A4 */  lw        $v0, 0xa4($s4)
/* 1B42C 8004002C 3C030100 */  lui       $v1, 0x100
/* 1B430 80040030 00431024 */  and       $v0, $v0, $v1
/* 1B434 80040034 10400008 */  beqz      $v0, .L80040058
/* 1B438 80040038 27A40034 */   addiu    $a0, $sp, 0x34
/* 1B43C 8004003C 3C0141F0 */  lui       $at, 0x41f0
/* 1B440 80040040 44816000 */  mtc1      $at, $f12
/* 1B444 80040044 00000000 */  nop
/* 1B448 80040048 460C0301 */  sub.s     $f12, $f0, $f12
.L8004004C:
/* 1B44C 8004004C 0C00A6C9 */  jal       clamp_angle
/* 1B450 80040050 00000000 */   nop
/* 1B454 80040054 27A40034 */  addiu     $a0, $sp, 0x34
.L80040058:
/* 1B458 80040058 3C0641C0 */  lui       $a2, 0x41c0
/* 1B45C 8004005C 44070000 */  mfc1      $a3, $f0
/* 1B460 80040060 0C00A7E7 */  jal       add_vec2D_polar
/* 1B464 80040064 27A50038 */   addiu    $a1, $sp, 0x38
/* 1B468 80040068 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 1B46C 8004006C C7A00034 */  lwc1      $f0, 0x34($sp)
/* 1B470 80040070 46001001 */  sub.s     $f0, $f2, $f0
/* 1B474 80040074 46000102 */  mul.s     $f4, $f0, $f0
/* 1B478 80040078 00000000 */  nop
/* 1B47C 8004007C C7A20030 */  lwc1      $f2, 0x30($sp)
/* 1B480 80040080 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 1B484 80040084 46001001 */  sub.s     $f0, $f2, $f0
/* 1B488 80040088 46000002 */  mul.s     $f0, $f0, $f0
/* 1B48C 8004008C 00000000 */  nop
/* 1B490 80040090 46002300 */  add.s     $f12, $f4, $f0
/* 1B494 80040094 46006004 */  sqrt.s    $f0, $f12
/* 1B498 80040098 46000032 */  c.eq.s    $f0, $f0
/* 1B49C 8004009C 00000000 */  nop
/* 1B4A0 800400A0 45010003 */  bc1t      .L800400B0
/* 1B4A4 800400A4 00000000 */   nop
/* 1B4A8 800400A8 0C0187BC */  jal       sqrtf
/* 1B4AC 800400AC 00000000 */   nop
.L800400B0:
/* 1B4B0 800400B0 8E220000 */  lw        $v0, ($s1)
/* 1B4B4 800400B4 3C030400 */  lui       $v1, 0x400
/* 1B4B8 800400B8 00431024 */  and       $v0, $v0, $v1
/* 1B4BC 800400BC 14400135 */  bnez      $v0, L80040594_1B994
/* 1B4C0 800400C0 46000586 */   mov.s    $f22, $f0
/* 1B4C4 800400C4 8E820000 */  lw        $v0, ($s4)
/* 1B4C8 800400C8 3C030100 */  lui       $v1, 0x100
/* 1B4CC 800400CC 00431024 */  and       $v0, $v0, $v1
/* 1B4D0 800400D0 10400130 */  beqz      $v0, L80040594_1B994
/* 1B4D4 800400D4 00000000 */   nop
/* 1B4D8 800400D8 3C014160 */  lui       $at, 0x4160
/* 1B4DC 800400DC 44819000 */  mtc1      $at, $f18
/* 1B4E0 800400E0 00000000 */  nop
/* 1B4E4 800400E4 461E9000 */  add.s     $f0, $f18, $f30
/* 1B4E8 800400E8 4616003E */  c.le.s    $f0, $f22
/* 1B4EC 800400EC 00000000 */  nop
/* 1B4F0 800400F0 45010128 */  bc1t      L80040594_1B994
/* 1B4F4 800400F4 00000000 */   nop
/* 1B4F8 800400F8 461CD000 */  add.s     $f0, $f26, $f28
/* 1B4FC 800400FC 4614003C */  c.lt.s    $f0, $f20
/* 1B500 80040100 00000000 */  nop
/* 1B504 80040104 45010123 */  bc1t      L80040594_1B994
/* 1B508 80040108 00000000 */   nop
/* 1B50C 8004010C 3C014190 */  lui       $at, 0x4190
/* 1B510 80040110 44818000 */  mtc1      $at, $f16
/* 1B514 80040114 00000000 */  nop
/* 1B518 80040118 4610A000 */  add.s     $f0, $f20, $f16
/* 1B51C 8004011C 461A003C */  c.lt.s    $f0, $f26
/* 1B520 80040120 00000000 */  nop
/* 1B524 80040124 4501011B */  bc1t      L80040594_1B994
/* 1B528 80040128 00000000 */   nop
/* 1B52C 8004012C 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B530 80040130 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B534 80040134 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B538 80040138 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B53C 8004013C E7BA0040 */  swc1      $f26, 0x40($sp)
/* 1B540 80040140 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B544 80040144 0C00A720 */  jal       atan2
/* 1B548 80040148 E7AE0044 */   swc1     $f14, 0x44($sp)
/* 1B54C 8004014C 3C040001 */  lui       $a0, 1
/* 1B550 80040150 03C0302D */  daddu     $a2, $fp, $zero
/* 1B554 80040154 02E0382D */  daddu     $a3, $s7, $zero
/* 1B558 80040158 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B55C 8004015C 461EF500 */  add.s     $f20, $f30, $f30
/* 1B560 80040160 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B564 80040164 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B568 80040168 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B56C 8004016C 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 1B570 80040170 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B574 80040174 10400016 */  beqz      $v0, .L800401D0
/* 1B578 80040178 00000000 */   nop
/* 1B57C 8004017C C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B580 80040180 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B584 80040184 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B588 80040188 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B58C 8004018C C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B590 80040190 46007406 */  mov.s     $f16, $f14
/* 1B594 80040194 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B598 80040198 E7B20040 */  swc1      $f18, 0x40($sp)
/* 1B59C 8004019C 0C00A720 */  jal       atan2
/* 1B5A0 800401A0 E7B00044 */   swc1     $f16, 0x44($sp)
/* 1B5A4 800401A4 3C040001 */  lui       $a0, 1
/* 1B5A8 800401A8 03C0302D */  daddu     $a2, $fp, $zero
/* 1B5AC 800401AC 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B5B0 800401B0 02E0382D */  daddu     $a3, $s7, $zero
/* 1B5B4 800401B4 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B5B8 800401B8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B5BC 800401BC E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B5C0 800401C0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 1B5C4 800401C4 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B5C8 800401C8 144000F2 */  bnez      $v0, L80040594_1B994
/* 1B5CC 800401CC 00000000 */   nop
.L800401D0:
/* 1B5D0 800401D0 82220007 */  lb        $v0, 7($s1)
/* 1B5D4 800401D4 1040000F */  beqz      $v0, .L80040214
/* 1B5D8 800401D8 00000000 */   nop
/* 1B5DC 800401DC 86220012 */  lh        $v0, 0x12($s1)
/* 1B5E0 800401E0 4482D000 */  mtc1      $v0, $f26
/* 1B5E4 800401E4 00000000 */  nop
/* 1B5E8 800401E8 4680D6A0 */  cvt.s.w   $f26, $f26
/* 1B5EC 800401EC 86220010 */  lh        $v0, 0x10($s1)
/* 1B5F0 800401F0 86230014 */  lh        $v1, 0x14($s1)
/* 1B5F4 800401F4 44820000 */  mtc1      $v0, $f0
/* 1B5F8 800401F8 00000000 */  nop
/* 1B5FC 800401FC 46800020 */  cvt.s.w   $f0, $f0
/* 1B600 80040200 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 1B604 80040204 44830000 */  mtc1      $v1, $f0
/* 1B608 80040208 00000000 */  nop
/* 1B60C 8004020C 46800020 */  cvt.s.w   $f0, $f0
/* 1B610 80040210 E7A00030 */  swc1      $f0, 0x30($sp)
.L80040214:
/* 1B614 80040214 C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B618 80040218 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B61C 8004021C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B620 80040220 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B624 80040224 0C00A720 */  jal       atan2
/* 1B628 80040228 0000802D */   daddu    $s0, $zero, $zero
/* 1B62C 8004022C C7AE005C */  lwc1      $f14, 0x5c($sp)
/* 1B630 80040230 0C00A70A */  jal       get_clamped_angle_diff
/* 1B634 80040234 46000306 */   mov.s    $f12, $f0
/* 1B638 80040238 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B63C 8004023C C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B640 80040240 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B644 80040244 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B648 80040248 0C00A720 */  jal       atan2
/* 1B64C 8004024C 46000505 */   abs.s    $f20, $f0
/* 1B650 80040250 46000306 */  mov.s     $f12, $f0
/* 1B654 80040254 0C00A70A */  jal       get_clamped_angle_diff
/* 1B658 80040258 4600C386 */   mov.s    $f14, $f24
/* 1B65C 8004025C 3C0142B4 */  lui       $at, 0x42b4
/* 1B660 80040260 44819000 */  mtc1      $at, $f18
/* 1B664 80040264 3C0142B4 */  lui       $at, 0x42b4
/* 1B668 80040268 44818000 */  mtc1      $at, $f16
/* 1B66C 8004026C 00000000 */  nop
/* 1B670 80040270 4610A03C */  c.lt.s    $f20, $f16
/* 1B674 80040274 00000000 */  nop
/* 1B678 80040278 45000008 */  bc1f      .L8004029C
/* 1B67C 8004027C 46000005 */   abs.s    $f0, $f0
/* 1B680 80040280 4600803E */  c.le.s    $f16, $f0
/* 1B684 80040284 00000000 */  nop
/* 1B688 80040288 45030004 */  bc1tl     .L8004029C
/* 1B68C 8004028C 24100001 */   addiu    $s0, $zero, 1
/* 1B690 80040290 3C0142B4 */  lui       $at, 0x42b4
/* 1B694 80040294 44819000 */  mtc1      $at, $f18
/* 1B698 80040298 00000000 */  nop
.L8004029C:
/* 1B69C 8004029C 4614903E */  c.le.s    $f18, $f20
/* 1B6A0 800402A0 00000000 */  nop
/* 1B6A4 800402A4 45000005 */  bc1f      .L800402BC
/* 1B6A8 800402A8 00000000 */   nop
/* 1B6AC 800402AC 4612003C */  c.lt.s    $f0, $f18
/* 1B6B0 800402B0 00000000 */  nop
/* 1B6B4 800402B4 45030001 */  bc1tl     .L800402BC
/* 1B6B8 800402B8 0000802D */   daddu    $s0, $zero, $zero
.L800402BC:
/* 1B6BC 800402BC 3C0142B4 */  lui       $at, 0x42b4
/* 1B6C0 800402C0 44818000 */  mtc1      $at, $f16
/* 1B6C4 800402C4 00000000 */  nop
/* 1B6C8 800402C8 4610A03C */  c.lt.s    $f20, $f16
/* 1B6CC 800402CC 00000000 */  nop
/* 1B6D0 800402D0 45000005 */  bc1f      .L800402E8
/* 1B6D4 800402D4 00000000 */   nop
/* 1B6D8 800402D8 4610003C */  c.lt.s    $f0, $f16
/* 1B6DC 800402DC 00000000 */  nop
/* 1B6E0 800402E0 45030001 */  bc1tl     .L800402E8
/* 1B6E4 800402E4 24100001 */   addiu    $s0, $zero, 1
.L800402E8:
/* 1B6E8 800402E8 120000AA */  beqz      $s0, L80040594_1B994
/* 1B6EC 800402EC 240400E1 */   addiu    $a0, $zero, 0xe1
/* 1B6F0 800402F0 8E860028 */  lw        $a2, 0x28($s4)
/* 1B6F4 800402F4 8E87002C */  lw        $a3, 0x2c($s4)
/* 1B6F8 800402F8 C6800030 */  lwc1      $f0, 0x30($s4)
/* 1B6FC 800402FC 0000282D */  daddu     $a1, $zero, $zero
/* 1B700 80040300 0C052757 */  jal       sfx_play_sound_at_position
/* 1B704 80040304 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1B708 80040308 3C038011 */  lui       $v1, %hi(gPlayerData+0x1)
/* 1B70C 8004030C 9063F291 */  lbu       $v1, %lo(gPlayerData+0x1)($v1)
/* 1B710 80040310 24020004 */  addiu     $v0, $zero, 4
/* 1B714 80040314 A2620005 */  sb        $v0, 5($s3)
/* 1B718 80040318 0801015F */  j         .L8004057C
/* 1B71C 8004031C A2630006 */   sb       $v1, 6($s3)
dlabel L80040320_1B720
/* 1B720 80040320 C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B724 80040324 C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B728 80040328 E7B00034 */  swc1      $f16, 0x34($sp)
/* 1B72C 8004032C E7B20038 */  swc1      $f18, 0x38($sp)
/* 1B730 80040330 8E220000 */  lw        $v0, ($s1)
/* 1B734 80040334 3C030200 */  lui       $v1, 0x200
/* 1B738 80040338 00431024 */  and       $v0, $v0, $v1
/* 1B73C 8004033C 14400095 */  bnez      $v0, L80040594_1B994
/* 1B740 80040340 00000000 */   nop
/* 1B744 80040344 3C014160 */  lui       $at, 0x4160
/* 1B748 80040348 44818000 */  mtc1      $at, $f16
/* 1B74C 8004034C 00000000 */  nop
/* 1B750 80040350 461E8000 */  add.s     $f0, $f16, $f30
/* 1B754 80040354 4616003E */  c.le.s    $f0, $f22
/* 1B758 80040358 00000000 */  nop
/* 1B75C 8004035C 4501015A */  bc1t      .L800408C8
/* 1B760 80040360 00000000 */   nop
/* 1B764 80040364 461CD600 */  add.s     $f24, $f26, $f28
/* 1B768 80040368 C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B76C 8004036C 4612C03C */  c.lt.s    $f24, $f18
/* 1B770 80040370 00000000 */  nop
/* 1B774 80040374 45010154 */  bc1t      .L800408C8
/* 1B778 80040378 00000000 */   nop
/* 1B77C 8004037C 3C014214 */  lui       $at, 0x4214
/* 1B780 80040380 44818000 */  mtc1      $at, $f16
/* 1B784 80040384 00000000 */  nop
/* 1B788 80040388 46109000 */  add.s     $f0, $f18, $f16
/* 1B78C 8004038C 461A003C */  c.lt.s    $f0, $f26
/* 1B790 80040390 00000000 */  nop
/* 1B794 80040394 4501014C */  bc1t      .L800408C8
/* 1B798 80040398 00000000 */   nop
/* 1B79C 8004039C 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B7A0 800403A0 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B7A4 800403A4 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B7A8 800403A8 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B7AC 800403AC E7BA0040 */  swc1      $f26, 0x40($sp)
/* 1B7B0 800403B0 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B7B4 800403B4 0C00A720 */  jal       atan2
/* 1B7B8 800403B8 E7AE0044 */   swc1     $f14, 0x44($sp)
/* 1B7BC 800403BC 3C040001 */  lui       $a0, 1
/* 1B7C0 800403C0 03C0302D */  daddu     $a2, $fp, $zero
/* 1B7C4 800403C4 02E0382D */  daddu     $a3, $s7, $zero
/* 1B7C8 800403C8 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B7CC 800403CC 461EF500 */  add.s     $f20, $f30, $f30
/* 1B7D0 800403D0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B7D4 800403D4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B7D8 800403D8 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B7DC 800403DC 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 1B7E0 800403E0 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B7E4 800403E4 10400016 */  beqz      $v0, .L80040440
/* 1B7E8 800403E8 00000000 */   nop
/* 1B7EC 800403EC C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B7F0 800403F0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B7F4 800403F4 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B7F8 800403F8 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B7FC 800403FC C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B800 80040400 46007406 */  mov.s     $f16, $f14
/* 1B804 80040404 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B808 80040408 E7B20040 */  swc1      $f18, 0x40($sp)
/* 1B80C 8004040C 0C00A720 */  jal       atan2
/* 1B810 80040410 E7B00044 */   swc1     $f16, 0x44($sp)
/* 1B814 80040414 3C040001 */  lui       $a0, 1
/* 1B818 80040418 03C0302D */  daddu     $a2, $fp, $zero
/* 1B81C 8004041C 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B820 80040420 02E0382D */  daddu     $a3, $s7, $zero
/* 1B824 80040424 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B828 80040428 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B82C 8004042C E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B830 80040430 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 1B834 80040434 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B838 80040438 14400056 */  bnez      $v0, L80040594_1B994
/* 1B83C 8004043C 00000000 */   nop
.L80040440:
/* 1B840 80040440 3C014214 */  lui       $at, 0x4214
/* 1B844 80040444 44819000 */  mtc1      $at, $f18
/* 1B848 80040448 3C013F00 */  lui       $at, 0x3f00
/* 1B84C 8004044C 44818000 */  mtc1      $at, $f16
/* 1B850 80040450 00000000 */  nop
/* 1B854 80040454 46109002 */  mul.s     $f0, $f18, $f16
/* 1B858 80040458 00000000 */  nop
/* 1B85C 8004045C C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B860 80040460 46009000 */  add.s     $f0, $f18, $f0
/* 1B864 80040464 4600C03C */  c.lt.s    $f24, $f0
/* 1B868 80040468 00000000 */  nop
/* 1B86C 8004046C 45000015 */  bc1f      .L800404C4
/* 1B870 80040470 0000802D */   daddu    $s0, $zero, $zero
/* 1B874 80040474 928300B4 */  lbu       $v1, 0xb4($s4)
/* 1B878 80040478 2462FFF8 */  addiu     $v0, $v1, -8
/* 1B87C 8004047C 2C420004 */  sltiu     $v0, $v0, 4
/* 1B880 80040480 54400010 */  bnel      $v0, $zero, .L800404C4
/* 1B884 80040484 24100001 */   addiu    $s0, $zero, 1
/* 1B888 80040488 00031600 */  sll       $v0, $v1, 0x18
/* 1B88C 8004048C 00021E03 */  sra       $v1, $v0, 0x18
/* 1B890 80040490 2402000D */  addiu     $v0, $zero, 0xd
/* 1B894 80040494 10620007 */  beq       $v1, $v0, .L800404B4
/* 1B898 80040498 2402000E */   addiu    $v0, $zero, 0xe
/* 1B89C 8004049C 10620005 */  beq       $v1, $v0, .L800404B4
/* 1B8A0 800404A0 2402000F */   addiu    $v0, $zero, 0xf
/* 1B8A4 800404A4 10620003 */  beq       $v1, $v0, .L800404B4
/* 1B8A8 800404A8 24020010 */   addiu    $v0, $zero, 0x10
/* 1B8AC 800404AC 14620005 */  bne       $v1, $v0, .L800404C4
/* 1B8B0 800404B0 00000000 */   nop
.L800404B4:
/* 1B8B4 800404B4 24100001 */  addiu     $s0, $zero, 1
/* 1B8B8 800404B8 3C013F00 */  lui       $at, 0x3f00
/* 1B8BC 800404BC 44818000 */  mtc1      $at, $f16
/* 1B8C0 800404C0 00000000 */  nop
.L800404C4:
/* 1B8C4 800404C4 4610E002 */  mul.s     $f0, $f28, $f16
/* 1B8C8 800404C8 00000000 */  nop
/* 1B8CC 800404CC C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B8D0 800404D0 3C014214 */  lui       $at, 0x4214
/* 1B8D4 800404D4 44818000 */  mtc1      $at, $f16
/* 1B8D8 800404D8 00000000 */  nop
/* 1B8DC 800404DC 46109080 */  add.s     $f2, $f18, $f16
/* 1B8E0 800404E0 4600D000 */  add.s     $f0, $f26, $f0
/* 1B8E4 800404E4 4600103C */  c.lt.s    $f2, $f0
/* 1B8E8 800404E8 00000000 */  nop
/* 1B8EC 800404EC 45030001 */  bc1tl     .L800404F4
/* 1B8F0 800404F0 0000802D */   daddu    $s0, $zero, $zero
.L800404F4:
/* 1B8F4 800404F4 12000027 */  beqz      $s0, L80040594_1B994
/* 1B8F8 800404F8 00000000 */   nop
/* 1B8FC 800404FC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 1B900 80040500 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 1B904 80040504 0440FD12 */  bltz      $v0, .L8003F950
/* 1B908 80040508 24030002 */   addiu    $v1, $zero, 2
/* 1B90C 8004050C 928200B4 */  lbu       $v0, 0xb4($s4)
/* 1B910 80040510 A2630005 */  sb        $v1, 5($s3)
/* 1B914 80040514 2442FFFD */  addiu     $v0, $v0, -3
/* 1B918 80040518 00021600 */  sll       $v0, $v0, 0x18
/* 1B91C 8004051C 00021E03 */  sra       $v1, $v0, 0x18
/* 1B920 80040520 2C62000E */  sltiu     $v0, $v1, 0xe
/* 1B924 80040524 1040000D */  beqz      $v0, L8004055C_1B95C
/* 1B928 80040528 00031080 */   sll      $v0, $v1, 2
/* 1B92C 8004052C 3C01800A */  lui       $at, %hi(jtbl_80098638)
/* 1B930 80040530 00220821 */  addu      $at, $at, $v0
/* 1B934 80040534 8C228638 */  lw        $v0, %lo(jtbl_80098638)($at)
/* 1B938 80040538 00400008 */  jr        $v0
/* 1B93C 8004053C 00000000 */   nop
dlabel L80040540_1B940
/* 1B940 80040540 08010157 */  j         L8004055C_1B95C
/* 1B944 80040544 A2600006 */   sb       $zero, 6($s3)
dlabel L80040548_1B948
/* 1B948 80040548 24080001 */  addiu     $t0, $zero, 1
/* 1B94C 8004054C 08010157 */  j         L8004055C_1B95C
/* 1B950 80040550 A2680006 */   sb       $t0, 6($s3)
dlabel L80040554_1B954
/* 1B954 80040554 24020002 */  addiu     $v0, $zero, 2
/* 1B958 80040558 A2620006 */  sb        $v0, 6($s3)
dlabel L8004055C_1B95C
/* 1B95C 8004055C 240400E1 */  addiu     $a0, $zero, 0xe1
/* 1B960 80040560 8E860028 */  lw        $a2, 0x28($s4)
/* 1B964 80040564 8E87002C */  lw        $a3, 0x2c($s4)
/* 1B968 80040568 C6800030 */  lwc1      $f0, 0x30($s4)
/* 1B96C 8004056C 0000282D */  daddu     $a1, $zero, $zero
/* 1B970 80040570 0C052757 */  jal       sfx_play_sound_at_position
/* 1B974 80040574 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1B978 80040578 24020002 */  addiu     $v0, $zero, 2
.L8004057C:
/* 1B97C 8004057C A2220005 */  sb        $v0, 5($s1)
/* 1B980 80040580 24080001 */  addiu     $t0, $zero, 1
/* 1B984 80040584 AE760088 */  sw        $s6, 0x88($s3)
/* 1B988 80040588 AE71008C */  sw        $s1, 0x8c($s3)
/* 1B98C 8004058C 0801023D */  j         .L800408F4
/* 1B990 80040590 A2680004 */   sb       $t0, 4($s3)
dlabel L80040594_1B994
/* 1B994 80040594 8E220000 */  lw        $v0, ($s1)
/* 1B998 80040598 3C030100 */  lui       $v1, 0x100
/* 1B99C 8004059C 00431024 */  and       $v0, $v0, $v1
/* 1B9A0 800405A0 144000C9 */  bnez      $v0, .L800408C8
/* 1B9A4 800405A4 00000000 */   nop
/* 1B9A8 800405A8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 1B9AC 800405AC C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B9B0 800405B0 46100001 */  sub.s     $f0, $f0, $f16
/* 1B9B4 800405B4 46000082 */  mul.s     $f2, $f0, $f0
/* 1B9B8 800405B8 00000000 */  nop
/* 1B9BC 800405BC C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B9C0 800405C0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 1B9C4 800405C4 46120001 */  sub.s     $f0, $f0, $f18
/* 1B9C8 800405C8 46000002 */  mul.s     $f0, $f0, $f0
/* 1B9CC 800405CC 00000000 */  nop
/* 1B9D0 800405D0 46001300 */  add.s     $f12, $f2, $f0
/* 1B9D4 800405D4 46006104 */  sqrt.s    $f4, $f12
/* 1B9D8 800405D8 46042032 */  c.eq.s    $f4, $f4
/* 1B9DC 800405DC 00000000 */  nop
/* 1B9E0 800405E0 45010004 */  bc1t      .L800405F4
/* 1B9E4 800405E4 00000000 */   nop
/* 1B9E8 800405E8 0C0187BC */  jal       sqrtf
/* 1B9EC 800405EC 00000000 */   nop
/* 1B9F0 800405F0 46000106 */  mov.s     $f4, $f0
.L800405F4:
/* 1B9F4 800405F4 3C014160 */  lui       $at, 0x4160
/* 1B9F8 800405F8 44818000 */  mtc1      $at, $f16
/* 1B9FC 800405FC 00000000 */  nop
/* 1BA00 80040600 461E8000 */  add.s     $f0, $f16, $f30
/* 1BA04 80040604 3C01800A */  lui       $at, %hi(D_80098670)
/* 1BA08 80040608 D4228670 */  ldc1      $f2, %lo(D_80098670)($at)
/* 1BA0C 8004060C 46000021 */  cvt.d.s   $f0, $f0
/* 1BA10 80040610 46220002 */  mul.d     $f0, $f0, $f2
/* 1BA14 80040614 00000000 */  nop
/* 1BA18 80040618 46002586 */  mov.s     $f22, $f4
/* 1BA1C 8004061C 4600B0A1 */  cvt.d.s   $f2, $f22
/* 1BA20 80040620 4622003E */  c.le.d    $f0, $f2
/* 1BA24 80040624 00000000 */  nop
/* 1BA28 80040628 450100A7 */  bc1t      .L800408C8
/* 1BA2C 8004062C 00000000 */   nop
/* 1BA30 80040630 461CD000 */  add.s     $f0, $f26, $f28
/* 1BA34 80040634 C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1BA38 80040638 4612003C */  c.lt.s    $f0, $f18
/* 1BA3C 8004063C 00000000 */  nop
/* 1BA40 80040640 450100A1 */  bc1t      .L800408C8
/* 1BA44 80040644 00000000 */   nop
/* 1BA48 80040648 3C014214 */  lui       $at, 0x4214
/* 1BA4C 8004064C 44818000 */  mtc1      $at, $f16
/* 1BA50 80040650 00000000 */  nop
/* 1BA54 80040654 46109000 */  add.s     $f0, $f18, $f16
/* 1BA58 80040658 461A003C */  c.lt.s    $f0, $f26
/* 1BA5C 8004065C 00000000 */  nop
/* 1BA60 80040660 45010099 */  bc1t      .L800408C8
/* 1BA64 80040664 00000000 */   nop
/* 1BA68 80040668 8FA60050 */  lw        $a2, 0x50($sp)
/* 1BA6C 8004066C 8FA70058 */  lw        $a3, 0x58($sp)
/* 1BA70 80040670 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1BA74 80040674 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1BA78 80040678 E7BA0040 */  swc1      $f26, 0x40($sp)
/* 1BA7C 8004067C E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1BA80 80040680 0C00A720 */  jal       atan2
/* 1BA84 80040684 E7AE0044 */   swc1     $f14, 0x44($sp)
/* 1BA88 80040688 3C040001 */  lui       $a0, 1
/* 1BA8C 8004068C 03C0302D */  daddu     $a2, $fp, $zero
/* 1BA90 80040690 02E0382D */  daddu     $a3, $s7, $zero
/* 1BA94 80040694 8FA50064 */  lw        $a1, 0x64($sp)
/* 1BA98 80040698 461EF500 */  add.s     $f20, $f30, $f30
/* 1BA9C 8004069C E7B60010 */  swc1      $f22, 0x10($sp)
/* 1BAA0 800406A0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1BAA4 800406A4 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1BAA8 800406A8 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 1BAAC 800406AC E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1BAB0 800406B0 10400016 */  beqz      $v0, .L8004070C
/* 1BAB4 800406B4 0000802D */   daddu    $s0, $zero, $zero
/* 1BAB8 800406B8 C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1BABC 800406BC 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1BAC0 800406C0 8FA70030 */  lw        $a3, 0x30($sp)
/* 1BAC4 800406C4 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1BAC8 800406C8 C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1BACC 800406CC 46007406 */  mov.s     $f16, $f14
/* 1BAD0 800406D0 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1BAD4 800406D4 E7B20040 */  swc1      $f18, 0x40($sp)
/* 1BAD8 800406D8 0C00A720 */  jal       atan2
/* 1BADC 800406DC E7B00044 */   swc1     $f16, 0x44($sp)
/* 1BAE0 800406E0 3C040001 */  lui       $a0, 1
/* 1BAE4 800406E4 03C0302D */  daddu     $a2, $fp, $zero
/* 1BAE8 800406E8 8FA50064 */  lw        $a1, 0x64($sp)
/* 1BAEC 800406EC 02E0382D */  daddu     $a3, $s7, $zero
/* 1BAF0 800406F0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1BAF4 800406F4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1BAF8 800406F8 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1BAFC 800406FC 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 1BB00 80040700 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1BB04 80040704 14400070 */  bnez      $v0, .L800408C8
/* 1BB08 80040708 0000802D */   daddu    $s0, $zero, $zero
.L8004070C:
/* 1BB0C 8004070C 0C03A752 */  jal       is_ability_active
/* 1BB10 80040710 24040028 */   addiu    $a0, $zero, 0x28
/* 1BB14 80040714 1040000A */  beqz      $v0, .L80040740
/* 1BB18 80040718 00000000 */   nop
/* 1BB1C 8004071C 8E220018 */  lw        $v0, 0x18($s1)
/* 1BB20 80040720 3C038011 */  lui       $v1, %hi(gPlayerData+0x9)
/* 1BB24 80040724 8063F299 */  lb        $v1, %lo(gPlayerData+0x9)($v1)
/* 1BB28 80040728 84420028 */  lh        $v0, 0x28($v0)
/* 1BB2C 8004072C 0062182A */  slt       $v1, $v1, $v0
/* 1BB30 80040730 14600003 */  bnez      $v1, .L80040740
/* 1BB34 80040734 00000000 */   nop
/* 1BB38 80040738 82620012 */  lb        $v0, 0x12($s3)
/* 1BB3C 8004073C 2C500001 */  sltiu     $s0, $v0, 1
.L80040740:
/* 1BB40 80040740 0C03A752 */  jal       is_ability_active
/* 1BB44 80040744 2404002D */   addiu    $a0, $zero, 0x2d
/* 1BB48 80040748 54400001 */  bnel      $v0, $zero, .L80040750
/* 1BB4C 8004074C 24100001 */   addiu    $s0, $zero, 1
.L80040750:
/* 1BB50 80040750 8E820004 */  lw        $v0, 4($s4)
/* 1BB54 80040754 3C030001 */  lui       $v1, 1
/* 1BB58 80040758 00431024 */  and       $v0, $v0, $v1
/* 1BB5C 8004075C 10400007 */  beqz      $v0, .L8004077C
/* 1BB60 80040760 3C032000 */   lui      $v1, 0x2000
/* 1BB64 80040764 8E220000 */  lw        $v0, ($s1)
/* 1BB68 80040768 00431024 */  and       $v0, $v0, $v1
/* 1BB6C 8004076C 14400004 */  bnez      $v0, .L80040780
/* 1BB70 80040770 3C03FFFD */   lui      $v1, 0xfffd
/* 1BB74 80040774 1600FC7E */  bnez      $s0, .L8003F970
/* 1BB78 80040778 240400E1 */   addiu    $a0, $zero, 0xe1
.L8004077C:
/* 1BB7C 8004077C 3C03FFFD */  lui       $v1, 0xfffd
.L80040780:
/* 1BB80 80040780 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1BB84 80040784 8E820004 */  lw        $v0, 4($s4)
/* 1BB88 80040788 24080001 */  addiu     $t0, $zero, 1
/* 1BB8C 8004078C A2680005 */  sb        $t0, 5($s3)
/* 1BB90 80040790 00431024 */  and       $v0, $v0, $v1
/* 1BB94 80040794 AE820004 */  sw        $v0, 4($s4)
/* 1BB98 80040798 A2280005 */  sb        $t0, 5($s1)
/* 1BB9C 8004079C AE760088 */  sw        $s6, 0x88($s3)
/* 1BBA0 800407A0 AE71008C */  sw        $s1, 0x8c($s3)
/* 1BBA4 800407A4 C6460038 */  lwc1      $f6, 0x38($s2)
/* 1BBA8 800407A8 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1BBAC 800407AC 460A3181 */  sub.s     $f6, $f6, $f10
/* 1BBB0 800407B0 3C013F00 */  lui       $at, 0x3f00
/* 1BBB4 800407B4 44818000 */  mtc1      $at, $f16
/* 1BBB8 800407B8 00000000 */  nop
/* 1BBBC 800407BC 46103182 */  mul.s     $f6, $f6, $f16
/* 1BBC0 800407C0 00000000 */  nop
/* 1BBC4 800407C4 864200A8 */  lh        $v0, 0xa8($s2)
/* 1BBC8 800407C8 C644003C */  lwc1      $f4, 0x3c($s2)
/* 1BBCC 800407CC 44820000 */  mtc1      $v0, $f0
/* 1BBD0 800407D0 00000000 */  nop
/* 1BBD4 800407D4 46800020 */  cvt.s.w   $f0, $f0
/* 1BBD8 800407D8 46002100 */  add.s     $f4, $f4, $f0
/* 1BBDC 800407DC 868200B0 */  lh        $v0, 0xb0($s4)
/* 1BBE0 800407E0 C688002C */  lwc1      $f8, 0x2c($s4)
/* 1BBE4 800407E4 44820000 */  mtc1      $v0, $f0
/* 1BBE8 800407E8 00000000 */  nop
/* 1BBEC 800407EC 46800020 */  cvt.s.w   $f0, $f0
/* 1BBF0 800407F0 46004000 */  add.s     $f0, $f8, $f0
/* 1BBF4 800407F4 46002101 */  sub.s     $f4, $f4, $f0
/* 1BBF8 800407F8 46102102 */  mul.s     $f4, $f4, $f16
/* 1BBFC 800407FC 00000000 */  nop
/* 1BC00 80040800 C6820030 */  lwc1      $f2, 0x30($s4)
/* 1BC04 80040804 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1BC08 80040808 46020001 */  sub.s     $f0, $f0, $f2
/* 1BC0C 8004080C 46100002 */  mul.s     $f0, $f0, $f16
/* 1BC10 80040810 00000000 */  nop
/* 1BC14 80040814 46065280 */  add.s     $f10, $f10, $f6
/* 1BC18 80040818 46044200 */  add.s     $f8, $f8, $f4
/* 1BC1C 8004081C 24040003 */  addiu     $a0, $zero, 3
/* 1BC20 80040820 44055000 */  mfc1      $a1, $f10
/* 1BC24 80040824 46001080 */  add.s     $f2, $f2, $f0
/* 1BC28 80040828 3C01BF80 */  lui       $at, 0xbf80
/* 1BC2C 8004082C 44810000 */  mtc1      $at, $f0
/* 1BC30 80040830 44064000 */  mfc1      $a2, $f8
/* 1BC34 80040834 44071000 */  mfc1      $a3, $f2
/* 1BC38 80040838 0080102D */  daddu     $v0, $a0, $zero
/* 1BC3C 8004083C AFA5003C */  sw        $a1, 0x3c($sp)
/* 1BC40 80040840 AFA60040 */  sw        $a2, 0x40($sp)
/* 1BC44 80040844 AFA70044 */  sw        $a3, 0x44($sp)
/* 1BC48 80040848 AFA00010 */  sw        $zero, 0x10($sp)
/* 1BC4C 8004084C E7A00014 */  swc1      $f0, 0x14($sp)
/* 1BC50 80040850 AFA00018 */  sw        $zero, 0x18($sp)
/* 1BC54 80040854 0C01C064 */  jal       playFX_18
/* 1BC58 80040858 AFA2001C */   sw       $v0, 0x1c($sp)
/* 1BC5C 8004085C 82220007 */  lb        $v0, 7($s1)
/* 1BC60 80040860 10400005 */  beqz      $v0, .L80040878
/* 1BC64 80040864 0000802D */   daddu    $s0, $zero, $zero
/* 1BC68 80040868 0C03A752 */  jal       is_ability_active
/* 1BC6C 8004086C 24040011 */   addiu    $a0, $zero, 0x11
/* 1BC70 80040870 2C420001 */  sltiu     $v0, $v0, 1
/* 1BC74 80040874 00028040 */  sll       $s0, $v0, 1
.L80040878:
/* 1BC78 80040878 0C03A752 */  jal       is_ability_active
/* 1BC7C 8004087C 2404002A */   addiu    $a0, $zero, 0x2a
/* 1BC80 80040880 5040001C */  beql      $v0, $zero, .L800408F4
/* 1BC84 80040884 A2700004 */   sb       $s0, 4($s3)
/* 1BC88 80040888 8E220018 */  lw        $v0, 0x18($s1)
/* 1BC8C 8004088C 3C038011 */  lui       $v1, %hi(gPlayerData+0x9)
/* 1BC90 80040890 8063F299 */  lb        $v1, %lo(gPlayerData+0x9)($v1)
/* 1BC94 80040894 84420028 */  lh        $v0, 0x28($v0)
/* 1BC98 80040898 0062182A */  slt       $v1, $v1, $v0
/* 1BC9C 8004089C 54600015 */  bnel      $v1, $zero, .L800408F4
/* 1BCA0 800408A0 A2700004 */   sb       $s0, 4($s3)
/* 1BCA4 800408A4 8E220000 */  lw        $v0, ($s1)
/* 1BCA8 800408A8 30420040 */  andi      $v0, $v0, 0x40
/* 1BCAC 800408AC 54400011 */  bnel      $v0, $zero, .L800408F4
/* 1BCB0 800408B0 A2700004 */   sb       $s0, 4($s3)
/* 1BCB4 800408B4 82620012 */  lb        $v0, 0x12($s3)
/* 1BCB8 800408B8 50400001 */  beql      $v0, $zero, .L800408C0
/* 1BCBC 800408BC 0000802D */   daddu    $s0, $zero, $zero
.L800408C0:
/* 1BCC0 800408C0 0801023D */  j         .L800408F4
/* 1BCC4 800408C4 A2700004 */   sb       $s0, 4($s3)
.L800408C8:
/* 1BCC8 800408C8 8EC20000 */  lw        $v0, ($s6)
/* 1BCCC 800408CC 26B50001 */  addiu     $s5, $s5, 1
/* 1BCD0 800408D0 02A2102A */  slt       $v0, $s5, $v0
/* 1BCD4 800408D4 1440FC79 */  bnez      $v0, .L8003FABC
/* 1BCD8 800408D8 00151080 */   sll      $v0, $s5, 2
/* 1BCDC 800408DC 8FA8004C */  lw        $t0, 0x4c($sp)
.L800408E0:
/* 1BCE0 800408E0 8262001C */  lb        $v0, 0x1c($s3)
/* 1BCE4 800408E4 25080001 */  addiu     $t0, $t0, 1
/* 1BCE8 800408E8 0102102A */  slt       $v0, $t0, $v0
/* 1BCEC 800408EC 1440FC67 */  bnez      $v0, .L8003FA8C
/* 1BCF0 800408F0 AFA8004C */   sw       $t0, 0x4c($sp)
.L800408F4:
/* 1BCF4 800408F4 82630005 */  lb        $v1, 5($s3)
.L800408F8:
/* 1BCF8 800408F8 2C620007 */  sltiu     $v0, $v1, 7
/* 1BCFC 800408FC 10400285 */  beqz      $v0, L80041314_1C714
/* 1BD00 80040900 00031080 */   sll      $v0, $v1, 2
/* 1BD04 80040904 3C01800A */  lui       $at, %hi(jtbl_80098678)
/* 1BD08 80040908 00220821 */  addu      $at, $at, $v0
/* 1BD0C 8004090C 8C228678 */  lw        $v0, %lo(jtbl_80098678)($at)
/* 1BD10 80040910 00400008 */  jr        $v0
/* 1BD14 80040914 00000000 */   nop
dlabel L80040918_1BD18
/* 1BD18 80040918 8E71008C */  lw        $s1, 0x8c($s3)
/* 1BD1C 8004091C 8E22003C */  lw        $v0, 0x3c($s1)
/* 1BD20 80040920 10400004 */  beqz      $v0, .L80040934
/* 1BD24 80040924 0220B82D */   daddu    $s7, $s1, $zero
/* 1BD28 80040928 8E240054 */  lw        $a0, 0x54($s1)
/* 1BD2C 8004092C 0C0B1108 */  jal       suspend_all_script
/* 1BD30 80040930 00000000 */   nop
.L80040934:
/* 1BD34 80040934 8E220044 */  lw        $v0, 0x44($s1)
/* 1BD38 80040938 10400003 */  beqz      $v0, .L80040948
/* 1BD3C 8004093C 00000000 */   nop
/* 1BD40 80040940 0C0B1108 */  jal       suspend_all_script
/* 1BD44 80040944 8E24005C */   lw       $a0, 0x5c($s1)
.L80040948:
/* 1BD48 80040948 8E760088 */  lw        $s6, 0x88($s3)
/* 1BD4C 8004094C 8EC20000 */  lw        $v0, ($s6)
/* 1BD50 80040950 1840002B */  blez      $v0, .L80040A00
/* 1BD54 80040954 0000A82D */   daddu    $s5, $zero, $zero
/* 1BD58 80040958 24120001 */  addiu     $s2, $zero, 1
/* 1BD5C 8004095C 02C0802D */  daddu     $s0, $s6, $zero
.L80040960:
/* 1BD60 80040960 8E110004 */  lw        $s1, 4($s0)
/* 1BD64 80040964 12200021 */  beqz      $s1, .L800409EC
/* 1BD68 80040968 00000000 */   nop
/* 1BD6C 8004096C 8E230000 */  lw        $v1, ($s1)
/* 1BD70 80040970 30620008 */  andi      $v0, $v1, 8
/* 1BD74 80040974 10400004 */  beqz      $v0, .L80040988
/* 1BD78 80040978 30620020 */   andi     $v0, $v1, 0x20
/* 1BD7C 8004097C 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BD80 80040980 1622001A */  bne       $s1, $v0, .L800409EC
/* 1BD84 80040984 30620020 */   andi     $v0, $v1, 0x20
.L80040988:
/* 1BD88 80040988 14400018 */  bnez      $v0, .L800409EC
/* 1BD8C 8004098C 00000000 */   nop
/* 1BD90 80040990 8EE20000 */  lw        $v0, ($s7)
/* 1BD94 80040994 30420040 */  andi      $v0, $v0, 0x40
/* 1BD98 80040998 10400004 */  beqz      $v0, .L800409AC
/* 1BD9C 8004099C 00000000 */   nop
/* 1BDA0 800409A0 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BDA4 800409A4 16220011 */  bne       $s1, $v0, .L800409EC
/* 1BDA8 800409A8 00000000 */   nop
.L800409AC:
/* 1BDAC 800409AC 8E220028 */  lw        $v0, 0x28($s1)
/* 1BDB0 800409B0 1040000E */  beqz      $v0, .L800409EC
/* 1BDB4 800409B4 2405000A */   addiu    $a1, $zero, 0xa
/* 1BDB8 800409B8 0040202D */  daddu     $a0, $v0, $zero
/* 1BDBC 800409BC 0000302D */  daddu     $a2, $zero, $zero
/* 1BDC0 800409C0 0C0B0CF8 */  jal       start_script
/* 1BDC4 800409C4 A2320005 */   sb       $s2, 5($s1)
/* 1BDC8 800409C8 0040202D */  daddu     $a0, $v0, $zero
/* 1BDCC 800409CC AE240040 */  sw        $a0, 0x40($s1)
/* 1BDD0 800409D0 8C820144 */  lw        $v0, 0x144($a0)
/* 1BDD4 800409D4 AE220058 */  sw        $v0, 0x58($s1)
/* 1BDD8 800409D8 AC910148 */  sw        $s1, 0x148($a0)
/* 1BDDC 800409DC 86220008 */  lh        $v0, 8($s1)
/* 1BDE0 800409E0 AC82014C */  sw        $v0, 0x14c($a0)
/* 1BDE4 800409E4 92220006 */  lbu       $v0, 6($s1)
/* 1BDE8 800409E8 A0820004 */  sb        $v0, 4($a0)
.L800409EC:
/* 1BDEC 800409EC 8EC20000 */  lw        $v0, ($s6)
/* 1BDF0 800409F0 26B50001 */  addiu     $s5, $s5, 1
/* 1BDF4 800409F4 02A2102A */  slt       $v0, $s5, $v0
/* 1BDF8 800409F8 1440FFD9 */  bnez      $v0, .L80040960
/* 1BDFC 800409FC 26100004 */   addiu    $s0, $s0, 4
.L80040A00:
/* 1BE00 80040A00 0C03805E */  jal       disable_player_input
/* 1BE04 80040A04 00000000 */   nop
/* 1BE08 80040A08 0C03BD8A */  jal       partner_disable_input
/* 1BE0C 80040A0C 00000000 */   nop
/* 1BE10 80040A10 928300B4 */  lbu       $v1, 0xb4($s4)
/* 1BE14 80040A14 2462FFF1 */  addiu     $v0, $v1, -0xf
/* 1BE18 80040A18 2C420002 */  sltiu     $v0, $v0, 2
/* 1BE1C 80040A1C 1440000A */  bnez      $v0, .L80040A48
/* 1BE20 80040A20 00031600 */   sll      $v0, $v1, 0x18
/* 1BE24 80040A24 00021E03 */  sra       $v1, $v0, 0x18
/* 1BE28 80040A28 2402000D */  addiu     $v0, $zero, 0xd
/* 1BE2C 80040A2C 10620006 */  beq       $v1, $v0, .L80040A48
/* 1BE30 80040A30 2402000E */   addiu    $v0, $zero, 0xe
/* 1BE34 80040A34 10620004 */  beq       $v1, $v0, .L80040A48
/* 1BE38 80040A38 3C030004 */   lui      $v1, 4
/* 1BE3C 80040A3C 8E820000 */  lw        $v0, ($s4)
/* 1BE40 80040A40 00431025 */  or        $v0, $v0, $v1
/* 1BE44 80040A44 AE820000 */  sw        $v0, ($s4)
.L80040A48:
/* 1BE48 80040A48 0C03A752 */  jal       is_ability_active
/* 1BE4C 80040A4C 24040011 */   addiu    $a0, $zero, 0x11
/* 1BE50 80040A50 14400013 */  bnez      $v0, .L80040AA0
/* 1BE54 80040A54 24020003 */   addiu    $v0, $zero, 3
/* 1BE58 80040A58 82630004 */  lb        $v1, 4($s3)
/* 1BE5C 80040A5C 24020002 */  addiu     $v0, $zero, 2
/* 1BE60 80040A60 1462000F */  bne       $v1, $v0, .L80040AA0
/* 1BE64 80040A64 24020003 */   addiu    $v0, $zero, 3
/* 1BE68 80040A68 0C039769 */  jal       set_action_state
/* 1BE6C 80040A6C 2404001B */   addiu    $a0, $zero, 0x1b
/* 1BE70 80040A70 86240008 */  lh        $a0, 8($s1)
/* 1BE74 80040A74 0C00EABB */  jal       get_npc_unsafe
/* 1BE78 80040A78 00000000 */   nop
/* 1BE7C 80040A7C 0040902D */  daddu     $s2, $v0, $zero
/* 1BE80 80040A80 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1BE84 80040A84 240400E1 */  addiu     $a0, $zero, 0xe1
/* 1BE88 80040A88 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1BE8C 80040A8C 8E460038 */  lw        $a2, 0x38($s2)
/* 1BE90 80040A90 8E47003C */  lw        $a3, 0x3c($s2)
/* 1BE94 80040A94 0C052757 */  jal       sfx_play_sound_at_position
/* 1BE98 80040A98 0000282D */   daddu    $a1, $zero, $zero
/* 1BE9C 80040A9C 24020003 */  addiu     $v0, $zero, 3
.L80040AA0:
/* 1BEA0 80040AA0 A2600012 */  sb        $zero, 0x12($s3)
/* 1BEA4 80040AA4 3C01800A */  lui       $at, %hi(gGameState)
/* 1BEA8 80040AA8 AC22A600 */  sw        $v0, %lo(gGameState)($at)
/* 1BEAC 80040AAC 24020001 */  addiu     $v0, $zero, 1
/* 1BEB0 80040AB0 AE600090 */  sw        $zero, 0x90($s3)
/* 1BEB4 80040AB4 080104C1 */  j         .L80041304
/* 1BEB8 80040AB8 AE600094 */   sw       $zero, 0x94($s3)
dlabel L80040ABC_1BEBC
/* 1BEBC 80040ABC 8E71008C */  lw        $s1, 0x8c($s3)
/* 1BEC0 80040AC0 8E22003C */  lw        $v0, 0x3c($s1)
/* 1BEC4 80040AC4 10400004 */  beqz      $v0, .L80040AD8
/* 1BEC8 80040AC8 0220B82D */   daddu    $s7, $s1, $zero
/* 1BECC 80040ACC 8E240054 */  lw        $a0, 0x54($s1)
/* 1BED0 80040AD0 0C0B1108 */  jal       suspend_all_script
/* 1BED4 80040AD4 00000000 */   nop
.L80040AD8:
/* 1BED8 80040AD8 8E220044 */  lw        $v0, 0x44($s1)
/* 1BEDC 80040ADC 10400003 */  beqz      $v0, .L80040AEC
/* 1BEE0 80040AE0 00000000 */   nop
/* 1BEE4 80040AE4 0C0B1108 */  jal       suspend_all_script
/* 1BEE8 80040AE8 8E24005C */   lw       $a0, 0x5c($s1)
.L80040AEC:
/* 1BEEC 80040AEC 8E760088 */  lw        $s6, 0x88($s3)
/* 1BEF0 80040AF0 8EC20000 */  lw        $v0, ($s6)
/* 1BEF4 80040AF4 1840002B */  blez      $v0, .L80040BA4
/* 1BEF8 80040AF8 0000A82D */   daddu    $s5, $zero, $zero
/* 1BEFC 80040AFC 24120003 */  addiu     $s2, $zero, 3
/* 1BF00 80040B00 02C0802D */  daddu     $s0, $s6, $zero
.L80040B04:
/* 1BF04 80040B04 8E110004 */  lw        $s1, 4($s0)
/* 1BF08 80040B08 12200021 */  beqz      $s1, .L80040B90
/* 1BF0C 80040B0C 00000000 */   nop
/* 1BF10 80040B10 8E230000 */  lw        $v1, ($s1)
/* 1BF14 80040B14 30620008 */  andi      $v0, $v1, 8
/* 1BF18 80040B18 10400004 */  beqz      $v0, .L80040B2C
/* 1BF1C 80040B1C 30620020 */   andi     $v0, $v1, 0x20
/* 1BF20 80040B20 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BF24 80040B24 1622001A */  bne       $s1, $v0, .L80040B90
/* 1BF28 80040B28 30620020 */   andi     $v0, $v1, 0x20
.L80040B2C:
/* 1BF2C 80040B2C 14400018 */  bnez      $v0, .L80040B90
/* 1BF30 80040B30 00000000 */   nop
/* 1BF34 80040B34 8EE20000 */  lw        $v0, ($s7)
/* 1BF38 80040B38 30420040 */  andi      $v0, $v0, 0x40
/* 1BF3C 80040B3C 10400004 */  beqz      $v0, .L80040B50
/* 1BF40 80040B40 00000000 */   nop
/* 1BF44 80040B44 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BF48 80040B48 16220011 */  bne       $s1, $v0, .L80040B90
/* 1BF4C 80040B4C 00000000 */   nop
.L80040B50:
/* 1BF50 80040B50 8E220028 */  lw        $v0, 0x28($s1)
/* 1BF54 80040B54 1040000E */  beqz      $v0, .L80040B90
/* 1BF58 80040B58 2405000A */   addiu    $a1, $zero, 0xa
/* 1BF5C 80040B5C 0040202D */  daddu     $a0, $v0, $zero
/* 1BF60 80040B60 0000302D */  daddu     $a2, $zero, $zero
/* 1BF64 80040B64 0C0B0CF8 */  jal       start_script
/* 1BF68 80040B68 A2320005 */   sb       $s2, 5($s1)
/* 1BF6C 80040B6C 0040202D */  daddu     $a0, $v0, $zero
/* 1BF70 80040B70 AE240040 */  sw        $a0, 0x40($s1)
/* 1BF74 80040B74 8C820144 */  lw        $v0, 0x144($a0)
/* 1BF78 80040B78 AE220058 */  sw        $v0, 0x58($s1)
/* 1BF7C 80040B7C AC910148 */  sw        $s1, 0x148($a0)
/* 1BF80 80040B80 86220008 */  lh        $v0, 8($s1)
/* 1BF84 80040B84 AC82014C */  sw        $v0, 0x14c($a0)
/* 1BF88 80040B88 92220006 */  lbu       $v0, 6($s1)
/* 1BF8C 80040B8C A0820004 */  sb        $v0, 4($a0)
.L80040B90:
/* 1BF90 80040B90 8EC20000 */  lw        $v0, ($s6)
/* 1BF94 80040B94 26B50001 */  addiu     $s5, $s5, 1
/* 1BF98 80040B98 02A2102A */  slt       $v0, $s5, $v0
/* 1BF9C 80040B9C 1440FFD9 */  bnez      $v0, .L80040B04
/* 1BFA0 80040BA0 26100004 */   addiu    $s0, $s0, 4
.L80040BA4:
/* 1BFA4 80040BA4 0C03805E */  jal       disable_player_input
/* 1BFA8 80040BA8 00000000 */   nop
/* 1BFAC 80040BAC 0C03BD8A */  jal       partner_disable_input
/* 1BFB0 80040BB0 00000000 */   nop
/* 1BFB4 80040BB4 24020003 */  addiu     $v0, $zero, 3
/* 1BFB8 80040BB8 A2600012 */  sb        $zero, 0x12($s3)
/* 1BFBC 80040BBC 3C01800A */  lui       $at, %hi(gGameState)
/* 1BFC0 80040BC0 AC22A600 */  sw        $v0, %lo(gGameState)($at)
/* 1BFC4 80040BC4 24020001 */  addiu     $v0, $zero, 1
/* 1BFC8 80040BC8 AE600090 */  sw        $zero, 0x90($s3)
/* 1BFCC 80040BCC AE600094 */  sw        $zero, 0x94($s3)
/* 1BFD0 80040BD0 3C01800A */  lui       $at, %hi(D_8009A678)
/* 1BFD4 80040BD4 AC22A678 */  sw        $v0, %lo(D_8009A678)($at)
/* 1BFD8 80040BD8 8E820000 */  lw        $v0, ($s4)
/* 1BFDC 80040BDC 3C030004 */  lui       $v1, 4
/* 1BFE0 80040BE0 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1BFE4 80040BE4 AC20A5D0 */  sw        $zero, %lo(D_8009A5D0)($at)
/* 1BFE8 80040BE8 00431025 */  or        $v0, $v0, $v1
/* 1BFEC 80040BEC 080104C5 */  j         L80041314_1C714
/* 1BFF0 80040BF0 AE820000 */   sw       $v0, ($s4)
dlabel L80040BF4_1BFF4
/* 1BFF4 80040BF4 8E71008C */  lw        $s1, 0x8c($s3)
/* 1BFF8 80040BF8 8E22003C */  lw        $v0, 0x3c($s1)
/* 1BFFC 80040BFC 10400004 */  beqz      $v0, .L80040C10
/* 1C000 80040C00 0220B82D */   daddu    $s7, $s1, $zero
/* 1C004 80040C04 8E240054 */  lw        $a0, 0x54($s1)
/* 1C008 80040C08 0C0B1108 */  jal       suspend_all_script
/* 1C00C 80040C0C 00000000 */   nop
.L80040C10:
/* 1C010 80040C10 8E220044 */  lw        $v0, 0x44($s1)
/* 1C014 80040C14 10400003 */  beqz      $v0, .L80040C24
/* 1C018 80040C18 00000000 */   nop
/* 1C01C 80040C1C 0C0B1108 */  jal       suspend_all_script
/* 1C020 80040C20 8E24005C */   lw       $a0, 0x5c($s1)
.L80040C24:
/* 1C024 80040C24 8E760088 */  lw        $s6, 0x88($s3)
/* 1C028 80040C28 0000802D */  daddu     $s0, $zero, $zero
/* 1C02C 80040C2C 8EC20000 */  lw        $v0, ($s6)
/* 1C030 80040C30 18400070 */  blez      $v0, .L80040DF4
/* 1C034 80040C34 0200A82D */   daddu    $s5, $s0, $zero
/* 1C038 80040C38 241E0003 */  addiu     $fp, $zero, 3
/* 1C03C 80040C3C 3C013F00 */  lui       $at, 0x3f00
/* 1C040 80040C40 4481A000 */  mtc1      $at, $f20
/* 1C044 80040C44 3C01BF80 */  lui       $at, 0xbf80
/* 1C048 80040C48 4481B000 */  mtc1      $at, $f22
/* 1C04C 80040C4C 00151080 */  sll       $v0, $s5, 2
.L80040C50:
/* 1C050 80040C50 02C21021 */  addu      $v0, $s6, $v0
/* 1C054 80040C54 8C510004 */  lw        $s1, 4($v0)
/* 1C058 80040C58 12200061 */  beqz      $s1, .L80040DE0
/* 1C05C 80040C5C 00000000 */   nop
/* 1C060 80040C60 8E230000 */  lw        $v1, ($s1)
/* 1C064 80040C64 30620008 */  andi      $v0, $v1, 8
/* 1C068 80040C68 10400004 */  beqz      $v0, .L80040C7C
/* 1C06C 80040C6C 30620020 */   andi     $v0, $v1, 0x20
/* 1C070 80040C70 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C074 80040C74 1622005A */  bne       $s1, $v0, .L80040DE0
/* 1C078 80040C78 30620020 */   andi     $v0, $v1, 0x20
.L80040C7C:
/* 1C07C 80040C7C 14400058 */  bnez      $v0, .L80040DE0
/* 1C080 80040C80 00000000 */   nop
/* 1C084 80040C84 8EE20000 */  lw        $v0, ($s7)
/* 1C088 80040C88 30420040 */  andi      $v0, $v0, 0x40
/* 1C08C 80040C8C 10400004 */  beqz      $v0, .L80040CA0
/* 1C090 80040C90 00000000 */   nop
/* 1C094 80040C94 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C098 80040C98 16220051 */  bne       $s1, $v0, .L80040DE0
/* 1C09C 80040C9C 00000000 */   nop
.L80040CA0:
/* 1C0A0 80040CA0 8E220028 */  lw        $v0, 0x28($s1)
/* 1C0A4 80040CA4 1040001F */  beqz      $v0, .L80040D24
/* 1C0A8 80040CA8 2405000A */   addiu    $a1, $zero, 0xa
/* 1C0AC 80040CAC 0000302D */  daddu     $a2, $zero, $zero
/* 1C0B0 80040CB0 0040202D */  daddu     $a0, $v0, $zero
/* 1C0B4 80040CB4 24020002 */  addiu     $v0, $zero, 2
/* 1C0B8 80040CB8 0C0B0CF8 */  jal       start_script
/* 1C0BC 80040CBC A2220005 */   sb       $v0, 5($s1)
/* 1C0C0 80040CC0 0040202D */  daddu     $a0, $v0, $zero
/* 1C0C4 80040CC4 AE240040 */  sw        $a0, 0x40($s1)
/* 1C0C8 80040CC8 8C820144 */  lw        $v0, 0x144($a0)
/* 1C0CC 80040CCC AE220058 */  sw        $v0, 0x58($s1)
/* 1C0D0 80040CD0 AC910148 */  sw        $s1, 0x148($a0)
/* 1C0D4 80040CD4 86220008 */  lh        $v0, 8($s1)
/* 1C0D8 80040CD8 AC82014C */  sw        $v0, 0x14c($a0)
/* 1C0DC 80040CDC 92220006 */  lbu       $v0, 6($s1)
/* 1C0E0 80040CE0 A0820004 */  sb        $v0, 4($a0)
/* 1C0E4 80040CE4 0C00EABB */  jal       get_npc_unsafe
/* 1C0E8 80040CE8 86240008 */   lh       $a0, 8($s1)
/* 1C0EC 80040CEC 0040902D */  daddu     $s2, $v0, $zero
/* 1C0F0 80040CF0 C6460038 */  lwc1      $f6, 0x38($s2)
/* 1C0F4 80040CF4 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1C0F8 80040CF8 460A3181 */  sub.s     $f6, $f6, $f10
/* 1C0FC 80040CFC 46143182 */  mul.s     $f6, $f6, $f20
/* 1C100 80040D00 00000000 */  nop
/* 1C104 80040D04 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C108 80040D08 C642003C */  lwc1      $f2, 0x3c($s2)
/* 1C10C 80040D0C 44820000 */  mtc1      $v0, $f0
/* 1C110 80040D10 00000000 */  nop
/* 1C114 80040D14 46800020 */  cvt.s.w   $f0, $f0
/* 1C118 80040D18 868200B0 */  lh        $v0, 0xb0($s4)
/* 1C11C 80040D1C 0801035B */  j         .L80040D6C
/* 1C120 80040D20 46001080 */   add.s    $f2, $f2, $f0
.L80040D24:
/* 1C124 80040D24 30620001 */  andi      $v0, $v1, 1
/* 1C128 80040D28 1440002D */  bnez      $v0, .L80040DE0
/* 1C12C 80040D2C 00000000 */   nop
/* 1C130 80040D30 0C00EABB */  jal       get_npc_unsafe
/* 1C134 80040D34 86240008 */   lh       $a0, 8($s1)
/* 1C138 80040D38 0040902D */  daddu     $s2, $v0, $zero
/* 1C13C 80040D3C C4460038 */  lwc1      $f6, 0x38($v0)
/* 1C140 80040D40 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1C144 80040D44 460A3181 */  sub.s     $f6, $f6, $f10
/* 1C148 80040D48 46143182 */  mul.s     $f6, $f6, $f20
/* 1C14C 80040D4C 00000000 */  nop
/* 1C150 80040D50 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C154 80040D54 C642003C */  lwc1      $f2, 0x3c($s2)
/* 1C158 80040D58 44820000 */  mtc1      $v0, $f0
/* 1C15C 80040D5C 00000000 */  nop
/* 1C160 80040D60 46800020 */  cvt.s.w   $f0, $f0
/* 1C164 80040D64 868200B0 */  lh        $v0, 0xb0($s4)
/* 1C168 80040D68 46001080 */  add.s     $f2, $f2, $f0
.L80040D6C:
/* 1C16C 80040D6C C688002C */  lwc1      $f8, 0x2c($s4)
/* 1C170 80040D70 44820000 */  mtc1      $v0, $f0
/* 1C174 80040D74 00000000 */  nop
/* 1C178 80040D78 46800020 */  cvt.s.w   $f0, $f0
/* 1C17C 80040D7C 46004000 */  add.s     $f0, $f8, $f0
/* 1C180 80040D80 46001081 */  sub.s     $f2, $f2, $f0
/* 1C184 80040D84 46141082 */  mul.s     $f2, $f2, $f20
/* 1C188 80040D88 00000000 */  nop
/* 1C18C 80040D8C C6840030 */  lwc1      $f4, 0x30($s4)
/* 1C190 80040D90 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1C194 80040D94 46040001 */  sub.s     $f0, $f0, $f4
/* 1C198 80040D98 46140002 */  mul.s     $f0, $f0, $f20
/* 1C19C 80040D9C 00000000 */  nop
/* 1C1A0 80040DA0 46065280 */  add.s     $f10, $f10, $f6
/* 1C1A4 80040DA4 46024200 */  add.s     $f8, $f8, $f2
/* 1C1A8 80040DA8 24100001 */  addiu     $s0, $zero, 1
/* 1C1AC 80040DAC 46002100 */  add.s     $f4, $f4, $f0
/* 1C1B0 80040DB0 44055000 */  mfc1      $a1, $f10
/* 1C1B4 80040DB4 44064000 */  mfc1      $a2, $f8
/* 1C1B8 80040DB8 44072000 */  mfc1      $a3, $f4
/* 1C1BC 80040DBC 24040003 */  addiu     $a0, $zero, 3
/* 1C1C0 80040DC0 AFA5003C */  sw        $a1, 0x3c($sp)
/* 1C1C4 80040DC4 AFA60040 */  sw        $a2, 0x40($sp)
/* 1C1C8 80040DC8 AFA70044 */  sw        $a3, 0x44($sp)
/* 1C1CC 80040DCC AFA00010 */  sw        $zero, 0x10($sp)
/* 1C1D0 80040DD0 E7B60014 */  swc1      $f22, 0x14($sp)
/* 1C1D4 80040DD4 AFA00018 */  sw        $zero, 0x18($sp)
/* 1C1D8 80040DD8 0C01C064 */  jal       playFX_18
/* 1C1DC 80040DDC AFBE001C */   sw       $fp, 0x1c($sp)
.L80040DE0:
/* 1C1E0 80040DE0 8EC20000 */  lw        $v0, ($s6)
/* 1C1E4 80040DE4 26B50001 */  addiu     $s5, $s5, 1
/* 1C1E8 80040DE8 02A2102A */  slt       $v0, $s5, $v0
/* 1C1EC 80040DEC 1440FF98 */  bnez      $v0, .L80040C50
/* 1C1F0 80040DF0 00151080 */   sll      $v0, $s5, 2
.L80040DF4:
/* 1C1F4 80040DF4 0C03805E */  jal       disable_player_input
/* 1C1F8 80040DF8 00000000 */   nop
/* 1C1FC 80040DFC 0C03BD8A */  jal       partner_disable_input
/* 1C200 80040E00 00000000 */   nop
/* 1C204 80040E04 8E820000 */  lw        $v0, ($s4)
/* 1C208 80040E08 3C030004 */  lui       $v1, 4
/* 1C20C 80040E0C 00431025 */  or        $v0, $v0, $v1
/* 1C210 80040E10 12000003 */  beqz      $s0, .L80040E20
/* 1C214 80040E14 AE820000 */   sw       $v0, ($s4)
/* 1C218 80040E18 0C03980D */  jal       start_bounce_a
/* 1C21C 80040E1C 00000000 */   nop
.L80040E20:
/* 1C220 80040E20 0000202D */  daddu     $a0, $zero, $zero
/* 1C224 80040E24 AE600090 */  sw        $zero, 0x90($s3)
/* 1C228 80040E28 AE600094 */  sw        $zero, 0x94($s3)
/* 1C22C 80040E2C 080104BB */  j         .L800412EC
/* 1C230 80040E30 A2600012 */   sb       $zero, 0x12($s3)
dlabel L80040E34_1C234
/* 1C234 80040E34 8E71008C */  lw        $s1, 0x8c($s3)
/* 1C238 80040E38 8E22003C */  lw        $v0, 0x3c($s1)
/* 1C23C 80040E3C 10400004 */  beqz      $v0, .L80040E50
/* 1C240 80040E40 0220B82D */   daddu    $s7, $s1, $zero
/* 1C244 80040E44 8E240054 */  lw        $a0, 0x54($s1)
/* 1C248 80040E48 0C0B1108 */  jal       suspend_all_script
/* 1C24C 80040E4C 00000000 */   nop
.L80040E50:
/* 1C250 80040E50 8E220044 */  lw        $v0, 0x44($s1)
/* 1C254 80040E54 10400003 */  beqz      $v0, .L80040E64
/* 1C258 80040E58 00000000 */   nop
/* 1C25C 80040E5C 0C0B1108 */  jal       suspend_all_script
/* 1C260 80040E60 8E24005C */   lw       $a0, 0x5c($s1)
.L80040E64:
/* 1C264 80040E64 8E760088 */  lw        $s6, 0x88($s3)
/* 1C268 80040E68 8EC20000 */  lw        $v0, ($s6)
/* 1C26C 80040E6C 18400113 */  blez      $v0, .L800412BC
/* 1C270 80040E70 0000A82D */   daddu    $s5, $zero, $zero
/* 1C274 80040E74 24100003 */  addiu     $s0, $zero, 3
/* 1C278 80040E78 3C013F00 */  lui       $at, 0x3f00
/* 1C27C 80040E7C 4481A000 */  mtc1      $at, $f20
/* 1C280 80040E80 3C01BF80 */  lui       $at, 0xbf80
/* 1C284 80040E84 4481B000 */  mtc1      $at, $f22
/* 1C288 80040E88 00151080 */  sll       $v0, $s5, 2
.L80040E8C:
/* 1C28C 80040E8C 02C21021 */  addu      $v0, $s6, $v0
/* 1C290 80040E90 8C510004 */  lw        $s1, 4($v0)
/* 1C294 80040E94 12200082 */  beqz      $s1, .L800410A0
/* 1C298 80040E98 00000000 */   nop
/* 1C29C 80040E9C 8E230000 */  lw        $v1, ($s1)
/* 1C2A0 80040EA0 30620008 */  andi      $v0, $v1, 8
/* 1C2A4 80040EA4 10400004 */  beqz      $v0, .L80040EB8
/* 1C2A8 80040EA8 30620020 */   andi     $v0, $v1, 0x20
/* 1C2AC 80040EAC 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C2B0 80040EB0 1622007B */  bne       $s1, $v0, .L800410A0
/* 1C2B4 80040EB4 30620020 */   andi     $v0, $v1, 0x20
.L80040EB8:
/* 1C2B8 80040EB8 14400079 */  bnez      $v0, .L800410A0
/* 1C2BC 80040EBC 00000000 */   nop
/* 1C2C0 80040EC0 8EE20000 */  lw        $v0, ($s7)
/* 1C2C4 80040EC4 30420040 */  andi      $v0, $v0, 0x40
/* 1C2C8 80040EC8 10400004 */  beqz      $v0, .L80040EDC
/* 1C2CC 80040ECC 00000000 */   nop
/* 1C2D0 80040ED0 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C2D4 80040ED4 16220072 */  bne       $s1, $v0, .L800410A0
/* 1C2D8 80040ED8 00000000 */   nop
.L80040EDC:
/* 1C2DC 80040EDC 8E220028 */  lw        $v0, 0x28($s1)
/* 1C2E0 80040EE0 1040003A */  beqz      $v0, .L80040FCC
/* 1C2E4 80040EE4 2405000A */   addiu    $a1, $zero, 0xa
/* 1C2E8 80040EE8 0000302D */  daddu     $a2, $zero, $zero
/* 1C2EC 80040EEC 0040202D */  daddu     $a0, $v0, $zero
/* 1C2F0 80040EF0 24020004 */  addiu     $v0, $zero, 4
/* 1C2F4 80040EF4 0C0B0CF8 */  jal       start_script
/* 1C2F8 80040EF8 A2220005 */   sb       $v0, 5($s1)
/* 1C2FC 80040EFC 0040202D */  daddu     $a0, $v0, $zero
/* 1C300 80040F00 AE240040 */  sw        $a0, 0x40($s1)
/* 1C304 80040F04 8C820144 */  lw        $v0, 0x144($a0)
/* 1C308 80040F08 AE220058 */  sw        $v0, 0x58($s1)
/* 1C30C 80040F0C AC910148 */  sw        $s1, 0x148($a0)
/* 1C310 80040F10 86220008 */  lh        $v0, 8($s1)
/* 1C314 80040F14 AC82014C */  sw        $v0, 0x14c($a0)
/* 1C318 80040F18 92220006 */  lbu       $v0, 6($s1)
/* 1C31C 80040F1C A0820004 */  sb        $v0, 4($a0)
/* 1C320 80040F20 0C00EABB */  jal       get_npc_unsafe
/* 1C324 80040F24 86240008 */   lh       $a0, 8($s1)
/* 1C328 80040F28 0040902D */  daddu     $s2, $v0, $zero
/* 1C32C 80040F2C C6480038 */  lwc1      $f8, 0x38($s2)
/* 1C330 80040F30 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1C334 80040F34 460A4201 */  sub.s     $f8, $f8, $f10
/* 1C338 80040F38 46144202 */  mul.s     $f8, $f8, $f20
/* 1C33C 80040F3C 00000000 */  nop
/* 1C340 80040F40 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C344 80040F44 C644003C */  lwc1      $f4, 0x3c($s2)
/* 1C348 80040F48 44820000 */  mtc1      $v0, $f0
/* 1C34C 80040F4C 00000000 */  nop
/* 1C350 80040F50 46800020 */  cvt.s.w   $f0, $f0
/* 1C354 80040F54 46002100 */  add.s     $f4, $f4, $f0
/* 1C358 80040F58 868200B0 */  lh        $v0, 0xb0($s4)
/* 1C35C 80040F5C C686002C */  lwc1      $f6, 0x2c($s4)
/* 1C360 80040F60 44820000 */  mtc1      $v0, $f0
/* 1C364 80040F64 00000000 */  nop
/* 1C368 80040F68 46800020 */  cvt.s.w   $f0, $f0
/* 1C36C 80040F6C 46003000 */  add.s     $f0, $f6, $f0
/* 1C370 80040F70 46002101 */  sub.s     $f4, $f4, $f0
/* 1C374 80040F74 46142102 */  mul.s     $f4, $f4, $f20
/* 1C378 80040F78 00000000 */  nop
/* 1C37C 80040F7C C6820030 */  lwc1      $f2, 0x30($s4)
/* 1C380 80040F80 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1C384 80040F84 46020001 */  sub.s     $f0, $f0, $f2
/* 1C388 80040F88 46140002 */  mul.s     $f0, $f0, $f20
/* 1C38C 80040F8C 00000000 */  nop
/* 1C390 80040F90 46085280 */  add.s     $f10, $f10, $f8
/* 1C394 80040F94 46043180 */  add.s     $f6, $f6, $f4
/* 1C398 80040F98 46001080 */  add.s     $f2, $f2, $f0
/* 1C39C 80040F9C 44055000 */  mfc1      $a1, $f10
/* 1C3A0 80040FA0 44063000 */  mfc1      $a2, $f6
/* 1C3A4 80040FA4 44071000 */  mfc1      $a3, $f2
/* 1C3A8 80040FA8 24040003 */  addiu     $a0, $zero, 3
/* 1C3AC 80040FAC AFA5003C */  sw        $a1, 0x3c($sp)
/* 1C3B0 80040FB0 AFA60040 */  sw        $a2, 0x40($sp)
/* 1C3B4 80040FB4 AFA70044 */  sw        $a3, 0x44($sp)
/* 1C3B8 80040FB8 AFA00010 */  sw        $zero, 0x10($sp)
/* 1C3BC 80040FBC E7B60014 */  swc1      $f22, 0x14($sp)
/* 1C3C0 80040FC0 AFA00018 */  sw        $zero, 0x18($sp)
/* 1C3C4 80040FC4 08010426 */  j         .L80041098
/* 1C3C8 80040FC8 AFB0001C */   sw       $s0, 0x1c($sp)
.L80040FCC:
/* 1C3CC 80040FCC 30620001 */  andi      $v0, $v1, 1
/* 1C3D0 80040FD0 14400033 */  bnez      $v0, .L800410A0
/* 1C3D4 80040FD4 00000000 */   nop
/* 1C3D8 80040FD8 0C00EABB */  jal       get_npc_unsafe
/* 1C3DC 80040FDC 86240008 */   lh       $a0, 8($s1)
/* 1C3E0 80040FE0 0040902D */  daddu     $s2, $v0, $zero
/* 1C3E4 80040FE4 C44C0038 */  lwc1      $f12, 0x38($v0)
/* 1C3E8 80040FE8 C68E0028 */  lwc1      $f14, 0x28($s4)
/* 1C3EC 80040FEC 460E6301 */  sub.s     $f12, $f12, $f14
/* 1C3F0 80040FF0 46146302 */  mul.s     $f12, $f12, $f20
/* 1C3F4 80040FF4 00000000 */  nop
/* 1C3F8 80040FF8 C6420040 */  lwc1      $f2, 0x40($s2)
/* 1C3FC 80040FFC C6880030 */  lwc1      $f8, 0x30($s4)
/* 1C400 80041000 46081081 */  sub.s     $f2, $f2, $f8
/* 1C404 80041004 46141082 */  mul.s     $f2, $f2, $f20
/* 1C408 80041008 00000000 */  nop
/* 1C40C 8004100C 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C410 80041010 C646003C */  lwc1      $f6, 0x3c($s2)
/* 1C414 80041014 44820000 */  mtc1      $v0, $f0
/* 1C418 80041018 00000000 */  nop
/* 1C41C 8004101C 46800020 */  cvt.s.w   $f0, $f0
/* 1C420 80041020 868200B0 */  lh        $v0, 0xb0($s4)
/* 1C424 80041024 46003180 */  add.s     $f6, $f6, $f0
/* 1C428 80041028 C68A002C */  lwc1      $f10, 0x2c($s4)
/* 1C42C 8004102C 44820000 */  mtc1      $v0, $f0
/* 1C430 80041030 00000000 */  nop
/* 1C434 80041034 46800020 */  cvt.s.w   $f0, $f0
/* 1C438 80041038 46005000 */  add.s     $f0, $f10, $f0
/* 1C43C 8004103C 46003181 */  sub.s     $f6, $f6, $f0
/* 1C440 80041040 46143182 */  mul.s     $f6, $f6, $f20
/* 1C444 80041044 00000000 */  nop
/* 1C448 80041048 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C44C 8004104C C644003C */  lwc1      $f4, 0x3c($s2)
/* 1C450 80041050 44820000 */  mtc1      $v0, $f0
/* 1C454 80041054 00000000 */  nop
/* 1C458 80041058 46800020 */  cvt.s.w   $f0, $f0
/* 1C45C 8004105C 46002100 */  add.s     $f4, $f4, $f0
/* 1C460 80041060 460C7380 */  add.s     $f14, $f14, $f12
/* 1C464 80041064 46024200 */  add.s     $f8, $f8, $f2
/* 1C468 80041068 44062000 */  mfc1      $a2, $f4
/* 1C46C 8004106C 46065280 */  add.s     $f10, $f10, $f6
/* 1C470 80041070 E7AE003C */  swc1      $f14, 0x3c($sp)
/* 1C474 80041074 E7A80044 */  swc1      $f8, 0x44($sp)
/* 1C478 80041078 E7AA0040 */  swc1      $f10, 0x40($sp)
/* 1C47C 8004107C AFA00010 */  sw        $zero, 0x10($sp)
/* 1C480 80041080 E7B60014 */  swc1      $f22, 0x14($sp)
/* 1C484 80041084 AFA00018 */  sw        $zero, 0x18($sp)
/* 1C488 80041088 AFB0001C */  sw        $s0, 0x1c($sp)
/* 1C48C 8004108C 8E450038 */  lw        $a1, 0x38($s2)
/* 1C490 80041090 8E470040 */  lw        $a3, 0x40($s2)
/* 1C494 80041094 24040003 */  addiu     $a0, $zero, 3
.L80041098:
/* 1C498 80041098 0C01C064 */  jal       playFX_18
/* 1C49C 8004109C 00000000 */   nop
.L800410A0:
/* 1C4A0 800410A0 8EC20000 */  lw        $v0, ($s6)
/* 1C4A4 800410A4 26B50001 */  addiu     $s5, $s5, 1
/* 1C4A8 800410A8 02A2102A */  slt       $v0, $s5, $v0
/* 1C4AC 800410AC 1440FF77 */  bnez      $v0, .L80040E8C
/* 1C4B0 800410B0 00151080 */   sll      $v0, $s5, 2
/* 1C4B4 800410B4 080104AF */  j         .L800412BC
/* 1C4B8 800410B8 00000000 */   nop
dlabel L800410BC_1C4BC
/* 1C4BC 800410BC 0C0B117A */  jal       suspend_all_group
/* 1C4C0 800410C0 24040001 */   addiu    $a0, $zero, 1
/* 1C4C4 800410C4 8E71008C */  lw        $s1, 0x8c($s3)
/* 1C4C8 800410C8 12200007 */  beqz      $s1, .L800410E8
/* 1C4CC 800410CC 00000000 */   nop
/* 1C4D0 800410D0 8E22003C */  lw        $v0, 0x3c($s1)
/* 1C4D4 800410D4 10400004 */  beqz      $v0, .L800410E8
/* 1C4D8 800410D8 00000000 */   nop
/* 1C4DC 800410DC 0C0B1108 */  jal       suspend_all_script
/* 1C4E0 800410E0 8E240054 */   lw       $a0, 0x54($s1)
/* 1C4E4 800410E4 8E71008C */  lw        $s1, 0x8c($s3)
.L800410E8:
/* 1C4E8 800410E8 8E220020 */  lw        $v0, 0x20($s1)
/* 1C4EC 800410EC 1040000F */  beqz      $v0, .L8004112C
/* 1C4F0 800410F0 2405000A */   addiu    $a1, $zero, 0xa
/* 1C4F4 800410F4 0000302D */  daddu     $a2, $zero, $zero
/* 1C4F8 800410F8 0040202D */  daddu     $a0, $v0, $zero
/* 1C4FC 800410FC 24020005 */  addiu     $v0, $zero, 5
/* 1C500 80041100 0C0B0CF8 */  jal       start_script
/* 1C504 80041104 A2220005 */   sb       $v0, 5($s1)
/* 1C508 80041108 0040202D */  daddu     $a0, $v0, $zero
/* 1C50C 8004110C AE240038 */  sw        $a0, 0x38($s1)
/* 1C510 80041110 8C820144 */  lw        $v0, 0x144($a0)
/* 1C514 80041114 AE220050 */  sw        $v0, 0x50($s1)
/* 1C518 80041118 AC910148 */  sw        $s1, 0x148($a0)
/* 1C51C 8004111C 86220008 */  lh        $v0, 8($s1)
/* 1C520 80041120 AC82014C */  sw        $v0, 0x14c($a0)
/* 1C524 80041124 92220006 */  lbu       $v0, 6($s1)
/* 1C528 80041128 A0820004 */  sb        $v0, 4($a0)
.L8004112C:
/* 1C52C 8004112C 0C03805E */  jal       disable_player_input
/* 1C530 80041130 00000000 */   nop
/* 1C534 80041134 0C03BD8A */  jal       partner_disable_input
/* 1C538 80041138 00000000 */   nop
/* 1C53C 8004113C 0C039769 */  jal       set_action_state
/* 1C540 80041140 2404000C */   addiu    $a0, $zero, 0xc
/* 1C544 80041144 24040001 */  addiu     $a0, $zero, 1
/* 1C548 80041148 AE600090 */  sw        $zero, 0x90($s3)
/* 1C54C 8004114C 0C03BCF5 */  jal       func_800EF3D4
/* 1C550 80041150 AE600094 */   sw       $zero, 0x94($s3)
/* 1C554 80041154 080104BE */  j         .L800412F8
/* 1C558 80041158 24020004 */   addiu    $v0, $zero, 4
dlabel L8004115C_1C55C
/* 1C55C 8004115C 8E71008C */  lw        $s1, 0x8c($s3)
/* 1C560 80041160 8E22003C */  lw        $v0, 0x3c($s1)
/* 1C564 80041164 10400004 */  beqz      $v0, .L80041178
/* 1C568 80041168 0220B82D */   daddu    $s7, $s1, $zero
/* 1C56C 8004116C 8E240054 */  lw        $a0, 0x54($s1)
/* 1C570 80041170 0C0B1108 */  jal       suspend_all_script
/* 1C574 80041174 00000000 */   nop
.L80041178:
/* 1C578 80041178 8E220044 */  lw        $v0, 0x44($s1)
/* 1C57C 8004117C 10400003 */  beqz      $v0, .L8004118C
/* 1C580 80041180 00000000 */   nop
/* 1C584 80041184 0C0B1108 */  jal       suspend_all_script
/* 1C588 80041188 8E24005C */   lw       $a0, 0x5c($s1)
.L8004118C:
/* 1C58C 8004118C 8E760088 */  lw        $s6, 0x88($s3)
/* 1C590 80041190 8EC20000 */  lw        $v0, ($s6)
/* 1C594 80041194 18400049 */  blez      $v0, .L800412BC
/* 1C598 80041198 0000A82D */   daddu    $s5, $zero, $zero
/* 1C59C 8004119C 3C01BF80 */  lui       $at, 0xbf80
/* 1C5A0 800411A0 4481A000 */  mtc1      $at, $f20
/* 1C5A4 800411A4 241E0003 */  addiu     $fp, $zero, 3
/* 1C5A8 800411A8 02C0802D */  daddu     $s0, $s6, $zero
.L800411AC:
/* 1C5AC 800411AC 8E110004 */  lw        $s1, 4($s0)
/* 1C5B0 800411B0 1220003D */  beqz      $s1, .L800412A8
/* 1C5B4 800411B4 00000000 */   nop
/* 1C5B8 800411B8 8E230000 */  lw        $v1, ($s1)
/* 1C5BC 800411BC 30620008 */  andi      $v0, $v1, 8
/* 1C5C0 800411C0 10400004 */  beqz      $v0, .L800411D4
/* 1C5C4 800411C4 30620020 */   andi     $v0, $v1, 0x20
/* 1C5C8 800411C8 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C5CC 800411CC 16220036 */  bne       $s1, $v0, .L800412A8
/* 1C5D0 800411D0 30620020 */   andi     $v0, $v1, 0x20
.L800411D4:
/* 1C5D4 800411D4 14400034 */  bnez      $v0, .L800412A8
/* 1C5D8 800411D8 00000000 */   nop
/* 1C5DC 800411DC 8EE20000 */  lw        $v0, ($s7)
/* 1C5E0 800411E0 30420040 */  andi      $v0, $v0, 0x40
/* 1C5E4 800411E4 10400004 */  beqz      $v0, .L800411F8
/* 1C5E8 800411E8 00000000 */   nop
/* 1C5EC 800411EC 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C5F0 800411F0 1622002D */  bne       $s1, $v0, .L800412A8
/* 1C5F4 800411F4 00000000 */   nop
.L800411F8:
/* 1C5F8 800411F8 8E220028 */  lw        $v0, 0x28($s1)
/* 1C5FC 800411FC 10400010 */  beqz      $v0, .L80041240
/* 1C600 80041200 2405000A */   addiu    $a1, $zero, 0xa
/* 1C604 80041204 0000302D */  daddu     $a2, $zero, $zero
/* 1C608 80041208 0040202D */  daddu     $a0, $v0, $zero
/* 1C60C 8004120C 24020006 */  addiu     $v0, $zero, 6
/* 1C610 80041210 0C0B0CF8 */  jal       start_script
/* 1C614 80041214 A2220005 */   sb       $v0, 5($s1)
/* 1C618 80041218 0040202D */  daddu     $a0, $v0, $zero
/* 1C61C 8004121C AE240040 */  sw        $a0, 0x40($s1)
/* 1C620 80041220 8C820144 */  lw        $v0, 0x144($a0)
/* 1C624 80041224 AE220058 */  sw        $v0, 0x58($s1)
/* 1C628 80041228 AC910148 */  sw        $s1, 0x148($a0)
/* 1C62C 8004122C 86220008 */  lh        $v0, 8($s1)
/* 1C630 80041230 AC82014C */  sw        $v0, 0x14c($a0)
/* 1C634 80041234 92220006 */  lbu       $v0, 6($s1)
/* 1C638 80041238 08010493 */  j         .L8004124C
/* 1C63C 8004123C A0820004 */   sb       $v0, 4($a0)
.L80041240:
/* 1C640 80041240 30620001 */  andi      $v0, $v1, 1
/* 1C644 80041244 14400018 */  bnez      $v0, .L800412A8
/* 1C648 80041248 00000000 */   nop
.L8004124C:
/* 1C64C 8004124C 0C00EABB */  jal       get_npc_unsafe
/* 1C650 80041250 86240008 */   lh       $a0, 8($s1)
/* 1C654 80041254 0040902D */  daddu     $s2, $v0, $zero
/* 1C658 80041258 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C65C 8004125C C644003C */  lwc1      $f4, 0x3c($s2)
/* 1C660 80041260 C6420040 */  lwc1      $f2, 0x40($s2)
/* 1C664 80041264 44820000 */  mtc1      $v0, $f0
/* 1C668 80041268 00000000 */  nop
/* 1C66C 8004126C 46800020 */  cvt.s.w   $f0, $f0
/* 1C670 80041270 46002100 */  add.s     $f4, $f4, $f0
/* 1C674 80041274 C6400038 */  lwc1      $f0, 0x38($s2)
/* 1C678 80041278 44071000 */  mfc1      $a3, $f2
/* 1C67C 8004127C 44050000 */  mfc1      $a1, $f0
/* 1C680 80041280 44062000 */  mfc1      $a2, $f4
/* 1C684 80041284 24040003 */  addiu     $a0, $zero, 3
/* 1C688 80041288 AFA70044 */  sw        $a3, 0x44($sp)
/* 1C68C 8004128C AFA5003C */  sw        $a1, 0x3c($sp)
/* 1C690 80041290 AFA60040 */  sw        $a2, 0x40($sp)
/* 1C694 80041294 AFA00010 */  sw        $zero, 0x10($sp)
/* 1C698 80041298 E7B40014 */  swc1      $f20, 0x14($sp)
/* 1C69C 8004129C AFA00018 */  sw        $zero, 0x18($sp)
/* 1C6A0 800412A0 0C01C064 */  jal       playFX_18
/* 1C6A4 800412A4 AFBE001C */   sw       $fp, 0x1c($sp)
.L800412A8:
/* 1C6A8 800412A8 8EC20000 */  lw        $v0, ($s6)
/* 1C6AC 800412AC 26B50001 */  addiu     $s5, $s5, 1
/* 1C6B0 800412B0 02A2102A */  slt       $v0, $s5, $v0
/* 1C6B4 800412B4 1440FFBD */  bnez      $v0, .L800411AC
/* 1C6B8 800412B8 26100004 */   addiu    $s0, $s0, 4
.L800412BC:
/* 1C6BC 800412BC 0C03805E */  jal       disable_player_input
/* 1C6C0 800412C0 00000000 */   nop
/* 1C6C4 800412C4 0C03BD8A */  jal       partner_disable_input
/* 1C6C8 800412C8 00000000 */   nop
/* 1C6CC 800412CC 0000202D */  daddu     $a0, $zero, $zero
/* 1C6D0 800412D0 AE600090 */  sw        $zero, 0x90($s3)
/* 1C6D4 800412D4 AE600094 */  sw        $zero, 0x94($s3)
/* 1C6D8 800412D8 A2600012 */  sb        $zero, 0x12($s3)
/* 1C6DC 800412DC 8E820000 */  lw        $v0, ($s4)
/* 1C6E0 800412E0 3C030004 */  lui       $v1, 4
/* 1C6E4 800412E4 00431025 */  or        $v0, $v0, $v1
/* 1C6E8 800412E8 AE820000 */  sw        $v0, ($s4)
.L800412EC:
/* 1C6EC 800412EC 0C05272D */  jal       sfx_play_sound
/* 1C6F0 800412F0 00000000 */   nop
/* 1C6F4 800412F4 24020003 */  addiu     $v0, $zero, 3
.L800412F8:
/* 1C6F8 800412F8 3C01800A */  lui       $at, %hi(gGameState)
/* 1C6FC 800412FC AC22A600 */  sw        $v0, %lo(gGameState)($at)
/* 1C700 80041300 24020001 */  addiu     $v0, $zero, 1
.L80041304:
/* 1C704 80041304 3C01800A */  lui       $at, %hi(D_8009A678)
/* 1C708 80041308 AC22A678 */  sw        $v0, %lo(D_8009A678)($at)
/* 1C70C 8004130C 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1C710 80041310 AC20A5D0 */  sw        $zero, %lo(D_8009A5D0)($at)
dlabel L80041314_1C714
/* 1C714 80041314 8FBF008C */  lw        $ra, 0x8c($sp)
/* 1C718 80041318 8FBE0088 */  lw        $fp, 0x88($sp)
/* 1C71C 8004131C 8FB70084 */  lw        $s7, 0x84($sp)
/* 1C720 80041320 8FB60080 */  lw        $s6, 0x80($sp)
/* 1C724 80041324 8FB5007C */  lw        $s5, 0x7c($sp)
/* 1C728 80041328 8FB40078 */  lw        $s4, 0x78($sp)
/* 1C72C 8004132C 8FB30074 */  lw        $s3, 0x74($sp)
/* 1C730 80041330 8FB20070 */  lw        $s2, 0x70($sp)
/* 1C734 80041334 8FB1006C */  lw        $s1, 0x6c($sp)
/* 1C738 80041338 8FB00068 */  lw        $s0, 0x68($sp)
/* 1C73C 8004133C D7BE00B8 */  ldc1      $f30, 0xb8($sp)
/* 1C740 80041340 D7BC00B0 */  ldc1      $f28, 0xb0($sp)
/* 1C744 80041344 D7BA00A8 */  ldc1      $f26, 0xa8($sp)
/* 1C748 80041348 D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 1C74C 8004134C D7B60098 */  ldc1      $f22, 0x98($sp)
/* 1C750 80041350 D7B40090 */  ldc1      $f20, 0x90($sp)
/* 1C754 80041354 03E00008 */  jr        $ra
/* 1C758 80041358 27BD00C0 */   addiu    $sp, $sp, 0xc0
