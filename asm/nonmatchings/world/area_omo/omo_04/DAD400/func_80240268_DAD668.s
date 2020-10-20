.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240268_DAD668
/* DAD668 80240268 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DAD66C 8024026C AFB00010 */  sw        $s0, 0x10($sp)
/* DAD670 80240270 0080802D */  daddu     $s0, $a0, $zero
/* DAD674 80240274 AFBF0014 */  sw        $ra, 0x14($sp)
/* DAD678 80240278 8E02000C */  lw        $v0, 0xc($s0)
/* DAD67C 8024027C 0C0B1EAF */  jal       get_variable
/* DAD680 80240280 8C450000 */   lw       $a1, ($v0)
/* DAD684 80240284 00021140 */  sll       $v0, $v0, 5
/* DAD688 80240288 AE000084 */  sw        $zero, 0x84($s0)
/* DAD68C 8024028C 3C018008 */  lui       $at, 0x8008
/* DAD690 80240290 00220821 */  addu      $at, $at, $v0
/* DAD694 80240294 942278F8 */  lhu       $v0, 0x78f8($at)
/* DAD698 80240298 30420040 */  andi      $v0, $v0, 0x40
/* DAD69C 8024029C 10400002 */  beqz      $v0, .L802402A8
/* DAD6A0 802402A0 24020001 */   addiu    $v0, $zero, 1
/* DAD6A4 802402A4 AE020084 */  sw        $v0, 0x84($s0)
.L802402A8:
/* DAD6A8 802402A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DAD6AC 802402AC 8FB00010 */  lw        $s0, 0x10($sp)
/* DAD6B0 802402B0 24020002 */  addiu     $v0, $zero, 2
/* DAD6B4 802402B4 03E00008 */  jr        $ra
/* DAD6B8 802402B8 27BD0018 */   addiu    $sp, $sp, 0x18
