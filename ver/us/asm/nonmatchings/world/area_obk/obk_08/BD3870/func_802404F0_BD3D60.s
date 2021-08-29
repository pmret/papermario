.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404F0_BD3D60
/* BD3D60 802404F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD3D64 802404F4 AFB10014 */  sw        $s1, 0x14($sp)
/* BD3D68 802404F8 0080882D */  daddu     $s1, $a0, $zero
/* BD3D6C 802404FC 0000202D */  daddu     $a0, $zero, $zero
/* BD3D70 80240500 3C05FD05 */  lui       $a1, 0xfd05
/* BD3D74 80240504 34A50F8A */  ori       $a1, $a1, 0xf8a
/* BD3D78 80240508 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD3D7C 8024050C 0C0B1EAF */  jal       get_variable
/* BD3D80 80240510 AFB00010 */   sw       $s0, 0x10($sp)
/* BD3D84 80240514 0040802D */  daddu     $s0, $v0, $zero
/* BD3D88 80240518 0C04EA15 */  jal       func_8013A854
/* BD3D8C 8024051C 8E040000 */   lw       $a0, ($s0)
/* BD3D90 80240520 0C048D70 */  jal       free_generic_entity
/* BD3D94 80240524 8E040004 */   lw       $a0, 4($s0)
/* BD3D98 80240528 0C00AB4B */  jal       heap_free
/* BD3D9C 8024052C 0200202D */   daddu    $a0, $s0, $zero
/* BD3DA0 80240530 0220202D */  daddu     $a0, $s1, $zero
/* BD3DA4 80240534 3C05FD05 */  lui       $a1, 0xfd05
/* BD3DA8 80240538 34A50F8A */  ori       $a1, $a1, 0xf8a
/* BD3DAC 8024053C 0C0B2026 */  jal       evt_set_variable
/* BD3DB0 80240540 0000302D */   daddu    $a2, $zero, $zero
/* BD3DB4 80240544 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD3DB8 80240548 8FB10014 */  lw        $s1, 0x14($sp)
/* BD3DBC 8024054C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD3DC0 80240550 24020002 */  addiu     $v0, $zero, 2
/* BD3DC4 80240554 03E00008 */  jr        $ra
/* BD3DC8 80240558 27BD0020 */   addiu    $sp, $sp, 0x20
