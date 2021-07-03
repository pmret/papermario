.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243A10_AC8B80
.double 32767.0

.section .text

glabel func_80240000_AC5170
/* AC5170 80240000 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AC5174 80240004 AFB50024 */  sw        $s5, 0x24($sp)
/* AC5178 80240008 0080A82D */  daddu     $s5, $a0, $zero
/* AC517C 8024000C AFBF002C */  sw        $ra, 0x2c($sp)
/* AC5180 80240010 AFB60028 */  sw        $s6, 0x28($sp)
/* AC5184 80240014 AFB40020 */  sw        $s4, 0x20($sp)
/* AC5188 80240018 AFB3001C */  sw        $s3, 0x1c($sp)
/* AC518C 8024001C AFB20018 */  sw        $s2, 0x18($sp)
/* AC5190 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* AC5194 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* AC5198 80240028 F7B80040 */  sdc1      $f24, 0x40($sp)
/* AC519C 8024002C F7B60038 */  sdc1      $f22, 0x38($sp)
/* AC51A0 80240030 F7B40030 */  sdc1      $f20, 0x30($sp)
/* AC51A4 80240034 8EB30148 */  lw        $s3, 0x148($s5)
/* AC51A8 80240038 86640008 */  lh        $a0, 8($s3)
/* AC51AC 8024003C 0C00EABB */  jal       get_npc_unsafe
/* AC51B0 80240040 00A0B02D */   daddu    $s6, $a1, $zero
/* AC51B4 80240044 0040A02D */  daddu     $s4, $v0, $zero
/* AC51B8 80240048 AEA00074 */  sw        $zero, 0x74($s5)
/* AC51BC 8024004C C6980038 */  lwc1      $f24, 0x38($s4)
/* AC51C0 80240050 C6960040 */  lwc1      $f22, 0x40($s4)
/* AC51C4 80240054 0000902D */  daddu     $s2, $zero, $zero
/* AC51C8 80240058 AEA00078 */  sw        $zero, 0x78($s5)
/* AC51CC 8024005C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* AC51D0 80240060 8C620000 */  lw        $v0, ($v1)
/* AC51D4 80240064 3C0146FF */  lui       $at, 0x46ff
/* AC51D8 80240068 3421FE00 */  ori       $at, $at, 0xfe00
/* AC51DC 8024006C 4481A000 */  mtc1      $at, $f20
/* AC51E0 80240070 18400018 */  blez      $v0, .L802400D4
/* AC51E4 80240074 0240802D */   daddu    $s0, $s2, $zero
/* AC51E8 80240078 0240882D */  daddu     $s1, $s2, $zero
.L8024007C:
/* AC51EC 8024007C 02231021 */  addu      $v0, $s1, $v1
/* AC51F0 80240080 4600C306 */  mov.s     $f12, $f24
/* AC51F4 80240084 C4440004 */  lwc1      $f4, 4($v0)
/* AC51F8 80240088 46802120 */  cvt.s.w   $f4, $f4
/* AC51FC 8024008C 44062000 */  mfc1      $a2, $f4
/* AC5200 80240090 C444000C */  lwc1      $f4, 0xc($v0)
/* AC5204 80240094 46802120 */  cvt.s.w   $f4, $f4
/* AC5208 80240098 44072000 */  mfc1      $a3, $f4
/* AC520C 8024009C 0C00A7B5 */  jal       dist2D
/* AC5210 802400A0 4600B386 */   mov.s    $f14, $f22
/* AC5214 802400A4 4614003C */  c.lt.s    $f0, $f20
/* AC5218 802400A8 00000000 */  nop
/* AC521C 802400AC 45000003 */  bc1f      .L802400BC
/* AC5220 802400B0 2631000C */   addiu    $s1, $s1, 0xc
/* AC5224 802400B4 46000506 */  mov.s     $f20, $f0
/* AC5228 802400B8 AEB20078 */  sw        $s2, 0x78($s5)
.L802400BC:
/* AC522C 802400BC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* AC5230 802400C0 26100001 */  addiu     $s0, $s0, 1
/* AC5234 802400C4 8C620000 */  lw        $v0, ($v1)
/* AC5238 802400C8 0202102A */  slt       $v0, $s0, $v0
/* AC523C 802400CC 1440FFEB */  bnez      $v0, .L8024007C
/* AC5240 802400D0 26520001 */   addiu    $s2, $s2, 1
.L802400D4:
/* AC5244 802400D4 8E6200CC */  lw        $v0, 0xcc($s3)
/* AC5248 802400D8 8C420004 */  lw        $v0, 4($v0)
/* AC524C 802400DC AE820028 */  sw        $v0, 0x28($s4)
/* AC5250 802400E0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* AC5254 802400E4 8C42007C */  lw        $v0, 0x7c($v0)
/* AC5258 802400E8 04410004 */  bgez      $v0, .L802400FC
/* AC525C 802400EC 00000000 */   nop
/* AC5260 802400F0 C6C00000 */  lwc1      $f0, ($s6)
/* AC5264 802400F4 08090047 */  j         .L8024011C
/* AC5268 802400F8 E6800018 */   swc1     $f0, 0x18($s4)
.L802400FC:
/* AC526C 802400FC 3C018024 */  lui       $at, %hi(D_80243A10_AC8B80)
/* AC5270 80240100 D4223A10 */  ldc1      $f2, %lo(D_80243A10_AC8B80)($at)
/* AC5274 80240104 44820000 */  mtc1      $v0, $f0
/* AC5278 80240108 00000000 */  nop
/* AC527C 8024010C 46800021 */  cvt.d.w   $f0, $f0
/* AC5280 80240110 46220003 */  div.d     $f0, $f0, $f2
/* AC5284 80240114 46200020 */  cvt.s.d   $f0, $f0
/* AC5288 80240118 E6800018 */  swc1      $f0, 0x18($s4)
.L8024011C:
/* AC528C 8024011C 24020001 */  addiu     $v0, $zero, 1
/* AC5290 80240120 AEA20070 */  sw        $v0, 0x70($s5)
/* AC5294 80240124 8FBF002C */  lw        $ra, 0x2c($sp)
/* AC5298 80240128 8FB60028 */  lw        $s6, 0x28($sp)
/* AC529C 8024012C 8FB50024 */  lw        $s5, 0x24($sp)
/* AC52A0 80240130 8FB40020 */  lw        $s4, 0x20($sp)
/* AC52A4 80240134 8FB3001C */  lw        $s3, 0x1c($sp)
/* AC52A8 80240138 8FB20018 */  lw        $s2, 0x18($sp)
/* AC52AC 8024013C 8FB10014 */  lw        $s1, 0x14($sp)
/* AC52B0 80240140 8FB00010 */  lw        $s0, 0x10($sp)
/* AC52B4 80240144 D7B80040 */  ldc1      $f24, 0x40($sp)
/* AC52B8 80240148 D7B60038 */  ldc1      $f22, 0x38($sp)
/* AC52BC 8024014C D7B40030 */  ldc1      $f20, 0x30($sp)
/* AC52C0 80240150 03E00008 */  jr        $ra
/* AC52C4 80240154 27BD0048 */   addiu    $sp, $sp, 0x48
