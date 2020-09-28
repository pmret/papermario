.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViSetMode
/* 42210 80066E10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42214 80066E14 AFB00010 */  sw        $s0, 0x10($sp)
/* 42218 80066E18 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4221C 80066E1C 0C01ACD8 */  jal       __osDisableInt
/* 42220 80066E20 00808021 */   addu     $s0, $a0, $zero
/* 42224 80066E24 3C048009 */  lui       $a0, %hi(D_800959D4)
/* 42228 80066E28 8C8459D4 */  lw        $a0, %lo(D_800959D4)($a0)
/* 4222C 80066E2C AC900008 */  sw        $s0, 8($a0)
/* 42230 80066E30 8C850008 */  lw        $a1, 8($a0)
/* 42234 80066E34 24030001 */  addiu     $v1, $zero, 1
/* 42238 80066E38 A4830000 */  sh        $v1, ($a0)
/* 4223C 80066E3C 8CA30004 */  lw        $v1, 4($a1)
/* 42240 80066E40 AC83000C */  sw        $v1, 0xc($a0)
/* 42244 80066E44 0C01ACF4 */  jal       __osRestoreInt
/* 42248 80066E48 00402021 */   addu     $a0, $v0, $zero
/* 4224C 80066E4C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42250 80066E50 8FB00010 */  lw        $s0, 0x10($sp)
/* 42254 80066E54 03E00008 */  jr        $ra
/* 42258 80066E58 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4225C 80066E5C 00000000 */  nop       
