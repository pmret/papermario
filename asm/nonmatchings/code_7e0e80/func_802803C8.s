.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802803C8
/* 7E1248 802803C8 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 7E124C 802803CC 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 7E1250 802803D0 AC80008C */  sw        $zero, 0x8c($a0)
/* 7E1254 802803D4 80A300B4 */  lb        $v1, 0xb4($a1)
/* 7E1258 802803D8 24020004 */  addiu     $v0, $zero, 4
/* 7E125C 802803DC 10620008 */  beq       $v1, $v0, .L80280400
/* 7E1260 802803E0 24020008 */   addiu    $v0, $zero, 8
/* 7E1264 802803E4 10620006 */  beq       $v1, $v0, .L80280400
/* 7E1268 802803E8 00000000 */   nop      
/* 7E126C 802803EC 8CA20000 */  lw        $v0, ($a1)
/* 7E1270 802803F0 30420100 */  andi      $v0, $v0, 0x100
/* 7E1274 802803F4 14400004 */  bnez      $v0, .L80280408
/* 7E1278 802803F8 24020001 */   addiu    $v0, $zero, 1
/* 7E127C 802803FC AC82008C */  sw        $v0, 0x8c($a0)
.L80280400:
/* 7E1280 80280400 03E00008 */  jr        $ra
/* 7E1284 80280404 24020002 */   addiu    $v0, $zero, 2
.L80280408:
/* 7E1288 80280408 03E00008 */  jr        $ra
/* 7E128C 8028040C 24020002 */   addiu    $v0, $zero, 2
