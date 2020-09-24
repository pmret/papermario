.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112E4C
/* A954C 80112E4C 3C028015 */  lui       $v0, 0x8015
/* A9550 80112E50 24421700 */  addiu     $v0, $v0, 0x1700
/* A9554 80112E54 00041840 */  sll       $v1, $a0, 1
/* A9558 80112E58 00641821 */  addu      $v1, $v1, $a0
/* A955C 80112E5C 000318C0 */  sll       $v1, $v1, 3
/* A9560 80112E60 00621821 */  addu      $v1, $v1, $v0
/* A9564 80112E64 94620000 */  lhu       $v0, ($v1)
/* A9568 80112E68 3042FFF3 */  andi      $v0, $v0, 0xfff3
/* A956C 80112E6C 34420010 */  ori       $v0, $v0, 0x10
/* A9570 80112E70 03E00008 */  jr        $ra
/* A9574 80112E74 A4620000 */   sh       $v0, ($v1)
