.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C3EE4
/* E8894 802C3EE4 3C02802E */  lui       $v0, 0x802e
/* E8898 802C3EE8 8C42AC98 */  lw        $v0, -0x5368($v0)
/* E889C 802C3EEC 18400011 */  blez      $v0, .L802C3F34
/* E88A0 802C3EF0 0000202D */   daddu    $a0, $zero, $zero
/* E88A4 802C3EF4 3C08802E */  lui       $t0, 0x802e
/* E88A8 802C3EF8 8D08A890 */  lw        $t0, -0x5770($t0)
/* E88AC 802C3EFC 0040382D */  daddu     $a3, $v0, $zero
/* E88B0 802C3F00 3C06802E */  lui       $a2, 0x802e
/* E88B4 802C3F04 24C6AA98 */  addiu     $a2, $a2, -0x5568
/* E88B8 802C3F08 3C05802E */  lui       $a1, 0x802e
/* E88BC 802C3F0C 24A5A898 */  addiu     $a1, $a1, -0x5768
.L802C3F10:
/* E88C0 802C3F10 8CA20000 */  lw        $v0, ($a1)
/* E88C4 802C3F14 00021080 */  sll       $v0, $v0, 2
/* E88C8 802C3F18 00481021 */  addu      $v0, $v0, $t0
/* E88CC 802C3F1C 8C420000 */  lw        $v0, ($v0)
/* E88D0 802C3F20 24C60004 */  addiu     $a2, $a2, 4
/* E88D4 802C3F24 24840001 */  addiu     $a0, $a0, 1
/* E88D8 802C3F28 0087102A */  slt       $v0, $a0, $a3
/* E88DC 802C3F2C 1440FFF8 */  bnez      $v0, .L802C3F10
/* E88E0 802C3F30 24A50004 */   addiu    $a1, $a1, 4
.L802C3F34:
/* E88E4 802C3F34 03E00008 */  jr        $ra
/* E88E8 802C3F38 00000000 */   nop      
