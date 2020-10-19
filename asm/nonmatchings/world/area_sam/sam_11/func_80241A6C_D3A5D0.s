.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A6C_D3C03C
/* D3C03C 80241A6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3C040 80241A70 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3C044 80241A74 0C04C3D6 */  jal       get_item_entity
/* D3C048 80241A78 8C840084 */   lw       $a0, 0x84($a0)
/* D3C04C 80241A7C 3C013F19 */  lui       $at, 0x3f19
/* D3C050 80241A80 3421999A */  ori       $at, $at, 0x999a
/* D3C054 80241A84 44810000 */  mtc1      $at, $f0
/* D3C058 80241A88 00000000 */  nop       
/* D3C05C 80241A8C E4400030 */  swc1      $f0, 0x30($v0)
/* D3C060 80241A90 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3C064 80241A94 24020002 */  addiu     $v0, $zero, 2
/* D3C068 80241A98 03E00008 */  jr        $ra
/* D3C06C 80241A9C 27BD0018 */   addiu    $sp, $sp, 0x18
