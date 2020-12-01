.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243138_C49D18
/* C49D18 80243138 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C49D1C 8024313C AFB00010 */  sw        $s0, 0x10($sp)
/* C49D20 80243140 0080802D */  daddu     $s0, $a0, $zero
/* C49D24 80243144 AFBF0014 */  sw        $ra, 0x14($sp)
/* C49D28 80243148 8E020148 */  lw        $v0, 0x148($s0)
/* C49D2C 8024314C 0C00EABB */  jal       get_npc_unsafe
/* C49D30 80243150 84440008 */   lh       $a0, 8($v0)
/* C49D34 80243154 0040202D */  daddu     $a0, $v0, $zero
/* C49D38 80243158 9482008E */  lhu       $v0, 0x8e($a0)
/* C49D3C 8024315C 24420001 */  addiu     $v0, $v0, 1
/* C49D40 80243160 A482008E */  sh        $v0, 0x8e($a0)
/* C49D44 80243164 00021400 */  sll       $v0, $v0, 0x10
/* C49D48 80243168 00021403 */  sra       $v0, $v0, 0x10
/* C49D4C 8024316C 28420003 */  slti      $v0, $v0, 3
/* C49D50 80243170 1440000D */  bnez      $v0, .L802431A8
/* C49D54 80243174 24020009 */   addiu    $v0, $zero, 9
/* C49D58 80243178 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C49D5C 8024317C 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C49D60 80243180 10620003 */  beq       $v1, $v0, .L80243190
/* C49D64 80243184 24020064 */   addiu    $v0, $zero, 0x64
/* C49D68 80243188 08090C69 */  j         .L802431A4
/* C49D6C 8024318C A480008E */   sh       $zero, 0x8e($a0)
.L80243190:
/* C49D70 80243190 0C038069 */  jal       enable_player_input
/* C49D74 80243194 00000000 */   nop      
/* C49D78 80243198 0C03BD80 */  jal       func_800EF600
/* C49D7C 8024319C 00000000 */   nop      
/* C49D80 802431A0 24020010 */  addiu     $v0, $zero, 0x10
.L802431A4:
/* C49D84 802431A4 AE020070 */  sw        $v0, 0x70($s0)
.L802431A8:
/* C49D88 802431A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* C49D8C 802431AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C49D90 802431B0 03E00008 */  jr        $ra
/* C49D94 802431B4 27BD0018 */   addiu    $sp, $sp, 0x18
