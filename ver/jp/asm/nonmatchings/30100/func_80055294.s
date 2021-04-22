.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055294
/* 30694 80055294 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 30698 80055298 AFB00010 */  sw        $s0, 0x10($sp)
/* 3069C 8005529C AFBF0014 */  sw        $ra, 0x14($sp)
/* 306A0 800552A0 0C014238 */  jal       func_800508E0
/* 306A4 800552A4 0080802D */   daddu    $s0, $a0, $zero
/* 306A8 800552A8 14400003 */  bnez      $v0, .L800552B8
/* 306AC 800552AC 00000000 */   nop
/* 306B0 800552B0 0C014340 */  jal       func_80050D00
/* 306B4 800552B4 0200202D */   daddu    $a0, $s0, $zero
.L800552B8:
/* 306B8 800552B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 306BC 800552BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 306C0 800552C0 03E00008 */  jr        $ra
/* 306C4 800552C4 27BD0018 */   addiu    $sp, $sp, 0x18
