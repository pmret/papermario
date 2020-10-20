.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D4
/* B1BB44 802405D4 27BDFEA8 */  addiu     $sp, $sp, -0x158
/* B1BB48 802405D8 AFB00150 */  sw        $s0, 0x150($sp)
/* B1BB4C 802405DC 27B00050 */  addiu     $s0, $sp, 0x50
/* B1BB50 802405E0 3C05C3F2 */  lui       $a1, 0xc3f2
/* B1BB54 802405E4 3C0641C8 */  lui       $a2, 0x41c8
/* B1BB58 802405E8 3C07C220 */  lui       $a3, 0xc220
/* B1BB5C 802405EC AFBF0154 */  sw        $ra, 0x154($sp)
/* B1BB60 802405F0 0C019E40 */  jal       guTranslateF
/* B1BB64 802405F4 0200202D */   daddu    $a0, $s0, $zero
/* B1BB68 802405F8 0200202D */  daddu     $a0, $s0, $zero
/* B1BB6C 802405FC 27B00110 */  addiu     $s0, $sp, 0x110
/* B1BB70 80240600 0C019D40 */  jal       guMtxF2L
/* B1BB74 80240604 0200282D */   daddu    $a1, $s0, $zero
/* B1BB78 80240608 3C048024 */  lui       $a0, 0x8024
/* B1BB7C 8024060C 8C840FD0 */  lw        $a0, 0xfd0($a0)
/* B1BB80 80240610 0C047CC1 */  jal       func_8011F304
/* B1BB84 80240614 0200282D */   daddu    $a1, $s0, $zero
/* B1BB88 80240618 8FBF0154 */  lw        $ra, 0x154($sp)
/* B1BB8C 8024061C 8FB00150 */  lw        $s0, 0x150($sp)
/* B1BB90 80240620 03E00008 */  jr        $ra
/* B1BB94 80240624 27BD0158 */   addiu    $sp, $sp, 0x158
