.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F360
/* 3A760 8005F360 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A764 8005F364 3C048009 */  lui       $a0, %hi(D_80093CA0)
/* 3A768 8005F368 24843CA0 */  addiu     $a0, $a0, %lo(D_80093CA0)
/* 3A76C 8005F36C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A770 8005F370 0C0180F0 */  jal       func_800603C0
/* 3A774 8005F374 00000000 */   nop
/* 3A778 8005F378 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A77C 8005F37C 03E00008 */  jr        $ra
/* 3A780 8005F380 27BD0018 */   addiu    $sp, $sp, 0x18
