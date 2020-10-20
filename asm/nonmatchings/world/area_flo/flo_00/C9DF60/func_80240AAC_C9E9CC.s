.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_C9E9CC
/* C9E9CC 80240AAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9E9D0 80240AB0 AFB10014 */  sw        $s1, 0x14($sp)
/* C9E9D4 80240AB4 0080882D */  daddu     $s1, $a0, $zero
/* C9E9D8 80240AB8 AFBF0018 */  sw        $ra, 0x18($sp)
/* C9E9DC 80240ABC AFB00010 */  sw        $s0, 0x10($sp)
/* C9E9E0 80240AC0 8E300148 */  lw        $s0, 0x148($s1)
/* C9E9E4 80240AC4 0C00EABB */  jal       get_npc_unsafe
/* C9E9E8 80240AC8 86040008 */   lh       $a0, 8($s0)
/* C9E9EC 80240ACC 9443008E */  lhu       $v1, 0x8e($v0)
/* C9E9F0 80240AD0 2463FFFF */  addiu     $v1, $v1, -1
/* C9E9F4 80240AD4 A443008E */  sh        $v1, 0x8e($v0)
/* C9E9F8 80240AD8 00031C00 */  sll       $v1, $v1, 0x10
/* C9E9FC 80240ADC 14600008 */  bnez      $v1, .L80240B00
/* C9EA00 80240AE0 00000000 */   nop      
/* C9EA04 80240AE4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C9EA08 80240AE8 30420080 */  andi      $v0, $v0, 0x80
/* C9EA0C 80240AEC 10400003 */  beqz      $v0, .L80240AFC
/* C9EA10 80240AF0 2402000F */   addiu    $v0, $zero, 0xf
/* C9EA14 80240AF4 080902C0 */  j         .L80240B00
/* C9EA18 80240AF8 AE220070 */   sw       $v0, 0x70($s1)
.L80240AFC:
/* C9EA1C 80240AFC AE200070 */  sw        $zero, 0x70($s1)
.L80240B00:
/* C9EA20 80240B00 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9EA24 80240B04 8FB10014 */  lw        $s1, 0x14($sp)
/* C9EA28 80240B08 8FB00010 */  lw        $s0, 0x10($sp)
/* C9EA2C 80240B0C 03E00008 */  jr        $ra
/* C9EA30 80240B10 27BD0020 */   addiu    $sp, $sp, 0x20
