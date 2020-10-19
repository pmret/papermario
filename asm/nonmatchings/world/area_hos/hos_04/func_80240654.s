.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240654
/* A27524 80240654 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* A27528 80240658 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* A2752C 8024065C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A27530 80240660 AFBF0010 */  sw        $ra, 0x10($sp)
/* A27534 80240664 908300A8 */  lbu       $v1, 0xa8($a0)
/* A27538 80240668 2C620005 */  sltiu     $v0, $v1, 5
/* A2753C 8024066C 10400003 */  beqz      $v0, .L8024067C
/* A27540 80240670 24620001 */   addiu    $v0, $v1, 1
/* A27544 80240674 0C00D994 */  jal       begin_state_intro
/* A27548 80240678 A08200A8 */   sb       $v0, 0xa8($a0)
.L8024067C:
/* A2754C 8024067C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A27550 80240680 24020001 */  addiu     $v0, $zero, 1
/* A27554 80240684 03E00008 */  jr        $ra
/* A27558 80240688 27BD0018 */   addiu    $sp, $sp, 0x18
