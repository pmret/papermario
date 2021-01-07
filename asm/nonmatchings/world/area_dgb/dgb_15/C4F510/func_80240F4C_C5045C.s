.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F4C_C5045C
/* C5045C 80240F4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C50460 80240F50 AFB10014 */  sw        $s1, 0x14($sp)
/* C50464 80240F54 0080882D */  daddu     $s1, $a0, $zero
/* C50468 80240F58 AFBF001C */  sw        $ra, 0x1c($sp)
/* C5046C 80240F5C AFB20018 */  sw        $s2, 0x18($sp)
/* C50470 80240F60 AFB00010 */  sw        $s0, 0x10($sp)
/* C50474 80240F64 8E300148 */  lw        $s0, 0x148($s1)
/* C50478 80240F68 86040008 */  lh        $a0, 8($s0)
/* C5047C 80240F6C 0C00EABB */  jal       get_npc_unsafe
/* C50480 80240F70 00A0902D */   daddu    $s2, $a1, $zero
/* C50484 80240F74 8E230078 */  lw        $v1, 0x78($s1)
/* C50488 80240F78 24630001 */  addiu     $v1, $v1, 1
/* C5048C 80240F7C AE230078 */  sw        $v1, 0x78($s1)
/* C50490 80240F80 8E0400D0 */  lw        $a0, 0xd0($s0)
/* C50494 80240F84 8C840000 */  lw        $a0, ($a0)
/* C50498 80240F88 0064182A */  slt       $v1, $v1, $a0
/* C5049C 80240F8C 14600002 */  bnez      $v1, .L80240F98
/* C504A0 80240F90 0040282D */   daddu    $a1, $v0, $zero
/* C504A4 80240F94 AE200078 */  sw        $zero, 0x78($s1)
.L80240F98:
/* C504A8 80240F98 8E0200CC */  lw        $v0, 0xcc($s0)
/* C504AC 80240F9C 8C420004 */  lw        $v0, 4($v0)
/* C504B0 80240FA0 ACA20028 */  sw        $v0, 0x28($a1)
/* C504B4 80240FA4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C504B8 80240FA8 8C42007C */  lw        $v0, 0x7c($v0)
/* C504BC 80240FAC 04410004 */  bgez      $v0, .L80240FC0
/* C504C0 80240FB0 00000000 */   nop      
/* C504C4 80240FB4 C6400000 */  lwc1      $f0, ($s2)
/* C504C8 80240FB8 080903F8 */  j         .L80240FE0
/* C504CC 80240FBC E4A00018 */   swc1     $f0, 0x18($a1)
.L80240FC0:
/* C504D0 80240FC0 3C018024 */  lui       $at, %hi(D_80242E90)
/* C504D4 80240FC4 D4222E90 */  ldc1      $f2, %lo(D_80242E90)($at)
/* C504D8 80240FC8 44820000 */  mtc1      $v0, $f0
/* C504DC 80240FCC 00000000 */  nop       
/* C504E0 80240FD0 46800021 */  cvt.d.w   $f0, $f0
/* C504E4 80240FD4 46220003 */  div.d     $f0, $f0, $f2
/* C504E8 80240FD8 46200020 */  cvt.s.d   $f0, $f0
/* C504EC 80240FDC E4A00018 */  swc1      $f0, 0x18($a1)
.L80240FE0:
/* C504F0 80240FE0 24020001 */  addiu     $v0, $zero, 1
/* C504F4 80240FE4 AE220070 */  sw        $v0, 0x70($s1)
/* C504F8 80240FE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* C504FC 80240FEC 8FB20018 */  lw        $s2, 0x18($sp)
/* C50500 80240FF0 8FB10014 */  lw        $s1, 0x14($sp)
/* C50504 80240FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* C50508 80240FF8 03E00008 */  jr        $ra
/* C5050C 80240FFC 27BD0020 */   addiu    $sp, $sp, 0x20
