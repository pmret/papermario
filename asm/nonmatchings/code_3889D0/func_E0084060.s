.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0084060
/* 388A30 E0084060 3C02E008 */  lui       $v0, %hi(D_E0084E3C)
/* 388A34 E0084064 8C424E3C */  lw        $v0, %lo(D_E0084E3C)($v0)
/* 388A38 E0084068 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 388A3C E008406C AFBF0010 */  sw        $ra, 0x10($sp)
/* 388A40 E0084070 0040F809 */  jalr      $v0
/* 388A44 E0084074 00000000 */   nop      
/* 388A48 E0084078 8FBF0010 */  lw        $ra, 0x10($sp)
/* 388A4C E008407C 03E00008 */  jr        $ra
/* 388A50 E0084080 27BD0018 */   addiu    $sp, $sp, 0x18
