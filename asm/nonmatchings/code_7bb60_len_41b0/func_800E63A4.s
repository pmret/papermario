.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E63A4
/* 7F854 800E63A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7F858 800E63A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7F85C 800E63AC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7F860 800E63B0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7F864 800E63B4 10800005 */  beqz      $a0, .L800E63CC
/* 7F868 800E63B8 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7F86C 800E63BC 0C039769 */  jal       set_action_state
/* 7F870 800E63C0 24040019 */   addiu    $a0, $zero, 0x19
/* 7F874 800E63C4 08039906 */  j         .L800E6418
/* 7F878 800E63C8 00000000 */   nop      
.L800E63CC:
/* 7F87C 800E63CC 2403DFFF */  addiu     $v1, $zero, -0x2001
/* 7F880 800E63D0 8E020004 */  lw        $v0, 4($s0)
/* 7F884 800E63D4 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 7F888 800E63D8 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 7F88C 800E63DC 00431024 */  and       $v0, $v0, $v1
/* 7F890 800E63E0 AE020004 */  sw        $v0, 4($s0)
/* 7F894 800E63E4 9082007E */  lbu       $v0, 0x7e($a0)
/* 7F898 800E63E8 304200FD */  andi      $v0, $v0, 0xfd
/* 7F89C 800E63EC A082007E */  sb        $v0, 0x7e($a0)
/* 7F8A0 800E63F0 3C048011 */  lui       $a0, 0x8011
/* 7F8A4 800E63F4 8C84C96C */  lw        $a0, -0x3694($a0)
/* 7F8A8 800E63F8 0C00E228 */  jal       free_npc_by_index
/* 7F8AC 800E63FC A200000C */   sb       $zero, 0xc($s0)
/* 7F8B0 800E6400 0C039769 */  jal       set_action_state
/* 7F8B4 800E6404 0000202D */   daddu    $a0, $zero, $zero
/* 7F8B8 800E6408 24020037 */  addiu     $v0, $zero, 0x37
/* 7F8BC 800E640C A60200B0 */  sh        $v0, 0xb0($s0)
/* 7F8C0 800E6410 24020026 */  addiu     $v0, $zero, 0x26
/* 7F8C4 800E6414 A60200B2 */  sh        $v0, 0xb2($s0)
.L800E6418:
/* 7F8C8 800E6418 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7F8CC 800E641C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7F8D0 800E6420 03E00008 */  jr        $ra
/* 7F8D4 800E6424 27BD0018 */   addiu    $sp, $sp, 0x18
