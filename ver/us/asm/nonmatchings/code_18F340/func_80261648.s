.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261648
/* 18FF28 80261648 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18FF2C 8026164C AFB00010 */  sw        $s0, 0x10($sp)
/* 18FF30 80261650 00A0802D */  daddu     $s0, $a1, $zero
/* 18FF34 80261654 2404FFF6 */  addiu     $a0, $zero, -0xa
/* 18FF38 80261658 AFBF0018 */  sw        $ra, 0x18($sp)
/* 18FF3C 8026165C 0C00EABB */  jal       get_npc_unsafe
/* 18FF40 80261660 AFB10014 */   sw       $s1, 0x14($sp)
/* 18FF44 80261664 12000004 */  beqz      $s0, .L80261678
/* 18FF48 80261668 0040882D */   daddu    $s1, $v0, $zero
/* 18FF4C 8026166C 0C05272D */  jal       sfx_play_sound
/* 18FF50 80261670 2404024B */   addiu    $a0, $zero, 0x24b
/* 18FF54 80261674 A22000AC */  sb        $zero, 0xac($s1)
.L80261678:
/* 18FF58 80261678 922200AC */  lbu       $v0, 0xac($s1)
/* 18FF5C 8026167C 24420011 */  addiu     $v0, $v0, 0x11
/* 18FF60 80261680 A22200AC */  sb        $v0, 0xac($s1)
/* 18FF64 80261684 304200FF */  andi      $v0, $v0, 0xff
/* 18FF68 80261688 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 18FF6C 8026168C 14400004 */  bnez      $v0, .L802616A0
/* 18FF70 80261690 0000102D */   daddu    $v0, $zero, $zero
/* 18FF74 80261694 240200FF */  addiu     $v0, $zero, 0xff
/* 18FF78 80261698 A22200AC */  sb        $v0, 0xac($s1)
/* 18FF7C 8026169C 24020001 */  addiu     $v0, $zero, 1
.L802616A0:
/* 18FF80 802616A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18FF84 802616A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 18FF88 802616A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FF8C 802616AC 03E00008 */  jr        $ra
/* 18FF90 802616B0 27BD0020 */   addiu    $sp, $sp, 0x20
