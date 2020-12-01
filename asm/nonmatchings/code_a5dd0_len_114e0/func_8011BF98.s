.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BF98
/* B2698 8011BF98 8FA20010 */  lw        $v0, 0x10($sp)
/* B269C 8011BF9C 8FA30014 */  lw        $v1, 0x14($sp)
/* B26A0 8011BFA0 3C018015 */  lui       $at, %hi(D_8014B760)
/* B26A4 8011BFA4 A024B760 */  sb        $a0, %lo(D_8014B760)($at)
/* B26A8 8011BFA8 3C018015 */  lui       $at, %hi(D_8014B761)
/* B26AC 8011BFAC A025B761 */  sb        $a1, %lo(D_8014B761)($at)
/* B26B0 8011BFB0 3C018015 */  lui       $at, %hi(D_8014B762)
/* B26B4 8011BFB4 A026B762 */  sb        $a2, %lo(D_8014B762)($at)
/* B26B8 8011BFB8 3C018015 */  lui       $at, %hi(D_8014B763)
/* B26BC 8011BFBC A027B763 */  sb        $a3, %lo(D_8014B763)($at)
/* B26C0 8011BFC0 3C018015 */  lui       $at, %hi(D_8014B764)
/* B26C4 8011BFC4 A022B764 */  sb        $v0, %lo(D_8014B764)($at)
/* B26C8 8011BFC8 3C018015 */  lui       $at, %hi(D_8014B765)
/* B26CC 8011BFCC 03E00008 */  jr        $ra
/* B26D0 8011BFD0 A023B765 */   sb       $v1, %lo(D_8014B765)($at)
