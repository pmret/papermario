.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CAA8
/* 27EA8 8004CAA8 30A500FF */  andi      $a1, $a1, 0xff
/* 27EAC 8004CAAC 00041943 */  sra       $v1, $a0, 5
/* 27EB0 8004CAB0 000410C3 */  sra       $v0, $a0, 3
/* 27EB4 8004CAB4 00621821 */  addu      $v1, $v1, $v0
/* 27EB8 8004CAB8 30630001 */  andi      $v1, $v1, 1
/* 27EBC 8004CABC 00041203 */  sra       $v0, $a0, 8
/* 27EC0 8004CAC0 3042001F */  andi      $v0, $v0, 0x1f
/* 27EC4 8004CAC4 000420C0 */  sll       $a0, $a0, 3
/* 27EC8 8004CAC8 308400E0 */  andi      $a0, $a0, 0xe0
/* 27ECC 8004CACC 10600007 */  beqz      $v1, .L8004CAEC
/* 27ED0 8004CAD0 00442021 */   addu     $a0, $v0, $a0
/* 27ED4 8004CAD4 30C200FF */  andi      $v0, $a2, 0xff
/* 27ED8 8004CAD8 00440018 */  mult      $v0, $a0
/* 27EDC 8004CADC 00003812 */  mflo      $a3
/* 27EE0 8004CAE0 00071203 */  sra       $v0, $a3, 8
/* 27EE4 8004CAE4 080132C0 */  j         .L8004CB00
/* 27EE8 8004CAE8 00A22821 */   addu     $a1, $a1, $v0
.L8004CAEC:
/* 27EEC 8004CAEC 30C200FF */  andi      $v0, $a2, 0xff
/* 27EF0 8004CAF0 00440018 */  mult      $v0, $a0
/* 27EF4 8004CAF4 00003812 */  mflo      $a3
/* 27EF8 8004CAF8 00071203 */  sra       $v0, $a3, 8
/* 27EFC 8004CAFC 00A22823 */  subu      $a1, $a1, $v0
.L8004CB00:
/* 27F00 8004CB00 04A10003 */  bgez      $a1, .L8004CB10
/* 27F04 8004CB04 28A20080 */   slti     $v0, $a1, 0x80
/* 27F08 8004CB08 080132C6 */  j         .L8004CB18
/* 27F0C 8004CB0C 0000282D */   daddu    $a1, $zero, $zero
.L8004CB10:
/* 27F10 8004CB10 50400001 */  beql      $v0, $zero, .L8004CB18
/* 27F14 8004CB14 2405007F */   addiu    $a1, $zero, 0x7f
.L8004CB18:
/* 27F18 8004CB18 03E00008 */  jr        $ra
/* 27F1C 8004CB1C 30A200FF */   andi     $v0, $a1, 0xff
