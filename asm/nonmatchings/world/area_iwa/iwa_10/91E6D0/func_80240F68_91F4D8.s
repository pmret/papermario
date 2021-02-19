.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_10_UnkPartnerPosFunc
/* 91F4D8 80240F68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91F4DC 80240F6C AFBF0018 */  sw        $ra, 0x18($sp)
/* 91F4E0 80240F70 0C00EAD2 */  jal       get_npc_safe
/* 91F4E4 80240F74 2404FFFC */   addiu    $a0, $zero, -4
/* 91F4E8 80240F78 3C0141F0 */  lui       $at, 0x41f0
/* 91F4EC 80240F7C 44810000 */  mtc1      $at, $f0
/* 91F4F0 80240F80 C442003C */  lwc1      $f2, 0x3c($v0)
/* 91F4F4 80240F84 46001080 */  add.s     $f2, $f2, $f0
/* 91F4F8 80240F88 E7A00010 */  swc1      $f0, 0x10($sp)
/* 91F4FC 80240F8C 8C450038 */  lw        $a1, 0x38($v0)
/* 91F500 80240F90 8C470040 */  lw        $a3, 0x40($v0)
/* 91F504 80240F94 44061000 */  mfc1      $a2, $f2
/* 91F508 80240F98 0C01BFBC */  jal       func_8006FEF0
/* 91F50C 80240F9C 24040002 */   addiu    $a0, $zero, 2
/* 91F510 80240FA0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91F514 80240FA4 24020002 */  addiu     $v0, $zero, 2
/* 91F518 80240FA8 03E00008 */  jr        $ra
/* 91F51C 80240FAC 27BD0020 */   addiu    $sp, $sp, 0x20
