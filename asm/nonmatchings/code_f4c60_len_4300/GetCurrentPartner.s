.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetCurrentPartner
/* F74BC 802D2B0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F74C0 802D2B10 AFBF0010 */  sw        $ra, 0x10($sp)
/* F74C4 802D2B14 8C82000C */  lw        $v0, 0xc($a0)
/* F74C8 802D2B18 3C038011 */  lui       $v1, 0x8011
/* F74CC 802D2B1C 8063EBB0 */  lb        $v1, -0x1450($v1)
/* F74D0 802D2B20 8C450000 */  lw        $a1, ($v0)
/* F74D4 802D2B24 10600004 */  beqz      $v1, .L802D2B38
/* F74D8 802D2B28 0000302D */   daddu    $a2, $zero, $zero
/* F74DC 802D2B2C 3C028011 */  lui       $v0, 0x8011
/* F74E0 802D2B30 2442F290 */  addiu     $v0, $v0, -0xd70
/* F74E4 802D2B34 80460012 */  lb        $a2, 0x12($v0)
.L802D2B38:
/* F74E8 802D2B38 0C0B2026 */  jal       set_variable
/* F74EC 802D2B3C 00000000 */   nop      
/* F74F0 802D2B40 8FBF0010 */  lw        $ra, 0x10($sp)
/* F74F4 802D2B44 24020002 */  addiu     $v0, $zero, 2
/* F74F8 802D2B48 03E00008 */  jr        $ra
/* F74FC 802D2B4C 27BD0018 */   addiu    $sp, $sp, 0x18
