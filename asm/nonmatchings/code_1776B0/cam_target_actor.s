.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel cam_target_actor
/* 17CD1C 8024E43C 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CD20 8024E440 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CD24 8024E444 14400003 */  bnez      $v0, .L8024E454
/* 17CD28 8024E448 00000000 */   nop
/* 17CD2C 8024E44C 3C01802A */  lui       $at, %hi(D_8029F27C)
/* 17CD30 8024E450 A424F27C */  sh        $a0, %lo(D_8029F27C)($at)
.L8024E454:
/* 17CD34 8024E454 03E00008 */  jr        $ra
/* 17CD38 8024E458 00000000 */   nop
