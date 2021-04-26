.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_13_UnkFunc41
/* CC3850 80240040 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CC3854 80240044 AFB20018 */  sw        $s2, 0x18($sp)
/* CC3858 80240048 0080902D */  daddu     $s2, $a0, $zero
/* CC385C 8024004C AFB10014 */  sw        $s1, 0x14($sp)
/* CC3860 80240050 00A0882D */  daddu     $s1, $a1, $zero
/* CC3864 80240054 AFBF0024 */  sw        $ra, 0x24($sp)
/* CC3868 80240058 AFB40020 */  sw        $s4, 0x20($sp)
/* CC386C 8024005C AFB3001C */  sw        $s3, 0x1c($sp)
/* CC3870 80240060 AFB00010 */  sw        $s0, 0x10($sp)
/* CC3874 80240064 8E50000C */  lw        $s0, 0xc($s2)
/* CC3878 80240068 8E050000 */  lw        $a1, ($s0)
/* CC387C 8024006C 0C0B1EAF */  jal       get_variable
/* CC3880 80240070 26100004 */   addiu    $s0, $s0, 4
/* CC3884 80240074 0240202D */  daddu     $a0, $s2, $zero
/* CC3888 80240078 8E050000 */  lw        $a1, ($s0)
/* CC388C 8024007C 0C0B1EAF */  jal       get_variable
/* CC3890 80240080 0040802D */   daddu    $s0, $v0, $zero
/* CC3894 80240084 0200202D */  daddu     $a0, $s0, $zero
/* CC3898 80240088 0C00EAD2 */  jal       get_npc_safe
/* CC389C 8024008C 0040A02D */   daddu    $s4, $v0, $zero
/* CC38A0 80240090 3C138011 */  lui       $s3, %hi(gPlayerData)
/* CC38A4 80240094 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* CC38A8 80240098 12200006 */  beqz      $s1, .L802400B4
/* CC38AC 8024009C 0040802D */   daddu    $s0, $v0, $zero
/* CC38B0 802400A0 82620012 */  lb        $v0, 0x12($s3)
/* CC38B4 802400A4 54400003 */  bnel      $v0, $zero, .L802400B4
/* CC38B8 802400A8 AE400070 */   sw       $zero, 0x70($s2)
/* CC38BC 802400AC 24020002 */  addiu     $v0, $zero, 2
/* CC38C0 802400B0 AE420070 */  sw        $v0, 0x70($s2)
.L802400B4:
/* CC38C4 802400B4 8E430070 */  lw        $v1, 0x70($s2)
/* CC38C8 802400B8 24110001 */  addiu     $s1, $zero, 1
/* CC38CC 802400BC 10710013 */  beq       $v1, $s1, .L8024010C
/* CC38D0 802400C0 28620002 */   slti     $v0, $v1, 2
/* CC38D4 802400C4 10400005 */  beqz      $v0, .L802400DC
/* CC38D8 802400C8 24020002 */   addiu    $v0, $zero, 2
/* CC38DC 802400CC 10600009 */  beqz      $v1, .L802400F4
/* CC38E0 802400D0 0000102D */   daddu    $v0, $zero, $zero
/* CC38E4 802400D4 08090069 */  j         .L802401A4
/* CC38E8 802400D8 00000000 */   nop
.L802400DC:
/* CC38EC 802400DC 10620013 */  beq       $v1, $v0, .L8024012C
/* CC38F0 802400E0 24020003 */   addiu    $v0, $zero, 3
/* CC38F4 802400E4 1062001E */  beq       $v1, $v0, .L80240160
/* CC38F8 802400E8 0000102D */   daddu    $v0, $zero, $zero
/* CC38FC 802400EC 08090069 */  j         .L802401A4
/* CC3900 802400F0 00000000 */   nop
.L802400F4:
/* CC3904 802400F4 0C03AC5A */  jal       func_800EB168
/* CC3908 802400F8 0000202D */   daddu    $a0, $zero, $zero
/* CC390C 802400FC 2402001E */  addiu     $v0, $zero, 0x1e
/* CC3910 80240100 AE420074 */  sw        $v0, 0x74($s2)
/* CC3914 80240104 08090068 */  j         .L802401A0
/* CC3918 80240108 AE510070 */   sw       $s1, 0x70($s2)
.L8024010C:
/* CC391C 8024010C 8E420074 */  lw        $v0, 0x74($s2)
/* CC3920 80240110 2403FFFF */  addiu     $v1, $zero, -1
/* CC3924 80240114 2442FFFF */  addiu     $v0, $v0, -1
/* CC3928 80240118 14430021 */  bne       $v0, $v1, .L802401A0
/* CC392C 8024011C AE420074 */   sw       $v0, 0x74($s2)
/* CC3930 80240120 24020002 */  addiu     $v0, $zero, 2
/* CC3934 80240124 08090068 */  j         .L802401A0
/* CC3938 80240128 AE420070 */   sw       $v0, 0x70($s2)
.L8024012C:
/* CC393C 8024012C 0200202D */  daddu     $a0, $s0, $zero
/* CC3940 80240130 00141600 */  sll       $v0, $s4, 0x18
/* CC3944 80240134 00021543 */  sra       $v0, $v0, 0x15
/* CC3948 80240138 02621021 */  addu      $v0, $s3, $v0
/* CC394C 8024013C A2740012 */  sb        $s4, 0x12($s3)
/* CC3950 80240140 0C03BD17 */  jal       clear_partner_move_history
/* CC3954 80240144 A0510014 */   sb       $s1, 0x14($v0)
/* CC3958 80240148 82640012 */  lb        $a0, 0x12($s3)
/* CC395C 8024014C 0C03ACA9 */  jal       func_800EB2A4
/* CC3960 80240150 00000000 */   nop
/* CC3964 80240154 24020003 */  addiu     $v0, $zero, 3
/* CC3968 80240158 08090068 */  j         .L802401A0
/* CC396C 8024015C AE420070 */   sw       $v0, 0x70($s2)
.L80240160:
/* CC3970 80240160 0C00EAD2 */  jal       get_npc_safe
/* CC3974 80240164 2404FFFC */   addiu    $a0, $zero, -4
/* CC3978 80240168 8E05000C */  lw        $a1, 0xc($s0)
/* CC397C 8024016C 0C00ECD0 */  jal       set_npc_yaw
/* CC3980 80240170 0040202D */   daddu    $a0, $v0, $zero
/* CC3984 80240174 0200202D */  daddu     $a0, $s0, $zero
/* CC3988 80240178 8E020000 */  lw        $v0, ($s0)
/* CC398C 8024017C 2403FFFB */  addiu     $v1, $zero, -5
/* CC3990 80240180 00431024 */  and       $v0, $v0, $v1
/* CC3994 80240184 0C00EAFF */  jal       disable_npc_shadow
/* CC3998 80240188 AE020000 */   sw       $v0, ($s0)
/* CC399C 8024018C 3C01C47A */  lui       $at, 0xc47a
/* CC39A0 80240190 44810000 */  mtc1      $at, $f0
/* CC39A4 80240194 24020002 */  addiu     $v0, $zero, 2
/* CC39A8 80240198 08090069 */  j         .L802401A4
/* CC39AC 8024019C E600003C */   swc1     $f0, 0x3c($s0)
.L802401A0:
/* CC39B0 802401A0 0000102D */  daddu     $v0, $zero, $zero
.L802401A4:
/* CC39B4 802401A4 8FBF0024 */  lw        $ra, 0x24($sp)
/* CC39B8 802401A8 8FB40020 */  lw        $s4, 0x20($sp)
/* CC39BC 802401AC 8FB3001C */  lw        $s3, 0x1c($sp)
/* CC39C0 802401B0 8FB20018 */  lw        $s2, 0x18($sp)
/* CC39C4 802401B4 8FB10014 */  lw        $s1, 0x14($sp)
/* CC39C8 802401B8 8FB00010 */  lw        $s0, 0x10($sp)
/* CC39CC 802401BC 03E00008 */  jr        $ra
/* CC39D0 802401C0 27BD0028 */   addiu    $sp, $sp, 0x28
