
.section .text8005FF90, "ax"

func_8005FF90:
/* 03B390 8005FF90 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03B394 8005FF94 AFB00010 */  sw    $s0, 0x10($sp)
/* 03B398 8005FF98 0080802D */  move  $s0, $a0
/* 03B39C 8005FF9C AFB10014 */  sw    $s1, 0x14($sp)
/* 03B3A0 8005FFA0 00A0882D */  move  $s1, $a1
/* 03B3A4 8005FFA4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 03B3A8 8005FFA8 0C018250 */  jal   func_80060940
/* 03B3AC 8005FFAC 24040001 */   addiu $a0, $zero, 1
/* 03B3B0 8005FFB0 0220202D */  move  $a0, $s1
/* 03B3B4 8005FFB4 00101880 */  sll   $v1, $s0, 2
/* 03B3B8 8005FFB8 00701821 */  addu  $v1, $v1, $s0
/* 03B3BC 8005FFBC 00032840 */  sll   $a1, $v1, 1
/* 03B3C0 8005FFC0 3C03800B */  lui   $v1, 0x800b
/* 03B3C4 8005FFC4 00651821 */  addu  $v1, $v1, $a1
/* 03B3C8 8005FFC8 90631D47 */  lbu   $v1, 0x1d47($v1)
/* 03B3CC 8005FFCC 308400FF */  andi  $a0, $a0, 0xff
/* 03B3D0 8005FFD0 30660080 */  andi  $a2, $v1, 0x80
/* 03B3D4 8005FFD4 24030001 */  addiu $v1, $zero, 1
/* 03B3D8 8005FFD8 1083000C */  beq   $a0, $v1, .L8006000C
/* 03B3DC 8005FFDC 0040382D */   move  $a3, $v0
/* 03B3E0 8005FFE0 28820002 */  slti  $v0, $a0, 2
/* 03B3E4 8005FFE4 10400005 */  beqz  $v0, .L8005FFFC
/* 03B3E8 8005FFE8 24020002 */   addiu $v0, $zero, 2
/* 03B3EC 8005FFEC 1080000D */  beqz  $a0, .L80060024
