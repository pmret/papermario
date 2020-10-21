.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240268_8D8738
/* 8D8738 80240268 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D873C 8024026C AFB00010 */  sw        $s0, 0x10($sp)
/* 8D8740 80240270 0080802D */  daddu     $s0, $a0, $zero
/* 8D8744 80240274 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D8748 80240278 8E02000C */  lw        $v0, 0xc($s0)
/* 8D874C 8024027C 0C0B1EAF */  jal       get_variable
/* 8D8750 80240280 8C450000 */   lw       $a1, ($v0)
/* 8D8754 80240284 00021140 */  sll       $v0, $v0, 5
/* 8D8758 80240288 AE000084 */  sw        $zero, 0x84($s0)
/* 8D875C 8024028C 3C018008 */  lui       $at, 0x8008
/* 8D8760 80240290 00220821 */  addu      $at, $at, $v0
/* 8D8764 80240294 942278F8 */  lhu       $v0, 0x78f8($at)
/* 8D8768 80240298 30420040 */  andi      $v0, $v0, 0x40
/* 8D876C 8024029C 10400002 */  beqz      $v0, .L802402A8
/* 8D8770 802402A0 24020001 */   addiu    $v0, $zero, 1
/* 8D8774 802402A4 AE020084 */  sw        $v0, 0x84($s0)
.L802402A8:
/* 8D8778 802402A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D877C 802402AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D8780 802402B0 24020002 */  addiu     $v0, $zero, 2
/* 8D8784 802402B4 03E00008 */  jr        $ra
/* 8D8788 802402B8 27BD0018 */   addiu    $sp, $sp, 0x18
