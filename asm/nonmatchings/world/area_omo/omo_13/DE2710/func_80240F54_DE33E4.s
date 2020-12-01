.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F54_DE33E4
/* DE33E4 80240F54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DE33E8 80240F58 AFBF0010 */  sw        $ra, 0x10($sp)
/* DE33EC 80240F5C 8C82000C */  lw        $v0, 0xc($a0)
/* DE33F0 80240F60 0C0B1EAF */  jal       get_variable
/* DE33F4 80240F64 8C450000 */   lw       $a1, ($v0)
/* DE33F8 80240F68 3C018024 */  lui       $at, %hi(D_80241C08)
/* DE33FC 80240F6C AC221C08 */  sw        $v0, %lo(D_80241C08)($at)
/* DE3400 80240F70 24020002 */  addiu     $v0, $zero, 2
/* DE3404 80240F74 8FBF0010 */  lw        $ra, 0x10($sp)
/* DE3408 80240F78 24030001 */  addiu     $v1, $zero, 1
/* DE340C 80240F7C 3C018024 */  lui       $at, %hi(D_80241C04)
/* DE3410 80240F80 AC231C04 */  sw        $v1, %lo(D_80241C04)($at)
/* DE3414 80240F84 03E00008 */  jr        $ra
/* DE3418 80240F88 27BD0018 */   addiu    $sp, $sp, 0x18
