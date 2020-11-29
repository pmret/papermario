.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D5C_B6680C
/* B6680C 80240D5C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B66810 80240D60 AFBF0024 */  sw        $ra, 0x24($sp)
/* B66814 80240D64 AFB40020 */  sw        $s4, 0x20($sp)
/* B66818 80240D68 AFB3001C */  sw        $s3, 0x1c($sp)
/* B6681C 80240D6C AFB20018 */  sw        $s2, 0x18($sp)
/* B66820 80240D70 AFB10014 */  sw        $s1, 0x14($sp)
/* B66824 80240D74 AFB00010 */  sw        $s0, 0x10($sp)
/* B66828 80240D78 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B6682C 80240D7C 8C900148 */  lw        $s0, 0x148($a0)
/* B66830 80240D80 86040008 */  lh        $a0, 8($s0)
/* B66834 80240D84 0C00EABB */  jal       get_npc_unsafe
/* B66838 80240D88 24110001 */   addiu    $s1, $zero, 1
/* B6683C 80240D8C 86040008 */  lh        $a0, 8($s0)
/* B66840 80240D90 0040802D */  daddu     $s0, $v0, $zero
/* B66844 80240D94 3C05800B */  lui       $a1, %hi(gCameras)
/* B66848 80240D98 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B6684C 80240D9C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B66850 80240DA0 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B66854 80240DA4 00912021 */  addu      $a0, $a0, $s1
/* B66858 80240DA8 00031080 */  sll       $v0, $v1, 2
/* B6685C 80240DAC 00431021 */  addu      $v0, $v0, $v1
/* B66860 80240DB0 00021080 */  sll       $v0, $v0, 2
/* B66864 80240DB4 00431023 */  subu      $v0, $v0, $v1
/* B66868 80240DB8 000218C0 */  sll       $v1, $v0, 3
/* B6686C 80240DBC 00431021 */  addu      $v0, $v0, $v1
/* B66870 80240DC0 000210C0 */  sll       $v0, $v0, 3
/* B66874 80240DC4 0C00FB3A */  jal       get_enemy
/* B66878 80240DC8 00459021 */   addu     $s2, $v0, $a1
/* B6687C 80240DCC 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* B66880 80240DD0 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* B66884 80240DD4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B66888 80240DD8 8E830000 */  lw        $v1, ($s4)
/* B6688C 80240DDC C60E0040 */  lwc1      $f14, 0x40($s0)
/* B66890 80240DE0 8C660028 */  lw        $a2, 0x28($v1)
/* B66894 80240DE4 8C670030 */  lw        $a3, 0x30($v1)
/* B66898 80240DE8 0C00A7B5 */  jal       dist2D
/* B6689C 80240DEC 0040982D */   daddu    $s3, $v0, $zero
/* B668A0 80240DF0 C6620074 */  lwc1      $f2, 0x74($s3)
/* B668A4 80240DF4 468010A0 */  cvt.s.w   $f2, $f2
/* B668A8 80240DF8 4600103C */  c.lt.s    $f2, $f0
/* B668AC 80240DFC 00000000 */  nop       
/* B668B0 80240E00 45030001 */  bc1tl     .L80240E08
/* B668B4 80240E04 0000882D */   daddu    $s1, $zero, $zero
.L80240E08:
/* B668B8 80240E08 C64C006C */  lwc1      $f12, 0x6c($s2)
/* B668BC 80240E0C C60E000C */  lwc1      $f14, 0xc($s0)
/* B668C0 80240E10 3C014387 */  lui       $at, 0x4387
/* B668C4 80240E14 4481A000 */  mtc1      $at, $f20
/* B668C8 80240E18 0C00A70A */  jal       get_clamped_angle_diff
/* B668CC 80240E1C 00000000 */   nop      
/* B668D0 80240E20 0C00A6C9 */  jal       clamp_angle
/* B668D4 80240E24 46000306 */   mov.s    $f12, $f0
/* B668D8 80240E28 3C018024 */  lui       $at, %hi(D_802465B8)
/* B668DC 80240E2C D42265B8 */  ldc1      $f2, %lo(D_802465B8)($at)
/* B668E0 80240E30 46000021 */  cvt.d.s   $f0, $f0
/* B668E4 80240E34 4622003C */  c.lt.d    $f0, $f2
/* B668E8 80240E38 00000000 */  nop       
/* B668EC 80240E3C 45000003 */  bc1f      .L80240E4C
/* B668F0 80240E40 00000000 */   nop      
/* B668F4 80240E44 3C0142B4 */  lui       $at, 0x42b4
/* B668F8 80240E48 4481A000 */  mtc1      $at, $f20
.L80240E4C:
/* B668FC 80240E4C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B66900 80240E50 8E820000 */  lw        $v0, ($s4)
/* B66904 80240E54 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B66908 80240E58 8C460028 */  lw        $a2, 0x28($v0)
/* B6690C 80240E5C 0C00A720 */  jal       atan2
/* B66910 80240E60 8C470030 */   lw       $a3, 0x30($v0)
/* B66914 80240E64 4600A306 */  mov.s     $f12, $f20
/* B66918 80240E68 0C00A70A */  jal       get_clamped_angle_diff
/* B6691C 80240E6C 46000386 */   mov.s    $f14, $f0
/* B66920 80240E70 C6620078 */  lwc1      $f2, 0x78($s3)
/* B66924 80240E74 468010A0 */  cvt.s.w   $f2, $f2
/* B66928 80240E78 46000005 */  abs.s     $f0, $f0
/* B6692C 80240E7C 4600103C */  c.lt.s    $f2, $f0
/* B66930 80240E80 00000000 */  nop       
/* B66934 80240E84 45030001 */  bc1tl     .L80240E8C
/* B66938 80240E88 0000882D */   daddu    $s1, $zero, $zero
.L80240E8C:
/* B6693C 80240E8C 8E820000 */  lw        $v0, ($s4)
/* B66940 80240E90 C600003C */  lwc1      $f0, 0x3c($s0)
/* B66944 80240E94 C442002C */  lwc1      $f2, 0x2c($v0)
/* B66948 80240E98 860200A8 */  lh        $v0, 0xa8($s0)
/* B6694C 80240E9C 46020001 */  sub.s     $f0, $f0, $f2
/* B66950 80240EA0 44821000 */  mtc1      $v0, $f2
/* B66954 80240EA4 00000000 */  nop       
/* B66958 80240EA8 468010A1 */  cvt.d.w   $f2, $f2
/* B6695C 80240EAC 46221080 */  add.d     $f2, $f2, $f2
/* B66960 80240EB0 46000005 */  abs.s     $f0, $f0
/* B66964 80240EB4 46000021 */  cvt.d.s   $f0, $f0
/* B66968 80240EB8 4620103E */  c.le.d    $f2, $f0
/* B6696C 80240EBC 00000000 */  nop       
/* B66970 80240EC0 45030001 */  bc1tl     .L80240EC8
/* B66974 80240EC4 0000882D */   daddu    $s1, $zero, $zero
.L80240EC8:
/* B66978 80240EC8 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* B6697C 80240ECC 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* B66980 80240ED0 24020009 */  addiu     $v0, $zero, 9
/* B66984 80240ED4 50620001 */  beql      $v1, $v0, .L80240EDC
/* B66988 80240ED8 0000882D */   daddu    $s1, $zero, $zero
.L80240EDC:
/* B6698C 80240EDC 24020007 */  addiu     $v0, $zero, 7
/* B66990 80240EE0 50620001 */  beql      $v1, $v0, .L80240EE8
/* B66994 80240EE4 0000882D */   daddu    $s1, $zero, $zero
.L80240EE8:
/* B66998 80240EE8 0220102D */  daddu     $v0, $s1, $zero
/* B6699C 80240EEC 8FBF0024 */  lw        $ra, 0x24($sp)
/* B669A0 80240EF0 8FB40020 */  lw        $s4, 0x20($sp)
/* B669A4 80240EF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* B669A8 80240EF8 8FB20018 */  lw        $s2, 0x18($sp)
/* B669AC 80240EFC 8FB10014 */  lw        $s1, 0x14($sp)
/* B669B0 80240F00 8FB00010 */  lw        $s0, 0x10($sp)
/* B669B4 80240F04 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B669B8 80240F08 03E00008 */  jr        $ra
/* B669BC 80240F0C 27BD0030 */   addiu    $sp, $sp, 0x30
