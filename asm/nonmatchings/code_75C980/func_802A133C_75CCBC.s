.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A133C_75CCBC
/* 75CCBC 802A133C 3C02802A */  lui       $v0, %hi(D_802A2C50)
/* 75CCC0 802A1340 8C422C50 */  lw        $v0, %lo(D_802A2C50)($v0)
/* 75CCC4 802A1344 54400002 */  bnel      $v0, $zero, .L802A1350
/* 75CCC8 802A1348 24020007 */   addiu    $v0, $zero, 7
/* 75CCCC 802A134C 24020006 */  addiu     $v0, $zero, 6
.L802A1350:
/* 75CCD0 802A1350 AC820084 */  sw        $v0, 0x84($a0)
/* 75CCD4 802A1354 03E00008 */  jr        $ra
/* 75CCD8 802A1358 24020002 */   addiu    $v0, $zero, 2
/* 75CCDC 802A135C 00000000 */  nop       
