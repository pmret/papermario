.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F384
/* 1A784 8003F384 24020001 */  addiu     $v0, $zero, 1
/* 1A788 8003F388 3C01800A */  lui       $at, 0x800a
/* 1A78C 8003F38C A4220BB8 */  sh        $v0, 0xbb8($at)
/* 1A790 8003F390 03E00008 */  jr        $ra
/* 1A794 8003F394 24020002 */   addiu    $v0, $zero, 2
