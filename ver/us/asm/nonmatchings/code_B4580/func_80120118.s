.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120118
/* B6818 80120118 2402F7FF */  addiu     $v0, $zero, -0x801
/* B681C 8012011C 00822024 */  and       $a0, $a0, $v0
/* B6820 80120120 3C028015 */  lui       $v0, %hi(gCurrentAnimMeshListPtr)
/* B6824 80120124 8C423A40 */  lw        $v0, %lo(gCurrentAnimMeshListPtr)($v0)
/* B6828 80120128 00042080 */  sll       $a0, $a0, 2
/* B682C 8012012C 00822021 */  addu      $a0, $a0, $v0
/* B6830 80120130 8C830000 */  lw        $v1, ($a0)
/* B6834 80120134 8C620000 */  lw        $v0, ($v1)
/* B6838 80120138 00052827 */  nor       $a1, $zero, $a1
/* B683C 8012013C 00451024 */  and       $v0, $v0, $a1
/* B6840 80120140 03E00008 */  jr        $ra
/* B6844 80120144 AC620000 */   sw       $v0, ($v1)
