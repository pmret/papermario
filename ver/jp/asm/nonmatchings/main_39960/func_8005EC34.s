.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EC34
/* 3A034 8005EC34 3C02800E */  lui       $v0, %hi(D_800DA424)
/* 3A038 8005EC38 03E00008 */  jr        $ra
/* 3A03C 8005EC3C 2442A424 */   addiu    $v0, $v0, %lo(D_800DA424)
