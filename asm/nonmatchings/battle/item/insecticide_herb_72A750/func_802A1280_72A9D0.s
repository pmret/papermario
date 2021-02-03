.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1280_72A9D0
/* 72A9D0 802A1280 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 72A9D4 802A1284 AFBF001C */  sw        $ra, 0x1c($sp)
/* 72A9D8 802A1288 AFB00018 */  sw        $s0, 0x18($sp)
/* 72A9DC 802A128C 0C09A75B */  jal       get_actor
/* 72A9E0 802A1290 8C840148 */   lw       $a0, 0x148($a0)
/* 72A9E4 802A1294 0040802D */  daddu     $s0, $v0, $zero
/* 72A9E8 802A1298 C6000020 */  lwc1      $f0, 0x20($s0)
/* 72A9EC 802A129C 24040231 */  addiu     $a0, $zero, 0x231
/* 72A9F0 802A12A0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 72A9F4 802A12A4 8E060018 */  lw        $a2, 0x18($s0)
/* 72A9F8 802A12A8 8E07001C */  lw        $a3, 0x1c($s0)
/* 72A9FC 802A12AC 0C052757 */  jal       play_sound_at_position
/* 72AA00 802A12B0 0000282D */   daddu    $a1, $zero, $zero
/* 72AA04 802A12B4 86040428 */  lh        $a0, 0x428($s0)
/* 72AA08 802A12B8 0C09A75B */  jal       get_actor
/* 72AA0C 802A12BC 00000000 */   nop
/* 72AA10 802A12C0 0040202D */  daddu     $a0, $v0, $zero
/* 72AA14 802A12C4 0C09DC58 */  jal       dispatch_event_actor
/* 72AA18 802A12C8 24050039 */   addiu    $a1, $zero, 0x39
/* 72AA1C 802A12CC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 72AA20 802A12D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 72AA24 802A12D4 24020002 */  addiu     $v0, $zero, 2
/* 72AA28 802A12D8 03E00008 */  jr        $ra
/* 72AA2C 802A12DC 27BD0020 */   addiu    $sp, $sp, 0x20
