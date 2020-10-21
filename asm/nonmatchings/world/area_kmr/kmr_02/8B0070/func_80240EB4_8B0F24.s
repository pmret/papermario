.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB4_8B0F24
/* 8B0F24 80240EB4 3C028025 */  lui       $v0, 0x8025
/* 8B0F28 80240EB8 8C427F50 */  lw        $v0, 0x7f50($v0)
/* 8B0F2C 80240EBC 8C43000C */  lw        $v1, 0xc($v0)
/* 8B0F30 80240EC0 24020002 */  addiu     $v0, $zero, 2
/* 8B0F34 80240EC4 03E00008 */  jr        $ra
/* 8B0F38 80240EC8 AC62001C */   sw       $v0, 0x1c($v1)
