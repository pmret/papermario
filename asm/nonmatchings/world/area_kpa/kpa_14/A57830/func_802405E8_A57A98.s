.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405E8_A57A98
/* A57A98 802405E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A57A9C 802405EC AFB00010 */  sw        $s0, 0x10($sp)
/* A57AA0 802405F0 0080802D */  daddu     $s0, $a0, $zero
/* A57AA4 802405F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A57AA8 802405F8 8E02000C */  lw        $v0, 0xc($s0)
/* A57AAC 802405FC 0C0B1EAF */  jal       get_variable
/* A57AB0 80240600 8C450000 */   lw       $a1, ($v0)
/* A57AB4 80240604 00021140 */  sll       $v0, $v0, 5
/* A57AB8 80240608 AE000084 */  sw        $zero, 0x84($s0)
/* A57ABC 8024060C 3C018008 */  lui       $at, 0x8008
/* A57AC0 80240610 00220821 */  addu      $at, $at, $v0
/* A57AC4 80240614 942278F8 */  lhu       $v0, 0x78f8($at)
/* A57AC8 80240618 30420040 */  andi      $v0, $v0, 0x40
/* A57ACC 8024061C 10400002 */  beqz      $v0, .L80240628
/* A57AD0 80240620 24020001 */   addiu    $v0, $zero, 1
/* A57AD4 80240624 AE020084 */  sw        $v0, 0x84($s0)
.L80240628:
/* A57AD8 80240628 8FBF0014 */  lw        $ra, 0x14($sp)
/* A57ADC 8024062C 8FB00010 */  lw        $s0, 0x10($sp)
/* A57AE0 80240630 24020002 */  addiu     $v0, $zero, 2
/* A57AE4 80240634 03E00008 */  jr        $ra
/* A57AE8 80240638 27BD0018 */   addiu    $sp, $sp, 0x18
