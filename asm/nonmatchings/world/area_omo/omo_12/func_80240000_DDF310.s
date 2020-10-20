.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DDF310
/* DDF310 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DDF314 80240004 AFB20018 */  sw        $s2, 0x18($sp)
/* DDF318 80240008 0080902D */  daddu     $s2, $a0, $zero
/* DDF31C 8024000C AFB10014 */  sw        $s1, 0x14($sp)
/* DDF320 80240010 00A0882D */  daddu     $s1, $a1, $zero
/* DDF324 80240014 AFBF0024 */  sw        $ra, 0x24($sp)
/* DDF328 80240018 AFB40020 */  sw        $s4, 0x20($sp)
/* DDF32C 8024001C AFB3001C */  sw        $s3, 0x1c($sp)
/* DDF330 80240020 AFB00010 */  sw        $s0, 0x10($sp)
/* DDF334 80240024 8E50000C */  lw        $s0, 0xc($s2)
/* DDF338 80240028 8E050000 */  lw        $a1, ($s0)
/* DDF33C 8024002C 0C0B1EAF */  jal       get_variable
/* DDF340 80240030 26100004 */   addiu    $s0, $s0, 4
/* DDF344 80240034 0240202D */  daddu     $a0, $s2, $zero
/* DDF348 80240038 8E050000 */  lw        $a1, ($s0)
/* DDF34C 8024003C 0C0B1EAF */  jal       get_variable
/* DDF350 80240040 0040802D */   daddu    $s0, $v0, $zero
/* DDF354 80240044 0200202D */  daddu     $a0, $s0, $zero
/* DDF358 80240048 0C00EAD2 */  jal       get_npc_safe
/* DDF35C 8024004C 0040A02D */   daddu    $s4, $v0, $zero
/* DDF360 80240050 3C138011 */  lui       $s3, %hi(gPlayerData)
/* DDF364 80240054 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* DDF368 80240058 12200006 */  beqz      $s1, .L80240074
/* DDF36C 8024005C 0040802D */   daddu    $s0, $v0, $zero
/* DDF370 80240060 82620012 */  lb        $v0, 0x12($s3)
/* DDF374 80240064 54400003 */  bnel      $v0, $zero, .L80240074
/* DDF378 80240068 AE400070 */   sw       $zero, 0x70($s2)
/* DDF37C 8024006C 24020002 */  addiu     $v0, $zero, 2
/* DDF380 80240070 AE420070 */  sw        $v0, 0x70($s2)
.L80240074:
/* DDF384 80240074 8E430070 */  lw        $v1, 0x70($s2)
/* DDF388 80240078 24110001 */  addiu     $s1, $zero, 1
/* DDF38C 8024007C 10710013 */  beq       $v1, $s1, .L802400CC
/* DDF390 80240080 28620002 */   slti     $v0, $v1, 2
/* DDF394 80240084 10400005 */  beqz      $v0, .L8024009C
/* DDF398 80240088 24020002 */   addiu    $v0, $zero, 2
/* DDF39C 8024008C 10600009 */  beqz      $v1, .L802400B4
/* DDF3A0 80240090 0000102D */   daddu    $v0, $zero, $zero
/* DDF3A4 80240094 08090059 */  j         .L80240164
/* DDF3A8 80240098 00000000 */   nop      
.L8024009C:
/* DDF3AC 8024009C 10620013 */  beq       $v1, $v0, .L802400EC
/* DDF3B0 802400A0 24020003 */   addiu    $v0, $zero, 3
/* DDF3B4 802400A4 1062001E */  beq       $v1, $v0, .L80240120
/* DDF3B8 802400A8 0000102D */   daddu    $v0, $zero, $zero
/* DDF3BC 802400AC 08090059 */  j         .L80240164
/* DDF3C0 802400B0 00000000 */   nop      
.L802400B4:
/* DDF3C4 802400B4 0C03AC5A */  jal       func_800EB168
/* DDF3C8 802400B8 0000202D */   daddu    $a0, $zero, $zero
/* DDF3CC 802400BC 2402001E */  addiu     $v0, $zero, 0x1e
/* DDF3D0 802400C0 AE420074 */  sw        $v0, 0x74($s2)
/* DDF3D4 802400C4 08090058 */  j         .L80240160
/* DDF3D8 802400C8 AE510070 */   sw       $s1, 0x70($s2)
.L802400CC:
/* DDF3DC 802400CC 8E420074 */  lw        $v0, 0x74($s2)
/* DDF3E0 802400D0 2403FFFF */  addiu     $v1, $zero, -1
/* DDF3E4 802400D4 2442FFFF */  addiu     $v0, $v0, -1
/* DDF3E8 802400D8 14430021 */  bne       $v0, $v1, .L80240160
/* DDF3EC 802400DC AE420074 */   sw       $v0, 0x74($s2)
/* DDF3F0 802400E0 24020002 */  addiu     $v0, $zero, 2
/* DDF3F4 802400E4 08090058 */  j         .L80240160
/* DDF3F8 802400E8 AE420070 */   sw       $v0, 0x70($s2)
.L802400EC:
/* DDF3FC 802400EC 0200202D */  daddu     $a0, $s0, $zero
/* DDF400 802400F0 00141600 */  sll       $v0, $s4, 0x18
/* DDF404 802400F4 00021543 */  sra       $v0, $v0, 0x15
/* DDF408 802400F8 02621021 */  addu      $v0, $s3, $v0
/* DDF40C 802400FC A2740012 */  sb        $s4, 0x12($s3)
/* DDF410 80240100 0C03BD17 */  jal       clear_partner_move_history
/* DDF414 80240104 A0510014 */   sb       $s1, 0x14($v0)
/* DDF418 80240108 82640012 */  lb        $a0, 0x12($s3)
/* DDF41C 8024010C 0C03ACA9 */  jal       func_800EB2A4
/* DDF420 80240110 00000000 */   nop      
/* DDF424 80240114 24020003 */  addiu     $v0, $zero, 3
/* DDF428 80240118 08090058 */  j         .L80240160
/* DDF42C 8024011C AE420070 */   sw       $v0, 0x70($s2)
.L80240120:
/* DDF430 80240120 0C00EAD2 */  jal       get_npc_safe
/* DDF434 80240124 2404FFFC */   addiu    $a0, $zero, -4
/* DDF438 80240128 8E05000C */  lw        $a1, 0xc($s0)
/* DDF43C 8024012C 0C00ECD0 */  jal       set_npc_yaw
/* DDF440 80240130 0040202D */   daddu    $a0, $v0, $zero
/* DDF444 80240134 0200202D */  daddu     $a0, $s0, $zero
/* DDF448 80240138 8E020000 */  lw        $v0, ($s0)
/* DDF44C 8024013C 2403FFFB */  addiu     $v1, $zero, -5
/* DDF450 80240140 00431024 */  and       $v0, $v0, $v1
/* DDF454 80240144 0C00EAFF */  jal       disable_npc_shadow
/* DDF458 80240148 AE020000 */   sw       $v0, ($s0)
/* DDF45C 8024014C 3C01C47A */  lui       $at, 0xc47a
/* DDF460 80240150 44810000 */  mtc1      $at, $f0
/* DDF464 80240154 24020002 */  addiu     $v0, $zero, 2
/* DDF468 80240158 08090059 */  j         .L80240164
/* DDF46C 8024015C E600003C */   swc1     $f0, 0x3c($s0)
.L80240160:
/* DDF470 80240160 0000102D */  daddu     $v0, $zero, $zero
.L80240164:
/* DDF474 80240164 8FBF0024 */  lw        $ra, 0x24($sp)
/* DDF478 80240168 8FB40020 */  lw        $s4, 0x20($sp)
/* DDF47C 8024016C 8FB3001C */  lw        $s3, 0x1c($sp)
/* DDF480 80240170 8FB20018 */  lw        $s2, 0x18($sp)
/* DDF484 80240174 8FB10014 */  lw        $s1, 0x14($sp)
/* DDF488 80240178 8FB00010 */  lw        $s0, 0x10($sp)
/* DDF48C 8024017C 03E00008 */  jr        $ra
/* DDF490 80240180 27BD0028 */   addiu    $sp, $sp, 0x28
