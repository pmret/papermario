.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CB20
/* 17F20 8003CB20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17F24 8003CB24 00052880 */  sll       $a1, $a1, 2
/* 17F28 8003CB28 00852021 */  addu      $a0, $a0, $a1
/* 17F2C 8003CB2C AFBF0010 */  sw        $ra, 0x10($sp)
/* 17F30 8003CB30 0C016914 */  jal       remove_effect
/* 17F34 8003CB34 8C840324 */   lw       $a0, 0x324($a0)
/* 17F38 8003CB38 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17F3C 8003CB3C 03E00008 */  jr        $ra
/* 17F40 8003CB40 27BD0018 */   addiu    $sp, $sp, 0x18
