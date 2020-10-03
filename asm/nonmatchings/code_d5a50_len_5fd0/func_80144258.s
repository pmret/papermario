.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80144258
/* DA958 80144258 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DA95C 8014425C 24050001 */  addiu     $a1, $zero, 1
/* DA960 80144260 AFBF0010 */  sw        $ra, 0x10($sp)
/* DA964 80144264 0C050F12 */  jal       func_80143C48
/* DA968 80144268 00A0302D */   daddu    $a2, $a1, $zero
/* DA96C 8014426C 8FBF0010 */  lw        $ra, 0x10($sp)
/* DA970 80144270 03E00008 */  jr        $ra
/* DA974 80144274 27BD0018 */   addiu    $sp, $sp, 0x18
