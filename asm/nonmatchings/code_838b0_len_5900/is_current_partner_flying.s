.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_current_partner_flying
/* 83A54 800EA5A4 3C028011 */  lui       $v0, 0x8011
/* 83A58 800EA5A8 8C42CFEC */  lw        $v0, -0x3014($v0)
/* 83A5C 800EA5AC 8C42000C */  lw        $v0, 0xc($v0)
/* 83A60 800EA5B0 03E00008 */  jr        $ra
/* 83A64 800EA5B4 2C420001 */   sltiu    $v0, $v0, 1
