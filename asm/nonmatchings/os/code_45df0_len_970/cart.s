.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel cart
/* 46080 8006AC80 2401F7FF */  addiu     $at, $zero, -0x801
/* 46084 8006AC84 02018024 */  and       $s0, $s0, $at
/* 46088 8006AC88 3C098009 */  lui       $t1, 0x8009
/* 4608C 8006AC8C 25295910 */  addiu     $t1, $t1, 0x5910
/* 46090 8006AC90 21290008 */  addi      $t1, $t1, 8
/* 46094 8006AC94 8D2A0000 */  lw        $t2, ($t1)
/* 46098 8006AC98 11400007 */  beqz      $t2, .L8006ACB8
/* 4609C 8006AC9C 00000000 */   nop      
/* 460A0 8006ACA0 0140F809 */  jalr      $t2
/* 460A4 8006ACA4 8D3D0004 */   lw       $sp, 4($t1)
/* 460A8 8006ACA8 10400003 */  beqz      $v0, .L8006ACB8
/* 460AC 8006ACAC 00000000 */   nop      
/* 460B0 8006ACB0 10000093 */  b         redispatch
/* 460B4 8006ACB4 00000000 */   nop      
.L8006ACB8:
/* 460B8 8006ACB8 0C01ABDF */  jal       send_mesg
/* 460BC 8006ACBC 24040010 */   addiu    $a0, $zero, 0x10
/* 460C0 8006ACC0 1000FFD2 */  b         next_interrupt
/* 460C4 8006ACC4 00000000 */   nop      
