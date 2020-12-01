.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_982530
/* 982530 802400F0 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x2)
/* 982534 802400F4 8442A552 */  lh        $v0, %lo(gCollisionStatus+0x2)($v0)
/* 982538 802400F8 38420025 */  xori      $v0, $v0, 0x25
/* 98253C 802400FC 0002102B */  sltu      $v0, $zero, $v0
/* 982540 80240100 03E00008 */  jr        $ra
/* 982544 80240104 00021040 */   sll      $v0, $v0, 1
/* 982548 80240108 00000000 */  nop       
/* 98254C 8024010C 00000000 */  nop       
