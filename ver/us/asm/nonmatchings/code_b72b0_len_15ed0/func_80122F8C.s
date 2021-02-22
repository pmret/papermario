.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80122F8C
/* B968C 80122F8C 2402F7FF */  addiu     $v0, $zero, -0x801
/* B9690 80122F90 00822024 */  and       $a0, $a0, $v0
/* B9694 80122F94 3C028015 */  lui       $v0, %hi(gCurrentEntityModelList)
/* B9698 80122F98 8C424370 */  lw        $v0, %lo(gCurrentEntityModelList)($v0)
/* B969C 80122F9C 00042080 */  sll       $a0, $a0, 2
/* B96A0 80122FA0 00822021 */  addu      $a0, $a0, $v0
/* B96A4 80122FA4 8C830000 */  lw        $v1, ($a0)
/* B96A8 80122FA8 8C620000 */  lw        $v0, ($v1)
/* B96AC 80122FAC 00451025 */  or        $v0, $v0, $a1
/* B96B0 80122FB0 03E00008 */  jr        $ra
/* B96B4 80122FB4 AC620000 */   sw       $v0, ($v1)
