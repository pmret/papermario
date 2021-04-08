.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055D58
/* 31158 80055D58 3C03800A */  lui       $v1, %hi(D_8009A5A0)
/* 3115C 80055D5C 8C63A5A0 */  lw        $v1, %lo(D_8009A5A0)($v1)
/* 31160 80055D60 24020001 */  addiu     $v0, $zero, 1
/* 31164 80055D64 03E00008 */  jr        $ra
/* 31168 80055D68 AC62009C */   sw       $v0, 0x9c($v1)
