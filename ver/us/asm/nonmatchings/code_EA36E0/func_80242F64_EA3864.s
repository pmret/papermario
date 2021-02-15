.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F64_EA3864
/* EA3864 80242F64 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA3868 80242F68 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA386C 80242F6C 8C82000C */  lw        $v0, 0xc($a0)
/* EA3870 80242F70 0C0B53A3 */  jal       func_802D4E8C
/* EA3874 80242F74 8C450000 */   lw       $a1, ($v0)
/* EA3878 80242F78 44820000 */  mtc1      $v0, $f0
/* EA387C 80242F7C 00000000 */  nop
/* EA3880 80242F80 46800020 */  cvt.s.w   $f0, $f0
/* EA3884 80242F84 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA3888 80242F88 24020002 */  addiu     $v0, $zero, 2
/* EA388C 80242F8C 3C018011 */  lui       $at, %hi(D_80117604)
/* EA3890 80242F90 E4207604 */  swc1      $f0, %lo(D_80117604)($at)
/* EA3894 80242F94 03E00008 */  jr        $ra
/* EA3898 80242F98 27BD0018 */   addiu    $sp, $sp, 0x18
