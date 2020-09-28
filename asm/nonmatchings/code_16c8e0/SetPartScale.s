.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartScale
/* 19B42C 8026CB4C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 19B430 8026CB50 AFB10014 */  sw        $s1, 0x14($sp)
/* 19B434 8026CB54 0080882D */  daddu     $s1, $a0, $zero
/* 19B438 8026CB58 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19B43C 8026CB5C AFB3001C */  sw        $s3, 0x1c($sp)
/* 19B440 8026CB60 AFB20018 */  sw        $s2, 0x18($sp)
/* 19B444 8026CB64 AFB00010 */  sw        $s0, 0x10($sp)
/* 19B448 8026CB68 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 19B44C 8026CB6C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 19B450 8026CB70 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 19B454 8026CB74 8E30000C */  lw        $s0, 0xc($s1)
/* 19B458 8026CB78 8E050000 */  lw        $a1, ($s0)
/* 19B45C 8026CB7C 0C0B1EAF */  jal       get_variable
/* 19B460 8026CB80 26100004 */   addiu    $s0, $s0, 4
/* 19B464 8026CB84 0040902D */  daddu     $s2, $v0, $zero
/* 19B468 8026CB88 8E050000 */  lw        $a1, ($s0)
/* 19B46C 8026CB8C 26100004 */  addiu     $s0, $s0, 4
/* 19B470 8026CB90 0C0B1EAF */  jal       get_variable
/* 19B474 8026CB94 0220202D */   daddu    $a0, $s1, $zero
/* 19B478 8026CB98 0040982D */  daddu     $s3, $v0, $zero
/* 19B47C 8026CB9C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19B480 8026CBA0 16420002 */  bne       $s2, $v0, .L8026CBAC
/* 19B484 8026CBA4 00000000 */   nop      
/* 19B488 8026CBA8 8E320148 */  lw        $s2, 0x148($s1)
.L8026CBAC:
/* 19B48C 8026CBAC 8E050000 */  lw        $a1, ($s0)
/* 19B490 8026CBB0 26100004 */  addiu     $s0, $s0, 4
/* 19B494 8026CBB4 0C0B210B */  jal       get_float_variable
/* 19B498 8026CBB8 0220202D */   daddu    $a0, $s1, $zero
/* 19B49C 8026CBBC 8E050000 */  lw        $a1, ($s0)
/* 19B4A0 8026CBC0 26100004 */  addiu     $s0, $s0, 4
/* 19B4A4 8026CBC4 0220202D */  daddu     $a0, $s1, $zero
/* 19B4A8 8026CBC8 0C0B210B */  jal       get_float_variable
/* 19B4AC 8026CBCC 46000606 */   mov.s    $f24, $f0
/* 19B4B0 8026CBD0 0220202D */  daddu     $a0, $s1, $zero
/* 19B4B4 8026CBD4 8E050000 */  lw        $a1, ($s0)
/* 19B4B8 8026CBD8 0C0B210B */  jal       get_float_variable
/* 19B4BC 8026CBDC 46000586 */   mov.s    $f22, $f0
/* 19B4C0 8026CBE0 0240202D */  daddu     $a0, $s2, $zero
/* 19B4C4 8026CBE4 0C09A75B */  jal       get_actor
/* 19B4C8 8026CBE8 46000506 */   mov.s    $f20, $f0
/* 19B4CC 8026CBEC 0040202D */  daddu     $a0, $v0, $zero
/* 19B4D0 8026CBF0 0C099117 */  jal       get_actor_part
/* 19B4D4 8026CBF4 0260282D */   daddu    $a1, $s3, $zero
/* 19B4D8 8026CBF8 0040182D */  daddu     $v1, $v0, $zero
/* 19B4DC 8026CBFC E478004C */  swc1      $f24, 0x4c($v1)
/* 19B4E0 8026CC00 E4760050 */  swc1      $f22, 0x50($v1)
/* 19B4E4 8026CC04 E4740054 */  swc1      $f20, 0x54($v1)
/* 19B4E8 8026CC08 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19B4EC 8026CC0C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19B4F0 8026CC10 8FB20018 */  lw        $s2, 0x18($sp)
/* 19B4F4 8026CC14 8FB10014 */  lw        $s1, 0x14($sp)
/* 19B4F8 8026CC18 8FB00010 */  lw        $s0, 0x10($sp)
/* 19B4FC 8026CC1C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 19B500 8026CC20 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 19B504 8026CC24 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 19B508 8026CC28 24020002 */  addiu     $v0, $zero, 2
/* 19B50C 8026CC2C 03E00008 */  jr        $ra
/* 19B510 8026CC30 27BD0040 */   addiu    $sp, $sp, 0x40
