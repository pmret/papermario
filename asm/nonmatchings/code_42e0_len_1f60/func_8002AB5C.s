.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AB5C
/* 5F5C 8002AB5C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5F60 8002AB60 0080402D */  daddu     $t0, $a0, $zero
/* 5F64 8002AB64 00A0482D */  daddu     $t1, $a1, $zero
/* 5F68 8002AB68 00C0502D */  daddu     $t2, $a2, $zero
/* 5F6C 8002AB6C 00E0582D */  daddu     $t3, $a3, $zero
/* 5F70 8002AB70 00061C00 */  sll       $v1, $a2, 0x10
/* 5F74 8002AB74 00041400 */  sll       $v0, $a0, 0x10
/* 5F78 8002AB78 97AC003A */  lhu       $t4, 0x3a($sp)
/* 5F7C 8002AB7C 97AD003E */  lhu       $t5, 0x3e($sp)
/* 5F80 8002AB80 97AE0042 */  lhu       $t6, 0x42($sp)
/* 5F84 8002AB84 97AF0046 */  lhu       $t7, 0x46($sp)
/* 5F88 8002AB88 0062182A */  slt       $v1, $v1, $v0
/* 5F8C 8002AB8C 10600003 */  beqz      $v1, .L8002AB9C
/* 5F90 8002AB90 AFBF0020 */   sw       $ra, 0x20($sp)
/* 5F94 8002AB94 0080502D */  daddu     $t2, $a0, $zero
/* 5F98 8002AB98 00C0402D */  daddu     $t0, $a2, $zero
.L8002AB9C:
/* 5F9C 8002AB9C 00071400 */  sll       $v0, $a3, 0x10
/* 5FA0 8002ABA0 00051C00 */  sll       $v1, $a1, 0x10
/* 5FA4 8002ABA4 0043102A */  slt       $v0, $v0, $v1
/* 5FA8 8002ABA8 10400003 */  beqz      $v0, .L8002ABB8
/* 5FAC 8002ABAC 3102FFFF */   andi     $v0, $t0, 0xffff
/* 5FB0 8002ABB0 00A0582D */  daddu     $t3, $a1, $zero
/* 5FB4 8002ABB4 00E0482D */  daddu     $t1, $a3, $zero
.L8002ABB8:
/* 5FB8 8002ABB8 AFA20010 */  sw        $v0, 0x10($sp)
/* 5FBC 8002ABBC 3122FFFF */  andi      $v0, $t1, 0xffff
/* 5FC0 8002ABC0 AFA20014 */  sw        $v0, 0x14($sp)
/* 5FC4 8002ABC4 3142FFFF */  andi      $v0, $t2, 0xffff
/* 5FC8 8002ABC8 AFA20018 */  sw        $v0, 0x18($sp)
/* 5FCC 8002ABCC 3162FFFF */  andi      $v0, $t3, 0xffff
/* 5FD0 8002ABD0 318400FF */  andi      $a0, $t4, 0xff
/* 5FD4 8002ABD4 31A500FF */  andi      $a1, $t5, 0xff
/* 5FD8 8002ABD8 31C600FF */  andi      $a2, $t6, 0xff
/* 5FDC 8002ABDC 31E700FF */  andi      $a3, $t7, 0xff
/* 5FE0 8002ABE0 0C00AA41 */  jal       func_8002A904
/* 5FE4 8002ABE4 AFA2001C */   sw       $v0, 0x1c($sp)
/* 5FE8 8002ABE8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5FEC 8002ABEC 03E00008 */  jr        $ra
/* 5FF0 8002ABF0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5FF4 8002ABF4 00000000 */  nop       
/* 5FF8 8002ABF8 00000000 */  nop       
/* 5FFC 8002ABFC 00000000 */  nop       
