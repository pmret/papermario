.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FallPartTo
/* 1A9134 8027A854 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 1A9138 8027A858 AFB30024 */  sw    $s3, 0x24($sp)
/* 1A913C 8027A85C 0080982D */  daddu $s3, $a0, $zero
/* 1A9140 8027A860 AFBF0028 */  sw    $ra, 0x28($sp)
/* 1A9144 8027A864 AFB20020 */  sw    $s2, 0x20($sp)
/* 1A9148 8027A868 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1A914C 8027A86C AFB00018 */  sw    $s0, 0x18($sp)
/* 1A9150 8027A870 F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 1A9154 8027A874 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 1A9158 8027A878 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 1A915C 8027A87C F7B80040 */  sdc1  $f24, 0x40($sp)
/* 1A9160 8027A880 F7B60038 */  sdc1  $f22, 0x38($sp)
/* 1A9164 8027A884 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 1A9168 8027A888 8E72000C */  lw    $s2, 0xc($s3)
/* 1A916C 8027A88C 54A00001 */  bnezl $a1, .L8027A894
/* 1A9170 8027A890 AE600070 */   sw    $zero, 0x70($s3)
.L8027A894:
/* 1A9174 8027A894 8E620070 */  lw    $v0, 0x70($s3)
/* 1A9178 8027A898 1440007C */  bnez  $v0, .L8027AA8C
/* 1A917C 8027A89C 00000000 */   nop   
/* 1A9180 8027A8A0 8E450000 */  lw    $a1, ($s2)
/* 1A9184 8027A8A4 26520004 */  addiu $s2, $s2, 4
/* 1A9188 8027A8A8 0C0B1EAF */  jal   get_variable
/* 1A918C 8027A8AC 0260202D */   daddu $a0, $s3, $zero
/* 1A9190 8027A8B0 0040802D */  daddu $s0, $v0, $zero
/* 1A9194 8027A8B4 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A9198 8027A8B8 16020002 */  bne   $s0, $v0, .L8027A8C4
/* 1A919C 8027A8BC 00000000 */   nop   
/* 1A91A0 8027A8C0 8E700148 */  lw    $s0, 0x148($s3)
.L8027A8C4:
/* 1A91A4 8027A8C4 8E450000 */  lw    $a1, ($s2)
/* 1A91A8 8027A8C8 26520004 */  addiu $s2, $s2, 4
/* 1A91AC 8027A8CC 0C0B1EAF */  jal   get_variable
/* 1A91B0 8027A8D0 0260202D */   daddu $a0, $s3, $zero
/* 1A91B4 8027A8D4 0200202D */  daddu $a0, $s0, $zero
/* 1A91B8 8027A8D8 0C09A75B */  jal   get_actor
/* 1A91BC 8027A8DC 0040882D */   daddu $s1, $v0, $zero
/* 1A91C0 8027A8E0 0040802D */  daddu $s0, $v0, $zero
/* 1A91C4 8027A8E4 0200202D */  daddu $a0, $s0, $zero
/* 1A91C8 8027A8E8 0C099117 */  jal   get_actor_part
/* 1A91CC 8027A8EC 0220282D */   daddu $a1, $s1, $zero
/* 1A91D0 8027A8F0 0040882D */  daddu $s1, $v0, $zero
/* 1A91D4 8027A8F4 AE700074 */  sw    $s0, 0x74($s3)
/* 1A91D8 8027A8F8 AE710078 */  sw    $s1, 0x78($s3)
/* 1A91DC 8027A8FC 8E450000 */  lw    $a1, ($s2)
/* 1A91E0 8027A900 26520004 */  addiu $s2, $s2, 4
/* 1A91E4 8027A904 8E300010 */  lw    $s0, 0x10($s1)
/* 1A91E8 8027A908 0C0B1EAF */  jal   get_variable
/* 1A91EC 8027A90C 0260202D */   daddu $a0, $s3, $zero
/* 1A91F0 8027A910 4482E000 */  mtc1  $v0, $f28
/* 1A91F4 8027A914 00000000 */  nop   
/* 1A91F8 8027A918 4680E720 */  cvt.s.w $f28, $f28
/* 1A91FC 8027A91C 8E450000 */  lw    $a1, ($s2)
/* 1A9200 8027A920 26520004 */  addiu $s2, $s2, 4
/* 1A9204 8027A924 0C0B1EAF */  jal   get_variable
/* 1A9208 8027A928 0260202D */   daddu $a0, $s3, $zero
/* 1A920C 8027A92C 4482F000 */  mtc1  $v0, $f30
/* 1A9210 8027A930 00000000 */  nop   
/* 1A9214 8027A934 4680F7A0 */  cvt.s.w $f30, $f30
/* 1A9218 8027A938 8E450000 */  lw    $a1, ($s2)
/* 1A921C 8027A93C 26520004 */  addiu $s2, $s2, 4
/* 1A9220 8027A940 0C0B1EAF */  jal   get_variable
/* 1A9224 8027A944 0260202D */   daddu $a0, $s3, $zero
/* 1A9228 8027A948 44820000 */  mtc1  $v0, $f0
/* 1A922C 8027A94C 00000000 */  nop   
/* 1A9230 8027A950 46800020 */  cvt.s.w $f0, $f0
/* 1A9234 8027A954 E61C000C */  swc1  $f28, 0xc($s0)
/* 1A9238 8027A958 E61E0010 */  swc1  $f30, 0x10($s0)
/* 1A923C 8027A95C E6000014 */  swc1  $f0, 0x14($s0)
/* 1A9240 8027A960 8E450000 */  lw    $a1, ($s2)
/* 1A9244 8027A964 0C0B1EAF */  jal   get_variable
/* 1A9248 8027A968 0260202D */   daddu $a0, $s3, $zero
/* 1A924C 8027A96C A6020038 */  sh    $v0, 0x38($s0)
/* 1A9250 8027A970 C620002C */  lwc1  $f0, 0x2c($s1)
/* 1A9254 8027A974 C618000C */  lwc1  $f24, 0xc($s0)
/* 1A9258 8027A978 C61A0014 */  lwc1  $f26, 0x14($s0)
/* 1A925C 8027A97C C6160010 */  lwc1  $f22, 0x10($s0)
/* 1A9260 8027A980 E6000000 */  swc1  $f0, ($s0)
/* 1A9264 8027A984 46000706 */  mov.s $f28, $f0
/* 1A9268 8027A988 4406C000 */  mfc1  $a2, $f24
/* 1A926C 8027A98C 4407D000 */  mfc1  $a3, $f26
/* 1A9270 8027A990 C6200030 */  lwc1  $f0, 0x30($s1)
/* 1A9274 8027A994 4600E306 */  mov.s $f12, $f28
/* 1A9278 8027A998 E6000004 */  swc1  $f0, 4($s0)
/* 1A927C 8027A99C C6340034 */  lwc1  $f20, 0x34($s1)
/* 1A9280 8027A9A0 46000786 */  mov.s $f30, $f0
/* 1A9284 8027A9A4 4600A386 */  mov.s $f14, $f20
/* 1A9288 8027A9A8 0C00A720 */  jal   atan2
/* 1A928C 8027A9AC E6140008 */   swc1  $f20, 8($s0)
/* 1A9290 8027A9B0 4600E306 */  mov.s $f12, $f28
/* 1A9294 8027A9B4 4600A386 */  mov.s $f14, $f20
/* 1A9298 8027A9B8 4406C000 */  mfc1  $a2, $f24
/* 1A929C 8027A9BC 4407D000 */  mfc1  $a3, $f26
/* 1A92A0 8027A9C0 461EB781 */  sub.s $f30, $f22, $f30
/* 1A92A4 8027A9C4 0C00A7B5 */  jal   dist2D
/* 1A92A8 8027A9C8 E6000030 */   swc1  $f0, 0x30($s0)
/* 1A92AC 8027A9CC 86020038 */  lh    $v0, 0x38($s0)
/* 1A92B0 8027A9D0 46000086 */  mov.s $f2, $f0
/* 1A92B4 8027A9D4 14400007 */  bnez  $v0, .L8027A9F4
/* 1A92B8 8027A9D8 E6020034 */   swc1  $f2, 0x34($s0)
/* 1A92BC 8027A9DC C6000028 */  lwc1  $f0, 0x28($s0)
/* 1A92C0 8027A9E0 46001003 */  div.s $f0, $f2, $f0
/* 1A92C4 8027A9E4 4600018D */  trunc.w.s $f6, $f0
/* 1A92C8 8027A9E8 44023000 */  mfc1  $v0, $f6
/* 1A92CC 8027A9EC 0809EA82 */  j     .L8027AA08
/* 1A92D0 8027A9F0 A6020038 */   sh    $v0, 0x38($s0)

