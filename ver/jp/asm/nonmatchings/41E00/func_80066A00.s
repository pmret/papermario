.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066A00
/* 41E00 80066A00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41E04 80066A04 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41E08 80066A08 0C01ACD0 */  jal       func_8006B340
/* 41E0C 80066A0C AFB00010 */   sw       $s0, 0x10($sp)
/* 41E10 80066A10 3C038009 */  lui       $v1, %hi(D_80095960)
/* 41E14 80066A14 8C635960 */  lw        $v1, %lo(D_80095960)($v1)
/* 41E18 80066A18 8C630008 */  lw        $v1, 8($v1)
/* 41E1C 80066A1C 90700000 */  lbu       $s0, ($v1)
/* 41E20 80066A20 0C01ACEC */  jal       func_8006B3B0
/* 41E24 80066A24 00402021 */   addu     $a0, $v0, $zero
/* 41E28 80066A28 02001021 */  addu      $v0, $s0, $zero
/* 41E2C 80066A2C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41E30 80066A30 8FB00010 */  lw        $s0, 0x10($sp)
/* 41E34 80066A34 03E00008 */  jr        $ra
/* 41E38 80066A38 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41E3C 80066A3C 00000000 */  nop
