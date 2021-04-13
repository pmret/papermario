.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EF00
/* 3A300 8005EF00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A304 8005EF04 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A308 8005EF08 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3A30C 8005EF0C 0C017BE0 */  jal       func_8005EF80
/* 3A310 8005EF10 0080802D */   daddu    $s0, $a0, $zero
/* 3A314 8005EF14 0C018244 */  jal       func_80060910
/* 3A318 8005EF18 24040001 */   addiu    $a0, $zero, 1
/* 3A31C 8005EF1C 3C018009 */  lui       $at, %hi(D_80093CE0)
/* 3A320 8005EF20 AC303CE0 */  sw        $s0, %lo(D_80093CE0)($at)
/* 3A324 8005EF24 0C018244 */  jal       func_80060910
/* 3A328 8005EF28 0040202D */   daddu    $a0, $v0, $zero
/* 3A32C 8005EF2C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3A330 8005EF30 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A334 8005EF34 03E00008 */  jr        $ra
/* 3A338 8005EF38 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3A33C 8005EF3C 00000000 */  nop
