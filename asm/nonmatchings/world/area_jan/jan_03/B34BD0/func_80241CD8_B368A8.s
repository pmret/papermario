.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CD8_B368A8
/* B368A8 80241CD8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B368AC 80241CDC AFB10024 */  sw        $s1, 0x24($sp)
/* B368B0 80241CE0 0080882D */  daddu     $s1, $a0, $zero
/* B368B4 80241CE4 3C05F840 */  lui       $a1, 0xf840
/* B368B8 80241CE8 AFBF0044 */  sw        $ra, 0x44($sp)
/* B368BC 80241CEC AFBE0040 */  sw        $fp, 0x40($sp)
/* B368C0 80241CF0 AFB7003C */  sw        $s7, 0x3c($sp)
/* B368C4 80241CF4 AFB60038 */  sw        $s6, 0x38($sp)
/* B368C8 80241CF8 AFB50034 */  sw        $s5, 0x34($sp)
/* B368CC 80241CFC AFB40030 */  sw        $s4, 0x30($sp)
/* B368D0 80241D00 AFB3002C */  sw        $s3, 0x2c($sp)
/* B368D4 80241D04 AFB20028 */  sw        $s2, 0x28($sp)
/* B368D8 80241D08 AFB00020 */  sw        $s0, 0x20($sp)
/* B368DC 80241D0C 8E3E0148 */  lw        $fp, 0x148($s1)
/* B368E0 80241D10 0C0B1EAF */  jal       get_variable
/* B368E4 80241D14 34A56268 */   ori      $a1, $a1, 0x6268
/* B368E8 80241D18 0040802D */  daddu     $s0, $v0, $zero
/* B368EC 80241D1C 0220202D */  daddu     $a0, $s1, $zero
/* B368F0 80241D20 3C05F840 */  lui       $a1, 0xf840
/* B368F4 80241D24 0C0B1EAF */  jal       get_variable
/* B368F8 80241D28 34A56269 */   ori      $a1, $a1, 0x6269
/* B368FC 80241D2C 0040B82D */  daddu     $s7, $v0, $zero
/* B36900 80241D30 0220202D */  daddu     $a0, $s1, $zero
/* B36904 80241D34 3C05F5DE */  lui       $a1, 0xf5de
/* B36908 80241D38 0C0B1EAF */  jal       get_variable
/* B3690C 80241D3C 34A502DE */   ori      $a1, $a1, 0x2de
/* B36910 80241D40 0040B02D */  daddu     $s6, $v0, $zero
/* B36914 80241D44 0220202D */  daddu     $a0, $s1, $zero
/* B36918 80241D48 3C05F5DE */  lui       $a1, 0xf5de
/* B3691C 80241D4C 0C0B1EAF */  jal       get_variable
/* B36920 80241D50 34A502DF */   ori      $a1, $a1, 0x2df
/* B36924 80241D54 0040A82D */  daddu     $s5, $v0, $zero
/* B36928 80241D58 93D3006D */  lbu       $s3, 0x6d($fp)
/* B3692C 80241D5C 32C2FFFF */  andi      $v0, $s6, 0xffff
/* B36930 80241D60 A7B30010 */  sh        $s3, 0x10($sp)
/* B36934 80241D64 93D2006E */  lbu       $s2, 0x6e($fp)
/* B36938 80241D68 93C7006F */  lbu       $a3, 0x6f($fp)
/* B3693C 80241D6C 3274FFFF */  andi      $s4, $s3, 0xffff
/* B36940 80241D70 12820003 */  beq       $s4, $v0, .L80241D80
/* B36944 80241D74 A7A7001E */   sh       $a3, 0x1e($sp)
/* B36948 80241D78 0000B82D */  daddu     $s7, $zero, $zero
/* B3694C 80241D7C 02E0802D */  daddu     $s0, $s7, $zero
.L80241D80:
/* B36950 80241D80 3202FFFF */  andi      $v0, $s0, 0xffff
/* B36954 80241D84 14400016 */  bnez      $v0, .L80241DE0
/* B36958 80241D88 0220202D */   daddu    $a0, $s1, $zero
/* B3695C 80241D8C 0C00A67F */  jal       rand_int
/* B36960 80241D90 24040064 */   addiu    $a0, $zero, 0x64
/* B36964 80241D94 2842001E */  slti      $v0, $v0, 0x1e
/* B36968 80241D98 10400011 */  beqz      $v0, .L80241DE0
/* B3696C 80241D9C 0220202D */   daddu    $a0, $s1, $zero
/* B36970 80241DA0 0C00A67F */  jal       rand_int
/* B36974 80241DA4 2644FFFF */   addiu    $a0, $s2, -1
/* B36978 80241DA8 0040A82D */  daddu     $s5, $v0, $zero
/* B3697C 80241DAC 0260B02D */  daddu     $s6, $s3, $zero
/* B36980 80241DB0 0220202D */  daddu     $a0, $s1, $zero
/* B36984 80241DB4 3C05F5DE */  lui       $a1, 0xf5de
/* B36988 80241DB8 34A502DE */  ori       $a1, $a1, 0x2de
/* B3698C 80241DBC 0C0B2026 */  jal       set_variable
/* B36990 80241DC0 0280302D */   daddu    $a2, $s4, $zero
/* B36994 80241DC4 0220202D */  daddu     $a0, $s1, $zero
/* B36998 80241DC8 3C05F5DE */  lui       $a1, 0xf5de
/* B3699C 80241DCC 34A502DF */  ori       $a1, $a1, 0x2df
/* B369A0 80241DD0 0C0B2026 */  jal       set_variable
/* B369A4 80241DD4 32A6FFFF */   andi     $a2, $s5, 0xffff
/* B369A8 80241DD8 24100001 */  addiu     $s0, $zero, 1
/* B369AC 80241DDC 0220202D */  daddu     $a0, $s1, $zero
.L80241DE0:
/* B369B0 80241DE0 3C05F840 */  lui       $a1, 0xf840
/* B369B4 80241DE4 34A56268 */  ori       $a1, $a1, 0x6268
/* B369B8 80241DE8 0C0B2026 */  jal       set_variable
/* B369BC 80241DEC 3206FFFF */   andi     $a2, $s0, 0xffff
/* B369C0 80241DF0 0220202D */  daddu     $a0, $s1, $zero
/* B369C4 80241DF4 3C05F840 */  lui       $a1, 0xf840
/* B369C8 80241DF8 34A56269 */  ori       $a1, $a1, 0x6269
/* B369CC 80241DFC 0C0B2026 */  jal       set_variable
/* B369D0 80241E00 32E6FFFF */   andi     $a2, $s7, 0xffff
/* B369D4 80241E04 0000202D */  daddu     $a0, $zero, $zero
/* B369D8 80241E08 3C05F5DE */  lui       $a1, 0xf5de
/* B369DC 80241E0C 0C0B1EAF */  jal       get_variable
/* B369E0 80241E10 34A502E0 */   ori      $a1, $a1, 0x2e0
/* B369E4 80241E14 0000202D */  daddu     $a0, $zero, $zero
/* B369E8 80241E18 3C05F5DE */  lui       $a1, 0xf5de
/* B369EC 80241E1C 34A50180 */  ori       $a1, $a1, 0x180
/* B369F0 80241E20 0C0B1EAF */  jal       get_variable
/* B369F4 80241E24 0040802D */   daddu    $s0, $v0, $zero
/* B369F8 80241E28 0040282D */  daddu     $a1, $v0, $zero
/* B369FC 80241E2C 0000182D */  daddu     $v1, $zero, $zero
/* B36A00 80241E30 3C068024 */  lui       $a2, %hi(D_80247808)
/* B36A04 80241E34 24C67808 */  addiu     $a2, $a2, %lo(D_80247808)
/* B36A08 80241E38 00C0202D */  daddu     $a0, $a2, $zero
.L80241E3C:
/* B36A0C 80241E3C 8C820000 */  lw        $v0, ($a0)
/* B36A10 80241E40 00A2102A */  slt       $v0, $a1, $v0
/* B36A14 80241E44 14400006 */  bnez      $v0, .L80241E60
/* B36A18 80241E48 000310C0 */   sll      $v0, $v1, 3
/* B36A1C 80241E4C 24630001 */  addiu     $v1, $v1, 1
/* B36A20 80241E50 28620008 */  slti      $v0, $v1, 8
/* B36A24 80241E54 1440FFF9 */  bnez      $v0, .L80241E3C
/* B36A28 80241E58 24840008 */   addiu    $a0, $a0, 8
/* B36A2C 80241E5C 000310C0 */  sll       $v0, $v1, 3
.L80241E60:
/* B36A30 80241E60 00461021 */  addu      $v0, $v0, $a2
/* B36A34 80241E64 8C420004 */  lw        $v0, 4($v0)
/* B36A38 80241E68 97A30010 */  lhu       $v1, 0x10($sp)
/* B36A3C 80241E6C 0202202A */  slt       $a0, $s0, $v0
/* B36A40 80241E70 32C2FFFF */  andi      $v0, $s6, 0xffff
/* B36A44 80241E74 14620008 */  bne       $v1, $v0, .L80241E98
/* B36A48 80241E78 32A2FFFF */   andi     $v0, $s5, 0xffff
/* B36A4C 80241E7C 97A7001E */  lhu       $a3, 0x1e($sp)
/* B36A50 80241E80 14E20005 */  bne       $a3, $v0, .L80241E98
/* B36A54 80241E84 32E2FFFF */   andi     $v0, $s7, 0xffff
/* B36A58 80241E88 14400003 */  bnez      $v0, .L80241E98
/* B36A5C 80241E8C 00000000 */   nop      
/* B36A60 80241E90 14800008 */  bnez      $a0, .L80241EB4
/* B36A64 80241E94 24020001 */   addiu    $v0, $zero, 1
.L80241E98:
/* B36A68 80241E98 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B36A6C 80241E9C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B36A70 80241EA0 80420075 */  lb        $v0, 0x75($v0)
/* B36A74 80241EA4 10400005 */  beqz      $v0, .L80241EBC
/* B36A78 80241EA8 00000000 */   nop      
/* B36A7C 80241EAC 10800003 */  beqz      $a0, .L80241EBC
/* B36A80 80241EB0 24020001 */   addiu    $v0, $zero, 1
.L80241EB4:
/* B36A84 80241EB4 080907B2 */  j         .L80241EC8
/* B36A88 80241EB8 AE220084 */   sw       $v0, 0x84($s1)
.L80241EBC:
/* B36A8C 80241EBC 0C00F9EB */  jal       kill_enemy
/* B36A90 80241EC0 03C0202D */   daddu    $a0, $fp, $zero
/* B36A94 80241EC4 AE200084 */  sw        $zero, 0x84($s1)
.L80241EC8:
/* B36A98 80241EC8 8FBF0044 */  lw        $ra, 0x44($sp)
/* B36A9C 80241ECC 8FBE0040 */  lw        $fp, 0x40($sp)
/* B36AA0 80241ED0 8FB7003C */  lw        $s7, 0x3c($sp)
/* B36AA4 80241ED4 8FB60038 */  lw        $s6, 0x38($sp)
/* B36AA8 80241ED8 8FB50034 */  lw        $s5, 0x34($sp)
/* B36AAC 80241EDC 8FB40030 */  lw        $s4, 0x30($sp)
/* B36AB0 80241EE0 8FB3002C */  lw        $s3, 0x2c($sp)
/* B36AB4 80241EE4 8FB20028 */  lw        $s2, 0x28($sp)
/* B36AB8 80241EE8 8FB10024 */  lw        $s1, 0x24($sp)
/* B36ABC 80241EEC 8FB00020 */  lw        $s0, 0x20($sp)
/* B36AC0 80241EF0 24020002 */  addiu     $v0, $zero, 2
/* B36AC4 80241EF4 03E00008 */  jr        $ra
/* B36AC8 80241EF8 27BD0048 */   addiu    $sp, $sp, 0x48
