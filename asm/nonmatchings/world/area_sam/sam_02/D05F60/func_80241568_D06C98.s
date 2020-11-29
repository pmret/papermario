.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241568_D06C98
/* D06C98 80241568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D06C9C 8024156C AFBF0010 */  sw        $ra, 0x10($sp)
/* D06CA0 80241570 8C82000C */  lw        $v0, 0xc($a0)
/* D06CA4 80241574 0C0B1EAF */  jal       get_variable
/* D06CA8 80241578 8C450000 */   lw       $a1, ($v0)
/* D06CAC 8024157C 3C038025 */  lui       $v1, %hi(D_8024B9B0)
/* D06CB0 80241580 8C63B9B0 */  lw        $v1, %lo(D_8024B9B0)($v1)
/* D06CB4 80241584 8C63000C */  lw        $v1, 0xc($v1)
/* D06CB8 80241588 AC620034 */  sw        $v0, 0x34($v1)
/* D06CBC 8024158C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06CC0 80241590 24020002 */  addiu     $v0, $zero, 2
/* D06CC4 80241594 03E00008 */  jr        $ra
/* D06CC8 80241598 27BD0018 */   addiu    $sp, $sp, 0x18
