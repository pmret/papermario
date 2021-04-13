.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060DF0
/* 3C1F0 80060DF0 3C028009 */  lui       $v0, %hi(D_80093D30)
/* 3C1F4 80060DF4 8C423D30 */  lw        $v0, %lo(D_80093D30)($v0)
/* 3C1F8 80060DF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C1FC 80060DFC AFB00010 */  sw        $s0, 0x10($sp)
/* 3C200 80060E00 00A08021 */  addu      $s0, $a1, $zero
/* 3C204 80060E04 14400003 */  bnez      $v0, .L80060E14
/* 3C208 80060E08 AFBF0014 */   sw       $ra, 0x14($sp)
/* 3C20C 80060E0C 0801839D */  j         .L80060E74
/* 3C210 80060E10 2402FFFF */   addiu    $v0, $zero, -1
.L80060E14:
/* 3C214 80060E14 14C00003 */  bnez      $a2, .L80060E24
/* 3C218 80060E18 AE040014 */   sw       $a0, 0x14($s0)
/* 3C21C 80060E1C 0801838A */  j         .L80060E28
/* 3C220 80060E20 2402000F */   addiu    $v0, $zero, 0xf
.L80060E24:
/* 3C224 80060E24 24020010 */  addiu     $v0, $zero, 0x10
.L80060E28:
/* 3C228 80060E28 A6020000 */  sh        $v0, ($s0)
/* 3C22C 80060E2C 92030002 */  lbu       $v1, 2($s0)
/* 3C230 80060E30 24020001 */  addiu     $v0, $zero, 1
/* 3C234 80060E34 14620009 */  bne       $v1, $v0, .L80060E5C
/* 3C238 80060E38 00000000 */   nop
/* 3C23C 80060E3C 0C01AD4C */  jal       func_8006B530
/* 3C240 80060E40 00000000 */   nop
/* 3C244 80060E44 00402021 */  addu      $a0, $v0, $zero
/* 3C248 80060E48 02002821 */  addu      $a1, $s0, $zero
/* 3C24C 80060E4C 0C019560 */  jal       func_80065580
/* 3C250 80060E50 00003021 */   addu     $a2, $zero, $zero
/* 3C254 80060E54 0801839D */  j         .L80060E74
/* 3C258 80060E58 00000000 */   nop
.L80060E5C:
/* 3C25C 80060E5C 0C01AD4C */  jal       func_8006B530
/* 3C260 80060E60 00000000 */   nop
/* 3C264 80060E64 00402021 */  addu      $a0, $v0, $zero
/* 3C268 80060E68 02002821 */  addu      $a1, $s0, $zero
/* 3C26C 80060E6C 0C0195FC */  jal       func_800657F0
/* 3C270 80060E70 00003021 */   addu     $a2, $zero, $zero
.L80060E74:
/* 3C274 80060E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3C278 80060E78 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C27C 80060E7C 03E00008 */  jr        $ra
/* 3C280 80060E80 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3C284 80060E84 00000000 */  nop
/* 3C288 80060E88 00000000 */  nop
/* 3C28C 80060E8C 00000000 */  nop
