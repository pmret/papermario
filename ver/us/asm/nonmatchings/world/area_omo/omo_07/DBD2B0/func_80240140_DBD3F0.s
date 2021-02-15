.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_DBD3F0
/* DBD3F0 80240140 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DBD3F4 80240144 AFB10024 */  sw        $s1, 0x24($sp)
/* DBD3F8 80240148 0080882D */  daddu     $s1, $a0, $zero
/* DBD3FC 8024014C AFBF0028 */  sw        $ra, 0x28($sp)
/* DBD400 80240150 AFB00020 */  sw        $s0, 0x20($sp)
/* DBD404 80240154 8E220148 */  lw        $v0, 0x148($s1)
/* DBD408 80240158 0C00EABB */  jal       get_npc_unsafe
/* DBD40C 8024015C 84440008 */   lh       $a0, 8($v0)
/* DBD410 80240160 0040802D */  daddu     $s0, $v0, $zero
/* DBD414 80240164 0200202D */  daddu     $a0, $s0, $zero
/* DBD418 80240168 C600000C */  lwc1      $f0, 0xc($s0)
/* DBD41C 8024016C 27A60018 */  addiu     $a2, $sp, 0x18
/* DBD420 80240170 E7A00018 */  swc1      $f0, 0x18($sp)
/* DBD424 80240174 AFA00010 */  sw        $zero, 0x10($sp)
/* DBD428 80240178 AFA00014 */  sw        $zero, 0x14($sp)
/* DBD42C 8024017C 8E050018 */  lw        $a1, 0x18($s0)
/* DBD430 80240180 0C0129E1 */  jal       func_8004A784
/* DBD434 80240184 0000382D */   daddu    $a3, $zero, $zero
/* DBD438 80240188 14400005 */  bnez      $v0, .L802401A0
/* DBD43C 8024018C 00000000 */   nop
/* DBD440 80240190 8E050018 */  lw        $a1, 0x18($s0)
/* DBD444 80240194 8E06000C */  lw        $a2, 0xc($s0)
/* DBD448 80240198 0C00EA95 */  jal       npc_move_heading
/* DBD44C 8024019C 0200202D */   daddu    $a0, $s0, $zero
.L802401A0:
/* DBD450 802401A0 9602008E */  lhu       $v0, 0x8e($s0)
/* DBD454 802401A4 2442FFFF */  addiu     $v0, $v0, -1
/* DBD458 802401A8 A602008E */  sh        $v0, 0x8e($s0)
/* DBD45C 802401AC 00021400 */  sll       $v0, $v0, 0x10
/* DBD460 802401B0 14400004 */  bnez      $v0, .L802401C4
/* DBD464 802401B4 2402001E */   addiu    $v0, $zero, 0x1e
/* DBD468 802401B8 A602008E */  sh        $v0, 0x8e($s0)
/* DBD46C 802401BC 24020011 */  addiu     $v0, $zero, 0x11
/* DBD470 802401C0 AE220070 */  sw        $v0, 0x70($s1)
.L802401C4:
/* DBD474 802401C4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DBD478 802401C8 8FB10024 */  lw        $s1, 0x24($sp)
/* DBD47C 802401CC 8FB00020 */  lw        $s0, 0x20($sp)
/* DBD480 802401D0 03E00008 */  jr        $ra
/* DBD484 802401D4 27BD0030 */   addiu    $sp, $sp, 0x30
