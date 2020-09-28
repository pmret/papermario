.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112DD4
/* A94D4 80112DD4 3C028015 */  lui       $v0, %hi(gMainGameState)
/* A94D8 80112DD8 24421700 */  addiu     $v0, $v0, %lo(gMainGameState)
/* A94DC 80112DDC 00041840 */  sll       $v1, $a0, 1
/* A94E0 80112DE0 00641821 */  addu      $v1, $v1, $a0
/* A94E4 80112DE4 000318C0 */  sll       $v1, $v1, 3
/* A94E8 80112DE8 00621821 */  addu      $v1, $v1, $v0
/* A94EC 80112DEC 94620000 */  lhu       $v0, ($v1)
/* A94F0 80112DF0 34420004 */  ori       $v0, $v0, 4
/* A94F4 80112DF4 03E00008 */  jr        $ra
/* A94F8 80112DF8 A4620000 */   sh       $v0, ($v1)
