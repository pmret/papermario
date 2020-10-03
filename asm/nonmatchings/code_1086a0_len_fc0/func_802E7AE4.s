.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7AE4
/* 109364 802E7AE4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 109368 802E7AE8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 10936C 802E7AEC 0080882D */  daddu     $s1, $a0, $zero
/* 109370 802E7AF0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 109374 802E7AF4 AFB00018 */  sw        $s0, 0x18($sp)
/* 109378 802E7AF8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 10937C 802E7AFC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 109380 802E7B00 8E300040 */  lw        $s0, 0x40($s1)
/* 109384 802E7B04 8E020010 */  lw        $v0, 0x10($s0)
/* 109388 802E7B08 2443FFFF */  addiu     $v1, $v0, -1
/* 10938C 802E7B0C 2C620006 */  sltiu     $v0, $v1, 6
/* 109390 802E7B10 1040001D */  beqz      $v0, .L802E7B88
/* 109394 802E7B14 00031080 */   sll      $v0, $v1, 2
/* 109398 802E7B18 3C01802F */  lui       $at, 0x802f
/* 10939C 802E7B1C 00220821 */  addu      $at, $at, $v0
/* 1093A0 802E7B20 8C22B330 */  lw        $v0, -0x4cd0($at)
/* 1093A4 802E7B24 00400008 */  jr        $v0
/* 1093A8 802E7B28 00000000 */   nop      
/* 1093AC 802E7B2C 3C018011 */  lui       $at, %hi(gPlayerData)
/* 1093B0 802E7B30 A020F290 */  sb        $zero, %lo(gPlayerData)($at)
/* 1093B4 802E7B34 080B9EE2 */  j         .L802E7B88
/* 1093B8 802E7B38 00000000 */   nop      
/* 1093BC 802E7B3C 24020001 */  addiu     $v0, $zero, 1
/* 1093C0 802E7B40 3C018011 */  lui       $at, %hi(gPlayerData)
/* 1093C4 802E7B44 A022F290 */  sb        $v0, %lo(gPlayerData)($at)
/* 1093C8 802E7B48 080B9EE2 */  j         .L802E7B88
/* 1093CC 802E7B4C 00000000 */   nop      
/* 1093D0 802E7B50 24020002 */  addiu     $v0, $zero, 2
/* 1093D4 802E7B54 3C018011 */  lui       $at, %hi(gPlayerData)
/* 1093D8 802E7B58 A022F290 */  sb        $v0, %lo(gPlayerData)($at)
/* 1093DC 802E7B5C 080B9EE2 */  j         .L802E7B88
/* 1093E0 802E7B60 00000000 */   nop      
/* 1093E4 802E7B64 3C018011 */  lui       $at, 0x8011
/* 1093E8 802E7B68 A020F291 */  sb        $zero, -0xd6f($at)
/* 1093EC 802E7B6C 080B9EE2 */  j         .L802E7B88
/* 1093F0 802E7B70 00000000 */   nop      
/* 1093F4 802E7B74 080B9EE0 */  j         .L802E7B80
/* 1093F8 802E7B78 24020001 */   addiu    $v0, $zero, 1
/* 1093FC 802E7B7C 24020002 */  addiu     $v0, $zero, 2
.L802E7B80:
/* 109400 802E7B80 3C018011 */  lui       $at, 0x8011
/* 109404 802E7B84 A022F291 */  sb        $v0, -0xd6f($at)
.L802E7B88:
/* 109408 802E7B88 8E020010 */  lw        $v0, 0x10($s0)
/* 10940C 802E7B8C 10400027 */  beqz      $v0, .L802E7C2C
/* 109410 802E7B90 00000000 */   nop      
/* 109414 802E7B94 C6340064 */  lwc1      $f20, 0x64($s1)
/* 109418 802E7B98 3C0140C9 */  lui       $at, 0x40c9
/* 10941C 802E7B9C 34210FD0 */  ori       $at, $at, 0xfd0
/* 109420 802E7BA0 44810000 */  mtc1      $at, $f0
/* 109424 802E7BA4 00000000 */  nop       
/* 109428 802E7BA8 4600A502 */  mul.s     $f20, $f20, $f0
/* 10942C 802E7BAC 00000000 */  nop       
/* 109430 802E7BB0 3C0143B4 */  lui       $at, 0x43b4
/* 109434 802E7BB4 44810000 */  mtc1      $at, $f0
/* 109438 802E7BB8 3C014120 */  lui       $at, 0x4120
/* 10943C 802E7BBC 4481B000 */  mtc1      $at, $f22
/* 109440 802E7BC0 4600A503 */  div.s     $f20, $f20, $f0
/* 109444 802E7BC4 0C00A85B */  jal       sin_rad
/* 109448 802E7BC8 4600A306 */   mov.s    $f12, $f20
/* 10944C 802E7BCC 46160002 */  mul.s     $f0, $f0, $f22
/* 109450 802E7BD0 00000000 */  nop       
/* 109454 802E7BD4 C6220048 */  lwc1      $f2, 0x48($s1)
/* 109458 802E7BD8 46001080 */  add.s     $f2, $f2, $f0
/* 10945C 802E7BDC E6020018 */  swc1      $f2, 0x18($s0)
/* 109460 802E7BE0 C620004C */  lwc1      $f0, 0x4c($s1)
/* 109464 802E7BE4 4600A306 */  mov.s     $f12, $f20
/* 109468 802E7BE8 0C00A874 */  jal       cos_rad
/* 10946C 802E7BEC E600001C */   swc1     $f0, 0x1c($s0)
/* 109470 802E7BF0 46160002 */  mul.s     $f0, $f0, $f22
/* 109474 802E7BF4 00000000 */  nop       
/* 109478 802E7BF8 C6220050 */  lwc1      $f2, 0x50($s1)
/* 10947C 802E7BFC 46001080 */  add.s     $f2, $f2, $f0
/* 109480 802E7C00 24020001 */  addiu     $v0, $zero, 1
/* 109484 802E7C04 E6020020 */  swc1      $f2, 0x20($s0)
/* 109488 802E7C08 AFA20010 */  sw        $v0, 0x10($sp)
/* 10948C 802E7C0C 2402FFFF */  addiu     $v0, $zero, -1
/* 109490 802E7C10 AFA20014 */  sw        $v0, 0x14($sp)
/* 109494 802E7C14 8E040010 */  lw        $a0, 0x10($s0)
/* 109498 802E7C18 8E050018 */  lw        $a1, 0x18($s0)
/* 10949C 802E7C1C 8E06001C */  lw        $a2, 0x1c($s0)
/* 1094A0 802E7C20 0C04C6A5 */  jal       make_item_entity_nodelay
/* 1094A4 802E7C24 8E070020 */   lw       $a3, 0x20($s0)
/* 1094A8 802E7C28 AE020014 */  sw        $v0, 0x14($s0)
.L802E7C2C:
/* 1094AC 802E7C2C 96040000 */  lhu       $a0, ($s0)
/* 1094B0 802E7C30 3C02F8D8 */  lui       $v0, 0xf8d8
/* 1094B4 802E7C34 3442F200 */  ori       $v0, $v0, 0xf200
/* 1094B8 802E7C38 0044102A */  slt       $v0, $v0, $a0
/* 1094BC 802E7C3C 14400003 */  bnez      $v0, .L802E7C4C
/* 1094C0 802E7C40 3C0207BF */   lui      $v0, 0x7bf
/* 1094C4 802E7C44 3442A480 */  ori       $v0, $v0, 0xa480
/* 1094C8 802E7C48 00822021 */  addu      $a0, $a0, $v0
.L802E7C4C:
/* 1094CC 802E7C4C 0C051514 */  jal       set_global_flag
/* 1094D0 802E7C50 00000000 */   nop      
/* 1094D4 802E7C54 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1094D8 802E7C58 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1094DC 802E7C5C 8FB00018 */  lw        $s0, 0x18($sp)
/* 1094E0 802E7C60 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 1094E4 802E7C64 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1094E8 802E7C68 03E00008 */  jr        $ra
/* 1094EC 802E7C6C 27BD0038 */   addiu    $sp, $sp, 0x38
