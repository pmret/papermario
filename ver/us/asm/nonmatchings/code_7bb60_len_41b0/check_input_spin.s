.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel check_input_spin
/* 7F718 800E6268 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7F71C 800E626C AFB00010 */  sw        $s0, 0x10($sp)
/* 7F720 800E6270 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7F724 800E6274 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7F728 800E6278 AFB10014 */  sw        $s1, 0x14($sp)
/* 7F72C 800E627C 3C118011 */  lui       $s1, %hi(D_8010F250)
/* 7F730 800E6280 2631F250 */  addiu     $s1, $s1, %lo(D_8010F250)
/* 7F734 800E6284 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7F738 800E6288 AFB20018 */  sw        $s2, 0x18($sp)
/* 7F73C 800E628C 8E020000 */  lw        $v0, ($s0)
/* 7F740 800E6290 30425000 */  andi      $v0, $v0, 0x5000
/* 7F744 800E6294 1440002F */  bnez      $v0, .L800E6354
/* 7F748 800E6298 0220902D */   daddu    $s2, $s1, $zero
/* 7F74C 800E629C 8E020004 */  lw        $v0, 4($s0)
/* 7F750 800E62A0 30420001 */  andi      $v0, $v0, 1
/* 7F754 800E62A4 1440002B */  bnez      $v0, .L800E6354
/* 7F758 800E62A8 00000000 */   nop
/* 7F75C 800E62AC 8E0200DC */  lw        $v0, 0xdc($s0)
/* 7F760 800E62B0 30420004 */  andi      $v0, $v0, 4
/* 7F764 800E62B4 14400027 */  bnez      $v0, .L800E6354
/* 7F768 800E62B8 00000000 */   nop
/* 7F76C 800E62BC 0C03A752 */  jal       is_ability_active
/* 7F770 800E62C0 2404000B */   addiu    $a0, $zero, 0xb
/* 7F774 800E62C4 14400023 */  bnez      $v0, .L800E6354
/* 7F778 800E62C8 00000000 */   nop
/* 7F77C 800E62CC 8E0200E0 */  lw        $v0, 0xe0($s0)
/* 7F780 800E62D0 820300B4 */  lb        $v1, 0xb4($s0)
/* 7F784 800E62D4 30442000 */  andi      $a0, $v0, 0x2000
/* 7F788 800E62D8 24020021 */  addiu     $v0, $zero, 0x21
/* 7F78C 800E62DC 1062001D */  beq       $v1, $v0, .L800E6354
/* 7F790 800E62E0 28620022 */   slti     $v0, $v1, 0x22
/* 7F794 800E62E4 1040001B */  beqz      $v0, .L800E6354
/* 7F798 800E62E8 28620003 */   slti     $v0, $v1, 3
/* 7F79C 800E62EC 10400019 */  beqz      $v0, .L800E6354
/* 7F7A0 800E62F0 00000000 */   nop
/* 7F7A4 800E62F4 04600017 */  bltz      $v1, .L800E6354
/* 7F7A8 800E62F8 3C030001 */   lui      $v1, 1
/* 7F7AC 800E62FC 8E020004 */  lw        $v0, 4($s0)
/* 7F7B0 800E6300 00431024 */  and       $v0, $v0, $v1
/* 7F7B4 800E6304 14400013 */  bnez      $v0, .L800E6354
/* 7F7B8 800E6308 00000000 */   nop
/* 7F7BC 800E630C 14800004 */  bnez      $a0, .L800E6320
/* 7F7C0 800E6310 00000000 */   nop
/* 7F7C4 800E6314 82220001 */  lb        $v0, 1($s1)
/* 7F7C8 800E6318 1040000E */  beqz      $v0, .L800E6354
/* 7F7CC 800E631C 00000000 */   nop
.L800E6320:
/* 7F7D0 800E6320 0C039769 */  jal       set_action_state
/* 7F7D4 800E6324 2404001A */   addiu    $a0, $zero, 0x1a
/* 7F7D8 800E6328 82220001 */  lb        $v0, 1($s1)
/* 7F7DC 800E632C 10400009 */  beqz      $v0, .L800E6354
/* 7F7E0 800E6330 00000000 */   nop
/* 7F7E4 800E6334 8E220008 */  lw        $v0, 8($s1)
/* 7F7E8 800E6338 14400004 */  bnez      $v0, .L800E634C
/* 7F7EC 800E633C 00000000 */   nop
/* 7F7F0 800E6340 8E22000C */  lw        $v0, 0xc($s1)
/* 7F7F4 800E6344 50400003 */  beql      $v0, $zero, .L800E6354
/* 7F7F8 800E6348 A20000B5 */   sb       $zero, 0xb5($s0)
.L800E634C:
/* 7F7FC 800E634C 92420007 */  lbu       $v0, 7($s2)
/* 7F800 800E6350 A20200B5 */  sb        $v0, 0xb5($s0)
.L800E6354:
/* 7F804 800E6354 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7F808 800E6358 8FB20018 */  lw        $s2, 0x18($sp)
/* 7F80C 800E635C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7F810 800E6360 8FB00010 */  lw        $s0, 0x10($sp)
/* 7F814 800E6364 03E00008 */  jr        $ra
/* 7F818 800E6368 27BD0020 */   addiu    $sp, $sp, 0x20
