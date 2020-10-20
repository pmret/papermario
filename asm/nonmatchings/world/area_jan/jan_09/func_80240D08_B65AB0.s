.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D08_B667B8
/* B667B8 80240D08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B667BC 80240D0C AFB10014 */  sw        $s1, 0x14($sp)
/* B667C0 80240D10 0080882D */  daddu     $s1, $a0, $zero
/* B667C4 80240D14 AFBF0018 */  sw        $ra, 0x18($sp)
/* B667C8 80240D18 AFB00010 */  sw        $s0, 0x10($sp)
/* B667CC 80240D1C 8E300148 */  lw        $s0, 0x148($s1)
/* B667D0 80240D20 0C00EABB */  jal       get_npc_unsafe
/* B667D4 80240D24 86040008 */   lh       $a0, 8($s0)
/* B667D8 80240D28 9443008E */  lhu       $v1, 0x8e($v0)
/* B667DC 80240D2C 2463FFFF */  addiu     $v1, $v1, -1
/* B667E0 80240D30 A443008E */  sh        $v1, 0x8e($v0)
/* B667E4 80240D34 00031C00 */  sll       $v1, $v1, 0x10
/* B667E8 80240D38 1C600003 */  bgtz      $v1, .L80240D48
/* B667EC 80240D3C 2402000C */   addiu    $v0, $zero, 0xc
/* B667F0 80240D40 AE00006C */  sw        $zero, 0x6c($s0)
/* B667F4 80240D44 AE220070 */  sw        $v0, 0x70($s1)
.L80240D48:
/* B667F8 80240D48 8FBF0018 */  lw        $ra, 0x18($sp)
/* B667FC 80240D4C 8FB10014 */  lw        $s1, 0x14($sp)
/* B66800 80240D50 8FB00010 */  lw        $s0, 0x10($sp)
/* B66804 80240D54 03E00008 */  jr        $ra
/* B66808 80240D58 27BD0020 */   addiu    $sp, $sp, 0x20
