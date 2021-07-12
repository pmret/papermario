.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024032C_A3FA6C
/* A3FA6C 8024032C 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* A3FA70 80240330 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* A3FA74 80240334 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3FA78 80240338 AFBF0010 */  sw        $ra, 0x10($sp)
/* A3FA7C 8024033C 908300A8 */  lbu       $v1, 0xa8($a0)
/* A3FA80 80240340 2C620005 */  sltiu     $v0, $v1, 5
/* A3FA84 80240344 10400003 */  beqz      $v0, .L80240354
/* A3FA88 80240348 24620001 */   addiu    $v0, $v1, 1
/* A3FA8C 8024034C 0C00D994 */  jal       state_init_intro
/* A3FA90 80240350 A08200A8 */   sb       $v0, 0xa8($a0)
.L80240354:
/* A3FA94 80240354 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3FA98 80240358 24020001 */  addiu     $v0, $zero, 1
/* A3FA9C 8024035C 03E00008 */  jr        $ra
/* A3FAA0 80240360 27BD0018 */   addiu    $sp, $sp, 0x18
