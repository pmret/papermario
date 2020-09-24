.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pi
/* 461B8 8006ADB8 32290010 */  andi      $t1, $s1, 0x10
/* 461BC 8006ADBC 11200013 */  beqz      $t1, dp
/* 461C0 8006ADC0 00000000 */   nop      
/* 461C4 8006ADC4 3231002F */  andi      $s1, $s1, 0x2f
/* 461C8 8006ADC8 24090002 */  addiu     $t1, $zero, 2
/* 461CC 8006ADCC 3C01A460 */  lui       $at, 0xa460
/* 461D0 8006ADD0 AC290010 */  sw        $t1, 0x10($at)
/* 461D4 8006ADD4 3C098009 */  lui       $t1, 0x8009
/* 461D8 8006ADD8 25295938 */  addiu     $t1, $t1, 0x5938
/* 461DC 8006ADDC 8D2A0000 */  lw        $t2, ($t1)
/* 461E0 8006ADE0 11400006 */  beqz      $t2, .L8006ADFC
/* 461E4 8006ADE4 00000000 */   nop      
/* 461E8 8006ADE8 8D3D0004 */  lw        $sp, 4($t1)
/* 461EC 8006ADEC 0140F809 */  jalr      $t2
/* 461F0 8006ADF0 00402021 */   addu     $a0, $v0, $zero
/* 461F4 8006ADF4 14400003 */  bnez      $v0, .L8006AE04
/* 461F8 8006ADF8 00000000 */   nop      
.L8006ADFC:
/* 461FC 8006ADFC 0C01ABDF */  jal       send_mesg
/* 46200 8006AE00 24040040 */   addiu    $a0, $zero, 0x40
.L8006AE04:
/* 46204 8006AE04 1220000A */  beqz      $s1, NoMoreRcpInts
/* 46208 8006AE08 00000000 */   nop      
