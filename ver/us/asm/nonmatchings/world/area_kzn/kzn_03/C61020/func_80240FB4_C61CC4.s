.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_03_UnkFunc7
/* C61CC4 80240FB4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C61CC8 80240FB8 AFB40028 */  sw        $s4, 0x28($sp)
/* C61CCC 80240FBC 0080A02D */  daddu     $s4, $a0, $zero
/* C61CD0 80240FC0 AFBF002C */  sw        $ra, 0x2c($sp)
/* C61CD4 80240FC4 AFB30024 */  sw        $s3, 0x24($sp)
/* C61CD8 80240FC8 AFB20020 */  sw        $s2, 0x20($sp)
/* C61CDC 80240FCC AFB1001C */  sw        $s1, 0x1c($sp)
/* C61CE0 80240FD0 AFB00018 */  sw        $s0, 0x18($sp)
/* C61CE4 80240FD4 8E910148 */  lw        $s1, 0x148($s4)
/* C61CE8 80240FD8 86240008 */  lh        $a0, 8($s1)
/* C61CEC 80240FDC 0C00EABB */  jal       get_npc_unsafe
/* C61CF0 80240FE0 00A0802D */   daddu    $s0, $a1, $zero
/* C61CF4 80240FE4 16000005 */  bnez      $s0, .L80240FFC
/* C61CF8 80240FE8 0040902D */   daddu    $s2, $v0, $zero
/* C61CFC 80240FEC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C61D00 80240FF0 30420004 */  andi      $v0, $v0, 4
/* C61D04 80240FF4 10400015 */  beqz      $v0, .L8024104C
/* C61D08 80240FF8 00000000 */   nop
.L80240FFC:
/* C61D0C 80240FFC AE800070 */  sw        $zero, 0x70($s4)
/* C61D10 80241000 8E420000 */  lw        $v0, ($s2)
/* C61D14 80241004 3C031F30 */  lui       $v1, 0x1f30
/* C61D18 80241008 A640008E */  sh        $zero, 0x8e($s2)
/* C61D1C 8024100C 34420102 */  ori       $v0, $v0, 0x102
/* C61D20 80241010 AE420000 */  sw        $v0, ($s2)
/* C61D24 80241014 8E220000 */  lw        $v0, ($s1)
/* C61D28 80241018 3C01C47A */  lui       $at, 0xc47a
/* C61D2C 8024101C 44810000 */  mtc1      $at, $f0
/* C61D30 80241020 00431025 */  or        $v0, $v0, $v1
/* C61D34 80241024 AE220000 */  sw        $v0, ($s1)
/* C61D38 80241028 AE400038 */  sw        $zero, 0x38($s2)
/* C61D3C 8024102C E640003C */  swc1      $f0, 0x3c($s2)
/* C61D40 80241030 AE400040 */  sw        $zero, 0x40($s2)
/* C61D44 80241034 8E2300B0 */  lw        $v1, 0xb0($s1)
/* C61D48 80241038 30620004 */  andi      $v0, $v1, 4
/* C61D4C 8024103C 10400003 */  beqz      $v0, .L8024104C
/* C61D50 80241040 2402FFFB */   addiu    $v0, $zero, -5
/* C61D54 80241044 00621024 */  and       $v0, $v1, $v0
/* C61D58 80241048 AE2200B0 */  sw        $v0, 0xb0($s1)
.L8024104C:
/* C61D5C 8024104C 8E930070 */  lw        $s3, 0x70($s4)
/* C61D60 80241050 12600005 */  beqz      $s3, .L80241068
/* C61D64 80241054 24020001 */   addiu    $v0, $zero, 1
/* C61D68 80241058 12620048 */  beq       $s3, $v0, .L8024117C
/* C61D6C 8024105C 00000000 */   nop
/* C61D70 80241060 0809047C */  j         .L802411F0
/* C61D74 80241064 00000000 */   nop
.L80241068:
/* C61D78 80241068 86240008 */  lh        $a0, 8($s1)
/* C61D7C 8024106C 0C00FB3A */  jal       get_enemy
/* C61D80 80241070 2484FFFF */   addiu    $a0, $a0, -1
/* C61D84 80241074 0040802D */  daddu     $s0, $v0, $zero
/* C61D88 80241078 0C00EABB */  jal       get_npc_unsafe
/* C61D8C 8024107C 86040008 */   lh       $a0, 8($s0)
/* C61D90 80241080 24030001 */  addiu     $v1, $zero, 1
/* C61D94 80241084 0040982D */  daddu     $s3, $v0, $zero
/* C61D98 80241088 A2230007 */  sb        $v1, 7($s1)
/* C61D9C 8024108C 8E03006C */  lw        $v1, 0x6c($s0)
/* C61DA0 80241090 24020003 */  addiu     $v0, $zero, 3
/* C61DA4 80241094 14620056 */  bne       $v1, $v0, .L802411F0
/* C61DA8 80241098 00000000 */   nop
/* C61DAC 8024109C 8E2500A8 */  lw        $a1, 0xa8($s1)
/* C61DB0 802410A0 10A00003 */  beqz      $a1, .L802410B0
/* C61DB4 802410A4 0260202D */   daddu    $a0, $s3, $zero
/* C61DB8 802410A8 0C012530 */  jal       func_800494C0
/* C61DBC 802410AC 0000302D */   daddu    $a2, $zero, $zero
.L802410B0:
/* C61DC0 802410B0 27A40010 */  addiu     $a0, $sp, 0x10
/* C61DC4 802410B4 C6280070 */  lwc1      $f8, 0x70($s1)
/* C61DC8 802410B8 46804220 */  cvt.s.w   $f8, $f8
/* C61DCC 802410BC C6620034 */  lwc1      $f2, 0x34($s3)
/* C61DD0 802410C0 3C014387 */  lui       $at, 0x4387
/* C61DD4 802410C4 44810000 */  mtc1      $at, $f0
/* C61DD8 802410C8 44064000 */  mfc1      $a2, $f8
/* C61DDC 802410CC 46020001 */  sub.s     $f0, $f0, $f2
/* C61DE0 802410D0 C6660038 */  lwc1      $f6, 0x38($s3)
/* C61DE4 802410D4 C6640040 */  lwc1      $f4, 0x40($s3)
/* C61DE8 802410D8 44070000 */  mfc1      $a3, $f0
/* C61DEC 802410DC 27A50014 */  addiu     $a1, $sp, 0x14
/* C61DF0 802410E0 E7A60010 */  swc1      $f6, 0x10($sp)
/* C61DF4 802410E4 0C00A7E7 */  jal       add_vec2D_polar
/* C61DF8 802410E8 E7A40014 */   swc1     $f4, 0x14($sp)
/* C61DFC 802410EC C7A00010 */  lwc1      $f0, 0x10($sp)
/* C61E00 802410F0 4600020D */  trunc.w.s $f8, $f0
/* C61E04 802410F4 44024000 */  mfc1      $v0, $f8
/* C61E08 802410F8 E6400038 */  swc1      $f0, 0x38($s2)
/* C61E0C 802410FC A6220010 */  sh        $v0, 0x10($s1)
/* C61E10 80241100 C660003C */  lwc1      $f0, 0x3c($s3)
/* C61E14 80241104 C622006C */  lwc1      $f2, 0x6c($s1)
/* C61E18 80241108 468010A0 */  cvt.s.w   $f2, $f2
/* C61E1C 8024110C 46020000 */  add.s     $f0, $f0, $f2
/* C61E20 80241110 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C61E24 80241114 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C61E28 80241118 E640003C */  swc1      $f0, 0x3c($s2)
/* C61E2C 8024111C C7A20014 */  lwc1      $f2, 0x14($sp)
/* C61E30 80241120 4600020D */  trunc.w.s $f8, $f0
/* C61E34 80241124 44024000 */  mfc1      $v0, $f8
/* C61E38 80241128 00000000 */  nop
/* C61E3C 8024112C A6220012 */  sh        $v0, 0x12($s1)
/* C61E40 80241130 4600120D */  trunc.w.s $f8, $f2
/* C61E44 80241134 44024000 */  mfc1      $v0, $f8
/* C61E48 80241138 E6420040 */  swc1      $f2, 0x40($s2)
/* C61E4C 8024113C A6220014 */  sh        $v0, 0x14($s1)
/* C61E50 80241140 8C660028 */  lw        $a2, 0x28($v1)
/* C61E54 80241144 8C670030 */  lw        $a3, 0x30($v1)
/* C61E58 80241148 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C61E5C 8024114C 0C00A720 */  jal       atan2
/* C61E60 80241150 C64E0040 */   lwc1     $f14, 0x40($s2)
/* C61E64 80241154 3C03E0EF */  lui       $v1, 0xe0ef
/* C61E68 80241158 E640000C */  swc1      $f0, 0xc($s2)
/* C61E6C 8024115C 8E220000 */  lw        $v0, ($s1)
/* C61E70 80241160 3463FFFF */  ori       $v1, $v1, 0xffff
/* C61E74 80241164 00431024 */  and       $v0, $v0, $v1
/* C61E78 80241168 AE220000 */  sw        $v0, ($s1)
/* C61E7C 8024116C 24020001 */  addiu     $v0, $zero, 1
/* C61E80 80241170 A640008E */  sh        $zero, 0x8e($s2)
/* C61E84 80241174 0809047C */  j         .L802411F0
/* C61E88 80241178 AE820070 */   sw       $v0, 0x70($s4)
.L8024117C:
/* C61E8C 8024117C 86240008 */  lh        $a0, 8($s1)
/* C61E90 80241180 0C00FB3A */  jal       get_enemy
/* C61E94 80241184 2484FFFF */   addiu    $a0, $a0, -1
/* C61E98 80241188 0040802D */  daddu     $s0, $v0, $zero
/* C61E9C 8024118C 0C00EABB */  jal       get_npc_unsafe
/* C61EA0 80241190 86040008 */   lh       $a0, 8($s0)
/* C61EA4 80241194 9642008E */  lhu       $v0, 0x8e($s2)
/* C61EA8 80241198 24420001 */  addiu     $v0, $v0, 1
/* C61EAC 8024119C A642008E */  sh        $v0, 0x8e($s2)
/* C61EB0 802411A0 00021400 */  sll       $v0, $v0, 0x10
/* C61EB4 802411A4 8E23007C */  lw        $v1, 0x7c($s1)
/* C61EB8 802411A8 00021403 */  sra       $v0, $v0, 0x10
/* C61EBC 802411AC 0043102A */  slt       $v0, $v0, $v1
/* C61EC0 802411B0 50400001 */  beql      $v0, $zero, .L802411B8
/* C61EC4 802411B4 A2200007 */   sb       $zero, 7($s1)
.L802411B8:
/* C61EC8 802411B8 8E03006C */  lw        $v1, 0x6c($s0)
/* C61ECC 802411BC 24020004 */  addiu     $v0, $zero, 4
/* C61ED0 802411C0 1462000B */  bne       $v1, $v0, .L802411F0
/* C61ED4 802411C4 3C021F10 */   lui      $v0, 0x1f10
/* C61ED8 802411C8 8E230000 */  lw        $v1, ($s1)
/* C61EDC 802411CC 3C01C47A */  lui       $at, 0xc47a
/* C61EE0 802411D0 44810000 */  mtc1      $at, $f0
/* C61EE4 802411D4 00621825 */  or        $v1, $v1, $v0
/* C61EE8 802411D8 AE230000 */  sw        $v1, ($s1)
/* C61EEC 802411DC AE400038 */  sw        $zero, 0x38($s2)
/* C61EF0 802411E0 E640003C */  swc1      $f0, 0x3c($s2)
/* C61EF4 802411E4 AE400040 */  sw        $zero, 0x40($s2)
/* C61EF8 802411E8 A2330007 */  sb        $s3, 7($s1)
/* C61EFC 802411EC AE800070 */  sw        $zero, 0x70($s4)
.L802411F0:
/* C61F00 802411F0 8FBF002C */  lw        $ra, 0x2c($sp)
/* C61F04 802411F4 8FB40028 */  lw        $s4, 0x28($sp)
/* C61F08 802411F8 8FB30024 */  lw        $s3, 0x24($sp)
/* C61F0C 802411FC 8FB20020 */  lw        $s2, 0x20($sp)
/* C61F10 80241200 8FB1001C */  lw        $s1, 0x1c($sp)
/* C61F14 80241204 8FB00018 */  lw        $s0, 0x18($sp)
/* C61F18 80241208 0000102D */  daddu     $v0, $zero, $zero
/* C61F1C 8024120C 03E00008 */  jr        $ra
/* C61F20 80241210 27BD0030 */   addiu    $sp, $sp, 0x30
