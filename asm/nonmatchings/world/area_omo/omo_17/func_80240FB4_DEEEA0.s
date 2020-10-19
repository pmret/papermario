.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB4_DEFE54
/* DEFE54 80240FB4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DEFE58 80240FB8 AFB3002C */  sw        $s3, 0x2c($sp)
/* DEFE5C 80240FBC 0080982D */  daddu     $s3, $a0, $zero
/* DEFE60 80240FC0 AFBF0030 */  sw        $ra, 0x30($sp)
/* DEFE64 80240FC4 AFB20028 */  sw        $s2, 0x28($sp)
/* DEFE68 80240FC8 AFB10024 */  sw        $s1, 0x24($sp)
/* DEFE6C 80240FCC AFB00020 */  sw        $s0, 0x20($sp)
/* DEFE70 80240FD0 8E710148 */  lw        $s1, 0x148($s3)
/* DEFE74 80240FD4 86240008 */  lh        $a0, 8($s1)
/* DEFE78 80240FD8 0C00EABB */  jal       get_npc_unsafe
/* DEFE7C 80240FDC 00A0902D */   daddu    $s2, $a1, $zero
/* DEFE80 80240FE0 8E440004 */  lw        $a0, 4($s2)
/* DEFE84 80240FE4 0040802D */  daddu     $s0, $v0, $zero
/* DEFE88 80240FE8 00041FC2 */  srl       $v1, $a0, 0x1f
/* DEFE8C 80240FEC 00832021 */  addu      $a0, $a0, $v1
/* DEFE90 80240FF0 00042043 */  sra       $a0, $a0, 1
/* DEFE94 80240FF4 0C00A67F */  jal       rand_int
/* DEFE98 80240FF8 24840001 */   addiu    $a0, $a0, 1
/* DEFE9C 80240FFC 8E430004 */  lw        $v1, 4($s2)
/* DEFEA0 80241000 000327C2 */  srl       $a0, $v1, 0x1f
/* DEFEA4 80241004 00641821 */  addu      $v1, $v1, $a0
/* DEFEA8 80241008 00031843 */  sra       $v1, $v1, 1
/* DEFEAC 8024100C 00621821 */  addu      $v1, $v1, $v0
/* DEFEB0 80241010 A603008E */  sh        $v1, 0x8e($s0)
/* DEFEB4 80241014 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DEFEB8 80241018 C6000040 */  lwc1      $f0, 0x40($s0)
/* DEFEBC 8024101C C4640000 */  lwc1      $f4, ($v1)
/* DEFEC0 80241020 46802120 */  cvt.s.w   $f4, $f4
/* DEFEC4 80241024 C4620008 */  lwc1      $f2, 8($v1)
/* DEFEC8 80241028 468010A0 */  cvt.s.w   $f2, $f2
/* DEFECC 8024102C E7A00010 */  swc1      $f0, 0x10($sp)
/* DEFED0 80241030 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DEFED4 80241034 44061000 */  mfc1      $a2, $f2
/* DEFED8 80241038 C440000C */  lwc1      $f0, 0xc($v0)
/* DEFEDC 8024103C 46800020 */  cvt.s.w   $f0, $f0
/* DEFEE0 80241040 E7A00014 */  swc1      $f0, 0x14($sp)
/* DEFEE4 80241044 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DEFEE8 80241048 44052000 */  mfc1      $a1, $f4
/* DEFEEC 8024104C C4400010 */  lwc1      $f0, 0x10($v0)
/* DEFEF0 80241050 46800020 */  cvt.s.w   $f0, $f0
/* DEFEF4 80241054 E7A00018 */  swc1      $f0, 0x18($sp)
/* DEFEF8 80241058 8C640018 */  lw        $a0, 0x18($v1)
/* DEFEFC 8024105C 0C0123F5 */  jal       is_point_within_region
/* DEFF00 80241060 8E070038 */   lw       $a3, 0x38($s0)
/* DEFF04 80241064 1040000E */  beqz      $v0, .L802410A0
/* DEFF08 80241068 00000000 */   nop      
/* DEFF0C 8024106C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DEFF10 80241070 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DEFF14 80241074 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DEFF18 80241078 C4460000 */  lwc1      $f6, ($v0)
/* DEFF1C 8024107C 468031A0 */  cvt.s.w   $f6, $f6
/* DEFF20 80241080 44063000 */  mfc1      $a2, $f6
/* DEFF24 80241084 C4460008 */  lwc1      $f6, 8($v0)
/* DEFF28 80241088 468031A0 */  cvt.s.w   $f6, $f6
/* DEFF2C 8024108C 44073000 */  mfc1      $a3, $f6
/* DEFF30 80241090 0C00A720 */  jal       atan2
/* DEFF34 80241094 00000000 */   nop      
/* DEFF38 80241098 08090434 */  j         .L802410D0
/* DEFF3C 8024109C E600000C */   swc1     $f0, 0xc($s0)
.L802410A0:
/* DEFF40 802410A0 0C00A67F */  jal       rand_int
/* DEFF44 802410A4 2404003C */   addiu    $a0, $zero, 0x3c
/* DEFF48 802410A8 C60C000C */  lwc1      $f12, 0xc($s0)
/* DEFF4C 802410AC 44820000 */  mtc1      $v0, $f0
/* DEFF50 802410B0 00000000 */  nop       
/* DEFF54 802410B4 46800020 */  cvt.s.w   $f0, $f0
/* DEFF58 802410B8 46006300 */  add.s     $f12, $f12, $f0
/* DEFF5C 802410BC 3C0141F0 */  lui       $at, 0x41f0
/* DEFF60 802410C0 44810000 */  mtc1      $at, $f0
/* DEFF64 802410C4 0C00A6C9 */  jal       clamp_angle
/* DEFF68 802410C8 46006301 */   sub.s    $f12, $f12, $f0
/* DEFF6C 802410CC E600000C */  swc1      $f0, 0xc($s0)
.L802410D0:
/* DEFF70 802410D0 8E2200CC */  lw        $v0, 0xcc($s1)
/* DEFF74 802410D4 8C420004 */  lw        $v0, 4($v0)
/* DEFF78 802410D8 AE020028 */  sw        $v0, 0x28($s0)
/* DEFF7C 802410DC AE600074 */  sw        $zero, 0x74($s3)
/* DEFF80 802410E0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DEFF84 802410E4 8C420014 */  lw        $v0, 0x14($v0)
/* DEFF88 802410E8 04410004 */  bgez      $v0, .L802410FC
/* DEFF8C 802410EC 00000000 */   nop      
/* DEFF90 802410F0 C6400000 */  lwc1      $f0, ($s2)
/* DEFF94 802410F4 08090447 */  j         .L8024111C
/* DEFF98 802410F8 E6000018 */   swc1     $f0, 0x18($s0)
.L802410FC:
/* DEFF9C 802410FC 3C018024 */  lui       $at, 0x8024
/* DEFFA0 80241100 D4227950 */  ldc1      $f2, 0x7950($at)
/* DEFFA4 80241104 44820000 */  mtc1      $v0, $f0
/* DEFFA8 80241108 00000000 */  nop       
/* DEFFAC 8024110C 46800021 */  cvt.d.w   $f0, $f0
/* DEFFB0 80241110 46220003 */  div.d     $f0, $f0, $f2
/* DEFFB4 80241114 46200020 */  cvt.s.d   $f0, $f0
/* DEFFB8 80241118 E6000018 */  swc1      $f0, 0x18($s0)
.L8024111C:
/* DEFFBC 8024111C C600003C */  lwc1      $f0, 0x3c($s0)
/* DEFFC0 80241120 3C014059 */  lui       $at, 0x4059
/* DEFFC4 80241124 44811800 */  mtc1      $at, $f3
/* DEFFC8 80241128 44801000 */  mtc1      $zero, $f2
/* DEFFCC 8024112C 46000021 */  cvt.d.s   $f0, $f0
/* DEFFD0 80241130 46220002 */  mul.d     $f0, $f0, $f2
/* DEFFD4 80241134 00000000 */  nop       
/* DEFFD8 80241138 24020001 */  addiu     $v0, $zero, 1
/* DEFFDC 8024113C 4620018D */  trunc.w.d $f6, $f0
/* DEFFE0 80241140 E626007C */  swc1      $f6, 0x7c($s1)
/* DEFFE4 80241144 AE620070 */  sw        $v0, 0x70($s3)
/* DEFFE8 80241148 8FBF0030 */  lw        $ra, 0x30($sp)
/* DEFFEC 8024114C 8FB3002C */  lw        $s3, 0x2c($sp)
/* DEFFF0 80241150 8FB20028 */  lw        $s2, 0x28($sp)
/* DEFFF4 80241154 8FB10024 */  lw        $s1, 0x24($sp)
/* DEFFF8 80241158 8FB00020 */  lw        $s0, 0x20($sp)
/* DEFFFC 8024115C 03E00008 */  jr        $ra
/* DF0000 80241160 27BD0038 */   addiu    $sp, $sp, 0x38
