.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066DE0
/* 421E0 80066DE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 421E4 80066DE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 421E8 80066DE8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 421EC 80066DEC 0C01ACD0 */  jal       func_8006B340
/* 421F0 80066DF0 00808021 */   addu     $s0, $a0, $zero
/* 421F4 80066DF4 3C048009 */  lui       $a0, %hi(D_80095964)
/* 421F8 80066DF8 8C845964 */  lw        $a0, %lo(D_80095964)($a0)
/* 421FC 80066DFC AC900008 */  sw        $s0, 8($a0)
/* 42200 80066E00 8C850008 */  lw        $a1, 8($a0)
/* 42204 80066E04 24030001 */  addiu     $v1, $zero, 1
/* 42208 80066E08 A4830000 */  sh        $v1, ($a0)
/* 4220C 80066E0C 8CA30004 */  lw        $v1, 4($a1)
/* 42210 80066E10 AC83000C */  sw        $v1, 0xc($a0)
/* 42214 80066E14 0C01ACEC */  jal       func_8006B3B0
/* 42218 80066E18 00402021 */   addu     $a0, $v0, $zero
/* 4221C 80066E1C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42220 80066E20 8FB00010 */  lw        $s0, 0x10($sp)
/* 42224 80066E24 03E00008 */  jr        $ra
/* 42228 80066E28 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4222C 80066E2C 00000000 */  nop
