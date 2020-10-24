.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243494_803D14
/* 803D14 80243494 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803D18 80243498 AFB10014 */  sw        $s1, 0x14($sp)
/* 803D1C 8024349C 0080882D */  daddu     $s1, $a0, $zero
/* 803D20 802434A0 0000202D */  daddu     $a0, $zero, $zero
/* 803D24 802434A4 3C05FD05 */  lui       $a1, 0xfd05
/* 803D28 802434A8 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 803D2C 802434AC AFBF0018 */  sw        $ra, 0x18($sp)
/* 803D30 802434B0 0C0B1EAF */  jal       get_variable
/* 803D34 802434B4 AFB00010 */   sw       $s0, 0x10($sp)
/* 803D38 802434B8 0040802D */  daddu     $s0, $v0, $zero
/* 803D3C 802434BC 0C04EA15 */  jal       func_8013A854
/* 803D40 802434C0 8E040000 */   lw       $a0, ($s0)
/* 803D44 802434C4 0C048D70 */  jal       func_801235C0
/* 803D48 802434C8 8E040004 */   lw       $a0, 4($s0)
/* 803D4C 802434CC 0C00AB4B */  jal       heap_free
/* 803D50 802434D0 0200202D */   daddu    $a0, $s0, $zero
/* 803D54 802434D4 0220202D */  daddu     $a0, $s1, $zero
/* 803D58 802434D8 3C05FD05 */  lui       $a1, 0xfd05
/* 803D5C 802434DC 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 803D60 802434E0 0C0B2026 */  jal       set_variable
/* 803D64 802434E4 0000302D */   daddu    $a2, $zero, $zero
/* 803D68 802434E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 803D6C 802434EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 803D70 802434F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 803D74 802434F4 24020002 */  addiu     $v0, $zero, 2
/* 803D78 802434F8 03E00008 */  jr        $ra
/* 803D7C 802434FC 27BD0020 */   addiu    $sp, $sp, 0x20
