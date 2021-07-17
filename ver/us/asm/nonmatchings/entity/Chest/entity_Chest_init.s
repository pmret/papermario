.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_Chest_init
/* 109604 802E7D84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 109608 802E7D88 AFB00010 */  sw        $s0, 0x10($sp)
/* 10960C 802E7D8C 0080802D */  daddu     $s0, $a0, $zero
/* 109610 802E7D90 24020001 */  addiu     $v0, $zero, 1
/* 109614 802E7D94 AFBF0014 */  sw        $ra, 0x14($sp)
/* 109618 802E7D98 8E030040 */  lw        $v1, 0x40($s0)
/* 10961C 802E7D9C 0C0B9F4E */  jal       entity_Chest_readargs
/* 109620 802E7DA0 A0620007 */   sb       $v0, 7($v1)
/* 109624 802E7DA4 3C013F0F */  lui       $at, 0x3f0f
/* 109628 802E7DA8 34215C29 */  ori       $at, $at, 0x5c29
/* 10962C 802E7DAC 44810000 */  mtc1      $at, $f0
/* 109630 802E7DB0 3C02802E */  lui       $v0, %hi(entity_Chest_setupGfx)
/* 109634 802E7DB4 24426ED8 */  addiu     $v0, $v0, %lo(entity_Chest_setupGfx)
/* 109638 802E7DB8 AE02003C */  sw        $v0, 0x3c($s0)
/* 10963C 802E7DBC E6000054 */  swc1      $f0, 0x54($s0)
/* 109640 802E7DC0 E6000058 */  swc1      $f0, 0x58($s0)
/* 109644 802E7DC4 E600005C */  swc1      $f0, 0x5c($s0)
/* 109648 802E7DC8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10964C 802E7DCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 109650 802E7DD0 03E00008 */  jr        $ra
/* 109654 802E7DD4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 109658 802E7DD8 00000000 */  nop
/* 10965C 802E7DDC 00000000 */  nop
