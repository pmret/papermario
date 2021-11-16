.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80246590_B6C040
.double 0.2, 0.0

.section .text

glabel func_8024082C_B662DC
/* B662DC 8024082C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B662E0 80240830 AFB00010 */  sw        $s0, 0x10($sp)
/* B662E4 80240834 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B662E8 80240838 4485A000 */  mtc1      $a1, $f20
/* B662EC 8024083C AFBF0014 */  sw        $ra, 0x14($sp)
/* B662F0 80240840 0C019D28 */  jal       guMtxIdentF
/* B662F4 80240844 0080802D */   daddu    $s0, $a0, $zero
/* B662F8 80240848 3C018024 */  lui       $at, %hi(D_80246590_B6C040)
/* B662FC 8024084C D4206590 */  ldc1      $f0, %lo(D_80246590_B6C040)($at)
/* B66300 80240850 4600A521 */  cvt.d.s   $f20, $f20
/* B66304 80240854 4620A502 */  mul.d     $f20, $f20, $f0
/* B66308 80240858 00000000 */  nop
/* B6630C 8024085C 3C013F80 */  lui       $at, 0x3f80
/* B66310 80240860 44810000 */  mtc1      $at, $f0
/* B66314 80240864 AE000018 */  sw        $zero, 0x18($s0)
/* B66318 80240868 E6000014 */  swc1      $f0, 0x14($s0)
/* B6631C 8024086C 4620A520 */  cvt.s.d   $f20, $f20
/* B66320 80240870 E6140010 */  swc1      $f20, 0x10($s0)
/* B66324 80240874 8FBF0014 */  lw        $ra, 0x14($sp)
/* B66328 80240878 8FB00010 */  lw        $s0, 0x10($sp)
/* B6632C 8024087C D7B40018 */  ldc1      $f20, 0x18($sp)
/* B66330 80240880 03E00008 */  jr        $ra
/* B66334 80240884 27BD0020 */   addiu    $sp, $sp, 0x20
