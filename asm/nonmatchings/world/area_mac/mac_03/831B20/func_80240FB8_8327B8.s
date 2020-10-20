.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB8_8327B8
/* 8327B8 80240FB8 3C028025 */  lui       $v0, 0x8025
/* 8327BC 80240FBC 8C4213F8 */  lw        $v0, 0x13f8($v0)
/* 8327C0 80240FC0 8C43000C */  lw        $v1, 0xc($v0)
/* 8327C4 80240FC4 24020001 */  addiu     $v0, $zero, 1
/* 8327C8 80240FC8 AC62001C */  sw        $v0, 0x1c($v1)
/* 8327CC 80240FCC 03E00008 */  jr        $ra
/* 8327D0 80240FD0 24020002 */   addiu    $v0, $zero, 2
