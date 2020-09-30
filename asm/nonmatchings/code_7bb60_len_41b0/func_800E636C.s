.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E636C
/* 7F81C 800E636C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7F820 800E6370 AFB00010 */  sw        $s0, 0x10($sp)
/* 7F824 800E6374 0080802D */  daddu     $s0, $a0, $zero
/* 7F828 800E6378 3C048011 */  lui       $a0, 0x8011
/* 7F82C 800E637C 8C84C96C */  lw        $a0, -0x3694($a0)
/* 7F830 800E6380 04800004 */  bltz      $a0, .L800E6394
/* 7F834 800E6384 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7F838 800E6388 0C00E2B7 */  jal       get_npc_by_index
/* 7F83C 800E638C 00000000 */   nop      
/* 7F840 800E6390 AC500028 */  sw        $s0, 0x28($v0)
.L800E6394:
/* 7F844 800E6394 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7F848 800E6398 8FB00010 */  lw        $s0, 0x10($sp)
/* 7F84C 800E639C 03E00008 */  jr        $ra
/* 7F850 800E63A0 27BD0018 */   addiu    $sp, $sp, 0x18
