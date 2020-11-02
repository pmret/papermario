.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240988_DCD658
/* DCD658 80240988 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DCD65C 8024098C AFB00010 */  sw        $s0, 0x10($sp)
/* DCD660 80240990 0080802D */  daddu     $s0, $a0, $zero
/* DCD664 80240994 AFBF0014 */  sw        $ra, 0x14($sp)
/* DCD668 80240998 8E02000C */  lw        $v0, 0xc($s0)
/* DCD66C 8024099C 0C0B1EAF */  jal       get_variable
/* DCD670 802409A0 8C450000 */   lw       $a1, ($v0)
/* DCD674 802409A4 00021140 */  sll       $v0, $v0, 5
/* DCD678 802409A8 AE000084 */  sw        $zero, 0x84($s0)
/* DCD67C 802409AC 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* DCD680 802409B0 00220821 */  addu      $at, $at, $v0
/* DCD684 802409B4 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* DCD688 802409B8 30420040 */  andi      $v0, $v0, 0x40
/* DCD68C 802409BC 10400002 */  beqz      $v0, .L802409C8
/* DCD690 802409C0 24020001 */   addiu    $v0, $zero, 1
/* DCD694 802409C4 AE020084 */  sw        $v0, 0x84($s0)
.L802409C8:
/* DCD698 802409C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DCD69C 802409CC 8FB00010 */  lw        $s0, 0x10($sp)
/* DCD6A0 802409D0 24020002 */  addiu     $v0, $zero, 2
/* DCD6A4 802409D4 03E00008 */  jr        $ra
/* DCD6A8 802409D8 27BD0018 */   addiu    $sp, $sp, 0x18
/* DCD6AC 802409DC 00000000 */  nop       
