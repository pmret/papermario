.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D70_893790
/* 893790 80240D70 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 893794 80240D74 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 893798 80240D78 8C430004 */  lw        $v1, 4($v0)
/* 89379C 80240D7C 3C040010 */  lui       $a0, 0x10
/* 8937A0 80240D80 00641825 */  or        $v1, $v1, $a0
/* 8937A4 80240D84 AC430004 */  sw        $v1, 4($v0)
/* 8937A8 80240D88 03E00008 */  jr        $ra
/* 8937AC 80240D8C 24020002 */   addiu    $v0, $zero, 2
