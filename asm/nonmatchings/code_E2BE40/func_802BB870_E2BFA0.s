.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB870_E2BFA0
/* E2BFA0 802BB870 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2BFA4 802BB874 3C050A00 */  lui       $a1, 0xa00
/* E2BFA8 802BB878 24A52E18 */  addiu     $a1, $a1, 0x2e18
/* E2BFAC 802BB87C AFBF0010 */  sw        $ra, 0x10($sp)
/* E2BFB0 802BB880 8C820040 */  lw        $v0, 0x40($a0)
/* E2BFB4 802BB884 C480004C */  lwc1      $f0, 0x4c($a0)
/* E2BFB8 802BB888 3C060A00 */  lui       $a2, 0xa00
/* E2BFBC 802BB88C 24C62478 */  addiu     $a2, $a2, 0x2478
/* E2BFC0 802BB890 0C0AEDC4 */  jal       func_802BB710_E2BE40
/* E2BFC4 802BB894 E4400004 */   swc1     $f0, 4($v0)
/* E2BFC8 802BB898 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2BFCC 802BB89C 03E00008 */  jr        $ra
/* E2BFD0 802BB8A0 27BD0018 */   addiu    $sp, $sp, 0x18
