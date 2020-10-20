.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431E4
/* 8B3254 802431E4 3C028011 */  lui       $v0, 0x8011
/* 8B3258 802431E8 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 8B325C 802431EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B3260 802431F0 10400003 */  beqz      $v0, .L80243200
/* 8B3264 802431F4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8B3268 802431F8 0C03AE06 */  jal       partner_suspend_ability_script
/* 8B326C 802431FC 00000000 */   nop      
.L80243200:
/* 8B3270 80243200 24020002 */  addiu     $v0, $zero, 2
/* 8B3274 80243204 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B3278 80243208 03E00008 */  jr        $ra
/* 8B327C 8024320C 27BD0018 */   addiu    $sp, $sp, 0x18
