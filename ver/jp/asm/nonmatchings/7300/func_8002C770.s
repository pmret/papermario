.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C770
/* 7B70 8002C770 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7B74 8002C774 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7B78 8002C778 0C019898 */  jal       func_80066260
/* 7B7C 8002C77C 00000000 */   nop
/* 7B80 8002C780 0040202D */  daddu     $a0, $v0, $zero
/* 7B84 8002C784 8C830004 */  lw        $v1, 4($a0)
/* 7B88 8002C788 2402FFFF */  addiu     $v0, $zero, -1
/* 7B8C 8002C78C 50620010 */  beql      $v1, $v0, .L8002C7D0
/* 7B90 8002C790 0000102D */   daddu    $v0, $zero, $zero
/* 7B94 8002C794 0040182D */  daddu     $v1, $v0, $zero
/* 7B98 8002C798 8C820004 */  lw        $v0, 4($a0)
/* 7B9C 8002C79C 2442FFFF */  addiu     $v0, $v0, -1
.L8002C7A0:
/* 7BA0 8002C7A0 2C42007E */  sltiu     $v0, $v0, 0x7e
/* 7BA4 8002C7A4 10400005 */  beqz      $v0, .L8002C7BC
/* 7BA8 8002C7A8 00000000 */   nop
/* 7BAC 8002C7AC 94820012 */  lhu       $v0, 0x12($a0)
/* 7BB0 8002C7B0 30420003 */  andi      $v0, $v0, 3
/* 7BB4 8002C7B4 14400006 */  bnez      $v0, .L8002C7D0
/* 7BB8 8002C7B8 0080102D */   daddu    $v0, $a0, $zero
.L8002C7BC:
/* 7BBC 8002C7BC 8C84000C */  lw        $a0, 0xc($a0)
/* 7BC0 8002C7C0 8C820004 */  lw        $v0, 4($a0)
/* 7BC4 8002C7C4 1443FFF6 */  bne       $v0, $v1, .L8002C7A0
/* 7BC8 8002C7C8 2442FFFF */   addiu    $v0, $v0, -1
/* 7BCC 8002C7CC 0000102D */  daddu     $v0, $zero, $zero
.L8002C7D0:
/* 7BD0 8002C7D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7BD4 8002C7D4 03E00008 */  jr        $ra
/* 7BD8 8002C7D8 27BD0018 */   addiu    $sp, $sp, 0x18
