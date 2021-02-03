.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD6BC_32120C
/* 32120C 802BD6BC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 321210 802BD6C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 321214 802BD6C4 0080802D */  daddu     $s0, $a0, $zero
/* 321218 802BD6C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 32121C 802BD6CC 00A0882D */  daddu     $s1, $a1, $zero
/* 321220 802BD6D0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 321224 802BD6D4 4480A000 */  mtc1      $zero, $f20
/* 321228 802BD6D8 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 32122C 802BD6DC 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 321230 802BD6E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 321234 802BD6E4 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 321238 802BD6E8 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 32123C 802BD6EC F7B60028 */  sdc1      $f22, 0x28($sp)
/* 321240 802BD6F0 84620004 */  lh        $v0, 4($v1)
/* 321244 802BD6F4 4600A306 */  mov.s     $f12, $f20
/* 321248 802BD6F8 4482C000 */  mtc1      $v0, $f24
/* 32124C 802BD6FC 00000000 */  nop
/* 321250 802BD700 4680C620 */  cvt.s.w   $f24, $f24
/* 321254 802BD704 84620006 */  lh        $v0, 6($v1)
/* 321258 802BD708 4406C000 */  mfc1      $a2, $f24
/* 32125C 802BD70C 4482D000 */  mtc1      $v0, $f26
/* 321260 802BD710 00000000 */  nop
/* 321264 802BD714 4680D6A0 */  cvt.s.w   $f26, $f26
/* 321268 802BD718 4600D587 */  neg.s     $f22, $f26
/* 32126C 802BD71C 4407B000 */  mfc1      $a3, $f22
/* 321270 802BD720 0C00A720 */  jal       atan2
/* 321274 802BD724 4600A386 */   mov.s    $f14, $f20
/* 321278 802BD728 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 32127C 802BD72C C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* 321280 802BD730 0C00A6C9 */  jal       clamp_angle
/* 321284 802BD734 460C0300 */   add.s    $f12, $f0, $f12
/* 321288 802BD738 4600A306 */  mov.s     $f12, $f20
/* 32128C 802BD73C 4600A386 */  mov.s     $f14, $f20
/* 321290 802BD740 4406C000 */  mfc1      $a2, $f24
/* 321294 802BD744 4407B000 */  mfc1      $a3, $f22
/* 321298 802BD748 0C00A7B5 */  jal       dist2D
/* 32129C 802BD74C 46000586 */   mov.s    $f22, $f0
/* 3212A0 802BD750 3C013FF0 */  lui       $at, 0x3ff0
/* 3212A4 802BD754 44811800 */  mtc1      $at, $f3
/* 3212A8 802BD758 44801000 */  mtc1      $zero, $f2
/* 3212AC 802BD75C 46000021 */  cvt.d.s   $f0, $f0
/* 3212B0 802BD760 4620103E */  c.le.d    $f2, $f0
/* 3212B4 802BD764 00000000 */  nop
/* 3212B8 802BD768 45000012 */  bc1f      .L802BD7B4
/* 3212BC 802BD76C E6160000 */   swc1     $f22, ($s0)
/* 3212C0 802BD770 4618C002 */  mul.s     $f0, $f24, $f24
/* 3212C4 802BD774 00000000 */  nop
/* 3212C8 802BD778 461AD082 */  mul.s     $f2, $f26, $f26
/* 3212CC 802BD77C 00000000 */  nop
/* 3212D0 802BD780 46020000 */  add.s     $f0, $f0, $f2
/* 3212D4 802BD784 3C01453D */  lui       $at, 0x453d
/* 3212D8 802BD788 34211000 */  ori       $at, $at, 0x1000
/* 3212DC 802BD78C 44811000 */  mtc1      $at, $f2
/* 3212E0 802BD790 3C014040 */  lui       $at, 0x4040
/* 3212E4 802BD794 4481A000 */  mtc1      $at, $f20
/* 3212E8 802BD798 4600103C */  c.lt.s    $f2, $f0
/* 3212EC 802BD79C 00000000 */  nop
/* 3212F0 802BD7A0 45000004 */  bc1f      .L802BD7B4
/* 3212F4 802BD7A4 00000000 */   nop
/* 3212F8 802BD7A8 3C0140C0 */  lui       $at, 0x40c0
/* 3212FC 802BD7AC 4481A000 */  mtc1      $at, $f20
/* 321300 802BD7B0 00000000 */  nop
.L802BD7B4:
/* 321304 802BD7B4 E6340000 */  swc1      $f20, ($s1)
/* 321308 802BD7B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 32130C 802BD7BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 321310 802BD7C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 321314 802BD7C4 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 321318 802BD7C8 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 32131C 802BD7CC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 321320 802BD7D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 321324 802BD7D4 03E00008 */  jr        $ra
/* 321328 802BD7D8 27BD0040 */   addiu    $sp, $sp, 0x40
