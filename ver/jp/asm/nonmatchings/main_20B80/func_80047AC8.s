.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047AC8
/* 22EC8 80047AC8 00041040 */  sll       $v0, $a0, 1
/* 22ECC 80047ACC 00441021 */  addu      $v0, $v0, $a0
/* 22ED0 80047AD0 00021080 */  sll       $v0, $v0, 2
/* 22ED4 80047AD4 00441023 */  subu      $v0, $v0, $a0
/* 22ED8 80047AD8 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22EDC 80047ADC 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22EE0 80047AE0 00021100 */  sll       $v0, $v0, 4
/* 22EE4 80047AE4 00621821 */  addu      $v1, $v1, $v0
/* 22EE8 80047AE8 8C620000 */  lw        $v0, ($v1)
/* 22EEC 80047AEC 34420080 */  ori       $v0, $v0, 0x80
/* 22EF0 80047AF0 03E00008 */  jr        $ra
/* 22EF4 80047AF4 AC620000 */   sw       $v0, ($v1)
