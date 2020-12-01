.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E6C_A27D3C
/* A27D3C 80240E6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A27D40 80240E70 3C048024 */  lui       $a0, %hi(D_80243284)
/* A27D44 80240E74 24843284 */  addiu     $a0, $a0, %lo(D_80243284)
/* A27D48 80240E78 AFBF0010 */  sw        $ra, 0x10($sp)
/* A27D4C 80240E7C 0C0902F4 */  jal       func_80240BD0_A27AA0
/* A27D50 80240E80 00000000 */   nop      
/* A27D54 80240E84 8FBF0010 */  lw        $ra, 0x10($sp)
/* A27D58 80240E88 03E00008 */  jr        $ra
/* A27D5C 80240E8C 27BD0018 */   addiu    $sp, $sp, 0x18
