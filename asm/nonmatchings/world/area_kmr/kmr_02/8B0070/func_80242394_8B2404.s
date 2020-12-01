.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242394_8B2404
/* 8B2404 80242394 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B2408 80242398 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B240C 8024239C 0080882D */  daddu     $s1, $a0, $zero
/* 8B2410 802423A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B2414 802423A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B2418 802423A8 8E30000C */  lw        $s0, 0xc($s1)
/* 8B241C 802423AC 8E050000 */  lw        $a1, ($s0)
/* 8B2420 802423B0 0C0B1EAF */  jal       get_variable
/* 8B2424 802423B4 26100004 */   addiu    $s0, $s0, 4
/* 8B2428 802423B8 0220202D */  daddu     $a0, $s1, $zero
/* 8B242C 802423BC 8E050000 */  lw        $a1, ($s0)
/* 8B2430 802423C0 0C0B1EAF */  jal       get_variable
/* 8B2434 802423C4 0040802D */   daddu    $s0, $v0, $zero
/* 8B2438 802423C8 0200202D */  daddu     $a0, $s0, $zero
/* 8B243C 802423CC 00021080 */  sll       $v0, $v0, 2
/* 8B2440 802423D0 3C108025 */  lui       $s0, %hi(D_802480AC)
/* 8B2444 802423D4 02028021 */  addu      $s0, $s0, $v0
/* 8B2448 802423D8 0C00FB3A */  jal       get_enemy
/* 8B244C 802423DC 8E1080AC */   lw       $s0, %lo(D_802480AC)($s0)
/* 8B2450 802423E0 0040302D */  daddu     $a2, $v0, $zero
/* 8B2454 802423E4 0000282D */  daddu     $a1, $zero, $zero
.L802423E8:
/* 8B2458 802423E8 8E040000 */  lw        $a0, ($s0)
/* 8B245C 802423EC 00051080 */  sll       $v0, $a1, 2
/* 8B2460 802423F0 8CC300D0 */  lw        $v1, 0xd0($a2)
/* 8B2464 802423F4 24A50001 */  addiu     $a1, $a1, 1
/* 8B2468 802423F8 00431021 */  addu      $v0, $v0, $v1
/* 8B246C 802423FC AC440000 */  sw        $a0, ($v0)
/* 8B2470 80242400 28A2000E */  slti      $v0, $a1, 0xe
/* 8B2474 80242404 1440FFF8 */  bnez      $v0, .L802423E8
/* 8B2478 80242408 26100004 */   addiu    $s0, $s0, 4
/* 8B247C 8024240C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B2480 80242410 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B2484 80242414 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B2488 80242418 24020002 */  addiu     $v0, $zero, 2
/* 8B248C 8024241C 03E00008 */  jr        $ra
/* 8B2490 80242420 27BD0020 */   addiu    $sp, $sp, 0x20
