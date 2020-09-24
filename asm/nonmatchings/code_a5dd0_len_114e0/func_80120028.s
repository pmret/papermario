.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120028
/* B6728 80120028 24020001 */  addiu     $v0, $zero, 1
/* B672C 8012002C 3C018015 */  lui       $at, 0x8015
/* B6730 80120030 AC223A44 */  sw        $v0, 0x3a44($at)
/* B6734 80120034 03E00008 */  jr        $ra
/* B6738 80120038 00000000 */   nop      
