.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A133C_761C5C
/* 761C5C 802A133C 3C02802A */  lui       $v0, %hi(D_802A2C20)
/* 761C60 802A1340 8C422C20 */  lw        $v0, %lo(D_802A2C20)($v0)
/* 761C64 802A1344 54400002 */  bnel      $v0, $zero, .L802A1350
/* 761C68 802A1348 24020007 */   addiu    $v0, $zero, 7
/* 761C6C 802A134C 24020006 */  addiu     $v0, $zero, 6
.L802A1350:
/* 761C70 802A1350 AC820084 */  sw        $v0, 0x84($a0)
/* 761C74 802A1354 03E00008 */  jr        $ra
/* 761C78 802A1358 24020002 */   addiu    $v0, $zero, 2
/* 761C7C 802A135C 00000000 */  nop
