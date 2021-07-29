.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AB1C
/* 5F1C 8002AB1C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5F20 8002AB20 0080402D */  daddu     $t0, $a0, $zero
/* 5F24 8002AB24 00A0482D */  daddu     $t1, $a1, $zero
/* 5F28 8002AB28 00C0502D */  daddu     $t2, $a2, $zero
/* 5F2C 8002AB2C 00E0582D */  daddu     $t3, $a3, $zero
/* 5F30 8002AB30 00061C00 */  sll       $v1, $a2, 0x10
/* 5F34 8002AB34 00041400 */  sll       $v0, $a0, 0x10
/* 5F38 8002AB38 97AC003A */  lhu       $t4, 0x3a($sp)
/* 5F3C 8002AB3C 97AD003E */  lhu       $t5, 0x3e($sp)
/* 5F40 8002AB40 97AE0042 */  lhu       $t6, 0x42($sp)
/* 5F44 8002AB44 97AF0046 */  lhu       $t7, 0x46($sp)
/* 5F48 8002AB48 0062182A */  slt       $v1, $v1, $v0
/* 5F4C 8002AB4C 10600003 */  beqz      $v1, .L8002AB5C
/* 5F50 8002AB50 AFBF0020 */   sw       $ra, 0x20($sp)
/* 5F54 8002AB54 0080502D */  daddu     $t2, $a0, $zero
/* 5F58 8002AB58 00C0402D */  daddu     $t0, $a2, $zero
.L8002AB5C:
/* 5F5C 8002AB5C 00071400 */  sll       $v0, $a3, 0x10
/* 5F60 8002AB60 00051C00 */  sll       $v1, $a1, 0x10
/* 5F64 8002AB64 0043102A */  slt       $v0, $v0, $v1
/* 5F68 8002AB68 10400003 */  beqz      $v0, .L8002AB78
/* 5F6C 8002AB6C 3102FFFF */   andi     $v0, $t0, 0xffff
/* 5F70 8002AB70 00A0582D */  daddu     $t3, $a1, $zero
/* 5F74 8002AB74 00E0482D */  daddu     $t1, $a3, $zero
.L8002AB78:
/* 5F78 8002AB78 AFA20010 */  sw        $v0, 0x10($sp)
/* 5F7C 8002AB7C 3122FFFF */  andi      $v0, $t1, 0xffff
/* 5F80 8002AB80 AFA20014 */  sw        $v0, 0x14($sp)
/* 5F84 8002AB84 3142FFFF */  andi      $v0, $t2, 0xffff
/* 5F88 8002AB88 AFA20018 */  sw        $v0, 0x18($sp)
/* 5F8C 8002AB8C 3162FFFF */  andi      $v0, $t3, 0xffff
/* 5F90 8002AB90 318400FF */  andi      $a0, $t4, 0xff
/* 5F94 8002AB94 31A500FF */  andi      $a1, $t5, 0xff
/* 5F98 8002AB98 31C600FF */  andi      $a2, $t6, 0xff
/* 5F9C 8002AB9C 31E700FF */  andi      $a3, $t7, 0xff
/* 5FA0 8002ABA0 0C00AA31 */  jal       func_8002A8C4
/* 5FA4 8002ABA4 AFA2001C */   sw       $v0, 0x1c($sp)
/* 5FA8 8002ABA8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5FAC 8002ABAC 03E00008 */  jr        $ra
/* 5FB0 8002ABB0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5FB4 8002ABB4 00000000 */  nop
/* 5FB8 8002ABB8 00000000 */  nop
/* 5FBC 8002ABBC 00000000 */  nop
