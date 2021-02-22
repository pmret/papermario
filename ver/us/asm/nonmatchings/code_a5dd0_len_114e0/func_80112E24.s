.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112E24
/* A9524 80112E24 3C028015 */  lui       $v0, %hi(gMainGameState)
/* A9528 80112E28 24421700 */  addiu     $v0, $v0, %lo(gMainGameState)
/* A952C 80112E2C 00041840 */  sll       $v1, $a0, 1
/* A9530 80112E30 00641821 */  addu      $v1, $v1, $a0
/* A9534 80112E34 000318C0 */  sll       $v1, $v1, 3
/* A9538 80112E38 00621821 */  addu      $v1, $v1, $v0
/* A953C 80112E3C 94620000 */  lhu       $v0, ($v1)
/* A9540 80112E40 3042FFE3 */  andi      $v0, $v0, 0xffe3
/* A9544 80112E44 03E00008 */  jr        $ra
/* A9548 80112E48 A4620000 */   sh       $v0, ($v1)
