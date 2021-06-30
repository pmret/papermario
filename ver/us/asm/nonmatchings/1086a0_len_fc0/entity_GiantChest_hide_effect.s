.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_GiantChest_hide_effect
/* 108E40 802E75C0 8C820040 */  lw        $v0, 0x40($a0)
/* 108E44 802E75C4 8C420034 */  lw        $v0, 0x34($v0)
/* 108E48 802E75C8 10400004 */  beqz      $v0, .L802E75DC
/* 108E4C 802E75CC 00000000 */   nop
/* 108E50 802E75D0 8C43000C */  lw        $v1, 0xc($v0)
/* 108E54 802E75D4 2402000A */  addiu     $v0, $zero, 0xa
/* 108E58 802E75D8 AC620014 */  sw        $v0, 0x14($v1)
.L802E75DC:
/* 108E5C 802E75DC 03E00008 */  jr        $ra
/* 108E60 802E75E0 00000000 */   nop
