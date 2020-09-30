.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BFD4
/* B26D4 8011BFD4 3C028015 */  lui       $v0, 0x8015
/* B26D8 8011BFD8 9042B760 */  lbu       $v0, -0x48a0($v0)
/* B26DC 8011BFDC 8FA30010 */  lw        $v1, 0x10($sp)
/* B26E0 8011BFE0 8FA80014 */  lw        $t0, 0x14($sp)
/* B26E4 8011BFE4 A0820000 */  sb        $v0, ($a0)
/* B26E8 8011BFE8 3C028015 */  lui       $v0, 0x8015
/* B26EC 8011BFEC 9042B761 */  lbu       $v0, -0x489f($v0)
/* B26F0 8011BFF0 A0A20000 */  sb        $v0, ($a1)
/* B26F4 8011BFF4 3C028015 */  lui       $v0, 0x8015
/* B26F8 8011BFF8 9042B762 */  lbu       $v0, -0x489e($v0)
/* B26FC 8011BFFC A0C20000 */  sb        $v0, ($a2)
/* B2700 8011C000 3C028015 */  lui       $v0, 0x8015
/* B2704 8011C004 9042B763 */  lbu       $v0, -0x489d($v0)
/* B2708 8011C008 A0E20000 */  sb        $v0, ($a3)
/* B270C 8011C00C 3C028015 */  lui       $v0, 0x8015
/* B2710 8011C010 9042B764 */  lbu       $v0, -0x489c($v0)
/* B2714 8011C014 A0620000 */  sb        $v0, ($v1)
/* B2718 8011C018 3C028015 */  lui       $v0, 0x8015
/* B271C 8011C01C 9042B765 */  lbu       $v0, -0x489b($v0)
/* B2720 8011C020 03E00008 */  jr        $ra
/* B2724 8011C024 A1020000 */   sb       $v0, ($t0)
