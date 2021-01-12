.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7460
/* FBE10 802D7460 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* FBE14 802D7464 24E2001E */  addiu     $v0, $a3, 0x1e
/* FBE18 802D7468 44820000 */  mtc1      $v0, $f0
/* FBE1C 802D746C 00000000 */  nop
/* FBE20 802D7470 46800020 */  cvt.s.w   $f0, $f0
/* FBE24 802D7474 000717C2 */  srl       $v0, $a3, 0x1f
/* FBE28 802D7478 00E23821 */  addu      $a3, $a3, $v0
/* FBE2C 802D747C 00073843 */  sra       $a3, $a3, 1
/* FBE30 802D7480 24E7000A */  addiu     $a3, $a3, 0xa
/* FBE34 802D7484 44861000 */  mtc1      $a2, $f2
/* FBE38 802D7488 44056000 */  mfc1      $a1, $f12
/* FBE3C 802D748C 44067000 */  mfc1      $a2, $f14
/* FBE40 802D7490 2402001E */  addiu     $v0, $zero, 0x1e
/* FBE44 802D7494 AFA70018 */  sw        $a3, 0x18($sp)
/* FBE48 802D7498 44071000 */  mfc1      $a3, $f2
/* FBE4C 802D749C 24040001 */  addiu     $a0, $zero, 1
/* FBE50 802D74A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* FBE54 802D74A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* FBE58 802D74A8 E7A00014 */  swc1      $f0, 0x14($sp)
/* FBE5C 802D74AC 0C01C154 */  jal       func_80070550
/* FBE60 802D74B0 AFA2001C */   sw       $v0, 0x1c($sp)
/* FBE64 802D74B4 8FBF0020 */  lw        $ra, 0x20($sp)
/* FBE68 802D74B8 03E00008 */  jr        $ra
/* FBE6C 802D74BC 27BD0028 */   addiu    $sp, $sp, 0x28
