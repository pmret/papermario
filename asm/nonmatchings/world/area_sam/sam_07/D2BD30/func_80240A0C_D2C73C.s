.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A0C_D2C73C
/* D2C73C 80240A0C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D2C740 80240A10 AFB40028 */  sw        $s4, 0x28($sp)
/* D2C744 80240A14 0080A02D */  daddu     $s4, $a0, $zero
/* D2C748 80240A18 AFBF002C */  sw        $ra, 0x2c($sp)
/* D2C74C 80240A1C AFB30024 */  sw        $s3, 0x24($sp)
/* D2C750 80240A20 AFB20020 */  sw        $s2, 0x20($sp)
/* D2C754 80240A24 AFB1001C */  sw        $s1, 0x1c($sp)
/* D2C758 80240A28 AFB00018 */  sw        $s0, 0x18($sp)
/* D2C75C 80240A2C 8E910148 */  lw        $s1, 0x148($s4)
/* D2C760 80240A30 86240008 */  lh        $a0, 8($s1)
/* D2C764 80240A34 0C00EABB */  jal       get_npc_unsafe
/* D2C768 80240A38 00A0802D */   daddu    $s0, $a1, $zero
/* D2C76C 80240A3C 16000005 */  bnez      $s0, .L80240A54
/* D2C770 80240A40 0040902D */   daddu    $s2, $v0, $zero
/* D2C774 80240A44 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D2C778 80240A48 30420004 */  andi      $v0, $v0, 4
/* D2C77C 80240A4C 10400015 */  beqz      $v0, .L80240AA4
/* D2C780 80240A50 00000000 */   nop      
.L80240A54:
/* D2C784 80240A54 AE800070 */  sw        $zero, 0x70($s4)
/* D2C788 80240A58 8E420000 */  lw        $v0, ($s2)
/* D2C78C 80240A5C 3C031F30 */  lui       $v1, 0x1f30
/* D2C790 80240A60 A640008E */  sh        $zero, 0x8e($s2)
/* D2C794 80240A64 34420102 */  ori       $v0, $v0, 0x102
/* D2C798 80240A68 AE420000 */  sw        $v0, ($s2)
/* D2C79C 80240A6C 8E220000 */  lw        $v0, ($s1)
/* D2C7A0 80240A70 3C01C47A */  lui       $at, 0xc47a
/* D2C7A4 80240A74 44810000 */  mtc1      $at, $f0
/* D2C7A8 80240A78 00431025 */  or        $v0, $v0, $v1
/* D2C7AC 80240A7C AE220000 */  sw        $v0, ($s1)
/* D2C7B0 80240A80 AE400038 */  sw        $zero, 0x38($s2)
/* D2C7B4 80240A84 E640003C */  swc1      $f0, 0x3c($s2)
/* D2C7B8 80240A88 AE400040 */  sw        $zero, 0x40($s2)
/* D2C7BC 80240A8C 8E2300B0 */  lw        $v1, 0xb0($s1)
/* D2C7C0 80240A90 30620004 */  andi      $v0, $v1, 4
/* D2C7C4 80240A94 10400003 */  beqz      $v0, .L80240AA4
/* D2C7C8 80240A98 2402FFFB */   addiu    $v0, $zero, -5
/* D2C7CC 80240A9C 00621024 */  and       $v0, $v1, $v0
/* D2C7D0 80240AA0 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240AA4:
/* D2C7D4 80240AA4 8E930070 */  lw        $s3, 0x70($s4)
/* D2C7D8 80240AA8 12600005 */  beqz      $s3, .L80240AC0
/* D2C7DC 80240AAC 24020001 */   addiu    $v0, $zero, 1
/* D2C7E0 80240AB0 12620048 */  beq       $s3, $v0, .L80240BD4
/* D2C7E4 80240AB4 00000000 */   nop      
/* D2C7E8 80240AB8 08090312 */  j         .L80240C48
/* D2C7EC 80240ABC 00000000 */   nop      
.L80240AC0:
/* D2C7F0 80240AC0 86240008 */  lh        $a0, 8($s1)
/* D2C7F4 80240AC4 0C00FB3A */  jal       get_enemy
/* D2C7F8 80240AC8 2484FFFF */   addiu    $a0, $a0, -1
/* D2C7FC 80240ACC 0040802D */  daddu     $s0, $v0, $zero
/* D2C800 80240AD0 0C00EABB */  jal       get_npc_unsafe
/* D2C804 80240AD4 86040008 */   lh       $a0, 8($s0)
/* D2C808 80240AD8 24030001 */  addiu     $v1, $zero, 1
/* D2C80C 80240ADC 0040982D */  daddu     $s3, $v0, $zero
/* D2C810 80240AE0 A2230007 */  sb        $v1, 7($s1)
/* D2C814 80240AE4 8E03006C */  lw        $v1, 0x6c($s0)
/* D2C818 80240AE8 24020003 */  addiu     $v0, $zero, 3
/* D2C81C 80240AEC 14620056 */  bne       $v1, $v0, .L80240C48
/* D2C820 80240AF0 00000000 */   nop      
/* D2C824 80240AF4 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D2C828 80240AF8 10A00003 */  beqz      $a1, .L80240B08
/* D2C82C 80240AFC 0260202D */   daddu    $a0, $s3, $zero
/* D2C830 80240B00 0C012530 */  jal       func_800494C0
/* D2C834 80240B04 0000302D */   daddu    $a2, $zero, $zero
.L80240B08:
/* D2C838 80240B08 27A40010 */  addiu     $a0, $sp, 0x10
/* D2C83C 80240B0C C6280070 */  lwc1      $f8, 0x70($s1)
/* D2C840 80240B10 46804220 */  cvt.s.w   $f8, $f8
/* D2C844 80240B14 C6620034 */  lwc1      $f2, 0x34($s3)
/* D2C848 80240B18 3C014387 */  lui       $at, 0x4387
/* D2C84C 80240B1C 44810000 */  mtc1      $at, $f0
/* D2C850 80240B20 44064000 */  mfc1      $a2, $f8
/* D2C854 80240B24 46020001 */  sub.s     $f0, $f0, $f2
/* D2C858 80240B28 C6660038 */  lwc1      $f6, 0x38($s3)
/* D2C85C 80240B2C C6640040 */  lwc1      $f4, 0x40($s3)
/* D2C860 80240B30 44070000 */  mfc1      $a3, $f0
/* D2C864 80240B34 27A50014 */  addiu     $a1, $sp, 0x14
/* D2C868 80240B38 E7A60010 */  swc1      $f6, 0x10($sp)
/* D2C86C 80240B3C 0C00A7E7 */  jal       add_vec2D_polar
/* D2C870 80240B40 E7A40014 */   swc1     $f4, 0x14($sp)
/* D2C874 80240B44 C7A00010 */  lwc1      $f0, 0x10($sp)
/* D2C878 80240B48 4600020D */  trunc.w.s $f8, $f0
/* D2C87C 80240B4C 44024000 */  mfc1      $v0, $f8
/* D2C880 80240B50 E6400038 */  swc1      $f0, 0x38($s2)
/* D2C884 80240B54 A6220010 */  sh        $v0, 0x10($s1)
/* D2C888 80240B58 C660003C */  lwc1      $f0, 0x3c($s3)
/* D2C88C 80240B5C C622006C */  lwc1      $f2, 0x6c($s1)
/* D2C890 80240B60 468010A0 */  cvt.s.w   $f2, $f2
/* D2C894 80240B64 46020000 */  add.s     $f0, $f0, $f2
/* D2C898 80240B68 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* D2C89C 80240B6C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* D2C8A0 80240B70 E640003C */  swc1      $f0, 0x3c($s2)
/* D2C8A4 80240B74 C7A20014 */  lwc1      $f2, 0x14($sp)
/* D2C8A8 80240B78 4600020D */  trunc.w.s $f8, $f0
/* D2C8AC 80240B7C 44024000 */  mfc1      $v0, $f8
/* D2C8B0 80240B80 00000000 */  nop       
/* D2C8B4 80240B84 A6220012 */  sh        $v0, 0x12($s1)
/* D2C8B8 80240B88 4600120D */  trunc.w.s $f8, $f2
/* D2C8BC 80240B8C 44024000 */  mfc1      $v0, $f8
/* D2C8C0 80240B90 E6420040 */  swc1      $f2, 0x40($s2)
/* D2C8C4 80240B94 A6220014 */  sh        $v0, 0x14($s1)
/* D2C8C8 80240B98 8C660028 */  lw        $a2, 0x28($v1)
/* D2C8CC 80240B9C 8C670030 */  lw        $a3, 0x30($v1)
/* D2C8D0 80240BA0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* D2C8D4 80240BA4 0C00A720 */  jal       atan2
/* D2C8D8 80240BA8 C64E0040 */   lwc1     $f14, 0x40($s2)
/* D2C8DC 80240BAC 3C03E0EF */  lui       $v1, 0xe0ef
/* D2C8E0 80240BB0 E640000C */  swc1      $f0, 0xc($s2)
/* D2C8E4 80240BB4 8E220000 */  lw        $v0, ($s1)
/* D2C8E8 80240BB8 3463FFFF */  ori       $v1, $v1, 0xffff
/* D2C8EC 80240BBC 00431024 */  and       $v0, $v0, $v1
/* D2C8F0 80240BC0 AE220000 */  sw        $v0, ($s1)
/* D2C8F4 80240BC4 24020001 */  addiu     $v0, $zero, 1
/* D2C8F8 80240BC8 A640008E */  sh        $zero, 0x8e($s2)
/* D2C8FC 80240BCC 08090312 */  j         .L80240C48
/* D2C900 80240BD0 AE820070 */   sw       $v0, 0x70($s4)
.L80240BD4:
/* D2C904 80240BD4 86240008 */  lh        $a0, 8($s1)
/* D2C908 80240BD8 0C00FB3A */  jal       get_enemy
/* D2C90C 80240BDC 2484FFFF */   addiu    $a0, $a0, -1
/* D2C910 80240BE0 0040802D */  daddu     $s0, $v0, $zero
/* D2C914 80240BE4 0C00EABB */  jal       get_npc_unsafe
/* D2C918 80240BE8 86040008 */   lh       $a0, 8($s0)
/* D2C91C 80240BEC 9642008E */  lhu       $v0, 0x8e($s2)
/* D2C920 80240BF0 24420001 */  addiu     $v0, $v0, 1
/* D2C924 80240BF4 A642008E */  sh        $v0, 0x8e($s2)
/* D2C928 80240BF8 00021400 */  sll       $v0, $v0, 0x10
/* D2C92C 80240BFC 8E23007C */  lw        $v1, 0x7c($s1)
/* D2C930 80240C00 00021403 */  sra       $v0, $v0, 0x10
/* D2C934 80240C04 0043102A */  slt       $v0, $v0, $v1
/* D2C938 80240C08 50400001 */  beql      $v0, $zero, .L80240C10
/* D2C93C 80240C0C A2200007 */   sb       $zero, 7($s1)
.L80240C10:
/* D2C940 80240C10 8E03006C */  lw        $v1, 0x6c($s0)
/* D2C944 80240C14 24020004 */  addiu     $v0, $zero, 4
/* D2C948 80240C18 1462000B */  bne       $v1, $v0, .L80240C48
/* D2C94C 80240C1C 3C021F10 */   lui      $v0, 0x1f10
/* D2C950 80240C20 8E230000 */  lw        $v1, ($s1)
/* D2C954 80240C24 3C01C47A */  lui       $at, 0xc47a
/* D2C958 80240C28 44810000 */  mtc1      $at, $f0
/* D2C95C 80240C2C 00621825 */  or        $v1, $v1, $v0
/* D2C960 80240C30 AE230000 */  sw        $v1, ($s1)
/* D2C964 80240C34 AE400038 */  sw        $zero, 0x38($s2)
/* D2C968 80240C38 E640003C */  swc1      $f0, 0x3c($s2)
/* D2C96C 80240C3C AE400040 */  sw        $zero, 0x40($s2)
/* D2C970 80240C40 A2330007 */  sb        $s3, 7($s1)
/* D2C974 80240C44 AE800070 */  sw        $zero, 0x70($s4)
.L80240C48:
/* D2C978 80240C48 8FBF002C */  lw        $ra, 0x2c($sp)
/* D2C97C 80240C4C 8FB40028 */  lw        $s4, 0x28($sp)
/* D2C980 80240C50 8FB30024 */  lw        $s3, 0x24($sp)
/* D2C984 80240C54 8FB20020 */  lw        $s2, 0x20($sp)
/* D2C988 80240C58 8FB1001C */  lw        $s1, 0x1c($sp)
/* D2C98C 80240C5C 8FB00018 */  lw        $s0, 0x18($sp)
/* D2C990 80240C60 0000102D */  daddu     $v0, $zero, $zero
/* D2C994 80240C64 03E00008 */  jr        $ra
/* D2C998 80240C68 27BD0030 */   addiu    $sp, $sp, 0x30
