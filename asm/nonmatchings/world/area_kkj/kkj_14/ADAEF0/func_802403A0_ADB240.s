.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A0_ADB240
/* ADB240 802403A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ADB244 802403A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* ADB248 802403A8 8C82000C */  lw        $v0, 0xc($a0)
/* ADB24C 802403AC 3C068011 */  lui       $a2, 0x8011
/* ADB250 802403B0 80C6EFD4 */  lb        $a2, -0x102c($a2)
/* ADB254 802403B4 0C0B2026 */  jal       set_variable
/* ADB258 802403B8 8C450000 */   lw       $a1, ($v0)
/* ADB25C 802403BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* ADB260 802403C0 24020002 */  addiu     $v0, $zero, 2
/* ADB264 802403C4 03E00008 */  jr        $ra
/* ADB268 802403C8 27BD0018 */   addiu    $sp, $sp, 0x18
