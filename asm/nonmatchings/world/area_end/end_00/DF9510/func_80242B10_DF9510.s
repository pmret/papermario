.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B10_DF9510
/* DF9510 80242B10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF9514 80242B14 AFBF0010 */  sw        $ra, 0x10($sp)
/* DF9518 80242B18 8C82000C */  lw        $v0, 0xc($a0)
/* DF951C 80242B1C 0C0B1EAF */  jal       get_variable
/* DF9520 80242B20 8C450000 */   lw       $a1, ($v0)
/* DF9524 80242B24 8FBF0010 */  lw        $ra, 0x10($sp)
/* DF9528 80242B28 3C018025 */  lui       $at, %hi(D_80249D60)
/* DF952C 80242B2C AC229D60 */  sw        $v0, %lo(D_80249D60)($at)
/* DF9530 80242B30 24020002 */  addiu     $v0, $zero, 2
/* DF9534 80242B34 03E00008 */  jr        $ra
/* DF9538 80242B38 27BD0018 */   addiu    $sp, $sp, 0x18
/* DF953C 80242B3C 00000000 */  nop       
