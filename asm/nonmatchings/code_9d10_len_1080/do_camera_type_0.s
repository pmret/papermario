.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel do_camera_type_0
/* AC50 8002F850 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* AC54 8002F854 AFB00010 */  sw        $s0, 0x10($sp)
/* AC58 8002F858 0080802D */  daddu     $s0, $a0, $zero
/* AC5C 8002F85C AFBF0014 */  sw        $ra, 0x14($sp)
/* AC60 8002F860 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* AC64 8002F864 F7B80028 */  sdc1      $f24, 0x28($sp)
/* AC68 8002F868 F7B60020 */  sdc1      $f22, 0x20($sp)
/* AC6C 8002F86C F7B40018 */  sdc1      $f20, 0x18($sp)
/* AC70 8002F870 86020006 */  lh        $v0, 6($s0)
/* AC74 8002F874 10400011 */  beqz      $v0, .L8002F8BC
/* AC78 8002F878 00000000 */   nop      
/* AC7C 8002F87C 3C01800A */  lui       $at, 0x800a
/* AC80 8002F880 C420A5EC */  lwc1      $f0, -0x5a14($at)
/* AC84 8002F884 3C01447A */  lui       $at, 0x447a
/* AC88 8002F888 44811000 */  mtc1      $at, $f2
/* AC8C 8002F88C AE000048 */  sw        $zero, 0x48($s0)
/* AC90 8002F890 C6060048 */  lwc1      $f6, 0x48($s0)
/* AC94 8002F894 AE00004C */  sw        $zero, 0x4c($s0)
/* AC98 8002F898 C604004C */  lwc1      $f4, 0x4c($s0)
/* AC9C 8002F89C AE000050 */  sw        $zero, 0x50($s0)
/* ACA0 8002F8A0 46001083 */  div.s     $f2, $f2, $f0
/* ACA4 8002F8A4 C6000050 */  lwc1      $f0, 0x50($s0)
/* ACA8 8002F8A8 A6000006 */  sh        $zero, 6($s0)
/* ACAC 8002F8AC 46020001 */  sub.s     $f0, $f0, $f2
/* ACB0 8002F8B0 E606003C */  swc1      $f6, 0x3c($s0)
/* ACB4 8002F8B4 E6040040 */  swc1      $f4, 0x40($s0)
/* ACB8 8002F8B8 E6000044 */  swc1      $f0, 0x44($s0)
.L8002F8BC:
/* ACBC 8002F8BC C60C003C */  lwc1      $f12, 0x3c($s0)
/* ACC0 8002F8C0 C60E0044 */  lwc1      $f14, 0x44($s0)
/* ACC4 8002F8C4 8E060048 */  lw        $a2, 0x48($s0)
/* ACC8 8002F8C8 8E070050 */  lw        $a3, 0x50($s0)
/* ACCC 8002F8CC 4480C000 */  mtc1      $zero, $f24
/* ACD0 8002F8D0 0C00A720 */  jal       atan2
/* ACD4 8002F8D4 00000000 */   nop      
/* ACD8 8002F8D8 4600C306 */  mov.s     $f12, $f24
/* ACDC 8002F8DC 4600C386 */  mov.s     $f14, $f24
/* ACE0 8002F8E0 C6040048 */  lwc1      $f4, 0x48($s0)
/* ACE4 8002F8E4 C602003C */  lwc1      $f2, 0x3c($s0)
/* ACE8 8002F8E8 C6140050 */  lwc1      $f20, 0x50($s0)
/* ACEC 8002F8EC 46022581 */  sub.s     $f22, $f4, $f2
/* ACF0 8002F8F0 C6020044 */  lwc1      $f2, 0x44($s0)
/* ACF4 8002F8F4 C604004C */  lwc1      $f4, 0x4c($s0)
/* ACF8 8002F8F8 4602A501 */  sub.s     $f20, $f20, $f2
/* ACFC 8002F8FC C6020040 */  lwc1      $f2, 0x40($s0)
/* AD00 8002F900 4406B000 */  mfc1      $a2, $f22
/* AD04 8002F904 4407A000 */  mfc1      $a3, $f20
/* AD08 8002F908 46022681 */  sub.s     $f26, $f4, $f2
/* AD0C 8002F90C 0C00A720 */  jal       atan2
/* AD10 8002F910 E600006C */   swc1     $f0, 0x6c($s0)
/* AD14 8002F914 4616B082 */  mul.s     $f2, $f22, $f22
/* AD18 8002F918 00000000 */  nop       
/* AD1C 8002F91C 4614A502 */  mul.s     $f20, $f20, $f20
/* AD20 8002F920 00000000 */  nop       
/* AD24 8002F924 46141300 */  add.s     $f12, $f2, $f20
/* AD28 8002F928 46000007 */  neg.s     $f0, $f0
/* AD2C 8002F92C E6000090 */  swc1      $f0, 0x90($s0)
/* AD30 8002F930 46006004 */  sqrt.s    $f0, $f12
/* AD34 8002F934 46000032 */  c.eq.s    $f0, $f0
/* AD38 8002F938 00000000 */  nop       
/* AD3C 8002F93C 45030004 */  bc1tl     .L8002F950
/* AD40 8002F940 4600C306 */   mov.s    $f12, $f24
/* AD44 8002F944 0C0187BC */  jal       sqrtf
/* AD48 8002F948 00000000 */   nop      
/* AD4C 8002F94C 4600C306 */  mov.s     $f12, $f24
.L8002F950:
/* AD50 8002F950 46000007 */  neg.s     $f0, $f0
/* AD54 8002F954 4406D000 */  mfc1      $a2, $f26
/* AD58 8002F958 44070000 */  mfc1      $a3, $f0
/* AD5C 8002F95C 0C00A720 */  jal       atan2
/* AD60 8002F960 46006386 */   mov.s    $f14, $f12
/* AD64 8002F964 E6000094 */  swc1      $f0, 0x94($s0)
/* AD68 8002F968 8FBF0014 */  lw        $ra, 0x14($sp)
/* AD6C 8002F96C 8FB00010 */  lw        $s0, 0x10($sp)
/* AD70 8002F970 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* AD74 8002F974 D7B80028 */  ldc1      $f24, 0x28($sp)
/* AD78 8002F978 D7B60020 */  ldc1      $f22, 0x20($sp)
/* AD7C 8002F97C D7B40018 */  ldc1      $f20, 0x18($sp)
/* AD80 8002F980 03E00008 */  jr        $ra
/* AD84 8002F984 27BD0038 */   addiu    $sp, $sp, 0x38
/* AD88 8002F988 00000000 */  nop       
/* AD8C 8002F98C 00000000 */  nop       
