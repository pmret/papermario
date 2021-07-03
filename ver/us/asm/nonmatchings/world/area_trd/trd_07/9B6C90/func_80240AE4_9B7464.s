.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244880_9BB200
.double 32767.0

.section .text

glabel func_80240AE4_9B7464
/* 9B7464 80240AE4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9B7468 80240AE8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 9B746C 80240AEC 0080982D */  daddu     $s3, $a0, $zero
/* 9B7470 80240AF0 AFBF0030 */  sw        $ra, 0x30($sp)
/* 9B7474 80240AF4 AFB20028 */  sw        $s2, 0x28($sp)
/* 9B7478 80240AF8 AFB10024 */  sw        $s1, 0x24($sp)
/* 9B747C 80240AFC AFB00020 */  sw        $s0, 0x20($sp)
/* 9B7480 80240B00 8E710148 */  lw        $s1, 0x148($s3)
/* 9B7484 80240B04 86240008 */  lh        $a0, 8($s1)
/* 9B7488 80240B08 0C00EABB */  jal       get_npc_unsafe
/* 9B748C 80240B0C 00A0902D */   daddu    $s2, $a1, $zero
/* 9B7490 80240B10 8E440004 */  lw        $a0, 4($s2)
/* 9B7494 80240B14 0040802D */  daddu     $s0, $v0, $zero
/* 9B7498 80240B18 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9B749C 80240B1C 00832021 */  addu      $a0, $a0, $v1
/* 9B74A0 80240B20 00042043 */  sra       $a0, $a0, 1
/* 9B74A4 80240B24 0C00A67F */  jal       rand_int
/* 9B74A8 80240B28 24840001 */   addiu    $a0, $a0, 1
/* 9B74AC 80240B2C 8E430004 */  lw        $v1, 4($s2)
/* 9B74B0 80240B30 000327C2 */  srl       $a0, $v1, 0x1f
/* 9B74B4 80240B34 00641821 */  addu      $v1, $v1, $a0
/* 9B74B8 80240B38 00031843 */  sra       $v1, $v1, 1
/* 9B74BC 80240B3C 00621821 */  addu      $v1, $v1, $v0
/* 9B74C0 80240B40 A603008E */  sh        $v1, 0x8e($s0)
/* 9B74C4 80240B44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9B74C8 80240B48 C6000040 */  lwc1      $f0, 0x40($s0)
/* 9B74CC 80240B4C C4640000 */  lwc1      $f4, ($v1)
/* 9B74D0 80240B50 46802120 */  cvt.s.w   $f4, $f4
/* 9B74D4 80240B54 C4620008 */  lwc1      $f2, 8($v1)
/* 9B74D8 80240B58 468010A0 */  cvt.s.w   $f2, $f2
/* 9B74DC 80240B5C E7A00010 */  swc1      $f0, 0x10($sp)
/* 9B74E0 80240B60 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9B74E4 80240B64 44061000 */  mfc1      $a2, $f2
/* 9B74E8 80240B68 C440000C */  lwc1      $f0, 0xc($v0)
/* 9B74EC 80240B6C 46800020 */  cvt.s.w   $f0, $f0
/* 9B74F0 80240B70 E7A00014 */  swc1      $f0, 0x14($sp)
/* 9B74F4 80240B74 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9B74F8 80240B78 44052000 */  mfc1      $a1, $f4
/* 9B74FC 80240B7C C4400010 */  lwc1      $f0, 0x10($v0)
/* 9B7500 80240B80 46800020 */  cvt.s.w   $f0, $f0
/* 9B7504 80240B84 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9B7508 80240B88 8C640018 */  lw        $a0, 0x18($v1)
/* 9B750C 80240B8C 0C0123F5 */  jal       is_point_within_region
/* 9B7510 80240B90 8E070038 */   lw       $a3, 0x38($s0)
/* 9B7514 80240B94 1040000E */  beqz      $v0, .L80240BD0
/* 9B7518 80240B98 00000000 */   nop
/* 9B751C 80240B9C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9B7520 80240BA0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9B7524 80240BA4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9B7528 80240BA8 C4460000 */  lwc1      $f6, ($v0)
/* 9B752C 80240BAC 468031A0 */  cvt.s.w   $f6, $f6
/* 9B7530 80240BB0 44063000 */  mfc1      $a2, $f6
/* 9B7534 80240BB4 C4460008 */  lwc1      $f6, 8($v0)
/* 9B7538 80240BB8 468031A0 */  cvt.s.w   $f6, $f6
/* 9B753C 80240BBC 44073000 */  mfc1      $a3, $f6
/* 9B7540 80240BC0 0C00A720 */  jal       atan2
/* 9B7544 80240BC4 00000000 */   nop
/* 9B7548 80240BC8 08090300 */  j         .L80240C00
/* 9B754C 80240BCC E600000C */   swc1     $f0, 0xc($s0)
.L80240BD0:
/* 9B7550 80240BD0 0C00A67F */  jal       rand_int
/* 9B7554 80240BD4 2404003C */   addiu    $a0, $zero, 0x3c
/* 9B7558 80240BD8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9B755C 80240BDC 44820000 */  mtc1      $v0, $f0
/* 9B7560 80240BE0 00000000 */  nop
/* 9B7564 80240BE4 46800020 */  cvt.s.w   $f0, $f0
/* 9B7568 80240BE8 46006300 */  add.s     $f12, $f12, $f0
/* 9B756C 80240BEC 3C0141F0 */  lui       $at, 0x41f0
/* 9B7570 80240BF0 44810000 */  mtc1      $at, $f0
/* 9B7574 80240BF4 0C00A6C9 */  jal       clamp_angle
/* 9B7578 80240BF8 46006301 */   sub.s    $f12, $f12, $f0
/* 9B757C 80240BFC E600000C */  swc1      $f0, 0xc($s0)
.L80240C00:
/* 9B7580 80240C00 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9B7584 80240C04 8C420004 */  lw        $v0, 4($v0)
/* 9B7588 80240C08 AE020028 */  sw        $v0, 0x28($s0)
/* 9B758C 80240C0C AE600074 */  sw        $zero, 0x74($s3)
/* 9B7590 80240C10 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9B7594 80240C14 8C420014 */  lw        $v0, 0x14($v0)
/* 9B7598 80240C18 04410004 */  bgez      $v0, .L80240C2C
/* 9B759C 80240C1C 00000000 */   nop
/* 9B75A0 80240C20 C6400000 */  lwc1      $f0, ($s2)
/* 9B75A4 80240C24 08090313 */  j         .L80240C4C
/* 9B75A8 80240C28 E6000018 */   swc1     $f0, 0x18($s0)
.L80240C2C:
/* 9B75AC 80240C2C 3C018024 */  lui       $at, %hi(D_80244880_9BB200)
/* 9B75B0 80240C30 D4224880 */  ldc1      $f2, %lo(D_80244880_9BB200)($at)
/* 9B75B4 80240C34 44820000 */  mtc1      $v0, $f0
/* 9B75B8 80240C38 00000000 */  nop
/* 9B75BC 80240C3C 46800021 */  cvt.d.w   $f0, $f0
/* 9B75C0 80240C40 46220003 */  div.d     $f0, $f0, $f2
/* 9B75C4 80240C44 46200020 */  cvt.s.d   $f0, $f0
/* 9B75C8 80240C48 E6000018 */  swc1      $f0, 0x18($s0)
.L80240C4C:
/* 9B75CC 80240C4C C600003C */  lwc1      $f0, 0x3c($s0)
/* 9B75D0 80240C50 3C014059 */  lui       $at, 0x4059
/* 9B75D4 80240C54 44811800 */  mtc1      $at, $f3
/* 9B75D8 80240C58 44801000 */  mtc1      $zero, $f2
/* 9B75DC 80240C5C 46000021 */  cvt.d.s   $f0, $f0
/* 9B75E0 80240C60 46220002 */  mul.d     $f0, $f0, $f2
/* 9B75E4 80240C64 00000000 */  nop
/* 9B75E8 80240C68 24020001 */  addiu     $v0, $zero, 1
/* 9B75EC 80240C6C 4620018D */  trunc.w.d $f6, $f0
/* 9B75F0 80240C70 E626007C */  swc1      $f6, 0x7c($s1)
/* 9B75F4 80240C74 AE620070 */  sw        $v0, 0x70($s3)
/* 9B75F8 80240C78 8FBF0030 */  lw        $ra, 0x30($sp)
/* 9B75FC 80240C7C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 9B7600 80240C80 8FB20028 */  lw        $s2, 0x28($sp)
/* 9B7604 80240C84 8FB10024 */  lw        $s1, 0x24($sp)
/* 9B7608 80240C88 8FB00020 */  lw        $s0, 0x20($sp)
/* 9B760C 80240C8C 03E00008 */  jr        $ra
/* 9B7610 80240C90 27BD0038 */   addiu    $sp, $sp, 0x38
