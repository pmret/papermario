.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428C0_E07C20
/* E07C20 802428C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E07C24 802428C4 2404005B */  addiu     $a0, $zero, 0x5b
/* E07C28 802428C8 2405FFFF */  addiu     $a1, $zero, -1
/* E07C2C 802428CC 24060001 */  addiu     $a2, $zero, 1
/* E07C30 802428D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E07C34 802428D4 0C046E54 */  jal       func_8011B950
/* E07C38 802428D8 0000382D */   daddu    $a3, $zero, $zero
/* E07C3C 802428DC 0000202D */  daddu     $a0, $zero, $zero
/* E07C40 802428E0 0080282D */  daddu     $a1, $a0, $zero
/* E07C44 802428E4 0080302D */  daddu     $a2, $a0, $zero
/* E07C48 802428E8 0C046F97 */  jal       set_background_color_blend
/* E07C4C 802428EC 240700FF */   addiu    $a3, $zero, 0xff
/* E07C50 802428F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E07C54 802428F4 24020002 */  addiu     $v0, $zero, 2
/* E07C58 802428F8 03E00008 */  jr        $ra
/* E07C5C 802428FC 27BD0018 */   addiu    $sp, $sp, 0x18
