.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B02C_6A222C
/* 6A222C 8021B02C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A2230 8021B030 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A2234 8021B034 0080882D */  daddu     $s1, $a0, $zero
/* 6A2238 8021B038 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A223C 8021B03C 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 6A2240 8021B040 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 6A2244 8021B044 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A2248 8021B048 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A224C 8021B04C 8E30000C */  lw        $s0, 0xc($s1)
/* 6A2250 8021B050 82460097 */  lb        $a2, 0x97($s2)
/* 6A2254 8021B054 8E050000 */  lw        $a1, ($s0)
/* 6A2258 8021B058 0C0B2026 */  jal       set_variable
/* 6A225C 8021B05C 26100004 */   addiu    $s0, $s0, 4
/* 6A2260 8021B060 8E050000 */  lw        $a1, ($s0)
/* 6A2264 8021B064 82460096 */  lb        $a2, 0x96($s2)
/* 6A2268 8021B068 0C0B2026 */  jal       set_variable
/* 6A226C 8021B06C 0220202D */   daddu    $a0, $s1, $zero
/* 6A2270 8021B070 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A2274 8021B074 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A2278 8021B078 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A227C 8021B07C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A2280 8021B080 24020002 */  addiu     $v0, $zero, 2
/* 6A2284 8021B084 03E00008 */  jr        $ra
/* 6A2288 8021B088 27BD0020 */   addiu    $sp, $sp, 0x20
