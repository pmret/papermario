.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12EC_7333BC
/* 7333BC 802A12EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7333C0 802A12F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 7333C4 802A12F4 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 7333C8 802A12F8 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 7333CC 802A12FC AFBF0014 */  sw        $ra, 0x14($sp)
/* 7333D0 802A1300 82020217 */  lb        $v0, 0x217($s0)
/* 7333D4 802A1304 8C85000C */  lw        $a1, 0xc($a0)
/* 7333D8 802A1308 10400017 */  beqz      $v0, .L802A1368
/* 7333DC 802A130C 24020002 */   addiu    $v0, $zero, 2
/* 7333E0 802A1310 8CA50000 */  lw        $a1, ($a1)
/* 7333E4 802A1314 0C0B1EAF */  jal       get_variable
/* 7333E8 802A1318 00000000 */   nop
/* 7333EC 802A131C 92030217 */  lbu       $v1, 0x217($s0)
/* 7333F0 802A1320 00621823 */  subu      $v1, $v1, $v0
/* 7333F4 802A1324 A2030217 */  sb        $v1, 0x217($s0)
/* 7333F8 802A1328 00031E00 */  sll       $v1, $v1, 0x18
/* 7333FC 802A132C 04620001 */  bltzl     $v1, .L802A1334
/* 733400 802A1330 A2000217 */   sb       $zero, 0x217($s0)
.L802A1334:
/* 733404 802A1334 82030217 */  lb        $v1, 0x217($s0)
/* 733408 802A1338 18600005 */  blez      $v1, .L802A1350
/* 73340C 802A133C 24040034 */   addiu    $a0, $zero, 0x34
/* 733410 802A1340 8E020440 */  lw        $v0, 0x440($s0)
/* 733414 802A1344 8C42000C */  lw        $v0, 0xc($v0)
/* 733418 802A1348 080A84D9 */  j         .L802A1364
/* 73341C 802A134C AC43003C */   sw       $v1, 0x3c($v0)
.L802A1350:
/* 733420 802A1350 0C09F7A0 */  jal       dispatch_event_partner
/* 733424 802A1354 A2000216 */   sb       $zero, 0x216($s0)
/* 733428 802A1358 8E020440 */  lw        $v0, 0x440($s0)
/* 73342C 802A135C 8C42000C */  lw        $v0, 0xc($v0)
/* 733430 802A1360 AC40003C */  sw        $zero, 0x3c($v0)
.L802A1364:
/* 733434 802A1364 24020002 */  addiu     $v0, $zero, 2
.L802A1368:
/* 733438 802A1368 8FBF0014 */  lw        $ra, 0x14($sp)
/* 73343C 802A136C 8FB00010 */  lw        $s0, 0x10($sp)
/* 733440 802A1370 03E00008 */  jr        $ra
/* 733444 802A1374 27BD0018 */   addiu    $sp, $sp, 0x18
