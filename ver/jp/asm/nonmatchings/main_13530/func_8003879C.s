.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003879C
/* 13B9C 8003879C 2402F7FF */  addiu     $v0, $zero, -0x801
/* 13BA0 800387A0 00822024 */  and       $a0, $a0, $v0
/* 13BA4 800387A4 3C02800A */  lui       $v0, %hi(D_8009E9A0)
/* 13BA8 800387A8 8C42E9A0 */  lw        $v0, %lo(D_8009E9A0)($v0)
/* 13BAC 800387AC 00042080 */  sll       $a0, $a0, 2
/* 13BB0 800387B0 00822021 */  addu      $a0, $a0, $v0
/* 13BB4 800387B4 03E00008 */  jr        $ra
/* 13BB8 800387B8 8C820000 */   lw       $v0, ($a0)
