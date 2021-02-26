.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052250
/* 2D650 80052250 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2D654 80052254 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2D658 80052258 0080982D */  daddu     $s3, $a0, $zero
/* 2D65C 8005225C AFB10014 */  sw        $s1, 0x14($sp)
/* 2D660 80052260 0000882D */  daddu     $s1, $zero, $zero
/* 2D664 80052264 AFB20018 */  sw        $s2, 0x18($sp)
/* 2D668 80052268 24121320 */  addiu     $s2, $zero, 0x1320
/* 2D66C 8005226C AFBF0020 */  sw        $ra, 0x20($sp)
/* 2D670 80052270 AFB00010 */  sw        $s0, 0x10($sp)
.L80052274:
/* 2D674 80052274 02728021 */  addu      $s0, $s3, $s2
/* 2D678 80052278 92020042 */  lbu       $v0, 0x42($s0)
/* 2D67C 8005227C 50400007 */  beql      $v0, $zero, .L8005229C
/* 2D680 80052280 26310001 */   addiu    $s1, $s1, 1
/* 2D684 80052284 0C015AE6 */  jal       func_80056B98
/* 2D688 80052288 322400FF */   andi     $a0, $s1, 0xff
/* 2D68C 8005228C A2000042 */  sb        $zero, 0x42($s0)
/* 2D690 80052290 AE00001C */  sw        $zero, 0x1c($s0)
/* 2D694 80052294 A2000045 */  sb        $zero, 0x45($s0)
/* 2D698 80052298 26310001 */  addiu     $s1, $s1, 1
.L8005229C:
/* 2D69C 8005229C 2A220018 */  slti      $v0, $s1, 0x18
/* 2D6A0 800522A0 1440FFF4 */  bnez      $v0, .L80052274
/* 2D6A4 800522A4 26520048 */   addiu    $s2, $s2, 0x48
/* 2D6A8 800522A8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 2D6AC 800522AC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2D6B0 800522B0 8FB20018 */  lw        $s2, 0x18($sp)
/* 2D6B4 800522B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 2D6B8 800522B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 2D6BC 800522BC 03E00008 */  jr        $ra
/* 2D6C0 800522C0 27BD0028 */   addiu    $sp, $sp, 0x28
