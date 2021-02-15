.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12FC_7598AC
/* 7598AC 802A12FC 3C02802A */  lui       $v0, %hi(D_802A43D0)
/* 7598B0 802A1300 8C4243D0 */  lw        $v0, %lo(D_802A43D0)($v0)
/* 7598B4 802A1304 54400002 */  bnel      $v0, $zero, .L802A1310
/* 7598B8 802A1308 24020005 */   addiu    $v0, $zero, 5
/* 7598BC 802A130C 24020004 */  addiu     $v0, $zero, 4
.L802A1310:
/* 7598C0 802A1310 AC820084 */  sw        $v0, 0x84($a0)
/* 7598C4 802A1314 03E00008 */  jr        $ra
/* 7598C8 802A1318 24020002 */   addiu    $v0, $zero, 2
/* 7598CC 802A131C 00000000 */  nop
