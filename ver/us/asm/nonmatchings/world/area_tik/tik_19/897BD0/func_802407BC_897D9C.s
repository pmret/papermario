.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407BC_897D9C
/* 897D9C 802407BC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 897DA0 802407C0 AFB5002C */  sw        $s5, 0x2c($sp)
/* 897DA4 802407C4 0080A82D */  daddu     $s5, $a0, $zero
/* 897DA8 802407C8 AFBE0038 */  sw        $fp, 0x38($sp)
/* 897DAC 802407CC 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* 897DB0 802407D0 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* 897DB4 802407D4 AFBF003C */  sw        $ra, 0x3c($sp)
/* 897DB8 802407D8 AFB70034 */  sw        $s7, 0x34($sp)
/* 897DBC 802407DC AFB60030 */  sw        $s6, 0x30($sp)
/* 897DC0 802407E0 AFB40028 */  sw        $s4, 0x28($sp)
/* 897DC4 802407E4 AFB30024 */  sw        $s3, 0x24($sp)
/* 897DC8 802407E8 AFB20020 */  sw        $s2, 0x20($sp)
/* 897DCC 802407EC AFB1001C */  sw        $s1, 0x1c($sp)
/* 897DD0 802407F0 10A0004F */  beqz      $a1, .L80240930
/* 897DD4 802407F4 AFB00018 */   sw       $s0, 0x18($sp)
/* 897DD8 802407F8 0C00AB39 */  jal       heap_malloc
/* 897DDC 802407FC 24040330 */   addiu    $a0, $zero, 0x330
/* 897DE0 80240800 0040982D */  daddu     $s3, $v0, $zero
/* 897DE4 80240804 0000B02D */  daddu     $s6, $zero, $zero
/* 897DE8 80240808 02C0902D */  daddu     $s2, $s6, $zero
/* 897DEC 8024080C 3C148024 */  lui       $s4, %hi(tik_19_SuperBlockDataB)
/* 897DF0 80240810 269426B8 */  addiu     $s4, $s4, %lo(tik_19_SuperBlockDataB)
/* 897DF4 80240814 0260882D */  daddu     $s1, $s3, $zero
/* 897DF8 80240818 8EA200B4 */  lw        $v0, 0xb4($s5)
/* 897DFC 8024081C 3C038024 */  lui       $v1, %hi(tik_19_SuperBlockDataA)
/* 897E00 80240820 246326B0 */  addiu     $v1, $v1, %lo(tik_19_SuperBlockDataA)
/* 897E04 80240824 AEB30078 */  sw        $s3, 0x78($s5)
/* 897E08 80240828 00021027 */  nor       $v0, $zero, $v0
/* 897E0C 8024082C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* 897E10 80240830 00171080 */  sll       $v0, $s7, 2
/* 897E14 80240834 00431021 */  addu      $v0, $v0, $v1
/* 897E18 80240838 AFA20010 */  sw        $v0, 0x10($sp)
.L8024083C:
/* 897E1C 8024083C 86900000 */  lh        $s0, ($s4)
/* 897E20 80240840 001010C0 */  sll       $v0, $s0, 3
/* 897E24 80240844 03C21021 */  addu      $v0, $fp, $v0
/* 897E28 80240848 90420014 */  lbu       $v0, 0x14($v0)
/* 897E2C 8024084C 5040002E */  beql      $v0, $zero, .L80240908
/* 897E30 80240850 26520001 */   addiu    $s2, $s2, 1
/* 897E34 80240854 00101100 */  sll       $v0, $s0, 4
/* 897E38 80240858 3C068009 */  lui       $a2, %hi(gPartnerPopupProperties)
/* 897E3C 8024085C 24C6EF20 */  addiu     $a2, $a2, %lo(gPartnerPopupProperties)
/* 897E40 80240860 00461021 */  addu      $v0, $v0, $a2
/* 897E44 80240864 0200202D */  daddu     $a0, $s0, $zero
/* 897E48 80240868 AE300108 */  sw        $s0, 0x108($s1)
/* 897E4C 8024086C 8C420000 */  lw        $v0, ($v0)
/* 897E50 80240870 02E0282D */  daddu     $a1, $s7, $zero
/* 897E54 80240874 0C0901B1 */  jal       tik_19_UnkFunc37
/* 897E58 80240878 AE220084 */   sw       $v0, 0x84($s1)
/* 897E5C 8024087C 0040202D */  daddu     $a0, $v0, $zero
/* 897E60 80240880 04800011 */  bltz      $a0, .L802408C8
/* 897E64 80240884 00101080 */   sll      $v0, $s0, 2
/* 897E68 80240888 3C06800F */  lui       $a2, %hi(wPartnerHudScripts)
/* 897E6C 8024088C 24C67F00 */  addiu     $a2, $a2, %lo(wPartnerHudScripts)
/* 897E70 80240890 00461021 */  addu      $v0, $v0, $a2
/* 897E74 80240894 8C430000 */  lw        $v1, ($v0)
/* 897E78 80240898 24020001 */  addiu     $v0, $zero, 1
/* 897E7C 8024089C AE22018C */  sw        $v0, 0x18c($s1)
/* 897E80 802408A0 00041080 */  sll       $v0, $a0, 2
/* 897E84 802408A4 3C068024 */  lui       $a2, %hi(tik_19_SuperBlockDataC)
/* 897E88 802408A8 24C626C8 */  addiu     $a2, $a2, %lo(tik_19_SuperBlockDataC)
/* 897E8C 802408AC AE230000 */  sw        $v1, ($s1)
/* 897E90 802408B0 001218C0 */  sll       $v1, $s2, 3
/* 897E94 802408B4 00431021 */  addu      $v0, $v0, $v1
/* 897E98 802408B8 00461021 */  addu      $v0, $v0, $a2
/* 897E9C 802408BC 8C420000 */  lw        $v0, ($v0)
/* 897EA0 802408C0 0809023B */  j         .L802408EC
/* 897EA4 802408C4 AE220294 */   sw       $v0, 0x294($s1)
.L802408C8:
/* 897EA8 802408C8 3C06800F */  lui       $a2, %hi(wDisabledPartnerHudScripts)
/* 897EAC 802408CC 24C67F40 */  addiu     $a2, $a2, %lo(wDisabledPartnerHudScripts)
/* 897EB0 802408D0 00461021 */  addu      $v0, $v0, $a2
/* 897EB4 802408D4 8C420000 */  lw        $v0, ($v0)
/* 897EB8 802408D8 AE20018C */  sw        $zero, 0x18c($s1)
/* 897EBC 802408DC AE220000 */  sw        $v0, ($s1)
/* 897EC0 802408E0 8FA60010 */  lw        $a2, 0x10($sp)
/* 897EC4 802408E4 8CC20000 */  lw        $v0, ($a2)
/* 897EC8 802408E8 AE220294 */  sw        $v0, 0x294($s1)
.L802408EC:
/* 897ECC 802408EC 001010C0 */  sll       $v0, $s0, 3
/* 897ED0 802408F0 03C21021 */  addu      $v0, $fp, $v0
/* 897ED4 802408F4 80420015 */  lb        $v0, 0x15($v0)
/* 897ED8 802408F8 26D60001 */  addiu     $s6, $s6, 1
/* 897EDC 802408FC AE220210 */  sw        $v0, 0x210($s1)
/* 897EE0 80240900 26310004 */  addiu     $s1, $s1, 4
/* 897EE4 80240904 26520001 */  addiu     $s2, $s2, 1
.L80240908:
/* 897EE8 80240908 2A420008 */  slti      $v0, $s2, 8
/* 897EEC 8024090C 1440FFCB */  bnez      $v0, .L8024083C
/* 897EF0 80240910 26940002 */   addiu    $s4, $s4, 2
/* 897EF4 80240914 0260202D */  daddu     $a0, $s3, $zero
/* 897EF8 80240918 24020004 */  addiu     $v0, $zero, 4
/* 897EFC 8024091C AC820318 */  sw        $v0, 0x318($a0)
/* 897F00 80240920 AC960324 */  sw        $s6, 0x324($a0)
/* 897F04 80240924 0C03D390 */  jal       create_popup_menu
/* 897F08 80240928 AC800328 */   sw       $zero, 0x328($a0)
/* 897F0C 8024092C AEA00070 */  sw        $zero, 0x70($s5)
.L80240930:
/* 897F10 80240930 8EA20070 */  lw        $v0, 0x70($s5)
/* 897F14 80240934 8EB30078 */  lw        $s3, 0x78($s5)
/* 897F18 80240938 14400008 */  bnez      $v0, .L8024095C
/* 897F1C 8024093C 24420001 */   addiu    $v0, $v0, 1
/* 897F20 80240940 8662032C */  lh        $v0, 0x32c($s3)
/* 897F24 80240944 10400009 */  beqz      $v0, .L8024096C
/* 897F28 80240948 AEA20074 */   sw       $v0, 0x74($s5)
/* 897F2C 8024094C 0C03C4EC */  jal       hide_popup_menu
/* 897F30 80240950 00000000 */   nop
/* 897F34 80240954 8EA20070 */  lw        $v0, 0x70($s5)
/* 897F38 80240958 24420001 */  addiu     $v0, $v0, 1
.L8024095C:
/* 897F3C 8024095C AEA20070 */  sw        $v0, 0x70($s5)
/* 897F40 80240960 2842000F */  slti      $v0, $v0, 0xf
/* 897F44 80240964 10400003 */  beqz      $v0, .L80240974
/* 897F48 80240968 00000000 */   nop
.L8024096C:
/* 897F4C 8024096C 08090277 */  j         .L802409DC
/* 897F50 80240970 0000102D */   daddu    $v0, $zero, $zero
.L80240974:
/* 897F54 80240974 0C03C54E */  jal       destroy_popup_menu
/* 897F58 80240978 00000000 */   nop
/* 897F5C 8024097C 8EA30074 */  lw        $v1, 0x74($s5)
/* 897F60 80240980 240200FF */  addiu     $v0, $zero, 0xff
/* 897F64 80240984 10620010 */  beq       $v1, $v0, .L802409C8
/* 897F68 80240988 2462FFFF */   addiu    $v0, $v1, -1
/* 897F6C 8024098C 00021080 */  sll       $v0, $v0, 2
/* 897F70 80240990 02621021 */  addu      $v0, $s3, $v0
/* 897F74 80240994 8C420108 */  lw        $v0, 0x108($v0)
/* 897F78 80240998 00021100 */  sll       $v0, $v0, 4
/* 897F7C 8024099C 3C038009 */  lui       $v1, %hi(gPartnerPopupProperties)
/* 897F80 802409A0 00621821 */  addu      $v1, $v1, $v0
/* 897F84 802409A4 8C63EF20 */  lw        $v1, %lo(gPartnerPopupProperties)($v1)
/* 897F88 802409A8 8EA20074 */  lw        $v0, 0x74($s5)
/* 897F8C 802409AC 2442FFFF */  addiu     $v0, $v0, -1
/* 897F90 802409B0 00021080 */  sll       $v0, $v0, 2
/* 897F94 802409B4 02621021 */  addu      $v0, $s3, $v0
/* 897F98 802409B8 AEA30084 */  sw        $v1, 0x84($s5)
/* 897F9C 802409BC 8C420108 */  lw        $v0, 0x108($v0)
/* 897FA0 802409C0 08090274 */  j         .L802409D0
/* 897FA4 802409C4 AEA20088 */   sw       $v0, 0x88($s5)
.L802409C8:
/* 897FA8 802409C8 2402FFFF */  addiu     $v0, $zero, -1
/* 897FAC 802409CC AEA20084 */  sw        $v0, 0x84($s5)
.L802409D0:
/* 897FB0 802409D0 0C00AB4B */  jal       heap_free
/* 897FB4 802409D4 8EA40078 */   lw       $a0, 0x78($s5)
/* 897FB8 802409D8 24020002 */  addiu     $v0, $zero, 2
.L802409DC:
/* 897FBC 802409DC 8FBF003C */  lw        $ra, 0x3c($sp)
/* 897FC0 802409E0 8FBE0038 */  lw        $fp, 0x38($sp)
/* 897FC4 802409E4 8FB70034 */  lw        $s7, 0x34($sp)
/* 897FC8 802409E8 8FB60030 */  lw        $s6, 0x30($sp)
/* 897FCC 802409EC 8FB5002C */  lw        $s5, 0x2c($sp)
/* 897FD0 802409F0 8FB40028 */  lw        $s4, 0x28($sp)
/* 897FD4 802409F4 8FB30024 */  lw        $s3, 0x24($sp)
/* 897FD8 802409F8 8FB20020 */  lw        $s2, 0x20($sp)
/* 897FDC 802409FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 897FE0 80240A00 8FB00018 */  lw        $s0, 0x18($sp)
/* 897FE4 80240A04 03E00008 */  jr        $ra
/* 897FE8 80240A08 27BD0040 */   addiu    $sp, $sp, 0x40
