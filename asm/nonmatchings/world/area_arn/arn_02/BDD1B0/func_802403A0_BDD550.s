.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A0_BDD550
/* BDD550 802403A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDD554 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* BDD558 802403A8 0080882D */  daddu     $s1, $a0, $zero
/* BDD55C 802403AC AFBF0018 */  sw        $ra, 0x18($sp)
/* BDD560 802403B0 AFB00010 */  sw        $s0, 0x10($sp)
/* BDD564 802403B4 8E220148 */  lw        $v0, 0x148($s1)
/* BDD568 802403B8 0C00EABB */  jal       get_npc_unsafe
/* BDD56C 802403BC 84440008 */   lh       $a0, 8($v0)
/* BDD570 802403C0 0040802D */  daddu     $s0, $v0, $zero
/* BDD574 802403C4 9602008E */  lhu       $v0, 0x8e($s0)
/* BDD578 802403C8 2442FFFF */  addiu     $v0, $v0, -1
/* BDD57C 802403CC A602008E */  sh        $v0, 0x8e($s0)
/* BDD580 802403D0 00021400 */  sll       $v0, $v0, 0x10
/* BDD584 802403D4 1C40000F */  bgtz      $v0, .L80240414
/* BDD588 802403D8 00000000 */   nop
/* BDD58C 802403DC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BDD590 802403E0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BDD594 802403E4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDD598 802403E8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDD59C 802403EC 8C460028 */  lw        $a2, 0x28($v0)
/* BDD5A0 802403F0 0C00A720 */  jal       atan2
/* BDD5A4 802403F4 8C470030 */   lw       $a3, 0x30($v0)
/* BDD5A8 802403F8 2402001A */  addiu     $v0, $zero, 0x1a
/* BDD5AC 802403FC A60200A8 */  sh        $v0, 0xa8($s0)
/* BDD5B0 80240400 24020018 */  addiu     $v0, $zero, 0x18
/* BDD5B4 80240404 A60200A6 */  sh        $v0, 0xa6($s0)
/* BDD5B8 80240408 24020004 */  addiu     $v0, $zero, 4
/* BDD5BC 8024040C E600000C */  swc1      $f0, 0xc($s0)
/* BDD5C0 80240410 AE220070 */  sw        $v0, 0x70($s1)
.L80240414:
/* BDD5C4 80240414 8FBF0018 */  lw        $ra, 0x18($sp)
/* BDD5C8 80240418 8FB10014 */  lw        $s1, 0x14($sp)
/* BDD5CC 8024041C 8FB00010 */  lw        $s0, 0x10($sp)
/* BDD5D0 80240420 03E00008 */  jr        $ra
/* BDD5D4 80240424 27BD0020 */   addiu    $sp, $sp, 0x20
