.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_current_partner_id
/* 7E538 800E5088 3C028011 */  lui       $v0, 0x8011
/* 7E53C 800E508C 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 7E540 800E5090 03E00008 */  jr        $ra
/* 7E544 800E5094 00000000 */   nop      
