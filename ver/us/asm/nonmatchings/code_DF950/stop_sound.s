.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel stop_sound
/* E036C 80149C6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E0370 80149C70 AFBF0010 */  sw        $ra, 0x10($sp)
/* E0374 80149C74 0481000A */  bgez      $a0, .L80149CA0
/* E0378 80149C78 0080102D */   daddu    $v0, $a0, $zero
/* E037C 80149C7C 3082FFFF */  andi      $v0, $a0, 0xffff
/* E0380 80149C80 00021080 */  sll       $v0, $v0, 2
/* E0384 80149C84 3C048015 */  lui       $a0, %hi(D_8014F2D0)
/* E0388 80149C88 00822021 */  addu      $a0, $a0, $v0
/* E038C 80149C8C 8C84F2D0 */  lw        $a0, %lo(D_8014F2D0)($a0)
/* E0390 80149C90 0C05269B */  jal       func_80149A6C
/* E0394 80149C94 0000282D */   daddu    $a1, $zero, $zero
/* E0398 80149C98 0805272A */  j         .L80149CA8
/* E039C 80149C9C 00000000 */   nop
.L80149CA0:
/* E03A0 80149CA0 0C0154F0 */  jal       snd_stop_sound
/* E03A4 80149CA4 0040202D */   daddu    $a0, $v0, $zero
.L80149CA8:
/* E03A8 80149CA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E03AC 80149CAC 03E00008 */  jr        $ra
/* E03B0 80149CB0 27BD0018 */   addiu    $sp, $sp, 0x18
