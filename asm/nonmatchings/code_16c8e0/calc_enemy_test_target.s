.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel calc_enemy_test_target
/* 1A5AD8 802771F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A5ADC 802771FC AFB20018 */  sw        $s2, 0x18($sp)
/* 1A5AE0 80277200 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 1A5AE4 80277204 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 1A5AE8 80277208 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1A5AEC 8027720C AFB3001C */  sw        $s3, 0x1c($sp)
/* 1A5AF0 80277210 AFB10014 */  sw        $s1, 0x14($sp)
/* 1A5AF4 80277214 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A5AF8 80277218 964301A0 */  lhu       $v1, 0x1a0($s2)
/* 1A5AFC 8027721C 865301A0 */  lh        $s3, 0x1a0($s2)
/* 1A5B00 80277220 924201A2 */  lbu       $v0, 0x1a2($s2)
/* 1A5B04 80277224 825101A2 */  lb        $s1, 0x1a2($s2)
/* 1A5B08 80277228 0260202D */  daddu     $a0, $s3, $zero
/* 1A5B0C 8027722C A64301A4 */  sh        $v1, 0x1a4($s2)
/* 1A5B10 80277230 0C09A75B */  jal       get_actor
/* 1A5B14 80277234 A24201A6 */   sb       $v0, 0x1a6($s2)
/* 1A5B18 80277238 0040802D */  daddu     $s0, $v0, $zero
/* 1A5B1C 8027723C 1200001C */  beqz      $s0, .L802772B0
/* 1A5B20 80277240 0200202D */   daddu    $a0, $s0, $zero
/* 1A5B24 80277244 0C099117 */  jal       get_actor_part
/* 1A5B28 80277248 0220282D */   daddu    $a1, $s1, $zero
/* 1A5B2C 8027724C 0040182D */  daddu     $v1, $v0, $zero
/* 1A5B30 80277250 14600003 */  bnez      $v1, .L80277260
/* 1A5B34 80277254 32640700 */   andi     $a0, $s3, 0x700
.L80277258:
/* 1A5B38 80277258 0809DC96 */  j         .L80277258
/* 1A5B3C 8027725C 00000000 */   nop      
.L80277260:
/* 1A5B40 80277260 24020100 */  addiu     $v0, $zero, 0x100
/* 1A5B44 80277264 1082000A */  beq       $a0, $v0, .L80277290
/* 1A5B48 80277268 28820101 */   slti     $v0, $a0, 0x101
/* 1A5B4C 8027726C 1040000A */  beqz      $v0, .L80277298
/* 1A5B50 80277270 00000000 */   nop      
/* 1A5B54 80277274 14800008 */  bnez      $a0, .L80277298
/* 1A5B58 80277278 00000000 */   nop      
/* 1A5B5C 8027727C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 1A5B60 80277280 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 1A5B64 80277284 90420002 */  lbu       $v0, 2($v0)
/* 1A5B68 80277288 0809DCA6 */  j         .L80277298
/* 1A5B6C 8027728C A20201B8 */   sb       $v0, 0x1b8($s0)
.L80277290:
/* 1A5B70 80277290 2402007F */  addiu     $v0, $zero, 0x7f
/* 1A5B74 80277294 A20201B8 */  sb        $v0, 0x1b8($s0)
.L80277298:
/* 1A5B78 80277298 8E420188 */  lw        $v0, 0x188($s2)
/* 1A5B7C 8027729C 04410006 */  bgez      $v0, .L802772B8
/* 1A5B80 802772A0 00000000 */   nop      
/* 1A5B84 802772A4 0200202D */  daddu     $a0, $s0, $zero
/* 1A5B88 802772A8 0C09DBE3 */  jal       dispatch_event_general
/* 1A5B8C 802772AC 24050037 */   addiu    $a1, $zero, 0x37
.L802772B0:
/* 1A5B90 802772B0 0809DD04 */  j         .L80277410
/* 1A5B94 802772B4 0000102D */   daddu    $v0, $zero, $zero
.L802772B8:
/* 1A5B98 802772B8 8C62007C */  lw        $v0, 0x7c($v1)
/* 1A5B9C 802772BC 30420020 */  andi      $v0, $v0, 0x20
/* 1A5BA0 802772C0 14400007 */  bnez      $v0, .L802772E0
/* 1A5BA4 802772C4 0000882D */   daddu    $s1, $zero, $zero
/* 1A5BA8 802772C8 8242009A */  lb        $v0, 0x9a($s2)
/* 1A5BAC 802772CC 14400004 */  bnez      $v0, .L802772E0
/* 1A5BB0 802772D0 2402000E */   addiu    $v0, $zero, 0xe
/* 1A5BB4 802772D4 82030218 */  lb        $v1, 0x218($s0)
/* 1A5BB8 802772D8 14620006 */  bne       $v1, $v0, .L802772F4
/* 1A5BBC 802772DC 24020006 */   addiu    $v0, $zero, 6
.L802772E0:
/* 1A5BC0 802772E0 8E420188 */  lw        $v0, 0x188($s2)
/* 1A5BC4 802772E4 30420010 */  andi      $v0, $v0, 0x10
/* 1A5BC8 802772E8 50400001 */  beql      $v0, $zero, .L802772F0
/* 1A5BCC 802772EC 24110006 */   addiu    $s1, $zero, 6
.L802772F0:
/* 1A5BD0 802772F0 24020006 */  addiu     $v0, $zero, 6
.L802772F4:
/* 1A5BD4 802772F4 12220046 */  beq       $s1, $v0, .L80277410
/* 1A5BD8 802772F8 00000000 */   nop      
/* 1A5BDC 802772FC 24020100 */  addiu     $v0, $zero, 0x100
/* 1A5BE0 80277300 10820033 */  beq       $a0, $v0, .L802773D0
/* 1A5BE4 80277304 0000882D */   daddu    $s1, $zero, $zero
/* 1A5BE8 80277308 28820101 */  slti      $v0, $a0, 0x101
/* 1A5BEC 8027730C 10400031 */  beqz      $v0, .L802773D4
/* 1A5BF0 80277310 24020006 */   addiu    $v0, $zero, 6
/* 1A5BF4 80277314 1480002F */  bnez      $a0, .L802773D4
/* 1A5BF8 80277318 00000000 */   nop      
/* 1A5BFC 8027731C 824200A4 */  lb        $v0, 0xa4($s2)
/* 1A5C00 80277320 10400009 */  beqz      $v0, .L80277348
/* 1A5C04 80277324 0200202D */   daddu    $a0, $s0, $zero
/* 1A5C08 80277328 0C00A67F */  jal       rand_int
/* 1A5C0C 8027732C 24040064 */   addiu    $a0, $zero, 0x64
/* 1A5C10 80277330 824300A5 */  lb        $v1, 0xa5($s2)
/* 1A5C14 80277334 0043102A */  slt       $v0, $v0, $v1
/* 1A5C18 80277338 54400025 */  bnel      $v0, $zero, .L802773D0
/* 1A5C1C 8027733C 24110006 */   addiu    $s1, $zero, 6
/* 1A5C20 80277340 0809DCF5 */  j         .L802773D4
/* 1A5C24 80277344 24020006 */   addiu    $v0, $zero, 6
.L80277348:
/* 1A5C28 80277348 0C099CAB */  jal       heroes_is_ability_active
/* 1A5C2C 8027734C 24050008 */   addiu    $a1, $zero, 8
/* 1A5C30 80277350 10400007 */  beqz      $v0, .L80277370
/* 1A5C34 80277354 0200202D */   daddu    $a0, $s0, $zero
/* 1A5C38 80277358 0C00A67F */  jal       rand_int
/* 1A5C3C 8027735C 24040064 */   addiu    $a0, $zero, 0x64
/* 1A5C40 80277360 2842000A */  slti      $v0, $v0, 0xa
/* 1A5C44 80277364 5440001A */  bnel      $v0, $zero, .L802773D0
/* 1A5C48 80277368 24110005 */   addiu    $s1, $zero, 5
/* 1A5C4C 8027736C 0200202D */  daddu     $a0, $s0, $zero
.L80277370:
/* 1A5C50 80277370 0C099CAB */  jal       heroes_is_ability_active
/* 1A5C54 80277374 24050021 */   addiu    $a1, $zero, 0x21
/* 1A5C58 80277378 1040000B */  beqz      $v0, .L802773A8
/* 1A5C5C 8027737C 0200202D */   daddu    $a0, $s0, $zero
/* 1A5C60 80277380 820201B8 */  lb        $v0, 0x1b8($s0)
/* 1A5C64 80277384 28420006 */  slti      $v0, $v0, 6
/* 1A5C68 80277388 10400007 */  beqz      $v0, .L802773A8
/* 1A5C6C 8027738C 00000000 */   nop      
/* 1A5C70 80277390 0C00A67F */  jal       rand_int
/* 1A5C74 80277394 24040064 */   addiu    $a0, $zero, 0x64
/* 1A5C78 80277398 2842001E */  slti      $v0, $v0, 0x1e
/* 1A5C7C 8027739C 5440000C */  bnel      $v0, $zero, .L802773D0
/* 1A5C80 802773A0 24110005 */   addiu    $s1, $zero, 5
/* 1A5C84 802773A4 0200202D */  daddu     $a0, $s0, $zero
.L802773A8:
/* 1A5C88 802773A8 0C099CAB */  jal       heroes_is_ability_active
/* 1A5C8C 802773AC 24050023 */   addiu    $a1, $zero, 0x23
/* 1A5C90 802773B0 10400008 */  beqz      $v0, .L802773D4
/* 1A5C94 802773B4 24020006 */   addiu    $v0, $zero, 6
/* 1A5C98 802773B8 0C00A67F */  jal       rand_int
/* 1A5C9C 802773BC 24040064 */   addiu    $a0, $zero, 0x64
/* 1A5CA0 802773C0 28420014 */  slti      $v0, $v0, 0x14
/* 1A5CA4 802773C4 10400003 */  beqz      $v0, .L802773D4
/* 1A5CA8 802773C8 24020006 */   addiu    $v0, $zero, 6
/* 1A5CAC 802773CC 24110005 */  addiu     $s1, $zero, 5
.L802773D0:
/* 1A5CB0 802773D0 24020006 */  addiu     $v0, $zero, 6
.L802773D4:
/* 1A5CB4 802773D4 1222000E */  beq       $s1, $v0, .L80277410
/* 1A5CB8 802773D8 00000000 */   nop      
/* 1A5CBC 802773DC 24020005 */  addiu     $v0, $zero, 5
/* 1A5CC0 802773E0 1222000B */  beq       $s1, $v0, .L80277410
/* 1A5CC4 802773E4 00000000 */   nop      
/* 1A5CC8 802773E8 82030214 */  lb        $v1, 0x214($s0)
/* 1A5CCC 802773EC 2402000C */  addiu     $v0, $zero, 0xc
/* 1A5CD0 802773F0 10620006 */  beq       $v1, $v0, .L8027740C
/* 1A5CD4 802773F4 2403000B */   addiu    $v1, $zero, 0xb
/* 1A5CD8 802773F8 82040212 */  lb        $a0, 0x212($s0)
/* 1A5CDC 802773FC 10830004 */  beq       $a0, $v1, .L80277410
/* 1A5CE0 80277400 24020007 */   addiu    $v0, $zero, 7
/* 1A5CE4 80277404 0809DD04 */  j         .L80277410
/* 1A5CE8 80277408 0000102D */   daddu    $v0, $zero, $zero
.L8027740C:
/* 1A5CEC 8027740C 24020008 */  addiu     $v0, $zero, 8
.L80277410:
/* 1A5CF0 80277410 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1A5CF4 80277414 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A5CF8 80277418 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A5CFC 8027741C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A5D00 80277420 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A5D04 80277424 03E00008 */  jr        $ra
/* 1A5D08 80277428 27BD0028 */   addiu    $sp, $sp, 0x28
