.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C8AC
/* 47CAC 8006C8AC 00001821 */  addu      $v1, $zero, $zero
/* 47CB0 8006C8B0 24060020 */  addiu     $a2, $zero, 0x20
.L8006C8B4:
/* 47CB4 8006C8B4 24050080 */  addiu     $a1, $zero, 0x80
/* 47CB8 8006C8B8 90870000 */  lbu       $a3, ($a0)
/* 47CBC 8006C8BC 00E51024 */  and       $v0, $a3, $a1
.L8006C8C0:
/* 47CC0 8006C8C0 10400006 */  beqz      $v0, .L8006C8DC
/* 47CC4 8006C8C4 00031840 */   sll      $v1, $v1, 1
/* 47CC8 8006C8C8 30620100 */  andi      $v0, $v1, 0x100
/* 47CCC 8006C8CC 50400006 */  beql      $v0, $zero, .L8006C8E8
/* 47CD0 8006C8D0 24630001 */   addiu    $v1, $v1, 1
/* 47CD4 8006C8D4 0801B23A */  j         .L8006C8E8
/* 47CD8 8006C8D8 38630084 */   xori     $v1, $v1, 0x84
.L8006C8DC:
/* 47CDC 8006C8DC 30620100 */  andi      $v0, $v1, 0x100
/* 47CE0 8006C8E0 54400001 */  bnel      $v0, $zero, .L8006C8E8
/* 47CE4 8006C8E4 38630085 */   xori     $v1, $v1, 0x85
.L8006C8E8:
/* 47CE8 8006C8E8 00052842 */  srl       $a1, $a1, 1
/* 47CEC 8006C8EC 14A0FFF4 */  bnez      $a1, .L8006C8C0
/* 47CF0 8006C8F0 00E51024 */   and      $v0, $a3, $a1
/* 47CF4 8006C8F4 24C6FFFF */  addiu     $a2, $a2, -1
/* 47CF8 8006C8F8 14C0FFEE */  bnez      $a2, .L8006C8B4
/* 47CFC 8006C8FC 24840001 */   addiu    $a0, $a0, 1
/* 47D00 8006C900 00031840 */  sll       $v1, $v1, 1
.L8006C904:
/* 47D04 8006C904 30620100 */  andi      $v0, $v1, 0x100
/* 47D08 8006C908 54400001 */  bnel      $v0, $zero, .L8006C910
/* 47D0C 8006C90C 38630085 */   xori     $v1, $v1, 0x85
.L8006C910:
/* 47D10 8006C910 24C60001 */  addiu     $a2, $a2, 1
/* 47D14 8006C914 2CC20008 */  sltiu     $v0, $a2, 8
/* 47D18 8006C918 5440FFFA */  bnel      $v0, $zero, .L8006C904
/* 47D1C 8006C91C 00031840 */   sll      $v1, $v1, 1
/* 47D20 8006C920 03E00008 */  jr        $ra
/* 47D24 8006C924 306200FF */   andi     $v0, $v1, 0xff
/* 47D28 8006C928 00000000 */  nop
/* 47D2C 8006C92C 00000000 */  nop
