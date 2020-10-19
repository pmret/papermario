.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A70_9B2200
/* 9B2200 80240A70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B2204 80240A74 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B2208 80240A78 0080802D */  daddu     $s0, $a0, $zero
/* 9B220C 80240A7C AFBF0014 */  sw        $ra, 0x14($sp)
/* 9B2210 80240A80 0C00EABB */  jal       get_npc_unsafe
/* 9B2214 80240A84 2404FFFC */   addiu    $a0, $zero, -4
/* 9B2218 80240A88 844200A8 */  lh        $v0, 0xa8($v0)
/* 9B221C 80240A8C 44820000 */  mtc1      $v0, $f0
/* 9B2220 80240A90 00000000 */  nop       
/* 9B2224 80240A94 46800020 */  cvt.s.w   $f0, $f0
/* 9B2228 80240A98 46000000 */  add.s     $f0, $f0, $f0
/* 9B222C 80240A9C 3C014040 */  lui       $at, 0x4040
/* 9B2230 80240AA0 44811000 */  mtc1      $at, $f2
/* 9B2234 80240AA4 3C014311 */  lui       $at, 0x4311
/* 9B2238 80240AA8 44812000 */  mtc1      $at, $f4
/* 9B223C 80240AAC 46020003 */  div.s     $f0, $f0, $f2
/* 9B2240 80240AB0 46040000 */  add.s     $f0, $f0, $f4
/* 9B2244 80240AB4 4600018D */  trunc.w.s $f6, $f0
/* 9B2248 80240AB8 E6060084 */  swc1      $f6, 0x84($s0)
/* 9B224C 80240ABC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9B2250 80240AC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B2254 80240AC4 24020002 */  addiu     $v0, $zero, 2
/* 9B2258 80240AC8 03E00008 */  jr        $ra
/* 9B225C 80240ACC 27BD0018 */   addiu    $sp, $sp, 0x18
