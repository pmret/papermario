.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC37C_E2ECAC
/* E2ECAC 802BC37C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2ECB0 802BC380 3C05802C */  lui       $a1, %hi(D_802BCD40)
/* E2ECB4 802BC384 24A5CD40 */  addiu     $a1, $a1, %lo(D_802BCD40)
/* E2ECB8 802BC388 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2ECBC 802BC38C 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2ECC0 802BC390 00000000 */   nop
/* E2ECC4 802BC394 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2ECC8 802BC398 03E00008 */  jr        $ra
/* E2ECCC 802BC39C 27BD0018 */   addiu    $sp, $sp, 0x18
