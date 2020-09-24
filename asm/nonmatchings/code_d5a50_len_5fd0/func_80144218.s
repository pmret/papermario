.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80144218
/* DA918 80144218 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DA91C 8014421C 24050001 */  addiu     $a1, $zero, 1
/* DA920 80144220 AFBF0010 */  sw        $ra, 0x10($sp)
/* DA924 80144224 0C050F12 */  jal       func_80143C48
/* DA928 80144228 24060003 */   addiu    $a2, $zero, 3
/* DA92C 8014422C 8FBF0010 */  lw        $ra, 0x10($sp)
/* DA930 80144230 03E00008 */  jr        $ra
/* DA934 80144234 27BD0018 */   addiu    $sp, $sp, 0x18
