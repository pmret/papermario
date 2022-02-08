.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008403C
/* 388A0C E008403C 3C02E008 */  lui       $v0, %hi(D_E0084E38)
/* 388A10 E0084040 8C424E38 */  lw        $v0, %lo(D_E0084E38)($v0)
/* 388A14 E0084044 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 388A18 E0084048 AFBF0010 */  sw        $ra, 0x10($sp)
/* 388A1C E008404C 0040F809 */  jalr      $v0
/* 388A20 E0084050 00000000 */   nop
/* 388A24 E0084054 8FBF0010 */  lw        $ra, 0x10($sp)
/* 388A28 E0084058 03E00008 */  jr        $ra
/* 388A2C E008405C 27BD0018 */   addiu    $sp, $sp, 0x18
