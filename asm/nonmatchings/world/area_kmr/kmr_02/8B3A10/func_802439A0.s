.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802439A0
/* 8B3A10 802439A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8B3A14 802439A4 3C048025 */  lui       $a0, 0x8025
/* 8B3A18 802439A8 24847F10 */  addiu     $a0, $a0, 0x7f10
/* 8B3A1C 802439AC 27A50010 */  addiu     $a1, $sp, 0x10
/* 8B3A20 802439B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8B3A24 802439B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8B3A28 802439B8 0C016B3A */  jal       load_asset_by_name
/* 8B3A2C 802439BC AFB00018 */   sw       $s0, 0x18($sp)
/* 8B3A30 802439C0 0040802D */  daddu     $s0, $v0, $zero
/* 8B3A34 802439C4 0200202D */  daddu     $a0, $s0, $zero
/* 8B3A38 802439C8 3C118026 */  lui       $s1, 0x8026
/* 8B3A3C 802439CC 26318140 */  addiu     $s1, $s1, -0x7ec0
/* 8B3A40 802439D0 0C01BB7C */  jal       decode_yay0
/* 8B3A44 802439D4 0220282D */   daddu    $a1, $s1, $zero
/* 8B3A48 802439D8 0C00AB1E */  jal       general_heap_free
/* 8B3A4C 802439DC 0200202D */   daddu    $a0, $s0, $zero
/* 8B3A50 802439E0 3C048026 */  lui       $a0, 0x8026
/* 8B3A54 802439E4 2484C0D0 */  addiu     $a0, $a0, -0x3f30
/* 8B3A58 802439E8 3C028026 */  lui       $v0, 0x8026
/* 8B3A5C 802439EC 24428340 */  addiu     $v0, $v0, -0x7cc0
/* 8B3A60 802439F0 AC820000 */  sw        $v0, ($a0)
/* 8B3A64 802439F4 24020096 */  addiu     $v0, $zero, 0x96
/* 8B3A68 802439F8 A4820008 */  sh        $v0, 8($a0)
/* 8B3A6C 802439FC 24020069 */  addiu     $v0, $zero, 0x69
/* 8B3A70 80243A00 A482000A */  sh        $v0, 0xa($a0)
/* 8B3A74 80243A04 24020002 */  addiu     $v0, $zero, 2
/* 8B3A78 80243A08 AC82000C */  sw        $v0, 0xc($a0)
/* 8B3A7C 80243A0C 24020001 */  addiu     $v0, $zero, 1
/* 8B3A80 80243A10 AC910004 */  sw        $s1, 4($a0)
/* 8B3A84 80243A14 0C0496CB */  jal       set_message_images
/* 8B3A88 80243A18 AC820010 */   sw       $v0, 0x10($a0)
/* 8B3A8C 80243A1C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8B3A90 80243A20 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8B3A94 80243A24 8FB00018 */  lw        $s0, 0x18($sp)
/* 8B3A98 80243A28 24020002 */  addiu     $v0, $zero, 2
/* 8B3A9C 80243A2C 03E00008 */  jr        $ra
/* 8B3AA0 80243A30 27BD0028 */   addiu    $sp, $sp, 0x28
/* 8B3AA4 80243A34 00000000 */  nop       
/* 8B3AA8 80243A38 00000000 */  nop       
/* 8B3AAC 80243A3C 00000000 */  nop       
