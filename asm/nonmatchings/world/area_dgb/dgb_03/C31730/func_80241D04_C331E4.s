.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D04_C331E4
/* C331E4 80241D04 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C331E8 80241D08 AFB40048 */  sw        $s4, 0x48($sp)
/* C331EC 80241D0C 0080A02D */  daddu     $s4, $a0, $zero
/* C331F0 80241D10 AFBF004C */  sw        $ra, 0x4c($sp)
/* C331F4 80241D14 AFB30044 */  sw        $s3, 0x44($sp)
/* C331F8 80241D18 AFB20040 */  sw        $s2, 0x40($sp)
/* C331FC 80241D1C AFB1003C */  sw        $s1, 0x3c($sp)
/* C33200 80241D20 AFB00038 */  sw        $s0, 0x38($sp)
/* C33204 80241D24 8E930148 */  lw        $s3, 0x148($s4)
/* C33208 80241D28 00C0802D */  daddu     $s0, $a2, $zero
/* C3320C 80241D2C 86640008 */  lh        $a0, 8($s3)
/* C33210 80241D30 0C00EABB */  jal       get_npc_unsafe
/* C33214 80241D34 0000902D */   daddu    $s2, $zero, $zero
/* C33218 80241D38 0C039D59 */  jal       get_player_data
/* C3321C 80241D3C 0040882D */   daddu    $s1, $v0, $zero
/* C33220 80241D40 0200202D */  daddu     $a0, $s0, $zero
/* C33224 80241D44 0260282D */  daddu     $a1, $s3, $zero
/* C33228 80241D48 0000382D */  daddu     $a3, $zero, $zero
/* C3322C 80241D4C 3C0642A0 */  lui       $a2, 0x42a0
/* C33230 80241D50 0040802D */  daddu     $s0, $v0, $zero
/* C33234 80241D54 0C01242D */  jal       func_800490B4
/* C33238 80241D58 AFA00010 */   sw       $zero, 0x10($sp)
/* C3323C 80241D5C 10400022 */  beqz      $v0, .L80241DE8
/* C33240 80241D60 00000000 */   nop      
/* C33244 80241D64 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C33248 80241D68 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3324C 80241D6C 804300B4 */  lb        $v1, 0xb4($v0)
/* C33250 80241D70 24020002 */  addiu     $v0, $zero, 2
/* C33254 80241D74 10620013 */  beq       $v1, $v0, .L80241DC4
/* C33258 80241D78 2402001A */   addiu    $v0, $zero, 0x1a
/* C3325C 80241D7C 10620011 */  beq       $v1, $v0, .L80241DC4
/* C33260 80241D80 24020003 */   addiu    $v0, $zero, 3
/* C33264 80241D84 1062000F */  beq       $v1, $v0, .L80241DC4
/* C33268 80241D88 2402000E */   addiu    $v0, $zero, 0xe
/* C3326C 80241D8C 1062000D */  beq       $v1, $v0, .L80241DC4
/* C33270 80241D90 24020010 */   addiu    $v0, $zero, 0x10
/* C33274 80241D94 1062000B */  beq       $v1, $v0, .L80241DC4
/* C33278 80241D98 2402000B */   addiu    $v0, $zero, 0xb
/* C3327C 80241D9C 10620009 */  beq       $v1, $v0, .L80241DC4
/* C33280 80241DA0 2402000A */   addiu    $v0, $zero, 0xa
/* C33284 80241DA4 10620007 */  beq       $v1, $v0, .L80241DC4
/* C33288 80241DA8 24020012 */   addiu    $v0, $zero, 0x12
/* C3328C 80241DAC 10620005 */  beq       $v1, $v0, .L80241DC4
/* C33290 80241DB0 24020013 */   addiu    $v0, $zero, 0x13
/* C33294 80241DB4 10620003 */  beq       $v1, $v0, .L80241DC4
/* C33298 80241DB8 24020025 */   addiu    $v0, $zero, 0x25
/* C3329C 80241DBC 14620002 */  bne       $v1, $v0, .L80241DC8
/* C332A0 80241DC0 00000000 */   nop      
.L80241DC4:
/* C332A4 80241DC4 24120001 */  addiu     $s2, $zero, 1
.L80241DC8:
/* C332A8 80241DC8 82030012 */  lb        $v1, 0x12($s0)
/* C332AC 80241DCC 24020002 */  addiu     $v0, $zero, 2
/* C332B0 80241DD0 14620007 */  bne       $v1, $v0, .L80241DF0
/* C332B4 80241DD4 24020001 */   addiu    $v0, $zero, 1
/* C332B8 80241DD8 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C332BC 80241DDC 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C332C0 80241DE0 50430002 */  beql      $v0, $v1, .L80241DEC
/* C332C4 80241DE4 24120001 */   addiu    $s2, $zero, 1
.L80241DE8:
/* C332C8 80241DE8 82030012 */  lb        $v1, 0x12($s0)
.L80241DEC:
/* C332CC 80241DEC 24020001 */  addiu     $v0, $zero, 1
.L80241DF0:
/* C332D0 80241DF0 14620006 */  bne       $v1, $v0, .L80241E0C
/* C332D4 80241DF4 24020003 */   addiu    $v0, $zero, 3
/* C332D8 80241DF8 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C332DC 80241DFC 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C332E0 80241E00 14400008 */  bnez      $v0, .L80241E24
/* C332E4 80241E04 27A40028 */   addiu    $a0, $sp, 0x28
/* C332E8 80241E08 24020003 */  addiu     $v0, $zero, 3
.L80241E0C:
/* C332EC 80241E0C 1462001B */  bne       $v1, $v0, .L80241E7C
/* C332F0 80241E10 24020002 */   addiu    $v0, $zero, 2
/* C332F4 80241E14 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C332F8 80241E18 8063EBB0 */  lb        $v1, %lo(D_8010EBB0)($v1)
/* C332FC 80241E1C 14620017 */  bne       $v1, $v0, .L80241E7C
/* C33300 80241E20 27A40028 */   addiu    $a0, $sp, 0x28
.L80241E24:
/* C33304 80241E24 27A5002C */  addiu     $a1, $sp, 0x2c
/* C33308 80241E28 8E27000C */  lw        $a3, 0xc($s1)
/* C3330C 80241E2C C6200038 */  lwc1      $f0, 0x38($s1)
/* C33310 80241E30 C6220040 */  lwc1      $f2, 0x40($s1)
/* C33314 80241E34 0000302D */  daddu     $a2, $zero, $zero
/* C33318 80241E38 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3331C 80241E3C 0C00A7E7 */  jal       add_vec2D_polar
/* C33320 80241E40 E7A2002C */   swc1     $f2, 0x2c($sp)
/* C33324 80241E44 3C028011 */  lui       $v0, %hi(D_8010C930)
/* C33328 80241E48 8C42C930 */  lw        $v0, %lo(D_8010C930)($v0)
/* C3332C 80241E4C C7AC0028 */  lwc1      $f12, 0x28($sp)
/* C33330 80241E50 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* C33334 80241E54 8C460038 */  lw        $a2, 0x38($v0)
/* C33338 80241E58 0C00A7B5 */  jal       dist2D
/* C3333C 80241E5C 8C470040 */   lw       $a3, 0x40($v0)
/* C33340 80241E60 3C0142A0 */  lui       $at, 0x42a0
/* C33344 80241E64 44811000 */  mtc1      $at, $f2
/* C33348 80241E68 00000000 */  nop       
/* C3334C 80241E6C 4602003E */  c.le.s    $f0, $f2
/* C33350 80241E70 00000000 */  nop       
/* C33354 80241E74 45030001 */  bc1tl     .L80241E7C
/* C33358 80241E78 24120001 */   addiu    $s2, $zero, 1
.L80241E7C:
/* C3335C 80241E7C 12400026 */  beqz      $s2, .L80241F18
/* C33360 80241E80 0220202D */   daddu    $a0, $s1, $zero
/* C33364 80241E84 3C05B000 */  lui       $a1, 0xb000
/* C33368 80241E88 34A5000E */  ori       $a1, $a1, 0xe
/* C3336C 80241E8C 0C012530 */  jal       func_800494C0
/* C33370 80241E90 0000302D */   daddu    $a2, $zero, $zero
/* C33374 80241E94 0000202D */  daddu     $a0, $zero, $zero
/* C33378 80241E98 0220282D */  daddu     $a1, $s1, $zero
/* C3337C 80241E9C 0000302D */  daddu     $a2, $zero, $zero
/* C33380 80241EA0 862200A8 */  lh        $v0, 0xa8($s1)
/* C33384 80241EA4 8E6300CC */  lw        $v1, 0xcc($s3)
/* C33388 80241EA8 3C013F80 */  lui       $at, 0x3f80
/* C3338C 80241EAC 44810000 */  mtc1      $at, $f0
/* C33390 80241EB0 3C014000 */  lui       $at, 0x4000
/* C33394 80241EB4 44811000 */  mtc1      $at, $f2
/* C33398 80241EB8 3C01C1A0 */  lui       $at, 0xc1a0
/* C3339C 80241EBC 44812000 */  mtc1      $at, $f4
/* C333A0 80241EC0 44823000 */  mtc1      $v0, $f6
/* C333A4 80241EC4 00000000 */  nop       
/* C333A8 80241EC8 468031A0 */  cvt.s.w   $f6, $f6
/* C333AC 80241ECC 44073000 */  mfc1      $a3, $f6
/* C333B0 80241ED0 8C63002C */  lw        $v1, 0x2c($v1)
/* C333B4 80241ED4 2402000A */  addiu     $v0, $zero, 0xa
/* C333B8 80241ED8 A622008E */  sh        $v0, 0x8e($s1)
/* C333BC 80241EDC 2402000F */  addiu     $v0, $zero, 0xf
/* C333C0 80241EE0 AE230028 */  sw        $v1, 0x28($s1)
/* C333C4 80241EE4 AFA2001C */  sw        $v0, 0x1c($sp)
/* C333C8 80241EE8 27A20030 */  addiu     $v0, $sp, 0x30
/* C333CC 80241EEC E7A00010 */  swc1      $f0, 0x10($sp)
/* C333D0 80241EF0 E7A20014 */  swc1      $f2, 0x14($sp)
/* C333D4 80241EF4 E7A40018 */  swc1      $f4, 0x18($sp)
/* C333D8 80241EF8 0C01BFA4 */  jal       fx_emote
/* C333DC 80241EFC AFA20020 */   sw       $v0, 0x20($sp)
/* C333E0 80241F00 0220202D */  daddu     $a0, $s1, $zero
/* C333E4 80241F04 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C333E8 80241F08 0C012530 */  jal       func_800494C0
/* C333EC 80241F0C 3C060020 */   lui      $a2, 0x20
/* C333F0 80241F10 24020002 */  addiu     $v0, $zero, 2
/* C333F4 80241F14 AE820070 */  sw        $v0, 0x70($s4)
.L80241F18:
/* C333F8 80241F18 9622008E */  lhu       $v0, 0x8e($s1)
/* C333FC 80241F1C 24420001 */  addiu     $v0, $v0, 1
/* C33400 80241F20 A622008E */  sh        $v0, 0x8e($s1)
/* C33404 80241F24 00021400 */  sll       $v0, $v0, 0x10
/* C33408 80241F28 00021C03 */  sra       $v1, $v0, 0x10
/* C3340C 80241F2C 2402001B */  addiu     $v0, $zero, 0x1b
/* C33410 80241F30 14620005 */  bne       $v1, $v0, .L80241F48
/* C33414 80241F34 24020039 */   addiu    $v0, $zero, 0x39
/* C33418 80241F38 0220202D */  daddu     $a0, $s1, $zero
/* C3341C 80241F3C 3C05B000 */  lui       $a1, 0xb000
/* C33420 80241F40 080907D7 */  j         .L80241F5C
/* C33424 80241F44 34A5000C */   ori      $a1, $a1, 0xc
.L80241F48:
/* C33428 80241F48 14620008 */  bne       $v1, $v0, .L80241F6C
/* C3342C 80241F4C 2402003B */   addiu    $v0, $zero, 0x3b
/* C33430 80241F50 0220202D */  daddu     $a0, $s1, $zero
/* C33434 80241F54 3C05B000 */  lui       $a1, 0xb000
/* C33438 80241F58 34A5000D */  ori       $a1, $a1, 0xd
.L80241F5C:
/* C3343C 80241F5C 0C012530 */  jal       func_800494C0
/* C33440 80241F60 0000302D */   daddu    $a2, $zero, $zero
/* C33444 80241F64 080907E7 */  j         .L80241F9C
/* C33448 80241F68 00000000 */   nop      
.L80241F6C:
/* C3344C 80241F6C 14620005 */  bne       $v1, $v0, .L80241F84
/* C33450 80241F70 2402003C */   addiu    $v0, $zero, 0x3c
/* C33454 80241F74 8E6200CC */  lw        $v0, 0xcc($s3)
/* C33458 80241F78 8C420030 */  lw        $v0, 0x30($v0)
/* C3345C 80241F7C 080907E7 */  j         .L80241F9C
/* C33460 80241F80 AE220028 */   sw       $v0, 0x28($s1)
.L80241F84:
/* C33464 80241F84 14620005 */  bne       $v1, $v0, .L80241F9C
/* C33468 80241F88 00000000 */   nop      
/* C3346C 80241F8C 8E6200CC */  lw        $v0, 0xcc($s3)
/* C33470 80241F90 8C420028 */  lw        $v0, 0x28($v0)
/* C33474 80241F94 A620008E */  sh        $zero, 0x8e($s1)
/* C33478 80241F98 AE220028 */  sw        $v0, 0x28($s1)
.L80241F9C:
/* C3347C 80241F9C 8FBF004C */  lw        $ra, 0x4c($sp)
/* C33480 80241FA0 8FB40048 */  lw        $s4, 0x48($sp)
/* C33484 80241FA4 8FB30044 */  lw        $s3, 0x44($sp)
/* C33488 80241FA8 8FB20040 */  lw        $s2, 0x40($sp)
/* C3348C 80241FAC 8FB1003C */  lw        $s1, 0x3c($sp)
/* C33490 80241FB0 8FB00038 */  lw        $s0, 0x38($sp)
/* C33494 80241FB4 03E00008 */  jr        $ra
/* C33498 80241FB8 27BD0050 */   addiu    $sp, $sp, 0x50
