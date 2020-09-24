.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112DFC
/* A94FC 80112DFC 3C028015 */  lui       $v0, 0x8015
/* A9500 80112E00 24421700 */  addiu     $v0, $v0, 0x1700
/* A9504 80112E04 00041840 */  sll       $v1, $a0, 1
/* A9508 80112E08 00641821 */  addu      $v1, $v1, $a0
/* A950C 80112E0C 000318C0 */  sll       $v1, $v1, 3
/* A9510 80112E10 00621821 */  addu      $v1, $v1, $v0
/* A9514 80112E14 94620000 */  lhu       $v0, ($v1)
/* A9518 80112E18 34420008 */  ori       $v0, $v0, 8
/* A951C 80112E1C 03E00008 */  jr        $ra
/* A9520 80112E20 A4620000 */   sh       $v0, ($v1)
