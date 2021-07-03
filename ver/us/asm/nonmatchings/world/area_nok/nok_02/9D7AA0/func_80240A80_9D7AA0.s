.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80254620_9EB640
.double 32767.0

.section .text

glabel func_80240A80_9D7AA0
/* 9D7AA0 80240A80 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D7AA4 80240A84 AFB50024 */  sw        $s5, 0x24($sp)
/* 9D7AA8 80240A88 0080A82D */  daddu     $s5, $a0, $zero
/* 9D7AAC 80240A8C AFBF002C */  sw        $ra, 0x2c($sp)
/* 9D7AB0 80240A90 AFB60028 */  sw        $s6, 0x28($sp)
/* 9D7AB4 80240A94 AFB40020 */  sw        $s4, 0x20($sp)
/* 9D7AB8 80240A98 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9D7ABC 80240A9C AFB20018 */  sw        $s2, 0x18($sp)
/* 9D7AC0 80240AA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D7AC4 80240AA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D7AC8 80240AA8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 9D7ACC 80240AAC F7B60038 */  sdc1      $f22, 0x38($sp)
/* 9D7AD0 80240AB0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 9D7AD4 80240AB4 8EB30148 */  lw        $s3, 0x148($s5)
/* 9D7AD8 80240AB8 86640008 */  lh        $a0, 8($s3)
/* 9D7ADC 80240ABC 0C00EABB */  jal       get_npc_unsafe
/* 9D7AE0 80240AC0 00A0B02D */   daddu    $s6, $a1, $zero
/* 9D7AE4 80240AC4 0040A02D */  daddu     $s4, $v0, $zero
/* 9D7AE8 80240AC8 AEA00074 */  sw        $zero, 0x74($s5)
/* 9D7AEC 80240ACC C6980038 */  lwc1      $f24, 0x38($s4)
/* 9D7AF0 80240AD0 C6960040 */  lwc1      $f22, 0x40($s4)
/* 9D7AF4 80240AD4 0000902D */  daddu     $s2, $zero, $zero
/* 9D7AF8 80240AD8 AEA00078 */  sw        $zero, 0x78($s5)
/* 9D7AFC 80240ADC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* 9D7B00 80240AE0 8C620000 */  lw        $v0, ($v1)
/* 9D7B04 80240AE4 3C0146FF */  lui       $at, 0x46ff
/* 9D7B08 80240AE8 3421FE00 */  ori       $at, $at, 0xfe00
/* 9D7B0C 80240AEC 4481A000 */  mtc1      $at, $f20
/* 9D7B10 80240AF0 18400018 */  blez      $v0, .L80240B54
/* 9D7B14 80240AF4 0240802D */   daddu    $s0, $s2, $zero
/* 9D7B18 80240AF8 0240882D */  daddu     $s1, $s2, $zero
.L80240AFC:
/* 9D7B1C 80240AFC 02231021 */  addu      $v0, $s1, $v1
/* 9D7B20 80240B00 4600C306 */  mov.s     $f12, $f24
/* 9D7B24 80240B04 C4440004 */  lwc1      $f4, 4($v0)
/* 9D7B28 80240B08 46802120 */  cvt.s.w   $f4, $f4
/* 9D7B2C 80240B0C 44062000 */  mfc1      $a2, $f4
/* 9D7B30 80240B10 C444000C */  lwc1      $f4, 0xc($v0)
/* 9D7B34 80240B14 46802120 */  cvt.s.w   $f4, $f4
/* 9D7B38 80240B18 44072000 */  mfc1      $a3, $f4
/* 9D7B3C 80240B1C 0C00A7B5 */  jal       dist2D
/* 9D7B40 80240B20 4600B386 */   mov.s    $f14, $f22
/* 9D7B44 80240B24 4614003C */  c.lt.s    $f0, $f20
/* 9D7B48 80240B28 00000000 */  nop
/* 9D7B4C 80240B2C 45000003 */  bc1f      .L80240B3C
/* 9D7B50 80240B30 2631000C */   addiu    $s1, $s1, 0xc
/* 9D7B54 80240B34 46000506 */  mov.s     $f20, $f0
/* 9D7B58 80240B38 AEB20078 */  sw        $s2, 0x78($s5)
.L80240B3C:
/* 9D7B5C 80240B3C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* 9D7B60 80240B40 26100001 */  addiu     $s0, $s0, 1
/* 9D7B64 80240B44 8C620000 */  lw        $v0, ($v1)
/* 9D7B68 80240B48 0202102A */  slt       $v0, $s0, $v0
/* 9D7B6C 80240B4C 1440FFEB */  bnez      $v0, .L80240AFC
/* 9D7B70 80240B50 26520001 */   addiu    $s2, $s2, 1
.L80240B54:
/* 9D7B74 80240B54 8E6200CC */  lw        $v0, 0xcc($s3)
/* 9D7B78 80240B58 8C420004 */  lw        $v0, 4($v0)
/* 9D7B7C 80240B5C AE820028 */  sw        $v0, 0x28($s4)
/* 9D7B80 80240B60 8E6200D0 */  lw        $v0, 0xd0($s3)
/* 9D7B84 80240B64 8C42007C */  lw        $v0, 0x7c($v0)
/* 9D7B88 80240B68 04410004 */  bgez      $v0, .L80240B7C
/* 9D7B8C 80240B6C 00000000 */   nop
/* 9D7B90 80240B70 C6C00000 */  lwc1      $f0, ($s6)
/* 9D7B94 80240B74 080902E7 */  j         .L80240B9C
/* 9D7B98 80240B78 E6800018 */   swc1     $f0, 0x18($s4)
.L80240B7C:
/* 9D7B9C 80240B7C 3C018025 */  lui       $at, %hi(D_80254620_9EB640)
/* 9D7BA0 80240B80 D4224620 */  ldc1      $f2, %lo(D_80254620_9EB640)($at)
/* 9D7BA4 80240B84 44820000 */  mtc1      $v0, $f0
/* 9D7BA8 80240B88 00000000 */  nop
/* 9D7BAC 80240B8C 46800021 */  cvt.d.w   $f0, $f0
/* 9D7BB0 80240B90 46220003 */  div.d     $f0, $f0, $f2
/* 9D7BB4 80240B94 46200020 */  cvt.s.d   $f0, $f0
/* 9D7BB8 80240B98 E6800018 */  swc1      $f0, 0x18($s4)
.L80240B9C:
/* 9D7BBC 80240B9C 24020001 */  addiu     $v0, $zero, 1
/* 9D7BC0 80240BA0 AEA20070 */  sw        $v0, 0x70($s5)
/* 9D7BC4 80240BA4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 9D7BC8 80240BA8 8FB60028 */  lw        $s6, 0x28($sp)
/* 9D7BCC 80240BAC 8FB50024 */  lw        $s5, 0x24($sp)
/* 9D7BD0 80240BB0 8FB40020 */  lw        $s4, 0x20($sp)
/* 9D7BD4 80240BB4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9D7BD8 80240BB8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D7BDC 80240BBC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D7BE0 80240BC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D7BE4 80240BC4 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 9D7BE8 80240BC8 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 9D7BEC 80240BCC D7B40030 */  ldc1      $f20, 0x30($sp)
/* 9D7BF0 80240BD0 03E00008 */  jr        $ra
/* 9D7BF4 80240BD4 27BD0048 */   addiu    $sp, $sp, 0x48
