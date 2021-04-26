.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel obk_09_UnkFunc41
/* BDA7B0 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BDA7B4 80240004 AFB20018 */  sw        $s2, 0x18($sp)
/* BDA7B8 80240008 0080902D */  daddu     $s2, $a0, $zero
/* BDA7BC 8024000C AFB10014 */  sw        $s1, 0x14($sp)
/* BDA7C0 80240010 00A0882D */  daddu     $s1, $a1, $zero
/* BDA7C4 80240014 AFBF0024 */  sw        $ra, 0x24($sp)
/* BDA7C8 80240018 AFB40020 */  sw        $s4, 0x20($sp)
/* BDA7CC 8024001C AFB3001C */  sw        $s3, 0x1c($sp)
/* BDA7D0 80240020 AFB00010 */  sw        $s0, 0x10($sp)
/* BDA7D4 80240024 8E50000C */  lw        $s0, 0xc($s2)
/* BDA7D8 80240028 8E050000 */  lw        $a1, ($s0)
/* BDA7DC 8024002C 0C0B1EAF */  jal       get_variable
/* BDA7E0 80240030 26100004 */   addiu    $s0, $s0, 4
/* BDA7E4 80240034 0240202D */  daddu     $a0, $s2, $zero
/* BDA7E8 80240038 8E050000 */  lw        $a1, ($s0)
/* BDA7EC 8024003C 0C0B1EAF */  jal       get_variable
/* BDA7F0 80240040 0040802D */   daddu    $s0, $v0, $zero
/* BDA7F4 80240044 0200202D */  daddu     $a0, $s0, $zero
/* BDA7F8 80240048 0C00EAD2 */  jal       get_npc_safe
/* BDA7FC 8024004C 0040A02D */   daddu    $s4, $v0, $zero
/* BDA800 80240050 3C138011 */  lui       $s3, %hi(gPlayerData)
/* BDA804 80240054 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* BDA808 80240058 12200006 */  beqz      $s1, .L80240074
/* BDA80C 8024005C 0040802D */   daddu    $s0, $v0, $zero
/* BDA810 80240060 82620012 */  lb        $v0, 0x12($s3)
/* BDA814 80240064 54400003 */  bnel      $v0, $zero, .L80240074
/* BDA818 80240068 AE400070 */   sw       $zero, 0x70($s2)
/* BDA81C 8024006C 24020002 */  addiu     $v0, $zero, 2
/* BDA820 80240070 AE420070 */  sw        $v0, 0x70($s2)
.L80240074:
/* BDA824 80240074 8E430070 */  lw        $v1, 0x70($s2)
/* BDA828 80240078 24110001 */  addiu     $s1, $zero, 1
/* BDA82C 8024007C 10710013 */  beq       $v1, $s1, .L802400CC
/* BDA830 80240080 28620002 */   slti     $v0, $v1, 2
/* BDA834 80240084 10400005 */  beqz      $v0, .L8024009C
/* BDA838 80240088 24020002 */   addiu    $v0, $zero, 2
/* BDA83C 8024008C 10600009 */  beqz      $v1, .L802400B4
/* BDA840 80240090 0000102D */   daddu    $v0, $zero, $zero
/* BDA844 80240094 08090059 */  j         .L80240164
/* BDA848 80240098 00000000 */   nop
.L8024009C:
/* BDA84C 8024009C 10620013 */  beq       $v1, $v0, .L802400EC
/* BDA850 802400A0 24020003 */   addiu    $v0, $zero, 3
/* BDA854 802400A4 1062001E */  beq       $v1, $v0, .L80240120
/* BDA858 802400A8 0000102D */   daddu    $v0, $zero, $zero
/* BDA85C 802400AC 08090059 */  j         .L80240164
/* BDA860 802400B0 00000000 */   nop
.L802400B4:
/* BDA864 802400B4 0C03AC5A */  jal       func_800EB168
/* BDA868 802400B8 0000202D */   daddu    $a0, $zero, $zero
/* BDA86C 802400BC 2402001E */  addiu     $v0, $zero, 0x1e
/* BDA870 802400C0 AE420074 */  sw        $v0, 0x74($s2)
/* BDA874 802400C4 08090058 */  j         .L80240160
/* BDA878 802400C8 AE510070 */   sw       $s1, 0x70($s2)
.L802400CC:
/* BDA87C 802400CC 8E420074 */  lw        $v0, 0x74($s2)
/* BDA880 802400D0 2403FFFF */  addiu     $v1, $zero, -1
/* BDA884 802400D4 2442FFFF */  addiu     $v0, $v0, -1
/* BDA888 802400D8 14430021 */  bne       $v0, $v1, .L80240160
/* BDA88C 802400DC AE420074 */   sw       $v0, 0x74($s2)
/* BDA890 802400E0 24020002 */  addiu     $v0, $zero, 2
/* BDA894 802400E4 08090058 */  j         .L80240160
/* BDA898 802400E8 AE420070 */   sw       $v0, 0x70($s2)
.L802400EC:
/* BDA89C 802400EC 0200202D */  daddu     $a0, $s0, $zero
/* BDA8A0 802400F0 00141600 */  sll       $v0, $s4, 0x18
/* BDA8A4 802400F4 00021543 */  sra       $v0, $v0, 0x15
/* BDA8A8 802400F8 02621021 */  addu      $v0, $s3, $v0
/* BDA8AC 802400FC A2740012 */  sb        $s4, 0x12($s3)
/* BDA8B0 80240100 0C03BD17 */  jal       clear_partner_move_history
/* BDA8B4 80240104 A0510014 */   sb       $s1, 0x14($v0)
/* BDA8B8 80240108 82640012 */  lb        $a0, 0x12($s3)
/* BDA8BC 8024010C 0C03ACA9 */  jal       func_800EB2A4
/* BDA8C0 80240110 00000000 */   nop
/* BDA8C4 80240114 24020003 */  addiu     $v0, $zero, 3
/* BDA8C8 80240118 08090058 */  j         .L80240160
/* BDA8CC 8024011C AE420070 */   sw       $v0, 0x70($s2)
.L80240120:
/* BDA8D0 80240120 0C00EAD2 */  jal       get_npc_safe
/* BDA8D4 80240124 2404FFFC */   addiu    $a0, $zero, -4
/* BDA8D8 80240128 8E05000C */  lw        $a1, 0xc($s0)
/* BDA8DC 8024012C 0C00ECD0 */  jal       set_npc_yaw
/* BDA8E0 80240130 0040202D */   daddu    $a0, $v0, $zero
/* BDA8E4 80240134 0200202D */  daddu     $a0, $s0, $zero
/* BDA8E8 80240138 8E020000 */  lw        $v0, ($s0)
/* BDA8EC 8024013C 2403FFFB */  addiu     $v1, $zero, -5
/* BDA8F0 80240140 00431024 */  and       $v0, $v0, $v1
/* BDA8F4 80240144 0C00EAFF */  jal       disable_npc_shadow
/* BDA8F8 80240148 AE020000 */   sw       $v0, ($s0)
/* BDA8FC 8024014C 3C01C47A */  lui       $at, 0xc47a
/* BDA900 80240150 44810000 */  mtc1      $at, $f0
/* BDA904 80240154 24020002 */  addiu     $v0, $zero, 2
/* BDA908 80240158 08090059 */  j         .L80240164
/* BDA90C 8024015C E600003C */   swc1     $f0, 0x3c($s0)
.L80240160:
/* BDA910 80240160 0000102D */  daddu     $v0, $zero, $zero
.L80240164:
/* BDA914 80240164 8FBF0024 */  lw        $ra, 0x24($sp)
/* BDA918 80240168 8FB40020 */  lw        $s4, 0x20($sp)
/* BDA91C 8024016C 8FB3001C */  lw        $s3, 0x1c($sp)
/* BDA920 80240170 8FB20018 */  lw        $s2, 0x18($sp)
/* BDA924 80240174 8FB10014 */  lw        $s1, 0x14($sp)
/* BDA928 80240178 8FB00010 */  lw        $s0, 0x10($sp)
/* BDA92C 8024017C 03E00008 */  jr        $ra
/* BDA930 80240180 27BD0028 */   addiu    $sp, $sp, 0x28
/* BDA934 80240184 00000000 */  nop
/* BDA938 80240188 00000000 */  nop
/* BDA93C 8024018C 00000000 */  nop
