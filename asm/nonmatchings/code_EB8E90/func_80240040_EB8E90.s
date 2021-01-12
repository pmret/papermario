.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_EB8E90
/* EB8E90 80240040 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EB8E94 80240044 AFB50024 */  sw        $s5, 0x24($sp)
/* EB8E98 80240048 0080A82D */  daddu     $s5, $a0, $zero
/* EB8E9C 8024004C AFBF002C */  sw        $ra, 0x2c($sp)
/* EB8EA0 80240050 AFB60028 */  sw        $s6, 0x28($sp)
/* EB8EA4 80240054 AFB40020 */  sw        $s4, 0x20($sp)
/* EB8EA8 80240058 AFB3001C */  sw        $s3, 0x1c($sp)
/* EB8EAC 8024005C AFB20018 */  sw        $s2, 0x18($sp)
/* EB8EB0 80240060 AFB10014 */  sw        $s1, 0x14($sp)
/* EB8EB4 80240064 AFB00010 */  sw        $s0, 0x10($sp)
/* EB8EB8 80240068 F7B80040 */  sdc1      $f24, 0x40($sp)
/* EB8EBC 8024006C F7B60038 */  sdc1      $f22, 0x38($sp)
/* EB8EC0 80240070 F7B40030 */  sdc1      $f20, 0x30($sp)
/* EB8EC4 80240074 8EB30148 */  lw        $s3, 0x148($s5)
/* EB8EC8 80240078 86640008 */  lh        $a0, 8($s3)
/* EB8ECC 8024007C 0C00F92F */  jal       func_8003E4BC
/* EB8ED0 80240080 00A0B02D */   daddu    $s6, $a1, $zero
/* EB8ED4 80240084 0040A02D */  daddu     $s4, $v0, $zero
/* EB8ED8 80240088 AEA00074 */  sw        $zero, 0x74($s5)
/* EB8EDC 8024008C C6980038 */  lwc1      $f24, 0x38($s4)
/* EB8EE0 80240090 C6960040 */  lwc1      $f22, 0x40($s4)
/* EB8EE4 80240094 0000902D */  daddu     $s2, $zero, $zero
/* EB8EE8 80240098 AEA00078 */  sw        $zero, 0x78($s5)
/* EB8EEC 8024009C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EB8EF0 802400A0 8C620000 */  lw        $v0, ($v1)
/* EB8EF4 802400A4 3C0146FF */  lui       $at, 0x46ff
/* EB8EF8 802400A8 3421FE00 */  ori       $at, $at, 0xfe00
/* EB8EFC 802400AC 4481A000 */  mtc1      $at, $f20
/* EB8F00 802400B0 18400018 */  blez      $v0, .L80240114
/* EB8F04 802400B4 0240802D */   daddu    $s0, $s2, $zero
/* EB8F08 802400B8 0240882D */  daddu     $s1, $s2, $zero
.L802400BC:
/* EB8F0C 802400BC 02231021 */  addu      $v0, $s1, $v1
/* EB8F10 802400C0 4600C306 */  mov.s     $f12, $f24
/* EB8F14 802400C4 C4440004 */  lwc1      $f4, 4($v0)
/* EB8F18 802400C8 46802120 */  cvt.s.w   $f4, $f4
/* EB8F1C 802400CC 44062000 */  mfc1      $a2, $f4
/* EB8F20 802400D0 C444000C */  lwc1      $f4, 0xc($v0)
/* EB8F24 802400D4 46802120 */  cvt.s.w   $f4, $f4
/* EB8F28 802400D8 44072000 */  mfc1      $a3, $f4
/* EB8F2C 802400DC 0C00AC71 */  jal       func_8002B1C4
/* EB8F30 802400E0 4600B386 */   mov.s    $f14, $f22
/* EB8F34 802400E4 4614003C */  c.lt.s    $f0, $f20
/* EB8F38 802400E8 00000000 */  nop       
/* EB8F3C 802400EC 45000003 */  bc1f      .L802400FC
/* EB8F40 802400F0 2631000C */   addiu    $s1, $s1, 0xc
/* EB8F44 802400F4 46000506 */  mov.s     $f20, $f0
/* EB8F48 802400F8 AEB20078 */  sw        $s2, 0x78($s5)
.L802400FC:
/* EB8F4C 802400FC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EB8F50 80240100 26100001 */  addiu     $s0, $s0, 1
/* EB8F54 80240104 8C620000 */  lw        $v0, ($v1)
/* EB8F58 80240108 0202102A */  slt       $v0, $s0, $v0
/* EB8F5C 8024010C 1440FFEB */  bnez      $v0, .L802400BC
/* EB8F60 80240110 26520001 */   addiu    $s2, $s2, 1
.L80240114:
/* EB8F64 80240114 8E6200CC */  lw        $v0, 0xcc($s3)
/* EB8F68 80240118 8C420004 */  lw        $v0, 4($v0)
/* EB8F6C 8024011C AE820028 */  sw        $v0, 0x28($s4)
/* EB8F70 80240120 8E6200D0 */  lw        $v0, 0xd0($s3)
/* EB8F74 80240124 8C42007C */  lw        $v0, 0x7c($v0)
/* EB8F78 80240128 04410004 */  bgez      $v0, .L8024013C
/* EB8F7C 8024012C 00000000 */   nop      
/* EB8F80 80240130 C6C00000 */  lwc1      $f0, ($s6)
/* EB8F84 80240134 08090057 */  j         .L8024015C
/* EB8F88 80240138 E6800018 */   swc1     $f0, 0x18($s4)
.L8024013C:
/* EB8F8C 8024013C 3C018025 */  lui       $at, %hi(D_802491F0)
/* EB8F90 80240140 D42291F0 */  ldc1      $f2, %lo(D_802491F0)($at)
/* EB8F94 80240144 44820000 */  mtc1      $v0, $f0
/* EB8F98 80240148 00000000 */  nop       
/* EB8F9C 8024014C 46800021 */  cvt.d.w   $f0, $f0
/* EB8FA0 80240150 46220003 */  div.d     $f0, $f0, $f2
/* EB8FA4 80240154 46200020 */  cvt.s.d   $f0, $f0
/* EB8FA8 80240158 E6800018 */  swc1      $f0, 0x18($s4)
.L8024015C:
/* EB8FAC 8024015C 24020001 */  addiu     $v0, $zero, 1
/* EB8FB0 80240160 AEA20070 */  sw        $v0, 0x70($s5)
/* EB8FB4 80240164 8FBF002C */  lw        $ra, 0x2c($sp)
/* EB8FB8 80240168 8FB60028 */  lw        $s6, 0x28($sp)
/* EB8FBC 8024016C 8FB50024 */  lw        $s5, 0x24($sp)
/* EB8FC0 80240170 8FB40020 */  lw        $s4, 0x20($sp)
/* EB8FC4 80240174 8FB3001C */  lw        $s3, 0x1c($sp)
/* EB8FC8 80240178 8FB20018 */  lw        $s2, 0x18($sp)
/* EB8FCC 8024017C 8FB10014 */  lw        $s1, 0x14($sp)
/* EB8FD0 80240180 8FB00010 */  lw        $s0, 0x10($sp)
/* EB8FD4 80240184 D7B80040 */  ldc1      $f24, 0x40($sp)
/* EB8FD8 80240188 D7B60038 */  ldc1      $f22, 0x38($sp)
/* EB8FDC 8024018C D7B40030 */  ldc1      $f20, 0x30($sp)
/* EB8FE0 80240190 03E00008 */  jr        $ra
/* EB8FE4 80240194 27BD0048 */   addiu    $sp, $sp, 0x48
