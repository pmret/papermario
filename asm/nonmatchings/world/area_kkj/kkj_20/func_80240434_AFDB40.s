.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240434_AFDF74
/* AFDF74 80240434 3C028011 */  lui       $v0, 0x8011
/* AFDF78 80240438 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* AFDF7C 8024043C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFDF80 80240440 10400003 */  beqz      $v0, .L80240450
/* AFDF84 80240444 AFBF0010 */   sw       $ra, 0x10($sp)
/* AFDF88 80240448 0C03AE06 */  jal       partner_suspend_ability_script
/* AFDF8C 8024044C 00000000 */   nop      
.L80240450:
/* AFDF90 80240450 24020002 */  addiu     $v0, $zero, 2
/* AFDF94 80240454 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFDF98 80240458 03E00008 */  jr        $ra
/* AFDF9C 8024045C 27BD0018 */   addiu    $sp, $sp, 0x18
