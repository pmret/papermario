.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802381C8_7110B8
/* 7110B8 802381C8 3C02800E */  lui       $v0, %hi(gBattleStatus+0xD8)
/* 7110BC 802381CC 8C42C148 */  lw        $v0, %lo(gBattleStatus+0xD8)($v0)
/* 7110C0 802381D0 8C4301F4 */  lw        $v1, 0x1f4($v0)
/* 7110C4 802381D4 3C028028 */  lui       $v0, %hi(D_80283238)
/* 7110C8 802381D8 24423238 */  addiu     $v0, $v0, %lo(D_80283238)
/* 7110CC 802381DC AC620094 */  sw        $v0, 0x94($v1)
/* 7110D0 802381E0 03E00008 */  jr        $ra
/* 7110D4 802381E4 24020002 */   addiu    $v0, $zero, 2
