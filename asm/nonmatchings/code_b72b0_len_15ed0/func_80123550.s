.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80123550
/* B9C50 80123550 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9C54 80123554 AFB00010 */  sw        $s0, 0x10($sp)
/* B9C58 80123558 0000802D */  daddu     $s0, $zero, $zero
/* B9C5C 8012355C AFBF0014 */  sw        $ra, 0x14($sp)
.L80123560:
/* B9C60 80123560 3C038015 */  lui       $v1, %hi(gCurrentDynamicEntityListPtr)
/* B9C64 80123564 8C634420 */  lw        $v1, %lo(gCurrentDynamicEntityListPtr)($v1)
/* B9C68 80123568 00101080 */  sll       $v0, $s0, 2
/* B9C6C 8012356C 00431021 */  addu      $v0, $v0, $v1
/* B9C70 80123570 8C430000 */  lw        $v1, ($v0)
/* B9C74 80123574 5060000B */  beql      $v1, $zero, .L801235A4
/* B9C78 80123578 26100001 */   addiu    $s0, $s0, 1
/* B9C7C 8012357C 8C640000 */  lw        $a0, ($v1)
/* B9C80 80123580 30820002 */  andi      $v0, $a0, 2
/* B9C84 80123584 14400007 */  bnez      $v0, .L801235A4
/* B9C88 80123588 26100001 */   addiu    $s0, $s0, 1
/* B9C8C 8012358C 30820008 */  andi      $v0, $a0, 8
/* B9C90 80123590 10400004 */  beqz      $v0, .L801235A4
/* B9C94 80123594 00000000 */   nop
/* B9C98 80123598 8C620008 */  lw        $v0, 8($v1)
/* B9C9C 8012359C 0040F809 */  jalr      $v0
/* B9CA0 801235A0 00000000 */   nop
.L801235A4:
/* B9CA4 801235A4 2A020010 */  slti      $v0, $s0, 0x10
/* B9CA8 801235A8 1440FFED */  bnez      $v0, .L80123560
/* B9CAC 801235AC 00000000 */   nop
/* B9CB0 801235B0 8FBF0014 */  lw        $ra, 0x14($sp)
/* B9CB4 801235B4 8FB00010 */  lw        $s0, 0x10($sp)
/* B9CB8 801235B8 03E00008 */  jr        $ra
/* B9CBC 801235BC 27BD0018 */   addiu    $sp, $sp, 0x18
