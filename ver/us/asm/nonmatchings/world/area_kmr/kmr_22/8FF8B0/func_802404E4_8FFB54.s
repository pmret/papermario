.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404E4_8FFB54
/* 8FFB54 802404E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8FFB58 802404E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 8FFB5C 802404EC 0080882D */  daddu     $s1, $a0, $zero
/* 8FFB60 802404F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8FFB64 802404F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8FFB68 802404F8 8E30000C */  lw        $s0, 0xc($s1)
/* 8FFB6C 802404FC 8E050000 */  lw        $a1, ($s0)
/* 8FFB70 80240500 0C0B1EAF */  jal       evt_get_variable
/* 8FFB74 80240504 26100004 */   addiu    $s0, $s0, 4
/* 8FFB78 80240508 8E050000 */  lw        $a1, ($s0)
/* 8FFB7C 8024050C 26100004 */  addiu     $s0, $s0, 4
/* 8FFB80 80240510 0C0B1EAF */  jal       evt_get_variable
/* 8FFB84 80240514 0220202D */   daddu    $a0, $s1, $zero
/* 8FFB88 80240518 8E050000 */  lw        $a1, ($s0)
/* 8FFB8C 8024051C 26100004 */  addiu     $s0, $s0, 4
/* 8FFB90 80240520 0C0B1EAF */  jal       evt_get_variable
/* 8FFB94 80240524 0220202D */   daddu    $a0, $s1, $zero
/* 8FFB98 80240528 8E050000 */  lw        $a1, ($s0)
/* 8FFB9C 8024052C 26100004 */  addiu     $s0, $s0, 4
/* 8FFBA0 80240530 0C0B1EAF */  jal       evt_get_variable
/* 8FFBA4 80240534 0220202D */   daddu    $a0, $s1, $zero
/* 8FFBA8 80240538 8E050000 */  lw        $a1, ($s0)
/* 8FFBAC 8024053C 0C0B1EAF */  jal       evt_get_variable
/* 8FFBB0 80240540 0220202D */   daddu    $a0, $s1, $zero
/* 8FFBB4 80240544 0000202D */  daddu     $a0, $zero, $zero
/* 8FFBB8 80240548 3C05FD05 */  lui       $a1, 0xfd05
/* 8FFBBC 8024054C 0C0B1EAF */  jal       evt_get_variable
/* 8FFBC0 80240550 34A50F80 */   ori      $a1, $a1, 0xf80
/* 8FFBC4 80240554 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8FFBC8 80240558 8FB10014 */  lw        $s1, 0x14($sp)
/* 8FFBCC 8024055C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8FFBD0 80240560 24020002 */  addiu     $v0, $zero, 2
/* 8FFBD4 80240564 03E00008 */  jr        $ra
/* 8FFBD8 80240568 27BD0020 */   addiu    $sp, $sp, 0x20
