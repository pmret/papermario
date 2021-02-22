.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8010FE44
/* A6544 8010FE44 3C058015 */  lui       $a1, %hi(D_8014AFB0)
/* A6548 8010FE48 8CA5AFB0 */  lw        $a1, %lo(D_8014AFB0)($a1)
/* A654C 8010FE4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A6550 8010FE50 AFBF0010 */  sw        $ra, 0x10($sp)
/* A6554 8010FE54 0C043F66 */  jal       func_8010FD98
/* A6558 8010FE58 00000000 */   nop
/* A655C 8010FE5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A6560 8010FE60 03E00008 */  jr        $ra
/* A6564 8010FE64 27BD0018 */   addiu    $sp, $sp, 0x18
