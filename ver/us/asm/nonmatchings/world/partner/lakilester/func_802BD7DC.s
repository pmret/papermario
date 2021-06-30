.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD7DC
/* 32132C 802BD7DC 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 321330 802BD7E0 AFBF005C */  sw        $ra, 0x5c($sp)
/* 321334 802BD7E4 AFB40058 */  sw        $s4, 0x58($sp)
/* 321338 802BD7E8 AFB30054 */  sw        $s3, 0x54($sp)
/* 32133C 802BD7EC AFB20050 */  sw        $s2, 0x50($sp)
/* 321340 802BD7F0 AFB1004C */  sw        $s1, 0x4c($sp)
/* 321344 802BD7F4 AFB00048 */  sw        $s0, 0x48($sp)
/* 321348 802BD7F8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 32134C 802BD7FC 0C00EABB */  jal       get_npc_unsafe
/* 321350 802BD800 2404FFFC */   addiu    $a0, $zero, -4
/* 321354 802BD804 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 321358 802BD808 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 32135C 802BD80C 0040902D */  daddu     $s2, $v0, $zero
/* 321360 802BD810 8E030004 */  lw        $v1, 4($s0)
/* 321364 802BD814 3C022000 */  lui       $v0, 0x2000
/* 321368 802BD818 00621024 */  and       $v0, $v1, $v0
/* 32136C 802BD81C 10400007 */  beqz      $v0, .L802BD83C
/* 321370 802BD820 0200982D */   daddu    $s3, $s0, $zero
/* 321374 802BD824 3C02DFFF */  lui       $v0, 0xdfff
/* 321378 802BD828 3442FFFF */  ori       $v0, $v0, 0xffff
/* 32137C 802BD82C 00621024 */  and       $v0, $v1, $v0
/* 321380 802BD830 AE020004 */  sw        $v0, 4($s0)
/* 321384 802BD834 080AF65E */  j         .L802BD978
/* 321388 802BD838 24020001 */   addiu    $v0, $zero, 1
.L802BD83C:
/* 32138C 802BD83C 0000A02D */  daddu     $s4, $zero, $zero
/* 321390 802BD840 27B10028 */  addiu     $s1, $sp, 0x28
/* 321394 802BD844 0220202D */  daddu     $a0, $s1, $zero
/* 321398 802BD848 27B0002C */  addiu     $s0, $sp, 0x2c
/* 32139C 802BD84C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3213A0 802BD850 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3213A4 802BD854 3C064000 */  lui       $a2, 0x4000
/* 3213A8 802BD858 3C014180 */  lui       $at, 0x4180
/* 3213AC 802BD85C 4481A000 */  mtc1      $at, $f20
/* 3213B0 802BD860 3C0140E0 */  lui       $at, 0x40e0
/* 3213B4 802BD864 44811000 */  mtc1      $at, $f2
/* 3213B8 802BD868 00031080 */  sll       $v0, $v1, 2
/* 3213BC 802BD86C 00431021 */  addu      $v0, $v0, $v1
/* 3213C0 802BD870 00021080 */  sll       $v0, $v0, 2
/* 3213C4 802BD874 00431023 */  subu      $v0, $v0, $v1
/* 3213C8 802BD878 000218C0 */  sll       $v1, $v0, 3
/* 3213CC 802BD87C 00431021 */  addu      $v0, $v0, $v1
/* 3213D0 802BD880 000210C0 */  sll       $v0, $v0, 3
/* 3213D4 802BD884 3C07800B */  lui       $a3, %hi(gCameras+0x6C)
/* 3213D8 802BD888 00E23821 */  addu      $a3, $a3, $v0
/* 3213DC 802BD88C 8CE71DEC */  lw        $a3, %lo(gCameras+0x6C)($a3)
/* 3213E0 802BD890 0200282D */  daddu     $a1, $s0, $zero
/* 3213E4 802BD894 E7B40034 */  swc1      $f20, 0x34($sp)
/* 3213E8 802BD898 C6400064 */  lwc1      $f0, 0x64($s2)
/* 3213EC 802BD89C C6640028 */  lwc1      $f4, 0x28($s3)
/* 3213F0 802BD8A0 C6660030 */  lwc1      $f6, 0x30($s3)
/* 3213F4 802BD8A4 46020000 */  add.s     $f0, $f0, $f2
/* 3213F8 802BD8A8 E7A40028 */  swc1      $f4, 0x28($sp)
/* 3213FC 802BD8AC E7A6002C */  swc1      $f6, 0x2c($sp)
/* 321400 802BD8B0 0C00A7E7 */  jal       add_vec2D_polar
/* 321404 802BD8B4 E7A00030 */   swc1     $f0, 0x30($sp)
/* 321408 802BD8B8 0260202D */  daddu     $a0, $s3, $zero
/* 32140C 802BD8BC 0220282D */  daddu     $a1, $s1, $zero
/* 321410 802BD8C0 27A60030 */  addiu     $a2, $sp, 0x30
/* 321414 802BD8C4 0200382D */  daddu     $a3, $s0, $zero
/* 321418 802BD8C8 27A20034 */  addiu     $v0, $sp, 0x34
/* 32141C 802BD8CC AFA20010 */  sw        $v0, 0x10($sp)
/* 321420 802BD8D0 27A20038 */  addiu     $v0, $sp, 0x38
/* 321424 802BD8D4 AFA20014 */  sw        $v0, 0x14($sp)
/* 321428 802BD8D8 27A2003C */  addiu     $v0, $sp, 0x3c
/* 32142C 802BD8DC AFA20018 */  sw        $v0, 0x18($sp)
/* 321430 802BD8E0 27A20040 */  addiu     $v0, $sp, 0x40
/* 321434 802BD8E4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 321438 802BD8E8 27A20044 */  addiu     $v0, $sp, 0x44
/* 32143C 802BD8EC 0C03791B */  jal       player_raycast_below_cam_relative
/* 321440 802BD8F0 AFA20020 */   sw       $v0, 0x20($sp)
/* 321444 802BD8F4 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 321448 802BD8F8 4614003E */  c.le.s    $f0, $f20
/* 32144C 802BD8FC 00000000 */  nop
/* 321450 802BD900 4500001C */  bc1f      .L802BD974
/* 321454 802BD904 0040802D */   daddu    $s0, $v0, $zero
/* 321458 802BD908 0600001A */  bltz      $s0, .L802BD974
/* 32145C 802BD90C 32024000 */   andi     $v0, $s0, 0x4000
/* 321460 802BD910 10400007 */  beqz      $v0, .L802BD930
/* 321464 802BD914 00000000 */   nop
/* 321468 802BD918 0C0441A9 */  jal       get_entity_type
/* 32146C 802BD91C 0200202D */   daddu    $a0, $s0, $zero
/* 321470 802BD920 2442FFD2 */  addiu     $v0, $v0, -0x2e
/* 321474 802BD924 2C420002 */  sltiu     $v0, $v0, 2
/* 321478 802BD928 14400013 */  bnez      $v0, .L802BD978
/* 32147C 802BD92C 0280102D */   daddu    $v0, $s4, $zero
.L802BD930:
/* 321480 802BD930 0C016F6A */  jal       get_collider_type_by_id
/* 321484 802BD934 0200202D */   daddu    $a0, $s0, $zero
/* 321488 802BD938 305000FF */  andi      $s0, $v0, 0xff
/* 32148C 802BD93C 2602FFFF */  addiu     $v0, $s0, -1
/* 321490 802BD940 2C420003 */  sltiu     $v0, $v0, 3
/* 321494 802BD944 1440000C */  bnez      $v0, .L802BD978
/* 321498 802BD948 0280102D */   daddu    $v0, $s4, $zero
/* 32149C 802BD94C 24020005 */  addiu     $v0, $zero, 5
/* 3214A0 802BD950 12020009 */  beq       $s0, $v0, .L802BD978
/* 3214A4 802BD954 0280102D */   daddu    $v0, $s4, $zero
/* 3214A8 802BD958 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 3214AC 802BD95C C7A20030 */  lwc1      $f2, 0x30($sp)
/* 3214B0 802BD960 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* 3214B4 802BD964 24140001 */  addiu     $s4, $zero, 1
/* 3214B8 802BD968 E6400060 */  swc1      $f0, 0x60($s2)
/* 3214BC 802BD96C E6420064 */  swc1      $f2, 0x64($s2)
/* 3214C0 802BD970 E6440068 */  swc1      $f4, 0x68($s2)
.L802BD974:
/* 3214C4 802BD974 0280102D */  daddu     $v0, $s4, $zero
.L802BD978:
/* 3214C8 802BD978 8FBF005C */  lw        $ra, 0x5c($sp)
/* 3214CC 802BD97C 8FB40058 */  lw        $s4, 0x58($sp)
/* 3214D0 802BD980 8FB30054 */  lw        $s3, 0x54($sp)
/* 3214D4 802BD984 8FB20050 */  lw        $s2, 0x50($sp)
/* 3214D8 802BD988 8FB1004C */  lw        $s1, 0x4c($sp)
/* 3214DC 802BD98C 8FB00048 */  lw        $s0, 0x48($sp)
/* 3214E0 802BD990 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 3214E4 802BD994 03E00008 */  jr        $ra
/* 3214E8 802BD998 27BD0068 */   addiu    $sp, $sp, 0x68
