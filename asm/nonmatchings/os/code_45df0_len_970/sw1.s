.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sw1
/* 462C4 8006AEC4 2401FEFF */  addiu     $at, $zero, -0x101
/* 462C8 8006AEC8 01014024 */  and       $t0, $t0, $at
/* 462CC 8006AECC 40886800 */  mtc0      $t0, $13
/* 462D0 8006AED0 24040000 */  addiu     $a0, $zero, 0
/* 462D4 8006AED4 0C01ABDF */  jal       send_mesg
/* 462D8 8006AED8 00000000 */   nop      
/* 462DC 8006AEDC 2401FEFF */  addiu     $at, $zero, -0x101
/* 462E0 8006AEE0 1000FF4A */  b         next_interrupt
/* 462E4 8006AEE4 02018024 */   and      $s0, $s0, $at
