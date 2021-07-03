.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245F40_9AE330
.double 32767.0

.section .text

glabel func_80240C84_9A9074
/* 9A9074 80240C84 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9A9078 80240C88 AFB50024 */  sw        $s5, 0x24($sp)
/* 9A907C 80240C8C 0080A82D */  daddu     $s5, $a0, $zero
/* 9A9080 80240C90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 9A9084 80240C94 AFB60028 */  sw        $s6, 0x28($sp)
/* 9A9088 80240C98 AFB40020 */  sw        $s4, 0x20($sp)
/* 9A908C 80240C9C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9A9090 80240CA0 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A9094 80240CA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A9098 80240CA8 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A909C 80240CAC F7B80040 */  sdc1      $f24, 0x40($sp)
/* 9A90A0 80240CB0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 9A90A4 80240CB4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 9A90A8 80240CB8 8EB30148 */  lw        $s3, 0x148($s5)
/* 9A90AC 80240CBC 86640008 */  lh        $a0, 8($s3)
/* 9A90B0 80240CC0 0C00EABB */  jal       get_npc_unsafe
/* 9A90B4 80240CC4 00A0B02D */   daddu    $s6, $a1, $zero
/* 9A90B8 80240CC8 0040A02D */  daddu     $s4, $v0, $zero
/* 9A90BC 80240CCC AEA00074 */  sw        $zero, 0x74($s5)
/* 9A90C0 80240CD0 C6980038 */  lwc1      $f24, 0x38($s4)
/* 9A90C4 80240CD4 C6960040 */  lwc1      $f22, 0x40($s4)
/* 9A90C8 80240CD8 0000902D */  daddu     $s2, $zero, $zero
/* 9A90CC 80240CDC AEA00078 */  sw        $zero, 0x78($s5)
/* 9A90D0 80240CE0 8E6300D0 */  lw        $v1, 0xd0($s3)
/* 9A90D4 80240CE4 8C620000 */  lw        $v0, ($v1)
/* 9A90D8 80240CE8 3C0146FF */  lui       $at, 0x46ff
/* 9A90DC 80240CEC 3421FE00 */  ori       $at, $at, 0xfe00
/* 9A90E0 80240CF0 4481A000 */  mtc1      $at, $f20
/* 9A90E4 80240CF4 18400018 */  blez      $v0, .L80240D58
/* 9A90E8 80240CF8 0240802D */   daddu    $s0, $s2, $zero
/* 9A90EC 80240CFC 0240882D */  daddu     $s1, $s2, $zero
.L80240D00:
/* 9A90F0 80240D00 02231021 */  addu      $v0, $s1, $v1
/* 9A90F4 80240D04 4600C306 */  mov.s     $f12, $f24
/* 9A90F8 80240D08 C4440004 */  lwc1      $f4, 4($v0)
/* 9A90FC 80240D0C 46802120 */  cvt.s.w   $f4, $f4
/* 9A9100 80240D10 44062000 */  mfc1      $a2, $f4
/* 9A9104 80240D14 C444000C */  lwc1      $f4, 0xc($v0)
/* 9A9108 80240D18 46802120 */  cvt.s.w   $f4, $f4
/* 9A910C 80240D1C 44072000 */  mfc1      $a3, $f4
/* 9A9110 80240D20 0C00A7B5 */  jal       dist2D
/* 9A9114 80240D24 4600B386 */   mov.s    $f14, $f22
/* 9A9118 80240D28 4614003C */  c.lt.s    $f0, $f20
/* 9A911C 80240D2C 00000000 */  nop
/* 9A9120 80240D30 45000003 */  bc1f      .L80240D40
/* 9A9124 80240D34 2631000C */   addiu    $s1, $s1, 0xc
/* 9A9128 80240D38 46000506 */  mov.s     $f20, $f0
/* 9A912C 80240D3C AEB20078 */  sw        $s2, 0x78($s5)
.L80240D40:
/* 9A9130 80240D40 8E6300D0 */  lw        $v1, 0xd0($s3)
/* 9A9134 80240D44 26100001 */  addiu     $s0, $s0, 1
/* 9A9138 80240D48 8C620000 */  lw        $v0, ($v1)
/* 9A913C 80240D4C 0202102A */  slt       $v0, $s0, $v0
/* 9A9140 80240D50 1440FFEB */  bnez      $v0, .L80240D00
/* 9A9144 80240D54 26520001 */   addiu    $s2, $s2, 1
.L80240D58:
/* 9A9148 80240D58 8E6200CC */  lw        $v0, 0xcc($s3)
/* 9A914C 80240D5C 8C420004 */  lw        $v0, 4($v0)
/* 9A9150 80240D60 AE820028 */  sw        $v0, 0x28($s4)
/* 9A9154 80240D64 8E6200D0 */  lw        $v0, 0xd0($s3)
/* 9A9158 80240D68 8C42007C */  lw        $v0, 0x7c($v0)
/* 9A915C 80240D6C 04410004 */  bgez      $v0, .L80240D80
/* 9A9160 80240D70 00000000 */   nop
/* 9A9164 80240D74 C6C00000 */  lwc1      $f0, ($s6)
/* 9A9168 80240D78 08090368 */  j         .L80240DA0
/* 9A916C 80240D7C E6800018 */   swc1     $f0, 0x18($s4)
.L80240D80:
/* 9A9170 80240D80 3C018024 */  lui       $at, %hi(D_80245F40_9AE330)
/* 9A9174 80240D84 D4225F40 */  ldc1      $f2, %lo(D_80245F40_9AE330)($at)
/* 9A9178 80240D88 44820000 */  mtc1      $v0, $f0
/* 9A917C 80240D8C 00000000 */  nop
/* 9A9180 80240D90 46800021 */  cvt.d.w   $f0, $f0
/* 9A9184 80240D94 46220003 */  div.d     $f0, $f0, $f2
/* 9A9188 80240D98 46200020 */  cvt.s.d   $f0, $f0
/* 9A918C 80240D9C E6800018 */  swc1      $f0, 0x18($s4)
.L80240DA0:
/* 9A9190 80240DA0 24020001 */  addiu     $v0, $zero, 1
/* 9A9194 80240DA4 AEA20070 */  sw        $v0, 0x70($s5)
/* 9A9198 80240DA8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 9A919C 80240DAC 8FB60028 */  lw        $s6, 0x28($sp)
/* 9A91A0 80240DB0 8FB50024 */  lw        $s5, 0x24($sp)
/* 9A91A4 80240DB4 8FB40020 */  lw        $s4, 0x20($sp)
/* 9A91A8 80240DB8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9A91AC 80240DBC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A91B0 80240DC0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A91B4 80240DC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A91B8 80240DC8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 9A91BC 80240DCC D7B60038 */  ldc1      $f22, 0x38($sp)
/* 9A91C0 80240DD0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 9A91C4 80240DD4 03E00008 */  jr        $ra
/* 9A91C8 80240DD8 27BD0048 */   addiu    $sp, $sp, 0x48
