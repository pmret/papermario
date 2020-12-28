.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183E0_6DE1A0
/* 6DE1A0 802183E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE1A4 802183E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE1A8 802183E8 0080802D */  daddu     $s0, $a0, $zero
/* 6DE1AC 802183EC 3C05F5DE */  lui       $a1, 0xf5de
/* 6DE1B0 802183F0 34A501FB */  ori       $a1, $a1, 0x1fb
/* 6DE1B4 802183F4 0000202D */  daddu     $a0, $zero, $zero
/* 6DE1B8 802183F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6DE1BC 802183FC 0C0B1EAF */  jal       get_variable
/* 6DE1C0 80218400 AE000084 */   sw       $zero, 0x84($s0)
/* 6DE1C4 80218404 28420008 */  slti      $v0, $v0, 8
/* 6DE1C8 80218408 14400002 */  bnez      $v0, .L80218414
/* 6DE1CC 8021840C 24020001 */   addiu    $v0, $zero, 1
/* 6DE1D0 80218410 AE020084 */  sw        $v0, 0x84($s0)
.L80218414:
/* 6DE1D4 80218414 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DE1D8 80218418 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE1DC 8021841C 24020002 */  addiu     $v0, $zero, 2
/* 6DE1E0 80218420 03E00008 */  jr        $ra
/* 6DE1E4 80218424 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6DE1E8 80218428 00000000 */  nop       
/* 6DE1EC 8021842C 00000000 */  nop       
