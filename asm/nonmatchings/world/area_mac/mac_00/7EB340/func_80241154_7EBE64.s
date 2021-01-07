.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241154_7EBE64
/* 7EBE64 80241154 3C028025 */  lui       $v0, %hi(D_80255B98)
/* 7EBE68 80241158 8C425B98 */  lw        $v0, %lo(D_80255B98)($v0)
/* 7EBE6C 8024115C 8C43000C */  lw        $v1, 0xc($v0)
/* 7EBE70 80241160 24020002 */  addiu     $v0, $zero, 2
/* 7EBE74 80241164 03E00008 */  jr        $ra
/* 7EBE78 80241168 AC62001C */   sw       $v0, 0x1c($v1)
