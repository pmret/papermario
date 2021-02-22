.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800605B8
/* 3B9B8 800605B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B9BC 800605BC 3C048009 */  lui       $a0, %hi(D_80093D18)
/* 3B9C0 800605C0 24843D18 */  addiu     $a0, $a0, %lo(D_80093D18)
/* 3B9C4 800605C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B9C8 800605C8 0C018118 */  jal       func_80060460
/* 3B9CC 800605CC 00000000 */   nop
/* 3B9D0 800605D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B9D4 800605D4 03E00008 */  jr        $ra
/* 3B9D8 800605D8 27BD0018 */   addiu    $sp, $sp, 0x18
