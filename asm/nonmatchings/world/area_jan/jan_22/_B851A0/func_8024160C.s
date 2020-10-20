.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024160C
/* B8578C 8024160C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B85790 80241610 AFB00010 */  sw        $s0, 0x10($sp)
/* B85794 80241614 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B85798 80241618 4485A000 */  mtc1      $a1, $f20
/* B8579C 8024161C AFBF0014 */  sw        $ra, 0x14($sp)
/* B857A0 80241620 0C019D28 */  jal       guMtxIdentF
/* B857A4 80241624 0080802D */   daddu    $s0, $a0, $zero
/* B857A8 80241628 3C018025 */  lui       $at, 0x8025
/* B857AC 8024162C D420BB40 */  ldc1      $f0, -0x44c0($at)
/* B857B0 80241630 4600A521 */  cvt.d.s   $f20, $f20
/* B857B4 80241634 4620A502 */  mul.d     $f20, $f20, $f0
/* B857B8 80241638 00000000 */  nop       
/* B857BC 8024163C 3C013F80 */  lui       $at, 0x3f80
/* B857C0 80241640 44810000 */  mtc1      $at, $f0
/* B857C4 80241644 AE000018 */  sw        $zero, 0x18($s0)
/* B857C8 80241648 E6000014 */  swc1      $f0, 0x14($s0)
/* B857CC 8024164C 4620A520 */  cvt.s.d   $f20, $f20
/* B857D0 80241650 E6140010 */  swc1      $f20, 0x10($s0)
/* B857D4 80241654 8FBF0014 */  lw        $ra, 0x14($sp)
/* B857D8 80241658 8FB00010 */  lw        $s0, 0x10($sp)
/* B857DC 8024165C D7B40018 */  ldc1      $f20, 0x18($sp)
/* B857E0 80241660 03E00008 */  jr        $ra
/* B857E4 80241664 27BD0020 */   addiu    $sp, $sp, 0x20
