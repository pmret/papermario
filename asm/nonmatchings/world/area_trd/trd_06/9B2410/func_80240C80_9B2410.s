.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C80_9B2410
/* 9B2410 80240C80 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9B2414 80240C84 3C048024 */  lui       $a0, %hi(D_802451D8_9B6968)
/* 9B2418 80240C88 248451D8 */  addiu     $a0, $a0, %lo(D_802451D8_9B6968)
/* 9B241C 80240C8C 27A50010 */  addiu     $a1, $sp, 0x10
/* 9B2420 80240C90 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9B2424 80240C94 AFB1001C */  sw        $s1, 0x1c($sp)
/* 9B2428 80240C98 0C016B3A */  jal       load_asset_by_name
/* 9B242C 80240C9C AFB00018 */   sw       $s0, 0x18($sp)
/* 9B2430 80240CA0 0040802D */  daddu     $s0, $v0, $zero
/* 9B2434 80240CA4 0200202D */  daddu     $a0, $s0, $zero
/* 9B2438 80240CA8 3C118024 */  lui       $s1, %hi(D_80245230)
/* 9B243C 80240CAC 26315230 */  addiu     $s1, $s1, %lo(D_80245230)
/* 9B2440 80240CB0 0C01BB7C */  jal       decode_yay0
/* 9B2444 80240CB4 0220282D */   daddu    $a1, $s1, $zero
/* 9B2448 80240CB8 0C00AB1E */  jal       general_heap_free
/* 9B244C 80240CBC 0200202D */   daddu    $a0, $s0, $zero
/* 9B2450 80240CC0 3C048025 */  lui       $a0, %hi(D_802491C0)
/* 9B2454 80240CC4 248491C0 */  addiu     $a0, $a0, %lo(D_802491C0)
/* 9B2458 80240CC8 3C028024 */  lui       $v0, %hi(D_80245430)
/* 9B245C 80240CCC 24425430 */  addiu     $v0, $v0, %lo(D_80245430)
/* 9B2460 80240CD0 AC820000 */  sw        $v0, ($a0)
/* 9B2464 80240CD4 24020096 */  addiu     $v0, $zero, 0x96
/* 9B2468 80240CD8 A4820008 */  sh        $v0, 8($a0)
/* 9B246C 80240CDC 24020069 */  addiu     $v0, $zero, 0x69
/* 9B2470 80240CE0 A482000A */  sh        $v0, 0xa($a0)
/* 9B2474 80240CE4 24020002 */  addiu     $v0, $zero, 2
/* 9B2478 80240CE8 AC82000C */  sw        $v0, 0xc($a0)
/* 9B247C 80240CEC 24020001 */  addiu     $v0, $zero, 1
/* 9B2480 80240CF0 AC910004 */  sw        $s1, 4($a0)
/* 9B2484 80240CF4 0C0496CB */  jal       set_message_images
/* 9B2488 80240CF8 AC820010 */   sw       $v0, 0x10($a0)
/* 9B248C 80240CFC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9B2490 80240D00 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9B2494 80240D04 8FB00018 */  lw        $s0, 0x18($sp)
/* 9B2498 80240D08 24020002 */  addiu     $v0, $zero, 2
/* 9B249C 80240D0C 03E00008 */  jr        $ra
/* 9B24A0 80240D10 27BD0028 */   addiu    $sp, $sp, 0x28
/* 9B24A4 80240D14 00000000 */  nop
/* 9B24A8 80240D18 00000000 */  nop
/* 9B24AC 80240D1C 00000000 */  nop
