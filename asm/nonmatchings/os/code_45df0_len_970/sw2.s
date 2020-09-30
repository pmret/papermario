.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sw2
/* 462A0 8006AEA0 2401FDFF */  addiu     $at, $zero, -0x201
/* 462A4 8006AEA4 01014024 */  and       $t0, $t0, $at
/* 462A8 8006AEA8 40886800 */  mtc0      $t0, $13
/* 462AC 8006AEAC 24040008 */  addiu     $a0, $zero, 8
/* 462B0 8006AEB0 0C01ABDF */  jal       send_mesg
/* 462B4 8006AEB4 00000000 */   nop      
/* 462B8 8006AEB8 2401FDFF */  addiu     $at, $zero, -0x201
/* 462BC 8006AEBC 1000FF53 */  b         next_interrupt
/* 462C0 8006AEC0 02018024 */   and      $s0, $s0, $at
