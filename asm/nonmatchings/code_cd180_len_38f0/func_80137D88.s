.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80137D88
/* CE488 80137D88 308400FF */  andi      $a0, $a0, 0xff
/* CE48C 80137D8C 3C018015 */  lui       $at, %hi(D_80156900)
/* CE490 80137D90 AC246900 */  sw        $a0, %lo(D_80156900)($at)
/* CE494 80137D94 3C018015 */  lui       $at, %hi(D_80156904)
/* CE498 80137D98 AC256904 */  sw        $a1, %lo(D_80156904)($at)
/* CE49C 80137D9C 03E00008 */  jr        $ra
/* CE4A0 80137DA0 00000000 */   nop
