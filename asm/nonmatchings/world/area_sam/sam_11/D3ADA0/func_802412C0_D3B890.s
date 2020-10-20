.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C0_D3B890
/* D3B890 802412C0 3C028025 */  lui       $v0, 0x8025
/* D3B894 802412C4 8C421478 */  lw        $v0, 0x1478($v0)
/* D3B898 802412C8 8C42000C */  lw        $v0, 0xc($v0)
/* D3B89C 802412CC AC40001C */  sw        $zero, 0x1c($v0)
/* D3B8A0 802412D0 03E00008 */  jr        $ra
/* D3B8A4 802412D4 24020002 */   addiu    $v0, $zero, 2
