.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel phys_can_player_interact
/* 7E7A8 800E52F8 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 7E7AC 800E52FC 2442EBB0 */  addiu     $v0, $v0, %lo(D_8010EBB0)
/* 7E7B0 800E5300 80440000 */  lb        $a0, ($v0)
/* 7E7B4 800E5304 10800008 */  beqz      $a0, .L800E5328
/* 7E7B8 800E5308 24030001 */   addiu    $v1, $zero, 1
/* 7E7BC 800E530C 80430003 */  lb        $v1, 3($v0)
/* 7E7C0 800E5310 24020003 */  addiu     $v0, $zero, 3
/* 7E7C4 800E5314 1462000A */  bne       $v1, $v0, .L800E5340
/* 7E7C8 800E5318 0000182D */   daddu    $v1, $zero, $zero
/* 7E7CC 800E531C 0082102A */  slt       $v0, $a0, $v0
/* 7E7D0 800E5320 080394D0 */  j         .L800E5340
/* 7E7D4 800E5324 38430001 */   xori     $v1, $v0, 1
.L800E5328:
/* 7E7D8 800E5328 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7E7DC 800E532C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7E7E0 800E5330 904200B4 */  lbu       $v0, 0xb4($v0)
/* 7E7E4 800E5334 2C420003 */  sltiu     $v0, $v0, 3
/* 7E7E8 800E5338 50400001 */  beql      $v0, $zero, .L800E5340
/* 7E7EC 800E533C 0000182D */   daddu    $v1, $zero, $zero
.L800E5340:
/* 7E7F0 800E5340 03E00008 */  jr        $ra
/* 7E7F4 800E5344 0060102D */   daddu    $v0, $v1, $zero
