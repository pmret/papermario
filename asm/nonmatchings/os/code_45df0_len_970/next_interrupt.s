.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel next_interrupt
/* 4600C 8006AC0C 3209FF00 */  andi      $t1, $s0, 0xff00
/* 46010 8006AC10 00095302 */  srl       $t2, $t1, 0xc
/* 46014 8006AC14 15400003 */  bnez      $t2, .L8006AC24
/* 46018 8006AC18 00000000 */   nop      
/* 4601C 8006AC1C 00095202 */  srl       $t2, $t1, 8
/* 46020 8006AC20 214A0010 */  addi      $t2, $t2, 0x10
.L8006AC24:
/* 46024 8006AC24 3C01800A */  lui       $at, 0x800a
/* 46028 8006AC28 002A0821 */  addu      $at, $at, $t2
/* 4602C 8006AC2C 902A9D80 */  lbu       $t2, -0x6280($at)
/* 46030 8006AC30 3C01800A */  lui       $at, 0x800a
/* 46034 8006AC34 002A0821 */  addu      $at, $at, $t2
/* 46038 8006AC38 8C2A9DA0 */  lw        $t2, -0x6260($at)
/* 4603C 8006AC3C 01400008 */  jr        $t2
/* 46040 8006AC40 00000000 */   nop      
