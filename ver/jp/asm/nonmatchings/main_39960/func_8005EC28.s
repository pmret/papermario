.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EC28
/* 3A028 8005EC28 3C02800E */  lui       $v0, %hi(D_800DA45C)
/* 3A02C 8005EC2C 03E00008 */  jr        $ra
/* 3A030 8005EC30 2442A45C */   addiu    $v0, $v0, %lo(D_800DA45C)
