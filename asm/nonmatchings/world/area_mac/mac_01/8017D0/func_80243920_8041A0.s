.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243920_8041A0
/* 8041A0 80243920 3C028011 */  lui       $v0, 0x8011
/* 8041A4 80243924 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 8041A8 80243928 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8041AC 8024392C 10400003 */  beqz      $v0, .L8024393C
/* 8041B0 80243930 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8041B4 80243934 0C03AE06 */  jal       partner_suspend_ability_script
/* 8041B8 80243938 00000000 */   nop      
.L8024393C:
/* 8041BC 8024393C 24020002 */  addiu     $v0, $zero, 2
/* 8041C0 80243940 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8041C4 80243944 03E00008 */  jr        $ra
/* 8041C8 80243948 27BD0018 */   addiu    $sp, $sp, 0x18
