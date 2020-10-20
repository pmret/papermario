.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EBC_C8896C
/* C8896C 80242EBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C88970 80242EC0 AFB00010 */  sw        $s0, 0x10($sp)
/* C88974 80242EC4 0080802D */  daddu     $s0, $a0, $zero
/* C88978 80242EC8 AFBF0014 */  sw        $ra, 0x14($sp)
/* C8897C 80242ECC F7B40018 */  sdc1      $f20, 0x18($sp)
/* C88980 80242ED0 C60C0090 */  lwc1      $f12, 0x90($s0)
/* C88984 80242ED4 46806320 */  cvt.s.w   $f12, $f12
/* C88988 80242ED8 3C018024 */  lui       $at, 0x8024
/* C8898C 80242EDC D43465D0 */  ldc1      $f20, 0x65d0($at)
/* C88990 80242EE0 46006307 */  neg.s     $f12, $f12
/* C88994 80242EE4 46006321 */  cvt.d.s   $f12, $f12
/* C88998 80242EE8 46346301 */  sub.d     $f12, $f12, $f20
/* C8899C 80242EEC 0C00A8D4 */  jal       cos_deg
/* C889A0 80242EF0 46206320 */   cvt.s.d  $f12, $f12
/* C889A4 80242EF4 3C014008 */  lui       $at, 0x4008
/* C889A8 80242EF8 44811800 */  mtc1      $at, $f3
/* C889AC 80242EFC 44801000 */  mtc1      $zero, $f2
/* C889B0 80242F00 46000021 */  cvt.d.s   $f0, $f0
/* C889B4 80242F04 46220002 */  mul.d     $f0, $f0, $f2
/* C889B8 80242F08 00000000 */  nop       
/* C889BC 80242F0C C60C0090 */  lwc1      $f12, 0x90($s0)
/* C889C0 80242F10 46806320 */  cvt.s.w   $f12, $f12
/* C889C4 80242F14 46006307 */  neg.s     $f12, $f12
/* C889C8 80242F18 46006321 */  cvt.d.s   $f12, $f12
/* C889CC 80242F1C 46346301 */  sub.d     $f12, $f12, $f20
/* C889D0 80242F20 3C018024 */  lui       $at, 0x8024
/* C889D4 80242F24 D42265D8 */  ldc1      $f2, 0x65d8($at)
/* C889D8 80242F28 46220001 */  sub.d     $f0, $f0, $f2
/* C889DC 80242F2C 4620010D */  trunc.w.d $f4, $f0
/* C889E0 80242F30 E6040098 */  swc1      $f4, 0x98($s0)
/* C889E4 80242F34 0C00A8BB */  jal       sin_deg
/* C889E8 80242F38 46206320 */   cvt.s.d  $f12, $f12
/* C889EC 80242F3C 3C014014 */  lui       $at, 0x4014
/* C889F0 80242F40 44811800 */  mtc1      $at, $f3
/* C889F4 80242F44 44801000 */  mtc1      $zero, $f2
/* C889F8 80242F48 46000021 */  cvt.d.s   $f0, $f0
/* C889FC 80242F4C 46220002 */  mul.d     $f0, $f0, $f2
/* C88A00 80242F50 00000000 */  nop       
/* C88A04 80242F54 4620010D */  trunc.w.d $f4, $f0
/* C88A08 80242F58 E604009C */  swc1      $f4, 0x9c($s0)
/* C88A0C 80242F5C 8FBF0014 */  lw        $ra, 0x14($sp)
/* C88A10 80242F60 8FB00010 */  lw        $s0, 0x10($sp)
/* C88A14 80242F64 D7B40018 */  ldc1      $f20, 0x18($sp)
/* C88A18 80242F68 24020002 */  addiu     $v0, $zero, 2
/* C88A1C 80242F6C 03E00008 */  jr        $ra
/* C88A20 80242F70 27BD0020 */   addiu    $sp, $sp, 0x20
