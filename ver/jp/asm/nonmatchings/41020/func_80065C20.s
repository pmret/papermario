.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065C20
/* 41020 80065C20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41024 80065C24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 41028 80065C28 0C01B1B4 */  jal       func_8006C6D0
/* 4102C 80065C2C 24040400 */   addiu    $a0, $zero, 0x400
/* 41030 80065C30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 41034 80065C34 03E00008 */  jr        $ra
/* 41038 80065C38 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4103C 80065C3C 00000000 */  nop
