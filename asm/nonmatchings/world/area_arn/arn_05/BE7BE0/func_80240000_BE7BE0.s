.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BE7BE0
/* BE7BE0 80240000 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE7BE4 80240004 AFB50024 */  sw        $s5, 0x24($sp)
/* BE7BE8 80240008 0080A82D */  daddu     $s5, $a0, $zero
/* BE7BEC 8024000C AFBF002C */  sw        $ra, 0x2c($sp)
/* BE7BF0 80240010 AFB60028 */  sw        $s6, 0x28($sp)
/* BE7BF4 80240014 AFB40020 */  sw        $s4, 0x20($sp)
/* BE7BF8 80240018 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE7BFC 8024001C AFB20018 */  sw        $s2, 0x18($sp)
/* BE7C00 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* BE7C04 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* BE7C08 80240028 F7B80040 */  sdc1      $f24, 0x40($sp)
/* BE7C0C 8024002C F7B60038 */  sdc1      $f22, 0x38($sp)
/* BE7C10 80240030 F7B40030 */  sdc1      $f20, 0x30($sp)
/* BE7C14 80240034 8EB30148 */  lw        $s3, 0x148($s5)
/* BE7C18 80240038 86640008 */  lh        $a0, 8($s3)
/* BE7C1C 8024003C 0C00EABB */  jal       get_npc_unsafe
/* BE7C20 80240040 00A0B02D */   daddu    $s6, $a1, $zero
/* BE7C24 80240044 0040A02D */  daddu     $s4, $v0, $zero
/* BE7C28 80240048 AEA00074 */  sw        $zero, 0x74($s5)
/* BE7C2C 8024004C C6980038 */  lwc1      $f24, 0x38($s4)
/* BE7C30 80240050 C6960040 */  lwc1      $f22, 0x40($s4)
/* BE7C34 80240054 0000902D */  daddu     $s2, $zero, $zero
/* BE7C38 80240058 AEA00078 */  sw        $zero, 0x78($s5)
/* BE7C3C 8024005C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE7C40 80240060 8C620000 */  lw        $v0, ($v1)
/* BE7C44 80240064 3C0146FF */  lui       $at, 0x46ff
/* BE7C48 80240068 3421FE00 */  ori       $at, $at, 0xfe00
/* BE7C4C 8024006C 4481A000 */  mtc1      $at, $f20
/* BE7C50 80240070 18400018 */  blez      $v0, .L802400D4
/* BE7C54 80240074 0240802D */   daddu    $s0, $s2, $zero
/* BE7C58 80240078 0240882D */  daddu     $s1, $s2, $zero
.L8024007C:
/* BE7C5C 8024007C 02231021 */  addu      $v0, $s1, $v1
/* BE7C60 80240080 4600C306 */  mov.s     $f12, $f24
/* BE7C64 80240084 C4440004 */  lwc1      $f4, 4($v0)
/* BE7C68 80240088 46802120 */  cvt.s.w   $f4, $f4
/* BE7C6C 8024008C 44062000 */  mfc1      $a2, $f4
/* BE7C70 80240090 C444000C */  lwc1      $f4, 0xc($v0)
/* BE7C74 80240094 46802120 */  cvt.s.w   $f4, $f4
/* BE7C78 80240098 44072000 */  mfc1      $a3, $f4
/* BE7C7C 8024009C 0C00A7B5 */  jal       dist2D
/* BE7C80 802400A0 4600B386 */   mov.s    $f14, $f22
/* BE7C84 802400A4 4614003C */  c.lt.s    $f0, $f20
/* BE7C88 802400A8 00000000 */  nop
/* BE7C8C 802400AC 45000003 */  bc1f      .L802400BC
/* BE7C90 802400B0 2631000C */   addiu    $s1, $s1, 0xc
/* BE7C94 802400B4 46000506 */  mov.s     $f20, $f0
/* BE7C98 802400B8 AEB20078 */  sw        $s2, 0x78($s5)
.L802400BC:
/* BE7C9C 802400BC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE7CA0 802400C0 26100001 */  addiu     $s0, $s0, 1
/* BE7CA4 802400C4 8C620000 */  lw        $v0, ($v1)
/* BE7CA8 802400C8 0202102A */  slt       $v0, $s0, $v0
/* BE7CAC 802400CC 1440FFEB */  bnez      $v0, .L8024007C
/* BE7CB0 802400D0 26520001 */   addiu    $s2, $s2, 1
.L802400D4:
/* BE7CB4 802400D4 8E6200CC */  lw        $v0, 0xcc($s3)
/* BE7CB8 802400D8 8C420004 */  lw        $v0, 4($v0)
/* BE7CBC 802400DC AE820028 */  sw        $v0, 0x28($s4)
/* BE7CC0 802400E0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BE7CC4 802400E4 8C42007C */  lw        $v0, 0x7c($v0)
/* BE7CC8 802400E8 04410004 */  bgez      $v0, .L802400FC
/* BE7CCC 802400EC 00000000 */   nop
/* BE7CD0 802400F0 C6C00000 */  lwc1      $f0, ($s6)
/* BE7CD4 802400F4 08090047 */  j         .L8024011C
/* BE7CD8 802400F8 E6800018 */   swc1     $f0, 0x18($s4)
.L802400FC:
/* BE7CDC 802400FC 3C018024 */  lui       $at, %hi(D_80245050_BECC30)
/* BE7CE0 80240100 D4225050 */  ldc1      $f2, %lo(D_80245050_BECC30)($at)
/* BE7CE4 80240104 44820000 */  mtc1      $v0, $f0
/* BE7CE8 80240108 00000000 */  nop
/* BE7CEC 8024010C 46800021 */  cvt.d.w   $f0, $f0
/* BE7CF0 80240110 46220003 */  div.d     $f0, $f0, $f2
/* BE7CF4 80240114 46200020 */  cvt.s.d   $f0, $f0
/* BE7CF8 80240118 E6800018 */  swc1      $f0, 0x18($s4)
.L8024011C:
/* BE7CFC 8024011C 24020001 */  addiu     $v0, $zero, 1
/* BE7D00 80240120 AEA20070 */  sw        $v0, 0x70($s5)
/* BE7D04 80240124 8FBF002C */  lw        $ra, 0x2c($sp)
/* BE7D08 80240128 8FB60028 */  lw        $s6, 0x28($sp)
/* BE7D0C 8024012C 8FB50024 */  lw        $s5, 0x24($sp)
/* BE7D10 80240130 8FB40020 */  lw        $s4, 0x20($sp)
/* BE7D14 80240134 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE7D18 80240138 8FB20018 */  lw        $s2, 0x18($sp)
/* BE7D1C 8024013C 8FB10014 */  lw        $s1, 0x14($sp)
/* BE7D20 80240140 8FB00010 */  lw        $s0, 0x10($sp)
/* BE7D24 80240144 D7B80040 */  ldc1      $f24, 0x40($sp)
/* BE7D28 80240148 D7B60038 */  ldc1      $f22, 0x38($sp)
/* BE7D2C 8024014C D7B40030 */  ldc1      $f20, 0x30($sp)
/* BE7D30 80240150 03E00008 */  jr        $ra
/* BE7D34 80240154 27BD0048 */   addiu    $sp, $sp, 0x48
