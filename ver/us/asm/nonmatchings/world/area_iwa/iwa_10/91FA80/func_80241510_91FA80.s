.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80248470_9269E0
.ascii "party_pareta\0\0\0\0"

.section .text

glabel func_80241510_91FA80
/* 91FA80 80241510 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 91FA84 80241514 3C048025 */  lui       $a0, %hi(D_80248470_9269E0)
/* 91FA88 80241518 24848470 */  addiu     $a0, $a0, %lo(D_80248470_9269E0)
/* 91FA8C 8024151C 27A50010 */  addiu     $a1, $sp, 0x10
/* 91FA90 80241520 AFBF0020 */  sw        $ra, 0x20($sp)
/* 91FA94 80241524 AFB1001C */  sw        $s1, 0x1c($sp)
/* 91FA98 80241528 0C016B3A */  jal       load_asset_by_name
/* 91FA9C 8024152C AFB00018 */   sw       $s0, 0x18($sp)
/* 91FAA0 80241530 0040802D */  daddu     $s0, $v0, $zero
/* 91FAA4 80241534 0200202D */  daddu     $a0, $s0, $zero
/* 91FAA8 80241538 3C118025 */  lui       $s1, %hi(D_80248650)
/* 91FAAC 8024153C 26318650 */  addiu     $s1, $s1, %lo(D_80248650)
/* 91FAB0 80241540 0C01BB7C */  jal       decode_yay0
/* 91FAB4 80241544 0220282D */   daddu    $a1, $s1, $zero
/* 91FAB8 80241548 0C00AB1E */  jal       general_heap_free
/* 91FABC 8024154C 0200202D */   daddu    $a0, $s0, $zero
/* 91FAC0 80241550 3C048025 */  lui       $a0, %hi(D_8024C5E0)
/* 91FAC4 80241554 2484C5E0 */  addiu     $a0, $a0, %lo(D_8024C5E0)
/* 91FAC8 80241558 3C028025 */  lui       $v0, %hi(D_80248850)
/* 91FACC 8024155C 24428850 */  addiu     $v0, $v0, %lo(D_80248850)
/* 91FAD0 80241560 AC820000 */  sw        $v0, ($a0)
/* 91FAD4 80241564 24020096 */  addiu     $v0, $zero, 0x96
/* 91FAD8 80241568 A4820008 */  sh        $v0, 8($a0)
/* 91FADC 8024156C 24020069 */  addiu     $v0, $zero, 0x69
/* 91FAE0 80241570 A482000A */  sh        $v0, 0xa($a0)
/* 91FAE4 80241574 24020002 */  addiu     $v0, $zero, 2
/* 91FAE8 80241578 AC82000C */  sw        $v0, 0xc($a0)
/* 91FAEC 8024157C 24020001 */  addiu     $v0, $zero, 1
/* 91FAF0 80241580 AC910004 */  sw        $s1, 4($a0)
/* 91FAF4 80241584 0C0496CB */  jal       set_message_images
/* 91FAF8 80241588 AC820010 */   sw       $v0, 0x10($a0)
/* 91FAFC 8024158C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 91FB00 80241590 8FB1001C */  lw        $s1, 0x1c($sp)
/* 91FB04 80241594 8FB00018 */  lw        $s0, 0x18($sp)
/* 91FB08 80241598 24020002 */  addiu     $v0, $zero, 2
/* 91FB0C 8024159C 03E00008 */  jr        $ra
/* 91FB10 802415A0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 91FB14 802415A4 00000000 */  nop
/* 91FB18 802415A8 00000000 */  nop
/* 91FB1C 802415AC 00000000 */  nop
