.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056254
/* 31654 80056254 3C038008 */  lui       $v1, %hi(D_80078E20)
/* 31658 80056258 24638E20 */  addiu     $v1, $v1, %lo(D_80078E20)
/* 3165C 8005625C 8C620000 */  lw        $v0, ($v1)
/* 31660 80056260 54400001 */  bnel      $v0, $zero, .L80056268
/* 31664 80056264 AC600000 */   sw       $zero, ($v1)
.L80056268:
/* 31668 80056268 03E00008 */  jr        $ra
/* 3166C 8005626C 00000000 */   nop
