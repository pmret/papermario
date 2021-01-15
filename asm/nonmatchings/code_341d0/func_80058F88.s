.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058F88
/* 34388 80058F88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3438C 80058F8C AFB10014 */  sw        $s1, 0x14($sp)
/* 34390 80058F90 0080882D */  daddu     $s1, $a0, $zero
/* 34394 80058F94 AFB00010 */  sw        $s0, 0x10($sp)
/* 34398 80058F98 00A0802D */  daddu     $s0, $a1, $zero
/* 3439C 80058F9C 0200202D */  daddu     $a0, $s0, $zero
/* 343A0 80058FA0 24051420 */  addiu     $a1, $zero, 0x1420
/* 343A4 80058FA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 343A8 80058FA8 0C015FE4 */  jal       alHeapAlloc
/* 343AC 80058FAC 24060002 */   addiu    $a2, $zero, 2
/* 343B0 80058FB0 0200202D */  daddu     $a0, $s0, $zero
/* 343B4 80058FB4 24050001 */  addiu     $a1, $zero, 1
/* 343B8 80058FB8 24060030 */  addiu     $a2, $zero, 0x30
/* 343BC 80058FBC 0C015FE4 */  jal       alHeapAlloc
/* 343C0 80058FC0 AE220000 */   sw       $v0, ($s1)
/* 343C4 80058FC4 0200202D */  daddu     $a0, $s0, $zero
/* 343C8 80058FC8 24050001 */  addiu     $a1, $zero, 1
/* 343CC 80058FCC 24060008 */  addiu     $a2, $zero, 8
/* 343D0 80058FD0 0C015FE4 */  jal       alHeapAlloc
/* 343D4 80058FD4 AE220010 */   sw       $v0, 0x10($s1)
/* 343D8 80058FD8 0220202D */  daddu     $a0, $s1, $zero
/* 343DC 80058FDC 0000282D */  daddu     $a1, $zero, $zero
/* 343E0 80058FE0 00A0302D */  daddu     $a2, $a1, $zero
/* 343E4 80058FE4 8C830010 */  lw        $v1, 0x10($a0)
/* 343E8 80058FE8 24075000 */  addiu     $a3, $zero, 0x5000
/* 343EC 80058FEC 0C016402 */  jal       func_80059008
/* 343F0 80058FF0 AC620028 */   sw       $v0, 0x28($v1)
/* 343F4 80058FF4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 343F8 80058FF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 343FC 80058FFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 34400 80059000 03E00008 */  jr        $ra
/* 34404 80059004 27BD0020 */   addiu    $sp, $sp, 0x20
