.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D50
/* 8EDB70 80241D50 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8EDB74 80241D54 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8EDB78 80241D58 8C430004 */  lw        $v1, 4($v0)
/* 8EDB7C 80241D5C 3C040010 */  lui       $a0, 0x10
/* 8EDB80 80241D60 00641825 */  or        $v1, $v1, $a0
/* 8EDB84 80241D64 AC430004 */  sw        $v1, 4($v0)
/* 8EDB88 80241D68 03E00008 */  jr        $ra
/* 8EDB8C 80241D6C 24020002 */   addiu    $v0, $zero, 2
