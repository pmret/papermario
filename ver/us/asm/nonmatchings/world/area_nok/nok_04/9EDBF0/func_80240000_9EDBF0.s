.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_04_UnkFunc41
/* 9EDBF0 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9EDBF4 80240004 AFB20018 */  sw        $s2, 0x18($sp)
/* 9EDBF8 80240008 0080902D */  daddu     $s2, $a0, $zero
/* 9EDBFC 8024000C AFB10014 */  sw        $s1, 0x14($sp)
/* 9EDC00 80240010 00A0882D */  daddu     $s1, $a1, $zero
/* 9EDC04 80240014 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9EDC08 80240018 AFB40020 */  sw        $s4, 0x20($sp)
/* 9EDC0C 8024001C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9EDC10 80240020 AFB00010 */  sw        $s0, 0x10($sp)
/* 9EDC14 80240024 8E50000C */  lw        $s0, 0xc($s2)
/* 9EDC18 80240028 8E050000 */  lw        $a1, ($s0)
/* 9EDC1C 8024002C 0C0B1EAF */  jal       get_variable
/* 9EDC20 80240030 26100004 */   addiu    $s0, $s0, 4
/* 9EDC24 80240034 0240202D */  daddu     $a0, $s2, $zero
/* 9EDC28 80240038 8E050000 */  lw        $a1, ($s0)
/* 9EDC2C 8024003C 0C0B1EAF */  jal       get_variable
/* 9EDC30 80240040 0040802D */   daddu    $s0, $v0, $zero
/* 9EDC34 80240044 0200202D */  daddu     $a0, $s0, $zero
/* 9EDC38 80240048 0C00EAD2 */  jal       get_npc_safe
/* 9EDC3C 8024004C 0040A02D */   daddu    $s4, $v0, $zero
/* 9EDC40 80240050 3C138011 */  lui       $s3, %hi(gPlayerData)
/* 9EDC44 80240054 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* 9EDC48 80240058 12200006 */  beqz      $s1, .L80240074
/* 9EDC4C 8024005C 0040802D */   daddu    $s0, $v0, $zero
/* 9EDC50 80240060 82620012 */  lb        $v0, 0x12($s3)
/* 9EDC54 80240064 54400003 */  bnel      $v0, $zero, .L80240074
/* 9EDC58 80240068 AE400070 */   sw       $zero, 0x70($s2)
/* 9EDC5C 8024006C 24020002 */  addiu     $v0, $zero, 2
/* 9EDC60 80240070 AE420070 */  sw        $v0, 0x70($s2)
.L80240074:
/* 9EDC64 80240074 8E430070 */  lw        $v1, 0x70($s2)
/* 9EDC68 80240078 24110001 */  addiu     $s1, $zero, 1
/* 9EDC6C 8024007C 10710013 */  beq       $v1, $s1, .L802400CC
/* 9EDC70 80240080 28620002 */   slti     $v0, $v1, 2
/* 9EDC74 80240084 10400005 */  beqz      $v0, .L8024009C
/* 9EDC78 80240088 24020002 */   addiu    $v0, $zero, 2
/* 9EDC7C 8024008C 10600009 */  beqz      $v1, .L802400B4
/* 9EDC80 80240090 0000102D */   daddu    $v0, $zero, $zero
/* 9EDC84 80240094 08090059 */  j         .L80240164
/* 9EDC88 80240098 00000000 */   nop
.L8024009C:
/* 9EDC8C 8024009C 10620013 */  beq       $v1, $v0, .L802400EC
/* 9EDC90 802400A0 24020003 */   addiu    $v0, $zero, 3
/* 9EDC94 802400A4 1062001E */  beq       $v1, $v0, .L80240120
/* 9EDC98 802400A8 0000102D */   daddu    $v0, $zero, $zero
/* 9EDC9C 802400AC 08090059 */  j         .L80240164
/* 9EDCA0 802400B0 00000000 */   nop
.L802400B4:
/* 9EDCA4 802400B4 0C03AC5A */  jal       func_800EB168
/* 9EDCA8 802400B8 0000202D */   daddu    $a0, $zero, $zero
/* 9EDCAC 802400BC 2402001E */  addiu     $v0, $zero, 0x1e
/* 9EDCB0 802400C0 AE420074 */  sw        $v0, 0x74($s2)
/* 9EDCB4 802400C4 08090058 */  j         .L80240160
/* 9EDCB8 802400C8 AE510070 */   sw       $s1, 0x70($s2)
.L802400CC:
/* 9EDCBC 802400CC 8E420074 */  lw        $v0, 0x74($s2)
/* 9EDCC0 802400D0 2403FFFF */  addiu     $v1, $zero, -1
/* 9EDCC4 802400D4 2442FFFF */  addiu     $v0, $v0, -1
/* 9EDCC8 802400D8 14430021 */  bne       $v0, $v1, .L80240160
/* 9EDCCC 802400DC AE420074 */   sw       $v0, 0x74($s2)
/* 9EDCD0 802400E0 24020002 */  addiu     $v0, $zero, 2
/* 9EDCD4 802400E4 08090058 */  j         .L80240160
/* 9EDCD8 802400E8 AE420070 */   sw       $v0, 0x70($s2)
.L802400EC:
/* 9EDCDC 802400EC 0200202D */  daddu     $a0, $s0, $zero
/* 9EDCE0 802400F0 00141600 */  sll       $v0, $s4, 0x18
/* 9EDCE4 802400F4 00021543 */  sra       $v0, $v0, 0x15
/* 9EDCE8 802400F8 02621021 */  addu      $v0, $s3, $v0
/* 9EDCEC 802400FC A2740012 */  sb        $s4, 0x12($s3)
/* 9EDCF0 80240100 0C03BD17 */  jal       clear_partner_move_history
/* 9EDCF4 80240104 A0510014 */   sb       $s1, 0x14($v0)
/* 9EDCF8 80240108 82640012 */  lb        $a0, 0x12($s3)
/* 9EDCFC 8024010C 0C03ACA9 */  jal       func_800EB2A4
/* 9EDD00 80240110 00000000 */   nop
/* 9EDD04 80240114 24020003 */  addiu     $v0, $zero, 3
/* 9EDD08 80240118 08090058 */  j         .L80240160
/* 9EDD0C 8024011C AE420070 */   sw       $v0, 0x70($s2)
.L80240120:
/* 9EDD10 80240120 0C00EAD2 */  jal       get_npc_safe
/* 9EDD14 80240124 2404FFFC */   addiu    $a0, $zero, -4
/* 9EDD18 80240128 8E05000C */  lw        $a1, 0xc($s0)
/* 9EDD1C 8024012C 0C00ECD0 */  jal       set_npc_yaw
/* 9EDD20 80240130 0040202D */   daddu    $a0, $v0, $zero
/* 9EDD24 80240134 0200202D */  daddu     $a0, $s0, $zero
/* 9EDD28 80240138 8E020000 */  lw        $v0, ($s0)
/* 9EDD2C 8024013C 2403FFFB */  addiu     $v1, $zero, -5
/* 9EDD30 80240140 00431024 */  and       $v0, $v0, $v1
/* 9EDD34 80240144 0C00EAFF */  jal       disable_npc_shadow
/* 9EDD38 80240148 AE020000 */   sw       $v0, ($s0)
/* 9EDD3C 8024014C 3C01C47A */  lui       $at, 0xc47a
/* 9EDD40 80240150 44810000 */  mtc1      $at, $f0
/* 9EDD44 80240154 24020002 */  addiu     $v0, $zero, 2
/* 9EDD48 80240158 08090059 */  j         .L80240164
/* 9EDD4C 8024015C E600003C */   swc1     $f0, 0x3c($s0)
.L80240160:
/* 9EDD50 80240160 0000102D */  daddu     $v0, $zero, $zero
.L80240164:
/* 9EDD54 80240164 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9EDD58 80240168 8FB40020 */  lw        $s4, 0x20($sp)
/* 9EDD5C 8024016C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9EDD60 80240170 8FB20018 */  lw        $s2, 0x18($sp)
/* 9EDD64 80240174 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EDD68 80240178 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EDD6C 8024017C 03E00008 */  jr        $ra
/* 9EDD70 80240180 27BD0028 */   addiu    $sp, $sp, 0x28
