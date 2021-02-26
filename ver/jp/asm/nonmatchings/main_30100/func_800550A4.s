.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800550A4
/* 304A4 800550A4 3C03800A */  lui       $v1, %hi(D_8009A620)
/* 304A8 800550A8 8C63A620 */  lw        $v1, %lo(D_8009A620)($v1)
/* 304AC 800550AC 24020001 */  addiu     $v0, $zero, 1
/* 304B0 800550B0 03E00008 */  jr        $ra
/* 304B4 800550B4 AC620168 */   sw       $v0, 0x168($v1)
