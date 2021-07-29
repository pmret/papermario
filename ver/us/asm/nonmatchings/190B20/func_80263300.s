.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80263300
/* 191BE0 80263300 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 191BE4 80263304 AFB40020 */  sw        $s4, 0x20($sp)
/* 191BE8 80263308 0000A02D */  daddu     $s4, $zero, $zero
/* 191BEC 8026330C AFB20018 */  sw        $s2, 0x18($sp)
/* 191BF0 80263310 0280902D */  daddu     $s2, $s4, $zero
/* 191BF4 80263314 AFB60028 */  sw        $s6, 0x28($sp)
/* 191BF8 80263318 3C168008 */  lui       $s6, %hi(gItemTable)
/* 191BFC 8026331C 26D678E0 */  addiu     $s6, $s6, %lo(gItemTable)
/* 191C00 80263320 AFB50024 */  sw        $s5, 0x24($sp)
/* 191C04 80263324 24150002 */  addiu     $s5, $zero, 2
/* 191C08 80263328 AFB10014 */  sw        $s1, 0x14($sp)
/* 191C0C 8026332C 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 191C10 80263330 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 191C14 80263334 AFBF002C */  sw        $ra, 0x2c($sp)
/* 191C18 80263338 AFB3001C */  sw        $s3, 0x1c($sp)
/* 191C1C 8026333C AFB00010 */  sw        $s0, 0x10($sp)
/* 191C20 80263340 8E3300D8 */  lw        $s3, 0xd8($s1)
/* 191C24 80263344 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 191C28 80263348 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 191C2C 8026334C A220007D */  sb        $zero, 0x7d($s1)
.L80263350:
/* 191C30 80263350 860201B4 */  lh        $v0, 0x1b4($s0)
/* 191C34 80263354 50400015 */  beql      $v0, $zero, .L802633AC
/* 191C38 80263358 26520001 */   addiu    $s2, $s2, 1
/* 191C3C 8026335C 00021140 */  sll       $v0, $v0, 5
/* 191C40 80263360 00561821 */  addu      $v1, $v0, $s6
/* 191C44 80263364 94620018 */  lhu       $v0, 0x18($v1)
/* 191C48 80263368 30420002 */  andi      $v0, $v0, 2
/* 191C4C 8026336C 5040000F */  beql      $v0, $zero, .L802633AC
/* 191C50 80263370 26520001 */   addiu    $s2, $s2, 1
/* 191C54 80263374 A2350178 */  sb        $s5, 0x178($s1)
/* 191C58 80263378 960201B4 */  lhu       $v0, 0x1b4($s0)
/* 191C5C 8026337C A622017A */  sh        $v0, 0x17a($s1)
/* 191C60 80263380 8C620008 */  lw        $v0, 8($v1)
/* 191C64 80263384 0260202D */  daddu     $a0, $s3, $zero
/* 191C68 80263388 0C098C0B */  jal       player_create_target_list
/* 191C6C 8026338C AE220184 */   sw       $v0, 0x184($s1)
/* 191C70 80263390 8262040C */  lb        $v0, 0x40c($s3)
/* 191C74 80263394 10400005 */  beqz      $v0, .L802633AC
/* 191C78 80263398 26520001 */   addiu    $s2, $s2, 1
/* 191C7C 8026339C 9222007D */  lbu       $v0, 0x7d($s1)
/* 191C80 802633A0 24140001 */  addiu     $s4, $zero, 1
/* 191C84 802633A4 00541021 */  addu      $v0, $v0, $s4
/* 191C88 802633A8 A222007D */  sb        $v0, 0x7d($s1)
.L802633AC:
/* 191C8C 802633AC 2A42000A */  slti      $v0, $s2, 0xa
/* 191C90 802633B0 1440FFE7 */  bnez      $v0, .L80263350
/* 191C94 802633B4 26100002 */   addiu    $s0, $s0, 2
/* 191C98 802633B8 52800001 */  beql      $s4, $zero, .L802633C0
/* 191C9C 802633BC A220007D */   sb       $zero, 0x7d($s1)
.L802633C0:
/* 191CA0 802633C0 8FBF002C */  lw        $ra, 0x2c($sp)
/* 191CA4 802633C4 8FB60028 */  lw        $s6, 0x28($sp)
/* 191CA8 802633C8 8FB50024 */  lw        $s5, 0x24($sp)
/* 191CAC 802633CC 8FB40020 */  lw        $s4, 0x20($sp)
/* 191CB0 802633D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 191CB4 802633D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 191CB8 802633D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 191CBC 802633DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 191CC0 802633E0 03E00008 */  jr        $ra
/* 191CC4 802633E4 27BD0030 */   addiu    $sp, $sp, 0x30
