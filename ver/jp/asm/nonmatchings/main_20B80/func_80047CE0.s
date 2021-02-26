.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047CE0
/* 230E0 80047CE0 00041040 */  sll       $v0, $a0, 1
/* 230E4 80047CE4 00441021 */  addu      $v0, $v0, $a0
/* 230E8 80047CE8 00021080 */  sll       $v0, $v0, 2
/* 230EC 80047CEC 00441023 */  subu      $v0, $v0, $a0
/* 230F0 80047CF0 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 230F4 80047CF4 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 230F8 80047CF8 00021100 */  sll       $v0, $v0, 4
/* 230FC 80047CFC 00621821 */  addu      $v1, $v1, $v0
/* 23100 80047D00 8C620000 */  lw        $v0, ($v1)
/* 23104 80047D04 34420200 */  ori       $v0, $v0, 0x200
/* 23108 80047D08 03E00008 */  jr        $ra
/* 2310C 80047D0C AC620000 */   sw       $v0, ($v1)
