.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055ED8
/* 312D8 80055ED8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 312DC 80055EDC 3C04800A */  lui       $a0, %hi(D_8009A620)
/* 312E0 80055EE0 8C84A620 */  lw        $a0, %lo(D_8009A620)($a0)
/* 312E4 80055EE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 312E8 80055EE8 0C012DC1 */  jal       func_8004B704
/* 312EC 80055EEC 24050001 */   addiu    $a1, $zero, 1
/* 312F0 80055EF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 312F4 80055EF4 03E00008 */  jr        $ra
/* 312F8 80055EF8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 312FC 80055EFC 00000000 */  nop
