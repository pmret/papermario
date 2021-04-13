.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003DFA0
/* 193A0 8003DFA0 0080182D */  daddu     $v1, $a0, $zero
/* 193A4 8003DFA4 00A0102D */  daddu     $v0, $a1, $zero
/* 193A8 8003DFA8 04410002 */  bgez      $v0, .L8003DFB4
/* 193AC 8003DFAC 0040202D */   daddu    $a0, $v0, $zero
/* 193B0 8003DFB0 2444001F */  addiu     $a0, $v0, 0x1f
.L8003DFB4:
/* 193B4 8003DFB4 00042143 */  sra       $a0, $a0, 5
/* 193B8 8003DFB8 00042940 */  sll       $a1, $a0, 5
/* 193BC 8003DFBC 00452823 */  subu      $a1, $v0, $a1
/* 193C0 8003DFC0 00042080 */  sll       $a0, $a0, 2
/* 193C4 8003DFC4 00031040 */  sll       $v0, $v1, 1
/* 193C8 8003DFC8 00431021 */  addu      $v0, $v0, $v1
/* 193CC 8003DFCC 00021100 */  sll       $v0, $v0, 4
/* 193D0 8003DFD0 00822021 */  addu      $a0, $a0, $v0
/* 193D4 8003DFD4 3C02800B */  lui       $v0, %hi(D_800B0EF0)
/* 193D8 8003DFD8 24420EF0 */  addiu     $v0, $v0, %lo(D_800B0EF0)
/* 193DC 8003DFDC 00822021 */  addu      $a0, $a0, $v0
/* 193E0 8003DFE0 24030001 */  addiu     $v1, $zero, 1
/* 193E4 8003DFE4 8C8200B0 */  lw        $v0, 0xb0($a0)
/* 193E8 8003DFE8 00A31804 */  sllv      $v1, $v1, $a1
/* 193EC 8003DFEC 00431025 */  or        $v0, $v0, $v1
/* 193F0 8003DFF0 03E00008 */  jr        $ra
/* 193F4 8003DFF4 AC8200B0 */   sw       $v0, 0xb0($a0)
