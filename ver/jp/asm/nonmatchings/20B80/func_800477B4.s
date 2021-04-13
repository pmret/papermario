.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800477B4
/* 22BB4 800477B4 00041040 */  sll       $v0, $a0, 1
/* 22BB8 800477B8 00441021 */  addu      $v0, $v0, $a0
/* 22BBC 800477BC 00021080 */  sll       $v0, $v0, 2
/* 22BC0 800477C0 00441023 */  subu      $v0, $v0, $a0
/* 22BC4 800477C4 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22BC8 800477C8 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22BCC 800477CC 00021100 */  sll       $v0, $v0, 4
/* 22BD0 800477D0 00621821 */  addu      $v1, $v1, $v0
/* 22BD4 800477D4 8C620000 */  lw        $v0, ($v1)
/* 22BD8 800477D8 34420010 */  ori       $v0, $v0, 0x10
/* 22BDC 800477DC 03E00008 */  jr        $ra
/* 22BE0 800477E0 AC620000 */   sw       $v0, ($v1)
