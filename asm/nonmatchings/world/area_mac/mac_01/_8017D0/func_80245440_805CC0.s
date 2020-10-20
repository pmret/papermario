.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245440_805CC0
/* 805CC0 80245440 3C028011 */  lui       $v0, 0x8011
/* 805CC4 80245444 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 805CC8 80245448 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 805CCC 8024544C AFB00010 */  sw        $s0, 0x10($sp)
/* 805CD0 80245450 0080802D */  daddu     $s0, $a0, $zero
/* 805CD4 80245454 AFBF0014 */  sw        $ra, 0x14($sp)
/* 805CD8 80245458 8E0400AC */  lw        $a0, 0xac($s0)
/* 805CDC 8024545C 50440005 */  beql      $v0, $a0, .L80245474
/* 805CE0 80245460 AE000088 */   sw       $zero, 0x88($s0)
/* 805CE4 80245464 0C03AC5A */  jal       func_800EB168
/* 805CE8 80245468 00000000 */   nop      
/* 805CEC 8024546C 24020001 */  addiu     $v0, $zero, 1
/* 805CF0 80245470 AE020088 */  sw        $v0, 0x88($s0)
.L80245474:
/* 805CF4 80245474 24020002 */  addiu     $v0, $zero, 2
/* 805CF8 80245478 8FBF0014 */  lw        $ra, 0x14($sp)
/* 805CFC 8024547C 8FB00010 */  lw        $s0, 0x10($sp)
/* 805D00 80245480 03E00008 */  jr        $ra
/* 805D04 80245484 27BD0018 */   addiu    $sp, $sp, 0x18
