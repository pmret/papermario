.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405B0_B1BB20
/* B1BB20 802405B0 3C048024 */  lui       $a0, %hi(func_80240FD0_A171F0)
/* B1BB24 802405B4 8C840FD0 */  lw        $a0, %lo(func_80240FD0_A171F0)($a0)
/* B1BB28 802405B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1BB2C 802405BC AFBF0010 */  sw        $ra, 0x10($sp)
/* B1BB30 802405C0 0C047A2F */  jal       func_8011E8BC
/* B1BB34 802405C4 00000000 */   nop
/* B1BB38 802405C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B1BB3C 802405CC 03E00008 */  jr        $ra
/* B1BB40 802405D0 27BD0018 */   addiu    $sp, $sp, 0x18
