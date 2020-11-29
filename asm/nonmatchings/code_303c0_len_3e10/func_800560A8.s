.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800560A8
/* 314A8 800560A8 3C03800A */  lui       $v1, %hi(D_8009A5C0)
/* 314AC 800560AC 8C63A5C0 */  lw        $v1, %lo(D_8009A5C0)($v1)
/* 314B0 800560B0 24020001 */  addiu     $v0, $zero, 1
/* 314B4 800560B4 03E00008 */  jr        $ra
/* 314B8 800560B8 AC62009C */   sw       $v0, 0x9c($v1)
