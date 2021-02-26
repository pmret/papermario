.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AA84
/* 5E84 8002AA84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5E88 8002AA88 0080402D */  daddu     $t0, $a0, $zero
/* 5E8C 8002AA8C 00A0482D */  daddu     $t1, $a1, $zero
/* 5E90 8002AA90 00C0502D */  daddu     $t2, $a2, $zero
/* 5E94 8002AA94 00E0582D */  daddu     $t3, $a3, $zero
/* 5E98 8002AA98 00061C00 */  sll       $v1, $a2, 0x10
/* 5E9C 8002AA9C 00041400 */  sll       $v0, $a0, 0x10
/* 5EA0 8002AAA0 97AC003A */  lhu       $t4, 0x3a($sp)
/* 5EA4 8002AAA4 97AD003E */  lhu       $t5, 0x3e($sp)
/* 5EA8 8002AAA8 97AE0042 */  lhu       $t6, 0x42($sp)
/* 5EAC 8002AAAC 97AF0046 */  lhu       $t7, 0x46($sp)
/* 5EB0 8002AAB0 0062182A */  slt       $v1, $v1, $v0
/* 5EB4 8002AAB4 10600003 */  beqz      $v1, .L8002AAC4
/* 5EB8 8002AAB8 AFBF0020 */   sw       $ra, 0x20($sp)
/* 5EBC 8002AABC 0080502D */  daddu     $t2, $a0, $zero
/* 5EC0 8002AAC0 00C0402D */  daddu     $t0, $a2, $zero
.L8002AAC4:
/* 5EC4 8002AAC4 00071400 */  sll       $v0, $a3, 0x10
/* 5EC8 8002AAC8 00051C00 */  sll       $v1, $a1, 0x10
/* 5ECC 8002AACC 0043102A */  slt       $v0, $v0, $v1
/* 5ED0 8002AAD0 10400003 */  beqz      $v0, .L8002AAE0
/* 5ED4 8002AAD4 3102FFFF */   andi     $v0, $t0, 0xffff
/* 5ED8 8002AAD8 00A0582D */  daddu     $t3, $a1, $zero
/* 5EDC 8002AADC 00E0482D */  daddu     $t1, $a3, $zero
.L8002AAE0:
/* 5EE0 8002AAE0 AFA20010 */  sw        $v0, 0x10($sp)
/* 5EE4 8002AAE4 3122FFFF */  andi      $v0, $t1, 0xffff
/* 5EE8 8002AAE8 AFA20014 */  sw        $v0, 0x14($sp)
/* 5EEC 8002AAEC 3142FFFF */  andi      $v0, $t2, 0xffff
/* 5EF0 8002AAF0 AFA20018 */  sw        $v0, 0x18($sp)
/* 5EF4 8002AAF4 3162FFFF */  andi      $v0, $t3, 0xffff
/* 5EF8 8002AAF8 318400FF */  andi      $a0, $t4, 0xff
/* 5EFC 8002AAFC 31A500FF */  andi      $a1, $t5, 0xff
/* 5F00 8002AB00 31C600FF */  andi      $a2, $t6, 0xff
/* 5F04 8002AB04 31E700FF */  andi      $a3, $t7, 0xff
/* 5F08 8002AB08 0C00AA31 */  jal       func_8002A8C4
/* 5F0C 8002AB0C AFA2001C */   sw       $v0, 0x1c($sp)
/* 5F10 8002AB10 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5F14 8002AB14 03E00008 */  jr        $ra
/* 5F18 8002AB18 27BD0028 */   addiu    $sp, $sp, 0x28
