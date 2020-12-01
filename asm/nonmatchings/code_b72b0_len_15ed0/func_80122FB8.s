.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80122FB8
/* B96B8 80122FB8 2402F7FF */  addiu     $v0, $zero, -0x801
/* B96BC 80122FBC 00822024 */  and       $a0, $a0, $v0
/* B96C0 80122FC0 3C028015 */  lui       $v0, %hi(D_80154370)
/* B96C4 80122FC4 8C424370 */  lw        $v0, %lo(D_80154370)($v0)
/* B96C8 80122FC8 00042080 */  sll       $a0, $a0, 2
/* B96CC 80122FCC 00822021 */  addu      $a0, $a0, $v0
/* B96D0 80122FD0 8C840000 */  lw        $a0, ($a0)
/* B96D4 80122FD4 8C820000 */  lw        $v0, ($a0)
/* B96D8 80122FD8 2403FFF0 */  addiu     $v1, $zero, -0x10
/* B96DC 80122FDC 00431024 */  and       $v0, $v0, $v1
/* B96E0 80122FE0 00451025 */  or        $v0, $v0, $a1
/* B96E4 80122FE4 03E00008 */  jr        $ra
/* B96E8 80122FE8 AC820000 */   sw       $v0, ($a0)
