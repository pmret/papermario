.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1378_725058
/* 725058 802A1378 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 72505C 802A137C AFBF0018 */  sw        $ra, 0x18($sp)
/* 725060 802A1380 AFB10014 */  sw        $s1, 0x14($sp)
/* 725064 802A1384 AFB00010 */  sw        $s0, 0x10($sp)
/* 725068 802A1388 8C82000C */  lw        $v0, 0xc($a0)
/* 72506C 802A138C 0C0B1EAF */  jal       get_variable
/* 725070 802A1390 8C450000 */   lw       $a1, ($v0)
/* 725074 802A1394 0C09A75B */  jal       get_actor
/* 725078 802A1398 0040202D */   daddu    $a0, $v0, $zero
/* 72507C 802A139C 0040802D */  daddu     $s0, $v0, $zero
/* 725080 802A13A0 96020192 */  lhu       $v0, 0x192($s0)
/* 725084 802A13A4 82030210 */  lb        $v1, 0x210($s0)
/* 725088 802A13A8 10600005 */  beqz      $v1, .L802A13C0
/* 72508C 802A13AC 30510700 */   andi     $s1, $v0, 0x700
/* 725090 802A13B0 86040436 */  lh        $a0, 0x436($s0)
/* 725094 802A13B4 A2000211 */  sb        $zero, 0x211($s0)
/* 725098 802A13B8 0C011E26 */  jal       func_80047898
/* 72509C 802A13BC A2000210 */   sb       $zero, 0x210($s0)
.L802A13C0:
/* 7250A0 802A13C0 82020216 */  lb        $v0, 0x216($s0)
/* 7250A4 802A13C4 1040000C */  beqz      $v0, .L802A13F8
/* 7250A8 802A13C8 00000000 */   nop
/* 7250AC 802A13CC A2000217 */  sb        $zero, 0x217($s0)
/* 7250B0 802A13D0 12200006 */  beqz      $s1, .L802A13EC
/* 7250B4 802A13D4 A2000216 */   sb       $zero, 0x216($s0)
/* 7250B8 802A13D8 24020100 */  addiu     $v0, $zero, 0x100
/* 7250BC 802A13DC 16220003 */  bne       $s1, $v0, .L802A13EC
/* 7250C0 802A13E0 00000000 */   nop
/* 7250C4 802A13E4 0C09F7A0 */  jal       dispatch_event_partner
/* 7250C8 802A13E8 24040031 */   addiu    $a0, $zero, 0x31
.L802A13EC:
/* 7250CC 802A13EC 8E020440 */  lw        $v0, 0x440($s0)
/* 7250D0 802A13F0 8C42000C */  lw        $v0, 0xc($v0)
/* 7250D4 802A13F4 AC40003C */  sw        $zero, 0x3c($v0)
.L802A13F8:
/* 7250D8 802A13F8 0C099DDF */  jal       func_8026777C
/* 7250DC 802A13FC 00000000 */   nop
/* 7250E0 802A1400 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7250E4 802A1404 8FB10014 */  lw        $s1, 0x14($sp)
/* 7250E8 802A1408 8FB00010 */  lw        $s0, 0x10($sp)
/* 7250EC 802A140C 24020002 */  addiu     $v0, $zero, 2
/* 7250F0 802A1410 03E00008 */  jr        $ra
/* 7250F4 802A1414 27BD0020 */   addiu    $sp, $sp, 0x20
