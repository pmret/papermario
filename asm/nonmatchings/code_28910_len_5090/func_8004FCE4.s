.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FCE4
/* 2B0E4 8004FCE4 808300D4 */  lb        $v1, 0xd4($a0)
/* 2B0E8 8004FCE8 00031040 */  sll       $v0, $v1, 1
/* 2B0EC 8004FCEC 00431021 */  addu      $v0, $v0, $v1
/* 2B0F0 8004FCF0 000210C0 */  sll       $v0, $v0, 3
/* 2B0F4 8004FCF4 00431021 */  addu      $v0, $v0, $v1
/* 2B0F8 8004FCF8 00021080 */  sll       $v0, $v0, 2
/* 2B0FC 8004FCFC 03E00008 */  jr        $ra
/* 2B100 8004FD00 A482020C */   sh       $v0, 0x20c($a0)
