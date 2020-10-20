.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426D8
/* B372A8 802426D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B372AC 802426DC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B372B0 802426E0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B372B4 802426E4 3C05FE36 */  lui       $a1, 0xfe36
/* B372B8 802426E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* B372BC 802426EC 80460075 */  lb        $a2, 0x75($v0)
/* B372C0 802426F0 0C0B2026 */  jal       set_variable
/* B372C4 802426F4 34A53C80 */   ori      $a1, $a1, 0x3c80
/* B372C8 802426F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B372CC 802426FC 24020002 */  addiu     $v0, $zero, 2
/* B372D0 80242700 03E00008 */  jr        $ra
/* B372D4 80242704 27BD0018 */   addiu    $sp, $sp, 0x18
