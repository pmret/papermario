.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053538
/* 2E938 80053538 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2E93C 8005353C AFBF0010 */  sw        $ra, 0x10($sp)
/* 2E940 80053540 90820045 */  lbu       $v0, 0x45($a0)
/* 2E944 80053544 10400008 */  beqz      $v0, .L80053568
/* 2E948 80053548 24020001 */   addiu    $v0, $zero, 1
/* 2E94C 8005354C AC80001C */  sw        $zero, 0x1c($a0)
/* 2E950 80053550 A0820042 */  sb        $v0, 0x42($a0)
/* 2E954 80053554 A0800043 */  sb        $zero, 0x43($a0)
/* 2E958 80053558 30A400FF */  andi      $a0, $a1, 0xff
/* 2E95C 8005355C 0000282D */  daddu     $a1, $zero, $zero
/* 2E960 80053560 0C015CE7 */  jal       func_8005739C
/* 2E964 80053564 240600B8 */   addiu    $a2, $zero, 0xb8
.L80053568:
/* 2E968 80053568 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2E96C 8005356C 03E00008 */  jr        $ra
/* 2E970 80053570 27BD0018 */   addiu    $sp, $sp, 0x18
