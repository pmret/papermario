.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E90_8B1F00
/* 8B1F00 80241E90 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8B1F04 80241E94 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B1F08 80241E98 0080902D */  daddu     $s2, $a0, $zero
/* 8B1F0C 80241E9C AFB10014 */  sw        $s1, 0x14($sp)
/* 8B1F10 80241EA0 00A0882D */  daddu     $s1, $a1, $zero
/* 8B1F14 80241EA4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 8B1F18 80241EA8 AFB40020 */  sw        $s4, 0x20($sp)
/* 8B1F1C 80241EAC AFB3001C */  sw        $s3, 0x1c($sp)
/* 8B1F20 80241EB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B1F24 80241EB4 8E50000C */  lw        $s0, 0xc($s2)
/* 8B1F28 80241EB8 8E050000 */  lw        $a1, ($s0)
/* 8B1F2C 80241EBC 0C0B1EAF */  jal       get_variable
/* 8B1F30 80241EC0 26100004 */   addiu    $s0, $s0, 4
/* 8B1F34 80241EC4 0240202D */  daddu     $a0, $s2, $zero
/* 8B1F38 80241EC8 8E050000 */  lw        $a1, ($s0)
/* 8B1F3C 80241ECC 0C0B1EAF */  jal       get_variable
/* 8B1F40 80241ED0 0040802D */   daddu    $s0, $v0, $zero
/* 8B1F44 80241ED4 0200202D */  daddu     $a0, $s0, $zero
/* 8B1F48 80241ED8 0C00EAD2 */  jal       get_npc_safe
/* 8B1F4C 80241EDC 0040A02D */   daddu    $s4, $v0, $zero
/* 8B1F50 80241EE0 3C138011 */  lui       $s3, %hi(gPlayerData)
/* 8B1F54 80241EE4 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* 8B1F58 80241EE8 12200006 */  beqz      $s1, .L80241F04
/* 8B1F5C 80241EEC 0040802D */   daddu    $s0, $v0, $zero
/* 8B1F60 80241EF0 82620012 */  lb        $v0, 0x12($s3)
/* 8B1F64 80241EF4 54400003 */  bnel      $v0, $zero, .L80241F04
/* 8B1F68 80241EF8 AE400070 */   sw       $zero, 0x70($s2)
/* 8B1F6C 80241EFC 24020002 */  addiu     $v0, $zero, 2
/* 8B1F70 80241F00 AE420070 */  sw        $v0, 0x70($s2)
.L80241F04:
/* 8B1F74 80241F04 8E430070 */  lw        $v1, 0x70($s2)
/* 8B1F78 80241F08 24110001 */  addiu     $s1, $zero, 1
/* 8B1F7C 80241F0C 10710013 */  beq       $v1, $s1, .L80241F5C
/* 8B1F80 80241F10 28620002 */   slti     $v0, $v1, 2
/* 8B1F84 80241F14 10400005 */  beqz      $v0, .L80241F2C
/* 8B1F88 80241F18 24020002 */   addiu    $v0, $zero, 2
/* 8B1F8C 80241F1C 10600009 */  beqz      $v1, .L80241F44
/* 8B1F90 80241F20 0000102D */   daddu    $v0, $zero, $zero
/* 8B1F94 80241F24 080907FD */  j         .L80241FF4
/* 8B1F98 80241F28 00000000 */   nop
.L80241F2C:
/* 8B1F9C 80241F2C 10620013 */  beq       $v1, $v0, .L80241F7C
/* 8B1FA0 80241F30 24020003 */   addiu    $v0, $zero, 3
/* 8B1FA4 80241F34 1062001E */  beq       $v1, $v0, .L80241FB0
/* 8B1FA8 80241F38 0000102D */   daddu    $v0, $zero, $zero
/* 8B1FAC 80241F3C 080907FD */  j         .L80241FF4
/* 8B1FB0 80241F40 00000000 */   nop
.L80241F44:
/* 8B1FB4 80241F44 0C03AC5A */  jal       func_800EB168
/* 8B1FB8 80241F48 0000202D */   daddu    $a0, $zero, $zero
/* 8B1FBC 80241F4C 2402001E */  addiu     $v0, $zero, 0x1e
/* 8B1FC0 80241F50 AE420074 */  sw        $v0, 0x74($s2)
/* 8B1FC4 80241F54 080907FC */  j         .L80241FF0
/* 8B1FC8 80241F58 AE510070 */   sw       $s1, 0x70($s2)
.L80241F5C:
/* 8B1FCC 80241F5C 8E420074 */  lw        $v0, 0x74($s2)
/* 8B1FD0 80241F60 2403FFFF */  addiu     $v1, $zero, -1
/* 8B1FD4 80241F64 2442FFFF */  addiu     $v0, $v0, -1
/* 8B1FD8 80241F68 14430021 */  bne       $v0, $v1, .L80241FF0
/* 8B1FDC 80241F6C AE420074 */   sw       $v0, 0x74($s2)
/* 8B1FE0 80241F70 24020002 */  addiu     $v0, $zero, 2
/* 8B1FE4 80241F74 080907FC */  j         .L80241FF0
/* 8B1FE8 80241F78 AE420070 */   sw       $v0, 0x70($s2)
.L80241F7C:
/* 8B1FEC 80241F7C 0200202D */  daddu     $a0, $s0, $zero
/* 8B1FF0 80241F80 00141600 */  sll       $v0, $s4, 0x18
/* 8B1FF4 80241F84 00021543 */  sra       $v0, $v0, 0x15
/* 8B1FF8 80241F88 02621021 */  addu      $v0, $s3, $v0
/* 8B1FFC 80241F8C A2740012 */  sb        $s4, 0x12($s3)
/* 8B2000 80241F90 0C03BD17 */  jal       clear_partner_move_history
/* 8B2004 80241F94 A0510014 */   sb       $s1, 0x14($v0)
/* 8B2008 80241F98 82640012 */  lb        $a0, 0x12($s3)
/* 8B200C 80241F9C 0C03ACA9 */  jal       func_800EB2A4
/* 8B2010 80241FA0 00000000 */   nop
/* 8B2014 80241FA4 24020003 */  addiu     $v0, $zero, 3
/* 8B2018 80241FA8 080907FC */  j         .L80241FF0
/* 8B201C 80241FAC AE420070 */   sw       $v0, 0x70($s2)
.L80241FB0:
/* 8B2020 80241FB0 0C00EAD2 */  jal       get_npc_safe
/* 8B2024 80241FB4 2404FFFC */   addiu    $a0, $zero, -4
/* 8B2028 80241FB8 8E05000C */  lw        $a1, 0xc($s0)
/* 8B202C 80241FBC 0C00ECD0 */  jal       set_npc_yaw
/* 8B2030 80241FC0 0040202D */   daddu    $a0, $v0, $zero
/* 8B2034 80241FC4 0200202D */  daddu     $a0, $s0, $zero
/* 8B2038 80241FC8 8E020000 */  lw        $v0, ($s0)
/* 8B203C 80241FCC 2403FFFB */  addiu     $v1, $zero, -5
/* 8B2040 80241FD0 00431024 */  and       $v0, $v0, $v1
/* 8B2044 80241FD4 0C00EAFF */  jal       disable_npc_shadow
/* 8B2048 80241FD8 AE020000 */   sw       $v0, ($s0)
/* 8B204C 80241FDC 3C01C47A */  lui       $at, 0xc47a
/* 8B2050 80241FE0 44810000 */  mtc1      $at, $f0
/* 8B2054 80241FE4 24020002 */  addiu     $v0, $zero, 2
/* 8B2058 80241FE8 080907FD */  j         .L80241FF4
/* 8B205C 80241FEC E600003C */   swc1     $f0, 0x3c($s0)
.L80241FF0:
/* 8B2060 80241FF0 0000102D */  daddu     $v0, $zero, $zero
.L80241FF4:
/* 8B2064 80241FF4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 8B2068 80241FF8 8FB40020 */  lw        $s4, 0x20($sp)
/* 8B206C 80241FFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8B2070 80242000 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B2074 80242004 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B2078 80242008 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B207C 8024200C 03E00008 */  jr        $ra
/* 8B2080 80242010 27BD0028 */   addiu    $sp, $sp, 0x28
