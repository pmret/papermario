.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartAlpha
/* 19DD50 8026F470 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19DD54 8026F474 AFB20018 */  sw        $s2, 0x18($sp)
/* 19DD58 8026F478 0080902D */  daddu     $s2, $a0, $zero
/* 19DD5C 8026F47C AFBF0024 */  sw        $ra, 0x24($sp)
/* 19DD60 8026F480 AFB40020 */  sw        $s4, 0x20($sp)
/* 19DD64 8026F484 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19DD68 8026F488 AFB10014 */  sw        $s1, 0x14($sp)
/* 19DD6C 8026F48C AFB00010 */  sw        $s0, 0x10($sp)
/* 19DD70 8026F490 8E50000C */  lw        $s0, 0xc($s2)
/* 19DD74 8026F494 8E050000 */  lw        $a1, ($s0)
/* 19DD78 8026F498 0C0B1EAF */  jal       evt_get_variable
/* 19DD7C 8026F49C 26100004 */   addiu    $s0, $s0, 4
/* 19DD80 8026F4A0 0040882D */  daddu     $s1, $v0, $zero
/* 19DD84 8026F4A4 8E050000 */  lw        $a1, ($s0)
/* 19DD88 8026F4A8 26100004 */  addiu     $s0, $s0, 4
/* 19DD8C 8026F4AC 0C0B1EAF */  jal       evt_get_variable
/* 19DD90 8026F4B0 0240202D */   daddu    $a0, $s2, $zero
/* 19DD94 8026F4B4 0240202D */  daddu     $a0, $s2, $zero
/* 19DD98 8026F4B8 8E050000 */  lw        $a1, ($s0)
/* 19DD9C 8026F4BC 0C0B1EAF */  jal       evt_get_variable
/* 19DDA0 8026F4C0 0040A02D */   daddu    $s4, $v0, $zero
/* 19DDA4 8026F4C4 0040982D */  daddu     $s3, $v0, $zero
/* 19DDA8 8026F4C8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19DDAC 8026F4CC 16220002 */  bne       $s1, $v0, .L8026F4D8
/* 19DDB0 8026F4D0 00000000 */   nop
/* 19DDB4 8026F4D4 8E510148 */  lw        $s1, 0x148($s2)
.L8026F4D8:
/* 19DDB8 8026F4D8 0C09A75B */  jal       get_actor
/* 19DDBC 8026F4DC 0220202D */   daddu    $a0, $s1, $zero
/* 19DDC0 8026F4E0 0040802D */  daddu     $s0, $v0, $zero
/* 19DDC4 8026F4E4 0200202D */  daddu     $a0, $s0, $zero
/* 19DDC8 8026F4E8 0C099117 */  jal       get_actor_part
/* 19DDCC 8026F4EC 0280282D */   daddu    $a1, $s4, $zero
/* 19DDD0 8026F4F0 A4530098 */  sh        $s3, 0x98($v0)
/* 19DDD4 8026F4F4 240200FF */  addiu     $v0, $zero, 0xff
/* 19DDD8 8026F4F8 16620002 */  bne       $s3, $v0, .L8026F504
/* 19DDDC 8026F4FC 24020022 */   addiu    $v0, $zero, 0x22
/* 19DDE0 8026F500 2402000D */  addiu     $v0, $zero, 0xd
.L8026F504:
/* 19DDE4 8026F504 A6020434 */  sh        $v0, 0x434($s0)
/* 19DDE8 8026F508 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19DDEC 8026F50C 8FB40020 */  lw        $s4, 0x20($sp)
/* 19DDF0 8026F510 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19DDF4 8026F514 8FB20018 */  lw        $s2, 0x18($sp)
/* 19DDF8 8026F518 8FB10014 */  lw        $s1, 0x14($sp)
/* 19DDFC 8026F51C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DE00 8026F520 24020002 */  addiu     $v0, $zero, 2
/* 19DE04 8026F524 03E00008 */  jr        $ra
/* 19DE08 8026F528 27BD0028 */   addiu    $sp, $sp, 0x28
