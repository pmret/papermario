.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024206C_83386C
/* 83386C 8024206C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 833870 80242070 AFB00018 */  sw        $s0, 0x18($sp)
/* 833874 80242074 0080802D */  daddu     $s0, $a0, $zero
/* 833878 80242078 AFB40028 */  sw        $s4, 0x28($sp)
/* 83387C 8024207C 3C14F5DE */  lui       $s4, 0xf5de
/* 833880 80242080 3694019E */  ori       $s4, $s4, 0x19e
/* 833884 80242084 0000202D */  daddu     $a0, $zero, $zero
/* 833888 80242088 3C05F5DE */  lui       $a1, 0xf5de
/* 83388C 8024208C AFBF0030 */  sw        $ra, 0x30($sp)
/* 833890 80242090 AFB5002C */  sw        $s5, 0x2c($sp)
/* 833894 80242094 AFB30024 */  sw        $s3, 0x24($sp)
/* 833898 80242098 AFB20020 */  sw        $s2, 0x20($sp)
/* 83389C 8024209C AFB1001C */  sw        $s1, 0x1c($sp)
/* 8338A0 802420A0 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 8338A4 802420A4 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 8338A8 802420A8 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 8338AC 802420AC 0C0B1EAF */  jal       get_variable
/* 8338B0 802420B0 34A5019D */   ori      $a1, $a1, 0x19d
/* 8338B4 802420B4 0000202D */  daddu     $a0, $zero, $zero
/* 8338B8 802420B8 44800000 */  mtc1      $zero, $f0
/* 8338BC 802420BC 0080882D */  daddu     $s1, $a0, $zero
/* 8338C0 802420C0 44050000 */  mfc1      $a1, $f0
/* 8338C4 802420C4 0040982D */  daddu     $s3, $v0, $zero
/* 8338C8 802420C8 AFA00014 */  sw        $zero, 0x14($sp)
/* 8338CC 802420CC 00A0302D */  daddu     $a2, $a1, $zero
/* 8338D0 802420D0 00A0382D */  daddu     $a3, $a1, $zero
/* 8338D4 802420D4 0C01C9C4 */  jal       func_80072710
/* 8338D8 802420D8 AFA50010 */   sw       $a1, 0x10($sp)
/* 8338DC 802420DC 0200202D */  daddu     $a0, $s0, $zero
/* 8338E0 802420E0 3C05FD05 */  lui       $a1, 0xfd05
/* 8338E4 802420E4 34A50F82 */  ori       $a1, $a1, 0xf82
/* 8338E8 802420E8 0040802D */  daddu     $s0, $v0, $zero
/* 8338EC 802420EC 0C0B2026 */  jal       set_variable
/* 8338F0 802420F0 0200302D */   daddu    $a2, $s0, $zero
/* 8338F4 802420F4 1A60002F */  blez      $s3, .L802421B4
/* 8338F8 802420F8 24150002 */   addiu    $s5, $zero, 2
/* 8338FC 802420FC 2412012C */  addiu     $s2, $zero, 0x12c
/* 833900 80242100 3C0141A0 */  lui       $at, 0x41a0
/* 833904 80242104 4481C000 */  mtc1      $at, $f24
/* 833908 80242108 3C01C334 */  lui       $at, 0xc334
/* 83390C 8024210C 4481B000 */  mtc1      $at, $f22
/* 833910 80242110 3C014387 */  lui       $at, 0x4387
/* 833914 80242114 4481A000 */  mtc1      $at, $f20
.L80242118:
/* 833918 80242118 0000202D */  daddu     $a0, $zero, $zero
/* 83391C 8024211C 0C0B1EAF */  jal       get_variable
/* 833920 80242120 02912821 */   addu     $a1, $s4, $s1
/* 833924 80242124 8E03000C */  lw        $v1, 0xc($s0)
/* 833928 80242128 00112080 */  sll       $a0, $s1, 2
/* 83392C 8024212C 00711821 */  addu      $v1, $v1, $s1
/* 833930 80242130 A06200E4 */  sb        $v0, 0xe4($v1)
/* 833934 80242134 8E02000C */  lw        $v0, 0xc($s0)
/* 833938 80242138 44920000 */  mtc1      $s2, $f0
/* 83393C 8024213C 00000000 */  nop
/* 833940 80242140 46800020 */  cvt.s.w   $f0, $f0
/* 833944 80242144 00441021 */  addu      $v0, $v0, $a0
/* 833948 80242148 E4400034 */  swc1      $f0, 0x34($v0)
/* 83394C 8024214C 8E02000C */  lw        $v0, 0xc($s0)
/* 833950 80242150 00441021 */  addu      $v0, $v0, $a0
/* 833954 80242154 E4580060 */  swc1      $f24, 0x60($v0)
/* 833958 80242158 8E02000C */  lw        $v0, 0xc($s0)
/* 83395C 8024215C 00441021 */  addu      $v0, $v0, $a0
/* 833960 80242160 E456008C */  swc1      $f22, 0x8c($v0)
/* 833964 80242164 8E02000C */  lw        $v0, 0xc($s0)
/* 833968 80242168 00441021 */  addu      $v0, $v0, $a0
/* 83396C 8024216C E45400B8 */  swc1      $f20, 0xb8($v0)
/* 833970 80242170 8E03000C */  lw        $v1, 0xc($s0)
/* 833974 80242174 00641821 */  addu      $v1, $v1, $a0
/* 833978 80242178 8C620008 */  lw        $v0, 8($v1)
/* 83397C 8024217C 34420001 */  ori       $v0, $v0, 1
/* 833980 80242180 AC620008 */  sw        $v0, 8($v1)
/* 833984 80242184 8E03000C */  lw        $v1, 0xc($s0)
/* 833988 80242188 00641821 */  addu      $v1, $v1, $a0
/* 83398C 8024218C 8C620008 */  lw        $v0, 8($v1)
/* 833990 80242190 34420002 */  ori       $v0, $v0, 2
/* 833994 80242194 AC620008 */  sw        $v0, 8($v1)
/* 833998 80242198 8E02000C */  lw        $v0, 0xc($s0)
/* 83399C 8024219C 00511021 */  addu      $v0, $v0, $s1
/* 8339A0 802421A0 26310001 */  addiu     $s1, $s1, 1
/* 8339A4 802421A4 A05500EF */  sb        $s5, 0xef($v0)
/* 8339A8 802421A8 0233102A */  slt       $v0, $s1, $s3
/* 8339AC 802421AC 1440FFDA */  bnez      $v0, .L80242118
/* 8339B0 802421B0 2652001E */   addiu    $s2, $s2, 0x1e
.L802421B4:
/* 8339B4 802421B4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 8339B8 802421B8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8339BC 802421BC 8FB40028 */  lw        $s4, 0x28($sp)
/* 8339C0 802421C0 8FB30024 */  lw        $s3, 0x24($sp)
/* 8339C4 802421C4 8FB20020 */  lw        $s2, 0x20($sp)
/* 8339C8 802421C8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8339CC 802421CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 8339D0 802421D0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 8339D4 802421D4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 8339D8 802421D8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 8339DC 802421DC 24020002 */  addiu     $v0, $zero, 2
/* 8339E0 802421E0 03E00008 */  jr        $ra
/* 8339E4 802421E4 27BD0050 */   addiu    $sp, $sp, 0x50
