.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E84_C88934
/* C88934 80242E84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C88938 80242E88 AFBF0010 */  sw        $ra, 0x10($sp)
/* C8893C 80242E8C 8C82000C */  lw        $v0, 0xc($a0)
/* C88940 80242E90 0C0B1EAF */  jal       get_variable
/* C88944 80242E94 8C450000 */   lw       $a1, ($v0)
/* C88948 80242E98 44820000 */  mtc1      $v0, $f0
/* C8894C 80242E9C 00000000 */  nop       
/* C88950 80242EA0 46800020 */  cvt.s.w   $f0, $f0
/* C88954 80242EA4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C88958 80242EA8 24020002 */  addiu     $v0, $zero, 2
/* C8895C 80242EAC 3C018011 */  lui       $at, 0x8011
/* C88960 80242EB0 E420F054 */  swc1      $f0, -0xfac($at)
/* C88964 80242EB4 03E00008 */  jr        $ra
/* C88968 80242EB8 27BD0018 */   addiu    $sp, $sp, 0x18
