.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1318_718B68
/* 718B68 802A1318 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 718B6C 802A131C AFBF0014 */  sw        $ra, 0x14($sp)
/* 718B70 802A1320 AFB00010 */  sw        $s0, 0x10($sp)
/* 718B74 802A1324 8C8400AC */  lw        $a0, 0xac($a0)
/* 718B78 802A1328 3C10800E */  lui       $s0, %hi(gBattleStatus+0xD8)
/* 718B7C 802A132C 8E10C148 */  lw        $s0, %lo(gBattleStatus+0xD8)($s0)
/* 718B80 802A1330 0C04417A */  jal       get_entity_by_index
/* 718B84 802A1334 00000000 */   nop      
/* 718B88 802A1338 C6000188 */  lwc1      $f0, 0x188($s0)
/* 718B8C 802A133C E4400054 */  swc1      $f0, 0x54($v0)
/* 718B90 802A1340 C6000188 */  lwc1      $f0, 0x188($s0)
/* 718B94 802A1344 E4400058 */  swc1      $f0, 0x58($v0)
/* 718B98 802A1348 C6000188 */  lwc1      $f0, 0x188($s0)
/* 718B9C 802A134C E440005C */  swc1      $f0, 0x5c($v0)
/* 718BA0 802A1350 C6000188 */  lwc1      $f0, 0x188($s0)
/* 718BA4 802A1354 3C013FF0 */  lui       $at, 0x3ff0
/* 718BA8 802A1358 44811800 */  mtc1      $at, $f3
/* 718BAC 802A135C 44801000 */  mtc1      $zero, $f2
/* 718BB0 802A1360 46000021 */  cvt.d.s   $f0, $f0
/* 718BB4 802A1364 46220032 */  c.eq.d    $f0, $f2
/* 718BB8 802A1368 00000000 */  nop       
/* 718BBC 802A136C 45010007 */  bc1t      .L802A138C
/* 718BC0 802A1370 00000000 */   nop      
/* 718BC4 802A1374 C440004C */  lwc1      $f0, 0x4c($v0)
/* 718BC8 802A1378 3C014120 */  lui       $at, 0x4120
/* 718BCC 802A137C 44811000 */  mtc1      $at, $f2
/* 718BD0 802A1380 00000000 */  nop       
/* 718BD4 802A1384 46020001 */  sub.s     $f0, $f0, $f2
/* 718BD8 802A1388 E440004C */  swc1      $f0, 0x4c($v0)
.L802A138C:
/* 718BDC 802A138C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 718BE0 802A1390 8FB00010 */  lw        $s0, 0x10($sp)
/* 718BE4 802A1394 24020002 */  addiu     $v0, $zero, 2
/* 718BE8 802A1398 03E00008 */  jr        $ra
/* 718BEC 802A139C 27BD0018 */   addiu    $sp, $sp, 0x18
