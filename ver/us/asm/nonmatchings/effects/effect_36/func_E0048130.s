.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0048130
/* 356AB0 E0048130 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 356AB4 E0048134 AFBF0010 */  sw        $ra, 0x10($sp)
/* 356AB8 E0048138 8C85000C */  lw        $a1, 0xc($a0)
/* 356ABC E004813C 3C014100 */  lui       $at, 0x4100
/* 356AC0 E0048140 44810000 */  mtc1      $at, $f0
/* 356AC4 E0048144 8CA20018 */  lw        $v0, 0x18($a1)
/* 356AC8 E0048148 8CA30014 */  lw        $v1, 0x14($a1)
/* 356ACC E004814C 44821000 */  mtc1      $v0, $f2
/* 356AD0 E0048150 00000000 */  nop
/* 356AD4 E0048154 468010A0 */  cvt.s.w   $f2, $f2
/* 356AD8 E0048158 24420001 */  addiu     $v0, $v0, 1
/* 356ADC E004815C 46001082 */  mul.s     $f2, $f2, $f0
/* 356AE0 E0048160 00000000 */  nop
/* 356AE4 E0048164 2463FFFF */  addiu     $v1, $v1, -1
/* 356AE8 E0048168 C4A0001C */  lwc1      $f0, 0x1c($a1)
/* 356AEC E004816C 46800020 */  cvt.s.w   $f0, $f0
/* 356AF0 E0048170 ACA20018 */  sw        $v0, 0x18($a1)
/* 356AF4 E0048174 ACA30014 */  sw        $v1, 0x14($a1)
/* 356AF8 E0048178 46001083 */  div.s     $f2, $f2, $f0
/* 356AFC E004817C 04610005 */  bgez      $v1, .LE0048194
/* 356B00 E0048180 E4A20020 */   swc1     $f2, 0x20($a1)
/* 356B04 E0048184 0C080128 */  jal       func_E02004A0
/* 356B08 E0048188 00000000 */   nop
/* 356B0C E004818C 08012072 */  j         .LE00481C8
/* 356B10 E0048190 00000000 */   nop
.LE0048194:
/* 356B14 E0048194 C4A00024 */  lwc1      $f0, 0x24($a1)
/* 356B18 E0048198 C4A20028 */  lwc1      $f2, 0x28($a1)
/* 356B1C E004819C 46020000 */  add.s     $f0, $f0, $f2
/* 356B20 E00481A0 94A20000 */  lhu       $v0, ($a1)
/* 356B24 E00481A4 14400008 */  bnez      $v0, .LE00481C8
/* 356B28 E00481A8 E4A00024 */   swc1     $f0, 0x24($a1)
/* 356B2C E00481AC C4A00010 */  lwc1      $f0, 0x10($a1)
/* 356B30 E00481B0 3C01E005 */  lui       $at, %hi(D_E0048A10)
/* 356B34 E00481B4 D4228A10 */  ldc1      $f2, %lo(D_E0048A10)($at)
/* 356B38 E00481B8 46000021 */  cvt.d.s   $f0, $f0
/* 356B3C E00481BC 46220000 */  add.d     $f0, $f0, $f2
/* 356B40 E00481C0 46200020 */  cvt.s.d   $f0, $f0
/* 356B44 E00481C4 E4A00010 */  swc1      $f0, 0x10($a1)
.LE00481C8:
/* 356B48 E00481C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 356B4C E00481CC 03E00008 */  jr        $ra
/* 356B50 E00481D0 27BD0018 */   addiu    $sp, $sp, 0x18
