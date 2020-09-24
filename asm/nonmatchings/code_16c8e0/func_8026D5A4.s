.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026D5A4
/* 19BE84 8026D5A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19BE88 8026D5A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 19BE8C 8026D5AC 0080882D */  daddu     $s1, $a0, $zero
/* 19BE90 8026D5B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19BE94 8026D5B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19BE98 8026D5B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 19BE9C 8026D5BC AFB00010 */  sw        $s0, 0x10($sp)
/* 19BEA0 8026D5C0 8E30000C */  lw        $s0, 0xc($s1)
/* 19BEA4 8026D5C4 8E050000 */  lw        $a1, ($s0)
/* 19BEA8 8026D5C8 0C0B1EAF */  jal       get_variable
/* 19BEAC 8026D5CC 26100004 */   addiu    $s0, $s0, 4
/* 19BEB0 8026D5D0 0040902D */  daddu     $s2, $v0, $zero
/* 19BEB4 8026D5D4 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BEB8 8026D5D8 16420002 */  bne       $s2, $v0, .L8026D5E4
/* 19BEBC 8026D5DC 00000000 */   nop      
/* 19BEC0 8026D5E0 8E320148 */  lw        $s2, 0x148($s1)
.L8026D5E4:
/* 19BEC4 8026D5E4 8E050000 */  lw        $a1, ($s0)
/* 19BEC8 8026D5E8 26100004 */  addiu     $s0, $s0, 4
/* 19BECC 8026D5EC 0C0B1EAF */  jal       get_variable
/* 19BED0 8026D5F0 0220202D */   daddu    $a0, $s1, $zero
/* 19BED4 8026D5F4 0220202D */  daddu     $a0, $s1, $zero
/* 19BED8 8026D5F8 8E050004 */  lw        $a1, 4($s0)
/* 19BEDC 8026D5FC 8E130000 */  lw        $s3, ($s0)
/* 19BEE0 8026D600 0C0B1EAF */  jal       get_variable
/* 19BEE4 8026D604 0040882D */   daddu    $s1, $v0, $zero
/* 19BEE8 8026D608 0240202D */  daddu     $a0, $s2, $zero
/* 19BEEC 8026D60C 0C09A75B */  jal       get_actor
/* 19BEF0 8026D610 0040802D */   daddu    $s0, $v0, $zero
/* 19BEF4 8026D614 0040202D */  daddu     $a0, $v0, $zero
/* 19BEF8 8026D618 0C099117 */  jal       get_actor_part
/* 19BEFC 8026D61C 0220282D */   daddu    $a1, $s1, $zero
/* 19BF00 8026D620 12000004 */  beqz      $s0, .L8026D634
/* 19BF04 8026D624 0040202D */   daddu    $a0, $v0, $zero
/* 19BF08 8026D628 8C820080 */  lw        $v0, 0x80($a0)
/* 19BF0C 8026D62C 0809B590 */  j         .L8026D640
/* 19BF10 8026D630 00531025 */   or       $v0, $v0, $s3
.L8026D634:
/* 19BF14 8026D634 8C820080 */  lw        $v0, 0x80($a0)
/* 19BF18 8026D638 00131827 */  nor       $v1, $zero, $s3
/* 19BF1C 8026D63C 00431024 */  and       $v0, $v0, $v1
.L8026D640:
/* 19BF20 8026D640 AC820080 */  sw        $v0, 0x80($a0)
/* 19BF24 8026D644 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19BF28 8026D648 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19BF2C 8026D64C 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BF30 8026D650 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BF34 8026D654 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BF38 8026D658 24020002 */  addiu     $v0, $zero, 2
/* 19BF3C 8026D65C 03E00008 */  jr        $ra
/* 19BF40 8026D660 27BD0028 */   addiu    $sp, $sp, 0x28
