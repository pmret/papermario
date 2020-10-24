.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BC8_889798
/* 889798 80240BC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 88979C 80240BCC AFB00010 */  sw        $s0, 0x10($sp)
/* 8897A0 80240BD0 0080802D */  daddu     $s0, $a0, $zero
/* 8897A4 80240BD4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8897A8 80240BD8 8E02000C */  lw        $v0, 0xc($s0)
/* 8897AC 80240BDC 0C0B1EAF */  jal       get_variable
/* 8897B0 80240BE0 8C450000 */   lw       $a1, ($v0)
/* 8897B4 80240BE4 00021140 */  sll       $v0, $v0, 5
/* 8897B8 80240BE8 AE000084 */  sw        $zero, 0x84($s0)
/* 8897BC 80240BEC 3C018008 */  lui       $at, 0x8008
/* 8897C0 80240BF0 00220821 */  addu      $at, $at, $v0
/* 8897C4 80240BF4 942278F8 */  lhu       $v0, 0x78f8($at)
/* 8897C8 80240BF8 30420040 */  andi      $v0, $v0, 0x40
/* 8897CC 80240BFC 10400002 */  beqz      $v0, .L80240C08
/* 8897D0 80240C00 24020001 */   addiu    $v0, $zero, 1
/* 8897D4 80240C04 AE020084 */  sw        $v0, 0x84($s0)
.L80240C08:
/* 8897D8 80240C08 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8897DC 80240C0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8897E0 80240C10 24020002 */  addiu     $v0, $zero, 2
/* 8897E4 80240C14 03E00008 */  jr        $ra
/* 8897E8 80240C18 27BD0018 */   addiu    $sp, $sp, 0x18
