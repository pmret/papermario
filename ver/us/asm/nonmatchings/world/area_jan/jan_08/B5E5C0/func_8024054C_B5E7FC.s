.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802474B0_B65760
.double 0.2, 0.0

.section .text

glabel func_8024054C_B5E7FC
/* B5E7FC 8024054C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5E800 80240550 AFB00010 */  sw        $s0, 0x10($sp)
/* B5E804 80240554 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B5E808 80240558 4485A000 */  mtc1      $a1, $f20
/* B5E80C 8024055C AFBF0014 */  sw        $ra, 0x14($sp)
/* B5E810 80240560 0C019D28 */  jal       guMtxIdentF
/* B5E814 80240564 0080802D */   daddu    $s0, $a0, $zero
/* B5E818 80240568 3C018024 */  lui       $at, %hi(D_802474B0_B65760)
/* B5E81C 8024056C D42074B0 */  ldc1      $f0, %lo(D_802474B0_B65760)($at)
/* B5E820 80240570 4600A521 */  cvt.d.s   $f20, $f20
/* B5E824 80240574 4620A502 */  mul.d     $f20, $f20, $f0
/* B5E828 80240578 00000000 */  nop
/* B5E82C 8024057C 3C013F80 */  lui       $at, 0x3f80
/* B5E830 80240580 44810000 */  mtc1      $at, $f0
/* B5E834 80240584 AE000018 */  sw        $zero, 0x18($s0)
/* B5E838 80240588 E6000014 */  swc1      $f0, 0x14($s0)
/* B5E83C 8024058C 4620A520 */  cvt.s.d   $f20, $f20
/* B5E840 80240590 E6140010 */  swc1      $f20, 0x10($s0)
/* B5E844 80240594 8FBF0014 */  lw        $ra, 0x14($sp)
/* B5E848 80240598 8FB00010 */  lw        $s0, 0x10($sp)
/* B5E84C 8024059C D7B40018 */  ldc1      $f20, 0x18($sp)
/* B5E850 802405A0 03E00008 */  jr        $ra
/* B5E854 802405A4 27BD0020 */   addiu    $sp, $sp, 0x20
