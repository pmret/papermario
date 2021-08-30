.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182E4_59E9C4
/* 59E9C4 802182E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59E9C8 802182E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 59E9CC 802182EC 0080882D */  daddu     $s1, $a0, $zero
/* 59E9D0 802182F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 59E9D4 802182F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 59E9D8 802182F8 8E30000C */  lw        $s0, 0xc($s1)
/* 59E9DC 802182FC 8E050000 */  lw        $a1, ($s0)
/* 59E9E0 80218300 0C0B1EAF */  jal       evt_get_variable
/* 59E9E4 80218304 26100004 */   addiu    $s0, $s0, 4
/* 59E9E8 80218308 8E050000 */  lw        $a1, ($s0)
/* 59E9EC 8021830C 26100004 */  addiu     $s0, $s0, 4
/* 59E9F0 80218310 0C0B1EAF */  jal       evt_get_variable
/* 59E9F4 80218314 0220202D */   daddu    $a0, $s1, $zero
/* 59E9F8 80218318 8E050000 */  lw        $a1, ($s0)
/* 59E9FC 8021831C 26100004 */  addiu     $s0, $s0, 4
/* 59EA00 80218320 0C0B1EAF */  jal       evt_get_variable
/* 59EA04 80218324 0220202D */   daddu    $a0, $s1, $zero
/* 59EA08 80218328 8E050000 */  lw        $a1, ($s0)
/* 59EA0C 8021832C 26100004 */  addiu     $s0, $s0, 4
/* 59EA10 80218330 0C0B1EAF */  jal       evt_get_variable
/* 59EA14 80218334 0220202D */   daddu    $a0, $s1, $zero
/* 59EA18 80218338 8E050000 */  lw        $a1, ($s0)
/* 59EA1C 8021833C 0C0B1EAF */  jal       evt_get_variable
/* 59EA20 80218340 0220202D */   daddu    $a0, $s1, $zero
/* 59EA24 80218344 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59EA28 80218348 8FB10014 */  lw        $s1, 0x14($sp)
/* 59EA2C 8021834C 8FB00010 */  lw        $s0, 0x10($sp)
/* 59EA30 80218350 24020002 */  addiu     $v0, $zero, 2
/* 59EA34 80218354 03E00008 */  jr        $ra
/* 59EA38 80218358 27BD0020 */   addiu    $sp, $sp, 0x20
