.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD4_8327D4
/* 8327D4 80240FD4 3C028025 */  lui       $v0, 0x8025
/* 8327D8 80240FD8 8C4213F8 */  lw        $v0, 0x13f8($v0)
/* 8327DC 80240FDC 8C43000C */  lw        $v1, 0xc($v0)
/* 8327E0 80240FE0 24020002 */  addiu     $v0, $zero, 2
/* 8327E4 80240FE4 03E00008 */  jr        $ra
/* 8327E8 80240FE8 AC62001C */   sw       $v0, 0x1c($v1)
