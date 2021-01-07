.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047D00
/* 23100 80047D00 00041040 */  sll       $v0, $a0, 1
/* 23104 80047D04 00441021 */  addu      $v0, $v0, $a0
/* 23108 80047D08 00021080 */  sll       $v0, $v0, 2
/* 2310C 80047D0C 00441023 */  subu      $v0, $v0, $a0
/* 23110 80047D10 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23114 80047D14 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23118 80047D18 00021100 */  sll       $v0, $v0, 4
/* 2311C 80047D1C 00621821 */  addu      $v1, $v1, $v0
/* 23120 80047D20 8C620000 */  lw        $v0, ($v1)
/* 23124 80047D24 34420040 */  ori       $v0, $v0, 0x40
/* 23128 80047D28 03E00008 */  jr        $ra
/* 2312C 80047D2C AC620000 */   sw       $v0, ($v1)
