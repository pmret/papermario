.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_718A8C
/* 718A8C 802A123C 3C02800E */  lui       $v0, %hi(gBattleStatus+0xD8)
/* 718A90 802A1240 8C42C148 */  lw        $v0, %lo(gBattleStatus+0xD8)($v0)
/* 718A94 802A1244 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 718A98 802A1248 AFB20018 */  sw        $s2, 0x18($sp)
/* 718A9C 802A124C 3C128016 */  lui       $s2, %hi(gCollisionStatus)
/* 718AA0 802A1250 2652A550 */  addiu     $s2, $s2, %lo(gCollisionStatus)
/* 718AA4 802A1254 AFB10014 */  sw        $s1, 0x14($sp)
/* 718AA8 802A1258 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 718AAC 802A125C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 718AB0 802A1260 AFBF001C */  sw        $ra, 0x1c($sp)
/* 718AB4 802A1264 AFB00010 */  sw        $s0, 0x10($sp)
/* 718AB8 802A1268 C4400188 */  lwc1      $f0, 0x188($v0)
/* 718ABC 802A126C 3C013FF0 */  lui       $at, 0x3ff0
/* 718AC0 802A1270 44811800 */  mtc1      $at, $f3
/* 718AC4 802A1274 44801000 */  mtc1      $zero, $f2
/* 718AC8 802A1278 46000021 */  cvt.d.s   $f0, $f0
/* 718ACC 802A127C 46220032 */  c.eq.d    $f0, $f2
/* 718AD0 802A1280 00000000 */  nop       
/* 718AD4 802A1284 45000011 */  bc1f      .L802A12CC
/* 718AD8 802A1288 24020002 */   addiu    $v0, $zero, 2
/* 718ADC 802A128C 8C9000AC */  lw        $s0, 0xac($a0)
/* 718AE0 802A1290 0C04417A */  jal       get_entity_by_index
/* 718AE4 802A1294 0200202D */   daddu    $a0, $s0, $zero
/* 718AE8 802A1298 8E220000 */  lw        $v0, ($s1)
/* 718AEC 802A129C 36104000 */  ori       $s0, $s0, 0x4000
/* 718AF0 802A12A0 A6500008 */  sh        $s0, 8($s2)
/* 718AF4 802A12A4 34420002 */  ori       $v0, $v0, 2
/* 718AF8 802A12A8 0C043DB4 */  jal       update_entities
/* 718AFC 802A12AC AE220000 */   sw       $v0, ($s1)
/* 718B00 802A12B0 24020002 */  addiu     $v0, $zero, 2
/* 718B04 802A12B4 2403FFFF */  addiu     $v1, $zero, -1
/* 718B08 802A12B8 A6430008 */  sh        $v1, 8($s2)
/* 718B0C 802A12BC 8E230000 */  lw        $v1, ($s1)
/* 718B10 802A12C0 2404FFFD */  addiu     $a0, $zero, -3
/* 718B14 802A12C4 00641824 */  and       $v1, $v1, $a0
/* 718B18 802A12C8 AE230000 */  sw        $v1, ($s1)
.L802A12CC:
/* 718B1C 802A12CC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 718B20 802A12D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 718B24 802A12D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 718B28 802A12D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 718B2C 802A12DC 03E00008 */  jr        $ra
/* 718B30 802A12E0 27BD0020 */   addiu    $sp, $sp, 0x20
