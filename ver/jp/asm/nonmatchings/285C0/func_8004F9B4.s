.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004F9B4
/* 2ADB4 8004F9B4 90830235 */  lbu       $v1, 0x235($a0)
/* 2ADB8 8004F9B8 8C820000 */  lw        $v0, ($a0)
/* 2ADBC 8004F9BC 908500D4 */  lbu       $a1, 0xd4($a0)
/* 2ADC0 8004F9C0 00031880 */  sll       $v1, $v1, 2
/* 2ADC4 8004F9C4 00431021 */  addu      $v0, $v0, $v1
/* 2ADC8 8004F9C8 A0450040 */  sb        $a1, 0x40($v0)
/* 2ADCC 8004F9CC 90820235 */  lbu       $v0, 0x235($a0)
/* 2ADD0 8004F9D0 8C830000 */  lw        $v1, ($a0)
/* 2ADD4 8004F9D4 00021080 */  sll       $v0, $v0, 2
/* 2ADD8 8004F9D8 00621821 */  addu      $v1, $v1, $v0
/* 2ADDC 8004F9DC 24020001 */  addiu     $v0, $zero, 1
/* 2ADE0 8004F9E0 03E00008 */  jr        $ra
/* 2ADE4 8004F9E4 A0620041 */   sb       $v0, 0x41($v1)
