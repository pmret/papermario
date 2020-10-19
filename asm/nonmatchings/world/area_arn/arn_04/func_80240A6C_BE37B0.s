.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_BE421C
/* BE421C 80240A6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE4220 80240A70 AFB10014 */  sw        $s1, 0x14($sp)
/* BE4224 80240A74 0080882D */  daddu     $s1, $a0, $zero
/* BE4228 80240A78 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE422C 80240A7C AFB00010 */  sw        $s0, 0x10($sp)
/* BE4230 80240A80 8E300148 */  lw        $s0, 0x148($s1)
/* BE4234 80240A84 0C00EABB */  jal       get_npc_unsafe
/* BE4238 80240A88 86040008 */   lh       $a0, 8($s0)
/* BE423C 80240A8C 9443008E */  lhu       $v1, 0x8e($v0)
/* BE4240 80240A90 2463FFFF */  addiu     $v1, $v1, -1
/* BE4244 80240A94 A443008E */  sh        $v1, 0x8e($v0)
/* BE4248 80240A98 00031C00 */  sll       $v1, $v1, 0x10
/* BE424C 80240A9C 14600008 */  bnez      $v1, .L80240AC0
/* BE4250 80240AA0 00000000 */   nop      
/* BE4254 80240AA4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BE4258 80240AA8 30420080 */  andi      $v0, $v0, 0x80
/* BE425C 80240AAC 10400003 */  beqz      $v0, .L80240ABC
/* BE4260 80240AB0 2402000F */   addiu    $v0, $zero, 0xf
/* BE4264 80240AB4 080902B0 */  j         .L80240AC0
/* BE4268 80240AB8 AE220070 */   sw       $v0, 0x70($s1)
.L80240ABC:
/* BE426C 80240ABC AE200070 */  sw        $zero, 0x70($s1)
.L80240AC0:
/* BE4270 80240AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE4274 80240AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* BE4278 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* BE427C 80240ACC 03E00008 */  jr        $ra
/* BE4280 80240AD0 27BD0020 */   addiu    $sp, $sp, 0x20
