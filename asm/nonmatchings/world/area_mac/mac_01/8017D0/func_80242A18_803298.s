.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A18_803298
/* 803298 80242A18 3C028026 */  lui       $v0, 0x8026
/* 80329C 80242A1C 8C422A68 */  lw        $v0, 0x2a68($v0)
/* 8032A0 80242A20 8C43000C */  lw        $v1, 0xc($v0)
/* 8032A4 80242A24 24020001 */  addiu     $v0, $zero, 1
/* 8032A8 80242A28 AC62001C */  sw        $v0, 0x1c($v1)
/* 8032AC 80242A2C 03E00008 */  jr        $ra
/* 8032B0 80242A30 24020002 */   addiu    $v0, $zero, 2
