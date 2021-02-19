.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkPartnerPosFunc
/* C69100 80240FD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C69104 80240FD4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C69108 80240FD8 0C00EAD2 */  jal       get_npc_safe
/* C6910C 80240FDC 2404FFFC */   addiu    $a0, $zero, -4
/* C69110 80240FE0 3C0141F0 */  lui       $at, 0x41f0
/* C69114 80240FE4 44810000 */  mtc1      $at, $f0
/* C69118 80240FE8 C442003C */  lwc1      $f2, 0x3c($v0)
/* C6911C 80240FEC 46001080 */  add.s     $f2, $f2, $f0
/* C69120 80240FF0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C69124 80240FF4 8C450038 */  lw        $a1, 0x38($v0)
/* C69128 80240FF8 8C470040 */  lw        $a3, 0x40($v0)
/* C6912C 80240FFC 44061000 */  mfc1      $a2, $f2
/* C69130 80241000 0C01BFBC */  jal       func_8006FEF0
/* C69134 80241004 24040004 */   addiu    $a0, $zero, 4
/* C69138 80241008 8FBF0018 */  lw        $ra, 0x18($sp)
/* C6913C 8024100C 24020002 */  addiu     $v0, $zero, 2
/* C69140 80241010 03E00008 */  jr        $ra
/* C69144 80241014 27BD0020 */   addiu    $sp, $sp, 0x20
