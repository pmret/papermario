.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_ED8E20
/* ED8E20 80240000 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* ED8E24 80240004 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* ED8E28 80240008 8C430004 */  lw        $v1, 4($v0)
/* ED8E2C 8024000C 3C040010 */  lui       $a0, 0x10
/* ED8E30 80240010 00641825 */  or        $v1, $v1, $a0
/* ED8E34 80240014 AC430004 */  sw        $v1, 4($v0)
/* ED8E38 80240018 03E00008 */  jr        $ra
/* ED8E3C 8024001C 24020002 */   addiu    $v0, $zero, 2
