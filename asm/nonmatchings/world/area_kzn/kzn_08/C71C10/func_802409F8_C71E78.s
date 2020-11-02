.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409F8_C71E78
/* C71E78 802409F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C71E7C 802409FC AFB00010 */  sw        $s0, 0x10($sp)
/* C71E80 80240A00 0080802D */  daddu     $s0, $a0, $zero
/* C71E84 80240A04 AFBF0014 */  sw        $ra, 0x14($sp)
/* C71E88 80240A08 8E02000C */  lw        $v0, 0xc($s0)
/* C71E8C 80240A0C 0C0B1EAF */  jal       get_variable
/* C71E90 80240A10 8C450000 */   lw       $a1, ($v0)
/* C71E94 80240A14 00021140 */  sll       $v0, $v0, 5
/* C71E98 80240A18 AE000084 */  sw        $zero, 0x84($s0)
/* C71E9C 80240A1C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* C71EA0 80240A20 00220821 */  addu      $at, $at, $v0
/* C71EA4 80240A24 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* C71EA8 80240A28 30420040 */  andi      $v0, $v0, 0x40
/* C71EAC 80240A2C 10400002 */  beqz      $v0, .L80240A38
/* C71EB0 80240A30 24020001 */   addiu    $v0, $zero, 1
/* C71EB4 80240A34 AE020084 */  sw        $v0, 0x84($s0)
.L80240A38:
/* C71EB8 80240A38 8FBF0014 */  lw        $ra, 0x14($sp)
/* C71EBC 80240A3C 8FB00010 */  lw        $s0, 0x10($sp)
/* C71EC0 80240A40 24020002 */  addiu     $v0, $zero, 2
/* C71EC4 80240A44 03E00008 */  jr        $ra
/* C71EC8 80240A48 27BD0018 */   addiu    $sp, $sp, 0x18
/* C71ECC 80240A4C 00000000 */  nop       
