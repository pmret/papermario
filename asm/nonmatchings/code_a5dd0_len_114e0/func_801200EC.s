.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801200EC
/* B67EC 801200EC 2402F7FF */  addiu     $v0, $zero, -0x801
/* B67F0 801200F0 00822024 */  and       $a0, $a0, $v0
/* B67F4 801200F4 3C028015 */  lui       $v0, %hi(gCurrentAnimMeshListPtr)
/* B67F8 801200F8 8C423A40 */  lw        $v0, %lo(gCurrentAnimMeshListPtr)($v0)
/* B67FC 801200FC 00042080 */  sll       $a0, $a0, 2
/* B6800 80120100 00822021 */  addu      $a0, $a0, $v0
/* B6804 80120104 8C830000 */  lw        $v1, ($a0)
/* B6808 80120108 8C620000 */  lw        $v0, ($v1)
/* B680C 8012010C 00451025 */  or        $v0, $v0, $a1
/* B6810 80120110 03E00008 */  jr        $ra
/* B6814 80120114 AC620000 */   sw       $v0, ($v1)
