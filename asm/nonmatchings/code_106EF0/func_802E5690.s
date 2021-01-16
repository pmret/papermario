.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5690
/* 106F10 802E5690 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106F14 802E5694 AFBF0010 */  sw        $ra, 0x10($sp)
/* 106F18 802E5698 0C04417A */  jal       get_entity_by_index
/* 106F1C 802E569C 00000000 */   nop
/* 106F20 802E56A0 8C420040 */  lw        $v0, 0x40($v0)
/* 106F24 802E56A4 84440012 */  lh        $a0, 0x12($v0)
/* 106F28 802E56A8 04800006 */  bltz      $a0, .L802E56C4
/* 106F2C 802E56AC 00000000 */   nop
/* 106F30 802E56B0 0C04417A */  jal       get_entity_by_index
/* 106F34 802E56B4 00000000 */   nop
/* 106F38 802E56B8 8C430040 */  lw        $v1, 0x40($v0)
/* 106F3C 802E56BC 24020001 */  addiu     $v0, $zero, 1
/* 106F40 802E56C0 A062000A */  sb        $v0, 0xa($v1)
.L802E56C4:
/* 106F44 802E56C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106F48 802E56C8 03E00008 */  jr        $ra
/* 106F4C 802E56CC 27BD0018 */   addiu    $sp, $sp, 0x18
