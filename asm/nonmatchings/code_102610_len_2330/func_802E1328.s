.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1328
/* 102BA8 802E1328 3C02802F */  lui       $v0, %hi(D_802EB394)
/* 102BAC 802E132C 8C42B394 */  lw        $v0, %lo(D_802EB394)($v0)
/* 102BB0 802E1330 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102BB4 802E1334 10400003 */  beqz      $v0, .L802E1344
/* 102BB8 802E1338 AFBF0010 */   sw       $ra, 0x10($sp)
/* 102BBC 802E133C 0C043F5A */  jal       func_8010FD68
/* 102BC0 802E1340 00000000 */   nop      
.L802E1344:
/* 102BC4 802E1344 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102BC8 802E1348 03E00008 */  jr        $ra
/* 102BCC 802E134C 27BD0018 */   addiu    $sp, $sp, 0x18
