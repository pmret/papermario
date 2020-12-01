.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D8E170
/* D8E170 80240F20 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D8E174 80240F24 AFB50024 */  sw        $s5, 0x24($sp)
/* D8E178 80240F28 0080A82D */  daddu     $s5, $a0, $zero
/* D8E17C 80240F2C AFBF002C */  sw        $ra, 0x2c($sp)
/* D8E180 80240F30 AFB60028 */  sw        $s6, 0x28($sp)
/* D8E184 80240F34 AFB40020 */  sw        $s4, 0x20($sp)
/* D8E188 80240F38 AFB3001C */  sw        $s3, 0x1c($sp)
/* D8E18C 80240F3C AFB20018 */  sw        $s2, 0x18($sp)
/* D8E190 80240F40 AFB10014 */  sw        $s1, 0x14($sp)
/* D8E194 80240F44 AFB00010 */  sw        $s0, 0x10($sp)
/* D8E198 80240F48 F7B80040 */  sdc1      $f24, 0x40($sp)
/* D8E19C 80240F4C F7B60038 */  sdc1      $f22, 0x38($sp)
/* D8E1A0 80240F50 F7B40030 */  sdc1      $f20, 0x30($sp)
/* D8E1A4 80240F54 8EB30148 */  lw        $s3, 0x148($s5)
/* D8E1A8 80240F58 86640008 */  lh        $a0, 8($s3)
/* D8E1AC 80240F5C 0C00EABB */  jal       get_npc_unsafe
/* D8E1B0 80240F60 00A0B02D */   daddu    $s6, $a1, $zero
/* D8E1B4 80240F64 0040A02D */  daddu     $s4, $v0, $zero
/* D8E1B8 80240F68 AEA00074 */  sw        $zero, 0x74($s5)
/* D8E1BC 80240F6C C6980038 */  lwc1      $f24, 0x38($s4)
/* D8E1C0 80240F70 C6960040 */  lwc1      $f22, 0x40($s4)
/* D8E1C4 80240F74 0000902D */  daddu     $s2, $zero, $zero
/* D8E1C8 80240F78 AEA00078 */  sw        $zero, 0x78($s5)
/* D8E1CC 80240F7C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* D8E1D0 80240F80 8C620000 */  lw        $v0, ($v1)
/* D8E1D4 80240F84 3C0146FF */  lui       $at, 0x46ff
/* D8E1D8 80240F88 3421FE00 */  ori       $at, $at, 0xfe00
/* D8E1DC 80240F8C 4481A000 */  mtc1      $at, $f20
/* D8E1E0 80240F90 18400018 */  blez      $v0, .L80240FF4
/* D8E1E4 80240F94 0240802D */   daddu    $s0, $s2, $zero
/* D8E1E8 80240F98 0240882D */  daddu     $s1, $s2, $zero
.L80240F9C:
/* D8E1EC 80240F9C 02231021 */  addu      $v0, $s1, $v1
/* D8E1F0 80240FA0 4600C306 */  mov.s     $f12, $f24
/* D8E1F4 80240FA4 C4440004 */  lwc1      $f4, 4($v0)
/* D8E1F8 80240FA8 46802120 */  cvt.s.w   $f4, $f4
/* D8E1FC 80240FAC 44062000 */  mfc1      $a2, $f4
/* D8E200 80240FB0 C444000C */  lwc1      $f4, 0xc($v0)
/* D8E204 80240FB4 46802120 */  cvt.s.w   $f4, $f4
/* D8E208 80240FB8 44072000 */  mfc1      $a3, $f4
/* D8E20C 80240FBC 0C00A7B5 */  jal       dist2D
/* D8E210 80240FC0 4600B386 */   mov.s    $f14, $f22
/* D8E214 80240FC4 4614003C */  c.lt.s    $f0, $f20
/* D8E218 80240FC8 00000000 */  nop       
/* D8E21C 80240FCC 45000003 */  bc1f      .L80240FDC
/* D8E220 80240FD0 2631000C */   addiu    $s1, $s1, 0xc
/* D8E224 80240FD4 46000506 */  mov.s     $f20, $f0
/* D8E228 80240FD8 AEB20078 */  sw        $s2, 0x78($s5)
.L80240FDC:
/* D8E22C 80240FDC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* D8E230 80240FE0 26100001 */  addiu     $s0, $s0, 1
/* D8E234 80240FE4 8C620000 */  lw        $v0, ($v1)
/* D8E238 80240FE8 0202102A */  slt       $v0, $s0, $v0
/* D8E23C 80240FEC 1440FFEB */  bnez      $v0, .L80240F9C
/* D8E240 80240FF0 26520001 */   addiu    $s2, $s2, 1
.L80240FF4:
/* D8E244 80240FF4 8E6200CC */  lw        $v0, 0xcc($s3)
/* D8E248 80240FF8 8C420004 */  lw        $v0, 4($v0)
/* D8E24C 80240FFC AE820028 */  sw        $v0, 0x28($s4)
/* D8E250 80241000 8E6200D0 */  lw        $v0, 0xd0($s3)
/* D8E254 80241004 8C42007C */  lw        $v0, 0x7c($v0)
/* D8E258 80241008 04410004 */  bgez      $v0, .L8024101C
/* D8E25C 8024100C 00000000 */   nop      
/* D8E260 80241010 C6C00000 */  lwc1      $f0, ($s6)
/* D8E264 80241014 0809040F */  j         .L8024103C
/* D8E268 80241018 E6800018 */   swc1     $f0, 0x18($s4)
.L8024101C:
/* D8E26C 8024101C 3C018024 */  lui       $at, %hi(D_80243FE0)
/* D8E270 80241020 D4223FE0 */  ldc1      $f2, %lo(D_80243FE0)($at)
/* D8E274 80241024 44820000 */  mtc1      $v0, $f0
/* D8E278 80241028 00000000 */  nop       
/* D8E27C 8024102C 46800021 */  cvt.d.w   $f0, $f0
/* D8E280 80241030 46220003 */  div.d     $f0, $f0, $f2
/* D8E284 80241034 46200020 */  cvt.s.d   $f0, $f0
/* D8E288 80241038 E6800018 */  swc1      $f0, 0x18($s4)
.L8024103C:
/* D8E28C 8024103C 24020001 */  addiu     $v0, $zero, 1
/* D8E290 80241040 AEA20070 */  sw        $v0, 0x70($s5)
/* D8E294 80241044 8FBF002C */  lw        $ra, 0x2c($sp)
/* D8E298 80241048 8FB60028 */  lw        $s6, 0x28($sp)
/* D8E29C 8024104C 8FB50024 */  lw        $s5, 0x24($sp)
/* D8E2A0 80241050 8FB40020 */  lw        $s4, 0x20($sp)
/* D8E2A4 80241054 8FB3001C */  lw        $s3, 0x1c($sp)
/* D8E2A8 80241058 8FB20018 */  lw        $s2, 0x18($sp)
/* D8E2AC 8024105C 8FB10014 */  lw        $s1, 0x14($sp)
/* D8E2B0 80241060 8FB00010 */  lw        $s0, 0x10($sp)
/* D8E2B4 80241064 D7B80040 */  ldc1      $f24, 0x40($sp)
/* D8E2B8 80241068 D7B60038 */  ldc1      $f22, 0x38($sp)
/* D8E2BC 8024106C D7B40030 */  ldc1      $f20, 0x30($sp)
/* D8E2C0 80241070 03E00008 */  jr        $ra
/* D8E2C4 80241074 27BD0048 */   addiu    $sp, $sp, 0x48
