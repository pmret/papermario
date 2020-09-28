.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80263268
/* 191B48 80263268 3C07800E */  lui       $a3, %hi(gBattleStatus)
/* 191B4C 8026326C 24E7C070 */  addiu     $a3, $a3, %lo(gBattleStatus)
/* 191B50 80263270 8CE600DC */  lw        $a2, 0xdc($a3)
/* 191B54 80263274 3C088011 */  lui       $t0, %hi(gPlayerData)
/* 191B58 80263278 2508F290 */  addiu     $t0, $t0, %lo(gPlayerData)
/* 191B5C 8026327C 10C0001C */  beqz      $a2, .L802632F0
/* 191B60 80263280 A0E0007C */   sb       $zero, 0x7c($a3)
/* 191B64 80263284 24020001 */  addiu     $v0, $zero, 1
/* 191B68 80263288 A0E2007C */  sb        $v0, 0x7c($a3)
/* 191B6C 8026328C 0000282D */  daddu     $a1, $zero, $zero
/* 191B70 80263290 00A0202D */  daddu     $a0, $a1, $zero
/* 191B74 80263294 0100182D */  daddu     $v1, $t0, $zero
.L80263298:
/* 191B78 80263298 90620014 */  lbu       $v0, 0x14($v1)
/* 191B7C 8026329C 54400001 */  bnel      $v0, $zero, .L802632A4
/* 191B80 802632A0 24A50001 */   addiu    $a1, $a1, 1
.L802632A4:
/* 191B84 802632A4 24840001 */  addiu     $a0, $a0, 1
/* 191B88 802632A8 2882000C */  slti      $v0, $a0, 0xc
/* 191B8C 802632AC 1440FFFA */  bnez      $v0, .L80263298
/* 191B90 802632B0 24630008 */   addiu    $v1, $v1, 8
/* 191B94 802632B4 28A20002 */  slti      $v0, $a1, 2
/* 191B98 802632B8 1440000E */  bnez      $v0, .L802632F4
/* 191B9C 802632BC 2402FFFF */   addiu    $v0, $zero, -1
/* 191BA0 802632C0 80C30216 */  lb        $v1, 0x216($a2)
/* 191BA4 802632C4 2402000D */  addiu     $v0, $zero, 0xd
/* 191BA8 802632C8 14620003 */  bne       $v1, $v0, .L802632D8
/* 191BAC 802632CC 24020007 */   addiu    $v0, $zero, 7
.L802632D0:
/* 191BB0 802632D0 03E00008 */  jr        $ra
/* 191BB4 802632D4 A0E0007C */   sb       $zero, 0x7c($a3)
.L802632D8:
/* 191BB8 802632D8 80C30210 */  lb        $v1, 0x210($a2)
/* 191BBC 802632DC 1062FFFC */  beq       $v1, $v0, .L802632D0
/* 191BC0 802632E0 24020005 */   addiu    $v0, $zero, 5
/* 191BC4 802632E4 81030012 */  lb        $v1, 0x12($t0)
/* 191BC8 802632E8 14620003 */  bne       $v1, $v0, .L802632F8
/* 191BCC 802632EC 00000000 */   nop      
.L802632F0:
/* 191BD0 802632F0 2402FFFF */  addiu     $v0, $zero, -1
.L802632F4:
/* 191BD4 802632F4 A0E2007C */  sb        $v0, 0x7c($a3)
.L802632F8:
/* 191BD8 802632F8 03E00008 */  jr        $ra
/* 191BDC 802632FC 00000000 */   nop      
