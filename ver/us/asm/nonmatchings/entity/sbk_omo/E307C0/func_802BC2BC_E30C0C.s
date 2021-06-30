.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC2BC_E30C0C
/* E30C0C 802BC2BC 3C058016 */  lui       $a1, %hi(gCollisionStatus+0x2)
/* E30C10 802BC2C0 94A5A552 */  lhu       $a1, %lo(gCollisionStatus+0x2)($a1)
/* E30C14 802BC2C4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* E30C18 802BC2C8 AFB20038 */  sw        $s2, 0x38($sp)
/* E30C1C 802BC2CC 0080902D */  daddu     $s2, $a0, $zero
/* E30C20 802BC2D0 AFB3003C */  sw        $s3, 0x3c($sp)
/* E30C24 802BC2D4 AFB50044 */  sw        $s5, 0x44($sp)
/* E30C28 802BC2D8 3C158011 */  lui       $s5, %hi(gPlayerStatus)
/* E30C2C 802BC2DC 26B5EFC8 */  addiu     $s5, $s5, %lo(gPlayerStatus)
/* E30C30 802BC2E0 AFBF0048 */  sw        $ra, 0x48($sp)
/* E30C34 802BC2E4 AFB40040 */  sw        $s4, 0x40($sp)
/* E30C38 802BC2E8 AFB10034 */  sw        $s1, 0x34($sp)
/* E30C3C 802BC2EC AFB00030 */  sw        $s0, 0x30($sp)
/* E30C40 802BC2F0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* E30C44 802BC2F4 8E540040 */  lw        $s4, 0x40($s2)
/* E30C48 802BC2F8 82A400B4 */  lb        $a0, 0xb4($s5)
/* E30C4C 802BC2FC 30A24000 */  andi      $v0, $a1, 0x4000
/* E30C50 802BC300 1040002E */  beqz      $v0, .L802BC3BC
/* E30C54 802BC304 0000982D */   daddu    $s3, $zero, $zero
/* E30C58 802BC308 92430004 */  lbu       $v1, 4($s2)
/* E30C5C 802BC30C 30A200FF */  andi      $v0, $a1, 0xff
/* E30C60 802BC310 1443002A */  bne       $v0, $v1, .L802BC3BC
/* E30C64 802BC314 24020012 */   addiu    $v0, $zero, 0x12
/* E30C68 802BC318 14820028 */  bne       $a0, $v0, .L802BC3BC
/* E30C6C 802BC31C 00000000 */   nop
/* E30C70 802BC320 C6A00028 */  lwc1      $f0, 0x28($s5)
/* E30C74 802BC324 3C0140A0 */  lui       $at, 0x40a0
/* E30C78 802BC328 44811000 */  mtc1      $at, $f2
/* E30C7C 802BC32C 3C014120 */  lui       $at, 0x4120
/* E30C80 802BC330 4481A000 */  mtc1      $at, $f20
/* E30C84 802BC334 E7A00020 */  swc1      $f0, 0x20($sp)
/* E30C88 802BC338 C6A0002C */  lwc1      $f0, 0x2c($s5)
/* E30C8C 802BC33C C6A40030 */  lwc1      $f4, 0x30($s5)
/* E30C90 802BC340 46020000 */  add.s     $f0, $f0, $f2
/* E30C94 802BC344 E7B4002C */  swc1      $f20, 0x2c($sp)
/* E30C98 802BC348 E7A40024 */  swc1      $f4, 0x24($sp)
/* E30C9C 802BC34C 0C0394D2 */  jal       func_800E5348
/* E30CA0 802BC350 E7A00028 */   swc1     $f0, 0x28($sp)
/* E30CA4 802BC354 27B10020 */  addiu     $s1, $sp, 0x20
/* E30CA8 802BC358 0220202D */  daddu     $a0, $s1, $zero
/* E30CAC 802BC35C 27B00024 */  addiu     $s0, $sp, 0x24
/* E30CB0 802BC360 4406A000 */  mfc1      $a2, $f20
/* E30CB4 802BC364 44070000 */  mfc1      $a3, $f0
/* E30CB8 802BC368 0C00A7E7 */  jal       add_vec2D_polar
/* E30CBC 802BC36C 0200282D */   daddu    $a1, $s0, $zero
/* E30CC0 802BC370 3C040001 */  lui       $a0, 1
/* E30CC4 802BC374 0220282D */  daddu     $a1, $s1, $zero
/* E30CC8 802BC378 27A60028 */  addiu     $a2, $sp, 0x28
/* E30CCC 802BC37C 0200382D */  daddu     $a3, $s0, $zero
/* E30CD0 802BC380 27A2002C */  addiu     $v0, $sp, 0x2c
/* E30CD4 802BC384 0C0372DF */  jal       npc_raycast_down_sides
/* E30CD8 802BC388 AFA20010 */   sw       $v0, 0x10($sp)
/* E30CDC 802BC38C 10400019 */  beqz      $v0, .L802BC3F4
/* E30CE0 802BC390 00000000 */   nop
/* E30CE4 802BC394 3C048011 */  lui       $a0, %hi(D_8010C978)
/* E30CE8 802BC398 8C84C978 */  lw        $a0, %lo(D_8010C978)($a0)
/* E30CEC 802BC39C 30824000 */  andi      $v0, $a0, 0x4000
/* E30CF0 802BC3A0 10400014 */  beqz      $v0, .L802BC3F4
/* E30CF4 802BC3A4 00000000 */   nop
/* E30CF8 802BC3A8 0C0441A9 */  jal       get_entity_type
/* E30CFC 802BC3AC 00000000 */   nop
/* E30D00 802BC3B0 38420031 */  xori      $v0, $v0, 0x31
/* E30D04 802BC3B4 080AF0FD */  j         .L802BC3F4
/* E30D08 802BC3B8 2C530001 */   sltiu    $s3, $v0, 1
.L802BC3BC:
/* E30D0C 802BC3BC 92420006 */  lbu       $v0, 6($s2)
/* E30D10 802BC3C0 30420001 */  andi      $v0, $v0, 1
/* E30D14 802BC3C4 10400007 */  beqz      $v0, .L802BC3E4
/* E30D18 802BC3C8 2402000E */   addiu    $v0, $zero, 0xe
/* E30D1C 802BC3CC 10820003 */  beq       $a0, $v0, .L802BC3DC
/* E30D20 802BC3D0 24020010 */   addiu    $v0, $zero, 0x10
/* E30D24 802BC3D4 14820003 */  bne       $a0, $v0, .L802BC3E4
/* E30D28 802BC3D8 00000000 */   nop
.L802BC3DC:
/* E30D2C 802BC3DC 080AF0FD */  j         .L802BC3F4
/* E30D30 802BC3E0 24130001 */   addiu    $s3, $zero, 1
.L802BC3E4:
/* E30D34 802BC3E4 92420006 */  lbu       $v0, 6($s2)
/* E30D38 802BC3E8 30420040 */  andi      $v0, $v0, 0x40
/* E30D3C 802BC3EC 54400001 */  bnel      $v0, $zero, .L802BC3F4
/* E30D40 802BC3F0 2413FFFF */   addiu    $s3, $zero, -1
.L802BC3F4:
/* E30D44 802BC3F4 12600026 */  beqz      $s3, .L802BC490
/* E30D48 802BC3F8 00000000 */   nop
/* E30D4C 802BC3FC 92820002 */  lbu       $v0, 2($s4)
/* E30D50 802BC400 3C01BF80 */  lui       $at, 0xbf80
/* E30D54 802BC404 44810000 */  mtc1      $at, $f0
/* E30D58 802BC408 304200FE */  andi      $v0, $v0, 0xfe
/* E30D5C 802BC40C A2820002 */  sb        $v0, 2($s4)
/* E30D60 802BC410 C642004C */  lwc1      $f2, 0x4c($s2)
/* E30D64 802BC414 E7A00014 */  swc1      $f0, 0x14($sp)
/* E30D68 802BC418 3C01420C */  lui       $at, 0x420c
/* E30D6C 802BC41C 44810000 */  mtc1      $at, $f0
/* E30D70 802BC420 24020003 */  addiu     $v0, $zero, 3
/* E30D74 802BC424 AFA00010 */  sw        $zero, 0x10($sp)
/* E30D78 802BC428 AFA00018 */  sw        $zero, 0x18($sp)
/* E30D7C 802BC42C AFA2001C */  sw        $v0, 0x1c($sp)
/* E30D80 802BC430 46001080 */  add.s     $f2, $f2, $f0
/* E30D84 802BC434 8E450048 */  lw        $a1, 0x48($s2)
/* E30D88 802BC438 8E470050 */  lw        $a3, 0x50($s2)
/* E30D8C 802BC43C 44061000 */  mfc1      $a2, $f2
/* E30D90 802BC440 0C01C064 */  jal       playFX_18
/* E30D94 802BC444 0040202D */   daddu    $a0, $v0, $zero
/* E30D98 802BC448 1A600004 */  blez      $s3, .L802BC45C
/* E30D9C 802BC44C 00000000 */   nop
/* E30DA0 802BC450 92820002 */  lbu       $v0, 2($s4)
/* E30DA4 802BC454 34420001 */  ori       $v0, $v0, 1
/* E30DA8 802BC458 A2820002 */  sb        $v0, 2($s4)
.L802BC45C:
/* E30DAC 802BC45C C640004C */  lwc1      $f0, 0x4c($s2)
/* E30DB0 802BC460 3C014000 */  lui       $at, 0x4000
/* E30DB4 802BC464 44811000 */  mtc1      $at, $f2
/* E30DB8 802BC468 00000000 */  nop
/* E30DBC 802BC46C 46020001 */  sub.s     $f0, $f0, $f2
/* E30DC0 802BC470 0240202D */  daddu     $a0, $s2, $zero
/* E30DC4 802BC474 0C043F5A */  jal       exec_entity_commandlist
/* E30DC8 802BC478 E480004C */   swc1     $f0, 0x4c($a0)
/* E30DCC 802BC47C 24020004 */  addiu     $v0, $zero, 4
/* E30DD0 802BC480 0C038045 */  jal       disable_player_static_collisions
/* E30DD4 802BC484 A2820001 */   sb       $v0, 1($s4)
/* E30DD8 802BC488 24020005 */  addiu     $v0, $zero, 5
/* E30DDC 802BC48C A2A200C5 */  sb        $v0, 0xc5($s5)
.L802BC490:
/* E30DE0 802BC490 8FBF0048 */  lw        $ra, 0x48($sp)
/* E30DE4 802BC494 8FB50044 */  lw        $s5, 0x44($sp)
/* E30DE8 802BC498 8FB40040 */  lw        $s4, 0x40($sp)
/* E30DEC 802BC49C 8FB3003C */  lw        $s3, 0x3c($sp)
/* E30DF0 802BC4A0 8FB20038 */  lw        $s2, 0x38($sp)
/* E30DF4 802BC4A4 8FB10034 */  lw        $s1, 0x34($sp)
/* E30DF8 802BC4A8 8FB00030 */  lw        $s0, 0x30($sp)
/* E30DFC 802BC4AC D7B40050 */  ldc1      $f20, 0x50($sp)
/* E30E00 802BC4B0 03E00008 */  jr        $ra
/* E30E04 802BC4B4 27BD0058 */   addiu    $sp, $sp, 0x58
