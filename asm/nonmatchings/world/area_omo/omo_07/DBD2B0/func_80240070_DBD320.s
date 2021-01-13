.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_DBD320
/* DBD320 80240070 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DBD324 80240074 AFB20028 */  sw        $s2, 0x28($sp)
/* DBD328 80240078 0080902D */  daddu     $s2, $a0, $zero
/* DBD32C 8024007C AFBF002C */  sw        $ra, 0x2c($sp)
/* DBD330 80240080 AFB10024 */  sw        $s1, 0x24($sp)
/* DBD334 80240084 AFB00020 */  sw        $s0, 0x20($sp)
/* DBD338 80240088 8E510148 */  lw        $s1, 0x148($s2)
/* DBD33C 8024008C 0C00EABB */  jal       get_npc_unsafe
/* DBD340 80240090 86240008 */   lh       $a0, 8($s1)
/* DBD344 80240094 0040802D */  daddu     $s0, $v0, $zero
/* DBD348 80240098 0200202D */  daddu     $a0, $s0, $zero
/* DBD34C 8024009C C600000C */  lwc1      $f0, 0xc($s0)
/* DBD350 802400A0 27A60018 */  addiu     $a2, $sp, 0x18
/* DBD354 802400A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* DBD358 802400A8 AFA00010 */  sw        $zero, 0x10($sp)
/* DBD35C 802400AC AFA00014 */  sw        $zero, 0x14($sp)
/* DBD360 802400B0 8E050018 */  lw        $a1, 0x18($s0)
/* DBD364 802400B4 0C0129E1 */  jal       func_8004A784
/* DBD368 802400B8 0000382D */   daddu    $a3, $zero, $zero
/* DBD36C 802400BC 14400005 */  bnez      $v0, .L802400D4
/* DBD370 802400C0 00000000 */   nop
/* DBD374 802400C4 8E050018 */  lw        $a1, 0x18($s0)
/* DBD378 802400C8 8E06000C */  lw        $a2, 0xc($s0)
/* DBD37C 802400CC 0C00EA95 */  jal       npc_move_heading
/* DBD380 802400D0 0200202D */   daddu    $a0, $s0, $zero
.L802400D4:
/* DBD384 802400D4 9602008E */  lhu       $v0, 0x8e($s0)
/* DBD388 802400D8 2442FFFF */  addiu     $v0, $v0, -1
/* DBD38C 802400DC A602008E */  sh        $v0, 0x8e($s0)
/* DBD390 802400E0 00021400 */  sll       $v0, $v0, 0x10
/* DBD394 802400E4 14400010 */  bnez      $v0, .L80240128
/* DBD398 802400E8 00000000 */   nop
/* DBD39C 802400EC C6000018 */  lwc1      $f0, 0x18($s0)
/* DBD3A0 802400F0 3C018024 */  lui       $at, %hi(D_80246BD8)
/* DBD3A4 802400F4 D4226BD8 */  ldc1      $f2, %lo(D_80246BD8)($at)
/* DBD3A8 802400F8 46000021 */  cvt.d.s   $f0, $f0
/* DBD3AC 802400FC 46220002 */  mul.d     $f0, $f0, $f2
/* DBD3B0 80240100 00000000 */  nop
/* DBD3B4 80240104 46200020 */  cvt.s.d   $f0, $f0
/* DBD3B8 80240108 E6000018 */  swc1      $f0, 0x18($s0)
/* DBD3BC 8024010C 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBD3C0 80240110 8C43002C */  lw        $v1, 0x2c($v0)
/* DBD3C4 80240114 2402000A */  addiu     $v0, $zero, 0xa
/* DBD3C8 80240118 A602008E */  sh        $v0, 0x8e($s0)
/* DBD3CC 8024011C 24020010 */  addiu     $v0, $zero, 0x10
/* DBD3D0 80240120 AE030028 */  sw        $v1, 0x28($s0)
/* DBD3D4 80240124 AE420070 */  sw        $v0, 0x70($s2)
.L80240128:
/* DBD3D8 80240128 8FBF002C */  lw        $ra, 0x2c($sp)
/* DBD3DC 8024012C 8FB20028 */  lw        $s2, 0x28($sp)
/* DBD3E0 80240130 8FB10024 */  lw        $s1, 0x24($sp)
/* DBD3E4 80240134 8FB00020 */  lw        $s0, 0x20($sp)
/* DBD3E8 80240138 03E00008 */  jr        $ra
/* DBD3EC 8024013C 27BD0030 */   addiu    $sp, $sp, 0x30
