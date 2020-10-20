.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240268_C3D2E8
/* C3D2E8 80240268 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C3D2EC 8024026C AFB00010 */  sw        $s0, 0x10($sp)
/* C3D2F0 80240270 0080802D */  daddu     $s0, $a0, $zero
/* C3D2F4 80240274 AFBF0014 */  sw        $ra, 0x14($sp)
/* C3D2F8 80240278 8E02000C */  lw        $v0, 0xc($s0)
/* C3D2FC 8024027C 0C0B1EAF */  jal       get_variable
/* C3D300 80240280 8C450000 */   lw       $a1, ($v0)
/* C3D304 80240284 00021140 */  sll       $v0, $v0, 5
/* C3D308 80240288 AE000084 */  sw        $zero, 0x84($s0)
/* C3D30C 8024028C 3C018008 */  lui       $at, 0x8008
/* C3D310 80240290 00220821 */  addu      $at, $at, $v0
/* C3D314 80240294 942278F8 */  lhu       $v0, 0x78f8($at)
/* C3D318 80240298 30420040 */  andi      $v0, $v0, 0x40
/* C3D31C 8024029C 10400002 */  beqz      $v0, .L802402A8
/* C3D320 802402A0 24020001 */   addiu    $v0, $zero, 1
/* C3D324 802402A4 AE020084 */  sw        $v0, 0x84($s0)
.L802402A8:
/* C3D328 802402A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* C3D32C 802402AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C3D330 802402B0 24020002 */  addiu     $v0, $zero, 2
/* C3D334 802402B4 03E00008 */  jr        $ra
/* C3D338 802402B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* C3D33C 802402BC 00000000 */  nop       
