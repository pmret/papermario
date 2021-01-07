.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240010_E05370
/* E05370 80240010 3C01420C */  lui       $at, 0x420c
/* E05374 80240014 44810000 */  mtc1      $at, $f0
/* E05378 80240018 00000000 */  nop       
/* E0537C 8024001C 3C01800B */  lui       $at, %hi(D_800B1D98)
/* E05380 80240020 E4201D98 */  swc1      $f0, %lo(D_800B1D98)($at)
/* E05384 80240024 03E00008 */  jr        $ra
/* E05388 80240028 24020002 */   addiu    $v0, $zero, 2
/* E0538C 8024002C 00000000 */  nop       
