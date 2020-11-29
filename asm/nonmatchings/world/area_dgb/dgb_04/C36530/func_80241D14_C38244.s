.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D14_C38244
/* C38244 80241D14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C38248 80241D18 AFB00010 */  sw        $s0, 0x10($sp)
/* C3824C 80241D1C 0080802D */  daddu     $s0, $a0, $zero
/* C38250 80241D20 AFBF0014 */  sw        $ra, 0x14($sp)
/* C38254 80241D24 8E020148 */  lw        $v0, 0x148($s0)
/* C38258 80241D28 0C00EABB */  jal       get_npc_unsafe
/* C3825C 80241D2C 84440008 */   lh       $a0, 8($v0)
/* C38260 80241D30 0040202D */  daddu     $a0, $v0, $zero
/* C38264 80241D34 9482008E */  lhu       $v0, 0x8e($a0)
/* C38268 80241D38 24420001 */  addiu     $v0, $v0, 1
/* C3826C 80241D3C A482008E */  sh        $v0, 0x8e($a0)
/* C38270 80241D40 00021400 */  sll       $v0, $v0, 0x10
/* C38274 80241D44 00021403 */  sra       $v0, $v0, 0x10
/* C38278 80241D48 28420003 */  slti      $v0, $v0, 3
/* C3827C 80241D4C 1440000D */  bnez      $v0, .L80241D84
/* C38280 80241D50 24020009 */   addiu    $v0, $zero, 9
/* C38284 80241D54 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C38288 80241D58 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C3828C 80241D5C 10620003 */  beq       $v1, $v0, .L80241D6C
/* C38290 80241D60 24020064 */   addiu    $v0, $zero, 0x64
/* C38294 80241D64 08090760 */  j         .L80241D80
/* C38298 80241D68 A480008E */   sh       $zero, 0x8e($a0)
.L80241D6C:
/* C3829C 80241D6C 0C038069 */  jal       enable_player_input
/* C382A0 80241D70 00000000 */   nop      
/* C382A4 80241D74 0C03BD80 */  jal       func_800EF600
/* C382A8 80241D78 00000000 */   nop      
/* C382AC 80241D7C 24020010 */  addiu     $v0, $zero, 0x10
.L80241D80:
/* C382B0 80241D80 AE020070 */  sw        $v0, 0x70($s0)
.L80241D84:
/* C382B4 80241D84 8FBF0014 */  lw        $ra, 0x14($sp)
/* C382B8 80241D88 8FB00010 */  lw        $s0, 0x10($sp)
/* C382BC 80241D8C 03E00008 */  jr        $ra
/* C382C0 80241D90 27BD0018 */   addiu    $sp, $sp, 0x18
