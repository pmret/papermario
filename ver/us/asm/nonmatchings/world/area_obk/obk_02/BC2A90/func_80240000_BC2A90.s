.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BC2A90
/* BC2A90 80240000 AC800074 */  sw        $zero, 0x74($a0)
/* BC2A94 80240004 03E00008 */  jr        $ra
/* BC2A98 80240008 24020002 */   addiu    $v0, $zero, 2
