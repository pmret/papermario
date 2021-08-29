.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405BC_AFE0FC
/* AFE0FC 802405BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFE100 802405C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFE104 802405C4 8C82000C */  lw        $v0, 0xc($a0)
/* AFE108 802405C8 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* AFE10C 802405CC 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* AFE110 802405D0 0C0B2026 */  jal       evt_set_variable
/* AFE114 802405D4 8C450000 */   lw       $a1, ($v0)
/* AFE118 802405D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFE11C 802405DC 24020002 */  addiu     $v0, $zero, 2
/* AFE120 802405E0 03E00008 */  jr        $ra
/* AFE124 802405E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* AFE128 802405E8 00000000 */  nop
/* AFE12C 802405EC 00000000 */  nop
