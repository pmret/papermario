.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F4C
/* A7032C 80241F4C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A70330 80241F50 AFB20018 */  sw        $s2, 0x18($sp)
/* A70334 80241F54 0080902D */  daddu     $s2, $a0, $zero
/* A70338 80241F58 AFBF001C */  sw        $ra, 0x1c($sp)
/* A7033C 80241F5C AFB10014 */  sw        $s1, 0x14($sp)
/* A70340 80241F60 AFB00010 */  sw        $s0, 0x10($sp)
/* A70344 80241F64 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A70348 80241F68 8E500148 */  lw        $s0, 0x148($s2)
/* A7034C 80241F6C 0C00EABB */  jal       get_npc_unsafe
/* A70350 80241F70 86040008 */   lh       $a0, 8($s0)
/* A70354 80241F74 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A70358 80241F78 46806320 */  cvt.s.w   $f12, $f12
/* A7035C 80241F7C 0040882D */  daddu     $s1, $v0, $zero
/* A70360 80241F80 C6140070 */  lwc1      $f20, 0x70($s0)
/* A70364 80241F84 4680A520 */  cvt.s.w   $f20, $f20
/* A70368 80241F88 3C014059 */  lui       $at, 0x4059
/* A7036C 80241F8C 44810800 */  mtc1      $at, $f1
/* A70370 80241F90 44800000 */  mtc1      $zero, $f0
/* A70374 80241F94 4600A521 */  cvt.d.s   $f20, $f20
/* A70378 80241F98 4620A503 */  div.d     $f20, $f20, $f0
/* A7037C 80241F9C 0C00A8BB */  jal       sin_deg
/* A70380 80241FA0 4620A520 */   cvt.s.d  $f20, $f20
/* A70384 80241FA4 3C014018 */  lui       $at, 0x4018
/* A70388 80241FA8 44811800 */  mtc1      $at, $f3
/* A7038C 80241FAC 44801000 */  mtc1      $zero, $f2
/* A70390 80241FB0 46000021 */  cvt.d.s   $f0, $f0
/* A70394 80241FB4 46220002 */  mul.d     $f0, $f0, $f2
/* A70398 80241FB8 00000000 */  nop       
/* A7039C 80241FBC 4600A0A1 */  cvt.d.s   $f2, $f20
/* A703A0 80241FC0 46201080 */  add.d     $f2, $f2, $f0
/* A703A4 80241FC4 462010A0 */  cvt.s.d   $f2, $f2
/* A703A8 80241FC8 E622003C */  swc1      $f2, 0x3c($s1)
/* A703AC 80241FCC 8E02006C */  lw        $v0, 0x6c($s0)
/* A703B0 80241FD0 2442000A */  addiu     $v0, $v0, 0xa
/* A703B4 80241FD4 44826000 */  mtc1      $v0, $f12
/* A703B8 80241FD8 00000000 */  nop       
/* A703BC 80241FDC 0C00A6C9 */  jal       clamp_angle
/* A703C0 80241FE0 46806320 */   cvt.s.w  $f12, $f12
/* A703C4 80241FE4 4600010D */  trunc.w.s $f4, $f0
/* A703C8 80241FE8 E604006C */  swc1      $f4, 0x6c($s0)
/* A703CC 80241FEC 9622008E */  lhu       $v0, 0x8e($s1)
/* A703D0 80241FF0 2442FFFF */  addiu     $v0, $v0, -1
/* A703D4 80241FF4 A622008E */  sh        $v0, 0x8e($s1)
/* A703D8 80241FF8 00021400 */  sll       $v0, $v0, 0x10
/* A703DC 80241FFC 1C400002 */  bgtz      $v0, .L80242008
/* A703E0 80242000 2402000A */   addiu    $v0, $zero, 0xa
/* A703E4 80242004 AE420070 */  sw        $v0, 0x70($s2)
.L80242008:
/* A703E8 80242008 8FBF001C */  lw        $ra, 0x1c($sp)
/* A703EC 8024200C 8FB20018 */  lw        $s2, 0x18($sp)
/* A703F0 80242010 8FB10014 */  lw        $s1, 0x14($sp)
/* A703F4 80242014 8FB00010 */  lw        $s0, 0x10($sp)
/* A703F8 80242018 D7B40020 */  ldc1      $f20, 0x20($sp)
/* A703FC 8024201C 03E00008 */  jr        $ra
/* A70400 80242020 27BD0028 */   addiu    $sp, $sp, 0x28
