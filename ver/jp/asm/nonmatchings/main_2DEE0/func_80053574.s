.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053574
/* 2E974 80053574 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2E978 80053578 24020001 */  addiu     $v0, $zero, 1
/* 2E97C 8005357C AFBF0010 */  sw        $ra, 0x10($sp)
/* 2E980 80053580 AC80001C */  sw        $zero, 0x1c($a0)
/* 2E984 80053584 A0820042 */  sb        $v0, 0x42($a0)
/* 2E988 80053588 A0800043 */  sb        $zero, 0x43($a0)
/* 2E98C 8005358C 30A400FF */  andi      $a0, $a1, 0xff
/* 2E990 80053590 0000282D */  daddu     $a1, $zero, $zero
/* 2E994 80053594 0C015CE7 */  jal       func_8005739C
/* 2E998 80053598 240600B8 */   addiu    $a2, $zero, 0xb8
/* 2E99C 8005359C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2E9A0 800535A0 03E00008 */  jr        $ra
/* 2E9A4 800535A4 27BD0018 */   addiu    $sp, $sp, 0x18
