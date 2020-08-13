.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024A57C
/* 13D8BC 8024A57C 16000005 */  bnez  $s0, .L8024A594
/* 13D8C0 8024A580 24027FFE */   addiu $v0, $zero, 0x7ffe
/* 13D8C4 8024A584 3C018027 */  lui   $at, 0x8027
/* 13D8C8 8024A588 A4220400 */  sh    $v0, 0x400($at)
/* 13D8CC 8024A58C 0809296B */  j     func_8024A5AC
/* 13D8D0 8024A590 24100001 */   addiu $s0, $zero, 1

.L8024A594:
/* 13D8D4 8024A594 3C048027 */  lui   $a0, 0x8027
/* 13D8D8 8024A598 24840400 */  addiu $a0, $a0, 0x400
/* 13D8DC 8024A59C 3C068025 */  lui   $a2, 0x8025
/* 13D8E0 8024A5A0 24C697B0 */  addiu $a2, $a2, -0x6850
/* 13D8E4 8024A5A4 0C091293 */  jal   func_80244A4C
/* 13D8E8 8024A5A8 0200282D */   daddu $a1, $s0, $zero
