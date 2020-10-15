.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlaySoundAtPart
/* 1821B0 802538D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1821B4 802538D4 AFB20020 */  sw        $s2, 0x20($sp)
/* 1821B8 802538D8 0080902D */  daddu     $s2, $a0, $zero
/* 1821BC 802538DC AFBF0028 */  sw        $ra, 0x28($sp)
/* 1821C0 802538E0 AFB30024 */  sw        $s3, 0x24($sp)
/* 1821C4 802538E4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1821C8 802538E8 AFB00018 */  sw        $s0, 0x18($sp)
/* 1821CC 802538EC 8E50000C */  lw        $s0, 0xc($s2)
/* 1821D0 802538F0 8E050000 */  lw        $a1, ($s0)
/* 1821D4 802538F4 0C0B1EAF */  jal       get_variable
/* 1821D8 802538F8 26100004 */   addiu    $s0, $s0, 4
/* 1821DC 802538FC 0040882D */  daddu     $s1, $v0, $zero
/* 1821E0 80253900 8E050000 */  lw        $a1, ($s0)
/* 1821E4 80253904 26100004 */  addiu     $s0, $s0, 4
/* 1821E8 80253908 0C0B1EAF */  jal       get_variable
/* 1821EC 8025390C 0240202D */   daddu    $a0, $s2, $zero
/* 1821F0 80253910 0040982D */  daddu     $s3, $v0, $zero
/* 1821F4 80253914 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1821F8 80253918 16220002 */  bne       $s1, $v0, .L80253924
/* 1821FC 8025391C 8E100000 */   lw       $s0, ($s0)
/* 182200 80253920 8E510148 */  lw        $s1, 0x148($s2)
.L80253924:
/* 182204 80253924 0C09A75B */  jal       get_actor
/* 182208 80253928 0220202D */   daddu    $a0, $s1, $zero
/* 18220C 8025392C 0040202D */  daddu     $a0, $v0, $zero
/* 182210 80253930 0C099117 */  jal       get_actor_part
/* 182214 80253934 0260282D */   daddu    $a1, $s3, $zero
/* 182218 80253938 C4400060 */  lwc1      $f0, 0x60($v0)
/* 18221C 8025393C 0200202D */  daddu     $a0, $s0, $zero
/* 182220 80253940 E7A00010 */  swc1      $f0, 0x10($sp)
/* 182224 80253944 8C460058 */  lw        $a2, 0x58($v0)
/* 182228 80253948 8C47005C */  lw        $a3, 0x5c($v0)
/* 18222C 8025394C 0C052757 */  jal       play_sound_at_position
/* 182230 80253950 0000282D */   daddu    $a1, $zero, $zero
/* 182234 80253954 8FBF0028 */  lw        $ra, 0x28($sp)
/* 182238 80253958 8FB30024 */  lw        $s3, 0x24($sp)
/* 18223C 8025395C 8FB20020 */  lw        $s2, 0x20($sp)
/* 182240 80253960 8FB1001C */  lw        $s1, 0x1c($sp)
/* 182244 80253964 8FB00018 */  lw        $s0, 0x18($sp)
/* 182248 80253968 24020002 */  addiu     $v0, $zero, 2
/* 18224C 8025396C 03E00008 */  jr        $ra
/* 182250 80253970 27BD0030 */   addiu    $sp, $sp, 0x30
