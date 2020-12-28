.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4B11F0
/* 4B11F0 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B11F4 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B11F8 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 4B11FC 8021800C AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B1200 80218010 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1204 80218014 8E30000C */  lw        $s0, 0xc($s1)
/* 4B1208 80218018 8E050000 */  lw        $a1, ($s0)
/* 4B120C 8021801C 0C0B1EAF */  jal       get_variable
/* 4B1210 80218020 26100004 */   addiu    $s0, $s0, 4
/* 4B1214 80218024 0220202D */  daddu     $a0, $s1, $zero
/* 4B1218 80218028 8E050000 */  lw        $a1, ($s0)
/* 4B121C 8021802C 0C0B1EAF */  jal       get_variable
/* 4B1220 80218030 0040802D */   daddu    $s0, $v0, $zero
/* 4B1224 80218034 0200202D */  daddu     $a0, $s0, $zero
/* 4B1228 80218038 0C00A3C2 */  jal       start_rumble
/* 4B122C 8021803C 0040282D */   daddu    $a1, $v0, $zero
/* 4B1230 80218040 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B1234 80218044 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B1238 80218048 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B123C 8021804C 24020002 */  addiu     $v0, $zero, 2
/* 4B1240 80218050 03E00008 */  jr        $ra
/* 4B1244 80218054 27BD0020 */   addiu    $sp, $sp, 0x20
