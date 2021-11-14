.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_8029D7C0
.word L8026F7E4_19E0C4, L8026F7F0_19E0D0, L8026F7FC_19E0DC, L8026F804_19E0E4, L8026F80C_19E0EC, L8026F814_19E0F4

.section .text

glabel SetActorSounds
/* 19E020 8026F740 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19E024 8026F744 AFB20018 */  sw        $s2, 0x18($sp)
/* 19E028 8026F748 0080902D */  daddu     $s2, $a0, $zero
/* 19E02C 8026F74C AFBF0020 */  sw        $ra, 0x20($sp)
/* 19E030 8026F750 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19E034 8026F754 AFB10014 */  sw        $s1, 0x14($sp)
/* 19E038 8026F758 AFB00010 */  sw        $s0, 0x10($sp)
/* 19E03C 8026F75C 8E50000C */  lw        $s0, 0xc($s2)
/* 19E040 8026F760 8E050000 */  lw        $a1, ($s0)
/* 19E044 8026F764 0C0B1EAF */  jal       evt_get_variable
/* 19E048 8026F768 26100004 */   addiu    $s0, $s0, 4
/* 19E04C 8026F76C 0040882D */  daddu     $s1, $v0, $zero
/* 19E050 8026F770 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19E054 8026F774 16220002 */  bne       $s1, $v0, .L8026F780
/* 19E058 8026F778 00000000 */   nop
/* 19E05C 8026F77C 8E510148 */  lw        $s1, 0x148($s2)
.L8026F780:
/* 19E060 8026F780 8E050000 */  lw        $a1, ($s0)
/* 19E064 8026F784 26100004 */  addiu     $s0, $s0, 4
/* 19E068 8026F788 0C0B1EAF */  jal       evt_get_variable
/* 19E06C 8026F78C 0240202D */   daddu    $a0, $s2, $zero
/* 19E070 8026F790 8E050000 */  lw        $a1, ($s0)
/* 19E074 8026F794 26100004 */  addiu     $s0, $s0, 4
/* 19E078 8026F798 0240202D */  daddu     $a0, $s2, $zero
/* 19E07C 8026F79C 0C0B1EAF */  jal       evt_get_variable
/* 19E080 8026F7A0 0040982D */   daddu    $s3, $v0, $zero
/* 19E084 8026F7A4 0240202D */  daddu     $a0, $s2, $zero
/* 19E088 8026F7A8 8E050000 */  lw        $a1, ($s0)
/* 19E08C 8026F7AC 0C0B1EAF */  jal       evt_get_variable
/* 19E090 8026F7B0 0040802D */   daddu    $s0, $v0, $zero
/* 19E094 8026F7B4 0220202D */  daddu     $a0, $s1, $zero
/* 19E098 8026F7B8 0C09A75B */  jal       get_actor
/* 19E09C 8026F7BC 0040882D */   daddu    $s1, $v0, $zero
/* 19E0A0 8026F7C0 0040182D */  daddu     $v1, $v0, $zero
/* 19E0A4 8026F7C4 2E620006 */  sltiu     $v0, $s3, 6
/* 19E0A8 8026F7C8 10400013 */  beqz      $v0, .L8026F818
/* 19E0AC 8026F7CC 00131080 */   sll      $v0, $s3, 2
/* 19E0B0 8026F7D0 3C01802A */  lui       $at, %hi(jtbl_8029D7C0)
/* 19E0B4 8026F7D4 00220821 */  addu      $at, $at, $v0
/* 19E0B8 8026F7D8 8C22D7C0 */  lw        $v0, %lo(jtbl_8029D7C0)($at)
/* 19E0BC 8026F7DC 00400008 */  jr        $v0
/* 19E0C0 8026F7E0 00000000 */   nop
dlabel L8026F7E4_19E0C4
/* 19E0C4 8026F7E4 AC70019C */  sw        $s0, 0x19c($v1)
/* 19E0C8 8026F7E8 0809BE06 */  j         .L8026F818
/* 19E0CC 8026F7EC AC7101A0 */   sw       $s1, 0x1a0($v1)
dlabel L8026F7F0_19E0D0
/* 19E0D0 8026F7F0 AC7001A4 */  sw        $s0, 0x1a4($v1)
/* 19E0D4 8026F7F4 0809BE06 */  j         .L8026F818
/* 19E0D8 8026F7F8 AC7101A8 */   sw       $s1, 0x1a8($v1)
dlabel L8026F7FC_19E0DC
/* 19E0DC 8026F7FC 0809BE06 */  j         .L8026F818
/* 19E0E0 8026F800 AC7001AC */   sw       $s0, 0x1ac($v1)
dlabel L8026F804_19E0E4
/* 19E0E4 8026F804 0809BE06 */  j         .L8026F818
/* 19E0E8 8026F808 AC7001B0 */   sw       $s0, 0x1b0($v1)
dlabel L8026F80C_19E0EC
/* 19E0EC 8026F80C 0809BE06 */  j         .L8026F818
/* 19E0F0 8026F810 A47001B4 */   sh       $s0, 0x1b4($v1)
dlabel L8026F814_19E0F4
/* 19E0F4 8026F814 A47001B6 */  sh        $s0, 0x1b6($v1)
.L8026F818:
/* 19E0F8 8026F818 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19E0FC 8026F81C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19E100 8026F820 8FB20018 */  lw        $s2, 0x18($sp)
/* 19E104 8026F824 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E108 8026F828 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E10C 8026F82C 24020002 */  addiu     $v0, $zero, 2
/* 19E110 8026F830 03E00008 */  jr        $ra
/* 19E114 8026F834 27BD0028 */   addiu    $sp, $sp, 0x28
