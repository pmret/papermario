.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A34_8032B4
/* 8032B4 80242A34 3C028026 */  lui       $v0, 0x8026
/* 8032B8 80242A38 8C422A68 */  lw        $v0, 0x2a68($v0)
/* 8032BC 80242A3C 8C43000C */  lw        $v1, 0xc($v0)
/* 8032C0 80242A40 24020002 */  addiu     $v0, $zero, 2
/* 8032C4 80242A44 03E00008 */  jr        $ra
/* 8032C8 80242A48 AC62001C */   sw       $v0, 0x1c($v1)
