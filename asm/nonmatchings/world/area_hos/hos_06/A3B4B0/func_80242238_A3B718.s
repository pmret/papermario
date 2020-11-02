.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242238_A3B718
/* A3B718 80242238 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3B71C 8024223C AFB00010 */  sw        $s0, 0x10($sp)
/* A3B720 80242240 0080802D */  daddu     $s0, $a0, $zero
/* A3B724 80242244 AFBF0014 */  sw        $ra, 0x14($sp)
/* A3B728 80242248 8E02000C */  lw        $v0, 0xc($s0)
/* A3B72C 8024224C 0C0B1EAF */  jal       get_variable
/* A3B730 80242250 8C450000 */   lw       $a1, ($v0)
/* A3B734 80242254 00021140 */  sll       $v0, $v0, 5
/* A3B738 80242258 AE000084 */  sw        $zero, 0x84($s0)
/* A3B73C 8024225C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* A3B740 80242260 00220821 */  addu      $at, $at, $v0
/* A3B744 80242264 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* A3B748 80242268 30420040 */  andi      $v0, $v0, 0x40
/* A3B74C 8024226C 10400002 */  beqz      $v0, .L80242278
/* A3B750 80242270 24020001 */   addiu    $v0, $zero, 1
/* A3B754 80242274 AE020084 */  sw        $v0, 0x84($s0)
.L80242278:
/* A3B758 80242278 8FBF0014 */  lw        $ra, 0x14($sp)
/* A3B75C 8024227C 8FB00010 */  lw        $s0, 0x10($sp)
/* A3B760 80242280 24020002 */  addiu     $v0, $zero, 2
/* A3B764 80242284 03E00008 */  jr        $ra
/* A3B768 80242288 27BD0018 */   addiu    $sp, $sp, 0x18
