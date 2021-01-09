.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240510_B1BA80
/* B1BA80 80240510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1BA84 80240514 AFB00010 */  sw        $s0, 0x10($sp)
/* B1BA88 80240518 0080802D */  daddu     $s0, $a0, $zero
/* B1BA8C 8024051C 3C048024 */  lui       $a0, %hi(func_80240574_B1B5D4)
/* B1BA90 80240520 24840574 */  addiu     $a0, $a0, %lo(func_80240574_B1B5D4)
/* B1BA94 80240524 AFBF0014 */  sw        $ra, 0x14($sp)
/* B1BA98 80240528 0C048C56 */  jal       bind_dynamic_entity_3
/* B1BA9C 8024052C 0000282D */   daddu    $a1, $zero, $zero
/* B1BAA0 80240530 8E03013C */  lw        $v1, 0x13c($s0)
/* B1BAA4 80240534 2404FFFC */  addiu     $a0, $zero, -4
/* B1BAA8 80240538 0C00EAD2 */  jal       get_npc_safe
/* B1BAAC 8024053C AC620004 */   sw       $v0, 4($v1)
/* B1BAB0 80240540 0040282D */  daddu     $a1, $v0, $zero
/* B1BAB4 80240544 10A00007 */  beqz      $a1, .L80240564
/* B1BAB8 80240548 24020002 */   addiu    $v0, $zero, 2
/* B1BABC 8024054C 8CA30000 */  lw        $v1, ($a1)
/* B1BAC0 80240550 3C040002 */  lui       $a0, 2
/* B1BAC4 80240554 00641825 */  or        $v1, $v1, $a0
/* B1BAC8 80240558 3C040008 */  lui       $a0, 8
/* B1BACC 8024055C 00641825 */  or        $v1, $v1, $a0
/* B1BAD0 80240560 ACA30000 */  sw        $v1, ($a1)
.L80240564:
/* B1BAD4 80240564 8FBF0014 */  lw        $ra, 0x14($sp)
/* B1BAD8 80240568 8FB00010 */  lw        $s0, 0x10($sp)
/* B1BADC 8024056C 03E00008 */  jr        $ra
/* B1BAE0 80240570 27BD0018 */   addiu    $sp, $sp, 0x18
