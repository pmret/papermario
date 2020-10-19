.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_A071E0
/* A071E0 802402E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A071E4 802402E4 AFB20018 */  sw        $s2, 0x18($sp)
/* A071E8 802402E8 0080902D */  daddu     $s2, $a0, $zero
/* A071EC 802402EC AFBF001C */  sw        $ra, 0x1c($sp)
/* A071F0 802402F0 AFB10014 */  sw        $s1, 0x14($sp)
/* A071F4 802402F4 AFB00010 */  sw        $s0, 0x10($sp)
/* A071F8 802402F8 8E510148 */  lw        $s1, 0x148($s2)
/* A071FC 802402FC 0C00EABB */  jal       get_npc_unsafe
/* A07200 80240300 86240008 */   lh       $a0, 8($s1)
/* A07204 80240304 0040802D */  daddu     $s0, $v0, $zero
/* A07208 80240308 8E2300CC */  lw        $v1, 0xcc($s1)
/* A0720C 8024030C C60C0038 */  lwc1      $f12, 0x38($s0)
/* A07210 80240310 8C630020 */  lw        $v1, 0x20($v1)
/* A07214 80240314 AE030028 */  sw        $v1, 0x28($s0)
/* A07218 80240318 96220076 */  lhu       $v0, 0x76($s1)
/* A0721C 8024031C A602008E */  sh        $v0, 0x8e($s0)
/* A07220 80240320 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A07224 80240324 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A07228 80240328 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A0722C 8024032C 8C460028 */  lw        $a2, 0x28($v0)
/* A07230 80240330 0C00A720 */  jal       atan2
/* A07234 80240334 8C470030 */   lw       $a3, 0x30($v0)
/* A07238 80240338 2402000D */  addiu     $v0, $zero, 0xd
/* A0723C 8024033C E600000C */  swc1      $f0, 0xc($s0)
/* A07240 80240340 AE420070 */  sw        $v0, 0x70($s2)
/* A07244 80240344 8FBF001C */  lw        $ra, 0x1c($sp)
/* A07248 80240348 8FB20018 */  lw        $s2, 0x18($sp)
/* A0724C 8024034C 8FB10014 */  lw        $s1, 0x14($sp)
/* A07250 80240350 8FB00010 */  lw        $s0, 0x10($sp)
/* A07254 80240354 03E00008 */  jr        $ra
/* A07258 80240358 27BD0020 */   addiu    $sp, $sp, 0x20
