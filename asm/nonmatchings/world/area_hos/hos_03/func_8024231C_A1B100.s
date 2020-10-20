.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024231C_A1D41C
/* A1D41C 8024231C 3C028011 */  lui       $v0, 0x8011
/* A1D420 80242320 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* A1D424 80242324 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D428 80242328 10400003 */  beqz      $v0, .L80242338
/* A1D42C 8024232C AFBF0010 */   sw       $ra, 0x10($sp)
/* A1D430 80242330 0C03AE06 */  jal       partner_suspend_ability_script
/* A1D434 80242334 00000000 */   nop      
.L80242338:
/* A1D438 80242338 24020002 */  addiu     $v0, $zero, 2
/* A1D43C 8024233C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D440 80242340 03E00008 */  jr        $ra
/* A1D444 80242344 27BD0018 */   addiu    $sp, $sp, 0x18
