.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241414_8ED234
/* 8ED234 80241414 3C028011 */  lui       $v0, 0x8011
/* 8ED238 80241418 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 8ED23C 8024141C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED240 80241420 10400003 */  beqz      $v0, .L80241430
/* 8ED244 80241424 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8ED248 80241428 0C03AE06 */  jal       partner_suspend_ability_script
/* 8ED24C 8024142C 00000000 */   nop      
.L80241430:
/* 8ED250 80241430 24020002 */  addiu     $v0, $zero, 2
/* 8ED254 80241434 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED258 80241438 03E00008 */  jr        $ra
/* 8ED25C 8024143C 27BD0018 */   addiu    $sp, $sp, 0x18
