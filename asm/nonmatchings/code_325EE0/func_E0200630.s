.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200630
/* 326100 E0200630 3C01E020 */  lui       $at, %hi(D_E020071C)
/* 326104 E0200634 8C21071C */  lw        $at, %lo(D_E020071C)($at)
/* 326108 E0200638 00200008 */  jr        $at
/* 32610C E020063C 00000000 */   nop      
