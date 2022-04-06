.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024084C_886C0C
/* 886C0C 8024084C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 886C10 80240850 AFB5002C */  sw        $s5, 0x2c($sp)
/* 886C14 80240854 0080A82D */  daddu     $s5, $a0, $zero
/* 886C18 80240858 AFBE0038 */  sw        $fp, 0x38($sp)
/* 886C1C 8024085C 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* 886C20 80240860 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* 886C24 80240864 AFBF003C */  sw        $ra, 0x3c($sp)
/* 886C28 80240868 AFB70034 */  sw        $s7, 0x34($sp)
/* 886C2C 8024086C AFB60030 */  sw        $s6, 0x30($sp)
/* 886C30 80240870 AFB40028 */  sw        $s4, 0x28($sp)
/* 886C34 80240874 AFB30024 */  sw        $s3, 0x24($sp)
/* 886C38 80240878 AFB20020 */  sw        $s2, 0x20($sp)
/* 886C3C 8024087C AFB1001C */  sw        $s1, 0x1c($sp)
/* 886C40 80240880 10A0004F */  beqz      $a1, .L802409C0
/* 886C44 80240884 AFB00018 */   sw       $s0, 0x18($sp)
/* 886C48 80240888 0C00AB39 */  jal       heap_malloc
/* 886C4C 8024088C 24040330 */   addiu    $a0, $zero, 0x330
/* 886C50 80240890 0040982D */  daddu     $s3, $v0, $zero
/* 886C54 80240894 0000B02D */  daddu     $s6, $zero, $zero
/* 886C58 80240898 02C0902D */  daddu     $s2, $s6, $zero
/* 886C5C 8024089C 3C148024 */  lui       $s4, %hi(tik_10_SuperBlockDataB)
/* 886C60 802408A0 26942038 */  addiu     $s4, $s4, %lo(tik_10_SuperBlockDataB)
/* 886C64 802408A4 0260882D */  daddu     $s1, $s3, $zero
/* 886C68 802408A8 8EA200B4 */  lw        $v0, 0xb4($s5)
/* 886C6C 802408AC 3C038024 */  lui       $v1, %hi(tik_10_SuperBlockDataA)
/* 886C70 802408B0 24632030 */  addiu     $v1, $v1, %lo(tik_10_SuperBlockDataA)
/* 886C74 802408B4 AEB30078 */  sw        $s3, 0x78($s5)
/* 886C78 802408B8 00021027 */  nor       $v0, $zero, $v0
/* 886C7C 802408BC 0002BFC2 */  srl       $s7, $v0, 0x1f
/* 886C80 802408C0 00171080 */  sll       $v0, $s7, 2
/* 886C84 802408C4 00431021 */  addu      $v0, $v0, $v1
/* 886C88 802408C8 AFA20010 */  sw        $v0, 0x10($sp)
.L802408CC:
/* 886C8C 802408CC 86900000 */  lh        $s0, ($s4)
/* 886C90 802408D0 001010C0 */  sll       $v0, $s0, 3
/* 886C94 802408D4 03C21021 */  addu      $v0, $fp, $v0
/* 886C98 802408D8 90420014 */  lbu       $v0, 0x14($v0)
/* 886C9C 802408DC 5040002E */  beql      $v0, $zero, .L80240998
/* 886CA0 802408E0 26520001 */   addiu    $s2, $s2, 1
/* 886CA4 802408E4 00101100 */  sll       $v0, $s0, 4
/* 886CA8 802408E8 3C068009 */  lui       $a2, %hi(gPartnerPopupProperties)
/* 886CAC 802408EC 24C6EF20 */  addiu     $a2, $a2, %lo(gPartnerPopupProperties)
/* 886CB0 802408F0 00461021 */  addu      $v0, $v0, $a2
/* 886CB4 802408F4 0200202D */  daddu     $a0, $s0, $zero
/* 886CB8 802408F8 AE300108 */  sw        $s0, 0x108($s1)
/* 886CBC 802408FC 8C420000 */  lw        $v0, ($v0)
/* 886CC0 80240900 02E0282D */  daddu     $a1, $s7, $zero
/* 886CC4 80240904 0C0901D5 */  jal       tik_10_UnkFunc37
/* 886CC8 80240908 AE220084 */   sw       $v0, 0x84($s1)
/* 886CCC 8024090C 0040202D */  daddu     $a0, $v0, $zero
/* 886CD0 80240910 04800011 */  bltz      $a0, .L80240958
/* 886CD4 80240914 00101080 */   sll      $v0, $s0, 2
/* 886CD8 80240918 3C06800F */  lui       $a2, %hi(wPartnerHudScripts)
/* 886CDC 8024091C 24C67F00 */  addiu     $a2, $a2, %lo(wPartnerHudScripts)
/* 886CE0 80240920 00461021 */  addu      $v0, $v0, $a2
/* 886CE4 80240924 8C430000 */  lw        $v1, ($v0)
/* 886CE8 80240928 24020001 */  addiu     $v0, $zero, 1
/* 886CEC 8024092C AE22018C */  sw        $v0, 0x18c($s1)
/* 886CF0 80240930 00041080 */  sll       $v0, $a0, 2
/* 886CF4 80240934 3C068024 */  lui       $a2, %hi(tik_10_SuperBlockDataC)
/* 886CF8 80240938 24C62048 */  addiu     $a2, $a2, %lo(tik_10_SuperBlockDataC)
/* 886CFC 8024093C AE230000 */  sw        $v1, ($s1)
/* 886D00 80240940 001218C0 */  sll       $v1, $s2, 3
/* 886D04 80240944 00431021 */  addu      $v0, $v0, $v1
/* 886D08 80240948 00461021 */  addu      $v0, $v0, $a2
/* 886D0C 8024094C 8C420000 */  lw        $v0, ($v0)
/* 886D10 80240950 0809025F */  j         .L8024097C
/* 886D14 80240954 AE220294 */   sw       $v0, 0x294($s1)
.L80240958:
/* 886D18 80240958 3C06800F */  lui       $a2, %hi(wDisabledPartnerHudScripts)
/* 886D1C 8024095C 24C67F40 */  addiu     $a2, $a2, %lo(wDisabledPartnerHudScripts)
/* 886D20 80240960 00461021 */  addu      $v0, $v0, $a2
/* 886D24 80240964 8C420000 */  lw        $v0, ($v0)
/* 886D28 80240968 AE20018C */  sw        $zero, 0x18c($s1)
/* 886D2C 8024096C AE220000 */  sw        $v0, ($s1)
/* 886D30 80240970 8FA60010 */  lw        $a2, 0x10($sp)
/* 886D34 80240974 8CC20000 */  lw        $v0, ($a2)
/* 886D38 80240978 AE220294 */  sw        $v0, 0x294($s1)
.L8024097C:
/* 886D3C 8024097C 001010C0 */  sll       $v0, $s0, 3
/* 886D40 80240980 03C21021 */  addu      $v0, $fp, $v0
/* 886D44 80240984 80420015 */  lb        $v0, 0x15($v0)
/* 886D48 80240988 26D60001 */  addiu     $s6, $s6, 1
/* 886D4C 8024098C AE220210 */  sw        $v0, 0x210($s1)
/* 886D50 80240990 26310004 */  addiu     $s1, $s1, 4
/* 886D54 80240994 26520001 */  addiu     $s2, $s2, 1
.L80240998:
/* 886D58 80240998 2A420008 */  slti      $v0, $s2, 8
/* 886D5C 8024099C 1440FFCB */  bnez      $v0, .L802408CC
/* 886D60 802409A0 26940002 */   addiu    $s4, $s4, 2
/* 886D64 802409A4 0260202D */  daddu     $a0, $s3, $zero
/* 886D68 802409A8 24020004 */  addiu     $v0, $zero, 4
/* 886D6C 802409AC AC820318 */  sw        $v0, 0x318($a0)
/* 886D70 802409B0 AC960324 */  sw        $s6, 0x324($a0)
/* 886D74 802409B4 0C03D390 */  jal       create_popup_menu
/* 886D78 802409B8 AC800328 */   sw       $zero, 0x328($a0)
/* 886D7C 802409BC AEA00070 */  sw        $zero, 0x70($s5)
.L802409C0:
/* 886D80 802409C0 8EA20070 */  lw        $v0, 0x70($s5)
/* 886D84 802409C4 8EB30078 */  lw        $s3, 0x78($s5)
/* 886D88 802409C8 14400008 */  bnez      $v0, .L802409EC
/* 886D8C 802409CC 24420001 */   addiu    $v0, $v0, 1
/* 886D90 802409D0 8662032C */  lh        $v0, 0x32c($s3)
/* 886D94 802409D4 10400009 */  beqz      $v0, .L802409FC
/* 886D98 802409D8 AEA20074 */   sw       $v0, 0x74($s5)
/* 886D9C 802409DC 0C03C4EC */  jal       hide_popup_menu
/* 886DA0 802409E0 00000000 */   nop
/* 886DA4 802409E4 8EA20070 */  lw        $v0, 0x70($s5)
/* 886DA8 802409E8 24420001 */  addiu     $v0, $v0, 1
.L802409EC:
/* 886DAC 802409EC AEA20070 */  sw        $v0, 0x70($s5)
/* 886DB0 802409F0 2842000F */  slti      $v0, $v0, 0xf
/* 886DB4 802409F4 10400003 */  beqz      $v0, .L80240A04
/* 886DB8 802409F8 00000000 */   nop
.L802409FC:
/* 886DBC 802409FC 0809029B */  j         .L80240A6C
/* 886DC0 80240A00 0000102D */   daddu    $v0, $zero, $zero
.L80240A04:
/* 886DC4 80240A04 0C03C54E */  jal       destroy_popup_menu
/* 886DC8 80240A08 00000000 */   nop
/* 886DCC 80240A0C 8EA30074 */  lw        $v1, 0x74($s5)
/* 886DD0 80240A10 240200FF */  addiu     $v0, $zero, 0xff
/* 886DD4 80240A14 10620010 */  beq       $v1, $v0, .L80240A58
/* 886DD8 80240A18 2462FFFF */   addiu    $v0, $v1, -1
/* 886DDC 80240A1C 00021080 */  sll       $v0, $v0, 2
/* 886DE0 80240A20 02621021 */  addu      $v0, $s3, $v0
/* 886DE4 80240A24 8C420108 */  lw        $v0, 0x108($v0)
/* 886DE8 80240A28 00021100 */  sll       $v0, $v0, 4
/* 886DEC 80240A2C 3C038009 */  lui       $v1, %hi(gPartnerPopupProperties)
/* 886DF0 80240A30 00621821 */  addu      $v1, $v1, $v0
/* 886DF4 80240A34 8C63EF20 */  lw        $v1, %lo(gPartnerPopupProperties)($v1)
/* 886DF8 80240A38 8EA20074 */  lw        $v0, 0x74($s5)
/* 886DFC 80240A3C 2442FFFF */  addiu     $v0, $v0, -1
/* 886E00 80240A40 00021080 */  sll       $v0, $v0, 2
/* 886E04 80240A44 02621021 */  addu      $v0, $s3, $v0
/* 886E08 80240A48 AEA30084 */  sw        $v1, 0x84($s5)
/* 886E0C 80240A4C 8C420108 */  lw        $v0, 0x108($v0)
/* 886E10 80240A50 08090298 */  j         .L80240A60
/* 886E14 80240A54 AEA20088 */   sw       $v0, 0x88($s5)
.L80240A58:
/* 886E18 80240A58 2402FFFF */  addiu     $v0, $zero, -1
/* 886E1C 80240A5C AEA20084 */  sw        $v0, 0x84($s5)
.L80240A60:
/* 886E20 80240A60 0C00AB4B */  jal       heap_free
/* 886E24 80240A64 8EA40078 */   lw       $a0, 0x78($s5)
/* 886E28 80240A68 24020002 */  addiu     $v0, $zero, 2
.L80240A6C:
/* 886E2C 80240A6C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 886E30 80240A70 8FBE0038 */  lw        $fp, 0x38($sp)
/* 886E34 80240A74 8FB70034 */  lw        $s7, 0x34($sp)
/* 886E38 80240A78 8FB60030 */  lw        $s6, 0x30($sp)
/* 886E3C 80240A7C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 886E40 80240A80 8FB40028 */  lw        $s4, 0x28($sp)
/* 886E44 80240A84 8FB30024 */  lw        $s3, 0x24($sp)
/* 886E48 80240A88 8FB20020 */  lw        $s2, 0x20($sp)
/* 886E4C 80240A8C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 886E50 80240A90 8FB00018 */  lw        $s0, 0x18($sp)
/* 886E54 80240A94 03E00008 */  jr        $ra
/* 886E58 80240A98 27BD0040 */   addiu    $sp, $sp, 0x40
