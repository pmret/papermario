.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_C9DF60
/* C9DF60 80240040 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C9DF64 80240044 AFB50024 */  sw        $s5, 0x24($sp)
/* C9DF68 80240048 0080A82D */  daddu     $s5, $a0, $zero
/* C9DF6C 8024004C AFBF002C */  sw        $ra, 0x2c($sp)
/* C9DF70 80240050 AFB60028 */  sw        $s6, 0x28($sp)
/* C9DF74 80240054 AFB40020 */  sw        $s4, 0x20($sp)
/* C9DF78 80240058 AFB3001C */  sw        $s3, 0x1c($sp)
/* C9DF7C 8024005C AFB20018 */  sw        $s2, 0x18($sp)
/* C9DF80 80240060 AFB10014 */  sw        $s1, 0x14($sp)
/* C9DF84 80240064 AFB00010 */  sw        $s0, 0x10($sp)
/* C9DF88 80240068 F7B80040 */  sdc1      $f24, 0x40($sp)
/* C9DF8C 8024006C F7B60038 */  sdc1      $f22, 0x38($sp)
/* C9DF90 80240070 F7B40030 */  sdc1      $f20, 0x30($sp)
/* C9DF94 80240074 8EB30148 */  lw        $s3, 0x148($s5)
/* C9DF98 80240078 86640008 */  lh        $a0, 8($s3)
/* C9DF9C 8024007C 0C00EABB */  jal       get_npc_unsafe
/* C9DFA0 80240080 00A0B02D */   daddu    $s6, $a1, $zero
/* C9DFA4 80240084 0040A02D */  daddu     $s4, $v0, $zero
/* C9DFA8 80240088 AEA00074 */  sw        $zero, 0x74($s5)
/* C9DFAC 8024008C C6980038 */  lwc1      $f24, 0x38($s4)
/* C9DFB0 80240090 C6960040 */  lwc1      $f22, 0x40($s4)
/* C9DFB4 80240094 0000902D */  daddu     $s2, $zero, $zero
/* C9DFB8 80240098 AEA00078 */  sw        $zero, 0x78($s5)
/* C9DFBC 8024009C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* C9DFC0 802400A0 8C620000 */  lw        $v0, ($v1)
/* C9DFC4 802400A4 3C0146FF */  lui       $at, 0x46ff
/* C9DFC8 802400A8 3421FE00 */  ori       $at, $at, 0xfe00
/* C9DFCC 802400AC 4481A000 */  mtc1      $at, $f20
/* C9DFD0 802400B0 18400018 */  blez      $v0, .L80240114
/* C9DFD4 802400B4 0240802D */   daddu    $s0, $s2, $zero
/* C9DFD8 802400B8 0240882D */  daddu     $s1, $s2, $zero
.L802400BC:
/* C9DFDC 802400BC 02231021 */  addu      $v0, $s1, $v1
/* C9DFE0 802400C0 4600C306 */  mov.s     $f12, $f24
/* C9DFE4 802400C4 C4440004 */  lwc1      $f4, 4($v0)
/* C9DFE8 802400C8 46802120 */  cvt.s.w   $f4, $f4
/* C9DFEC 802400CC 44062000 */  mfc1      $a2, $f4
/* C9DFF0 802400D0 C444000C */  lwc1      $f4, 0xc($v0)
/* C9DFF4 802400D4 46802120 */  cvt.s.w   $f4, $f4
/* C9DFF8 802400D8 44072000 */  mfc1      $a3, $f4
/* C9DFFC 802400DC 0C00A7B5 */  jal       dist2D
/* C9E000 802400E0 4600B386 */   mov.s    $f14, $f22
/* C9E004 802400E4 4614003C */  c.lt.s    $f0, $f20
/* C9E008 802400E8 00000000 */  nop
/* C9E00C 802400EC 45000003 */  bc1f      .L802400FC
/* C9E010 802400F0 2631000C */   addiu    $s1, $s1, 0xc
/* C9E014 802400F4 46000506 */  mov.s     $f20, $f0
/* C9E018 802400F8 AEB20078 */  sw        $s2, 0x78($s5)
.L802400FC:
/* C9E01C 802400FC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* C9E020 80240100 26100001 */  addiu     $s0, $s0, 1
/* C9E024 80240104 8C620000 */  lw        $v0, ($v1)
/* C9E028 80240108 0202102A */  slt       $v0, $s0, $v0
/* C9E02C 8024010C 1440FFEB */  bnez      $v0, .L802400BC
/* C9E030 80240110 26520001 */   addiu    $s2, $s2, 1
.L80240114:
/* C9E034 80240114 8E6200CC */  lw        $v0, 0xcc($s3)
/* C9E038 80240118 8C420004 */  lw        $v0, 4($v0)
/* C9E03C 8024011C AE820028 */  sw        $v0, 0x28($s4)
/* C9E040 80240120 8E6200D0 */  lw        $v0, 0xd0($s3)
/* C9E044 80240124 8C42007C */  lw        $v0, 0x7c($v0)
/* C9E048 80240128 04410004 */  bgez      $v0, .L8024013C
/* C9E04C 8024012C 00000000 */   nop
/* C9E050 80240130 C6C00000 */  lwc1      $f0, ($s6)
/* C9E054 80240134 08090057 */  j         .L8024015C
/* C9E058 80240138 E6800018 */   swc1     $f0, 0x18($s4)
.L8024013C:
/* C9E05C 8024013C 3C018025 */  lui       $at, %hi(D_802491C0_CA70E0)
/* C9E060 80240140 D42291C0 */  ldc1      $f2, %lo(D_802491C0_CA70E0)($at)
/* C9E064 80240144 44820000 */  mtc1      $v0, $f0
/* C9E068 80240148 00000000 */  nop
/* C9E06C 8024014C 46800021 */  cvt.d.w   $f0, $f0
/* C9E070 80240150 46220003 */  div.d     $f0, $f0, $f2
/* C9E074 80240154 46200020 */  cvt.s.d   $f0, $f0
/* C9E078 80240158 E6800018 */  swc1      $f0, 0x18($s4)
.L8024015C:
/* C9E07C 8024015C 24020001 */  addiu     $v0, $zero, 1
/* C9E080 80240160 AEA20070 */  sw        $v0, 0x70($s5)
/* C9E084 80240164 8FBF002C */  lw        $ra, 0x2c($sp)
/* C9E088 80240168 8FB60028 */  lw        $s6, 0x28($sp)
/* C9E08C 8024016C 8FB50024 */  lw        $s5, 0x24($sp)
/* C9E090 80240170 8FB40020 */  lw        $s4, 0x20($sp)
/* C9E094 80240174 8FB3001C */  lw        $s3, 0x1c($sp)
/* C9E098 80240178 8FB20018 */  lw        $s2, 0x18($sp)
/* C9E09C 8024017C 8FB10014 */  lw        $s1, 0x14($sp)
/* C9E0A0 80240180 8FB00010 */  lw        $s0, 0x10($sp)
/* C9E0A4 80240184 D7B80040 */  ldc1      $f24, 0x40($sp)
/* C9E0A8 80240188 D7B60038 */  ldc1      $f22, 0x38($sp)
/* C9E0AC 8024018C D7B40030 */  ldc1      $f20, 0x30($sp)
/* C9E0B0 80240190 03E00008 */  jr        $ra
/* C9E0B4 80240194 27BD0048 */   addiu    $sp, $sp, 0x48
