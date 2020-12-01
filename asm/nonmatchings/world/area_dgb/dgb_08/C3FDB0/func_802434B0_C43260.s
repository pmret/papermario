.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802434B0_C43260
/* C43260 802434B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C43264 802434B4 AFB00010 */  sw        $s0, 0x10($sp)
/* C43268 802434B8 0080802D */  daddu     $s0, $a0, $zero
/* C4326C 802434BC AFBF0014 */  sw        $ra, 0x14($sp)
/* C43270 802434C0 8E020148 */  lw        $v0, 0x148($s0)
/* C43274 802434C4 0C00EABB */  jal       get_npc_unsafe
/* C43278 802434C8 84440008 */   lh       $a0, 8($v0)
/* C4327C 802434CC 0040202D */  daddu     $a0, $v0, $zero
/* C43280 802434D0 9482008E */  lhu       $v0, 0x8e($a0)
/* C43284 802434D4 24420001 */  addiu     $v0, $v0, 1
/* C43288 802434D8 A482008E */  sh        $v0, 0x8e($a0)
/* C4328C 802434DC 00021400 */  sll       $v0, $v0, 0x10
/* C43290 802434E0 00021403 */  sra       $v0, $v0, 0x10
/* C43294 802434E4 28420003 */  slti      $v0, $v0, 3
/* C43298 802434E8 1440000D */  bnez      $v0, .L80243520
/* C4329C 802434EC 24020009 */   addiu    $v0, $zero, 9
/* C432A0 802434F0 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C432A4 802434F4 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C432A8 802434F8 10620003 */  beq       $v1, $v0, .L80243508
/* C432AC 802434FC 24020064 */   addiu    $v0, $zero, 0x64
/* C432B0 80243500 08090D47 */  j         .L8024351C
/* C432B4 80243504 A480008E */   sh       $zero, 0x8e($a0)
.L80243508:
/* C432B8 80243508 0C038069 */  jal       enable_player_input
/* C432BC 8024350C 00000000 */   nop      
/* C432C0 80243510 0C03BD80 */  jal       func_800EF600
/* C432C4 80243514 00000000 */   nop      
/* C432C8 80243518 24020010 */  addiu     $v0, $zero, 0x10
.L8024351C:
/* C432CC 8024351C AE020070 */  sw        $v0, 0x70($s0)
.L80243520:
/* C432D0 80243520 8FBF0014 */  lw        $ra, 0x14($sp)
/* C432D4 80243524 8FB00010 */  lw        $s0, 0x10($sp)
/* C432D8 80243528 03E00008 */  jr        $ra
/* C432DC 8024352C 27BD0018 */   addiu    $sp, $sp, 0x18
