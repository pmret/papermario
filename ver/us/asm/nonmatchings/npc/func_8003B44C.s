.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B44C
/* 1684C 8003B44C 8FA20010 */  lw        $v0, 0x10($sp)
/* 16850 8003B450 A4850308 */  sh        $a1, 0x308($a0)
/* 16854 8003B454 A486030A */  sh        $a2, 0x30a($a0)
/* 16858 8003B458 A487030C */  sh        $a3, 0x30c($a0)
/* 1685C 8003B45C 03E00008 */  jr        $ra
/* 16860 8003B460 A482030E */   sh       $v0, 0x30e($a0)
