.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12FC_75E8CC
/* 75E8CC 802A12FC 3C02802A */  lui       $v0, %hi(D_802A4350)
/* 75E8D0 802A1300 8C424350 */  lw        $v0, %lo(D_802A4350)($v0)
/* 75E8D4 802A1304 54400002 */  bnel      $v0, $zero, .L802A1310
/* 75E8D8 802A1308 24020005 */   addiu    $v0, $zero, 5
/* 75E8DC 802A130C 24020004 */  addiu     $v0, $zero, 4
.L802A1310:
/* 75E8E0 802A1310 AC820084 */  sw        $v0, 0x84($a0)
/* 75E8E4 802A1314 03E00008 */  jr        $ra
/* 75E8E8 802A1318 24020002 */   addiu    $v0, $zero, 2
/* 75E8EC 802A131C 00000000 */  nop       
