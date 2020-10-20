.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F64
/* D8F1B4 80241F64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8F1B8 80241F68 AFB10014 */  sw        $s1, 0x14($sp)
/* D8F1BC 80241F6C 0080882D */  daddu     $s1, $a0, $zero
/* D8F1C0 80241F70 AFBF0018 */  sw        $ra, 0x18($sp)
/* D8F1C4 80241F74 AFB00010 */  sw        $s0, 0x10($sp)
/* D8F1C8 80241F78 8E300148 */  lw        $s0, 0x148($s1)
/* D8F1CC 80241F7C 0C00EABB */  jal       get_npc_unsafe
/* D8F1D0 80241F80 86040008 */   lh       $a0, 8($s0)
/* D8F1D4 80241F84 9443008E */  lhu       $v1, 0x8e($v0)
/* D8F1D8 80241F88 2463FFFF */  addiu     $v1, $v1, -1
/* D8F1DC 80241F8C A443008E */  sh        $v1, 0x8e($v0)
/* D8F1E0 80241F90 00031C00 */  sll       $v1, $v1, 0x10
/* D8F1E4 80241F94 1C600003 */  bgtz      $v1, .L80241FA4
/* D8F1E8 80241F98 2402000C */   addiu    $v0, $zero, 0xc
/* D8F1EC 80241F9C AE00006C */  sw        $zero, 0x6c($s0)
/* D8F1F0 80241FA0 AE220070 */  sw        $v0, 0x70($s1)
.L80241FA4:
/* D8F1F4 80241FA4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8F1F8 80241FA8 8FB10014 */  lw        $s1, 0x14($sp)
/* D8F1FC 80241FAC 8FB00010 */  lw        $s0, 0x10($sp)
/* D8F200 80241FB0 03E00008 */  jr        $ra
/* D8F204 80241FB4 27BD0020 */   addiu    $sp, $sp, 0x20
