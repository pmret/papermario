.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B10_CCBE20
/* CCBE20 80240B10 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CCBE24 80240B14 AFB3002C */  sw        $s3, 0x2c($sp)
/* CCBE28 80240B18 0080982D */  daddu     $s3, $a0, $zero
/* CCBE2C 80240B1C AFBF0030 */  sw        $ra, 0x30($sp)
/* CCBE30 80240B20 AFB20028 */  sw        $s2, 0x28($sp)
/* CCBE34 80240B24 AFB10024 */  sw        $s1, 0x24($sp)
/* CCBE38 80240B28 AFB00020 */  sw        $s0, 0x20($sp)
/* CCBE3C 80240B2C 8E710148 */  lw        $s1, 0x148($s3)
/* CCBE40 80240B30 86240008 */  lh        $a0, 8($s1)
/* CCBE44 80240B34 0C00EABB */  jal       get_npc_unsafe
/* CCBE48 80240B38 00A0902D */   daddu    $s2, $a1, $zero
/* CCBE4C 80240B3C 8E440004 */  lw        $a0, 4($s2)
/* CCBE50 80240B40 0040802D */  daddu     $s0, $v0, $zero
/* CCBE54 80240B44 00041FC2 */  srl       $v1, $a0, 0x1f
/* CCBE58 80240B48 00832021 */  addu      $a0, $a0, $v1
/* CCBE5C 80240B4C 00042043 */  sra       $a0, $a0, 1
/* CCBE60 80240B50 0C00A67F */  jal       rand_int
/* CCBE64 80240B54 24840001 */   addiu    $a0, $a0, 1
/* CCBE68 80240B58 8E430004 */  lw        $v1, 4($s2)
/* CCBE6C 80240B5C 000327C2 */  srl       $a0, $v1, 0x1f
/* CCBE70 80240B60 00641821 */  addu      $v1, $v1, $a0
/* CCBE74 80240B64 00031843 */  sra       $v1, $v1, 1
/* CCBE78 80240B68 00621821 */  addu      $v1, $v1, $v0
/* CCBE7C 80240B6C A603008E */  sh        $v1, 0x8e($s0)
/* CCBE80 80240B70 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CCBE84 80240B74 C6000040 */  lwc1      $f0, 0x40($s0)
/* CCBE88 80240B78 C4640000 */  lwc1      $f4, ($v1)
/* CCBE8C 80240B7C 46802120 */  cvt.s.w   $f4, $f4
/* CCBE90 80240B80 C4620008 */  lwc1      $f2, 8($v1)
/* CCBE94 80240B84 468010A0 */  cvt.s.w   $f2, $f2
/* CCBE98 80240B88 E7A00010 */  swc1      $f0, 0x10($sp)
/* CCBE9C 80240B8C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCBEA0 80240B90 44061000 */  mfc1      $a2, $f2
/* CCBEA4 80240B94 C440000C */  lwc1      $f0, 0xc($v0)
/* CCBEA8 80240B98 46800020 */  cvt.s.w   $f0, $f0
/* CCBEAC 80240B9C E7A00014 */  swc1      $f0, 0x14($sp)
/* CCBEB0 80240BA0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCBEB4 80240BA4 44052000 */  mfc1      $a1, $f4
/* CCBEB8 80240BA8 C4400010 */  lwc1      $f0, 0x10($v0)
/* CCBEBC 80240BAC 46800020 */  cvt.s.w   $f0, $f0
/* CCBEC0 80240BB0 E7A00018 */  swc1      $f0, 0x18($sp)
/* CCBEC4 80240BB4 8C640018 */  lw        $a0, 0x18($v1)
/* CCBEC8 80240BB8 0C0123F5 */  jal       is_point_within_region
/* CCBECC 80240BBC 8E070038 */   lw       $a3, 0x38($s0)
/* CCBED0 80240BC0 1040000E */  beqz      $v0, .L80240BFC
/* CCBED4 80240BC4 00000000 */   nop
/* CCBED8 80240BC8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCBEDC 80240BCC C60C0038 */  lwc1      $f12, 0x38($s0)
/* CCBEE0 80240BD0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CCBEE4 80240BD4 C4460000 */  lwc1      $f6, ($v0)
/* CCBEE8 80240BD8 468031A0 */  cvt.s.w   $f6, $f6
/* CCBEEC 80240BDC 44063000 */  mfc1      $a2, $f6
/* CCBEF0 80240BE0 C4460008 */  lwc1      $f6, 8($v0)
/* CCBEF4 80240BE4 468031A0 */  cvt.s.w   $f6, $f6
/* CCBEF8 80240BE8 44073000 */  mfc1      $a3, $f6
/* CCBEFC 80240BEC 0C00A720 */  jal       atan2
/* CCBF00 80240BF0 00000000 */   nop
/* CCBF04 80240BF4 0809030B */  j         .L80240C2C
/* CCBF08 80240BF8 E600000C */   swc1     $f0, 0xc($s0)
.L80240BFC:
/* CCBF0C 80240BFC 0C00A67F */  jal       rand_int
/* CCBF10 80240C00 2404003C */   addiu    $a0, $zero, 0x3c
/* CCBF14 80240C04 C60C000C */  lwc1      $f12, 0xc($s0)
/* CCBF18 80240C08 44820000 */  mtc1      $v0, $f0
/* CCBF1C 80240C0C 00000000 */  nop
/* CCBF20 80240C10 46800020 */  cvt.s.w   $f0, $f0
/* CCBF24 80240C14 46006300 */  add.s     $f12, $f12, $f0
/* CCBF28 80240C18 3C0141F0 */  lui       $at, 0x41f0
/* CCBF2C 80240C1C 44810000 */  mtc1      $at, $f0
/* CCBF30 80240C20 0C00A6C9 */  jal       clamp_angle
/* CCBF34 80240C24 46006301 */   sub.s    $f12, $f12, $f0
/* CCBF38 80240C28 E600000C */  swc1      $f0, 0xc($s0)
.L80240C2C:
/* CCBF3C 80240C2C 8E2200CC */  lw        $v0, 0xcc($s1)
/* CCBF40 80240C30 8C420004 */  lw        $v0, 4($v0)
/* CCBF44 80240C34 AE020028 */  sw        $v0, 0x28($s0)
/* CCBF48 80240C38 AE600074 */  sw        $zero, 0x74($s3)
/* CCBF4C 80240C3C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCBF50 80240C40 8C420014 */  lw        $v0, 0x14($v0)
/* CCBF54 80240C44 04410004 */  bgez      $v0, .L80240C58
/* CCBF58 80240C48 00000000 */   nop
/* CCBF5C 80240C4C C6400000 */  lwc1      $f0, ($s2)
/* CCBF60 80240C50 0809031E */  j         .L80240C78
/* CCBF64 80240C54 E6000018 */   swc1     $f0, 0x18($s0)
.L80240C58:
/* CCBF68 80240C58 3C018024 */  lui       $at, %hi(D_80245350_CD0660)
/* CCBF6C 80240C5C D4225350 */  ldc1      $f2, %lo(D_80245350_CD0660)($at)
/* CCBF70 80240C60 44820000 */  mtc1      $v0, $f0
/* CCBF74 80240C64 00000000 */  nop
/* CCBF78 80240C68 46800021 */  cvt.d.w   $f0, $f0
/* CCBF7C 80240C6C 46220003 */  div.d     $f0, $f0, $f2
/* CCBF80 80240C70 46200020 */  cvt.s.d   $f0, $f0
/* CCBF84 80240C74 E6000018 */  swc1      $f0, 0x18($s0)
.L80240C78:
/* CCBF88 80240C78 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCBF8C 80240C7C 3C014059 */  lui       $at, 0x4059
/* CCBF90 80240C80 44811800 */  mtc1      $at, $f3
/* CCBF94 80240C84 44801000 */  mtc1      $zero, $f2
/* CCBF98 80240C88 46000021 */  cvt.d.s   $f0, $f0
/* CCBF9C 80240C8C 46220002 */  mul.d     $f0, $f0, $f2
/* CCBFA0 80240C90 00000000 */  nop
/* CCBFA4 80240C94 24020001 */  addiu     $v0, $zero, 1
/* CCBFA8 80240C98 4620018D */  trunc.w.d $f6, $f0
/* CCBFAC 80240C9C E626007C */  swc1      $f6, 0x7c($s1)
/* CCBFB0 80240CA0 AE620070 */  sw        $v0, 0x70($s3)
/* CCBFB4 80240CA4 8FBF0030 */  lw        $ra, 0x30($sp)
/* CCBFB8 80240CA8 8FB3002C */  lw        $s3, 0x2c($sp)
/* CCBFBC 80240CAC 8FB20028 */  lw        $s2, 0x28($sp)
/* CCBFC0 80240CB0 8FB10024 */  lw        $s1, 0x24($sp)
/* CCBFC4 80240CB4 8FB00020 */  lw        $s0, 0x20($sp)
/* CCBFC8 80240CB8 03E00008 */  jr        $ra
/* CCBFCC 80240CBC 27BD0038 */   addiu    $sp, $sp, 0x38
