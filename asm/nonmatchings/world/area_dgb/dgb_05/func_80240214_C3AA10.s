.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240214_C3AC24
/* C3AC24 80240214 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3AC28 80240218 AFB10014 */  sw        $s1, 0x14($sp)
/* C3AC2C 8024021C 0080882D */  daddu     $s1, $a0, $zero
/* C3AC30 80240220 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3AC34 80240224 AFB00010 */  sw        $s0, 0x10($sp)
/* C3AC38 80240228 8E300148 */  lw        $s0, 0x148($s1)
/* C3AC3C 8024022C 0C00EABB */  jal       get_npc_unsafe
/* C3AC40 80240230 86040008 */   lh       $a0, 8($s0)
/* C3AC44 80240234 9443008E */  lhu       $v1, 0x8e($v0)
/* C3AC48 80240238 2463FFFF */  addiu     $v1, $v1, -1
/* C3AC4C 8024023C A443008E */  sh        $v1, 0x8e($v0)
/* C3AC50 80240240 00031C00 */  sll       $v1, $v1, 0x10
/* C3AC54 80240244 1C600003 */  bgtz      $v1, .L80240254
/* C3AC58 80240248 2402000C */   addiu    $v0, $zero, 0xc
/* C3AC5C 8024024C AE00006C */  sw        $zero, 0x6c($s0)
/* C3AC60 80240250 AE220070 */  sw        $v0, 0x70($s1)
.L80240254:
/* C3AC64 80240254 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3AC68 80240258 8FB10014 */  lw        $s1, 0x14($sp)
/* C3AC6C 8024025C 8FB00010 */  lw        $s0, 0x10($sp)
/* C3AC70 80240260 03E00008 */  jr        $ra
/* C3AC74 80240264 27BD0020 */   addiu    $sp, $sp, 0x20
