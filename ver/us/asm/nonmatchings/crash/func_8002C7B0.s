.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C7B0
/* 7BB0 8002C7B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7BB4 8002C7B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7BB8 8002C7B8 0C0198A4 */  jal       osGetActiveQueue
/* 7BBC 8002C7BC 00000000 */   nop
/* 7BC0 8002C7C0 0040202D */  daddu     $a0, $v0, $zero
/* 7BC4 8002C7C4 8C830004 */  lw        $v1, 4($a0)
/* 7BC8 8002C7C8 2402FFFF */  addiu     $v0, $zero, -1
/* 7BCC 8002C7CC 50620010 */  beql      $v1, $v0, .L8002C810
/* 7BD0 8002C7D0 0000102D */   daddu    $v0, $zero, $zero
/* 7BD4 8002C7D4 0040182D */  daddu     $v1, $v0, $zero
/* 7BD8 8002C7D8 8C820004 */  lw        $v0, 4($a0)
/* 7BDC 8002C7DC 2442FFFF */  addiu     $v0, $v0, -1
.L8002C7E0:
/* 7BE0 8002C7E0 2C42007E */  sltiu     $v0, $v0, 0x7e
/* 7BE4 8002C7E4 10400005 */  beqz      $v0, .L8002C7FC
/* 7BE8 8002C7E8 00000000 */   nop
/* 7BEC 8002C7EC 94820012 */  lhu       $v0, 0x12($a0)
/* 7BF0 8002C7F0 30420003 */  andi      $v0, $v0, 3
/* 7BF4 8002C7F4 14400006 */  bnez      $v0, .L8002C810
/* 7BF8 8002C7F8 0080102D */   daddu    $v0, $a0, $zero
.L8002C7FC:
/* 7BFC 8002C7FC 8C84000C */  lw        $a0, 0xc($a0)
/* 7C00 8002C800 8C820004 */  lw        $v0, 4($a0)
/* 7C04 8002C804 1443FFF6 */  bne       $v0, $v1, .L8002C7E0
/* 7C08 8002C808 2442FFFF */   addiu    $v0, $v0, -1
/* 7C0C 8002C80C 0000102D */  daddu     $v0, $zero, $zero
.L8002C810:
/* 7C10 8002C810 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7C14 8002C814 03E00008 */  jr        $ra
/* 7C18 8002C818 27BD0018 */   addiu    $sp, $sp, 0x18
