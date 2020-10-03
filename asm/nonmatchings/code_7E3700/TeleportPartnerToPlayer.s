.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel TeleportPartnerToPlayer
/* 7E46FC 8028387C 3C028011 */  lui       $v0, 0x8011
/* 7E4700 80283880 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 7E4704 80283884 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E4708 80283888 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E470C 8028388C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7E4710 80283890 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7E4714 80283894 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E4718 80283898 0220902D */  daddu     $s2, $s1, $zero
/* 7E471C 8028389C AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E4720 802838A0 10400012 */  beqz      $v0, .L802838EC
/* 7E4724 802838A4 AFB00010 */   sw       $s0, 0x10($sp)
/* 7E4728 802838A8 0C00EABB */  jal       get_npc_unsafe
/* 7E472C 802838AC 2404FFFC */   addiu    $a0, $zero, -4
/* 7E4730 802838B0 C6200028 */  lwc1      $f0, 0x28($s1)
/* 7E4734 802838B4 0040802D */  daddu     $s0, $v0, $zero
/* 7E4738 802838B8 E6000038 */  swc1      $f0, 0x38($s0)
/* 7E473C 802838BC C6200030 */  lwc1      $f0, 0x30($s1)
/* 7E4740 802838C0 0C03A969 */  jal       is_current_partner_flying
/* 7E4744 802838C4 E6000040 */   swc1     $f0, 0x40($s0)
/* 7E4748 802838C8 10400003 */  beqz      $v0, .L802838D8
/* 7E474C 802838CC 00000000 */   nop      
/* 7E4750 802838D0 C620002C */  lwc1      $f0, 0x2c($s1)
/* 7E4754 802838D4 E600003C */  swc1      $f0, 0x3c($s0)
.L802838D8:
/* 7E4758 802838D8 8E450080 */  lw        $a1, 0x80($s2)
/* 7E475C 802838DC 0C00ECD0 */  jal       set_npc_yaw
/* 7E4760 802838E0 0200202D */   daddu    $a0, $s0, $zero
/* 7E4764 802838E4 0C03BD17 */  jal       clear_partner_move_history
/* 7E4768 802838E8 0200202D */   daddu    $a0, $s0, $zero
.L802838EC:
/* 7E476C 802838EC 24020002 */  addiu     $v0, $zero, 2
/* 7E4770 802838F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E4774 802838F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E4778 802838F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E477C 802838FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E4780 80283900 03E00008 */  jr        $ra
/* 7E4784 80283904 27BD0020 */   addiu    $sp, $sp, 0x20
