.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802549A0
/* 183280 802549A0 3C02800E */  lui       $v0, 0x800e
/* 183284 802549A4 8C42C148 */  lw        $v0, -0x3eb8($v0)
/* 183288 802549A8 8C4201F4 */  lw        $v0, 0x1f4($v0)
/* 18328C 802549AC 8C4300C0 */  lw        $v1, 0xc0($v0)
/* 183290 802549B0 24020014 */  addiu     $v0, $zero, 0x14
/* 183294 802549B4 A06007DB */  sb        $zero, 0x7db($v1)
/* 183298 802549B8 03E00008 */  jr        $ra
/* 18329C 802549BC A06208AC */   sb       $v0, 0x8ac($v1)
