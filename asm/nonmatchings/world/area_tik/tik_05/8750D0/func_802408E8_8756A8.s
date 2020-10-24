.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408E8_8756A8
/* 8756A8 802408E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8756AC 802408EC AFB00010 */  sw        $s0, 0x10($sp)
/* 8756B0 802408F0 0080802D */  daddu     $s0, $a0, $zero
/* 8756B4 802408F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8756B8 802408F8 8E02000C */  lw        $v0, 0xc($s0)
/* 8756BC 802408FC 0C0B1EAF */  jal       get_variable
/* 8756C0 80240900 8C450000 */   lw       $a1, ($v0)
/* 8756C4 80240904 00021140 */  sll       $v0, $v0, 5
/* 8756C8 80240908 AE000084 */  sw        $zero, 0x84($s0)
/* 8756CC 8024090C 3C018008 */  lui       $at, 0x8008
/* 8756D0 80240910 00220821 */  addu      $at, $at, $v0
/* 8756D4 80240914 942278F8 */  lhu       $v0, 0x78f8($at)
/* 8756D8 80240918 30420040 */  andi      $v0, $v0, 0x40
/* 8756DC 8024091C 10400002 */  beqz      $v0, .L80240928
/* 8756E0 80240920 24020001 */   addiu    $v0, $zero, 1
/* 8756E4 80240924 AE020084 */  sw        $v0, 0x84($s0)
.L80240928:
/* 8756E8 80240928 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8756EC 8024092C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8756F0 80240930 24020002 */  addiu     $v0, $zero, 2
/* 8756F4 80240934 03E00008 */  jr        $ra
/* 8756F8 80240938 27BD0018 */   addiu    $sp, $sp, 0x18
