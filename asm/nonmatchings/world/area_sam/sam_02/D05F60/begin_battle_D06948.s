.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel begin_battle_D06948
/* D06948 80241218 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D0694C 8024121C AFB00010 */  sw        $s0, 0x10($sp)
/* D06950 80241220 3C108011 */  lui       $s0, %hi(gPlayerData)
/* D06954 80241224 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* D06958 80241228 AFBF0018 */  sw        $ra, 0x18($sp)
/* D0695C 8024122C AFB10014 */  sw        $s1, 0x14($sp)
/* D06960 80241230 960302C0 */  lhu       $v1, 0x2c0($s0)
/* D06964 80241234 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* D06968 80241238 10400003 */  beqz      $v0, .L80241248
/* D0696C 8024123C 0080882D */   daddu    $s1, $a0, $zero
/* D06970 80241240 24620001 */  addiu     $v0, $v1, 1
/* D06974 80241244 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80241248:
/* D06978 80241248 3C05F5DE */  lui       $a1, 0xf5de
/* D0697C 8024124C 34A502E0 */  ori       $a1, $a1, 0x2e0
/* D06980 80241250 0C0B1EAF */  jal       get_variable
/* D06984 80241254 0000202D */   daddu    $a0, $zero, $zero
/* D06988 80241258 3C038024 */  lui       $v1, 0x8024
/* D0698C 8024125C 00621821 */  addu      $v1, $v1, $v0
/* D06990 80241260 90636BC4 */  lbu       $v1, 0x6bc4($v1)
/* D06994 80241264 8E220084 */  lw        $v0, 0x84($s1)
/* D06998 80241268 54430006 */  bnel      $v0, $v1, .L80241284
/* D0699C 8024126C AE200084 */   sw       $zero, 0x84($s1)
/* D069A0 80241270 24020001 */  addiu     $v0, $zero, 1
/* D069A4 80241274 AE220084 */  sw        $v0, 0x84($s1)
/* D069A8 80241278 960202C2 */  lhu       $v0, 0x2c2($s0)
/* D069AC 8024127C 24420001 */  addiu     $v0, $v0, 1
/* D069B0 80241280 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80241284:
/* D069B4 80241284 8FBF0018 */  lw        $ra, 0x18($sp)
/* D069B8 80241288 8FB10014 */  lw        $s1, 0x14($sp)
/* D069BC 8024128C 8FB00010 */  lw        $s0, 0x10($sp)
/* D069C0 80241290 24020002 */  addiu     $v0, $zero, 2
/* D069C4 80241294 03E00008 */  jr        $ra
/* D069C8 80241298 27BD0020 */   addiu    $sp, $sp, 0x20
