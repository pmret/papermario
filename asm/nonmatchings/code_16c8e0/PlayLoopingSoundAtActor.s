.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayLoopingSoundAtActor
/* 182254 80253974 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 182258 80253978 AFB20020 */  sw        $s2, 0x20($sp)
/* 18225C 8025397C 0080902D */  daddu     $s2, $a0, $zero
/* 182260 80253980 AFBF0028 */  sw        $ra, 0x28($sp)
/* 182264 80253984 AFB30024 */  sw        $s3, 0x24($sp)
/* 182268 80253988 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18226C 8025398C AFB00018 */  sw        $s0, 0x18($sp)
/* 182270 80253990 8E50000C */  lw        $s0, 0xc($s2)
/* 182274 80253994 8E050000 */  lw        $a1, ($s0)
/* 182278 80253998 0C0B1EAF */  jal       get_variable
/* 18227C 8025399C 26100004 */   addiu    $s0, $s0, 4
/* 182280 802539A0 0040882D */  daddu     $s1, $v0, $zero
/* 182284 802539A4 8E050000 */  lw        $a1, ($s0)
/* 182288 802539A8 26100004 */  addiu     $s0, $s0, 4
/* 18228C 802539AC 0C0B1EAF */  jal       get_variable
/* 182290 802539B0 0240202D */   daddu    $a0, $s2, $zero
/* 182294 802539B4 0040982D */  daddu     $s3, $v0, $zero
/* 182298 802539B8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 18229C 802539BC 16220002 */  bne       $s1, $v0, .L802539C8
/* 1822A0 802539C0 8E100000 */   lw       $s0, ($s0)
/* 1822A4 802539C4 8E510148 */  lw        $s1, 0x148($s2)
.L802539C8:
/* 1822A8 802539C8 0C09A75B */  jal       get_actor
/* 1822AC 802539CC 0220202D */   daddu    $a0, $s1, $zero
/* 1822B0 802539D0 00131880 */  sll       $v1, $s3, 2
/* 1822B4 802539D4 00431821 */  addu      $v1, $v0, $v1
/* 1822B8 802539D8 AC700438 */  sw        $s0, 0x438($v1)
/* 1822BC 802539DC C440014C */  lwc1      $f0, 0x14c($v0)
/* 1822C0 802539E0 0200202D */  daddu     $a0, $s0, $zero
/* 1822C4 802539E4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1822C8 802539E8 8C460144 */  lw        $a2, 0x144($v0)
/* 1822CC 802539EC 8C470148 */  lw        $a3, 0x148($v0)
/* 1822D0 802539F0 0C052757 */  jal       play_sound_at_position
/* 1822D4 802539F4 0000282D */   daddu    $a1, $zero, $zero
/* 1822D8 802539F8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 1822DC 802539FC 8FB30024 */  lw        $s3, 0x24($sp)
/* 1822E0 80253A00 8FB20020 */  lw        $s2, 0x20($sp)
/* 1822E4 80253A04 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1822E8 80253A08 8FB00018 */  lw        $s0, 0x18($sp)
/* 1822EC 80253A0C 24020002 */  addiu     $v0, $zero, 2
/* 1822F0 80253A10 03E00008 */  jr        $ra
/* 1822F4 80253A14 27BD0030 */   addiu    $sp, $sp, 0x30
