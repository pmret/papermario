.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240268_AF1EC8
/* AF1EC8 80240268 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF1ECC 8024026C AFB00010 */  sw        $s0, 0x10($sp)
/* AF1ED0 80240270 0080802D */  daddu     $s0, $a0, $zero
/* AF1ED4 80240274 AFBF0014 */  sw        $ra, 0x14($sp)
/* AF1ED8 80240278 8E02000C */  lw        $v0, 0xc($s0)
/* AF1EDC 8024027C 0C0B1EAF */  jal       get_variable
/* AF1EE0 80240280 8C450000 */   lw       $a1, ($v0)
/* AF1EE4 80240284 00021140 */  sll       $v0, $v0, 5
/* AF1EE8 80240288 AE000084 */  sw        $zero, 0x84($s0)
/* AF1EEC 8024028C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* AF1EF0 80240290 00220821 */  addu      $at, $at, $v0
/* AF1EF4 80240294 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* AF1EF8 80240298 30420040 */  andi      $v0, $v0, 0x40
/* AF1EFC 8024029C 10400002 */  beqz      $v0, .L802402A8
/* AF1F00 802402A0 24020001 */   addiu    $v0, $zero, 1
/* AF1F04 802402A4 AE020084 */  sw        $v0, 0x84($s0)
.L802402A8:
/* AF1F08 802402A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* AF1F0C 802402AC 8FB00010 */  lw        $s0, 0x10($sp)
/* AF1F10 802402B0 24020002 */  addiu     $v0, $zero, 2
/* AF1F14 802402B4 03E00008 */  jr        $ra
/* AF1F18 802402B8 27BD0018 */   addiu    $sp, $sp, 0x18
