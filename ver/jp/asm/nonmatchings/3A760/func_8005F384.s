.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F384
/* 3A784 8005F384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A788 8005F388 3C048009 */  lui       $a0, %hi(D_80093CA0)
/* 3A78C 8005F38C 24843CA0 */  addiu     $a0, $a0, %lo(D_80093CA0)
/* 3A790 8005F390 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A794 8005F394 0C018118 */  jal       func_80060460
/* 3A798 8005F398 00000000 */   nop
/* 3A79C 8005F39C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A7A0 8005F3A0 03E00008 */  jr        $ra
/* 3A7A4 8005F3A4 27BD0018 */   addiu    $sp, $sp, 0x18
