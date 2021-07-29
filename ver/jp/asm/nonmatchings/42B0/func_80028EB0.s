.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028EB0
/* 42B0 80028EB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42B4 80028EB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 42B8 80028EB8 0C017EE8 */  jal       func_8005FBA0
/* 42BC 80028EBC 0000202D */   daddu    $a0, $zero, $zero
/* 42C0 80028EC0 0000202D */  daddu     $a0, $zero, $zero
/* 42C4 80028EC4 0C017F10 */  jal       func_8005FC40
/* 42C8 80028EC8 24050002 */   addiu    $a1, $zero, 2
/* 42CC 80028ECC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 42D0 80028ED0 03E00008 */  jr        $ra
/* 42D4 80028ED4 27BD0018 */   addiu    $sp, $sp, 0x18
