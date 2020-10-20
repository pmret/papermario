.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F58
/* 87AB38 80240F58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87AB3C 80240F5C AFBF0018 */  sw        $ra, 0x18($sp)
/* 87AB40 80240F60 0C00EAD2 */  jal       get_npc_safe
/* 87AB44 80240F64 2404FFFC */   addiu    $a0, $zero, -4
/* 87AB48 80240F68 3C0141F0 */  lui       $at, 0x41f0
/* 87AB4C 80240F6C 44810000 */  mtc1      $at, $f0
/* 87AB50 80240F70 C442003C */  lwc1      $f2, 0x3c($v0)
/* 87AB54 80240F74 46001080 */  add.s     $f2, $f2, $f0
/* 87AB58 80240F78 E7A00010 */  swc1      $f0, 0x10($sp)
/* 87AB5C 80240F7C 8C450038 */  lw        $a1, 0x38($v0)
/* 87AB60 80240F80 8C470040 */  lw        $a3, 0x40($v0)
/* 87AB64 80240F84 44061000 */  mfc1      $a2, $f2
/* 87AB68 80240F88 0C01BFBC */  jal       func_8006FEF0
/* 87AB6C 80240F8C 24040002 */   addiu    $a0, $zero, 2
/* 87AB70 80240F90 8FBF0018 */  lw        $ra, 0x18($sp)
/* 87AB74 80240F94 24020002 */  addiu     $v0, $zero, 2
/* 87AB78 80240F98 03E00008 */  jr        $ra
/* 87AB7C 80240F9C 27BD0020 */   addiu    $sp, $sp, 0x20
