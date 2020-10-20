.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241104_D94044
/* D94044 80241104 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D94048 80241108 AFB10014 */  sw        $s1, 0x14($sp)
/* D9404C 8024110C 0080882D */  daddu     $s1, $a0, $zero
/* D94050 80241110 AFBF0018 */  sw        $ra, 0x18($sp)
/* D94054 80241114 AFB00010 */  sw        $s0, 0x10($sp)
/* D94058 80241118 8E300148 */  lw        $s0, 0x148($s1)
/* D9405C 8024111C 0C00EABB */  jal       get_npc_unsafe
/* D94060 80241120 86040008 */   lh       $a0, 8($s0)
/* D94064 80241124 9443008E */  lhu       $v1, 0x8e($v0)
/* D94068 80241128 2463FFFF */  addiu     $v1, $v1, -1
/* D9406C 8024112C A443008E */  sh        $v1, 0x8e($v0)
/* D94070 80241130 00031C00 */  sll       $v1, $v1, 0x10
/* D94074 80241134 1C600003 */  bgtz      $v1, .L80241144
/* D94078 80241138 2402000C */   addiu    $v0, $zero, 0xc
/* D9407C 8024113C AE00006C */  sw        $zero, 0x6c($s0)
/* D94080 80241140 AE220070 */  sw        $v0, 0x70($s1)
.L80241144:
/* D94084 80241144 8FBF0018 */  lw        $ra, 0x18($sp)
/* D94088 80241148 8FB10014 */  lw        $s1, 0x14($sp)
/* D9408C 8024114C 8FB00010 */  lw        $s0, 0x10($sp)
/* D94090 80241150 03E00008 */  jr        $ra
/* D94094 80241154 27BD0020 */   addiu    $sp, $sp, 0x20
