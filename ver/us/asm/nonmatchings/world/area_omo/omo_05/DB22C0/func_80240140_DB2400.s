.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_DB2400
/* DB2400 80240140 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DB2404 80240144 AFB10024 */  sw        $s1, 0x24($sp)
/* DB2408 80240148 0080882D */  daddu     $s1, $a0, $zero
/* DB240C 8024014C AFBF0028 */  sw        $ra, 0x28($sp)
/* DB2410 80240150 AFB00020 */  sw        $s0, 0x20($sp)
/* DB2414 80240154 8E220148 */  lw        $v0, 0x148($s1)
/* DB2418 80240158 0C00EABB */  jal       get_npc_unsafe
/* DB241C 8024015C 84440008 */   lh       $a0, 8($v0)
/* DB2420 80240160 0040802D */  daddu     $s0, $v0, $zero
/* DB2424 80240164 0200202D */  daddu     $a0, $s0, $zero
/* DB2428 80240168 C600000C */  lwc1      $f0, 0xc($s0)
/* DB242C 8024016C 27A60018 */  addiu     $a2, $sp, 0x18
/* DB2430 80240170 E7A00018 */  swc1      $f0, 0x18($sp)
/* DB2434 80240174 AFA00010 */  sw        $zero, 0x10($sp)
/* DB2438 80240178 AFA00014 */  sw        $zero, 0x14($sp)
/* DB243C 8024017C 8E050018 */  lw        $a1, 0x18($s0)
/* DB2440 80240180 0C0129E1 */  jal       func_8004A784
/* DB2444 80240184 0000382D */   daddu    $a3, $zero, $zero
/* DB2448 80240188 14400005 */  bnez      $v0, .L802401A0
/* DB244C 8024018C 00000000 */   nop
/* DB2450 80240190 8E050018 */  lw        $a1, 0x18($s0)
/* DB2454 80240194 8E06000C */  lw        $a2, 0xc($s0)
/* DB2458 80240198 0C00EA95 */  jal       npc_move_heading
/* DB245C 8024019C 0200202D */   daddu    $a0, $s0, $zero
.L802401A0:
/* DB2460 802401A0 9602008E */  lhu       $v0, 0x8e($s0)
/* DB2464 802401A4 2442FFFF */  addiu     $v0, $v0, -1
/* DB2468 802401A8 A602008E */  sh        $v0, 0x8e($s0)
/* DB246C 802401AC 00021400 */  sll       $v0, $v0, 0x10
/* DB2470 802401B0 14400004 */  bnez      $v0, .L802401C4
/* DB2474 802401B4 2402001E */   addiu    $v0, $zero, 0x1e
/* DB2478 802401B8 A602008E */  sh        $v0, 0x8e($s0)
/* DB247C 802401BC 24020011 */  addiu     $v0, $zero, 0x11
/* DB2480 802401C0 AE220070 */  sw        $v0, 0x70($s1)
.L802401C4:
/* DB2484 802401C4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DB2488 802401C8 8FB10024 */  lw        $s1, 0x24($sp)
/* DB248C 802401CC 8FB00020 */  lw        $s0, 0x20($sp)
/* DB2490 802401D0 03E00008 */  jr        $ra
/* DB2494 802401D4 27BD0030 */   addiu    $sp, $sp, 0x30
