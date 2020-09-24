.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_actor
/* 19864C 80269D6C 0000282D */  daddu     $a1, $zero, $zero
/* 198650 80269D70 3C06800E */  lui       $a2, 0x800e
/* 198654 80269D74 24C6C070 */  addiu     $a2, $a2, -0x3f90
/* 198658 80269D78 30830700 */  andi      $v1, $a0, 0x700
/* 19865C 80269D7C 24020100 */  addiu     $v0, $zero, 0x100
/* 198660 80269D80 1062000F */  beq       $v1, $v0, .L80269DC0
/* 198664 80269D84 308400FF */   andi     $a0, $a0, 0xff
/* 198668 80269D88 28620101 */  slti      $v0, $v1, 0x101
/* 19866C 80269D8C 10400005 */  beqz      $v0, .L80269DA4
/* 198670 80269D90 24020200 */   addiu    $v0, $zero, 0x200
/* 198674 80269D94 10600007 */  beqz      $v1, .L80269DB4
/* 198678 80269D98 00A0102D */   daddu    $v0, $a1, $zero
/* 19867C 80269D9C 0809A777 */  j         .L80269DDC
/* 198680 80269DA0 00000000 */   nop      
.L80269DA4:
/* 198684 80269DA4 10620009 */  beq       $v1, $v0, .L80269DCC
/* 198688 80269DA8 00A0102D */   daddu    $v0, $a1, $zero
/* 19868C 80269DAC 0809A777 */  j         .L80269DDC
/* 198690 80269DB0 00000000 */   nop      
.L80269DB4:
/* 198694 80269DB4 8CC500D8 */  lw        $a1, 0xd8($a2)
/* 198698 80269DB8 03E00008 */  jr        $ra
/* 19869C 80269DBC 00A0102D */   daddu    $v0, $a1, $zero
.L80269DC0:
/* 1986A0 80269DC0 8CC500DC */  lw        $a1, 0xdc($a2)
/* 1986A4 80269DC4 03E00008 */  jr        $ra
/* 1986A8 80269DC8 00A0102D */   daddu    $v0, $a1, $zero
.L80269DCC:
/* 1986AC 80269DCC 00041080 */  sll       $v0, $a0, 2
/* 1986B0 80269DD0 00461021 */  addu      $v0, $v0, $a2
/* 1986B4 80269DD4 8C4500E0 */  lw        $a1, 0xe0($v0)
/* 1986B8 80269DD8 00A0102D */  daddu     $v0, $a1, $zero
.L80269DDC:
/* 1986BC 80269DDC 03E00008 */  jr        $ra
/* 1986C0 80269DE0 00000000 */   nop      
