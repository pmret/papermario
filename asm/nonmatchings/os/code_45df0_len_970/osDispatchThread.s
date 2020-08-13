.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osDispatchThread
/* 0465D4 8006B1D4 3C048009 */  lui   $a0, 0x8009
/* 0465D8 8006B1D8 0C01AC6F */  jal   osPopThread
/* 0465DC 8006B1DC 24844658 */   addiu $a0, $a0, 0x4658
/* 0465E0 8006B1E0 3C018009 */  lui   $at, 0x8009
/* 0465E4 8006B1E4 AC224660 */  sw    $v0, 0x4660($at)
/* 0465E8 8006B1E8 24080004 */  addiu $t0, $zero, 4
/* 0465EC 8006B1EC A4480010 */  sh    $t0, 0x10($v0)
/* 0465F0 8006B1F0 0040D021 */  addu  $k0, $v0, $zero
