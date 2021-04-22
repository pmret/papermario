.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800479AC
/* 22DAC 800479AC 00041040 */  sll       $v0, $a0, 1
/* 22DB0 800479B0 00441021 */  addu      $v0, $v0, $a0
/* 22DB4 800479B4 00021080 */  sll       $v0, $v0, 2
/* 22DB8 800479B8 00441023 */  subu      $v0, $v0, $a0
/* 22DBC 800479BC 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22DC0 800479C0 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22DC4 800479C4 00021100 */  sll       $v0, $v0, 4
/* 22DC8 800479C8 00621821 */  addu      $v1, $v1, $v0
/* 22DCC 800479CC 8C620000 */  lw        $v0, ($v1)
/* 22DD0 800479D0 34420040 */  ori       $v0, $v0, 0x40
/* 22DD4 800479D4 03E00008 */  jr        $ra
/* 22DD8 800479D8 AC620000 */   sw       $v0, ($v1)
