.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243034_8B30A4
/* 8B30A4 80243034 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B30A8 80243038 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B30AC 8024303C 0C04C3D6 */  jal       get_item_entity
/* 8B30B0 80243040 8C840084 */   lw       $a0, 0x84($a0)
/* 8B30B4 80243044 3C013F19 */  lui       $at, 0x3f19
/* 8B30B8 80243048 3421999A */  ori       $at, $at, 0x999a
/* 8B30BC 8024304C 44810000 */  mtc1      $at, $f0
/* 8B30C0 80243050 00000000 */  nop
/* 8B30C4 80243054 E4400030 */  swc1      $f0, 0x30($v0)
/* 8B30C8 80243058 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B30CC 8024305C 24020002 */  addiu     $v0, $zero, 2
/* 8B30D0 80243060 03E00008 */  jr        $ra
/* 8B30D4 80243064 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8B30D8 80243068 00000000 */  nop
/* 8B30DC 8024306C 00000000 */  nop
