.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181C0_4D03B0
/* 4D03B0 802181C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4D03B4 802181C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 4D03B8 802181C8 0080802D */  daddu     $s0, $a0, $zero
/* 4D03BC 802181CC 3C05F5DE */  lui       $a1, 0xf5de
/* 4D03C0 802181D0 34A501FB */  ori       $a1, $a1, 0x1fb
/* 4D03C4 802181D4 0000202D */  daddu     $a0, $zero, $zero
/* 4D03C8 802181D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4D03CC 802181DC 0C0B1EAF */  jal       get_variable
/* 4D03D0 802181E0 AE000084 */   sw       $zero, 0x84($s0)
/* 4D03D4 802181E4 28420008 */  slti      $v0, $v0, 8
/* 4D03D8 802181E8 14400002 */  bnez      $v0, .L802181F4
/* 4D03DC 802181EC 24020001 */   addiu    $v0, $zero, 1
/* 4D03E0 802181F0 AE020084 */  sw        $v0, 0x84($s0)
.L802181F4:
/* 4D03E4 802181F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4D03E8 802181F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4D03EC 802181FC 24020002 */  addiu     $v0, $zero, 2
/* 4D03F0 80218200 03E00008 */  jr        $ra
/* 4D03F4 80218204 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4D03F8 80218208 00000000 */  nop       
/* 4D03FC 8021820C 00000000 */  nop       
