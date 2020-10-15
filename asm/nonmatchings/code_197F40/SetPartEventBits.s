.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartEventBits
/* 19BCA8 8026D3C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19BCAC 8026D3CC AFB10014 */  sw        $s1, 0x14($sp)
/* 19BCB0 8026D3D0 0080882D */  daddu     $s1, $a0, $zero
/* 19BCB4 8026D3D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19BCB8 8026D3D8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19BCBC 8026D3DC AFB20018 */  sw        $s2, 0x18($sp)
/* 19BCC0 8026D3E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 19BCC4 8026D3E4 8E30000C */  lw        $s0, 0xc($s1)
/* 19BCC8 8026D3E8 8E050000 */  lw        $a1, ($s0)
/* 19BCCC 8026D3EC 0C0B1EAF */  jal       get_variable
/* 19BCD0 8026D3F0 26100004 */   addiu    $s0, $s0, 4
/* 19BCD4 8026D3F4 0040902D */  daddu     $s2, $v0, $zero
/* 19BCD8 8026D3F8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BCDC 8026D3FC 16420002 */  bne       $s2, $v0, .L8026D408
/* 19BCE0 8026D400 00000000 */   nop      
/* 19BCE4 8026D404 8E320148 */  lw        $s2, 0x148($s1)
.L8026D408:
/* 19BCE8 8026D408 8E050000 */  lw        $a1, ($s0)
/* 19BCEC 8026D40C 26100004 */  addiu     $s0, $s0, 4
/* 19BCF0 8026D410 0C0B1EAF */  jal       get_variable
/* 19BCF4 8026D414 0220202D */   daddu    $a0, $s1, $zero
/* 19BCF8 8026D418 0220202D */  daddu     $a0, $s1, $zero
/* 19BCFC 8026D41C 8E050004 */  lw        $a1, 4($s0)
/* 19BD00 8026D420 8E130000 */  lw        $s3, ($s0)
/* 19BD04 8026D424 0C0B1EAF */  jal       get_variable
/* 19BD08 8026D428 0040882D */   daddu    $s1, $v0, $zero
/* 19BD0C 8026D42C 0240202D */  daddu     $a0, $s2, $zero
/* 19BD10 8026D430 0C09A75B */  jal       get_actor
/* 19BD14 8026D434 0040802D */   daddu    $s0, $v0, $zero
/* 19BD18 8026D438 0040202D */  daddu     $a0, $v0, $zero
/* 19BD1C 8026D43C 0C099117 */  jal       get_actor_part
/* 19BD20 8026D440 0220282D */   daddu    $a1, $s1, $zero
/* 19BD24 8026D444 12000004 */  beqz      $s0, .L8026D458
/* 19BD28 8026D448 0040202D */   daddu    $a0, $v0, $zero
/* 19BD2C 8026D44C 8C82007C */  lw        $v0, 0x7c($a0)
/* 19BD30 8026D450 0809B519 */  j         .L8026D464
/* 19BD34 8026D454 00531025 */   or       $v0, $v0, $s3
.L8026D458:
/* 19BD38 8026D458 8C82007C */  lw        $v0, 0x7c($a0)
/* 19BD3C 8026D45C 00131827 */  nor       $v1, $zero, $s3
/* 19BD40 8026D460 00431024 */  and       $v0, $v0, $v1
.L8026D464:
/* 19BD44 8026D464 AC82007C */  sw        $v0, 0x7c($a0)
/* 19BD48 8026D468 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19BD4C 8026D46C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19BD50 8026D470 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BD54 8026D474 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BD58 8026D478 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BD5C 8026D47C 24020002 */  addiu     $v0, $zero, 2
/* 19BD60 8026D480 03E00008 */  jr        $ra
/* 19BD64 8026D484 27BD0028 */   addiu    $sp, $sp, 0x28
