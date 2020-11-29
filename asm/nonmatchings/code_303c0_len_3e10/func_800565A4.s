.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800565A4
/* 319A4 800565A4 3C038008 */  lui       $v1, %hi(D_80078E50)
/* 319A8 800565A8 24638E50 */  addiu     $v1, $v1, %lo(D_80078E50)
/* 319AC 800565AC 8C620000 */  lw        $v0, ($v1)
/* 319B0 800565B0 54400001 */  bnel      $v0, $zero, .L800565B8
/* 319B4 800565B4 AC600000 */   sw       $zero, ($v1)
.L800565B8:
/* 319B8 800565B8 03E00008 */  jr        $ra
/* 319BC 800565BC 00000000 */   nop      
