.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8C7F90
/* 8C7F90 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8C7F94 80240004 AFB20018 */  sw        $s2, 0x18($sp)
/* 8C7F98 80240008 0080902D */  daddu     $s2, $a0, $zero
/* 8C7F9C 8024000C AFB10014 */  sw        $s1, 0x14($sp)
/* 8C7FA0 80240010 00A0882D */  daddu     $s1, $a1, $zero
/* 8C7FA4 80240014 AFBF0024 */  sw        $ra, 0x24($sp)
/* 8C7FA8 80240018 AFB40020 */  sw        $s4, 0x20($sp)
/* 8C7FAC 8024001C AFB3001C */  sw        $s3, 0x1c($sp)
/* 8C7FB0 80240020 AFB00010 */  sw        $s0, 0x10($sp)
/* 8C7FB4 80240024 8E50000C */  lw        $s0, 0xc($s2)
/* 8C7FB8 80240028 8E050000 */  lw        $a1, ($s0)
/* 8C7FBC 8024002C 0C0B1EAF */  jal       get_variable
/* 8C7FC0 80240030 26100004 */   addiu    $s0, $s0, 4
/* 8C7FC4 80240034 0240202D */  daddu     $a0, $s2, $zero
/* 8C7FC8 80240038 8E050000 */  lw        $a1, ($s0)
/* 8C7FCC 8024003C 0C0B1EAF */  jal       get_variable
/* 8C7FD0 80240040 0040802D */   daddu    $s0, $v0, $zero
/* 8C7FD4 80240044 0200202D */  daddu     $a0, $s0, $zero
/* 8C7FD8 80240048 0C00EAD2 */  jal       get_npc_safe
/* 8C7FDC 8024004C 0040A02D */   daddu    $s4, $v0, $zero
/* 8C7FE0 80240050 3C138011 */  lui       $s3, %hi(gPlayerData)
/* 8C7FE4 80240054 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* 8C7FE8 80240058 12200006 */  beqz      $s1, .L80240074
/* 8C7FEC 8024005C 0040802D */   daddu    $s0, $v0, $zero
/* 8C7FF0 80240060 82620012 */  lb        $v0, 0x12($s3)
/* 8C7FF4 80240064 54400003 */  bnel      $v0, $zero, .L80240074
/* 8C7FF8 80240068 AE400070 */   sw       $zero, 0x70($s2)
/* 8C7FFC 8024006C 24020002 */  addiu     $v0, $zero, 2
/* 8C8000 80240070 AE420070 */  sw        $v0, 0x70($s2)
.L80240074:
/* 8C8004 80240074 8E430070 */  lw        $v1, 0x70($s2)
/* 8C8008 80240078 24110001 */  addiu     $s1, $zero, 1
/* 8C800C 8024007C 10710013 */  beq       $v1, $s1, .L802400CC
/* 8C8010 80240080 28620002 */   slti     $v0, $v1, 2
/* 8C8014 80240084 10400005 */  beqz      $v0, .L8024009C
/* 8C8018 80240088 24020002 */   addiu    $v0, $zero, 2
/* 8C801C 8024008C 10600009 */  beqz      $v1, .L802400B4
/* 8C8020 80240090 0000102D */   daddu    $v0, $zero, $zero
/* 8C8024 80240094 08090059 */  j         .L80240164
/* 8C8028 80240098 00000000 */   nop      
.L8024009C:
/* 8C802C 8024009C 10620013 */  beq       $v1, $v0, .L802400EC
/* 8C8030 802400A0 24020003 */   addiu    $v0, $zero, 3
/* 8C8034 802400A4 1062001E */  beq       $v1, $v0, .L80240120
/* 8C8038 802400A8 0000102D */   daddu    $v0, $zero, $zero
/* 8C803C 802400AC 08090059 */  j         .L80240164
/* 8C8040 802400B0 00000000 */   nop      
.L802400B4:
/* 8C8044 802400B4 0C03AC5A */  jal       func_800EB168
/* 8C8048 802400B8 0000202D */   daddu    $a0, $zero, $zero
/* 8C804C 802400BC 2402001E */  addiu     $v0, $zero, 0x1e
/* 8C8050 802400C0 AE420074 */  sw        $v0, 0x74($s2)
/* 8C8054 802400C4 08090058 */  j         .L80240160
/* 8C8058 802400C8 AE510070 */   sw       $s1, 0x70($s2)
.L802400CC:
/* 8C805C 802400CC 8E420074 */  lw        $v0, 0x74($s2)
/* 8C8060 802400D0 2403FFFF */  addiu     $v1, $zero, -1
/* 8C8064 802400D4 2442FFFF */  addiu     $v0, $v0, -1
/* 8C8068 802400D8 14430021 */  bne       $v0, $v1, .L80240160
/* 8C806C 802400DC AE420074 */   sw       $v0, 0x74($s2)
/* 8C8070 802400E0 24020002 */  addiu     $v0, $zero, 2
/* 8C8074 802400E4 08090058 */  j         .L80240160
/* 8C8078 802400E8 AE420070 */   sw       $v0, 0x70($s2)
.L802400EC:
/* 8C807C 802400EC 0200202D */  daddu     $a0, $s0, $zero
/* 8C8080 802400F0 00141600 */  sll       $v0, $s4, 0x18
/* 8C8084 802400F4 00021543 */  sra       $v0, $v0, 0x15
/* 8C8088 802400F8 02621021 */  addu      $v0, $s3, $v0
/* 8C808C 802400FC A2740012 */  sb        $s4, 0x12($s3)
/* 8C8090 80240100 0C03BD17 */  jal       clear_partner_move_history
/* 8C8094 80240104 A0510014 */   sb       $s1, 0x14($v0)
/* 8C8098 80240108 82640012 */  lb        $a0, 0x12($s3)
/* 8C809C 8024010C 0C03ACA9 */  jal       func_800EB2A4
/* 8C80A0 80240110 00000000 */   nop      
/* 8C80A4 80240114 24020003 */  addiu     $v0, $zero, 3
/* 8C80A8 80240118 08090058 */  j         .L80240160
/* 8C80AC 8024011C AE420070 */   sw       $v0, 0x70($s2)
.L80240120:
/* 8C80B0 80240120 0C00EAD2 */  jal       get_npc_safe
/* 8C80B4 80240124 2404FFFC */   addiu    $a0, $zero, -4
/* 8C80B8 80240128 8E05000C */  lw        $a1, 0xc($s0)
/* 8C80BC 8024012C 0C00ECD0 */  jal       set_npc_yaw
/* 8C80C0 80240130 0040202D */   daddu    $a0, $v0, $zero
/* 8C80C4 80240134 0200202D */  daddu     $a0, $s0, $zero
/* 8C80C8 80240138 8E020000 */  lw        $v0, ($s0)
/* 8C80CC 8024013C 2403FFFB */  addiu     $v1, $zero, -5
/* 8C80D0 80240140 00431024 */  and       $v0, $v0, $v1
/* 8C80D4 80240144 0C00EAFF */  jal       disable_npc_shadow
/* 8C80D8 80240148 AE020000 */   sw       $v0, ($s0)
/* 8C80DC 8024014C 3C01C47A */  lui       $at, 0xc47a
/* 8C80E0 80240150 44810000 */  mtc1      $at, $f0
/* 8C80E4 80240154 24020002 */  addiu     $v0, $zero, 2
/* 8C80E8 80240158 08090059 */  j         .L80240164
/* 8C80EC 8024015C E600003C */   swc1     $f0, 0x3c($s0)
.L80240160:
/* 8C80F0 80240160 0000102D */  daddu     $v0, $zero, $zero
.L80240164:
/* 8C80F4 80240164 8FBF0024 */  lw        $ra, 0x24($sp)
/* 8C80F8 80240168 8FB40020 */  lw        $s4, 0x20($sp)
/* 8C80FC 8024016C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8C8100 80240170 8FB20018 */  lw        $s2, 0x18($sp)
/* 8C8104 80240174 8FB10014 */  lw        $s1, 0x14($sp)
/* 8C8108 80240178 8FB00010 */  lw        $s0, 0x10($sp)
/* 8C810C 8024017C 03E00008 */  jr        $ra
/* 8C8110 80240180 27BD0028 */   addiu    $sp, $sp, 0x28
