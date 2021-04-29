.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024082C_B5EADC
/* B5EADC 8024082C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B5EAE0 80240830 AFB5002C */  sw        $s5, 0x2c($sp)
/* B5EAE4 80240834 0080A82D */  daddu     $s5, $a0, $zero
/* B5EAE8 80240838 AFBE0038 */  sw        $fp, 0x38($sp)
/* B5EAEC 8024083C 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* B5EAF0 80240840 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* B5EAF4 80240844 AFBF003C */  sw        $ra, 0x3c($sp)
/* B5EAF8 80240848 AFB70034 */  sw        $s7, 0x34($sp)
/* B5EAFC 8024084C AFB60030 */  sw        $s6, 0x30($sp)
/* B5EB00 80240850 AFB40028 */  sw        $s4, 0x28($sp)
/* B5EB04 80240854 AFB30024 */  sw        $s3, 0x24($sp)
/* B5EB08 80240858 AFB20020 */  sw        $s2, 0x20($sp)
/* B5EB0C 8024085C AFB1001C */  sw        $s1, 0x1c($sp)
/* B5EB10 80240860 10A0004F */  beqz      $a1, .L802409A0
/* B5EB14 80240864 AFB00018 */   sw       $s0, 0x18($sp)
/* B5EB18 80240868 0C00AB39 */  jal       heap_malloc
/* B5EB1C 8024086C 24040330 */   addiu    $a0, $zero, 0x330
/* B5EB20 80240870 0040982D */  daddu     $s3, $v0, $zero
/* B5EB24 80240874 0000B02D */  daddu     $s6, $zero, $zero
/* B5EB28 80240878 02C0902D */  daddu     $s2, $s6, $zero
/* B5EB2C 8024087C 3C148024 */  lui       $s4, %hi(D_80243E08_B620B8)
/* B5EB30 80240880 26943E08 */  addiu     $s4, $s4, %lo(D_80243E08_B620B8)
/* B5EB34 80240884 0260882D */  daddu     $s1, $s3, $zero
/* B5EB38 80240888 8EA200B4 */  lw        $v0, 0xb4($s5)
/* B5EB3C 8024088C 3C038024 */  lui       $v1, %hi(D_80243E00_B620B0)
/* B5EB40 80240890 24633E00 */  addiu     $v1, $v1, %lo(D_80243E00_B620B0)
/* B5EB44 80240894 AEB30078 */  sw        $s3, 0x78($s5)
/* B5EB48 80240898 00021027 */  nor       $v0, $zero, $v0
/* B5EB4C 8024089C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* B5EB50 802408A0 00171080 */  sll       $v0, $s7, 2
/* B5EB54 802408A4 00431021 */  addu      $v0, $v0, $v1
/* B5EB58 802408A8 AFA20010 */  sw        $v0, 0x10($sp)
.L802408AC:
/* B5EB5C 802408AC 86900000 */  lh        $s0, ($s4)
/* B5EB60 802408B0 001010C0 */  sll       $v0, $s0, 3
/* B5EB64 802408B4 03C21021 */  addu      $v0, $fp, $v0
/* B5EB68 802408B8 90420014 */  lbu       $v0, 0x14($v0)
/* B5EB6C 802408BC 5040002E */  beql      $v0, $zero, .L80240978
/* B5EB70 802408C0 26520001 */   addiu    $s2, $s2, 1
/* B5EB74 802408C4 00101100 */  sll       $v0, $s0, 4
/* B5EB78 802408C8 3C068009 */  lui       $a2, %hi(D_8008EF20)
/* B5EB7C 802408CC 24C6EF20 */  addiu     $a2, $a2, %lo(D_8008EF20)
/* B5EB80 802408D0 00461021 */  addu      $v0, $v0, $a2
/* B5EB84 802408D4 0200202D */  daddu     $a0, $s0, $zero
/* B5EB88 802408D8 AE300108 */  sw        $s0, 0x108($s1)
/* B5EB8C 802408DC 8C420000 */  lw        $v0, ($v0)
/* B5EB90 802408E0 02E0282D */  daddu     $a1, $s7, $zero
/* B5EB94 802408E4 0C0901CD */  jal       jan_08_UnkFunc37
/* B5EB98 802408E8 AE220084 */   sw       $v0, 0x84($s1)
/* B5EB9C 802408EC 0040202D */  daddu     $a0, $v0, $zero
/* B5EBA0 802408F0 04800011 */  bltz      $a0, .L80240938
/* B5EBA4 802408F4 00101080 */   sll      $v0, $s0, 2
/* B5EBA8 802408F8 3C06800F */  lui       $a2, %hi(D_800F7F00)
/* B5EBAC 802408FC 24C67F00 */  addiu     $a2, $a2, %lo(D_800F7F00)
/* B5EBB0 80240900 00461021 */  addu      $v0, $v0, $a2
/* B5EBB4 80240904 8C430000 */  lw        $v1, ($v0)
/* B5EBB8 80240908 24020001 */  addiu     $v0, $zero, 1
/* B5EBBC 8024090C AE22018C */  sw        $v0, 0x18c($s1)
/* B5EBC0 80240910 00041080 */  sll       $v0, $a0, 2
/* B5EBC4 80240914 3C068024 */  lui       $a2, %hi(D_80243E18_B620C8)
/* B5EBC8 80240918 24C63E18 */  addiu     $a2, $a2, %lo(D_80243E18_B620C8)
/* B5EBCC 8024091C AE230000 */  sw        $v1, ($s1)
/* B5EBD0 80240920 001218C0 */  sll       $v1, $s2, 3
/* B5EBD4 80240924 00431021 */  addu      $v0, $v0, $v1
/* B5EBD8 80240928 00461021 */  addu      $v0, $v0, $a2
/* B5EBDC 8024092C 8C420000 */  lw        $v0, ($v0)
/* B5EBE0 80240930 08090257 */  j         .L8024095C
/* B5EBE4 80240934 AE220294 */   sw       $v0, 0x294($s1)
.L80240938:
/* B5EBE8 80240938 3C06800F */  lui       $a2, %hi(D_800F7F40)
/* B5EBEC 8024093C 24C67F40 */  addiu     $a2, $a2, %lo(D_800F7F40)
/* B5EBF0 80240940 00461021 */  addu      $v0, $v0, $a2
/* B5EBF4 80240944 8C420000 */  lw        $v0, ($v0)
/* B5EBF8 80240948 AE20018C */  sw        $zero, 0x18c($s1)
/* B5EBFC 8024094C AE220000 */  sw        $v0, ($s1)
/* B5EC00 80240950 8FA60010 */  lw        $a2, 0x10($sp)
/* B5EC04 80240954 8CC20000 */  lw        $v0, ($a2)
/* B5EC08 80240958 AE220294 */  sw        $v0, 0x294($s1)
.L8024095C:
/* B5EC0C 8024095C 001010C0 */  sll       $v0, $s0, 3
/* B5EC10 80240960 03C21021 */  addu      $v0, $fp, $v0
/* B5EC14 80240964 80420015 */  lb        $v0, 0x15($v0)
/* B5EC18 80240968 26D60001 */  addiu     $s6, $s6, 1
/* B5EC1C 8024096C AE220210 */  sw        $v0, 0x210($s1)
/* B5EC20 80240970 26310004 */  addiu     $s1, $s1, 4
/* B5EC24 80240974 26520001 */  addiu     $s2, $s2, 1
.L80240978:
/* B5EC28 80240978 2A420008 */  slti      $v0, $s2, 8
/* B5EC2C 8024097C 1440FFCB */  bnez      $v0, .L802408AC
/* B5EC30 80240980 26940002 */   addiu    $s4, $s4, 2
/* B5EC34 80240984 0260202D */  daddu     $a0, $s3, $zero
/* B5EC38 80240988 24020004 */  addiu     $v0, $zero, 4
/* B5EC3C 8024098C AC820318 */  sw        $v0, 0x318($a0)
/* B5EC40 80240990 AC960324 */  sw        $s6, 0x324($a0)
/* B5EC44 80240994 0C03D390 */  jal       func_800F4E40
/* B5EC48 80240998 AC800328 */   sw       $zero, 0x328($a0)
/* B5EC4C 8024099C AEA00070 */  sw        $zero, 0x70($s5)
.L802409A0:
/* B5EC50 802409A0 8EA20070 */  lw        $v0, 0x70($s5)
/* B5EC54 802409A4 8EB30078 */  lw        $s3, 0x78($s5)
/* B5EC58 802409A8 14400008 */  bnez      $v0, .L802409CC
/* B5EC5C 802409AC 24420001 */   addiu    $v0, $v0, 1
/* B5EC60 802409B0 8662032C */  lh        $v0, 0x32c($s3)
/* B5EC64 802409B4 10400009 */  beqz      $v0, .L802409DC
/* B5EC68 802409B8 AEA20074 */   sw       $v0, 0x74($s5)
/* B5EC6C 802409BC 0C03C4EC */  jal       func_800F13B0
/* B5EC70 802409C0 00000000 */   nop
/* B5EC74 802409C4 8EA20070 */  lw        $v0, 0x70($s5)
/* B5EC78 802409C8 24420001 */  addiu     $v0, $v0, 1
.L802409CC:
/* B5EC7C 802409CC AEA20070 */  sw        $v0, 0x70($s5)
/* B5EC80 802409D0 2842000F */  slti      $v0, $v0, 0xf
/* B5EC84 802409D4 10400003 */  beqz      $v0, .L802409E4
/* B5EC88 802409D8 00000000 */   nop
.L802409DC:
/* B5EC8C 802409DC 08090293 */  j         .L80240A4C
/* B5EC90 802409E0 0000102D */   daddu    $v0, $zero, $zero
.L802409E4:
/* B5EC94 802409E4 0C03C54E */  jal       func_800F1538
/* B5EC98 802409E8 00000000 */   nop
/* B5EC9C 802409EC 8EA30074 */  lw        $v1, 0x74($s5)
/* B5ECA0 802409F0 240200FF */  addiu     $v0, $zero, 0xff
/* B5ECA4 802409F4 10620010 */  beq       $v1, $v0, .L80240A38
/* B5ECA8 802409F8 2462FFFF */   addiu    $v0, $v1, -1
/* B5ECAC 802409FC 00021080 */  sll       $v0, $v0, 2
/* B5ECB0 80240A00 02621021 */  addu      $v0, $s3, $v0
/* B5ECB4 80240A04 8C420108 */  lw        $v0, 0x108($v0)
/* B5ECB8 80240A08 00021100 */  sll       $v0, $v0, 4
/* B5ECBC 80240A0C 3C038009 */  lui       $v1, %hi(D_8008EF20)
/* B5ECC0 80240A10 00621821 */  addu      $v1, $v1, $v0
/* B5ECC4 80240A14 8C63EF20 */  lw        $v1, %lo(D_8008EF20)($v1)
/* B5ECC8 80240A18 8EA20074 */  lw        $v0, 0x74($s5)
/* B5ECCC 80240A1C 2442FFFF */  addiu     $v0, $v0, -1
/* B5ECD0 80240A20 00021080 */  sll       $v0, $v0, 2
/* B5ECD4 80240A24 02621021 */  addu      $v0, $s3, $v0
/* B5ECD8 80240A28 AEA30084 */  sw        $v1, 0x84($s5)
/* B5ECDC 80240A2C 8C420108 */  lw        $v0, 0x108($v0)
/* B5ECE0 80240A30 08090290 */  j         .L80240A40
/* B5ECE4 80240A34 AEA20088 */   sw       $v0, 0x88($s5)
.L80240A38:
/* B5ECE8 80240A38 2402FFFF */  addiu     $v0, $zero, -1
/* B5ECEC 80240A3C AEA20084 */  sw        $v0, 0x84($s5)
.L80240A40:
/* B5ECF0 80240A40 0C00AB4B */  jal       heap_free
/* B5ECF4 80240A44 8EA40078 */   lw       $a0, 0x78($s5)
/* B5ECF8 80240A48 24020002 */  addiu     $v0, $zero, 2
.L80240A4C:
/* B5ECFC 80240A4C 8FBF003C */  lw        $ra, 0x3c($sp)
/* B5ED00 80240A50 8FBE0038 */  lw        $fp, 0x38($sp)
/* B5ED04 80240A54 8FB70034 */  lw        $s7, 0x34($sp)
/* B5ED08 80240A58 8FB60030 */  lw        $s6, 0x30($sp)
/* B5ED0C 80240A5C 8FB5002C */  lw        $s5, 0x2c($sp)
/* B5ED10 80240A60 8FB40028 */  lw        $s4, 0x28($sp)
/* B5ED14 80240A64 8FB30024 */  lw        $s3, 0x24($sp)
/* B5ED18 80240A68 8FB20020 */  lw        $s2, 0x20($sp)
/* B5ED1C 80240A6C 8FB1001C */  lw        $s1, 0x1c($sp)
/* B5ED20 80240A70 8FB00018 */  lw        $s0, 0x18($sp)
/* B5ED24 80240A74 03E00008 */  jr        $ra
/* B5ED28 80240A78 27BD0040 */   addiu    $sp, $sp, 0x40
