.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D05730
/* D05730 80240000 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D05734 80240004 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D05738 80240008 8C430004 */  lw        $v1, 4($v0)
/* D0573C 8024000C 3C040010 */  lui       $a0, 0x10
/* D05740 80240010 00641825 */  or        $v1, $v1, $a0
/* D05744 80240014 AC430004 */  sw        $v1, 4($v0)
/* D05748 80240018 03E00008 */  jr        $ra
/* D0574C 8024001C 24020002 */   addiu    $v0, $zero, 2
