.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218130_58C420
/* 58C420 80218130 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 58C424 80218134 AFB10014 */  sw        $s1, 0x14($sp)
/* 58C428 80218138 0080882D */  daddu     $s1, $a0, $zero
/* 58C42C 8021813C AFBF0020 */  sw        $ra, 0x20($sp)
/* 58C430 80218140 AFB3001C */  sw        $s3, 0x1c($sp)
/* 58C434 80218144 AFB20018 */  sw        $s2, 0x18($sp)
/* 58C438 80218148 AFB00010 */  sw        $s0, 0x10($sp)
/* 58C43C 8021814C 8E30000C */  lw        $s0, 0xc($s1)
/* 58C440 80218150 8E050000 */  lw        $a1, ($s0)
/* 58C444 80218154 0C0B1EAF */  jal       get_variable
/* 58C448 80218158 26100004 */   addiu    $s0, $s0, 4
/* 58C44C 8021815C 8E050000 */  lw        $a1, ($s0)
/* 58C450 80218160 26100004 */  addiu     $s0, $s0, 4
/* 58C454 80218164 0220202D */  daddu     $a0, $s1, $zero
/* 58C458 80218168 0C0B1EAF */  jal       get_variable
/* 58C45C 8021816C 0040982D */   daddu    $s3, $v0, $zero
/* 58C460 80218170 8E050000 */  lw        $a1, ($s0)
/* 58C464 80218174 26100004 */  addiu     $s0, $s0, 4
/* 58C468 80218178 0220202D */  daddu     $a0, $s1, $zero
/* 58C46C 8021817C 0C0B1EAF */  jal       get_variable
/* 58C470 80218180 0040902D */   daddu    $s2, $v0, $zero
/* 58C474 80218184 0220202D */  daddu     $a0, $s1, $zero
/* 58C478 80218188 8E050000 */  lw        $a1, ($s0)
/* 58C47C 8021818C 0C0B1EAF */  jal       get_variable
/* 58C480 80218190 0040802D */   daddu    $s0, $v0, $zero
/* 58C484 80218194 8E240148 */  lw        $a0, 0x148($s1)
/* 58C488 80218198 0C09A75B */  jal       get_actor
/* 58C48C 8021819C 0040882D */   daddu    $s1, $v0, $zero
/* 58C490 802181A0 0040182D */  daddu     $v1, $v0, $zero
/* 58C494 802181A4 8C620008 */  lw        $v0, 8($v1)
/* 58C498 802181A8 90420024 */  lbu       $v0, 0x24($v0)
/* 58C49C 802181AC 8C640008 */  lw        $a0, 8($v1)
/* 58C4A0 802181B0 02629823 */  subu      $s3, $s3, $v0
/* 58C4A4 802181B4 A0730194 */  sb        $s3, 0x194($v1)
/* 58C4A8 802181B8 90820025 */  lbu       $v0, 0x25($a0)
/* 58C4AC 802181BC 02429023 */  subu      $s2, $s2, $v0
/* 58C4B0 802181C0 A0720195 */  sb        $s2, 0x195($v1)
/* 58C4B4 802181C4 90820026 */  lbu       $v0, 0x26($a0)
/* 58C4B8 802181C8 02028023 */  subu      $s0, $s0, $v0
/* 58C4BC 802181CC A0700196 */  sb        $s0, 0x196($v1)
/* 58C4C0 802181D0 90840027 */  lbu       $a0, 0x27($a0)
/* 58C4C4 802181D4 02248823 */  subu      $s1, $s1, $a0
/* 58C4C8 802181D8 A0710197 */  sb        $s1, 0x197($v1)
/* 58C4CC 802181DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 58C4D0 802181E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 58C4D4 802181E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 58C4D8 802181E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 58C4DC 802181EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 58C4E0 802181F0 24020002 */  addiu     $v0, $zero, 2
/* 58C4E4 802181F4 03E00008 */  jr        $ra
/* 58C4E8 802181F8 27BD0028 */   addiu    $sp, $sp, 0x28
