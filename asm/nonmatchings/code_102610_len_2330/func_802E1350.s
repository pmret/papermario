.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1350
/* 102BD0 802E1350 3C02802F */  lui       $v0, 0x802f
/* 102BD4 802E1354 8C42B390 */  lw        $v0, -0x4c70($v0)
/* 102BD8 802E1358 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102BDC 802E135C 10400013 */  beqz      $v0, .L802E13AC
/* 102BE0 802E1360 AFBF0010 */   sw       $ra, 0x10($sp)
/* 102BE4 802E1364 3C02802F */  lui       $v0, 0x802f
/* 102BE8 802E1368 8C42B398 */  lw        $v0, -0x4c68($v0)
/* 102BEC 802E136C 904304E8 */  lbu       $v1, 0x4e8($v0)
/* 102BF0 802E1370 24020001 */  addiu     $v0, $zero, 1
/* 102BF4 802E1374 14620007 */  bne       $v1, $v0, .L802E1394
/* 102BF8 802E1378 00000000 */   nop      
/* 102BFC 802E137C 3C05802F */  lui       $a1, 0x802f
/* 102C00 802E1380 24A599DC */  addiu     $a1, $a1, -0x6624
/* 102C04 802E1384 0C043EF0 */  jal       func_8010FBC0
/* 102C08 802E1388 00000000 */   nop      
/* 102C0C 802E138C 080B84E7 */  j         .L802E139C
/* 102C10 802E1390 00000000 */   nop      
.L802E1394:
/* 102C14 802E1394 0C043F5A */  jal       func_8010FD68
/* 102C18 802E1398 00000000 */   nop      
.L802E139C:
/* 102C1C 802E139C 3C04802F */  lui       $a0, 0x802f
/* 102C20 802E13A0 8C84B39C */  lw        $a0, -0x4c64($a0)
/* 102C24 802E13A4 0C04971C */  jal       close_message
/* 102C28 802E13A8 00000000 */   nop      
.L802E13AC:
/* 102C2C 802E13AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 102C30 802E13B0 03E00008 */  jr        $ra
/* 102C34 802E13B4 27BD0018 */   addiu    $sp, $sp, 0x18
