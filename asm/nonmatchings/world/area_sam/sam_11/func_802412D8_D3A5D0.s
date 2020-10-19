.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412D8_D3B8A8
/* D3B8A8 802412D8 3C028025 */  lui       $v0, 0x8025
/* D3B8AC 802412DC 8C421478 */  lw        $v0, 0x1478($v0)
/* D3B8B0 802412E0 8C43000C */  lw        $v1, 0xc($v0)
/* D3B8B4 802412E4 24020001 */  addiu     $v0, $zero, 1
/* D3B8B8 802412E8 AC62001C */  sw        $v0, 0x1c($v1)
/* D3B8BC 802412EC 03E00008 */  jr        $ra
/* D3B8C0 802412F0 24020002 */   addiu    $v0, $zero, 2
