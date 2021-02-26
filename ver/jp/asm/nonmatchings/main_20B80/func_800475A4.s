.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800475A4
/* 229A4 800475A4 00041040 */  sll       $v0, $a0, 1
/* 229A8 800475A8 00441021 */  addu      $v0, $v0, $a0
/* 229AC 800475AC 00021080 */  sll       $v0, $v0, 2
/* 229B0 800475B0 00441023 */  subu      $v0, $v0, $a0
/* 229B4 800475B4 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 229B8 800475B8 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 229BC 800475BC 00021100 */  sll       $v0, $v0, 4
/* 229C0 800475C0 00621821 */  addu      $v1, $v1, $v0
/* 229C4 800475C4 8C620000 */  lw        $v0, ($v1)
/* 229C8 800475C8 34420004 */  ori       $v0, $v0, 4
/* 229CC 800475CC 03E00008 */  jr        $ra
/* 229D0 800475D0 AC620000 */   sw       $v0, ($v1)
