.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EC40
/* 3A040 8005EC40 3C01800E */  lui       $at, %hi(D_800DAA9D)
/* 3A044 8005EC44 03E00008 */  jr        $ra
/* 3A048 8005EC48 A024AA9D */   sb       $a0, %lo(D_800DAA9D)($at)
