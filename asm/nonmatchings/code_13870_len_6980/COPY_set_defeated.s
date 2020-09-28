.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel COPY_set_defeated
/* 196E0 8003E2E0 0080182D */  daddu     $v1, $a0, $zero
/* 196E4 8003E2E4 00A0102D */  daddu     $v0, $a1, $zero
/* 196E8 8003E2E8 04410002 */  bgez      $v0, .L8003E2F4
/* 196EC 8003E2EC 0040202D */   daddu    $a0, $v0, $zero
/* 196F0 8003E2F0 2444001F */  addiu     $a0, $v0, 0x1f
.L8003E2F4:
/* 196F4 8003E2F4 00042143 */  sra       $a0, $a0, 5
/* 196F8 8003E2F8 00042940 */  sll       $a1, $a0, 5
/* 196FC 8003E2FC 00452823 */  subu      $a1, $v0, $a1
/* 19700 8003E300 00042080 */  sll       $a0, $a0, 2
/* 19704 8003E304 00031040 */  sll       $v0, $v1, 1
/* 19708 8003E308 00431021 */  addu      $v0, $v0, $v1
/* 1970C 8003E30C 00021100 */  sll       $v0, $v0, 4
/* 19710 8003E310 00822021 */  addu      $a0, $a0, $v0
/* 19714 8003E314 3C02800B */  lui       $v0, %hi(gCurrentEncounter)
/* 19718 8003E318 24420F10 */  addiu     $v0, $v0, %lo(gCurrentEncounter)
/* 1971C 8003E31C 00822021 */  addu      $a0, $a0, $v0
/* 19720 8003E320 24030001 */  addiu     $v1, $zero, 1
/* 19724 8003E324 8C8200B0 */  lw        $v0, 0xb0($a0)
/* 19728 8003E328 00A31804 */  sllv      $v1, $v1, $a1
/* 1972C 8003E32C 00431025 */  or        $v0, $v0, $v1
/* 19730 8003E330 03E00008 */  jr        $ra
/* 19734 8003E334 AC8200B0 */   sw       $v0, 0xb0($a0)
