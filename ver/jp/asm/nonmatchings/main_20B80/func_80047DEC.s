.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047DEC
/* 231EC 80047DEC 00041040 */  sll       $v0, $a0, 1
/* 231F0 80047DF0 00441021 */  addu      $v0, $v0, $a0
/* 231F4 80047DF4 00021080 */  sll       $v0, $v0, 2
/* 231F8 80047DF8 00441023 */  subu      $v0, $v0, $a0
/* 231FC 80047DFC 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 23200 80047E00 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 23204 80047E04 00021100 */  sll       $v0, $v0, 4
/* 23208 80047E08 00621821 */  addu      $v1, $v1, $v0
/* 2320C 80047E0C 8C620000 */  lw        $v0, ($v1)
/* 23210 80047E10 34420400 */  ori       $v0, $v0, 0x400
/* 23214 80047E14 03E00008 */  jr        $ra
/* 23218 80047E18 AC620000 */   sw       $v0, ($v1)
