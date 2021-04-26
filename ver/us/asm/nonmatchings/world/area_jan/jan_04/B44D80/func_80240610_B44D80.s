.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_04_UnkFunc41
/* B44D80 80240610 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B44D84 80240614 AFB20018 */  sw        $s2, 0x18($sp)
/* B44D88 80240618 0080902D */  daddu     $s2, $a0, $zero
/* B44D8C 8024061C AFB10014 */  sw        $s1, 0x14($sp)
/* B44D90 80240620 00A0882D */  daddu     $s1, $a1, $zero
/* B44D94 80240624 AFBF0024 */  sw        $ra, 0x24($sp)
/* B44D98 80240628 AFB40020 */  sw        $s4, 0x20($sp)
/* B44D9C 8024062C AFB3001C */  sw        $s3, 0x1c($sp)
/* B44DA0 80240630 AFB00010 */  sw        $s0, 0x10($sp)
/* B44DA4 80240634 8E50000C */  lw        $s0, 0xc($s2)
/* B44DA8 80240638 8E050000 */  lw        $a1, ($s0)
/* B44DAC 8024063C 0C0B1EAF */  jal       get_variable
/* B44DB0 80240640 26100004 */   addiu    $s0, $s0, 4
/* B44DB4 80240644 0240202D */  daddu     $a0, $s2, $zero
/* B44DB8 80240648 8E050000 */  lw        $a1, ($s0)
/* B44DBC 8024064C 0C0B1EAF */  jal       get_variable
/* B44DC0 80240650 0040802D */   daddu    $s0, $v0, $zero
/* B44DC4 80240654 0200202D */  daddu     $a0, $s0, $zero
/* B44DC8 80240658 0C00EAD2 */  jal       get_npc_safe
/* B44DCC 8024065C 0040A02D */   daddu    $s4, $v0, $zero
/* B44DD0 80240660 3C138011 */  lui       $s3, %hi(gPlayerData)
/* B44DD4 80240664 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* B44DD8 80240668 12200006 */  beqz      $s1, .L80240684
/* B44DDC 8024066C 0040802D */   daddu    $s0, $v0, $zero
/* B44DE0 80240670 82620012 */  lb        $v0, 0x12($s3)
/* B44DE4 80240674 54400003 */  bnel      $v0, $zero, .L80240684
/* B44DE8 80240678 AE400070 */   sw       $zero, 0x70($s2)
/* B44DEC 8024067C 24020002 */  addiu     $v0, $zero, 2
/* B44DF0 80240680 AE420070 */  sw        $v0, 0x70($s2)
.L80240684:
/* B44DF4 80240684 8E430070 */  lw        $v1, 0x70($s2)
/* B44DF8 80240688 24110001 */  addiu     $s1, $zero, 1
/* B44DFC 8024068C 10710013 */  beq       $v1, $s1, .L802406DC
/* B44E00 80240690 28620002 */   slti     $v0, $v1, 2
/* B44E04 80240694 10400005 */  beqz      $v0, .L802406AC
/* B44E08 80240698 24020002 */   addiu    $v0, $zero, 2
/* B44E0C 8024069C 10600009 */  beqz      $v1, .L802406C4
/* B44E10 802406A0 0000102D */   daddu    $v0, $zero, $zero
/* B44E14 802406A4 080901DD */  j         .L80240774
/* B44E18 802406A8 00000000 */   nop
.L802406AC:
/* B44E1C 802406AC 10620013 */  beq       $v1, $v0, .L802406FC
/* B44E20 802406B0 24020003 */   addiu    $v0, $zero, 3
/* B44E24 802406B4 1062001E */  beq       $v1, $v0, .L80240730
/* B44E28 802406B8 0000102D */   daddu    $v0, $zero, $zero
/* B44E2C 802406BC 080901DD */  j         .L80240774
/* B44E30 802406C0 00000000 */   nop
.L802406C4:
/* B44E34 802406C4 0C03AC5A */  jal       func_800EB168
/* B44E38 802406C8 0000202D */   daddu    $a0, $zero, $zero
/* B44E3C 802406CC 2402001E */  addiu     $v0, $zero, 0x1e
/* B44E40 802406D0 AE420074 */  sw        $v0, 0x74($s2)
/* B44E44 802406D4 080901DC */  j         .L80240770
/* B44E48 802406D8 AE510070 */   sw       $s1, 0x70($s2)
.L802406DC:
/* B44E4C 802406DC 8E420074 */  lw        $v0, 0x74($s2)
/* B44E50 802406E0 2403FFFF */  addiu     $v1, $zero, -1
/* B44E54 802406E4 2442FFFF */  addiu     $v0, $v0, -1
/* B44E58 802406E8 14430021 */  bne       $v0, $v1, .L80240770
/* B44E5C 802406EC AE420074 */   sw       $v0, 0x74($s2)
/* B44E60 802406F0 24020002 */  addiu     $v0, $zero, 2
/* B44E64 802406F4 080901DC */  j         .L80240770
/* B44E68 802406F8 AE420070 */   sw       $v0, 0x70($s2)
.L802406FC:
/* B44E6C 802406FC 0200202D */  daddu     $a0, $s0, $zero
/* B44E70 80240700 00141600 */  sll       $v0, $s4, 0x18
/* B44E74 80240704 00021543 */  sra       $v0, $v0, 0x15
/* B44E78 80240708 02621021 */  addu      $v0, $s3, $v0
/* B44E7C 8024070C A2740012 */  sb        $s4, 0x12($s3)
/* B44E80 80240710 0C03BD17 */  jal       clear_partner_move_history
/* B44E84 80240714 A0510014 */   sb       $s1, 0x14($v0)
/* B44E88 80240718 82640012 */  lb        $a0, 0x12($s3)
/* B44E8C 8024071C 0C03ACA9 */  jal       func_800EB2A4
/* B44E90 80240720 00000000 */   nop
/* B44E94 80240724 24020003 */  addiu     $v0, $zero, 3
/* B44E98 80240728 080901DC */  j         .L80240770
/* B44E9C 8024072C AE420070 */   sw       $v0, 0x70($s2)
.L80240730:
/* B44EA0 80240730 0C00EAD2 */  jal       get_npc_safe
/* B44EA4 80240734 2404FFFC */   addiu    $a0, $zero, -4
/* B44EA8 80240738 8E05000C */  lw        $a1, 0xc($s0)
/* B44EAC 8024073C 0C00ECD0 */  jal       set_npc_yaw
/* B44EB0 80240740 0040202D */   daddu    $a0, $v0, $zero
/* B44EB4 80240744 0200202D */  daddu     $a0, $s0, $zero
/* B44EB8 80240748 8E020000 */  lw        $v0, ($s0)
/* B44EBC 8024074C 2403FFFB */  addiu     $v1, $zero, -5
/* B44EC0 80240750 00431024 */  and       $v0, $v0, $v1
/* B44EC4 80240754 0C00EAFF */  jal       disable_npc_shadow
/* B44EC8 80240758 AE020000 */   sw       $v0, ($s0)
/* B44ECC 8024075C 3C01C47A */  lui       $at, 0xc47a
/* B44ED0 80240760 44810000 */  mtc1      $at, $f0
/* B44ED4 80240764 24020002 */  addiu     $v0, $zero, 2
/* B44ED8 80240768 080901DD */  j         .L80240774
/* B44EDC 8024076C E600003C */   swc1     $f0, 0x3c($s0)
.L80240770:
/* B44EE0 80240770 0000102D */  daddu     $v0, $zero, $zero
.L80240774:
/* B44EE4 80240774 8FBF0024 */  lw        $ra, 0x24($sp)
/* B44EE8 80240778 8FB40020 */  lw        $s4, 0x20($sp)
/* B44EEC 8024077C 8FB3001C */  lw        $s3, 0x1c($sp)
/* B44EF0 80240780 8FB20018 */  lw        $s2, 0x18($sp)
/* B44EF4 80240784 8FB10014 */  lw        $s1, 0x14($sp)
/* B44EF8 80240788 8FB00010 */  lw        $s0, 0x10($sp)
/* B44EFC 8024078C 03E00008 */  jr        $ra
/* B44F00 80240790 27BD0028 */   addiu    $sp, $sp, 0x28
/* B44F04 80240794 00000000 */  nop
/* B44F08 80240798 00000000 */  nop
/* B44F0C 8024079C 00000000 */  nop
