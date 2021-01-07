.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243014_95E214
/* 95E214 80243014 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95E218 80243018 AFB00010 */  sw        $s0, 0x10($sp)
/* 95E21C 8024301C 0080802D */  daddu     $s0, $a0, $zero
/* 95E220 80243020 AFBF0014 */  sw        $ra, 0x14($sp)
/* 95E224 80243024 0C00EABB */  jal       get_npc_unsafe
/* 95E228 80243028 8E04008C */   lw       $a0, 0x8c($s0)
/* 95E22C 8024302C 0040282D */  daddu     $a1, $v0, $zero
/* 95E230 80243030 8E040094 */  lw        $a0, 0x94($s0)
/* 95E234 80243034 8CA30028 */  lw        $v1, 0x28($a1)
/* 95E238 80243038 ACA40028 */  sw        $a0, 0x28($a1)
/* 95E23C 8024303C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 95E240 80243040 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E244 80243044 24020002 */  addiu     $v0, $zero, 2
/* 95E248 80243048 3C018025 */  lui       $at, %hi(D_8024E1B4)
/* 95E24C 8024304C AC23E1B4 */  sw        $v1, %lo(D_8024E1B4)($at)
/* 95E250 80243050 03E00008 */  jr        $ra
/* 95E254 80243054 27BD0018 */   addiu    $sp, $sp, 0x18
