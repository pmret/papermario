.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243334
/* 8B33A4 80243334 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B33A8 80243338 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B33AC 8024333C 8C82000C */  lw        $v0, 0xc($a0)
/* 8B33B0 80243340 0C0B1EAF */  jal       get_variable
/* 8B33B4 80243344 8C450000 */   lw       $a1, ($v0)
/* 8B33B8 80243348 00021600 */  sll       $v0, $v0, 0x18
/* 8B33BC 8024334C 0C03AC5A */  jal       func_800EB168
/* 8B33C0 80243350 00022603 */   sra      $a0, $v0, 0x18
/* 8B33C4 80243354 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B33C8 80243358 24020002 */  addiu     $v0, $zero, 2
/* 8B33CC 8024335C 03E00008 */  jr        $ra
/* 8B33D0 80243360 27BD0018 */   addiu    $sp, $sp, 0x18
