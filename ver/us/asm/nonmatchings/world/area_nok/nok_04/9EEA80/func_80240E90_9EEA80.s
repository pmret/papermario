.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80246E40_9F4A30
.ascii "party_kameki\0\0\0\0"

.section .text

glabel func_80240E90_9EEA80
/* 9EEA80 80240E90 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9EEA84 80240E94 3C048024 */  lui       $a0, %hi(D_80246E40_9F4A30)
/* 9EEA88 80240E98 24846E40 */  addiu     $a0, $a0, %lo(D_80246E40_9F4A30)
/* 9EEA8C 80240E9C 27A50010 */  addiu     $a1, $sp, 0x10
/* 9EEA90 80240EA0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9EEA94 80240EA4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 9EEA98 80240EA8 0C016B3A */  jal       load_asset_by_name
/* 9EEA9C 80240EAC AFB00018 */   sw       $s0, 0x18($sp)
/* 9EEAA0 80240EB0 0040802D */  daddu     $s0, $v0, $zero
/* 9EEAA4 80240EB4 0200202D */  daddu     $a0, $s0, $zero
/* 9EEAA8 80240EB8 3C118024 */  lui       $s1, %hi(dgb_01_npcGroupList_80246E50)
/* 9EEAAC 80240EBC 26316E50 */  addiu     $s1, $s1, %lo(dgb_01_npcGroupList_80246E50)
/* 9EEAB0 80240EC0 0C01BB7C */  jal       decode_yay0
/* 9EEAB4 80240EC4 0220282D */   daddu    $a1, $s1, $zero
/* 9EEAB8 80240EC8 0C00AB1E */  jal       general_heap_free
/* 9EEABC 80240ECC 0200202D */   daddu    $a0, $s0, $zero
/* 9EEAC0 80240ED0 3C048025 */  lui       $a0, %hi(pause_partners_load_portrait)
/* 9EEAC4 80240ED4 2484ADE0 */  addiu     $a0, $a0, %lo(pause_partners_load_portrait)
/* 9EEAC8 80240ED8 3C028024 */  lui       $v0, %hi(D_80247050)
/* 9EEACC 80240EDC 24427050 */  addiu     $v0, $v0, %lo(D_80247050)
/* 9EEAD0 80240EE0 AC820000 */  sw        $v0, ($a0)
/* 9EEAD4 80240EE4 24020096 */  addiu     $v0, $zero, 0x96
/* 9EEAD8 80240EE8 A4820008 */  sh        $v0, 8($a0)
/* 9EEADC 80240EEC 24020069 */  addiu     $v0, $zero, 0x69
/* 9EEAE0 80240EF0 A482000A */  sh        $v0, 0xa($a0)
/* 9EEAE4 80240EF4 24020002 */  addiu     $v0, $zero, 2
/* 9EEAE8 80240EF8 AC82000C */  sw        $v0, 0xc($a0)
/* 9EEAEC 80240EFC 24020001 */  addiu     $v0, $zero, 1
/* 9EEAF0 80240F00 AC910004 */  sw        $s1, 4($a0)
/* 9EEAF4 80240F04 0C0496CB */  jal       set_message_images
/* 9EEAF8 80240F08 AC820010 */   sw       $v0, 0x10($a0)
/* 9EEAFC 80240F0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9EEB00 80240F10 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9EEB04 80240F14 8FB00018 */  lw        $s0, 0x18($sp)
/* 9EEB08 80240F18 24020002 */  addiu     $v0, $zero, 2
/* 9EEB0C 80240F1C 03E00008 */  jr        $ra
/* 9EEB10 80240F20 27BD0028 */   addiu    $sp, $sp, 0x28
/* 9EEB14 80240F24 00000000 */  nop
/* 9EEB18 80240F28 00000000 */  nop
/* 9EEB1C 80240F2C 00000000 */  nop
