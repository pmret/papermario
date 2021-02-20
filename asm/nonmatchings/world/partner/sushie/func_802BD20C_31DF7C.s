.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD20C_31DF7C
/* 31DF7C 802BD20C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31DF80 802BD210 AFB20018 */  sw        $s2, 0x18($sp)
/* 31DF84 802BD214 0080902D */  daddu     $s2, $a0, $zero
/* 31DF88 802BD218 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31DF8C 802BD21C 00A0982D */  daddu     $s3, $a1, $zero
/* 31DF90 802BD220 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 31DF94 802BD224 4480A000 */  mtc1      $zero, $f20
/* 31DF98 802BD228 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 31DF9C 802BD22C 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 31DFA0 802BD230 AFB00010 */  sw        $s0, 0x10($sp)
/* 31DFA4 802BD234 3C10802C */  lui       $s0, %hi(D_802BFDB0_320B20)
/* 31DFA8 802BD238 2610FDB0 */  addiu     $s0, $s0, %lo(D_802BFDB0_320B20)
/* 31DFAC 802BD23C AFB10014 */  sw        $s1, 0x14($sp)
/* 31DFB0 802BD240 3C11802C */  lui       $s1, %hi(D_802BFDB4_320B24)
/* 31DFB4 802BD244 2631FDB4 */  addiu     $s1, $s1, %lo(D_802BFDB4_320B24)
/* 31DFB8 802BD248 AFBF0020 */  sw        $ra, 0x20($sp)
/* 31DFBC 802BD24C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 31DFC0 802BD250 84620006 */  lh        $v0, 6($v1)
/* 31DFC4 802BD254 4600A306 */  mov.s     $f12, $f20
/* 31DFC8 802BD258 44821000 */  mtc1      $v0, $f2
/* 31DFCC 802BD25C 00000000 */  nop
/* 31DFD0 802BD260 468010A0 */  cvt.s.w   $f2, $f2
/* 31DFD4 802BD264 46001107 */  neg.s     $f4, $f2
/* 31DFD8 802BD268 84620004 */  lh        $v0, 4($v1)
/* 31DFDC 802BD26C 44072000 */  mfc1      $a3, $f4
/* 31DFE0 802BD270 44820000 */  mtc1      $v0, $f0
/* 31DFE4 802BD274 00000000 */  nop
/* 31DFE8 802BD278 46800020 */  cvt.s.w   $f0, $f0
/* 31DFEC 802BD27C 44060000 */  mfc1      $a2, $f0
/* 31DFF0 802BD280 4600A386 */  mov.s     $f14, $f20
/* 31DFF4 802BD284 AE060000 */  sw        $a2, ($s0)
/* 31DFF8 802BD288 0C00A720 */  jal       atan2
/* 31DFFC 802BD28C E6220000 */   swc1     $f2, ($s1)
/* 31E000 802BD290 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 31E004 802BD294 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* 31E008 802BD298 0C00A6C9 */  jal       clamp_angle
/* 31E00C 802BD29C 460C0300 */   add.s    $f12, $f0, $f12
/* 31E010 802BD2A0 4600A306 */  mov.s     $f12, $f20
/* 31E014 802BD2A4 4600A386 */  mov.s     $f14, $f20
/* 31E018 802BD2A8 C6220000 */  lwc1      $f2, ($s1)
/* 31E01C 802BD2AC 8E060000 */  lw        $a2, ($s0)
/* 31E020 802BD2B0 46001087 */  neg.s     $f2, $f2
/* 31E024 802BD2B4 44071000 */  mfc1      $a3, $f2
/* 31E028 802BD2B8 0C00A7B5 */  jal       dist2D
/* 31E02C 802BD2BC 46000586 */   mov.s    $f22, $f0
/* 31E030 802BD2C0 3C013FF0 */  lui       $at, 0x3ff0
/* 31E034 802BD2C4 44811800 */  mtc1      $at, $f3
/* 31E038 802BD2C8 44801000 */  mtc1      $zero, $f2
/* 31E03C 802BD2CC 46000021 */  cvt.d.s   $f0, $f0
/* 31E040 802BD2D0 4620103E */  c.le.d    $f2, $f0
/* 31E044 802BD2D4 00000000 */  nop
/* 31E048 802BD2D8 45020019 */  bc1fl     .L802BD340
/* 31E04C 802BD2DC E6560000 */   swc1     $f22, ($s2)
/* 31E050 802BD2E0 C6000000 */  lwc1      $f0, ($s0)
/* 31E054 802BD2E4 46000002 */  mul.s     $f0, $f0, $f0
/* 31E058 802BD2E8 00000000 */  nop
/* 31E05C 802BD2EC C6220000 */  lwc1      $f2, ($s1)
/* 31E060 802BD2F0 46021082 */  mul.s     $f2, $f2, $f2
/* 31E064 802BD2F4 00000000 */  nop
/* 31E068 802BD2F8 46020000 */  add.s     $f0, $f0, $f2
/* 31E06C 802BD2FC 3C01453D */  lui       $at, 0x453d
/* 31E070 802BD300 34211000 */  ori       $at, $at, 0x1000
/* 31E074 802BD304 44811000 */  mtc1      $at, $f2
/* 31E078 802BD308 00000000 */  nop
/* 31E07C 802BD30C 4600103C */  c.lt.s    $f2, $f0
/* 31E080 802BD310 00000000 */  nop
/* 31E084 802BD314 45000007 */  bc1f      .L802BD334
/* 31E088 802BD318 00000000 */   nop
/* 31E08C 802BD31C 3C02802C */  lui       $v0, %hi(D_802BFEE4)
/* 31E090 802BD320 8C42FEE4 */  lw        $v0, %lo(D_802BFEE4)($v0)
/* 31E094 802BD324 3C014080 */  lui       $at, 0x4080
/* 31E098 802BD328 4481A000 */  mtc1      $at, $f20
/* 31E09C 802BD32C 50400004 */  beql      $v0, $zero, .L802BD340
/* 31E0A0 802BD330 E6560000 */   swc1     $f22, ($s2)
.L802BD334:
/* 31E0A4 802BD334 3C014000 */  lui       $at, 0x4000
/* 31E0A8 802BD338 4481A000 */  mtc1      $at, $f20
/* 31E0AC 802BD33C E6560000 */  swc1      $f22, ($s2)
.L802BD340:
/* 31E0B0 802BD340 E6740000 */  swc1      $f20, ($s3)
/* 31E0B4 802BD344 8FBF0020 */  lw        $ra, 0x20($sp)
/* 31E0B8 802BD348 8FB3001C */  lw        $s3, 0x1c($sp)
/* 31E0BC 802BD34C 8FB20018 */  lw        $s2, 0x18($sp)
/* 31E0C0 802BD350 8FB10014 */  lw        $s1, 0x14($sp)
/* 31E0C4 802BD354 8FB00010 */  lw        $s0, 0x10($sp)
/* 31E0C8 802BD358 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 31E0CC 802BD35C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 31E0D0 802BD360 03E00008 */  jr        $ra
/* 31E0D4 802BD364 27BD0038 */   addiu    $sp, $sp, 0x38
