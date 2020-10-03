.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050128
/* 2B528 80050128 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B52C 8005012C 00821821 */  addu      $v1, $a0, $v0
/* 2B530 80050130 2C420004 */  sltiu     $v0, $v0, 4
/* 2B534 80050134 9063004C */  lbu       $v1, 0x4c($v1)
/* 2B538 80050138 10400005 */  beqz      $v0, .L80050150
/* 2B53C 8005013C 00031600 */   sll      $v0, $v1, 0x18
/* 2B540 80050140 04400003 */  bltz      $v0, .L80050150
/* 2B544 80050144 00000000 */   nop      
/* 2B548 80050148 03E00008 */  jr        $ra
/* 2B54C 8005014C A0A3005B */   sb       $v1, 0x5b($a1)
.L80050150:
/* 2B550 80050150 90820235 */  lbu       $v0, 0x235($a0)
/* 2B554 80050154 03E00008 */  jr        $ra
/* 2B558 80050158 A0A2005B */   sb       $v0, 0x5b($a1)
