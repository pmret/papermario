.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F58_D8A638
/* D8A638 80240F58 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D8A63C 80240F5C AFB10014 */  sw        $s1, 0x14($sp)
/* D8A640 80240F60 0080882D */  daddu     $s1, $a0, $zero
/* D8A644 80240F64 AFB00010 */  sw        $s0, 0x10($sp)
/* D8A648 80240F68 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D8A64C 80240F6C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D8A650 80240F70 AFBF0018 */  sw        $ra, 0x18($sp)
/* D8A654 80240F74 F7B60028 */  sdc1      $f22, 0x28($sp)
/* D8A658 80240F78 F7B40020 */  sdc1      $f20, 0x20($sp)
/* D8A65C 80240F7C 8E060028 */  lw        $a2, 0x28($s0)
/* D8A660 80240F80 8E070030 */  lw        $a3, 0x30($s0)
/* D8A664 80240F84 3C014348 */  lui       $at, 0x4348
/* D8A668 80240F88 4481A000 */  mtc1      $at, $f20
/* D8A66C 80240F8C 4480B000 */  mtc1      $zero, $f22
/* D8A670 80240F90 4600A306 */  mov.s     $f12, $f20
/* D8A674 80240F94 0C00A7B5 */  jal       dist2D
/* D8A678 80240F98 4600B386 */   mov.s    $f14, $f22
/* D8A67C 80240F9C 4600008D */  trunc.w.s $f2, $f0
/* D8A680 80240FA0 E622009C */  swc1      $f2, 0x9c($s1)
/* D8A684 80240FA4 4600A306 */  mov.s     $f12, $f20
/* D8A688 80240FA8 8E060028 */  lw        $a2, 0x28($s0)
/* D8A68C 80240FAC 8E070030 */  lw        $a3, 0x30($s0)
/* D8A690 80240FB0 0C00A720 */  jal       atan2
/* D8A694 80240FB4 4600B386 */   mov.s    $f14, $f22
/* D8A698 80240FB8 4600008D */  trunc.w.s $f2, $f0
/* D8A69C 80240FBC 44021000 */  mfc1      $v0, $f2
/* D8A6A0 80240FC0 00000000 */  nop
/* D8A6A4 80240FC4 44826000 */  mtc1      $v0, $f12
/* D8A6A8 80240FC8 00000000 */  nop
/* D8A6AC 80240FCC 46806320 */  cvt.s.w   $f12, $f12
/* D8A6B0 80240FD0 0C00A6C9 */  jal       clamp_angle
/* D8A6B4 80240FD4 AE2200A0 */   sw       $v0, 0xa0($s1)
/* D8A6B8 80240FD8 4600008D */  trunc.w.s $f2, $f0
/* D8A6BC 80240FDC E62200A0 */  swc1      $f2, 0xa0($s1)
/* D8A6C0 80240FE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8A6C4 80240FE4 8FB10014 */  lw        $s1, 0x14($sp)
/* D8A6C8 80240FE8 8FB00010 */  lw        $s0, 0x10($sp)
/* D8A6CC 80240FEC D7B60028 */  ldc1      $f22, 0x28($sp)
/* D8A6D0 80240FF0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D8A6D4 80240FF4 24020002 */  addiu     $v0, $zero, 2
/* D8A6D8 80240FF8 03E00008 */  jr        $ra
/* D8A6DC 80240FFC 27BD0030 */   addiu    $sp, $sp, 0x30
