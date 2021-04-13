.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055D6C
/* 3116C 80055D6C 3C07800A */  lui       $a3, %hi(D_8009A5A0)
/* 31170 80055D70 8CE7A5A0 */  lw        $a3, %lo(D_8009A5A0)($a3)
/* 31174 80055D74 8CE20098 */  lw        $v0, 0x98($a3)
/* 31178 80055D78 2C420010 */  sltiu     $v0, $v0, 0x10
/* 3117C 80055D7C 1040000D */  beqz      $v0, .L80055DB4
/* 31180 80055D80 0080182D */   daddu    $v1, $a0, $zero
/* 31184 80055D84 00031F00 */  sll       $v1, $v1, 0x1c
/* 31188 80055D88 30A2000F */  andi      $v0, $a1, 0xf
/* 3118C 80055D8C 00021600 */  sll       $v0, $v0, 0x18
/* 31190 80055D90 00621821 */  addu      $v1, $v1, $v0
/* 31194 80055D94 8CE40090 */  lw        $a0, 0x90($a3)
/* 31198 80055D98 00661821 */  addu      $v1, $v1, $a2
/* 3119C 80055D9C AC830000 */  sw        $v1, ($a0)
/* 311A0 80055DA0 8CE20098 */  lw        $v0, 0x98($a3)
/* 311A4 80055DA4 24840004 */  addiu     $a0, $a0, 4
/* 311A8 80055DA8 ACE40090 */  sw        $a0, 0x90($a3)
/* 311AC 80055DAC 24420001 */  addiu     $v0, $v0, 1
/* 311B0 80055DB0 ACE20098 */  sw        $v0, 0x98($a3)
.L80055DB4:
/* 311B4 80055DB4 03E00008 */  jr        $ra
/* 311B8 80055DB8 00000000 */   nop
