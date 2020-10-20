.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243104_8263C4
/* 8263C4 80243104 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8263C8 80243108 AFB10014 */  sw        $s1, 0x14($sp)
/* 8263CC 8024310C 0080882D */  daddu     $s1, $a0, $zero
/* 8263D0 80243110 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8263D4 80243114 AFB00010 */  sw        $s0, 0x10($sp)
/* 8263D8 80243118 8E30000C */  lw        $s0, 0xc($s1)
/* 8263DC 8024311C 8E050000 */  lw        $a1, ($s0)
/* 8263E0 80243120 0C0B1EAF */  jal       get_variable
/* 8263E4 80243124 26100004 */   addiu    $s0, $s0, 4
/* 8263E8 80243128 AE22008C */  sw        $v0, 0x8c($s1)
/* 8263EC 8024312C 8E050000 */  lw        $a1, ($s0)
/* 8263F0 80243130 26100004 */  addiu     $s0, $s0, 4
/* 8263F4 80243134 0C0B1EAF */  jal       get_variable
/* 8263F8 80243138 0220202D */   daddu    $a0, $s1, $zero
/* 8263FC 8024313C AE220090 */  sw        $v0, 0x90($s1)
/* 826400 80243140 8E050000 */  lw        $a1, ($s0)
/* 826404 80243144 26100004 */  addiu     $s0, $s0, 4
/* 826408 80243148 0C0B1EAF */  jal       get_variable
/* 82640C 8024314C 0220202D */   daddu    $a0, $s1, $zero
/* 826410 80243150 AE220094 */  sw        $v0, 0x94($s1)
/* 826414 80243154 8E050000 */  lw        $a1, ($s0)
/* 826418 80243158 26100004 */  addiu     $s0, $s0, 4
/* 82641C 8024315C 0C0B1EAF */  jal       get_variable
/* 826420 80243160 0220202D */   daddu    $a0, $s1, $zero
/* 826424 80243164 AE220098 */  sw        $v0, 0x98($s1)
/* 826428 80243168 8E050000 */  lw        $a1, ($s0)
/* 82642C 8024316C 26100004 */  addiu     $s0, $s0, 4
/* 826430 80243170 0C0B1EAF */  jal       get_variable
/* 826434 80243174 0220202D */   daddu    $a0, $s1, $zero
/* 826438 80243178 AE22009C */  sw        $v0, 0x9c($s1)
/* 82643C 8024317C 8E050000 */  lw        $a1, ($s0)
/* 826440 80243180 26100004 */  addiu     $s0, $s0, 4
/* 826444 80243184 0C0B1EAF */  jal       get_variable
/* 826448 80243188 0220202D */   daddu    $a0, $s1, $zero
/* 82644C 8024318C AE2200A0 */  sw        $v0, 0xa0($s1)
/* 826450 80243190 8E050000 */  lw        $a1, ($s0)
/* 826454 80243194 26100004 */  addiu     $s0, $s0, 4
/* 826458 80243198 0C0B1EAF */  jal       get_variable
/* 82645C 8024319C 0220202D */   daddu    $a0, $s1, $zero
/* 826460 802431A0 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 826464 802431A4 8E050000 */  lw        $a1, ($s0)
/* 826468 802431A8 26100004 */  addiu     $s0, $s0, 4
/* 82646C 802431AC 0C0B1EAF */  jal       get_variable
/* 826470 802431B0 0220202D */   daddu    $a0, $s1, $zero
/* 826474 802431B4 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 826478 802431B8 8E050000 */  lw        $a1, ($s0)
/* 82647C 802431BC 26100004 */  addiu     $s0, $s0, 4
/* 826480 802431C0 0C0B1EAF */  jal       get_variable
/* 826484 802431C4 0220202D */   daddu    $a0, $s1, $zero
/* 826488 802431C8 AE2200AC */  sw        $v0, 0xac($s1)
/* 82648C 802431CC 8E050000 */  lw        $a1, ($s0)
/* 826490 802431D0 0C0B1EAF */  jal       get_variable
/* 826494 802431D4 0220202D */   daddu    $a0, $s1, $zero
/* 826498 802431D8 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 82649C 802431DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8264A0 802431E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 8264A4 802431E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8264A8 802431E8 24020002 */  addiu     $v0, $zero, 2
/* 8264AC 802431EC 03E00008 */  jr        $ra
/* 8264B0 802431F0 27BD0020 */   addiu    $sp, $sp, 0x20
