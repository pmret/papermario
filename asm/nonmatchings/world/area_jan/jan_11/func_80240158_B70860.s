.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_B709B8
/* B709B8 80240158 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B709BC 8024015C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B709C0 80240160 8C430004 */  lw        $v1, 4($v0)
/* B709C4 80240164 3C040010 */  lui       $a0, 0x10
/* B709C8 80240168 00641825 */  or        $v1, $v1, $a0
/* B709CC 8024016C AC430004 */  sw        $v1, 4($v0)
/* B709D0 80240170 03E00008 */  jr        $ra
/* B709D4 80240174 24020002 */   addiu    $v0, $zero, 2
