.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B84
/* 833384 80241B84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 833388 80241B88 AFB00010 */  sw        $s0, 0x10($sp)
/* 83338C 80241B8C 0080802D */  daddu     $s0, $a0, $zero
/* 833390 80241B90 3C05F5DE */  lui       $a1, 0xf5de
/* 833394 80241B94 AFBF0014 */  sw        $ra, 0x14($sp)
/* 833398 80241B98 0C0B1EAF */  jal       get_variable
/* 83339C 80241B9C 34A5019D */   ori      $a1, $a1, 0x19d
/* 8333A0 80241BA0 54400003 */  bnel      $v0, $zero, .L80241BB0
/* 8333A4 80241BA4 3C05F5DE */   lui      $a1, 0xf5de
/* 8333A8 80241BA8 080906F0 */  j         .L80241BC0
/* 8333AC 80241BAC 2402FFFF */   addiu    $v0, $zero, -1
.L80241BB0:
/* 8333B0 80241BB0 34A5019D */  ori       $a1, $a1, 0x19d
/* 8333B4 80241BB4 0200202D */  daddu     $a0, $s0, $zero
/* 8333B8 80241BB8 0C0B1EAF */  jal       get_variable
/* 8333BC 80241BBC 00452821 */   addu     $a1, $v0, $a1
.L80241BC0:
/* 8333C0 80241BC0 AE020084 */  sw        $v0, 0x84($s0)
/* 8333C4 80241BC4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8333C8 80241BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8333CC 80241BCC 24020002 */  addiu     $v0, $zero, 2
/* 8333D0 80241BD0 03E00008 */  jr        $ra
/* 8333D4 80241BD4 27BD0018 */   addiu    $sp, $sp, 0x18
