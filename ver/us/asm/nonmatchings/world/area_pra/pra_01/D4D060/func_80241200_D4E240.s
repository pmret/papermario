.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241200_D4E240
/* D4E240 80241200 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4E244 80241204 AFBF0010 */  sw        $ra, 0x10($sp)
/* D4E248 80241208 8C82000C */  lw        $v0, 0xc($a0)
/* D4E24C 8024120C 0C0B1EAF */  jal       get_variable
/* D4E250 80241210 8C450000 */   lw       $a1, ($v0)
/* D4E254 80241214 3C018024 */  lui       $at, %hi(D_80241F98_D4EFD8)
/* D4E258 80241218 AC221F98 */  sw        $v0, %lo(D_80241F98_D4EFD8)($at)
/* D4E25C 8024121C 24020002 */  addiu     $v0, $zero, 2
/* D4E260 80241220 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4E264 80241224 24030001 */  addiu     $v1, $zero, 1
/* D4E268 80241228 3C018024 */  lui       $at, %hi(D_80241F94_D4EFD4)
/* D4E26C 8024122C AC231F94 */  sw        $v1, %lo(D_80241F94_D4EFD4)($at)
/* D4E270 80241230 03E00008 */  jr        $ra
/* D4E274 80241234 27BD0018 */   addiu    $sp, $sp, 0x18
