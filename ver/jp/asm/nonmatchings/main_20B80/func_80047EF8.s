.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047EF8
/* 232F8 80047EF8 00041040 */  sll       $v0, $a0, 1
/* 232FC 80047EFC 00441021 */  addu      $v0, $v0, $a0
/* 23300 80047F00 00021080 */  sll       $v0, $v0, 2
/* 23304 80047F04 00441023 */  subu      $v0, $v0, $a0
/* 23308 80047F08 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 2330C 80047F0C 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 23310 80047F10 00021100 */  sll       $v0, $v0, 4
/* 23314 80047F14 00621821 */  addu      $v1, $v1, $v0
/* 23318 80047F18 8C620000 */  lw        $v0, ($v1)
/* 2331C 80047F1C 34420800 */  ori       $v0, $v0, 0x800
/* 23320 80047F20 03E00008 */  jr        $ra
/* 23324 80047F24 AC620000 */   sw       $v0, ($v1)
/* 23328 80047F28 00000000 */  nop
/* 2332C 80047F2C 00000000 */  nop
