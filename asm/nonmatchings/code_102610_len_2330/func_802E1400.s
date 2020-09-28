.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1400
/* 102C80 802E1400 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102C84 802E1404 AFBF0014 */  sw        $ra, 0x14($sp)
/* 102C88 802E1408 AFB00010 */  sw        $s0, 0x10($sp)
/* 102C8C 802E140C 90820006 */  lbu       $v0, 6($a0)
/* 102C90 802E1410 8C900040 */  lw        $s0, 0x40($a0)
/* 102C94 802E1414 30420001 */  andi      $v0, $v0, 1
/* 102C98 802E1418 1040000D */  beqz      $v0, .L802E1450
/* 102C9C 802E141C 00000000 */   nop      
/* 102CA0 802E1420 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 102CA4 802E1424 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 102CA8 802E1428 804300B4 */  lb        $v1, 0xb4($v0)
/* 102CAC 802E142C 2402000E */  addiu     $v0, $zero, 0xe
/* 102CB0 802E1430 10620003 */  beq       $v1, $v0, .L802E1440
/* 102CB4 802E1434 24020010 */   addiu    $v0, $zero, 0x10
/* 102CB8 802E1438 14620005 */  bne       $v1, $v0, .L802E1450
/* 102CBC 802E143C 00000000 */   nop      
.L802E1440:
/* 102CC0 802E1440 0C043F5A */  jal       func_8010FD68
/* 102CC4 802E1444 00000000 */   nop      
/* 102CC8 802E1448 24020008 */  addiu     $v0, $zero, 8
/* 102CCC 802E144C A6020022 */  sh        $v0, 0x22($s0)
.L802E1450:
/* 102CD0 802E1450 8FBF0014 */  lw        $ra, 0x14($sp)
/* 102CD4 802E1454 8FB00010 */  lw        $s0, 0x10($sp)
/* 102CD8 802E1458 03E00008 */  jr        $ra
/* 102CDC 802E145C 27BD0018 */   addiu    $sp, $sp, 0x18