.L8027A9F4:
/* 1A92D4 8027A9F4 44820000 */  mtc1  $v0, $f0
/* 1A92D8 8027A9F8 00000000 */  nop   
/* 1A92DC 8027A9FC 46800020 */  cvt.s.w $f0, $f0
/* 1A92E0 8027AA00 46001003 */  div.s $f0, $f2, $f0
/* 1A92E4 8027AA04 E6000028 */  swc1  $f0, 0x28($s0)
.L8027AA08:
/* 1A92E8 8027AA08 86030038 */  lh    $v1, 0x38($s0)
/* 1A92EC 8027AA0C 3C013FE0 */  lui   $at, 0x3fe0
/* 1A92F0 8027AA10 44810800 */  mtc1  $at, $f1
/* 1A92F4 8027AA14 44800000 */  mtc1  $zero, $f0
/* 1A92F8 8027AA18 00031023 */  negu  $v0, $v1
/* 1A92FC 8027AA1C 44821000 */  mtc1  $v0, $f2
/* 1A9300 8027AA20 00000000 */  nop   
/* 1A9304 8027AA24 468010A1 */  cvt.d.w $f2, $f2
/* 1A9308 8027AA28 46201082 */  mul.d $f2, $f2, $f0
/* 1A930C 8027AA2C 00000000 */  nop   
/* 1A9310 8027AA30 AE00002C */  sw    $zero, 0x2c($s0)
/* 1A9314 8027AA34 C604002C */  lwc1  $f4, 0x2c($s0)
/* 1A9318 8027AA38 44830000 */  mtc1  $v1, $f0
/* 1A931C 8027AA3C 00000000 */  nop   
/* 1A9320 8027AA40 46800020 */  cvt.s.w $f0, $f0
/* 1A9324 8027AA44 4600F003 */  div.s $f0, $f30, $f0
/* 1A9328 8027AA48 46040001 */  sub.s $f0, $f0, $f4
/* 1A932C 8027AA4C 46000021 */  cvt.d.s $f0, $f0
/* 1A9330 8027AA50 46220003 */  div.d $f0, $f0, $f2
/* 1A9334 8027AA54 46200020 */  cvt.s.d $f0, $f0
/* 1A9338 8027AA58 E6000024 */  swc1  $f0, 0x24($s0)
/* 1A933C 8027AA5C 8E2200B4 */  lw    $v0, 0xb4($s1)
/* 1A9340 8027AA60 10400009 */  beqz  $v0, .L8027AA88
/* 1A9344 8027AA64 24020001 */   addiu $v0, $zero, 1
/* 1A9348 8027AA68 C6200034 */  lwc1  $f0, 0x34($s1)
/* 1A934C 8027AA6C E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A9350 8027AA70 8E2400B4 */  lw    $a0, 0xb4($s1)
/* 1A9354 8027AA74 8E26002C */  lw    $a2, 0x2c($s1)
/* 1A9358 8027AA78 8E270030 */  lw    $a3, 0x30($s1)
/* 1A935C 8027AA7C 0C052757 */  jal   play_sound_at_position
/* 1A9360 8027AA80 0000282D */   daddu $a1, $zero, $zero
/* 1A9364 8027AA84 24020001 */  addiu $v0, $zero, 1
.L8027AA88:
/* 1A9368 8027AA88 AE620070 */  sw    $v0, 0x70($s3)
.L8027AA8C:
/* 1A936C 8027AA8C 8E710078 */  lw    $s1, 0x78($s3)
/* 1A9370 8027AA90 8E300010 */  lw    $s0, 0x10($s1)
/* 1A9374 8027AA94 C6040004 */  lwc1  $f4, 4($s0)
/* 1A9378 8027AA98 C600002C */  lwc1  $f0, 0x2c($s0)
/* 1A937C 8027AA9C 8E050028 */  lw    $a1, 0x28($s0)
/* 1A9380 8027AAA0 46002100 */  add.s $f4, $f4, $f0
/* 1A9384 8027AAA4 C6020024 */  lwc1  $f2, 0x24($s0)
/* 1A9388 8027AAA8 8E060030 */  lw    $a2, 0x30($s0)
/* 1A938C 8027AAAC 46020001 */  sub.s $f0, $f0, $f2
/* 1A9390 8027AAB0 0200202D */  daddu $a0, $s0, $zero
/* 1A9394 8027AAB4 E6040004 */  swc1  $f4, 4($s0)
/* 1A9398 8027AAB8 0C099070 */  jal   add_xz_vec3f_copy1
/* 1A939C 8027AABC E600002C */   swc1  $f0, 0x2c($s0)
/* 1A93A0 8027AAC0 C6000000 */  lwc1  $f0, ($s0)
/* 1A93A4 8027AAC4 E620002C */  swc1  $f0, 0x2c($s1)
/* 1A93A8 8027AAC8 C6000004 */  lwc1  $f0, 4($s0)
/* 1A93AC 8027AACC E6200030 */  swc1  $f0, 0x30($s1)
/* 1A93B0 8027AAD0 C6000008 */  lwc1  $f0, 8($s0)
/* 1A93B4 8027AAD4 E6200034 */  swc1  $f0, 0x34($s1)
/* 1A93B8 8027AAD8 96020038 */  lhu   $v0, 0x38($s0)
/* 1A93BC 8027AADC 2442FFFF */  addiu $v0, $v0, -1
/* 1A93C0 8027AAE0 A6020038 */  sh    $v0, 0x38($s0)
/* 1A93C4 8027AAE4 00021400 */  sll   $v0, $v0, 0x10
/* 1A93C8 8027AAE8 1C40000F */  bgtz  $v0, .L8027AB28
/* 1A93CC 8027AAEC 0000102D */   daddu $v0, $zero, $zero
/* 1A93D0 8027AAF0 C6000030 */  lwc1  $f0, 0x30($s0)
/* 1A93D4 8027AAF4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A93D8 8027AAF8 8E05000C */  lw    $a1, 0xc($s0)
/* 1A93DC 8027AAFC 8E060010 */  lw    $a2, 0x10($s0)
/* 1A93E0 8027AB00 8E070014 */  lw    $a3, 0x14($s0)
/* 1A93E4 8027AB04 0C0990BC */  jal   play_movement_dust_effects
/* 1A93E8 8027AB08 24040002 */   addiu $a0, $zero, 2
/* 1A93EC 8027AB0C C600000C */  lwc1  $f0, 0xc($s0)
/* 1A93F0 8027AB10 E620002C */  swc1  $f0, 0x2c($s1)
/* 1A93F4 8027AB14 C6000010 */  lwc1  $f0, 0x10($s0)
/* 1A93F8 8027AB18 E6200030 */  swc1  $f0, 0x30($s1)
/* 1A93FC 8027AB1C C6000014 */  lwc1  $f0, 0x14($s0)
/* 1A9400 8027AB20 24020001 */  addiu $v0, $zero, 1
/* 1A9404 8027AB24 E6200034 */  swc1  $f0, 0x34($s1)
.L8027AB28:
/* 1A9408 8027AB28 8FBF0028 */  lw    $ra, 0x28($sp)
/* 1A940C 8027AB2C 8FB30024 */  lw    $s3, 0x24($sp)
/* 1A9410 8027AB30 8FB20020 */  lw    $s2, 0x20($sp)
/* 1A9414 8027AB34 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1A9418 8027AB38 8FB00018 */  lw    $s0, 0x18($sp)
/* 1A941C 8027AB3C D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 1A9420 8027AB40 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 1A9424 8027AB44 D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 1A9428 8027AB48 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 1A942C 8027AB4C D7B60038 */  ldc1  $f22, 0x38($sp)
/* 1A9430 8027AB50 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 1A9434 8027AB54 03E00008 */  jr    $ra
/* 1A9438 8027AB58 27BD0060 */   addiu $sp, $sp, 0x60

