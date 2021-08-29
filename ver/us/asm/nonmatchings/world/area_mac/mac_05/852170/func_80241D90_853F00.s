.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D90_853F00
/* 853F00 80241D90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 853F04 80241D94 AFBF0010 */  sw        $ra, 0x10($sp)
/* 853F08 80241D98 8C82000C */  lw        $v0, 0xc($a0)
/* 853F0C 80241D9C 0C0B1EAF */  jal       evt_get_variable
/* 853F10 80241DA0 8C450000 */   lw       $a1, ($v0)
/* 853F14 80241DA4 0040202D */  daddu     $a0, $v0, $zero
/* 853F18 80241DA8 3C028025 */  lui       $v0, %hi(D_802529F0)
/* 853F1C 80241DAC 8C4229F0 */  lw        $v0, %lo(D_802529F0)($v0)
/* 853F20 80241DB0 24030001 */  addiu     $v1, $zero, 1
/* 853F24 80241DB4 8C45000C */  lw        $a1, 0xc($v0)
/* 853F28 80241DB8 1083000D */  beq       $a0, $v1, .L80241DF0
/* 853F2C 80241DBC 28820002 */   slti     $v0, $a0, 2
/* 853F30 80241DC0 10400005 */  beqz      $v0, .L80241DD8
/* 853F34 80241DC4 24020002 */   addiu    $v0, $zero, 2
/* 853F38 80241DC8 10800007 */  beqz      $a0, .L80241DE8
/* 853F3C 80241DCC 240200C0 */   addiu    $v0, $zero, 0xc0
/* 853F40 80241DD0 08090780 */  j         .L80241E00
/* 853F44 80241DD4 ACA00038 */   sw       $zero, 0x38($a1)
.L80241DD8:
/* 853F48 80241DD8 10820008 */  beq       $a0, $v0, .L80241DFC
/* 853F4C 80241DDC 24020040 */   addiu    $v0, $zero, 0x40
/* 853F50 80241DE0 08090780 */  j         .L80241E00
/* 853F54 80241DE4 ACA00038 */   sw       $zero, 0x38($a1)
.L80241DE8:
/* 853F58 80241DE8 08090780 */  j         .L80241E00
/* 853F5C 80241DEC ACA20038 */   sw       $v0, 0x38($a1)
.L80241DF0:
/* 853F60 80241DF0 24020080 */  addiu     $v0, $zero, 0x80
/* 853F64 80241DF4 08090780 */  j         .L80241E00
/* 853F68 80241DF8 ACA20038 */   sw       $v0, 0x38($a1)
.L80241DFC:
/* 853F6C 80241DFC ACA20038 */  sw        $v0, 0x38($a1)
.L80241E00:
/* 853F70 80241E00 8FBF0010 */  lw        $ra, 0x10($sp)
/* 853F74 80241E04 24020002 */  addiu     $v0, $zero, 2
/* 853F78 80241E08 03E00008 */  jr        $ra
/* 853F7C 80241E0C 27BD0018 */   addiu    $sp, $sp, 0x18
