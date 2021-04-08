.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_05_UnkFunc7
/* B4C6F8 80241C88 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B4C6FC 80241C8C AFB40028 */  sw        $s4, 0x28($sp)
/* B4C700 80241C90 0080A02D */  daddu     $s4, $a0, $zero
/* B4C704 80241C94 AFBF002C */  sw        $ra, 0x2c($sp)
/* B4C708 80241C98 AFB30024 */  sw        $s3, 0x24($sp)
/* B4C70C 80241C9C AFB20020 */  sw        $s2, 0x20($sp)
/* B4C710 80241CA0 AFB1001C */  sw        $s1, 0x1c($sp)
/* B4C714 80241CA4 AFB00018 */  sw        $s0, 0x18($sp)
/* B4C718 80241CA8 8E910148 */  lw        $s1, 0x148($s4)
/* B4C71C 80241CAC 86240008 */  lh        $a0, 8($s1)
/* B4C720 80241CB0 0C00EABB */  jal       get_npc_unsafe
/* B4C724 80241CB4 00A0802D */   daddu    $s0, $a1, $zero
/* B4C728 80241CB8 16000005 */  bnez      $s0, .L80241CD0
/* B4C72C 80241CBC 0040902D */   daddu    $s2, $v0, $zero
/* B4C730 80241CC0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B4C734 80241CC4 30420004 */  andi      $v0, $v0, 4
/* B4C738 80241CC8 10400015 */  beqz      $v0, .L80241D20
/* B4C73C 80241CCC 00000000 */   nop
.L80241CD0:
/* B4C740 80241CD0 AE800070 */  sw        $zero, 0x70($s4)
/* B4C744 80241CD4 8E420000 */  lw        $v0, ($s2)
/* B4C748 80241CD8 3C031F30 */  lui       $v1, 0x1f30
/* B4C74C 80241CDC A640008E */  sh        $zero, 0x8e($s2)
/* B4C750 80241CE0 34420102 */  ori       $v0, $v0, 0x102
/* B4C754 80241CE4 AE420000 */  sw        $v0, ($s2)
/* B4C758 80241CE8 8E220000 */  lw        $v0, ($s1)
/* B4C75C 80241CEC 3C01C47A */  lui       $at, 0xc47a
/* B4C760 80241CF0 44810000 */  mtc1      $at, $f0
/* B4C764 80241CF4 00431025 */  or        $v0, $v0, $v1
/* B4C768 80241CF8 AE220000 */  sw        $v0, ($s1)
/* B4C76C 80241CFC AE400038 */  sw        $zero, 0x38($s2)
/* B4C770 80241D00 E640003C */  swc1      $f0, 0x3c($s2)
/* B4C774 80241D04 AE400040 */  sw        $zero, 0x40($s2)
/* B4C778 80241D08 8E2300B0 */  lw        $v1, 0xb0($s1)
/* B4C77C 80241D0C 30620004 */  andi      $v0, $v1, 4
/* B4C780 80241D10 10400003 */  beqz      $v0, .L80241D20
/* B4C784 80241D14 2402FFFB */   addiu    $v0, $zero, -5
/* B4C788 80241D18 00621024 */  and       $v0, $v1, $v0
/* B4C78C 80241D1C AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241D20:
/* B4C790 80241D20 8E930070 */  lw        $s3, 0x70($s4)
/* B4C794 80241D24 12600005 */  beqz      $s3, .L80241D3C
/* B4C798 80241D28 24020001 */   addiu    $v0, $zero, 1
/* B4C79C 80241D2C 12620048 */  beq       $s3, $v0, .L80241E50
/* B4C7A0 80241D30 00000000 */   nop
/* B4C7A4 80241D34 080907B1 */  j         .L80241EC4
/* B4C7A8 80241D38 00000000 */   nop
.L80241D3C:
/* B4C7AC 80241D3C 86240008 */  lh        $a0, 8($s1)
/* B4C7B0 80241D40 0C00FB3A */  jal       get_enemy
/* B4C7B4 80241D44 2484FFFF */   addiu    $a0, $a0, -1
/* B4C7B8 80241D48 0040802D */  daddu     $s0, $v0, $zero
/* B4C7BC 80241D4C 0C00EABB */  jal       get_npc_unsafe
/* B4C7C0 80241D50 86040008 */   lh       $a0, 8($s0)
/* B4C7C4 80241D54 24030001 */  addiu     $v1, $zero, 1
/* B4C7C8 80241D58 0040982D */  daddu     $s3, $v0, $zero
/* B4C7CC 80241D5C A2230007 */  sb        $v1, 7($s1)
/* B4C7D0 80241D60 8E03006C */  lw        $v1, 0x6c($s0)
/* B4C7D4 80241D64 24020003 */  addiu     $v0, $zero, 3
/* B4C7D8 80241D68 14620056 */  bne       $v1, $v0, .L80241EC4
/* B4C7DC 80241D6C 00000000 */   nop
/* B4C7E0 80241D70 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B4C7E4 80241D74 10A00003 */  beqz      $a1, .L80241D84
/* B4C7E8 80241D78 0260202D */   daddu    $a0, $s3, $zero
/* B4C7EC 80241D7C 0C012530 */  jal       func_800494C0
/* B4C7F0 80241D80 0000302D */   daddu    $a2, $zero, $zero
.L80241D84:
/* B4C7F4 80241D84 27A40010 */  addiu     $a0, $sp, 0x10
/* B4C7F8 80241D88 C6280070 */  lwc1      $f8, 0x70($s1)
/* B4C7FC 80241D8C 46804220 */  cvt.s.w   $f8, $f8
/* B4C800 80241D90 C6620034 */  lwc1      $f2, 0x34($s3)
/* B4C804 80241D94 3C014387 */  lui       $at, 0x4387
/* B4C808 80241D98 44810000 */  mtc1      $at, $f0
/* B4C80C 80241D9C 44064000 */  mfc1      $a2, $f8
/* B4C810 80241DA0 46020001 */  sub.s     $f0, $f0, $f2
/* B4C814 80241DA4 C6660038 */  lwc1      $f6, 0x38($s3)
/* B4C818 80241DA8 C6640040 */  lwc1      $f4, 0x40($s3)
/* B4C81C 80241DAC 44070000 */  mfc1      $a3, $f0
/* B4C820 80241DB0 27A50014 */  addiu     $a1, $sp, 0x14
/* B4C824 80241DB4 E7A60010 */  swc1      $f6, 0x10($sp)
/* B4C828 80241DB8 0C00A7E7 */  jal       add_vec2D_polar
/* B4C82C 80241DBC E7A40014 */   swc1     $f4, 0x14($sp)
/* B4C830 80241DC0 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B4C834 80241DC4 4600020D */  trunc.w.s $f8, $f0
/* B4C838 80241DC8 44024000 */  mfc1      $v0, $f8
/* B4C83C 80241DCC E6400038 */  swc1      $f0, 0x38($s2)
/* B4C840 80241DD0 A6220010 */  sh        $v0, 0x10($s1)
/* B4C844 80241DD4 C660003C */  lwc1      $f0, 0x3c($s3)
/* B4C848 80241DD8 C622006C */  lwc1      $f2, 0x6c($s1)
/* B4C84C 80241DDC 468010A0 */  cvt.s.w   $f2, $f2
/* B4C850 80241DE0 46020000 */  add.s     $f0, $f0, $f2
/* B4C854 80241DE4 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* B4C858 80241DE8 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* B4C85C 80241DEC E640003C */  swc1      $f0, 0x3c($s2)
/* B4C860 80241DF0 C7A20014 */  lwc1      $f2, 0x14($sp)
/* B4C864 80241DF4 4600020D */  trunc.w.s $f8, $f0
/* B4C868 80241DF8 44024000 */  mfc1      $v0, $f8
/* B4C86C 80241DFC 00000000 */  nop
/* B4C870 80241E00 A6220012 */  sh        $v0, 0x12($s1)
/* B4C874 80241E04 4600120D */  trunc.w.s $f8, $f2
/* B4C878 80241E08 44024000 */  mfc1      $v0, $f8
/* B4C87C 80241E0C E6420040 */  swc1      $f2, 0x40($s2)
/* B4C880 80241E10 A6220014 */  sh        $v0, 0x14($s1)
/* B4C884 80241E14 8C660028 */  lw        $a2, 0x28($v1)
/* B4C888 80241E18 8C670030 */  lw        $a3, 0x30($v1)
/* B4C88C 80241E1C C64C0038 */  lwc1      $f12, 0x38($s2)
/* B4C890 80241E20 0C00A720 */  jal       atan2
/* B4C894 80241E24 C64E0040 */   lwc1     $f14, 0x40($s2)
/* B4C898 80241E28 3C03E0EF */  lui       $v1, 0xe0ef
/* B4C89C 80241E2C E640000C */  swc1      $f0, 0xc($s2)
/* B4C8A0 80241E30 8E220000 */  lw        $v0, ($s1)
/* B4C8A4 80241E34 3463FFFF */  ori       $v1, $v1, 0xffff
/* B4C8A8 80241E38 00431024 */  and       $v0, $v0, $v1
/* B4C8AC 80241E3C AE220000 */  sw        $v0, ($s1)
/* B4C8B0 80241E40 24020001 */  addiu     $v0, $zero, 1
/* B4C8B4 80241E44 A640008E */  sh        $zero, 0x8e($s2)
/* B4C8B8 80241E48 080907B1 */  j         .L80241EC4
/* B4C8BC 80241E4C AE820070 */   sw       $v0, 0x70($s4)
.L80241E50:
/* B4C8C0 80241E50 86240008 */  lh        $a0, 8($s1)
/* B4C8C4 80241E54 0C00FB3A */  jal       get_enemy
/* B4C8C8 80241E58 2484FFFF */   addiu    $a0, $a0, -1
/* B4C8CC 80241E5C 0040802D */  daddu     $s0, $v0, $zero
/* B4C8D0 80241E60 0C00EABB */  jal       get_npc_unsafe
/* B4C8D4 80241E64 86040008 */   lh       $a0, 8($s0)
/* B4C8D8 80241E68 9642008E */  lhu       $v0, 0x8e($s2)
/* B4C8DC 80241E6C 24420001 */  addiu     $v0, $v0, 1
/* B4C8E0 80241E70 A642008E */  sh        $v0, 0x8e($s2)
/* B4C8E4 80241E74 00021400 */  sll       $v0, $v0, 0x10
/* B4C8E8 80241E78 8E23007C */  lw        $v1, 0x7c($s1)
/* B4C8EC 80241E7C 00021403 */  sra       $v0, $v0, 0x10
/* B4C8F0 80241E80 0043102A */  slt       $v0, $v0, $v1
/* B4C8F4 80241E84 50400001 */  beql      $v0, $zero, .L80241E8C
/* B4C8F8 80241E88 A2200007 */   sb       $zero, 7($s1)
.L80241E8C:
/* B4C8FC 80241E8C 8E03006C */  lw        $v1, 0x6c($s0)
/* B4C900 80241E90 24020004 */  addiu     $v0, $zero, 4
/* B4C904 80241E94 1462000B */  bne       $v1, $v0, .L80241EC4
/* B4C908 80241E98 3C021F10 */   lui      $v0, 0x1f10
/* B4C90C 80241E9C 8E230000 */  lw        $v1, ($s1)
/* B4C910 80241EA0 3C01C47A */  lui       $at, 0xc47a
/* B4C914 80241EA4 44810000 */  mtc1      $at, $f0
/* B4C918 80241EA8 00621825 */  or        $v1, $v1, $v0
/* B4C91C 80241EAC AE230000 */  sw        $v1, ($s1)
/* B4C920 80241EB0 AE400038 */  sw        $zero, 0x38($s2)
/* B4C924 80241EB4 E640003C */  swc1      $f0, 0x3c($s2)
/* B4C928 80241EB8 AE400040 */  sw        $zero, 0x40($s2)
/* B4C92C 80241EBC A2330007 */  sb        $s3, 7($s1)
/* B4C930 80241EC0 AE800070 */  sw        $zero, 0x70($s4)
.L80241EC4:
/* B4C934 80241EC4 8FBF002C */  lw        $ra, 0x2c($sp)
/* B4C938 80241EC8 8FB40028 */  lw        $s4, 0x28($sp)
/* B4C93C 80241ECC 8FB30024 */  lw        $s3, 0x24($sp)
/* B4C940 80241ED0 8FB20020 */  lw        $s2, 0x20($sp)
/* B4C944 80241ED4 8FB1001C */  lw        $s1, 0x1c($sp)
/* B4C948 80241ED8 8FB00018 */  lw        $s0, 0x18($sp)
/* B4C94C 80241EDC 0000102D */  daddu     $v0, $zero, $zero
/* B4C950 80241EE0 03E00008 */  jr        $ra
/* B4C954 80241EE4 27BD0030 */   addiu    $sp, $sp, 0x30
