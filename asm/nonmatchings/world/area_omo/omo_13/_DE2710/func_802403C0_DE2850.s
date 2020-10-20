.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C0_DE2850
/* DE2850 802403C0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DE2854 802403C4 AFB10024 */  sw        $s1, 0x24($sp)
/* DE2858 802403C8 0080882D */  daddu     $s1, $a0, $zero
/* DE285C 802403CC AFBF0028 */  sw        $ra, 0x28($sp)
/* DE2860 802403D0 AFB00020 */  sw        $s0, 0x20($sp)
/* DE2864 802403D4 8E220148 */  lw        $v0, 0x148($s1)
/* DE2868 802403D8 0C00EABB */  jal       get_npc_unsafe
/* DE286C 802403DC 84440008 */   lh       $a0, 8($v0)
/* DE2870 802403E0 0040802D */  daddu     $s0, $v0, $zero
/* DE2874 802403E4 0200202D */  daddu     $a0, $s0, $zero
/* DE2878 802403E8 C600000C */  lwc1      $f0, 0xc($s0)
/* DE287C 802403EC 27A60018 */  addiu     $a2, $sp, 0x18
/* DE2880 802403F0 E7A00018 */  swc1      $f0, 0x18($sp)
/* DE2884 802403F4 AFA00010 */  sw        $zero, 0x10($sp)
/* DE2888 802403F8 AFA00014 */  sw        $zero, 0x14($sp)
/* DE288C 802403FC 8E050018 */  lw        $a1, 0x18($s0)
/* DE2890 80240400 0C0129E1 */  jal       func_8004A784
/* DE2894 80240404 0000382D */   daddu    $a3, $zero, $zero
/* DE2898 80240408 14400005 */  bnez      $v0, .L80240420
/* DE289C 8024040C 00000000 */   nop      
/* DE28A0 80240410 8E050018 */  lw        $a1, 0x18($s0)
/* DE28A4 80240414 8E06000C */  lw        $a2, 0xc($s0)
/* DE28A8 80240418 0C00EA95 */  jal       npc_move_heading
/* DE28AC 8024041C 0200202D */   daddu    $a0, $s0, $zero
.L80240420:
/* DE28B0 80240420 9602008E */  lhu       $v0, 0x8e($s0)
/* DE28B4 80240424 2442FFFF */  addiu     $v0, $v0, -1
/* DE28B8 80240428 A602008E */  sh        $v0, 0x8e($s0)
/* DE28BC 8024042C 00021400 */  sll       $v0, $v0, 0x10
/* DE28C0 80240430 14400004 */  bnez      $v0, .L80240444
/* DE28C4 80240434 2402001E */   addiu    $v0, $zero, 0x1e
/* DE28C8 80240438 A602008E */  sh        $v0, 0x8e($s0)
/* DE28CC 8024043C 24020011 */  addiu     $v0, $zero, 0x11
/* DE28D0 80240440 AE220070 */  sw        $v0, 0x70($s1)
.L80240444:
/* DE28D4 80240444 8FBF0028 */  lw        $ra, 0x28($sp)
/* DE28D8 80240448 8FB10024 */  lw        $s1, 0x24($sp)
/* DE28DC 8024044C 8FB00020 */  lw        $s0, 0x20($sp)
/* DE28E0 80240450 03E00008 */  jr        $ra
/* DE28E4 80240454 27BD0030 */   addiu    $sp, $sp, 0x30
