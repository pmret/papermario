.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_BDAB00
/* BDAB00 80240350 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BDAB04 80240354 3C048024 */  lui       $a0, %hi(D_802429E8_BDD198)
/* BDAB08 80240358 248429E8 */  addiu     $a0, $a0, %lo(D_802429E8_BDD198)
/* BDAB0C 8024035C 27A50010 */  addiu     $a1, $sp, 0x10
/* BDAB10 80240360 AFBF0020 */  sw        $ra, 0x20($sp)
/* BDAB14 80240364 AFB1001C */  sw        $s1, 0x1c($sp)
/* BDAB18 80240368 0C016B3A */  jal       load_asset_by_name
/* BDAB1C 8024036C AFB00018 */   sw       $s0, 0x18($sp)
/* BDAB20 80240370 0040802D */  daddu     $s0, $v0, $zero
/* BDAB24 80240374 0200202D */  daddu     $a0, $s0, $zero
/* BDAB28 80240378 3C118024 */  lui       $s1, %hi(func_80242A00_803280)
/* BDAB2C 8024037C 26312A00 */  addiu     $s1, $s1, %lo(func_80242A00_803280)
/* BDAB30 80240380 0C01BB7C */  jal       decode_yay0
/* BDAB34 80240384 0220282D */   daddu    $a1, $s1, $zero
/* BDAB38 80240388 0C00AB1E */  jal       general_heap_free
/* BDAB3C 8024038C 0200202D */   daddu    $a0, $s0, $zero
/* BDAB40 80240390 3C048024 */  lui       $a0, %hi(D_80246990)
/* BDAB44 80240394 24846990 */  addiu     $a0, $a0, %lo(D_80246990)
/* BDAB48 80240398 3C028024 */  lui       $v0, %hi(func_80242C00_B377D0)
/* BDAB4C 8024039C 24422C00 */  addiu     $v0, $v0, %lo(func_80242C00_B377D0)
/* BDAB50 802403A0 AC820000 */  sw        $v0, ($a0)
/* BDAB54 802403A4 24020096 */  addiu     $v0, $zero, 0x96
/* BDAB58 802403A8 A4820008 */  sh        $v0, 8($a0)
/* BDAB5C 802403AC 24020069 */  addiu     $v0, $zero, 0x69
/* BDAB60 802403B0 A482000A */  sh        $v0, 0xa($a0)
/* BDAB64 802403B4 24020002 */  addiu     $v0, $zero, 2
/* BDAB68 802403B8 AC82000C */  sw        $v0, 0xc($a0)
/* BDAB6C 802403BC 24020001 */  addiu     $v0, $zero, 1
/* BDAB70 802403C0 AC910004 */  sw        $s1, 4($a0)
/* BDAB74 802403C4 0C0496CB */  jal       set_message_images
/* BDAB78 802403C8 AC820010 */   sw       $v0, 0x10($a0)
/* BDAB7C 802403CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* BDAB80 802403D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* BDAB84 802403D4 8FB00018 */  lw        $s0, 0x18($sp)
/* BDAB88 802403D8 24020002 */  addiu     $v0, $zero, 2
/* BDAB8C 802403DC 03E00008 */  jr        $ra
/* BDAB90 802403E0 27BD0028 */   addiu    $sp, $sp, 0x28
/* BDAB94 802403E4 00000000 */  nop
/* BDAB98 802403E8 00000000 */  nop
/* BDAB9C 802403EC 00000000 */  nop
