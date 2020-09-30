.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CDF8
/* 281F8 8004CDF8 30A500FF */  andi      $a1, $a1, 0xff
/* 281FC 8004CDFC 00041943 */  sra       $v1, $a0, 5
/* 28200 8004CE00 000410C3 */  sra       $v0, $a0, 3
/* 28204 8004CE04 00621821 */  addu      $v1, $v1, $v0
/* 28208 8004CE08 30630001 */  andi      $v1, $v1, 1
/* 2820C 8004CE0C 00041203 */  sra       $v0, $a0, 8
/* 28210 8004CE10 3042001F */  andi      $v0, $v0, 0x1f
/* 28214 8004CE14 000420C0 */  sll       $a0, $a0, 3
/* 28218 8004CE18 308400E0 */  andi      $a0, $a0, 0xe0
/* 2821C 8004CE1C 10600007 */  beqz      $v1, .L8004CE3C
/* 28220 8004CE20 00442021 */   addu     $a0, $v0, $a0
/* 28224 8004CE24 30C200FF */  andi      $v0, $a2, 0xff
/* 28228 8004CE28 00440018 */  mult      $v0, $a0
/* 2822C 8004CE2C 00003812 */  mflo      $a3
/* 28230 8004CE30 00071203 */  sra       $v0, $a3, 8
/* 28234 8004CE34 08013394 */  j         .L8004CE50
/* 28238 8004CE38 00A22821 */   addu     $a1, $a1, $v0
.L8004CE3C:
/* 2823C 8004CE3C 30C200FF */  andi      $v0, $a2, 0xff
/* 28240 8004CE40 00440018 */  mult      $v0, $a0
/* 28244 8004CE44 00003812 */  mflo      $a3
/* 28248 8004CE48 00071203 */  sra       $v0, $a3, 8
/* 2824C 8004CE4C 00A22823 */  subu      $a1, $a1, $v0
.L8004CE50:
/* 28250 8004CE50 04A10003 */  bgez      $a1, .L8004CE60
/* 28254 8004CE54 28A20080 */   slti     $v0, $a1, 0x80
/* 28258 8004CE58 0801339A */  j         .L8004CE68
/* 2825C 8004CE5C 0000282D */   daddu    $a1, $zero, $zero
.L8004CE60:
/* 28260 8004CE60 50400001 */  beql      $v0, $zero, .L8004CE68
/* 28264 8004CE64 2405007F */   addiu    $a1, $zero, 0x7f
.L8004CE68:
/* 28268 8004CE68 03E00008 */  jr        $ra
/* 2826C 8004CE6C 30A200FF */   andi     $v0, $a1, 0xff
