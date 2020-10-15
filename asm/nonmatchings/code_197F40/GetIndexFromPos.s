.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetIndexFromPos
/* 19893C 8026A05C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 198940 8026A060 AFB10014 */  sw        $s1, 0x14($sp)
/* 198944 8026A064 0080882D */  daddu     $s1, $a0, $zero
/* 198948 8026A068 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19894C 8026A06C AFB00010 */  sw        $s0, 0x10($sp)
/* 198950 8026A070 8E30000C */  lw        $s0, 0xc($s1)
/* 198954 8026A074 8E050000 */  lw        $a1, ($s0)
/* 198958 8026A078 0C0B1EAF */  jal       get_variable
/* 19895C 8026A07C 26100004 */   addiu    $s0, $s0, 4
/* 198960 8026A080 0040202D */  daddu     $a0, $v0, $zero
/* 198964 8026A084 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 198968 8026A088 14820002 */  bne       $a0, $v0, .L8026A094
/* 19896C 8026A08C 8E100000 */   lw       $s0, ($s0)
/* 198970 8026A090 8E240148 */  lw        $a0, 0x148($s1)
.L8026A094:
/* 198974 8026A094 0C09A75B */  jal       get_actor
/* 198978 8026A098 00000000 */   nop      
/* 19897C 8026A09C 8C46014C */  lw        $a2, 0x14c($v0)
/* 198980 8026A0A0 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 198984 8026A0A4 0C09A5A6 */  jal       get_nearest_home_index
/* 198988 8026A0A8 C44E0148 */   lwc1     $f14, 0x148($v0)
/* 19898C 8026A0AC 0220202D */  daddu     $a0, $s1, $zero
/* 198990 8026A0B0 0200282D */  daddu     $a1, $s0, $zero
/* 198994 8026A0B4 0C0B2026 */  jal       set_variable
/* 198998 8026A0B8 0040302D */   daddu    $a2, $v0, $zero
/* 19899C 8026A0BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1989A0 8026A0C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 1989A4 8026A0C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 1989A8 8026A0C8 24020002 */  addiu     $v0, $zero, 2
/* 1989AC 8026A0CC 03E00008 */  jr        $ra
/* 1989B0 8026A0D0 27BD0020 */   addiu    $sp, $sp, 0x20
