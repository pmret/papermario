.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416CC_E13E2C
/* E13E2C 802416CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13E30 802416D0 3C05FE36 */  lui       $a1, 0xfe36
/* E13E34 802416D4 3C068011 */  lui       $a2, %hi(gPlayerData+0xC)
/* E13E38 802416D8 84C6F29C */  lh        $a2, %lo(gPlayerData+0xC)($a2)
/* E13E3C 802416DC AFBF0010 */  sw        $ra, 0x10($sp)
/* E13E40 802416E0 0C0B2026 */  jal       set_variable
/* E13E44 802416E4 34A53C8A */   ori      $a1, $a1, 0x3c8a
/* E13E48 802416E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E13E4C 802416EC 24020002 */  addiu     $v0, $zero, 2
/* E13E50 802416F0 03E00008 */  jr        $ra
/* E13E54 802416F4 27BD0018 */   addiu    $sp, $sp, 0x18
