.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D74C0
/* FBE70 802D74C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* FBE74 802D74C4 24E2001E */  addiu     $v0, $a3, 0x1e
/* FBE78 802D74C8 44820000 */  mtc1      $v0, $f0
/* FBE7C 802D74CC 00000000 */  nop
/* FBE80 802D74D0 46800020 */  cvt.s.w   $f0, $f0
/* FBE84 802D74D4 000717C2 */  srl       $v0, $a3, 0x1f
/* FBE88 802D74D8 00E23821 */  addu      $a3, $a3, $v0
/* FBE8C 802D74DC 00073843 */  sra       $a3, $a3, 1
/* FBE90 802D74E0 24E7000A */  addiu     $a3, $a3, 0xa
/* FBE94 802D74E4 44861000 */  mtc1      $a2, $f2
/* FBE98 802D74E8 44056000 */  mfc1      $a1, $f12
/* FBE9C 802D74EC 44067000 */  mfc1      $a2, $f14
/* FBEA0 802D74F0 2402001E */  addiu     $v0, $zero, 0x1e
/* FBEA4 802D74F4 AFA70018 */  sw        $a3, 0x18($sp)
/* FBEA8 802D74F8 44071000 */  mfc1      $a3, $f2
/* FBEAC 802D74FC 24040002 */  addiu     $a0, $zero, 2
/* FBEB0 802D7500 AFBF0020 */  sw        $ra, 0x20($sp)
/* FBEB4 802D7504 E7A00010 */  swc1      $f0, 0x10($sp)
/* FBEB8 802D7508 E7A00014 */  swc1      $f0, 0x14($sp)
/* FBEBC 802D750C 0C01C154 */  jal       playFX_22
/* FBEC0 802D7510 AFA2001C */   sw       $v0, 0x1c($sp)
/* FBEC4 802D7514 8FBF0020 */  lw        $ra, 0x20($sp)
/* FBEC8 802D7518 03E00008 */  jr        $ra
/* FBECC 802D751C 27BD0028 */   addiu    $sp, $sp, 0x28
