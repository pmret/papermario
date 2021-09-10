.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EA8_DC0158
/* DC0158 80242EA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DC015C 80242EAC AFB20018 */  sw        $s2, 0x18($sp)
/* DC0160 80242EB0 0080902D */  daddu     $s2, $a0, $zero
/* DC0164 80242EB4 AFB10014 */  sw        $s1, 0x14($sp)
/* DC0168 80242EB8 3C11F971 */  lui       $s1, 0xf971
/* DC016C 80242EBC AFBF001C */  sw        $ra, 0x1c($sp)
/* DC0170 80242EC0 AFB00010 */  sw        $s0, 0x10($sp)
/* DC0174 80242EC4 8E50000C */  lw        $s0, 0xc($s2)
/* DC0178 80242EC8 36318887 */  ori       $s1, $s1, 0x8887
/* DC017C 80242ECC 8E050000 */  lw        $a1, ($s0)
/* DC0180 80242ED0 0C0B1EAF */  jal       evt_get_variable
/* DC0184 80242ED4 26100004 */   addiu    $s0, $s0, 4
/* DC0188 80242ED8 00518821 */  addu      $s1, $v0, $s1
/* DC018C 80242EDC 8E050000 */  lw        $a1, ($s0)
/* DC0190 80242EE0 0C0B1EAF */  jal       evt_get_variable
/* DC0194 80242EE4 0240202D */   daddu    $a0, $s2, $zero
/* DC0198 80242EE8 0240202D */  daddu     $a0, $s2, $zero
/* DC019C 80242EEC 0220282D */  daddu     $a1, $s1, $zero
/* DC01A0 80242EF0 0C0B2026 */  jal       evt_set_variable
/* DC01A4 80242EF4 0040302D */   daddu    $a2, $v0, $zero
/* DC01A8 80242EF8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DC01AC 80242EFC 8FB20018 */  lw        $s2, 0x18($sp)
/* DC01B0 80242F00 8FB10014 */  lw        $s1, 0x14($sp)
/* DC01B4 80242F04 8FB00010 */  lw        $s0, 0x10($sp)
/* DC01B8 80242F08 24020002 */  addiu     $v0, $zero, 2
/* DC01BC 80242F0C 03E00008 */  jr        $ra
/* DC01C0 80242F10 27BD0020 */   addiu    $sp, $sp, 0x20
/* DC01C4 80242F14 00000000 */  nop
/* DC01C8 80242F18 00000000 */  nop
/* DC01CC 80242F1C 00000000 */  nop
