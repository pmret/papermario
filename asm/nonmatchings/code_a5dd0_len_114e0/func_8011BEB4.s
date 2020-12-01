.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BEB4
/* B25B4 8011BEB4 8FA20010 */  lw        $v0, 0x10($sp)
/* B25B8 8011BEB8 8FA30014 */  lw        $v1, 0x14($sp)
/* B25BC 8011BEBC 8FA80018 */  lw        $t0, 0x18($sp)
/* B25C0 8011BEC0 8FA9001C */  lw        $t1, 0x1c($sp)
/* B25C4 8011BEC4 8FAA0020 */  lw        $t2, 0x20($sp)
/* B25C8 8011BEC8 3C018015 */  lui       $at, %hi(D_8014B750)
/* B25CC 8011BECC A024B750 */  sb        $a0, %lo(D_8014B750)($at)
/* B25D0 8011BED0 3C018015 */  lui       $at, %hi(D_8014B751)
/* B25D4 8011BED4 A025B751 */  sb        $a1, %lo(D_8014B751)($at)
/* B25D8 8011BED8 3C018015 */  lui       $at, %hi(D_8014B752)
/* B25DC 8011BEDC A026B752 */  sb        $a2, %lo(D_8014B752)($at)
/* B25E0 8011BEE0 3C018015 */  lui       $at, %hi(D_8014B753)
/* B25E4 8011BEE4 A027B753 */  sb        $a3, %lo(D_8014B753)($at)
/* B25E8 8011BEE8 3C018015 */  lui       $at, %hi(D_8014B754)
/* B25EC 8011BEEC A022B754 */  sb        $v0, %lo(D_8014B754)($at)
/* B25F0 8011BEF0 3C018015 */  lui       $at, %hi(D_8014B755)
/* B25F4 8011BEF4 A023B755 */  sb        $v1, %lo(D_8014B755)($at)
/* B25F8 8011BEF8 3C018015 */  lui       $at, %hi(D_8014B756)
/* B25FC 8011BEFC A028B756 */  sb        $t0, %lo(D_8014B756)($at)
/* B2600 8011BF00 3C018015 */  lui       $at, %hi(D_8014B758)
/* B2604 8011BF04 AC29B758 */  sw        $t1, %lo(D_8014B758)($at)
/* B2608 8011BF08 3C018015 */  lui       $at, %hi(D_8014B75C)
/* B260C 8011BF0C 03E00008 */  jr        $ra
/* B2610 8011BF10 AC2AB75C */   sw       $t2, %lo(D_8014B75C)($at)
