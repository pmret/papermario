.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C78_911328
/* 911328 80241C78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91132C 80241C7C AFB10014 */  sw        $s1, 0x14($sp)
/* 911330 80241C80 0080882D */  daddu     $s1, $a0, $zero
/* 911334 80241C84 AFBF0018 */  sw        $ra, 0x18($sp)
/* 911338 80241C88 AFB00010 */  sw        $s0, 0x10($sp)
/* 91133C 80241C8C 8E220148 */  lw        $v0, 0x148($s1)
/* 911340 80241C90 0C00EABB */  jal       get_npc_unsafe
/* 911344 80241C94 84440008 */   lh       $a0, 8($v0)
/* 911348 80241C98 0040802D */  daddu     $s0, $v0, $zero
/* 91134C 80241C9C 9602008E */  lhu       $v0, 0x8e($s0)
/* 911350 80241CA0 2442FFFF */  addiu     $v0, $v0, -1
/* 911354 80241CA4 A602008E */  sh        $v0, 0x8e($s0)
/* 911358 80241CA8 00021400 */  sll       $v0, $v0, 0x10
/* 91135C 80241CAC 1C40000B */  bgtz      $v0, .L80241CDC
/* 911360 80241CB0 0200202D */   daddu    $a0, $s0, $zero
/* 911364 80241CB4 24050322 */  addiu     $a1, $zero, 0x322
/* 911368 80241CB8 0C012530 */  jal       ai_enemy_play_sound
/* 91136C 80241CBC 0000302D */   daddu    $a2, $zero, $zero
/* 911370 80241CC0 3C02002F */  lui       $v0, 0x2f
/* 911374 80241CC4 34420011 */  ori       $v0, $v0, 0x11
/* 911378 80241CC8 2403000B */  addiu     $v1, $zero, 0xb
/* 91137C 80241CCC AE020028 */  sw        $v0, 0x28($s0)
/* 911380 80241CD0 24020015 */  addiu     $v0, $zero, 0x15
/* 911384 80241CD4 A603008E */  sh        $v1, 0x8e($s0)
/* 911388 80241CD8 AE220070 */  sw        $v0, 0x70($s1)
.L80241CDC:
/* 91138C 80241CDC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 911390 80241CE0 8FB10014 */  lw        $s1, 0x14($sp)
/* 911394 80241CE4 8FB00010 */  lw        $s0, 0x10($sp)
/* 911398 80241CE8 03E00008 */  jr        $ra
/* 91139C 80241CEC 27BD0020 */   addiu    $sp, $sp, 0x20
