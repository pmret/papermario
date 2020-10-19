.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240204_D112C4
/* D112C4 80240204 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D112C8 80240208 AFB10014 */  sw        $s1, 0x14($sp)
/* D112CC 8024020C 0080882D */  daddu     $s1, $a0, $zero
/* D112D0 80240210 AFBF0018 */  sw        $ra, 0x18($sp)
/* D112D4 80240214 AFB00010 */  sw        $s0, 0x10($sp)
/* D112D8 80240218 8E300148 */  lw        $s0, 0x148($s1)
/* D112DC 8024021C 0C00EABB */  jal       get_npc_unsafe
/* D112E0 80240220 86040008 */   lh       $a0, 8($s0)
/* D112E4 80240224 9443008E */  lhu       $v1, 0x8e($v0)
/* D112E8 80240228 2463FFFF */  addiu     $v1, $v1, -1
/* D112EC 8024022C A443008E */  sh        $v1, 0x8e($v0)
/* D112F0 80240230 00031C00 */  sll       $v1, $v1, 0x10
/* D112F4 80240234 1C600003 */  bgtz      $v1, .L80240244
/* D112F8 80240238 2402000C */   addiu    $v0, $zero, 0xc
/* D112FC 8024023C AE00006C */  sw        $zero, 0x6c($s0)
/* D11300 80240240 AE220070 */  sw        $v0, 0x70($s1)
.L80240244:
/* D11304 80240244 8FBF0018 */  lw        $ra, 0x18($sp)
/* D11308 80240248 8FB10014 */  lw        $s1, 0x14($sp)
/* D1130C 8024024C 8FB00010 */  lw        $s0, 0x10($sp)
/* D11310 80240250 03E00008 */  jr        $ra
/* D11314 80240254 27BD0020 */   addiu    $sp, $sp, 0x20
