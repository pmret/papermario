.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E584
/* 17CE64 8024E584 3C02802A */  lui       $v0, %hi(D_8029F29C)
/* 17CE68 8024E588 8042F29C */  lb        $v0, %lo(D_8029F29C)($v0)
/* 17CE6C 8024E58C 03E00008 */  jr        $ra
/* 17CE70 8024E590 00000000 */   nop
