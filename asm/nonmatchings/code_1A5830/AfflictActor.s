.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AfflictActor
/* 1ABF5C 8027D67C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1ABF60 8027D680 AFB20018 */  sw        $s2, 0x18($sp)
/* 1ABF64 8027D684 0080902D */  daddu     $s2, $a0, $zero
/* 1ABF68 8027D688 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1ABF6C 8027D68C AFB3001C */  sw        $s3, 0x1c($sp)
/* 1ABF70 8027D690 AFB10014 */  sw        $s1, 0x14($sp)
/* 1ABF74 8027D694 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABF78 8027D698 8E50000C */  lw        $s0, 0xc($s2)
/* 1ABF7C 8027D69C 8E050000 */  lw        $a1, ($s0)
/* 1ABF80 8027D6A0 0C0B1EAF */  jal       get_variable
/* 1ABF84 8027D6A4 26100004 */   addiu    $s0, $s0, 4
/* 1ABF88 8027D6A8 0040882D */  daddu     $s1, $v0, $zero
/* 1ABF8C 8027D6AC 8E050000 */  lw        $a1, ($s0)
/* 1ABF90 8027D6B0 26100004 */  addiu     $s0, $s0, 4
/* 1ABF94 8027D6B4 0C0B1EAF */  jal       get_variable
/* 1ABF98 8027D6B8 0240202D */   daddu    $a0, $s2, $zero
/* 1ABF9C 8027D6BC 0240202D */  daddu     $a0, $s2, $zero
/* 1ABFA0 8027D6C0 8E050000 */  lw        $a1, ($s0)
/* 1ABFA4 8027D6C4 0C0B1EAF */  jal       get_variable
/* 1ABFA8 8027D6C8 0040802D */   daddu    $s0, $v0, $zero
/* 1ABFAC 8027D6CC 0040982D */  daddu     $s3, $v0, $zero
/* 1ABFB0 8027D6D0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABFB4 8027D6D4 16220002 */  bne       $s1, $v0, .L8027D6E0
/* 1ABFB8 8027D6D8 00000000 */   nop
/* 1ABFBC 8027D6DC 8E510148 */  lw        $s1, 0x148($s2)
.L8027D6E0:
/* 1ABFC0 8027D6E0 0C09A75B */  jal       get_actor
/* 1ABFC4 8027D6E4 0220202D */   daddu    $a0, $s1, $zero
/* 1ABFC8 8027D6E8 0040202D */  daddu     $a0, $v0, $zero
/* 1ABFCC 8027D6EC 24020005 */  addiu     $v0, $zero, 5
/* 1ABFD0 8027D6F0 1202000E */  beq       $s0, $v0, .L8027D72C
/* 1ABFD4 8027D6F4 2A020006 */   slti     $v0, $s0, 6
/* 1ABFD8 8027D6F8 10400005 */  beqz      $v0, .L8027D710
/* 1ABFDC 8027D6FC 24020004 */   addiu    $v0, $zero, 4
/* 1ABFE0 8027D700 12020008 */  beq       $s0, $v0, .L8027D724
/* 1ABFE4 8027D704 24060026 */   addiu    $a2, $zero, 0x26
/* 1ABFE8 8027D708 0809F5CD */  j         .L8027D734
/* 1ABFEC 8027D70C 0200282D */   daddu    $a1, $s0, $zero
.L8027D710:
/* 1ABFF0 8027D710 24020006 */  addiu     $v0, $zero, 6
/* 1ABFF4 8027D714 16020006 */  bne       $s0, $v0, .L8027D730
/* 1ABFF8 8027D718 24060026 */   addiu    $a2, $zero, 0x26
/* 1ABFFC 8027D71C 0809F5CC */  j         .L8027D730
/* 1AC000 8027D720 24060020 */   addiu    $a2, $zero, 0x20
.L8027D724:
/* 1AC004 8027D724 0809F5CC */  j         .L8027D730
/* 1AC008 8027D728 24060024 */   addiu    $a2, $zero, 0x24
.L8027D72C:
/* 1AC00C 8027D72C 24060026 */  addiu     $a2, $zero, 0x26
.L8027D730:
/* 1AC010 8027D730 0200282D */  daddu     $a1, $s0, $zero
.L8027D734:
/* 1AC014 8027D734 0C099B3C */  jal       inflict_status_set_duration
/* 1AC018 8027D738 0260382D */   daddu    $a3, $s3, $zero
/* 1AC01C 8027D73C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1AC020 8027D740 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AC024 8027D744 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AC028 8027D748 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC02C 8027D74C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC030 8027D750 24020002 */  addiu     $v0, $zero, 2
/* 1AC034 8027D754 03E00008 */  jr        $ra
/* 1AC038 8027D758 27BD0028 */   addiu    $sp, $sp, 0x28
