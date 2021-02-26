.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B10C
/* 1650C 8003B10C 8FA20010 */  lw        $v0, 0x10($sp)
/* 16510 8003B110 A4850308 */  sh        $a1, 0x308($a0)
/* 16514 8003B114 A486030A */  sh        $a2, 0x30a($a0)
/* 16518 8003B118 A487030C */  sh        $a3, 0x30c($a0)
/* 1651C 8003B11C 03E00008 */  jr        $ra
/* 16520 8003B120 A482030E */   sh       $v0, 0x30e($a0)
