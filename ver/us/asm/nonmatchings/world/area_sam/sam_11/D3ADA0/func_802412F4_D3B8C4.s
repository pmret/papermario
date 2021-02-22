.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412F4_D3B8C4
/* D3B8C4 802412F4 3C028025 */  lui       $v0, %hi(D_80251478)
/* D3B8C8 802412F8 8C421478 */  lw        $v0, %lo(D_80251478)($v0)
/* D3B8CC 802412FC 8C43000C */  lw        $v1, 0xc($v0)
/* D3B8D0 80241300 24020002 */  addiu     $v0, $zero, 2
/* D3B8D4 80241304 03E00008 */  jr        $ra
/* D3B8D8 80241308 AC62001C */   sw       $v0, 0x1c($v1)
