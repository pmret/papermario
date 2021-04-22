.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80049B7C
/* 24F7C 80049B7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 24F80 80049B80 AFB00010 */  sw        $s0, 0x10($sp)
/* 24F84 80049B84 0080802D */  daddu     $s0, $a0, $zero
/* 24F88 80049B88 AFBF0014 */  sw        $ra, 0x14($sp)
/* 24F8C 80049B8C 8E020148 */  lw        $v0, 0x148($s0)
/* 24F90 80049B90 0C00E9EB */  jal       func_8003A7AC
/* 24F94 80049B94 84440008 */   lh       $a0, 8($v0)
/* 24F98 80049B98 0040202D */  daddu     $a0, $v0, $zero
/* 24F9C 80049B9C C480001C */  lwc1      $f0, 0x1c($a0)
/* 24FA0 80049BA0 44801000 */  mtc1      $zero, $f2
/* 24FA4 80049BA4 44801800 */  mtc1      $zero, $f3
/* 24FA8 80049BA8 46000021 */  cvt.d.s   $f0, $f0
/* 24FAC 80049BAC 4622003E */  c.le.d    $f0, $f2
/* 24FB0 80049BB0 00000000 */  nop
/* 24FB4 80049BB4 45000009 */  bc1f      .L80049BDC
/* 24FB8 80049BB8 0000182D */   daddu    $v1, $zero, $zero
/* 24FBC 80049BBC C480003C */  lwc1      $f0, 0x3c($a0)
/* 24FC0 80049BC0 C4820064 */  lwc1      $f2, 0x64($a0)
/* 24FC4 80049BC4 4602003E */  c.le.s    $f0, $f2
/* 24FC8 80049BC8 00000000 */  nop
/* 24FCC 80049BCC 45000003 */  bc1f      .L80049BDC
/* 24FD0 80049BD0 00000000 */   nop
/* 24FD4 80049BD4 E482003C */  swc1      $f2, 0x3c($a0)
/* 24FD8 80049BD8 24030001 */  addiu     $v1, $zero, 1
.L80049BDC:
/* 24FDC 80049BDC 14600009 */  bnez      $v1, .L80049C04
/* 24FE0 80049BE0 2403F7FF */   addiu    $v1, $zero, -0x801
/* 24FE4 80049BE4 C484003C */  lwc1      $f4, 0x3c($a0)
/* 24FE8 80049BE8 C480001C */  lwc1      $f0, 0x1c($a0)
/* 24FEC 80049BEC 46002100 */  add.s     $f4, $f4, $f0
/* 24FF0 80049BF0 C4820014 */  lwc1      $f2, 0x14($a0)
/* 24FF4 80049BF4 46020001 */  sub.s     $f0, $f0, $f2
/* 24FF8 80049BF8 E484003C */  swc1      $f4, 0x3c($a0)
/* 24FFC 80049BFC 08012707 */  j         .L80049C1C
/* 25000 80049C00 E480001C */   swc1     $f0, 0x1c($a0)
.L80049C04:
/* 25004 80049C04 8C820000 */  lw        $v0, ($a0)
/* 25008 80049C08 AC80001C */  sw        $zero, 0x1c($a0)
/* 2500C 80049C0C 00431024 */  and       $v0, $v0, $v1
/* 25010 80049C10 AC820000 */  sw        $v0, ($a0)
/* 25014 80049C14 2402000C */  addiu     $v0, $zero, 0xc
/* 25018 80049C18 AE020070 */  sw        $v0, 0x70($s0)
.L80049C1C:
/* 2501C 80049C1C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 25020 80049C20 8FB00010 */  lw        $s0, 0x10($sp)
/* 25024 80049C24 03E00008 */  jr        $ra
/* 25028 80049C28 27BD0018 */   addiu    $sp, $sp, 0x18
