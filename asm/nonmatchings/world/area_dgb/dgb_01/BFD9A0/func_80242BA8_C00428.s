.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BA8_C00428
/* C00428 80242BA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C0042C 80242BAC AFB10014 */  sw        $s1, 0x14($sp)
/* C00430 80242BB0 0080882D */  daddu     $s1, $a0, $zero
/* C00434 80242BB4 AFBF001C */  sw        $ra, 0x1c($sp)
/* C00438 80242BB8 AFB20018 */  sw        $s2, 0x18($sp)
/* C0043C 80242BBC AFB00010 */  sw        $s0, 0x10($sp)
/* C00440 80242BC0 8E300148 */  lw        $s0, 0x148($s1)
/* C00444 80242BC4 86040008 */  lh        $a0, 8($s0)
/* C00448 80242BC8 0C00EABB */  jal       get_npc_unsafe
/* C0044C 80242BCC 00A0902D */   daddu    $s2, $a1, $zero
/* C00450 80242BD0 8E230078 */  lw        $v1, 0x78($s1)
/* C00454 80242BD4 24630001 */  addiu     $v1, $v1, 1
/* C00458 80242BD8 AE230078 */  sw        $v1, 0x78($s1)
/* C0045C 80242BDC 8E0400D0 */  lw        $a0, 0xd0($s0)
/* C00460 80242BE0 8C840000 */  lw        $a0, ($a0)
/* C00464 80242BE4 0064182A */  slt       $v1, $v1, $a0
/* C00468 80242BE8 14600002 */  bnez      $v1, .L80242BF4
/* C0046C 80242BEC 0040282D */   daddu    $a1, $v0, $zero
/* C00470 80242BF0 AE200078 */  sw        $zero, 0x78($s1)
.L80242BF4:
/* C00474 80242BF4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C00478 80242BF8 8C420004 */  lw        $v0, 4($v0)
/* C0047C 80242BFC ACA20028 */  sw        $v0, 0x28($a1)
/* C00480 80242C00 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C00484 80242C04 8C42007C */  lw        $v0, 0x7c($v0)
/* C00488 80242C08 04410004 */  bgez      $v0, .L80242C1C
/* C0048C 80242C0C 00000000 */   nop
/* C00490 80242C10 C6400000 */  lwc1      $f0, ($s2)
/* C00494 80242C14 08090B0F */  j         .L80242C3C
/* C00498 80242C18 E4A00018 */   swc1     $f0, 0x18($a1)
.L80242C1C:
/* C0049C 80242C1C 3C018026 */  lui       $at, %hi(D_80263518)
/* C004A0 80242C20 D4223518 */  ldc1      $f2, %lo(D_80263518)($at)
/* C004A4 80242C24 44820000 */  mtc1      $v0, $f0
/* C004A8 80242C28 00000000 */  nop
/* C004AC 80242C2C 46800021 */  cvt.d.w   $f0, $f0
/* C004B0 80242C30 46220003 */  div.d     $f0, $f0, $f2
/* C004B4 80242C34 46200020 */  cvt.s.d   $f0, $f0
/* C004B8 80242C38 E4A00018 */  swc1      $f0, 0x18($a1)
.L80242C3C:
/* C004BC 80242C3C 24020001 */  addiu     $v0, $zero, 1
/* C004C0 80242C40 AE220070 */  sw        $v0, 0x70($s1)
/* C004C4 80242C44 8FBF001C */  lw        $ra, 0x1c($sp)
/* C004C8 80242C48 8FB20018 */  lw        $s2, 0x18($sp)
/* C004CC 80242C4C 8FB10014 */  lw        $s1, 0x14($sp)
/* C004D0 80242C50 8FB00010 */  lw        $s0, 0x10($sp)
/* C004D4 80242C54 03E00008 */  jr        $ra
/* C004D8 80242C58 27BD0020 */   addiu    $sp, $sp, 0x20
