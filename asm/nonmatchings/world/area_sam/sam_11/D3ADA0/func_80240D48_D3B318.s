.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D48_D3B318
/* D3B318 80240D48 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D3B31C 80240D4C AFB00010 */  sw        $s0, 0x10($sp)
/* D3B320 80240D50 0080802D */  daddu     $s0, $a0, $zero
/* D3B324 80240D54 AFBF0020 */  sw        $ra, 0x20($sp)
/* D3B328 80240D58 AFB3001C */  sw        $s3, 0x1c($sp)
/* D3B32C 80240D5C AFB20018 */  sw        $s2, 0x18($sp)
/* D3B330 80240D60 10A00009 */  beqz      $a1, .L80240D88
/* D3B334 80240D64 AFB10014 */   sw       $s1, 0x14($sp)
/* D3B338 80240D68 0000202D */  daddu     $a0, $zero, $zero
/* D3B33C 80240D6C 0080282D */  daddu     $a1, $a0, $zero
/* D3B340 80240D70 0080302D */  daddu     $a2, $a0, $zero
/* D3B344 80240D74 0C046F97 */  jal       set_background_color_blend
/* D3B348 80240D78 240700FF */   addiu    $a3, $zero, 0xff
/* D3B34C 80240D7C 240200FF */  addiu     $v0, $zero, 0xff
/* D3B350 80240D80 AE020070 */  sw        $v0, 0x70($s0)
/* D3B354 80240D84 AE000074 */  sw        $zero, 0x74($s0)
.L80240D88:
/* D3B358 80240D88 8E020070 */  lw        $v0, 0x70($s0)
/* D3B35C 80240D8C 2442FFF8 */  addiu     $v0, $v0, -8
/* D3B360 80240D90 04410002 */  bgez      $v0, .L80240D9C
/* D3B364 80240D94 AE020070 */   sw       $v0, 0x70($s0)
/* D3B368 80240D98 AE000070 */  sw        $zero, 0x70($s0)
.L80240D9C:
/* D3B36C 80240D9C 0000202D */  daddu     $a0, $zero, $zero
/* D3B370 80240DA0 0080282D */  daddu     $a1, $a0, $zero
/* D3B374 80240DA4 92070073 */  lbu       $a3, 0x73($s0)
/* D3B378 80240DA8 0C046F97 */  jal       set_background_color_blend
/* D3B37C 80240DAC 0080302D */   daddu    $a2, $a0, $zero
/* D3B380 80240DB0 8E020070 */  lw        $v0, 0x70($s0)
/* D3B384 80240DB4 14400006 */  bnez      $v0, .L80240DD0
/* D3B388 80240DB8 00000000 */   nop      
/* D3B38C 80240DBC 8E020074 */  lw        $v0, 0x74($s0)
/* D3B390 80240DC0 14400003 */  bnez      $v0, .L80240DD0
/* D3B394 80240DC4 24020001 */   addiu    $v0, $zero, 1
/* D3B398 80240DC8 080903A7 */  j         .L80240E9C
/* D3B39C 80240DCC AE020074 */   sw       $v0, 0x74($s0)
.L80240DD0:
/* D3B3A0 80240DD0 8E030074 */  lw        $v1, 0x74($s0)
/* D3B3A4 80240DD4 24020001 */  addiu     $v0, $zero, 1
/* D3B3A8 80240DD8 14620031 */  bne       $v1, $v0, .L80240EA0
/* D3B3AC 80240DDC 0000102D */   daddu    $v0, $zero, $zero
/* D3B3B0 80240DE0 0C04760B */  jal       func_8011D82C
/* D3B3B4 80240DE4 0000202D */   daddu    $a0, $zero, $zero
/* D3B3B8 80240DE8 0000802D */  daddu     $s0, $zero, $zero
/* D3B3BC 80240DEC 2413FFFC */  addiu     $s3, $zero, -4
/* D3B3C0 80240DF0 24120011 */  addiu     $s2, $zero, 0x11
/* D3B3C4 80240DF4 3C11FF7F */  lui       $s1, 0xff7f
/* D3B3C8 80240DF8 3C028015 */  lui       $v0, %hi(D_801512F0)
/* D3B3CC 80240DFC 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* D3B3D0 80240E00 3631FFFF */  ori       $s1, $s1, 0xffff
/* D3B3D4 80240E04 A0400000 */  sb        $zero, ($v0)
.L80240E08:
/* D3B3D8 80240E08 0C00E2B7 */  jal       get_npc_by_index
/* D3B3DC 80240E0C 0200202D */   daddu    $a0, $s0, $zero
/* D3B3E0 80240E10 0040202D */  daddu     $a0, $v0, $zero
/* D3B3E4 80240E14 5080000B */  beql      $a0, $zero, .L80240E44
/* D3B3E8 80240E18 26100001 */   addiu    $s0, $s0, 1
/* D3B3EC 80240E1C 8C820000 */  lw        $v0, ($a0)
/* D3B3F0 80240E20 50400008 */  beql      $v0, $zero, .L80240E44
/* D3B3F4 80240E24 26100001 */   addiu    $s0, $s0, 1
/* D3B3F8 80240E28 808300A4 */  lb        $v1, 0xa4($a0)
/* D3B3FC 80240E2C 10730005 */  beq       $v1, $s3, .L80240E44
/* D3B400 80240E30 26100001 */   addiu    $s0, $s0, 1
/* D3B404 80240E34 10720003 */  beq       $v1, $s2, .L80240E44
/* D3B408 80240E38 00000000 */   nop      
/* D3B40C 80240E3C 00511024 */  and       $v0, $v0, $s1
/* D3B410 80240E40 AC820000 */  sw        $v0, ($a0)
.L80240E44:
/* D3B414 80240E44 2A020040 */  slti      $v0, $s0, 0x40
/* D3B418 80240E48 1440FFEF */  bnez      $v0, .L80240E08
/* D3B41C 80240E4C 00000000 */   nop      
/* D3B420 80240E50 0000802D */  daddu     $s0, $zero, $zero
/* D3B424 80240E54 3C11F7FF */  lui       $s1, 0xf7ff
/* D3B428 80240E58 3631FFFF */  ori       $s1, $s1, 0xffff
.L80240E5C:
/* D3B42C 80240E5C 0C04C3D6 */  jal       get_item_entity
/* D3B430 80240E60 0200202D */   daddu    $a0, $s0, $zero
/* D3B434 80240E64 0040182D */  daddu     $v1, $v0, $zero
/* D3B438 80240E68 10600007 */  beqz      $v1, .L80240E88
/* D3B43C 80240E6C 26100001 */   addiu    $s0, $s0, 1
/* D3B440 80240E70 8C640000 */  lw        $a0, ($v1)
/* D3B444 80240E74 30820010 */  andi      $v0, $a0, 0x10
/* D3B448 80240E78 10400003 */  beqz      $v0, .L80240E88
/* D3B44C 80240E7C 00000000 */   nop      
/* D3B450 80240E80 00911024 */  and       $v0, $a0, $s1
/* D3B454 80240E84 AC620000 */  sw        $v0, ($v1)
.L80240E88:
/* D3B458 80240E88 2A020100 */  slti      $v0, $s0, 0x100
/* D3B45C 80240E8C 1440FFF3 */  bnez      $v0, .L80240E5C
/* D3B460 80240E90 24020002 */   addiu    $v0, $zero, 2
/* D3B464 80240E94 080903A8 */  j         .L80240EA0
/* D3B468 80240E98 00000000 */   nop      
.L80240E9C:
/* D3B46C 80240E9C 0000102D */  daddu     $v0, $zero, $zero
.L80240EA0:
/* D3B470 80240EA0 8FBF0020 */  lw        $ra, 0x20($sp)
/* D3B474 80240EA4 8FB3001C */  lw        $s3, 0x1c($sp)
/* D3B478 80240EA8 8FB20018 */  lw        $s2, 0x18($sp)
/* D3B47C 80240EAC 8FB10014 */  lw        $s1, 0x14($sp)
/* D3B480 80240EB0 8FB00010 */  lw        $s0, 0x10($sp)
/* D3B484 80240EB4 03E00008 */  jr        $ra
/* D3B488 80240EB8 27BD0028 */   addiu    $sp, $sp, 0x28
