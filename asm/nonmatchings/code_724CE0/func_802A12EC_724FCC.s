.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12EC_724FCC
/* 724FCC 802A12EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 724FD0 802A12F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 724FD4 802A12F4 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 724FD8 802A12F8 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 724FDC 802A12FC AFBF0014 */  sw        $ra, 0x14($sp)
/* 724FE0 802A1300 82020217 */  lb        $v0, 0x217($s0)
/* 724FE4 802A1304 8C85000C */  lw        $a1, 0xc($a0)
/* 724FE8 802A1308 10400017 */  beqz      $v0, .L802A1368
/* 724FEC 802A130C 24020002 */   addiu    $v0, $zero, 2
/* 724FF0 802A1310 8CA50000 */  lw        $a1, ($a1)
/* 724FF4 802A1314 0C0B1EAF */  jal       get_variable
/* 724FF8 802A1318 00000000 */   nop      
/* 724FFC 802A131C 92030217 */  lbu       $v1, 0x217($s0)
/* 725000 802A1320 00621823 */  subu      $v1, $v1, $v0
/* 725004 802A1324 A2030217 */  sb        $v1, 0x217($s0)
/* 725008 802A1328 00031E00 */  sll       $v1, $v1, 0x18
/* 72500C 802A132C 04620001 */  bltzl     $v1, .L802A1334
/* 725010 802A1330 A2000217 */   sb       $zero, 0x217($s0)
.L802A1334:
/* 725014 802A1334 82030217 */  lb        $v1, 0x217($s0)
/* 725018 802A1338 18600005 */  blez      $v1, .L802A1350
/* 72501C 802A133C 24040034 */   addiu    $a0, $zero, 0x34
/* 725020 802A1340 8E020440 */  lw        $v0, 0x440($s0)
/* 725024 802A1344 8C42000C */  lw        $v0, 0xc($v0)
/* 725028 802A1348 080A84D9 */  j         .L802A1364
/* 72502C 802A134C AC43003C */   sw       $v1, 0x3c($v0)
.L802A1350:
/* 725030 802A1350 0C09F7A0 */  jal       dispatch_event_partner
/* 725034 802A1354 A2000216 */   sb       $zero, 0x216($s0)
/* 725038 802A1358 8E020440 */  lw        $v0, 0x440($s0)
/* 72503C 802A135C 8C42000C */  lw        $v0, 0xc($v0)
/* 725040 802A1360 AC40003C */  sw        $zero, 0x3c($v0)
.L802A1364:
/* 725044 802A1364 24020002 */  addiu     $v0, $zero, 2
.L802A1368:
/* 725048 802A1368 8FBF0014 */  lw        $ra, 0x14($sp)
/* 72504C 802A136C 8FB00010 */  lw        $s0, 0x10($sp)
/* 725050 802A1370 03E00008 */  jr        $ra
/* 725054 802A1374 27BD0018 */   addiu    $sp, $sp, 0x18
