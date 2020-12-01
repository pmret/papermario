.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0B14
/* 79FC4 800E0B14 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 79FC8 800E0B18 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 79FCC 800E0B1C 8C430004 */  lw        $v1, 4($v0)
/* 79FD0 800E0B20 2404FFEF */  addiu     $a0, $zero, -0x11
/* 79FD4 800E0B24 3C018011 */  lui       $at, %hi(D_8010C958)
/* 79FD8 800E0B28 AC20C958 */  sw        $zero, %lo(D_8010C958)($at)
/* 79FDC 800E0B2C 00641824 */  and       $v1, $v1, $a0
/* 79FE0 800E0B30 03E00008 */  jr        $ra
/* 79FE4 800E0B34 AC430004 */   sw       $v1, 4($v0)
