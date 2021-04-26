.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_06_UnkFunc41
/* 9B2280 80240AF0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9B2284 80240AF4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9B2288 80240AF8 0080902D */  daddu     $s2, $a0, $zero
/* 9B228C 80240AFC AFB10014 */  sw        $s1, 0x14($sp)
/* 9B2290 80240B00 00A0882D */  daddu     $s1, $a1, $zero
/* 9B2294 80240B04 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9B2298 80240B08 AFB40020 */  sw        $s4, 0x20($sp)
/* 9B229C 80240B0C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9B22A0 80240B10 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B22A4 80240B14 8E50000C */  lw        $s0, 0xc($s2)
/* 9B22A8 80240B18 8E050000 */  lw        $a1, ($s0)
/* 9B22AC 80240B1C 0C0B1EAF */  jal       get_variable
/* 9B22B0 80240B20 26100004 */   addiu    $s0, $s0, 4
/* 9B22B4 80240B24 0240202D */  daddu     $a0, $s2, $zero
/* 9B22B8 80240B28 8E050000 */  lw        $a1, ($s0)
/* 9B22BC 80240B2C 0C0B1EAF */  jal       get_variable
/* 9B22C0 80240B30 0040802D */   daddu    $s0, $v0, $zero
/* 9B22C4 80240B34 0200202D */  daddu     $a0, $s0, $zero
/* 9B22C8 80240B38 0C00EAD2 */  jal       get_npc_safe
/* 9B22CC 80240B3C 0040A02D */   daddu    $s4, $v0, $zero
/* 9B22D0 80240B40 3C138011 */  lui       $s3, %hi(gPlayerData)
/* 9B22D4 80240B44 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* 9B22D8 80240B48 12200006 */  beqz      $s1, .L80240B64
/* 9B22DC 80240B4C 0040802D */   daddu    $s0, $v0, $zero
/* 9B22E0 80240B50 82620012 */  lb        $v0, 0x12($s3)
/* 9B22E4 80240B54 54400003 */  bnel      $v0, $zero, .L80240B64
/* 9B22E8 80240B58 AE400070 */   sw       $zero, 0x70($s2)
/* 9B22EC 80240B5C 24020002 */  addiu     $v0, $zero, 2
/* 9B22F0 80240B60 AE420070 */  sw        $v0, 0x70($s2)
.L80240B64:
/* 9B22F4 80240B64 8E430070 */  lw        $v1, 0x70($s2)
/* 9B22F8 80240B68 24110001 */  addiu     $s1, $zero, 1
/* 9B22FC 80240B6C 10710013 */  beq       $v1, $s1, .L80240BBC
/* 9B2300 80240B70 28620002 */   slti     $v0, $v1, 2
/* 9B2304 80240B74 10400005 */  beqz      $v0, .L80240B8C
/* 9B2308 80240B78 24020002 */   addiu    $v0, $zero, 2
/* 9B230C 80240B7C 10600009 */  beqz      $v1, .L80240BA4
/* 9B2310 80240B80 0000102D */   daddu    $v0, $zero, $zero
/* 9B2314 80240B84 08090315 */  j         .L80240C54
/* 9B2318 80240B88 00000000 */   nop
.L80240B8C:
/* 9B231C 80240B8C 10620013 */  beq       $v1, $v0, .L80240BDC
/* 9B2320 80240B90 24020003 */   addiu    $v0, $zero, 3
/* 9B2324 80240B94 1062001E */  beq       $v1, $v0, .L80240C10
/* 9B2328 80240B98 0000102D */   daddu    $v0, $zero, $zero
/* 9B232C 80240B9C 08090315 */  j         .L80240C54
/* 9B2330 80240BA0 00000000 */   nop
.L80240BA4:
/* 9B2334 80240BA4 0C03AC5A */  jal       func_800EB168
/* 9B2338 80240BA8 0000202D */   daddu    $a0, $zero, $zero
/* 9B233C 80240BAC 2402001E */  addiu     $v0, $zero, 0x1e
/* 9B2340 80240BB0 AE420074 */  sw        $v0, 0x74($s2)
/* 9B2344 80240BB4 08090314 */  j         .L80240C50
/* 9B2348 80240BB8 AE510070 */   sw       $s1, 0x70($s2)
.L80240BBC:
/* 9B234C 80240BBC 8E420074 */  lw        $v0, 0x74($s2)
/* 9B2350 80240BC0 2403FFFF */  addiu     $v1, $zero, -1
/* 9B2354 80240BC4 2442FFFF */  addiu     $v0, $v0, -1
/* 9B2358 80240BC8 14430021 */  bne       $v0, $v1, .L80240C50
/* 9B235C 80240BCC AE420074 */   sw       $v0, 0x74($s2)
/* 9B2360 80240BD0 24020002 */  addiu     $v0, $zero, 2
/* 9B2364 80240BD4 08090314 */  j         .L80240C50
/* 9B2368 80240BD8 AE420070 */   sw       $v0, 0x70($s2)
.L80240BDC:
/* 9B236C 80240BDC 0200202D */  daddu     $a0, $s0, $zero
/* 9B2370 80240BE0 00141600 */  sll       $v0, $s4, 0x18
/* 9B2374 80240BE4 00021543 */  sra       $v0, $v0, 0x15
/* 9B2378 80240BE8 02621021 */  addu      $v0, $s3, $v0
/* 9B237C 80240BEC A2740012 */  sb        $s4, 0x12($s3)
/* 9B2380 80240BF0 0C03BD17 */  jal       clear_partner_move_history
/* 9B2384 80240BF4 A0510014 */   sb       $s1, 0x14($v0)
/* 9B2388 80240BF8 82640012 */  lb        $a0, 0x12($s3)
/* 9B238C 80240BFC 0C03ACA9 */  jal       func_800EB2A4
/* 9B2390 80240C00 00000000 */   nop
/* 9B2394 80240C04 24020003 */  addiu     $v0, $zero, 3
/* 9B2398 80240C08 08090314 */  j         .L80240C50
/* 9B239C 80240C0C AE420070 */   sw       $v0, 0x70($s2)
.L80240C10:
/* 9B23A0 80240C10 0C00EAD2 */  jal       get_npc_safe
/* 9B23A4 80240C14 2404FFFC */   addiu    $a0, $zero, -4
/* 9B23A8 80240C18 8E05000C */  lw        $a1, 0xc($s0)
/* 9B23AC 80240C1C 0C00ECD0 */  jal       set_npc_yaw
/* 9B23B0 80240C20 0040202D */   daddu    $a0, $v0, $zero
/* 9B23B4 80240C24 0200202D */  daddu     $a0, $s0, $zero
/* 9B23B8 80240C28 8E020000 */  lw        $v0, ($s0)
/* 9B23BC 80240C2C 2403FFFB */  addiu     $v1, $zero, -5
/* 9B23C0 80240C30 00431024 */  and       $v0, $v0, $v1
/* 9B23C4 80240C34 0C00EAFF */  jal       disable_npc_shadow
/* 9B23C8 80240C38 AE020000 */   sw       $v0, ($s0)
/* 9B23CC 80240C3C 3C01C47A */  lui       $at, 0xc47a
/* 9B23D0 80240C40 44810000 */  mtc1      $at, $f0
/* 9B23D4 80240C44 24020002 */  addiu     $v0, $zero, 2
/* 9B23D8 80240C48 08090315 */  j         .L80240C54
/* 9B23DC 80240C4C E600003C */   swc1     $f0, 0x3c($s0)
.L80240C50:
/* 9B23E0 80240C50 0000102D */  daddu     $v0, $zero, $zero
.L80240C54:
/* 9B23E4 80240C54 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9B23E8 80240C58 8FB40020 */  lw        $s4, 0x20($sp)
/* 9B23EC 80240C5C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9B23F0 80240C60 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B23F4 80240C64 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B23F8 80240C68 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B23FC 80240C6C 03E00008 */  jr        $ra
/* 9B2400 80240C70 27BD0028 */   addiu    $sp, $sp, 0x28
/* 9B2404 80240C74 00000000 */  nop
/* 9B2408 80240C78 00000000 */  nop
/* 9B240C 80240C7C 00000000 */  nop
