.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218120_4D0310
/* 4D0310 80218120 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4D0314 80218124 AFB00010 */  sw        $s0, 0x10($sp)
/* 4D0318 80218128 0080802D */  daddu     $s0, $a0, $zero
/* 4D031C 8021812C 3C05F5DE */  lui       $a1, 0xf5de
/* 4D0320 80218130 34A501FB */  ori       $a1, $a1, 0x1fb
/* 4D0324 80218134 0000202D */  daddu     $a0, $zero, $zero
/* 4D0328 80218138 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4D032C 8021813C 0C0B1EAF */  jal       get_variable
/* 4D0330 80218140 AE000084 */   sw       $zero, 0x84($s0)
/* 4D0334 80218144 28420008 */  slti      $v0, $v0, 8
/* 4D0338 80218148 14400002 */  bnez      $v0, .L80218154
/* 4D033C 8021814C 24020001 */   addiu    $v0, $zero, 1
/* 4D0340 80218150 AE020084 */  sw        $v0, 0x84($s0)
.L80218154:
/* 4D0344 80218154 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4D0348 80218158 8FB00010 */  lw        $s0, 0x10($sp)
/* 4D034C 8021815C 24020002 */  addiu     $v0, $zero, 2
/* 4D0350 80218160 03E00008 */  jr        $ra
/* 4D0354 80218164 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4D0358 80218168 00000000 */  nop       
/* 4D035C 8021816C 00000000 */  nop       
