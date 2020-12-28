.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218170_4D0360
/* 4D0360 80218170 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4D0364 80218174 AFB00010 */  sw        $s0, 0x10($sp)
/* 4D0368 80218178 0080802D */  daddu     $s0, $a0, $zero
/* 4D036C 8021817C 3C05F5DE */  lui       $a1, 0xf5de
/* 4D0370 80218180 34A501FB */  ori       $a1, $a1, 0x1fb
/* 4D0374 80218184 0000202D */  daddu     $a0, $zero, $zero
/* 4D0378 80218188 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4D037C 8021818C 0C0B1EAF */  jal       get_variable
/* 4D0380 80218190 AE000084 */   sw       $zero, 0x84($s0)
/* 4D0384 80218194 28420008 */  slti      $v0, $v0, 8
/* 4D0388 80218198 14400002 */  bnez      $v0, .L802181A4
/* 4D038C 8021819C 24020001 */   addiu    $v0, $zero, 1
/* 4D0390 802181A0 AE020084 */  sw        $v0, 0x84($s0)
.L802181A4:
/* 4D0394 802181A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4D0398 802181A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4D039C 802181AC 24020002 */  addiu     $v0, $zero, 2
/* 4D03A0 802181B0 03E00008 */  jr        $ra
/* 4D03A4 802181B4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4D03A8 802181B8 00000000 */  nop       
/* 4D03AC 802181BC 00000000 */  nop       
