.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A17D4_78BDD4
/* 78BDD4 802A17D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78BDD8 802A17D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 78BDDC 802A17DC 3C10800E */  lui       $s0, %hi(gBattleStatus+0xD8)
/* 78BDE0 802A17E0 8E10C148 */  lw        $s0, %lo(gBattleStatus+0xD8)($s0)
/* 78BDE4 802A17E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 78BDE8 802A17E8 82020210 */  lb        $v0, 0x210($s0)
/* 78BDEC 802A17EC 10400005 */  beqz      $v0, .L802A1804
/* 78BDF0 802A17F0 00000000 */   nop
/* 78BDF4 802A17F4 86040436 */  lh        $a0, 0x436($s0)
/* 78BDF8 802A17F8 A2000211 */  sb        $zero, 0x211($s0)
/* 78BDFC 802A17FC 0C011E26 */  jal       func_80047898
/* 78BE00 802A1800 A2000210 */   sb       $zero, 0x210($s0)
.L802A1804:
/* 78BE04 802A1804 82020216 */  lb        $v0, 0x216($s0)
/* 78BE08 802A1808 10400006 */  beqz      $v0, .L802A1824
/* 78BE0C 802A180C 00000000 */   nop
/* 78BE10 802A1810 8E020440 */  lw        $v0, 0x440($s0)
/* 78BE14 802A1814 A2000217 */  sb        $zero, 0x217($s0)
/* 78BE18 802A1818 A2000216 */  sb        $zero, 0x216($s0)
/* 78BE1C 802A181C 8C42000C */  lw        $v0, 0xc($v0)
/* 78BE20 802A1820 AC40003C */  sw        $zero, 0x3c($v0)
.L802A1824:
/* 78BE24 802A1824 0C099DDF */  jal       func_8026777C
/* 78BE28 802A1828 00000000 */   nop
/* 78BE2C 802A182C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 78BE30 802A1830 8FB00010 */  lw        $s0, 0x10($sp)
/* 78BE34 802A1834 24020002 */  addiu     $v0, $zero, 2
/* 78BE38 802A1838 03E00008 */  jr        $ra
/* 78BE3C 802A183C 27BD0018 */   addiu    $sp, $sp, 0x18
