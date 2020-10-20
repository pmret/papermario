.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240224_BA0954
/* BA0954 80240224 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA0958 80240228 AFB10014 */  sw        $s1, 0x14($sp)
/* BA095C 8024022C 0080882D */  daddu     $s1, $a0, $zero
/* BA0960 80240230 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA0964 80240234 AFB00010 */  sw        $s0, 0x10($sp)
/* BA0968 80240238 8E300148 */  lw        $s0, 0x148($s1)
/* BA096C 8024023C 0C00EABB */  jal       get_npc_unsafe
/* BA0970 80240240 86040008 */   lh       $a0, 8($s0)
/* BA0974 80240244 9443008E */  lhu       $v1, 0x8e($v0)
/* BA0978 80240248 2463FFFF */  addiu     $v1, $v1, -1
/* BA097C 8024024C A443008E */  sh        $v1, 0x8e($v0)
/* BA0980 80240250 00031C00 */  sll       $v1, $v1, 0x10
/* BA0984 80240254 1C600003 */  bgtz      $v1, .L80240264
/* BA0988 80240258 2402000C */   addiu    $v0, $zero, 0xc
/* BA098C 8024025C AE00006C */  sw        $zero, 0x6c($s0)
/* BA0990 80240260 AE220070 */  sw        $v0, 0x70($s1)
.L80240264:
/* BA0994 80240264 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA0998 80240268 8FB10014 */  lw        $s1, 0x14($sp)
/* BA099C 8024026C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA09A0 80240270 03E00008 */  jr        $ra
/* BA09A4 80240274 27BD0020 */   addiu    $sp, $sp, 0x20
