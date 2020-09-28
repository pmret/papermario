.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E06C0
/* 79B70 800E06C0 38840001 */  xori      $a0, $a0, 1
/* 79B74 800E06C4 2C840001 */  sltiu     $a0, $a0, 1
/* 79B78 800E06C8 3C018011 */  lui       $at, 0x8011
/* 79B7C 800E06CC AC24C950 */  sw        $a0, -0x36b0($at)
/* 79B80 800E06D0 03E00008 */  jr        $ra
/* 79B84 800E06D4 00000000 */   nop      
