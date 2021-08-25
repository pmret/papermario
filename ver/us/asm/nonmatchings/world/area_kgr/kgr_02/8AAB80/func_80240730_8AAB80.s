.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_8AAB80
/* 8AAB80 80240730 3C028011 */  lui       $v0, %hi(gPartnerActionStatus+0x3)
/* 8AAB84 80240734 8042EBB3 */  lb        $v0, %lo(gPartnerActionStatus+0x3)($v0)
/* 8AAB88 80240738 38420006 */  xori      $v0, $v0, 6
/* 8AAB8C 8024073C 2C420001 */  sltiu     $v0, $v0, 1
/* 8AAB90 80240740 03E00008 */  jr        $ra
/* 8AAB94 80240744 00021040 */   sll      $v0, $v0, 1
