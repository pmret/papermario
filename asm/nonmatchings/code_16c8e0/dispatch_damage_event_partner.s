.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dispatch_damage_event_partner
/* 1AE2AC 8027F9CC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1AE2B0 8027F9D0 AFB30024 */  sw        $s3, 0x24($sp)
/* 1AE2B4 8027F9D4 00A0982D */  daddu     $s3, $a1, $zero
/* 1AE2B8 8027F9D8 AFB20020 */  sw        $s2, 0x20($sp)
/* 1AE2BC 8027F9DC 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 1AE2C0 8027F9E0 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 1AE2C4 8027F9E4 00041400 */  sll       $v0, $a0, 0x10
/* 1AE2C8 8027F9E8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 1AE2CC 8027F9EC AFB40028 */  sw        $s4, 0x28($sp)
/* 1AE2D0 8027F9F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1AE2D4 8027F9F4 AFB00018 */  sw        $s0, 0x18($sp)
/* 1AE2D8 8027F9F8 8E5000DC */  lw        $s0, 0xdc($s2)
/* 1AE2DC 8027F9FC 00022C03 */  sra       $a1, $v0, 0x10
/* 1AE2E0 8027FA00 A644017E */  sh        $a0, 0x17e($s2)
/* 1AE2E4 8027FA04 960301FA */  lhu       $v1, 0x1fa($s0)
/* 1AE2E8 8027FA08 2402007F */  addiu     $v0, $zero, 0x7f
/* 1AE2EC 8027FA0C A20201B8 */  sb        $v0, 0x1b8($s0)
/* 1AE2F0 8027FA10 00651821 */  addu      $v1, $v1, $a1
/* 1AE2F4 8027FA14 00031400 */  sll       $v0, $v1, 0x10
/* 1AE2F8 8027FA18 00022C03 */  sra       $a1, $v0, 0x10
/* 1AE2FC 8027FA1C 960201FC */  lhu       $v0, 0x1fc($s0)
/* 1AE300 8027FA20 00C0A02D */  daddu     $s4, $a2, $zero
/* 1AE304 8027FA24 A60301FA */  sh        $v1, 0x1fa($s0)
/* 1AE308 8027FA28 00651823 */  subu      $v1, $v1, $a1
/* 1AE30C 8027FA2C A60301FA */  sh        $v1, 0x1fa($s0)
/* 1AE310 8027FA30 00451021 */  addu      $v0, $v0, $a1
/* 1AE314 8027FA34 A60201FC */  sh        $v0, 0x1fc($s0)
/* 1AE318 8027FA38 A6400180 */  sh        $zero, 0x180($s2)
/* 1AE31C 8027FA3C 920201B8 */  lbu       $v0, 0x1b8($s0)
/* 1AE320 8027FA40 00451023 */  subu      $v0, $v0, $a1
/* 1AE324 8027FA44 A20201B8 */  sb        $v0, 0x1b8($s0)
/* 1AE328 8027FA48 00021600 */  sll       $v0, $v0, 0x18
/* 1AE32C 8027FA4C 00021E03 */  sra       $v1, $v0, 0x18
/* 1AE330 8027FA50 1C600006 */  bgtz      $v1, .L8027FA6C
/* 1AE334 8027FA54 2611000C */   addiu    $s1, $s0, 0xc
/* 1AE338 8027FA58 96420180 */  lhu       $v0, 0x180($s2)
/* 1AE33C 8027FA5C 24130020 */  addiu     $s3, $zero, 0x20
/* 1AE340 8027FA60 00431021 */  addu      $v0, $v0, $v1
/* 1AE344 8027FA64 A6420180 */  sh        $v0, 0x180($s2)
/* 1AE348 8027FA68 A20001B8 */  sb        $zero, 0x1b8($s0)
.L8027FA6C:
/* 1AE34C 8027FA6C 96420180 */  lhu       $v0, 0x180($s2)
/* 1AE350 8027FA70 00451021 */  addu      $v0, $v0, $a1
/* 1AE354 8027FA74 A6420180 */  sh        $v0, 0x180($s2)
/* 1AE358 8027FA78 A60201F8 */  sh        $v0, 0x1f8($s0)
/* 1AE35C 8027FA7C 8E420000 */  lw        $v0, ($s2)
/* 1AE360 8027FA80 30420020 */  andi      $v0, $v0, 0x20
/* 1AE364 8027FA84 10400007 */  beqz      $v0, .L8027FAA4
/* 1AE368 8027FA88 A240019A */   sb       $zero, 0x19a($s2)
/* 1AE36C 8027FA8C 24020009 */  addiu     $v0, $zero, 9
/* 1AE370 8027FA90 52620001 */  beql      $s3, $v0, .L8027FA98
/* 1AE374 8027FA94 2413000A */   addiu    $s3, $zero, 0xa
.L8027FA98:
/* 1AE378 8027FA98 24020017 */  addiu     $v0, $zero, 0x17
/* 1AE37C 8027FA9C 52620001 */  beql      $s3, $v0, .L8027FAA4
/* 1AE380 8027FAA0 24130019 */   addiu    $s3, $zero, 0x19
.L8027FAA4:
/* 1AE384 8027FAA4 86420180 */  lh        $v0, 0x180($s2)
/* 1AE388 8027FAA8 18400009 */  blez      $v0, .L8027FAD0
/* 1AE38C 8027FAAC 0200202D */   daddu    $a0, $s0, $zero
/* 1AE390 8027FAB0 2405000D */  addiu     $a1, $zero, 0xd
/* 1AE394 8027FAB4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AE398 8027FAB8 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AE39C 8027FABC 8C620000 */  lw        $v0, ($v1)
/* 1AE3A0 8027FAC0 86460180 */  lh        $a2, 0x180($s2)
/* 1AE3A4 8027FAC4 34420020 */  ori       $v0, $v0, 0x20
/* 1AE3A8 8027FAC8 0C0997D0 */  jal       inflict_status
/* 1AE3AC 8027FACC AC620000 */   sw       $v0, ($v1)
.L8027FAD0:
/* 1AE3B0 8027FAD0 16800006 */  bnez      $s4, .L8027FAEC
/* 1AE3B4 8027FAD4 24020001 */   addiu    $v0, $zero, 1
/* 1AE3B8 8027FAD8 0220202D */  daddu     $a0, $s1, $zero
/* 1AE3BC 8027FADC 24050100 */  addiu     $a1, $zero, 0x100
/* 1AE3C0 8027FAE0 0C09A5D5 */  jal       set_goal_pos_to_part
/* 1AE3C4 8027FAE4 0000302D */   daddu    $a2, $zero, $zero
/* 1AE3C8 8027FAE8 24020001 */  addiu     $v0, $zero, 1
.L8027FAEC:
/* 1AE3CC 8027FAEC AFA20010 */  sw        $v0, 0x10($sp)
/* 1AE3D0 8027FAF0 8E260014 */  lw        $a2, 0x14($s1)
/* 1AE3D4 8027FAF4 86470180 */  lh        $a3, 0x180($s2)
/* 1AE3D8 8027FAF8 C62C000C */  lwc1      $f12, 0xc($s1)
/* 1AE3DC 8027FAFC 0C09996B */  jal       show_damage_popup
/* 1AE3E0 8027FB00 C62E0010 */   lwc1     $f14, 0x10($s1)
/* 1AE3E4 8027FB04 86420180 */  lh        $v0, 0x180($s2)
/* 1AE3E8 8027FB08 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AE3EC 8027FB0C 8E25000C */  lw        $a1, 0xc($s1)
/* 1AE3F0 8027FB10 8E260010 */  lw        $a2, 0x10($s1)
/* 1AE3F4 8027FB14 8E270014 */  lw        $a3, 0x14($s1)
/* 1AE3F8 8027FB18 0C0999B9 */  jal       func_802666E4
/* 1AE3FC 8027FB1C 0200202D */   daddu    $a0, $s0, $zero
/* 1AE400 8027FB20 86420180 */  lh        $v0, 0x180($s2)
/* 1AE404 8027FB24 18400003 */  blez      $v0, .L8027FB34
/* 1AE408 8027FB28 0200202D */   daddu    $a0, $s0, $zero
/* 1AE40C 8027FB2C 0C099C06 */  jal       func_80267018
/* 1AE410 8027FB30 24050001 */   addiu    $a1, $zero, 1
.L8027FB34:
/* 1AE414 8027FB34 8E020000 */  lw        $v0, ($s0)
/* 1AE418 8027FB38 3C030008 */  lui       $v1, 8
/* 1AE41C 8027FB3C 00431025 */  or        $v0, $v0, $v1
/* 1AE420 8027FB40 AE020000 */  sw        $v0, ($s0)
/* 1AE424 8027FB44 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1AE428 8027FB48 8E10C070 */  lw        $s0, %lo(gBattleStatus)($s0)
/* 1AE42C 8027FB4C 0260202D */  daddu     $a0, $s3, $zero
/* 1AE430 8027FB50 32100240 */  andi      $s0, $s0, 0x240
/* 1AE434 8027FB54 0C09F7A0 */  jal       dispatch_event_partner
/* 1AE438 8027FB58 0010802B */   sltu     $s0, $zero, $s0
/* 1AE43C 8027FB5C 0200102D */  daddu     $v0, $s0, $zero
/* 1AE440 8027FB60 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1AE444 8027FB64 8FB40028 */  lw        $s4, 0x28($sp)
/* 1AE448 8027FB68 8FB30024 */  lw        $s3, 0x24($sp)
/* 1AE44C 8027FB6C 8FB20020 */  lw        $s2, 0x20($sp)
/* 1AE450 8027FB70 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1AE454 8027FB74 8FB00018 */  lw        $s0, 0x18($sp)
/* 1AE458 8027FB78 03E00008 */  jr        $ra
/* 1AE45C 8027FB7C 27BD0030 */   addiu    $sp, $sp, 0x30
