.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060E90
/* 3C290 80060E90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C294 80060E94 AFB00010 */  sw        $s0, 0x10($sp)
/* 3C298 80060E98 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3C29C 80060E9C 0C01ACD0 */  jal       func_8006B340
/* 3C2A0 80060EA0 00808021 */   addu     $s0, $a0, $zero
/* 3C2A4 80060EA4 3C038009 */  lui       $v1, %hi(D_80093D4C)
/* 3C2A8 80060EA8 8C633D4C */  lw        $v1, %lo(D_80093D4C)($v1)
/* 3C2AC 80060EAC 00402021 */  addu      $a0, $v0, $zero
/* 3C2B0 80060EB0 3C018009 */  lui       $at, %hi(D_80093D4C)
/* 3C2B4 80060EB4 AC303D4C */  sw        $s0, %lo(D_80093D4C)($at)
/* 3C2B8 80060EB8 0C01ACEC */  jal       func_8006B3B0
/* 3C2BC 80060EBC AE030000 */   sw       $v1, ($s0)
/* 3C2C0 80060EC0 00001021 */  addu      $v0, $zero, $zero
/* 3C2C4 80060EC4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3C2C8 80060EC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C2CC 80060ECC 03E00008 */  jr        $ra
/* 3C2D0 80060ED0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3C2D4 80060ED4 00000000 */  nop
/* 3C2D8 80060ED8 00000000 */  nop
/* 3C2DC 80060EDC 00000000 */  nop
