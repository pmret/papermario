.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_EDEA00
/* EDEA00 80240040 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EDEA04 80240044 AFB20018 */  sw        $s2, 0x18($sp)
/* EDEA08 80240048 0080902D */  daddu     $s2, $a0, $zero
/* EDEA0C 8024004C AFB10014 */  sw        $s1, 0x14($sp)
/* EDEA10 80240050 00A0882D */  daddu     $s1, $a1, $zero
/* EDEA14 80240054 AFBF0024 */  sw        $ra, 0x24($sp)
/* EDEA18 80240058 AFB40020 */  sw        $s4, 0x20($sp)
/* EDEA1C 8024005C AFB3001C */  sw        $s3, 0x1c($sp)
/* EDEA20 80240060 AFB00010 */  sw        $s0, 0x10($sp)
/* EDEA24 80240064 8E50000C */  lw        $s0, 0xc($s2)
/* EDEA28 80240068 8E050000 */  lw        $a1, ($s0)
/* EDEA2C 8024006C 0C0B53A3 */  jal       dead_get_variable
/* EDEA30 80240070 26100004 */   addiu    $s0, $s0, 4
/* EDEA34 80240074 0240202D */  daddu     $a0, $s2, $zero
/* EDEA38 80240078 8E050000 */  lw        $a1, ($s0)
/* EDEA3C 8024007C 0C0B53A3 */  jal       dead_get_variable
/* EDEA40 80240080 0040802D */   daddu    $s0, $v0, $zero
/* EDEA44 80240084 0200202D */  daddu     $a0, $s0, $zero
/* EDEA48 80240088 0C00F94D */  jal       func_8003E534
/* EDEA4C 8024008C 0040A02D */   daddu    $s4, $v0, $zero
/* EDEA50 80240090 3C138011 */  lui       $s3, %hi(D_80117840)
/* EDEA54 80240094 26737840 */  addiu     $s3, $s3, %lo(D_80117840)
/* EDEA58 80240098 12200006 */  beqz      $s1, .L802400B4
/* EDEA5C 8024009C 0040802D */   daddu    $s0, $v0, $zero
/* EDEA60 802400A0 82620012 */  lb        $v0, 0x12($s3)
/* EDEA64 802400A4 54400003 */  bnel      $v0, $zero, .L802400B4
/* EDEA68 802400A8 AE400070 */   sw       $zero, 0x70($s2)
/* EDEA6C 802400AC 24020002 */  addiu     $v0, $zero, 2
/* EDEA70 802400B0 AE420070 */  sw        $v0, 0x70($s2)
.L802400B4:
/* EDEA74 802400B4 8E430070 */  lw        $v1, 0x70($s2)
/* EDEA78 802400B8 24110001 */  addiu     $s1, $zero, 1
/* EDEA7C 802400BC 10710013 */  beq       $v1, $s1, .L8024010C
/* EDEA80 802400C0 28620002 */   slti     $v0, $v1, 2
/* EDEA84 802400C4 10400005 */  beqz      $v0, .L802400DC
/* EDEA88 802400C8 24020002 */   addiu    $v0, $zero, 2
/* EDEA8C 802400CC 10600009 */  beqz      $v1, .L802400F4
/* EDEA90 802400D0 0000102D */   daddu    $v0, $zero, $zero
/* EDEA94 802400D4 08090069 */  j         .L802401A4
/* EDEA98 802400D8 00000000 */   nop
.L802400DC:
/* EDEA9C 802400DC 10620013 */  beq       $v1, $v0, .L8024012C
/* EDEAA0 802400E0 24020003 */   addiu    $v0, $zero, 3
/* EDEAA4 802400E4 1062001E */  beq       $v1, $v0, .L80240160
/* EDEAA8 802400E8 0000102D */   daddu    $v0, $zero, $zero
/* EDEAAC 802400EC 08090069 */  j         .L802401A4
/* EDEAB0 802400F0 00000000 */   nop
.L802400F4:
/* EDEAB4 802400F4 0C03CB57 */  jal       func_800F2D5C
/* EDEAB8 802400F8 0000202D */   daddu    $a0, $zero, $zero
/* EDEABC 802400FC 2402001E */  addiu     $v0, $zero, 0x1e
/* EDEAC0 80240100 AE420074 */  sw        $v0, 0x74($s2)
/* EDEAC4 80240104 08090068 */  j         .L802401A0
/* EDEAC8 80240108 AE510070 */   sw       $s1, 0x70($s2)
.L8024010C:
/* EDEACC 8024010C 8E420074 */  lw        $v0, 0x74($s2)
/* EDEAD0 80240110 2403FFFF */  addiu     $v1, $zero, -1
/* EDEAD4 80240114 2442FFFF */  addiu     $v0, $v0, -1
/* EDEAD8 80240118 14430021 */  bne       $v0, $v1, .L802401A0
/* EDEADC 8024011C AE420074 */   sw       $v0, 0x74($s2)
/* EDEAE0 80240120 24020002 */  addiu     $v0, $zero, 2
/* EDEAE4 80240124 08090068 */  j         .L802401A0
/* EDEAE8 80240128 AE420070 */   sw       $v0, 0x70($s2)
.L8024012C:
/* EDEAEC 8024012C 0200202D */  daddu     $a0, $s0, $zero
/* EDEAF0 80240130 00141600 */  sll       $v0, $s4, 0x18
/* EDEAF4 80240134 00021543 */  sra       $v0, $v0, 0x15
/* EDEAF8 80240138 02621021 */  addu      $v0, $s3, $v0
/* EDEAFC 8024013C A2740012 */  sb        $s4, 0x12($s3)
/* EDEB00 80240140 0C03DC9E */  jal       func_800F7278
/* EDEB04 80240144 A0510014 */   sb       $s1, 0x14($v0)
/* EDEB08 80240148 82640012 */  lb        $a0, 0x12($s3)
/* EDEB0C 8024014C 0C03CBA6 */  jal       func_800F2E98
/* EDEB10 80240150 00000000 */   nop
/* EDEB14 80240154 24020003 */  addiu     $v0, $zero, 3
/* EDEB18 80240158 08090068 */  j         .L802401A0
/* EDEB1C 8024015C AE420070 */   sw       $v0, 0x70($s2)
.L80240160:
/* EDEB20 80240160 0C00F94D */  jal       func_8003E534
/* EDEB24 80240164 2404FFFC */   addiu    $a0, $zero, -4
/* EDEB28 80240168 8E05000C */  lw        $a1, 0xc($s0)
/* EDEB2C 8024016C 0C00FB54 */  jal       func_8003ED50
/* EDEB30 80240170 0040202D */   daddu    $a0, $v0, $zero
/* EDEB34 80240174 0200202D */  daddu     $a0, $s0, $zero
/* EDEB38 80240178 8E020000 */  lw        $v0, ($s0)
/* EDEB3C 8024017C 2403FFFB */  addiu     $v1, $zero, -5
/* EDEB40 80240180 00431024 */  and       $v0, $v0, $v1
/* EDEB44 80240184 0C00F97A */  jal       func_8003E5E8
/* EDEB48 80240188 AE020000 */   sw       $v0, ($s0)
/* EDEB4C 8024018C 3C01C47A */  lui       $at, 0xc47a
/* EDEB50 80240190 44810000 */  mtc1      $at, $f0
/* EDEB54 80240194 24020002 */  addiu     $v0, $zero, 2
/* EDEB58 80240198 08090069 */  j         .L802401A4
/* EDEB5C 8024019C E600003C */   swc1     $f0, 0x3c($s0)
.L802401A0:
/* EDEB60 802401A0 0000102D */  daddu     $v0, $zero, $zero
.L802401A4:
/* EDEB64 802401A4 8FBF0024 */  lw        $ra, 0x24($sp)
/* EDEB68 802401A8 8FB40020 */  lw        $s4, 0x20($sp)
/* EDEB6C 802401AC 8FB3001C */  lw        $s3, 0x1c($sp)
/* EDEB70 802401B0 8FB20018 */  lw        $s2, 0x18($sp)
/* EDEB74 802401B4 8FB10014 */  lw        $s1, 0x14($sp)
/* EDEB78 802401B8 8FB00010 */  lw        $s0, 0x10($sp)
/* EDEB7C 802401BC 03E00008 */  jr        $ra
/* EDEB80 802401C0 27BD0028 */   addiu    $sp, $sp, 0x28
