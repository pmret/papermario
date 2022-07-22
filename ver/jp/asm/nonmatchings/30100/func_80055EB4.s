.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055EB4
/* 312B4 80055EB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 312B8 80055EB8 3C04800A */  lui       $a0, %hi(D_8009A620)
/* 312BC 80055EBC 8C84A620 */  lw        $a0, %lo(D_8009A620)($a0)
/* 312C0 80055EC0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 312C4 80055EC4 0C012DC1 */  jal       func_8004B704
/* 312C8 80055EC8 0000282D */   daddu    $a1, $zero, $zero
/* 312CC 80055ECC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 312D0 80055ED0 03E00008 */  jr        $ra
/* 312D4 80055ED4 27BD0018 */   addiu    $sp, $sp, 0x18
